/*
 * Benchmark Program: R001005
 * Security Family: bitwise_flow
 * Generator Seed: 600513
 * High Inputs: 19 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001005_513_0 {
    unsigned char severity;
    short code;
    int signature;
    short timestamp;
    int seq;
    short facility;
    int buffer[3];
};

struct FilterState_R001005_513_1 {
    short prev_in;
    short mode;
    short damping;
    int gain_db;
    int prev_out;
    unsigned char cutoff;
    int buffer[3];
};

struct DeviceConfig_R001005_513_2 {
    int parity;
    unsigned char baud_rate;
    short timeout;
    int id;
    int buffer[3];
};

union RegisterBank_R001005_513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001005_513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001005_513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int coefficient_50 = local_arr[aux % 3];
    acc = (acc + coefficient_50 * 2) & 127;
    int sample_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_46) & 63;
    acc ^= aux;
    int threshold_63 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_63 > 49) {
        acc = (acc + threshold_63 * 2 + 5) & 127;
        aux ^= (threshold_63 & 15);
    } else {
        acc = (acc - threshold_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_1(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_40 = 0;
    for (int k = 0; k < 3; k++) {
        damping_40 = (damping_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_40) & 127;
    }
    int residue_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001005_513_2(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_35 = (aux + st.buffer[1]) & 3;
    switch (tracker_35) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_20 = 0;
    for (int k = 0; k < 2; k++) {
        tally_20 = (tally_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_20) & 127;
    }
    int vector_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_91) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001005_513_3(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int index_reg_38 = local_arr[aux % 3];
    acc = (acc + index_reg_38 * 2) & 127;
    int mask_23 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_23 > 41) {
        acc = (acc + mask_23 * 2 + 5) & 127;
        aux ^= (mask_23 & 15);
    } else {
        acc = (acc - mask_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int segment_27 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_27 > 44) {
        acc = (acc + segment_27 * 2 + 5) & 127;
        aux ^= (segment_27 & 15);
    } else {
        acc = (acc - segment_27 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_55 = local_arr[aux % 3];
    acc = (acc + bound_55 * 2) & 127;
    int phase_14 = (aux + st.buffer[1]) & 3;
    switch (phase_14) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_90 = 0;
    for (int k = 0; k < 2; k++) {
        stride_90 = (stride_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_90) & 127;
    }
    int segment_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_61 = local_arr[aux % 3];
    acc = (acc + sample_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001005_513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_68) & 63;
    acc ^= aux;
    int metric_71 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_71 > 38) {
        acc = (acc + metric_71 * 2 + 5) & 127;
        aux ^= (metric_71 & 15);
    } else {
        acc = (acc - metric_71 + 11) & 127;
        aux += 3;
    }
    int quotient_31 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_31 = (quotient_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001005_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int bound_57 = local_arr[aux % 3];
    acc = (acc + bound_57 * 2) & 127;
    int window_37 = 0;
    for (int k = 0; k < 3; k++) {
        window_37 = (window_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_37) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int accumulator_21 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_21 > 11) {
        acc = (acc + accumulator_21 * 2 + 5) & 127;
        aux ^= (accumulator_21 & 15);
    } else {
        acc = (acc - accumulator_21 + 11) & 127;
        aux += 3;
    }
    int segment_80 = 0;
    for (int k = 0; k < 2; k++) {
        segment_80 = (segment_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_50 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_50 > 23) {
        acc = (acc + stride_50 * 2 + 5) & 127;
        aux ^= (stride_50 & 15);
    } else {
        acc = (acc - stride_50 + 11) & 127;
        aux += 3;
    }
    int accumulator_16 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_16 = (accumulator_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_10(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tally_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_65) & 63;
    acc ^= aux;
    int margin_86 = (aux + st.buffer[1]) & 3;
    switch (margin_86) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_13 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_13 > 22) {
        acc = (acc + coefficient_13 * 2 + 5) & 127;
        aux ^= (coefficient_13 & 15);
    } else {
        acc = (acc - coefficient_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_33 = local_arr[aux % 3];
    acc = (acc + sample_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001005_513_11(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_12 = (aux + st.buffer[1]) & 3;
    switch (anchor_12) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_12(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int metric_73 = 0;
    for (int k = 0; k < 3; k++) {
        metric_73 = (metric_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_73) & 127;
    }
    int quantum_47 = (aux + st.buffer[1]) & 3;
    switch (quantum_47) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_87 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_87 > 42) {
        acc = (acc + scale_87 * 2 + 5) & 127;
        aux ^= (scale_87 & 15);
    } else {
        acc = (acc - scale_87 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_14 = local_arr[aux % 3];
    acc = (acc + delta_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001005_513_13(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int residue_86 = (aux + st.buffer[1]) & 3;
    switch (residue_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001005_513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quantum_61 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_61 > 46) {
        acc = (acc + quantum_61 * 2 + 5) & 127;
        aux ^= (quantum_61 & 15);
    } else {
        acc = (acc - quantum_61 + 11) & 127;
        aux += 3;
    }
    int index_reg_23 = (aux + st.buffer[1]) & 3;
    switch (index_reg_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_76 = local_arr[aux % 3];
    acc = (acc + offset_76 * 2) & 127;
    int phase_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001005_513_15(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int bound_34 = (aux + st.buffer[1]) & 3;
    switch (bound_34) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_55 = 0;
    for (int k = 0; k < 3; k++) {
        bound_55 = (bound_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_55) & 127;
    }
    int stride_89 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_89 > 35) {
        acc = (acc + stride_89 * 2 + 5) & 127;
        aux ^= (stride_89 & 15);
    } else {
        acc = (acc - stride_89 + 11) & 127;
        aux += 3;
    }
    int anchor_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001005_513_16(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001005_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001005_513_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001005_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int delta_89 = local_arr[aux % 3];
    acc = (acc + delta_89 * 2) & 127;
    int quantum_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001005_513_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001005_513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_57 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_57 > 15) {
        acc = (acc + damping_57 * 2 + 5) & 127;
        aux ^= (damping_57 & 15);
    } else {
        acc = (acc - damping_57 + 11) & 127;
        aux += 3;
    }
    int coefficient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_52) & 63;
    acc ^= aux;
    int bound_35 = (aux + st.buffer[1]) & 3;
    switch (bound_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_17 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_17 = (tracker_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_17) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int phase_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_51) & 63;
    acc ^= aux;
    int checksum_80 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_80 = (checksum_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_80) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_32 = (aux + st.buffer[1]) & 3;
    switch (stride_32) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001005_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int anchor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_33 > 10) {
        acc = (acc + anchor_33 * 2 + 5) & 127;
        aux ^= (anchor_33 & 15);
    } else {
        acc = (acc - anchor_33 + 11) & 127;
        aux += 3;
    }
    int scale_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_14) & 63;
    acc ^= aux;
    int residue_73 = 0;
    for (int k = 0; k < 2; k++) {
        residue_73 = (residue_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_21(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001005_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_34 = 0;
    for (int k = 0; k < 3; k++) {
        stride_34 = (stride_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_34) & 127;
    }
    int damping_30 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_30 > 50) {
        acc = (acc + damping_30 * 2 + 5) & 127;
        aux ^= (damping_30 & 15);
    } else {
        acc = (acc - damping_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001005_513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_20 = (aux + st.buffer[1]) & 3;
    switch (metric_20) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_84 = local_arr[aux % 3];
    acc = (acc + parity_84 * 2) & 127;
    int segment_13 = 0;
    for (int k = 0; k < 3; k++) {
        segment_13 = (segment_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001005_513_23(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001005_513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int damping_35 = 0;
    for (int k = 0; k < 2; k++) {
        damping_35 = (damping_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_35) & 127;
    }
    int parity_43 = (aux + st.buffer[1]) & 3;
    switch (parity_43) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_59 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_59 > 18) {
        acc = (acc + stride_59 * 2 + 5) & 127;
        aux ^= (stride_59 & 15);
    } else {
        acc = (acc - stride_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001005_0;
    int sec_r001005_1;
    int sec_r001005_2;
    int sec_r001005_3;
    int sec_r001005_4;
    int sec_r001005_5;
    int sec_r001005_6;
    int sec_r001005_7;
    int sec_r001005_8;
    int sec_r001005_9;
    int sec_r001005_10;
    int sec_r001005_11;
    int sec_r001005_12;
    int sec_r001005_13;
    int sec_r001005_14;
    int sec_r001005_15;
    int sec_r001005_16;
    int sec_r001005_17;
    int sec_r001005_18;
    int pub_r001005_0;
    int pub_r001005_1;
    int pub_r001005_2;
    int pub_r001005_3;
    int pub_r001005_4;
    int pub_r001005_5;
    int pub_r001005_6;
    int pub_r001005_7;
    int pub_r001005_8;
    int pub_r001005_9;
    int pub_r001005_10;
    int pub_r001005_11;
    int pub_r001005_12;
    int pub_r001005_13;
    int pub_r001005_14;
    int pub_r001005_15;
    int pub_r001005_16;
    int pub_r001005_17;
    int pub_r001005_18;
    int pub_r001005_19;
    int pub_r001005_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001005_0 >= -100 && pub_r001005_0 <= 100);
    __CPROVER_assume(pub_r001005_1 >= -100 && pub_r001005_1 <= 100);
    __CPROVER_assume(pub_r001005_2 >= -100 && pub_r001005_2 <= 100);
    __CPROVER_assume(pub_r001005_3 >= -100 && pub_r001005_3 <= 100);
    __CPROVER_assume(pub_r001005_4 >= -100 && pub_r001005_4 <= 100);
    __CPROVER_assume(pub_r001005_5 >= -100 && pub_r001005_5 <= 100);
    __CPROVER_assume(pub_r001005_6 >= -100 && pub_r001005_6 <= 100);
    __CPROVER_assume(pub_r001005_7 >= -100 && pub_r001005_7 <= 100);
    __CPROVER_assume(pub_r001005_8 >= -100 && pub_r001005_8 <= 100);
    __CPROVER_assume(pub_r001005_9 >= -100 && pub_r001005_9 <= 100);
    __CPROVER_assume(pub_r001005_10 >= -100 && pub_r001005_10 <= 100);
    __CPROVER_assume(pub_r001005_11 >= -100 && pub_r001005_11 <= 100);
    __CPROVER_assume(pub_r001005_12 >= -100 && pub_r001005_12 <= 100);
    __CPROVER_assume(pub_r001005_13 >= -100 && pub_r001005_13 <= 100);
    __CPROVER_assume(pub_r001005_14 >= -100 && pub_r001005_14 <= 100);
    __CPROVER_assume(pub_r001005_15 >= -100 && pub_r001005_15 <= 100);
    __CPROVER_assume(pub_r001005_16 >= -100 && pub_r001005_16 <= 100);
    __CPROVER_assume(pub_r001005_17 >= -100 && pub_r001005_17 <= 100);
    __CPROVER_assume(pub_r001005_18 >= -100 && pub_r001005_18 <= 100);
    __CPROVER_assume(pub_r001005_19 >= -100 && pub_r001005_19 <= 100);
    __CPROVER_assume(pub_r001005_20 >= -100 && pub_r001005_20 <= 100);
    __CPROVER_assume(sec_r001005_0 >= 0 && sec_r001005_0 <= 255);
    __CPROVER_assume(sec_r001005_1 >= 0 && sec_r001005_1 <= 255);
    __CPROVER_assume(sec_r001005_2 >= 0 && sec_r001005_2 <= 255);
    __CPROVER_assume(sec_r001005_3 >= 0 && sec_r001005_3 <= 255);
    __CPROVER_assume(sec_r001005_4 >= 0 && sec_r001005_4 <= 255);
    __CPROVER_assume(sec_r001005_5 >= 0 && sec_r001005_5 <= 255);
    __CPROVER_assume(sec_r001005_6 >= 0 && sec_r001005_6 <= 255);
    __CPROVER_assume(sec_r001005_7 >= 0 && sec_r001005_7 <= 255);
    __CPROVER_assume(sec_r001005_8 >= 0 && sec_r001005_8 <= 255);
    __CPROVER_assume(sec_r001005_9 >= 0 && sec_r001005_9 <= 255);
    __CPROVER_assume(sec_r001005_10 >= 0 && sec_r001005_10 <= 255);
    __CPROVER_assume(sec_r001005_11 >= 0 && sec_r001005_11 <= 255);
    __CPROVER_assume(sec_r001005_12 >= 0 && sec_r001005_12 <= 255);
    __CPROVER_assume(sec_r001005_13 >= 0 && sec_r001005_13 <= 255);
    __CPROVER_assume(sec_r001005_14 >= 0 && sec_r001005_14 <= 255);
    __CPROVER_assume(sec_r001005_15 >= 0 && sec_r001005_15 <= 255);
    __CPROVER_assume(sec_r001005_16 >= 0 && sec_r001005_16 <= 255);
    __CPROVER_assume(sec_r001005_17 >= 0 && sec_r001005_17 <= 255);
    __CPROVER_assume(sec_r001005_18 >= 0 && sec_r001005_18 <= 255);

    struct EventLog_R001005_513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001005_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001005_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001005_0 + 7) & 15;
    struct FilterState_R001005_513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001005_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001005_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001005_0 + 9) & 15;
    struct DeviceConfig_R001005_513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001005_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001005_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001005_0 + 11) & 15;

    union RegisterBank_R001005_513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001005_513_0(sec_r001005_0, sec_r001005_1, pub_r001005_2, pub_r001005_3);
    int helper_flow_1 = fn_R001005_513_1(sec_r001005_1, sec_r001005_2, pub_r001005_3);
    int helper_flow_2 = fn_R001005_513_2(sec_r001005_2, pub_r001005_3);
    int helper_flow_3 = fn_R001005_513_3(sec_r001005_3, sec_r001005_4);
    int helper_flow_4 = fn_R001005_513_4(sec_r001005_4, pub_r001005_5, pub_r001005_6, pub_r001005_7, pub_r001005_8);
    int helper_flow_5 = fn_R001005_513_5(sec_r001005_5, sec_r001005_6, pub_r001005_7, pub_r001005_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001005_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001005_12 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001005_5 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001005_8 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001005_10 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001005_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((stage_v_2 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001005_17 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001005_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001005_4 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001005_18 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001005_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_2 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001005_7 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001005_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001005_1 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_1 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_15 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001005_10 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001005_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001005_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001005_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_6 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_4 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001005_13 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001005_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001005_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001005_13 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_7 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001005_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_9 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_18 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_2 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_4 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001005_16 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001005_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_12 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_1 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001005_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_16 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_37 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_23 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_33 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001005_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001005_18 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_4 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001005_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_31 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_7 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001005_2 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_2 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_40 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_9 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001005_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_18 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001005_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001005_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001005_18 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_17 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_0 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_0 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001005_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001005_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001005_6 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001005_2 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_2 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_59 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001005_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001005_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001005_12 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_18 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001005_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001005_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001005_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001005_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001005_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001005_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_34 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_5 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_22 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001005_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001005_18 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_47 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001005_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001005_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001005_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_7 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_1 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_54 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001005_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_0 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001005_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_27 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_32 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001005_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001005_2 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001005_1 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_10 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001005_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((helper_flow_3 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001005_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001005_8 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001005_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001005_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_60 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001005_20 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001005_12 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_23 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001005_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001005_3 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((helper_flow_3 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_99 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_44 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001005_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001005_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_9 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001005_4 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001005_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_86 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001005_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001005_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_44 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_32 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_1 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001005_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001005_20 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_12 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001005_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_27 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_88 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((helper_flow_1 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_66 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001005_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001005_19 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_111 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001005_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001005_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_99 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001005_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001005_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001005_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001005_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_27 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_122 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001005_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_130 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001005_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001005_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_15 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001005_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001005_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001005_7 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001005_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001005_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001005_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001005_11 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001005_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001005_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_143 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001005_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001005_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001005_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001005_17 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001005_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_12 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001005_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_142 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001005_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_64 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_137 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001005_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_36 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_169 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001005_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_164 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001005_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_9 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_162 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001005_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001005_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_90 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001005_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_176 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_121 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_78 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001005_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001005_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_27 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001005_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001005_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001005_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_96 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((helper_flow_3 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_187 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_23 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_191 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001005_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r001005_9 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r001005_1 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001005_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001005_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r001005_2 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r001005_10 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((helper_flow_4 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_28 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001005_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_130 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001005_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001005_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_206 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_194 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001005_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_13 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001005_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001005_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001005_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001005_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r001005_8 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_92 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_131 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_116 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_183 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_145 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_88 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_93 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_201 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_63 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001005_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001005_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001005_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001005_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001005_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_112 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_176 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_2 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_107 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001005_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001005_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_180 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_2 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_50 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001005_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_60 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_47 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_195 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001005_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((sec_r001005_1 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_42 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001005_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001005_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_222 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_172 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_182 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001005_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_79 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001005_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r001005_17 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r001005_18 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001005_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001005_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001005_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001005_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_77 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_168 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_64 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_104 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001005_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_87 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_221 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_121 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001005_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_54 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001005_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001005_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_63 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_97 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_24 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001005_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_47 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((helper_flow_4 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_23 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_264 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001005_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_18 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_268 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_187 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001005_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001005_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001005_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_225 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_177 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((sec_r001005_9 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001005_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001005_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r001005_0 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001005_7 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_23 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001005_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001005_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_37 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((helper_flow_4 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_271 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_54 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_82 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_263 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_290 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_143 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_107 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_16 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001005_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_250 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001005_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_86 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_60 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_23 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_202 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_116 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001005_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_101 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001005_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001005_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_116 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_312 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001005_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001005_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_322 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_302 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001005_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_279 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_224 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (pub_r001005_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_330) & 127;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001005_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001005_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001005_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001005_17 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001005_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001005_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_122 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001005_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_87 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_123 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_280 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_70 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_93 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_221 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_151 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_291 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001005_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_271 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001005_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001005_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_337 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_97 << 1) ^ (pub_r001005_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_274 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001005_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001005_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_203 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_294 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001005_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_321 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_79 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001005_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001005_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_172 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((sec_r001005_17 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_271 << 1) ^ (pub_r001005_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_174 << 1) ^ (pub_r001005_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001005_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001005_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_59 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = (pub_r001005_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_370) & 127;

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001005_20 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001005_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((sec_r001005_12 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001005_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_60 << 1) ^ (pub_r001005_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_250 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_4 << 1) ^ (pub_r001005_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_296 << 1) ^ (pub_r001005_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_148 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001005_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_168 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_251 << 1) ^ (pub_r001005_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001005_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_246 << 1) ^ (pub_r001005_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001005_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001005_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_281 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_3 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_4 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_60 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_233 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001005_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001005_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_263 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_12 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001005_17 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001005_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001005_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001005_20 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001005_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_31 << 1) ^ (pub_r001005_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_106 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_303 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001005_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_52 << 1) ^ (pub_r001005_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_126 << 1) ^ (pub_r001005_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001005_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_220 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_58 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((sec_r001005_5 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_33 << 1) ^ (pub_r001005_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_198 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001005_1 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_81 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_233 << 1) ^ (pub_r001005_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001005_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_325 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((sec_r001005_15 << 1) ^ (pub_r001005_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((sec_r001005_4 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_162 << 1) ^ (pub_r001005_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001005_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_10 << 1) ^ (pub_r001005_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001005_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_232 << 1) ^ (pub_r001005_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001005_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001005_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001005_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_240 << 1) ^ (pub_r001005_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_296 << 1) ^ (pub_r001005_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_6 << 1) ^ (pub_r001005_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_265 << 1) ^ (pub_r001005_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
