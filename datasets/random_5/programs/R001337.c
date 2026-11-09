/*
 * Benchmark Program: R001337
 * Security Family: nested_implicit_flow
 * Generator Seed: 633713
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001337_3713_0 {
    int code;
    int signature;
    int timestamp;
    short severity;
    int buffer[3];
};

struct SensorNode_R001337_3713_1 {
    unsigned char reading;
    unsigned char offset;
    int calib;
    short gain;
    int threshold;
    int buffer[3];
};

union ColorPixel_R001337_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001337_3713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int pivot_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001337_3713_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_66 = (aux + st.buffer[1]) & 3;
    switch (sample_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int vector_51 = 0;
    for (int k = 0; k < 3; k++) {
        vector_51 = (vector_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_51) & 127;
    }
    int coefficient_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_34) & 63;
    acc ^= aux;
    int damping_23 = (aux + st.buffer[1]) & 3;
    switch (damping_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001337_3713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int factor_28 = local_arr[aux % 3];
    acc = (acc + factor_28 * 2) & 127;
    int window_74 = (aux + st.buffer[1]) & 3;
    switch (window_74) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_28 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_28 > 42) {
        acc = (acc + sample_28 * 2 + 5) & 127;
        aux ^= (sample_28 & 15);
    } else {
        acc = (acc - sample_28 + 11) & 127;
        aux += 3;
    }
    int tally_65 = 0;
    for (int k = 0; k < 2; k++) {
        tally_65 = (tally_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_4(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int quotient_33 = local_arr[aux % 3];
    acc = (acc + quotient_33 * 2) & 127;
    int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001337_3713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int metric_39 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_39 > 22) {
        acc = (acc + metric_39 * 2 + 5) & 127;
        aux ^= (metric_39 & 15);
    } else {
        acc = (acc - metric_39 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_32 = local_arr[aux % 3];
    acc = (acc + damping_32 * 2) & 127;
    int coefficient_44 = (aux + st.buffer[1]) & 3;
    switch (coefficient_44) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_6(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_94 = local_arr[aux % 3];
    acc = (acc + delta_94 * 2) & 127;
    int cursor_27 = (aux + st.buffer[1]) & 3;
    switch (cursor_27) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_98 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_98 > 21) {
        acc = (acc + checksum_98 * 2 + 5) & 127;
        aux ^= (checksum_98 & 15);
    } else {
        acc = (acc - checksum_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int phase_84 = local_arr[aux % 3];
    acc = (acc + phase_84 * 2) & 127;
    int stride_41 = (aux + st.buffer[1]) & 3;
    switch (stride_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_66 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_66 > 30) {
        acc = (acc + weight_66 * 2 + 5) & 127;
        aux ^= (weight_66 & 15);
    } else {
        acc = (acc - weight_66 + 11) & 127;
        aux += 3;
    }
    int checksum_73 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_73 = (checksum_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_8(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_40) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_28 = (aux + st.buffer[1]) & 3;
    switch (scale_28) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_84 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_84 = (anchor_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_84) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_9(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_43 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_43 > 17) {
        acc = (acc + mask_43 * 2 + 5) & 127;
        aux ^= (mask_43 & 15);
    } else {
        acc = (acc - mask_43 + 11) & 127;
        aux += 3;
    }
    int damping_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001337_3713_10(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_90 = (aux + st.buffer[1]) & 3;
    switch (quotient_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = 0;
    for (int k = 0; k < 2; k++) {
        tally_80 = (tally_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_50 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_50 = (accumulator_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_50) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_88 = local_arr[aux % 3];
    acc = (acc + sample_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001337_3713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_57 = 0;
    for (int k = 0; k < 2; k++) {
        segment_57 = (segment_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_57) & 127;
    }
    int accumulator_57 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_57 > 31) {
        acc = (acc + accumulator_57 * 2 + 5) & 127;
        aux ^= (accumulator_57 & 15);
    } else {
        acc = (acc - accumulator_57 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int mask_86 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_86 > 36) {
        acc = (acc + mask_86 * 2 + 5) & 127;
        aux ^= (mask_86 & 15);
    } else {
        acc = (acc - mask_86 + 11) & 127;
        aux += 3;
    }
    int damping_56 = 0;
    for (int k = 0; k < 2; k++) {
        damping_56 = (damping_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_56) & 127;
    }
    int checksum_59 = (aux + st.buffer[1]) & 3;
    switch (checksum_59) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001337_3713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int sample_25 = (aux + st.buffer[1]) & 3;
    switch (sample_25) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_99) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_47 = local_arr[aux % 3];
    acc = (acc + sample_47 * 2) & 127;
    int weight_80 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_80 > 33) {
        acc = (acc + weight_80 * 2 + 5) & 127;
        aux ^= (weight_80 & 15);
    } else {
        acc = (acc - weight_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001337_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int delta_59 = 0;
    for (int k = 0; k < 2; k++) {
        delta_59 = (delta_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_59) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_20 = (aux + st.buffer[1]) & 3;
    switch (threshold_20) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001337_3713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001337_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int pivot_37 = local_arr[aux % 3];
    acc = (acc + pivot_37 * 2) & 127;
    int window_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_39) & 63;
    acc ^= aux;
    int anchor_53 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_53 > 13) {
        acc = (acc + anchor_53 * 2 + 5) & 127;
        aux ^= (anchor_53 & 15);
    } else {
        acc = (acc - anchor_53 + 11) & 127;
        aux += 3;
    }
    int damping_12 = 0;
    for (int k = 0; k < 3; k++) {
        damping_12 = (damping_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_12) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001337_0;
    int sec_r001337_1;
    int sec_r001337_2;
    int sec_r001337_3;
    int sec_r001337_4;
    int sec_r001337_5;
    int sec_r001337_6;
    int sec_r001337_7;
    int sec_r001337_8;
    int sec_r001337_9;
    int sec_r001337_10;
    int sec_r001337_11;
    int sec_r001337_12;
    int sec_r001337_13;
    int sec_r001337_14;
    int sec_r001337_15;
    int sec_r001337_16;
    int sec_r001337_17;
    int sec_r001337_18;
    int pub_r001337_0;
    int pub_r001337_1;
    int pub_r001337_2;
    int pub_r001337_3;
    int pub_r001337_4;
    int pub_r001337_5;
    int pub_r001337_6;
    int pub_r001337_7;
    int pub_r001337_8;
    int pub_r001337_9;
    int pub_r001337_10;
    int pub_r001337_11;
    int pub_r001337_12;
    int pub_r001337_13;
    int pub_r001337_14;
    int pub_r001337_15;
    int pub_r001337_16;
    int pub_r001337_17;
    int pub_r001337_18;
    int pub_r001337_19;
    int pub_r001337_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001337_0 >= -100 && pub_r001337_0 <= 100);
    __CPROVER_assume(pub_r001337_1 >= -100 && pub_r001337_1 <= 100);
    __CPROVER_assume(pub_r001337_2 >= -100 && pub_r001337_2 <= 100);
    __CPROVER_assume(pub_r001337_3 >= -100 && pub_r001337_3 <= 100);
    __CPROVER_assume(pub_r001337_4 >= -100 && pub_r001337_4 <= 100);
    __CPROVER_assume(pub_r001337_5 >= -100 && pub_r001337_5 <= 100);
    __CPROVER_assume(pub_r001337_6 >= -100 && pub_r001337_6 <= 100);
    __CPROVER_assume(pub_r001337_7 >= -100 && pub_r001337_7 <= 100);
    __CPROVER_assume(pub_r001337_8 >= -100 && pub_r001337_8 <= 100);
    __CPROVER_assume(pub_r001337_9 >= -100 && pub_r001337_9 <= 100);
    __CPROVER_assume(pub_r001337_10 >= -100 && pub_r001337_10 <= 100);
    __CPROVER_assume(pub_r001337_11 >= -100 && pub_r001337_11 <= 100);
    __CPROVER_assume(pub_r001337_12 >= -100 && pub_r001337_12 <= 100);
    __CPROVER_assume(pub_r001337_13 >= -100 && pub_r001337_13 <= 100);
    __CPROVER_assume(pub_r001337_14 >= -100 && pub_r001337_14 <= 100);
    __CPROVER_assume(pub_r001337_15 >= -100 && pub_r001337_15 <= 100);
    __CPROVER_assume(pub_r001337_16 >= -100 && pub_r001337_16 <= 100);
    __CPROVER_assume(pub_r001337_17 >= -100 && pub_r001337_17 <= 100);
    __CPROVER_assume(pub_r001337_18 >= -100 && pub_r001337_18 <= 100);
    __CPROVER_assume(pub_r001337_19 >= -100 && pub_r001337_19 <= 100);
    __CPROVER_assume(pub_r001337_20 >= -100 && pub_r001337_20 <= 100);
    __CPROVER_assume(sec_r001337_0 >= 0 && sec_r001337_0 <= 255);
    __CPROVER_assume(sec_r001337_1 >= 0 && sec_r001337_1 <= 255);
    __CPROVER_assume(sec_r001337_2 >= 0 && sec_r001337_2 <= 255);
    __CPROVER_assume(sec_r001337_3 >= 0 && sec_r001337_3 <= 255);
    __CPROVER_assume(sec_r001337_4 >= 0 && sec_r001337_4 <= 255);
    __CPROVER_assume(sec_r001337_5 >= 0 && sec_r001337_5 <= 255);
    __CPROVER_assume(sec_r001337_6 >= 0 && sec_r001337_6 <= 255);
    __CPROVER_assume(sec_r001337_7 >= 0 && sec_r001337_7 <= 255);
    __CPROVER_assume(sec_r001337_8 >= 0 && sec_r001337_8 <= 255);
    __CPROVER_assume(sec_r001337_9 >= 0 && sec_r001337_9 <= 255);
    __CPROVER_assume(sec_r001337_10 >= 0 && sec_r001337_10 <= 255);
    __CPROVER_assume(sec_r001337_11 >= 0 && sec_r001337_11 <= 255);
    __CPROVER_assume(sec_r001337_12 >= 0 && sec_r001337_12 <= 255);
    __CPROVER_assume(sec_r001337_13 >= 0 && sec_r001337_13 <= 255);
    __CPROVER_assume(sec_r001337_14 >= 0 && sec_r001337_14 <= 255);
    __CPROVER_assume(sec_r001337_15 >= 0 && sec_r001337_15 <= 255);
    __CPROVER_assume(sec_r001337_16 >= 0 && sec_r001337_16 <= 255);
    __CPROVER_assume(sec_r001337_17 >= 0 && sec_r001337_17 <= 255);
    __CPROVER_assume(sec_r001337_18 >= 0 && sec_r001337_18 <= 255);

    struct EventLog_R001337_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001337_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001337_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001337_0 + 7) & 15;
    struct SensorNode_R001337_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001337_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001337_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001337_0 + 9) & 15;

    union ColorPixel_R001337_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001337_3713_0(sec_r001337_0, pub_r001337_1, pub_r001337_2, pub_r001337_3);
    int helper_flow_1 = fn_R001337_3713_1(sec_r001337_1, sec_r001337_2, pub_r001337_3);
    int helper_flow_2 = fn_R001337_3713_2(sec_r001337_2, sec_r001337_3, pub_r001337_4, pub_r001337_5);
    int helper_flow_3 = fn_R001337_3713_3(sec_r001337_3, pub_r001337_4, pub_r001337_5, pub_r001337_6);
    int helper_flow_4 = fn_R001337_3713_4(sec_r001337_4, sec_r001337_5, pub_r001337_6);
    int helper_flow_5 = fn_R001337_3713_5(sec_r001337_5, sec_r001337_6, pub_r001337_7, pub_r001337_8, pub_r001337_9);
    int helper_flow_6 = fn_R001337_3713_6(sec_r001337_6, sec_r001337_7, pub_r001337_8);
    int helper_flow_7 = fn_R001337_3713_7(sec_r001337_7, sec_r001337_8, pub_r001337_9, pub_r001337_10, pub_r001337_11);
    int helper_flow_8 = fn_R001337_3713_8(sec_r001337_8, pub_r001337_9);
    int helper_flow_9 = fn_R001337_3713_9(sec_r001337_9, pub_r001337_10, pub_r001337_11);
    int helper_flow_10 = fn_R001337_3713_10(sec_r001337_10, sec_r001337_11, pub_r001337_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001337_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001337_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001337_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001337_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001337_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_2 ^ pub_r001337_11) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001337_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001337_16 ^ pub_r001337_5) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001337_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001337_10 ^ pub_r001337_6) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001337_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001337_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001337_3 ^ pub_r001337_9) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001337_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001337_2 ^ pub_r001337_13) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001337_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001337_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_8 ^ pub_r001337_15) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001337_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_6 ^ pub_r001337_11) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001337_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001337_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001337_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_8 ^ pub_r001337_7) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001337_8 ^ pub_r001337_13) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_0 ^ pub_r001337_18) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_1 ^ pub_r001337_18) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001337_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001337_5 ^ pub_r001337_13) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001337_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_5 ^ pub_r001337_3) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_3 ^ pub_r001337_13) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001337_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_16 ^ pub_r001337_3) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001337_5 ^ pub_r001337_8) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001337_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_26 ^ pub_r001337_11) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001337_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001337_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001337_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_22 ^ pub_r001337_11) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_28 ^ pub_r001337_19) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_21 ^ pub_r001337_3) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_25 ^ pub_r001337_14) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001337_8 ^ pub_r001337_15) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001337_10 ^ pub_r001337_11) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001337_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_33 ^ pub_r001337_18) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001337_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_21 ^ pub_r001337_20) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001337_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001337_5 ^ pub_r001337_3) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001337_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001337_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001337_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_38 ^ pub_r001337_9) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001337_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001337_17 ^ pub_r001337_11) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001337_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001337_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_9 ^ pub_r001337_4) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001337_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_2 ^ pub_r001337_20) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_31 ^ pub_r001337_18) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001337_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001337_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_40 ^ pub_r001337_13) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (helper_flow_4 ^ pub_r001337_12) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_28 ^ pub_r001337_14) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_40 ^ pub_r001337_13) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001337_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_9 ^ pub_r001337_13) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r001337_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_54 ^ pub_r001337_12) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001337_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001337_17 ^ pub_r001337_12) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001337_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (helper_flow_0 ^ pub_r001337_12) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_34 ^ pub_r001337_5) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_35 ^ pub_r001337_20) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001337_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001337_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_61 ^ pub_r001337_16) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_56 ^ pub_r001337_16) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (helper_flow_10 ^ pub_r001337_9) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001337_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_22 ^ pub_r001337_6) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_25 ^ pub_r001337_18) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001337_14 ^ pub_r001337_17) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001337_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001337_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001337_6 ^ pub_r001337_0) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_58 ^ pub_r001337_7) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_62 ^ pub_r001337_15) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001337_16 ^ pub_r001337_8) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_5 ^ pub_r001337_15) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001337_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001337_8 ^ pub_r001337_7) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_38 ^ pub_r001337_5) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001337_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001337_4 ^ pub_r001337_16) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001337_5 ^ pub_r001337_6) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r001337_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001337_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_58 ^ pub_r001337_12) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001337_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (helper_flow_10 ^ pub_r001337_8) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001337_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_56 ^ pub_r001337_14) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_83 ^ pub_r001337_19) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001337_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_77 ^ pub_r001337_13) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001337_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001337_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001337_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001337_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_28 ^ pub_r001337_20) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_61 ^ pub_r001337_18) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001337_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001337_4 ^ pub_r001337_9) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_10 ^ pub_r001337_18) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001337_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001337_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001337_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_26 ^ pub_r001337_5) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_33 ^ pub_r001337_14) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001337_20 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001337_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_33 ^ pub_r001337_14) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_1 ^ pub_r001337_8) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_54 ^ pub_r001337_18) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001337_4 ^ pub_r001337_1) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_32 ^ pub_r001337_8) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_95 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001337_16 ^ pub_r001337_12) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_53 ^ pub_r001337_11) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001337_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001337_10 ^ pub_r001337_2) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_103 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001337_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001337_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_80 ^ pub_r001337_4) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r001337_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001337_6 ^ pub_r001337_11) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_78 ^ pub_r001337_12) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001337_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (helper_flow_0 ^ pub_r001337_20) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_97 ^ pub_r001337_12) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r001337_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001337_5 ^ pub_r001337_6) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001337_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001337_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_36 ^ pub_r001337_6) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001337_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (helper_flow_9 ^ pub_r001337_2) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001337_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_32 ^ pub_r001337_6) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_98 ^ pub_r001337_5) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_56 ^ pub_r001337_15) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r001337_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_106 ^ pub_r001337_11) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r001337_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_5 ^ pub_r001337_19) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_98 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001337_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_89 ^ pub_r001337_20) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_44 ^ pub_r001337_17) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001337_13 ^ pub_r001337_14) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_70 ^ pub_r001337_4) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_61 ^ pub_r001337_2) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001337_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001337_5 ^ pub_r001337_3) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001337_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001337_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001337_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001337_18 ^ pub_r001337_15) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_7 ^ pub_r001337_20) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001337_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001337_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_58 ^ pub_r001337_3) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r001337_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (sec_r001337_10 ^ pub_r001337_20) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001337_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_19 ^ pub_r001337_8) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_23 ^ pub_r001337_11) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_70 ^ pub_r001337_6) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001337_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001337_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_22 ^ pub_r001337_12) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_119 ^ pub_r001337_10) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001337_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_66 ^ pub_r001337_18) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((sec_r001337_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (sec_r001337_5 ^ pub_r001337_14) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (helper_flow_1 ^ pub_r001337_20) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r001337_6 ^ pub_r001337_5) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_114 ^ pub_r001337_14) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001337_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_75 ^ pub_r001337_15) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_103 ^ pub_r001337_4) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_151 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001337_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_34 ^ pub_r001337_5) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_142 ^ pub_r001337_20) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_137 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001337_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_71 ^ pub_r001337_5) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001337_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001337_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_132 ^ pub_r001337_16) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001337_16 ^ pub_r001337_8) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_153 ^ pub_r001337_4) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_37 ^ pub_r001337_19) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((sec_r001337_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_82 ^ pub_r001337_9) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_106 ^ pub_r001337_1) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_79 ^ pub_r001337_17) & 63;
    if ((stage_v_182 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_182 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_182 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_180 ^ pub_r001337_14) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
