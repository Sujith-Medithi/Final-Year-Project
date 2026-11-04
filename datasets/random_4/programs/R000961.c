/*
 * Benchmark Program: R000961
 * Family: mixed_control_data
 * Generator Seed: 496113
 * High Inputs: 19 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000961_6113_0 {
    int iv;
    unsigned char nonce;
    short round_key;
    int flags;
    int counter;
    int buffer[3];
};

struct Vector3D_R000961_6113_1 {
    int coord_z;
    int pitch;
    short norm_sq;
    short coord_x;
    short coord_y;
    unsigned char heading;
    int buffer[3];
};

struct AudioFrame_R000961_6113_2 {
    int channels;
    int envelope;
    int gain;
    short rms;
    short sample_rate;
    int peak;
    int buffer[3];
};

union TelemetryField_R000961_6113_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000961_6113_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000961_6113_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000961_6113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int delta_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_27) & 63;
    acc ^= aux;
    int quotient_22 = (aux + st.buffer[1]) & 3;
    switch (quotient_22) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_62 = 0;
    for (int k = 0; k < 2; k++) {
        segment_62 = (segment_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_62) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_57 = local_arr[aux % 3];
    acc = (acc + checksum_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_1(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int offset_71 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_71 > 38) {
        acc = (acc + offset_71 * 2 + 5) & 127;
        aux ^= (offset_71 & 15);
    } else {
        acc = (acc - offset_71 + 11) & 127;
        aux += 3;
    }
    int metric_24 = (aux + st.buffer[1]) & 3;
    switch (metric_24) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_72 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_72 > 34) {
        acc = (acc + damping_72 * 2 + 5) & 127;
        aux ^= (damping_72 & 15);
    } else {
        acc = (acc - damping_72 + 11) & 127;
        aux += 3;
    }
    int parity_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_75 = local_arr[aux % 3];
    acc = (acc + weight_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_76 = local_arr[aux % 3];
    acc = (acc + quotient_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000961_6113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int segment_24 = local_arr[aux % 3];
    acc = (acc + segment_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int accumulator_91 = local_arr[aux % 3];
    acc = (acc + accumulator_91 * 2) & 127;
    int segment_84 = (aux + st.buffer[1]) & 3;
    switch (segment_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_53 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_53 = (cursor_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_53) & 127;
    }
    int bound_96 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_96 > 23) {
        acc = (acc + bound_96 * 2 + 5) & 127;
        aux ^= (bound_96 & 15);
    } else {
        acc = (acc - bound_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000961_6113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_95) & 63;
    acc ^= aux;
    int offset_27 = (aux + st.buffer[1]) & 3;
    switch (offset_27) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int quantum_37 = local_arr[aux % 3];
    acc = (acc + quantum_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_13 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_13 > 10) {
        acc = (acc + quotient_13 * 2 + 5) & 127;
        aux ^= (quotient_13 & 15);
    } else {
        acc = (acc - quotient_13 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_18 = local_arr[aux % 3];
    acc = (acc + parity_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_9(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000961_6113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quantum_42 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_42 = (quantum_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_42) & 127;
    }
    int stride_61 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_61 > 43) {
        acc = (acc + stride_61 * 2 + 5) & 127;
        aux ^= (stride_61 & 15);
    } else {
        acc = (acc - stride_61 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_20 = (aux + st.buffer[1]) & 3;
    switch (threshold_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000961_6113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_73 = 0;
    for (int k = 0; k < 3; k++) {
        metric_73 = (metric_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_73) & 127;
    }
    int phase_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000961_6113_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_98 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_98 > 12) {
        acc = (acc + delta_98 * 2 + 5) & 127;
        aux ^= (delta_98 & 15);
    } else {
        acc = (acc - delta_98 + 11) & 127;
        aux += 3;
    }
    int metric_42 = (aux + st.buffer[1]) & 3;
    switch (metric_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_90 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_90 = (quantum_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_90) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_12(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int damping_28 = 0;
    for (int k = 0; k < 2; k++) {
        damping_28 = (damping_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_28) & 127;
    }
    int sample_63 = (aux + st.buffer[1]) & 3;
    switch (sample_63) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_13(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tracker_84 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_84 = (tracker_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_84) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_94 = local_arr[aux % 3];
    acc = (acc + mask_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_68 = 0;
    for (int k = 0; k < 2; k++) {
        segment_68 = (segment_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_68) & 127;
    }
    int window_46 = (aux + st.buffer[1]) & 3;
    switch (window_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_80 = local_arr[aux % 3];
    acc = (acc + weight_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_15(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int index_reg_42 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_42 = (index_reg_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_42) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000961_6113_16(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int parity_97 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_97 > 25) {
        acc = (acc + parity_97 * 2 + 5) & 127;
        aux ^= (parity_97 & 15);
    } else {
        acc = (acc - parity_97 + 11) & 127;
        aux += 3;
    }
    int weight_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_27) & 63;
    acc ^= aux;
    int margin_18 = (aux + st.buffer[1]) & 3;
    switch (margin_18) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_17(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_30 = local_arr[aux % 3];
    acc = (acc + cursor_30 * 2) & 127;
    int pivot_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_97) & 63;
    acc ^= aux;
    int tracker_50 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_50 > 48) {
        acc = (acc + tracker_50 * 2 + 5) & 127;
        aux ^= (tracker_50 & 15);
    } else {
        acc = (acc - tracker_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_18(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int pivot_53 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_53 = (pivot_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_53) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_19(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000961_6113_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int pivot_49 = local_arr[aux % 3];
    acc = (acc + pivot_49 * 2) & 127;
    int quantum_27 = (aux + st.buffer[1]) & 3;
    switch (quantum_27) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000961_6113_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_53 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_53 = (tracker_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_53) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_59 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_59 > 37) {
        acc = (acc + vector_59 * 2 + 5) & 127;
        aux ^= (vector_59 & 15);
    } else {
        acc = (acc - vector_59 + 11) & 127;
        aux += 3;
    }
    int offset_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000961_6113_21(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_42 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_42 > 15) {
        acc = (acc + index_reg_42 * 2 + 5) & 127;
        aux ^= (index_reg_42 & 15);
    } else {
        acc = (acc - index_reg_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_90 = local_arr[aux % 3];
    acc = (acc + anchor_90 * 2) & 127;
    int segment_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000961_6113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int sample_81 = 0;
    for (int k = 0; k < 3; k++) {
        sample_81 = (sample_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_81) & 127;
    }
    int weight_74 = (aux + st.buffer[1]) & 3;
    switch (weight_74) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000961_6113_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000961_6113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_59 = 0;
    for (int k = 0; k < 3; k++) {
        margin_59 = (margin_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_59) & 127;
    }
    int accumulator_78 = (aux + st.buffer[1]) & 3;
    switch (accumulator_78) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_95 = local_arr[aux % 3];
    acc = (acc + accumulator_95 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000961_0;
    int sec_r000961_1;
    int sec_r000961_2;
    int sec_r000961_3;
    int sec_r000961_4;
    int sec_r000961_5;
    int sec_r000961_6;
    int sec_r000961_7;
    int sec_r000961_8;
    int sec_r000961_9;
    int sec_r000961_10;
    int sec_r000961_11;
    int sec_r000961_12;
    int sec_r000961_13;
    int sec_r000961_14;
    int sec_r000961_15;
    int sec_r000961_16;
    int sec_r000961_17;
    int sec_r000961_18;
    int pub_r000961_0;
    int pub_r000961_1;
    int pub_r000961_2;
    int pub_r000961_3;
    int pub_r000961_4;
    int pub_r000961_5;
    int pub_r000961_6;
    int pub_r000961_7;
    int pub_r000961_8;
    int pub_r000961_9;
    int pub_r000961_10;
    int pub_r000961_11;
    int pub_r000961_12;
    int pub_r000961_13;
    int pub_r000961_14;
    int pub_r000961_15;
    int pub_r000961_16;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000961_0 >= -100 && pub_r000961_0 <= 100);
    __CPROVER_assume(pub_r000961_1 >= -100 && pub_r000961_1 <= 100);
    __CPROVER_assume(pub_r000961_2 >= -100 && pub_r000961_2 <= 100);
    __CPROVER_assume(pub_r000961_3 >= -100 && pub_r000961_3 <= 100);
    __CPROVER_assume(pub_r000961_4 >= -100 && pub_r000961_4 <= 100);
    __CPROVER_assume(pub_r000961_5 >= -100 && pub_r000961_5 <= 100);
    __CPROVER_assume(pub_r000961_6 >= -100 && pub_r000961_6 <= 100);
    __CPROVER_assume(pub_r000961_7 >= -100 && pub_r000961_7 <= 100);
    __CPROVER_assume(pub_r000961_8 >= -100 && pub_r000961_8 <= 100);
    __CPROVER_assume(pub_r000961_9 >= -100 && pub_r000961_9 <= 100);
    __CPROVER_assume(pub_r000961_10 >= -100 && pub_r000961_10 <= 100);
    __CPROVER_assume(pub_r000961_11 >= -100 && pub_r000961_11 <= 100);
    __CPROVER_assume(pub_r000961_12 >= -100 && pub_r000961_12 <= 100);
    __CPROVER_assume(pub_r000961_13 >= -100 && pub_r000961_13 <= 100);
    __CPROVER_assume(pub_r000961_14 >= -100 && pub_r000961_14 <= 100);
    __CPROVER_assume(pub_r000961_15 >= -100 && pub_r000961_15 <= 100);
    __CPROVER_assume(pub_r000961_16 >= -100 && pub_r000961_16 <= 100);
    __CPROVER_assume(sec_r000961_0 >= 0 && sec_r000961_0 <= 255);
    __CPROVER_assume(sec_r000961_1 >= 0 && sec_r000961_1 <= 255);
    __CPROVER_assume(sec_r000961_2 >= 0 && sec_r000961_2 <= 255);
    __CPROVER_assume(sec_r000961_3 >= 0 && sec_r000961_3 <= 255);
    __CPROVER_assume(sec_r000961_4 >= 0 && sec_r000961_4 <= 255);
    __CPROVER_assume(sec_r000961_5 >= 0 && sec_r000961_5 <= 255);
    __CPROVER_assume(sec_r000961_6 >= 0 && sec_r000961_6 <= 255);
    __CPROVER_assume(sec_r000961_7 >= 0 && sec_r000961_7 <= 255);
    __CPROVER_assume(sec_r000961_8 >= 0 && sec_r000961_8 <= 255);
    __CPROVER_assume(sec_r000961_9 >= 0 && sec_r000961_9 <= 255);
    __CPROVER_assume(sec_r000961_10 >= 0 && sec_r000961_10 <= 255);
    __CPROVER_assume(sec_r000961_11 >= 0 && sec_r000961_11 <= 255);
    __CPROVER_assume(sec_r000961_12 >= 0 && sec_r000961_12 <= 255);
    __CPROVER_assume(sec_r000961_13 >= 0 && sec_r000961_13 <= 255);
    __CPROVER_assume(sec_r000961_14 >= 0 && sec_r000961_14 <= 255);
    __CPROVER_assume(sec_r000961_15 >= 0 && sec_r000961_15 <= 255);
    __CPROVER_assume(sec_r000961_16 >= 0 && sec_r000961_16 <= 255);
    __CPROVER_assume(sec_r000961_17 >= 0 && sec_r000961_17 <= 255);
    __CPROVER_assume(sec_r000961_18 >= 0 && sec_r000961_18 <= 255);

    struct CipherContext_R000961_6113_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000961_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000961_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000961_0 + 7) & 15;
    struct Vector3D_R000961_6113_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000961_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000961_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000961_0 + 9) & 15;
    struct AudioFrame_R000961_6113_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000961_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000961_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000961_0 + 11) & 15;

    union TelemetryField_R000961_6113_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 11) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 26) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 35) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 50) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 15) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 30) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 30) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 45) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 10) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 25) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 31) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 46) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 15) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 30) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (out_sink > 100) ? (chk_sum & 31) : (61 & 31);
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= (stage_v_56 << 1) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 19) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 34) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 18) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 33) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 28) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 43) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 25) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 40) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 15) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 30) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 89) & 15;
    int stage_v_88 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= stage_v_88;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 91) & 15;
    int stage_v_90 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= stage_v_90;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[1] * 2 + 280) & 63;
    if (stage_v_91 > 14) {
        out_sink = (out_sink + stage_v_91 - 5) & 255;
        if (stage_v_91 > 29) {
            chk_sum ^= (stage_v_91 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_91 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_93 = (stage_v_93 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_2.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 22) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 37) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 40) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 55) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = table[2];
    table[2] = (table[3] + 197) & 63;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = table[2];
    table[2] = (table[3] + 205) & 63;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 23) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 38) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 109) & 15;
    int stage_v_108 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= stage_v_108;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_109 = (stage_v_109 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_115 = (stage_v_115 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_117 = (stage_v_117 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 12) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 27) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (out_sink > 100) ? (chk_sum & 31) : (134 & 31);
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= (stage_v_129 << 1) & 127;

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[0] ^ 134) & 3;
    switch (stage_v_131) {
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

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_132 = (stage_v_132 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = table[1];
    table[1] = (table[2] + 267) & 63;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_2.buffer[0] ^ 137) & 3;
    switch (stage_v_134) {
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

    /* Execution Pipeline Stage 135 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 140) & 15;
    int stage_v_139 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= stage_v_139;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_2.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 10) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 25) {
            chk_sum ^= (stage_v_140 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_140 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[2] * 2 + 445) & 63;
    if (stage_v_146 > 26) {
        out_sink = (out_sink + stage_v_146 - 5) & 255;
        if (stage_v_146 > 41) {
            chk_sum ^= (stage_v_146 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_146 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

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
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = table[2];
    table[2] = (table[3] + 309) & 63;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_2.buffer[2] * 2 + 490) & 63;
    if (stage_v_161 > 24) {
        out_sink = (out_sink + stage_v_161 - 5) & 255;
        if (stage_v_161 > 39) {
            chk_sum ^= (stage_v_161 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_161 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_163 = (stage_v_163 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_166 = (stage_v_166 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = table[2];
    table[2] = (table[3] + 341) & 63;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = table[3];
    table[3] = (table[0] + 343) & 63;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] * 2 + 529) & 63;
    if (stage_v_174 > 39) {
        out_sink = (out_sink + stage_v_174 - 5) & 255;
        if (stage_v_174 > 54) {
            chk_sum ^= (stage_v_174 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_174 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = table[3];
    table[3] = (table[0] + 351) & 63;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_176 = (stage_v_176 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 180) & 15;
    int stage_v_179 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    chk_sum ^= stage_v_179;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (out_sink > 100) ? (chk_sum & 31) : (185 & 31);
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= (stage_v_180 << 1) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = table[2];
    table[2] = (table[3] + 365) & 63;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (st_var_0.buffer[0] ^ 186) & 3;
    switch (stage_v_183) {
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

    /* Execution Pipeline Stage 184 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 185) & 15;
    int stage_v_184 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= stage_v_184;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_186 = (stage_v_186 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_186) & 127;
    }
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 188) & 15;
    int stage_v_187 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= stage_v_187;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (st_var_2.buffer[0] ^ 191) & 3;
    switch (stage_v_188) {
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

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_1.buffer[1] * 2 + 577) & 63;
    if (stage_v_190 > 32) {
        out_sink = (out_sink + stage_v_190 - 5) & 255;
        if (stage_v_190 > 47) {
            chk_sum ^= (stage_v_190 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_190 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_2.buffer[0] ^ 194) & 3;
    switch (stage_v_191) {
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

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = table[0];
    table[0] = (table[1] + 385) & 63;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_194 = (stage_v_194 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_194) & 127;
    }
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_0.buffer[0] ^ 198) & 3;
    switch (stage_v_195) {
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

    /* Security Information Flow: Family = mixed_control_data */
    int m_var = (sec_r000961_5 ^ 0x55) & 63;
    if (m_var > 31) {
        out_sink += (m_var * 2 + pub_r000961_2) & 127;
    } else {
        out_sink -= (m_var + 12) & 31;
    }
    out_sink ^= (sec_r000961_10 & 15);

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
