/*
 * Benchmark Program: R001660
 * Security Family: mixed_control_data
 * Generator Seed: 666013
 * High Inputs: 18 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001660_6013_0 {
    int sample_rate;
    int rms;
    int channels;
    short gain;
    unsigned char envelope;
    int peak;
    int buffer[3];
};

struct SensorNode_R001660_6013_1 {
    int threshold;
    unsigned char calib;
    short reading;
    int buffer[3];
};

struct Transaction_R001660_6013_2 {
    short account_id;
    short rate;
    short fee;
    short status;
    unsigned char balance;
    int buffer[3];
};

struct EventLog_R001660_6013_3 {
    int seq;
    unsigned char timestamp;
    unsigned char signature;
    int severity;
    unsigned char code;
    int buffer[3];
};

union TelemetryField_R001660_6013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001660_6013_0(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001660_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int vector_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_90) & 63;
    acc ^= aux;
    int residue_55 = (aux + st.buffer[1]) & 3;
    switch (residue_55) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_39 = 0;
    for (int k = 0; k < 2; k++) {
        offset_39 = (offset_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_1(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_94 = local_arr[aux % 3];
    acc = (acc + metric_94 * 2) & 127;
    int stride_12 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_12 > 33) {
        acc = (acc + stride_12 * 2 + 5) & 127;
        aux ^= (stride_12 & 15);
    } else {
        acc = (acc - stride_12 + 11) & 127;
        aux += 3;
    }
    int phase_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001660_6013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_78 = (aux + st.buffer[1]) & 3;
    switch (parity_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_25 = (st.buffer[0] * 3 + aux) & 63;
    if (window_25 > 49) {
        acc = (acc + window_25 * 2 + 5) & 127;
        aux ^= (window_25 & 15);
    } else {
        acc = (acc - window_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_3(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001660_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int coefficient_64 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_64 > 27) {
        acc = (acc + coefficient_64 * 2 + 5) & 127;
        aux ^= (coefficient_64 & 15);
    } else {
        acc = (acc - coefficient_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_83 = local_arr[aux % 3];
    acc = (acc + mask_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001660_6013_4(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int mask_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_31) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_84 = local_arr[aux % 3];
    acc = (acc + pivot_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001660_6013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001660_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_33 = 0;
    for (int k = 0; k < 2; k++) {
        tally_33 = (tally_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_33) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001660_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int sample_76 = (aux + st.buffer[1]) & 3;
    switch (sample_76) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_74 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_74 = (tracker_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_74) & 127;
    }
    int damping_63 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_63 > 15) {
        acc = (acc + damping_63 * 2 + 5) & 127;
        aux ^= (damping_63 & 15);
    } else {
        acc = (acc - damping_63 + 11) & 127;
        aux += 3;
    }
    int quantum_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001660_6013_7(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001660_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_29 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_29 > 14) {
        acc = (acc + weight_29 * 2 + 5) & 127;
        aux ^= (weight_29 & 15);
    } else {
        acc = (acc - weight_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_84 = local_arr[aux % 3];
    acc = (acc + residue_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001660_6013_8(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int vector_79 = local_arr[aux % 3];
    acc = (acc + vector_79 * 2) & 127;
    int parity_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_90 = (aux + st.buffer[1]) & 3;
    switch (mask_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int threshold_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_77) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_47 = local_arr[aux % 3];
    acc = (acc + phase_47 * 2) & 127;
    int margin_38 = 0;
    for (int k = 0; k < 2; k++) {
        margin_38 = (margin_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_38) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001660_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_85 = (aux + st.buffer[1]) & 3;
    switch (weight_85) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_39 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_39 > 45) {
        acc = (acc + offset_39 * 2 + 5) & 127;
        aux ^= (offset_39 & 15);
    } else {
        acc = (acc - offset_39 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_99 = local_arr[aux % 3];
    acc = (acc + phase_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001660_6013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_40 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_40 > 38) {
        acc = (acc + offset_40 * 2 + 5) & 127;
        aux ^= (offset_40 & 15);
    } else {
        acc = (acc - offset_40 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_26 = local_arr[aux % 3];
    acc = (acc + tally_26 * 2) & 127;
    int pivot_42 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_42 = (pivot_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_12(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int stride_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_41 = local_arr[aux % 3];
    acc = (acc + threshold_41 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_65 = (aux + st.buffer[1]) & 3;
    switch (residue_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_13(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001660_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_23 = 0;
    for (int k = 0; k < 3; k++) {
        sample_23 = (sample_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_23) & 127;
    }
    int mask_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_16) & 63;
    acc ^= aux;
    int coefficient_87 = (aux + st.buffer[1]) & 3;
    switch (coefficient_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_14(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001660_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int vector_26 = 0;
    for (int k = 0; k < 2; k++) {
        vector_26 = (vector_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_26) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_27 = local_arr[aux % 3];
    acc = (acc + margin_27 * 2) & 127;
    int accumulator_76 = (aux + st.buffer[1]) & 3;
    switch (accumulator_76) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_15(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int vector_78 = 0;
    for (int k = 0; k < 2; k++) {
        vector_78 = (vector_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_78) & 127;
    }
    int tracker_22 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_22 > 14) {
        acc = (acc + tracker_22 * 2 + 5) & 127;
        aux ^= (tracker_22 & 15);
    } else {
        acc = (acc - tracker_22 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_74 = local_arr[aux % 3];
    acc = (acc + stride_74 * 2) & 127;
    int parity_54 = (aux + st.buffer[1]) & 3;
    switch (parity_54) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001660_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int anchor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_65) & 63;
    acc ^= aux;
    int cursor_24 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_24 = (cursor_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_24) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_16 = local_arr[aux % 3];
    acc = (acc + tally_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001660_6013_17(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001660_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int scale_48 = (aux + st.buffer[1]) & 3;
    switch (scale_48) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_71 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_71 = (checksum_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_71) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_19 = local_arr[aux % 3];
    acc = (acc + bound_19 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001660_6013_18(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001660_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_59 = (aux + st.buffer[1]) & 3;
    switch (coefficient_59) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_19(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001660_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int scale_68 = 0;
    for (int k = 0; k < 3; k++) {
        scale_68 = (scale_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_68) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_88 = local_arr[aux % 3];
    acc = (acc + bound_88 * 2) & 127;
    int mask_58 = (aux + st.buffer[1]) & 3;
    switch (mask_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001660_6013_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001660_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_27 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_27 > 20) {
        acc = (acc + delta_27 * 2 + 5) & 127;
        aux ^= (delta_27 & 15);
    } else {
        acc = (acc - delta_27 + 11) & 127;
        aux += 3;
    }
    int tally_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001660_6013_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001660_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_77 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_77 = (anchor_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_77) & 127;
    }
    int window_84 = (aux + st.buffer[1]) & 3;
    switch (window_84) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_54 = local_arr[aux % 3];
    acc = (acc + margin_54 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001660_0;
    int sec_r001660_1;
    int sec_r001660_2;
    int sec_r001660_3;
    int sec_r001660_4;
    int sec_r001660_5;
    int sec_r001660_6;
    int sec_r001660_7;
    int sec_r001660_8;
    int sec_r001660_9;
    int sec_r001660_10;
    int sec_r001660_11;
    int sec_r001660_12;
    int sec_r001660_13;
    int sec_r001660_14;
    int sec_r001660_15;
    int sec_r001660_16;
    int sec_r001660_17;
    int pub_r001660_0;
    int pub_r001660_1;
    int pub_r001660_2;
    int pub_r001660_3;
    int pub_r001660_4;
    int pub_r001660_5;
    int pub_r001660_6;
    int pub_r001660_7;
    int pub_r001660_8;
    int pub_r001660_9;
    int pub_r001660_10;
    int pub_r001660_11;
    int pub_r001660_12;
    int pub_r001660_13;
    int pub_r001660_14;
    int pub_r001660_15;
    int pub_r001660_16;
    int pub_r001660_17;
    int pub_r001660_18;
    int pub_r001660_19;
    int pub_r001660_20;
    int pub_r001660_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001660_0 >= -100 && pub_r001660_0 <= 100);
    __CPROVER_assume(pub_r001660_1 >= -100 && pub_r001660_1 <= 100);
    __CPROVER_assume(pub_r001660_2 >= -100 && pub_r001660_2 <= 100);
    __CPROVER_assume(pub_r001660_3 >= -100 && pub_r001660_3 <= 100);
    __CPROVER_assume(pub_r001660_4 >= -100 && pub_r001660_4 <= 100);
    __CPROVER_assume(pub_r001660_5 >= -100 && pub_r001660_5 <= 100);
    __CPROVER_assume(pub_r001660_6 >= -100 && pub_r001660_6 <= 100);
    __CPROVER_assume(pub_r001660_7 >= -100 && pub_r001660_7 <= 100);
    __CPROVER_assume(pub_r001660_8 >= -100 && pub_r001660_8 <= 100);
    __CPROVER_assume(pub_r001660_9 >= -100 && pub_r001660_9 <= 100);
    __CPROVER_assume(pub_r001660_10 >= -100 && pub_r001660_10 <= 100);
    __CPROVER_assume(pub_r001660_11 >= -100 && pub_r001660_11 <= 100);
    __CPROVER_assume(pub_r001660_12 >= -100 && pub_r001660_12 <= 100);
    __CPROVER_assume(pub_r001660_13 >= -100 && pub_r001660_13 <= 100);
    __CPROVER_assume(pub_r001660_14 >= -100 && pub_r001660_14 <= 100);
    __CPROVER_assume(pub_r001660_15 >= -100 && pub_r001660_15 <= 100);
    __CPROVER_assume(pub_r001660_16 >= -100 && pub_r001660_16 <= 100);
    __CPROVER_assume(pub_r001660_17 >= -100 && pub_r001660_17 <= 100);
    __CPROVER_assume(pub_r001660_18 >= -100 && pub_r001660_18 <= 100);
    __CPROVER_assume(pub_r001660_19 >= -100 && pub_r001660_19 <= 100);
    __CPROVER_assume(pub_r001660_20 >= -100 && pub_r001660_20 <= 100);
    __CPROVER_assume(pub_r001660_21 >= -100 && pub_r001660_21 <= 100);
    __CPROVER_assume(sec_r001660_0 >= 0 && sec_r001660_0 <= 255);
    __CPROVER_assume(sec_r001660_1 >= 0 && sec_r001660_1 <= 255);
    __CPROVER_assume(sec_r001660_2 >= 0 && sec_r001660_2 <= 255);
    __CPROVER_assume(sec_r001660_3 >= 0 && sec_r001660_3 <= 255);
    __CPROVER_assume(sec_r001660_4 >= 0 && sec_r001660_4 <= 255);
    __CPROVER_assume(sec_r001660_5 >= 0 && sec_r001660_5 <= 255);
    __CPROVER_assume(sec_r001660_6 >= 0 && sec_r001660_6 <= 255);
    __CPROVER_assume(sec_r001660_7 >= 0 && sec_r001660_7 <= 255);
    __CPROVER_assume(sec_r001660_8 >= 0 && sec_r001660_8 <= 255);
    __CPROVER_assume(sec_r001660_9 >= 0 && sec_r001660_9 <= 255);
    __CPROVER_assume(sec_r001660_10 >= 0 && sec_r001660_10 <= 255);
    __CPROVER_assume(sec_r001660_11 >= 0 && sec_r001660_11 <= 255);
    __CPROVER_assume(sec_r001660_12 >= 0 && sec_r001660_12 <= 255);
    __CPROVER_assume(sec_r001660_13 >= 0 && sec_r001660_13 <= 255);
    __CPROVER_assume(sec_r001660_14 >= 0 && sec_r001660_14 <= 255);
    __CPROVER_assume(sec_r001660_15 >= 0 && sec_r001660_15 <= 255);
    __CPROVER_assume(sec_r001660_16 >= 0 && sec_r001660_16 <= 255);
    __CPROVER_assume(sec_r001660_17 >= 0 && sec_r001660_17 <= 255);

    struct AudioFrame_R001660_6013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001660_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001660_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001660_0 + 7) & 15;
    struct SensorNode_R001660_6013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001660_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001660_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001660_0 + 9) & 15;
    struct Transaction_R001660_6013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001660_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001660_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001660_0 + 11) & 15;
    struct EventLog_R001660_6013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001660_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001660_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001660_0 + 13) & 15;

    union TelemetryField_R001660_6013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001660_6013_0(sec_r001660_0, sec_r001660_1, pub_r001660_2);
    int helper_flow_1 = fn_R001660_6013_1(sec_r001660_1, pub_r001660_2, pub_r001660_3);
    int helper_flow_2 = fn_R001660_6013_2(sec_r001660_2, pub_r001660_3, pub_r001660_4, pub_r001660_5, pub_r001660_6);
    int helper_flow_3 = fn_R001660_6013_3(sec_r001660_3, pub_r001660_4);
    int helper_flow_4 = fn_R001660_6013_4(sec_r001660_4, pub_r001660_5);
    int helper_flow_5 = fn_R001660_6013_5(sec_r001660_5, sec_r001660_6, pub_r001660_7, pub_r001660_8);
    int helper_flow_6 = fn_R001660_6013_6(sec_r001660_6, pub_r001660_7, pub_r001660_8, pub_r001660_9, pub_r001660_10);
    int helper_flow_7 = fn_R001660_6013_7(sec_r001660_7, pub_r001660_8);
    int helper_flow_8 = fn_R001660_6013_8(sec_r001660_8, pub_r001660_9, pub_r001660_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001660_8 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_0 > 41) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001660_12 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_1 > 36) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001660_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001660_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001660_20 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001660_16) & 127;
    if (stage_v_5 > 48) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001660_10 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_6 > 38) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001660_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001660_9 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_8 > 32) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_9 > 38) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001660_20) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001660_16) & 127;
    if (stage_v_11 > 27) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001660_0 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_12 > 26) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_13 > 27) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_14 > 20) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001660_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001660_14) & 127;
    if (stage_v_16 > 28) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001660_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_18 > 45) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001660_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_20 > 33) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_21 > 22) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001660_5 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_22 > 20) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_23 > 27) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001660_12 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_24 > 40) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001660_16) & 127;
    if (stage_v_25 > 42) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001660_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001660_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001660_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_29 > 41) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001660_9 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_30 > 50) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001660_12 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_31 > 24) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001660_14) & 127;
    if (stage_v_32 > 31) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001660_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_34 > 28) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001660_12 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_35 > 37) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_36 > 27) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001660_21 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001660_11 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_38 > 21) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001660_14) & 127;
    if (stage_v_39 > 48) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_40 > 40) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_41 > 31) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001660_2) & 127;
    if (stage_v_42 > 28) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001660_6 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_43 > 37) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001660_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_45 > 32) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_46 > 48) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_47 > 22) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_48 > 32) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001660_3 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_49 > 44) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_50 > 43) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001660_12 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_51 > 25) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_52 > 43) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001660_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_54 > 24) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_55 > 30) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_56 > 25) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_57 > 27) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_58 > 43) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_59 > 35) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001660_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_61 > 32) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001660_15 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_62 > 28) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_63 > 29) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001660_1) & 127;
    if (stage_v_64 > 36) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_65 > 20) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001660_13 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_66 > 49) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_67 > 44) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_68 > 23) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001660_21 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_70 > 29) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_71 > 30) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_72 > 39) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001660_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001660_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001660_20) & 127;
    if (stage_v_75 > 30) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001660_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001660_5 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_77 > 34) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001660_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001660_20) & 127;
    if (stage_v_79 > 42) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_80 > 39) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_81 > 45) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001660_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_83 > 38) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001660_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_85 > 29) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001660_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001660_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001660_13 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_88 > 28) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001660_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001660_7) & 127;
    if (stage_v_90 > 31) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001660_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_92 > 50) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_93 > 41) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001660_21 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_95 > 27) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001660_19) & 127;
    if (stage_v_96 > 36) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_97 > 21) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001660_0 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_98 > 38) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001660_1) & 127;
    if (stage_v_99 > 23) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_100 > 34) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001660_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_102 > 34) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_103 > 47) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001660_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001660_12 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_105 > 46) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_106 > 40) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_107 > 32) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_108 > 24) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_109 > 33) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_110 > 40) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001660_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_112 > 46) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001660_19) & 127;
    if (stage_v_113 > 47) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_114 > 21) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001660_2 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_115 > 43) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_116 > 42) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001660_1) & 127;
    if (stage_v_117 > 28) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_118 > 45) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_119 > 29) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001660_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_121 > 37) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_122 > 30) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_123 > 25) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001660_20) & 127;
    if (stage_v_124 > 34) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001660_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_126 > 49) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001660_19) & 127;
    if (stage_v_127 > 34) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_128 > 35) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_129 > 48) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001660_19) & 127;
    if (stage_v_130 > 21) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_131 > 29) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001660_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001660_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_134 > 39) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001660_7) & 127;
    if (stage_v_135 > 40) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001660_2) & 127;
    if (stage_v_136 > 36) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001660_14) & 127;
    if (stage_v_137 > 28) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001660_7) & 127;
    if (stage_v_138 > 50) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_139 > 40) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001660_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_141 > 42) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001660_19) & 127;
    if (stage_v_142 > 35) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001660_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_144 > 27) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_145 > 24) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_146 > 29) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_147 > 37) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_148 > 20) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_149 > 26) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001660_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001660_5 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_151 > 49) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001660_14 ^ 0x2A) * 2 + pub_r001660_20) & 127;
    if (stage_v_152 > 31) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001660_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_154 > 27) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_155 > 35) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001660_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001660_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r001660_17 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_158 > 36) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_159 > 26) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001660_15 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_160 > 32) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001660_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001660_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001660_17 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_164 > 21) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_165 > 33) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_166 > 46) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001660_2) & 127;
    if (stage_v_167 > 47) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001660_2) & 127;
    if (stage_v_168 > 20) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001660_20) & 127;
    if (stage_v_169 > 44) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_170 > 41) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_171 > 38) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_172 > 35) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_173 > 34) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_174 > 46) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001660_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001660_14) & 127;
    if (stage_v_176 > 48) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_177 > 48) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001660_21) & 127;
    if (stage_v_178 > 28) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001660_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001660_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001660_14) & 127;
    if (stage_v_181 > 21) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001660_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_183 > 26) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001660_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001660_6 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_185 > 47) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r001660_16 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_186 > 26) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_187 > 46) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001660_1) & 127;
    if (stage_v_188 > 50) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001660_17 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_189 > 35) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_190 > 23) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_191 > 27) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_192 > 35) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001660_21 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001660_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001660_8) & 127;
    if (stage_v_195 > 33) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_196 > 41) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001660_13) & 127;
    if (stage_v_197 > 45) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_198 > 24) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_199 > 38) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_200 > 38) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_201 > 43) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001660_19) & 127;
    if (stage_v_202 > 42) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001660_15) & 127;
    if (stage_v_203 > 45) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r001660_7 ^ 0x2A) * 2 + pub_r001660_7) & 127;
    if (stage_v_204 > 47) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001660_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_195 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_206 > 34) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001660_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001660_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001660_2) & 127;
    if (stage_v_209 > 30) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_210 > 44) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001660_7) & 127;
    if (stage_v_211 > 25) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001660_6) & 127;
    if (stage_v_212 > 50) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001660_5) & 127;
    if (stage_v_213 > 29) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001660_16) & 127;
    if (stage_v_214 > 42) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_215 > 37) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_216 > 21) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_149 ^ 0x2A) * 2 + pub_r001660_16) & 127;
    if (stage_v_217 > 41) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001660_18) & 127;
    if (stage_v_218 > 22) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_192 ^ 0x2A) * 2 + pub_r001660_7) & 127;
    if (stage_v_219 > 44) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001660_4) & 127;
    if (stage_v_220 > 41) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001660_9) & 127;
    if (stage_v_221 > 22) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001660_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001660_3 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_223 > 21) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_224 > 32) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001660_11) & 127;
    if (stage_v_225 > 50) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001660_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001660_10) & 127;
    if (stage_v_227 > 50) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001660_12) & 127;
    if (stage_v_228 > 30) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001660_17) & 127;
    if (stage_v_229 > 47) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_230 > 28) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001660_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_202 ^ 0x2A) * 2 + pub_r001660_3) & 127;
    if (stage_v_232 > 39) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_219 ^ 0x2A) * 2 + pub_r001660_0) & 127;
    if (stage_v_233 > 21) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001660_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
