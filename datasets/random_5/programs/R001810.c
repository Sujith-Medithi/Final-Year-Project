/*
 * Benchmark Program: R001810
 * Security Family: mixed_control_data
 * Generator Seed: 681013
 * High Inputs: 17 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001810_1013_0 {
    unsigned char id;
    int stop_bits;
    short parity;
    unsigned char timeout;
    short port;
    int buffer[3];
};

struct SensorNode_R001810_1013_1 {
    short reading;
    short offset;
    unsigned char gain;
    int buffer[3];
};

union TelemetryField_R001810_1013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001810_1013_0(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quantum_88 = (aux + st.buffer[1]) & 3;
    switch (quantum_88) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_59 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_59 = (quantum_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_59) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_1(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int vector_31 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_31 > 37) {
        acc = (acc + vector_31 * 2 + 5) & 127;
        aux ^= (vector_31 & 15);
    } else {
        acc = (acc - vector_31 + 11) & 127;
        aux += 3;
    }
    int anchor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001810_1013_2(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int checksum_35 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_35 > 12) {
        acc = (acc + checksum_35 * 2 + 5) & 127;
        aux ^= (checksum_35 & 15);
    } else {
        acc = (acc - checksum_35 + 11) & 127;
        aux += 3;
    }
    int accumulator_52 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_52 = (accumulator_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_52) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int delta_47 = local_arr[aux % 3];
    acc = (acc + delta_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_4(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int pivot_15 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_15 > 30) {
        acc = (acc + pivot_15 * 2 + 5) & 127;
        aux ^= (pivot_15 & 15);
    } else {
        acc = (acc - pivot_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_57 = local_arr[aux % 3];
    acc = (acc + pivot_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int accumulator_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_38) & 63;
    acc ^= aux;
    int delta_21 = 0;
    for (int k = 0; k < 2; k++) {
        delta_21 = (delta_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_6(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int stride_44 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_44 > 40) {
        acc = (acc + stride_44 * 2 + 5) & 127;
        aux ^= (stride_44 & 15);
    } else {
        acc = (acc - stride_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_66 = (aux + st.buffer[1]) & 3;
    switch (quantum_66) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_67 = 0;
    for (int k = 0; k < 2; k++) {
        window_67 = (window_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_7(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int weight_53 = (aux + st.buffer[1]) & 3;
    switch (weight_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_78 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_78 > 38) {
        acc = (acc + coefficient_78 * 2 + 5) & 127;
        aux ^= (coefficient_78 & 15);
    } else {
        acc = (acc - coefficient_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tally_72 = 0;
    for (int k = 0; k < 3; k++) {
        tally_72 = (tally_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_72) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_76 = local_arr[aux % 3];
    acc = (acc + coefficient_76 * 2) & 127;
    int sample_15 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_15 > 50) {
        acc = (acc + sample_15 * 2 + 5) & 127;
        aux ^= (sample_15 & 15);
    } else {
        acc = (acc - sample_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_46) & 63;
    acc ^= aux;
    int anchor_73 = (aux + st.buffer[1]) & 3;
    switch (anchor_73) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_28 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_28 = (index_reg_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int cursor_90 = local_arr[aux % 3];
    acc = (acc + cursor_90 * 2) & 127;
    int weight_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_50) & 63;
    acc ^= aux;
    int metric_10 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_10 > 45) {
        acc = (acc + metric_10 * 2 + 5) & 127;
        aux ^= (metric_10 & 15);
    } else {
        acc = (acc - metric_10 + 11) & 127;
        aux += 3;
    }
    int stride_87 = 0;
    for (int k = 0; k < 2; k++) {
        stride_87 = (stride_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_87) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_45 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_45 > 27) {
        acc = (acc + checksum_45 * 2 + 5) & 127;
        aux ^= (checksum_45 & 15);
    } else {
        acc = (acc - checksum_45 + 11) & 127;
        aux += 3;
    }
    int window_66 = (aux + st.buffer[1]) & 3;
    switch (window_66) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_43 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_43 > 39) {
        acc = (acc + phase_43 * 2 + 5) & 127;
        aux ^= (phase_43 & 15);
    } else {
        acc = (acc - phase_43 + 11) & 127;
        aux += 3;
    }
    int anchor_43 = (aux + st.buffer[1]) & 3;
    switch (anchor_43) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001810_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_54 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_54 = (quantum_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_54) & 127;
    }
    int bound_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_99) & 63;
    acc ^= aux;
    int stride_44 = (aux + st.buffer[1]) & 3;
    switch (stride_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_14(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int segment_66 = local_arr[aux % 3];
    acc = (acc + segment_66 * 2) & 127;
    int weight_66 = (aux + st.buffer[1]) & 3;
    switch (weight_66) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_67 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_67 = (anchor_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_67) & 127;
    }
    int window_33 = (st.buffer[0] * 3 + aux) & 63;
    if (window_33 > 39) {
        acc = (acc + window_33 * 2 + 5) & 127;
        aux ^= (window_33 & 15);
    } else {
        acc = (acc - window_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001810_1013_16(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int tracker_56 = (aux + st.buffer[1]) & 3;
    switch (tracker_56) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_67 = local_arr[aux % 3];
    acc = (acc + pivot_67 * 2) & 127;
    int metric_77 = 0;
    for (int k = 0; k < 2; k++) {
        metric_77 = (metric_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_77) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_17(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_84 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_84 = (checksum_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_84) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_36 = local_arr[aux % 3];
    acc = (acc + tracker_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001810_1013_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001810_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int cursor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_24) & 63;
    acc ^= aux;
    int weight_54 = 0;
    for (int k = 0; k < 2; k++) {
        weight_54 = (weight_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_54) & 127;
    }
    int phase_55 = (aux + st.buffer[1]) & 3;
    switch (phase_55) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001810_0;
    int sec_r001810_1;
    int sec_r001810_2;
    int sec_r001810_3;
    int sec_r001810_4;
    int sec_r001810_5;
    int sec_r001810_6;
    int sec_r001810_7;
    int sec_r001810_8;
    int sec_r001810_9;
    int sec_r001810_10;
    int sec_r001810_11;
    int sec_r001810_12;
    int sec_r001810_13;
    int sec_r001810_14;
    int sec_r001810_15;
    int sec_r001810_16;
    int pub_r001810_0;
    int pub_r001810_1;
    int pub_r001810_2;
    int pub_r001810_3;
    int pub_r001810_4;
    int pub_r001810_5;
    int pub_r001810_6;
    int pub_r001810_7;
    int pub_r001810_8;
    int pub_r001810_9;
    int pub_r001810_10;
    int pub_r001810_11;
    int pub_r001810_12;
    int pub_r001810_13;
    int pub_r001810_14;
    int pub_r001810_15;
    int pub_r001810_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001810_0 >= -100 && pub_r001810_0 <= 100);
    __CPROVER_assume(pub_r001810_1 >= -100 && pub_r001810_1 <= 100);
    __CPROVER_assume(pub_r001810_2 >= -100 && pub_r001810_2 <= 100);
    __CPROVER_assume(pub_r001810_3 >= -100 && pub_r001810_3 <= 100);
    __CPROVER_assume(pub_r001810_4 >= -100 && pub_r001810_4 <= 100);
    __CPROVER_assume(pub_r001810_5 >= -100 && pub_r001810_5 <= 100);
    __CPROVER_assume(pub_r001810_6 >= -100 && pub_r001810_6 <= 100);
    __CPROVER_assume(pub_r001810_7 >= -100 && pub_r001810_7 <= 100);
    __CPROVER_assume(pub_r001810_8 >= -100 && pub_r001810_8 <= 100);
    __CPROVER_assume(pub_r001810_9 >= -100 && pub_r001810_9 <= 100);
    __CPROVER_assume(pub_r001810_10 >= -100 && pub_r001810_10 <= 100);
    __CPROVER_assume(pub_r001810_11 >= -100 && pub_r001810_11 <= 100);
    __CPROVER_assume(pub_r001810_12 >= -100 && pub_r001810_12 <= 100);
    __CPROVER_assume(pub_r001810_13 >= -100 && pub_r001810_13 <= 100);
    __CPROVER_assume(pub_r001810_14 >= -100 && pub_r001810_14 <= 100);
    __CPROVER_assume(pub_r001810_15 >= -100 && pub_r001810_15 <= 100);
    __CPROVER_assume(pub_r001810_16 >= -100 && pub_r001810_16 <= 100);
    __CPROVER_assume(sec_r001810_0 >= 0 && sec_r001810_0 <= 255);
    __CPROVER_assume(sec_r001810_1 >= 0 && sec_r001810_1 <= 255);
    __CPROVER_assume(sec_r001810_2 >= 0 && sec_r001810_2 <= 255);
    __CPROVER_assume(sec_r001810_3 >= 0 && sec_r001810_3 <= 255);
    __CPROVER_assume(sec_r001810_4 >= 0 && sec_r001810_4 <= 255);
    __CPROVER_assume(sec_r001810_5 >= 0 && sec_r001810_5 <= 255);
    __CPROVER_assume(sec_r001810_6 >= 0 && sec_r001810_6 <= 255);
    __CPROVER_assume(sec_r001810_7 >= 0 && sec_r001810_7 <= 255);
    __CPROVER_assume(sec_r001810_8 >= 0 && sec_r001810_8 <= 255);
    __CPROVER_assume(sec_r001810_9 >= 0 && sec_r001810_9 <= 255);
    __CPROVER_assume(sec_r001810_10 >= 0 && sec_r001810_10 <= 255);
    __CPROVER_assume(sec_r001810_11 >= 0 && sec_r001810_11 <= 255);
    __CPROVER_assume(sec_r001810_12 >= 0 && sec_r001810_12 <= 255);
    __CPROVER_assume(sec_r001810_13 >= 0 && sec_r001810_13 <= 255);
    __CPROVER_assume(sec_r001810_14 >= 0 && sec_r001810_14 <= 255);
    __CPROVER_assume(sec_r001810_15 >= 0 && sec_r001810_15 <= 255);
    __CPROVER_assume(sec_r001810_16 >= 0 && sec_r001810_16 <= 255);

    struct DeviceConfig_R001810_1013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001810_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001810_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001810_0 + 7) & 15;
    struct SensorNode_R001810_1013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001810_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001810_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001810_0 + 9) & 15;

    union TelemetryField_R001810_1013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001810_1013_0(sec_r001810_0, pub_r001810_1);
    int helper_flow_1 = fn_R001810_1013_1(sec_r001810_1, pub_r001810_2);
    int helper_flow_2 = fn_R001810_1013_2(sec_r001810_2, pub_r001810_3, pub_r001810_4);
    int helper_flow_3 = fn_R001810_1013_3(sec_r001810_3, pub_r001810_4, pub_r001810_5, pub_r001810_6);
    int helper_flow_4 = fn_R001810_1013_4(sec_r001810_4, sec_r001810_5, pub_r001810_6);
    int helper_flow_5 = fn_R001810_1013_5(sec_r001810_5, pub_r001810_6, pub_r001810_7, pub_r001810_8);
    int helper_flow_6 = fn_R001810_1013_6(sec_r001810_6, sec_r001810_7, pub_r001810_8);
    int helper_flow_7 = fn_R001810_1013_7(sec_r001810_7, sec_r001810_8);
    int helper_flow_8 = fn_R001810_1013_8(sec_r001810_8, pub_r001810_9, pub_r001810_10, pub_r001810_11, pub_r001810_12);
    int helper_flow_9 = fn_R001810_1013_9(sec_r001810_9, sec_r001810_10, pub_r001810_11, pub_r001810_12, pub_r001810_13);
    int helper_flow_10 = fn_R001810_1013_10(sec_r001810_10, sec_r001810_11, pub_r001810_12, pub_r001810_13, pub_r001810_14);
    int helper_flow_11 = fn_R001810_1013_11(sec_r001810_11, pub_r001810_12, pub_r001810_13, pub_r001810_14, pub_r001810_15);
    int helper_flow_12 = fn_R001810_1013_12(sec_r001810_12, sec_r001810_13, pub_r001810_14, pub_r001810_15, pub_r001810_16);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_0 > 38) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_1 > 41) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001810_11 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_2 > 34) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001810_11 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_3 > 43) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001810_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001810_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_6 > 45) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_7 > 31) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001810_15 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_8 > 29) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001810_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001810_12 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_10 > 36) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001810_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_12 > 49) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_13 > 36) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_14 > 44) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001810_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_16 > 22) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001810_12 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_17 > 35) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001810_8 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_18 > 45) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_19 > 46) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001810_2 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_20 > 38) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001810_12 ^ 0x2A) * 2 + pub_r001810_10) & 127;
    if (stage_v_21 > 44) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001810_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001810_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001810_16 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_24 > 23) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_25 > 46) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_26 > 20) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001810_12 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_27 > 42) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_28 > 47) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001810_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_30 > 49) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001810_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_32 > 23) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_33 > 47) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001810_11 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_34 > 21) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_35 > 37) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_36 > 34) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001810_7 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_37 > 46) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001810_13 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_38 > 25) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_39 > 31) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001810_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001810_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001810_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_43 > 43) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_44 > 30) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001810_10) & 127;
    if (stage_v_45 > 29) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001810_6 ^ 0x2A) * 2 + pub_r001810_7) & 127;
    if (stage_v_46 > 29) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001810_5 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_47 > 35) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001810_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001810_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001810_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001810_5 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_51 > 50) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001810_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_53 > 44) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_54 > 40) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001810_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001810_16) & 127;
    if (stage_v_56 > 42) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001810_0 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_57 > 33) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_58 > 48) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001810_5) & 127;
    if (stage_v_59 > 22) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001810_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_61 > 28) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_62 > 40) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001810_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_64 > 45) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_65 > 48) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001810_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001810_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001810_6 ^ 0x2A) * 2 + pub_r001810_16) & 127;
    if (stage_v_68 > 45) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001810_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001810_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_71 > 43) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001810_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_73 > 37) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001810_5) & 127;
    if (stage_v_74 > 36) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_75 > 22) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_76 > 40) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_77 > 41) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_78 > 46) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_79 > 44) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_80 > 23) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_81 > 21) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_82 > 26) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001810_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001810_12 ^ 0x2A) * 2 + pub_r001810_10) & 127;
    if (stage_v_84 > 22) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001810_16) & 127;
    if (stage_v_85 > 34) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001810_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_87 > 49) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_88 > 30) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_89 > 48) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001810_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001810_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001810_16) & 127;
    if (stage_v_92 > 28) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001810_11 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_93 > 34) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_94 > 29) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001810_7) & 127;
    if (stage_v_95 > 42) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001810_7) & 127;
    if (stage_v_96 > 42) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_97 > 30) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001810_5 ^ 0x2A) * 2 + pub_r001810_10) & 127;
    if (stage_v_98 > 25) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_99 > 21) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r001810_15 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_100 > 39) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001810_1 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_101 > 39) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r001810_10 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_102 > 23) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_103 > 21) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001810_5 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_104 > 29) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_105 > 45) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001810_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_107 > 45) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_108 > 49) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_109 > 42) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_110 > 48) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_111 > 22) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001810_10) & 127;
    if (stage_v_112 > 24) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001810_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_115 > 29) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_116 > 46) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_117 > 40) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_118 > 23) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001810_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_120 > 40) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001810_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_122 > 38) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_123 > 20) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001810_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r001810_16 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_125 > 39) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001810_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_127 > 39) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_128 > 28) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_129 > 29) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_130 > 31) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_131 > 39) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_132 > 21) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001810_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_134 > 36) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001810_7) & 127;
    if (stage_v_135 > 47) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_136 > 40) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001810_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001810_5) & 127;
    if (stage_v_138 > 31) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_139 > 32) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_140 > 29) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001810_10 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_141 > 36) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r001810_13 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_142 > 44) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_143 > 39) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_144 > 30) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_145 > 44) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_146 > 38) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_147 > 34) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001810_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001810_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_150 > 30) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_151 > 29) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001810_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001810_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_154 > 35) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_155 > 48) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_156 > 34) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_157 > 24) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_158 > 50) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001810_16) & 127;
    if (stage_v_159 > 21) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001810_7) & 127;
    if (stage_v_160 > 23) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_161 > 21) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_162 > 36) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_163 > 43) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_164 > 49) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_165 > 45) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_166 > 43) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_167 > 31) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_168 > 22) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_169 > 42) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_170 > 47) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_171 > 32) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001810_0 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_172 > 47) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_173 > 48) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001810_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_175 > 49) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001810_7) & 127;
    if (stage_v_176 > 24) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_177 > 29) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_178 > 50) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001810_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001810_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001810_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001810_15) & 127;
    if (stage_v_182 > 27) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001810_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001810_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_185 > 32) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001810_12) & 127;
    if (stage_v_186 > 31) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001810_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_188 > 35) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001810_4) & 127;
    if (stage_v_189 > 33) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_190 > 28) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_191 > 38) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r001810_16 ^ 0x2A) * 2 + pub_r001810_2) & 127;
    if (stage_v_192 > 47) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_193 > 32) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_194 > 31) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_195 > 47) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_196 > 29) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_197 > 35) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001810_6) & 127;
    if (stage_v_198 > 27) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001810_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001810_3) & 127;
    if (stage_v_200 > 23) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001810_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001810_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001810_11) & 127;
    if (stage_v_203 > 47) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001810_0 ^ 0x2A) * 2 + pub_r001810_9) & 127;
    if (stage_v_204 > 28) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001810_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001810_14) & 127;
    if (stage_v_206 > 23) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_186 ^ 0x2A) * 2 + pub_r001810_16) & 127;
    if (stage_v_207 > 27) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001810_8) & 127;
    if (stage_v_208 > 39) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001810_5) & 127;
    if (stage_v_209 > 34) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001810_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001810_1) & 127;
    if (stage_v_211 > 29) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001810_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001810_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001810_0) & 127;
    if (stage_v_214 > 34) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001810_13) & 127;
    if (stage_v_215 > 20) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
