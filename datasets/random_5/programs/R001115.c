/*
 * Benchmark Program: R001115
 * Security Family: bitwise_flow
 * Generator Seed: 611513
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001115_1513_0 {
    int sample_rate;
    int rms;
    unsigned char envelope;
    int buffer[3];
};

struct Vector3D_R001115_1513_1 {
    unsigned char norm_sq;
    int pitch;
    int coord_z;
    unsigned char coord_y;
    int buffer[3];
};

union ColorPixel_R001115_1513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001115_1513_0(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_69) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_53 = local_arr[aux % 3];
    acc = (acc + residue_53 * 2) & 127;
    int index_reg_64 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_64 = (index_reg_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_88 = (aux + st.buffer[1]) & 3;
    switch (vector_88) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001115_1513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_51 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_51 > 32) {
        acc = (acc + delta_51 * 2 + 5) & 127;
        aux ^= (delta_51 & 15);
    } else {
        acc = (acc - delta_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_21 = local_arr[aux % 3];
    acc = (acc + quantum_21 * 2) & 127;
    int index_reg_93 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_93 = (index_reg_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_93) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_3(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int accumulator_48 = (aux + st.buffer[1]) & 3;
    switch (accumulator_48) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_30 = local_arr[aux % 3];
    acc = (acc + tally_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_20 = local_arr[aux % 3];
    acc = (acc + mask_20 * 2) & 127;
    int sample_51 = 0;
    for (int k = 0; k < 2; k++) {
        sample_51 = (sample_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int offset_43 = (aux + st.buffer[1]) & 3;
    switch (offset_43) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_18 = local_arr[aux % 3];
    acc = (acc + quotient_18 * 2) & 127;
    int delta_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_18) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_6(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_85 = (aux + st.buffer[1]) & 3;
    switch (factor_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_7(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_45 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_45 > 50) {
        acc = (acc + factor_45 * 2 + 5) & 127;
        aux ^= (factor_45 & 15);
    } else {
        acc = (acc - factor_45 + 11) & 127;
        aux += 3;
    }
    int sample_81 = (aux + st.buffer[1]) & 3;
    switch (sample_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_58 = local_arr[aux % 3];
    acc = (acc + checksum_58 * 2) & 127;
    int quantum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001115_1513_8(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_46 = 0;
    for (int k = 0; k < 2; k++) {
        bound_46 = (bound_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_46) & 127;
    }
    int mask_29 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_29 > 20) {
        acc = (acc + mask_29 * 2 + 5) & 127;
        aux ^= (mask_29 & 15);
    } else {
        acc = (acc - mask_29 + 11) & 127;
        aux += 3;
    }
    int window_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_82) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001115_1513_9(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int vector_11 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_11 > 23) {
        acc = (acc + vector_11 * 2 + 5) & 127;
        aux ^= (vector_11 & 15);
    } else {
        acc = (acc - vector_11 + 11) & 127;
        aux += 3;
    }
    int checksum_23 = (aux + st.buffer[1]) & 3;
    switch (checksum_23) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_93 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_93 > 47) {
        acc = (acc + weight_93 * 2 + 5) & 127;
        aux ^= (weight_93 & 15);
    } else {
        acc = (acc - weight_93 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int phase_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_72) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_85 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_85 > 36) {
        acc = (acc + weight_85 * 2 + 5) & 127;
        aux ^= (weight_85 & 15);
    } else {
        acc = (acc - weight_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_12(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_26 = (aux + st.buffer[1]) & 3;
    switch (checksum_26) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_76) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_36 = local_arr[aux % 3];
    acc = (acc + pivot_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int metric_46 = (aux + st.buffer[1]) & 3;
    switch (metric_46) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001115_1513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int threshold_35 = local_arr[aux % 3];
    acc = (acc + threshold_35 * 2) & 127;
    int accumulator_71 = (aux + st.buffer[1]) & 3;
    switch (accumulator_71) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_61 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_61 = (cursor_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_15(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int mask_31 = local_arr[aux % 3];
    acc = (acc + mask_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001115_1513_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int delta_63 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_63 > 30) {
        acc = (acc + delta_63 * 2 + 5) & 127;
        aux ^= (delta_63 & 15);
    } else {
        acc = (acc - delta_63 + 11) & 127;
        aux += 3;
    }
    int vector_80 = 0;
    for (int k = 0; k < 3; k++) {
        vector_80 = (vector_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_80) & 127;
    }
    int parity_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001115_1513_17(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001115_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int threshold_21 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_21 = (threshold_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_21) & 127;
    }
    int accumulator_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_61 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_61 > 43) {
        acc = (acc + tally_61 * 2 + 5) & 127;
        aux ^= (tally_61 & 15);
    } else {
        acc = (acc - tally_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_18(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tracker_38 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_38 > 29) {
        acc = (acc + tracker_38 * 2 + 5) & 127;
        aux ^= (tracker_38 & 15);
    } else {
        acc = (acc - tracker_38 + 11) & 127;
        aux += 3;
    }
    int stride_47 = 0;
    for (int k = 0; k < 3; k++) {
        stride_47 = (stride_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_47) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int quotient_39 = local_arr[aux % 3];
    acc = (acc + quotient_39 * 2) & 127;
    int checksum_60 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_60 > 31) {
        acc = (acc + checksum_60 * 2 + 5) & 127;
        aux ^= (checksum_60 & 15);
    } else {
        acc = (acc - checksum_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001115_1513_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001115_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int margin_22 = local_arr[aux % 3];
    acc = (acc + margin_22 * 2) & 127;
    int quantum_65 = (aux + st.buffer[1]) & 3;
    switch (quantum_65) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_87 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_87 > 41) {
        acc = (acc + offset_87 * 2 + 5) & 127;
        aux ^= (offset_87 & 15);
    } else {
        acc = (acc - offset_87 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001115_0;
    int sec_r001115_1;
    int sec_r001115_2;
    int sec_r001115_3;
    int sec_r001115_4;
    int sec_r001115_5;
    int sec_r001115_6;
    int sec_r001115_7;
    int sec_r001115_8;
    int sec_r001115_9;
    int sec_r001115_10;
    int sec_r001115_11;
    int sec_r001115_12;
    int sec_r001115_13;
    int sec_r001115_14;
    int sec_r001115_15;
    int sec_r001115_16;
    int sec_r001115_17;
    int sec_r001115_18;
    int sec_r001115_19;
    int sec_r001115_20;
    int sec_r001115_21;
    int pub_r001115_0;
    int pub_r001115_1;
    int pub_r001115_2;
    int pub_r001115_3;
    int pub_r001115_4;
    int pub_r001115_5;
    int pub_r001115_6;
    int pub_r001115_7;
    int pub_r001115_8;
    int pub_r001115_9;
    int pub_r001115_10;
    int pub_r001115_11;
    int pub_r001115_12;
    int pub_r001115_13;
    int pub_r001115_14;
    int pub_r001115_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001115_0 >= -100 && pub_r001115_0 <= 100);
    __CPROVER_assume(pub_r001115_1 >= -100 && pub_r001115_1 <= 100);
    __CPROVER_assume(pub_r001115_2 >= -100 && pub_r001115_2 <= 100);
    __CPROVER_assume(pub_r001115_3 >= -100 && pub_r001115_3 <= 100);
    __CPROVER_assume(pub_r001115_4 >= -100 && pub_r001115_4 <= 100);
    __CPROVER_assume(pub_r001115_5 >= -100 && pub_r001115_5 <= 100);
    __CPROVER_assume(pub_r001115_6 >= -100 && pub_r001115_6 <= 100);
    __CPROVER_assume(pub_r001115_7 >= -100 && pub_r001115_7 <= 100);
    __CPROVER_assume(pub_r001115_8 >= -100 && pub_r001115_8 <= 100);
    __CPROVER_assume(pub_r001115_9 >= -100 && pub_r001115_9 <= 100);
    __CPROVER_assume(pub_r001115_10 >= -100 && pub_r001115_10 <= 100);
    __CPROVER_assume(pub_r001115_11 >= -100 && pub_r001115_11 <= 100);
    __CPROVER_assume(pub_r001115_12 >= -100 && pub_r001115_12 <= 100);
    __CPROVER_assume(pub_r001115_13 >= -100 && pub_r001115_13 <= 100);
    __CPROVER_assume(pub_r001115_14 >= -100 && pub_r001115_14 <= 100);
    __CPROVER_assume(pub_r001115_15 >= -100 && pub_r001115_15 <= 100);
    __CPROVER_assume(sec_r001115_0 >= 0 && sec_r001115_0 <= 255);
    __CPROVER_assume(sec_r001115_1 >= 0 && sec_r001115_1 <= 255);
    __CPROVER_assume(sec_r001115_2 >= 0 && sec_r001115_2 <= 255);
    __CPROVER_assume(sec_r001115_3 >= 0 && sec_r001115_3 <= 255);
    __CPROVER_assume(sec_r001115_4 >= 0 && sec_r001115_4 <= 255);
    __CPROVER_assume(sec_r001115_5 >= 0 && sec_r001115_5 <= 255);
    __CPROVER_assume(sec_r001115_6 >= 0 && sec_r001115_6 <= 255);
    __CPROVER_assume(sec_r001115_7 >= 0 && sec_r001115_7 <= 255);
    __CPROVER_assume(sec_r001115_8 >= 0 && sec_r001115_8 <= 255);
    __CPROVER_assume(sec_r001115_9 >= 0 && sec_r001115_9 <= 255);
    __CPROVER_assume(sec_r001115_10 >= 0 && sec_r001115_10 <= 255);
    __CPROVER_assume(sec_r001115_11 >= 0 && sec_r001115_11 <= 255);
    __CPROVER_assume(sec_r001115_12 >= 0 && sec_r001115_12 <= 255);
    __CPROVER_assume(sec_r001115_13 >= 0 && sec_r001115_13 <= 255);
    __CPROVER_assume(sec_r001115_14 >= 0 && sec_r001115_14 <= 255);
    __CPROVER_assume(sec_r001115_15 >= 0 && sec_r001115_15 <= 255);
    __CPROVER_assume(sec_r001115_16 >= 0 && sec_r001115_16 <= 255);
    __CPROVER_assume(sec_r001115_17 >= 0 && sec_r001115_17 <= 255);
    __CPROVER_assume(sec_r001115_18 >= 0 && sec_r001115_18 <= 255);
    __CPROVER_assume(sec_r001115_19 >= 0 && sec_r001115_19 <= 255);
    __CPROVER_assume(sec_r001115_20 >= 0 && sec_r001115_20 <= 255);
    __CPROVER_assume(sec_r001115_21 >= 0 && sec_r001115_21 <= 255);

    struct AudioFrame_R001115_1513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001115_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001115_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001115_0 + 7) & 15;
    struct Vector3D_R001115_1513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001115_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001115_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001115_0 + 9) & 15;

    union ColorPixel_R001115_1513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001115_1513_0(sec_r001115_0, sec_r001115_1, pub_r001115_2);
    int helper_flow_1 = fn_R001115_1513_1(sec_r001115_1, sec_r001115_2, pub_r001115_3, pub_r001115_4);
    int helper_flow_2 = fn_R001115_1513_2(sec_r001115_2, pub_r001115_3, pub_r001115_4, pub_r001115_5);
    int helper_flow_3 = fn_R001115_1513_3(sec_r001115_3, sec_r001115_4);
    int helper_flow_4 = fn_R001115_1513_4(sec_r001115_4, sec_r001115_5, pub_r001115_6, pub_r001115_7, pub_r001115_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001115_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001115_4 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001115_9 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001115_16 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001115_13 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((stage_v_2 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_5 + 1) & 15;
    out_sink ^= (stage_v_5 & 63);

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001115_15 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001115_20 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001115_1 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001115_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001115_7 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_1 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001115_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001115_14 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001115_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001115_13 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001115_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001115_3 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001115_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001115_1 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001115_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001115_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001115_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_1 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001115_14 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001115_12 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001115_7 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_13 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_27 + 1) & 15;
    out_sink ^= (stage_v_27 & 63);

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001115_16 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001115_4 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_11 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001115_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_29 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_10 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001115_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001115_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001115_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001115_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001115_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001115_7 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_28 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001115_6 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_6 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001115_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_15 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001115_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001115_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_5 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001115_5 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001115_16 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_29 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001115_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001115_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_6 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001115_3 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001115_9 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001115_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001115_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001115_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001115_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001115_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001115_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001115_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_5 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_28 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((helper_flow_1 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_5 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001115_3 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001115_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_47 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001115_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_48 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_69 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001115_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001115_12 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_13 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001115_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001115_17 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001115_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_29 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001115_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001115_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001115_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001115_13 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_74 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_75 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001115_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_28 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001115_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001115_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_72 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001115_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001115_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((helper_flow_0 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001115_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001115_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001115_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_53 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_75 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001115_11 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001115_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_17 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_8 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r001115_21 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001115_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_5 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_48 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001115_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_72 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001115_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001115_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_3 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001115_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001115_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001115_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001115_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001115_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001115_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_54 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001115_3 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001115_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001115_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001115_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001115_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001115_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001115_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001115_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_26 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_90 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001115_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_72 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_72 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001115_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((sec_r001115_4 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_28 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_55 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001115_14 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_63 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_137 + 1) & 15;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_30 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_138 + 1) & 15;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001115_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_137 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_54 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001115_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001115_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_102 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001115_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_13 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001115_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001115_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001115_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_54 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_32 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_10 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_101 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001115_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001115_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((helper_flow_4 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r001115_1 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001115_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001115_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_13 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r001115_20 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_27 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_8 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001115_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_161 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_77 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((helper_flow_0 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001115_12 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001115_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001115_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_128 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001115_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001115_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001115_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001115_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001115_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001115_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001115_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_10 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001115_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001115_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001115_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_28 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001115_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_183 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_79 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_138 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_2 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001115_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_151 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001115_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_131 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_98 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_15 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_161 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001115_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001115_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001115_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001115_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_25 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001115_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_137 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001115_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_53 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_33 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r001115_0 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_8 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001115_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001115_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_3 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001115_4 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_211 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r001115_20 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001115_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001115_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001115_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_171 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_204 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_48 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r001115_12 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_44 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001115_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001115_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_134 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_69 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001115_2 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_131 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_47 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_157 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001115_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001115_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001115_0 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001115_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_202 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001115_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001115_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_186 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_237 + 1) & 15;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001115_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001115_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r001115_7 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_50 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_150 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001115_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001115_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001115_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_4 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001115_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_25 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001115_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((sec_r001115_3 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001115_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001115_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_161 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r001115_17 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001115_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_103 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_108 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001115_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_5 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_205 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001115_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001115_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_85 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001115_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_211 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_69 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_240 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001115_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_7 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((sec_r001115_5 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001115_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001115_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_224 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001115_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001115_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r001115_17 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001115_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_263 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001115_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001115_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((sec_r001115_9 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001115_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001115_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001115_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_83 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001115_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_87 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001115_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_2 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001115_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_167 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((sec_r001115_20 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001115_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001115_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001115_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001115_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001115_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_27 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001115_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_27 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_257 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_151 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_106 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001115_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((sec_r001115_7 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001115_4 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_83 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_211 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_291 << 1) ^ (pub_r001115_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001115_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_41 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_210 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_8 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_270 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001115_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((sec_r001115_14 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001115_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_64 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_40 << 1) ^ (pub_r001115_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001115_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_313 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_194 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_224 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001115_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001115_8 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_108 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_194 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001115_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001115_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((sec_r001115_1 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_259 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001115_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_98 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_40 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_152 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001115_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001115_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((sec_r001115_20 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((sec_r001115_21 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_187 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001115_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001115_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001115_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001115_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001115_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001115_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_127 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_166 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001115_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((sec_r001115_14 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_289 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001115_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_105 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001115_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((sec_r001115_7 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_195 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001115_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_83 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001115_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_205 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001115_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001115_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001115_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001115_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_340 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001115_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001115_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001115_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001115_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_72 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001115_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_185 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001115_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_338 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_224 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_119 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((sec_r001115_15 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001115_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_338 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001115_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_11 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((helper_flow_1 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_99 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001115_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_316 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001115_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_240 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001115_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((sec_r001115_10 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = ((stage_v_192 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_390 + 1) & 15;
    out_sink ^= (stage_v_390 & 63);

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = (pub_r001115_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_391) & 127;

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((helper_flow_0 << 1) ^ (pub_r001115_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001115_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = (pub_r001115_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_394) & 127;

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((sec_r001115_5 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001115_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001115_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = ((sec_r001115_6 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_398 + 1) & 15;
    out_sink ^= (stage_v_398 & 63);

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001115_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_338 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001115_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001115_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_204 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_241 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_323 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001115_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001115_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001115_12 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((sec_r001115_10 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001115_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_348 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((sec_r001115_7 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001115_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_355 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001115_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_11 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_312 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_300 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_77 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_365 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001115_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001115_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_313 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_212 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_305 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_167 << 1) ^ (pub_r001115_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001115_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_8 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001115_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_338 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001115_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001115_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_64 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001115_3 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_423 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_217 << 1) ^ (pub_r001115_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_254 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_281 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_438 + 1) & 15;
    out_sink ^= (stage_v_438 & 63);

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001115_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = ((stage_v_411 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_440 + 1) & 15;
    out_sink ^= (stage_v_440 & 63);

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_375 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_339 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_26 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001115_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_111 << 1) ^ (pub_r001115_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_420 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001115_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = (pub_r001115_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_448) & 127;

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001115_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_28 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((sec_r001115_0 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001115_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001115_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = (pub_r001115_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_454) & 127;

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001115_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = ((stage_v_5 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_456 + 1) & 15;
    out_sink ^= (stage_v_456 & 63);

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001115_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = ((stage_v_221 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_458 + 1) & 15;
    out_sink ^= (stage_v_458 & 63);

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_42 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_65 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_97 << 1) ^ (pub_r001115_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_461 + 1) & 15;
    out_sink ^= (stage_v_461 & 63);

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_179 << 1) ^ (pub_r001115_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_319 << 1) ^ (pub_r001115_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_463 + 1) & 15;
    out_sink ^= (stage_v_463 & 63);

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = ((stage_v_29 << 1) ^ (pub_r001115_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_464 + 1) & 15;
    out_sink ^= (stage_v_464 & 63);

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_136 << 1) ^ (pub_r001115_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_465 + 1) & 15;
    out_sink ^= (stage_v_465 & 63);

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_403 << 1) ^ (pub_r001115_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_466 + 1) & 15;
    out_sink ^= (stage_v_466 & 63);

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_266 << 1) ^ (pub_r001115_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_79 << 1) ^ (pub_r001115_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001115_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001115_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001115_1 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_425 << 1) ^ (pub_r001115_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001115_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_102 << 1) ^ (pub_r001115_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_474 + 1) & 15;
    out_sink ^= (stage_v_474 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
