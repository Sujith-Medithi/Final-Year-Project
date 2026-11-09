/*
 * Benchmark Program: R001455
 * Security Family: bitwise_flow
 * Generator Seed: 645513
 * High Inputs: 20 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001455_5513_0 {
    int id;
    int parity;
    int port;
    int timeout;
    int baud_rate;
    int buffer[3];
};

struct StreamBuffer_R001455_5513_1 {
    unsigned char watermark;
    int state;
    int tail;
    int head;
    int buffer[3];
};

struct EventLog_R001455_5513_2 {
    int code;
    unsigned char timestamp;
    short severity;
    int signature;
    short facility;
    int buffer[3];
};

union TelemetryField_R001455_5513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001455_5513_0(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int threshold_81 = local_arr[aux % 3];
    acc = (acc + threshold_81 * 2) & 127;
    int scale_87 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_87 > 39) {
        acc = (acc + scale_87 * 2 + 5) & 127;
        aux ^= (scale_87 & 15);
    } else {
        acc = (acc - scale_87 + 11) & 127;
        aux += 3;
    }
    int quotient_45 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_45 = (quotient_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_45) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001455_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_83 = 0;
    for (int k = 0; k < 2; k++) {
        offset_83 = (offset_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_83) & 127;
    }
    int threshold_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_2(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int weight_22 = 0;
    for (int k = 0; k < 2; k++) {
        weight_22 = (weight_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_22) & 127;
    }
    int damping_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_93) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_37 = local_arr[aux % 3];
    acc = (acc + scale_37 * 2) & 127;
    int quotient_53 = (aux + st.buffer[1]) & 3;
    switch (quotient_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001455_5513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_88 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_88 = (quotient_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_88) & 127;
    }
    int residue_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_74 = 0;
    for (int k = 0; k < 3; k++) {
        sample_74 = (sample_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_74) & 127;
    }
    int vector_17 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_17 > 40) {
        acc = (acc + vector_17 * 2 + 5) & 127;
        aux ^= (vector_17 & 15);
    } else {
        acc = (acc - vector_17 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_5(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_98 = local_arr[aux % 3];
    acc = (acc + sample_98 * 2) & 127;
    int quotient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_6(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int index_reg_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_37) & 63;
    acc ^= aux;
    int margin_41 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_41 > 11) {
        acc = (acc + margin_41 * 2 + 5) & 127;
        aux ^= (margin_41 & 15);
    } else {
        acc = (acc - margin_41 + 11) & 127;
        aux += 3;
    }
    int stride_80 = (aux + st.buffer[1]) & 3;
    switch (stride_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_96 = 0;
    for (int k = 0; k < 3; k++) {
        phase_96 = (phase_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_96) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001455_5513_7(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_24 = 0;
    for (int k = 0; k < 2; k++) {
        scale_24 = (scale_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_24) & 127;
    }
    int coefficient_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_28) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_8(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001455_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int bound_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_61) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_46 = local_arr[aux % 3];
    acc = (acc + pivot_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_9(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001455_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_42 = (aux + st.buffer[1]) & 3;
    switch (checksum_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_71 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_71 > 49) {
        acc = (acc + vector_71 * 2 + 5) & 127;
        aux ^= (vector_71 & 15);
    } else {
        acc = (acc - vector_71 + 11) & 127;
        aux += 3;
    }
    int quantum_31 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_31 = (quantum_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_31) & 127;
    }
    int segment_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int damping_81 = (aux + st.buffer[1]) & 3;
    switch (damping_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_11(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quantum_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_22) & 63;
    acc ^= aux;
    int pivot_34 = (aux + st.buffer[1]) & 3;
    switch (pivot_34) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_43 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_43 = (accumulator_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_43) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001455_5513_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int weight_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_43) & 63;
    acc ^= aux;
    int threshold_90 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_90 = (threshold_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001455_5513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int margin_75 = 0;
    for (int k = 0; k < 2; k++) {
        margin_75 = (margin_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_75) & 127;
    }
    int vector_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int mask_29 = local_arr[aux % 3];
    acc = (acc + mask_29 * 2) & 127;
    int parity_39 = 0;
    for (int k = 0; k < 2; k++) {
        parity_39 = (parity_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_39) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_15(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_82 = (aux + st.buffer[1]) & 3;
    switch (cursor_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_65 = local_arr[aux % 3];
    acc = (acc + segment_65 * 2) & 127;
    int tally_86 = 0;
    for (int k = 0; k < 2; k++) {
        tally_86 = (tally_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_86) & 127;
    }
    int factor_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_16(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001455_5513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int sample_49 = 0;
    for (int k = 0; k < 2; k++) {
        sample_49 = (sample_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_49) & 127;
    }
    int weight_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_41) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_55 = local_arr[aux % 3];
    acc = (acc + bound_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_17(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_30 = (aux + st.buffer[1]) & 3;
    switch (threshold_30) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_36 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_36 = (cursor_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001455_5513_19(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int mask_52 = 0;
    for (int k = 0; k < 3; k++) {
        mask_52 = (mask_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_52) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_41 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_41 > 29) {
        acc = (acc + damping_41 * 2 + 5) & 127;
        aux ^= (damping_41 & 15);
    } else {
        acc = (acc - damping_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001455_5513_20(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int phase_78 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_78 > 32) {
        acc = (acc + phase_78 * 2 + 5) & 127;
        aux ^= (phase_78 & 15);
    } else {
        acc = (acc - phase_78 + 11) & 127;
        aux += 3;
    }
    int accumulator_16 = (aux + st.buffer[1]) & 3;
    switch (accumulator_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001455_5513_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001455_5513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_77 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_77 > 44) {
        acc = (acc + accumulator_77 * 2 + 5) & 127;
        aux ^= (accumulator_77 & 15);
    } else {
        acc = (acc - accumulator_77 + 11) & 127;
        aux += 3;
    }
    int tracker_69 = (aux + st.buffer[1]) & 3;
    switch (tracker_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001455_5513_22(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001455_5513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_71 = local_arr[aux % 3];
    acc = (acc + threshold_71 * 2) & 127;
    int mask_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_43) & 63;
    acc ^= aux;
    int delta_74 = (aux + st.buffer[1]) & 3;
    switch (delta_74) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001455_0;
    int sec_r001455_1;
    int sec_r001455_2;
    int sec_r001455_3;
    int sec_r001455_4;
    int sec_r001455_5;
    int sec_r001455_6;
    int sec_r001455_7;
    int sec_r001455_8;
    int sec_r001455_9;
    int sec_r001455_10;
    int sec_r001455_11;
    int sec_r001455_12;
    int sec_r001455_13;
    int sec_r001455_14;
    int sec_r001455_15;
    int sec_r001455_16;
    int sec_r001455_17;
    int sec_r001455_18;
    int sec_r001455_19;
    int pub_r001455_0;
    int pub_r001455_1;
    int pub_r001455_2;
    int pub_r001455_3;
    int pub_r001455_4;
    int pub_r001455_5;
    int pub_r001455_6;
    int pub_r001455_7;
    int pub_r001455_8;
    int pub_r001455_9;
    int pub_r001455_10;
    int pub_r001455_11;
    int pub_r001455_12;
    int pub_r001455_13;
    int pub_r001455_14;
    int pub_r001455_15;
    int pub_r001455_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001455_0 >= -100 && pub_r001455_0 <= 100);
    __CPROVER_assume(pub_r001455_1 >= -100 && pub_r001455_1 <= 100);
    __CPROVER_assume(pub_r001455_2 >= -100 && pub_r001455_2 <= 100);
    __CPROVER_assume(pub_r001455_3 >= -100 && pub_r001455_3 <= 100);
    __CPROVER_assume(pub_r001455_4 >= -100 && pub_r001455_4 <= 100);
    __CPROVER_assume(pub_r001455_5 >= -100 && pub_r001455_5 <= 100);
    __CPROVER_assume(pub_r001455_6 >= -100 && pub_r001455_6 <= 100);
    __CPROVER_assume(pub_r001455_7 >= -100 && pub_r001455_7 <= 100);
    __CPROVER_assume(pub_r001455_8 >= -100 && pub_r001455_8 <= 100);
    __CPROVER_assume(pub_r001455_9 >= -100 && pub_r001455_9 <= 100);
    __CPROVER_assume(pub_r001455_10 >= -100 && pub_r001455_10 <= 100);
    __CPROVER_assume(pub_r001455_11 >= -100 && pub_r001455_11 <= 100);
    __CPROVER_assume(pub_r001455_12 >= -100 && pub_r001455_12 <= 100);
    __CPROVER_assume(pub_r001455_13 >= -100 && pub_r001455_13 <= 100);
    __CPROVER_assume(pub_r001455_14 >= -100 && pub_r001455_14 <= 100);
    __CPROVER_assume(pub_r001455_15 >= -100 && pub_r001455_15 <= 100);
    __CPROVER_assume(pub_r001455_16 >= -100 && pub_r001455_16 <= 100);
    __CPROVER_assume(sec_r001455_0 >= 0 && sec_r001455_0 <= 255);
    __CPROVER_assume(sec_r001455_1 >= 0 && sec_r001455_1 <= 255);
    __CPROVER_assume(sec_r001455_2 >= 0 && sec_r001455_2 <= 255);
    __CPROVER_assume(sec_r001455_3 >= 0 && sec_r001455_3 <= 255);
    __CPROVER_assume(sec_r001455_4 >= 0 && sec_r001455_4 <= 255);
    __CPROVER_assume(sec_r001455_5 >= 0 && sec_r001455_5 <= 255);
    __CPROVER_assume(sec_r001455_6 >= 0 && sec_r001455_6 <= 255);
    __CPROVER_assume(sec_r001455_7 >= 0 && sec_r001455_7 <= 255);
    __CPROVER_assume(sec_r001455_8 >= 0 && sec_r001455_8 <= 255);
    __CPROVER_assume(sec_r001455_9 >= 0 && sec_r001455_9 <= 255);
    __CPROVER_assume(sec_r001455_10 >= 0 && sec_r001455_10 <= 255);
    __CPROVER_assume(sec_r001455_11 >= 0 && sec_r001455_11 <= 255);
    __CPROVER_assume(sec_r001455_12 >= 0 && sec_r001455_12 <= 255);
    __CPROVER_assume(sec_r001455_13 >= 0 && sec_r001455_13 <= 255);
    __CPROVER_assume(sec_r001455_14 >= 0 && sec_r001455_14 <= 255);
    __CPROVER_assume(sec_r001455_15 >= 0 && sec_r001455_15 <= 255);
    __CPROVER_assume(sec_r001455_16 >= 0 && sec_r001455_16 <= 255);
    __CPROVER_assume(sec_r001455_17 >= 0 && sec_r001455_17 <= 255);
    __CPROVER_assume(sec_r001455_18 >= 0 && sec_r001455_18 <= 255);
    __CPROVER_assume(sec_r001455_19 >= 0 && sec_r001455_19 <= 255);

    struct DeviceConfig_R001455_5513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001455_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001455_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001455_0 + 7) & 15;
    struct StreamBuffer_R001455_5513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001455_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001455_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001455_0 + 9) & 15;
    struct EventLog_R001455_5513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001455_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001455_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001455_0 + 11) & 15;

    union TelemetryField_R001455_5513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001455_5513_0(sec_r001455_0, pub_r001455_1);
    int helper_flow_1 = fn_R001455_5513_1(sec_r001455_1, pub_r001455_2, pub_r001455_3, pub_r001455_4);
    int helper_flow_2 = fn_R001455_5513_2(sec_r001455_2, sec_r001455_3, pub_r001455_4);
    int helper_flow_3 = fn_R001455_5513_3(sec_r001455_3, pub_r001455_4, pub_r001455_5, pub_r001455_6, pub_r001455_7);
    int helper_flow_4 = fn_R001455_5513_4(sec_r001455_4, pub_r001455_5, pub_r001455_6, pub_r001455_7);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001455_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001455_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001455_18 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001455_1 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001455_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001455_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001455_3 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_6 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001455_17 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001455_5 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001455_0 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001455_6 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001455_9 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001455_13 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001455_10 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001455_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001455_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001455_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001455_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001455_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001455_3 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001455_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001455_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001455_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001455_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001455_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001455_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_7 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_4 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_7 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001455_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_9 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001455_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_20 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_31 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001455_18 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001455_10 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001455_11 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_2 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001455_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_4 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001455_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001455_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001455_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001455_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001455_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001455_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001455_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001455_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001455_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_7 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001455_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001455_1 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001455_2 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_10 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001455_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001455_8 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_0 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001455_8 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_11 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001455_13 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_14 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_53 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_59 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_56 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001455_7 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_52 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_14 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_67 + 1) & 15;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_20 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001455_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_50 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001455_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_12 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001455_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_52 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_31 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001455_16 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_27 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001455_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_29 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_34 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r001455_1 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_63 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_61 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_54 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_35 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001455_9 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001455_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001455_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001455_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001455_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((helper_flow_2 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_83 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_82 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001455_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001455_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001455_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_50 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_68 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_74 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001455_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001455_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001455_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_35 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001455_16 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001455_7 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_52 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_3 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001455_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001455_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r001455_15 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r001455_19 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r001455_5 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_52 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001455_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001455_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_13 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_38 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001455_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001455_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_31 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r001455_11 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_85 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001455_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_60 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001455_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001455_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001455_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_99 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001455_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_63 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_99 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001455_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001455_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001455_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_6 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_3 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_63 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_91 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_138 + 1) & 15;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_53 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_2 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_107 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001455_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001455_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_12 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_98 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_144 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001455_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_112 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001455_16 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((helper_flow_4 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_11 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_146 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001455_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_63 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_138 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001455_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_116 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_144 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r001455_1 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_72 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_110 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_10 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001455_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_116 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001455_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_59 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_107 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_158 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_161 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_135 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001455_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001455_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001455_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_111 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001455_7 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001455_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001455_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001455_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_77 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((helper_flow_3 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001455_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_66 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_2 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_150 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_160 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001455_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001455_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001455_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001455_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001455_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001455_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001455_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_59 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001455_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001455_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_80 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_141 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001455_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001455_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001455_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_149 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_14 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001455_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_184 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001455_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001455_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_74 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_161 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001455_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_59 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001455_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_111 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001455_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_170 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_135 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_29 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001455_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001455_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001455_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r001455_12 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_1 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_9 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001455_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_103 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_64 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001455_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001455_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001455_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001455_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_210 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_152 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001455_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001455_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001455_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r001455_8 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((helper_flow_0 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_136 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_237 + 1) & 15;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001455_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_72 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001455_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_185 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001455_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_31 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_182 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001455_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_105 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_61 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001455_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_35 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_249 + 1) & 15;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001455_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001455_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_244 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_111 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_237 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001455_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_116 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001455_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001455_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001455_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001455_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001455_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001455_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((helper_flow_3 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001455_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_121 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_13 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001455_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001455_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_37 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_97 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((helper_flow_1 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_159 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_243 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001455_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((sec_r001455_15 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (pub_r001455_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_276) & 127;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001455_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r001455_13 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001455_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_202 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001455_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_235 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_275 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_221 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001455_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_170 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001455_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001455_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_67 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001455_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_166 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_159 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_145 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_252 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001455_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_84 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001455_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001455_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_254 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_154 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001455_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001455_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (pub_r001455_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_303) & 127;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001455_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_2 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001455_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001455_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_160 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_144 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_293 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_75 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_77 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_193 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_38 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((sec_r001455_3 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_243 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001455_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001455_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_162 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_247 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001455_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_70 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_266 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((helper_flow_0 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001455_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_40 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_122 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_85 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001455_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_204 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001455_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001455_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_319 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001455_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001455_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_269 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001455_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001455_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_313 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_309 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001455_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_105 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001455_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001455_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_91 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_27 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_81 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_300 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_67 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_137 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_291 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_212 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001455_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001455_1 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_351 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (pub_r001455_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_356) & 127;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001455_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001455_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001455_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_31 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001455_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001455_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_52 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_291 << 1) ^ (pub_r001455_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_75 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_136 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001455_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001455_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001455_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_363 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_76 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_330 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001455_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_363 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001455_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001455_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_2 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001455_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_122 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((stage_v_145 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001455_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001455_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001455_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((sec_r001455_9 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001455_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_149 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001455_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001455_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = (pub_r001455_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_389) & 127;

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_36 << 1) ^ (pub_r001455_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001455_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001455_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_327 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001455_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001455_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_328 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_309 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001455_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_8 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001455_1 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_135 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_175 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001455_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001455_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_339 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001455_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001455_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_2 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_53 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001455_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001455_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001455_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_201 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001455_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_76 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_60 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001455_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = (pub_r001455_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_418) & 127;

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_315 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = (pub_r001455_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_420) & 127;

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001455_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001455_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_139 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001455_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001455_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001455_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_320 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001455_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_86 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001455_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001455_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001455_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001455_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_146 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_323 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_135 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_92 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001455_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_216 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001455_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001455_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_185 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = (pub_r001455_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_443) & 127;

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_278 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001455_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001455_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001455_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_76 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_282 << 1) ^ (pub_r001455_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_449 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001455_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001455_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_174 << 1) ^ (pub_r001455_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_453 + 1) & 15;
    out_sink ^= (stage_v_453 & 63);

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001455_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((sec_r001455_11 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_455 + 1) & 15;
    out_sink ^= (stage_v_455 & 63);

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_107 << 1) ^ (pub_r001455_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_456 + 1) & 15;
    out_sink ^= (stage_v_456 & 63);

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001455_14 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001455_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001455_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = (pub_r001455_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_460) & 127;

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001455_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_293 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001455_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_241 << 1) ^ (pub_r001455_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_464 + 1) & 15;
    out_sink ^= (stage_v_464 & 63);

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001455_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_160 << 1) ^ (pub_r001455_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_466 + 1) & 15;
    out_sink ^= (stage_v_466 & 63);

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = (pub_r001455_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_467) & 127;

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_464 << 1) ^ (pub_r001455_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001455_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001455_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = ((stage_v_14 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_471 + 1) & 15;
    out_sink ^= (stage_v_471 & 63);

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_305 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_75 << 1) ^ (pub_r001455_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_473 + 1) & 15;
    out_sink ^= (stage_v_473 & 63);

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_221 << 1) ^ (pub_r001455_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_474 + 1) & 15;
    out_sink ^= (stage_v_474 & 63);

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = (pub_r001455_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_475) & 127;

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001455_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001455_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = (pub_r001455_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_478) & 127;

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = (pub_r001455_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_479) & 127;

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = ((stage_v_336 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_480 + 1) & 15;
    out_sink ^= (stage_v_480 & 63);

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = ((stage_v_471 << 1) ^ (pub_r001455_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_481 + 1) & 15;
    out_sink ^= (stage_v_481 & 63);

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = (pub_r001455_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_482) & 127;

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001455_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001455_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = ((stage_v_145 << 1) ^ (pub_r001455_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_485 + 1) & 15;
    out_sink ^= (stage_v_485 & 63);

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = ((stage_v_50 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_486 + 1) & 15;
    out_sink ^= (stage_v_486 & 63);

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = ((stage_v_63 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_487 + 1) & 15;
    out_sink ^= (stage_v_487 & 63);

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = (pub_r001455_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_488) & 127;

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = ((stage_v_282 << 1) ^ (pub_r001455_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_489 + 1) & 15;
    out_sink ^= (stage_v_489 & 63);

    /* Execution Pipeline Stage 490 */
    int stage_v_490 = ((stage_v_419 << 1) ^ (pub_r001455_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_490 + 1) & 15;
    out_sink ^= (stage_v_490 & 63);

    /* Execution Pipeline Stage 491 */
    int stage_v_491 = (pub_r001455_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_491) & 127;

    /* Execution Pipeline Stage 492 */
    int stage_v_492 = ((stage_v_135 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_492 + 1) & 15;
    out_sink ^= (stage_v_492 & 63);

    /* Execution Pipeline Stage 493 */
    int stage_v_493 = ((stage_v_135 << 1) ^ (pub_r001455_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_493 + 1) & 15;
    out_sink ^= (stage_v_493 & 63);

    /* Execution Pipeline Stage 494 */
    int stage_v_494 = ((stage_v_282 << 1) ^ (pub_r001455_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_494 + 1) & 15;
    out_sink ^= (stage_v_494 & 63);

    /* Execution Pipeline Stage 495 */
    int stage_v_495 = ((stage_v_280 << 1) ^ (pub_r001455_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_495 + 1) & 15;
    out_sink ^= (stage_v_495 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
