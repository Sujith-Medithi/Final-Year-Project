/*
 * Benchmark Program: R000087
 * Security Family: nested_implicit_flow
 * Generator Seed: 508713
 * High Inputs: 17 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000087_8713_0 {
    unsigned char heading;
    short norm_sq;
    unsigned char coord_x;
    int coord_z;
    unsigned char coord_y;
    int buffer[3];
};

struct Transaction_R000087_8713_1 {
    short account_id;
    int rate;
    short auth_code;
    unsigned char status;
    int buffer[3];
};

struct FilterState_R000087_8713_2 {
    unsigned char prev_out;
    short cutoff;
    int gain_db;
    int damping;
    int mode;
    unsigned char prev_in;
    int buffer[3];
};

union ColorPixel_R000087_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000087_8713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000087_8713_0(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int offset_97 = (aux + st.buffer[1]) & 3;
    switch (offset_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_24 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_24 > 14) {
        acc = (acc + weight_24 * 2 + 5) & 127;
        aux ^= (weight_24 & 15);
    } else {
        acc = (acc - weight_24 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000087_8713_1(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_75 > 26) {
        acc = (acc + cursor_75 * 2 + 5) & 127;
        aux ^= (cursor_75 & 15);
    } else {
        acc = (acc - cursor_75 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_81 = local_arr[aux % 3];
    acc = (acc + vector_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_2(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int cursor_21 = (aux + st.buffer[1]) & 3;
    switch (cursor_21) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int metric_51 = local_arr[aux % 3];
    acc = (acc + metric_51 * 2) & 127;
    int offset_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_59) & 63;
    acc ^= aux;
    int vector_65 = (aux + st.buffer[1]) & 3;
    switch (vector_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000087_8713_4(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int vector_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_94) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_99 = local_arr[aux % 3];
    acc = (acc + offset_99 * 2) & 127;
    int bound_75 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_75 > 33) {
        acc = (acc + bound_75 * 2 + 5) & 127;
        aux ^= (bound_75 & 15);
    } else {
        acc = (acc - bound_75 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int metric_41 = local_arr[aux % 3];
    acc = (acc + metric_41 * 2) & 127;
    int tracker_13 = (aux + st.buffer[1]) & 3;
    switch (tracker_13) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000087_8713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int bound_39 = local_arr[aux % 3];
    acc = (acc + bound_39 * 2) & 127;
    int anchor_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_14) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int index_reg_48 = (aux + st.buffer[1]) & 3;
    switch (index_reg_48) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_38 = (st.buffer[0] * 3 + aux) & 63;
    if (window_38 > 10) {
        acc = (acc + window_38 * 2 + 5) & 127;
        aux ^= (window_38 & 15);
    } else {
        acc = (acc - window_38 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_99 = local_arr[aux % 3];
    acc = (acc + metric_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int quantum_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_16 = local_arr[aux % 3];
    acc = (acc + coefficient_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_9(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_43) & 63;
    acc ^= aux;
    int quantum_93 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_93 > 32) {
        acc = (acc + quantum_93 * 2 + 5) & 127;
        aux ^= (quantum_93 & 15);
    } else {
        acc = (acc - quantum_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000087_8713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int stride_95 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_95 > 34) {
        acc = (acc + stride_95 * 2 + 5) & 127;
        aux ^= (stride_95 & 15);
    } else {
        acc = (acc - stride_95 + 11) & 127;
        aux += 3;
    }
    int coefficient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000087_8713_11(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int accumulator_61 = (aux + st.buffer[1]) & 3;
    switch (accumulator_61) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_93 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_93 > 42) {
        acc = (acc + index_reg_93 * 2 + 5) & 127;
        aux ^= (index_reg_93 & 15);
    } else {
        acc = (acc - index_reg_93 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_21 = local_arr[aux % 3];
    acc = (acc + sample_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int index_reg_15 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_15 > 23) {
        acc = (acc + index_reg_15 * 2 + 5) & 127;
        aux ^= (index_reg_15 & 15);
    } else {
        acc = (acc - index_reg_15 + 11) & 127;
        aux += 3;
    }
    int parity_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000087_8713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_42 = (aux + st.buffer[1]) & 3;
    switch (parity_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000087_8713_14(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int margin_57 = (aux + st.buffer[1]) & 3;
    switch (margin_57) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_43) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_71 = local_arr[aux % 3];
    acc = (acc + window_71 * 2) & 127;
    int offset_26 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_26 > 33) {
        acc = (acc + offset_26 * 2 + 5) & 127;
        aux ^= (offset_26 & 15);
    } else {
        acc = (acc - offset_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000087_8713_15(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int coefficient_71 = local_arr[aux % 3];
    acc = (acc + coefficient_71 * 2) & 127;
    int sample_27 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_27) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000087_8713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000087_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int weight_62 = (aux + st.buffer[1]) & 3;
    switch (weight_62) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_17 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_17 > 48) {
        acc = (acc + margin_17 * 2 + 5) & 127;
        aux ^= (margin_17 & 15);
    } else {
        acc = (acc - margin_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_92 = local_arr[aux % 3];
    acc = (acc + segment_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tracker_70 = local_arr[aux % 3];
    acc = (acc + tracker_70 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_14) & 63;
    acc ^= aux;
    int threshold_32 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_32 > 10) {
        acc = (acc + threshold_32 * 2 + 5) & 127;
        aux ^= (threshold_32 & 15);
    } else {
        acc = (acc - threshold_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000087_8713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int parity_57 = local_arr[aux % 3];
    acc = (acc + parity_57 * 2) & 127;
    int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_21) & 63;
    acc ^= aux;
    int residue_10 = (aux + st.buffer[1]) & 3;
    switch (residue_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_34 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_34 > 30) {
        acc = (acc + coefficient_34 * 2 + 5) & 127;
        aux ^= (coefficient_34 & 15);
    } else {
        acc = (acc - coefficient_34 + 11) & 127;
        aux += 3;
    }
    int stride_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000087_8713_20(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000087_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int index_reg_10 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_10 > 48) {
        acc = (acc + index_reg_10 * 2 + 5) & 127;
        aux ^= (index_reg_10 & 15);
    } else {
        acc = (acc - index_reg_10 + 11) & 127;
        aux += 3;
    }
    int scale_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_63) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_58 = local_arr[aux % 3];
    acc = (acc + quotient_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000087_8713_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000087_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_61 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_61 > 33) {
        acc = (acc + pivot_61 * 2 + 5) & 127;
        aux ^= (pivot_61 & 15);
    } else {
        acc = (acc - pivot_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_84 = local_arr[aux % 3];
    acc = (acc + weight_84 * 2) & 127;
    int delta_33 = (aux + st.buffer[1]) & 3;
    switch (delta_33) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000087_0;
    int sec_r000087_1;
    int sec_r000087_2;
    int sec_r000087_3;
    int sec_r000087_4;
    int sec_r000087_5;
    int sec_r000087_6;
    int sec_r000087_7;
    int sec_r000087_8;
    int sec_r000087_9;
    int sec_r000087_10;
    int sec_r000087_11;
    int sec_r000087_12;
    int sec_r000087_13;
    int sec_r000087_14;
    int sec_r000087_15;
    int sec_r000087_16;
    int pub_r000087_0;
    int pub_r000087_1;
    int pub_r000087_2;
    int pub_r000087_3;
    int pub_r000087_4;
    int pub_r000087_5;
    int pub_r000087_6;
    int pub_r000087_7;
    int pub_r000087_8;
    int pub_r000087_9;
    int pub_r000087_10;
    int pub_r000087_11;
    int pub_r000087_12;
    int pub_r000087_13;
    int pub_r000087_14;
    int pub_r000087_15;
    int pub_r000087_16;
    int pub_r000087_17;
    int pub_r000087_18;
    int pub_r000087_19;
    int pub_r000087_20;
    int pub_r000087_21;
    int pub_r000087_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000087_0 >= -100 && pub_r000087_0 <= 100);
    __CPROVER_assume(pub_r000087_1 >= -100 && pub_r000087_1 <= 100);
    __CPROVER_assume(pub_r000087_2 >= -100 && pub_r000087_2 <= 100);
    __CPROVER_assume(pub_r000087_3 >= -100 && pub_r000087_3 <= 100);
    __CPROVER_assume(pub_r000087_4 >= -100 && pub_r000087_4 <= 100);
    __CPROVER_assume(pub_r000087_5 >= -100 && pub_r000087_5 <= 100);
    __CPROVER_assume(pub_r000087_6 >= -100 && pub_r000087_6 <= 100);
    __CPROVER_assume(pub_r000087_7 >= -100 && pub_r000087_7 <= 100);
    __CPROVER_assume(pub_r000087_8 >= -100 && pub_r000087_8 <= 100);
    __CPROVER_assume(pub_r000087_9 >= -100 && pub_r000087_9 <= 100);
    __CPROVER_assume(pub_r000087_10 >= -100 && pub_r000087_10 <= 100);
    __CPROVER_assume(pub_r000087_11 >= -100 && pub_r000087_11 <= 100);
    __CPROVER_assume(pub_r000087_12 >= -100 && pub_r000087_12 <= 100);
    __CPROVER_assume(pub_r000087_13 >= -100 && pub_r000087_13 <= 100);
    __CPROVER_assume(pub_r000087_14 >= -100 && pub_r000087_14 <= 100);
    __CPROVER_assume(pub_r000087_15 >= -100 && pub_r000087_15 <= 100);
    __CPROVER_assume(pub_r000087_16 >= -100 && pub_r000087_16 <= 100);
    __CPROVER_assume(pub_r000087_17 >= -100 && pub_r000087_17 <= 100);
    __CPROVER_assume(pub_r000087_18 >= -100 && pub_r000087_18 <= 100);
    __CPROVER_assume(pub_r000087_19 >= -100 && pub_r000087_19 <= 100);
    __CPROVER_assume(pub_r000087_20 >= -100 && pub_r000087_20 <= 100);
    __CPROVER_assume(pub_r000087_21 >= -100 && pub_r000087_21 <= 100);
    __CPROVER_assume(pub_r000087_22 >= -100 && pub_r000087_22 <= 100);
    __CPROVER_assume(sec_r000087_0 >= 0 && sec_r000087_0 <= 255);
    __CPROVER_assume(sec_r000087_1 >= 0 && sec_r000087_1 <= 255);
    __CPROVER_assume(sec_r000087_2 >= 0 && sec_r000087_2 <= 255);
    __CPROVER_assume(sec_r000087_3 >= 0 && sec_r000087_3 <= 255);
    __CPROVER_assume(sec_r000087_4 >= 0 && sec_r000087_4 <= 255);
    __CPROVER_assume(sec_r000087_5 >= 0 && sec_r000087_5 <= 255);
    __CPROVER_assume(sec_r000087_6 >= 0 && sec_r000087_6 <= 255);
    __CPROVER_assume(sec_r000087_7 >= 0 && sec_r000087_7 <= 255);
    __CPROVER_assume(sec_r000087_8 >= 0 && sec_r000087_8 <= 255);
    __CPROVER_assume(sec_r000087_9 >= 0 && sec_r000087_9 <= 255);
    __CPROVER_assume(sec_r000087_10 >= 0 && sec_r000087_10 <= 255);
    __CPROVER_assume(sec_r000087_11 >= 0 && sec_r000087_11 <= 255);
    __CPROVER_assume(sec_r000087_12 >= 0 && sec_r000087_12 <= 255);
    __CPROVER_assume(sec_r000087_13 >= 0 && sec_r000087_13 <= 255);
    __CPROVER_assume(sec_r000087_14 >= 0 && sec_r000087_14 <= 255);
    __CPROVER_assume(sec_r000087_15 >= 0 && sec_r000087_15 <= 255);
    __CPROVER_assume(sec_r000087_16 >= 0 && sec_r000087_16 <= 255);

    struct Vector3D_R000087_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000087_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000087_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000087_0 + 7) & 15;
    struct Transaction_R000087_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000087_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000087_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000087_0 + 9) & 15;
    struct FilterState_R000087_8713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000087_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000087_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000087_0 + 11) & 15;

    union ColorPixel_R000087_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 10) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 25) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

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
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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
    if (stage_v_40 > 14) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 29) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

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
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 20) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 35) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 33) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 48) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000087_16 & 1) != 0) {
        if ((sec_r000087_11 & 2) != 0) {
            stage_v_70 = (pub_r000087_8 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000087_8 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000087_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000087_11 & 1) != 0) {
        if ((sec_r000087_14 & 2) != 0) {
            stage_v_71 = (pub_r000087_1 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000087_1 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000087_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000087_4 & 1) != 0) {
        if ((sec_r000087_3 & 2) != 0) {
            stage_v_72 = (pub_r000087_15 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000087_15 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000087_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000087_5 & 2) != 0) {
            stage_v_73 = (pub_r000087_21 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000087_21 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000087_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_74 = (pub_r000087_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000087_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000087_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000087_6 & 2) != 0) {
            stage_v_75 = (pub_r000087_5 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000087_5 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000087_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000087_3 & 2) != 0) {
            stage_v_76 = (pub_r000087_22 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000087_22 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000087_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000087_7 & 1) != 0) {
        if ((sec_r000087_16 & 2) != 0) {
            stage_v_77 = (pub_r000087_2 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000087_2 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000087_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000087_12 & 2) != 0) {
            stage_v_78 = (pub_r000087_14 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000087_14 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000087_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000087_1 & 2) != 0) {
            stage_v_79 = (pub_r000087_16 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000087_16 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000087_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000087_6 & 2) != 0) {
            stage_v_80 = (pub_r000087_7 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000087_7 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000087_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000087_7 & 2) != 0) {
            stage_v_81 = (pub_r000087_2 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000087_2 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000087_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000087_9 & 2) != 0) {
            stage_v_82 = (pub_r000087_11 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000087_11 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000087_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000087_0 & 2) != 0) {
            stage_v_83 = (pub_r000087_20 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000087_20 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000087_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000087_1 & 1) != 0) {
        if ((sec_r000087_5 & 2) != 0) {
            stage_v_84 = (pub_r000087_6 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000087_6 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000087_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_85 = (pub_r000087_21 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000087_21 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000087_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_86 = (pub_r000087_10 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000087_10 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000087_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000087_1 & 2) != 0) {
            stage_v_87 = (pub_r000087_16 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000087_16 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000087_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000087_15 & 1) != 0) {
        if ((sec_r000087_14 & 2) != 0) {
            stage_v_88 = (pub_r000087_1 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000087_1 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000087_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000087_9 & 2) != 0) {
            stage_v_89 = (pub_r000087_22 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000087_22 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000087_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000087_3 & 1) != 0) {
        if ((sec_r000087_15 & 2) != 0) {
            stage_v_90 = (pub_r000087_8 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000087_8 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000087_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000087_7 & 1) != 0) {
        if ((sec_r000087_15 & 2) != 0) {
            stage_v_91 = (pub_r000087_20 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000087_20 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000087_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000087_4 & 1) != 0) {
        if ((sec_r000087_11 & 2) != 0) {
            stage_v_92 = (pub_r000087_0 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000087_0 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000087_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000087_12 & 1) != 0) {
        if ((sec_r000087_2 & 2) != 0) {
            stage_v_93 = (pub_r000087_7 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000087_7 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000087_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000087_8 & 2) != 0) {
            stage_v_94 = (pub_r000087_14 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000087_14 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000087_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000087_8 & 2) != 0) {
            stage_v_95 = (pub_r000087_12 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000087_12 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000087_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_96 = (pub_r000087_4 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000087_4 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000087_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000087_7 & 2) != 0) {
            stage_v_97 = (pub_r000087_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000087_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000087_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000087_9 & 2) != 0) {
            stage_v_98 = (pub_r000087_1 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000087_1 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000087_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000087_8 & 1) != 0) {
        if ((sec_r000087_14 & 2) != 0) {
            stage_v_99 = (pub_r000087_6 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000087_6 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000087_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000087_3 & 2) != 0) {
            stage_v_100 = (pub_r000087_19 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000087_19 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000087_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000087_2 & 1) != 0) {
        if ((sec_r000087_12 & 2) != 0) {
            stage_v_101 = (pub_r000087_22 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000087_22 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000087_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000087_12 & 2) != 0) {
            stage_v_102 = (pub_r000087_4 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000087_4 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000087_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000087_8 & 1) != 0) {
        if ((sec_r000087_3 & 2) != 0) {
            stage_v_103 = (pub_r000087_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000087_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000087_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000087_0 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_104 = (pub_r000087_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000087_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000087_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000087_15 & 2) != 0) {
            stage_v_105 = (pub_r000087_8 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000087_8 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000087_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000087_14 & 2) != 0) {
            stage_v_106 = (pub_r000087_9 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000087_9 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000087_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000087_15 & 1) != 0) {
        if ((sec_r000087_5 & 2) != 0) {
            stage_v_107 = (pub_r000087_12 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000087_12 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000087_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000087_4 & 1) != 0) {
        if ((sec_r000087_7 & 2) != 0) {
            stage_v_108 = (pub_r000087_18 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000087_18 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000087_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000087_2 & 1) != 0) {
        if ((sec_r000087_8 & 2) != 0) {
            stage_v_109 = (pub_r000087_15 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000087_15 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000087_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000087_5 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_110 = (pub_r000087_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000087_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000087_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000087_0 & 1) != 0) {
        if ((sec_r000087_4 & 2) != 0) {
            stage_v_111 = (pub_r000087_11 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000087_11 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000087_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_112 = (pub_r000087_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000087_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000087_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000087_16 & 1) != 0) {
        if ((sec_r000087_9 & 2) != 0) {
            stage_v_113 = (pub_r000087_2 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000087_2 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000087_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000087_14 & 2) != 0) {
            stage_v_114 = (pub_r000087_22 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000087_22 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000087_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000087_8 & 2) != 0) {
            stage_v_115 = (pub_r000087_21 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000087_21 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000087_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000087_13 & 1) != 0) {
        if ((sec_r000087_12 & 2) != 0) {
            stage_v_116 = (pub_r000087_22 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000087_22 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000087_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000087_6 & 1) != 0) {
        if ((sec_r000087_9 & 2) != 0) {
            stage_v_117 = (pub_r000087_17 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000087_17 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000087_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_118 = (pub_r000087_4 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000087_4 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000087_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000087_13 & 2) != 0) {
            stage_v_119 = (pub_r000087_20 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000087_20 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000087_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000087_16 & 1) != 0) {
        if ((sec_r000087_15 & 2) != 0) {
            stage_v_120 = (pub_r000087_9 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000087_9 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000087_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000087_0 & 2) != 0) {
            stage_v_121 = (pub_r000087_7 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000087_7 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000087_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000087_4 & 2) != 0) {
            stage_v_122 = (pub_r000087_7 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000087_7 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000087_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000087_0 & 2) != 0) {
            stage_v_123 = (pub_r000087_17 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000087_17 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000087_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000087_10 & 1) != 0) {
        if ((sec_r000087_14 & 2) != 0) {
            stage_v_124 = (pub_r000087_5 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000087_5 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000087_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000087_10 & 1) != 0) {
        if ((sec_r000087_8 & 2) != 0) {
            stage_v_125 = (pub_r000087_13 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000087_13 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000087_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000087_5 & 2) != 0) {
            stage_v_126 = (pub_r000087_15 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000087_15 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000087_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000087_14 & 1) != 0) {
        if ((sec_r000087_15 & 2) != 0) {
            stage_v_127 = (pub_r000087_8 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000087_8 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000087_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000087_12 & 2) != 0) {
            stage_v_128 = (pub_r000087_15 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000087_15 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000087_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000087_1 & 2) != 0) {
            stage_v_129 = (pub_r000087_8 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000087_8 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000087_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000087_10 & 2) != 0) {
            stage_v_130 = (pub_r000087_9 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000087_9 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000087_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000087_15 & 2) != 0) {
            stage_v_131 = (pub_r000087_4 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000087_4 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000087_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000087_3 & 2) != 0) {
            stage_v_132 = (pub_r000087_22 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000087_22 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000087_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000087_6 & 2) != 0) {
            stage_v_133 = (pub_r000087_6 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000087_6 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000087_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000087_8 & 1) != 0) {
        if ((sec_r000087_5 & 2) != 0) {
            stage_v_134 = (pub_r000087_0 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000087_0 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000087_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000087_2 & 2) != 0) {
            stage_v_135 = (pub_r000087_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000087_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000087_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000087_4 & 1) != 0) {
        if ((sec_r000087_12 & 2) != 0) {
            stage_v_136 = (pub_r000087_3 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000087_3 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000087_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000087_12 & 1) != 0) {
        if ((sec_r000087_3 & 2) != 0) {
            stage_v_137 = (pub_r000087_19 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000087_19 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000087_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
