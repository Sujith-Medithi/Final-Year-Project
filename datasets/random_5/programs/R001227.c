/*
 * Benchmark Program: R001227
 * Security Family: nested_implicit_flow
 * Generator Seed: 622713
 * High Inputs: 22 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001227_2713_0 {
    short parity;
    int id;
    short baud_rate;
    int buffer[3];
};

struct SensorNode_R001227_2713_1 {
    int offset;
    unsigned char status;
    short calib;
    int buffer[3];
};

struct EventLog_R001227_2713_2 {
    unsigned char code;
    unsigned char facility;
    short signature;
    short seq;
    int buffer[3];
};

struct CipherContext_R001227_2713_3 {
    int counter;
    int tag;
    unsigned char flags;
    int buffer[3];
};

union ColorPixel_R001227_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001227_2713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int sample_33 = (aux + st.buffer[1]) & 3;
    switch (sample_33) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_87 = 0;
    for (int k = 0; k < 3; k++) {
        delta_87 = (delta_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_87) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001227_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int margin_92 = local_arr[aux % 3];
    acc = (acc + margin_92 * 2) & 127;
    int weight_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_38) & 63;
    acc ^= aux;
    int segment_44 = (aux + st.buffer[1]) & 3;
    switch (segment_44) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_65 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_65 > 13) {
        acc = (acc + anchor_65 * 2 + 5) & 127;
        aux ^= (anchor_65 & 15);
    } else {
        acc = (acc - anchor_65 + 11) & 127;
        aux += 3;
    }
    int vector_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_34) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_27 = local_arr[aux % 3];
    acc = (acc + threshold_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_3(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001227_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int mask_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_51) & 63;
    acc ^= aux;
    int bound_96 = 0;
    for (int k = 0; k < 2; k++) {
        bound_96 = (bound_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_96) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_4(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_30 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_30 > 38) {
        acc = (acc + threshold_30 * 2 + 5) & 127;
        aux ^= (threshold_30 & 15);
    } else {
        acc = (acc - threshold_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_63 = local_arr[aux % 3];
    acc = (acc + parity_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_5(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tally_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_91) & 63;
    acc ^= aux;
    int vector_34 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_34 > 31) {
        acc = (acc + vector_34 * 2 + 5) & 127;
        aux ^= (vector_34 & 15);
    } else {
        acc = (acc - vector_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int vector_25 = (aux + st.buffer[1]) & 3;
    switch (vector_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_12 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_12 > 17) {
        acc = (acc + delta_12 * 2 + 5) & 127;
        aux ^= (delta_12 & 15);
    } else {
        acc = (acc - delta_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_7(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int bound_67 = local_arr[aux % 3];
    acc = (acc + bound_67 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_8(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001227_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int delta_68 = (aux + st.buffer[1]) & 3;
    switch (delta_68) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_36 = local_arr[aux % 3];
    acc = (acc + anchor_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_9(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_50 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_50 > 20) {
        acc = (acc + index_reg_50 * 2 + 5) & 127;
        aux ^= (index_reg_50 & 15);
    } else {
        acc = (acc - index_reg_50 + 11) & 127;
        aux += 3;
    }
    int residue_79 = (aux + st.buffer[1]) & 3;
    switch (residue_79) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_77) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_45 = local_arr[aux % 3];
    acc = (acc + sample_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_10(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001227_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int accumulator_20 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_20 = (accumulator_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_20) & 127;
    }
    int margin_83 = (aux + st.buffer[1]) & 3;
    switch (margin_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_29 = local_arr[aux % 3];
    acc = (acc + phase_29 * 2) & 127;
    int vector_93 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_93 > 45) {
        acc = (acc + vector_93 * 2 + 5) & 127;
        aux ^= (vector_93 & 15);
    } else {
        acc = (acc - vector_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_11(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int mask_41 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_41 > 25) {
        acc = (acc + mask_41 * 2 + 5) & 127;
        aux ^= (mask_41 & 15);
    } else {
        acc = (acc - mask_41 + 11) & 127;
        aux += 3;
    }
    int factor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001227_2713_12(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_21 = (aux + st.buffer[1]) & 3;
    switch (quantum_21) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_48 = local_arr[aux % 3];
    acc = (acc + accumulator_48 * 2) & 127;
    int accumulator_57 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_57 > 32) {
        acc = (acc + accumulator_57 * 2 + 5) & 127;
        aux ^= (accumulator_57 & 15);
    } else {
        acc = (acc - accumulator_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001227_2713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_12 = local_arr[aux % 3];
    acc = (acc + stride_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001227_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_27 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_27 = (tracker_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_27) & 127;
    }
    int threshold_21 = (aux + st.buffer[1]) & 3;
    switch (threshold_21) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_25 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_25 > 28) {
        acc = (acc + segment_25 * 2 + 5) & 127;
        aux ^= (segment_25 & 15);
    } else {
        acc = (acc - segment_25 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_55 = local_arr[aux % 3];
    acc = (acc + accumulator_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001227_2713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001227_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int margin_34 = (aux + st.buffer[1]) & 3;
    switch (margin_34) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_93 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_93 > 14) {
        acc = (acc + damping_93 * 2 + 5) & 127;
        aux ^= (damping_93 & 15);
    } else {
        acc = (acc - damping_93 + 11) & 127;
        aux += 3;
    }
    int threshold_73 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_73 = (threshold_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_73) & 127;
    }
    int tracker_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001227_2713_16(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001227_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int parity_40 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_40 > 41) {
        acc = (acc + parity_40 * 2 + 5) & 127;
        aux ^= (parity_40 & 15);
    } else {
        acc = (acc - parity_40 + 11) & 127;
        aux += 3;
    }
    int delta_96 = 0;
    for (int k = 0; k < 2; k++) {
        delta_96 = (delta_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_96) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_84 = local_arr[aux % 3];
    acc = (acc + margin_84 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001227_0;
    int sec_r001227_1;
    int sec_r001227_2;
    int sec_r001227_3;
    int sec_r001227_4;
    int sec_r001227_5;
    int sec_r001227_6;
    int sec_r001227_7;
    int sec_r001227_8;
    int sec_r001227_9;
    int sec_r001227_10;
    int sec_r001227_11;
    int sec_r001227_12;
    int sec_r001227_13;
    int sec_r001227_14;
    int sec_r001227_15;
    int sec_r001227_16;
    int sec_r001227_17;
    int sec_r001227_18;
    int sec_r001227_19;
    int sec_r001227_20;
    int sec_r001227_21;
    int pub_r001227_0;
    int pub_r001227_1;
    int pub_r001227_2;
    int pub_r001227_3;
    int pub_r001227_4;
    int pub_r001227_5;
    int pub_r001227_6;
    int pub_r001227_7;
    int pub_r001227_8;
    int pub_r001227_9;
    int pub_r001227_10;
    int pub_r001227_11;
    int pub_r001227_12;
    int pub_r001227_13;
    int pub_r001227_14;
    int pub_r001227_15;
    int pub_r001227_16;
    int pub_r001227_17;
    int pub_r001227_18;
    int pub_r001227_19;
    int pub_r001227_20;
    int pub_r001227_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001227_0 >= -100 && pub_r001227_0 <= 100);
    __CPROVER_assume(pub_r001227_1 >= -100 && pub_r001227_1 <= 100);
    __CPROVER_assume(pub_r001227_2 >= -100 && pub_r001227_2 <= 100);
    __CPROVER_assume(pub_r001227_3 >= -100 && pub_r001227_3 <= 100);
    __CPROVER_assume(pub_r001227_4 >= -100 && pub_r001227_4 <= 100);
    __CPROVER_assume(pub_r001227_5 >= -100 && pub_r001227_5 <= 100);
    __CPROVER_assume(pub_r001227_6 >= -100 && pub_r001227_6 <= 100);
    __CPROVER_assume(pub_r001227_7 >= -100 && pub_r001227_7 <= 100);
    __CPROVER_assume(pub_r001227_8 >= -100 && pub_r001227_8 <= 100);
    __CPROVER_assume(pub_r001227_9 >= -100 && pub_r001227_9 <= 100);
    __CPROVER_assume(pub_r001227_10 >= -100 && pub_r001227_10 <= 100);
    __CPROVER_assume(pub_r001227_11 >= -100 && pub_r001227_11 <= 100);
    __CPROVER_assume(pub_r001227_12 >= -100 && pub_r001227_12 <= 100);
    __CPROVER_assume(pub_r001227_13 >= -100 && pub_r001227_13 <= 100);
    __CPROVER_assume(pub_r001227_14 >= -100 && pub_r001227_14 <= 100);
    __CPROVER_assume(pub_r001227_15 >= -100 && pub_r001227_15 <= 100);
    __CPROVER_assume(pub_r001227_16 >= -100 && pub_r001227_16 <= 100);
    __CPROVER_assume(pub_r001227_17 >= -100 && pub_r001227_17 <= 100);
    __CPROVER_assume(pub_r001227_18 >= -100 && pub_r001227_18 <= 100);
    __CPROVER_assume(pub_r001227_19 >= -100 && pub_r001227_19 <= 100);
    __CPROVER_assume(pub_r001227_20 >= -100 && pub_r001227_20 <= 100);
    __CPROVER_assume(pub_r001227_21 >= -100 && pub_r001227_21 <= 100);
    __CPROVER_assume(sec_r001227_0 >= 0 && sec_r001227_0 <= 255);
    __CPROVER_assume(sec_r001227_1 >= 0 && sec_r001227_1 <= 255);
    __CPROVER_assume(sec_r001227_2 >= 0 && sec_r001227_2 <= 255);
    __CPROVER_assume(sec_r001227_3 >= 0 && sec_r001227_3 <= 255);
    __CPROVER_assume(sec_r001227_4 >= 0 && sec_r001227_4 <= 255);
    __CPROVER_assume(sec_r001227_5 >= 0 && sec_r001227_5 <= 255);
    __CPROVER_assume(sec_r001227_6 >= 0 && sec_r001227_6 <= 255);
    __CPROVER_assume(sec_r001227_7 >= 0 && sec_r001227_7 <= 255);
    __CPROVER_assume(sec_r001227_8 >= 0 && sec_r001227_8 <= 255);
    __CPROVER_assume(sec_r001227_9 >= 0 && sec_r001227_9 <= 255);
    __CPROVER_assume(sec_r001227_10 >= 0 && sec_r001227_10 <= 255);
    __CPROVER_assume(sec_r001227_11 >= 0 && sec_r001227_11 <= 255);
    __CPROVER_assume(sec_r001227_12 >= 0 && sec_r001227_12 <= 255);
    __CPROVER_assume(sec_r001227_13 >= 0 && sec_r001227_13 <= 255);
    __CPROVER_assume(sec_r001227_14 >= 0 && sec_r001227_14 <= 255);
    __CPROVER_assume(sec_r001227_15 >= 0 && sec_r001227_15 <= 255);
    __CPROVER_assume(sec_r001227_16 >= 0 && sec_r001227_16 <= 255);
    __CPROVER_assume(sec_r001227_17 >= 0 && sec_r001227_17 <= 255);
    __CPROVER_assume(sec_r001227_18 >= 0 && sec_r001227_18 <= 255);
    __CPROVER_assume(sec_r001227_19 >= 0 && sec_r001227_19 <= 255);
    __CPROVER_assume(sec_r001227_20 >= 0 && sec_r001227_20 <= 255);
    __CPROVER_assume(sec_r001227_21 >= 0 && sec_r001227_21 <= 255);

    struct DeviceConfig_R001227_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001227_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001227_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001227_0 + 7) & 15;
    struct SensorNode_R001227_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001227_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001227_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001227_0 + 9) & 15;
    struct EventLog_R001227_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001227_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001227_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001227_0 + 11) & 15;
    struct CipherContext_R001227_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001227_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001227_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001227_0 + 13) & 15;

    union ColorPixel_R001227_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001227_2713_0(sec_r001227_0, pub_r001227_1, pub_r001227_2, pub_r001227_3, pub_r001227_4);
    int helper_flow_1 = fn_R001227_2713_1(sec_r001227_1, pub_r001227_2, pub_r001227_3, pub_r001227_4);
    int helper_flow_2 = fn_R001227_2713_2(sec_r001227_2, sec_r001227_3, pub_r001227_4, pub_r001227_5);
    int helper_flow_3 = fn_R001227_2713_3(sec_r001227_3, pub_r001227_4, pub_r001227_5);
    int helper_flow_4 = fn_R001227_2713_4(sec_r001227_4, sec_r001227_5);
    int helper_flow_5 = fn_R001227_2713_5(sec_r001227_5, sec_r001227_6);
    int helper_flow_6 = fn_R001227_2713_6(sec_r001227_6, sec_r001227_7, pub_r001227_8, pub_r001227_9, pub_r001227_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001227_1 ^ pub_r001227_11) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001227_16 ^ pub_r001227_6) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001227_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001227_18 ^ pub_r001227_21) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001227_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_2 ^ pub_r001227_17) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001227_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (stage_v_2 ^ pub_r001227_1) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001227_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001227_7 ^ pub_r001227_10) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001227_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001227_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_2 ^ pub_r001227_18) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001227_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_5 ^ pub_r001227_21) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001227_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_9 ^ pub_r001227_16) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001227_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001227_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001227_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001227_16 ^ pub_r001227_20) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_13 ^ pub_r001227_4) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_2 ^ pub_r001227_4) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001227_11 ^ pub_r001227_15) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001227_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001227_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001227_21 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001227_18 ^ pub_r001227_17) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_4 ^ pub_r001227_6) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001227_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001227_16 ^ pub_r001227_17) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001227_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001227_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_3 ^ pub_r001227_12) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001227_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_0 ^ pub_r001227_0) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_25 ^ pub_r001227_4) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001227_7 ^ pub_r001227_16) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_24 ^ pub_r001227_8) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001227_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001227_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_4 ^ pub_r001227_3) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001227_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001227_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001227_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001227_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001227_15 ^ pub_r001227_2) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_6 ^ pub_r001227_6) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001227_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001227_10 ^ pub_r001227_7) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001227_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_6 ^ pub_r001227_14) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001227_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001227_14 ^ pub_r001227_2) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001227_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001227_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001227_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001227_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001227_18 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_34 ^ pub_r001227_10) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001227_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_25 ^ pub_r001227_4) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001227_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_13 ^ pub_r001227_7) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001227_9 ^ pub_r001227_9) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r001227_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001227_10 ^ pub_r001227_16) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001227_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_1 ^ pub_r001227_2) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001227_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001227_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001227_13 ^ pub_r001227_2) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001227_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_14 ^ pub_r001227_14) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_9 ^ pub_r001227_9) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001227_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_5 ^ pub_r001227_16) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001227_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001227_6 ^ pub_r001227_10) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001227_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001227_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001227_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_37 ^ pub_r001227_12) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001227_7 ^ pub_r001227_7) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_15 ^ pub_r001227_9) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r001227_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_47 ^ pub_r001227_3) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r001227_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001227_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001227_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_14 ^ pub_r001227_14) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001227_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_8 ^ pub_r001227_16) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_46 ^ pub_r001227_2) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001227_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_65 ^ pub_r001227_7) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001227_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_5 ^ pub_r001227_10) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_38 ^ pub_r001227_1) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001227_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001227_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_1 ^ pub_r001227_8) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001227_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (helper_flow_0 ^ pub_r001227_20) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001227_0 ^ pub_r001227_19) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r001227_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001227_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001227_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_0 ^ pub_r001227_10) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001227_18 ^ pub_r001227_1) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_25 ^ pub_r001227_16) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001227_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001227_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001227_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_25 ^ pub_r001227_16) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001227_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_72 ^ pub_r001227_8) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001227_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001227_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_1 ^ pub_r001227_15) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001227_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001227_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001227_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001227_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001227_13 ^ pub_r001227_6) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001227_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_54 ^ pub_r001227_10) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001227_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001227_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_10 ^ pub_r001227_3) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_30 ^ pub_r001227_15) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_102 ^ pub_r001227_14) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r001227_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_46 ^ pub_r001227_16) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001227_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_5 ^ pub_r001227_5) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r001227_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_0 ^ pub_r001227_8) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_14 ^ pub_r001227_14) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r001227_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_93 ^ pub_r001227_16) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001227_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_36 ^ pub_r001227_7) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r001227_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_36 ^ pub_r001227_5) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_8 ^ pub_r001227_20) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r001227_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_109 ^ pub_r001227_7) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_68 ^ pub_r001227_5) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001227_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_107 ^ pub_r001227_11) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001227_2 ^ pub_r001227_21) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r001227_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (helper_flow_2 ^ pub_r001227_3) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_99 ^ pub_r001227_14) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001227_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (helper_flow_3 ^ pub_r001227_15) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001227_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_5 ^ pub_r001227_19) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001227_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (helper_flow_1 ^ pub_r001227_9) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001227_10 ^ pub_r001227_7) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001227_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_10 ^ pub_r001227_3) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_1 ^ pub_r001227_8) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_125 ^ pub_r001227_0) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001227_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_58 ^ pub_r001227_16) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001227_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_99 ^ pub_r001227_8) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_130 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_122 ^ pub_r001227_10) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((sec_r001227_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_37 ^ pub_r001227_9) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_63 ^ pub_r001227_6) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001227_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001227_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001227_12 ^ pub_r001227_11) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_85 ^ pub_r001227_4) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001227_18 ^ pub_r001227_11) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001227_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001227_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_68 ^ pub_r001227_4) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r001227_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001227_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (sec_r001227_5 ^ pub_r001227_8) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_135 ^ pub_r001227_8) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_58 ^ pub_r001227_6) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001227_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_44 ^ pub_r001227_16) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_16 ^ pub_r001227_21) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((sec_r001227_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001227_20 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001227_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_1 ^ pub_r001227_9) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_126 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r001227_14 ^ pub_r001227_13) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_50 ^ pub_r001227_7) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_141 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_8 ^ pub_r001227_18) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_136 ^ pub_r001227_19) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_141 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001227_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_2 ^ pub_r001227_4) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_16 ^ pub_r001227_8) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((sec_r001227_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001227_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_135 ^ pub_r001227_4) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r001227_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001227_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001227_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001227_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_104 ^ pub_r001227_2) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_147 ^ pub_r001227_11) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_43 ^ pub_r001227_8) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_169 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_53 ^ pub_r001227_20) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r001227_18 ^ pub_r001227_1) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((sec_r001227_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001227_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_64 ^ pub_r001227_9) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_151 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_132 ^ pub_r001227_16) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_69 ^ pub_r001227_10) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001227_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001227_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001227_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001227_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001227_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001227_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001227_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (sec_r001227_5 ^ pub_r001227_0) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_140 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001227_8 ^ pub_r001227_7) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r001227_15 ^ pub_r001227_16) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001227_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001227_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_13 ^ pub_r001227_6) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((sec_r001227_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001227_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001227_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_84 ^ pub_r001227_6) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001227_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_22 ^ pub_r001227_4) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001227_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_83 ^ pub_r001227_12) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001227_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_74 ^ pub_r001227_1) & 63;
    if ((stage_v_198 & 1) != 0) {
        if ((stage_v_196 & 2) != 0) {
            out_sink = (out_sink + stage_v_198 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_198 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_158 ^ pub_r001227_13) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_155 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001227_20 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_192 ^ pub_r001227_12) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_104 ^ pub_r001227_17) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001227_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001227_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_74 ^ pub_r001227_0) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_13 ^ pub_r001227_4) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((sec_r001227_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_25 ^ pub_r001227_7) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((stage_v_156 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001227_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_171 ^ pub_r001227_3) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((stage_v_151 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_9 ^ pub_r001227_11) & 63;
    if ((stage_v_210 & 1) != 0) {
        if ((stage_v_209 & 2) != 0) {
            out_sink = (out_sink + stage_v_210 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_210 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001227_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001227_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001227_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_27 ^ pub_r001227_11) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001227_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001227_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r001227_17 ^ pub_r001227_20) & 63;
    if ((stage_v_217 & 1) != 0) {
        if ((stage_v_199 & 2) != 0) {
            out_sink = (out_sink + stage_v_217 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_217 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001227_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001227_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_116 ^ pub_r001227_17) & 63;
    if ((stage_v_220 & 1) != 0) {
        if ((stage_v_157 & 2) != 0) {
            out_sink = (out_sink + stage_v_220 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_220 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_1 ^ pub_r001227_3) & 63;
    if ((stage_v_221 & 1) != 0) {
        if ((stage_v_176 & 2) != 0) {
            out_sink = (out_sink + stage_v_221 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_221 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001227_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (sec_r001227_21 ^ pub_r001227_21) & 63;
    if ((stage_v_223 & 1) != 0) {
        if ((stage_v_134 & 2) != 0) {
            out_sink = (out_sink + stage_v_223 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_223 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
