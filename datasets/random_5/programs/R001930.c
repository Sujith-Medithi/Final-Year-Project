/*
 * Benchmark Program: R001930
 * Security Family: mixed_control_data
 * Generator Seed: 693013
 * High Inputs: 18 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001930_3013_0 {
    unsigned char sample_rate;
    int rms;
    unsigned char gain;
    short envelope;
    int peak;
    int channels;
    int buffer[3];
};

struct SensorNode_R001930_3013_1 {
    int calib;
    unsigned char offset;
    short status;
    int buffer[3];
};

struct Transaction_R001930_3013_2 {
    int status;
    short auth_code;
    int account_id;
    int fee;
    int buffer[3];
};

struct DeviceConfig_R001930_3013_3 {
    int baud_rate;
    int stop_bits;
    unsigned char timeout;
    int parity;
    short id;
    int buffer[3];
};

union ColorPixel_R001930_3013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001930_3013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001930_3013_0(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001930_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int vector_41 = 0;
    for (int k = 0; k < 2; k++) {
        vector_41 = (vector_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_41) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_13 = local_arr[aux % 3];
    acc = (acc + threshold_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001930_3013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001930_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_39 = 0;
    for (int k = 0; k < 2; k++) {
        bound_39 = (bound_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_39) & 127;
    }
    int quantum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001930_3013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001930_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_16 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_16 > 42) {
        acc = (acc + checksum_16 * 2 + 5) & 127;
        aux ^= (checksum_16 & 15);
    } else {
        acc = (acc - checksum_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_26 = local_arr[aux % 3];
    acc = (acc + delta_26 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_53 = 0;
    for (int k = 0; k < 3; k++) {
        offset_53 = (offset_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_53) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001930_3013_3(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001930_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int damping_62 = local_arr[aux % 3];
    acc = (acc + damping_62 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001930_3013_4(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001930_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_63) & 63;
    acc ^= aux;
    int vector_15 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_15 > 21) {
        acc = (acc + vector_15 * 2 + 5) & 127;
        aux ^= (vector_15 & 15);
    } else {
        acc = (acc - vector_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001930_3013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001930_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_73 = 0;
    for (int k = 0; k < 3; k++) {
        damping_73 = (damping_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_73) & 127;
    }
    int quotient_99 = (aux + st.buffer[1]) & 3;
    switch (quotient_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001930_3013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001930_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int accumulator_48 = local_arr[aux % 3];
    acc = (acc + accumulator_48 * 2) & 127;
    int mask_79 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_79 > 33) {
        acc = (acc + mask_79 * 2 + 5) & 127;
        aux ^= (mask_79 & 15);
    } else {
        acc = (acc - mask_79 + 11) & 127;
        aux += 3;
    }
    int residue_77 = (aux + st.buffer[1]) & 3;
    switch (residue_77) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001930_3013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001930_3013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_45 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_45 > 15) {
        acc = (acc + parity_45 * 2 + 5) & 127;
        aux ^= (parity_45 & 15);
    } else {
        acc = (acc - parity_45 + 11) & 127;
        aux += 3;
    }
    int window_40 = 0;
    for (int k = 0; k < 2; k++) {
        window_40 = (window_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_40) & 127;
    }
    int coefficient_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_37) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001930_3013_8(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001930_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_11 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_11 > 24) {
        acc = (acc + cursor_11 * 2 + 5) & 127;
        aux ^= (cursor_11 & 15);
    } else {
        acc = (acc - cursor_11 + 11) & 127;
        aux += 3;
    }
    int phase_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_54) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_77 = local_arr[aux % 3];
    acc = (acc + pivot_77 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001930_3013_9(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001930_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_26 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_26 > 48) {
        acc = (acc + tracker_26 * 2 + 5) & 127;
        aux ^= (tracker_26 & 15);
    } else {
        acc = (acc - tracker_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001930_3013_10(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001930_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_40 = (aux + st.buffer[1]) & 3;
    switch (mask_40) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_93 = local_arr[aux % 3];
    acc = (acc + damping_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001930_3013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001930_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int quantum_11 = local_arr[aux % 3];
    acc = (acc + quantum_11 * 2) & 127;
    int margin_11 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_11 > 47) {
        acc = (acc + margin_11 * 2 + 5) & 127;
        aux ^= (margin_11 & 15);
    } else {
        acc = (acc - margin_11 + 11) & 127;
        aux += 3;
    }
    int metric_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001930_3013_12(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001930_3013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int accumulator_62 = local_arr[aux % 3];
    acc = (acc + accumulator_62 * 2) & 127;
    int sample_29 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_29 > 39) {
        acc = (acc + sample_29 * 2 + 5) & 127;
        aux ^= (sample_29 & 15);
    } else {
        acc = (acc - sample_29 + 11) & 127;
        aux += 3;
    }
    int delta_27 = 0;
    for (int k = 0; k < 2; k++) {
        delta_27 = (delta_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_27) & 127;
    }
    int stride_24 = (aux + st.buffer[1]) & 3;
    switch (stride_24) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001930_3013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001930_3013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int parity_42 = (aux + st.buffer[1]) & 3;
    switch (parity_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_61 = 0;
    for (int k = 0; k < 2; k++) {
        offset_61 = (offset_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_61) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_36 = local_arr[aux % 3];
    acc = (acc + segment_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001930_3013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001930_3013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_47 = local_arr[aux % 3];
    acc = (acc + factor_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_92 = (aux + st.buffer[1]) & 3;
    switch (cursor_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001930_0;
    int sec_r001930_1;
    int sec_r001930_2;
    int sec_r001930_3;
    int sec_r001930_4;
    int sec_r001930_5;
    int sec_r001930_6;
    int sec_r001930_7;
    int sec_r001930_8;
    int sec_r001930_9;
    int sec_r001930_10;
    int sec_r001930_11;
    int sec_r001930_12;
    int sec_r001930_13;
    int sec_r001930_14;
    int sec_r001930_15;
    int sec_r001930_16;
    int sec_r001930_17;
    int pub_r001930_0;
    int pub_r001930_1;
    int pub_r001930_2;
    int pub_r001930_3;
    int pub_r001930_4;
    int pub_r001930_5;
    int pub_r001930_6;
    int pub_r001930_7;
    int pub_r001930_8;
    int pub_r001930_9;
    int pub_r001930_10;
    int pub_r001930_11;
    int pub_r001930_12;
    int pub_r001930_13;
    int pub_r001930_14;
    int pub_r001930_15;
    int pub_r001930_16;
    int pub_r001930_17;
    int pub_r001930_18;
    int pub_r001930_19;
    int pub_r001930_20;
    int pub_r001930_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001930_0 >= -100 && pub_r001930_0 <= 100);
    __CPROVER_assume(pub_r001930_1 >= -100 && pub_r001930_1 <= 100);
    __CPROVER_assume(pub_r001930_2 >= -100 && pub_r001930_2 <= 100);
    __CPROVER_assume(pub_r001930_3 >= -100 && pub_r001930_3 <= 100);
    __CPROVER_assume(pub_r001930_4 >= -100 && pub_r001930_4 <= 100);
    __CPROVER_assume(pub_r001930_5 >= -100 && pub_r001930_5 <= 100);
    __CPROVER_assume(pub_r001930_6 >= -100 && pub_r001930_6 <= 100);
    __CPROVER_assume(pub_r001930_7 >= -100 && pub_r001930_7 <= 100);
    __CPROVER_assume(pub_r001930_8 >= -100 && pub_r001930_8 <= 100);
    __CPROVER_assume(pub_r001930_9 >= -100 && pub_r001930_9 <= 100);
    __CPROVER_assume(pub_r001930_10 >= -100 && pub_r001930_10 <= 100);
    __CPROVER_assume(pub_r001930_11 >= -100 && pub_r001930_11 <= 100);
    __CPROVER_assume(pub_r001930_12 >= -100 && pub_r001930_12 <= 100);
    __CPROVER_assume(pub_r001930_13 >= -100 && pub_r001930_13 <= 100);
    __CPROVER_assume(pub_r001930_14 >= -100 && pub_r001930_14 <= 100);
    __CPROVER_assume(pub_r001930_15 >= -100 && pub_r001930_15 <= 100);
    __CPROVER_assume(pub_r001930_16 >= -100 && pub_r001930_16 <= 100);
    __CPROVER_assume(pub_r001930_17 >= -100 && pub_r001930_17 <= 100);
    __CPROVER_assume(pub_r001930_18 >= -100 && pub_r001930_18 <= 100);
    __CPROVER_assume(pub_r001930_19 >= -100 && pub_r001930_19 <= 100);
    __CPROVER_assume(pub_r001930_20 >= -100 && pub_r001930_20 <= 100);
    __CPROVER_assume(pub_r001930_21 >= -100 && pub_r001930_21 <= 100);
    __CPROVER_assume(sec_r001930_0 >= 0 && sec_r001930_0 <= 255);
    __CPROVER_assume(sec_r001930_1 >= 0 && sec_r001930_1 <= 255);
    __CPROVER_assume(sec_r001930_2 >= 0 && sec_r001930_2 <= 255);
    __CPROVER_assume(sec_r001930_3 >= 0 && sec_r001930_3 <= 255);
    __CPROVER_assume(sec_r001930_4 >= 0 && sec_r001930_4 <= 255);
    __CPROVER_assume(sec_r001930_5 >= 0 && sec_r001930_5 <= 255);
    __CPROVER_assume(sec_r001930_6 >= 0 && sec_r001930_6 <= 255);
    __CPROVER_assume(sec_r001930_7 >= 0 && sec_r001930_7 <= 255);
    __CPROVER_assume(sec_r001930_8 >= 0 && sec_r001930_8 <= 255);
    __CPROVER_assume(sec_r001930_9 >= 0 && sec_r001930_9 <= 255);
    __CPROVER_assume(sec_r001930_10 >= 0 && sec_r001930_10 <= 255);
    __CPROVER_assume(sec_r001930_11 >= 0 && sec_r001930_11 <= 255);
    __CPROVER_assume(sec_r001930_12 >= 0 && sec_r001930_12 <= 255);
    __CPROVER_assume(sec_r001930_13 >= 0 && sec_r001930_13 <= 255);
    __CPROVER_assume(sec_r001930_14 >= 0 && sec_r001930_14 <= 255);
    __CPROVER_assume(sec_r001930_15 >= 0 && sec_r001930_15 <= 255);
    __CPROVER_assume(sec_r001930_16 >= 0 && sec_r001930_16 <= 255);
    __CPROVER_assume(sec_r001930_17 >= 0 && sec_r001930_17 <= 255);

    struct AudioFrame_R001930_3013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001930_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001930_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001930_0 + 7) & 15;
    struct SensorNode_R001930_3013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001930_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001930_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001930_0 + 9) & 15;
    struct Transaction_R001930_3013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001930_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001930_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001930_0 + 11) & 15;
    struct DeviceConfig_R001930_3013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001930_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001930_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001930_0 + 13) & 15;

    union ColorPixel_R001930_3013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001930_3013_0(sec_r001930_0, pub_r001930_1, pub_r001930_2);
    int helper_flow_1 = fn_R001930_3013_1(sec_r001930_1, pub_r001930_2, pub_r001930_3, pub_r001930_4);
    int helper_flow_2 = fn_R001930_3013_2(sec_r001930_2, sec_r001930_3, pub_r001930_4, pub_r001930_5);
    int helper_flow_3 = fn_R001930_3013_3(sec_r001930_3, pub_r001930_4, pub_r001930_5);
    int helper_flow_4 = fn_R001930_3013_4(sec_r001930_4, sec_r001930_5);
    int helper_flow_5 = fn_R001930_3013_5(sec_r001930_5, pub_r001930_6, pub_r001930_7, pub_r001930_8);
    int helper_flow_6 = fn_R001930_3013_6(sec_r001930_6, sec_r001930_7, pub_r001930_8, pub_r001930_9);
    int helper_flow_7 = fn_R001930_3013_7(sec_r001930_7, sec_r001930_8, pub_r001930_9, pub_r001930_10, pub_r001930_11);
    int helper_flow_8 = fn_R001930_3013_8(sec_r001930_8, pub_r001930_9);
    int helper_flow_9 = fn_R001930_3013_9(sec_r001930_9, sec_r001930_10, pub_r001930_11);
    int helper_flow_10 = fn_R001930_3013_10(sec_r001930_10, pub_r001930_11);
    int helper_flow_11 = fn_R001930_3013_11(sec_r001930_11, sec_r001930_12, pub_r001930_13, pub_r001930_14);
    int helper_flow_12 = fn_R001930_3013_12(sec_r001930_12, sec_r001930_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001930_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_1 > 44) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001930_5 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_2 > 23) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001930_8 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_3 > 30) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_4 > 39) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001930_0 ^ 0x2A) * 2 + pub_r001930_0) & 127;
    if (stage_v_5 > 46) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001930_11 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_6 > 24) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001930_16 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_7 > 32) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001930_12 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_8 > 36) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001930_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_10 > 30) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001930_2 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_11 > 46) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001930_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_13 > 39) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_14 > 33) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001930_8) & 127;
    if (stage_v_15 > 23) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001930_4 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_16 > 24) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001930_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_18 > 32) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001930_14) & 127;
    if (stage_v_19 > 28) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_20 > 29) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001930_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001930_10 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_22 > 31) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001930_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001930_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_25 > 49) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001930_18) & 127;
    if (stage_v_26 > 26) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_27 > 50) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001930_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_29 > 35) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001930_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_31 > 27) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_32 > 46) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_33 > 37) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001930_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001930_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001930_0 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_36 > 20) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001930_14 ^ 0x2A) * 2 + pub_r001930_14) & 127;
    if (stage_v_37 > 41) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001930_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001930_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001930_5 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_40 > 39) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_41 > 28) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_42 > 23) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_43 > 26) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_44 > 30) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001930_17) & 127;
    if (stage_v_45 > 36) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001930_0 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_46 > 34) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001930_17) & 127;
    if (stage_v_47 > 47) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001930_20 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_49 > 36) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001930_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_51 > 36) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_52 > 47) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_53 > 49) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001930_2 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_54 > 22) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001930_15 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_55 > 45) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_56 > 25) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_57 > 43) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_58 > 33) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001930_7 ^ 0x2A) * 2 + pub_r001930_8) & 127;
    if (stage_v_59 > 47) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_60 > 42) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_61 > 21) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_62 > 39) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_63 > 44) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_64 > 44) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001930_12) & 127;
    if (stage_v_65 > 40) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_66 > 41) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001930_17 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_67 > 38) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_68 > 44) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001930_7 ^ 0x2A) * 2 + pub_r001930_21) & 127;
    if (stage_v_69 > 33) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_70 > 23) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_71 > 31) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_72 > 36) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001930_12 ^ 0x2A) * 2 + pub_r001930_0) & 127;
    if (stage_v_73 > 28) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001930_21 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001930_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001930_13 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_76 > 41) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001930_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_78 > 25) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_79 > 24) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001930_3) & 127;
    if (stage_v_80 > 22) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_81 > 47) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_82 > 28) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001930_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001930_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001930_8) & 127;
    if (stage_v_85 > 30) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_86 > 29) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001930_18) & 127;
    if (stage_v_87 > 22) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001930_7 ^ 0x2A) * 2 + pub_r001930_8) & 127;
    if (stage_v_88 > 50) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_89 > 29) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_90 > 32) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_91 > 44) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001930_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001930_1 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_93 > 42) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001930_0) & 127;
    if (stage_v_94 > 49) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001930_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001930_11 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_96 > 48) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001930_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_98 > 50) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001930_11 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_99 > 41) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_100 > 20) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001930_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001930_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_103 > 36) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001930_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_105 > 32) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_106 > 45) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001930_8) & 127;
    if (stage_v_107 > 49) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001930_3) & 127;
    if (stage_v_108 > 32) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_109 > 42) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001930_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_111 > 32) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001930_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001930_12) & 127;
    if (stage_v_113 > 47) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001930_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_115 > 26) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_116 > 31) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001930_14) & 127;
    if (stage_v_117 > 43) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_118 > 33) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001930_14 ^ 0x2A) * 2 + pub_r001930_12) & 127;
    if (stage_v_119 > 22) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001930_21) & 127;
    if (stage_v_120 > 49) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001930_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001930_17) & 127;
    if (stage_v_122 > 45) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001930_14 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_123 > 27) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_124 > 32) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_125 > 34) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001930_2 ^ 0x2A) * 2 + pub_r001930_12) & 127;
    if (stage_v_126 > 35) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_127 > 48) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001930_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001930_6 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_129 > 27) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_130 > 38) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001930_18) & 127;
    if (stage_v_131 > 24) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_132 > 22) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001930_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001930_3) & 127;
    if (stage_v_134 > 48) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001930_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_136 > 43) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001930_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001930_9 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_138 > 26) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_139 > 24) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001930_7 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_140 > 45) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001930_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_142 > 37) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_143 > 39) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001930_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_145 > 45) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_146 > 47) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001930_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001930_18) & 127;
    if (stage_v_148 > 40) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_149 > 43) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_150 > 25) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_151 > 47) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_153 > 46) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001930_2 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_154 > 22) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001930_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_156 > 32) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_157 > 38) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_158 > 40) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_159 > 45) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001930_6 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_160 > 46) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_161 > 46) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001930_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_146 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_163 > 37) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001930_0) & 127;
    if (stage_v_164 > 40) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001930_3) & 127;
    if (stage_v_165 > 25) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_166 > 36) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_167 > 36) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_168 > 26) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_169 > 32) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_170 > 47) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001930_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001930_18) & 127;
    if (stage_v_172 > 21) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_173 > 23) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001930_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001930_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001930_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001930_20) & 127;
    if (stage_v_177 > 26) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001930_17) & 127;
    if (stage_v_178 > 30) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_179 > 35) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001930_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r001930_0 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_181 > 43) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001930_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001930_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001930_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_185 > 45) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001930_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_187 > 22) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_188 > 40) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_189 > 31) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_190 > 28) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001930_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_192 > 24) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001930_10) & 127;
    if (stage_v_193 > 27) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_194 > 48) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_195 > 41) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001930_13) & 127;
    if (stage_v_196 > 25) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001930_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001930_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001930_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001930_18) & 127;
    if (stage_v_200 > 22) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_201 > 30) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_202 > 20) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001930_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_204 > 26) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001930_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001930_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_207 > 23) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_207 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_208 > 24) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001930_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001930_4) & 127;
    if (stage_v_210 > 42) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001930_15) & 127;
    if (stage_v_211 > 34) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001930_20 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001930_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001930_2) & 127;
    if (stage_v_214 > 47) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001930_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001930_11) & 127;
    if (stage_v_216 > 20) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r001930_16 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_217 > 20) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_218 > 42) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_219 > 43) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_220 > 29) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001930_17) & 127;
    if (stage_v_221 > 41) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001930_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_211 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_223 > 21) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001930_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001930_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001930_0) & 127;
    if (stage_v_226 > 40) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_202 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_227 > 26) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001930_6) & 127;
    if (stage_v_228 > 46) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001930_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001930_12) & 127;
    if (stage_v_230 > 32) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001930_5) & 127;
    if (stage_v_231 > 40) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001930_7) & 127;
    if (stage_v_232 > 35) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001930_19) & 127;
    if (stage_v_233 > 29) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001930_16) & 127;
    if (stage_v_234 > 26) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r001930_13 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_235 > 30) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_236 > 42) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001930_1) & 127;
    if (stage_v_237 > 44) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001930_9) & 127;
    if (stage_v_238 > 28) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
