/*
 * Benchmark Program: R000377
 * Security Family: nested_implicit_flow
 * Generator Seed: 537713
 * High Inputs: 16 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000377_7713_0 {
    short coord_z;
    int coord_x;
    short coord_y;
    unsigned char heading;
    short pitch;
    short norm_sq;
    int buffer[3];
};

struct Transaction_R000377_7713_1 {
    unsigned char balance;
    int rate;
    int account_id;
    int buffer[3];
};

struct SensorNode_R000377_7713_2 {
    short offset;
    int calib;
    short threshold;
    int reading;
    int buffer[3];
};

struct StreamBuffer_R000377_7713_3 {
    int tail;
    int head;
    unsigned char watermark;
    int buffer[3];
};

union RegisterBank_R000377_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000377_7713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int weight_92 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_92 > 41) {
        acc = (acc + weight_92 * 2 + 5) & 127;
        aux ^= (weight_92 & 15);
    } else {
        acc = (acc - weight_92 + 11) & 127;
        aux += 3;
    }
    int factor_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_83) & 63;
    acc ^= aux;
    int tracker_42 = (aux + st.buffer[1]) & 3;
    switch (tracker_42) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int sample_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_45) & 63;
    acc ^= aux;
    int anchor_65 = (aux + st.buffer[1]) & 3;
    switch (anchor_65) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_61) & 63;
    acc ^= aux;
    int pivot_82 = (aux + st.buffer[1]) & 3;
    switch (pivot_82) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_3(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int metric_52 = local_arr[aux % 3];
    acc = (acc + metric_52 * 2) & 127;
    int pivot_20 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_20 > 47) {
        acc = (acc + pivot_20 * 2 + 5) & 127;
        aux ^= (pivot_20 & 15);
    } else {
        acc = (acc - pivot_20 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_45) & 63;
    acc ^= aux;
    int segment_19 = (aux + st.buffer[1]) & 3;
    switch (segment_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int coefficient_16 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_16 > 24) {
        acc = (acc + coefficient_16 * 2 + 5) & 127;
        aux ^= (coefficient_16 & 15);
    } else {
        acc = (acc - coefficient_16 + 11) & 127;
        aux += 3;
    }
    int phase_59 = (aux + st.buffer[1]) & 3;
    switch (phase_59) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_75) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000377_7713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000377_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_10) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_48 = local_arr[aux % 3];
    acc = (acc + coefficient_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quotient_76 = (aux + st.buffer[1]) & 3;
    switch (quotient_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_97 = local_arr[aux % 3];
    acc = (acc + accumulator_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_8(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_30 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_30 > 18) {
        acc = (acc + tracker_30 * 2 + 5) & 127;
        aux ^= (tracker_30 & 15);
    } else {
        acc = (acc - tracker_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_55 = local_arr[aux % 3];
    acc = (acc + checksum_55 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000377_7713_9(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_36) & 63;
    acc ^= aux;
    int mask_89 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_89 > 49) {
        acc = (acc + mask_89 * 2 + 5) & 127;
        aux ^= (mask_89 & 15);
    } else {
        acc = (acc - mask_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int mask_90 = local_arr[aux % 3];
    acc = (acc + mask_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_10(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int margin_42 = (aux + st.buffer[1]) & 3;
    switch (margin_42) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000377_7713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_44 = (aux + st.buffer[1]) & 3;
    switch (tracker_44) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_33 = local_arr[aux % 3];
    acc = (acc + weight_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_12(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int tally_68 = local_arr[aux % 3];
    acc = (acc + tally_68 * 2) & 127;
    int stride_24 = (aux + st.buffer[1]) & 3;
    switch (stride_24) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_68 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_68 > 16) {
        acc = (acc + segment_68 * 2 + 5) & 127;
        aux ^= (segment_68 & 15);
    } else {
        acc = (acc - segment_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int cursor_85 = local_arr[aux % 3];
    acc = (acc + cursor_85 * 2) & 127;
    int delta_54 = (aux + st.buffer[1]) & 3;
    switch (delta_54) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_14(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_69 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_69 > 36) {
        acc = (acc + mask_69 * 2 + 5) & 127;
        aux ^= (mask_69 & 15);
    } else {
        acc = (acc - mask_69 + 11) & 127;
        aux += 3;
    }
    int segment_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_79 = local_arr[aux % 3];
    acc = (acc + offset_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000377_7713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_75 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_75 > 26) {
        acc = (acc + quotient_75 * 2 + 5) & 127;
        aux ^= (quotient_75 & 15);
    } else {
        acc = (acc - quotient_75 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_36 = local_arr[aux % 3];
    acc = (acc + margin_36 * 2) & 127;
    int window_38 = (aux + st.buffer[1]) & 3;
    switch (window_38) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_24 = local_arr[aux % 3];
    acc = (acc + stride_24 * 2) & 127;
    int factor_19 = (aux + st.buffer[1]) & 3;
    switch (factor_19) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_59 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_59 > 28) {
        acc = (acc + pivot_59 * 2 + 5) & 127;
        aux ^= (pivot_59 & 15);
    } else {
        acc = (acc - pivot_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int margin_14 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_14 > 40) {
        acc = (acc + margin_14 * 2 + 5) & 127;
        aux ^= (margin_14 & 15);
    } else {
        acc = (acc - margin_14 + 11) & 127;
        aux += 3;
    }
    int vector_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000377_7713_18(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_73) & 63;
    acc ^= aux;
    int weight_47 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_47 > 38) {
        acc = (acc + weight_47 * 2 + 5) & 127;
        aux ^= (weight_47 & 15);
    } else {
        acc = (acc - weight_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000377_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_26 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_26 > 19) {
        acc = (acc + cursor_26 * 2 + 5) & 127;
        aux ^= (cursor_26 & 15);
    } else {
        acc = (acc - cursor_26 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_72 = local_arr[aux % 3];
    acc = (acc + damping_72 * 2) & 127;
    int anchor_26 = (aux + st.buffer[1]) & 3;
    switch (anchor_26) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000377_7713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000377_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int coefficient_72 = local_arr[aux % 3];
    acc = (acc + coefficient_72 * 2) & 127;
    int stride_50 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_50 > 27) {
        acc = (acc + stride_50 * 2 + 5) & 127;
        aux ^= (stride_50 & 15);
    } else {
        acc = (acc - stride_50 + 11) & 127;
        aux += 3;
    }
    int checksum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000377_0;
    int sec_r000377_1;
    int sec_r000377_2;
    int sec_r000377_3;
    int sec_r000377_4;
    int sec_r000377_5;
    int sec_r000377_6;
    int sec_r000377_7;
    int sec_r000377_8;
    int sec_r000377_9;
    int sec_r000377_10;
    int sec_r000377_11;
    int sec_r000377_12;
    int sec_r000377_13;
    int sec_r000377_14;
    int sec_r000377_15;
    int pub_r000377_0;
    int pub_r000377_1;
    int pub_r000377_2;
    int pub_r000377_3;
    int pub_r000377_4;
    int pub_r000377_5;
    int pub_r000377_6;
    int pub_r000377_7;
    int pub_r000377_8;
    int pub_r000377_9;
    int pub_r000377_10;
    int pub_r000377_11;
    int pub_r000377_12;
    int pub_r000377_13;
    int pub_r000377_14;
    int pub_r000377_15;
    int pub_r000377_16;
    int pub_r000377_17;
    int pub_r000377_18;
    int pub_r000377_19;
    int pub_r000377_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000377_0 >= -100 && pub_r000377_0 <= 100);
    __CPROVER_assume(pub_r000377_1 >= -100 && pub_r000377_1 <= 100);
    __CPROVER_assume(pub_r000377_2 >= -100 && pub_r000377_2 <= 100);
    __CPROVER_assume(pub_r000377_3 >= -100 && pub_r000377_3 <= 100);
    __CPROVER_assume(pub_r000377_4 >= -100 && pub_r000377_4 <= 100);
    __CPROVER_assume(pub_r000377_5 >= -100 && pub_r000377_5 <= 100);
    __CPROVER_assume(pub_r000377_6 >= -100 && pub_r000377_6 <= 100);
    __CPROVER_assume(pub_r000377_7 >= -100 && pub_r000377_7 <= 100);
    __CPROVER_assume(pub_r000377_8 >= -100 && pub_r000377_8 <= 100);
    __CPROVER_assume(pub_r000377_9 >= -100 && pub_r000377_9 <= 100);
    __CPROVER_assume(pub_r000377_10 >= -100 && pub_r000377_10 <= 100);
    __CPROVER_assume(pub_r000377_11 >= -100 && pub_r000377_11 <= 100);
    __CPROVER_assume(pub_r000377_12 >= -100 && pub_r000377_12 <= 100);
    __CPROVER_assume(pub_r000377_13 >= -100 && pub_r000377_13 <= 100);
    __CPROVER_assume(pub_r000377_14 >= -100 && pub_r000377_14 <= 100);
    __CPROVER_assume(pub_r000377_15 >= -100 && pub_r000377_15 <= 100);
    __CPROVER_assume(pub_r000377_16 >= -100 && pub_r000377_16 <= 100);
    __CPROVER_assume(pub_r000377_17 >= -100 && pub_r000377_17 <= 100);
    __CPROVER_assume(pub_r000377_18 >= -100 && pub_r000377_18 <= 100);
    __CPROVER_assume(pub_r000377_19 >= -100 && pub_r000377_19 <= 100);
    __CPROVER_assume(pub_r000377_20 >= -100 && pub_r000377_20 <= 100);
    __CPROVER_assume(sec_r000377_0 >= 0 && sec_r000377_0 <= 255);
    __CPROVER_assume(sec_r000377_1 >= 0 && sec_r000377_1 <= 255);
    __CPROVER_assume(sec_r000377_2 >= 0 && sec_r000377_2 <= 255);
    __CPROVER_assume(sec_r000377_3 >= 0 && sec_r000377_3 <= 255);
    __CPROVER_assume(sec_r000377_4 >= 0 && sec_r000377_4 <= 255);
    __CPROVER_assume(sec_r000377_5 >= 0 && sec_r000377_5 <= 255);
    __CPROVER_assume(sec_r000377_6 >= 0 && sec_r000377_6 <= 255);
    __CPROVER_assume(sec_r000377_7 >= 0 && sec_r000377_7 <= 255);
    __CPROVER_assume(sec_r000377_8 >= 0 && sec_r000377_8 <= 255);
    __CPROVER_assume(sec_r000377_9 >= 0 && sec_r000377_9 <= 255);
    __CPROVER_assume(sec_r000377_10 >= 0 && sec_r000377_10 <= 255);
    __CPROVER_assume(sec_r000377_11 >= 0 && sec_r000377_11 <= 255);
    __CPROVER_assume(sec_r000377_12 >= 0 && sec_r000377_12 <= 255);
    __CPROVER_assume(sec_r000377_13 >= 0 && sec_r000377_13 <= 255);
    __CPROVER_assume(sec_r000377_14 >= 0 && sec_r000377_14 <= 255);
    __CPROVER_assume(sec_r000377_15 >= 0 && sec_r000377_15 <= 255);

    struct Vector3D_R000377_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000377_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000377_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000377_0 + 7) & 15;
    struct Transaction_R000377_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000377_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000377_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000377_0 + 9) & 15;
    struct SensorNode_R000377_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000377_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000377_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000377_0 + 11) & 15;
    struct StreamBuffer_R000377_7713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000377_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000377_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000377_0 + 13) & 15;

    union RegisterBank_R000377_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 14) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 29) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 18) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 33) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 38) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 53) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000377_4 & 1) != 0) {
        if ((sec_r000377_0 & 2) != 0) {
            stage_v_21 = (pub_r000377_4 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000377_4 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000377_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((sec_r000377_12 & 1) != 0) {
        if ((sec_r000377_2 & 2) != 0) {
            stage_v_22 = (pub_r000377_4 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000377_4 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000377_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((sec_r000377_10 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_23 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((sec_r000377_4 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_24 = (pub_r000377_2 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000377_2 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000377_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000377_13 & 2) != 0) {
            stage_v_25 = (pub_r000377_7 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000377_7 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000377_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((sec_r000377_15 & 1) != 0) {
        if ((sec_r000377_3 & 2) != 0) {
            stage_v_26 = (pub_r000377_10 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000377_10 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000377_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_27 = (pub_r000377_14 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000377_14 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000377_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_28 = (pub_r000377_1 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000377_1 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000377_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_29 = (pub_r000377_17 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000377_17 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000377_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_30 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((sec_r000377_9 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_31 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_32 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000377_3 & 2) != 0) {
            stage_v_33 = (pub_r000377_2 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000377_2 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000377_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_34 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_35 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_36 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_37 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_38 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_39 = (pub_r000377_11 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000377_11 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000377_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_40 = (pub_r000377_7 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000377_7 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000377_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000377_4 & 2) != 0) {
            stage_v_41 = (pub_r000377_17 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000377_17 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000377_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000377_7 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_42 = (pub_r000377_1 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000377_1 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000377_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((sec_r000377_15 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_43 = (pub_r000377_3 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000377_3 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000377_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000377_13 & 1) != 0) {
        if ((sec_r000377_0 & 2) != 0) {
            stage_v_44 = (pub_r000377_13 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000377_13 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000377_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_45 = (pub_r000377_3 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000377_3 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000377_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_46 = (pub_r000377_6 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000377_6 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000377_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000377_13 & 2) != 0) {
            stage_v_47 = (pub_r000377_9 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000377_9 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000377_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000377_3 & 2) != 0) {
            stage_v_48 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000377_7 & 1) != 0) {
        if ((sec_r000377_13 & 2) != 0) {
            stage_v_49 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_50 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000377_2 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_51 = (pub_r000377_4 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000377_4 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000377_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000377_3 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_52 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000377_15 & 2) != 0) {
            stage_v_53 = (pub_r000377_8 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000377_8 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000377_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000377_6 & 1) != 0) {
        if ((sec_r000377_0 & 2) != 0) {
            stage_v_54 = (pub_r000377_6 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000377_6 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000377_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000377_2 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_55 = (pub_r000377_11 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000377_11 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000377_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000377_13 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_56 = (pub_r000377_2 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000377_2 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000377_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_57 = (pub_r000377_12 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000377_12 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000377_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000377_6 & 2) != 0) {
            stage_v_58 = (pub_r000377_9 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000377_9 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000377_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_59 = (pub_r000377_17 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000377_17 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000377_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000377_0 & 1) != 0) {
        if ((sec_r000377_11 & 2) != 0) {
            stage_v_60 = (pub_r000377_9 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000377_9 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000377_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_61 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000377_6 & 2) != 0) {
            stage_v_62 = (pub_r000377_4 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000377_4 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000377_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000377_6 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_63 = (pub_r000377_14 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000377_14 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000377_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000377_13 & 2) != 0) {
            stage_v_64 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_65 = (pub_r000377_9 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000377_9 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000377_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000377_11 & 2) != 0) {
            stage_v_66 = (pub_r000377_6 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000377_6 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000377_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_67 = (pub_r000377_7 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000377_7 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000377_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000377_1 & 1) != 0) {
        if ((sec_r000377_11 & 2) != 0) {
            stage_v_68 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000377_11 & 2) != 0) {
            stage_v_69 = (pub_r000377_8 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000377_8 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000377_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000377_0 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_70 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000377_9 & 1) != 0) {
        if ((sec_r000377_15 & 2) != 0) {
            stage_v_71 = (pub_r000377_17 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000377_17 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000377_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_72 = (pub_r000377_18 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000377_18 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000377_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_73 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000377_1 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_74 = (pub_r000377_19 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000377_19 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000377_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000377_3 & 1) != 0) {
        if ((sec_r000377_2 & 2) != 0) {
            stage_v_75 = (pub_r000377_19 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000377_19 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000377_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000377_12 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_76 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000377_2 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_77 = (pub_r000377_9 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000377_9 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000377_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_78 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_79 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_80 = (pub_r000377_13 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000377_13 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000377_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_81 = (pub_r000377_1 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000377_1 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000377_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_82 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000377_10 & 2) != 0) {
            stage_v_83 = (pub_r000377_13 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000377_13 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000377_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_84 = (pub_r000377_0 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000377_0 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000377_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000377_14 & 1) != 0) {
        if ((sec_r000377_15 & 2) != 0) {
            stage_v_85 = (pub_r000377_14 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000377_14 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000377_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_86 = (pub_r000377_9 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000377_9 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000377_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_87 = (pub_r000377_6 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000377_6 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000377_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000377_3 & 2) != 0) {
            stage_v_88 = (pub_r000377_19 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000377_19 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000377_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_89 = (pub_r000377_2 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000377_2 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000377_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000377_7 & 2) != 0) {
            stage_v_90 = (pub_r000377_3 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000377_3 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000377_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000377_14 & 2) != 0) {
            stage_v_91 = (pub_r000377_19 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000377_19 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000377_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000377_6 & 2) != 0) {
            stage_v_92 = (pub_r000377_14 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000377_14 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000377_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000377_0 & 1) != 0) {
        if ((sec_r000377_4 & 2) != 0) {
            stage_v_93 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000377_11 & 2) != 0) {
            stage_v_94 = (pub_r000377_6 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000377_6 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000377_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000377_2 & 2) != 0) {
            stage_v_95 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000377_13 & 1) != 0) {
        if ((sec_r000377_6 & 2) != 0) {
            stage_v_96 = (pub_r000377_14 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000377_14 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000377_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000377_6 & 2) != 0) {
            stage_v_97 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000377_11 & 2) != 0) {
            stage_v_98 = (pub_r000377_10 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000377_10 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000377_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000377_9 & 1) != 0) {
        if ((sec_r000377_4 & 2) != 0) {
            stage_v_99 = (pub_r000377_3 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000377_3 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000377_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000377_1 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_100 = (pub_r000377_10 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000377_10 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000377_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000377_1 & 2) != 0) {
            stage_v_101 = (pub_r000377_11 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000377_11 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000377_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000377_13 & 2) != 0) {
            stage_v_102 = (pub_r000377_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000377_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000377_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000377_0 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_103 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000377_14 & 1) != 0) {
        if ((sec_r000377_6 & 2) != 0) {
            stage_v_104 = (pub_r000377_3 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000377_3 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000377_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000377_5 & 2) != 0) {
            stage_v_105 = (pub_r000377_11 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000377_11 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000377_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_106 = (pub_r000377_8 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000377_8 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000377_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000377_5 & 2) != 0) {
            stage_v_107 = (pub_r000377_3 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000377_3 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000377_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000377_12 & 2) != 0) {
            stage_v_108 = (pub_r000377_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000377_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000377_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000377_13 & 1) != 0) {
        if ((sec_r000377_0 & 2) != 0) {
            stage_v_109 = (pub_r000377_13 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000377_13 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000377_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000377_4 & 2) != 0) {
            stage_v_110 = (pub_r000377_16 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000377_16 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000377_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000377_15 & 2) != 0) {
            stage_v_111 = (pub_r000377_1 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000377_1 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000377_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000377_4 & 2) != 0) {
            stage_v_112 = (pub_r000377_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000377_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000377_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000377_14 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_113 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000377_1 & 1) != 0) {
        if ((sec_r000377_5 & 2) != 0) {
            stage_v_114 = (pub_r000377_6 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000377_6 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000377_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000377_9 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_115 = (pub_r000377_18 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000377_18 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000377_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000377_0 & 1) != 0) {
        if ((sec_r000377_9 & 2) != 0) {
            stage_v_116 = (pub_r000377_19 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000377_19 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000377_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000377_8 & 2) != 0) {
            stage_v_117 = (pub_r000377_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000377_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000377_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000377_13 & 1) != 0) {
        if ((sec_r000377_13 & 2) != 0) {
            stage_v_118 = (pub_r000377_20 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000377_20 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000377_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
