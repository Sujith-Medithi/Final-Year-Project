/*
 * Benchmark Program: R001265
 * Security Family: bitwise_flow
 * Generator Seed: 626513
 * High Inputs: 19 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001265_6513_0 {
    int peak;
    int rms;
    short envelope;
    int gain;
    unsigned char channels;
    int buffer[3];
};

struct SensorNode_R001265_6513_1 {
    unsigned char threshold;
    int calib;
    int status;
    unsigned char reading;
    short offset;
    int buffer[3];
};

struct EventLog_R001265_6513_2 {
    int timestamp;
    unsigned char facility;
    int severity;
    int code;
    int signature;
    int buffer[3];
};

struct Transaction_R001265_6513_3 {
    unsigned char fee;
    int balance;
    unsigned char account_id;
    unsigned char rate;
    short status;
    unsigned char auth_code;
    int buffer[3];
};

union PacketPayload_R001265_6513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001265_6513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001265_6513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_69 = 0;
    for (int k = 0; k < 2; k++) {
        bound_69 = (bound_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_69) & 127;
    }
    int parity_77 = (aux + st.buffer[1]) & 3;
    switch (parity_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_51 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_51 > 19) {
        acc = (acc + tally_51 * 2 + 5) & 127;
        aux ^= (tally_51 & 15);
    } else {
        acc = (acc - tally_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int delta_53 = local_arr[aux % 3];
    acc = (acc + delta_53 * 2) & 127;
    int cursor_71 = (aux + st.buffer[1]) & 3;
    switch (cursor_71) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_98 = 0;
    for (int k = 0; k < 3; k++) {
        metric_98 = (metric_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_98) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int pivot_25 = local_arr[aux % 3];
    acc = (acc + pivot_25 * 2) & 127;
    int pivot_82 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_82 = (pivot_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_3(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_15 = (aux + st.buffer[1]) & 3;
    switch (margin_15) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_60) & 63;
    acc ^= aux;
    int cursor_23 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_23 = (cursor_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_4(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001265_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int mask_93 = local_arr[aux % 3];
    acc = (acc + mask_93 * 2) & 127;
    int quotient_13 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_13 = (quotient_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int parity_32 = 0;
    for (int k = 0; k < 3; k++) {
        parity_32 = (parity_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_32) & 127;
    }
    int weight_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_31) & 63;
    acc ^= aux;
    int vector_70 = (aux + st.buffer[1]) & 3;
    switch (vector_70) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_20 = local_arr[aux % 3];
    acc = (acc + checksum_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int stride_98 = 0;
    for (int k = 0; k < 3; k++) {
        stride_98 = (stride_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_98) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_75 = (aux + st.buffer[1]) & 3;
    switch (window_75) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001265_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int accumulator_58 = local_arr[aux % 3];
    acc = (acc + accumulator_58 * 2) & 127;
    int parity_55 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_55 > 28) {
        acc = (acc + parity_55 * 2 + 5) & 127;
        aux ^= (parity_55 & 15);
    } else {
        acc = (acc - parity_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_8(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001265_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_53 = 0;
    for (int k = 0; k < 3; k++) {
        damping_53 = (damping_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_53) & 127;
    }
    int delta_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_10) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_80 = local_arr[aux % 3];
    acc = (acc + mask_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001265_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int metric_69 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_69 > 26) {
        acc = (acc + metric_69 * 2 + 5) & 127;
        aux ^= (metric_69 & 15);
    } else {
        acc = (acc - metric_69 + 11) & 127;
        aux += 3;
    }
    int vector_58 = 0;
    for (int k = 0; k < 2; k++) {
        vector_58 = (vector_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_58) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001265_6513_10(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_63 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_63 > 21) {
        acc = (acc + parity_63 * 2 + 5) & 127;
        aux ^= (parity_63 & 15);
    } else {
        acc = (acc - parity_63 + 11) & 127;
        aux += 3;
    }
    int offset_65 = 0;
    for (int k = 0; k < 2; k++) {
        offset_65 = (offset_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_65) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_71 = local_arr[aux % 3];
    acc = (acc + parity_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_11(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_77 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_77 > 38) {
        acc = (acc + mask_77 * 2 + 5) & 127;
        aux ^= (mask_77 & 15);
    } else {
        acc = (acc - mask_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_56 = 0;
    for (int k = 0; k < 3; k++) {
        scale_56 = (scale_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_56) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_12(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001265_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int accumulator_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_62) & 63;
    acc ^= aux;
    int tracker_95 = (aux + st.buffer[1]) & 3;
    switch (tracker_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_50 = 0;
    for (int k = 0; k < 3; k++) {
        factor_50 = (factor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_50) & 127;
    }
    int tracker_66 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_66 > 41) {
        acc = (acc + tracker_66 * 2 + 5) & 127;
        aux ^= (tracker_66 & 15);
    } else {
        acc = (acc - tracker_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001265_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int sample_10 = local_arr[aux % 3];
    acc = (acc + sample_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_12) & 63;
    acc ^= aux;
    int residue_81 = (aux + st.buffer[1]) & 3;
    switch (residue_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001265_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_12 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_12 > 20) {
        acc = (acc + offset_12 * 2 + 5) & 127;
        aux ^= (offset_12 & 15);
    } else {
        acc = (acc - offset_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_47 = local_arr[aux % 3];
    acc = (acc + threshold_47 * 2) & 127;
    int vector_31 = 0;
    for (int k = 0; k < 2; k++) {
        vector_31 = (vector_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_31) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001265_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int offset_29 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_29 > 43) {
        acc = (acc + offset_29 * 2 + 5) & 127;
        aux ^= (offset_29 & 15);
    } else {
        acc = (acc - offset_29 + 11) & 127;
        aux += 3;
    }
    int quantum_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_53 = local_arr[aux % 3];
    acc = (acc + mask_53 * 2) & 127;
    int sample_63 = 0;
    for (int k = 0; k < 3; k++) {
        sample_63 = (sample_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_63) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_16(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_67 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_67 > 30) {
        acc = (acc + delta_67 * 2 + 5) & 127;
        aux ^= (delta_67 & 15);
    } else {
        acc = (acc - delta_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_84 = (aux + st.buffer[1]) & 3;
    switch (segment_84) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001265_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_15) & 63;
    acc ^= aux;
    int bound_52 = 0;
    for (int k = 0; k < 2; k++) {
        bound_52 = (bound_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_52) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_19(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001265_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int factor_82 = local_arr[aux % 3];
    acc = (acc + factor_82 * 2) & 127;
    int quotient_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_29) & 63;
    acc ^= aux;
    int damping_95 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_95 > 19) {
        acc = (acc + damping_95 * 2 + 5) & 127;
        aux ^= (damping_95 & 15);
    } else {
        acc = (acc - damping_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001265_6513_20(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int vector_42 = local_arr[aux % 3];
    acc = (acc + vector_42 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_21(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001265_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_16) & 63;
    acc ^= aux;
    int mask_23 = (aux + st.buffer[1]) & 3;
    switch (mask_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_64 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_64 = (quantum_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_64) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001265_6513_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001265_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_31 = (aux + st.buffer[1]) & 3;
    switch (sample_31) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_41 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_41 > 27) {
        acc = (acc + sample_41 * 2 + 5) & 127;
        aux ^= (sample_41 & 15);
    } else {
        acc = (acc - sample_41 + 11) & 127;
        aux += 3;
    }
    int accumulator_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001265_0;
    int sec_r001265_1;
    int sec_r001265_2;
    int sec_r001265_3;
    int sec_r001265_4;
    int sec_r001265_5;
    int sec_r001265_6;
    int sec_r001265_7;
    int sec_r001265_8;
    int sec_r001265_9;
    int sec_r001265_10;
    int sec_r001265_11;
    int sec_r001265_12;
    int sec_r001265_13;
    int sec_r001265_14;
    int sec_r001265_15;
    int sec_r001265_16;
    int sec_r001265_17;
    int sec_r001265_18;
    int pub_r001265_0;
    int pub_r001265_1;
    int pub_r001265_2;
    int pub_r001265_3;
    int pub_r001265_4;
    int pub_r001265_5;
    int pub_r001265_6;
    int pub_r001265_7;
    int pub_r001265_8;
    int pub_r001265_9;
    int pub_r001265_10;
    int pub_r001265_11;
    int pub_r001265_12;
    int pub_r001265_13;
    int pub_r001265_14;
    int pub_r001265_15;
    int pub_r001265_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001265_0 >= -100 && pub_r001265_0 <= 100);
    __CPROVER_assume(pub_r001265_1 >= -100 && pub_r001265_1 <= 100);
    __CPROVER_assume(pub_r001265_2 >= -100 && pub_r001265_2 <= 100);
    __CPROVER_assume(pub_r001265_3 >= -100 && pub_r001265_3 <= 100);
    __CPROVER_assume(pub_r001265_4 >= -100 && pub_r001265_4 <= 100);
    __CPROVER_assume(pub_r001265_5 >= -100 && pub_r001265_5 <= 100);
    __CPROVER_assume(pub_r001265_6 >= -100 && pub_r001265_6 <= 100);
    __CPROVER_assume(pub_r001265_7 >= -100 && pub_r001265_7 <= 100);
    __CPROVER_assume(pub_r001265_8 >= -100 && pub_r001265_8 <= 100);
    __CPROVER_assume(pub_r001265_9 >= -100 && pub_r001265_9 <= 100);
    __CPROVER_assume(pub_r001265_10 >= -100 && pub_r001265_10 <= 100);
    __CPROVER_assume(pub_r001265_11 >= -100 && pub_r001265_11 <= 100);
    __CPROVER_assume(pub_r001265_12 >= -100 && pub_r001265_12 <= 100);
    __CPROVER_assume(pub_r001265_13 >= -100 && pub_r001265_13 <= 100);
    __CPROVER_assume(pub_r001265_14 >= -100 && pub_r001265_14 <= 100);
    __CPROVER_assume(pub_r001265_15 >= -100 && pub_r001265_15 <= 100);
    __CPROVER_assume(pub_r001265_16 >= -100 && pub_r001265_16 <= 100);
    __CPROVER_assume(sec_r001265_0 >= 0 && sec_r001265_0 <= 255);
    __CPROVER_assume(sec_r001265_1 >= 0 && sec_r001265_1 <= 255);
    __CPROVER_assume(sec_r001265_2 >= 0 && sec_r001265_2 <= 255);
    __CPROVER_assume(sec_r001265_3 >= 0 && sec_r001265_3 <= 255);
    __CPROVER_assume(sec_r001265_4 >= 0 && sec_r001265_4 <= 255);
    __CPROVER_assume(sec_r001265_5 >= 0 && sec_r001265_5 <= 255);
    __CPROVER_assume(sec_r001265_6 >= 0 && sec_r001265_6 <= 255);
    __CPROVER_assume(sec_r001265_7 >= 0 && sec_r001265_7 <= 255);
    __CPROVER_assume(sec_r001265_8 >= 0 && sec_r001265_8 <= 255);
    __CPROVER_assume(sec_r001265_9 >= 0 && sec_r001265_9 <= 255);
    __CPROVER_assume(sec_r001265_10 >= 0 && sec_r001265_10 <= 255);
    __CPROVER_assume(sec_r001265_11 >= 0 && sec_r001265_11 <= 255);
    __CPROVER_assume(sec_r001265_12 >= 0 && sec_r001265_12 <= 255);
    __CPROVER_assume(sec_r001265_13 >= 0 && sec_r001265_13 <= 255);
    __CPROVER_assume(sec_r001265_14 >= 0 && sec_r001265_14 <= 255);
    __CPROVER_assume(sec_r001265_15 >= 0 && sec_r001265_15 <= 255);
    __CPROVER_assume(sec_r001265_16 >= 0 && sec_r001265_16 <= 255);
    __CPROVER_assume(sec_r001265_17 >= 0 && sec_r001265_17 <= 255);
    __CPROVER_assume(sec_r001265_18 >= 0 && sec_r001265_18 <= 255);

    struct AudioFrame_R001265_6513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001265_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001265_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001265_0 + 7) & 15;
    struct SensorNode_R001265_6513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001265_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001265_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001265_0 + 9) & 15;
    struct EventLog_R001265_6513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001265_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001265_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001265_0 + 11) & 15;
    struct Transaction_R001265_6513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001265_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001265_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001265_0 + 13) & 15;

    union PacketPayload_R001265_6513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001265_6513_0(sec_r001265_0, sec_r001265_1, pub_r001265_2, pub_r001265_3);
    int helper_flow_1 = fn_R001265_6513_1(sec_r001265_1, pub_r001265_2, pub_r001265_3, pub_r001265_4);
    int helper_flow_2 = fn_R001265_6513_2(sec_r001265_2, sec_r001265_3, pub_r001265_4, pub_r001265_5);
    int helper_flow_3 = fn_R001265_6513_3(sec_r001265_3, pub_r001265_4, pub_r001265_5);
    int helper_flow_4 = fn_R001265_6513_4(sec_r001265_4, pub_r001265_5);
    int helper_flow_5 = fn_R001265_6513_5(sec_r001265_5, pub_r001265_6, pub_r001265_7, pub_r001265_8, pub_r001265_9);
    int helper_flow_6 = fn_R001265_6513_6(sec_r001265_6, pub_r001265_7, pub_r001265_8, pub_r001265_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001265_8 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001265_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001265_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001265_16 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001265_18 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001265_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001265_12 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001265_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001265_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_0 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001265_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001265_12 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_4 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001265_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001265_8 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001265_9 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001265_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001265_10 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001265_17 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001265_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001265_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001265_3 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001265_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_5 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_18 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_17 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001265_14 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001265_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001265_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_4 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001265_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001265_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_11 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r001265_8 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001265_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_21 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001265_1 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001265_10 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001265_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001265_6 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001265_4 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001265_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001265_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_1 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_40 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_2 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001265_17 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001265_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001265_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_11 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001265_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001265_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001265_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001265_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_3 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001265_2 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_32 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001265_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001265_18 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001265_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001265_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001265_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001265_14 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001265_9 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001265_18 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001265_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_9 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_56 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_40 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_12 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001265_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001265_1 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_2 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_4 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_63 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001265_16 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001265_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001265_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001265_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001265_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_12 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001265_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_69 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_55 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_14 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_39 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001265_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_80 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_85 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_56 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_3 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_36 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001265_0 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001265_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001265_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001265_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_37 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001265_9 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_55 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001265_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001265_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_3 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_39 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001265_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001265_2 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_54 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001265_2 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_88 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001265_13 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_36 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001265_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001265_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001265_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_62 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_44 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_114 + 1) & 15;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001265_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001265_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001265_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001265_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_58 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_107 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_82 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_97 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001265_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_63 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001265_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_40 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_2 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001265_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_91 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_126 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001265_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001265_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001265_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_104 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001265_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_120 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001265_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001265_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_11 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_108 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001265_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_67 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001265_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001265_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001265_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001265_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_92 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_71 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001265_9 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001265_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001265_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001265_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001265_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001265_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001265_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001265_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_23 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_87 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((helper_flow_0 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001265_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_23 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_4 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_113 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_90 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_2 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((helper_flow_6 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_162 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001265_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_102 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_35 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001265_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_126 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001265_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_126 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_39 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_37 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_75 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001265_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001265_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001265_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001265_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_101 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001265_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_149 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_165 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_113 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_64 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_56 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_69 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r001265_6 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001265_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001265_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_45 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((helper_flow_6 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_108 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001265_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001265_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r001265_12 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001265_9 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001265_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_105 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001265_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001265_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001265_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_32 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001265_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_186 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001265_1 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001265_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001265_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_122 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001265_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_25 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001265_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_18 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001265_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_58 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001265_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_126 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001265_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001265_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001265_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_176 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((sec_r001265_4 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_68 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001265_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001265_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001265_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001265_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001265_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_58 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001265_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_6 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_75 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001265_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001265_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001265_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001265_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_68 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001265_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001265_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001265_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_224 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001265_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001265_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_163 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_25 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_188 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((sec_r001265_18 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_234 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_158 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001265_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r001265_9 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_67 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_67 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_62 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_98 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_49 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001265_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001265_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001265_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001265_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_23 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001265_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001265_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_105 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001265_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_185 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001265_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_98 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_43 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_121 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_257 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_46 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001265_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_243 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_174 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_62 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001265_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001265_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_87 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_163 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_88 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_195 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_189 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_167 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001265_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001265_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_224 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_165 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_90 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_43 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001265_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001265_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_24 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001265_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_148 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_36 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_46 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001265_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_159 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001265_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_130 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_190 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_176 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_223 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_195 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001265_6 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001265_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001265_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001265_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_109 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_248 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_37 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001265_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_163 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_207 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_90 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((sec_r001265_9 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001265_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_312 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_55 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001265_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001265_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_161 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_114 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001265_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_256 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_284 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001265_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_73 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_277 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_129 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_174 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_289 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_215 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_195 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001265_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001265_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001265_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_223 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001265_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((sec_r001265_4 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_285 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_55 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_198 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001265_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001265_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_96 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_163 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_295 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001265_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001265_4 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001265_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_314 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001265_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001265_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001265_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_231 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (pub_r001265_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_360) & 127;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_119 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001265_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_277 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001265_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001265_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((sec_r001265_13 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((helper_flow_2 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_185 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001265_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001265_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001265_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001265_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_201 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001265_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_291 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_185 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_73 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001265_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001265_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_176 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001265_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_312 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_147 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001265_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001265_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_40 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001265_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001265_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001265_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_43 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_121 << 1) ^ (pub_r001265_8 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_3 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001265_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_17 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001265_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((helper_flow_0 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001265_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001265_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_276 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001265_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001265_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001265_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_89 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((sec_r001265_14 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001265_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_63 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001265_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_17 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((sec_r001265_5 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001265_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_292 << 1) ^ (pub_r001265_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_83 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_375 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_83 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001265_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001265_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_126 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_363 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001265_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_322 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_169 << 1) ^ (pub_r001265_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001265_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001265_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_101 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_215 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_334 << 1) ^ (pub_r001265_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001265_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_319 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((sec_r001265_13 << 1) ^ (pub_r001265_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001265_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001265_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_217 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_432 + 1) & 15;
    out_sink ^= (stage_v_432 & 63);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001265_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_380 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_243 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001265_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_72 << 1) ^ (pub_r001265_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001265_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001265_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_254 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_257 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_344 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((sec_r001265_13 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_14 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001265_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001265_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_432 << 1) ^ (pub_r001265_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_331 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001265_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_359 << 1) ^ (pub_r001265_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_190 << 1) ^ (pub_r001265_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001265_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_403 << 1) ^ (pub_r001265_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_453 + 1) & 15;
    out_sink ^= (stage_v_453 & 63);

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001265_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_199 << 1) ^ (pub_r001265_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_455 + 1) & 15;
    out_sink ^= (stage_v_455 & 63);

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_54 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_456 + 1) & 15;
    out_sink ^= (stage_v_456 & 63);

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = ((stage_v_440 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_457 + 1) & 15;
    out_sink ^= (stage_v_457 & 63);

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_249 << 1) ^ (pub_r001265_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_458 + 1) & 15;
    out_sink ^= (stage_v_458 & 63);

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001265_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((helper_flow_4 << 1) ^ (pub_r001265_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001265_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001265_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_434 << 1) ^ (pub_r001265_5 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_463 + 1) & 15;
    out_sink ^= (stage_v_463 & 63);

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001265_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001265_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_62 << 1) ^ (pub_r001265_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_466 + 1) & 15;
    out_sink ^= (stage_v_466 & 63);

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_441 << 1) ^ (pub_r001265_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_255 << 1) ^ (pub_r001265_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001265_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001265_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
