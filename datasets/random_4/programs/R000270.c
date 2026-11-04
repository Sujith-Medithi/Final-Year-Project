/*
 * Benchmark Program: R000270
 * Family: multi_step_explicit
 * Generator Seed: 429013
 * High Inputs: 17 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000270_9013_0 {
    short calib;
    unsigned char gain;
    int offset;
    int buffer[3];
};

struct FilterState_R000270_9013_1 {
    int damping;
    int cutoff;
    unsigned char prev_in;
    short mode;
    unsigned char prev_out;
    int gain_db;
    int buffer[3];
};

struct AudioFrame_R000270_9013_2 {
    unsigned char gain;
    unsigned char envelope;
    int sample_rate;
    unsigned char rms;
    int buffer[3];
};

union TelemetryField_R000270_9013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000270_9013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int window_77 = 0;
    for (int k = 0; k < 2; k++) {
        window_77 = (window_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_77) & 127;
    }
    int window_39 = (st.buffer[0] * 3 + aux) & 63;
    if (window_39 > 44) {
        acc = (acc + window_39 * 2 + 5) & 127;
        aux ^= (window_39 & 15);
    } else {
        acc = (acc - window_39 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_48 = local_arr[aux % 3];
    acc = (acc + mask_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000270_9013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum_57 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_57 = (quantum_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_57) & 127;
    }
    int metric_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_75) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_94 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_94 > 26) {
        acc = (acc + scale_94 * 2 + 5) & 127;
        aux ^= (scale_94 & 15);
    } else {
        acc = (acc - scale_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_2(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quotient_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_40) & 63;
    acc ^= aux;
    int mask_21 = 0;
    for (int k = 0; k < 2; k++) {
        mask_21 = (mask_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_53 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_53 > 39) {
        acc = (acc + margin_53 * 2 + 5) & 127;
        aux ^= (margin_53 & 15);
    } else {
        acc = (acc - margin_53 + 11) & 127;
        aux += 3;
    }
    int accumulator_45 = (aux + st.buffer[1]) & 3;
    switch (accumulator_45) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int sample_68 = local_arr[aux % 3];
    acc = (acc + sample_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000270_9013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int cursor_19 = local_arr[aux % 3];
    acc = (acc + cursor_19 * 2) & 127;
    int stride_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_15) & 63;
    acc ^= aux;
    int stride_68 = (aux + st.buffer[1]) & 3;
    switch (stride_68) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_20 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_20 = (quotient_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_20) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_6(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int metric_55 = local_arr[aux % 3];
    acc = (acc + metric_55 * 2) & 127;
    int segment_20 = (aux + st.buffer[1]) & 3;
    switch (segment_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_95 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_95 > 33) {
        acc = (acc + weight_95 * 2 + 5) & 127;
        aux ^= (weight_95 & 15);
    } else {
        acc = (acc - weight_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_7(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_43 = (aux + st.buffer[1]) & 3;
    switch (checksum_43) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_58 = 0;
    for (int k = 0; k < 2; k++) {
        scale_58 = (scale_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_8(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int parity_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_48) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000270_9013_9(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_39 = (aux + st.buffer[1]) & 3;
    switch (phase_39) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_71 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_71 > 44) {
        acc = (acc + offset_71 * 2 + 5) & 127;
        aux ^= (offset_71 & 15);
    } else {
        acc = (acc - offset_71 + 11) & 127;
        aux += 3;
    }
    int tracker_91 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_91 = (tracker_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_10(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int weight_91 = local_arr[aux % 3];
    acc = (acc + weight_91 * 2) & 127;
    int accumulator_77 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_77 > 24) {
        acc = (acc + accumulator_77 * 2 + 5) & 127;
        aux ^= (accumulator_77 & 15);
    } else {
        acc = (acc - accumulator_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000270_9013_11(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_98 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_98 > 33) {
        acc = (acc + parity_98 * 2 + 5) & 127;
        aux ^= (parity_98 & 15);
    } else {
        acc = (acc - parity_98 + 11) & 127;
        aux += 3;
    }
    int damping_36 = (aux + st.buffer[1]) & 3;
    switch (damping_36) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_98 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_98 = (checksum_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_98) & 127;
    }
    int weight_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000270_9013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_68 = (aux + st.buffer[1]) & 3;
    switch (factor_68) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_27 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_27 > 39) {
        acc = (acc + threshold_27 * 2 + 5) & 127;
        aux ^= (threshold_27 & 15);
    } else {
        acc = (acc - threshold_27 + 11) & 127;
        aux += 3;
    }
    int index_reg_69 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_69 = (index_reg_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_69) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_29 = local_arr[aux % 3];
    acc = (acc + damping_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000270_9013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_13 = (aux + st.buffer[1]) & 3;
    switch (bound_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_38 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_38 = (accumulator_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_38) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_14(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_22 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_22 > 19) {
        acc = (acc + tracker_22 * 2 + 5) & 127;
        aux ^= (tracker_22 & 15);
    } else {
        acc = (acc - tracker_22 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_25 = local_arr[aux % 3];
    acc = (acc + scale_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000270_9013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000270_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int anchor_84 = (aux + st.buffer[1]) & 3;
    switch (anchor_84) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_10) & 63;
    acc ^= aux;
    int sample_33 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_33 > 20) {
        acc = (acc + sample_33 * 2 + 5) & 127;
        aux ^= (sample_33 & 15);
    } else {
        acc = (acc - sample_33 + 11) & 127;
        aux += 3;
    }
    int stride_23 = 0;
    for (int k = 0; k < 2; k++) {
        stride_23 = (stride_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_23) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_16(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_40 = local_arr[aux % 3];
    acc = (acc + coefficient_40 * 2) & 127;
    int margin_73 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_73 > 46) {
        acc = (acc + margin_73 * 2 + 5) & 127;
        aux ^= (margin_73 & 15);
    } else {
        acc = (acc - margin_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_19 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_19 > 38) {
        acc = (acc + quantum_19 * 2 + 5) & 127;
        aux ^= (quantum_19 & 15);
    } else {
        acc = (acc - quantum_19 + 11) & 127;
        aux += 3;
    }
    int stride_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_27) & 63;
    acc ^= aux;
    int coefficient_39 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_39 = (coefficient_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_18(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_23 = (aux + st.buffer[1]) & 3;
    switch (quotient_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000270_9013_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int accumulator_76 = local_arr[aux % 3];
    acc = (acc + accumulator_76 * 2) & 127;
    int tracker_29 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_29 = (tracker_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_29) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000270_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tracker_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_38) & 63;
    acc ^= aux;
    int threshold_92 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_92 = (threshold_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_92) & 127;
    }
    int delta_74 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_74 > 43) {
        acc = (acc + delta_74 * 2 + 5) & 127;
        aux ^= (delta_74 & 15);
    } else {
        acc = (acc - delta_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_21(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quotient_71 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_71 > 24) {
        acc = (acc + quotient_71 * 2 + 5) & 127;
        aux ^= (quotient_71 & 15);
    } else {
        acc = (acc - quotient_71 + 11) & 127;
        aux += 3;
    }
    int parity_24 = 0;
    for (int k = 0; k < 2; k++) {
        parity_24 = (parity_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_24) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_79 = (aux + st.buffer[1]) & 3;
    switch (scale_79) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000270_9013_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000270_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_40 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_40 > 18) {
        acc = (acc + factor_40 * 2 + 5) & 127;
        aux ^= (factor_40 & 15);
    } else {
        acc = (acc - factor_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000270_0;
    int sec_r000270_1;
    int sec_r000270_2;
    int sec_r000270_3;
    int sec_r000270_4;
    int sec_r000270_5;
    int sec_r000270_6;
    int sec_r000270_7;
    int sec_r000270_8;
    int sec_r000270_9;
    int sec_r000270_10;
    int sec_r000270_11;
    int sec_r000270_12;
    int sec_r000270_13;
    int sec_r000270_14;
    int sec_r000270_15;
    int sec_r000270_16;
    int pub_r000270_0;
    int pub_r000270_1;
    int pub_r000270_2;
    int pub_r000270_3;
    int pub_r000270_4;
    int pub_r000270_5;
    int pub_r000270_6;
    int pub_r000270_7;
    int pub_r000270_8;
    int pub_r000270_9;
    int pub_r000270_10;
    int pub_r000270_11;
    int pub_r000270_12;
    int pub_r000270_13;
    int pub_r000270_14;
    int pub_r000270_15;
    int pub_r000270_16;
    int pub_r000270_17;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000270_0 >= -100 && pub_r000270_0 <= 100);
    __CPROVER_assume(pub_r000270_1 >= -100 && pub_r000270_1 <= 100);
    __CPROVER_assume(pub_r000270_2 >= -100 && pub_r000270_2 <= 100);
    __CPROVER_assume(pub_r000270_3 >= -100 && pub_r000270_3 <= 100);
    __CPROVER_assume(pub_r000270_4 >= -100 && pub_r000270_4 <= 100);
    __CPROVER_assume(pub_r000270_5 >= -100 && pub_r000270_5 <= 100);
    __CPROVER_assume(pub_r000270_6 >= -100 && pub_r000270_6 <= 100);
    __CPROVER_assume(pub_r000270_7 >= -100 && pub_r000270_7 <= 100);
    __CPROVER_assume(pub_r000270_8 >= -100 && pub_r000270_8 <= 100);
    __CPROVER_assume(pub_r000270_9 >= -100 && pub_r000270_9 <= 100);
    __CPROVER_assume(pub_r000270_10 >= -100 && pub_r000270_10 <= 100);
    __CPROVER_assume(pub_r000270_11 >= -100 && pub_r000270_11 <= 100);
    __CPROVER_assume(pub_r000270_12 >= -100 && pub_r000270_12 <= 100);
    __CPROVER_assume(pub_r000270_13 >= -100 && pub_r000270_13 <= 100);
    __CPROVER_assume(pub_r000270_14 >= -100 && pub_r000270_14 <= 100);
    __CPROVER_assume(pub_r000270_15 >= -100 && pub_r000270_15 <= 100);
    __CPROVER_assume(pub_r000270_16 >= -100 && pub_r000270_16 <= 100);
    __CPROVER_assume(pub_r000270_17 >= -100 && pub_r000270_17 <= 100);
    __CPROVER_assume(sec_r000270_0 >= 0 && sec_r000270_0 <= 255);
    __CPROVER_assume(sec_r000270_1 >= 0 && sec_r000270_1 <= 255);
    __CPROVER_assume(sec_r000270_2 >= 0 && sec_r000270_2 <= 255);
    __CPROVER_assume(sec_r000270_3 >= 0 && sec_r000270_3 <= 255);
    __CPROVER_assume(sec_r000270_4 >= 0 && sec_r000270_4 <= 255);
    __CPROVER_assume(sec_r000270_5 >= 0 && sec_r000270_5 <= 255);
    __CPROVER_assume(sec_r000270_6 >= 0 && sec_r000270_6 <= 255);
    __CPROVER_assume(sec_r000270_7 >= 0 && sec_r000270_7 <= 255);
    __CPROVER_assume(sec_r000270_8 >= 0 && sec_r000270_8 <= 255);
    __CPROVER_assume(sec_r000270_9 >= 0 && sec_r000270_9 <= 255);
    __CPROVER_assume(sec_r000270_10 >= 0 && sec_r000270_10 <= 255);
    __CPROVER_assume(sec_r000270_11 >= 0 && sec_r000270_11 <= 255);
    __CPROVER_assume(sec_r000270_12 >= 0 && sec_r000270_12 <= 255);
    __CPROVER_assume(sec_r000270_13 >= 0 && sec_r000270_13 <= 255);
    __CPROVER_assume(sec_r000270_14 >= 0 && sec_r000270_14 <= 255);
    __CPROVER_assume(sec_r000270_15 >= 0 && sec_r000270_15 <= 255);
    __CPROVER_assume(sec_r000270_16 >= 0 && sec_r000270_16 <= 255);

    struct SensorNode_R000270_9013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000270_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000270_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000270_0 + 7) & 15;
    struct FilterState_R000270_9013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000270_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000270_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000270_0 + 9) & 15;
    struct AudioFrame_R000270_9013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000270_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000270_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000270_0 + 11) & 15;

    union TelemetryField_R000270_9013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 11) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 26) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 11) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 26) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 37) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 52) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 24) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 39) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 29) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 44) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 17) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 32) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 11) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 26) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 16) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 31) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 28) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 43) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 33) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 48) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 13) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 28) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 22) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 37) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 64 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
        case 0:
            out_sink = (out_sink + 6) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 10) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 25) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] ^ 81) & 3;
    switch (stage_v_78) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (out_sink > 100) ? (chk_sum & 31) : (86 & 31);
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= (stage_v_81 << 1) & 127;

    /* Execution Pipeline Stage 82 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 27) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 42) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
        case 0:
            out_sink = (out_sink + 5) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = table[0];
    table[0] = (table[1] + 193) & 63;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 33) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 48) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_2.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 26) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 41) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] ^ 102) & 3;
    switch (stage_v_99) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 100 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 17) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 32) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_2.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 25) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 40) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 109) & 15;
    int stage_v_108 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= stage_v_108;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_110 = (stage_v_110 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_1.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 54) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 24) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 39) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = table[2];
    table[2] = (table[3] + 229) & 63;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_117 = (stage_v_117 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_1.buffer[0] ^ 121) & 3;
    switch (stage_v_118) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_122 = (stage_v_122 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 27) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 42) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_127 = (stage_v_127 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] * 2 + 394) & 63;
    if (stage_v_129 > 20) {
        out_sink = (out_sink + stage_v_129 - 5) & 255;
        if (stage_v_129 > 35) {
            chk_sum ^= (stage_v_129 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_129 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 17) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 32) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_135 = (stage_v_135 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_1.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 18) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 33) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_137 = (stage_v_137 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] ^ 141) & 3;
    switch (stage_v_138) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 141) & 15;
    int stage_v_140 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    chk_sum ^= stage_v_140;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_2.buffer[0] ^ 146) & 3;
    switch (stage_v_143) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_145 = (stage_v_145 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (out_sink > 100) ? (chk_sum & 31) : (151 & 31);
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= (stage_v_146 << 1) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 37) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 52) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 33) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 48) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 20) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 35) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (st_var_2.buffer[0] ^ 158) & 3;
    switch (stage_v_155) {
        case 0:
            out_sink = (out_sink + 2) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (out_sink > 100) ? (chk_sum & 31) : (161 & 31);
    out_sink = (out_sink + stage_v_156) & 255;
    chk_sum ^= (stage_v_156 << 1) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
        case 0:
            out_sink = (out_sink + 4) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 163 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (out_sink > 100) ? (chk_sum & 31) : (170 & 31);
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= (stage_v_165 << 1) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (out_sink > 100) ? (chk_sum & 31) : (173 & 31);
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= (stage_v_168 << 1) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = table[3];
    table[3] = (table[0] + 343) & 63;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = table[0];
    table[0] = (table[1] + 345) & 63;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_173 = (stage_v_173 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;

    /* Security Information Flow: Family = multi_step_explicit */
    int m_step_0 = (sec_r000270_8 + pub_r000270_16 + 9) & 127;
    int m_step_1 = (m_step_0 + pub_r000270_4 + 18) & 127;
    int m_step_2 = (m_step_1 + pub_r000270_7 + 10) & 127;
    int m_step_3 = (m_step_2 + pub_r000270_13 + 14) & 127;
    out_sink = (out_sink + m_step_3) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
