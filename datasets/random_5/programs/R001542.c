/*
 * Benchmark Program: R001542
 * Security Family: direct_leakage
 * Generator Seed: 654213
 * High Inputs: 17 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R001542_4213_0 {
    int density;
    int dim;
    int scale;
    int buffer[3];
};

struct FilterState_R001542_4213_1 {
    short prev_in;
    short prev_out;
    short damping;
    short mode;
    int buffer[3];
};

struct AudioFrame_R001542_4213_2 {
    int rms;
    int sample_rate;
    int gain;
    unsigned char envelope;
    int peak;
    int buffer[3];
};

struct DeviceConfig_R001542_4213_3 {
    int baud_rate;
    unsigned char port;
    int id;
    int buffer[3];
};

union RegisterBank_R001542_4213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001542_4213_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quantum_40 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_40 = (quantum_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_40) & 127;
    }
    int mask_20 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_20 > 49) {
        acc = (acc + mask_20 * 2 + 5) & 127;
        aux ^= (mask_20 & 15);
    } else {
        acc = (acc - mask_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001542_4213_1(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001542_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_89 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_89 > 29) {
        acc = (acc + offset_89 * 2 + 5) & 127;
        aux ^= (offset_89 & 15);
    } else {
        acc = (acc - offset_89 + 11) & 127;
        aux += 3;
    }
    int vector_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_60) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001542_4213_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001542_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_38 = (aux + st.buffer[1]) & 3;
    switch (weight_38) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_66 = 0;
    for (int k = 0; k < 3; k++) {
        segment_66 = (segment_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_66) & 127;
    }
    int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001542_4213_3(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001542_4213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_12 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_12 = (coefficient_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_12) & 127;
    }
    int parity_75 = (aux + st.buffer[1]) & 3;
    switch (parity_75) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_53 = local_arr[aux % 3];
    acc = (acc + cursor_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001542_4213_4(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001542_4213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int factor_16 = (aux + st.buffer[1]) & 3;
    switch (factor_16) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_79 = local_arr[aux % 3];
    acc = (acc + tracker_79 * 2) & 127;
    int damping_76 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_76 > 18) {
        acc = (acc + damping_76 * 2 + 5) & 127;
        aux ^= (damping_76 & 15);
    } else {
        acc = (acc - damping_76 + 11) & 127;
        aux += 3;
    }
    int quantum_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001542_4213_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001542_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int phase_55 = local_arr[aux % 3];
    acc = (acc + phase_55 * 2) & 127;
    int metric_90 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_90 > 27) {
        acc = (acc + metric_90 * 2 + 5) & 127;
        aux ^= (metric_90 & 15);
    } else {
        acc = (acc - metric_90 + 11) & 127;
        aux += 3;
    }
    int tracker_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001542_4213_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001542_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int margin_76 = (aux + st.buffer[1]) & 3;
    switch (margin_76) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_84 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_84 > 30) {
        acc = (acc + residue_84 * 2 + 5) & 127;
        aux ^= (residue_84 & 15);
    } else {
        acc = (acc - residue_84 + 11) & 127;
        aux += 3;
    }
    int bound_86 = 0;
    for (int k = 0; k < 3; k++) {
        bound_86 = (bound_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_86) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001542_4213_7(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int offset_49 = (aux + st.buffer[1]) & 3;
    switch (offset_49) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001542_4213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001542_4213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_69 = local_arr[aux % 3];
    acc = (acc + sample_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001542_4213_9(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001542_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_33 = (aux + st.buffer[1]) & 3;
    switch (margin_33) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001542_4213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001542_4213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_43 = 0;
    for (int k = 0; k < 2; k++) {
        offset_43 = (offset_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_43) & 127;
    }
    int coefficient_37 = (aux + st.buffer[1]) & 3;
    switch (coefficient_37) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001542_4213_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001542_4213_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_94 = 0;
    for (int k = 0; k < 3; k++) {
        margin_94 = (margin_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_94) & 127;
    }
    int delta_21 = (aux + st.buffer[1]) & 3;
    switch (delta_21) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001542_4213_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001542_4213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int sample_67 = local_arr[aux % 3];
    acc = (acc + sample_67 * 2) & 127;
    int weight_65 = 0;
    for (int k = 0; k < 2; k++) {
        weight_65 = (weight_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001542_4213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001542_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int cursor_46 = local_arr[aux % 3];
    acc = (acc + cursor_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_57 = (aux + st.buffer[1]) & 3;
    switch (phase_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_19 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_19 > 33) {
        acc = (acc + tally_19 * 2 + 5) & 127;
        aux ^= (tally_19 & 15);
    } else {
        acc = (acc - tally_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001542_4213_14(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001542_4213_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_89 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_89 > 15) {
        acc = (acc + tracker_89 * 2 + 5) & 127;
        aux ^= (tracker_89 & 15);
    } else {
        acc = (acc - tracker_89 + 11) & 127;
        aux += 3;
    }
    int residue_51 = 0;
    for (int k = 0; k < 2; k++) {
        residue_51 = (residue_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_51) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_60 = local_arr[aux % 3];
    acc = (acc + metric_60 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001542_0;
    int sec_r001542_1;
    int sec_r001542_2;
    int sec_r001542_3;
    int sec_r001542_4;
    int sec_r001542_5;
    int sec_r001542_6;
    int sec_r001542_7;
    int sec_r001542_8;
    int sec_r001542_9;
    int sec_r001542_10;
    int sec_r001542_11;
    int sec_r001542_12;
    int sec_r001542_13;
    int sec_r001542_14;
    int sec_r001542_15;
    int sec_r001542_16;
    int pub_r001542_0;
    int pub_r001542_1;
    int pub_r001542_2;
    int pub_r001542_3;
    int pub_r001542_4;
    int pub_r001542_5;
    int pub_r001542_6;
    int pub_r001542_7;
    int pub_r001542_8;
    int pub_r001542_9;
    int pub_r001542_10;
    int pub_r001542_11;
    int pub_r001542_12;
    int pub_r001542_13;
    int pub_r001542_14;
    int pub_r001542_15;
    int pub_r001542_16;
    int pub_r001542_17;
    int pub_r001542_18;
    int pub_r001542_19;
    int pub_r001542_20;
    int pub_r001542_21;
    int pub_r001542_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001542_0 >= -100 && pub_r001542_0 <= 100);
    __CPROVER_assume(pub_r001542_1 >= -100 && pub_r001542_1 <= 100);
    __CPROVER_assume(pub_r001542_2 >= -100 && pub_r001542_2 <= 100);
    __CPROVER_assume(pub_r001542_3 >= -100 && pub_r001542_3 <= 100);
    __CPROVER_assume(pub_r001542_4 >= -100 && pub_r001542_4 <= 100);
    __CPROVER_assume(pub_r001542_5 >= -100 && pub_r001542_5 <= 100);
    __CPROVER_assume(pub_r001542_6 >= -100 && pub_r001542_6 <= 100);
    __CPROVER_assume(pub_r001542_7 >= -100 && pub_r001542_7 <= 100);
    __CPROVER_assume(pub_r001542_8 >= -100 && pub_r001542_8 <= 100);
    __CPROVER_assume(pub_r001542_9 >= -100 && pub_r001542_9 <= 100);
    __CPROVER_assume(pub_r001542_10 >= -100 && pub_r001542_10 <= 100);
    __CPROVER_assume(pub_r001542_11 >= -100 && pub_r001542_11 <= 100);
    __CPROVER_assume(pub_r001542_12 >= -100 && pub_r001542_12 <= 100);
    __CPROVER_assume(pub_r001542_13 >= -100 && pub_r001542_13 <= 100);
    __CPROVER_assume(pub_r001542_14 >= -100 && pub_r001542_14 <= 100);
    __CPROVER_assume(pub_r001542_15 >= -100 && pub_r001542_15 <= 100);
    __CPROVER_assume(pub_r001542_16 >= -100 && pub_r001542_16 <= 100);
    __CPROVER_assume(pub_r001542_17 >= -100 && pub_r001542_17 <= 100);
    __CPROVER_assume(pub_r001542_18 >= -100 && pub_r001542_18 <= 100);
    __CPROVER_assume(pub_r001542_19 >= -100 && pub_r001542_19 <= 100);
    __CPROVER_assume(pub_r001542_20 >= -100 && pub_r001542_20 <= 100);
    __CPROVER_assume(pub_r001542_21 >= -100 && pub_r001542_21 <= 100);
    __CPROVER_assume(pub_r001542_22 >= -100 && pub_r001542_22 <= 100);
    __CPROVER_assume(sec_r001542_0 >= 0 && sec_r001542_0 <= 255);
    __CPROVER_assume(sec_r001542_1 >= 0 && sec_r001542_1 <= 255);
    __CPROVER_assume(sec_r001542_2 >= 0 && sec_r001542_2 <= 255);
    __CPROVER_assume(sec_r001542_3 >= 0 && sec_r001542_3 <= 255);
    __CPROVER_assume(sec_r001542_4 >= 0 && sec_r001542_4 <= 255);
    __CPROVER_assume(sec_r001542_5 >= 0 && sec_r001542_5 <= 255);
    __CPROVER_assume(sec_r001542_6 >= 0 && sec_r001542_6 <= 255);
    __CPROVER_assume(sec_r001542_7 >= 0 && sec_r001542_7 <= 255);
    __CPROVER_assume(sec_r001542_8 >= 0 && sec_r001542_8 <= 255);
    __CPROVER_assume(sec_r001542_9 >= 0 && sec_r001542_9 <= 255);
    __CPROVER_assume(sec_r001542_10 >= 0 && sec_r001542_10 <= 255);
    __CPROVER_assume(sec_r001542_11 >= 0 && sec_r001542_11 <= 255);
    __CPROVER_assume(sec_r001542_12 >= 0 && sec_r001542_12 <= 255);
    __CPROVER_assume(sec_r001542_13 >= 0 && sec_r001542_13 <= 255);
    __CPROVER_assume(sec_r001542_14 >= 0 && sec_r001542_14 <= 255);
    __CPROVER_assume(sec_r001542_15 >= 0 && sec_r001542_15 <= 255);
    __CPROVER_assume(sec_r001542_16 >= 0 && sec_r001542_16 <= 255);

    struct MatrixBlock_R001542_4213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001542_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001542_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001542_0 + 7) & 15;
    struct FilterState_R001542_4213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001542_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001542_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001542_0 + 9) & 15;
    struct AudioFrame_R001542_4213_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001542_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001542_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001542_0 + 11) & 15;
    struct DeviceConfig_R001542_4213_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001542_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001542_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001542_0 + 13) & 15;

    union RegisterBank_R001542_4213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001542_4213_0(sec_r001542_0, sec_r001542_1, pub_r001542_2, pub_r001542_3);
    int helper_flow_1 = fn_R001542_4213_1(sec_r001542_1, sec_r001542_2, pub_r001542_3);
    int helper_flow_2 = fn_R001542_4213_2(sec_r001542_2, sec_r001542_3, pub_r001542_4, pub_r001542_5);
    int helper_flow_3 = fn_R001542_4213_3(sec_r001542_3, pub_r001542_4, pub_r001542_5);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001542_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001542_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001542_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001542_1 * 3) + pub_r001542_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_3) & 255;
    out_sink = (out_sink + stage_v_3 * 2) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001542_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001542_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001542_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001542_0 * 3) + pub_r001542_14 + 30) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001542_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001542_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001542_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001542_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001542_15 * 3) + pub_r001542_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_12) & 255;
    out_sink = (out_sink + stage_v_12 * 2) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001542_15 * 3) + pub_r001542_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_13) & 255;
    out_sink = (out_sink + stage_v_13 * 2) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001542_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001542_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001542_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001542_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_7 * 3) + pub_r001542_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001542_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001542_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001542_5 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001542_13 * 3) + pub_r001542_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001542_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001542_6 * 3) + pub_r001542_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_24) & 255;
    out_sink = (out_sink + stage_v_24 * 2) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001542_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001542_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001542_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001542_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001542_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_24 * 3) + pub_r001542_14 + 3) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30 * 2) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_12 * 3) + pub_r001542_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001542_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001542_12 * 3) + pub_r001542_5 + 40) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001542_3 * 3) + pub_r001542_18 + 22) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001542_22 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001542_10 * 3) + pub_r001542_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001542_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_3 * 3) + pub_r001542_22 + 9) & 127;
    sec_accum = (sec_accum + stage_v_38) & 255;
    out_sink = (out_sink + stage_v_38 * 2) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001542_22 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001542_22 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_7 * 3) + pub_r001542_14 + 10) & 127;
    sec_accum = (sec_accum + stage_v_41) & 255;
    out_sink = (out_sink + stage_v_41 * 2) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001542_22 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_36 * 3) + pub_r001542_21 + 35) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_22 * 3) + pub_r001542_20 + 39) & 127;
    sec_accum = (sec_accum + stage_v_44) & 255;
    out_sink = (out_sink + stage_v_44 * 2) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001542_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001542_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_33 * 3) + pub_r001542_11 + 43) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001542_0 * 3) + pub_r001542_21 + 20) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001542_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001542_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_3 * 3) + pub_r001542_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001542_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_30 * 3) + pub_r001542_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_0 * 3) + pub_r001542_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_7 * 3) + pub_r001542_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55 * 2) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001542_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001542_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001542_14 * 3) + pub_r001542_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001542_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001542_11 * 3) + pub_r001542_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001542_8 * 3) + pub_r001542_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61 * 2) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001542_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_13 * 3) + pub_r001542_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_3 * 3) + pub_r001542_19 + 5) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001542_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001542_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001542_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001542_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001542_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001542_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001542_8 * 3) + pub_r001542_17 + 31) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_12 * 3) + pub_r001542_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001542_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001542_13 * 3) + pub_r001542_21 + 5) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74 * 2) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001542_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001542_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_18 * 3) + pub_r001542_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001542_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001542_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_74 * 3) + pub_r001542_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80 * 2) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001542_22 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001542_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001542_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_58 * 3) + pub_r001542_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001542_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001542_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r001542_13 * 3) + pub_r001542_22 + 40) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87 * 2) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001542_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001542_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_38 * 3) + pub_r001542_22 + 13) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_63 * 3) + pub_r001542_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91 * 2) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_30 * 3) + pub_r001542_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001542_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001542_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001542_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001542_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((helper_flow_0 * 3) + pub_r001542_0 + 14) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001542_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_47 * 3) + pub_r001542_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001542_20 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001542_14 * 3) + pub_r001542_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001542_20 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001542_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_3 * 3) + pub_r001542_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001542_11 * 3) + pub_r001542_18 + 35) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105 * 2) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001542_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001542_20 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001542_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001542_5 * 3) + pub_r001542_18 + 3) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001542_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001542_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_99 * 3) + pub_r001542_0 + 8) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001542_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001542_22 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_24 * 3) + pub_r001542_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115 * 2) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_90 * 3) + pub_r001542_17 + 44) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116 * 2) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001542_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001542_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001542_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001542_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001542_21 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001542_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001542_20 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001542_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001542_9 * 3) + pub_r001542_4 + 10) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001542_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_3 * 3) + pub_r001542_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127 * 2) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001542_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001542_12 * 3) + pub_r001542_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001542_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001542_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_13 * 3) + pub_r001542_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001542_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001542_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((helper_flow_1 * 3) + pub_r001542_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_13 * 3) + pub_r001542_19 + 23) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_91 * 3) + pub_r001542_12 + 40) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137 * 2) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001542_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_77 * 3) + pub_r001542_0 + 42) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139 * 2) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001542_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_13 * 3) + pub_r001542_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141 * 2) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001542_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_101 * 3) + pub_r001542_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143 * 2) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001542_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_104 * 3) + pub_r001542_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_33 * 3) + pub_r001542_15 + 32) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001542_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r001542_8 * 3) + pub_r001542_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001542_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_13 * 3) + pub_r001542_22 + 7) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001542_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001542_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001542_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r001542_1 * 3) + pub_r001542_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001542_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001542_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001542_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001542_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001542_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001542_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_51 * 3) + pub_r001542_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161 * 2) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_54 * 3) + pub_r001542_15 + 17) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162 * 2) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_51 * 3) + pub_r001542_0 + 6) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001542_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001542_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001542_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_136 * 3) + pub_r001542_7 + 16) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001542_21 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001542_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001542_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001542_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001542_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001542_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001542_6 * 3) + pub_r001542_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_150 * 3) + pub_r001542_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_154 * 3) + pub_r001542_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176 * 2) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001542_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001542_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001542_11 * 3) + pub_r001542_2 + 6) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_87 * 3) + pub_r001542_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001542_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_58 * 3) + pub_r001542_8 + 41) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001542_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001542_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001542_7 * 3) + pub_r001542_22 + 19) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001542_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_53 * 3) + pub_r001542_18 + 7) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187 * 2) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001542_22 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001542_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001542_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001542_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001542_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001542_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_104 * 3) + pub_r001542_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_0 * 3) + pub_r001542_20 + 31) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_87 * 3) + pub_r001542_21 + 44) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001542_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001542_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001542_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001542_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001542_22 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001542_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_180 * 3) + pub_r001542_21 + 35) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203 * 2) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_47 * 3) + pub_r001542_21 + 23) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_87 * 3) + pub_r001542_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_31 * 3) + pub_r001542_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((helper_flow_2 * 3) + pub_r001542_22 + 27) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207 * 2) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((helper_flow_1 * 3) + pub_r001542_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001542_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001542_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_145 * 3) + pub_r001542_12 + 13) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001542_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_175 * 3) + pub_r001542_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001542_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r001542_2 * 3) + pub_r001542_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_129 * 3) + pub_r001542_16 + 24) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_125 * 3) + pub_r001542_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001542_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_55 * 3) + pub_r001542_7 + 20) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((helper_flow_3 * 3) + pub_r001542_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220 * 2) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001542_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001542_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_55 * 3) + pub_r001542_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_180 * 3) + pub_r001542_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001542_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001542_22 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001542_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001542_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001542_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001542_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001542_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_101 * 3) + pub_r001542_6 + 38) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_104 * 3) + pub_r001542_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233 * 2) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001542_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001542_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001542_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_205 * 3) + pub_r001542_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_146 * 3) + pub_r001542_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238 * 2) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_224 * 3) + pub_r001542_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r001542_11 * 3) + pub_r001542_1 + 10) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240 * 2) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001542_22 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_104 * 3) + pub_r001542_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001542_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001542_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001542_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001542_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001542_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001542_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001542_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((sec_r001542_4 * 3) + pub_r001542_19 + 40) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250 * 2) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_185 * 3) + pub_r001542_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001542_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_232 * 3) + pub_r001542_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001542_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001542_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r001542_16 * 3) + pub_r001542_7 + 26) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_185 * 3) + pub_r001542_8 + 42) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257 * 2) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001542_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001542_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001542_21 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001542_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_174 * 3) + pub_r001542_6 + 34) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001542_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001542_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001542_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001542_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_154 * 3) + pub_r001542_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001542_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001542_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001542_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001542_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001542_22 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001542_0 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001542_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001542_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001542_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001542_21 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001542_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001542_21 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_179 * 3) + pub_r001542_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001542_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001542_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_257 * 3) + pub_r001542_13 + 40) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283 * 2) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((sec_r001542_12 * 3) + pub_r001542_19 + 35) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001542_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_187 * 3) + pub_r001542_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001542_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001542_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001542_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_43 * 3) + pub_r001542_21 + 25) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290 * 2) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001542_22 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_256 * 3) + pub_r001542_22 + 15) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((sec_r001542_7 * 3) + pub_r001542_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_143 * 3) + pub_r001542_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001542_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_125 * 3) + pub_r001542_18 + 28) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001542_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001542_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001542_22 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001542_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((sec_r001542_4 * 3) + pub_r001542_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301 * 2) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_127 * 3) + pub_r001542_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001542_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001542_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_185 * 3) + pub_r001542_4 + 38) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001542_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_182 * 3) + pub_r001542_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001542_22 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001542_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_205 * 3) + pub_r001542_0 + 40) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_301 * 3) + pub_r001542_17 + 38) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001542_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001542_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001542_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001542_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001542_20 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001542_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_137 * 3) + pub_r001542_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_33 * 3) + pub_r001542_15 + 44) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319 * 2) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_104 * 3) + pub_r001542_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001542_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_87 * 3) + pub_r001542_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001542_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001542_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001542_22 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001542_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001542_20 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_18 * 3) + pub_r001542_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001542_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_47 * 3) + pub_r001542_5 + 17) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001542_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001542_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001542_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001542_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001542_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001542_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_167 * 3) + pub_r001542_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_239 * 3) + pub_r001542_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001542_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001542_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((sec_r001542_16 * 3) + pub_r001542_1 + 38) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001542_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((sec_r001542_10 * 3) + pub_r001542_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001542_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_116 * 3) + pub_r001542_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001542_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((helper_flow_0 * 3) + pub_r001542_1 + 20) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_283 * 3) + pub_r001542_22 + 10) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001542_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001542_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001542_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001542_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001542_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001542_21 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001542_22 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001542_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001542_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001542_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((sec_r001542_5 * 3) + pub_r001542_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359 * 2) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001542_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_132 * 3) + pub_r001542_21 + 27) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361 * 2) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001542_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001542_20 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001542_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001542_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001542_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001542_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_179 * 3) + pub_r001542_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001542_2 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001542_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001542_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001542_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_112 * 3) + pub_r001542_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001542_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_345 * 3) + pub_r001542_19 + 17) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001542_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001542_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001542_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001542_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001542_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_310 * 3) + pub_r001542_19 + 24) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001542_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001542_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001542_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001542_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_368 * 3) + pub_r001542_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_239 * 3) + pub_r001542_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_387) & 255;
    out_sink = (out_sink + stage_v_387 * 2) & 255;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001542_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001542_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001542_21 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001542_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001542_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001542_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001542_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001542_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001542_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001542_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001542_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((helper_flow_3 * 3) + pub_r001542_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_399) & 255;
    out_sink = (out_sink + stage_v_399 * 2) & 255;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_127 * 3) + pub_r001542_4 + 15) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001542_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001542_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_386 * 3) + pub_r001542_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_38 * 3) + pub_r001542_2 + 13) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001542_21 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001542_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((sec_r001542_2 * 3) + pub_r001542_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_407) & 255;
    out_sink = (out_sink + stage_v_407 * 2) & 255;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001542_22 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_232 * 3) + pub_r001542_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_409) & 255;
    out_sink = (out_sink + stage_v_409 * 2) & 255;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_292 * 3) + pub_r001542_19 + 34) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001542_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_74 * 3) + pub_r001542_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_41 * 3) + pub_r001542_17 + 22) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_54 * 3) + pub_r001542_13 + 42) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001542_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001542_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001542_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001542_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_320 * 3) + pub_r001542_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001542_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_41 * 3) + pub_r001542_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001542_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_31 * 3) + pub_r001542_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((sec_r001542_0 * 3) + pub_r001542_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001542_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001542_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001542_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001542_19 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001542_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001542_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001542_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001542_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001542_22 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001542_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001542_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001542_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_311 * 3) + pub_r001542_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_437) & 255;
    out_sink = (out_sink + stage_v_437 * 2) & 255;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001542_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_148 * 3) + pub_r001542_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_129 * 3) + pub_r001542_3 + 38) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_162 * 3) + pub_r001542_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_441) & 255;
    out_sink = (out_sink + stage_v_441 * 2) & 255;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((sec_r001542_5 * 3) + pub_r001542_16 + 4) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001542_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001542_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001542_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001542_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001542_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_64 * 3) + pub_r001542_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001542_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001542_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001542_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001542_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001542_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001542_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001542_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001542_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_423 * 3) + pub_r001542_2 + 17) & 127;
    sec_accum = (sec_accum + stage_v_457) & 255;
    out_sink = (out_sink + stage_v_457 * 2) & 255;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001542_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001542_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001542_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001542_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001542_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_154 * 3) + pub_r001542_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_463) & 255;
    out_sink = (out_sink + stage_v_463 * 2) & 255;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((sec_r001542_11 * 3) + pub_r001542_22 + 23) & 127;
    sec_accum = (sec_accum + stage_v_464) & 255;
    out_sink = (out_sink + stage_v_464 * 2) & 255;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001542_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001542_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((sec_r001542_1 * 3) + pub_r001542_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_467) & 255;
    out_sink = (out_sink + stage_v_467 * 2) & 255;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_403 * 3) + pub_r001542_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_468) & 255;
    out_sink = (out_sink + stage_v_468 * 2) & 255;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((stage_v_292 * 3) + pub_r001542_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_469) & 255;
    out_sink = (out_sink + stage_v_469 * 2) & 255;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001542_22 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_464 * 3) + pub_r001542_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_471) & 255;
    out_sink = (out_sink + stage_v_471 * 2) & 255;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = (pub_r001542_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_472) & 127;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001542_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001542_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_84 * 3) + pub_r001542_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001542_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = ((stage_v_216 * 3) + pub_r001542_20 + 32) & 127;
    sec_accum = (sec_accum + stage_v_477) & 255;
    out_sink = (out_sink + stage_v_477 * 2) & 255;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001542_17 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001542_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001542_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001542_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = ((stage_v_41 * 3) + pub_r001542_20 + 14) & 127;
    sec_accum = (sec_accum + stage_v_482) & 255;
    out_sink = (out_sink + stage_v_482 * 2) & 255;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001542_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = ((stage_v_322 * 3) + pub_r001542_12 + 18) & 127;
    sec_accum = (sec_accum + stage_v_484) & 255;
    out_sink = (out_sink + stage_v_484 * 2) & 255;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001542_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001542_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001542_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001542_22 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001542_20 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = (pub_r001542_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_490) & 127;

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001542_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = (pub_r001542_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_492) & 127;

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = (pub_r001542_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_493) & 127;

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((stage_v_58 * 3) + pub_r001542_11 + 29) & 127;
    sec_accum = (sec_accum + stage_v_494) & 255;
    out_sink = (out_sink + stage_v_494 * 2) & 255;

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = ((sec_r001542_9 * 3) + pub_r001542_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_495) & 255;
    out_sink = (out_sink + stage_v_495 * 2) & 255;

    /* Execution Pipeline Stage 496 */
    int stage_v_496 = ((sec_r001542_13 * 3) + pub_r001542_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_496) & 255;
    out_sink = (out_sink + stage_v_496 * 2) & 255;

    /* Execution Pipeline Stage 497 */
    int stage_v_497 = (pub_r001542_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_497) & 127;

    /* Execution Pipeline Stage 498 */
    int stage_v_498 = (pub_r001542_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_498) & 127;

    /* Execution Pipeline Stage 499 */
    int stage_v_499 = ((stage_v_262 * 3) + pub_r001542_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_499) & 255;
    out_sink = (out_sink + stage_v_499 * 2) & 255;

    /* Execution Pipeline Stage 500 */
    int stage_v_500 = (pub_r001542_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_500) & 127;

    /* Execution Pipeline Stage 501 */
    int stage_v_501 = (pub_r001542_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_501) & 127;

    /* Execution Pipeline Stage 502 */
    int stage_v_502 = (pub_r001542_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_502) & 127;

    /* Execution Pipeline Stage 503 */
    int stage_v_503 = (pub_r001542_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_503) & 127;

    /* Execution Pipeline Stage 504 */
    int stage_v_504 = (pub_r001542_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_504) & 127;

    /* Execution Pipeline Stage 505 */
    int stage_v_505 = (pub_r001542_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_505) & 127;

    /* Execution Pipeline Stage 506 */
    int stage_v_506 = (pub_r001542_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_506) & 127;

    /* Execution Pipeline Stage 507 */
    int stage_v_507 = (pub_r001542_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_507) & 127;

    /* Execution Pipeline Stage 508 */
    int stage_v_508 = (pub_r001542_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_508) & 127;

    /* Execution Pipeline Stage 509 */
    int stage_v_509 = (pub_r001542_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_509) & 127;

    /* Execution Pipeline Stage 510 */
    int stage_v_510 = (pub_r001542_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_510) & 127;

    /* Execution Pipeline Stage 511 */
    int stage_v_511 = (pub_r001542_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_511) & 127;

    /* Execution Pipeline Stage 512 */
    int stage_v_512 = ((helper_flow_3 * 3) + pub_r001542_3 + 27) & 127;
    sec_accum = (sec_accum + stage_v_512) & 255;
    out_sink = (out_sink + stage_v_512 * 2) & 255;

    /* Execution Pipeline Stage 513 */
    int stage_v_513 = (pub_r001542_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_513) & 127;

    /* Execution Pipeline Stage 514 */
    int stage_v_514 = ((stage_v_132 * 3) + pub_r001542_21 + 4) & 127;
    sec_accum = (sec_accum + stage_v_514) & 255;
    out_sink = (out_sink + stage_v_514 * 2) & 255;

    /* Execution Pipeline Stage 515 */
    int stage_v_515 = ((stage_v_307 * 3) + pub_r001542_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_515) & 255;
    out_sink = (out_sink + stage_v_515 * 2) & 255;

    /* Execution Pipeline Stage 516 */
    int stage_v_516 = (pub_r001542_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_516) & 127;

    /* Execution Pipeline Stage 517 */
    int stage_v_517 = (pub_r001542_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_517) & 127;

    /* Execution Pipeline Stage 518 */
    int stage_v_518 = ((stage_v_13 * 3) + pub_r001542_21 + 36) & 127;
    sec_accum = (sec_accum + stage_v_518) & 255;
    out_sink = (out_sink + stage_v_518 * 2) & 255;

    /* Execution Pipeline Stage 519 */
    int stage_v_519 = (pub_r001542_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_519) & 127;

    /* Execution Pipeline Stage 520 */
    int stage_v_520 = (pub_r001542_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_520) & 127;

    /* Execution Pipeline Stage 521 */
    int stage_v_521 = (pub_r001542_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_521) & 127;

    /* Execution Pipeline Stage 522 */
    int stage_v_522 = (pub_r001542_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_522) & 127;

    /* Execution Pipeline Stage 523 */
    int stage_v_523 = (pub_r001542_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_523) & 127;

    /* Execution Pipeline Stage 524 */
    int stage_v_524 = ((stage_v_115 * 3) + pub_r001542_21 + 29) & 127;
    sec_accum = (sec_accum + stage_v_524) & 255;
    out_sink = (out_sink + stage_v_524 * 2) & 255;

    /* Execution Pipeline Stage 525 */
    int stage_v_525 = (pub_r001542_21 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_525) & 127;

    /* Execution Pipeline Stage 526 */
    int stage_v_526 = (pub_r001542_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_526) & 127;

    /* Execution Pipeline Stage 527 */
    int stage_v_527 = ((stage_v_423 * 3) + pub_r001542_12 + 15) & 127;
    sec_accum = (sec_accum + stage_v_527) & 255;
    out_sink = (out_sink + stage_v_527 * 2) & 255;

    /* Execution Pipeline Stage 528 */
    int stage_v_528 = (pub_r001542_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_528) & 127;

    /* Execution Pipeline Stage 529 */
    int stage_v_529 = ((stage_v_77 * 3) + pub_r001542_21 + 36) & 127;
    sec_accum = (sec_accum + stage_v_529) & 255;
    out_sink = (out_sink + stage_v_529 * 2) & 255;

    /* Execution Pipeline Stage 530 */
    int stage_v_530 = (pub_r001542_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_530) & 127;

    /* Execution Pipeline Stage 531 */
    int stage_v_531 = ((stage_v_80 * 3) + pub_r001542_3 + 39) & 127;
    sec_accum = (sec_accum + stage_v_531) & 255;
    out_sink = (out_sink + stage_v_531 * 2) & 255;

    /* Execution Pipeline Stage 532 */
    int stage_v_532 = (pub_r001542_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_532) & 127;

    /* Execution Pipeline Stage 533 */
    int stage_v_533 = (pub_r001542_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_533) & 127;

    /* Execution Pipeline Stage 534 */
    int stage_v_534 = ((stage_v_305 * 3) + pub_r001542_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_534) & 255;
    out_sink = (out_sink + stage_v_534 * 2) & 255;

    /* Execution Pipeline Stage 535 */
    int stage_v_535 = ((stage_v_205 * 3) + pub_r001542_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_535) & 255;
    out_sink = (out_sink + stage_v_535 * 2) & 255;

    /* Execution Pipeline Stage 536 */
    int stage_v_536 = (pub_r001542_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_536) & 127;

    /* Execution Pipeline Stage 537 */
    int stage_v_537 = (pub_r001542_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_537) & 127;

    /* Execution Pipeline Stage 538 */
    int stage_v_538 = ((stage_v_167 * 3) + pub_r001542_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_538) & 255;
    out_sink = (out_sink + stage_v_538 * 2) & 255;

    /* Execution Pipeline Stage 539 */
    int stage_v_539 = (pub_r001542_20 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_539) & 127;

    /* Execution Pipeline Stage 540 */
    int stage_v_540 = (pub_r001542_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_540) & 127;

    /* Execution Pipeline Stage 541 */
    int stage_v_541 = (pub_r001542_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_541) & 127;

    /* Execution Pipeline Stage 542 */
    int stage_v_542 = (pub_r001542_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_542) & 127;

    /* Execution Pipeline Stage 543 */
    int stage_v_543 = ((stage_v_7 * 3) + pub_r001542_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_543) & 255;
    out_sink = (out_sink + stage_v_543 * 2) & 255;

    /* Execution Pipeline Stage 544 */
    int stage_v_544 = (pub_r001542_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_544) & 127;

    /* Execution Pipeline Stage 545 */
    int stage_v_545 = ((stage_v_154 * 3) + pub_r001542_18 + 15) & 127;
    sec_accum = (sec_accum + stage_v_545) & 255;
    out_sink = (out_sink + stage_v_545 * 2) & 255;

    /* Execution Pipeline Stage 546 */
    int stage_v_546 = (pub_r001542_22 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_546) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
