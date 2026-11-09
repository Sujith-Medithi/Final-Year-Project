/*
 * Benchmark Program: R001880
 * Security Family: mixed_control_data
 * Generator Seed: 688013
 * High Inputs: 24 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001880_8013_0 {
    short mode;
    unsigned char gain_db;
    int prev_out;
    int buffer[3];
};

struct AudioFrame_R001880_8013_1 {
    short rms;
    short gain;
    short envelope;
    int channels;
    int buffer[3];
};

struct SensorNode_R001880_8013_2 {
    int threshold;
    int status;
    int gain;
    int buffer[3];
};

union TelemetryField_R001880_8013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001880_8013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001880_8013_0(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_32 = (aux + st.buffer[1]) & 3;
    switch (quotient_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_94 = 0;
    for (int k = 0; k < 3; k++) {
        offset_94 = (offset_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_1(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_73) & 63;
    acc ^= aux;
    int factor_36 = 0;
    for (int k = 0; k < 2; k++) {
        factor_36 = (factor_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_36) & 127;
    }
    int sample_80 = (aux + st.buffer[1]) & 3;
    switch (sample_80) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_2(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_13 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_13 > 46) {
        acc = (acc + sample_13 * 2 + 5) & 127;
        aux ^= (sample_13 & 15);
    } else {
        acc = (acc - sample_13 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_43 = (aux + st.buffer[1]) & 3;
    switch (checksum_43) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_23 = local_arr[aux % 3];
    acc = (acc + stride_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int coefficient_77 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_77 > 33) {
        acc = (acc + coefficient_77 * 2 + 5) & 127;
        aux ^= (coefficient_77 & 15);
    } else {
        acc = (acc - coefficient_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001880_8013_4(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_20 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_20 > 40) {
        acc = (acc + metric_20 * 2 + 5) & 127;
        aux ^= (metric_20 & 15);
    } else {
        acc = (acc - metric_20 + 11) & 127;
        aux += 3;
    }
    int damping_52 = (aux + st.buffer[1]) & 3;
    switch (damping_52) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_29 = local_arr[aux % 3];
    acc = (acc + scale_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_6(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_79 = (aux + st.buffer[1]) & 3;
    switch (coefficient_79) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_53 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_53 > 28) {
        acc = (acc + checksum_53 * 2 + 5) & 127;
        aux ^= (checksum_53 & 15);
    } else {
        acc = (acc - checksum_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int metric_30 = (aux + st.buffer[1]) & 3;
    switch (metric_30) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int cursor_21 = local_arr[aux % 3];
    acc = (acc + cursor_21 * 2) & 127;
    int phase_99 = 0;
    for (int k = 0; k < 2; k++) {
        phase_99 = (phase_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_9(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_22 = 0;
    for (int k = 0; k < 3; k++) {
        delta_22 = (delta_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_22) & 127;
    }
    int checksum_21 = (aux + st.buffer[1]) & 3;
    switch (checksum_21) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_10(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int coefficient_40 = (aux + st.buffer[1]) & 3;
    switch (coefficient_40) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_10 = local_arr[aux % 3];
    acc = (acc + quotient_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int tracker_36 = local_arr[aux % 3];
    acc = (acc + tracker_36 * 2) & 127;
    int sample_88 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_88 > 18) {
        acc = (acc + sample_88 * 2 + 5) & 127;
        aux ^= (sample_88 & 15);
    } else {
        acc = (acc - sample_88 + 11) & 127;
        aux += 3;
    }
    int weight_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001880_8013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int stride_40 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_40 > 12) {
        acc = (acc + stride_40 * 2 + 5) & 127;
        aux ^= (stride_40 & 15);
    } else {
        acc = (acc - stride_40 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_67 = local_arr[aux % 3];
    acc = (acc + stride_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_87 > 39) {
        acc = (acc + quantum_87 * 2 + 5) & 127;
        aux ^= (quantum_87 & 15);
    } else {
        acc = (acc - quantum_87 + 11) & 127;
        aux += 3;
    }
    int cursor_27 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_27 = (cursor_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_27) & 127;
    }
    int cursor_87 = (aux + st.buffer[1]) & 3;
    switch (cursor_87) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_14(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int anchor_15 = (aux + st.buffer[1]) & 3;
    switch (anchor_15) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_75 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_75 > 48) {
        acc = (acc + tally_75 * 2 + 5) & 127;
        aux ^= (tally_75 & 15);
    } else {
        acc = (acc - tally_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int index_reg_14 = (aux + st.buffer[1]) & 3;
    switch (index_reg_14) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_56) & 63;
    acc ^= aux;
    int quantum_37 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_37 > 31) {
        acc = (acc + quantum_37 * 2 + 5) & 127;
        aux ^= (quantum_37 & 15);
    } else {
        acc = (acc - quantum_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_65 = local_arr[aux % 3];
    acc = (acc + accumulator_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_16(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_72) & 63;
    acc ^= aux;
    int metric_35 = (aux + st.buffer[1]) & 3;
    switch (metric_35) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_98 = local_arr[aux % 3];
    acc = (acc + margin_98 * 2) & 127;
    int quantum_13 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_13 > 24) {
        acc = (acc + quantum_13 * 2 + 5) & 127;
        aux ^= (quantum_13 & 15);
    } else {
        acc = (acc - quantum_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_17(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int vector_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_53) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_16 = 0;
    for (int k = 0; k < 2; k++) {
        parity_16 = (parity_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_18(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_33 = 0;
    for (int k = 0; k < 3; k++) {
        mask_33 = (mask_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_33) & 127;
    }
    int margin_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_22) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_26 = local_arr[aux % 3];
    acc = (acc + parity_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_19(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int window_35 = 0;
    for (int k = 0; k < 2; k++) {
        window_35 = (window_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_35) & 127;
    }
    int window_14 = (st.buffer[0] * 3 + aux) & 63;
    if (window_14 > 43) {
        acc = (acc + window_14 * 2 + 5) & 127;
        aux ^= (window_14 & 15);
    } else {
        acc = (acc - window_14 + 11) & 127;
        aux += 3;
    }
    int cursor_15 = (aux + st.buffer[1]) & 3;
    switch (cursor_15) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int margin_41 = 0;
    for (int k = 0; k < 3; k++) {
        margin_41 = (margin_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_41) & 127;
    }
    int scale_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001880_8013_21(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001880_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_56 = 0;
    for (int k = 0; k < 3; k++) {
        scale_56 = (scale_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_56) & 127;
    }
    int scale_74 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_74 > 28) {
        acc = (acc + scale_74 * 2 + 5) & 127;
        aux ^= (scale_74 & 15);
    } else {
        acc = (acc - scale_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001880_8013_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001880_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int window_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001880_8013_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001880_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int delta_63 = 0;
    for (int k = 0; k < 3; k++) {
        delta_63 = (delta_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_63) & 127;
    }
    int weight_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_67 = local_arr[aux % 3];
    acc = (acc + factor_67 * 2) & 127;
    int tally_27 = (aux + st.buffer[1]) & 3;
    switch (tally_27) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001880_0;
    int sec_r001880_1;
    int sec_r001880_2;
    int sec_r001880_3;
    int sec_r001880_4;
    int sec_r001880_5;
    int sec_r001880_6;
    int sec_r001880_7;
    int sec_r001880_8;
    int sec_r001880_9;
    int sec_r001880_10;
    int sec_r001880_11;
    int sec_r001880_12;
    int sec_r001880_13;
    int sec_r001880_14;
    int sec_r001880_15;
    int sec_r001880_16;
    int sec_r001880_17;
    int sec_r001880_18;
    int sec_r001880_19;
    int sec_r001880_20;
    int sec_r001880_21;
    int sec_r001880_22;
    int sec_r001880_23;
    int pub_r001880_0;
    int pub_r001880_1;
    int pub_r001880_2;
    int pub_r001880_3;
    int pub_r001880_4;
    int pub_r001880_5;
    int pub_r001880_6;
    int pub_r001880_7;
    int pub_r001880_8;
    int pub_r001880_9;
    int pub_r001880_10;
    int pub_r001880_11;
    int pub_r001880_12;
    int pub_r001880_13;
    int pub_r001880_14;
    int pub_r001880_15;
    int pub_r001880_16;
    int pub_r001880_17;
    int pub_r001880_18;
    int pub_r001880_19;
    int pub_r001880_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001880_0 >= -100 && pub_r001880_0 <= 100);
    __CPROVER_assume(pub_r001880_1 >= -100 && pub_r001880_1 <= 100);
    __CPROVER_assume(pub_r001880_2 >= -100 && pub_r001880_2 <= 100);
    __CPROVER_assume(pub_r001880_3 >= -100 && pub_r001880_3 <= 100);
    __CPROVER_assume(pub_r001880_4 >= -100 && pub_r001880_4 <= 100);
    __CPROVER_assume(pub_r001880_5 >= -100 && pub_r001880_5 <= 100);
    __CPROVER_assume(pub_r001880_6 >= -100 && pub_r001880_6 <= 100);
    __CPROVER_assume(pub_r001880_7 >= -100 && pub_r001880_7 <= 100);
    __CPROVER_assume(pub_r001880_8 >= -100 && pub_r001880_8 <= 100);
    __CPROVER_assume(pub_r001880_9 >= -100 && pub_r001880_9 <= 100);
    __CPROVER_assume(pub_r001880_10 >= -100 && pub_r001880_10 <= 100);
    __CPROVER_assume(pub_r001880_11 >= -100 && pub_r001880_11 <= 100);
    __CPROVER_assume(pub_r001880_12 >= -100 && pub_r001880_12 <= 100);
    __CPROVER_assume(pub_r001880_13 >= -100 && pub_r001880_13 <= 100);
    __CPROVER_assume(pub_r001880_14 >= -100 && pub_r001880_14 <= 100);
    __CPROVER_assume(pub_r001880_15 >= -100 && pub_r001880_15 <= 100);
    __CPROVER_assume(pub_r001880_16 >= -100 && pub_r001880_16 <= 100);
    __CPROVER_assume(pub_r001880_17 >= -100 && pub_r001880_17 <= 100);
    __CPROVER_assume(pub_r001880_18 >= -100 && pub_r001880_18 <= 100);
    __CPROVER_assume(pub_r001880_19 >= -100 && pub_r001880_19 <= 100);
    __CPROVER_assume(pub_r001880_20 >= -100 && pub_r001880_20 <= 100);
    __CPROVER_assume(sec_r001880_0 >= 0 && sec_r001880_0 <= 255);
    __CPROVER_assume(sec_r001880_1 >= 0 && sec_r001880_1 <= 255);
    __CPROVER_assume(sec_r001880_2 >= 0 && sec_r001880_2 <= 255);
    __CPROVER_assume(sec_r001880_3 >= 0 && sec_r001880_3 <= 255);
    __CPROVER_assume(sec_r001880_4 >= 0 && sec_r001880_4 <= 255);
    __CPROVER_assume(sec_r001880_5 >= 0 && sec_r001880_5 <= 255);
    __CPROVER_assume(sec_r001880_6 >= 0 && sec_r001880_6 <= 255);
    __CPROVER_assume(sec_r001880_7 >= 0 && sec_r001880_7 <= 255);
    __CPROVER_assume(sec_r001880_8 >= 0 && sec_r001880_8 <= 255);
    __CPROVER_assume(sec_r001880_9 >= 0 && sec_r001880_9 <= 255);
    __CPROVER_assume(sec_r001880_10 >= 0 && sec_r001880_10 <= 255);
    __CPROVER_assume(sec_r001880_11 >= 0 && sec_r001880_11 <= 255);
    __CPROVER_assume(sec_r001880_12 >= 0 && sec_r001880_12 <= 255);
    __CPROVER_assume(sec_r001880_13 >= 0 && sec_r001880_13 <= 255);
    __CPROVER_assume(sec_r001880_14 >= 0 && sec_r001880_14 <= 255);
    __CPROVER_assume(sec_r001880_15 >= 0 && sec_r001880_15 <= 255);
    __CPROVER_assume(sec_r001880_16 >= 0 && sec_r001880_16 <= 255);
    __CPROVER_assume(sec_r001880_17 >= 0 && sec_r001880_17 <= 255);
    __CPROVER_assume(sec_r001880_18 >= 0 && sec_r001880_18 <= 255);
    __CPROVER_assume(sec_r001880_19 >= 0 && sec_r001880_19 <= 255);
    __CPROVER_assume(sec_r001880_20 >= 0 && sec_r001880_20 <= 255);
    __CPROVER_assume(sec_r001880_21 >= 0 && sec_r001880_21 <= 255);
    __CPROVER_assume(sec_r001880_22 >= 0 && sec_r001880_22 <= 255);
    __CPROVER_assume(sec_r001880_23 >= 0 && sec_r001880_23 <= 255);

    struct FilterState_R001880_8013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001880_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001880_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001880_0 + 7) & 15;
    struct AudioFrame_R001880_8013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001880_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001880_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001880_0 + 9) & 15;
    struct SensorNode_R001880_8013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001880_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001880_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001880_0 + 11) & 15;

    union TelemetryField_R001880_8013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001880_8013_0(sec_r001880_0, pub_r001880_1, pub_r001880_2);
    int helper_flow_1 = fn_R001880_8013_1(sec_r001880_1, sec_r001880_2);
    int helper_flow_2 = fn_R001880_8013_2(sec_r001880_2, sec_r001880_3);
    int helper_flow_3 = fn_R001880_8013_3(sec_r001880_3, pub_r001880_4, pub_r001880_5, pub_r001880_6, pub_r001880_7);
    int helper_flow_4 = fn_R001880_8013_4(sec_r001880_4, pub_r001880_5, pub_r001880_6);
    int helper_flow_5 = fn_R001880_8013_5(sec_r001880_5, sec_r001880_6, pub_r001880_7, pub_r001880_8);
    int helper_flow_6 = fn_R001880_8013_6(sec_r001880_6, sec_r001880_7);
    int helper_flow_7 = fn_R001880_8013_7(sec_r001880_7, pub_r001880_8, pub_r001880_9, pub_r001880_10);
    int helper_flow_8 = fn_R001880_8013_8(sec_r001880_8, sec_r001880_9, pub_r001880_10, pub_r001880_11);
    int helper_flow_9 = fn_R001880_8013_9(sec_r001880_9, pub_r001880_10);
    int helper_flow_10 = fn_R001880_8013_10(sec_r001880_10, sec_r001880_11);
    int helper_flow_11 = fn_R001880_8013_11(sec_r001880_11, pub_r001880_12, pub_r001880_13, pub_r001880_14, pub_r001880_15);
    int helper_flow_12 = fn_R001880_8013_12(sec_r001880_12, sec_r001880_13, pub_r001880_14, pub_r001880_15);
    int helper_flow_13 = fn_R001880_8013_13(sec_r001880_13, pub_r001880_14, pub_r001880_15, pub_r001880_16);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001880_19 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_0 > 42) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001880_15) & 127;
    if (stage_v_1 > 38) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_2 > 39) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001880_1 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_3 > 21) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_4 > 49) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001880_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_6 > 47) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_7 > 46) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001880_3 ^ 0x2A) * 2 + pub_r001880_8) & 127;
    if (stage_v_8 > 26) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001880_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001880_20 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_10 > 46) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001880_4 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_11 > 49) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001880_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001880_7 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_13 > 25) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_14 > 24) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001880_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_16 > 30) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001880_8 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_17 > 46) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001880_9 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_18 > 49) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001880_8 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_19 > 28) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001880_14) & 127;
    if (stage_v_20 > 43) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001880_15) & 127;
    if (stage_v_21 > 26) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001880_19 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001880_8) & 127;
    if (stage_v_23 > 33) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001880_13 ^ 0x2A) * 2 + pub_r001880_18) & 127;
    if (stage_v_24 > 30) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_25 > 24) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_26 > 40) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001880_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_28 > 41) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_29 > 24) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001880_15) & 127;
    if (stage_v_30 > 33) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001880_22 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_31 > 43) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001880_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001880_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001880_15 ^ 0x2A) * 2 + pub_r001880_1) & 127;
    if (stage_v_34 > 27) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_35 > 50) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001880_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_37 > 32) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_38 > 39) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001880_11 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_39 > 23) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001880_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001880_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001880_17 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_42 > 40) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001880_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001880_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001880_14) & 127;
    if (stage_v_45 > 37) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001880_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_47 > 26) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001880_7 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_48 > 46) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001880_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001880_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_51 > 40) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001880_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_53 > 38) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001880_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001880_2 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_55 > 23) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001880_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001880_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_58 > 26) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001880_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_60 > 30) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001880_15) & 127;
    if (stage_v_61 > 27) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_62 > 25) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_63 > 48) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_64 > 25) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_65 > 35) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_66 > 47) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_67 > 44) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_68 > 46) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_69 > 34) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001880_2) & 127;
    if (stage_v_70 > 47) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001880_8) & 127;
    if (stage_v_71 > 37) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001880_18 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_72 > 40) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001880_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_74 > 25) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001880_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001880_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001880_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001880_16 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_78 > 49) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_79 > 23) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_80 > 23) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001880_12) & 127;
    if (stage_v_81 > 21) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001880_12) & 127;
    if (stage_v_82 > 46) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001880_22 ^ 0x2A) * 2 + pub_r001880_1) & 127;
    if (stage_v_83 > 33) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001880_15) & 127;
    if (stage_v_84 > 31) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_85 > 40) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001880_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001880_13) & 127;
    if (stage_v_87 > 48) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001880_3 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_88 > 25) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001880_16 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_89 > 35) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_90 > 30) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_91 > 35) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001880_23 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_92 > 47) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001880_17 ^ 0x2A) * 2 + pub_r001880_12) & 127;
    if (stage_v_93 > 44) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001880_15 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_94 > 27) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_95 > 24) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_96 > 50) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_97 > 37) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_98 > 47) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001880_1 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_99 > 22) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_100 > 43) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_101 > 46) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_102 > 29) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001880_13) & 127;
    if (stage_v_103 > 38) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_104 > 47) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001880_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001880_1) & 127;
    if (stage_v_106 > 20) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_107 > 21) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r001880_10 ^ 0x2A) * 2 + pub_r001880_15) & 127;
    if (stage_v_108 > 48) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001880_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_110 > 47) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_111 > 22) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001880_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_113 > 42) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_114 > 45) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001880_12 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_115 > 26) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001880_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_117 > 50) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_118 > 44) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_119 > 42) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001880_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001880_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001880_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001880_20 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_124 > 38) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001880_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_126 > 44) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001880_8) & 127;
    if (stage_v_127 > 36) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001880_2) & 127;
    if (stage_v_128 > 37) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_129 > 39) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_130 > 33) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_131 > 48) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001880_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_133 > 33) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_134 > 24) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_135 > 40) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_136 > 44) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_137 > 34) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_138 > 48) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_139 > 33) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_140 > 24) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001880_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_142 > 32) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_143 > 24) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_144 > 27) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001880_14) & 127;
    if (stage_v_145 > 29) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001880_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_147 > 45) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001880_13) & 127;
    if (stage_v_148 > 24) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_149 > 27) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001880_7 ^ 0x2A) * 2 + pub_r001880_12) & 127;
    if (stage_v_150 > 39) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001880_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_152 > 33) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001880_8) & 127;
    if (stage_v_153 > 31) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_154 > 50) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001880_14) & 127;
    if (stage_v_155 > 35) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_156 > 48) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_157 > 25) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001880_13) & 127;
    if (stage_v_158 > 37) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001880_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_160 > 26) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001880_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001880_12) & 127;
    if (stage_v_162 > 25) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001880_18) & 127;
    if (stage_v_163 > 41) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001880_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_165 > 41) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_166 > 41) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_167 > 49) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_168 > 37) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_169 > 39) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r001880_20 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_170 > 21) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001880_16) & 127;
    if (stage_v_171 > 41) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001880_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_173 > 34) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001880_15 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_174 > 36) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001880_0) & 127;
    if (stage_v_175 > 42) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001880_2) & 127;
    if (stage_v_176 > 20) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001880_17) & 127;
    if (stage_v_177 > 22) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001880_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001880_19) & 127;
    if (stage_v_179 > 46) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_180 > 45) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_181 > 28) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_182 > 38) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001880_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_184 > 36) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001880_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001880_20) & 127;
    if (stage_v_186 > 26) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_187 > 46) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001880_6) & 127;
    if (stage_v_188 > 50) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001880_12) & 127;
    if (stage_v_189 > 37) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001880_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001880_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_180 ^ 0x2A) * 2 + pub_r001880_7) & 127;
    if (stage_v_192 > 45) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r001880_22 ^ 0x2A) * 2 + pub_r001880_18) & 127;
    if (stage_v_193 > 48) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001880_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001880_3) & 127;
    if (stage_v_195 > 22) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001880_14) & 127;
    if (stage_v_196 > 39) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_197 > 28) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001880_4) & 127;
    if (stage_v_198 > 40) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001880_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001880_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001880_10) & 127;
    if (stage_v_201 > 24) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001880_2) & 127;
    if (stage_v_202 > 20) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001880_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001880_11) & 127;
    if (stage_v_204 > 28) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001880_9) & 127;
    if (stage_v_205 > 38) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001880_5) & 127;
    if (stage_v_206 > 39) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
