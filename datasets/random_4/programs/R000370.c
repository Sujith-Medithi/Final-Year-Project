/*
 * Benchmark Program: R000370
 * Family: arithmetic_flow
 * Generator Seed: 437013
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000370_7013_0 {
    int heading;
    int pitch;
    unsigned char coord_y;
    int coord_x;
    int buffer[3];
};

struct DeviceConfig_R000370_7013_1 {
    short port;
    short baud_rate;
    unsigned char stop_bits;
    int id;
    int buffer[3];
};

struct StreamBuffer_R000370_7013_2 {
    short checksum;
    unsigned char tail;
    unsigned char watermark;
    unsigned char capacity;
    unsigned char state;
    int buffer[3];
};

union ColorPixel_R000370_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000370_7013_0(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_54 = (aux + st.buffer[1]) & 3;
    switch (tracker_54) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_66 = local_arr[aux % 3];
    acc = (acc + quantum_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_14 = local_arr[aux % 3];
    acc = (acc + threshold_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_2(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_12 = 0;
    for (int k = 0; k < 3; k++) {
        bound_12 = (bound_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_12) & 127;
    }
    int quantum_89 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_89 > 16) {
        acc = (acc + quantum_89 * 2 + 5) & 127;
        aux ^= (quantum_89 & 15);
    } else {
        acc = (acc - quantum_89 + 11) & 127;
        aux += 3;
    }
    int damping_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_3(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int bound_24 = 0;
    for (int k = 0; k < 3; k++) {
        bound_24 = (bound_24 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_24) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_95 = local_arr[aux % 3];
    acc = (acc + stride_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int checksum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_39) & 63;
    acc ^= aux;
    int scale_27 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_27 > 30) {
        acc = (acc + scale_27 * 2 + 5) & 127;
        aux ^= (scale_27 & 15);
    } else {
        acc = (acc - scale_27 + 11) & 127;
        aux += 3;
    }
    int anchor_54 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_54 = (anchor_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_54) & 127;
    }
    int margin_16 = (aux + st.buffer[1]) & 3;
    switch (margin_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_5(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int accumulator_44 = local_arr[aux % 3];
    acc = (acc + accumulator_44 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_28 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_28 > 20) {
        acc = (acc + segment_28 * 2 + 5) & 127;
        aux ^= (segment_28 & 15);
    } else {
        acc = (acc - segment_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_6(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int checksum_42 = (aux + st.buffer[1]) & 3;
    switch (checksum_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000370_7013_7(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int scale_21 = local_arr[aux % 3];
    acc = (acc + scale_21 * 2) & 127;
    int window_98 = (aux + st.buffer[1]) & 3;
    switch (window_98) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_38 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_38 = (quantum_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_38) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_8(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_92 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_92 > 13) {
        acc = (acc + mask_92 * 2 + 5) & 127;
        aux ^= (mask_92 & 15);
    } else {
        acc = (acc - mask_92 + 11) & 127;
        aux += 3;
    }
    int quotient_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000370_7013_9(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int weight_89 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_89 > 30) {
        acc = (acc + weight_89 * 2 + 5) & 127;
        aux ^= (weight_89 & 15);
    } else {
        acc = (acc - weight_89 + 11) & 127;
        aux += 3;
    }
    int stride_22 = 0;
    for (int k = 0; k < 2; k++) {
        stride_22 = (stride_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_22) & 127;
    }
    int quotient_94 = (aux + st.buffer[1]) & 3;
    switch (quotient_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000370_7013_10(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_53 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_53 > 42) {
        acc = (acc + scale_53 * 2 + 5) & 127;
        aux ^= (scale_53 & 15);
    } else {
        acc = (acc - scale_53 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_33 = local_arr[aux % 3];
    acc = (acc + accumulator_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_11(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int checksum_44 = (aux + st.buffer[1]) & 3;
    switch (checksum_44) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_62) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_65 = local_arr[aux % 3];
    acc = (acc + phase_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int pivot_15 = (aux + st.buffer[1]) & 3;
    switch (pivot_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_19 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_19 > 26) {
        acc = (acc + residue_19 * 2 + 5) & 127;
        aux ^= (residue_19 & 15);
    } else {
        acc = (acc - residue_19 + 11) & 127;
        aux += 3;
    }
    int weight_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000370_7013_13(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int tally_35 = (aux + st.buffer[1]) & 3;
    switch (tally_35) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_82 = local_arr[aux % 3];
    acc = (acc + threshold_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_14(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int tracker_55 = local_arr[aux % 3];
    acc = (acc + tracker_55 * 2) & 127;
    int scale_48 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_48 > 18) {
        acc = (acc + scale_48 * 2 + 5) & 127;
        aux ^= (scale_48 & 15);
    } else {
        acc = (acc - scale_48 + 11) & 127;
        aux += 3;
    }
    int segment_88 = (aux + st.buffer[1]) & 3;
    switch (segment_88) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int stride_59 = (aux + st.buffer[1]) & 3;
    switch (stride_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000370_7013_16(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000370_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int parity_77 = (aux + st.buffer[1]) & 3;
    switch (parity_77) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_55 = 0;
    for (int k = 0; k < 3; k++) {
        scale_55 = (scale_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_17(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000370_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_97 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_97 > 13) {
        acc = (acc + phase_97 * 2 + 5) & 127;
        aux ^= (phase_97 & 15);
    } else {
        acc = (acc - phase_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_64) & 63;
    acc ^= aux;
    int mask_58 = (aux + st.buffer[1]) & 3;
    switch (mask_58) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_18(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int segment_99 = local_arr[aux % 3];
    acc = (acc + segment_99 * 2) & 127;
    int weight_14 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_14 > 35) {
        acc = (acc + weight_14 * 2 + 5) & 127;
        aux ^= (weight_14 & 15);
    } else {
        acc = (acc - weight_14 + 11) & 127;
        aux += 3;
    }
    int tally_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_47) & 63;
    acc ^= aux;
    int quantum_20 = (aux + st.buffer[1]) & 3;
    switch (quantum_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000370_7013_19(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_10) & 63;
    acc ^= aux;
    int index_reg_58 = (aux + st.buffer[1]) & 3;
    switch (index_reg_58) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_19 = local_arr[aux % 3];
    acc = (acc + offset_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_20(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_95 = (aux + st.buffer[1]) & 3;
    switch (segment_95) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_55 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_55 > 38) {
        acc = (acc + metric_55 * 2 + 5) & 127;
        aux ^= (metric_55 & 15);
    } else {
        acc = (acc - metric_55 + 11) & 127;
        aux += 3;
    }
    int offset_55 = 0;
    for (int k = 0; k < 2; k++) {
        offset_55 = (offset_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_55) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_70 = local_arr[aux % 3];
    acc = (acc + checksum_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_40) & 63;
    acc ^= aux;
    int tally_49 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_49 > 39) {
        acc = (acc + tally_49 * 2 + 5) & 127;
        aux ^= (tally_49 & 15);
    } else {
        acc = (acc - tally_49 + 11) & 127;
        aux += 3;
    }
    int quantum_36 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_36 = (quantum_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_36) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000370_7013_22(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000370_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_75 = 0;
    for (int k = 0; k < 3; k++) {
        offset_75 = (offset_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_75) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_67 = local_arr[aux % 3];
    acc = (acc + parity_67 * 2) & 127;
    int scale_89 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_89 > 22) {
        acc = (acc + scale_89 * 2 + 5) & 127;
        aux ^= (scale_89 & 15);
    } else {
        acc = (acc - scale_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000370_0;
    int sec_r000370_1;
    int sec_r000370_2;
    int sec_r000370_3;
    int sec_r000370_4;
    int sec_r000370_5;
    int sec_r000370_6;
    int sec_r000370_7;
    int sec_r000370_8;
    int sec_r000370_9;
    int sec_r000370_10;
    int sec_r000370_11;
    int sec_r000370_12;
    int sec_r000370_13;
    int sec_r000370_14;
    int sec_r000370_15;
    int sec_r000370_16;
    int sec_r000370_17;
    int sec_r000370_18;
    int pub_r000370_0;
    int pub_r000370_1;
    int pub_r000370_2;
    int pub_r000370_3;
    int pub_r000370_4;
    int pub_r000370_5;
    int pub_r000370_6;
    int pub_r000370_7;
    int pub_r000370_8;
    int pub_r000370_9;
    int pub_r000370_10;
    int pub_r000370_11;
    int pub_r000370_12;
    int pub_r000370_13;
    int pub_r000370_14;
    int pub_r000370_15;
    int pub_r000370_16;
    int pub_r000370_17;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000370_0 >= -100 && pub_r000370_0 <= 100);
    __CPROVER_assume(pub_r000370_1 >= -100 && pub_r000370_1 <= 100);
    __CPROVER_assume(pub_r000370_2 >= -100 && pub_r000370_2 <= 100);
    __CPROVER_assume(pub_r000370_3 >= -100 && pub_r000370_3 <= 100);
    __CPROVER_assume(pub_r000370_4 >= -100 && pub_r000370_4 <= 100);
    __CPROVER_assume(pub_r000370_5 >= -100 && pub_r000370_5 <= 100);
    __CPROVER_assume(pub_r000370_6 >= -100 && pub_r000370_6 <= 100);
    __CPROVER_assume(pub_r000370_7 >= -100 && pub_r000370_7 <= 100);
    __CPROVER_assume(pub_r000370_8 >= -100 && pub_r000370_8 <= 100);
    __CPROVER_assume(pub_r000370_9 >= -100 && pub_r000370_9 <= 100);
    __CPROVER_assume(pub_r000370_10 >= -100 && pub_r000370_10 <= 100);
    __CPROVER_assume(pub_r000370_11 >= -100 && pub_r000370_11 <= 100);
    __CPROVER_assume(pub_r000370_12 >= -100 && pub_r000370_12 <= 100);
    __CPROVER_assume(pub_r000370_13 >= -100 && pub_r000370_13 <= 100);
    __CPROVER_assume(pub_r000370_14 >= -100 && pub_r000370_14 <= 100);
    __CPROVER_assume(pub_r000370_15 >= -100 && pub_r000370_15 <= 100);
    __CPROVER_assume(pub_r000370_16 >= -100 && pub_r000370_16 <= 100);
    __CPROVER_assume(pub_r000370_17 >= -100 && pub_r000370_17 <= 100);
    __CPROVER_assume(sec_r000370_0 >= 0 && sec_r000370_0 <= 255);
    __CPROVER_assume(sec_r000370_1 >= 0 && sec_r000370_1 <= 255);
    __CPROVER_assume(sec_r000370_2 >= 0 && sec_r000370_2 <= 255);
    __CPROVER_assume(sec_r000370_3 >= 0 && sec_r000370_3 <= 255);
    __CPROVER_assume(sec_r000370_4 >= 0 && sec_r000370_4 <= 255);
    __CPROVER_assume(sec_r000370_5 >= 0 && sec_r000370_5 <= 255);
    __CPROVER_assume(sec_r000370_6 >= 0 && sec_r000370_6 <= 255);
    __CPROVER_assume(sec_r000370_7 >= 0 && sec_r000370_7 <= 255);
    __CPROVER_assume(sec_r000370_8 >= 0 && sec_r000370_8 <= 255);
    __CPROVER_assume(sec_r000370_9 >= 0 && sec_r000370_9 <= 255);
    __CPROVER_assume(sec_r000370_10 >= 0 && sec_r000370_10 <= 255);
    __CPROVER_assume(sec_r000370_11 >= 0 && sec_r000370_11 <= 255);
    __CPROVER_assume(sec_r000370_12 >= 0 && sec_r000370_12 <= 255);
    __CPROVER_assume(sec_r000370_13 >= 0 && sec_r000370_13 <= 255);
    __CPROVER_assume(sec_r000370_14 >= 0 && sec_r000370_14 <= 255);
    __CPROVER_assume(sec_r000370_15 >= 0 && sec_r000370_15 <= 255);
    __CPROVER_assume(sec_r000370_16 >= 0 && sec_r000370_16 <= 255);
    __CPROVER_assume(sec_r000370_17 >= 0 && sec_r000370_17 <= 255);
    __CPROVER_assume(sec_r000370_18 >= 0 && sec_r000370_18 <= 255);

    struct Vector3D_R000370_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000370_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000370_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000370_0 + 7) & 15;
    struct DeviceConfig_R000370_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000370_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000370_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000370_0 + 9) & 15;
    struct StreamBuffer_R000370_7013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000370_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000370_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000370_0 + 11) & 15;

    union ColorPixel_R000370_7013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 36) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 51) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 39) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 54) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 16) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 31) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 14) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 29) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

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
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 39) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 54) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 18) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 33) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 12) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 27) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 36) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 51) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 12) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 27) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_2.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 24) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 39) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 31) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 46) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 36) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 51) {
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
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 23) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 38) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 18) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 33) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 38) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 53) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 83 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 35) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 50) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 31) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 46) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 27) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 42) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 40) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 55) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (out_sink > 100) ? (chk_sum & 31) : (102 & 31);
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= (stage_v_97 << 1) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 100 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 101) & 15;
    int stage_v_100 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= stage_v_100;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 106) & 15;
    int stage_v_105 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= stage_v_105;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 38) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 53) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 40) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 55) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_1.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 32) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 47) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 23) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 38) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 22) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 37) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (out_sink > 100) ? (chk_sum & 31) : (136 & 31);
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= (stage_v_131 << 1) & 127;

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
    int stage_v_134 = (st_var_2.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 35) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 50) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 138) & 15;
    int stage_v_137 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    chk_sum ^= stage_v_137;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (st_var_0.buffer[0] * 2 + 421) & 63;
    if (stage_v_138 > 13) {
        out_sink = (out_sink + stage_v_138 - 5) & 255;
        if (stage_v_138 > 28) {
            chk_sum ^= (stage_v_138 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_138 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 139 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 140) & 15;
    int stage_v_139 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= stage_v_139;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_2.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 33) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 48) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (out_sink > 100) ? (chk_sum & 31) : (148 & 31);
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= (stage_v_143 << 1) & 127;

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0];
    table[0] = (table[1] + 297) & 63;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_2.buffer[0] ^ 152) & 3;
    switch (stage_v_149) {
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

    /* Execution Pipeline Stage 150 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 34) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 49) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 154) & 15;
    int stage_v_153 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= stage_v_153;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = table[1];
    table[1] = (table[2] + 323) & 63;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (out_sink > 100) ? (chk_sum & 31) : (168 & 31);
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= (stage_v_163 << 1) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] ^ 168) & 3;
    switch (stage_v_165) {
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

    /* Execution Pipeline Stage 166 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 167) & 15;
    int stage_v_166 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= stage_v_166;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (out_sink > 100) ? (chk_sum & 31) : (173 & 31);
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= (stage_v_168 << 1) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
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

    /* Execution Pipeline Stage 170 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 171) & 15;
    int stage_v_170 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= stage_v_170;

    /* Execution Pipeline Stage 171 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 173) & 15;
    int stage_v_172 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= stage_v_172;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_173 = (stage_v_173 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[1] * 2 + 532) & 63;
    if (stage_v_175 > 32) {
        out_sink = (out_sink + stage_v_175 - 5) & 255;
        if (stage_v_175 > 47) {
            chk_sum ^= (stage_v_175 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_175 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_176 = (stage_v_176 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (out_sink > 100) ? (chk_sum & 31) : (182 & 31);
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= (stage_v_177 << 1) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 14) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 29) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 181) & 15;
    int stage_v_180 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= stage_v_180;

    /* Execution Pipeline Stage 181 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 182) & 15;
    int stage_v_181 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= stage_v_181;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = table[2];
    table[2] = (table[3] + 365) & 63;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_183 = (stage_v_183 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_1.buffer[0] ^ 187) & 3;
    switch (stage_v_184) {
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

    /* Execution Pipeline Stage 185 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 186) & 15;
    int stage_v_185 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= stage_v_185;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_188 = (stage_v_188 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_188) & 127;
    }
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_189 = (stage_v_189 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_189) & 127;
    }
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = table[3];
    table[3] = (table[0] + 383) & 63;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 193) & 15;
    int stage_v_192 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_192) & 255;
    chk_sum ^= stage_v_192;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = table[1];
    table[1] = (table[2] + 387) & 63;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_194 = (stage_v_194 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_194) & 127;
    }
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 196) & 15;
    int stage_v_195 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    chk_sum ^= stage_v_195;

    /* Security Information Flow: Family = arithmetic_flow */
    int arith_v_0 = (sec_r000370_9 * 3 + pub_r000370_9) & 127;
    int arith_v_1 = (arith_v_0 - (sec_r000370_17 * 2)) & 127;
    int arith_v_2 = (arith_v_1 + (sec_r000370_18 * 2)) & 127;
    int arith_v_3 = (arith_v_2 ^ (sec_r000370_9 * 2)) & 127;
    out_sink += arith_v_3 & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
