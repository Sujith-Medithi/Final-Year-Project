/*
 * Benchmark Program: R000277
 * Security Family: nested_implicit_flow
 * Generator Seed: 527713
 * High Inputs: 16 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000277_7713_0 {
    unsigned char scale;
    short trace;
    int determinant;
    short density;
    int stride;
    int dim;
    int buffer[3];
};

struct Vector3D_R000277_7713_1 {
    int coord_x;
    unsigned char heading;
    unsigned char norm_sq;
    int buffer[3];
};

struct DeviceConfig_R000277_7713_2 {
    unsigned char parity;
    int timeout;
    short port;
    int baud_rate;
    int id;
    int buffer[3];
};

struct Transaction_R000277_7713_3 {
    int status;
    unsigned char rate;
    int auth_code;
    short fee;
    int buffer[3];
};

union ColorPixel_R000277_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000277_7713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000277_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_76 = (aux + st.buffer[1]) & 3;
    switch (coefficient_76) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_31 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_31 > 14) {
        acc = (acc + scale_31 * 2 + 5) & 127;
        aux ^= (scale_31 & 15);
    } else {
        acc = (acc - scale_31 + 11) & 127;
        aux += 3;
    }
    int coefficient_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000277_7713_1(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_62 = (aux + st.buffer[1]) & 3;
    switch (mask_62) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000277_7713_2(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int vector_45 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_45 > 36) {
        acc = (acc + vector_45 * 2 + 5) & 127;
        aux ^= (vector_45 & 15);
    } else {
        acc = (acc - vector_45 + 11) & 127;
        aux += 3;
    }
    int metric_91 = (aux + st.buffer[1]) & 3;
    switch (metric_91) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_54) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_3(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_70 = (aux + st.buffer[1]) & 3;
    switch (scale_70) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_81 = local_arr[aux % 3];
    acc = (acc + coefficient_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_4(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int tracker_78 = local_arr[aux % 3];
    acc = (acc + tracker_78 * 2) & 127;
    int segment_88 = (aux + st.buffer[1]) & 3;
    switch (segment_88) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000277_7713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_98) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_6(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_73 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_73 > 28) {
        acc = (acc + mask_73 * 2 + 5) & 127;
        aux ^= (mask_73 & 15);
    } else {
        acc = (acc - mask_73 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_94 = local_arr[aux % 3];
    acc = (acc + metric_94 * 2) & 127;
    int parity_72 = (aux + st.buffer[1]) & 3;
    switch (parity_72) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int accumulator_37 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_37 > 26) {
        acc = (acc + accumulator_37 * 2 + 5) & 127;
        aux ^= (accumulator_37 & 15);
    } else {
        acc = (acc - accumulator_37 + 11) & 127;
        aux += 3;
    }
    int window_64 = (aux + st.buffer[1]) & 3;
    switch (window_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_35 = local_arr[aux % 3];
    acc = (acc + index_reg_35 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_78 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_78 > 14) {
        acc = (acc + offset_78 * 2 + 5) & 127;
        aux ^= (offset_78 & 15);
    } else {
        acc = (acc - offset_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int cursor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_64) & 63;
    acc ^= aux;
    int offset_56 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_56 > 10) {
        acc = (acc + offset_56 * 2 + 5) & 127;
        aux ^= (offset_56 & 15);
    } else {
        acc = (acc - offset_56 + 11) & 127;
        aux += 3;
    }
    int phase_16 = (aux + st.buffer[1]) & 3;
    switch (phase_16) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_10 = (aux + st.buffer[1]) & 3;
    switch (quotient_10) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tracker_41 = (aux + st.buffer[1]) & 3;
    switch (tracker_41) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_13(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_85 = local_arr[aux % 3];
    acc = (acc + cursor_85 * 2) & 127;
    int offset_59 = (aux + st.buffer[1]) & 3;
    switch (offset_59) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_14(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int margin_63 = (aux + st.buffer[1]) & 3;
    switch (margin_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_80 = local_arr[aux % 3];
    acc = (acc + vector_80 * 2) & 127;
    int factor_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000277_7713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_54 = (aux + st.buffer[1]) & 3;
    switch (cursor_54) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_40) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_92 = local_arr[aux % 3];
    acc = (acc + threshold_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_16(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int tracker_13 = local_arr[aux % 3];
    acc = (acc + tracker_13 * 2) & 127;
    int quantum_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_99) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_61 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_61 > 14) {
        acc = (acc + anchor_61 * 2 + 5) & 127;
        aux ^= (anchor_61 & 15);
    } else {
        acc = (acc - anchor_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int anchor_95 = local_arr[aux % 3];
    acc = (acc + anchor_95 * 2) & 127;
    int window_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_76) & 63;
    acc ^= aux;
    int vector_87 = (aux + st.buffer[1]) & 3;
    switch (vector_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000277_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quantum_18 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_18 > 50) {
        acc = (acc + quantum_18 * 2 + 5) & 127;
        aux ^= (quantum_18 & 15);
    } else {
        acc = (acc - quantum_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_81 = local_arr[aux % 3];
    acc = (acc + quantum_81 * 2) & 127;
    int sample_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_71) & 63;
    acc ^= aux;
    int residue_23 = (aux + st.buffer[1]) & 3;
    switch (residue_23) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_19(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int checksum_31 = local_arr[aux % 3];
    acc = (acc + checksum_31 * 2) & 127;
    int parity_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_20) & 63;
    acc ^= aux;
    int vector_15 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_15 > 50) {
        acc = (acc + vector_15 * 2 + 5) & 127;
        aux ^= (vector_15 & 15);
    } else {
        acc = (acc - vector_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int residue_81 = (aux + st.buffer[1]) & 3;
    switch (residue_81) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_92 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_92 > 38) {
        acc = (acc + anchor_92 * 2 + 5) & 127;
        aux ^= (anchor_92 & 15);
    } else {
        acc = (acc - anchor_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000277_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tally_92 = (aux + st.buffer[1]) & 3;
    switch (tally_92) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_27 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_27 > 11) {
        acc = (acc + metric_27 * 2 + 5) & 127;
        aux ^= (metric_27 & 15);
    } else {
        acc = (acc - metric_27 + 11) & 127;
        aux += 3;
    }
    int sample_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_75) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_88 = local_arr[aux % 3];
    acc = (acc + index_reg_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000277_7713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000277_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_47 = local_arr[aux % 3];
    acc = (acc + bound_47 * 2) & 127;
    int parity_67 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_67 > 26) {
        acc = (acc + parity_67 * 2 + 5) & 127;
        aux ^= (parity_67 & 15);
    } else {
        acc = (acc - parity_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000277_7713_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000277_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int phase_82 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_82 > 24) {
        acc = (acc + phase_82 * 2 + 5) & 127;
        aux ^= (phase_82 & 15);
    } else {
        acc = (acc - phase_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000277_0;
    int sec_r000277_1;
    int sec_r000277_2;
    int sec_r000277_3;
    int sec_r000277_4;
    int sec_r000277_5;
    int sec_r000277_6;
    int sec_r000277_7;
    int sec_r000277_8;
    int sec_r000277_9;
    int sec_r000277_10;
    int sec_r000277_11;
    int sec_r000277_12;
    int sec_r000277_13;
    int sec_r000277_14;
    int sec_r000277_15;
    int pub_r000277_0;
    int pub_r000277_1;
    int pub_r000277_2;
    int pub_r000277_3;
    int pub_r000277_4;
    int pub_r000277_5;
    int pub_r000277_6;
    int pub_r000277_7;
    int pub_r000277_8;
    int pub_r000277_9;
    int pub_r000277_10;
    int pub_r000277_11;
    int pub_r000277_12;
    int pub_r000277_13;
    int pub_r000277_14;
    int pub_r000277_15;
    int pub_r000277_16;
    int pub_r000277_17;
    int pub_r000277_18;
    int pub_r000277_19;
    int pub_r000277_20;
    int pub_r000277_21;
    int pub_r000277_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000277_0 >= -100 && pub_r000277_0 <= 100);
    __CPROVER_assume(pub_r000277_1 >= -100 && pub_r000277_1 <= 100);
    __CPROVER_assume(pub_r000277_2 >= -100 && pub_r000277_2 <= 100);
    __CPROVER_assume(pub_r000277_3 >= -100 && pub_r000277_3 <= 100);
    __CPROVER_assume(pub_r000277_4 >= -100 && pub_r000277_4 <= 100);
    __CPROVER_assume(pub_r000277_5 >= -100 && pub_r000277_5 <= 100);
    __CPROVER_assume(pub_r000277_6 >= -100 && pub_r000277_6 <= 100);
    __CPROVER_assume(pub_r000277_7 >= -100 && pub_r000277_7 <= 100);
    __CPROVER_assume(pub_r000277_8 >= -100 && pub_r000277_8 <= 100);
    __CPROVER_assume(pub_r000277_9 >= -100 && pub_r000277_9 <= 100);
    __CPROVER_assume(pub_r000277_10 >= -100 && pub_r000277_10 <= 100);
    __CPROVER_assume(pub_r000277_11 >= -100 && pub_r000277_11 <= 100);
    __CPROVER_assume(pub_r000277_12 >= -100 && pub_r000277_12 <= 100);
    __CPROVER_assume(pub_r000277_13 >= -100 && pub_r000277_13 <= 100);
    __CPROVER_assume(pub_r000277_14 >= -100 && pub_r000277_14 <= 100);
    __CPROVER_assume(pub_r000277_15 >= -100 && pub_r000277_15 <= 100);
    __CPROVER_assume(pub_r000277_16 >= -100 && pub_r000277_16 <= 100);
    __CPROVER_assume(pub_r000277_17 >= -100 && pub_r000277_17 <= 100);
    __CPROVER_assume(pub_r000277_18 >= -100 && pub_r000277_18 <= 100);
    __CPROVER_assume(pub_r000277_19 >= -100 && pub_r000277_19 <= 100);
    __CPROVER_assume(pub_r000277_20 >= -100 && pub_r000277_20 <= 100);
    __CPROVER_assume(pub_r000277_21 >= -100 && pub_r000277_21 <= 100);
    __CPROVER_assume(pub_r000277_22 >= -100 && pub_r000277_22 <= 100);
    __CPROVER_assume(sec_r000277_0 >= 0 && sec_r000277_0 <= 255);
    __CPROVER_assume(sec_r000277_1 >= 0 && sec_r000277_1 <= 255);
    __CPROVER_assume(sec_r000277_2 >= 0 && sec_r000277_2 <= 255);
    __CPROVER_assume(sec_r000277_3 >= 0 && sec_r000277_3 <= 255);
    __CPROVER_assume(sec_r000277_4 >= 0 && sec_r000277_4 <= 255);
    __CPROVER_assume(sec_r000277_5 >= 0 && sec_r000277_5 <= 255);
    __CPROVER_assume(sec_r000277_6 >= 0 && sec_r000277_6 <= 255);
    __CPROVER_assume(sec_r000277_7 >= 0 && sec_r000277_7 <= 255);
    __CPROVER_assume(sec_r000277_8 >= 0 && sec_r000277_8 <= 255);
    __CPROVER_assume(sec_r000277_9 >= 0 && sec_r000277_9 <= 255);
    __CPROVER_assume(sec_r000277_10 >= 0 && sec_r000277_10 <= 255);
    __CPROVER_assume(sec_r000277_11 >= 0 && sec_r000277_11 <= 255);
    __CPROVER_assume(sec_r000277_12 >= 0 && sec_r000277_12 <= 255);
    __CPROVER_assume(sec_r000277_13 >= 0 && sec_r000277_13 <= 255);
    __CPROVER_assume(sec_r000277_14 >= 0 && sec_r000277_14 <= 255);
    __CPROVER_assume(sec_r000277_15 >= 0 && sec_r000277_15 <= 255);

    struct MatrixBlock_R000277_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000277_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000277_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000277_0 + 7) & 15;
    struct Vector3D_R000277_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000277_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000277_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000277_0 + 9) & 15;
    struct DeviceConfig_R000277_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000277_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000277_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000277_0 + 11) & 15;
    struct Transaction_R000277_7713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000277_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000277_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000277_0 + 13) & 15;

    union ColorPixel_R000277_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 22) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 37) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 18) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 33) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 24) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 39) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 24) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 39) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 31) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 46) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 35) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 50) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 15) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 30) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((sec_r000277_2 & 1) != 0) {
        if ((sec_r000277_6 & 2) != 0) {
            stage_v_25 = (pub_r000277_19 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000277_19 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000277_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_26 = (pub_r000277_16 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000277_16 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000277_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_27 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000277_6 & 2) != 0) {
            stage_v_28 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((sec_r000277_11 & 1) != 0) {
        if ((sec_r000277_15 & 2) != 0) {
            stage_v_29 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_30 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((sec_r000277_10 & 1) != 0) {
        if ((sec_r000277_5 & 2) != 0) {
            stage_v_31 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_32 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((sec_r000277_7 & 1) != 0) {
        if ((sec_r000277_8 & 2) != 0) {
            stage_v_33 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000277_2 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_34 = (pub_r000277_0 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000277_0 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000277_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000277_15 & 2) != 0) {
            stage_v_35 = (pub_r000277_18 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000277_18 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000277_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_36 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_37 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000277_1 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_38 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000277_12 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_39 = (pub_r000277_4 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000277_4 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000277_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_40 = (pub_r000277_19 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000277_19 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000277_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_41 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000277_15 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_42 = (pub_r000277_17 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000277_17 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000277_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_43 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_44 = (pub_r000277_15 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000277_15 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000277_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_45 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_46 = (pub_r000277_14 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000277_14 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000277_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_47 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000277_8 & 2) != 0) {
            stage_v_48 = (pub_r000277_18 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000277_18 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000277_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_49 = (pub_r000277_0 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000277_0 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000277_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_50 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000277_3 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_51 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000277_1 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_52 = (pub_r000277_0 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000277_0 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000277_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_53 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000277_7 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_54 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000277_4 & 2) != 0) {
            stage_v_55 = (pub_r000277_9 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000277_9 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000277_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_56 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_57 = (pub_r000277_9 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000277_9 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000277_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000277_9 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_58 = (pub_r000277_15 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000277_15 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000277_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_59 = (pub_r000277_1 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000277_1 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000277_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_60 = (pub_r000277_7 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000277_7 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000277_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000277_3 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_61 = (pub_r000277_19 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000277_19 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000277_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000277_2 & 2) != 0) {
            stage_v_62 = (pub_r000277_4 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000277_4 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000277_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_63 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000277_11 & 1) != 0) {
        if ((sec_r000277_5 & 2) != 0) {
            stage_v_64 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_65 = (pub_r000277_13 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000277_13 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000277_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_66 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000277_9 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_67 = (pub_r000277_11 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000277_11 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000277_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_68 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000277_0 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_69 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000277_4 & 2) != 0) {
            stage_v_70 = (pub_r000277_16 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000277_16 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000277_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000277_0 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_71 = (pub_r000277_2 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000277_2 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000277_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_72 = (pub_r000277_17 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000277_17 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000277_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000277_4 & 2) != 0) {
            stage_v_73 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_74 = (pub_r000277_1 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000277_1 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000277_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000277_2 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_75 = (pub_r000277_22 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000277_22 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000277_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_76 = (pub_r000277_14 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000277_14 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000277_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_77 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000277_7 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_78 = (pub_r000277_6 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000277_6 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000277_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000277_2 & 1) != 0) {
        if ((sec_r000277_1 & 2) != 0) {
            stage_v_79 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_80 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_81 = (pub_r000277_18 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000277_18 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000277_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000277_2 & 2) != 0) {
            stage_v_82 = (pub_r000277_4 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000277_4 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000277_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000277_0 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_83 = (pub_r000277_13 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000277_13 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000277_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000277_13 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_84 = (pub_r000277_14 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000277_14 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000277_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_85 = (pub_r000277_16 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000277_16 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000277_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000277_10 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_86 = (pub_r000277_22 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000277_22 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000277_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000277_4 & 2) != 0) {
            stage_v_87 = (pub_r000277_0 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000277_0 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000277_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_88 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_89 = (pub_r000277_13 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000277_13 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000277_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000277_14 & 2) != 0) {
            stage_v_90 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000277_8 & 2) != 0) {
            stage_v_91 = (pub_r000277_20 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000277_20 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000277_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000277_4 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_92 = (pub_r000277_4 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000277_4 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000277_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_93 = (pub_r000277_9 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000277_9 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000277_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_94 = (pub_r000277_17 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000277_17 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000277_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_95 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000277_2 & 1) != 0) {
        if ((sec_r000277_15 & 2) != 0) {
            stage_v_96 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_97 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000277_3 & 1) != 0) {
        if ((sec_r000277_15 & 2) != 0) {
            stage_v_98 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000277_1 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_99 = (pub_r000277_9 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000277_9 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000277_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000277_2 & 2) != 0) {
            stage_v_100 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000277_7 & 1) != 0) {
        if ((sec_r000277_2 & 2) != 0) {
            stage_v_101 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_102 = (pub_r000277_5 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000277_5 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000277_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000277_8 & 2) != 0) {
            stage_v_103 = (pub_r000277_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000277_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000277_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000277_14 & 2) != 0) {
            stage_v_104 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000277_4 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_105 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000277_4 & 2) != 0) {
            stage_v_106 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000277_12 & 1) != 0) {
        if ((sec_r000277_6 & 2) != 0) {
            stage_v_107 = (pub_r000277_7 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000277_7 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000277_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000277_2 & 1) != 0) {
        if ((sec_r000277_6 & 2) != 0) {
            stage_v_108 = (pub_r000277_14 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000277_14 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000277_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000277_10 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_109 = (pub_r000277_20 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000277_20 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000277_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_110 = (pub_r000277_16 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000277_16 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000277_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000277_6 & 2) != 0) {
            stage_v_111 = (pub_r000277_0 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000277_0 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000277_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_112 = (pub_r000277_17 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000277_17 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000277_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000277_2 & 2) != 0) {
            stage_v_113 = (pub_r000277_12 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000277_12 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000277_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000277_4 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_114 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000277_13 & 2) != 0) {
            stage_v_115 = (pub_r000277_21 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000277_21 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000277_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_116 = (pub_r000277_9 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000277_9 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000277_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000277_11 & 1) != 0) {
        if ((sec_r000277_10 & 2) != 0) {
            stage_v_117 = (pub_r000277_4 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000277_4 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000277_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000277_6 & 2) != 0) {
            stage_v_118 = (pub_r000277_3 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000277_3 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000277_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000277_8 & 1) != 0) {
        if ((sec_r000277_5 & 2) != 0) {
            stage_v_119 = (pub_r000277_7 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000277_7 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000277_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000277_3 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_120 = (pub_r000277_2 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000277_2 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000277_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000277_5 & 2) != 0) {
            stage_v_121 = (pub_r000277_1 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000277_1 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000277_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000277_4 & 2) != 0) {
            stage_v_122 = (pub_r000277_22 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000277_22 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000277_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000277_15 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_123 = (pub_r000277_4 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000277_4 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000277_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000277_9 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_124 = (pub_r000277_18 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000277_18 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000277_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000277_5 & 2) != 0) {
            stage_v_125 = (pub_r000277_18 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000277_18 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000277_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000277_12 & 1) != 0) {
        if ((sec_r000277_0 & 2) != 0) {
            stage_v_126 = (pub_r000277_19 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000277_19 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000277_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000277_11 & 1) != 0) {
        if ((sec_r000277_7 & 2) != 0) {
            stage_v_127 = (pub_r000277_11 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000277_11 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000277_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000277_9 & 2) != 0) {
            stage_v_128 = (pub_r000277_10 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000277_10 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000277_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000277_3 & 2) != 0) {
            stage_v_129 = (pub_r000277_16 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000277_16 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000277_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000277_5 & 2) != 0) {
            stage_v_130 = (pub_r000277_7 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000277_7 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000277_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000277_11 & 2) != 0) {
            stage_v_131 = (pub_r000277_8 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000277_8 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000277_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000277_15 & 2) != 0) {
            stage_v_132 = (pub_r000277_7 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000277_7 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000277_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000277_12 & 2) != 0) {
            stage_v_133 = (pub_r000277_7 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000277_7 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000277_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
