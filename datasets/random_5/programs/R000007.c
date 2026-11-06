/*
 * Benchmark Program: R000007
 * Security Family: nested_implicit_flow
 * Generator Seed: 500713
 * High Inputs: 17 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000007_713_0 {
    int signature;
    int timestamp;
    int seq;
    unsigned char severity;
    int facility;
    int buffer[3];
};

struct FilterState_R000007_713_1 {
    int prev_in;
    short cutoff;
    unsigned char damping;
    unsigned char gain_db;
    int buffer[3];
};

struct MatrixBlock_R000007_713_2 {
    int scale;
    unsigned char stride;
    int trace;
    int determinant;
    int buffer[3];
};

struct Transaction_R000007_713_3 {
    unsigned char balance;
    int rate;
    int auth_code;
    short fee;
    int buffer[3];
};

union ColorPixel_R000007_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000007_713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000007_713_0(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int bound_56 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_56 > 18) {
        acc = (acc + bound_56 * 2 + 5) & 127;
        aux ^= (bound_56 & 15);
    } else {
        acc = (acc - bound_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_61 = (aux + st.buffer[1]) & 3;
    switch (damping_61) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_81 = local_arr[aux % 3];
    acc = (acc + quotient_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_2(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_62 = (aux + st.buffer[1]) & 3;
    switch (scale_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_3(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int weight_83 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_83 > 22) {
        acc = (acc + weight_83 * 2 + 5) & 127;
        aux ^= (weight_83 & 15);
    } else {
        acc = (acc - weight_83 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_62 = local_arr[aux % 3];
    acc = (acc + offset_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_32 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_32 > 27) {
        acc = (acc + vector_32 * 2 + 5) & 127;
        aux ^= (vector_32 & 15);
    } else {
        acc = (acc - vector_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_74 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_74 > 22) {
        acc = (acc + tracker_74 * 2 + 5) & 127;
        aux ^= (tracker_74 & 15);
    } else {
        acc = (acc - tracker_74 + 11) & 127;
        aux += 3;
    }
    int vector_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_36 = local_arr[aux % 3];
    acc = (acc + window_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_7(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int parity_55 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_55 > 42) {
        acc = (acc + parity_55 * 2 + 5) & 127;
        aux ^= (parity_55 & 15);
    } else {
        acc = (acc - parity_55 + 11) & 127;
        aux += 3;
    }
    int tracker_55 = (aux + st.buffer[1]) & 3;
    switch (tracker_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_8(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int checksum_46 = local_arr[aux % 3];
    acc = (acc + checksum_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_9(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int scale_98 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_98 > 29) {
        acc = (acc + scale_98 * 2 + 5) & 127;
        aux ^= (scale_98 & 15);
    } else {
        acc = (acc - scale_98 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_80 = local_arr[aux % 3];
    acc = (acc + window_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int accumulator_86 = local_arr[aux % 3];
    acc = (acc + accumulator_86 * 2) & 127;
    int mask_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_11(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int segment_45 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_45 > 39) {
        acc = (acc + segment_45 * 2 + 5) & 127;
        aux ^= (segment_45 & 15);
    } else {
        acc = (acc - segment_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_70) & 63;
    acc ^= aux;
    int checksum_20 = (aux + st.buffer[1]) & 3;
    switch (checksum_20) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_78 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_78 > 16) {
        acc = (acc + pivot_78 * 2 + 5) & 127;
        aux ^= (pivot_78 & 15);
    } else {
        acc = (acc - pivot_78 + 11) & 127;
        aux += 3;
    }
    int threshold_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_48) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_64 = local_arr[aux % 3];
    acc = (acc + accumulator_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000007_713_13(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000007_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int anchor_39 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_39 > 50) {
        acc = (acc + anchor_39 * 2 + 5) & 127;
        aux ^= (anchor_39 & 15);
    } else {
        acc = (acc - anchor_39 + 11) & 127;
        aux += 3;
    }
    int coefficient_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_39 = (aux + st.buffer[1]) & 3;
    switch (vector_39) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_34 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_34 > 38) {
        acc = (acc + scale_34 * 2 + 5) & 127;
        aux ^= (scale_34 & 15);
    } else {
        acc = (acc - scale_34 + 11) & 127;
        aux += 3;
    }
    int metric_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_15(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_12 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_12 > 47) {
        acc = (acc + damping_12 * 2 + 5) & 127;
        aux ^= (damping_12 & 15);
    } else {
        acc = (acc - damping_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_92 = local_arr[aux % 3];
    acc = (acc + scale_92 * 2) & 127;
    int residue_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int pivot_59 = (aux + st.buffer[1]) & 3;
    switch (pivot_59) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_63 = local_arr[aux % 3];
    acc = (acc + index_reg_63 * 2) & 127;
    int index_reg_41 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_41 > 26) {
        acc = (acc + index_reg_41 * 2 + 5) & 127;
        aux ^= (index_reg_41 & 15);
    } else {
        acc = (acc - index_reg_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_17(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000007_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_12 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_12 > 49) {
        acc = (acc + tracker_12 * 2 + 5) & 127;
        aux ^= (tracker_12 & 15);
    } else {
        acc = (acc - tracker_12 + 11) & 127;
        aux += 3;
    }
    int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_99) & 63;
    acc ^= aux;
    int vector_79 = (aux + st.buffer[1]) & 3;
    switch (vector_79) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_18(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_54 = (st.buffer[0] * 3 + aux) & 63;
    if (window_54 > 41) {
        acc = (acc + window_54 * 2 + 5) & 127;
        aux ^= (window_54 & 15);
    } else {
        acc = (acc - window_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_99 = (aux + st.buffer[1]) & 3;
    switch (bound_99) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_87 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_87 > 10) {
        acc = (acc + metric_87 * 2 + 5) & 127;
        aux ^= (metric_87 & 15);
    } else {
        acc = (acc - metric_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tracker_96 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_96 > 27) {
        acc = (acc + tracker_96 * 2 + 5) & 127;
        aux ^= (tracker_96 & 15);
    } else {
        acc = (acc - tracker_96 + 11) & 127;
        aux += 3;
    }
    int bound_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000007_713_21(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_82 = (st.buffer[0] * 3 + aux) & 63;
    if (window_82 > 39) {
        acc = (acc + window_82 * 2 + 5) & 127;
        aux ^= (window_82 & 15);
    } else {
        acc = (acc - window_82 + 11) & 127;
        aux += 3;
    }
    int parity_98 = (aux + st.buffer[1]) & 3;
    switch (parity_98) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000007_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int window_96 = local_arr[aux % 3];
    acc = (acc + window_96 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_33) & 63;
    acc ^= aux;
    int damping_72 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_72 > 42) {
        acc = (acc + damping_72 * 2 + 5) & 127;
        aux ^= (damping_72 & 15);
    } else {
        acc = (acc - damping_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000007_713_23(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000007_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int bound_49 = (aux + st.buffer[1]) & 3;
    switch (bound_49) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_46 = local_arr[aux % 3];
    acc = (acc + bound_46 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000007_0;
    int sec_r000007_1;
    int sec_r000007_2;
    int sec_r000007_3;
    int sec_r000007_4;
    int sec_r000007_5;
    int sec_r000007_6;
    int sec_r000007_7;
    int sec_r000007_8;
    int sec_r000007_9;
    int sec_r000007_10;
    int sec_r000007_11;
    int sec_r000007_12;
    int sec_r000007_13;
    int sec_r000007_14;
    int sec_r000007_15;
    int sec_r000007_16;
    int pub_r000007_0;
    int pub_r000007_1;
    int pub_r000007_2;
    int pub_r000007_3;
    int pub_r000007_4;
    int pub_r000007_5;
    int pub_r000007_6;
    int pub_r000007_7;
    int pub_r000007_8;
    int pub_r000007_9;
    int pub_r000007_10;
    int pub_r000007_11;
    int pub_r000007_12;
    int pub_r000007_13;
    int pub_r000007_14;
    int pub_r000007_15;
    int pub_r000007_16;
    int pub_r000007_17;
    int pub_r000007_18;
    int pub_r000007_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000007_0 >= -100 && pub_r000007_0 <= 100);
    __CPROVER_assume(pub_r000007_1 >= -100 && pub_r000007_1 <= 100);
    __CPROVER_assume(pub_r000007_2 >= -100 && pub_r000007_2 <= 100);
    __CPROVER_assume(pub_r000007_3 >= -100 && pub_r000007_3 <= 100);
    __CPROVER_assume(pub_r000007_4 >= -100 && pub_r000007_4 <= 100);
    __CPROVER_assume(pub_r000007_5 >= -100 && pub_r000007_5 <= 100);
    __CPROVER_assume(pub_r000007_6 >= -100 && pub_r000007_6 <= 100);
    __CPROVER_assume(pub_r000007_7 >= -100 && pub_r000007_7 <= 100);
    __CPROVER_assume(pub_r000007_8 >= -100 && pub_r000007_8 <= 100);
    __CPROVER_assume(pub_r000007_9 >= -100 && pub_r000007_9 <= 100);
    __CPROVER_assume(pub_r000007_10 >= -100 && pub_r000007_10 <= 100);
    __CPROVER_assume(pub_r000007_11 >= -100 && pub_r000007_11 <= 100);
    __CPROVER_assume(pub_r000007_12 >= -100 && pub_r000007_12 <= 100);
    __CPROVER_assume(pub_r000007_13 >= -100 && pub_r000007_13 <= 100);
    __CPROVER_assume(pub_r000007_14 >= -100 && pub_r000007_14 <= 100);
    __CPROVER_assume(pub_r000007_15 >= -100 && pub_r000007_15 <= 100);
    __CPROVER_assume(pub_r000007_16 >= -100 && pub_r000007_16 <= 100);
    __CPROVER_assume(pub_r000007_17 >= -100 && pub_r000007_17 <= 100);
    __CPROVER_assume(pub_r000007_18 >= -100 && pub_r000007_18 <= 100);
    __CPROVER_assume(pub_r000007_19 >= -100 && pub_r000007_19 <= 100);
    __CPROVER_assume(sec_r000007_0 >= 0 && sec_r000007_0 <= 255);
    __CPROVER_assume(sec_r000007_1 >= 0 && sec_r000007_1 <= 255);
    __CPROVER_assume(sec_r000007_2 >= 0 && sec_r000007_2 <= 255);
    __CPROVER_assume(sec_r000007_3 >= 0 && sec_r000007_3 <= 255);
    __CPROVER_assume(sec_r000007_4 >= 0 && sec_r000007_4 <= 255);
    __CPROVER_assume(sec_r000007_5 >= 0 && sec_r000007_5 <= 255);
    __CPROVER_assume(sec_r000007_6 >= 0 && sec_r000007_6 <= 255);
    __CPROVER_assume(sec_r000007_7 >= 0 && sec_r000007_7 <= 255);
    __CPROVER_assume(sec_r000007_8 >= 0 && sec_r000007_8 <= 255);
    __CPROVER_assume(sec_r000007_9 >= 0 && sec_r000007_9 <= 255);
    __CPROVER_assume(sec_r000007_10 >= 0 && sec_r000007_10 <= 255);
    __CPROVER_assume(sec_r000007_11 >= 0 && sec_r000007_11 <= 255);
    __CPROVER_assume(sec_r000007_12 >= 0 && sec_r000007_12 <= 255);
    __CPROVER_assume(sec_r000007_13 >= 0 && sec_r000007_13 <= 255);
    __CPROVER_assume(sec_r000007_14 >= 0 && sec_r000007_14 <= 255);
    __CPROVER_assume(sec_r000007_15 >= 0 && sec_r000007_15 <= 255);
    __CPROVER_assume(sec_r000007_16 >= 0 && sec_r000007_16 <= 255);

    struct EventLog_R000007_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000007_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000007_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000007_0 + 7) & 15;
    struct FilterState_R000007_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000007_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000007_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000007_0 + 9) & 15;
    struct MatrixBlock_R000007_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000007_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000007_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000007_0 + 11) & 15;
    struct Transaction_R000007_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000007_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000007_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000007_0 + 13) & 15;

    union ColorPixel_R000007_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 12) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 27) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 31) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 46) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

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
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 16) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 31) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 34) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 49) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_3.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 16) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 31) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 32) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 47) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 22) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 37) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
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
    int stage_v_73 = 0;
    if ((sec_r000007_6 & 1) != 0) {
        if ((sec_r000007_11 & 2) != 0) {
            stage_v_73 = (pub_r000007_11 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000007_11 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000007_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000007_11 & 1) != 0) {
        if ((sec_r000007_16 & 2) != 0) {
            stage_v_74 = (pub_r000007_2 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000007_2 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000007_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_75 = (pub_r000007_14 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000007_14 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000007_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000007_2 & 2) != 0) {
            stage_v_76 = (pub_r000007_17 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000007_17 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000007_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000007_15 & 2) != 0) {
            stage_v_77 = (pub_r000007_15 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000007_15 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000007_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000007_3 & 2) != 0) {
            stage_v_78 = (pub_r000007_15 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000007_15 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000007_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_79 = (pub_r000007_6 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000007_6 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000007_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_80 = (pub_r000007_13 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000007_13 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000007_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_81 = (pub_r000007_15 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000007_15 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000007_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000007_2 & 2) != 0) {
            stage_v_82 = (pub_r000007_11 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000007_11 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000007_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000007_0 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_83 = (pub_r000007_13 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000007_13 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000007_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000007_11 & 2) != 0) {
            stage_v_84 = (pub_r000007_13 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000007_13 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000007_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_85 = (pub_r000007_19 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000007_19 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000007_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000007_12 & 1) != 0) {
        if ((sec_r000007_10 & 2) != 0) {
            stage_v_86 = (pub_r000007_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000007_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000007_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000007_13 & 2) != 0) {
            stage_v_87 = (pub_r000007_2 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000007_2 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000007_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_88 = (pub_r000007_9 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000007_9 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000007_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_89 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000007_0 & 2) != 0) {
            stage_v_90 = (pub_r000007_16 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000007_16 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000007_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000007_2 & 2) != 0) {
            stage_v_91 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_92 = (pub_r000007_10 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000007_10 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000007_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_93 = (pub_r000007_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000007_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000007_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000007_8 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_94 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000007_14 & 1) != 0) {
        if ((sec_r000007_4 & 2) != 0) {
            stage_v_95 = (pub_r000007_16 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000007_16 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000007_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000007_14 & 1) != 0) {
        if ((sec_r000007_11 & 2) != 0) {
            stage_v_96 = (pub_r000007_12 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000007_12 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000007_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000007_14 & 1) != 0) {
        if ((sec_r000007_2 & 2) != 0) {
            stage_v_97 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000007_4 & 2) != 0) {
            stage_v_98 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000007_3 & 2) != 0) {
            stage_v_99 = (pub_r000007_5 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000007_5 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000007_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000007_14 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_100 = (pub_r000007_6 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000007_6 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000007_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_101 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000007_6 & 2) != 0) {
            stage_v_102 = (pub_r000007_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000007_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000007_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000007_16 & 2) != 0) {
            stage_v_103 = (pub_r000007_3 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000007_3 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000007_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000007_8 & 2) != 0) {
            stage_v_104 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_105 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000007_1 & 1) != 0) {
        if ((sec_r000007_15 & 2) != 0) {
            stage_v_106 = (pub_r000007_19 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000007_19 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000007_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000007_13 & 2) != 0) {
            stage_v_107 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_108 = (pub_r000007_14 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000007_14 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000007_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000007_8 & 2) != 0) {
            stage_v_109 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000007_12 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_110 = (pub_r000007_19 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000007_19 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000007_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_111 = (pub_r000007_18 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000007_18 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000007_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000007_0 & 2) != 0) {
            stage_v_112 = (pub_r000007_2 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000007_2 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000007_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_113 = (pub_r000007_8 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000007_8 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000007_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_114 = (pub_r000007_11 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000007_11 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000007_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000007_3 & 2) != 0) {
            stage_v_115 = (pub_r000007_19 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000007_19 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000007_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000007_13 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_116 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_117 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000007_10 & 1) != 0) {
        if ((sec_r000007_4 & 2) != 0) {
            stage_v_118 = (pub_r000007_2 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000007_2 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000007_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000007_8 & 1) != 0) {
        if ((sec_r000007_11 & 2) != 0) {
            stage_v_119 = (pub_r000007_13 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000007_13 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000007_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_120 = (pub_r000007_16 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000007_16 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000007_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_121 = (pub_r000007_6 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000007_6 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000007_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000007_12 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_122 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000007_15 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_123 = (pub_r000007_10 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000007_10 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000007_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000007_0 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_124 = (pub_r000007_12 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000007_12 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000007_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000007_10 & 2) != 0) {
            stage_v_125 = (pub_r000007_14 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000007_14 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000007_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000007_2 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_126 = (pub_r000007_0 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000007_0 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000007_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000007_3 & 2) != 0) {
            stage_v_127 = (pub_r000007_11 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000007_11 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000007_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_128 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000007_6 & 2) != 0) {
            stage_v_129 = (pub_r000007_9 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000007_9 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000007_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000007_13 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_130 = (pub_r000007_17 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000007_17 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000007_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000007_15 & 2) != 0) {
            stage_v_131 = (pub_r000007_10 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000007_10 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000007_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_132 = (pub_r000007_5 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000007_5 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000007_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000007_15 & 2) != 0) {
            stage_v_133 = (pub_r000007_13 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000007_13 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000007_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000007_10 & 1) != 0) {
        if ((sec_r000007_16 & 2) != 0) {
            stage_v_134 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000007_3 & 1) != 0) {
        if ((sec_r000007_16 & 2) != 0) {
            stage_v_135 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000007_10 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_136 = (pub_r000007_17 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000007_17 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000007_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_137 = (pub_r000007_12 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000007_12 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000007_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_115 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_138 = (pub_r000007_2 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000007_2 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000007_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_139 = (pub_r000007_11 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000007_11 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000007_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000007_10 & 1) != 0) {
        if ((sec_r000007_11 & 2) != 0) {
            stage_v_140 = (pub_r000007_17 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000007_17 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000007_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000007_2 & 2) != 0) {
            stage_v_141 = (pub_r000007_3 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000007_3 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000007_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000007_5 & 1) != 0) {
        if ((sec_r000007_3 & 2) != 0) {
            stage_v_142 = (pub_r000007_10 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000007_10 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000007_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_143 = (pub_r000007_10 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000007_10 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000007_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000007_12 & 1) != 0) {
        if ((sec_r000007_6 & 2) != 0) {
            stage_v_144 = (pub_r000007_19 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000007_19 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000007_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_145 = (pub_r000007_3 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000007_3 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000007_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000007_2 & 1) != 0) {
        if ((sec_r000007_14 & 2) != 0) {
            stage_v_146 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_147 = (pub_r000007_2 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000007_2 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000007_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000007_8 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_148 = (pub_r000007_5 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000007_5 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000007_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_149 = (pub_r000007_12 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000007_12 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000007_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000007_3 & 1) != 0) {
        if ((sec_r000007_6 & 2) != 0) {
            stage_v_150 = (pub_r000007_16 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000007_16 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000007_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000007_12 & 1) != 0) {
        if ((sec_r000007_0 & 2) != 0) {
            stage_v_151 = (pub_r000007_17 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000007_17 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000007_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000007_2 & 1) != 0) {
        if ((sec_r000007_9 & 2) != 0) {
            stage_v_152 = (pub_r000007_1 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000007_1 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000007_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000007_0 & 2) != 0) {
            stage_v_153 = (pub_r000007_13 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000007_13 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000007_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((sec_r000007_3 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_154 = (pub_r000007_8 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000007_8 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000007_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000007_2 & 1) != 0) {
        if ((sec_r000007_15 & 2) != 0) {
            stage_v_155 = (pub_r000007_14 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000007_14 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000007_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000007_8 & 2) != 0) {
            stage_v_156 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000007_8 & 2) != 0) {
            stage_v_157 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_158 = (pub_r000007_4 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000007_4 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000007_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r000007_6 & 2) != 0) {
            stage_v_159 = (pub_r000007_5 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000007_5 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000007_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_160 = (pub_r000007_17 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000007_17 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000007_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000007_12 & 2) != 0) {
            stage_v_161 = (pub_r000007_18 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000007_18 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000007_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000007_5 & 2) != 0) {
            stage_v_162 = (pub_r000007_7 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000007_7 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000007_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000007_3 & 2) != 0) {
            stage_v_163 = (pub_r000007_1 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000007_1 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000007_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000007_13 & 2) != 0) {
            stage_v_164 = (pub_r000007_12 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000007_12 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000007_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000007_1 & 2) != 0) {
            stage_v_165 = (pub_r000007_10 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000007_10 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000007_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000007_6 & 2) != 0) {
            stage_v_166 = (pub_r000007_3 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000007_3 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000007_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((sec_r000007_0 & 1) != 0) {
        if ((sec_r000007_7 & 2) != 0) {
            stage_v_167 = (pub_r000007_15 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000007_15 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000007_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
