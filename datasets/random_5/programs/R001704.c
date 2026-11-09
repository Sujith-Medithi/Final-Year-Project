/*
 * Benchmark Program: R001704
 * Security Family: arithmetic_flow
 * Generator Seed: 670413
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001704_413_0 {
    int tail;
    int head;
    int watermark;
    unsigned char checksum;
    short state;
    short capacity;
    int buffer[3];
};

struct Vector3D_R001704_413_1 {
    int coord_y;
    int heading;
    int norm_sq;
    int pitch;
    int buffer[3];
};

struct SensorNode_R001704_413_2 {
    int threshold;
    unsigned char status;
    int calib;
    int offset;
    int buffer[3];
};

union PacketPayload_R001704_413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001704_413_0(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001704_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int anchor_93 = local_arr[aux % 3];
    acc = (acc + anchor_93 * 2) & 127;
    int accumulator_56 = (aux + st.buffer[1]) & 3;
    switch (accumulator_56) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_40) & 63;
    acc ^= aux;
    int stride_79 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_79 > 14) {
        acc = (acc + stride_79 * 2 + 5) & 127;
        aux ^= (stride_79 & 15);
    } else {
        acc = (acc - stride_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001704_413_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001704_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int quotient_97 = local_arr[aux % 3];
    acc = (acc + quotient_97 * 2) & 127;
    int threshold_21 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_21 = (threshold_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_21) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001704_413_2(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int index_reg_84 = local_arr[aux % 3];
    acc = (acc + index_reg_84 * 2) & 127;
    int phase_58 = (aux + st.buffer[1]) & 3;
    switch (phase_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_56) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001704_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_83 = (aux + st.buffer[1]) & 3;
    switch (pivot_83) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001704_413_4(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int parity_59 = local_arr[aux % 3];
    acc = (acc + parity_59 * 2) & 127;
    int tracker_24 = (aux + st.buffer[1]) & 3;
    switch (tracker_24) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001704_413_5(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_21 = (aux + st.buffer[1]) & 3;
    switch (index_reg_21) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_71 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_71 > 34) {
        acc = (acc + weight_71 * 2 + 5) & 127;
        aux ^= (weight_71 & 15);
    } else {
        acc = (acc - weight_71 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int checksum_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_15) & 63;
    acc ^= aux;
    int segment_35 = 0;
    for (int k = 0; k < 2; k++) {
        segment_35 = (segment_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_35) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001704_413_7(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_34 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_34 = (cursor_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_34) & 127;
    }
    int tally_15 = (aux + st.buffer[1]) & 3;
    switch (tally_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_82 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_82 > 45) {
        acc = (acc + factor_82 * 2 + 5) & 127;
        aux ^= (factor_82 & 15);
    } else {
        acc = (acc - factor_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_8(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int coefficient_23 = local_arr[aux % 3];
    acc = (acc + coefficient_23 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_93 = (aux + st.buffer[1]) & 3;
    switch (phase_93) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001704_413_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int phase_21 = 0;
    for (int k = 0; k < 2; k++) {
        phase_21 = (phase_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_21) & 127;
    }
    int pivot_35 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_35 > 28) {
        acc = (acc + pivot_35 * 2 + 5) & 127;
        aux ^= (pivot_35 & 15);
    } else {
        acc = (acc - pivot_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_10(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int scale_80 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_80 > 47) {
        acc = (acc + scale_80 * 2 + 5) & 127;
        aux ^= (scale_80 & 15);
    } else {
        acc = (acc - scale_80 + 11) & 127;
        aux += 3;
    }
    int accumulator_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_66) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001704_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_16 = (aux + st.buffer[1]) & 3;
    switch (quotient_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001704_413_12(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int phase_39 = local_arr[aux % 3];
    acc = (acc + phase_39 * 2) & 127;
    int cursor_19 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_19 > 46) {
        acc = (acc + cursor_19 * 2 + 5) & 127;
        aux ^= (cursor_19 & 15);
    } else {
        acc = (acc - cursor_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001704_413_13(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int mask_84 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_84 > 36) {
        acc = (acc + mask_84 * 2 + 5) & 127;
        aux ^= (mask_84 & 15);
    } else {
        acc = (acc - mask_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_50 = local_arr[aux % 3];
    acc = (acc + bound_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_14(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_74 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_74 > 34) {
        acc = (acc + threshold_74 * 2 + 5) & 127;
        aux ^= (threshold_74 & 15);
    } else {
        acc = (acc - threshold_74 + 11) & 127;
        aux += 3;
    }
    int stride_68 = 0;
    for (int k = 0; k < 2; k++) {
        stride_68 = (stride_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_68) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_35 = local_arr[aux % 3];
    acc = (acc + segment_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_15(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_29) & 63;
    acc ^= aux;
    int coefficient_90 = (aux + st.buffer[1]) & 3;
    switch (coefficient_90) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_68 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_68 > 15) {
        acc = (acc + quantum_68 * 2 + 5) & 127;
        aux ^= (quantum_68 & 15);
    } else {
        acc = (acc - quantum_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_42 = 0;
    for (int k = 0; k < 2; k++) {
        weight_42 = (weight_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_42) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_62 = local_arr[aux % 3];
    acc = (acc + vector_62 * 2) & 127;
    int pivot_14 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_14 > 11) {
        acc = (acc + pivot_14 * 2 + 5) & 127;
        aux ^= (pivot_14 & 15);
    } else {
        acc = (acc - pivot_14 + 11) & 127;
        aux += 3;
    }
    int anchor_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001704_413_17(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_39 = (aux + st.buffer[1]) & 3;
    switch (quotient_39) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001704_413_18(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001704_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int threshold_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_40) & 63;
    acc ^= aux;
    int vector_47 = (aux + st.buffer[1]) & 3;
    switch (vector_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_40 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_40 = (accumulator_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_40) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001704_413_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001704_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int parity_97 = 0;
    for (int k = 0; k < 2; k++) {
        parity_97 = (parity_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001704_0;
    int sec_r001704_1;
    int sec_r001704_2;
    int sec_r001704_3;
    int sec_r001704_4;
    int sec_r001704_5;
    int sec_r001704_6;
    int sec_r001704_7;
    int sec_r001704_8;
    int sec_r001704_9;
    int sec_r001704_10;
    int sec_r001704_11;
    int sec_r001704_12;
    int sec_r001704_13;
    int sec_r001704_14;
    int sec_r001704_15;
    int sec_r001704_16;
    int sec_r001704_17;
    int sec_r001704_18;
    int pub_r001704_0;
    int pub_r001704_1;
    int pub_r001704_2;
    int pub_r001704_3;
    int pub_r001704_4;
    int pub_r001704_5;
    int pub_r001704_6;
    int pub_r001704_7;
    int pub_r001704_8;
    int pub_r001704_9;
    int pub_r001704_10;
    int pub_r001704_11;
    int pub_r001704_12;
    int pub_r001704_13;
    int pub_r001704_14;
    int pub_r001704_15;
    int pub_r001704_16;
    int pub_r001704_17;
    int pub_r001704_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001704_0 >= -100 && pub_r001704_0 <= 100);
    __CPROVER_assume(pub_r001704_1 >= -100 && pub_r001704_1 <= 100);
    __CPROVER_assume(pub_r001704_2 >= -100 && pub_r001704_2 <= 100);
    __CPROVER_assume(pub_r001704_3 >= -100 && pub_r001704_3 <= 100);
    __CPROVER_assume(pub_r001704_4 >= -100 && pub_r001704_4 <= 100);
    __CPROVER_assume(pub_r001704_5 >= -100 && pub_r001704_5 <= 100);
    __CPROVER_assume(pub_r001704_6 >= -100 && pub_r001704_6 <= 100);
    __CPROVER_assume(pub_r001704_7 >= -100 && pub_r001704_7 <= 100);
    __CPROVER_assume(pub_r001704_8 >= -100 && pub_r001704_8 <= 100);
    __CPROVER_assume(pub_r001704_9 >= -100 && pub_r001704_9 <= 100);
    __CPROVER_assume(pub_r001704_10 >= -100 && pub_r001704_10 <= 100);
    __CPROVER_assume(pub_r001704_11 >= -100 && pub_r001704_11 <= 100);
    __CPROVER_assume(pub_r001704_12 >= -100 && pub_r001704_12 <= 100);
    __CPROVER_assume(pub_r001704_13 >= -100 && pub_r001704_13 <= 100);
    __CPROVER_assume(pub_r001704_14 >= -100 && pub_r001704_14 <= 100);
    __CPROVER_assume(pub_r001704_15 >= -100 && pub_r001704_15 <= 100);
    __CPROVER_assume(pub_r001704_16 >= -100 && pub_r001704_16 <= 100);
    __CPROVER_assume(pub_r001704_17 >= -100 && pub_r001704_17 <= 100);
    __CPROVER_assume(pub_r001704_18 >= -100 && pub_r001704_18 <= 100);
    __CPROVER_assume(sec_r001704_0 >= 0 && sec_r001704_0 <= 255);
    __CPROVER_assume(sec_r001704_1 >= 0 && sec_r001704_1 <= 255);
    __CPROVER_assume(sec_r001704_2 >= 0 && sec_r001704_2 <= 255);
    __CPROVER_assume(sec_r001704_3 >= 0 && sec_r001704_3 <= 255);
    __CPROVER_assume(sec_r001704_4 >= 0 && sec_r001704_4 <= 255);
    __CPROVER_assume(sec_r001704_5 >= 0 && sec_r001704_5 <= 255);
    __CPROVER_assume(sec_r001704_6 >= 0 && sec_r001704_6 <= 255);
    __CPROVER_assume(sec_r001704_7 >= 0 && sec_r001704_7 <= 255);
    __CPROVER_assume(sec_r001704_8 >= 0 && sec_r001704_8 <= 255);
    __CPROVER_assume(sec_r001704_9 >= 0 && sec_r001704_9 <= 255);
    __CPROVER_assume(sec_r001704_10 >= 0 && sec_r001704_10 <= 255);
    __CPROVER_assume(sec_r001704_11 >= 0 && sec_r001704_11 <= 255);
    __CPROVER_assume(sec_r001704_12 >= 0 && sec_r001704_12 <= 255);
    __CPROVER_assume(sec_r001704_13 >= 0 && sec_r001704_13 <= 255);
    __CPROVER_assume(sec_r001704_14 >= 0 && sec_r001704_14 <= 255);
    __CPROVER_assume(sec_r001704_15 >= 0 && sec_r001704_15 <= 255);
    __CPROVER_assume(sec_r001704_16 >= 0 && sec_r001704_16 <= 255);
    __CPROVER_assume(sec_r001704_17 >= 0 && sec_r001704_17 <= 255);
    __CPROVER_assume(sec_r001704_18 >= 0 && sec_r001704_18 <= 255);

    struct StreamBuffer_R001704_413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001704_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001704_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001704_0 + 7) & 15;
    struct Vector3D_R001704_413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001704_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001704_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001704_0 + 9) & 15;
    struct SensorNode_R001704_413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001704_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001704_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001704_0 + 11) & 15;

    union PacketPayload_R001704_413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001704_413_0(sec_r001704_0, pub_r001704_1);
    int helper_flow_1 = fn_R001704_413_1(sec_r001704_1, sec_r001704_2, pub_r001704_3, pub_r001704_4);
    int helper_flow_2 = fn_R001704_413_2(sec_r001704_2, sec_r001704_3);
    int helper_flow_3 = fn_R001704_413_3(sec_r001704_3, pub_r001704_4, pub_r001704_5, pub_r001704_6);
    int helper_flow_4 = fn_R001704_413_4(sec_r001704_4, sec_r001704_5, pub_r001704_6);
    int helper_flow_5 = fn_R001704_413_5(sec_r001704_5, pub_r001704_6, pub_r001704_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001704_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001704_2 * 3) + pub_r001704_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001704_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001704_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_4 * 3) + pub_r001704_15 + 32) & 127;
    sec_accum = (sec_accum + stage_v_4) & 255;
    out_sink = (out_sink + stage_v_4 * 2) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001704_1 * 3) + pub_r001704_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001704_3 * 3) + pub_r001704_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_6) & 255;
    out_sink = (out_sink + stage_v_6 * 2) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001704_8 * 3) + pub_r001704_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001704_18 * 3) + pub_r001704_15 + 16) & 127;
    sec_accum = (sec_accum + stage_v_8) & 255;
    out_sink = (out_sink + stage_v_8 * 2) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001704_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_1 * 3) + pub_r001704_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001704_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001704_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001704_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_4 * 3) + pub_r001704_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_14) & 255;
    out_sink = (out_sink + stage_v_14 * 2) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001704_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001704_10 * 3) + pub_r001704_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001704_17 * 3) + pub_r001704_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_3 * 3) + pub_r001704_15 + 44) & 127;
    sec_accum = (sec_accum + stage_v_18) & 255;
    out_sink = (out_sink + stage_v_18 * 2) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_2 * 3) + pub_r001704_15 + 28) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001704_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001704_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001704_2 * 3) + pub_r001704_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_22) & 255;
    out_sink = (out_sink + stage_v_22 * 2) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001704_17 * 3) + pub_r001704_11 + 10) & 127;
    sec_accum = (sec_accum + stage_v_23) & 255;
    out_sink = (out_sink + stage_v_23 * 2) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001704_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_10 * 3) + pub_r001704_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_25) & 255;
    out_sink = (out_sink + stage_v_25 * 2) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001704_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001704_12 * 3) + pub_r001704_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_27) & 255;
    out_sink = (out_sink + stage_v_27 * 2) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_22 * 3) + pub_r001704_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_28) & 255;
    out_sink = (out_sink + stage_v_28 * 2) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001704_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001704_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001704_4 * 3) + pub_r001704_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_31) & 255;
    out_sink = (out_sink + stage_v_31 * 2) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001704_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_5 * 3) + pub_r001704_17 + 40) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001704_15 * 3) + pub_r001704_15 + 10) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_33 * 3) + pub_r001704_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_8 * 3) + pub_r001704_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_36) & 255;
    out_sink = (out_sink + stage_v_36 * 2) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_16 * 3) + pub_r001704_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_37) & 255;
    out_sink = (out_sink + stage_v_37 * 2) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001704_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001704_18 * 3) + pub_r001704_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001704_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001704_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001704_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_18 * 3) + pub_r001704_11 + 26) & 127;
    sec_accum = (sec_accum + stage_v_43) & 255;
    out_sink = (out_sink + stage_v_43 * 2) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001704_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001704_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001704_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001704_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_27 * 3) + pub_r001704_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48 * 2) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001704_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_48 * 3) + pub_r001704_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50 * 2) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_1 * 3) + pub_r001704_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51 * 2) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001704_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_25 * 3) + pub_r001704_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53 * 2) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001704_4 * 3) + pub_r001704_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_4 * 3) + pub_r001704_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55 * 2) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001704_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001704_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_25 * 3) + pub_r001704_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001704_1 * 3) + pub_r001704_18 + 19) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59 * 2) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001704_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001704_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001704_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001704_17 * 3) + pub_r001704_18 + 27) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63 * 2) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001704_11 * 3) + pub_r001704_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001704_11 * 3) + pub_r001704_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001704_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_58 * 3) + pub_r001704_18 + 40) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67 * 2) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001704_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001704_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001704_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_64 * 3) + pub_r001704_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71 * 2) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001704_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001704_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_48 * 3) + pub_r001704_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74 * 2) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001704_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_7 * 3) + pub_r001704_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76 * 2) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001704_6 * 3) + pub_r001704_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77 * 2) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_63 * 3) + pub_r001704_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78 * 2) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001704_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001704_9 * 3) + pub_r001704_11 + 32) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80 * 2) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001704_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001704_11 * 3) + pub_r001704_17 + 10) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82 * 2) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001704_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001704_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001704_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001704_8 * 3) + pub_r001704_3 + 8) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86 * 2) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001704_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_63 * 3) + pub_r001704_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001704_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001704_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001704_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_88 * 3) + pub_r001704_8 + 3) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92 * 2) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001704_10 * 3) + pub_r001704_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001704_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001704_7 * 3) + pub_r001704_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95 * 2) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_63 * 3) + pub_r001704_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96 * 2) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001704_8 * 3) + pub_r001704_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_33 * 3) + pub_r001704_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98 * 2) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001704_5 * 3) + pub_r001704_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_10 * 3) + pub_r001704_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100 * 2) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001704_18 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_95 * 3) + pub_r001704_4 + 15) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102 * 2) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_36 * 3) + pub_r001704_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103 * 2) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_65 * 3) + pub_r001704_4 + 35) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001704_12 * 3) + pub_r001704_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105 * 2) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001704_11 * 3) + pub_r001704_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_28 * 3) + pub_r001704_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107 * 2) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_71 * 3) + pub_r001704_10 + 22) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001704_9 * 3) + pub_r001704_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109 * 2) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_99 * 3) + pub_r001704_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110 * 2) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_67 * 3) + pub_r001704_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001704_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_37 * 3) + pub_r001704_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113 * 2) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001704_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_103 * 3) + pub_r001704_4 + 12) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115 * 2) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001704_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001704_4 * 3) + pub_r001704_9 + 20) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117 * 2) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001704_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001704_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_117 * 3) + pub_r001704_0 + 13) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_53 * 3) + pub_r001704_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_28 * 3) + pub_r001704_13 + 12) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_88 * 3) + pub_r001704_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123 * 2) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_22 * 3) + pub_r001704_2 + 41) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_103 * 3) + pub_r001704_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001704_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001704_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_16 * 3) + pub_r001704_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_50 * 3) + pub_r001704_18 + 41) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_115 * 3) + pub_r001704_17 + 8) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130 * 2) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r001704_2 * 3) + pub_r001704_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131 * 2) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_105 * 3) + pub_r001704_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132 * 2) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_25 * 3) + pub_r001704_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_7 * 3) + pub_r001704_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_121 * 3) + pub_r001704_0 + 37) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_111 * 3) + pub_r001704_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001704_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_33 * 3) + pub_r001704_17 + 8) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138 * 2) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001704_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001704_1 * 3) + pub_r001704_3 + 7) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001704_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001704_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001704_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_82 * 3) + pub_r001704_13 + 39) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144 * 2) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001704_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_53 * 3) + pub_r001704_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146 * 2) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_63 * 3) + pub_r001704_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_64 * 3) + pub_r001704_6 + 18) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148 * 2) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001704_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001704_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001704_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_123 * 3) + pub_r001704_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152 * 2) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001704_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_63 * 3) + pub_r001704_15 + 21) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154 * 2) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_134 * 3) + pub_r001704_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155 * 2) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_53 * 3) + pub_r001704_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156 * 2) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001704_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001704_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001704_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_33 * 3) + pub_r001704_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001704_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001704_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r001704_7 * 3) + pub_r001704_18 + 32) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001704_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r001704_6 * 3) + pub_r001704_10 + 24) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_131 * 3) + pub_r001704_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_115 * 3) + pub_r001704_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167 * 2) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_63 * 3) + pub_r001704_10 + 14) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168 * 2) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_108 * 3) + pub_r001704_0 + 43) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169 * 2) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001704_11 * 3) + pub_r001704_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170 * 2) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_108 * 3) + pub_r001704_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_80 * 3) + pub_r001704_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001704_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_123 * 3) + pub_r001704_9 + 41) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_7 * 3) + pub_r001704_5 + 13) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175 * 2) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001704_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001704_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001704_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001704_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_152 * 3) + pub_r001704_6 + 31) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180 * 2) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001704_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_23 * 3) + pub_r001704_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_14 * 3) + pub_r001704_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001704_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_28 * 3) + pub_r001704_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001704_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001704_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_8 * 3) + pub_r001704_18 + 26) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188 * 2) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001704_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_122 * 3) + pub_r001704_9 + 42) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190 * 2) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001704_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r001704_12 * 3) + pub_r001704_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192 * 2) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001704_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001704_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_125 * 3) + pub_r001704_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_37 * 3) + pub_r001704_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196 * 2) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001704_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_196 * 3) + pub_r001704_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198 * 2) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001704_2 * 3) + pub_r001704_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199 * 2) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001704_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001704_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001704_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001704_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_35 * 3) + pub_r001704_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_36 * 3) + pub_r001704_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001704_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r001704_4 * 3) + pub_r001704_11 + 22) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207 * 2) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_65 * 3) + pub_r001704_8 + 14) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208 * 2) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001704_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_4 * 3) + pub_r001704_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210 * 2) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001704_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001704_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001704_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_156 * 3) + pub_r001704_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214 * 2) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001704_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r001704_3 * 3) + pub_r001704_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216 * 2) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_152 * 3) + pub_r001704_3 + 41) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217 * 2) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_93 * 3) + pub_r001704_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((helper_flow_0 * 3) + pub_r001704_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219 * 2) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001704_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001704_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001704_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_17 * 3) + pub_r001704_11 + 26) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_210 * 3) + pub_r001704_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001704_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_25 * 3) + pub_r001704_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_97 * 3) + pub_r001704_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001704_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001704_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_154 * 3) + pub_r001704_8 + 45) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001704_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_130 * 3) + pub_r001704_4 + 42) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232 * 2) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001704_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001704_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001704_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_185 * 3) + pub_r001704_2 + 21) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_124 * 3) + pub_r001704_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001704_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((sec_r001704_13 * 3) + pub_r001704_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239 * 2) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001704_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001704_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001704_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001704_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_227 * 3) + pub_r001704_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001704_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001704_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_80 * 3) + pub_r001704_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247 * 2) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_106 * 3) + pub_r001704_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248 * 2) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_192 * 3) + pub_r001704_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249 * 2) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_37 * 3) + pub_r001704_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250 * 2) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_55 * 3) + pub_r001704_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_227 * 3) + pub_r001704_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252 * 2) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_35 * 3) + pub_r001704_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253 * 2) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_50 * 3) + pub_r001704_10 + 38) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_204 * 3) + pub_r001704_10 + 35) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255 * 2) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_48 * 3) + pub_r001704_17 + 37) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256 * 2) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001704_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001704_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001704_7 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001704_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001704_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_180 * 3) + pub_r001704_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_188 * 3) + pub_r001704_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263 * 2) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001704_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001704_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001704_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001704_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001704_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001704_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_168 * 3) + pub_r001704_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001704_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_115 * 3) + pub_r001704_16 + 28) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272 * 2) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((sec_r001704_13 * 3) + pub_r001704_5 + 22) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_244 * 3) + pub_r001704_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((helper_flow_0 * 3) + pub_r001704_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275 * 2) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_74 * 3) + pub_r001704_16 + 33) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276 * 2) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_227 * 3) + pub_r001704_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_8 * 3) + pub_r001704_9 + 26) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001704_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_97 * 3) + pub_r001704_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280 * 2) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_88 * 3) + pub_r001704_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281 * 2) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_196 * 3) + pub_r001704_4 + 40) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_99 * 3) + pub_r001704_4 + 41) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283 * 2) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_33 * 3) + pub_r001704_1 + 40) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284 * 2) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_196 * 3) + pub_r001704_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_78 * 3) + pub_r001704_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001704_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001704_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001704_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001704_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_218 * 3) + pub_r001704_7 + 41) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001704_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_249 * 3) + pub_r001704_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293 * 2) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_120 * 3) + pub_r001704_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294 * 2) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_134 * 3) + pub_r001704_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295 * 2) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001704_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001704_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001704_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001704_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_167 * 3) + pub_r001704_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300 * 2) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001704_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_50 * 3) + pub_r001704_12 + 35) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302 * 2) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_182 * 3) + pub_r001704_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303 * 2) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_121 * 3) + pub_r001704_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_281 * 3) + pub_r001704_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_1 * 3) + pub_r001704_1 + 12) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306 * 2) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_129 * 3) + pub_r001704_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307 * 2) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_51 * 3) + pub_r001704_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308 * 2) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001704_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_53 * 3) + pub_r001704_15 + 26) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310 * 2) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001704_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_6 * 3) + pub_r001704_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001704_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001704_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001704_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_172 * 3) + pub_r001704_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316 * 2) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001704_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001704_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((sec_r001704_2 * 3) + pub_r001704_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319 * 2) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_16 * 3) + pub_r001704_4 + 44) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_304 * 3) + pub_r001704_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321 * 2) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001704_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_96 * 3) + pub_r001704_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323 * 2) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_33 * 3) + pub_r001704_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001704_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_196 * 3) + pub_r001704_14 + 38) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_198 * 3) + pub_r001704_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327 * 2) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((sec_r001704_14 * 3) + pub_r001704_14 + 42) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328 * 2) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001704_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_291 * 3) + pub_r001704_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330 * 2) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_33 * 3) + pub_r001704_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001704_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_330 * 3) + pub_r001704_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001704_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_270 * 3) + pub_r001704_6 + 29) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335 * 2) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001704_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_327 * 3) + pub_r001704_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337 * 2) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_170 * 3) + pub_r001704_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338 * 2) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001704_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_273 * 3) + pub_r001704_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340 * 2) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((sec_r001704_7 * 3) + pub_r001704_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001704_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_263 * 3) + pub_r001704_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001704_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_247 * 3) + pub_r001704_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((sec_r001704_15 * 3) + pub_r001704_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((sec_r001704_16 * 3) + pub_r001704_13 + 30) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001704_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001704_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001704_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001704_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_140 * 3) + pub_r001704_2 + 7) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352 * 2) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001704_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001704_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001704_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_4 * 3) + pub_r001704_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001704_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_19 * 3) + pub_r001704_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001704_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_163 * 3) + pub_r001704_16 + 23) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001704_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001704_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_232 * 3) + pub_r001704_8 + 18) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363 * 2) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_51 * 3) + pub_r001704_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364 * 2) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_53 * 3) + pub_r001704_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_365) & 255;
    out_sink = (out_sink + stage_v_365 * 2) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((sec_r001704_16 * 3) + pub_r001704_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_366) & 255;
    out_sink = (out_sink + stage_v_366 * 2) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((sec_r001704_13 * 3) + pub_r001704_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_367) & 255;
    out_sink = (out_sink + stage_v_367 * 2) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_134 * 3) + pub_r001704_1 + 34) & 127;
    sec_accum = (sec_accum + stage_v_368) & 255;
    out_sink = (out_sink + stage_v_368 * 2) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001704_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_180 * 3) + pub_r001704_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((sec_r001704_0 * 3) + pub_r001704_12 + 22) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001704_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_182 * 3) + pub_r001704_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001704_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001704_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_363 * 3) + pub_r001704_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376 * 2) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001704_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001704_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_103 * 3) + pub_r001704_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001704_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_236 * 3) + pub_r001704_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001704_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_308 * 3) + pub_r001704_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((helper_flow_5 * 3) + pub_r001704_0 + 6) & 127;
    sec_accum = (sec_accum + stage_v_384) & 255;
    out_sink = (out_sink + stage_v_384 * 2) & 255;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001704_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001704_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_77 * 3) + pub_r001704_2 + 8) & 127;
    sec_accum = (sec_accum + stage_v_387) & 255;
    out_sink = (out_sink + stage_v_387 * 2) & 255;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_1 * 3) + pub_r001704_3 + 44) & 127;
    sec_accum = (sec_accum + stage_v_388) & 255;
    out_sink = (out_sink + stage_v_388 * 2) & 255;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001704_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001704_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_10 * 3) + pub_r001704_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_391) & 255;
    out_sink = (out_sink + stage_v_391 * 2) & 255;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_155 * 3) + pub_r001704_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_392) & 255;
    out_sink = (out_sink + stage_v_392 * 2) & 255;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001704_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001704_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001704_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_97 * 3) + pub_r001704_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_396) & 255;
    out_sink = (out_sink + stage_v_396 * 2) & 255;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_210 * 3) + pub_r001704_17 + 41) & 127;
    sec_accum = (sec_accum + stage_v_397) & 255;
    out_sink = (out_sink + stage_v_397 * 2) & 255;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001704_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001704_6 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_190 * 3) + pub_r001704_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_400) & 255;
    out_sink = (out_sink + stage_v_400 * 2) & 255;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_284 * 3) + pub_r001704_4 + 40) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_5 * 3) + pub_r001704_17 + 22) & 127;
    sec_accum = (sec_accum + stage_v_402) & 255;
    out_sink = (out_sink + stage_v_402 * 2) & 255;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_97 * 3) + pub_r001704_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_25 * 3) + pub_r001704_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001704_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001704_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001704_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_291 * 3) + pub_r001704_17 + 23) & 127;
    sec_accum = (sec_accum + stage_v_408) & 255;
    out_sink = (out_sink + stage_v_408 * 2) & 255;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_152 * 3) + pub_r001704_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_409) & 255;
    out_sink = (out_sink + stage_v_409 * 2) & 255;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_152 * 3) + pub_r001704_7 + 42) & 127;
    sec_accum = (sec_accum + stage_v_410) & 255;
    out_sink = (out_sink + stage_v_410 * 2) & 255;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_140 * 3) + pub_r001704_9 + 18) & 127;
    sec_accum = (sec_accum + stage_v_411) & 255;
    out_sink = (out_sink + stage_v_411 * 2) & 255;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001704_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001704_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001704_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_92 * 3) + pub_r001704_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_415) & 255;
    out_sink = (out_sink + stage_v_415 * 2) & 255;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_294 * 3) + pub_r001704_13 + 36) & 127;
    sec_accum = (sec_accum + stage_v_416) & 255;
    out_sink = (out_sink + stage_v_416 * 2) & 255;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001704_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_185 * 3) + pub_r001704_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_418) & 255;
    out_sink = (out_sink + stage_v_418 * 2) & 255;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_185 * 3) + pub_r001704_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_419) & 255;
    out_sink = (out_sink + stage_v_419 * 2) & 255;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_117 * 3) + pub_r001704_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_420) & 255;
    out_sink = (out_sink + stage_v_420 * 2) & 255;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001704_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001704_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001704_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((sec_r001704_10 * 3) + pub_r001704_7 + 39) & 127;
    sec_accum = (sec_accum + stage_v_424) & 255;
    out_sink = (out_sink + stage_v_424 * 2) & 255;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_130 * 3) + pub_r001704_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001704_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_256 * 3) + pub_r001704_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_163 * 3) + pub_r001704_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_428) & 255;
    out_sink = (out_sink + stage_v_428 * 2) & 255;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_28 * 3) + pub_r001704_18 + 17) & 127;
    sec_accum = (sec_accum + stage_v_429) & 255;
    out_sink = (out_sink + stage_v_429 * 2) & 255;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001704_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001704_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_392 * 3) + pub_r001704_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_432) & 255;
    out_sink = (out_sink + stage_v_432 * 2) & 255;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001704_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001704_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001704_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001704_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001704_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001704_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_263 * 3) + pub_r001704_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_397 * 3) + pub_r001704_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001704_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((sec_r001704_7 * 3) + pub_r001704_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001704_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_188 * 3) + pub_r001704_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_444) & 255;
    out_sink = (out_sink + stage_v_444 * 2) & 255;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_293 * 3) + pub_r001704_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_445) & 255;
    out_sink = (out_sink + stage_v_445 * 2) & 255;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_107 * 3) + pub_r001704_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_59 * 3) + pub_r001704_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_447) & 255;
    out_sink = (out_sink + stage_v_447 * 2) & 255;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_282 * 3) + pub_r001704_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_448) & 255;
    out_sink = (out_sink + stage_v_448 * 2) & 255;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001704_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001704_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_8 * 3) + pub_r001704_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_43 * 3) + pub_r001704_4 + 10) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_323 * 3) + pub_r001704_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_453) & 255;
    out_sink = (out_sink + stage_v_453 * 2) & 255;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001704_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_367 * 3) + pub_r001704_16 + 36) & 127;
    sec_accum = (sec_accum + stage_v_455) & 255;
    out_sink = (out_sink + stage_v_455 * 2) & 255;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_282 * 3) + pub_r001704_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_34 * 3) + pub_r001704_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_457) & 255;
    out_sink = (out_sink + stage_v_457 * 2) & 255;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001704_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
