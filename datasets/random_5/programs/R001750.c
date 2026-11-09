/*
 * Benchmark Program: R001750
 * Security Family: mixed_control_data
 * Generator Seed: 675013
 * High Inputs: 17 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001750_5013_0 {
    short coord_y;
    short coord_z;
    unsigned char coord_x;
    int norm_sq;
    int heading;
    int buffer[3];
};

struct CipherContext_R001750_5013_1 {
    unsigned char iv;
    short counter;
    int tag;
    short nonce;
    int flags;
    int round_key;
    int buffer[3];
};

union RegisterBank_R001750_5013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001750_5013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int tracker_87 = (aux + st.buffer[1]) & 3;
    switch (tracker_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_13 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_13 = (pivot_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_13) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_30 = local_arr[aux % 3];
    acc = (acc + phase_30 * 2) & 127;
    int weight_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001750_5013_1(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_59 > 22) {
        acc = (acc + cursor_59 * 2 + 5) & 127;
        aux ^= (cursor_59 & 15);
    } else {
        acc = (acc - cursor_59 + 11) & 127;
        aux += 3;
    }
    int offset_95 = (aux + st.buffer[1]) & 3;
    switch (offset_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001750_5013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int offset_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_73 = local_arr[aux % 3];
    acc = (acc + index_reg_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_61 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_61 > 16) {
        acc = (acc + bound_61 * 2 + 5) & 127;
        aux ^= (bound_61 & 15);
    } else {
        acc = (acc - bound_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_44 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_44 > 16) {
        acc = (acc + offset_44 * 2 + 5) & 127;
        aux ^= (offset_44 & 15);
    } else {
        acc = (acc - offset_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_66 = local_arr[aux % 3];
    acc = (acc + vector_66 * 2) & 127;
    int damping_76 = (aux + st.buffer[1]) & 3;
    switch (damping_76) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_4(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int index_reg_78 = local_arr[aux % 3];
    acc = (acc + index_reg_78 * 2) & 127;
    int pivot_14 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_14 > 14) {
        acc = (acc + pivot_14 * 2 + 5) & 127;
        aux ^= (pivot_14 & 15);
    } else {
        acc = (acc - pivot_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_10 = (aux + st.buffer[1]) & 3;
    switch (bound_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_5(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_90 = 0;
    for (int k = 0; k < 3; k++) {
        segment_90 = (segment_90 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_90) & 127;
    }
    int factor_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_90) & 63;
    acc ^= aux;
    int phase_46 = (aux + st.buffer[1]) & 3;
    switch (phase_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_55 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_55 > 10) {
        acc = (acc + scale_55 * 2 + 5) & 127;
        aux ^= (scale_55 & 15);
    } else {
        acc = (acc - scale_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_11 = local_arr[aux % 3];
    acc = (acc + weight_11 * 2) & 127;
    int scale_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001750_5013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int tracker_37 = local_arr[aux % 3];
    acc = (acc + tracker_37 * 2) & 127;
    int residue_10 = 0;
    for (int k = 0; k < 2; k++) {
        residue_10 = (residue_10 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_10) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_44 = (aux + st.buffer[1]) & 3;
    switch (index_reg_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_58 = local_arr[aux % 3];
    acc = (acc + parity_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001750_5013_9(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_28) & 63;
    acc ^= aux;
    int sample_83 = 0;
    for (int k = 0; k < 2; k++) {
        sample_83 = (sample_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001750_5013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int index_reg_20 = local_arr[aux % 3];
    acc = (acc + index_reg_20 * 2) & 127;
    int damping_56 = 0;
    for (int k = 0; k < 2; k++) {
        damping_56 = (damping_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_56) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001750_5013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_81 = (aux + st.buffer[1]) & 3;
    switch (scale_81) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_43 = local_arr[aux % 3];
    acc = (acc + weight_43 * 2) & 127;
    int threshold_39 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_39 = (threshold_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_13(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_43 = local_arr[aux % 3];
    acc = (acc + segment_43 * 2) & 127;
    int parity_27 = 0;
    for (int k = 0; k < 3; k++) {
        parity_27 = (parity_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_27) & 127;
    }
    int anchor_94 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_94 > 38) {
        acc = (acc + anchor_94 * 2 + 5) & 127;
        aux ^= (anchor_94 & 15);
    } else {
        acc = (acc - anchor_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_14(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_80 > 32) {
        acc = (acc + tally_80 * 2 + 5) & 127;
        aux ^= (tally_80 & 15);
    } else {
        acc = (acc - tally_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int damping_45 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_45 > 46) {
        acc = (acc + damping_45 * 2 + 5) & 127;
        aux ^= (damping_45 & 15);
    } else {
        acc = (acc - damping_45 + 11) & 127;
        aux += 3;
    }
    int stride_92 = 0;
    for (int k = 0; k < 2; k++) {
        stride_92 = (stride_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_92) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_16(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int vector_55 = 0;
    for (int k = 0; k < 2; k++) {
        vector_55 = (vector_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_55) & 127;
    }
    int metric_47 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_47 > 44) {
        acc = (acc + metric_47 * 2 + 5) & 127;
        aux ^= (metric_47 & 15);
    } else {
        acc = (acc - metric_47 + 11) & 127;
        aux += 3;
    }
    int segment_94 = (aux + st.buffer[1]) & 3;
    switch (segment_94) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001750_5013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_39 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_39 > 14) {
        acc = (acc + checksum_39 * 2 + 5) & 127;
        aux ^= (checksum_39 & 15);
    } else {
        acc = (acc - checksum_39 + 11) & 127;
        aux += 3;
    }
    int coefficient_90 = (aux + st.buffer[1]) & 3;
    switch (coefficient_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_38 = local_arr[aux % 3];
    acc = (acc + residue_38 * 2) & 127;
    int damping_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001750_5013_18(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001750_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int factor_72 = local_arr[aux % 3];
    acc = (acc + factor_72 * 2) & 127;
    int phase_21 = (aux + st.buffer[1]) & 3;
    switch (phase_21) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_19 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_19 > 29) {
        acc = (acc + coefficient_19 * 2 + 5) & 127;
        aux ^= (coefficient_19 & 15);
    } else {
        acc = (acc - coefficient_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001750_5013_19(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001750_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_93) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_42 = local_arr[aux % 3];
    acc = (acc + parity_42 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001750_0;
    int sec_r001750_1;
    int sec_r001750_2;
    int sec_r001750_3;
    int sec_r001750_4;
    int sec_r001750_5;
    int sec_r001750_6;
    int sec_r001750_7;
    int sec_r001750_8;
    int sec_r001750_9;
    int sec_r001750_10;
    int sec_r001750_11;
    int sec_r001750_12;
    int sec_r001750_13;
    int sec_r001750_14;
    int sec_r001750_15;
    int sec_r001750_16;
    int pub_r001750_0;
    int pub_r001750_1;
    int pub_r001750_2;
    int pub_r001750_3;
    int pub_r001750_4;
    int pub_r001750_5;
    int pub_r001750_6;
    int pub_r001750_7;
    int pub_r001750_8;
    int pub_r001750_9;
    int pub_r001750_10;
    int pub_r001750_11;
    int pub_r001750_12;
    int pub_r001750_13;
    int pub_r001750_14;
    int pub_r001750_15;
    int pub_r001750_16;
    int pub_r001750_17;
    int pub_r001750_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001750_0 >= -100 && pub_r001750_0 <= 100);
    __CPROVER_assume(pub_r001750_1 >= -100 && pub_r001750_1 <= 100);
    __CPROVER_assume(pub_r001750_2 >= -100 && pub_r001750_2 <= 100);
    __CPROVER_assume(pub_r001750_3 >= -100 && pub_r001750_3 <= 100);
    __CPROVER_assume(pub_r001750_4 >= -100 && pub_r001750_4 <= 100);
    __CPROVER_assume(pub_r001750_5 >= -100 && pub_r001750_5 <= 100);
    __CPROVER_assume(pub_r001750_6 >= -100 && pub_r001750_6 <= 100);
    __CPROVER_assume(pub_r001750_7 >= -100 && pub_r001750_7 <= 100);
    __CPROVER_assume(pub_r001750_8 >= -100 && pub_r001750_8 <= 100);
    __CPROVER_assume(pub_r001750_9 >= -100 && pub_r001750_9 <= 100);
    __CPROVER_assume(pub_r001750_10 >= -100 && pub_r001750_10 <= 100);
    __CPROVER_assume(pub_r001750_11 >= -100 && pub_r001750_11 <= 100);
    __CPROVER_assume(pub_r001750_12 >= -100 && pub_r001750_12 <= 100);
    __CPROVER_assume(pub_r001750_13 >= -100 && pub_r001750_13 <= 100);
    __CPROVER_assume(pub_r001750_14 >= -100 && pub_r001750_14 <= 100);
    __CPROVER_assume(pub_r001750_15 >= -100 && pub_r001750_15 <= 100);
    __CPROVER_assume(pub_r001750_16 >= -100 && pub_r001750_16 <= 100);
    __CPROVER_assume(pub_r001750_17 >= -100 && pub_r001750_17 <= 100);
    __CPROVER_assume(pub_r001750_18 >= -100 && pub_r001750_18 <= 100);
    __CPROVER_assume(sec_r001750_0 >= 0 && sec_r001750_0 <= 255);
    __CPROVER_assume(sec_r001750_1 >= 0 && sec_r001750_1 <= 255);
    __CPROVER_assume(sec_r001750_2 >= 0 && sec_r001750_2 <= 255);
    __CPROVER_assume(sec_r001750_3 >= 0 && sec_r001750_3 <= 255);
    __CPROVER_assume(sec_r001750_4 >= 0 && sec_r001750_4 <= 255);
    __CPROVER_assume(sec_r001750_5 >= 0 && sec_r001750_5 <= 255);
    __CPROVER_assume(sec_r001750_6 >= 0 && sec_r001750_6 <= 255);
    __CPROVER_assume(sec_r001750_7 >= 0 && sec_r001750_7 <= 255);
    __CPROVER_assume(sec_r001750_8 >= 0 && sec_r001750_8 <= 255);
    __CPROVER_assume(sec_r001750_9 >= 0 && sec_r001750_9 <= 255);
    __CPROVER_assume(sec_r001750_10 >= 0 && sec_r001750_10 <= 255);
    __CPROVER_assume(sec_r001750_11 >= 0 && sec_r001750_11 <= 255);
    __CPROVER_assume(sec_r001750_12 >= 0 && sec_r001750_12 <= 255);
    __CPROVER_assume(sec_r001750_13 >= 0 && sec_r001750_13 <= 255);
    __CPROVER_assume(sec_r001750_14 >= 0 && sec_r001750_14 <= 255);
    __CPROVER_assume(sec_r001750_15 >= 0 && sec_r001750_15 <= 255);
    __CPROVER_assume(sec_r001750_16 >= 0 && sec_r001750_16 <= 255);

    struct Vector3D_R001750_5013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001750_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001750_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001750_0 + 7) & 15;
    struct CipherContext_R001750_5013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001750_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001750_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001750_0 + 9) & 15;

    union RegisterBank_R001750_5013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001750_5013_0(sec_r001750_0, sec_r001750_1, pub_r001750_2, pub_r001750_3);
    int helper_flow_1 = fn_R001750_5013_1(sec_r001750_1, pub_r001750_2, pub_r001750_3);
    int helper_flow_2 = fn_R001750_5013_2(sec_r001750_2, sec_r001750_3, pub_r001750_4, pub_r001750_5);
    int helper_flow_3 = fn_R001750_5013_3(sec_r001750_3, pub_r001750_4, pub_r001750_5, pub_r001750_6);
    int helper_flow_4 = fn_R001750_5013_4(sec_r001750_4, pub_r001750_5, pub_r001750_6);
    int helper_flow_5 = fn_R001750_5013_5(sec_r001750_5, pub_r001750_6);
    int helper_flow_6 = fn_R001750_5013_6(sec_r001750_6, sec_r001750_7, pub_r001750_8, pub_r001750_9);
    int helper_flow_7 = fn_R001750_5013_7(sec_r001750_7, sec_r001750_8, pub_r001750_9, pub_r001750_10, pub_r001750_11);
    int helper_flow_8 = fn_R001750_5013_8(sec_r001750_8, sec_r001750_9, pub_r001750_10, pub_r001750_11);
    int helper_flow_9 = fn_R001750_5013_9(sec_r001750_9, sec_r001750_10, pub_r001750_11);
    int helper_flow_10 = fn_R001750_5013_10(sec_r001750_10, sec_r001750_11, pub_r001750_12, pub_r001750_13, pub_r001750_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001750_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001750_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001750_13 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_2 > 25) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001750_3 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_3 > 41) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001750_2 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_4 > 20) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_5 > 32) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_6 > 47) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001750_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001750_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001750_11 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_9 > 41) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_10 > 34) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001750_3 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_11 > 35) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_12 > 38) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001750_4 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_13 > 33) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_14 > 21) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_15 > 39) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001750_6 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_16 > 39) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001750_2 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_17 > 43) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_18 > 42) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001750_4) & 127;
    if (stage_v_19 > 36) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001750_2 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_20 > 29) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001750_8 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_21 > 34) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_22 > 33) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001750_3 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_23 > 23) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_24 > 29) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001750_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_26 > 46) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001750_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001750_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001750_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_30 > 27) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_31 > 47) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_32 > 25) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_33 > 41) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001750_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001750_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_36 > 20) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001750_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001750_8 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_38 > 50) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001750_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_40 > 26) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_41 > 41) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001750_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001750_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_44 > 39) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001750_3 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_45 > 35) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_46 > 20) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_47 > 42) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_48 > 30) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001750_3 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_49 > 50) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001750_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001750_10 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_51 > 50) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_52 > 50) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001750_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_54 > 27) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001750_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_56 > 50) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_57 > 34) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001750_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001750_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001750_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_61 > 27) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_62 > 21) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001750_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_64 > 33) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_65 > 28) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001750_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_67 > 41) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_68 > 50) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001750_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001750_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001750_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_72 > 33) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_73 > 50) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001750_7 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_74 > 31) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_75 > 50) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_76 > 42) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001750_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_78 > 23) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001750_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_80 > 25) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_81 > 39) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_82 > 33) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_83 > 40) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001750_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_85 > 38) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_86 > 32) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_87 > 25) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_88 > 43) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001750_5 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_89 > 48) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001750_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_91 > 48) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_92 > 35) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_93 > 33) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_94 > 48) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_95 > 21) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_96 > 45) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_97 > 45) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r001750_3 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_98 > 41) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_99 > 30) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_100 > 46) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_101 > 49) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_102 > 46) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001750_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_104 > 35) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001750_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_106 > 37) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001750_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001750_4) & 127;
    if (stage_v_108 > 48) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_109 > 35) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_110 > 38) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_111 > 44) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001750_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_113 > 43) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001750_18 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001750_4) & 127;
    if (stage_v_115 > 24) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001750_12 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_116 > 43) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_117 > 21) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_118 > 36) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_119 > 45) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_120 > 20) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_121 > 31) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_122 > 32) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001750_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001750_11 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_124 > 32) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001750_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_126 > 28) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_127 > 33) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_128 > 23) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_129 > 37) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001750_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_131 > 26) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_132 > 39) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_133 > 42) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001750_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_135 > 45) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((sec_r001750_6 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_136 > 24) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001750_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001750_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_139 > 46) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001750_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_141 > 46) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_142 > 47) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_143 > 37) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_144 > 31) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001750_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_146 > 49) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001750_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_148 > 50) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_149 > 49) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001750_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_151 > 25) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_152 > 45) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r001750_14 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_153 > 48) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_154 > 24) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_155 > 50) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001750_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_157 > 45) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_158 > 39) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_159 > 38) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_160 > 21) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001750_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001750_13 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_162 > 31) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_163 > 21) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001750_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001750_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_166 > 20) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001750_7 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_167 > 48) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_168 > 22) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_169 > 29) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_170 > 22) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001750_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_172 > 22) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_173 > 30) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001750_1 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_174 > 41) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_175 > 22) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_176 > 30) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001750_10 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_177 > 25) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001750_4) & 127;
    if (stage_v_178 > 49) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001750_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001750_16 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_180 > 23) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001750_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001750_9) & 127;
    if (stage_v_182 > 26) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_183 > 46) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001750_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_185 > 46) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_186 > 38) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_187 > 34) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_188 > 38) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_189 > 30) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_190 > 25) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001750_4) & 127;
    if (stage_v_191 > 31) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_192 > 20) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_193 > 36) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_194 > 27) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001750_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001750_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_197 > 44) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001750_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_199 > 25) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_200 > 40) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_201 > 43) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001750_4) & 127;
    if (stage_v_202 > 28) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_203 > 45) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_204 > 36) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_205 > 39) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_206 > 38) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_207 > 41) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001750_5 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_208 > 25) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_209 > 25) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r001750_4 ^ 0x2A) * 2 + pub_r001750_16) & 127;
    if (stage_v_210 > 40) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_211 > 42) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_212 > 28) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001750_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_214 > 29) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001750_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001750_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_217 > 25) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_190 ^ 0x2A) * 2 + pub_r001750_3) & 127;
    if (stage_v_218 > 48) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001750_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_220 > 47) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_221 > 31) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_222 > 23) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001750_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_211 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_224 > 27) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_225 > 21) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001750_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_227 > 42) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001750_15 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_220 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_229 > 20) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_230 > 46) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001750_15) & 127;
    if (stage_v_231 > 47) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_232 > 28) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001750_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001750_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_235 > 45) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_211 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_236 > 37) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_237 > 40) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001750_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_239 > 20) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_240 > 50) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001750_14) & 127;
    if (stage_v_241 > 41) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001750_2) & 127;
    if (stage_v_242 > 21) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((sec_r001750_13 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_243 > 35) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001750_10 ^ 0x2A) * 2 + pub_r001750_7) & 127;
    if (stage_v_244 > 24) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_245 > 35) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_246 > 30) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_247 > 28) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_248 > 41) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_224 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_249 > 28) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001750_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001750_8) & 127;
    if (stage_v_251 > 31) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_252 > 23) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_201 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_253 > 35) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_245 ^ 0x2A) * 2 + pub_r001750_5) & 127;
    if (stage_v_254 > 20) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_221 ^ 0x2A) * 2 + pub_r001750_12) & 127;
    if (stage_v_255 > 44) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_256 > 43) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_257 > 33) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001750_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001750_11) & 127;
    if (stage_v_259 > 47) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r001750_9 ^ 0x2A) * 2 + pub_r001750_10) & 127;
    if (stage_v_260 > 20) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001750_17) & 127;
    if (stage_v_261 > 35) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001750_13) & 127;
    if (stage_v_262 > 50) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_263 > 31) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001750_0) & 127;
    if (stage_v_264 > 48) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001750_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001750_1) & 127;
    if (stage_v_266 > 23) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_237 ^ 0x2A) * 2 + pub_r001750_18) & 127;
    if (stage_v_267 > 32) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001750_6) & 127;
    if (stage_v_268 > 24) {
        out_sink = (out_sink + stage_v_268 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_268 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_268) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
