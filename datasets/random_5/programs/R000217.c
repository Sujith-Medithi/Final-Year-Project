/*
 * Benchmark Program: R000217
 * Security Family: nested_implicit_flow
 * Generator Seed: 521713
 * High Inputs: 20 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000217_1713_0 {
    short port;
    int parity;
    short stop_bits;
    short id;
    unsigned char timeout;
    int buffer[3];
};

struct SensorNode_R000217_1713_1 {
    unsigned char status;
    int threshold;
    int calib;
    int reading;
    int gain;
    unsigned char offset;
    int buffer[3];
};

struct AudioFrame_R000217_1713_2 {
    unsigned char envelope;
    unsigned char rms;
    unsigned char sample_rate;
    int gain;
    int channels;
    int buffer[3];
};

union RegisterBank_R000217_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000217_1713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000217_1713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000217_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int parity_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_18) & 63;
    acc ^= aux;
    int mask_29 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_29 > 38) {
        acc = (acc + mask_29 * 2 + 5) & 127;
        aux ^= (mask_29 & 15);
    } else {
        acc = (acc - mask_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_16 = local_arr[aux % 3];
    acc = (acc + pivot_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000217_1713_1(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000217_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_45 = (aux + st.buffer[1]) & 3;
    switch (bound_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_82) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_64 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_64 > 23) {
        acc = (acc + factor_64 * 2 + 5) & 127;
        aux ^= (factor_64 & 15);
    } else {
        acc = (acc - factor_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000217_1713_2(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000217_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_52 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_52 > 34) {
        acc = (acc + vector_52 * 2 + 5) & 127;
        aux ^= (vector_52 & 15);
    } else {
        acc = (acc - vector_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_38 = local_arr[aux % 3];
    acc = (acc + offset_38 * 2) & 127;
    int threshold_76 = (aux + st.buffer[1]) & 3;
    switch (threshold_76) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000217_1713_3(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000217_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_71 = local_arr[aux % 3];
    acc = (acc + vector_71 * 2) & 127;
    int weight_89 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_89 > 43) {
        acc = (acc + weight_89 * 2 + 5) & 127;
        aux ^= (weight_89 & 15);
    } else {
        acc = (acc - weight_89 + 11) & 127;
        aux += 3;
    }
    int bound_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000217_1713_4(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000217_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_62 = (aux + st.buffer[1]) & 3;
    switch (factor_62) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000217_1713_5(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000217_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int vector_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_34) & 63;
    acc ^= aux;
    int quotient_98 = (aux + st.buffer[1]) & 3;
    switch (quotient_98) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_24 = local_arr[aux % 3];
    acc = (acc + factor_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000217_1713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000217_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_79 = local_arr[aux % 3];
    acc = (acc + metric_79 * 2) & 127;
    int window_44 = (aux + st.buffer[1]) & 3;
    switch (window_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000217_1713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000217_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int tracker_22 = local_arr[aux % 3];
    acc = (acc + tracker_22 * 2) & 127;
    int coefficient_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000217_1713_8(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000217_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int threshold_86 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_86 > 44) {
        acc = (acc + threshold_86 * 2 + 5) & 127;
        aux ^= (threshold_86 & 15);
    } else {
        acc = (acc - threshold_86 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_44) & 63;
    acc ^= aux;
    int margin_79 = (aux + st.buffer[1]) & 3;
    switch (margin_79) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000217_1713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000217_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000217_1713_10(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000217_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int accumulator_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_22) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_18 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_18 > 19) {
        acc = (acc + cursor_18 * 2 + 5) & 127;
        aux ^= (cursor_18 & 15);
    } else {
        acc = (acc - cursor_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_91 = local_arr[aux % 3];
    acc = (acc + stride_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000217_1713_11(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000217_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_37 = local_arr[aux % 3];
    acc = (acc + tracker_37 * 2) & 127;
    int damping_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000217_1713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000217_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int factor_29 = local_arr[aux % 3];
    acc = (acc + factor_29 * 2) & 127;
    int index_reg_77 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_77 > 30) {
        acc = (acc + index_reg_77 * 2 + 5) & 127;
        aux ^= (index_reg_77 & 15);
    } else {
        acc = (acc - index_reg_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_38 = (aux + st.buffer[1]) & 3;
    switch (tracker_38) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000217_1713_13(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000217_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int vector_46 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_46 > 19) {
        acc = (acc + vector_46 * 2 + 5) & 127;
        aux ^= (vector_46 & 15);
    } else {
        acc = (acc - vector_46 + 11) & 127;
        aux += 3;
    }
    int anchor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_21 = local_arr[aux % 3];
    acc = (acc + stride_21 * 2) & 127;
    int offset_81 = (aux + st.buffer[1]) & 3;
    switch (offset_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000217_0;
    int sec_r000217_1;
    int sec_r000217_2;
    int sec_r000217_3;
    int sec_r000217_4;
    int sec_r000217_5;
    int sec_r000217_6;
    int sec_r000217_7;
    int sec_r000217_8;
    int sec_r000217_9;
    int sec_r000217_10;
    int sec_r000217_11;
    int sec_r000217_12;
    int sec_r000217_13;
    int sec_r000217_14;
    int sec_r000217_15;
    int sec_r000217_16;
    int sec_r000217_17;
    int sec_r000217_18;
    int sec_r000217_19;
    int pub_r000217_0;
    int pub_r000217_1;
    int pub_r000217_2;
    int pub_r000217_3;
    int pub_r000217_4;
    int pub_r000217_5;
    int pub_r000217_6;
    int pub_r000217_7;
    int pub_r000217_8;
    int pub_r000217_9;
    int pub_r000217_10;
    int pub_r000217_11;
    int pub_r000217_12;
    int pub_r000217_13;
    int pub_r000217_14;
    int pub_r000217_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000217_0 >= -100 && pub_r000217_0 <= 100);
    __CPROVER_assume(pub_r000217_1 >= -100 && pub_r000217_1 <= 100);
    __CPROVER_assume(pub_r000217_2 >= -100 && pub_r000217_2 <= 100);
    __CPROVER_assume(pub_r000217_3 >= -100 && pub_r000217_3 <= 100);
    __CPROVER_assume(pub_r000217_4 >= -100 && pub_r000217_4 <= 100);
    __CPROVER_assume(pub_r000217_5 >= -100 && pub_r000217_5 <= 100);
    __CPROVER_assume(pub_r000217_6 >= -100 && pub_r000217_6 <= 100);
    __CPROVER_assume(pub_r000217_7 >= -100 && pub_r000217_7 <= 100);
    __CPROVER_assume(pub_r000217_8 >= -100 && pub_r000217_8 <= 100);
    __CPROVER_assume(pub_r000217_9 >= -100 && pub_r000217_9 <= 100);
    __CPROVER_assume(pub_r000217_10 >= -100 && pub_r000217_10 <= 100);
    __CPROVER_assume(pub_r000217_11 >= -100 && pub_r000217_11 <= 100);
    __CPROVER_assume(pub_r000217_12 >= -100 && pub_r000217_12 <= 100);
    __CPROVER_assume(pub_r000217_13 >= -100 && pub_r000217_13 <= 100);
    __CPROVER_assume(pub_r000217_14 >= -100 && pub_r000217_14 <= 100);
    __CPROVER_assume(pub_r000217_15 >= -100 && pub_r000217_15 <= 100);
    __CPROVER_assume(sec_r000217_0 >= 0 && sec_r000217_0 <= 255);
    __CPROVER_assume(sec_r000217_1 >= 0 && sec_r000217_1 <= 255);
    __CPROVER_assume(sec_r000217_2 >= 0 && sec_r000217_2 <= 255);
    __CPROVER_assume(sec_r000217_3 >= 0 && sec_r000217_3 <= 255);
    __CPROVER_assume(sec_r000217_4 >= 0 && sec_r000217_4 <= 255);
    __CPROVER_assume(sec_r000217_5 >= 0 && sec_r000217_5 <= 255);
    __CPROVER_assume(sec_r000217_6 >= 0 && sec_r000217_6 <= 255);
    __CPROVER_assume(sec_r000217_7 >= 0 && sec_r000217_7 <= 255);
    __CPROVER_assume(sec_r000217_8 >= 0 && sec_r000217_8 <= 255);
    __CPROVER_assume(sec_r000217_9 >= 0 && sec_r000217_9 <= 255);
    __CPROVER_assume(sec_r000217_10 >= 0 && sec_r000217_10 <= 255);
    __CPROVER_assume(sec_r000217_11 >= 0 && sec_r000217_11 <= 255);
    __CPROVER_assume(sec_r000217_12 >= 0 && sec_r000217_12 <= 255);
    __CPROVER_assume(sec_r000217_13 >= 0 && sec_r000217_13 <= 255);
    __CPROVER_assume(sec_r000217_14 >= 0 && sec_r000217_14 <= 255);
    __CPROVER_assume(sec_r000217_15 >= 0 && sec_r000217_15 <= 255);
    __CPROVER_assume(sec_r000217_16 >= 0 && sec_r000217_16 <= 255);
    __CPROVER_assume(sec_r000217_17 >= 0 && sec_r000217_17 <= 255);
    __CPROVER_assume(sec_r000217_18 >= 0 && sec_r000217_18 <= 255);
    __CPROVER_assume(sec_r000217_19 >= 0 && sec_r000217_19 <= 255);

    struct DeviceConfig_R000217_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000217_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000217_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000217_0 + 7) & 15;
    struct SensorNode_R000217_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000217_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000217_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000217_0 + 9) & 15;
    struct AudioFrame_R000217_1713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000217_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000217_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000217_0 + 11) & 15;

    union RegisterBank_R000217_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 31) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 46) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 21) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 36) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 29) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 44) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 38) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 53) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 24) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 39) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 14) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 29) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
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
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 15) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 30) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 13) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 28) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 30) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 45) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
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
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

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
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 26) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 41) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000217_9 & 1) != 0) {
        if ((sec_r000217_12 & 2) != 0) {
            stage_v_81 = (pub_r000217_8 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000217_8 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000217_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000217_8 & 2) != 0) {
            stage_v_82 = (pub_r000217_2 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000217_2 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000217_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000217_10 & 2) != 0) {
            stage_v_83 = (pub_r000217_5 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000217_5 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000217_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000217_14 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_84 = (pub_r000217_13 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000217_13 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000217_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000217_12 & 2) != 0) {
            stage_v_85 = (pub_r000217_14 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000217_14 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000217_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000217_9 & 2) != 0) {
            stage_v_86 = (pub_r000217_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000217_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000217_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000217_10 & 2) != 0) {
            stage_v_87 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_88 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000217_3 & 2) != 0) {
            stage_v_89 = (pub_r000217_5 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000217_5 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000217_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000217_14 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_90 = (pub_r000217_3 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000217_3 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000217_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000217_2 & 1) != 0) {
        if ((sec_r000217_9 & 2) != 0) {
            stage_v_91 = (pub_r000217_5 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000217_5 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000217_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000217_2 & 2) != 0) {
            stage_v_92 = (pub_r000217_3 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000217_3 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000217_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000217_18 & 1) != 0) {
        if ((sec_r000217_16 & 2) != 0) {
            stage_v_93 = (pub_r000217_13 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000217_13 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000217_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000217_16 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_94 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_95 = (pub_r000217_12 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000217_12 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000217_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000217_12 & 2) != 0) {
            stage_v_96 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000217_10 & 2) != 0) {
            stage_v_97 = (pub_r000217_15 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000217_15 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000217_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000217_4 & 2) != 0) {
            stage_v_98 = (pub_r000217_8 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000217_8 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000217_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000217_16 & 2) != 0) {
            stage_v_99 = (pub_r000217_1 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000217_1 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000217_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000217_0 & 2) != 0) {
            stage_v_100 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000217_11 & 1) != 0) {
        if ((sec_r000217_4 & 2) != 0) {
            stage_v_101 = (pub_r000217_6 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000217_6 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000217_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000217_6 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_102 = (pub_r000217_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000217_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000217_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000217_17 & 2) != 0) {
            stage_v_103 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000217_5 & 1) != 0) {
        if ((sec_r000217_7 & 2) != 0) {
            stage_v_104 = (pub_r000217_12 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000217_12 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000217_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000217_13 & 2) != 0) {
            stage_v_105 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000217_16 & 2) != 0) {
            stage_v_106 = (pub_r000217_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000217_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000217_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000217_2 & 2) != 0) {
            stage_v_107 = (pub_r000217_11 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000217_11 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000217_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000217_3 & 2) != 0) {
            stage_v_108 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000217_11 & 2) != 0) {
            stage_v_109 = (pub_r000217_11 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000217_11 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000217_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000217_8 & 2) != 0) {
            stage_v_110 = (pub_r000217_5 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000217_5 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000217_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_111 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000217_13 & 2) != 0) {
            stage_v_112 = (pub_r000217_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000217_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000217_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_113 = (pub_r000217_2 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000217_2 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000217_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_114 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_115 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000217_0 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_116 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000217_10 & 2) != 0) {
            stage_v_117 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000217_13 & 1) != 0) {
        if ((sec_r000217_12 & 2) != 0) {
            stage_v_118 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000217_2 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_119 = (pub_r000217_8 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000217_8 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000217_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_120 = (pub_r000217_13 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000217_13 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000217_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000217_13 & 1) != 0) {
        if ((sec_r000217_3 & 2) != 0) {
            stage_v_121 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000217_7 & 1) != 0) {
        if ((sec_r000217_18 & 2) != 0) {
            stage_v_122 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000217_3 & 2) != 0) {
            stage_v_123 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000217_6 & 2) != 0) {
            stage_v_124 = (pub_r000217_12 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000217_12 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000217_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000217_12 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_125 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000217_0 & 2) != 0) {
            stage_v_126 = (pub_r000217_0 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000217_0 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000217_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000217_3 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_127 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000217_16 & 2) != 0) {
            stage_v_128 = (pub_r000217_6 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000217_6 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000217_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000217_19 & 2) != 0) {
            stage_v_129 = (pub_r000217_3 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000217_3 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000217_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_130 = (pub_r000217_15 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000217_15 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000217_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000217_4 & 2) != 0) {
            stage_v_131 = (pub_r000217_6 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000217_6 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000217_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000217_12 & 1) != 0) {
        if ((sec_r000217_0 & 2) != 0) {
            stage_v_132 = (pub_r000217_15 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000217_15 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000217_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000217_17 & 2) != 0) {
            stage_v_133 = (pub_r000217_2 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000217_2 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000217_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_134 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_135 = (pub_r000217_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000217_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000217_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000217_6 & 2) != 0) {
            stage_v_136 = (pub_r000217_1 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000217_1 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000217_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000217_13 & 1) != 0) {
        if ((sec_r000217_7 & 2) != 0) {
            stage_v_137 = (pub_r000217_6 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000217_6 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000217_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000217_13 & 2) != 0) {
            stage_v_138 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000217_15 & 1) != 0) {
        if ((sec_r000217_8 & 2) != 0) {
            stage_v_139 = (pub_r000217_13 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000217_13 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000217_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000217_4 & 1) != 0) {
        if ((sec_r000217_17 & 2) != 0) {
            stage_v_140 = (pub_r000217_9 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000217_9 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000217_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000217_14 & 1) != 0) {
        if ((sec_r000217_8 & 2) != 0) {
            stage_v_141 = (pub_r000217_1 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000217_1 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000217_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_142 = (pub_r000217_5 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000217_5 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000217_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000217_12 & 1) != 0) {
        if ((sec_r000217_18 & 2) != 0) {
            stage_v_143 = (pub_r000217_13 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000217_13 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000217_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000217_0 & 1) != 0) {
        if ((sec_r000217_17 & 2) != 0) {
            stage_v_144 = (pub_r000217_0 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000217_0 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000217_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000217_2 & 1) != 0) {
        if ((sec_r000217_16 & 2) != 0) {
            stage_v_145 = (pub_r000217_6 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000217_6 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000217_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000217_16 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_146 = (pub_r000217_12 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000217_12 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000217_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000217_8 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_147 = (pub_r000217_5 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000217_5 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000217_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000217_2 & 2) != 0) {
            stage_v_148 = (pub_r000217_15 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000217_15 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000217_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000217_19 & 2) != 0) {
            stage_v_149 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000217_11 & 2) != 0) {
            stage_v_150 = (pub_r000217_10 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000217_10 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000217_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_151 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_152 = (pub_r000217_2 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000217_2 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000217_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000217_2 & 1) != 0) {
        if ((sec_r000217_10 & 2) != 0) {
            stage_v_153 = (pub_r000217_4 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000217_4 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000217_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000217_19 & 1) != 0) {
        if ((sec_r000217_17 & 2) != 0) {
            stage_v_154 = (pub_r000217_3 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000217_3 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000217_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000217_9 & 1) != 0) {
        if ((sec_r000217_10 & 2) != 0) {
            stage_v_155 = (pub_r000217_11 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000217_11 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000217_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000217_5 & 2) != 0) {
            stage_v_156 = (pub_r000217_13 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000217_13 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000217_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000217_3 & 2) != 0) {
            stage_v_157 = (pub_r000217_11 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000217_11 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000217_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000217_17 & 2) != 0) {
            stage_v_158 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000217_12 & 1) != 0) {
        if ((sec_r000217_18 & 2) != 0) {
            stage_v_159 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000217_15 & 2) != 0) {
            stage_v_160 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000217_13 & 2) != 0) {
            stage_v_161 = (pub_r000217_2 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000217_2 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000217_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000217_2 & 1) != 0) {
        if ((sec_r000217_9 & 2) != 0) {
            stage_v_162 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000217_16 & 1) != 0) {
        if ((sec_r000217_0 & 2) != 0) {
            stage_v_163 = (pub_r000217_11 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000217_11 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000217_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000217_11 & 2) != 0) {
            stage_v_164 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((sec_r000217_9 & 1) != 0) {
        if ((sec_r000217_19 & 2) != 0) {
            stage_v_165 = (pub_r000217_3 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000217_3 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000217_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((sec_r000217_18 & 1) != 0) {
        if ((sec_r000217_1 & 2) != 0) {
            stage_v_166 = (pub_r000217_7 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000217_7 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000217_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((sec_r000217_5 & 1) != 0) {
        if ((sec_r000217_7 & 2) != 0) {
            stage_v_167 = (pub_r000217_0 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000217_0 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000217_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((sec_r000217_18 & 1) != 0) {
        if ((sec_r000217_14 & 2) != 0) {
            stage_v_168 = (pub_r000217_1 + 31) & 127;
        } else {
            stage_v_168 = (pub_r000217_1 + 13) & 127;
        }
    } else {
        stage_v_168 = (pub_r000217_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
