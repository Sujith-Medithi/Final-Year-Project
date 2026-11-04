/*
 * Benchmark Program: R000742
 * Family: secret_dependent_loops
 * Generator Seed: 474213
 * High Inputs: 20 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000742_4213_0 {
    unsigned char coord_z;
    int pitch;
    short heading;
    int buffer[3];
};

struct DeviceConfig_R000742_4213_1 {
    int baud_rate;
    short parity;
    unsigned char timeout;
    short port;
    int buffer[3];
};

union RegisterBank_R000742_4213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000742_4213_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000742_4213_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int window_65 = local_arr[aux % 3];
    acc = (acc + window_65 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_39 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_39 > 19) {
        acc = (acc + threshold_39 * 2 + 5) & 127;
        aux ^= (threshold_39 & 15);
    } else {
        acc = (acc - threshold_39 + 11) & 127;
        aux += 3;
    }
    int factor_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000742_4213_1(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int segment_14 = 0;
    for (int k = 0; k < 2; k++) {
        segment_14 = (segment_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_14) & 127;
    }
    int cursor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_59 > 50) {
        acc = (acc + cursor_59 * 2 + 5) & 127;
        aux ^= (cursor_59 & 15);
    } else {
        acc = (acc - cursor_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int bound_80 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_80 > 29) {
        acc = (acc + bound_80 * 2 + 5) & 127;
        aux ^= (bound_80 & 15);
    } else {
        acc = (acc - bound_80 + 11) & 127;
        aux += 3;
    }
    int phase_20 = 0;
    for (int k = 0; k < 3; k++) {
        phase_20 = (phase_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_20) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_68 = local_arr[aux % 3];
    acc = (acc + weight_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int stride_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_61 = local_arr[aux % 3];
    acc = (acc + residue_61 * 2) & 127;
    int offset_13 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_13 > 12) {
        acc = (acc + offset_13 * 2 + 5) & 127;
        aux ^= (offset_13 & 15);
    } else {
        acc = (acc - offset_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_4(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_28 = 0;
    for (int k = 0; k < 3; k++) {
        window_28 = (window_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_28) & 127;
    }
    int damping_36 = (aux + st.buffer[1]) & 3;
    switch (damping_36) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_35 = local_arr[aux % 3];
    acc = (acc + tracker_35 * 2) & 127;
    int sample_71 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_71 > 49) {
        acc = (acc + sample_71 * 2 + 5) & 127;
        aux ^= (sample_71 & 15);
    } else {
        acc = (acc - sample_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_5(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_90) & 63;
    acc ^= aux;
    int delta_45 = (aux + st.buffer[1]) & 3;
    switch (delta_45) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_46) & 63;
    acc ^= aux;
    int weight_60 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_60 > 31) {
        acc = (acc + weight_60 * 2 + 5) & 127;
        aux ^= (weight_60 & 15);
    } else {
        acc = (acc - weight_60 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_63 = local_arr[aux % 3];
    acc = (acc + damping_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_17 = 0;
    for (int k = 0; k < 3; k++) {
        offset_17 = (offset_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_17) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_39 = local_arr[aux % 3];
    acc = (acc + offset_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int accumulator_53 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_53 > 34) {
        acc = (acc + accumulator_53 * 2 + 5) & 127;
        aux ^= (accumulator_53 & 15);
    } else {
        acc = (acc - accumulator_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_94 = (aux + st.buffer[1]) & 3;
    switch (residue_94) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_9(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int bound_85 = (aux + st.buffer[1]) & 3;
    switch (bound_85) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_41 = 0;
    for (int k = 0; k < 3; k++) {
        sample_41 = (sample_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_41) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int tracker_82 = local_arr[aux % 3];
    acc = (acc + tracker_82 * 2) & 127;
    int weight_10 = (aux + st.buffer[1]) & 3;
    switch (weight_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_11(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_58) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_48 = (aux + st.buffer[1]) & 3;
    switch (coefficient_48) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_33 = local_arr[aux % 3];
    acc = (acc + accumulator_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_82 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_82 > 12) {
        acc = (acc + segment_82 * 2 + 5) & 127;
        aux ^= (segment_82 & 15);
    } else {
        acc = (acc - segment_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int residue_96 = (aux + st.buffer[1]) & 3;
    switch (residue_96) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_30 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_30 > 40) {
        acc = (acc + residue_30 * 2 + 5) & 127;
        aux ^= (residue_30 & 15);
    } else {
        acc = (acc - residue_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_97 = local_arr[aux % 3];
    acc = (acc + vector_97 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_34 = 0;
    for (int k = 0; k < 3; k++) {
        tally_34 = (tally_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_34) & 127;
    }
    int mask_60 = (aux + st.buffer[1]) & 3;
    switch (mask_60) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_22 = local_arr[aux % 3];
    acc = (acc + anchor_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_15(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_23 = local_arr[aux % 3];
    acc = (acc + stride_23 * 2) & 127;
    int factor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000742_4213_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_22 = local_arr[aux % 3];
    acc = (acc + pivot_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000742_4213_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int weight_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_82) & 63;
    acc ^= aux;
    int bound_85 = 0;
    for (int k = 0; k < 3; k++) {
        bound_85 = (bound_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_18(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quantum_69 = (aux + st.buffer[1]) & 3;
    switch (quantum_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_22 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_22 > 19) {
        acc = (acc + stride_22 * 2 + 5) & 127;
        aux ^= (stride_22 & 15);
    } else {
        acc = (acc - stride_22 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_94 = local_arr[aux % 3];
    acc = (acc + delta_94 * 2) & 127;
    int tracker_76 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_76 = (tracker_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_76) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_19(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int tracker_67 = local_arr[aux % 3];
    acc = (acc + tracker_67 * 2) & 127;
    int index_reg_67 = (aux + st.buffer[1]) & 3;
    switch (index_reg_67) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_20(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_35) & 63;
    acc ^= aux;
    int delta_18 = 0;
    for (int k = 0; k < 3; k++) {
        delta_18 = (delta_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_18) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_21(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_74 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_74 > 20) {
        acc = (acc + threshold_74 * 2 + 5) & 127;
        aux ^= (threshold_74 & 15);
    } else {
        acc = (acc - threshold_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_26 = local_arr[aux % 3];
    acc = (acc + quantum_26 * 2) & 127;
    int threshold_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_86) & 63;
    acc ^= aux;
    int metric_22 = 0;
    for (int k = 0; k < 2; k++) {
        metric_22 = (metric_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000742_4213_22(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000742_4213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int weight_86 = (aux + st.buffer[1]) & 3;
    switch (weight_86) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_79 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_79 > 19) {
        acc = (acc + tracker_79 * 2 + 5) & 127;
        aux ^= (tracker_79 & 15);
    } else {
        acc = (acc - tracker_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_97 = local_arr[aux % 3];
    acc = (acc + sample_97 * 2) & 127;
    int quotient_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000742_4213_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000742_4213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_39 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_39 > 47) {
        acc = (acc + tally_39 * 2 + 5) & 127;
        aux ^= (tally_39 & 15);
    } else {
        acc = (acc - tally_39 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_35) & 63;
    acc ^= aux;
    int cursor_49 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_49 = (cursor_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_49) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000742_0;
    int sec_r000742_1;
    int sec_r000742_2;
    int sec_r000742_3;
    int sec_r000742_4;
    int sec_r000742_5;
    int sec_r000742_6;
    int sec_r000742_7;
    int sec_r000742_8;
    int sec_r000742_9;
    int sec_r000742_10;
    int sec_r000742_11;
    int sec_r000742_12;
    int sec_r000742_13;
    int sec_r000742_14;
    int sec_r000742_15;
    int sec_r000742_16;
    int sec_r000742_17;
    int sec_r000742_18;
    int sec_r000742_19;
    int pub_r000742_0;
    int pub_r000742_1;
    int pub_r000742_2;
    int pub_r000742_3;
    int pub_r000742_4;
    int pub_r000742_5;
    int pub_r000742_6;
    int pub_r000742_7;
    int pub_r000742_8;
    int pub_r000742_9;
    int pub_r000742_10;
    int pub_r000742_11;
    int pub_r000742_12;
    int pub_r000742_13;
    int pub_r000742_14;
    int pub_r000742_15;
    int pub_r000742_16;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000742_0 >= -100 && pub_r000742_0 <= 100);
    __CPROVER_assume(pub_r000742_1 >= -100 && pub_r000742_1 <= 100);
    __CPROVER_assume(pub_r000742_2 >= -100 && pub_r000742_2 <= 100);
    __CPROVER_assume(pub_r000742_3 >= -100 && pub_r000742_3 <= 100);
    __CPROVER_assume(pub_r000742_4 >= -100 && pub_r000742_4 <= 100);
    __CPROVER_assume(pub_r000742_5 >= -100 && pub_r000742_5 <= 100);
    __CPROVER_assume(pub_r000742_6 >= -100 && pub_r000742_6 <= 100);
    __CPROVER_assume(pub_r000742_7 >= -100 && pub_r000742_7 <= 100);
    __CPROVER_assume(pub_r000742_8 >= -100 && pub_r000742_8 <= 100);
    __CPROVER_assume(pub_r000742_9 >= -100 && pub_r000742_9 <= 100);
    __CPROVER_assume(pub_r000742_10 >= -100 && pub_r000742_10 <= 100);
    __CPROVER_assume(pub_r000742_11 >= -100 && pub_r000742_11 <= 100);
    __CPROVER_assume(pub_r000742_12 >= -100 && pub_r000742_12 <= 100);
    __CPROVER_assume(pub_r000742_13 >= -100 && pub_r000742_13 <= 100);
    __CPROVER_assume(pub_r000742_14 >= -100 && pub_r000742_14 <= 100);
    __CPROVER_assume(pub_r000742_15 >= -100 && pub_r000742_15 <= 100);
    __CPROVER_assume(pub_r000742_16 >= -100 && pub_r000742_16 <= 100);
    __CPROVER_assume(sec_r000742_0 >= 0 && sec_r000742_0 <= 255);
    __CPROVER_assume(sec_r000742_1 >= 0 && sec_r000742_1 <= 255);
    __CPROVER_assume(sec_r000742_2 >= 0 && sec_r000742_2 <= 255);
    __CPROVER_assume(sec_r000742_3 >= 0 && sec_r000742_3 <= 255);
    __CPROVER_assume(sec_r000742_4 >= 0 && sec_r000742_4 <= 255);
    __CPROVER_assume(sec_r000742_5 >= 0 && sec_r000742_5 <= 255);
    __CPROVER_assume(sec_r000742_6 >= 0 && sec_r000742_6 <= 255);
    __CPROVER_assume(sec_r000742_7 >= 0 && sec_r000742_7 <= 255);
    __CPROVER_assume(sec_r000742_8 >= 0 && sec_r000742_8 <= 255);
    __CPROVER_assume(sec_r000742_9 >= 0 && sec_r000742_9 <= 255);
    __CPROVER_assume(sec_r000742_10 >= 0 && sec_r000742_10 <= 255);
    __CPROVER_assume(sec_r000742_11 >= 0 && sec_r000742_11 <= 255);
    __CPROVER_assume(sec_r000742_12 >= 0 && sec_r000742_12 <= 255);
    __CPROVER_assume(sec_r000742_13 >= 0 && sec_r000742_13 <= 255);
    __CPROVER_assume(sec_r000742_14 >= 0 && sec_r000742_14 <= 255);
    __CPROVER_assume(sec_r000742_15 >= 0 && sec_r000742_15 <= 255);
    __CPROVER_assume(sec_r000742_16 >= 0 && sec_r000742_16 <= 255);
    __CPROVER_assume(sec_r000742_17 >= 0 && sec_r000742_17 <= 255);
    __CPROVER_assume(sec_r000742_18 >= 0 && sec_r000742_18 <= 255);
    __CPROVER_assume(sec_r000742_19 >= 0 && sec_r000742_19 <= 255);

    struct Vector3D_R000742_4213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000742_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000742_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000742_0 + 7) & 15;
    struct DeviceConfig_R000742_4213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000742_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000742_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000742_0 + 9) & 15;

    union RegisterBank_R000742_4213_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 34) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 49) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 19) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 34) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 34) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 49) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 33) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 48) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 22) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 37) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 30) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 45) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 40) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 55) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 35) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 50) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 19) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 34) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 31) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 46) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_1.buffer[0] ^ 66) & 3;
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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 12) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 27) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 26) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 41) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 89) & 15;
    int stage_v_88 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= stage_v_88;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_0.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[1] * 2 + 289) & 63;
    if (stage_v_94 > 35) {
        out_sink = (out_sink + stage_v_94 - 5) & 255;
        if (stage_v_94 > 50) {
            chk_sum ^= (stage_v_94 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_94 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 26) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 41) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_1.buffer[2] * 2 + 310) & 63;
    if (stage_v_101 > 39) {
        out_sink = (out_sink + stage_v_101 - 5) & 255;
        if (stage_v_101 > 54) {
            chk_sum ^= (stage_v_101 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_101 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 35) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 50) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (st_var_1.buffer[0] ^ 106) & 3;
    switch (stage_v_103) {
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

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_106 = (stage_v_106 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;

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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 111) & 15;
    int stage_v_110 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= stage_v_110;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = table[2];
    table[2] = (table[3] + 229) & 63;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_117 = (stage_v_117 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 119 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 120) & 15;
    int stage_v_119 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= stage_v_119;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 12) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 27) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 122) & 15;
    int stage_v_121 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= stage_v_121;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (out_sink > 100) ? (chk_sum & 31) : (131 & 31);
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= (stage_v_126 << 1) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (out_sink > 100) ? (chk_sum & 31) : (138 & 31);
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= (stage_v_133 << 1) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_0.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 25) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 40) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_1.buffer[0] * 2 + 412) & 63;
    if (stage_v_135 > 18) {
        out_sink = (out_sink + stage_v_135 - 5) & 255;
        if (stage_v_135 > 33) {
            chk_sum ^= (stage_v_135 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_135 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_1.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_1.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 15) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 30) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_142 = (stage_v_142 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_1.buffer[0] ^ 146) & 3;
    switch (stage_v_143) {
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

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (out_sink > 100) ? (chk_sum & 31) : (152 & 31);
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= (stage_v_147 << 1) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 154) & 15;
    int stage_v_153 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= stage_v_153;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = table[3];
    table[3] = (table[0] + 311) & 63;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (out_sink > 100) ? (chk_sum & 31) : (162 & 31);
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= (stage_v_157 << 1) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_0.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (out_sink > 100) ? (chk_sum & 31) : (164 & 31);
    out_sink = (out_sink + stage_v_159) & 255;
    chk_sum ^= (stage_v_159 << 1) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (out_sink > 100) ? (chk_sum & 31) : (165 & 31);
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= (stage_v_160 << 1) & 127;

    /* Execution Pipeline Stage 161 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 162) & 15;
    int stage_v_161 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= stage_v_161;

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
    int stage_v_163 = (st_var_1.buffer[1] * 2 + 496) & 63;
    if (stage_v_163 > 21) {
        out_sink = (out_sink + stage_v_163 - 5) & 255;
        if (stage_v_163 > 36) {
            chk_sum ^= (stage_v_163 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_163 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] ^ 168) & 3;
    switch (stage_v_165) {
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

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = table[2];
    table[2] = (table[3] + 333) & 63;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_169 = (stage_v_169 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;

    /* Security Information Flow: Family = secret_dependent_loops */
    int l_bound_0 = (sec_r000742_0 & 1) + 1;
    for (int it = 0; it < l_bound_0; it++) {
        out_sink += (it * 3 + 4);
    }
    int l_bound_1 = (sec_r000742_14 & 1) + 1;
    for (int it = 0; it < l_bound_1; it++) {
        out_sink += (it * 3 + 6);
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
