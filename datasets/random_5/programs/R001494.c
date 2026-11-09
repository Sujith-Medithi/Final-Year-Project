/*
 * Benchmark Program: R001494
 * Security Family: arithmetic_flow
 * Generator Seed: 649413
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001494_9413_0 {
    unsigned char coord_x;
    int pitch;
    unsigned char coord_y;
    unsigned char coord_z;
    int heading;
    int buffer[3];
};

struct SensorNode_R001494_9413_1 {
    int threshold;
    short status;
    unsigned char offset;
    short reading;
    int calib;
    int gain;
    int buffer[3];
};

struct EventLog_R001494_9413_2 {
    short signature;
    int facility;
    short timestamp;
    int buffer[3];
};

union TelemetryField_R001494_9413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001494_9413_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001494_9413_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int anchor_79 = local_arr[aux % 3];
    acc = (acc + anchor_79 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_48 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_48 > 40) {
        acc = (acc + index_reg_48 * 2 + 5) & 127;
        aux ^= (index_reg_48 & 15);
    } else {
        acc = (acc - index_reg_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_1(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int mask_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_14) & 63;
    acc ^= aux;
    int tally_99 = (aux + st.buffer[1]) & 3;
    switch (tally_99) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_33 = local_arr[aux % 3];
    acc = (acc + offset_33 * 2) & 127;
    int stride_63 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_63 > 37) {
        acc = (acc + stride_63 * 2 + 5) & 127;
        aux ^= (stride_63 & 15);
    } else {
        acc = (acc - stride_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_62 = local_arr[aux % 3];
    acc = (acc + checksum_62 * 2) & 127;
    int stride_66 = 0;
    for (int k = 0; k < 2; k++) {
        stride_66 = (stride_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_66) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_3(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_50) & 63;
    acc ^= aux;
    int sample_33 = 0;
    for (int k = 0; k < 3; k++) {
        sample_33 = (sample_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_33) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_22 = local_arr[aux % 3];
    acc = (acc + scale_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001494_9413_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001494_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_83 = local_arr[aux % 3];
    acc = (acc + residue_83 * 2) & 127;
    int quotient_85 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_85 = (quotient_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_5(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_55 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_55 > 14) {
        acc = (acc + bound_55 * 2 + 5) & 127;
        aux ^= (bound_55 & 15);
    } else {
        acc = (acc - bound_55 + 11) & 127;
        aux += 3;
    }
    int coefficient_18 = (aux + st.buffer[1]) & 3;
    switch (coefficient_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_20 = local_arr[aux % 3];
    acc = (acc + index_reg_20 * 2) & 127;
    int tracker_50 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_50 = (tracker_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_6(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001494_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int stride_93 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_93 > 41) {
        acc = (acc + stride_93 * 2 + 5) & 127;
        aux ^= (stride_93 & 15);
    } else {
        acc = (acc - stride_93 + 11) & 127;
        aux += 3;
    }
    int scale_54 = (aux + st.buffer[1]) & 3;
    switch (scale_54) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_7(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int bound_21 = local_arr[aux % 3];
    acc = (acc + bound_21 * 2) & 127;
    int stride_44 = (aux + st.buffer[1]) & 3;
    switch (stride_44) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_38 = 0;
    for (int k = 0; k < 2; k++) {
        tally_38 = (tally_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_38) & 127;
    }
    int accumulator_17 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_17 > 13) {
        acc = (acc + accumulator_17 * 2 + 5) & 127;
        aux ^= (accumulator_17 & 15);
    } else {
        acc = (acc - accumulator_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_12 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_12 > 24) {
        acc = (acc + accumulator_12 * 2 + 5) & 127;
        aux ^= (accumulator_12 & 15);
    } else {
        acc = (acc - accumulator_12 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_57 = (aux + st.buffer[1]) & 3;
    switch (offset_57) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_82 = 0;
    for (int k = 0; k < 2; k++) {
        delta_82 = (delta_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_62 = 0;
    for (int k = 0; k < 2; k++) {
        vector_62 = (vector_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_62) & 127;
    }
    int cursor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_56) & 63;
    acc ^= aux;
    int phase_95 = (aux + st.buffer[1]) & 3;
    switch (phase_95) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_10(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001494_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int pivot_19 = local_arr[aux % 3];
    acc = (acc + pivot_19 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001494_9413_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_84 = (aux + st.buffer[1]) & 3;
    switch (quantum_84) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_78 = (st.buffer[0] * 3 + aux) & 63;
    if (window_78 > 30) {
        acc = (acc + window_78 * 2 + 5) & 127;
        aux ^= (window_78 & 15);
    } else {
        acc = (acc - window_78 + 11) & 127;
        aux += 3;
    }
    int delta_44 = 0;
    for (int k = 0; k < 2; k++) {
        delta_44 = (delta_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_44) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_12(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_50 = (aux + st.buffer[1]) & 3;
    switch (accumulator_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001494_9413_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tracker_13 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_13 > 11) {
        acc = (acc + tracker_13 * 2 + 5) & 127;
        aux ^= (tracker_13 & 15);
    } else {
        acc = (acc - tracker_13 + 11) & 127;
        aux += 3;
    }
    int sample_76 = 0;
    for (int k = 0; k < 3; k++) {
        sample_76 = (sample_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_14(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int residue_23 = local_arr[aux % 3];
    acc = (acc + residue_23 * 2) & 127;
    int mask_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001494_9413_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001494_9413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int phase_39 = local_arr[aux % 3];
    acc = (acc + phase_39 * 2) & 127;
    int quantum_24 = (aux + st.buffer[1]) & 3;
    switch (quantum_24) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_16(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_86 = (aux + st.buffer[1]) & 3;
    switch (cursor_86) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_40 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_40 = (anchor_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_40) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_27 = local_arr[aux % 3];
    acc = (acc + sample_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001494_9413_17(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001494_9413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int scale_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_42) & 63;
    acc ^= aux;
    int vector_93 = 0;
    for (int k = 0; k < 2; k++) {
        vector_93 = (vector_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_93) & 127;
    }
    int vector_20 = (aux + st.buffer[1]) & 3;
    switch (vector_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001494_9413_18(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001494_9413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_65 = (aux + st.buffer[1]) & 3;
    switch (threshold_65) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_63) & 63;
    acc ^= aux;
    int delta_36 = 0;
    for (int k = 0; k < 2; k++) {
        delta_36 = (delta_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_36) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001494_0;
    int sec_r001494_1;
    int sec_r001494_2;
    int sec_r001494_3;
    int sec_r001494_4;
    int sec_r001494_5;
    int sec_r001494_6;
    int sec_r001494_7;
    int sec_r001494_8;
    int sec_r001494_9;
    int sec_r001494_10;
    int sec_r001494_11;
    int sec_r001494_12;
    int sec_r001494_13;
    int sec_r001494_14;
    int sec_r001494_15;
    int sec_r001494_16;
    int sec_r001494_17;
    int sec_r001494_18;
    int pub_r001494_0;
    int pub_r001494_1;
    int pub_r001494_2;
    int pub_r001494_3;
    int pub_r001494_4;
    int pub_r001494_5;
    int pub_r001494_6;
    int pub_r001494_7;
    int pub_r001494_8;
    int pub_r001494_9;
    int pub_r001494_10;
    int pub_r001494_11;
    int pub_r001494_12;
    int pub_r001494_13;
    int pub_r001494_14;
    int pub_r001494_15;
    int pub_r001494_16;
    int pub_r001494_17;
    int pub_r001494_18;
    int pub_r001494_19;
    int pub_r001494_20;
    int pub_r001494_21;
    int pub_r001494_22;
    int pub_r001494_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001494_0 >= -100 && pub_r001494_0 <= 100);
    __CPROVER_assume(pub_r001494_1 >= -100 && pub_r001494_1 <= 100);
    __CPROVER_assume(pub_r001494_2 >= -100 && pub_r001494_2 <= 100);
    __CPROVER_assume(pub_r001494_3 >= -100 && pub_r001494_3 <= 100);
    __CPROVER_assume(pub_r001494_4 >= -100 && pub_r001494_4 <= 100);
    __CPROVER_assume(pub_r001494_5 >= -100 && pub_r001494_5 <= 100);
    __CPROVER_assume(pub_r001494_6 >= -100 && pub_r001494_6 <= 100);
    __CPROVER_assume(pub_r001494_7 >= -100 && pub_r001494_7 <= 100);
    __CPROVER_assume(pub_r001494_8 >= -100 && pub_r001494_8 <= 100);
    __CPROVER_assume(pub_r001494_9 >= -100 && pub_r001494_9 <= 100);
    __CPROVER_assume(pub_r001494_10 >= -100 && pub_r001494_10 <= 100);
    __CPROVER_assume(pub_r001494_11 >= -100 && pub_r001494_11 <= 100);
    __CPROVER_assume(pub_r001494_12 >= -100 && pub_r001494_12 <= 100);
    __CPROVER_assume(pub_r001494_13 >= -100 && pub_r001494_13 <= 100);
    __CPROVER_assume(pub_r001494_14 >= -100 && pub_r001494_14 <= 100);
    __CPROVER_assume(pub_r001494_15 >= -100 && pub_r001494_15 <= 100);
    __CPROVER_assume(pub_r001494_16 >= -100 && pub_r001494_16 <= 100);
    __CPROVER_assume(pub_r001494_17 >= -100 && pub_r001494_17 <= 100);
    __CPROVER_assume(pub_r001494_18 >= -100 && pub_r001494_18 <= 100);
    __CPROVER_assume(pub_r001494_19 >= -100 && pub_r001494_19 <= 100);
    __CPROVER_assume(pub_r001494_20 >= -100 && pub_r001494_20 <= 100);
    __CPROVER_assume(pub_r001494_21 >= -100 && pub_r001494_21 <= 100);
    __CPROVER_assume(pub_r001494_22 >= -100 && pub_r001494_22 <= 100);
    __CPROVER_assume(pub_r001494_23 >= -100 && pub_r001494_23 <= 100);
    __CPROVER_assume(sec_r001494_0 >= 0 && sec_r001494_0 <= 255);
    __CPROVER_assume(sec_r001494_1 >= 0 && sec_r001494_1 <= 255);
    __CPROVER_assume(sec_r001494_2 >= 0 && sec_r001494_2 <= 255);
    __CPROVER_assume(sec_r001494_3 >= 0 && sec_r001494_3 <= 255);
    __CPROVER_assume(sec_r001494_4 >= 0 && sec_r001494_4 <= 255);
    __CPROVER_assume(sec_r001494_5 >= 0 && sec_r001494_5 <= 255);
    __CPROVER_assume(sec_r001494_6 >= 0 && sec_r001494_6 <= 255);
    __CPROVER_assume(sec_r001494_7 >= 0 && sec_r001494_7 <= 255);
    __CPROVER_assume(sec_r001494_8 >= 0 && sec_r001494_8 <= 255);
    __CPROVER_assume(sec_r001494_9 >= 0 && sec_r001494_9 <= 255);
    __CPROVER_assume(sec_r001494_10 >= 0 && sec_r001494_10 <= 255);
    __CPROVER_assume(sec_r001494_11 >= 0 && sec_r001494_11 <= 255);
    __CPROVER_assume(sec_r001494_12 >= 0 && sec_r001494_12 <= 255);
    __CPROVER_assume(sec_r001494_13 >= 0 && sec_r001494_13 <= 255);
    __CPROVER_assume(sec_r001494_14 >= 0 && sec_r001494_14 <= 255);
    __CPROVER_assume(sec_r001494_15 >= 0 && sec_r001494_15 <= 255);
    __CPROVER_assume(sec_r001494_16 >= 0 && sec_r001494_16 <= 255);
    __CPROVER_assume(sec_r001494_17 >= 0 && sec_r001494_17 <= 255);
    __CPROVER_assume(sec_r001494_18 >= 0 && sec_r001494_18 <= 255);

    struct Vector3D_R001494_9413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001494_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001494_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001494_0 + 7) & 15;
    struct SensorNode_R001494_9413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001494_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001494_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001494_0 + 9) & 15;
    struct EventLog_R001494_9413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001494_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001494_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001494_0 + 11) & 15;

    union TelemetryField_R001494_9413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001494_9413_0(sec_r001494_0, pub_r001494_1, pub_r001494_2, pub_r001494_3, pub_r001494_4);
    int helper_flow_1 = fn_R001494_9413_1(sec_r001494_1, sec_r001494_2);
    int helper_flow_2 = fn_R001494_9413_2(sec_r001494_2, pub_r001494_3, pub_r001494_4, pub_r001494_5);
    int helper_flow_3 = fn_R001494_9413_3(sec_r001494_3, pub_r001494_4);
    int helper_flow_4 = fn_R001494_9413_4(sec_r001494_4, pub_r001494_5, pub_r001494_6, pub_r001494_7, pub_r001494_8);
    int helper_flow_5 = fn_R001494_9413_5(sec_r001494_5, pub_r001494_6, pub_r001494_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001494_23 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_1 * 3) + pub_r001494_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_1) & 255;
    out_sink = (out_sink + stage_v_1 * 2) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001494_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001494_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001494_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001494_6 * 3) + pub_r001494_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_5) & 255;
    out_sink = (out_sink + stage_v_5 * 2) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001494_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001494_5 * 3) + pub_r001494_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_7) & 255;
    out_sink = (out_sink + stage_v_7 * 2) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001494_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001494_9 * 3) + pub_r001494_23 + 13) & 127;
    sec_accum = (sec_accum + stage_v_9) & 255;
    out_sink = (out_sink + stage_v_9 * 2) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001494_7 * 3) + pub_r001494_9 + 42) & 127;
    sec_accum = (sec_accum + stage_v_10) & 255;
    out_sink = (out_sink + stage_v_10 * 2) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001494_23 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001494_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001494_22 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001494_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001494_1 * 3) + pub_r001494_23 + 4) & 127;
    sec_accum = (sec_accum + stage_v_15) & 255;
    out_sink = (out_sink + stage_v_15 * 2) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001494_16 * 3) + pub_r001494_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_16) & 255;
    out_sink = (out_sink + stage_v_16 * 2) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_16 * 3) + pub_r001494_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_17) & 255;
    out_sink = (out_sink + stage_v_17 * 2) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001494_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001494_11 * 3) + pub_r001494_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_19) & 255;
    out_sink = (out_sink + stage_v_19 * 2) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_17 * 3) + pub_r001494_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_20) & 255;
    out_sink = (out_sink + stage_v_20 * 2) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001494_13 * 3) + pub_r001494_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_21) & 255;
    out_sink = (out_sink + stage_v_21 * 2) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001494_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001494_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001494_22 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_4 * 3) + pub_r001494_17 + 13) & 127;
    sec_accum = (sec_accum + stage_v_25) & 255;
    out_sink = (out_sink + stage_v_25 * 2) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_3 * 3) + pub_r001494_22 + 32) & 127;
    sec_accum = (sec_accum + stage_v_26) & 255;
    out_sink = (out_sink + stage_v_26 * 2) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001494_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001494_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_1 * 3) + pub_r001494_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_29) & 255;
    out_sink = (out_sink + stage_v_29 * 2) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_4 * 3) + pub_r001494_3 + 6) & 127;
    sec_accum = (sec_accum + stage_v_30) & 255;
    out_sink = (out_sink + stage_v_30 * 2) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001494_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001494_6 * 3) + pub_r001494_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_32) & 255;
    out_sink = (out_sink + stage_v_32 * 2) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_26 * 3) + pub_r001494_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_33) & 255;
    out_sink = (out_sink + stage_v_33 * 2) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001494_13 * 3) + pub_r001494_16 + 38) & 127;
    sec_accum = (sec_accum + stage_v_34) & 255;
    out_sink = (out_sink + stage_v_34 * 2) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001494_10 * 3) + pub_r001494_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_35) & 255;
    out_sink = (out_sink + stage_v_35 * 2) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001494_22 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001494_22 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001494_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_29 * 3) + pub_r001494_20 + 25) & 127;
    sec_accum = (sec_accum + stage_v_39) & 255;
    out_sink = (out_sink + stage_v_39 * 2) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_1 * 3) + pub_r001494_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_40) & 255;
    out_sink = (out_sink + stage_v_40 * 2) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001494_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001494_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001494_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001494_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_10 * 3) + pub_r001494_22 + 30) & 127;
    sec_accum = (sec_accum + stage_v_45) & 255;
    out_sink = (out_sink + stage_v_45 * 2) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_29 * 3) + pub_r001494_18 + 19) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46 * 2) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001494_16 * 3) + pub_r001494_20 + 22) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47 * 2) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001494_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001494_7 * 3) + pub_r001494_22 + 30) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49 * 2) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001494_22 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001494_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001494_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001494_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001494_9 * 3) + pub_r001494_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54 * 2) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001494_1 * 3) + pub_r001494_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55 * 2) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001494_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001494_18 * 3) + pub_r001494_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57 * 2) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001494_16 * 3) + pub_r001494_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58 * 2) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_33 * 3) + pub_r001494_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59 * 2) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001494_10 * 3) + pub_r001494_17 + 44) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60 * 2) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_7 * 3) + pub_r001494_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61 * 2) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001494_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001494_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((helper_flow_5 * 3) + pub_r001494_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64 * 2) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_64 * 3) + pub_r001494_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65 * 2) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_21 * 3) + pub_r001494_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66 * 2) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_54 * 3) + pub_r001494_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67 * 2) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001494_22 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_34 * 3) + pub_r001494_5 + 41) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69 * 2) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001494_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001494_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001494_16 * 3) + pub_r001494_20 + 19) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72 * 2) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_1 * 3) + pub_r001494_21 + 3) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73 * 2) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001494_15 * 3) + pub_r001494_12 + 37) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74 * 2) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001494_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001494_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001494_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001494_21 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001494_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_26 * 3) + pub_r001494_2 + 45) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80 * 2) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_67 * 3) + pub_r001494_19 + 39) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81 * 2) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001494_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_80 * 3) + pub_r001494_14 + 12) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83 * 2) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_57 * 3) + pub_r001494_19 + 29) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84 * 2) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_54 * 3) + pub_r001494_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85 * 2) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001494_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001494_20 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_40 * 3) + pub_r001494_13 + 34) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88 * 2) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_1 * 3) + pub_r001494_11 + 8) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89 * 2) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_16 * 3) + pub_r001494_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90 * 2) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001494_21 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001494_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001494_9 * 3) + pub_r001494_21 + 39) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93 * 2) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_16 * 3) + pub_r001494_23 + 23) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94 * 2) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_67 * 3) + pub_r001494_14 + 15) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95 * 2) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001494_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001494_15 * 3) + pub_r001494_3 + 23) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97 * 2) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001494_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_60 * 3) + pub_r001494_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99 * 2) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001494_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_90 * 3) + pub_r001494_18 + 37) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101 * 2) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001494_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001494_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_73 * 3) + pub_r001494_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104 * 2) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001494_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_5 * 3) + pub_r001494_19 + 31) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106 * 2) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001494_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001494_14 * 3) + pub_r001494_6 + 43) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108 * 2) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001494_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001494_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_40 * 3) + pub_r001494_12 + 41) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111 * 2) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_66 * 3) + pub_r001494_21 + 3) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112 * 2) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001494_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_57 * 3) + pub_r001494_22 + 32) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114 * 2) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001494_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001494_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001494_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_34 * 3) + pub_r001494_23 + 40) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118 * 2) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_59 * 3) + pub_r001494_2 + 25) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119 * 2) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_89 * 3) + pub_r001494_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120 * 2) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_34 * 3) + pub_r001494_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121 * 2) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((helper_flow_1 * 3) + pub_r001494_4 + 28) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122 * 2) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001494_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001494_3 * 3) + pub_r001494_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124 * 2) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_72 * 3) + pub_r001494_10 + 40) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125 * 2) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001494_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001494_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_25 * 3) + pub_r001494_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128 * 2) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_35 * 3) + pub_r001494_14 + 32) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129 * 2) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001494_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001494_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001494_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((sec_r001494_12 * 3) + pub_r001494_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133 * 2) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_89 * 3) + pub_r001494_2 + 37) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134 * 2) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_21 * 3) + pub_r001494_8 + 21) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135 * 2) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_1 * 3) + pub_r001494_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136 * 2) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001494_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001494_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001494_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_101 * 3) + pub_r001494_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140 * 2) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001494_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_140 * 3) + pub_r001494_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142 * 2) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001494_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_34 * 3) + pub_r001494_21 + 5) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144 * 2) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_90 * 3) + pub_r001494_13 + 43) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145 * 2) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001494_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r001494_5 * 3) + pub_r001494_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147 * 2) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001494_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001494_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_60 * 3) + pub_r001494_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150 * 2) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_73 * 3) + pub_r001494_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151 * 2) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001494_20 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001494_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001494_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001494_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_89 * 3) + pub_r001494_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156 * 2) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_61 * 3) + pub_r001494_22 + 33) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157 * 2) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001494_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001494_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_34 * 3) + pub_r001494_7 + 45) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160 * 2) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001494_15 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001494_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_108 * 3) + pub_r001494_17 + 22) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163 * 2) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_73 * 3) + pub_r001494_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164 * 2) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_25 * 3) + pub_r001494_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165 * 2) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_165 * 3) + pub_r001494_9 + 25) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166 * 2) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001494_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001494_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001494_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001494_21 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_64 * 3) + pub_r001494_9 + 10) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171 * 2) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_165 * 3) + pub_r001494_0 + 22) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172 * 2) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001494_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_32 * 3) + pub_r001494_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174 * 2) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001494_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001494_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001494_20 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_35 * 3) + pub_r001494_8 + 35) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178 * 2) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((helper_flow_0 * 3) + pub_r001494_22 + 39) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179 * 2) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001494_20 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001494_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_26 * 3) + pub_r001494_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182 * 2) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_111 * 3) + pub_r001494_7 + 34) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183 * 2) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001494_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((helper_flow_1 * 3) + pub_r001494_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185 * 2) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001494_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001494_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001494_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001494_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001494_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_95 * 3) + pub_r001494_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191 * 2) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001494_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_69 * 3) + pub_r001494_23 + 24) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193 * 2) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_179 * 3) + pub_r001494_18 + 8) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194 * 2) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_89 * 3) + pub_r001494_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195 * 2) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001494_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((helper_flow_4 * 3) + pub_r001494_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197 * 2) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001494_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001494_23 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001494_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001494_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_17 * 3) + pub_r001494_16 + 35) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202 * 2) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001494_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001494_17 * 3) + pub_r001494_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204 * 2) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_40 * 3) + pub_r001494_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205 * 2) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r001494_6 * 3) + pub_r001494_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206 * 2) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001494_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001494_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001494_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001494_20 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_157 * 3) + pub_r001494_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211 * 2) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001494_23 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r001494_5 * 3) + pub_r001494_22 + 22) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213 * 2) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001494_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_61 * 3) + pub_r001494_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215 * 2) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001494_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001494_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_156 * 3) + pub_r001494_21 + 42) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218 * 2) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001494_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001494_21 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_95 * 3) + pub_r001494_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221 * 2) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_54 * 3) + pub_r001494_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222 * 2) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_202 * 3) + pub_r001494_20 + 33) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223 * 2) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_85 * 3) + pub_r001494_18 + 19) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224 * 2) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001494_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_197 * 3) + pub_r001494_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226 * 2) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_89 * 3) + pub_r001494_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227 * 2) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_106 * 3) + pub_r001494_10 + 43) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228 * 2) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_7 * 3) + pub_r001494_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229 * 2) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_40 * 3) + pub_r001494_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230 * 2) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001494_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001494_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001494_21 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((sec_r001494_4 * 3) + pub_r001494_17 + 25) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234 * 2) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_147 * 3) + pub_r001494_19 + 26) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235 * 2) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_144 * 3) + pub_r001494_5 + 39) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236 * 2) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((sec_r001494_9 * 3) + pub_r001494_21 + 45) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237 * 2) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001494_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001494_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_49 * 3) + pub_r001494_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240 * 2) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_226 * 3) + pub_r001494_21 + 42) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241 * 2) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_35 * 3) + pub_r001494_18 + 44) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242 * 2) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001494_23 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_16 * 3) + pub_r001494_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244 * 2) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001494_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001494_21 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_114 * 3) + pub_r001494_23 + 15) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247 * 2) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001494_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001494_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001494_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_247 * 3) + pub_r001494_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251 * 2) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001494_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001494_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_227 * 3) + pub_r001494_21 + 7) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254 * 2) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001494_23 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001494_23 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001494_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001494_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001494_21 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001494_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001494_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_5 * 3) + pub_r001494_19 + 10) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262 * 2) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_227 * 3) + pub_r001494_7 + 16) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263 * 2) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001494_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r001494_8 * 3) + pub_r001494_21 + 40) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265 * 2) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001494_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_66 * 3) + pub_r001494_16 + 8) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267 * 2) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_15 * 3) + pub_r001494_8 + 43) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268 * 2) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001494_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_1 * 3) + pub_r001494_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270 * 2) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_45 * 3) + pub_r001494_0 + 21) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271 * 2) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001494_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_165 * 3) + pub_r001494_21 + 19) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273 * 2) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_197 * 3) + pub_r001494_21 + 4) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274 * 2) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001494_21 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001494_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_222 * 3) + pub_r001494_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277 * 2) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_16 * 3) + pub_r001494_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278 * 2) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001494_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001494_20 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001494_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_112 * 3) + pub_r001494_19 + 34) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282 * 2) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001494_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001494_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_164 * 3) + pub_r001494_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285 * 2) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_274 * 3) + pub_r001494_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286 * 2) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001494_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001494_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_64 * 3) + pub_r001494_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289 * 2) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001494_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_134 * 3) + pub_r001494_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291 * 2) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_282 * 3) + pub_r001494_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292 * 2) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001494_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001494_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001494_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_84 * 3) + pub_r001494_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296 * 2) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001494_21 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001494_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001494_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001494_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001494_22 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001494_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001494_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_133 * 3) + pub_r001494_0 + 27) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304 * 2) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_197 * 3) + pub_r001494_16 + 34) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305 * 2) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((sec_r001494_6 * 3) + pub_r001494_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306 * 2) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001494_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((sec_r001494_12 * 3) + pub_r001494_4 + 31) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308 * 2) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_49 * 3) + pub_r001494_12 + 25) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309 * 2) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001494_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((sec_r001494_7 * 3) + pub_r001494_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311 * 2) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_234 * 3) + pub_r001494_13 + 11) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312 * 2) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001494_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001494_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001494_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001494_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_106 * 3) + pub_r001494_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317 * 2) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_118 * 3) + pub_r001494_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318 * 2) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_240 * 3) + pub_r001494_21 + 3) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319 * 2) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_277 * 3) + pub_r001494_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320 * 2) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001494_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_59 * 3) + pub_r001494_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322 * 2) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001494_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_270 * 3) + pub_r001494_16 + 9) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324 * 2) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001494_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_165 * 3) + pub_r001494_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326 * 2) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001494_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001494_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_191 * 3) + pub_r001494_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329 * 2) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001494_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_93 * 3) + pub_r001494_11 + 25) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331 * 2) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_90 * 3) + pub_r001494_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332 * 2) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_289 * 3) + pub_r001494_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333 * 2) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_45 * 3) + pub_r001494_15 + 35) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334 * 2) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_30 * 3) + pub_r001494_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335 * 2) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_7 * 3) + pub_r001494_16 + 40) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336 * 2) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001494_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001494_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001494_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001494_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_9 * 3) + pub_r001494_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341 * 2) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_195 * 3) + pub_r001494_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342 * 2) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_331 * 3) + pub_r001494_11 + 39) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343 * 2) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001494_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_342 * 3) + pub_r001494_8 + 39) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345 * 2) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_10 * 3) + pub_r001494_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346 * 2) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_108 * 3) + pub_r001494_18 + 42) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347 * 2) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_97 * 3) + pub_r001494_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348 * 2) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_254 * 3) + pub_r001494_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349 * 2) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_274 * 3) + pub_r001494_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350 * 2) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_95 * 3) + pub_r001494_16 + 43) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351 * 2) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001494_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_164 * 3) + pub_r001494_16 + 41) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353 * 2) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_285 * 3) + pub_r001494_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354 * 2) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_191 * 3) + pub_r001494_18 + 17) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355 * 2) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_125 * 3) + pub_r001494_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356 * 2) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001494_22 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_166 * 3) + pub_r001494_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358 * 2) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001494_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_10 * 3) + pub_r001494_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360 * 2) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001494_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001494_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001494_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001494_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001494_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001494_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001494_23 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001494_22 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_355 * 3) + pub_r001494_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_369) & 255;
    out_sink = (out_sink + stage_v_369 * 2) & 255;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((sec_r001494_5 * 3) + pub_r001494_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_370) & 255;
    out_sink = (out_sink + stage_v_370 * 2) & 255;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_265 * 3) + pub_r001494_18 + 9) & 127;
    sec_accum = (sec_accum + stage_v_371) & 255;
    out_sink = (out_sink + stage_v_371 * 2) & 255;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_120 * 3) + pub_r001494_22 + 26) & 127;
    sec_accum = (sec_accum + stage_v_372) & 255;
    out_sink = (out_sink + stage_v_372 * 2) & 255;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_332 * 3) + pub_r001494_19 + 8) & 127;
    sec_accum = (sec_accum + stage_v_373) & 255;
    out_sink = (out_sink + stage_v_373 * 2) & 255;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_329 * 3) + pub_r001494_22 + 38) & 127;
    sec_accum = (sec_accum + stage_v_374) & 255;
    out_sink = (out_sink + stage_v_374 * 2) & 255;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_16 * 3) + pub_r001494_8 + 12) & 127;
    sec_accum = (sec_accum + stage_v_375) & 255;
    out_sink = (out_sink + stage_v_375 * 2) & 255;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_204 * 3) + pub_r001494_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_376) & 255;
    out_sink = (out_sink + stage_v_376 * 2) & 255;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_94 * 3) + pub_r001494_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_377) & 255;
    out_sink = (out_sink + stage_v_377 * 2) & 255;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_277 * 3) + pub_r001494_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_378) & 255;
    out_sink = (out_sink + stage_v_378 * 2) & 255;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((helper_flow_3 * 3) + pub_r001494_23 + 23) & 127;
    sec_accum = (sec_accum + stage_v_379) & 255;
    out_sink = (out_sink + stage_v_379 * 2) & 255;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_33 * 3) + pub_r001494_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_380) & 255;
    out_sink = (out_sink + stage_v_380 * 2) & 255;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_66 * 3) + pub_r001494_5 + 5) & 127;
    sec_accum = (sec_accum + stage_v_381) & 255;
    out_sink = (out_sink + stage_v_381 * 2) & 255;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001494_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_347 * 3) + pub_r001494_20 + 7) & 127;
    sec_accum = (sec_accum + stage_v_383) & 255;
    out_sink = (out_sink + stage_v_383 * 2) & 255;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001494_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001494_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_305 * 3) + pub_r001494_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_386) & 255;
    out_sink = (out_sink + stage_v_386 * 2) & 255;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001494_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001494_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_32 * 3) + pub_r001494_22 + 42) & 127;
    sec_accum = (sec_accum + stage_v_389) & 255;
    out_sink = (out_sink + stage_v_389 * 2) & 255;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_215 * 3) + pub_r001494_14 + 15) & 127;
    sec_accum = (sec_accum + stage_v_390) & 255;
    out_sink = (out_sink + stage_v_390 * 2) & 255;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001494_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001494_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001494_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_296 * 3) + pub_r001494_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_394) & 255;
    out_sink = (out_sink + stage_v_394 * 2) & 255;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_142 * 3) + pub_r001494_23 + 15) & 127;
    sec_accum = (sec_accum + stage_v_395) & 255;
    out_sink = (out_sink + stage_v_395 * 2) & 255;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001494_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001494_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((stage_v_235 * 3) + pub_r001494_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_398) & 255;
    out_sink = (out_sink + stage_v_398 * 2) & 255;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001494_5 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001494_23 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_185 * 3) + pub_r001494_0 + 20) & 127;
    sec_accum = (sec_accum + stage_v_401) & 255;
    out_sink = (out_sink + stage_v_401 * 2) & 255;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001494_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((helper_flow_4 * 3) + pub_r001494_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_403) & 255;
    out_sink = (out_sink + stage_v_403 * 2) & 255;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((helper_flow_2 * 3) + pub_r001494_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_404) & 255;
    out_sink = (out_sink + stage_v_404 * 2) & 255;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_125 * 3) + pub_r001494_20 + 10) & 127;
    sec_accum = (sec_accum + stage_v_405) & 255;
    out_sink = (out_sink + stage_v_405 * 2) & 255;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_204 * 3) + pub_r001494_21 + 24) & 127;
    sec_accum = (sec_accum + stage_v_406) & 255;
    out_sink = (out_sink + stage_v_406 * 2) & 255;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001494_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001494_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_172 * 3) + pub_r001494_20 + 17) & 127;
    sec_accum = (sec_accum + stage_v_409) & 255;
    out_sink = (out_sink + stage_v_409 * 2) & 255;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001494_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001494_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_251 * 3) + pub_r001494_6 + 30) & 127;
    sec_accum = (sec_accum + stage_v_412) & 255;
    out_sink = (out_sink + stage_v_412 * 2) & 255;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_135 * 3) + pub_r001494_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_413) & 255;
    out_sink = (out_sink + stage_v_413 * 2) & 255;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_30 * 3) + pub_r001494_23 + 18) & 127;
    sec_accum = (sec_accum + stage_v_414) & 255;
    out_sink = (out_sink + stage_v_414 * 2) & 255;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001494_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001494_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_135 * 3) + pub_r001494_22 + 43) & 127;
    sec_accum = (sec_accum + stage_v_417) & 255;
    out_sink = (out_sink + stage_v_417 * 2) & 255;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001494_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001494_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001494_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_332 * 3) + pub_r001494_12 + 45) & 127;
    sec_accum = (sec_accum + stage_v_421) & 255;
    out_sink = (out_sink + stage_v_421 * 2) & 255;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001494_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_157 * 3) + pub_r001494_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_423) & 255;
    out_sink = (out_sink + stage_v_423 * 2) & 255;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001494_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_95 * 3) + pub_r001494_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_425) & 255;
    out_sink = (out_sink + stage_v_425 * 2) & 255;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_40 * 3) + pub_r001494_2 + 23) & 127;
    sec_accum = (sec_accum + stage_v_426) & 255;
    out_sink = (out_sink + stage_v_426 * 2) & 255;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_235 * 3) + pub_r001494_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_427) & 255;
    out_sink = (out_sink + stage_v_427 * 2) & 255;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001494_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001494_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001494_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001494_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001494_23 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((helper_flow_5 * 3) + pub_r001494_18 + 5) & 127;
    sec_accum = (sec_accum + stage_v_433) & 255;
    out_sink = (out_sink + stage_v_433 * 2) & 255;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001494_23 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_409 * 3) + pub_r001494_7 + 22) & 127;
    sec_accum = (sec_accum + stage_v_435) & 255;
    out_sink = (out_sink + stage_v_435 * 2) & 255;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_25 * 3) + pub_r001494_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_436) & 255;
    out_sink = (out_sink + stage_v_436 * 2) & 255;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001494_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_7 * 3) + pub_r001494_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_438) & 255;
    out_sink = (out_sink + stage_v_438 * 2) & 255;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_121 * 3) + pub_r001494_23 + 30) & 127;
    sec_accum = (sec_accum + stage_v_439) & 255;
    out_sink = (out_sink + stage_v_439 * 2) & 255;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_347 * 3) + pub_r001494_1 + 29) & 127;
    sec_accum = (sec_accum + stage_v_440) & 255;
    out_sink = (out_sink + stage_v_440 * 2) & 255;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_373 * 3) + pub_r001494_19 + 28) & 127;
    sec_accum = (sec_accum + stage_v_441) & 255;
    out_sink = (out_sink + stage_v_441 * 2) & 255;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((sec_r001494_17 * 3) + pub_r001494_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_442) & 255;
    out_sink = (out_sink + stage_v_442 * 2) & 255;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_244 * 3) + pub_r001494_20 + 16) & 127;
    sec_accum = (sec_accum + stage_v_443) & 255;
    out_sink = (out_sink + stage_v_443 * 2) & 255;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001494_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001494_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_237 * 3) + pub_r001494_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_446) & 255;
    out_sink = (out_sink + stage_v_446 * 2) & 255;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_379 * 3) + pub_r001494_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_447) & 255;
    out_sink = (out_sink + stage_v_447 * 2) & 255;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001494_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_128 * 3) + pub_r001494_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_449) & 255;
    out_sink = (out_sink + stage_v_449 * 2) & 255;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_134 * 3) + pub_r001494_12 + 38) & 127;
    sec_accum = (sec_accum + stage_v_450) & 255;
    out_sink = (out_sink + stage_v_450 * 2) & 255;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_251 * 3) + pub_r001494_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_451) & 255;
    out_sink = (out_sink + stage_v_451 * 2) & 255;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_136 * 3) + pub_r001494_23 + 3) & 127;
    sec_accum = (sec_accum + stage_v_452) & 255;
    out_sink = (out_sink + stage_v_452 * 2) & 255;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001494_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001494_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_353 * 3) + pub_r001494_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_455) & 255;
    out_sink = (out_sink + stage_v_455 * 2) & 255;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_30 * 3) + pub_r001494_22 + 15) & 127;
    sec_accum = (sec_accum + stage_v_456) & 255;
    out_sink = (out_sink + stage_v_456 * 2) & 255;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001494_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001494_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_134 * 3) + pub_r001494_11 + 45) & 127;
    sec_accum = (sec_accum + stage_v_459) & 255;
    out_sink = (out_sink + stage_v_459 * 2) & 255;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_229 * 3) + pub_r001494_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_460) & 255;
    out_sink = (out_sink + stage_v_460 * 2) & 255;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_15 * 3) + pub_r001494_15 + 40) & 127;
    sec_accum = (sec_accum + stage_v_461) & 255;
    out_sink = (out_sink + stage_v_461 * 2) & 255;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_375 * 3) + pub_r001494_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_462) & 255;
    out_sink = (out_sink + stage_v_462 * 2) & 255;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001494_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001494_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001494_22 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_140 * 3) + pub_r001494_10 + 44) & 127;
    sec_accum = (sec_accum + stage_v_466) & 255;
    out_sink = (out_sink + stage_v_466 * 2) & 255;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_205 * 3) + pub_r001494_7 + 27) & 127;
    sec_accum = (sec_accum + stage_v_467) & 255;
    out_sink = (out_sink + stage_v_467 * 2) & 255;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = (pub_r001494_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_468) & 127;

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001494_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = ((sec_r001494_7 * 3) + pub_r001494_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_470) & 255;
    out_sink = (out_sink + stage_v_470 * 2) & 255;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001494_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_93 * 3) + pub_r001494_10 + 17) & 127;
    sec_accum = (sec_accum + stage_v_472) & 255;
    out_sink = (out_sink + stage_v_472 * 2) & 255;

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_226 * 3) + pub_r001494_13 + 45) & 127;
    sec_accum = (sec_accum + stage_v_473) & 255;
    out_sink = (out_sink + stage_v_473 * 2) & 255;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_32 * 3) + pub_r001494_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_474) & 255;
    out_sink = (out_sink + stage_v_474 * 2) & 255;

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((sec_r001494_18 * 3) + pub_r001494_23 + 42) & 127;
    sec_accum = (sec_accum + stage_v_475) & 255;
    out_sink = (out_sink + stage_v_475 * 2) & 255;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001494_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001494_23 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = ((stage_v_88 * 3) + pub_r001494_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_478) & 255;
    out_sink = (out_sink + stage_v_478 * 2) & 255;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001494_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_136 * 3) + pub_r001494_2 + 42) & 127;
    sec_accum = (sec_accum + stage_v_480) & 255;
    out_sink = (out_sink + stage_v_480 * 2) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
