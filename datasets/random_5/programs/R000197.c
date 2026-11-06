/*
 * Benchmark Program: R000197
 * Security Family: nested_implicit_flow
 * Generator Seed: 519713
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000197_9713_0 {
    unsigned char reading;
    unsigned char calib;
    int status;
    int buffer[3];
};

struct Transaction_R000197_9713_1 {
    int account_id;
    short auth_code;
    short balance;
    int fee;
    short rate;
    int status;
    int buffer[3];
};

union ColorPixel_R000197_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R000197_9713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000197_9713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int weight_63 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_63 > 26) {
        acc = (acc + weight_63 * 2 + 5) & 127;
        aux ^= (weight_63 & 15);
    } else {
        acc = (acc - weight_63 + 11) & 127;
        aux += 3;
    }
    int pivot_88 = (aux + st.buffer[1]) & 3;
    switch (pivot_88) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000197_9713_1(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_78 = local_arr[aux % 3];
    acc = (acc + sample_78 * 2) & 127;
    int index_reg_98 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_98 > 32) {
        acc = (acc + index_reg_98 * 2 + 5) & 127;
        aux ^= (index_reg_98 & 15);
    } else {
        acc = (acc - index_reg_98 + 11) & 127;
        aux += 3;
    }
    int segment_22 = (aux + st.buffer[1]) & 3;
    switch (segment_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_2(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_20 = (aux + st.buffer[1]) & 3;
    switch (accumulator_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_3(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_87 = local_arr[aux % 3];
    acc = (acc + quotient_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000197_9713_4(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int damping_10 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_10 > 45) {
        acc = (acc + damping_10 * 2 + 5) & 127;
        aux ^= (damping_10 & 15);
    } else {
        acc = (acc - damping_10 + 11) & 127;
        aux += 3;
    }
    int anchor_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000197_9713_5(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_73 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_73 > 17) {
        acc = (acc + threshold_73 * 2 + 5) & 127;
        aux ^= (threshold_73 & 15);
    } else {
        acc = (acc - threshold_73 + 11) & 127;
        aux += 3;
    }
    int vector_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_15) & 63;
    acc ^= aux;
    int factor_34 = (aux + st.buffer[1]) & 3;
    switch (factor_34) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000197_9713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_85 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_85 > 17) {
        acc = (acc + tracker_85 * 2 + 5) & 127;
        aux ^= (tracker_85 & 15);
    } else {
        acc = (acc - tracker_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_78 = local_arr[aux % 3];
    acc = (acc + factor_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000197_9713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int damping_66 = local_arr[aux % 3];
    acc = (acc + damping_66 * 2) & 127;
    int delta_30 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_30 > 41) {
        acc = (acc + delta_30 * 2 + 5) & 127;
        aux ^= (delta_30 & 15);
    } else {
        acc = (acc - delta_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int threshold_71 = local_arr[aux % 3];
    acc = (acc + threshold_71 * 2) & 127;
    int checksum_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_50) & 63;
    acc ^= aux;
    int tracker_29 = (aux + st.buffer[1]) & 3;
    switch (tracker_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int accumulator_43 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_43 > 41) {
        acc = (acc + accumulator_43 * 2 + 5) & 127;
        aux ^= (accumulator_43 & 15);
    } else {
        acc = (acc - accumulator_43 + 11) & 127;
        aux += 3;
    }
    int offset_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000197_9713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_58) & 63;
    acc ^= aux;
    int vector_62 = (aux + st.buffer[1]) & 3;
    switch (vector_62) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_26 = local_arr[aux % 3];
    acc = (acc + damping_26 * 2) & 127;
    int sample_32 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_32 > 17) {
        acc = (acc + sample_32 * 2 + 5) & 127;
        aux ^= (sample_32 & 15);
    } else {
        acc = (acc - sample_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_85 = (aux + st.buffer[1]) & 3;
    switch (segment_85) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int quotient_26 = local_arr[aux % 3];
    acc = (acc + quotient_26 * 2) & 127;
    int parity_96 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_96 > 21) {
        acc = (acc + parity_96 * 2 + 5) & 127;
        aux ^= (parity_96 & 15);
    } else {
        acc = (acc - parity_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000197_9713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int weight_67 = (aux + st.buffer[1]) & 3;
    switch (weight_67) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_98 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_98 > 50) {
        acc = (acc + parity_98 * 2 + 5) & 127;
        aux ^= (parity_98 & 15);
    } else {
        acc = (acc - parity_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int margin_88 = (aux + st.buffer[1]) & 3;
    switch (margin_88) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000197_9713_15(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_39 = local_arr[aux % 3];
    acc = (acc + checksum_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000197_9713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_35 = (aux + st.buffer[1]) & 3;
    switch (coefficient_35) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_48 = local_arr[aux % 3];
    acc = (acc + anchor_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000197_9713_17(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000197_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int sample_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_39) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_31 = local_arr[aux % 3];
    acc = (acc + threshold_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000197_9713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_41 = local_arr[aux % 3];
    acc = (acc + sample_41 * 2) & 127;
    int bound_85 = (aux + st.buffer[1]) & 3;
    switch (bound_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int factor_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_86 = local_arr[aux % 3];
    acc = (acc + parity_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000197_9713_20(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int anchor_16 = (aux + st.buffer[1]) & 3;
    switch (anchor_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_12 = (st.buffer[0] * 3 + aux) & 63;
    if (window_12 > 33) {
        acc = (acc + window_12 * 2 + 5) & 127;
        aux ^= (window_12 & 15);
    } else {
        acc = (acc - window_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_36 = (aux + st.buffer[1]) & 3;
    switch (tally_36) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_66 = local_arr[aux % 3];
    acc = (acc + weight_66 * 2) & 127;
    int metric_81 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_81 > 44) {
        acc = (acc + metric_81 * 2 + 5) & 127;
        aux ^= (metric_81 & 15);
    } else {
        acc = (acc - metric_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000197_9713_22(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000197_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int vector_36 = (aux + st.buffer[1]) & 3;
    switch (vector_36) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_52 = local_arr[aux % 3];
    acc = (acc + scale_52 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000197_0;
    int sec_r000197_1;
    int sec_r000197_2;
    int sec_r000197_3;
    int sec_r000197_4;
    int sec_r000197_5;
    int sec_r000197_6;
    int sec_r000197_7;
    int sec_r000197_8;
    int sec_r000197_9;
    int sec_r000197_10;
    int sec_r000197_11;
    int sec_r000197_12;
    int sec_r000197_13;
    int sec_r000197_14;
    int sec_r000197_15;
    int pub_r000197_0;
    int pub_r000197_1;
    int pub_r000197_2;
    int pub_r000197_3;
    int pub_r000197_4;
    int pub_r000197_5;
    int pub_r000197_6;
    int pub_r000197_7;
    int pub_r000197_8;
    int pub_r000197_9;
    int pub_r000197_10;
    int pub_r000197_11;
    int pub_r000197_12;
    int pub_r000197_13;
    int pub_r000197_14;
    int pub_r000197_15;
    int pub_r000197_16;
    int pub_r000197_17;
    int pub_r000197_18;
    int pub_r000197_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000197_0 >= -100 && pub_r000197_0 <= 100);
    __CPROVER_assume(pub_r000197_1 >= -100 && pub_r000197_1 <= 100);
    __CPROVER_assume(pub_r000197_2 >= -100 && pub_r000197_2 <= 100);
    __CPROVER_assume(pub_r000197_3 >= -100 && pub_r000197_3 <= 100);
    __CPROVER_assume(pub_r000197_4 >= -100 && pub_r000197_4 <= 100);
    __CPROVER_assume(pub_r000197_5 >= -100 && pub_r000197_5 <= 100);
    __CPROVER_assume(pub_r000197_6 >= -100 && pub_r000197_6 <= 100);
    __CPROVER_assume(pub_r000197_7 >= -100 && pub_r000197_7 <= 100);
    __CPROVER_assume(pub_r000197_8 >= -100 && pub_r000197_8 <= 100);
    __CPROVER_assume(pub_r000197_9 >= -100 && pub_r000197_9 <= 100);
    __CPROVER_assume(pub_r000197_10 >= -100 && pub_r000197_10 <= 100);
    __CPROVER_assume(pub_r000197_11 >= -100 && pub_r000197_11 <= 100);
    __CPROVER_assume(pub_r000197_12 >= -100 && pub_r000197_12 <= 100);
    __CPROVER_assume(pub_r000197_13 >= -100 && pub_r000197_13 <= 100);
    __CPROVER_assume(pub_r000197_14 >= -100 && pub_r000197_14 <= 100);
    __CPROVER_assume(pub_r000197_15 >= -100 && pub_r000197_15 <= 100);
    __CPROVER_assume(pub_r000197_16 >= -100 && pub_r000197_16 <= 100);
    __CPROVER_assume(pub_r000197_17 >= -100 && pub_r000197_17 <= 100);
    __CPROVER_assume(pub_r000197_18 >= -100 && pub_r000197_18 <= 100);
    __CPROVER_assume(pub_r000197_19 >= -100 && pub_r000197_19 <= 100);
    __CPROVER_assume(sec_r000197_0 >= 0 && sec_r000197_0 <= 255);
    __CPROVER_assume(sec_r000197_1 >= 0 && sec_r000197_1 <= 255);
    __CPROVER_assume(sec_r000197_2 >= 0 && sec_r000197_2 <= 255);
    __CPROVER_assume(sec_r000197_3 >= 0 && sec_r000197_3 <= 255);
    __CPROVER_assume(sec_r000197_4 >= 0 && sec_r000197_4 <= 255);
    __CPROVER_assume(sec_r000197_5 >= 0 && sec_r000197_5 <= 255);
    __CPROVER_assume(sec_r000197_6 >= 0 && sec_r000197_6 <= 255);
    __CPROVER_assume(sec_r000197_7 >= 0 && sec_r000197_7 <= 255);
    __CPROVER_assume(sec_r000197_8 >= 0 && sec_r000197_8 <= 255);
    __CPROVER_assume(sec_r000197_9 >= 0 && sec_r000197_9 <= 255);
    __CPROVER_assume(sec_r000197_10 >= 0 && sec_r000197_10 <= 255);
    __CPROVER_assume(sec_r000197_11 >= 0 && sec_r000197_11 <= 255);
    __CPROVER_assume(sec_r000197_12 >= 0 && sec_r000197_12 <= 255);
    __CPROVER_assume(sec_r000197_13 >= 0 && sec_r000197_13 <= 255);
    __CPROVER_assume(sec_r000197_14 >= 0 && sec_r000197_14 <= 255);
    __CPROVER_assume(sec_r000197_15 >= 0 && sec_r000197_15 <= 255);

    struct SensorNode_R000197_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000197_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000197_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000197_0 + 7) & 15;
    struct Transaction_R000197_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000197_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000197_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000197_0 + 9) & 15;

    union ColorPixel_R000197_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
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
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 17) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 32) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((sec_r000197_15 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_15 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_15 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_15 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_16 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_16 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_16 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_17 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_17 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_17 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_12 & 2) != 0) {
            stage_v_18 = (pub_r000197_14 + 31) & 127;
        } else {
            stage_v_18 = (pub_r000197_14 + 13) & 127;
        }
    } else {
        stage_v_18 = (pub_r000197_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_19 = (pub_r000197_12 + 31) & 127;
        } else {
            stage_v_19 = (pub_r000197_12 + 13) & 127;
        }
    } else {
        stage_v_19 = (pub_r000197_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_20 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_20 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_20 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000197_0 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_21 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_22 = (pub_r000197_6 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000197_6 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000197_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_23 = (pub_r000197_13 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000197_13 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000197_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_24 = (pub_r000197_1 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000197_1 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000197_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((sec_r000197_6 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_25 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_26 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000197_8 & 2) != 0) {
            stage_v_27 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_28 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_29 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000197_0 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_30 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_31 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((sec_r000197_5 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_32 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_33 = (pub_r000197_15 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000197_15 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000197_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000197_2 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_34 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000197_6 & 2) != 0) {
            stage_v_35 = (pub_r000197_13 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000197_13 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000197_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_36 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_37 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_38 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_39 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_40 = (pub_r000197_12 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000197_12 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000197_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000197_9 & 1) != 0) {
        if ((sec_r000197_8 & 2) != 0) {
            stage_v_41 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000197_0 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_42 = (pub_r000197_15 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000197_15 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000197_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((sec_r000197_14 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_43 = (pub_r000197_11 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000197_11 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000197_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000197_12 & 2) != 0) {
            stage_v_44 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_45 = (pub_r000197_4 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000197_4 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000197_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_46 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000197_8 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_47 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000197_14 & 2) != 0) {
            stage_v_48 = (pub_r000197_12 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000197_12 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000197_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000197_8 & 2) != 0) {
            stage_v_49 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000197_4 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_50 = (pub_r000197_1 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000197_1 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000197_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000197_11 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_51 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000197_13 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_52 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_53 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_54 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_55 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000197_6 & 2) != 0) {
            stage_v_56 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_57 = (pub_r000197_14 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000197_14 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000197_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_58 = (pub_r000197_15 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000197_15 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000197_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_59 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000197_1 & 1) != 0) {
        if ((sec_r000197_8 & 2) != 0) {
            stage_v_60 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000197_0 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_61 = (pub_r000197_9 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000197_9 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000197_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_62 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_63 = (pub_r000197_7 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000197_7 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000197_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000197_8 & 2) != 0) {
            stage_v_64 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_65 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000197_3 & 2) != 0) {
            stage_v_66 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000197_12 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_67 = (pub_r000197_13 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000197_13 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000197_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000197_6 & 2) != 0) {
            stage_v_68 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000197_3 & 2) != 0) {
            stage_v_69 = (pub_r000197_9 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000197_9 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000197_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000197_1 & 1) != 0) {
        if ((sec_r000197_3 & 2) != 0) {
            stage_v_70 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_71 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_72 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_73 = (pub_r000197_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000197_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000197_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_74 = (pub_r000197_14 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000197_14 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000197_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000197_13 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_75 = (pub_r000197_4 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000197_4 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000197_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_76 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000197_15 & 1) != 0) {
        if ((sec_r000197_3 & 2) != 0) {
            stage_v_77 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_78 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000197_12 & 2) != 0) {
            stage_v_79 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000197_0 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_80 = (pub_r000197_2 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000197_2 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000197_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000197_12 & 2) != 0) {
            stage_v_81 = (pub_r000197_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000197_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000197_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_82 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_83 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_84 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_85 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_86 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_87 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_88 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_89 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_90 = (pub_r000197_2 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000197_2 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000197_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_91 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_92 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000197_2 & 1) != 0) {
        if ((sec_r000197_6 & 2) != 0) {
            stage_v_93 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_94 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_95 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000197_15 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_96 = (pub_r000197_18 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000197_18 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000197_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_97 = (pub_r000197_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000197_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000197_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000197_10 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_98 = (pub_r000197_18 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000197_18 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000197_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_99 = (pub_r000197_11 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000197_11 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000197_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000197_7 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_100 = (pub_r000197_18 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000197_18 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000197_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_101 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_102 = (pub_r000197_18 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000197_18 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000197_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_103 = (pub_r000197_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000197_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000197_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000197_10 & 1) != 0) {
        if ((sec_r000197_3 & 2) != 0) {
            stage_v_104 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_105 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_106 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_107 = (pub_r000197_7 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000197_7 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000197_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000197_7 & 1) != 0) {
        if ((sec_r000197_6 & 2) != 0) {
            stage_v_108 = (pub_r000197_2 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000197_2 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000197_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_109 = (pub_r000197_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000197_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000197_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_110 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000197_15 & 1) != 0) {
        if ((sec_r000197_1 & 2) != 0) {
            stage_v_111 = (pub_r000197_2 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000197_2 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000197_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000197_14 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_112 = (pub_r000197_6 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000197_6 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000197_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000197_13 & 2) != 0) {
            stage_v_113 = (pub_r000197_9 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000197_9 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000197_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_114 = (pub_r000197_12 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000197_12 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000197_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_115 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000197_0 & 2) != 0) {
            stage_v_116 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000197_2 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_117 = (pub_r000197_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000197_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000197_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_118 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000197_12 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_119 = (pub_r000197_13 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000197_13 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000197_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_120 = (pub_r000197_0 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000197_0 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000197_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000197_6 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_121 = (pub_r000197_18 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000197_18 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000197_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000197_12 & 2) != 0) {
            stage_v_122 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000197_4 & 2) != 0) {
            stage_v_123 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000197_14 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_124 = (pub_r000197_19 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000197_19 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000197_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000197_1 & 1) != 0) {
        if ((sec_r000197_9 & 2) != 0) {
            stage_v_125 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000197_9 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_126 = (pub_r000197_12 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000197_12 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000197_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000197_14 & 2) != 0) {
            stage_v_127 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000197_4 & 1) != 0) {
        if ((sec_r000197_3 & 2) != 0) {
            stage_v_128 = (pub_r000197_9 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000197_9 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000197_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000197_8 & 2) != 0) {
            stage_v_129 = (pub_r000197_7 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000197_7 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000197_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000197_7 & 2) != 0) {
            stage_v_130 = (pub_r000197_13 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000197_13 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000197_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000197_5 & 2) != 0) {
            stage_v_131 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_132 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000197_15 & 2) != 0) {
            stage_v_133 = (pub_r000197_8 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000197_8 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000197_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000197_11 & 1) != 0) {
        if ((sec_r000197_10 & 2) != 0) {
            stage_v_134 = (pub_r000197_17 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000197_17 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000197_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000197_11 & 2) != 0) {
            stage_v_135 = (pub_r000197_5 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000197_5 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000197_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000197_2 & 1) != 0) {
        if ((sec_r000197_2 & 2) != 0) {
            stage_v_136 = (pub_r000197_16 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000197_16 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000197_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
