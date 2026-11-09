/*
 * Benchmark Program: R001077
 * Security Family: nested_implicit_flow
 * Generator Seed: 607713
 * High Inputs: 21 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001077_7713_0 {
    int checksum;
    short head;
    short state;
    unsigned char tail;
    unsigned char watermark;
    unsigned char capacity;
    int buffer[3];
};

struct DeviceConfig_R001077_7713_1 {
    short id;
    short baud_rate;
    int timeout;
    unsigned char stop_bits;
    int buffer[3];
};

struct SensorNode_R001077_7713_2 {
    int offset;
    short reading;
    short status;
    unsigned char threshold;
    unsigned char calib;
    int buffer[3];
};

struct FilterState_R001077_7713_3 {
    short cutoff;
    int prev_in;
    int gain_db;
    int prev_out;
    int buffer[3];
};

union TelemetryField_R001077_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001077_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int bound_57 = 0;
    for (int k = 0; k < 2; k++) {
        bound_57 = (bound_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_57) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_46 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_46 > 12) {
        acc = (acc + delta_46 * 2 + 5) & 127;
        aux ^= (delta_46 & 15);
    } else {
        acc = (acc - delta_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_72 = local_arr[aux % 3];
    acc = (acc + tally_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_1(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001077_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_43) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int damping_25 = (aux + st.buffer[1]) & 3;
    switch (damping_25) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_27 = 0;
    for (int k = 0; k < 2; k++) {
        offset_27 = (offset_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_27) & 127;
    }
    int metric_56 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_56 > 15) {
        acc = (acc + metric_56 * 2 + 5) & 127;
        aux ^= (metric_56 & 15);
    } else {
        acc = (acc - metric_56 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001077_7713_3(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001077_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_19 = (aux + st.buffer[1]) & 3;
    switch (metric_19) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_69 = local_arr[aux % 3];
    acc = (acc + margin_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int metric_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_5(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001077_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int accumulator_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_41) & 63;
    acc ^= aux;
    int factor_98 = 0;
    for (int k = 0; k < 3; k++) {
        factor_98 = (factor_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_98) & 127;
    }
    int accumulator_29 = (aux + st.buffer[1]) & 3;
    switch (accumulator_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_6(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int residue_22 = 0;
    for (int k = 0; k < 3; k++) {
        residue_22 = (residue_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_22) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_64 = local_arr[aux % 3];
    acc = (acc + coefficient_64 * 2) & 127;
    int tally_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_41) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001077_7713_7(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int pivot_99 = local_arr[aux % 3];
    acc = (acc + pivot_99 * 2) & 127;
    int vector_31 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_31 > 27) {
        acc = (acc + vector_31 * 2 + 5) & 127;
        aux ^= (vector_31 & 15);
    } else {
        acc = (acc - vector_31 + 11) & 127;
        aux += 3;
    }
    int window_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001077_7713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_28 = (aux + st.buffer[1]) & 3;
    switch (weight_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_50 = 0;
    for (int k = 0; k < 3; k++) {
        window_50 = (window_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_50) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_39 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_39 = (quantum_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_39) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_50 = (st.buffer[0] * 3 + aux) & 63;
    if (window_50 > 44) {
        acc = (acc + window_50 * 2 + 5) & 127;
        aux ^= (window_50 & 15);
    } else {
        acc = (acc - window_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001077_7713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001077_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quantum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_46) & 63;
    acc ^= aux;
    int accumulator_58 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_58 > 35) {
        acc = (acc + accumulator_58 * 2 + 5) & 127;
        aux ^= (accumulator_58 & 15);
    } else {
        acc = (acc - accumulator_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001077_7713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001077_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quantum_16 = (aux + st.buffer[1]) & 3;
    switch (quantum_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_54 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_54 = (coefficient_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_54) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001077_7713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int factor_19 = 0;
    for (int k = 0; k < 3; k++) {
        factor_19 = (factor_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_19) & 127;
    }
    int vector_47 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_47 > 46) {
        acc = (acc + vector_47 * 2 + 5) & 127;
        aux ^= (vector_47 & 15);
    } else {
        acc = (acc - vector_47 + 11) & 127;
        aux += 3;
    }
    int damping_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001077_7713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001077_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int stride_86 = local_arr[aux % 3];
    acc = (acc + stride_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_87 = (aux + st.buffer[1]) & 3;
    switch (damping_87) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001077_7713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quotient_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_81) & 63;
    acc ^= aux;
    int scale_98 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_98 > 30) {
        acc = (acc + scale_98 * 2 + 5) & 127;
        aux ^= (scale_98 & 15);
    } else {
        acc = (acc - scale_98 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_15(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001077_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_46 = (aux + st.buffer[1]) & 3;
    switch (factor_46) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_11 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_11 = (quotient_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_11) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_16(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001077_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int stride_78 = local_arr[aux % 3];
    acc = (acc + stride_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_24 = (aux + st.buffer[1]) & 3;
    switch (quantum_24) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001077_7713_17(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001077_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_48 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_48 > 39) {
        acc = (acc + sample_48 * 2 + 5) & 127;
        aux ^= (sample_48 & 15);
    } else {
        acc = (acc - sample_48 + 11) & 127;
        aux += 3;
    }
    int anchor_49 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_49 = (anchor_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_49) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_24 = local_arr[aux % 3];
    acc = (acc + factor_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001077_7713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001077_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_41) & 63;
    acc ^= aux;
    int stride_19 = (aux + st.buffer[1]) & 3;
    switch (stride_19) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_52 = local_arr[aux % 3];
    acc = (acc + coefficient_52 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001077_0;
    int sec_r001077_1;
    int sec_r001077_2;
    int sec_r001077_3;
    int sec_r001077_4;
    int sec_r001077_5;
    int sec_r001077_6;
    int sec_r001077_7;
    int sec_r001077_8;
    int sec_r001077_9;
    int sec_r001077_10;
    int sec_r001077_11;
    int sec_r001077_12;
    int sec_r001077_13;
    int sec_r001077_14;
    int sec_r001077_15;
    int sec_r001077_16;
    int sec_r001077_17;
    int sec_r001077_18;
    int sec_r001077_19;
    int sec_r001077_20;
    int pub_r001077_0;
    int pub_r001077_1;
    int pub_r001077_2;
    int pub_r001077_3;
    int pub_r001077_4;
    int pub_r001077_5;
    int pub_r001077_6;
    int pub_r001077_7;
    int pub_r001077_8;
    int pub_r001077_9;
    int pub_r001077_10;
    int pub_r001077_11;
    int pub_r001077_12;
    int pub_r001077_13;
    int pub_r001077_14;
    int pub_r001077_15;
    int pub_r001077_16;
    int pub_r001077_17;
    int pub_r001077_18;
    int pub_r001077_19;
    int pub_r001077_20;
    int pub_r001077_21;
    int pub_r001077_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001077_0 >= -100 && pub_r001077_0 <= 100);
    __CPROVER_assume(pub_r001077_1 >= -100 && pub_r001077_1 <= 100);
    __CPROVER_assume(pub_r001077_2 >= -100 && pub_r001077_2 <= 100);
    __CPROVER_assume(pub_r001077_3 >= -100 && pub_r001077_3 <= 100);
    __CPROVER_assume(pub_r001077_4 >= -100 && pub_r001077_4 <= 100);
    __CPROVER_assume(pub_r001077_5 >= -100 && pub_r001077_5 <= 100);
    __CPROVER_assume(pub_r001077_6 >= -100 && pub_r001077_6 <= 100);
    __CPROVER_assume(pub_r001077_7 >= -100 && pub_r001077_7 <= 100);
    __CPROVER_assume(pub_r001077_8 >= -100 && pub_r001077_8 <= 100);
    __CPROVER_assume(pub_r001077_9 >= -100 && pub_r001077_9 <= 100);
    __CPROVER_assume(pub_r001077_10 >= -100 && pub_r001077_10 <= 100);
    __CPROVER_assume(pub_r001077_11 >= -100 && pub_r001077_11 <= 100);
    __CPROVER_assume(pub_r001077_12 >= -100 && pub_r001077_12 <= 100);
    __CPROVER_assume(pub_r001077_13 >= -100 && pub_r001077_13 <= 100);
    __CPROVER_assume(pub_r001077_14 >= -100 && pub_r001077_14 <= 100);
    __CPROVER_assume(pub_r001077_15 >= -100 && pub_r001077_15 <= 100);
    __CPROVER_assume(pub_r001077_16 >= -100 && pub_r001077_16 <= 100);
    __CPROVER_assume(pub_r001077_17 >= -100 && pub_r001077_17 <= 100);
    __CPROVER_assume(pub_r001077_18 >= -100 && pub_r001077_18 <= 100);
    __CPROVER_assume(pub_r001077_19 >= -100 && pub_r001077_19 <= 100);
    __CPROVER_assume(pub_r001077_20 >= -100 && pub_r001077_20 <= 100);
    __CPROVER_assume(pub_r001077_21 >= -100 && pub_r001077_21 <= 100);
    __CPROVER_assume(pub_r001077_22 >= -100 && pub_r001077_22 <= 100);
    __CPROVER_assume(sec_r001077_0 >= 0 && sec_r001077_0 <= 255);
    __CPROVER_assume(sec_r001077_1 >= 0 && sec_r001077_1 <= 255);
    __CPROVER_assume(sec_r001077_2 >= 0 && sec_r001077_2 <= 255);
    __CPROVER_assume(sec_r001077_3 >= 0 && sec_r001077_3 <= 255);
    __CPROVER_assume(sec_r001077_4 >= 0 && sec_r001077_4 <= 255);
    __CPROVER_assume(sec_r001077_5 >= 0 && sec_r001077_5 <= 255);
    __CPROVER_assume(sec_r001077_6 >= 0 && sec_r001077_6 <= 255);
    __CPROVER_assume(sec_r001077_7 >= 0 && sec_r001077_7 <= 255);
    __CPROVER_assume(sec_r001077_8 >= 0 && sec_r001077_8 <= 255);
    __CPROVER_assume(sec_r001077_9 >= 0 && sec_r001077_9 <= 255);
    __CPROVER_assume(sec_r001077_10 >= 0 && sec_r001077_10 <= 255);
    __CPROVER_assume(sec_r001077_11 >= 0 && sec_r001077_11 <= 255);
    __CPROVER_assume(sec_r001077_12 >= 0 && sec_r001077_12 <= 255);
    __CPROVER_assume(sec_r001077_13 >= 0 && sec_r001077_13 <= 255);
    __CPROVER_assume(sec_r001077_14 >= 0 && sec_r001077_14 <= 255);
    __CPROVER_assume(sec_r001077_15 >= 0 && sec_r001077_15 <= 255);
    __CPROVER_assume(sec_r001077_16 >= 0 && sec_r001077_16 <= 255);
    __CPROVER_assume(sec_r001077_17 >= 0 && sec_r001077_17 <= 255);
    __CPROVER_assume(sec_r001077_18 >= 0 && sec_r001077_18 <= 255);
    __CPROVER_assume(sec_r001077_19 >= 0 && sec_r001077_19 <= 255);
    __CPROVER_assume(sec_r001077_20 >= 0 && sec_r001077_20 <= 255);

    struct StreamBuffer_R001077_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001077_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001077_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001077_0 + 7) & 15;
    struct DeviceConfig_R001077_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001077_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001077_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001077_0 + 9) & 15;
    struct SensorNode_R001077_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001077_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001077_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001077_0 + 11) & 15;
    struct FilterState_R001077_7713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001077_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001077_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001077_0 + 13) & 15;

    union TelemetryField_R001077_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001077_7713_0(sec_r001077_0, sec_r001077_1, pub_r001077_2);
    int helper_flow_1 = fn_R001077_7713_1(sec_r001077_1, pub_r001077_2);
    int helper_flow_2 = fn_R001077_7713_2(sec_r001077_2, pub_r001077_3, pub_r001077_4, pub_r001077_5, pub_r001077_6);
    int helper_flow_3 = fn_R001077_7713_3(sec_r001077_3, sec_r001077_4, pub_r001077_5);
    int helper_flow_4 = fn_R001077_7713_4(sec_r001077_4, pub_r001077_5, pub_r001077_6, pub_r001077_7, pub_r001077_8);
    int helper_flow_5 = fn_R001077_7713_5(sec_r001077_5, sec_r001077_6, pub_r001077_7);
    int helper_flow_6 = fn_R001077_7713_6(sec_r001077_6, sec_r001077_7, pub_r001077_8);
    int helper_flow_7 = fn_R001077_7713_7(sec_r001077_7, sec_r001077_8);
    int helper_flow_8 = fn_R001077_7713_8(sec_r001077_8, pub_r001077_9, pub_r001077_10, pub_r001077_11, pub_r001077_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001077_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_1 ^ pub_r001077_11) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001077_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001077_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001077_21 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001077_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001077_5 ^ pub_r001077_1) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001077_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001077_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001077_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001077_17 ^ pub_r001077_18) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001077_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001077_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001077_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001077_13 ^ pub_r001077_13) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001077_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_6 ^ pub_r001077_8) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001077_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001077_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_8 ^ pub_r001077_21) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001077_12 ^ pub_r001077_5) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001077_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001077_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_6 ^ pub_r001077_7) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r001077_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_5 ^ pub_r001077_10) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001077_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001077_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001077_2 ^ pub_r001077_0) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001077_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001077_7 ^ pub_r001077_17) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001077_2 ^ pub_r001077_20) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001077_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001077_4 ^ pub_r001077_17) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r001077_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001077_22 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001077_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001077_20 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001077_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_12 ^ pub_r001077_13) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r001077_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001077_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001077_1 ^ pub_r001077_13) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001077_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_1 ^ pub_r001077_5) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_8 ^ pub_r001077_14) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001077_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001077_8 ^ pub_r001077_11) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001077_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_1 ^ pub_r001077_13) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_36 ^ pub_r001077_11) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001077_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_15 ^ pub_r001077_18) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (helper_flow_4 ^ pub_r001077_12) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (helper_flow_7 ^ pub_r001077_22) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001077_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_25 ^ pub_r001077_22) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001077_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (sec_r001077_10 ^ pub_r001077_19) & 63;
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
    int stage_v_46 = (pub_r001077_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (helper_flow_2 ^ pub_r001077_1) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001077_10 ^ pub_r001077_21) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_15 ^ pub_r001077_8) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r001077_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001077_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001077_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001077_22 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_12 ^ pub_r001077_1) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_30 ^ pub_r001077_20) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001077_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_18 ^ pub_r001077_1) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001077_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_47 ^ pub_r001077_17) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_53 ^ pub_r001077_9) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_42 ^ pub_r001077_2) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_15 ^ pub_r001077_16) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001077_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_32 ^ pub_r001077_16) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001077_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (helper_flow_2 ^ pub_r001077_11) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r001077_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001077_9 ^ pub_r001077_13) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_25 ^ pub_r001077_12) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (helper_flow_2 ^ pub_r001077_9) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_65 ^ pub_r001077_13) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_65 ^ pub_r001077_18) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r001077_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001077_18 ^ pub_r001077_19) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001077_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001077_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001077_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_35 ^ pub_r001077_11) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_6 ^ pub_r001077_0) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_57 ^ pub_r001077_15) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001077_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_60 ^ pub_r001077_18) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001077_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_66 ^ pub_r001077_20) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r001077_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001077_7 ^ pub_r001077_5) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001077_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001077_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001077_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_3 ^ pub_r001077_10) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001077_20 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_54 ^ pub_r001077_1) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001077_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001077_16 ^ pub_r001077_21) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001077_15 ^ pub_r001077_21) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001077_3 ^ pub_r001077_11) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_1 ^ pub_r001077_0) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r001077_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_19 ^ pub_r001077_4) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001077_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001077_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_87 ^ pub_r001077_4) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_67 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001077_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_11 ^ pub_r001077_17) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001077_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001077_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001077_11 ^ pub_r001077_7) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001077_15 ^ pub_r001077_12) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_67 ^ pub_r001077_2) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001077_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001077_3 ^ pub_r001077_11) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001077_12 ^ pub_r001077_12) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_81 ^ pub_r001077_11) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r001077_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_35 ^ pub_r001077_19) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001077_17 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001077_2 ^ pub_r001077_17) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_81 ^ pub_r001077_21) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001077_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001077_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_86 ^ pub_r001077_11) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001077_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001077_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001077_5 ^ pub_r001077_6) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001077_12 ^ pub_r001077_11) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_78 ^ pub_r001077_18) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_56 ^ pub_r001077_9) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_102 ^ pub_r001077_1) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r001077_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001077_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_100 ^ pub_r001077_21) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r001077_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001077_12 ^ pub_r001077_22) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001077_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_56 ^ pub_r001077_13) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r001077_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001077_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_11 ^ pub_r001077_13) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r001077_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001077_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_6 ^ pub_r001077_12) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r001077_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001077_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_8 ^ pub_r001077_6) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001077_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001077_19 ^ pub_r001077_5) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_83 ^ pub_r001077_16) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001077_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001077_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (helper_flow_8 ^ pub_r001077_1) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_102 ^ pub_r001077_20) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_96 ^ pub_r001077_17) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_126 ^ pub_r001077_21) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001077_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001077_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_101 ^ pub_r001077_19) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_85 ^ pub_r001077_16) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_71 ^ pub_r001077_22) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r001077_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_97 ^ pub_r001077_14) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (helper_flow_4 ^ pub_r001077_18) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_124 ^ pub_r001077_9) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_133 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_1 ^ pub_r001077_2) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_143 ^ pub_r001077_6) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r001077_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_42 ^ pub_r001077_16) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001077_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001077_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (helper_flow_7 ^ pub_r001077_10) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r001077_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r001077_16 ^ pub_r001077_19) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_58 ^ pub_r001077_22) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_48 ^ pub_r001077_20) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_71 ^ pub_r001077_9) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001077_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001077_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_104 ^ pub_r001077_14) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((sec_r001077_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001077_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_77 ^ pub_r001077_9) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_55 ^ pub_r001077_14) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_134 ^ pub_r001077_0) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((sec_r001077_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_1 ^ pub_r001077_11) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_85 ^ pub_r001077_15) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_134 ^ pub_r001077_19) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001077_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001077_0 ^ pub_r001077_11) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((sec_r001077_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_35 ^ pub_r001077_9) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_163 ^ pub_r001077_13) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (helper_flow_3 ^ pub_r001077_1) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_113 ^ pub_r001077_9) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_49 ^ pub_r001077_10) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((sec_r001077_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_118 ^ pub_r001077_2) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_167 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_75 ^ pub_r001077_12) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (helper_flow_3 ^ pub_r001077_7) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((stage_v_159 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_87 ^ pub_r001077_10) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (sec_r001077_3 ^ pub_r001077_14) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((sec_r001077_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
