/*
 * Benchmark Program: R001016
 * Security Family: implicit_flow
 * Generator Seed: 601613
 * High Inputs: 24 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001016_1613_0 {
    unsigned char status;
    short threshold;
    int gain;
    int calib;
    unsigned char offset;
    int buffer[3];
};

struct FilterState_R001016_1613_1 {
    int prev_in;
    unsigned char damping;
    unsigned char prev_out;
    int cutoff;
    int mode;
    unsigned char gain_db;
    int buffer[3];
};

struct DeviceConfig_R001016_1613_2 {
    int parity;
    int baud_rate;
    int stop_bits;
    int buffer[3];
};

struct Vector3D_R001016_1613_3 {
    short coord_y;
    short coord_x;
    int heading;
    int buffer[3];
};

union TelemetryField_R001016_1613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001016_1613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001016_1613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_71 = (aux + st.buffer[1]) & 3;
    switch (bound_71) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_89 = 0;
    for (int k = 0; k < 2; k++) {
        offset_89 = (offset_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_89) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001016_1613_1(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001016_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_46 = (aux + st.buffer[1]) & 3;
    switch (tracker_46) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_43 = local_arr[aux % 3];
    acc = (acc + factor_43 * 2) & 127;
    int vector_48 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_48 > 37) {
        acc = (acc + vector_48 * 2 + 5) & 127;
        aux ^= (vector_48 & 15);
    } else {
        acc = (acc - vector_48 + 11) & 127;
        aux += 3;
    }
    int sample_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001016_1613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int scale_22 = local_arr[aux % 3];
    acc = (acc + scale_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001016_1613_3(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001016_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int parity_77 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_77 > 22) {
        acc = (acc + parity_77 * 2 + 5) & 127;
        aux ^= (parity_77 & 15);
    } else {
        acc = (acc - parity_77 + 11) & 127;
        aux += 3;
    }
    int accumulator_99 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_99 = (accumulator_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_99) & 127;
    }
    int coefficient_28 = (aux + st.buffer[1]) & 3;
    switch (coefficient_28) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_4(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_64 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_64 = (quotient_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_64) & 127;
    }
    int segment_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001016_1613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001016_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int phase_85 = local_arr[aux % 3];
    acc = (acc + phase_85 * 2) & 127;
    int mask_85 = 0;
    for (int k = 0; k < 2; k++) {
        mask_85 = (mask_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_85) & 127;
    }
    int segment_55 = (aux + st.buffer[1]) & 3;
    switch (segment_55) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_6(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001016_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_27 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_27 > 20) {
        acc = (acc + threshold_27 * 2 + 5) & 127;
        aux ^= (threshold_27 & 15);
    } else {
        acc = (acc - threshold_27 + 11) & 127;
        aux += 3;
    }
    int cursor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001016_1613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001016_1613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int checksum_83 = local_arr[aux % 3];
    acc = (acc + checksum_83 * 2) & 127;
    int tally_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_75) & 63;
    acc ^= aux;
    int segment_94 = (aux + st.buffer[1]) & 3;
    switch (segment_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001016_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int parity_66 = (aux + st.buffer[1]) & 3;
    switch (parity_66) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_95 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_95 > 27) {
        acc = (acc + metric_95 * 2 + 5) & 127;
        aux ^= (metric_95 & 15);
    } else {
        acc = (acc - metric_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_9(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_31 = local_arr[aux % 3];
    acc = (acc + window_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001016_1613_10(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001016_1613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int window_25 = (aux + st.buffer[1]) & 3;
    switch (window_25) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_41) & 63;
    acc ^= aux;
    int stride_58 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_58 > 42) {
        acc = (acc + stride_58 * 2 + 5) & 127;
        aux ^= (stride_58 & 15);
    } else {
        acc = (acc - stride_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int vector_74 = (aux + st.buffer[1]) & 3;
    switch (vector_74) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_43 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_43 > 36) {
        acc = (acc + metric_43 * 2 + 5) & 127;
        aux ^= (metric_43 & 15);
    } else {
        acc = (acc - metric_43 + 11) & 127;
        aux += 3;
    }
    int checksum_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001016_1613_12(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_12 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_12 = (quotient_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_12) & 127;
    }
    int metric_53 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_53 > 30) {
        acc = (acc + metric_53 * 2 + 5) & 127;
        aux ^= (metric_53 & 15);
    } else {
        acc = (acc - metric_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_13(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001016_1613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_83 = local_arr[aux % 3];
    acc = (acc + window_83 * 2) & 127;
    int cursor_22 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_22 > 40) {
        acc = (acc + cursor_22 * 2 + 5) & 127;
        aux ^= (cursor_22 & 15);
    } else {
        acc = (acc - cursor_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_14(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001016_1613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int checksum_84 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_84 = (checksum_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_84) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_69 = (aux + st.buffer[1]) & 3;
    switch (offset_69) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_15(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001016_1613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_62 = (aux + st.buffer[1]) & 3;
    switch (checksum_62) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_79 = local_arr[aux % 3];
    acc = (acc + quantum_79 * 2) & 127;
    int weight_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_38) & 63;
    acc ^= aux;
    int index_reg_13 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_13 > 14) {
        acc = (acc + index_reg_13 * 2 + 5) & 127;
        aux ^= (index_reg_13 & 15);
    } else {
        acc = (acc - index_reg_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_16(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001016_1613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int parity_46 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_46 > 31) {
        acc = (acc + parity_46 * 2 + 5) & 127;
        aux ^= (parity_46 & 15);
    } else {
        acc = (acc - parity_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_41 = local_arr[aux % 3];
    acc = (acc + delta_41 * 2) & 127;
    int mask_60 = 0;
    for (int k = 0; k < 2; k++) {
        mask_60 = (mask_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_60) & 127;
    }
    int vector_60 = (aux + st.buffer[1]) & 3;
    switch (vector_60) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001016_1613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int index_reg_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_19 = local_arr[aux % 3];
    acc = (acc + parity_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001016_1613_18(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_41 = (aux + st.buffer[1]) & 3;
    switch (mask_41) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_49 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_49 > 34) {
        acc = (acc + vector_49 * 2 + 5) & 127;
        aux ^= (vector_49 & 15);
    } else {
        acc = (acc - vector_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001016_1613_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001016_1613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int sample_39 = local_arr[aux % 3];
    acc = (acc + sample_39 * 2) & 127;
    int tally_92 = 0;
    for (int k = 0; k < 3; k++) {
        tally_92 = (tally_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_92) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001016_0;
    int sec_r001016_1;
    int sec_r001016_2;
    int sec_r001016_3;
    int sec_r001016_4;
    int sec_r001016_5;
    int sec_r001016_6;
    int sec_r001016_7;
    int sec_r001016_8;
    int sec_r001016_9;
    int sec_r001016_10;
    int sec_r001016_11;
    int sec_r001016_12;
    int sec_r001016_13;
    int sec_r001016_14;
    int sec_r001016_15;
    int sec_r001016_16;
    int sec_r001016_17;
    int sec_r001016_18;
    int sec_r001016_19;
    int sec_r001016_20;
    int sec_r001016_21;
    int sec_r001016_22;
    int sec_r001016_23;
    int pub_r001016_0;
    int pub_r001016_1;
    int pub_r001016_2;
    int pub_r001016_3;
    int pub_r001016_4;
    int pub_r001016_5;
    int pub_r001016_6;
    int pub_r001016_7;
    int pub_r001016_8;
    int pub_r001016_9;
    int pub_r001016_10;
    int pub_r001016_11;
    int pub_r001016_12;
    int pub_r001016_13;
    int pub_r001016_14;
    int pub_r001016_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001016_0 >= -100 && pub_r001016_0 <= 100);
    __CPROVER_assume(pub_r001016_1 >= -100 && pub_r001016_1 <= 100);
    __CPROVER_assume(pub_r001016_2 >= -100 && pub_r001016_2 <= 100);
    __CPROVER_assume(pub_r001016_3 >= -100 && pub_r001016_3 <= 100);
    __CPROVER_assume(pub_r001016_4 >= -100 && pub_r001016_4 <= 100);
    __CPROVER_assume(pub_r001016_5 >= -100 && pub_r001016_5 <= 100);
    __CPROVER_assume(pub_r001016_6 >= -100 && pub_r001016_6 <= 100);
    __CPROVER_assume(pub_r001016_7 >= -100 && pub_r001016_7 <= 100);
    __CPROVER_assume(pub_r001016_8 >= -100 && pub_r001016_8 <= 100);
    __CPROVER_assume(pub_r001016_9 >= -100 && pub_r001016_9 <= 100);
    __CPROVER_assume(pub_r001016_10 >= -100 && pub_r001016_10 <= 100);
    __CPROVER_assume(pub_r001016_11 >= -100 && pub_r001016_11 <= 100);
    __CPROVER_assume(pub_r001016_12 >= -100 && pub_r001016_12 <= 100);
    __CPROVER_assume(pub_r001016_13 >= -100 && pub_r001016_13 <= 100);
    __CPROVER_assume(pub_r001016_14 >= -100 && pub_r001016_14 <= 100);
    __CPROVER_assume(pub_r001016_15 >= -100 && pub_r001016_15 <= 100);
    __CPROVER_assume(sec_r001016_0 >= 0 && sec_r001016_0 <= 255);
    __CPROVER_assume(sec_r001016_1 >= 0 && sec_r001016_1 <= 255);
    __CPROVER_assume(sec_r001016_2 >= 0 && sec_r001016_2 <= 255);
    __CPROVER_assume(sec_r001016_3 >= 0 && sec_r001016_3 <= 255);
    __CPROVER_assume(sec_r001016_4 >= 0 && sec_r001016_4 <= 255);
    __CPROVER_assume(sec_r001016_5 >= 0 && sec_r001016_5 <= 255);
    __CPROVER_assume(sec_r001016_6 >= 0 && sec_r001016_6 <= 255);
    __CPROVER_assume(sec_r001016_7 >= 0 && sec_r001016_7 <= 255);
    __CPROVER_assume(sec_r001016_8 >= 0 && sec_r001016_8 <= 255);
    __CPROVER_assume(sec_r001016_9 >= 0 && sec_r001016_9 <= 255);
    __CPROVER_assume(sec_r001016_10 >= 0 && sec_r001016_10 <= 255);
    __CPROVER_assume(sec_r001016_11 >= 0 && sec_r001016_11 <= 255);
    __CPROVER_assume(sec_r001016_12 >= 0 && sec_r001016_12 <= 255);
    __CPROVER_assume(sec_r001016_13 >= 0 && sec_r001016_13 <= 255);
    __CPROVER_assume(sec_r001016_14 >= 0 && sec_r001016_14 <= 255);
    __CPROVER_assume(sec_r001016_15 >= 0 && sec_r001016_15 <= 255);
    __CPROVER_assume(sec_r001016_16 >= 0 && sec_r001016_16 <= 255);
    __CPROVER_assume(sec_r001016_17 >= 0 && sec_r001016_17 <= 255);
    __CPROVER_assume(sec_r001016_18 >= 0 && sec_r001016_18 <= 255);
    __CPROVER_assume(sec_r001016_19 >= 0 && sec_r001016_19 <= 255);
    __CPROVER_assume(sec_r001016_20 >= 0 && sec_r001016_20 <= 255);
    __CPROVER_assume(sec_r001016_21 >= 0 && sec_r001016_21 <= 255);
    __CPROVER_assume(sec_r001016_22 >= 0 && sec_r001016_22 <= 255);
    __CPROVER_assume(sec_r001016_23 >= 0 && sec_r001016_23 <= 255);

    struct SensorNode_R001016_1613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001016_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001016_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001016_0 + 7) & 15;
    struct FilterState_R001016_1613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001016_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001016_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001016_0 + 9) & 15;
    struct DeviceConfig_R001016_1613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001016_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001016_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001016_0 + 11) & 15;
    struct Vector3D_R001016_1613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001016_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001016_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001016_0 + 13) & 15;

    union TelemetryField_R001016_1613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001016_1613_0(sec_r001016_0, sec_r001016_1, pub_r001016_2, pub_r001016_3, pub_r001016_4);
    int helper_flow_1 = fn_R001016_1613_1(sec_r001016_1, sec_r001016_2);
    int helper_flow_2 = fn_R001016_1613_2(sec_r001016_2, sec_r001016_3, pub_r001016_4, pub_r001016_5);
    int helper_flow_3 = fn_R001016_1613_3(sec_r001016_3, sec_r001016_4);
    int helper_flow_4 = fn_R001016_1613_4(sec_r001016_4, sec_r001016_5);
    int helper_flow_5 = fn_R001016_1613_5(sec_r001016_5, sec_r001016_6, pub_r001016_7, pub_r001016_8, pub_r001016_9);
    int helper_flow_6 = fn_R001016_1613_6(sec_r001016_6, sec_r001016_7);
    int helper_flow_7 = fn_R001016_1613_7(sec_r001016_7, pub_r001016_8, pub_r001016_9, pub_r001016_10, pub_r001016_11);
    int helper_flow_8 = fn_R001016_1613_8(sec_r001016_8, pub_r001016_9, pub_r001016_10, pub_r001016_11, pub_r001016_12);
    int helper_flow_9 = fn_R001016_1613_9(sec_r001016_9, sec_r001016_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001016_9 + pub_r001016_2 * 2 + 5) & 127;
    if (stage_v_0 > 25) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001016_21 + pub_r001016_13 * 2 + 8) & 127;
    if (stage_v_1 > 27) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001016_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001016_20 + pub_r001016_1 * 2 + 14) & 127;
    if (stage_v_3 > 29) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001016_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001016_15 + pub_r001016_3 * 2 + 20) & 127;
    if (stage_v_5 > 16) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001016_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_8 + pub_r001016_6 * 2 + 26) & 127;
    if (stage_v_7 > 20) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_7 + pub_r001016_14 * 2 + 29) & 127;
    if (stage_v_8 > 20) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001016_2 + pub_r001016_6 * 2 + 32) & 127;
    if (stage_v_9 > 38) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_1 + pub_r001016_15 * 2 + 35) & 127;
    if (stage_v_10 > 17) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001016_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001016_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001016_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_8 + pub_r001016_5 * 2 + 47) & 127;
    if (stage_v_14 > 31) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001016_14 + pub_r001016_1 * 2 + 50) & 127;
    if (stage_v_15 > 17) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001016_14 + pub_r001016_15 * 2 + 53) & 127;
    if (stage_v_16 > 19) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001016_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001016_13 + pub_r001016_13 * 2 + 59) & 127;
    if (stage_v_18 > 21) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_8 + pub_r001016_8 * 2 + 62) & 127;
    if (stage_v_19 > 33) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001016_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001016_3 + pub_r001016_3 * 2 + 68) & 127;
    if (stage_v_21 > 52) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001016_18 + pub_r001016_13 * 2 + 71) & 127;
    if (stage_v_22 > 42) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001016_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001016_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_8 + pub_r001016_0 * 2 + 80) & 127;
    if (stage_v_25 > 16) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001016_15 + pub_r001016_3 * 2 + 83) & 127;
    if (stage_v_26 > 53) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_15 + pub_r001016_6 * 2 + 86) & 127;
    if (stage_v_27 > 55) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001016_6 + pub_r001016_12 * 2 + 89) & 127;
    if (stage_v_28 > 27) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001016_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_22 + pub_r001016_11 * 2 + 95) & 127;
    if (stage_v_30 > 38) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001016_0 + pub_r001016_12 * 2 + 98) & 127;
    if (stage_v_31 > 56) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001016_11 + pub_r001016_10 * 2 + 101) & 127;
    if (stage_v_32 > 18) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_32 + pub_r001016_3 * 2 + 104) & 127;
    if (stage_v_33 > 59) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001016_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_14 + pub_r001016_12 * 2 + 110) & 127;
    if (stage_v_35 > 43) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_10 + pub_r001016_10 * 2 + 113) & 127;
    if (stage_v_36 > 20) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_5 + pub_r001016_11 * 2 + 116) & 127;
    if (stage_v_37 > 38) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_1 + pub_r001016_2 * 2 + 119) & 127;
    if (stage_v_38 > 44) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001016_5 + pub_r001016_11 * 2 + 122) & 127;
    if (stage_v_39 > 17) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_9 + pub_r001016_11 * 2 + 125) & 127;
    if (stage_v_40 > 48) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001016_11 + pub_r001016_13 * 2 + 128) & 127;
    if (stage_v_41 > 47) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_3 + pub_r001016_12 * 2 + 131) & 127;
    if (stage_v_42 > 27) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001016_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_38 + pub_r001016_2 * 2 + 137) & 127;
    if (stage_v_44 > 40) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001016_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001016_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001016_17 + pub_r001016_6 * 2 + 146) & 127;
    if (stage_v_47 > 37) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001016_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001016_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_8 + pub_r001016_4 * 2 + 155) & 127;
    if (stage_v_50 > 26) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_25 + pub_r001016_9 * 2 + 158) & 127;
    if (stage_v_51 > 20) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (helper_flow_4 + pub_r001016_8 * 2 + 161) & 127;
    if (stage_v_52 > 34) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_8 + pub_r001016_6 * 2 + 164) & 127;
    if (stage_v_53 > 24) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_44 + pub_r001016_13 * 2 + 167) & 127;
    if (stage_v_54 > 43) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001016_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_51 + pub_r001016_15 * 2 + 173) & 127;
    if (stage_v_56 > 24) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001016_21 + pub_r001016_3 * 2 + 176) & 127;
    if (stage_v_57 > 26) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_36 + pub_r001016_3 * 2 + 179) & 127;
    if (stage_v_58 > 29) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001016_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001016_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001016_9 + pub_r001016_14 * 2 + 188) & 127;
    if (stage_v_61 > 28) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001016_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001016_20 + pub_r001016_4 * 2 + 194) & 127;
    if (stage_v_63 > 54) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_57 + pub_r001016_12 * 2 + 197) & 127;
    if (stage_v_64 > 17) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (helper_flow_2 + pub_r001016_7 * 2 + 200) & 127;
    if (stage_v_65 > 43) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001016_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r001016_13 + pub_r001016_12 * 2 + 206) & 127;
    if (stage_v_67 > 31) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
        sec_accum ^= (stage_v_67 & 31);
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_22 + pub_r001016_5 * 2 + 209) & 127;
    if (stage_v_68 > 26) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_0 + pub_r001016_2 * 2 + 212) & 127;
    if (stage_v_69 > 21) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_15 + pub_r001016_13 * 2 + 215) & 127;
    if (stage_v_70 > 16) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_51 + pub_r001016_15 * 2 + 218) & 127;
    if (stage_v_71 > 21) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001016_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001016_18 + pub_r001016_15 * 2 + 224) & 127;
    if (stage_v_73 > 41) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001016_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_26 + pub_r001016_3 * 2 + 230) & 127;
    if (stage_v_75 > 53) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001016_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001016_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_1 + pub_r001016_3 * 2 + 239) & 127;
    if (stage_v_78 > 25) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_44 + pub_r001016_13 * 2 + 242) & 127;
    if (stage_v_79 > 26) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001016_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_41 + pub_r001016_4 * 2 + 248) & 127;
    if (stage_v_81 > 47) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_65 + pub_r001016_6 * 2 + 251) & 127;
    if (stage_v_82 > 17) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_61 + pub_r001016_3 * 2 + 254) & 127;
    if (stage_v_83 > 40) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001016_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001016_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_69 + pub_r001016_0 * 2 + 263) & 127;
    if (stage_v_86 > 43) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001016_15 + pub_r001016_12 * 2 + 266) & 127;
    if (stage_v_87 > 19) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001016_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_10 + pub_r001016_8 * 2 + 272) & 127;
    if (stage_v_89 > 50) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_18 + pub_r001016_8 * 2 + 275) & 127;
    if (stage_v_90 > 30) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_14 + pub_r001016_12 * 2 + 278) & 127;
    if (stage_v_91 > 41) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001016_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001016_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_75 + pub_r001016_12 * 2 + 287) & 127;
    if (stage_v_94 > 24) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001016_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_36 + pub_r001016_11 * 2 + 293) & 127;
    if (stage_v_96 > 17) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001016_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_5 + pub_r001016_15 * 2 + 299) & 127;
    if (stage_v_98 > 35) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001016_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001016_6 + pub_r001016_7 * 2 + 305) & 127;
    if (stage_v_100 > 31) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_3 + pub_r001016_3 * 2 + 308) & 127;
    if (stage_v_101 > 39) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001016_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_0 + pub_r001016_6 * 2 + 314) & 127;
    if (stage_v_103 > 31) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_83 + pub_r001016_4 * 2 + 317) & 127;
    if (stage_v_104 > 24) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001016_23 + pub_r001016_1 * 2 + 320) & 127;
    if (stage_v_105 > 48) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001016_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_7 + pub_r001016_9 * 2 + 326) & 127;
    if (stage_v_107 > 15) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_36 + pub_r001016_8 * 2 + 329) & 127;
    if (stage_v_108 > 18) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001016_5 + pub_r001016_6 * 2 + 332) & 127;
    if (stage_v_109 > 44) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_30 + pub_r001016_10 * 2 + 335) & 127;
    if (stage_v_110 > 54) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001016_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_40 + pub_r001016_2 * 2 + 341) & 127;
    if (stage_v_112 > 26) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001016_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_61 + pub_r001016_0 * 2 + 347) & 127;
    if (stage_v_114 > 43) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001016_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001016_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_73 + pub_r001016_11 * 2 + 356) & 127;
    if (stage_v_117 > 20) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001016_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001016_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (helper_flow_2 + pub_r001016_11 * 2 + 365) & 127;
    if (stage_v_120 > 54) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_1 + pub_r001016_0 * 2 + 368) & 127;
    if (stage_v_121 > 34) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001016_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_27 + pub_r001016_2 * 2 + 374) & 127;
    if (stage_v_123 > 55) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001016_20 + pub_r001016_6 * 2 + 377) & 127;
    if (stage_v_124 > 54) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001016_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001016_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001016_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_39 + pub_r001016_13 * 2 + 389) & 127;
    if (stage_v_128 > 18) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_61 + pub_r001016_13 * 2 + 392) & 127;
    if (stage_v_129 > 26) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001016_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_69 + pub_r001016_0 * 2 + 398) & 127;
    if (stage_v_131 > 60) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_37 + pub_r001016_3 * 2 + 401) & 127;
    if (stage_v_132 > 51) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001016_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_105 + pub_r001016_10 * 2 + 407) & 127;
    if (stage_v_134 > 21) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_120 + pub_r001016_8 * 2 + 410) & 127;
    if (stage_v_135 > 27) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_19 + pub_r001016_1 * 2 + 413) & 127;
    if (stage_v_136 > 15) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_112 + pub_r001016_1 * 2 + 416) & 127;
    if (stage_v_137 > 17) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_124 + pub_r001016_4 * 2 + 419) & 127;
    if (stage_v_138 > 23) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001016_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001016_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001016_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (sec_r001016_15 + pub_r001016_8 * 2 + 431) & 127;
    if (stage_v_142 > 29) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r001016_17 + pub_r001016_3 * 2 + 434) & 127;
    if (stage_v_143 > 33) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_100 + pub_r001016_15 * 2 + 437) & 127;
    if (stage_v_144 > 15) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_107 + pub_r001016_12 * 2 + 440) & 127;
    if (stage_v_145 > 26) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_137 + pub_r001016_10 * 2 + 443) & 127;
    if (stage_v_146 > 41) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_1 + pub_r001016_0 * 2 + 446) & 127;
    if (stage_v_147 > 43) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (helper_flow_8 + pub_r001016_8 * 2 + 449) & 127;
    if (stage_v_148 > 53) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_70 + pub_r001016_7 * 2 + 452) & 127;
    if (stage_v_149 > 17) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_128 + pub_r001016_4 * 2 + 455) & 127;
    if (stage_v_150 > 16) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_114 + pub_r001016_10 * 2 + 458) & 127;
    if (stage_v_151 > 33) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_57 + pub_r001016_0 * 2 + 461) & 127;
    if (stage_v_152 > 51) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001016_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_120 + pub_r001016_7 * 2 + 467) & 127;
    if (stage_v_154 > 38) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001016_6 + pub_r001016_5 * 2 + 470) & 127;
    if (stage_v_155 > 31) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_132 + pub_r001016_12 * 2 + 473) & 127;
    if (stage_v_156 > 34) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_32 + pub_r001016_10 * 2 + 476) & 127;
    if (stage_v_157 > 48) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001016_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_32 + pub_r001016_2 * 2 + 482) & 127;
    if (stage_v_159 > 32) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_100 + pub_r001016_0 * 2 + 485) & 127;
    if (stage_v_160 > 26) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_41 + pub_r001016_10 * 2 + 488) & 127;
    if (stage_v_161 > 36) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_87 + pub_r001016_13 * 2 + 491) & 127;
    if (stage_v_162 > 47) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_123 + pub_r001016_11 * 2 + 494) & 127;
    if (stage_v_163 > 29) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_19 + pub_r001016_0 * 2 + 497) & 127;
    if (stage_v_164 > 46) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001016_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001016_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001016_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_15 + pub_r001016_5 * 2 + 509) & 127;
    if (stage_v_168 > 46) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001016_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_137 + pub_r001016_11 * 2 + 515) & 127;
    if (stage_v_170 > 47) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_61 + pub_r001016_11 * 2 + 518) & 127;
    if (stage_v_171 > 29) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001016_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_123 + pub_r001016_15 * 2 + 524) & 127;
    if (stage_v_173 > 37) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_160 + pub_r001016_15 * 2 + 527) & 127;
    if (stage_v_174 > 16) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001016_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_16 + pub_r001016_7 * 2 + 533) & 127;
    if (stage_v_176 > 23) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001016_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001016_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_78 + pub_r001016_3 * 2 + 542) & 127;
    if (stage_v_179 > 25) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001016_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_132 + pub_r001016_8 * 2 + 548) & 127;
    if (stage_v_181 > 39) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_79 + pub_r001016_1 * 2 + 551) & 127;
    if (stage_v_182 > 55) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_109 + pub_r001016_14 * 2 + 554) & 127;
    if (stage_v_183 > 22) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (helper_flow_6 + pub_r001016_13 * 2 + 557) & 127;
    if (stage_v_184 > 35) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_26 + pub_r001016_5 * 2 + 560) & 127;
    if (stage_v_185 > 47) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_185 + pub_r001016_3 * 2 + 563) & 127;
    if (stage_v_186 > 58) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_51 + pub_r001016_3 * 2 + 566) & 127;
    if (stage_v_187 > 43) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (helper_flow_8 + pub_r001016_9 * 2 + 569) & 127;
    if (stage_v_188 > 20) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_47 + pub_r001016_7 * 2 + 572) & 127;
    if (stage_v_189 > 44) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001016_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_19 + pub_r001016_2 * 2 + 578) & 127;
    if (stage_v_191 > 52) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001016_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001016_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_182 + pub_r001016_12 * 2 + 587) & 127;
    if (stage_v_194 > 22) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001016_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r001016_5 + pub_r001016_5 * 2 + 593) & 127;
    if (stage_v_196 > 15) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001016_1 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_154 + pub_r001016_6 * 2 + 599) & 127;
    if (stage_v_198 > 53) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_47 + pub_r001016_8 * 2 + 602) & 127;
    if (stage_v_199 > 42) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (helper_flow_6 + pub_r001016_2 * 2 + 605) & 127;
    if (stage_v_200 > 35) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001016_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001016_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001016_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001016_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_70 + pub_r001016_11 * 2 + 620) & 127;
    if (stage_v_205 > 51) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_132 + pub_r001016_15 * 2 + 623) & 127;
    if (stage_v_206 > 56) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001016_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_159 + pub_r001016_11 * 2 + 629) & 127;
    if (stage_v_208 > 48) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001016_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_19 + pub_r001016_3 * 2 + 635) & 127;
    if (stage_v_210 > 51) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_114 + pub_r001016_4 * 2 + 638) & 127;
    if (stage_v_211 > 58) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001016_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001016_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r001016_0 + pub_r001016_0 * 2 + 647) & 127;
    if (stage_v_214 > 41) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_135 + pub_r001016_13 * 2 + 650) & 127;
    if (stage_v_215 > 49) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_30 + pub_r001016_13 * 2 + 653) & 127;
    if (stage_v_216 > 19) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_27 + pub_r001016_14 * 2 + 656) & 127;
    if (stage_v_217 > 40) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (sec_r001016_16 + pub_r001016_12 * 2 + 659) & 127;
    if (stage_v_218 > 27) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_83 + pub_r001016_9 * 2 + 662) & 127;
    if (stage_v_219 > 40) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r001016_22 + pub_r001016_9 * 2 + 665) & 127;
    if (stage_v_220 > 55) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_30 + pub_r001016_6 * 2 + 668) & 127;
    if (stage_v_221 > 17) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (helper_flow_4 + pub_r001016_15 * 2 + 671) & 127;
    if (stage_v_222 > 57) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001016_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_36 + pub_r001016_8 * 2 + 677) & 127;
    if (stage_v_224 > 46) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_151 + pub_r001016_7 * 2 + 680) & 127;
    if (stage_v_225 > 45) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
