/*
 * Benchmark Program: R001646
 * Security Family: implicit_flow
 * Generator Seed: 664613
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001646_4613_0 {
    unsigned char gain;
    int calib;
    int reading;
    int status;
    short offset;
    int buffer[3];
};

struct StreamBuffer_R001646_4613_1 {
    int checksum;
    int tail;
    int watermark;
    unsigned char head;
    int buffer[3];
};

struct EventLog_R001646_4613_2 {
    int timestamp;
    int severity;
    int facility;
    int signature;
    int buffer[3];
};

union TelemetryField_R001646_4613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001646_4613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001646_4613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int pivot_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_42) & 63;
    acc ^= aux;
    int bound_76 = (aux + st.buffer[1]) & 3;
    switch (bound_76) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int segment_89 = local_arr[aux % 3];
    acc = (acc + segment_89 * 2) & 127;
    int checksum_24 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_24 = (checksum_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_24) & 127;
    }
    int scale_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001646_4613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_46 = local_arr[aux % 3];
    acc = (acc + segment_46 * 2) & 127;
    int anchor_46 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_46 > 10) {
        acc = (acc + anchor_46 * 2 + 5) & 127;
        aux ^= (anchor_46 & 15);
    } else {
        acc = (acc - anchor_46 + 11) & 127;
        aux += 3;
    }
    int phase_64 = (aux + st.buffer[1]) & 3;
    switch (phase_64) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int stride_67 = 0;
    for (int k = 0; k < 3; k++) {
        stride_67 = (stride_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_67) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_67 = local_arr[aux % 3];
    acc = (acc + metric_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001646_4613_4(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int residue_72 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_72 > 30) {
        acc = (acc + residue_72 * 2 + 5) & 127;
        aux ^= (residue_72 & 15);
    } else {
        acc = (acc - residue_72 + 11) & 127;
        aux += 3;
    }
    int quantum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001646_4613_5(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_24) & 63;
    acc ^= aux;
    int checksum_15 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_15 > 43) {
        acc = (acc + checksum_15 * 2 + 5) & 127;
        aux ^= (checksum_15 & 15);
    } else {
        acc = (acc - checksum_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_36 = local_arr[aux % 3];
    acc = (acc + threshold_36 * 2) & 127;
    int stride_68 = (aux + st.buffer[1]) & 3;
    switch (stride_68) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_7(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_90 = (aux + st.buffer[1]) & 3;
    switch (metric_90) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_35) & 63;
    acc ^= aux;
    int residue_24 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_24 > 50) {
        acc = (acc + residue_24 * 2 + 5) & 127;
        aux ^= (residue_24 & 15);
    } else {
        acc = (acc - residue_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001646_4613_8(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_48) & 63;
    acc ^= aux;
    int segment_34 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_34 > 15) {
        acc = (acc + segment_34 * 2 + 5) & 127;
        aux ^= (segment_34 & 15);
    } else {
        acc = (acc - segment_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_73 = local_arr[aux % 3];
    acc = (acc + phase_73 * 2) & 127;
    int threshold_28 = (aux + st.buffer[1]) & 3;
    switch (threshold_28) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_9(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001646_4613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_16 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_16 > 22) {
        acc = (acc + cursor_16 * 2 + 5) & 127;
        aux ^= (cursor_16 & 15);
    } else {
        acc = (acc - cursor_16 + 11) & 127;
        aux += 3;
    }
    int factor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_22) & 63;
    acc ^= aux;
    int segment_83 = (aux + st.buffer[1]) & 3;
    switch (segment_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_54) & 63;
    acc ^= aux;
    int offset_66 = 0;
    for (int k = 0; k < 3; k++) {
        offset_66 = (offset_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_66) & 127;
    }
    int damping_55 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_55 > 43) {
        acc = (acc + damping_55 * 2 + 5) & 127;
        aux ^= (damping_55 & 15);
    } else {
        acc = (acc - damping_55 + 11) & 127;
        aux += 3;
    }
    int scale_86 = (aux + st.buffer[1]) & 3;
    switch (scale_86) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_11(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_43) & 63;
    acc ^= aux;
    int weight_88 = 0;
    for (int k = 0; k < 3; k++) {
        weight_88 = (weight_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_88) & 127;
    }
    int stride_18 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_18 > 48) {
        acc = (acc + stride_18 * 2 + 5) & 127;
        aux ^= (stride_18 & 15);
    } else {
        acc = (acc - stride_18 + 11) & 127;
        aux += 3;
    }
    int coefficient_83 = (aux + st.buffer[1]) & 3;
    switch (coefficient_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_12(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001646_4613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int window_28 = local_arr[aux % 3];
    acc = (acc + window_28 * 2) & 127;
    int factor_80 = (aux + st.buffer[1]) & 3;
    switch (factor_80) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_46 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_46 > 28) {
        acc = (acc + accumulator_46 * 2 + 5) & 127;
        aux ^= (accumulator_46 & 15);
    } else {
        acc = (acc - accumulator_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001646_4613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int margin_65 = local_arr[aux % 3];
    acc = (acc + margin_65 * 2) & 127;
    int damping_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001646_4613_14(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int anchor_75 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_75 = (anchor_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_75) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001646_4613_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001646_4613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_90 = (aux + st.buffer[1]) & 3;
    switch (bound_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_88 = local_arr[aux % 3];
    acc = (acc + accumulator_88 * 2) & 127;
    int parity_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001646_0;
    int sec_r001646_1;
    int sec_r001646_2;
    int sec_r001646_3;
    int sec_r001646_4;
    int sec_r001646_5;
    int sec_r001646_6;
    int sec_r001646_7;
    int sec_r001646_8;
    int sec_r001646_9;
    int sec_r001646_10;
    int sec_r001646_11;
    int sec_r001646_12;
    int sec_r001646_13;
    int sec_r001646_14;
    int sec_r001646_15;
    int sec_r001646_16;
    int sec_r001646_17;
    int sec_r001646_18;
    int sec_r001646_19;
    int sec_r001646_20;
    int sec_r001646_21;
    int sec_r001646_22;
    int sec_r001646_23;
    int pub_r001646_0;
    int pub_r001646_1;
    int pub_r001646_2;
    int pub_r001646_3;
    int pub_r001646_4;
    int pub_r001646_5;
    int pub_r001646_6;
    int pub_r001646_7;
    int pub_r001646_8;
    int pub_r001646_9;
    int pub_r001646_10;
    int pub_r001646_11;
    int pub_r001646_12;
    int pub_r001646_13;
    int pub_r001646_14;
    int pub_r001646_15;
    int pub_r001646_16;
    int pub_r001646_17;
    int pub_r001646_18;
    int pub_r001646_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001646_0 >= -100 && pub_r001646_0 <= 100);
    __CPROVER_assume(pub_r001646_1 >= -100 && pub_r001646_1 <= 100);
    __CPROVER_assume(pub_r001646_2 >= -100 && pub_r001646_2 <= 100);
    __CPROVER_assume(pub_r001646_3 >= -100 && pub_r001646_3 <= 100);
    __CPROVER_assume(pub_r001646_4 >= -100 && pub_r001646_4 <= 100);
    __CPROVER_assume(pub_r001646_5 >= -100 && pub_r001646_5 <= 100);
    __CPROVER_assume(pub_r001646_6 >= -100 && pub_r001646_6 <= 100);
    __CPROVER_assume(pub_r001646_7 >= -100 && pub_r001646_7 <= 100);
    __CPROVER_assume(pub_r001646_8 >= -100 && pub_r001646_8 <= 100);
    __CPROVER_assume(pub_r001646_9 >= -100 && pub_r001646_9 <= 100);
    __CPROVER_assume(pub_r001646_10 >= -100 && pub_r001646_10 <= 100);
    __CPROVER_assume(pub_r001646_11 >= -100 && pub_r001646_11 <= 100);
    __CPROVER_assume(pub_r001646_12 >= -100 && pub_r001646_12 <= 100);
    __CPROVER_assume(pub_r001646_13 >= -100 && pub_r001646_13 <= 100);
    __CPROVER_assume(pub_r001646_14 >= -100 && pub_r001646_14 <= 100);
    __CPROVER_assume(pub_r001646_15 >= -100 && pub_r001646_15 <= 100);
    __CPROVER_assume(pub_r001646_16 >= -100 && pub_r001646_16 <= 100);
    __CPROVER_assume(pub_r001646_17 >= -100 && pub_r001646_17 <= 100);
    __CPROVER_assume(pub_r001646_18 >= -100 && pub_r001646_18 <= 100);
    __CPROVER_assume(pub_r001646_19 >= -100 && pub_r001646_19 <= 100);
    __CPROVER_assume(sec_r001646_0 >= 0 && sec_r001646_0 <= 255);
    __CPROVER_assume(sec_r001646_1 >= 0 && sec_r001646_1 <= 255);
    __CPROVER_assume(sec_r001646_2 >= 0 && sec_r001646_2 <= 255);
    __CPROVER_assume(sec_r001646_3 >= 0 && sec_r001646_3 <= 255);
    __CPROVER_assume(sec_r001646_4 >= 0 && sec_r001646_4 <= 255);
    __CPROVER_assume(sec_r001646_5 >= 0 && sec_r001646_5 <= 255);
    __CPROVER_assume(sec_r001646_6 >= 0 && sec_r001646_6 <= 255);
    __CPROVER_assume(sec_r001646_7 >= 0 && sec_r001646_7 <= 255);
    __CPROVER_assume(sec_r001646_8 >= 0 && sec_r001646_8 <= 255);
    __CPROVER_assume(sec_r001646_9 >= 0 && sec_r001646_9 <= 255);
    __CPROVER_assume(sec_r001646_10 >= 0 && sec_r001646_10 <= 255);
    __CPROVER_assume(sec_r001646_11 >= 0 && sec_r001646_11 <= 255);
    __CPROVER_assume(sec_r001646_12 >= 0 && sec_r001646_12 <= 255);
    __CPROVER_assume(sec_r001646_13 >= 0 && sec_r001646_13 <= 255);
    __CPROVER_assume(sec_r001646_14 >= 0 && sec_r001646_14 <= 255);
    __CPROVER_assume(sec_r001646_15 >= 0 && sec_r001646_15 <= 255);
    __CPROVER_assume(sec_r001646_16 >= 0 && sec_r001646_16 <= 255);
    __CPROVER_assume(sec_r001646_17 >= 0 && sec_r001646_17 <= 255);
    __CPROVER_assume(sec_r001646_18 >= 0 && sec_r001646_18 <= 255);
    __CPROVER_assume(sec_r001646_19 >= 0 && sec_r001646_19 <= 255);
    __CPROVER_assume(sec_r001646_20 >= 0 && sec_r001646_20 <= 255);
    __CPROVER_assume(sec_r001646_21 >= 0 && sec_r001646_21 <= 255);
    __CPROVER_assume(sec_r001646_22 >= 0 && sec_r001646_22 <= 255);
    __CPROVER_assume(sec_r001646_23 >= 0 && sec_r001646_23 <= 255);

    struct SensorNode_R001646_4613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001646_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001646_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001646_0 + 7) & 15;
    struct StreamBuffer_R001646_4613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001646_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001646_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001646_0 + 9) & 15;
    struct EventLog_R001646_4613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001646_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001646_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001646_0 + 11) & 15;

    union TelemetryField_R001646_4613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001646_4613_0(sec_r001646_0, pub_r001646_1, pub_r001646_2, pub_r001646_3);
    int helper_flow_1 = fn_R001646_4613_1(sec_r001646_1, sec_r001646_2, pub_r001646_3, pub_r001646_4, pub_r001646_5);
    int helper_flow_2 = fn_R001646_4613_2(sec_r001646_2, sec_r001646_3, pub_r001646_4, pub_r001646_5, pub_r001646_6);
    int helper_flow_3 = fn_R001646_4613_3(sec_r001646_3, pub_r001646_4, pub_r001646_5, pub_r001646_6, pub_r001646_7);
    int helper_flow_4 = fn_R001646_4613_4(sec_r001646_4, sec_r001646_5);
    int helper_flow_5 = fn_R001646_4613_5(sec_r001646_5, pub_r001646_6);
    int helper_flow_6 = fn_R001646_4613_6(sec_r001646_6, pub_r001646_7, pub_r001646_8, pub_r001646_9, pub_r001646_10);
    int helper_flow_7 = fn_R001646_4613_7(sec_r001646_7, pub_r001646_8);
    int helper_flow_8 = fn_R001646_4613_8(sec_r001646_8, pub_r001646_9);
    int helper_flow_9 = fn_R001646_4613_9(sec_r001646_9, sec_r001646_10, pub_r001646_11);
    int helper_flow_10 = fn_R001646_4613_10(sec_r001646_10, sec_r001646_11, pub_r001646_12, pub_r001646_13, pub_r001646_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001646_9 + pub_r001646_17 * 2 + 5) & 127;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_9 + pub_r001646_12 * 2 + 8) & 127;
    if (stage_v_1 > 32) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_0 + pub_r001646_15 * 2 + 11) & 127;
    if (stage_v_2 > 58) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001646_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_0 + pub_r001646_8 * 2 + 17) & 127;
    if (stage_v_4 > 18) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001646_3 + pub_r001646_18 * 2 + 20) & 127;
    if (stage_v_5 > 57) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001646_19 + pub_r001646_7 * 2 + 23) & 127;
    if (stage_v_6 > 33) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_6 + pub_r001646_19 * 2 + 26) & 127;
    if (stage_v_7 > 23) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001646_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_0 + pub_r001646_13 * 2 + 32) & 127;
    if (stage_v_9 > 50) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_1 + pub_r001646_13 * 2 + 35) & 127;
    if (stage_v_10 > 21) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001646_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001646_11 + pub_r001646_1 * 2 + 41) & 127;
    if (stage_v_12 > 44) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (helper_flow_3 + pub_r001646_8 * 2 + 44) & 127;
    if (stage_v_13 > 52) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_13 + pub_r001646_0 * 2 + 47) & 127;
    if (stage_v_14 > 44) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_9 + pub_r001646_9 * 2 + 50) & 127;
    if (stage_v_15 > 59) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_7 + pub_r001646_3 * 2 + 53) & 127;
    if (stage_v_16 > 19) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001646_21 + pub_r001646_0 * 2 + 56) & 127;
    if (stage_v_17 > 52) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001646_13 + pub_r001646_14 * 2 + 59) & 127;
    if (stage_v_18 > 43) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001646_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_12 + pub_r001646_0 * 2 + 65) & 127;
    if (stage_v_20 > 30) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001646_22 + pub_r001646_17 * 2 + 68) & 127;
    if (stage_v_21 > 51) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001646_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001646_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001646_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001646_22 + pub_r001646_19 * 2 + 80) & 127;
    if (stage_v_25 > 17) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_0 + pub_r001646_11 * 2 + 83) & 127;
    if (stage_v_26 > 39) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_18 + pub_r001646_0 * 2 + 86) & 127;
    if (stage_v_27 > 25) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_18 + pub_r001646_2 * 2 + 89) & 127;
    if (stage_v_28 > 20) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_16 + pub_r001646_1 * 2 + 92) & 127;
    if (stage_v_29 > 52) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001646_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_5 + pub_r001646_3 * 2 + 98) & 127;
    if (stage_v_31 > 31) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001646_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_9 + pub_r001646_11 * 2 + 104) & 127;
    if (stage_v_33 > 53) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001646_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_26 + pub_r001646_17 * 2 + 110) & 127;
    if (stage_v_35 > 35) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_17 + pub_r001646_0 * 2 + 113) & 127;
    if (stage_v_36 > 49) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001646_2 + pub_r001646_1 * 2 + 116) & 127;
    if (stage_v_37 > 36) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001646_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_35 + pub_r001646_11 * 2 + 122) & 127;
    if (stage_v_39 > 45) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_18 + pub_r001646_16 * 2 + 125) & 127;
    if (stage_v_40 > 20) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001646_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001646_20 + pub_r001646_7 * 2 + 131) & 127;
    if (stage_v_42 > 44) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_17 + pub_r001646_0 * 2 + 134) & 127;
    if (stage_v_43 > 58) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001646_2 + pub_r001646_14 * 2 + 137) & 127;
    if (stage_v_44 > 32) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001646_8 + pub_r001646_1 * 2 + 140) & 127;
    if (stage_v_45 > 57) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001646_18 + pub_r001646_8 * 2 + 143) & 127;
    if (stage_v_46 > 53) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001646_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_0 + pub_r001646_15 * 2 + 149) & 127;
    if (stage_v_48 > 17) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_35 + pub_r001646_7 * 2 + 152) & 127;
    if (stage_v_49 > 26) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_28 + pub_r001646_1 * 2 + 155) & 127;
    if (stage_v_50 > 31) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001646_9 + pub_r001646_18 * 2 + 158) & 127;
    if (stage_v_51 > 51) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_7 + pub_r001646_13 * 2 + 161) & 127;
    if (stage_v_52 > 21) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_20 + pub_r001646_2 * 2 + 164) & 127;
    if (stage_v_53 > 50) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001646_9 + pub_r001646_6 * 2 + 167) & 127;
    if (stage_v_54 > 22) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_36 + pub_r001646_14 * 2 + 170) & 127;
    if (stage_v_55 > 54) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001646_22 + pub_r001646_6 * 2 + 173) & 127;
    if (stage_v_56 > 41) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_37 + pub_r001646_6 * 2 + 176) & 127;
    if (stage_v_57 > 40) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_51 + pub_r001646_13 * 2 + 179) & 127;
    if (stage_v_58 > 33) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_12 + pub_r001646_13 * 2 + 182) & 127;
    if (stage_v_59 > 30) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_49 + pub_r001646_11 * 2 + 185) & 127;
    if (stage_v_60 > 53) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001646_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_52 + pub_r001646_0 * 2 + 191) & 127;
    if (stage_v_62 > 20) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_60 + pub_r001646_6 * 2 + 194) & 127;
    if (stage_v_63 > 39) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_16 + pub_r001646_3 * 2 + 197) & 127;
    if (stage_v_64 > 17) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_9 + pub_r001646_5 * 2 + 200) & 127;
    if (stage_v_65 > 24) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001646_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (helper_flow_4 + pub_r001646_5 * 2 + 206) & 127;
    if (stage_v_67 > 47) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001646_10 + pub_r001646_7 * 2 + 209) & 127;
    if (stage_v_68 > 53) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_0 + pub_r001646_2 * 2 + 212) & 127;
    if (stage_v_69 > 49) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_6 + pub_r001646_3 * 2 + 215) & 127;
    if (stage_v_70 > 19) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001646_11 + pub_r001646_2 * 2 + 218) & 127;
    if (stage_v_71 > 42) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001646_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001646_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001646_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_51 + pub_r001646_10 * 2 + 230) & 127;
    if (stage_v_75 > 27) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001646_13 + pub_r001646_18 * 2 + 233) & 127;
    if (stage_v_76 > 29) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_7 + pub_r001646_17 * 2 + 236) & 127;
    if (stage_v_77 > 57) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_2 + pub_r001646_11 * 2 + 239) & 127;
    if (stage_v_78 > 57) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001646_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_0 + pub_r001646_3 * 2 + 245) & 127;
    if (stage_v_80 > 35) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001646_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001646_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_55 + pub_r001646_4 * 2 + 254) & 127;
    if (stage_v_83 > 53) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001646_4 + pub_r001646_10 * 2 + 257) & 127;
    if (stage_v_84 > 24) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001646_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_26 + pub_r001646_16 * 2 + 263) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_65 + pub_r001646_3 * 2 + 266) & 127;
    if (stage_v_87 > 52) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001646_6 + pub_r001646_11 * 2 + 269) & 127;
    if (stage_v_88 > 18) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001646_0 + pub_r001646_2 * 2 + 272) & 127;
    if (stage_v_89 > 21) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_7 + pub_r001646_0 * 2 + 275) & 127;
    if (stage_v_90 > 36) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001646_15 + pub_r001646_16 * 2 + 278) & 127;
    if (stage_v_91 > 59) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_36 + pub_r001646_3 * 2 + 281) & 127;
    if (stage_v_92 > 19) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001646_13 + pub_r001646_15 * 2 + 284) & 127;
    if (stage_v_93 > 24) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_56 + pub_r001646_6 * 2 + 287) & 127;
    if (stage_v_94 > 30) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_91 + pub_r001646_4 * 2 + 290) & 127;
    if (stage_v_95 > 48) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001646_3 + pub_r001646_0 * 2 + 293) & 127;
    if (stage_v_96 > 28) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001646_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_50 + pub_r001646_6 * 2 + 299) & 127;
    if (stage_v_98 > 30) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001646_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_20 + pub_r001646_7 * 2 + 305) & 127;
    if (stage_v_100 > 22) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_98 + pub_r001646_2 * 2 + 308) & 127;
    if (stage_v_101 > 33) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001646_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001646_19 + pub_r001646_16 * 2 + 314) & 127;
    if (stage_v_103 > 16) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001646_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_68 + pub_r001646_0 * 2 + 320) & 127;
    if (stage_v_105 > 19) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001646_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_101 + pub_r001646_9 * 2 + 326) & 127;
    if (stage_v_107 > 58) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_80 + pub_r001646_16 * 2 + 329) & 127;
    if (stage_v_108 > 53) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_98 + pub_r001646_7 * 2 + 332) & 127;
    if (stage_v_109 > 56) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001646_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_10 + pub_r001646_16 * 2 + 338) & 127;
    if (stage_v_111 > 24) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001646_14 + pub_r001646_14 * 2 + 341) & 127;
    if (stage_v_112 > 36) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_100 + pub_r001646_18 * 2 + 344) & 127;
    if (stage_v_113 > 26) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001646_3 + pub_r001646_17 * 2 + 347) & 127;
    if (stage_v_114 > 24) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (helper_flow_1 + pub_r001646_12 * 2 + 350) & 127;
    if (stage_v_115 > 40) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001646_22 + pub_r001646_5 * 2 + 353) & 127;
    if (stage_v_116 > 60) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001646_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_33 + pub_r001646_15 * 2 + 359) & 127;
    if (stage_v_118 > 21) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_69 + pub_r001646_3 * 2 + 362) & 127;
    if (stage_v_119 > 35) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001646_23 + pub_r001646_1 * 2 + 365) & 127;
    if (stage_v_120 > 52) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_111 + pub_r001646_3 * 2 + 368) & 127;
    if (stage_v_121 > 41) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_26 + pub_r001646_14 * 2 + 371) & 127;
    if (stage_v_122 > 58) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_113 + pub_r001646_13 * 2 + 374) & 127;
    if (stage_v_123 > 54) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001646_21 + pub_r001646_9 * 2 + 377) & 127;
    if (stage_v_124 > 47) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001646_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_86 + pub_r001646_8 * 2 + 383) & 127;
    if (stage_v_126 > 44) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_60 + pub_r001646_3 * 2 + 386) & 127;
    if (stage_v_127 > 19) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001646_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001646_12 + pub_r001646_6 * 2 + 392) & 127;
    if (stage_v_129 > 38) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_0 + pub_r001646_1 * 2 + 395) & 127;
    if (stage_v_130 > 18) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001646_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_25 + pub_r001646_8 * 2 + 401) & 127;
    if (stage_v_132 > 27) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001646_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_9 + pub_r001646_11 * 2 + 407) & 127;
    if (stage_v_134 > 42) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_91 + pub_r001646_16 * 2 + 410) & 127;
    if (stage_v_135 > 40) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_93 + pub_r001646_18 * 2 + 413) & 127;
    if (stage_v_136 > 54) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001646_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001646_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001646_23 + pub_r001646_8 * 2 + 422) & 127;
    if (stage_v_139 > 36) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001646_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001646_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001646_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r001646_0 + pub_r001646_16 * 2 + 434) & 127;
    if (stage_v_143 > 35) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001646_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_124 + pub_r001646_4 * 2 + 440) & 127;
    if (stage_v_145 > 27) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_109 + pub_r001646_17 * 2 + 443) & 127;
    if (stage_v_146 > 15) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (sec_r001646_1 + pub_r001646_10 * 2 + 446) & 127;
    if (stage_v_147 > 27) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_123 + pub_r001646_3 * 2 + 449) & 127;
    if (stage_v_148 > 37) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r001646_6 + pub_r001646_2 * 2 + 452) & 127;
    if (stage_v_149 > 25) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_145 + pub_r001646_9 * 2 + 455) & 127;
    if (stage_v_150 > 36) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001646_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_124 + pub_r001646_3 * 2 + 461) & 127;
    if (stage_v_152 > 21) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_13 + pub_r001646_0 * 2 + 464) & 127;
    if (stage_v_153 > 48) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_145 + pub_r001646_14 * 2 + 467) & 127;
    if (stage_v_154 > 18) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_77 + pub_r001646_14 * 2 + 470) & 127;
    if (stage_v_155 > 37) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001646_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_57 + pub_r001646_11 * 2 + 476) & 127;
    if (stage_v_157 > 38) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001646_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001646_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_116 + pub_r001646_15 * 2 + 485) & 127;
    if (stage_v_160 > 15) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001646_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001646_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001646_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001646_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (helper_flow_2 + pub_r001646_12 * 2 + 500) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_114 + pub_r001646_12 * 2 + 503) & 127;
    if (stage_v_166 > 29) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_121 + pub_r001646_4 * 2 + 506) & 127;
    if (stage_v_167 > 32) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_107 + pub_r001646_11 * 2 + 509) & 127;
    if (stage_v_168 > 56) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001646_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001646_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001646_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_103 + pub_r001646_3 * 2 + 521) & 127;
    if (stage_v_172 > 48) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_71 + pub_r001646_19 * 2 + 524) & 127;
    if (stage_v_173 > 16) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_130 + pub_r001646_8 * 2 + 527) & 127;
    if (stage_v_174 > 50) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_7 + pub_r001646_4 * 2 + 530) & 127;
    if (stage_v_175 > 47) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001646_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_63 + pub_r001646_11 * 2 + 536) & 127;
    if (stage_v_177 > 34) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001646_19 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001646_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_126 + pub_r001646_0 * 2 + 545) & 127;
    if (stage_v_180 > 50) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_48 + pub_r001646_2 * 2 + 548) & 127;
    if (stage_v_181 > 29) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_145 + pub_r001646_11 * 2 + 551) & 127;
    if (stage_v_182 > 43) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001646_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_15 + pub_r001646_19 * 2 + 557) & 127;
    if (stage_v_184 > 39) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001646_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_153 + pub_r001646_19 * 2 + 563) & 127;
    if (stage_v_186 > 28) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001646_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_15 + pub_r001646_19 * 2 + 569) & 127;
    if (stage_v_188 > 25) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_27 + pub_r001646_8 * 2 + 572) & 127;
    if (stage_v_189 > 25) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_13 + pub_r001646_7 * 2 + 575) & 127;
    if (stage_v_190 > 44) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001646_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_120 + pub_r001646_0 * 2 + 581) & 127;
    if (stage_v_192 > 56) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_127 + pub_r001646_0 * 2 + 584) & 127;
    if (stage_v_193 > 60) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_4 + pub_r001646_19 * 2 + 587) & 127;
    if (stage_v_194 > 57) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001646_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_146 + pub_r001646_1 * 2 + 593) & 127;
    if (stage_v_196 > 43) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_114 + pub_r001646_10 * 2 + 596) & 127;
    if (stage_v_197 > 41) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_167 + pub_r001646_0 * 2 + 599) & 127;
    if (stage_v_198 > 18) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001646_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001646_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001646_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_31 + pub_r001646_3 * 2 + 611) & 127;
    if (stage_v_202 > 38) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (sec_r001646_9 + pub_r001646_14 * 2 + 614) & 127;
    if (stage_v_203 > 18) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_46 + pub_r001646_14 * 2 + 617) & 127;
    if (stage_v_204 > 46) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_194 + pub_r001646_19 * 2 + 620) & 127;
    if (stage_v_205 > 60) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001646_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_70 + pub_r001646_16 * 2 + 626) & 127;
    if (stage_v_207 > 30) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001646_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_53 + pub_r001646_11 * 2 + 632) & 127;
    if (stage_v_209 > 29) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_198 + pub_r001646_0 * 2 + 635) & 127;
    if (stage_v_210 > 53) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001646_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_12 + pub_r001646_17 * 2 + 641) & 127;
    if (stage_v_212 > 45) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_1 + pub_r001646_18 * 2 + 644) & 127;
    if (stage_v_213 > 49) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001646_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_76 + pub_r001646_17 * 2 + 650) & 127;
    if (stage_v_215 > 43) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001646_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001646_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001646_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_49 + pub_r001646_10 * 2 + 662) & 127;
    if (stage_v_219 > 47) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_129 + pub_r001646_18 * 2 + 665) & 127;
    if (stage_v_220 > 20) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (sec_r001646_17 + pub_r001646_18 * 2 + 668) & 127;
    if (stage_v_221 > 47) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (sec_r001646_17 + pub_r001646_8 * 2 + 671) & 127;
    if (stage_v_222 > 24) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001646_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (sec_r001646_0 + pub_r001646_14 * 2 + 677) & 127;
    if (stage_v_224 > 41) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_202 + pub_r001646_18 * 2 + 680) & 127;
    if (stage_v_225 > 44) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001646_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (stage_v_14 + pub_r001646_11 * 2 + 686) & 127;
    if (stage_v_227 > 54) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
