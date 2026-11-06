/*
 * Benchmark Program: R000747
 * Security Family: nested_implicit_flow
 * Generator Seed: 574713
 * High Inputs: 19 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000747_4713_0 {
    int tail;
    short capacity;
    unsigned char watermark;
    unsigned char checksum;
    short state;
    int buffer[3];
};

struct Transaction_R000747_4713_1 {
    int status;
    short fee;
    int auth_code;
    int rate;
    short balance;
    int account_id;
    int buffer[3];
};

struct Vector3D_R000747_4713_2 {
    int heading;
    unsigned char coord_z;
    int coord_y;
    unsigned char pitch;
    int buffer[3];
};

union RegisterBank_R000747_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000747_4713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000747_4713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_55 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_55 > 40) {
        acc = (acc + tally_55 * 2 + 5) & 127;
        aux ^= (tally_55 & 15);
    } else {
        acc = (acc - tally_55 + 11) & 127;
        aux += 3;
    }
    int mask_19 = (aux + st.buffer[1]) & 3;
    switch (mask_19) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000747_4713_1(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_13 = local_arr[aux % 3];
    acc = (acc + pivot_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int delta_87 = local_arr[aux % 3];
    acc = (acc + delta_87 * 2) & 127;
    int factor_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_86) & 63;
    acc ^= aux;
    int weight_60 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_60 > 19) {
        acc = (acc + weight_60 * 2 + 5) & 127;
        aux ^= (weight_60 & 15);
    } else {
        acc = (acc - weight_60 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_3(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000747_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int checksum_83 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_83 > 10) {
        acc = (acc + checksum_83 * 2 + 5) & 127;
        aux ^= (checksum_83 & 15);
    } else {
        acc = (acc - checksum_83 + 11) & 127;
        aux += 3;
    }
    int segment_55 = (aux + st.buffer[1]) & 3;
    switch (segment_55) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_88 = local_arr[aux % 3];
    acc = (acc + accumulator_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int delta_93 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_93 > 29) {
        acc = (acc + delta_93 * 2 + 5) & 127;
        aux ^= (delta_93 & 15);
    } else {
        acc = (acc - delta_93 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000747_4713_5(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_87 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_87 > 10) {
        acc = (acc + delta_87 * 2 + 5) & 127;
        aux ^= (delta_87 & 15);
    } else {
        acc = (acc - delta_87 + 11) & 127;
        aux += 3;
    }
    int mask_41 = (aux + st.buffer[1]) & 3;
    switch (mask_41) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_31 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_31 > 18) {
        acc = (acc + parity_31 * 2 + 5) & 127;
        aux ^= (parity_31 & 15);
    } else {
        acc = (acc - parity_31 + 11) & 127;
        aux += 3;
    }
    int vector_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_80) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_99 = local_arr[aux % 3];
    acc = (acc + anchor_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_7(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int weight_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_86) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_65 = local_arr[aux % 3];
    acc = (acc + phase_65 * 2) & 127;
    int mask_34 = (aux + st.buffer[1]) & 3;
    switch (mask_34) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_8(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int sample_86 = (aux + st.buffer[1]) & 3;
    switch (sample_86) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_9(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_75 = (aux + st.buffer[1]) & 3;
    switch (residue_75) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_12 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_12 > 13) {
        acc = (acc + offset_12 * 2 + 5) & 127;
        aux ^= (offset_12 & 15);
    } else {
        acc = (acc - offset_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_50 = local_arr[aux % 3];
    acc = (acc + residue_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_10(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int stride_82 = (aux + st.buffer[1]) & 3;
    switch (stride_82) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_39 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_39 > 26) {
        acc = (acc + residue_39 * 2 + 5) & 127;
        aux ^= (residue_39 & 15);
    } else {
        acc = (acc - residue_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int threshold_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_19) & 63;
    acc ^= aux;
    int damping_22 = (aux + st.buffer[1]) & 3;
    switch (damping_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_59 = local_arr[aux % 3];
    acc = (acc + stride_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_12(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int damping_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_87) & 63;
    acc ^= aux;
    int metric_30 = (aux + st.buffer[1]) & 3;
    switch (metric_30) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_13(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int bound_93 = (aux + st.buffer[1]) & 3;
    switch (bound_93) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000747_4713_14(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000747_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_22) & 63;
    acc ^= aux;
    int factor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_20 > 39) {
        acc = (acc + factor_20 * 2 + 5) & 127;
        aux ^= (factor_20 & 15);
    } else {
        acc = (acc - factor_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_15(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000747_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_47 = local_arr[aux % 3];
    acc = (acc + tally_47 * 2) & 127;
    int metric_13 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_13 > 46) {
        acc = (acc + metric_13 * 2 + 5) & 127;
        aux ^= (metric_13 & 15);
    } else {
        acc = (acc - metric_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_16(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int cursor_59 = local_arr[aux % 3];
    acc = (acc + cursor_59 * 2) & 127;
    int threshold_54 = (aux + st.buffer[1]) & 3;
    switch (threshold_54) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_17(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_69 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_69 > 41) {
        acc = (acc + anchor_69 * 2 + 5) & 127;
        aux ^= (anchor_69 & 15);
    } else {
        acc = (acc - anchor_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_62) & 63;
    acc ^= aux;
    int quantum_52 = (aux + st.buffer[1]) & 3;
    switch (quantum_52) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000747_4713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int parity_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_10 = local_arr[aux % 3];
    acc = (acc + stride_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_20(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int window_45 = (aux + st.buffer[1]) & 3;
    switch (window_45) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_75 = local_arr[aux % 3];
    acc = (acc + mask_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000747_4713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int accumulator_84 = (aux + st.buffer[1]) & 3;
    switch (accumulator_84) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_91) & 63;
    acc ^= aux;
    int damping_64 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_64 > 23) {
        acc = (acc + damping_64 * 2 + 5) & 127;
        aux ^= (damping_64 & 15);
    } else {
        acc = (acc - damping_64 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000747_0;
    int sec_r000747_1;
    int sec_r000747_2;
    int sec_r000747_3;
    int sec_r000747_4;
    int sec_r000747_5;
    int sec_r000747_6;
    int sec_r000747_7;
    int sec_r000747_8;
    int sec_r000747_9;
    int sec_r000747_10;
    int sec_r000747_11;
    int sec_r000747_12;
    int sec_r000747_13;
    int sec_r000747_14;
    int sec_r000747_15;
    int sec_r000747_16;
    int sec_r000747_17;
    int sec_r000747_18;
    int pub_r000747_0;
    int pub_r000747_1;
    int pub_r000747_2;
    int pub_r000747_3;
    int pub_r000747_4;
    int pub_r000747_5;
    int pub_r000747_6;
    int pub_r000747_7;
    int pub_r000747_8;
    int pub_r000747_9;
    int pub_r000747_10;
    int pub_r000747_11;
    int pub_r000747_12;
    int pub_r000747_13;
    int pub_r000747_14;
    int pub_r000747_15;
    int pub_r000747_16;
    int pub_r000747_17;
    int pub_r000747_18;
    int pub_r000747_19;
    int pub_r000747_20;
    int pub_r000747_21;
    int pub_r000747_22;
    int pub_r000747_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000747_0 >= -100 && pub_r000747_0 <= 100);
    __CPROVER_assume(pub_r000747_1 >= -100 && pub_r000747_1 <= 100);
    __CPROVER_assume(pub_r000747_2 >= -100 && pub_r000747_2 <= 100);
    __CPROVER_assume(pub_r000747_3 >= -100 && pub_r000747_3 <= 100);
    __CPROVER_assume(pub_r000747_4 >= -100 && pub_r000747_4 <= 100);
    __CPROVER_assume(pub_r000747_5 >= -100 && pub_r000747_5 <= 100);
    __CPROVER_assume(pub_r000747_6 >= -100 && pub_r000747_6 <= 100);
    __CPROVER_assume(pub_r000747_7 >= -100 && pub_r000747_7 <= 100);
    __CPROVER_assume(pub_r000747_8 >= -100 && pub_r000747_8 <= 100);
    __CPROVER_assume(pub_r000747_9 >= -100 && pub_r000747_9 <= 100);
    __CPROVER_assume(pub_r000747_10 >= -100 && pub_r000747_10 <= 100);
    __CPROVER_assume(pub_r000747_11 >= -100 && pub_r000747_11 <= 100);
    __CPROVER_assume(pub_r000747_12 >= -100 && pub_r000747_12 <= 100);
    __CPROVER_assume(pub_r000747_13 >= -100 && pub_r000747_13 <= 100);
    __CPROVER_assume(pub_r000747_14 >= -100 && pub_r000747_14 <= 100);
    __CPROVER_assume(pub_r000747_15 >= -100 && pub_r000747_15 <= 100);
    __CPROVER_assume(pub_r000747_16 >= -100 && pub_r000747_16 <= 100);
    __CPROVER_assume(pub_r000747_17 >= -100 && pub_r000747_17 <= 100);
    __CPROVER_assume(pub_r000747_18 >= -100 && pub_r000747_18 <= 100);
    __CPROVER_assume(pub_r000747_19 >= -100 && pub_r000747_19 <= 100);
    __CPROVER_assume(pub_r000747_20 >= -100 && pub_r000747_20 <= 100);
    __CPROVER_assume(pub_r000747_21 >= -100 && pub_r000747_21 <= 100);
    __CPROVER_assume(pub_r000747_22 >= -100 && pub_r000747_22 <= 100);
    __CPROVER_assume(pub_r000747_23 >= -100 && pub_r000747_23 <= 100);
    __CPROVER_assume(sec_r000747_0 >= 0 && sec_r000747_0 <= 255);
    __CPROVER_assume(sec_r000747_1 >= 0 && sec_r000747_1 <= 255);
    __CPROVER_assume(sec_r000747_2 >= 0 && sec_r000747_2 <= 255);
    __CPROVER_assume(sec_r000747_3 >= 0 && sec_r000747_3 <= 255);
    __CPROVER_assume(sec_r000747_4 >= 0 && sec_r000747_4 <= 255);
    __CPROVER_assume(sec_r000747_5 >= 0 && sec_r000747_5 <= 255);
    __CPROVER_assume(sec_r000747_6 >= 0 && sec_r000747_6 <= 255);
    __CPROVER_assume(sec_r000747_7 >= 0 && sec_r000747_7 <= 255);
    __CPROVER_assume(sec_r000747_8 >= 0 && sec_r000747_8 <= 255);
    __CPROVER_assume(sec_r000747_9 >= 0 && sec_r000747_9 <= 255);
    __CPROVER_assume(sec_r000747_10 >= 0 && sec_r000747_10 <= 255);
    __CPROVER_assume(sec_r000747_11 >= 0 && sec_r000747_11 <= 255);
    __CPROVER_assume(sec_r000747_12 >= 0 && sec_r000747_12 <= 255);
    __CPROVER_assume(sec_r000747_13 >= 0 && sec_r000747_13 <= 255);
    __CPROVER_assume(sec_r000747_14 >= 0 && sec_r000747_14 <= 255);
    __CPROVER_assume(sec_r000747_15 >= 0 && sec_r000747_15 <= 255);
    __CPROVER_assume(sec_r000747_16 >= 0 && sec_r000747_16 <= 255);
    __CPROVER_assume(sec_r000747_17 >= 0 && sec_r000747_17 <= 255);
    __CPROVER_assume(sec_r000747_18 >= 0 && sec_r000747_18 <= 255);

    struct StreamBuffer_R000747_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000747_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000747_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000747_0 + 7) & 15;
    struct Transaction_R000747_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000747_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000747_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000747_0 + 9) & 15;
    struct Vector3D_R000747_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000747_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000747_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000747_0 + 11) & 15;

    union RegisterBank_R000747_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 30) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 45) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 19) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 34) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 23) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 38) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 28) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 43) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 24) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 39) {
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

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 23) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 38) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000747_10 & 1) != 0) {
        if ((sec_r000747_8 & 2) != 0) {
            stage_v_71 = (pub_r000747_9 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000747_9 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000747_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_72 = (pub_r000747_9 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000747_9 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000747_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000747_11 & 1) != 0) {
        if ((sec_r000747_9 & 2) != 0) {
            stage_v_73 = (pub_r000747_8 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000747_8 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000747_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000747_8 & 2) != 0) {
            stage_v_74 = (pub_r000747_12 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000747_12 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000747_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000747_17 & 2) != 0) {
            stage_v_75 = (pub_r000747_15 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000747_15 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000747_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000747_6 & 2) != 0) {
            stage_v_76 = (pub_r000747_4 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000747_4 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000747_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000747_1 & 2) != 0) {
            stage_v_77 = (pub_r000747_10 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000747_10 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000747_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000747_13 & 2) != 0) {
            stage_v_78 = (pub_r000747_19 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000747_19 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000747_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000747_18 & 1) != 0) {
        if ((sec_r000747_7 & 2) != 0) {
            stage_v_79 = (pub_r000747_19 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000747_19 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000747_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000747_1 & 2) != 0) {
            stage_v_80 = (pub_r000747_3 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000747_3 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000747_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_9 & 2) != 0) {
            stage_v_81 = (pub_r000747_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000747_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000747_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000747_5 & 2) != 0) {
            stage_v_82 = (pub_r000747_3 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000747_3 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000747_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_2 & 2) != 0) {
            stage_v_83 = (pub_r000747_18 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000747_18 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000747_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000747_7 & 1) != 0) {
        if ((sec_r000747_13 & 2) != 0) {
            stage_v_84 = (pub_r000747_2 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000747_2 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000747_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_5 & 2) != 0) {
            stage_v_85 = (pub_r000747_19 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000747_19 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000747_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_86 = (pub_r000747_7 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000747_7 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000747_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000747_6 & 2) != 0) {
            stage_v_87 = (pub_r000747_17 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000747_17 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000747_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_13 & 2) != 0) {
            stage_v_88 = (pub_r000747_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000747_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000747_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000747_8 & 1) != 0) {
        if ((sec_r000747_10 & 2) != 0) {
            stage_v_89 = (pub_r000747_10 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000747_10 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000747_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000747_11 & 2) != 0) {
            stage_v_90 = (pub_r000747_15 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000747_15 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000747_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000747_12 & 2) != 0) {
            stage_v_91 = (pub_r000747_3 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000747_3 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000747_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000747_16 & 2) != 0) {
            stage_v_92 = (pub_r000747_21 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000747_21 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000747_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000747_8 & 1) != 0) {
        if ((sec_r000747_0 & 2) != 0) {
            stage_v_93 = (pub_r000747_14 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000747_14 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000747_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000747_12 & 1) != 0) {
        if ((sec_r000747_18 & 2) != 0) {
            stage_v_94 = (pub_r000747_17 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000747_17 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000747_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000747_17 & 1) != 0) {
        if ((sec_r000747_5 & 2) != 0) {
            stage_v_95 = (pub_r000747_18 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000747_18 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000747_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000747_17 & 2) != 0) {
            stage_v_96 = (pub_r000747_1 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000747_1 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000747_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000747_13 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_97 = (pub_r000747_22 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000747_22 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000747_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000747_7 & 2) != 0) {
            stage_v_98 = (pub_r000747_8 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000747_8 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000747_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000747_17 & 2) != 0) {
            stage_v_99 = (pub_r000747_5 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000747_5 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000747_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000747_3 & 2) != 0) {
            stage_v_100 = (pub_r000747_1 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000747_1 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000747_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000747_6 & 2) != 0) {
            stage_v_101 = (pub_r000747_2 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000747_2 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000747_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_13 & 2) != 0) {
            stage_v_102 = (pub_r000747_23 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000747_23 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000747_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000747_2 & 2) != 0) {
            stage_v_103 = (pub_r000747_21 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000747_21 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000747_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000747_15 & 2) != 0) {
            stage_v_104 = (pub_r000747_23 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000747_23 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000747_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000747_5 & 2) != 0) {
            stage_v_105 = (pub_r000747_12 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000747_12 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000747_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000747_10 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_106 = (pub_r000747_5 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000747_5 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000747_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000747_11 & 2) != 0) {
            stage_v_107 = (pub_r000747_11 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000747_11 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000747_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000747_16 & 1) != 0) {
        if ((sec_r000747_14 & 2) != 0) {
            stage_v_108 = (pub_r000747_22 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000747_22 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000747_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000747_7 & 2) != 0) {
            stage_v_109 = (pub_r000747_6 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000747_6 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000747_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_110 = (pub_r000747_4 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000747_4 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000747_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000747_10 & 1) != 0) {
        if ((sec_r000747_10 & 2) != 0) {
            stage_v_111 = (pub_r000747_1 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000747_1 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000747_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000747_13 & 2) != 0) {
            stage_v_112 = (pub_r000747_16 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000747_16 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000747_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000747_3 & 2) != 0) {
            stage_v_113 = (pub_r000747_16 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000747_16 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000747_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000747_11 & 1) != 0) {
        if ((sec_r000747_15 & 2) != 0) {
            stage_v_114 = (pub_r000747_7 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000747_7 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000747_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000747_1 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_115 = (pub_r000747_10 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000747_10 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000747_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000747_8 & 1) != 0) {
        if ((sec_r000747_11 & 2) != 0) {
            stage_v_116 = (pub_r000747_11 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000747_11 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000747_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000747_11 & 2) != 0) {
            stage_v_117 = (pub_r000747_3 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000747_3 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000747_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000747_13 & 1) != 0) {
        if ((sec_r000747_4 & 2) != 0) {
            stage_v_118 = (pub_r000747_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000747_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000747_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000747_15 & 1) != 0) {
        if ((sec_r000747_1 & 2) != 0) {
            stage_v_119 = (pub_r000747_21 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000747_21 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000747_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000747_11 & 2) != 0) {
            stage_v_120 = (pub_r000747_22 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000747_22 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000747_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000747_12 & 2) != 0) {
            stage_v_121 = (pub_r000747_19 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000747_19 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000747_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000747_6 & 2) != 0) {
            stage_v_122 = (pub_r000747_11 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000747_11 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000747_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000747_12 & 2) != 0) {
            stage_v_123 = (pub_r000747_6 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000747_6 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000747_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000747_12 & 1) != 0) {
        if ((sec_r000747_14 & 2) != 0) {
            stage_v_124 = (pub_r000747_17 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000747_17 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000747_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000747_15 & 2) != 0) {
            stage_v_125 = (pub_r000747_17 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000747_17 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000747_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000747_8 & 2) != 0) {
            stage_v_126 = (pub_r000747_20 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000747_20 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000747_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000747_7 & 1) != 0) {
        if ((sec_r000747_16 & 2) != 0) {
            stage_v_127 = (pub_r000747_4 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000747_4 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000747_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000747_12 & 2) != 0) {
            stage_v_128 = (pub_r000747_23 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000747_23 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000747_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000747_13 & 1) != 0) {
        if ((sec_r000747_1 & 2) != 0) {
            stage_v_129 = (pub_r000747_7 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000747_7 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000747_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000747_12 & 1) != 0) {
        if ((sec_r000747_6 & 2) != 0) {
            stage_v_130 = (pub_r000747_19 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000747_19 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000747_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000747_7 & 2) != 0) {
            stage_v_131 = (pub_r000747_22 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000747_22 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000747_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000747_13 & 2) != 0) {
            stage_v_132 = (pub_r000747_8 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000747_8 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000747_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000747_14 & 2) != 0) {
            stage_v_133 = (pub_r000747_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000747_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000747_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000747_18 & 2) != 0) {
            stage_v_134 = (pub_r000747_10 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000747_10 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000747_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000747_7 & 2) != 0) {
            stage_v_135 = (pub_r000747_1 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000747_1 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000747_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000747_8 & 2) != 0) {
            stage_v_136 = (pub_r000747_23 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000747_23 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000747_23 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000747_10 & 2) != 0) {
            stage_v_137 = (pub_r000747_11 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000747_11 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000747_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000747_3 & 2) != 0) {
            stage_v_138 = (pub_r000747_10 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000747_10 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000747_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
