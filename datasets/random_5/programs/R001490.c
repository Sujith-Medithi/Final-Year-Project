/*
 * Benchmark Program: R001490
 * Security Family: mixed_control_data
 * Generator Seed: 649013
 * High Inputs: 17 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001490_9013_0 {
    int rate;
    short auth_code;
    int status;
    int buffer[3];
};

struct SensorNode_R001490_9013_1 {
    int status;
    int calib;
    int gain;
    int buffer[3];
};

union ColorPixel_R001490_9013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001490_9013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_45 = 0;
    for (int k = 0; k < 3; k++) {
        sample_45 = (sample_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_45) & 127;
    }
    int damping_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_81) & 63;
    acc ^= aux;
    int quotient_48 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_48 > 50) {
        acc = (acc + quotient_48 * 2 + 5) & 127;
        aux ^= (quotient_48 & 15);
    } else {
        acc = (acc - quotient_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_19 = 0;
    for (int k = 0; k < 2; k++) {
        margin_19 = (margin_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_19) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001490_9013_2(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001490_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int bound_99 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_99 > 30) {
        acc = (acc + bound_99 * 2 + 5) & 127;
        aux ^= (bound_99 & 15);
    } else {
        acc = (acc - bound_99 + 11) & 127;
        aux += 3;
    }
    int margin_63 = 0;
    for (int k = 0; k < 2; k++) {
        margin_63 = (margin_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_63) & 127;
    }
    int stride_44 = (aux + st.buffer[1]) & 3;
    switch (stride_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001490_9013_3(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int accumulator_46 = local_arr[aux % 3];
    acc = (acc + accumulator_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001490_9013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001490_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_14 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_14 > 49) {
        acc = (acc + parity_14 * 2 + 5) & 127;
        aux ^= (parity_14 & 15);
    } else {
        acc = (acc - parity_14 + 11) & 127;
        aux += 3;
    }
    int cursor_40 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_40 = (cursor_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_40) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_87 = local_arr[aux % 3];
    acc = (acc + index_reg_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001490_9013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_67 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_67 = (quotient_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_67) & 127;
    }
    int stride_11 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_11 > 11) {
        acc = (acc + stride_11 * 2 + 5) & 127;
        aux ^= (stride_11 & 15);
    } else {
        acc = (acc - stride_11 + 11) & 127;
        aux += 3;
    }
    int phase_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001490_9013_6(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_93 = (aux + st.buffer[1]) & 3;
    switch (anchor_93) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_84) & 63;
    acc ^= aux;
    int quotient_98 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_98 = (quotient_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_98) & 127;
    }
    int coefficient_82 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_82 > 49) {
        acc = (acc + coefficient_82 * 2 + 5) & 127;
        aux ^= (coefficient_82 & 15);
    } else {
        acc = (acc - coefficient_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_7(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_73 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_73 > 34) {
        acc = (acc + metric_73 * 2 + 5) & 127;
        aux ^= (metric_73 & 15);
    } else {
        acc = (acc - metric_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int quotient_12 = local_arr[aux % 3];
    acc = (acc + quotient_12 * 2) & 127;
    int sample_33 = (aux + st.buffer[1]) & 3;
    switch (sample_33) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_40 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_40 > 50) {
        acc = (acc + parity_40 * 2 + 5) & 127;
        aux ^= (parity_40 & 15);
    } else {
        acc = (acc - parity_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_9(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_49) & 63;
    acc ^= aux;
    int tracker_88 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_88 = (tracker_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_88) & 127;
    }
    int quantum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_79 > 14) {
        acc = (acc + quantum_79 * 2 + 5) & 127;
        aux ^= (quantum_79 & 15);
    } else {
        acc = (acc - quantum_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int metric_49 = (aux + st.buffer[1]) & 3;
    switch (metric_49) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_79 = local_arr[aux % 3];
    acc = (acc + metric_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001490_9013_11(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_79 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_79 = (checksum_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_79) & 127;
    }
    int quotient_99 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_99 > 41) {
        acc = (acc + quotient_99 * 2 + 5) & 127;
        aux ^= (quotient_99 & 15);
    } else {
        acc = (acc - quotient_99 + 11) & 127;
        aux += 3;
    }
    int mask_86 = (aux + st.buffer[1]) & 3;
    switch (mask_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_12(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_11 = (aux + st.buffer[1]) & 3;
    switch (vector_11) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int cursor_75 = local_arr[aux % 3];
    acc = (acc + cursor_75 * 2) & 127;
    int cursor_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_44) & 63;
    acc ^= aux;
    int window_24 = (st.buffer[0] * 3 + aux) & 63;
    if (window_24 > 36) {
        acc = (acc + window_24 * 2 + 5) & 127;
        aux ^= (window_24 & 15);
    } else {
        acc = (acc - window_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_14(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_14 = 0;
    for (int k = 0; k < 2; k++) {
        window_14 = (window_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_14) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_15(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int factor_44 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_44 > 32) {
        acc = (acc + factor_44 * 2 + 5) & 127;
        aux ^= (factor_44 & 15);
    } else {
        acc = (acc - factor_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_80 = local_arr[aux % 3];
    acc = (acc + segment_80 * 2) & 127;
    int accumulator_29 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_29 = (accumulator_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_29) & 127;
    }
    int window_67 = (aux + st.buffer[1]) & 3;
    switch (window_67) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001490_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_12 = (aux + st.buffer[1]) & 3;
    switch (quantum_12) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001490_9013_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int cursor_86 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_86 > 36) {
        acc = (acc + cursor_86 * 2 + 5) & 127;
        aux ^= (cursor_86 & 15);
    } else {
        acc = (acc - cursor_86 + 11) & 127;
        aux += 3;
    }
    int phase_19 = 0;
    for (int k = 0; k < 3; k++) {
        phase_19 = (phase_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_19) & 127;
    }
    int checksum_17 = (aux + st.buffer[1]) & 3;
    switch (checksum_17) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_18(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int parity_39 = local_arr[aux % 3];
    acc = (acc + parity_39 * 2) & 127;
    int scale_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_27) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_28 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_28 > 37) {
        acc = (acc + sample_28 * 2 + 5) & 127;
        aux ^= (sample_28 & 15);
    } else {
        acc = (acc - sample_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_19(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001490_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int parity_48 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_48 > 17) {
        acc = (acc + parity_48 * 2 + 5) & 127;
        aux ^= (parity_48 & 15);
    } else {
        acc = (acc - parity_48 + 11) & 127;
        aux += 3;
    }
    int pivot_72 = (aux + st.buffer[1]) & 3;
    switch (pivot_72) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001490_9013_20(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001490_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_38 = 0;
    for (int k = 0; k < 3; k++) {
        scale_38 = (scale_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_38) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_88 = local_arr[aux % 3];
    acc = (acc + factor_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001490_9013_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001490_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_64) & 63;
    acc ^= aux;
    int tracker_47 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_47 > 42) {
        acc = (acc + tracker_47 * 2 + 5) & 127;
        aux ^= (tracker_47 & 15);
    } else {
        acc = (acc - tracker_47 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_61 = 0;
    for (int k = 0; k < 2; k++) {
        damping_61 = (damping_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_61) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001490_0;
    int sec_r001490_1;
    int sec_r001490_2;
    int sec_r001490_3;
    int sec_r001490_4;
    int sec_r001490_5;
    int sec_r001490_6;
    int sec_r001490_7;
    int sec_r001490_8;
    int sec_r001490_9;
    int sec_r001490_10;
    int sec_r001490_11;
    int sec_r001490_12;
    int sec_r001490_13;
    int sec_r001490_14;
    int sec_r001490_15;
    int sec_r001490_16;
    int pub_r001490_0;
    int pub_r001490_1;
    int pub_r001490_2;
    int pub_r001490_3;
    int pub_r001490_4;
    int pub_r001490_5;
    int pub_r001490_6;
    int pub_r001490_7;
    int pub_r001490_8;
    int pub_r001490_9;
    int pub_r001490_10;
    int pub_r001490_11;
    int pub_r001490_12;
    int pub_r001490_13;
    int pub_r001490_14;
    int pub_r001490_15;
    int pub_r001490_16;
    int pub_r001490_17;
    int pub_r001490_18;
    int pub_r001490_19;
    int pub_r001490_20;
    int pub_r001490_21;
    int pub_r001490_22;
    int pub_r001490_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001490_0 >= -100 && pub_r001490_0 <= 100);
    __CPROVER_assume(pub_r001490_1 >= -100 && pub_r001490_1 <= 100);
    __CPROVER_assume(pub_r001490_2 >= -100 && pub_r001490_2 <= 100);
    __CPROVER_assume(pub_r001490_3 >= -100 && pub_r001490_3 <= 100);
    __CPROVER_assume(pub_r001490_4 >= -100 && pub_r001490_4 <= 100);
    __CPROVER_assume(pub_r001490_5 >= -100 && pub_r001490_5 <= 100);
    __CPROVER_assume(pub_r001490_6 >= -100 && pub_r001490_6 <= 100);
    __CPROVER_assume(pub_r001490_7 >= -100 && pub_r001490_7 <= 100);
    __CPROVER_assume(pub_r001490_8 >= -100 && pub_r001490_8 <= 100);
    __CPROVER_assume(pub_r001490_9 >= -100 && pub_r001490_9 <= 100);
    __CPROVER_assume(pub_r001490_10 >= -100 && pub_r001490_10 <= 100);
    __CPROVER_assume(pub_r001490_11 >= -100 && pub_r001490_11 <= 100);
    __CPROVER_assume(pub_r001490_12 >= -100 && pub_r001490_12 <= 100);
    __CPROVER_assume(pub_r001490_13 >= -100 && pub_r001490_13 <= 100);
    __CPROVER_assume(pub_r001490_14 >= -100 && pub_r001490_14 <= 100);
    __CPROVER_assume(pub_r001490_15 >= -100 && pub_r001490_15 <= 100);
    __CPROVER_assume(pub_r001490_16 >= -100 && pub_r001490_16 <= 100);
    __CPROVER_assume(pub_r001490_17 >= -100 && pub_r001490_17 <= 100);
    __CPROVER_assume(pub_r001490_18 >= -100 && pub_r001490_18 <= 100);
    __CPROVER_assume(pub_r001490_19 >= -100 && pub_r001490_19 <= 100);
    __CPROVER_assume(pub_r001490_20 >= -100 && pub_r001490_20 <= 100);
    __CPROVER_assume(pub_r001490_21 >= -100 && pub_r001490_21 <= 100);
    __CPROVER_assume(pub_r001490_22 >= -100 && pub_r001490_22 <= 100);
    __CPROVER_assume(pub_r001490_23 >= -100 && pub_r001490_23 <= 100);
    __CPROVER_assume(sec_r001490_0 >= 0 && sec_r001490_0 <= 255);
    __CPROVER_assume(sec_r001490_1 >= 0 && sec_r001490_1 <= 255);
    __CPROVER_assume(sec_r001490_2 >= 0 && sec_r001490_2 <= 255);
    __CPROVER_assume(sec_r001490_3 >= 0 && sec_r001490_3 <= 255);
    __CPROVER_assume(sec_r001490_4 >= 0 && sec_r001490_4 <= 255);
    __CPROVER_assume(sec_r001490_5 >= 0 && sec_r001490_5 <= 255);
    __CPROVER_assume(sec_r001490_6 >= 0 && sec_r001490_6 <= 255);
    __CPROVER_assume(sec_r001490_7 >= 0 && sec_r001490_7 <= 255);
    __CPROVER_assume(sec_r001490_8 >= 0 && sec_r001490_8 <= 255);
    __CPROVER_assume(sec_r001490_9 >= 0 && sec_r001490_9 <= 255);
    __CPROVER_assume(sec_r001490_10 >= 0 && sec_r001490_10 <= 255);
    __CPROVER_assume(sec_r001490_11 >= 0 && sec_r001490_11 <= 255);
    __CPROVER_assume(sec_r001490_12 >= 0 && sec_r001490_12 <= 255);
    __CPROVER_assume(sec_r001490_13 >= 0 && sec_r001490_13 <= 255);
    __CPROVER_assume(sec_r001490_14 >= 0 && sec_r001490_14 <= 255);
    __CPROVER_assume(sec_r001490_15 >= 0 && sec_r001490_15 <= 255);
    __CPROVER_assume(sec_r001490_16 >= 0 && sec_r001490_16 <= 255);

    struct Transaction_R001490_9013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001490_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001490_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001490_0 + 7) & 15;
    struct SensorNode_R001490_9013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001490_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001490_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001490_0 + 9) & 15;

    union ColorPixel_R001490_9013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001490_9013_0(sec_r001490_0, sec_r001490_1, pub_r001490_2, pub_r001490_3, pub_r001490_4);
    int helper_flow_1 = fn_R001490_9013_1(sec_r001490_1, sec_r001490_2, pub_r001490_3, pub_r001490_4);
    int helper_flow_2 = fn_R001490_9013_2(sec_r001490_2, sec_r001490_3);
    int helper_flow_3 = fn_R001490_9013_3(sec_r001490_3, pub_r001490_4);
    int helper_flow_4 = fn_R001490_9013_4(sec_r001490_4, pub_r001490_5, pub_r001490_6, pub_r001490_7);
    int helper_flow_5 = fn_R001490_9013_5(sec_r001490_5, pub_r001490_6, pub_r001490_7, pub_r001490_8);
    int helper_flow_6 = fn_R001490_9013_6(sec_r001490_6, sec_r001490_7, pub_r001490_8);
    int helper_flow_7 = fn_R001490_9013_7(sec_r001490_7, pub_r001490_8, pub_r001490_9);
    int helper_flow_8 = fn_R001490_9013_8(sec_r001490_8, sec_r001490_9, pub_r001490_10, pub_r001490_11, pub_r001490_12);
    int helper_flow_9 = fn_R001490_9013_9(sec_r001490_9, pub_r001490_10);
    int helper_flow_10 = fn_R001490_9013_10(sec_r001490_10, pub_r001490_11, pub_r001490_12, pub_r001490_13, pub_r001490_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_0 > 20) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001490_16 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_1 > 34) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001490_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_3 > 38) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001490_9 ^ 0x2A) * 2 + pub_r001490_12) & 127;
    if (stage_v_4 > 46) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001490_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001490_2 ^ 0x2A) * 2 + pub_r001490_21) & 127;
    if (stage_v_6 > 50) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001490_7 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_7 > 33) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001490_11 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_8 > 33) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001490_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_10 > 49) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001490_9 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_11 > 43) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_12 > 48) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_13 > 21) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001490_21 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001490_1 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_15 > 33) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001490_20) & 127;
    if (stage_v_16 > 37) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_17 > 26) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_18 > 42) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001490_16 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_20 > 25) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001490_0 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001490_15 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001490_1 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_23 > 30) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001490_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001490_8 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_25 > 33) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001490_4 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_26 > 38) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_27 > 50) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001490_21 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_29 > 20) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001490_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001490_8 ^ 0x2A) * 2 + pub_r001490_1) & 127;
    if (stage_v_31 > 49) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_32 > 46) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_33 > 24) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_34 > 44) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001490_9 ^ 0x2A) * 2 + pub_r001490_1) & 127;
    if (stage_v_35 > 24) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001490_0) & 127;
    if (stage_v_36 > 25) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_37 > 34) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_38 > 36) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_39 > 22) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001490_11 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_40 > 29) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001490_23) & 127;
    if (stage_v_41 > 34) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_42 > 28) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_43 > 35) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_44 > 36) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001490_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_46 > 20) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001490_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001490_13 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_48 > 46) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_49 > 20) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_50 > 33) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_51 > 46) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_52 > 39) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_53 > 41) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001490_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001490_11 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_55 > 40) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_56 > 36) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_57 > 29) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_58 > 44) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_59 > 46) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001490_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_61 > 22) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001490_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001490_5 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_63 > 50) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001490_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001490_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_66 > 22) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001490_21 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001490_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001490_1 ^ 0x2A) * 2 + pub_r001490_1) & 127;
    if (stage_v_69 > 42) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001490_21) & 127;
    if (stage_v_70 > 27) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001490_1 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_71 > 37) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_72 > 37) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001490_21) & 127;
    if (stage_v_73 > 47) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_74 > 37) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_75 > 23) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_76 > 25) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_77 > 33) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001490_3 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_78 > 43) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_79 > 41) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001490_11 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001490_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_82 > 43) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001490_23 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_84 > 31) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001490_5 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_85 > 35) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_86 > 41) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_87 > 22) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001490_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_89 > 22) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001490_4 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_90 > 46) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001490_2 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_91 > 25) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_92 > 47) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001490_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001490_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001490_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001490_10 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_96 > 41) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001490_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001490_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_99 > 31) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001490_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_101 > 45) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001490_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_103 > 50) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001490_5 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_104 > 44) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_105 > 32) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_106 > 37) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001490_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_108 > 46) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001490_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001490_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_111 > 38) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001490_22) & 127;
    if (stage_v_112 > 20) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r001490_2 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_113 > 34) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_114 > 20) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001490_2 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_115 > 22) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001490_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001490_0 ^ 0x2A) * 2 + pub_r001490_2) & 127;
    if (stage_v_117 > 45) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_118 > 24) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_119 > 45) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_120 > 31) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001490_22 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001490_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_123 > 42) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001490_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001490_21 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001490_15 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_126 > 38) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_127 > 46) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_128 > 46) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001490_0) & 127;
    if (stage_v_129 > 39) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_130 > 34) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_131 > 26) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001490_2) & 127;
    if (stage_v_132 > 26) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_133 > 46) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001490_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001490_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_136 > 47) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001490_23) & 127;
    if (stage_v_137 > 25) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001490_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_139 > 47) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001490_8 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_140 > 41) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001490_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001490_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r001490_16 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_143 > 48) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r001490_14 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_144 > 31) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001490_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001490_2) & 127;
    if (stage_v_146 > 24) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001490_1) & 127;
    if (stage_v_147 > 25) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001490_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001490_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001490_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_151 > 47) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_152 > 50) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_153 > 27) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_154 > 46) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001490_13 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_155 > 22) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001490_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_157 > 32) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001490_12) & 127;
    if (stage_v_158 > 31) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r001490_5 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_159 > 26) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001490_13 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_160 > 49) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001490_20) & 127;
    if (stage_v_161 > 24) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_163 > 38) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_164 > 50) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r001490_0 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_165 > 21) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_166 > 47) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001490_1) & 127;
    if (stage_v_167 > 38) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_168 > 43) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001490_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_170 > 34) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001490_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_172 > 47) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_173 > 47) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001490_12) & 127;
    if (stage_v_174 > 34) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_175 > 50) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001490_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_177 > 41) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_179 > 27) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001490_23 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001490_23) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001490_4) & 127;
    if (stage_v_182 > 23) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_183 > 46) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_184 > 30) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001490_22 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_186 > 20) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_187 > 32) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_188 > 35) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001490_15) & 127;
    if (stage_v_189 > 23) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_190 > 48) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001490_9 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001490_12) & 127;
    if (stage_v_192 > 31) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001490_17) & 127;
    if (stage_v_193 > 34) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001490_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001490_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001490_0 ^ 0x2A) * 2 + pub_r001490_7) & 127;
    if (stage_v_196 > 49) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001490_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_198 > 41) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_199 > 33) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_200 > 47) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_201 > 37) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_202 > 43) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001490_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_204 > 27) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001490_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001490_9) & 127;
    if (stage_v_206 > 50) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_207 > 41) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001490_1) & 127;
    if (stage_v_208 > 34) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001490_2) & 127;
    if (stage_v_209 > 35) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_210 > 21) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001490_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001490_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_159 ^ 0x2A) * 2 + pub_r001490_21) & 127;
    if (stage_v_213 > 20) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_214 > 31) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_215 > 21) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_216 > 44) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_217 > 28) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_218 > 36) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r001490_15 ^ 0x2A) * 2 + pub_r001490_12) & 127;
    if (stage_v_219 > 31) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001490_5) & 127;
    if (stage_v_220 > 35) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001490_16) & 127;
    if (stage_v_221 > 32) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r001490_15 ^ 0x2A) * 2 + pub_r001490_13) & 127;
    if (stage_v_222 > 47) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001490_19 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001490_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001490_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001490_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001490_19) & 127;
    if (stage_v_227 > 37) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_228 > 36) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_229 > 45) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001490_22 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001490_12) & 127;
    if (stage_v_231 > 27) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001490_10) & 127;
    if (stage_v_232 > 41) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_233 > 29) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_234 > 42) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001490_8) & 127;
    if (stage_v_235 > 47) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001490_11 ^ 0x2A) * 2 + pub_r001490_11) & 127;
    if (stage_v_236 > 24) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001490_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001490_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001490_18) & 127;
    if (stage_v_239 > 35) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001490_21 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001490_14) & 127;
    if (stage_v_241 > 23) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001490_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001490_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_244 > 26) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001490_23) & 127;
    if (stage_v_245 > 47) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001490_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_219 ^ 0x2A) * 2 + pub_r001490_21) & 127;
    if (stage_v_247 > 48) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001490_3) & 127;
    if (stage_v_248 > 38) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001490_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_175 ^ 0x2A) * 2 + pub_r001490_6) & 127;
    if (stage_v_250 > 45) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
