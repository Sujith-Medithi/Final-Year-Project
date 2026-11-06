/*
 * Benchmark Program: R000948
 * Security Family: secret_dependent_loops
 * Generator Seed: 594813
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000948_4813_0 {
    short cutoff;
    unsigned char mode;
    int gain_db;
    int prev_out;
    unsigned char prev_in;
    int damping;
    int buffer[3];
};

struct SensorNode_R000948_4813_1 {
    int calib;
    int offset;
    int gain;
    int buffer[3];
};

union TelemetryField_R000948_4813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000948_4813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000948_4813_0(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int phase_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_92 = local_arr[aux % 3];
    acc = (acc + scale_92 * 2) & 127;
    int pivot_80 = (aux + st.buffer[1]) & 3;
    switch (pivot_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_62 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_62 > 29) {
        acc = (acc + checksum_62 * 2 + 5) & 127;
        aux ^= (checksum_62 & 15);
    } else {
        acc = (acc - checksum_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int phase_57 = local_arr[aux % 3];
    acc = (acc + phase_57 * 2) & 127;
    int coefficient_36 = (aux + st.buffer[1]) & 3;
    switch (coefficient_36) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_24 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_24 > 21) {
        acc = (acc + anchor_24 * 2 + 5) & 127;
        aux ^= (anchor_24 & 15);
    } else {
        acc = (acc - anchor_24 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_2(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int metric_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_97 = local_arr[aux % 3];
    acc = (acc + offset_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_3(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_12 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_12 > 21) {
        acc = (acc + margin_12 * 2 + 5) & 127;
        aux ^= (margin_12 & 15);
    } else {
        acc = (acc - margin_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_16 = local_arr[aux % 3];
    acc = (acc + vector_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_4(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int margin_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_42) & 63;
    acc ^= aux;
    int pivot_94 = (aux + st.buffer[1]) & 3;
    switch (pivot_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int weight_73 = local_arr[aux % 3];
    acc = (acc + weight_73 * 2) & 127;
    int quantum_81 = (aux + st.buffer[1]) & 3;
    switch (quantum_81) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_21 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_21 > 27) {
        acc = (acc + quotient_21 * 2 + 5) & 127;
        aux ^= (quotient_21 & 15);
    } else {
        acc = (acc - quotient_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_6(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int anchor_22 = (aux + st.buffer[1]) & 3;
    switch (anchor_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_90 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_90 > 47) {
        acc = (acc + stride_90 * 2 + 5) & 127;
        aux ^= (stride_90 & 15);
    } else {
        acc = (acc - stride_90 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_89 = local_arr[aux % 3];
    acc = (acc + offset_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_53) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_39 = local_arr[aux % 3];
    acc = (acc + accumulator_39 * 2) & 127;
    int segment_44 = (aux + st.buffer[1]) & 3;
    switch (segment_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int factor_40 = local_arr[aux % 3];
    acc = (acc + factor_40 * 2) & 127;
    int margin_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_44) & 63;
    acc ^= aux;
    int mask_12 = (aux + st.buffer[1]) & 3;
    switch (mask_12) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_76 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_76 > 16) {
        acc = (acc + stride_76 * 2 + 5) & 127;
        aux ^= (stride_76 & 15);
    } else {
        acc = (acc - stride_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_9(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int sample_24 = (aux + st.buffer[1]) & 3;
    switch (sample_24) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_20 = local_arr[aux % 3];
    acc = (acc + checksum_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int sample_48 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_48 > 27) {
        acc = (acc + sample_48 * 2 + 5) & 127;
        aux ^= (sample_48 & 15);
    } else {
        acc = (acc - sample_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_50 = local_arr[aux % 3];
    acc = (acc + vector_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_84 = (aux + st.buffer[1]) & 3;
    switch (vector_84) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_11(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int pivot_23 = (aux + st.buffer[1]) & 3;
    switch (pivot_23) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_67 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_67 > 30) {
        acc = (acc + tracker_67 * 2 + 5) & 127;
        aux ^= (tracker_67 & 15);
    } else {
        acc = (acc - tracker_67 + 11) & 127;
        aux += 3;
    }
    int segment_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_96) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_60 = local_arr[aux % 3];
    acc = (acc + tracker_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int factor_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_70) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_28 = local_arr[aux % 3];
    acc = (acc + bound_28 * 2) & 127;
    int checksum_74 = (aux + st.buffer[1]) & 3;
    switch (checksum_74) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_48 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_48 > 10) {
        acc = (acc + checksum_48 * 2 + 5) & 127;
        aux ^= (checksum_48 & 15);
    } else {
        acc = (acc - checksum_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int damping_90 = (aux + st.buffer[1]) & 3;
    switch (damping_90) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_26 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_26 > 45) {
        acc = (acc + tally_26 * 2 + 5) & 127;
        aux ^= (tally_26 & 15);
    } else {
        acc = (acc - tally_26 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_68 = local_arr[aux % 3];
    acc = (acc + tracker_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int pivot_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_90) & 63;
    acc ^= aux;
    int mask_35 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_35 > 10) {
        acc = (acc + mask_35 * 2 + 5) & 127;
        aux ^= (mask_35 & 15);
    } else {
        acc = (acc - mask_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_25 = local_arr[aux % 3];
    acc = (acc + damping_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_15(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int index_reg_80 = local_arr[aux % 3];
    acc = (acc + index_reg_80 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quantum_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_76) & 63;
    acc ^= aux;
    int delta_55 = (aux + st.buffer[1]) & 3;
    switch (delta_55) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_17(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int offset_18 = local_arr[aux % 3];
    acc = (acc + offset_18 * 2) & 127;
    int factor_69 = (aux + st.buffer[1]) & 3;
    switch (factor_69) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_81 = (aux + st.buffer[1]) & 3;
    switch (weight_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000948_4813_19(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_10 = local_arr[aux % 3];
    acc = (acc + index_reg_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_20(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_20) & 63;
    acc ^= aux;
    int factor_49 = (aux + st.buffer[1]) & 3;
    switch (factor_49) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_95 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_95 > 21) {
        acc = (acc + segment_95 * 2 + 5) & 127;
        aux ^= (segment_95 & 15);
    } else {
        acc = (acc - segment_95 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_61 = local_arr[aux % 3];
    acc = (acc + delta_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_21(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_62 = local_arr[aux % 3];
    acc = (acc + margin_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000948_4813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_48 = local_arr[aux % 3];
    acc = (acc + bound_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000948_4813_23(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000948_4813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int checksum_68 = (aux + st.buffer[1]) & 3;
    switch (checksum_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_77 = local_arr[aux % 3];
    acc = (acc + factor_77 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000948_0;
    int sec_r000948_1;
    int sec_r000948_2;
    int sec_r000948_3;
    int sec_r000948_4;
    int sec_r000948_5;
    int sec_r000948_6;
    int sec_r000948_7;
    int sec_r000948_8;
    int sec_r000948_9;
    int sec_r000948_10;
    int sec_r000948_11;
    int sec_r000948_12;
    int sec_r000948_13;
    int sec_r000948_14;
    int sec_r000948_15;
    int sec_r000948_16;
    int pub_r000948_0;
    int pub_r000948_1;
    int pub_r000948_2;
    int pub_r000948_3;
    int pub_r000948_4;
    int pub_r000948_5;
    int pub_r000948_6;
    int pub_r000948_7;
    int pub_r000948_8;
    int pub_r000948_9;
    int pub_r000948_10;
    int pub_r000948_11;
    int pub_r000948_12;
    int pub_r000948_13;
    int pub_r000948_14;
    int pub_r000948_15;
    int pub_r000948_16;
    int pub_r000948_17;
    int pub_r000948_18;
    int pub_r000948_19;
    int pub_r000948_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000948_0 >= -100 && pub_r000948_0 <= 100);
    __CPROVER_assume(pub_r000948_1 >= -100 && pub_r000948_1 <= 100);
    __CPROVER_assume(pub_r000948_2 >= -100 && pub_r000948_2 <= 100);
    __CPROVER_assume(pub_r000948_3 >= -100 && pub_r000948_3 <= 100);
    __CPROVER_assume(pub_r000948_4 >= -100 && pub_r000948_4 <= 100);
    __CPROVER_assume(pub_r000948_5 >= -100 && pub_r000948_5 <= 100);
    __CPROVER_assume(pub_r000948_6 >= -100 && pub_r000948_6 <= 100);
    __CPROVER_assume(pub_r000948_7 >= -100 && pub_r000948_7 <= 100);
    __CPROVER_assume(pub_r000948_8 >= -100 && pub_r000948_8 <= 100);
    __CPROVER_assume(pub_r000948_9 >= -100 && pub_r000948_9 <= 100);
    __CPROVER_assume(pub_r000948_10 >= -100 && pub_r000948_10 <= 100);
    __CPROVER_assume(pub_r000948_11 >= -100 && pub_r000948_11 <= 100);
    __CPROVER_assume(pub_r000948_12 >= -100 && pub_r000948_12 <= 100);
    __CPROVER_assume(pub_r000948_13 >= -100 && pub_r000948_13 <= 100);
    __CPROVER_assume(pub_r000948_14 >= -100 && pub_r000948_14 <= 100);
    __CPROVER_assume(pub_r000948_15 >= -100 && pub_r000948_15 <= 100);
    __CPROVER_assume(pub_r000948_16 >= -100 && pub_r000948_16 <= 100);
    __CPROVER_assume(pub_r000948_17 >= -100 && pub_r000948_17 <= 100);
    __CPROVER_assume(pub_r000948_18 >= -100 && pub_r000948_18 <= 100);
    __CPROVER_assume(pub_r000948_19 >= -100 && pub_r000948_19 <= 100);
    __CPROVER_assume(pub_r000948_20 >= -100 && pub_r000948_20 <= 100);
    __CPROVER_assume(sec_r000948_0 >= 0 && sec_r000948_0 <= 255);
    __CPROVER_assume(sec_r000948_1 >= 0 && sec_r000948_1 <= 255);
    __CPROVER_assume(sec_r000948_2 >= 0 && sec_r000948_2 <= 255);
    __CPROVER_assume(sec_r000948_3 >= 0 && sec_r000948_3 <= 255);
    __CPROVER_assume(sec_r000948_4 >= 0 && sec_r000948_4 <= 255);
    __CPROVER_assume(sec_r000948_5 >= 0 && sec_r000948_5 <= 255);
    __CPROVER_assume(sec_r000948_6 >= 0 && sec_r000948_6 <= 255);
    __CPROVER_assume(sec_r000948_7 >= 0 && sec_r000948_7 <= 255);
    __CPROVER_assume(sec_r000948_8 >= 0 && sec_r000948_8 <= 255);
    __CPROVER_assume(sec_r000948_9 >= 0 && sec_r000948_9 <= 255);
    __CPROVER_assume(sec_r000948_10 >= 0 && sec_r000948_10 <= 255);
    __CPROVER_assume(sec_r000948_11 >= 0 && sec_r000948_11 <= 255);
    __CPROVER_assume(sec_r000948_12 >= 0 && sec_r000948_12 <= 255);
    __CPROVER_assume(sec_r000948_13 >= 0 && sec_r000948_13 <= 255);
    __CPROVER_assume(sec_r000948_14 >= 0 && sec_r000948_14 <= 255);
    __CPROVER_assume(sec_r000948_15 >= 0 && sec_r000948_15 <= 255);
    __CPROVER_assume(sec_r000948_16 >= 0 && sec_r000948_16 <= 255);

    struct FilterState_R000948_4813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000948_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000948_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000948_0 + 7) & 15;
    struct SensorNode_R000948_4813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000948_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000948_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000948_0 + 9) & 15;

    union TelemetryField_R000948_4813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 38) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 53) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_1.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
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
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 15) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 30) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 24) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 39) {
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 18) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 33) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 31) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 46) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
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
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] ^ 54) & 3;
    switch (stage_v_51) {
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

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_1.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 14) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 29) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_1.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[0] ^ 74) & 3;
    switch (stage_v_71) {
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

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 77) & 15;
    int stage_v_76 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= stage_v_76;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 16) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 31) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_9 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000948_19) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000948_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_8 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000948_14) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000948_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000948_19) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000948_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_14 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000948_12) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_13 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000948_16) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000948_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000948_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000948_16) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000948_9) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000948_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000948_1) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000948_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_3 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000948_15) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000948_6) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000948_17) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000948_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000948_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000948_16) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000948_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000948_20) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000948_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000948_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000948_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_7 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000948_5) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000948_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000948_16) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000948_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000948_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_5 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000948_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000948_13) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000948_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000948_3) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000948_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000948_3) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000948_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000948_17) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000948_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_7 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000948_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_3 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000948_11) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000948_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_9 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000948_5) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_8 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000948_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_10 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000948_12) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000948_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000948_5) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000948_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000948_17) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000948_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000948_11) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_109 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000948_13) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000948_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_111 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000948_19) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000948_17) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_7 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000948_14) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_13 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000948_20) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000948_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000948_15) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_9 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000948_10) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_15 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000948_12) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000948_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_8 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000948_10) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000948_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000948_4) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_13 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000948_16) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000948_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000948_4) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000948_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_9 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000948_3) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_111 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000948_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_124 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000948_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000948_13) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000948_11) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_5 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000948_6) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000948_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_133 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000948_8) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000948_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_11 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000948_3) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000948_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000948_3) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000948_9) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_2 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000948_0) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000948_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_145 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000948_3) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000948_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_16 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000948_17) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000948_0) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000948_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_136 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000948_12) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000948_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000948_19) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000948_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000948_8) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_12 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000948_15) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000948_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_139 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000948_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000948_7) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_143 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000948_5) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000948_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_2 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000948_20) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_132 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000948_4) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_114 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000948_2) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000948_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000948_18) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_134 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000948_6) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000948_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000948_13) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000948_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000948_8) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000948_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_4 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000948_19) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000948_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000948_14) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000948_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_12 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000948_16) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000948_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_166 = (stage_v_166 + step * 4 + pub_r000948_20) & 63;
        } else {
            stage_v_166 = (stage_v_166 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000948_11 & 1) == step) {
            stage_v_167 = (stage_v_167 + step * 4 + pub_r000948_4) & 63;
        } else {
            stage_v_167 = (stage_v_167 + pub_r000948_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
