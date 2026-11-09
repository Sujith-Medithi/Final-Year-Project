/*
 * Benchmark Program: R001357
 * Security Family: nested_implicit_flow
 * Generator Seed: 635713
 * High Inputs: 19 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001357_5713_0 {
    int coord_x;
    int coord_z;
    unsigned char norm_sq;
    unsigned char heading;
    int coord_y;
    int buffer[3];
};

struct Transaction_R001357_5713_1 {
    int rate;
    short status;
    unsigned char balance;
    int fee;
    int account_id;
    int buffer[3];
};

union TelemetryField_R001357_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001357_5713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001357_5713_0(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int coefficient_24 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_24 > 35) {
        acc = (acc + coefficient_24 * 2 + 5) & 127;
        aux ^= (coefficient_24 & 15);
    } else {
        acc = (acc - coefficient_24 + 11) & 127;
        aux += 3;
    }
    int damping_26 = 0;
    for (int k = 0; k < 2; k++) {
        damping_26 = (damping_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_26) & 127;
    }
    int bound_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001357_5713_1(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quotient_53 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_53 > 50) {
        acc = (acc + quotient_53 * 2 + 5) & 127;
        aux ^= (quotient_53 & 15);
    } else {
        acc = (acc - quotient_53 + 11) & 127;
        aux += 3;
    }
    int threshold_97 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_97 = (threshold_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_45) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_88 = local_arr[aux % 3];
    acc = (acc + metric_88 * 2) & 127;
    int residue_71 = 0;
    for (int k = 0; k < 2; k++) {
        residue_71 = (residue_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_71) & 127;
    }
    int anchor_30 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_30 > 17) {
        acc = (acc + anchor_30 * 2 + 5) & 127;
        aux ^= (anchor_30 & 15);
    } else {
        acc = (acc - anchor_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_3(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_69 = (aux + st.buffer[1]) & 3;
    switch (delta_69) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_23 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_23 > 43) {
        acc = (acc + checksum_23 * 2 + 5) & 127;
        aux ^= (checksum_23 & 15);
    } else {
        acc = (acc - checksum_23 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_33 = local_arr[aux % 3];
    acc = (acc + pivot_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_4(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int pivot_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_59) & 63;
    acc ^= aux;
    int damping_37 = (aux + st.buffer[1]) & 3;
    switch (damping_37) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_5(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_64 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_64 = (quantum_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_64) & 127;
    }
    int cursor_78 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_78 > 50) {
        acc = (acc + cursor_78 * 2 + 5) & 127;
        aux ^= (cursor_78 & 15);
    } else {
        acc = (acc - cursor_78 + 11) & 127;
        aux += 3;
    }
    int window_28 = (aux + st.buffer[1]) & 3;
    switch (window_28) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_88 = local_arr[aux % 3];
    acc = (acc + damping_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_6(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int cursor_75 = local_arr[aux % 3];
    acc = (acc + cursor_75 * 2) & 127;
    int cursor_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_60) & 63;
    acc ^= aux;
    int delta_64 = 0;
    for (int k = 0; k < 3; k++) {
        delta_64 = (delta_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_7(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int tally_66 = local_arr[aux % 3];
    acc = (acc + tally_66 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_24 = (aux + st.buffer[1]) & 3;
    switch (threshold_24) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_8(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_14 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_14 > 12) {
        acc = (acc + quantum_14 * 2 + 5) & 127;
        aux ^= (quantum_14 & 15);
    } else {
        acc = (acc - quantum_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int mask_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_49 = local_arr[aux % 3];
    acc = (acc + margin_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_10(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_21 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_21 = (coefficient_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_21) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_59 = local_arr[aux % 3];
    acc = (acc + delta_59 * 2) & 127;
    int checksum_64 = (aux + st.buffer[1]) & 3;
    switch (checksum_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_11(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_14 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_14 > 41) {
        acc = (acc + delta_14 * 2 + 5) & 127;
        aux ^= (delta_14 & 15);
    } else {
        acc = (acc - delta_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_46 = local_arr[aux % 3];
    acc = (acc + anchor_46 * 2) & 127;
    int checksum_28 = (aux + st.buffer[1]) & 3;
    switch (checksum_28) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_64 = local_arr[aux % 3];
    acc = (acc + scale_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_61 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_61 > 30) {
        acc = (acc + index_reg_61 * 2 + 5) & 127;
        aux ^= (index_reg_61 & 15);
    } else {
        acc = (acc - index_reg_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_86 = local_arr[aux % 3];
    acc = (acc + accumulator_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int scale_84 = local_arr[aux % 3];
    acc = (acc + scale_84 * 2) & 127;
    int damping_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_37) & 63;
    acc ^= aux;
    int delta_94 = 0;
    for (int k = 0; k < 2; k++) {
        delta_94 = (delta_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_94) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int margin_39 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_39 > 49) {
        acc = (acc + margin_39 * 2 + 5) & 127;
        aux ^= (margin_39 & 15);
    } else {
        acc = (acc - margin_39 + 11) & 127;
        aux += 3;
    }
    int offset_58 = 0;
    for (int k = 0; k < 2; k++) {
        offset_58 = (offset_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_16(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int stride_40 = local_arr[aux % 3];
    acc = (acc + stride_40 * 2) & 127;
    int residue_81 = (aux + st.buffer[1]) & 3;
    switch (residue_81) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_88 = 0;
    for (int k = 0; k < 3; k++) {
        margin_88 = (margin_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_88) & 127;
    }
    int vector_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001357_5713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int margin_33 = 0;
    for (int k = 0; k < 2; k++) {
        margin_33 = (margin_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_33) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_68 = local_arr[aux % 3];
    acc = (acc + damping_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001357_5713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_81 = local_arr[aux % 3];
    acc = (acc + cursor_81 * 2) & 127;
    int scale_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_69) & 63;
    acc ^= aux;
    int anchor_88 = (aux + st.buffer[1]) & 3;
    switch (anchor_88) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001357_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int tally_56 = (aux + st.buffer[1]) & 3;
    switch (tally_56) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_22 = local_arr[aux % 3];
    acc = (acc + cursor_22 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_21 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_21 > 10) {
        acc = (acc + stride_21 * 2 + 5) & 127;
        aux ^= (stride_21 & 15);
    } else {
        acc = (acc - stride_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001357_5713_20(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001357_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int stride_44 = 0;
    for (int k = 0; k < 3; k++) {
        stride_44 = (stride_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_44) & 127;
    }
    int window_20 = (st.buffer[0] * 3 + aux) & 63;
    if (window_20 > 50) {
        acc = (acc + window_20 * 2 + 5) & 127;
        aux ^= (window_20 & 15);
    } else {
        acc = (acc - window_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001357_0;
    int sec_r001357_1;
    int sec_r001357_2;
    int sec_r001357_3;
    int sec_r001357_4;
    int sec_r001357_5;
    int sec_r001357_6;
    int sec_r001357_7;
    int sec_r001357_8;
    int sec_r001357_9;
    int sec_r001357_10;
    int sec_r001357_11;
    int sec_r001357_12;
    int sec_r001357_13;
    int sec_r001357_14;
    int sec_r001357_15;
    int sec_r001357_16;
    int sec_r001357_17;
    int sec_r001357_18;
    int pub_r001357_0;
    int pub_r001357_1;
    int pub_r001357_2;
    int pub_r001357_3;
    int pub_r001357_4;
    int pub_r001357_5;
    int pub_r001357_6;
    int pub_r001357_7;
    int pub_r001357_8;
    int pub_r001357_9;
    int pub_r001357_10;
    int pub_r001357_11;
    int pub_r001357_12;
    int pub_r001357_13;
    int pub_r001357_14;
    int pub_r001357_15;
    int pub_r001357_16;
    int pub_r001357_17;
    int pub_r001357_18;
    int pub_r001357_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001357_0 >= -100 && pub_r001357_0 <= 100);
    __CPROVER_assume(pub_r001357_1 >= -100 && pub_r001357_1 <= 100);
    __CPROVER_assume(pub_r001357_2 >= -100 && pub_r001357_2 <= 100);
    __CPROVER_assume(pub_r001357_3 >= -100 && pub_r001357_3 <= 100);
    __CPROVER_assume(pub_r001357_4 >= -100 && pub_r001357_4 <= 100);
    __CPROVER_assume(pub_r001357_5 >= -100 && pub_r001357_5 <= 100);
    __CPROVER_assume(pub_r001357_6 >= -100 && pub_r001357_6 <= 100);
    __CPROVER_assume(pub_r001357_7 >= -100 && pub_r001357_7 <= 100);
    __CPROVER_assume(pub_r001357_8 >= -100 && pub_r001357_8 <= 100);
    __CPROVER_assume(pub_r001357_9 >= -100 && pub_r001357_9 <= 100);
    __CPROVER_assume(pub_r001357_10 >= -100 && pub_r001357_10 <= 100);
    __CPROVER_assume(pub_r001357_11 >= -100 && pub_r001357_11 <= 100);
    __CPROVER_assume(pub_r001357_12 >= -100 && pub_r001357_12 <= 100);
    __CPROVER_assume(pub_r001357_13 >= -100 && pub_r001357_13 <= 100);
    __CPROVER_assume(pub_r001357_14 >= -100 && pub_r001357_14 <= 100);
    __CPROVER_assume(pub_r001357_15 >= -100 && pub_r001357_15 <= 100);
    __CPROVER_assume(pub_r001357_16 >= -100 && pub_r001357_16 <= 100);
    __CPROVER_assume(pub_r001357_17 >= -100 && pub_r001357_17 <= 100);
    __CPROVER_assume(pub_r001357_18 >= -100 && pub_r001357_18 <= 100);
    __CPROVER_assume(pub_r001357_19 >= -100 && pub_r001357_19 <= 100);
    __CPROVER_assume(sec_r001357_0 >= 0 && sec_r001357_0 <= 255);
    __CPROVER_assume(sec_r001357_1 >= 0 && sec_r001357_1 <= 255);
    __CPROVER_assume(sec_r001357_2 >= 0 && sec_r001357_2 <= 255);
    __CPROVER_assume(sec_r001357_3 >= 0 && sec_r001357_3 <= 255);
    __CPROVER_assume(sec_r001357_4 >= 0 && sec_r001357_4 <= 255);
    __CPROVER_assume(sec_r001357_5 >= 0 && sec_r001357_5 <= 255);
    __CPROVER_assume(sec_r001357_6 >= 0 && sec_r001357_6 <= 255);
    __CPROVER_assume(sec_r001357_7 >= 0 && sec_r001357_7 <= 255);
    __CPROVER_assume(sec_r001357_8 >= 0 && sec_r001357_8 <= 255);
    __CPROVER_assume(sec_r001357_9 >= 0 && sec_r001357_9 <= 255);
    __CPROVER_assume(sec_r001357_10 >= 0 && sec_r001357_10 <= 255);
    __CPROVER_assume(sec_r001357_11 >= 0 && sec_r001357_11 <= 255);
    __CPROVER_assume(sec_r001357_12 >= 0 && sec_r001357_12 <= 255);
    __CPROVER_assume(sec_r001357_13 >= 0 && sec_r001357_13 <= 255);
    __CPROVER_assume(sec_r001357_14 >= 0 && sec_r001357_14 <= 255);
    __CPROVER_assume(sec_r001357_15 >= 0 && sec_r001357_15 <= 255);
    __CPROVER_assume(sec_r001357_16 >= 0 && sec_r001357_16 <= 255);
    __CPROVER_assume(sec_r001357_17 >= 0 && sec_r001357_17 <= 255);
    __CPROVER_assume(sec_r001357_18 >= 0 && sec_r001357_18 <= 255);

    struct Vector3D_R001357_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001357_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001357_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001357_0 + 7) & 15;
    struct Transaction_R001357_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001357_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001357_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001357_0 + 9) & 15;

    union TelemetryField_R001357_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001357_5713_0(sec_r001357_0, sec_r001357_1);
    int helper_flow_1 = fn_R001357_5713_1(sec_r001357_1, pub_r001357_2);
    int helper_flow_2 = fn_R001357_5713_2(sec_r001357_2, sec_r001357_3, pub_r001357_4, pub_r001357_5);
    int helper_flow_3 = fn_R001357_5713_3(sec_r001357_3, sec_r001357_4, pub_r001357_5);
    int helper_flow_4 = fn_R001357_5713_4(sec_r001357_4, sec_r001357_5, pub_r001357_6);
    int helper_flow_5 = fn_R001357_5713_5(sec_r001357_5, sec_r001357_6);
    int helper_flow_6 = fn_R001357_5713_6(sec_r001357_6, sec_r001357_7, pub_r001357_8);
    int helper_flow_7 = fn_R001357_5713_7(sec_r001357_7, pub_r001357_8);
    int helper_flow_8 = fn_R001357_5713_8(sec_r001357_8, sec_r001357_9);
    int helper_flow_9 = fn_R001357_5713_9(sec_r001357_9, sec_r001357_10, pub_r001357_11, pub_r001357_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_0 ^ pub_r001357_6) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001357_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_9 ^ pub_r001357_16) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001357_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_2 ^ pub_r001357_12) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001357_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001357_8 ^ pub_r001357_3) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001357_10 ^ pub_r001357_4) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001357_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001357_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001357_17 ^ pub_r001357_19) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001357_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001357_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001357_16 ^ pub_r001357_5) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001357_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001357_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_1 ^ pub_r001357_12) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001357_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001357_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001357_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001357_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001357_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_7 ^ pub_r001357_17) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001357_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001357_3 ^ pub_r001357_8) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001357_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001357_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001357_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001357_15 ^ pub_r001357_17) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001357_7 ^ pub_r001357_13) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_20 ^ pub_r001357_4) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001357_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (helper_flow_9 ^ pub_r001357_12) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001357_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_8 ^ pub_r001357_18) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_7 ^ pub_r001357_16) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001357_18 ^ pub_r001357_0) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001357_16 ^ pub_r001357_12) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001357_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_3 ^ pub_r001357_10) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_6 ^ pub_r001357_7) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001357_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001357_9 ^ pub_r001357_13) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_22 ^ pub_r001357_12) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r001357_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_5 ^ pub_r001357_12) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001357_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001357_3 ^ pub_r001357_14) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001357_5 ^ pub_r001357_17) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_32 ^ pub_r001357_15) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (sec_r001357_2 ^ pub_r001357_18) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001357_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_24 ^ pub_r001357_10) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001357_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001357_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001357_15 ^ pub_r001357_5) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001357_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_37 ^ pub_r001357_1) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r001357_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001357_17 ^ pub_r001357_0) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_9 ^ pub_r001357_5) & 63;
    if ((stage_v_45 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_45 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_45 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001357_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_33 ^ pub_r001357_0) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r001357_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001357_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_1 ^ pub_r001357_19) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_44 ^ pub_r001357_1) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r001357_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (helper_flow_8 ^ pub_r001357_8) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001357_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_23 ^ pub_r001357_5) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001357_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r001357_5 ^ pub_r001357_15) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_29 ^ pub_r001357_10) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001357_13 ^ pub_r001357_9) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_28 ^ pub_r001357_19) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_3 ^ pub_r001357_9) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001357_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_24 ^ pub_r001357_15) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001357_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_59 ^ pub_r001357_11) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001357_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001357_5 ^ pub_r001357_7) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_54 ^ pub_r001357_8) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r001357_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_43 ^ pub_r001357_3) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001357_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_53 ^ pub_r001357_10) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_21 ^ pub_r001357_1) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_64 ^ pub_r001357_19) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001357_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_21 ^ pub_r001357_19) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_51 ^ pub_r001357_17) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001357_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001357_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001357_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001357_18 ^ pub_r001357_19) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r001357_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (helper_flow_5 ^ pub_r001357_13) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001357_12 ^ pub_r001357_12) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_34 ^ pub_r001357_2) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001357_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_4 ^ pub_r001357_14) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001357_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001357_0 ^ pub_r001357_1) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r001357_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_27 ^ pub_r001357_3) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001357_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_44 ^ pub_r001357_13) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r001357_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001357_5 ^ pub_r001357_10) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_4 ^ pub_r001357_3) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001357_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001357_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_21 ^ pub_r001357_2) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001357_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001357_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001357_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_75 ^ pub_r001357_6) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001357_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001357_16 ^ pub_r001357_18) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001357_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001357_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_15 ^ pub_r001357_16) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001357_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_55 ^ pub_r001357_7) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (sec_r001357_6 ^ pub_r001357_4) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001357_8 ^ pub_r001357_16) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (helper_flow_0 ^ pub_r001357_1) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r001357_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001357_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001357_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_35 ^ pub_r001357_14) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r001357_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_6 ^ pub_r001357_8) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_52 ^ pub_r001357_10) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_106 ^ pub_r001357_16) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r001357_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001357_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_84 ^ pub_r001357_9) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_55 ^ pub_r001357_11) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_20 ^ pub_r001357_9) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (helper_flow_9 ^ pub_r001357_4) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_45 ^ pub_r001357_19) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_99 ^ pub_r001357_16) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_112 ^ pub_r001357_4) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_10 ^ pub_r001357_9) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001357_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_112 ^ pub_r001357_16) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001357_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_33 ^ pub_r001357_13) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_53 ^ pub_r001357_1) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001357_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001357_10 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_41 ^ pub_r001357_7) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_45 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (helper_flow_2 ^ pub_r001357_0) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_55 ^ pub_r001357_3) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r001357_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_29 ^ pub_r001357_8) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001357_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001357_1 ^ pub_r001357_6) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (helper_flow_9 ^ pub_r001357_15) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r001357_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_121 ^ pub_r001357_4) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_100 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_8 ^ pub_r001357_7) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001357_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001357_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_59 ^ pub_r001357_0) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (sec_r001357_2 ^ pub_r001357_17) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001357_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001357_10 ^ pub_r001357_4) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r001357_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001357_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_71 ^ pub_r001357_6) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (helper_flow_1 ^ pub_r001357_17) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_35 ^ pub_r001357_19) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001357_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001357_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001357_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_47 ^ pub_r001357_17) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001357_5 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001357_0 ^ pub_r001357_14) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_105 ^ pub_r001357_0) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_115 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_78 ^ pub_r001357_15) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (sec_r001357_11 ^ pub_r001357_4) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_151 ^ pub_r001357_15) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_149 ^ pub_r001357_10) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001357_11 ^ pub_r001357_10) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_86 ^ pub_r001357_16) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_45 ^ pub_r001357_4) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001357_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_8 ^ pub_r001357_8) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_154 ^ pub_r001357_17) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_1 ^ pub_r001357_1) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001357_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_76 ^ pub_r001357_3) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001357_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001357_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_21 ^ pub_r001357_14) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001357_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001357_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_36 ^ pub_r001357_2) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((sec_r001357_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (sec_r001357_16 ^ pub_r001357_17) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_78 ^ pub_r001357_4) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_168 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_124 ^ pub_r001357_4) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_118 ^ pub_r001357_12) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001357_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_85 ^ pub_r001357_5) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((sec_r001357_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001357_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_131 ^ pub_r001357_16) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (sec_r001357_2 ^ pub_r001357_9) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_136 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_57 ^ pub_r001357_11) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001357_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_64 ^ pub_r001357_15) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_109 ^ pub_r001357_16) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001357_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_63 ^ pub_r001357_19) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_141 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_101 ^ pub_r001357_8) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_171 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_101 ^ pub_r001357_8) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001357_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001357_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001357_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001357_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_21 ^ pub_r001357_11) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001357_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001357_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (helper_flow_2 ^ pub_r001357_0) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_121 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001357_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001357_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001357_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001357_3 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001357_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (sec_r001357_14 ^ pub_r001357_11) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_112 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (sec_r001357_3 ^ pub_r001357_12) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((stage_v_76 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001357_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001357_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001357_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_178 ^ pub_r001357_12) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_116 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001357_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_1 ^ pub_r001357_15) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((sec_r001357_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_118 ^ pub_r001357_13) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_76 ^ pub_r001357_11) & 63;
    if ((stage_v_208 & 1) != 0) {
        if ((sec_r001357_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_208 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_208 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_32 ^ pub_r001357_13) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001357_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_29 ^ pub_r001357_8) & 63;
    if ((stage_v_211 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_211 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_211 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (sec_r001357_11 ^ pub_r001357_16) & 63;
    if ((stage_v_212 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_212 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_212 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_107 ^ pub_r001357_8) & 63;
    if ((stage_v_213 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_213 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_213 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_27 ^ pub_r001357_13) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001357_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_184 ^ pub_r001357_15) & 63;
    if ((stage_v_216 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_216 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_216 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
