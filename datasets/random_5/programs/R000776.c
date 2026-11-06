/*
 * Benchmark Program: R000776
 * Security Family: implicit_flow
 * Generator Seed: 577613
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000776_7613_0 {
    short severity;
    int code;
    unsigned char signature;
    unsigned char timestamp;
    short facility;
    int seq;
    int buffer[3];
};

struct FilterState_R000776_7613_1 {
    int prev_in;
    short mode;
    int cutoff;
    unsigned char damping;
    unsigned char gain_db;
    int buffer[3];
};

struct MatrixBlock_R000776_7613_2 {
    int trace;
    int determinant;
    short dim;
    int scale;
    short density;
    int buffer[3];
};

struct Vector3D_R000776_7613_3 {
    short heading;
    unsigned char norm_sq;
    int coord_x;
    int coord_y;
    short pitch;
    int buffer[3];
};

union ColorPixel_R000776_7613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000776_7613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000776_7613_0(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000776_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int phase_64 = (aux + st.buffer[1]) & 3;
    switch (phase_64) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_67) & 63;
    acc ^= aux;
    int bound_50 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_50 > 40) {
        acc = (acc + bound_50 * 2 + 5) & 127;
        aux ^= (bound_50 & 15);
    } else {
        acc = (acc - bound_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000776_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int sample_38 = (aux + st.buffer[1]) & 3;
    switch (sample_38) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000776_7613_2(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000776_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_21) & 63;
    acc ^= aux;
    int window_42 = (aux + st.buffer[1]) & 3;
    switch (window_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_19 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_19 > 45) {
        acc = (acc + stride_19 * 2 + 5) & 127;
        aux ^= (stride_19 & 15);
    } else {
        acc = (acc - stride_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000776_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_78 = local_arr[aux % 3];
    acc = (acc + index_reg_78 * 2) & 127;
    int checksum_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_86) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000776_7613_4(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int cursor_61 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_61 > 18) {
        acc = (acc + cursor_61 * 2 + 5) & 127;
        aux ^= (cursor_61 & 15);
    } else {
        acc = (acc - cursor_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_46 = local_arr[aux % 3];
    acc = (acc + mask_46 * 2) & 127;
    int tracker_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000776_7613_5(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000776_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_26 = (aux + st.buffer[1]) & 3;
    switch (weight_26) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_64 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_64 > 49) {
        acc = (acc + mask_64 * 2 + 5) & 127;
        aux ^= (mask_64 & 15);
    } else {
        acc = (acc - mask_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_6(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000776_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_61 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_61 > 13) {
        acc = (acc + factor_61 * 2 + 5) & 127;
        aux ^= (factor_61 & 15);
    } else {
        acc = (acc - factor_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_69 = local_arr[aux % 3];
    acc = (acc + margin_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_7(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000776_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int quotient_15 = local_arr[aux % 3];
    acc = (acc + quotient_15 * 2) & 127;
    int delta_61 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_61 > 21) {
        acc = (acc + delta_61 * 2 + 5) & 127;
        aux ^= (delta_61 & 15);
    } else {
        acc = (acc - delta_61 + 11) & 127;
        aux += 3;
    }
    int stride_80 = (aux + st.buffer[1]) & 3;
    switch (stride_80) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000776_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_48 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_48 > 32) {
        acc = (acc + parity_48 * 2 + 5) & 127;
        aux ^= (parity_48 & 15);
    } else {
        acc = (acc - parity_48 + 11) & 127;
        aux += 3;
    }
    int offset_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_9(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000776_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int checksum_13 = (aux + st.buffer[1]) & 3;
    switch (checksum_13) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_61 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_61 > 12) {
        acc = (acc + vector_61 * 2 + 5) & 127;
        aux ^= (vector_61 & 15);
    } else {
        acc = (acc - vector_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_42 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_42 > 17) {
        acc = (acc + delta_42 * 2 + 5) & 127;
        aux ^= (delta_42 & 15);
    } else {
        acc = (acc - delta_42 + 11) & 127;
        aux += 3;
    }
    int scale_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int window_47 = (st.buffer[0] * 3 + aux) & 63;
    if (window_47 > 48) {
        acc = (acc + window_47 * 2 + 5) & 127;
        aux ^= (window_47 & 15);
    } else {
        acc = (acc - window_47 + 11) & 127;
        aux += 3;
    }
    int index_reg_87 = (aux + st.buffer[1]) & 3;
    switch (index_reg_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000776_7613_12(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000776_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int scale_79 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_79 > 12) {
        acc = (acc + scale_79 * 2 + 5) & 127;
        aux ^= (scale_79 & 15);
    } else {
        acc = (acc - scale_79 + 11) & 127;
        aux += 3;
    }
    int damping_27 = (aux + st.buffer[1]) & 3;
    switch (damping_27) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_48 = local_arr[aux % 3];
    acc = (acc + tracker_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_13(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000776_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int metric_70 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_70 > 44) {
        acc = (acc + metric_70 * 2 + 5) & 127;
        aux ^= (metric_70 & 15);
    } else {
        acc = (acc - metric_70 + 11) & 127;
        aux += 3;
    }
    int stride_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_51) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_24) & 63;
    acc ^= aux;
    int checksum_97 = (aux + st.buffer[1]) & 3;
    switch (checksum_97) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_18) & 63;
    acc ^= aux;
    int bound_76 = (aux + st.buffer[1]) & 3;
    switch (bound_76) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_16(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000776_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quantum_25 = (aux + st.buffer[1]) & 3;
    switch (quantum_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_29 = local_arr[aux % 3];
    acc = (acc + damping_29 * 2) & 127;
    int stride_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000776_7613_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000776_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_75 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_75 > 19) {
        acc = (acc + residue_75 * 2 + 5) & 127;
        aux ^= (residue_75 & 15);
    } else {
        acc = (acc - residue_75 + 11) & 127;
        aux += 3;
    }
    int phase_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_61) & 63;
    acc ^= aux;
    int pivot_94 = (aux + st.buffer[1]) & 3;
    switch (pivot_94) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_53 = local_arr[aux % 3];
    acc = (acc + scale_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000776_7613_18(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000776_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_88 = local_arr[aux % 3];
    acc = (acc + margin_88 * 2) & 127;
    int quotient_36 = (aux + st.buffer[1]) & 3;
    switch (quotient_36) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_15 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_15 > 35) {
        acc = (acc + quotient_15 * 2 + 5) & 127;
        aux ^= (quotient_15 & 15);
    } else {
        acc = (acc - quotient_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_39 = local_arr[aux % 3];
    acc = (acc + delta_39 * 2) & 127;
    int bound_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000776_7613_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000776_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int sample_80 = local_arr[aux % 3];
    acc = (acc + sample_80 * 2) & 127;
    int threshold_65 = (aux + st.buffer[1]) & 3;
    switch (threshold_65) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_75 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_75 > 22) {
        acc = (acc + stride_75 * 2 + 5) & 127;
        aux ^= (stride_75 & 15);
    } else {
        acc = (acc - stride_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000776_7613_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000776_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int bound_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_87) & 63;
    acc ^= aux;
    int accumulator_43 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_43 > 34) {
        acc = (acc + accumulator_43 * 2 + 5) & 127;
        aux ^= (accumulator_43 & 15);
    } else {
        acc = (acc - accumulator_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000776_0;
    int sec_r000776_1;
    int sec_r000776_2;
    int sec_r000776_3;
    int sec_r000776_4;
    int sec_r000776_5;
    int sec_r000776_6;
    int sec_r000776_7;
    int sec_r000776_8;
    int sec_r000776_9;
    int sec_r000776_10;
    int sec_r000776_11;
    int sec_r000776_12;
    int sec_r000776_13;
    int sec_r000776_14;
    int sec_r000776_15;
    int sec_r000776_16;
    int sec_r000776_17;
    int pub_r000776_0;
    int pub_r000776_1;
    int pub_r000776_2;
    int pub_r000776_3;
    int pub_r000776_4;
    int pub_r000776_5;
    int pub_r000776_6;
    int pub_r000776_7;
    int pub_r000776_8;
    int pub_r000776_9;
    int pub_r000776_10;
    int pub_r000776_11;
    int pub_r000776_12;
    int pub_r000776_13;
    int pub_r000776_14;
    int pub_r000776_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000776_0 >= -100 && pub_r000776_0 <= 100);
    __CPROVER_assume(pub_r000776_1 >= -100 && pub_r000776_1 <= 100);
    __CPROVER_assume(pub_r000776_2 >= -100 && pub_r000776_2 <= 100);
    __CPROVER_assume(pub_r000776_3 >= -100 && pub_r000776_3 <= 100);
    __CPROVER_assume(pub_r000776_4 >= -100 && pub_r000776_4 <= 100);
    __CPROVER_assume(pub_r000776_5 >= -100 && pub_r000776_5 <= 100);
    __CPROVER_assume(pub_r000776_6 >= -100 && pub_r000776_6 <= 100);
    __CPROVER_assume(pub_r000776_7 >= -100 && pub_r000776_7 <= 100);
    __CPROVER_assume(pub_r000776_8 >= -100 && pub_r000776_8 <= 100);
    __CPROVER_assume(pub_r000776_9 >= -100 && pub_r000776_9 <= 100);
    __CPROVER_assume(pub_r000776_10 >= -100 && pub_r000776_10 <= 100);
    __CPROVER_assume(pub_r000776_11 >= -100 && pub_r000776_11 <= 100);
    __CPROVER_assume(pub_r000776_12 >= -100 && pub_r000776_12 <= 100);
    __CPROVER_assume(pub_r000776_13 >= -100 && pub_r000776_13 <= 100);
    __CPROVER_assume(pub_r000776_14 >= -100 && pub_r000776_14 <= 100);
    __CPROVER_assume(pub_r000776_15 >= -100 && pub_r000776_15 <= 100);
    __CPROVER_assume(sec_r000776_0 >= 0 && sec_r000776_0 <= 255);
    __CPROVER_assume(sec_r000776_1 >= 0 && sec_r000776_1 <= 255);
    __CPROVER_assume(sec_r000776_2 >= 0 && sec_r000776_2 <= 255);
    __CPROVER_assume(sec_r000776_3 >= 0 && sec_r000776_3 <= 255);
    __CPROVER_assume(sec_r000776_4 >= 0 && sec_r000776_4 <= 255);
    __CPROVER_assume(sec_r000776_5 >= 0 && sec_r000776_5 <= 255);
    __CPROVER_assume(sec_r000776_6 >= 0 && sec_r000776_6 <= 255);
    __CPROVER_assume(sec_r000776_7 >= 0 && sec_r000776_7 <= 255);
    __CPROVER_assume(sec_r000776_8 >= 0 && sec_r000776_8 <= 255);
    __CPROVER_assume(sec_r000776_9 >= 0 && sec_r000776_9 <= 255);
    __CPROVER_assume(sec_r000776_10 >= 0 && sec_r000776_10 <= 255);
    __CPROVER_assume(sec_r000776_11 >= 0 && sec_r000776_11 <= 255);
    __CPROVER_assume(sec_r000776_12 >= 0 && sec_r000776_12 <= 255);
    __CPROVER_assume(sec_r000776_13 >= 0 && sec_r000776_13 <= 255);
    __CPROVER_assume(sec_r000776_14 >= 0 && sec_r000776_14 <= 255);
    __CPROVER_assume(sec_r000776_15 >= 0 && sec_r000776_15 <= 255);
    __CPROVER_assume(sec_r000776_16 >= 0 && sec_r000776_16 <= 255);
    __CPROVER_assume(sec_r000776_17 >= 0 && sec_r000776_17 <= 255);

    struct EventLog_R000776_7613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000776_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000776_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000776_0 + 7) & 15;
    struct FilterState_R000776_7613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000776_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000776_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000776_0 + 9) & 15;
    struct MatrixBlock_R000776_7613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000776_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000776_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000776_0 + 11) & 15;
    struct Vector3D_R000776_7613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000776_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000776_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000776_0 + 13) & 15;

    union ColorPixel_R000776_7613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 22) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 37) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    if ((sec_r000776_14 & 63) > 37) {
        stage_v_10 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_10) & 255;
    } else {
        stage_v_10 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_10 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    if ((sec_r000776_10 & 63) > 27) {
        stage_v_11 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_11) & 255;
    } else {
        stage_v_11 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_11 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    if ((stage_v_10 & 63) > 34) {
        stage_v_12 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_12) & 255;
    } else {
        stage_v_12 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_12 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    if ((sec_r000776_4 & 63) > 47) {
        stage_v_13 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_13) & 255;
    } else {
        stage_v_13 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_13 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((stage_v_12 & 63) > 43) {
        stage_v_14 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_14) & 255;
    } else {
        stage_v_14 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_14 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((stage_v_10 & 63) > 27) {
        stage_v_15 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_15) & 255;
    } else {
        stage_v_15 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_15 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((stage_v_15 & 63) > 45) {
        stage_v_16 = (pub_r000776_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_16) & 255;
    } else {
        stage_v_16 = (pub_r000776_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_16 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((stage_v_10 & 63) > 37) {
        stage_v_17 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_17) & 255;
    } else {
        stage_v_17 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_17 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((stage_v_16 & 63) > 36) {
        stage_v_18 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_18) & 255;
    } else {
        stage_v_18 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_18 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((sec_r000776_10 & 63) > 25) {
        stage_v_19 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_19) & 255;
    } else {
        stage_v_19 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_19 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((sec_r000776_15 & 63) > 53) {
        stage_v_20 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_20) & 255;
    } else {
        stage_v_20 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_20 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000776_11 & 63) > 56) {
        stage_v_21 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_21) & 255;
    } else {
        stage_v_21 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_21 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((sec_r000776_11 & 63) > 27) {
        stage_v_22 = (pub_r000776_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_22) & 255;
    } else {
        stage_v_22 = (pub_r000776_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_22 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((stage_v_12 & 63) > 58) {
        stage_v_23 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_23) & 255;
    } else {
        stage_v_23 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_23 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_11 & 63) > 28) {
        stage_v_24 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_24) & 255;
    } else {
        stage_v_24 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_24 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_18 & 63) > 55) {
        stage_v_25 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_25) & 255;
    } else {
        stage_v_25 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_25 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_11 & 63) > 24) {
        stage_v_26 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_26) & 255;
    } else {
        stage_v_26 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_26 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_23 & 63) > 16) {
        stage_v_27 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_27) & 255;
    } else {
        stage_v_27 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_27 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_27 & 63) > 40) {
        stage_v_28 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_28) & 255;
    } else {
        stage_v_28 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_28 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((sec_r000776_6 & 63) > 42) {
        stage_v_29 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_29) & 255;
    } else {
        stage_v_29 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_29 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000776_11 & 63) > 56) {
        stage_v_30 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_30) & 255;
    } else {
        stage_v_30 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_30 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_26 & 63) > 30) {
        stage_v_31 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_31) & 255;
    } else {
        stage_v_31 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_31 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_27 & 63) > 18) {
        stage_v_32 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_32) & 255;
    } else {
        stage_v_32 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_32 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((sec_r000776_11 & 63) > 15) {
        stage_v_33 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_33) & 255;
    } else {
        stage_v_33 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_33 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000776_3 & 63) > 53) {
        stage_v_34 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_34) & 255;
    } else {
        stage_v_34 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_34 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_27 & 63) > 20) {
        stage_v_35 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_35) & 255;
    } else {
        stage_v_35 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_35 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_24 & 63) > 55) {
        stage_v_36 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_36) & 255;
    } else {
        stage_v_36 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_36 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_21 & 63) > 44) {
        stage_v_37 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_37) & 255;
    } else {
        stage_v_37 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_37 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000776_16 & 63) > 44) {
        stage_v_38 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_38) & 255;
    } else {
        stage_v_38 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_38 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000776_7 & 63) > 57) {
        stage_v_39 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_39) & 255;
    } else {
        stage_v_39 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_39 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_20 & 63) > 36) {
        stage_v_40 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_40) & 255;
    } else {
        stage_v_40 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_40 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000776_10 & 63) > 33) {
        stage_v_41 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_41) & 255;
    } else {
        stage_v_41 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_41 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_33 & 63) > 24) {
        stage_v_42 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_42) & 255;
    } else {
        stage_v_42 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_42 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_22 & 63) > 51) {
        stage_v_43 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_43) & 255;
    } else {
        stage_v_43 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_43 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000776_0 & 63) > 18) {
        stage_v_44 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_44) & 255;
    } else {
        stage_v_44 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_44 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_11 & 63) > 28) {
        stage_v_45 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_45) & 255;
    } else {
        stage_v_45 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_45 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_34 & 63) > 44) {
        stage_v_46 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_46) & 255;
    } else {
        stage_v_46 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_46 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_12 & 63) > 29) {
        stage_v_47 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_47) & 255;
    } else {
        stage_v_47 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_47 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000776_13 & 63) > 40) {
        stage_v_48 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_48) & 255;
    } else {
        stage_v_48 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_48 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_47 & 63) > 32) {
        stage_v_49 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_49) & 255;
    } else {
        stage_v_49 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_49 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000776_15 & 63) > 16) {
        stage_v_50 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_50) & 255;
    } else {
        stage_v_50 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_50 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_18 & 63) > 23) {
        stage_v_51 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_51) & 255;
    } else {
        stage_v_51 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_51 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000776_13 & 63) > 21) {
        stage_v_52 = (pub_r000776_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_52) & 255;
    } else {
        stage_v_52 = (pub_r000776_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_52 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000776_17 & 63) > 46) {
        stage_v_53 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_53) & 255;
    } else {
        stage_v_53 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_53 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000776_5 & 63) > 40) {
        stage_v_54 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_54) & 255;
    } else {
        stage_v_54 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_54 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_12 & 63) > 55) {
        stage_v_55 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_55) & 255;
    } else {
        stage_v_55 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_55 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_41 & 63) > 32) {
        stage_v_56 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_56) & 255;
    } else {
        stage_v_56 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_56 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000776_7 & 63) > 31) {
        stage_v_57 = (pub_r000776_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_57) & 255;
    } else {
        stage_v_57 = (pub_r000776_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_57 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_21 & 63) > 16) {
        stage_v_58 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_58) & 255;
    } else {
        stage_v_58 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_58 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000776_15 & 63) > 52) {
        stage_v_59 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_59) & 255;
    } else {
        stage_v_59 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_59 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_49 & 63) > 32) {
        stage_v_60 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_60) & 255;
    } else {
        stage_v_60 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_60 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_55 & 63) > 34) {
        stage_v_61 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_61) & 255;
    } else {
        stage_v_61 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_61 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000776_5 & 63) > 30) {
        stage_v_62 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_62) & 255;
    } else {
        stage_v_62 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_62 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000776_11 & 63) > 33) {
        stage_v_63 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_63) & 255;
    } else {
        stage_v_63 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_63 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_60 & 63) > 51) {
        stage_v_64 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_64) & 255;
    } else {
        stage_v_64 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_64 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_50 & 63) > 56) {
        stage_v_65 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_65) & 255;
    } else {
        stage_v_65 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_65 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000776_16 & 63) > 45) {
        stage_v_66 = (pub_r000776_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_66) & 255;
    } else {
        stage_v_66 = (pub_r000776_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_66 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_25 & 63) > 17) {
        stage_v_67 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_67) & 255;
    } else {
        stage_v_67 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_67 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_30 & 63) > 45) {
        stage_v_68 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_68) & 255;
    } else {
        stage_v_68 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_68 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_68 & 63) > 47) {
        stage_v_69 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_69) & 255;
    } else {
        stage_v_69 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_69 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_55 & 63) > 46) {
        stage_v_70 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_70) & 255;
    } else {
        stage_v_70 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_70 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000776_8 & 63) > 34) {
        stage_v_71 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_71) & 255;
    } else {
        stage_v_71 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_71 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000776_13 & 63) > 46) {
        stage_v_72 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_72) & 255;
    } else {
        stage_v_72 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_72 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_12 & 63) > 17) {
        stage_v_73 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_73) & 255;
    } else {
        stage_v_73 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_73 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_27 & 63) > 35) {
        stage_v_74 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_74) & 255;
    } else {
        stage_v_74 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_74 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000776_7 & 63) > 59) {
        stage_v_75 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_75) & 255;
    } else {
        stage_v_75 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_75 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_33 & 63) > 43) {
        stage_v_76 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_76) & 255;
    } else {
        stage_v_76 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_76 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_54 & 63) > 30) {
        stage_v_77 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_77) & 255;
    } else {
        stage_v_77 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_77 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_39 & 63) > 39) {
        stage_v_78 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_78) & 255;
    } else {
        stage_v_78 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_78 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_13 & 63) > 55) {
        stage_v_79 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_79) & 255;
    } else {
        stage_v_79 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_79 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_54 & 63) > 43) {
        stage_v_80 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_80) & 255;
    } else {
        stage_v_80 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_80 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_44 & 63) > 27) {
        stage_v_81 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_81) & 255;
    } else {
        stage_v_81 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_81 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000776_8 & 63) > 15) {
        stage_v_82 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_82) & 255;
    } else {
        stage_v_82 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_82 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_61 & 63) > 32) {
        stage_v_83 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_83) & 255;
    } else {
        stage_v_83 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_83 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_25 & 63) > 34) {
        stage_v_84 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_84) & 255;
    } else {
        stage_v_84 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_84 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_45 & 63) > 33) {
        stage_v_85 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_85) & 255;
    } else {
        stage_v_85 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_85 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_39 & 63) > 32) {
        stage_v_86 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_86) & 255;
    } else {
        stage_v_86 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_86 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_45 & 63) > 60) {
        stage_v_87 = (pub_r000776_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_87) & 255;
    } else {
        stage_v_87 = (pub_r000776_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_87 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_43 & 63) > 46) {
        stage_v_88 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_88) & 255;
    } else {
        stage_v_88 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_88 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_74 & 63) > 29) {
        stage_v_89 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_89) & 255;
    } else {
        stage_v_89 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_89 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_44 & 63) > 41) {
        stage_v_90 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_90) & 255;
    } else {
        stage_v_90 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_90 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000776_8 & 63) > 55) {
        stage_v_91 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_91) & 255;
    } else {
        stage_v_91 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_91 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_28 & 63) > 23) {
        stage_v_92 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_92) & 255;
    } else {
        stage_v_92 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_92 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000776_5 & 63) > 20) {
        stage_v_93 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_93) & 255;
    } else {
        stage_v_93 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_93 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_83 & 63) > 40) {
        stage_v_94 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_94) & 255;
    } else {
        stage_v_94 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_94 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000776_6 & 63) > 37) {
        stage_v_95 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_95) & 255;
    } else {
        stage_v_95 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_95 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_95 & 63) > 37) {
        stage_v_96 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_96) & 255;
    } else {
        stage_v_96 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_96 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_57 & 63) > 53) {
        stage_v_97 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_97) & 255;
    } else {
        stage_v_97 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_97 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_30 & 63) > 32) {
        stage_v_98 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_98) & 255;
    } else {
        stage_v_98 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_98 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_25 & 63) > 35) {
        stage_v_99 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_99) & 255;
    } else {
        stage_v_99 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_99 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_65 & 63) > 56) {
        stage_v_100 = (pub_r000776_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_100) & 255;
    } else {
        stage_v_100 = (pub_r000776_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_100 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_92 & 63) > 38) {
        stage_v_101 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_101) & 255;
    } else {
        stage_v_101 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_101 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_45 & 63) > 27) {
        stage_v_102 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_102) & 255;
    } else {
        stage_v_102 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_102 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_57 & 63) > 49) {
        stage_v_103 = (pub_r000776_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_103) & 255;
    } else {
        stage_v_103 = (pub_r000776_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_103 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_89 & 63) > 19) {
        stage_v_104 = (pub_r000776_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_104) & 255;
    } else {
        stage_v_104 = (pub_r000776_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_104 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_17 & 63) > 37) {
        stage_v_105 = (pub_r000776_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_105) & 255;
    } else {
        stage_v_105 = (pub_r000776_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_105 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_27 & 63) > 37) {
        stage_v_106 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_106) & 255;
    } else {
        stage_v_106 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_106 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000776_5 & 63) > 34) {
        stage_v_107 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_107) & 255;
    } else {
        stage_v_107 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_107 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_18 & 63) > 19) {
        stage_v_108 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_108) & 255;
    } else {
        stage_v_108 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_108 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_98 & 63) > 49) {
        stage_v_109 = (pub_r000776_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_109) & 255;
    } else {
        stage_v_109 = (pub_r000776_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_109 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000776_2 & 63) > 49) {
        stage_v_110 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_110) & 255;
    } else {
        stage_v_110 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_110 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_23 & 63) > 30) {
        stage_v_111 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_111) & 255;
    } else {
        stage_v_111 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_111 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_62 & 63) > 25) {
        stage_v_112 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_112) & 255;
    } else {
        stage_v_112 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_112 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000776_0 & 63) > 26) {
        stage_v_113 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_113) & 255;
    } else {
        stage_v_113 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_113 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_21 & 63) > 21) {
        stage_v_114 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_114) & 255;
    } else {
        stage_v_114 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_114 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_110 & 63) > 23) {
        stage_v_115 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_115) & 255;
    } else {
        stage_v_115 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_115 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000776_13 & 63) > 59) {
        stage_v_116 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_116) & 255;
    } else {
        stage_v_116 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_116 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_112 & 63) > 33) {
        stage_v_117 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_117) & 255;
    } else {
        stage_v_117 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_117 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_92 & 63) > 33) {
        stage_v_118 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_118) & 255;
    } else {
        stage_v_118 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_118 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_57 & 63) > 58) {
        stage_v_119 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_119) & 255;
    } else {
        stage_v_119 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_119 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_77 & 63) > 25) {
        stage_v_120 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_120) & 255;
    } else {
        stage_v_120 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_120 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_104 & 63) > 31) {
        stage_v_121 = (pub_r000776_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_121) & 255;
    } else {
        stage_v_121 = (pub_r000776_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_121 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_98 & 63) > 16) {
        stage_v_122 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_122) & 255;
    } else {
        stage_v_122 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_122 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_30 & 63) > 29) {
        stage_v_123 = (pub_r000776_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_123) & 255;
    } else {
        stage_v_123 = (pub_r000776_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_123 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_46 & 63) > 58) {
        stage_v_124 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_124) & 255;
    } else {
        stage_v_124 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_124 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_43 & 63) > 47) {
        stage_v_125 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_125) & 255;
    } else {
        stage_v_125 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_125 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_45 & 63) > 44) {
        stage_v_126 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_126) & 255;
    } else {
        stage_v_126 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_126 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_71 & 63) > 18) {
        stage_v_127 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_127) & 255;
    } else {
        stage_v_127 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_127 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_31 & 63) > 38) {
        stage_v_128 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_128) & 255;
    } else {
        stage_v_128 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_128 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_114 & 63) > 26) {
        stage_v_129 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_129) & 255;
    } else {
        stage_v_129 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_129 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000776_13 & 63) > 18) {
        stage_v_130 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_130) & 255;
    } else {
        stage_v_130 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_130 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000776_6 & 63) > 18) {
        stage_v_131 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_131) & 255;
    } else {
        stage_v_131 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_131 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_85 & 63) > 45) {
        stage_v_132 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_132) & 255;
    } else {
        stage_v_132 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_132 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_72 & 63) > 30) {
        stage_v_133 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_133) & 255;
    } else {
        stage_v_133 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_133 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_110 & 63) > 22) {
        stage_v_134 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_134) & 255;
    } else {
        stage_v_134 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_134 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_14 & 63) > 28) {
        stage_v_135 = (pub_r000776_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_135) & 255;
    } else {
        stage_v_135 = (pub_r000776_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_135 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_109 & 63) > 24) {
        stage_v_136 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_136) & 255;
    } else {
        stage_v_136 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_136 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000776_14 & 63) > 44) {
        stage_v_137 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_137) & 255;
    } else {
        stage_v_137 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_137 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_66 & 63) > 37) {
        stage_v_138 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_138) & 255;
    } else {
        stage_v_138 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_138 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_55 & 63) > 15) {
        stage_v_139 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_139) & 255;
    } else {
        stage_v_139 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_139 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_62 & 63) > 59) {
        stage_v_140 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_140) & 255;
    } else {
        stage_v_140 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_140 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_19 & 63) > 42) {
        stage_v_141 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_141) & 255;
    } else {
        stage_v_141 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_141 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_122 & 63) > 27) {
        stage_v_142 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_142) & 255;
    } else {
        stage_v_142 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_142 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000776_4 & 63) > 59) {
        stage_v_143 = (pub_r000776_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_143) & 255;
    } else {
        stage_v_143 = (pub_r000776_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_143 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_95 & 63) > 17) {
        stage_v_144 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_144) & 255;
    } else {
        stage_v_144 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_144 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000776_17 & 63) > 36) {
        stage_v_145 = (pub_r000776_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_145) & 255;
    } else {
        stage_v_145 = (pub_r000776_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_145 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_39 & 63) > 16) {
        stage_v_146 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_146) & 255;
    } else {
        stage_v_146 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_146 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_91 & 63) > 15) {
        stage_v_147 = (pub_r000776_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_147) & 255;
    } else {
        stage_v_147 = (pub_r000776_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_147 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000776_12 & 63) > 19) {
        stage_v_148 = (pub_r000776_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_148) & 255;
    } else {
        stage_v_148 = (pub_r000776_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_148 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_97 & 63) > 30) {
        stage_v_149 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_149) & 255;
    } else {
        stage_v_149 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_149 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_21 & 63) > 48) {
        stage_v_150 = (pub_r000776_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_150) & 255;
    } else {
        stage_v_150 = (pub_r000776_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_150 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_48 & 63) > 54) {
        stage_v_151 = (pub_r000776_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_151) & 255;
    } else {
        stage_v_151 = (pub_r000776_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_151 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_115 & 63) > 53) {
        stage_v_152 = (pub_r000776_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_152) & 255;
    } else {
        stage_v_152 = (pub_r000776_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_152 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_48 & 63) > 17) {
        stage_v_153 = (pub_r000776_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_153) & 255;
    } else {
        stage_v_153 = (pub_r000776_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_153 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000776_8 & 63) > 49) {
        stage_v_154 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_154) & 255;
    } else {
        stage_v_154 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_154 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_12 & 63) > 44) {
        stage_v_155 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_155) & 255;
    } else {
        stage_v_155 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_155 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_67 & 63) > 58) {
        stage_v_156 = (pub_r000776_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_156) & 255;
    } else {
        stage_v_156 = (pub_r000776_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_156 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000776_2 & 63) > 19) {
        stage_v_157 = (pub_r000776_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_157) & 255;
    } else {
        stage_v_157 = (pub_r000776_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_157 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000776_0 & 63) > 27) {
        stage_v_158 = (pub_r000776_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_158) & 255;
    } else {
        stage_v_158 = (pub_r000776_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_158 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((sec_r000776_16 & 63) > 40) {
        stage_v_159 = (pub_r000776_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_159) & 255;
    } else {
        stage_v_159 = (pub_r000776_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_159 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
