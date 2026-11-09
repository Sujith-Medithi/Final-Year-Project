/*
 * Benchmark Program: R001143
 * Security Family: multi_step_explicit
 * Generator Seed: 614313
 * High Inputs: 19 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001143_4313_0 {
    int code;
    unsigned char timestamp;
    int seq;
    int facility;
    int signature;
    int buffer[3];
};

struct DeviceConfig_R001143_4313_1 {
    int port;
    short parity;
    unsigned char id;
    unsigned char stop_bits;
    int buffer[3];
};

union PacketPayload_R001143_4313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001143_4313_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001143_4313_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int bound_35 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_35 > 14) {
        acc = (acc + bound_35 * 2 + 5) & 127;
        aux ^= (bound_35 & 15);
    } else {
        acc = (acc - bound_35 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_93 = local_arr[aux % 3];
    acc = (acc + factor_93 * 2) & 127;
    int cursor_68 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_68 = (cursor_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_68) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001143_4313_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_93 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_93 > 31) {
        acc = (acc + parity_93 * 2 + 5) & 127;
        aux ^= (parity_93 & 15);
    } else {
        acc = (acc - parity_93 + 11) & 127;
        aux += 3;
    }
    int quantum_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001143_4313_2(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int window_64 = (st.buffer[0] * 3 + aux) & 63;
    if (window_64 > 49) {
        acc = (acc + window_64 * 2 + 5) & 127;
        aux ^= (window_64 & 15);
    } else {
        acc = (acc - window_64 + 11) & 127;
        aux += 3;
    }
    int damping_40 = (aux + st.buffer[1]) & 3;
    switch (damping_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001143_4313_3(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int sample_92 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_92 > 33) {
        acc = (acc + sample_92 * 2 + 5) & 127;
        aux ^= (sample_92 & 15);
    } else {
        acc = (acc - sample_92 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_78 = local_arr[aux % 3];
    acc = (acc + checksum_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001143_4313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001143_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int metric_99 = local_arr[aux % 3];
    acc = (acc + metric_99 * 2) & 127;
    int threshold_38 = (aux + st.buffer[1]) & 3;
    switch (threshold_38) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_94 = 0;
    for (int k = 0; k < 3; k++) {
        tally_94 = (tally_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001143_4313_5(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int cursor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_99 > 11) {
        acc = (acc + cursor_99 * 2 + 5) & 127;
        aux ^= (cursor_99 & 15);
    } else {
        acc = (acc - cursor_99 + 11) & 127;
        aux += 3;
    }
    int cursor_68 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_68 = (cursor_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_68) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_15 = local_arr[aux % 3];
    acc = (acc + stride_15 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001143_4313_6(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001143_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int metric_11 = (aux + st.buffer[1]) & 3;
    switch (metric_11) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_51 = 0;
    for (int k = 0; k < 2; k++) {
        vector_51 = (vector_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_51) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_29 = local_arr[aux % 3];
    acc = (acc + coefficient_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001143_4313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int mask_38 = 0;
    for (int k = 0; k < 3; k++) {
        mask_38 = (mask_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_38) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001143_4313_8(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001143_4313_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_98 = (aux + st.buffer[1]) & 3;
    switch (stride_98) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_88 = local_arr[aux % 3];
    acc = (acc + stride_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001143_4313_10(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_27) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_83 = local_arr[aux % 3];
    acc = (acc + threshold_83 * 2) & 127;
    int sample_11 = (aux + st.buffer[1]) & 3;
    switch (sample_11) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001143_4313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int index_reg_91 = local_arr[aux % 3];
    acc = (acc + index_reg_91 * 2) & 127;
    int weight_91 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_91 > 20) {
        acc = (acc + weight_91 * 2 + 5) & 127;
        aux ^= (weight_91 & 15);
    } else {
        acc = (acc - weight_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001143_4313_12(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_60 = (aux + st.buffer[1]) & 3;
    switch (factor_60) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001143_4313_13(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001143_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tracker_84 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_84 > 33) {
        acc = (acc + tracker_84 * 2 + 5) & 127;
        aux ^= (tracker_84 & 15);
    } else {
        acc = (acc - tracker_84 + 11) & 127;
        aux += 3;
    }
    int checksum_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001143_4313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001143_4313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int sample_20 = 0;
    for (int k = 0; k < 2; k++) {
        sample_20 = (sample_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_20) & 127;
    }
    int vector_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001143_4313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001143_4313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_25 = local_arr[aux % 3];
    acc = (acc + margin_25 * 2) & 127;
    int scale_67 = (aux + st.buffer[1]) & 3;
    switch (scale_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001143_0;
    int sec_r001143_1;
    int sec_r001143_2;
    int sec_r001143_3;
    int sec_r001143_4;
    int sec_r001143_5;
    int sec_r001143_6;
    int sec_r001143_7;
    int sec_r001143_8;
    int sec_r001143_9;
    int sec_r001143_10;
    int sec_r001143_11;
    int sec_r001143_12;
    int sec_r001143_13;
    int sec_r001143_14;
    int sec_r001143_15;
    int sec_r001143_16;
    int sec_r001143_17;
    int sec_r001143_18;
    int pub_r001143_0;
    int pub_r001143_1;
    int pub_r001143_2;
    int pub_r001143_3;
    int pub_r001143_4;
    int pub_r001143_5;
    int pub_r001143_6;
    int pub_r001143_7;
    int pub_r001143_8;
    int pub_r001143_9;
    int pub_r001143_10;
    int pub_r001143_11;
    int pub_r001143_12;
    int pub_r001143_13;
    int pub_r001143_14;
    int pub_r001143_15;
    int pub_r001143_16;
    int pub_r001143_17;
    int pub_r001143_18;
    int pub_r001143_19;
    int pub_r001143_20;
    int pub_r001143_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001143_0 >= -100 && pub_r001143_0 <= 100);
    __CPROVER_assume(pub_r001143_1 >= -100 && pub_r001143_1 <= 100);
    __CPROVER_assume(pub_r001143_2 >= -100 && pub_r001143_2 <= 100);
    __CPROVER_assume(pub_r001143_3 >= -100 && pub_r001143_3 <= 100);
    __CPROVER_assume(pub_r001143_4 >= -100 && pub_r001143_4 <= 100);
    __CPROVER_assume(pub_r001143_5 >= -100 && pub_r001143_5 <= 100);
    __CPROVER_assume(pub_r001143_6 >= -100 && pub_r001143_6 <= 100);
    __CPROVER_assume(pub_r001143_7 >= -100 && pub_r001143_7 <= 100);
    __CPROVER_assume(pub_r001143_8 >= -100 && pub_r001143_8 <= 100);
    __CPROVER_assume(pub_r001143_9 >= -100 && pub_r001143_9 <= 100);
    __CPROVER_assume(pub_r001143_10 >= -100 && pub_r001143_10 <= 100);
    __CPROVER_assume(pub_r001143_11 >= -100 && pub_r001143_11 <= 100);
    __CPROVER_assume(pub_r001143_12 >= -100 && pub_r001143_12 <= 100);
    __CPROVER_assume(pub_r001143_13 >= -100 && pub_r001143_13 <= 100);
    __CPROVER_assume(pub_r001143_14 >= -100 && pub_r001143_14 <= 100);
    __CPROVER_assume(pub_r001143_15 >= -100 && pub_r001143_15 <= 100);
    __CPROVER_assume(pub_r001143_16 >= -100 && pub_r001143_16 <= 100);
    __CPROVER_assume(pub_r001143_17 >= -100 && pub_r001143_17 <= 100);
    __CPROVER_assume(pub_r001143_18 >= -100 && pub_r001143_18 <= 100);
    __CPROVER_assume(pub_r001143_19 >= -100 && pub_r001143_19 <= 100);
    __CPROVER_assume(pub_r001143_20 >= -100 && pub_r001143_20 <= 100);
    __CPROVER_assume(pub_r001143_21 >= -100 && pub_r001143_21 <= 100);
    __CPROVER_assume(sec_r001143_0 >= 0 && sec_r001143_0 <= 255);
    __CPROVER_assume(sec_r001143_1 >= 0 && sec_r001143_1 <= 255);
    __CPROVER_assume(sec_r001143_2 >= 0 && sec_r001143_2 <= 255);
    __CPROVER_assume(sec_r001143_3 >= 0 && sec_r001143_3 <= 255);
    __CPROVER_assume(sec_r001143_4 >= 0 && sec_r001143_4 <= 255);
    __CPROVER_assume(sec_r001143_5 >= 0 && sec_r001143_5 <= 255);
    __CPROVER_assume(sec_r001143_6 >= 0 && sec_r001143_6 <= 255);
    __CPROVER_assume(sec_r001143_7 >= 0 && sec_r001143_7 <= 255);
    __CPROVER_assume(sec_r001143_8 >= 0 && sec_r001143_8 <= 255);
    __CPROVER_assume(sec_r001143_9 >= 0 && sec_r001143_9 <= 255);
    __CPROVER_assume(sec_r001143_10 >= 0 && sec_r001143_10 <= 255);
    __CPROVER_assume(sec_r001143_11 >= 0 && sec_r001143_11 <= 255);
    __CPROVER_assume(sec_r001143_12 >= 0 && sec_r001143_12 <= 255);
    __CPROVER_assume(sec_r001143_13 >= 0 && sec_r001143_13 <= 255);
    __CPROVER_assume(sec_r001143_14 >= 0 && sec_r001143_14 <= 255);
    __CPROVER_assume(sec_r001143_15 >= 0 && sec_r001143_15 <= 255);
    __CPROVER_assume(sec_r001143_16 >= 0 && sec_r001143_16 <= 255);
    __CPROVER_assume(sec_r001143_17 >= 0 && sec_r001143_17 <= 255);
    __CPROVER_assume(sec_r001143_18 >= 0 && sec_r001143_18 <= 255);

    struct EventLog_R001143_4313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001143_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001143_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001143_0 + 7) & 15;
    struct DeviceConfig_R001143_4313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001143_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001143_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001143_0 + 9) & 15;

    union PacketPayload_R001143_4313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001143_4313_0(sec_r001143_0, pub_r001143_1, pub_r001143_2, pub_r001143_3);
    int helper_flow_1 = fn_R001143_4313_1(sec_r001143_1, pub_r001143_2, pub_r001143_3, pub_r001143_4);
    int helper_flow_2 = fn_R001143_4313_2(sec_r001143_2, sec_r001143_3);
    int helper_flow_3 = fn_R001143_4313_3(sec_r001143_3, sec_r001143_4, pub_r001143_5);
    int helper_flow_4 = fn_R001143_4313_4(sec_r001143_4, sec_r001143_5, pub_r001143_6, pub_r001143_7);
    int helper_flow_5 = fn_R001143_4313_5(sec_r001143_5, sec_r001143_6);
    int helper_flow_6 = fn_R001143_4313_6(sec_r001143_6, pub_r001143_7, pub_r001143_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001143_8 * 3) + pub_r001143_4 + 43) & 127;
    sec_accum = (sec_accum + stage_v_0) & 255;
    out_sink = (out_sink + stage_v_0 * 2) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001143_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001143_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001143_20 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001143_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001143_3 * 3) + pub_r001143_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_3 * 3) + pub_r001143_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001143_11 * 3) + pub_r001143_10 + 34) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001143_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001143_9 * 3) + pub_r001143_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001143_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_0 * 3) + pub_r001143_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_11) & 255;
    out_sink = (out_sink + stage_v_11 * 2) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001143_18 * 3) + pub_r001143_21 + 32) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_6 * 3) + pub_r001143_20 + 45) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001143_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001143_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_2 * 3) + pub_r001143_20 + 44) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001143_12 * 3) + pub_r001143_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001143_18 * 3) + pub_r001143_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001143_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001143_0 * 3) + pub_r001143_6 + 45) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001143_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001143_13 * 3) + pub_r001143_11 + 31) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_18 * 3) + pub_r001143_1 + 18) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001143_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001143_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001143_21 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001143_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001143_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001143_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001143_2 * 3) + pub_r001143_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30 * 2) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001143_21 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001143_18 * 3) + pub_r001143_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001143_8 * 3) + pub_r001143_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001143_1 * 3) + pub_r001143_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001143_5 * 3) + pub_r001143_16 + 5) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001143_6 * 3) + pub_r001143_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001143_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001143_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001143_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001143_13 * 3) + pub_r001143_17 + 28) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001143_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_30 * 3) + pub_r001143_0 + 38) & 127;
    sec_accum = (sec_accum + stage_v_42) & 255;
    out_sink = (out_sink + stage_v_42 * 2) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_4 * 3) + pub_r001143_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_0 * 3) + pub_r001143_4 + 21) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001143_11 * 3) + pub_r001143_16 + 37) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45 * 2) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001143_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_7 * 3) + pub_r001143_14 + 26) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_1 * 3) + pub_r001143_14 + 15) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_20 * 3) + pub_r001143_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49 * 2) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_0 * 3) + pub_r001143_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_36 * 3) + pub_r001143_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_6 * 3) + pub_r001143_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52 * 2) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_6 * 3) + pub_r001143_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_34 * 3) + pub_r001143_1 + 43) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001143_16 * 3) + pub_r001143_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55 * 2) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_45 * 3) + pub_r001143_1 + 45) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56 * 2) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_47 * 3) + pub_r001143_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001143_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001143_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001143_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_40 * 3) + pub_r001143_19 + 36) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61 * 2) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001143_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_52 * 3) + pub_r001143_6 + 20) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001143_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001143_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_6 * 3) + pub_r001143_0 + 30) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001143_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001143_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001143_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_42 * 3) + pub_r001143_1 + 45) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70 * 2) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_6 * 3) + pub_r001143_20 + 11) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_33 * 3) + pub_r001143_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_72 * 3) + pub_r001143_0 + 20) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73 * 2) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001143_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_0 * 3) + pub_r001143_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75 * 2) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001143_1 * 3) + pub_r001143_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76 * 2) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001143_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_49 * 3) + pub_r001143_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001143_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001143_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_3 * 3) + pub_r001143_21 + 21) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001143_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_50 * 3) + pub_r001143_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_11 * 3) + pub_r001143_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001143_8 * 3) + pub_r001143_18 + 17) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001143_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001143_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001143_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001143_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001143_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_43 * 3) + pub_r001143_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001143_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_54 * 3) + pub_r001143_18 + 33) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_76 * 3) + pub_r001143_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94 * 2) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_66 * 3) + pub_r001143_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95 * 2) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_3 * 3) + pub_r001143_20 + 22) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_83 * 3) + pub_r001143_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_11 * 3) + pub_r001143_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001143_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001143_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_18 * 3) + pub_r001143_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_53 * 3) + pub_r001143_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102 * 2) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001143_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001143_9 * 3) + pub_r001143_19 + 21) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001143_11 * 3) + pub_r001143_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105 * 2) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001143_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001143_11 * 3) + pub_r001143_14 + 4) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107 * 2) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001143_2 * 3) + pub_r001143_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001143_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_30 * 3) + pub_r001143_5 + 3) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001143_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001143_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_96 * 3) + pub_r001143_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_2 * 3) + pub_r001143_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114 * 2) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_75 * 3) + pub_r001143_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115 * 2) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001143_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001143_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001143_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_17 * 3) + pub_r001143_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_55 * 3) + pub_r001143_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001143_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_18 * 3) + pub_r001143_4 + 16) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001143_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001143_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001143_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001143_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_1 * 3) + pub_r001143_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001143_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_57 * 3) + pub_r001143_19 + 43) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_93 * 3) + pub_r001143_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_97 * 3) + pub_r001143_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001143_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_56 * 3) + pub_r001143_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_114 * 3) + pub_r001143_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001143_17 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_85 * 3) + pub_r001143_17 + 43) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_129 * 3) + pub_r001143_0 + 40) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_102 * 3) + pub_r001143_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001143_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001143_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001143_1 * 3) + pub_r001143_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001143_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_81 * 3) + pub_r001143_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001143_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001143_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001143_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001143_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_56 * 3) + pub_r001143_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_56 * 3) + pub_r001143_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149 * 2) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001143_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001143_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001143_13 * 3) + pub_r001143_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001143_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_120 * 3) + pub_r001143_1 + 36) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_152 * 3) + pub_r001143_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155 * 2) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001143_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_137 * 3) + pub_r001143_21 + 31) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001143_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_107 * 3) + pub_r001143_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159 * 2) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_137 * 3) + pub_r001143_0 + 10) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001143_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_95 * 3) + pub_r001143_21 + 29) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001143_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r001143_8 * 3) + pub_r001143_4 + 43) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_160 * 3) + pub_r001143_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_52 * 3) + pub_r001143_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001143_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r001143_17 * 3) + pub_r001143_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001143_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_134 * 3) + pub_r001143_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001143_20 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001143_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001143_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001143_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001143_17 * 3) + pub_r001143_20 + 13) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_119 * 3) + pub_r001143_10 + 7) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_148 * 3) + pub_r001143_20 + 30) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177 * 2) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_16 * 3) + pub_r001143_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001143_4 * 3) + pub_r001143_21 + 40) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001143_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001143_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((helper_flow_1 * 3) + pub_r001143_7 + 12) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001143_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001143_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_44 * 3) + pub_r001143_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001143_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_13 * 3) + pub_r001143_20 + 22) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_152 * 3) + pub_r001143_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188 * 2) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_152 * 3) + pub_r001143_20 + 42) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189 * 2) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001143_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_154 * 3) + pub_r001143_19 + 11) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_17 * 3) + pub_r001143_1 + 45) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192 * 2) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_66 * 3) + pub_r001143_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r001143_2 * 3) + pub_r001143_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_127 * 3) + pub_r001143_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001143_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_191 * 3) + pub_r001143_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((helper_flow_3 * 3) + pub_r001143_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001143_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001143_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_164 * 3) + pub_r001143_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201 * 2) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001143_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001143_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_114 * 3) + pub_r001143_6 + 21) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001143_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001143_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001143_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((helper_flow_3 * 3) + pub_r001143_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001143_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_143 * 3) + pub_r001143_18 + 41) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001143_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001143_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_44 * 3) + pub_r001143_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001143_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001143_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_98 * 3) + pub_r001143_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_138 * 3) + pub_r001143_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_159 * 3) + pub_r001143_21 + 27) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r001143_4 * 3) + pub_r001143_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r001143_3 * 3) + pub_r001143_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001143_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_42 * 3) + pub_r001143_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_143 * 3) + pub_r001143_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((sec_r001143_7 * 3) + pub_r001143_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001143_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_220 * 3) + pub_r001143_12 + 14) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_185 * 3) + pub_r001143_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001143_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_197 * 3) + pub_r001143_3 + 42) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001143_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_218 * 3) + pub_r001143_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231 * 2) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001143_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_185 * 3) + pub_r001143_17 + 42) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_210 * 3) + pub_r001143_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001143_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001143_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_217 * 3) + pub_r001143_19 + 16) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001143_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_218 * 3) + pub_r001143_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_192 * 3) + pub_r001143_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240 * 2) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001143_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001143_20 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001143_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_165 * 3) + pub_r001143_14 + 21) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001143_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001143_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001143_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001143_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001143_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_20 * 3) + pub_r001143_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250 * 2) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_81 * 3) + pub_r001143_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001143_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_17 * 3) + pub_r001143_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_30 * 3) + pub_r001143_19 + 33) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001143_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001143_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001143_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001143_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001143_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001143_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_189 * 3) + pub_r001143_4 + 36) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261 * 2) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001143_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_7 * 3) + pub_r001143_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263 * 2) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_170 * 3) + pub_r001143_8 + 31) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264 * 2) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001143_21 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001143_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_138 * 3) + pub_r001143_19 + 22) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((helper_flow_3 * 3) + pub_r001143_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_239 * 3) + pub_r001143_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269 * 2) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_51 * 3) + pub_r001143_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001143_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001143_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_157 * 3) + pub_r001143_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001143_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001143_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_35 * 3) + pub_r001143_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((helper_flow_1 * 3) + pub_r001143_14 + 4) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_160 * 3) + pub_r001143_20 + 7) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_73 * 3) + pub_r001143_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279 * 2) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001143_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001143_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001143_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001143_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_72 * 3) + pub_r001143_20 + 9) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_168 * 3) + pub_r001143_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001143_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001143_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_76 * 3) + pub_r001143_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288 * 2) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001143_20 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_273 * 3) + pub_r001143_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001143_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_168 * 3) + pub_r001143_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001143_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r001143_9 * 3) + pub_r001143_21 + 32) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001143_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_78 * 3) + pub_r001143_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_108 * 3) + pub_r001143_19 + 29) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297 * 2) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_234 * 3) + pub_r001143_20 + 5) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298 * 2) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_11 * 3) + pub_r001143_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299 * 2) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001143_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001143_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_129 * 3) + pub_r001143_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001143_20 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_227 * 3) + pub_r001143_8 + 44) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001143_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001143_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001143_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_52 * 3) + pub_r001143_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308 * 2) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_56 * 3) + pub_r001143_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_165 * 3) + pub_r001143_19 + 43) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001143_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001143_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_177 * 3) + pub_r001143_20 + 31) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313 * 2) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001143_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_277 * 3) + pub_r001143_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315 * 2) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_108 * 3) + pub_r001143_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001143_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001143_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001143_20 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_294 * 3) + pub_r001143_12 + 45) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_296 * 3) + pub_r001143_1 + 43) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_162 * 3) + pub_r001143_10 + 39) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_198 * 3) + pub_r001143_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001143_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001143_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001143_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_261 * 3) + pub_r001143_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001143_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001143_21 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_240 * 3) + pub_r001143_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_310 * 3) + pub_r001143_11 + 7) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_85 * 3) + pub_r001143_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_321 * 3) + pub_r001143_4 + 21) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001143_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001143_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001143_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001143_2 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001143_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001143_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_98 * 3) + pub_r001143_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_193 * 3) + pub_r001143_21 + 11) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001143_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_219 * 3) + pub_r001143_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001143_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_104 * 3) + pub_r001143_18 + 9) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001143_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_310 * 3) + pub_r001143_0 + 20) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_104 * 3) + pub_r001143_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_277 * 3) + pub_r001143_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001143_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_340 * 3) + pub_r001143_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001143_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_119 * 3) + pub_r001143_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((sec_r001143_2 * 3) + pub_r001143_21 + 16) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354 * 2) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001143_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_348 * 3) + pub_r001143_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001143_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_308 * 3) + pub_r001143_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_113 * 3) + pub_r001143_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_52 * 3) + pub_r001143_2 + 4) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001143_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_332 * 3) + pub_r001143_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362 * 2) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001143_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001143_19 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001143_21 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001143_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_95 * 3) + pub_r001143_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_97 * 3) + pub_r001143_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_178 * 3) + pub_r001143_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_369) & 255;
    out_sink = (out_sink + stage_v_369 * 2) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001143_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_240 * 3) + pub_r001143_20 + 4) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001143_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_33 * 3) + pub_r001143_19 + 10) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001143_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001143_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001143_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_33 * 3) + pub_r001143_11 + 42) & 127;
    sec_accum = (sec_accum + stage_v_377) & 255;
    out_sink = (out_sink + stage_v_377 * 2) & 255;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001143_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_362 * 3) + pub_r001143_21 + 11) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_332 * 3) + pub_r001143_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001143_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_66 * 3) + pub_r001143_16 + 30) & 127;
    sec_accum = (sec_accum + stage_v_382) & 255;
    out_sink = (out_sink + stage_v_382 * 2) & 255;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001143_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_54 * 3) + pub_r001143_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001143_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001143_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001143_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_47 * 3) + pub_r001143_13 + 30) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_114 * 3) + pub_r001143_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001143_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001143_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((sec_r001143_4 * 3) + pub_r001143_17 + 11) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001143_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_331 * 3) + pub_r001143_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_359 * 3) + pub_r001143_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001143_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_267 * 3) + pub_r001143_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001143_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001143_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001143_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_43 * 3) + pub_r001143_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001143_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001143_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_134 * 3) + pub_r001143_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_367 * 3) + pub_r001143_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001143_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001143_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001143_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((sec_r001143_3 * 3) + pub_r001143_16 + 42) & 127;
    sec_accum = (sec_accum + stage_v_409) & 255;
    out_sink = (out_sink + stage_v_409 * 2) & 255;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001143_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_234 * 3) + pub_r001143_2 + 40) & 127;
    sec_accum = (sec_accum + stage_v_411) & 255;
    out_sink = (out_sink + stage_v_411 * 2) & 255;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_127 * 3) + pub_r001143_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001143_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001143_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_164 * 3) + pub_r001143_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001143_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001143_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001143_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001143_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001143_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001143_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001143_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001143_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_240 * 3) + pub_r001143_16 + 14) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_412 * 3) + pub_r001143_17 + 16) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_61 * 3) + pub_r001143_21 + 20) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_379 * 3) + pub_r001143_17 + 41) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001143_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((sec_r001143_4 * 3) + pub_r001143_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_429) & 255;
    out_sink = (out_sink + stage_v_429 * 2) & 255;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001143_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_368 * 3) + pub_r001143_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_431) & 255;
    out_sink = (out_sink + stage_v_431 * 2) & 255;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001143_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001143_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_189 * 3) + pub_r001143_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_434) & 255;
    out_sink = (out_sink + stage_v_434 * 2) & 255;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001143_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001143_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001143_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((sec_r001143_18 * 3) + pub_r001143_17 + 30) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_351 * 3) + pub_r001143_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_160 * 3) + pub_r001143_19 + 38) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001143_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((helper_flow_1 * 3) + pub_r001143_9 + 38) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_55 * 3) + pub_r001143_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001143_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_175 * 3) + pub_r001143_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_445) & 255;
    out_sink = (out_sink + stage_v_445 * 2) & 255;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_354 * 3) + pub_r001143_11 + 29) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001143_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_358 * 3) + pub_r001143_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_22 * 3) + pub_r001143_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_189 * 3) + pub_r001143_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001143_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_104 * 3) + pub_r001143_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001143_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_395 * 3) + pub_r001143_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_454) & 255;
    out_sink = (out_sink + stage_v_454 * 2) & 255;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001143_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001143_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_168 * 3) + pub_r001143_18 + 19) & 127;
    sec_accum = (sec_accum + stage_v_457) & 255;
    out_sink = (out_sink + stage_v_457 * 2) & 255;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_107 * 3) + pub_r001143_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_458) & 255;
    out_sink = (out_sink + stage_v_458 * 2) & 255;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001143_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_310 * 3) + pub_r001143_1 + 27) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_110 * 3) + pub_r001143_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001143_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_70 * 3) + pub_r001143_0 + 9) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_315 * 3) + pub_r001143_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_464) & 255;
    out_sink = (out_sink + stage_v_464 * 2) & 255;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_304 * 3) + pub_r001143_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_465) & 255;
    out_sink = (out_sink + stage_v_465 * 2) & 255;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001143_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001143_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_114 * 3) + pub_r001143_13 + 22) & 127;
    sec_accum = (sec_accum + stage_v_468) & 255;
    out_sink = (out_sink + stage_v_468 * 2) & 255;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((stage_v_356 * 3) + pub_r001143_20 + 19) & 127;
    sec_accum = (sec_accum + stage_v_469) & 255;
    out_sink = (out_sink + stage_v_469 * 2) & 255;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((stage_v_309 * 3) + pub_r001143_5 + 17) & 127;
    sec_accum = (sec_accum + stage_v_470) & 255;
    out_sink = (out_sink + stage_v_470 * 2) & 255;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_341 * 3) + pub_r001143_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001143_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001143_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_395 * 3) + pub_r001143_20 + 28) & 127;
    sec_accum = (sec_accum + stage_v_474) & 255;
    out_sink = (out_sink + stage_v_474 * 2) & 255;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_91 * 3) + pub_r001143_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001143_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001143_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = ((stage_v_91 * 3) + pub_r001143_15 + 41) & 127;
    sec_accum = (sec_accum + stage_v_478) & 255;
    out_sink = (out_sink + stage_v_478 * 2) & 255;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001143_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001143_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001143_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001143_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = ((stage_v_425 * 3) + pub_r001143_15 + 18) & 127;
    sec_accum = (sec_accum + stage_v_483) & 255;
    out_sink = (out_sink + stage_v_483 * 2) & 255;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001143_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = ((stage_v_93 * 3) + pub_r001143_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_485) & 255;
    out_sink = (out_sink + stage_v_485 * 2) & 255;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001143_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_231 * 3) + pub_r001143_4 + 41) & 127;
    sec_accum = (sec_accum + stage_v_487) & 255;
    out_sink = (out_sink + stage_v_487 * 2) & 255;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((sec_r001143_4 * 3) + pub_r001143_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_488) & 255;
    out_sink = (out_sink + stage_v_488 * 2) & 255;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = ((stage_v_141 * 3) + pub_r001143_8 + 17) & 127;
    sec_accum = (sec_accum + stage_v_489) & 255;
    out_sink = (out_sink + stage_v_489 * 2) & 255;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001143_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001143_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001143_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001143_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = (pub_r001143_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_494) & 127;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = (pub_r001143_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_495) & 127;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = ((stage_v_63 * 3) + pub_r001143_15 + 27) & 127;
    sec_accum = (sec_accum + stage_v_496) & 255;
    out_sink = (out_sink + stage_v_496 * 2) & 255;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001143_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001143_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = ((stage_v_269 * 3) + pub_r001143_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_499) & 255;
    out_sink = (out_sink + stage_v_499 * 2) & 255;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = ((stage_v_489 * 3) + pub_r001143_20 + 24) & 127;
    sec_accum = (sec_accum + stage_v_500) & 255;
    out_sink = (out_sink + stage_v_500 * 2) & 255;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001143_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001143_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001143_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = ((stage_v_461 * 3) + pub_r001143_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_504) & 255;
    out_sink = (out_sink + stage_v_504 * 2) & 255;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = ((stage_v_96 * 3) + pub_r001143_21 + 14) & 127;
    sec_accum = (sec_accum + stage_v_505) & 255;
    out_sink = (out_sink + stage_v_505 * 2) & 255;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = ((stage_v_267 * 3) + pub_r001143_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_506) & 255;
    out_sink = (out_sink + stage_v_506 * 2) & 255;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = ((stage_v_489 * 3) + pub_r001143_17 + 36) & 127;
    sec_accum = (sec_accum + stage_v_507) & 255;
    out_sink = (out_sink + stage_v_507 * 2) & 255;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001143_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = ((stage_v_369 * 3) + pub_r001143_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_509) & 255;
    out_sink = (out_sink + stage_v_509 * 2) & 255;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = ((stage_v_320 * 3) + pub_r001143_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_510) & 255;
    out_sink = (out_sink + stage_v_510 * 2) & 255;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001143_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = (pub_r001143_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_512) & 127;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = ((stage_v_97 * 3) + pub_r001143_21 + 39) & 127;
    sec_accum = (sec_accum + stage_v_513) & 255;
    out_sink = (out_sink + stage_v_513 * 2) & 255;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_463 * 3) + pub_r001143_19 + 4) & 127;
    sec_accum = (sec_accum + stage_v_514) & 255;
    out_sink = (out_sink + stage_v_514 * 2) & 255;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = (pub_r001143_21 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_515) & 127;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = ((stage_v_197 * 3) + pub_r001143_17 + 24) & 127;
    sec_accum = (sec_accum + stage_v_516) & 255;
    out_sink = (out_sink + stage_v_516 * 2) & 255;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001143_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = ((stage_v_448 * 3) + pub_r001143_13 + 45) & 127;
    sec_accum = (sec_accum + stage_v_518) & 255;
    out_sink = (out_sink + stage_v_518 * 2) & 255;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = ((stage_v_264 * 3) + pub_r001143_20 + 33) & 127;
    sec_accum = (sec_accum + stage_v_519) & 255;
    out_sink = (out_sink + stage_v_519 * 2) & 255;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = ((stage_v_219 * 3) + pub_r001143_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_520) & 255;
    out_sink = (out_sink + stage_v_520 * 2) & 255;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = (pub_r001143_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_521) & 127;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = (pub_r001143_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_522) & 127;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = (pub_r001143_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_523) & 127;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = (pub_r001143_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_524) & 127;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = (pub_r001143_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_525) & 127;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = (pub_r001143_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_526) & 127;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = (pub_r001143_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_527) & 127;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = ((stage_v_268 * 3) + pub_r001143_18 + 10) & 127;
    sec_accum = (sec_accum + stage_v_528) & 255;
    out_sink = (out_sink + stage_v_528 * 2) & 255;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = ((stage_v_188 * 3) + pub_r001143_21 + 33) & 127;
    sec_accum = (sec_accum + stage_v_529) & 255;
    out_sink = (out_sink + stage_v_529 * 2) & 255;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = (pub_r001143_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_530) & 127;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = (pub_r001143_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_531) & 127;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = ((stage_v_316 * 3) + pub_r001143_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_532) & 255;
    out_sink = (out_sink + stage_v_532 * 2) & 255;

    /* Execution Pipeline Stage 533 */
    int stage_v_533 = ((stage_v_343 * 3) + pub_r001143_20 + 41) & 127;
    sec_accum = (sec_accum + stage_v_533) & 255;
    out_sink = (out_sink + stage_v_533 * 2) & 255;

    /* Execution Pipeline Stage 534 */
    int stage_v_534 = (pub_r001143_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_534) & 127;

    /* Execution Pipeline Stage 535 */
    int stage_v_535 = (pub_r001143_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_535) & 127;

    /* Execution Pipeline Stage 536 */
    int stage_v_536 = ((stage_v_425 * 3) + pub_r001143_14 + 4) & 127;
    sec_accum = (sec_accum + stage_v_536) & 255;
    out_sink = (out_sink + stage_v_536 * 2) & 255;

    /* Execution Pipeline Stage 537 */
    int stage_v_537 = ((stage_v_223 * 3) + pub_r001143_0 + 4) & 127;
    sec_accum = (sec_accum + stage_v_537) & 255;
    out_sink = (out_sink + stage_v_537 * 2) & 255;

    /* Execution Pipeline Stage 538 */
    int stage_v_538 = (pub_r001143_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_538) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
