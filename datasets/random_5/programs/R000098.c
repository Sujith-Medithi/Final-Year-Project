/*
 * Benchmark Program: R000098
 * Security Family: secret_dependent_loops
 * Generator Seed: 509813
 * High Inputs: 18 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000098_9813_0 {
    int status;
    int threshold;
    unsigned char reading;
    int gain;
    int buffer[3];
};

struct DeviceConfig_R000098_9813_1 {
    unsigned char parity;
    int stop_bits;
    int baud_rate;
    int timeout;
    short port;
    int buffer[3];
};

union TelemetryField_R000098_9813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000098_9813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000098_9813_0(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int tally_17 = local_arr[aux % 3];
    acc = (acc + tally_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_23 = (aux + st.buffer[1]) & 3;
    switch (mask_23) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int tracker_79 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_79 > 19) {
        acc = (acc + tracker_79 * 2 + 5) & 127;
        aux ^= (tracker_79 & 15);
    } else {
        acc = (acc - tracker_79 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int parity_44 = local_arr[aux % 3];
    acc = (acc + parity_44 * 2) & 127;
    int stride_92 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_92 > 30) {
        acc = (acc + stride_92 * 2 + 5) & 127;
        aux ^= (stride_92 & 15);
    } else {
        acc = (acc - stride_92 + 11) & 127;
        aux += 3;
    }
    int tally_52 = (aux + st.buffer[1]) & 3;
    switch (tally_52) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int segment_90 = local_arr[aux % 3];
    acc = (acc + segment_90 * 2) & 127;
    int threshold_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_25) & 63;
    acc ^= aux;
    int delta_61 = (aux + st.buffer[1]) & 3;
    switch (delta_61) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int index_reg_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_18) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_5(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int tracker_91 = local_arr[aux % 3];
    acc = (acc + tracker_91 * 2) & 127;
    int accumulator_17 = (aux + st.buffer[1]) & 3;
    switch (accumulator_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_14 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_14 > 27) {
        acc = (acc + scale_14 * 2 + 5) & 127;
        aux ^= (scale_14 & 15);
    } else {
        acc = (acc - scale_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_6(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int mask_67 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_67 > 29) {
        acc = (acc + mask_67 * 2 + 5) & 127;
        aux ^= (mask_67 & 15);
    } else {
        acc = (acc - mask_67 + 11) & 127;
        aux += 3;
    }
    int pivot_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000098_9813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int anchor_36 = local_arr[aux % 3];
    acc = (acc + anchor_36 * 2) & 127;
    int damping_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_8(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_61) & 63;
    acc ^= aux;
    int coefficient_91 = (aux + st.buffer[1]) & 3;
    switch (coefficient_91) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_9(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int index_reg_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_30) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_11 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_11 > 39) {
        acc = (acc + cursor_11 * 2 + 5) & 127;
        aux ^= (cursor_11 & 15);
    } else {
        acc = (acc - cursor_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_11(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int weight_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_33) & 63;
    acc ^= aux;
    int phase_50 = (aux + st.buffer[1]) & 3;
    switch (phase_50) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_51 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_51 > 14) {
        acc = (acc + tally_51 * 2 + 5) & 127;
        aux ^= (tally_51 & 15);
    } else {
        acc = (acc - tally_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int offset_57 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_57 > 46) {
        acc = (acc + offset_57 * 2 + 5) & 127;
        aux ^= (offset_57 & 15);
    } else {
        acc = (acc - offset_57 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_96 = local_arr[aux % 3];
    acc = (acc + margin_96 * 2) & 127;
    int cursor_40 = (aux + st.buffer[1]) & 3;
    switch (cursor_40) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_29) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000098_9813_13(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_28 = (aux + st.buffer[1]) & 3;
    switch (stride_28) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_27 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_27 > 11) {
        acc = (acc + factor_27 * 2 + 5) & 127;
        aux ^= (factor_27 & 15);
    } else {
        acc = (acc - factor_27 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_14(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_59 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_59 > 28) {
        acc = (acc + quotient_59 * 2 + 5) & 127;
        aux ^= (quotient_59 & 15);
    } else {
        acc = (acc - quotient_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_26 = local_arr[aux % 3];
    acc = (acc + residue_26 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_54 = (aux + st.buffer[1]) & 3;
    switch (damping_54) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_15(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_15 = (aux + st.buffer[1]) & 3;
    switch (coefficient_15) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_16(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_70 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_70 > 35) {
        acc = (acc + bound_70 * 2 + 5) & 127;
        aux ^= (bound_70 & 15);
    } else {
        acc = (acc - bound_70 + 11) & 127;
        aux += 3;
    }
    int segment_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_37) & 63;
    acc ^= aux;
    int delta_43 = (aux + st.buffer[1]) & 3;
    switch (delta_43) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_17(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_90) & 63;
    acc ^= aux;
    int cursor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_68 > 43) {
        acc = (acc + cursor_68 * 2 + 5) & 127;
        aux ^= (cursor_68 & 15);
    } else {
        acc = (acc - cursor_68 + 11) & 127;
        aux += 3;
    }
    int scale_43 = (aux + st.buffer[1]) & 3;
    switch (scale_43) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000098_9813_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000098_9813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_49 = local_arr[aux % 3];
    acc = (acc + window_49 * 2) & 127;
    int threshold_92 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_92 > 27) {
        acc = (acc + threshold_92 * 2 + 5) & 127;
        aux ^= (threshold_92 & 15);
    } else {
        acc = (acc - threshold_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_77 = local_arr[aux % 3];
    acc = (acc + stride_77 * 2) & 127;
    int tally_94 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_94 > 32) {
        acc = (acc + tally_94 * 2 + 5) & 127;
        aux ^= (tally_94 & 15);
    } else {
        acc = (acc - tally_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int factor_66 = local_arr[aux % 3];
    acc = (acc + factor_66 * 2) & 127;
    int mask_47 = (aux + st.buffer[1]) & 3;
    switch (mask_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000098_9813_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000098_9813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_45) & 63;
    acc ^= aux;
    int factor_75 = (aux + st.buffer[1]) & 3;
    switch (factor_75) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000098_0;
    int sec_r000098_1;
    int sec_r000098_2;
    int sec_r000098_3;
    int sec_r000098_4;
    int sec_r000098_5;
    int sec_r000098_6;
    int sec_r000098_7;
    int sec_r000098_8;
    int sec_r000098_9;
    int sec_r000098_10;
    int sec_r000098_11;
    int sec_r000098_12;
    int sec_r000098_13;
    int sec_r000098_14;
    int sec_r000098_15;
    int sec_r000098_16;
    int sec_r000098_17;
    int pub_r000098_0;
    int pub_r000098_1;
    int pub_r000098_2;
    int pub_r000098_3;
    int pub_r000098_4;
    int pub_r000098_5;
    int pub_r000098_6;
    int pub_r000098_7;
    int pub_r000098_8;
    int pub_r000098_9;
    int pub_r000098_10;
    int pub_r000098_11;
    int pub_r000098_12;
    int pub_r000098_13;
    int pub_r000098_14;
    int pub_r000098_15;
    int pub_r000098_16;
    int pub_r000098_17;
    int pub_r000098_18;
    int pub_r000098_19;
    int pub_r000098_20;
    int pub_r000098_21;
    int pub_r000098_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000098_0 >= -100 && pub_r000098_0 <= 100);
    __CPROVER_assume(pub_r000098_1 >= -100 && pub_r000098_1 <= 100);
    __CPROVER_assume(pub_r000098_2 >= -100 && pub_r000098_2 <= 100);
    __CPROVER_assume(pub_r000098_3 >= -100 && pub_r000098_3 <= 100);
    __CPROVER_assume(pub_r000098_4 >= -100 && pub_r000098_4 <= 100);
    __CPROVER_assume(pub_r000098_5 >= -100 && pub_r000098_5 <= 100);
    __CPROVER_assume(pub_r000098_6 >= -100 && pub_r000098_6 <= 100);
    __CPROVER_assume(pub_r000098_7 >= -100 && pub_r000098_7 <= 100);
    __CPROVER_assume(pub_r000098_8 >= -100 && pub_r000098_8 <= 100);
    __CPROVER_assume(pub_r000098_9 >= -100 && pub_r000098_9 <= 100);
    __CPROVER_assume(pub_r000098_10 >= -100 && pub_r000098_10 <= 100);
    __CPROVER_assume(pub_r000098_11 >= -100 && pub_r000098_11 <= 100);
    __CPROVER_assume(pub_r000098_12 >= -100 && pub_r000098_12 <= 100);
    __CPROVER_assume(pub_r000098_13 >= -100 && pub_r000098_13 <= 100);
    __CPROVER_assume(pub_r000098_14 >= -100 && pub_r000098_14 <= 100);
    __CPROVER_assume(pub_r000098_15 >= -100 && pub_r000098_15 <= 100);
    __CPROVER_assume(pub_r000098_16 >= -100 && pub_r000098_16 <= 100);
    __CPROVER_assume(pub_r000098_17 >= -100 && pub_r000098_17 <= 100);
    __CPROVER_assume(pub_r000098_18 >= -100 && pub_r000098_18 <= 100);
    __CPROVER_assume(pub_r000098_19 >= -100 && pub_r000098_19 <= 100);
    __CPROVER_assume(pub_r000098_20 >= -100 && pub_r000098_20 <= 100);
    __CPROVER_assume(pub_r000098_21 >= -100 && pub_r000098_21 <= 100);
    __CPROVER_assume(pub_r000098_22 >= -100 && pub_r000098_22 <= 100);
    __CPROVER_assume(sec_r000098_0 >= 0 && sec_r000098_0 <= 255);
    __CPROVER_assume(sec_r000098_1 >= 0 && sec_r000098_1 <= 255);
    __CPROVER_assume(sec_r000098_2 >= 0 && sec_r000098_2 <= 255);
    __CPROVER_assume(sec_r000098_3 >= 0 && sec_r000098_3 <= 255);
    __CPROVER_assume(sec_r000098_4 >= 0 && sec_r000098_4 <= 255);
    __CPROVER_assume(sec_r000098_5 >= 0 && sec_r000098_5 <= 255);
    __CPROVER_assume(sec_r000098_6 >= 0 && sec_r000098_6 <= 255);
    __CPROVER_assume(sec_r000098_7 >= 0 && sec_r000098_7 <= 255);
    __CPROVER_assume(sec_r000098_8 >= 0 && sec_r000098_8 <= 255);
    __CPROVER_assume(sec_r000098_9 >= 0 && sec_r000098_9 <= 255);
    __CPROVER_assume(sec_r000098_10 >= 0 && sec_r000098_10 <= 255);
    __CPROVER_assume(sec_r000098_11 >= 0 && sec_r000098_11 <= 255);
    __CPROVER_assume(sec_r000098_12 >= 0 && sec_r000098_12 <= 255);
    __CPROVER_assume(sec_r000098_13 >= 0 && sec_r000098_13 <= 255);
    __CPROVER_assume(sec_r000098_14 >= 0 && sec_r000098_14 <= 255);
    __CPROVER_assume(sec_r000098_15 >= 0 && sec_r000098_15 <= 255);
    __CPROVER_assume(sec_r000098_16 >= 0 && sec_r000098_16 <= 255);
    __CPROVER_assume(sec_r000098_17 >= 0 && sec_r000098_17 <= 255);

    struct SensorNode_R000098_9813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000098_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000098_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000098_0 + 7) & 15;
    struct DeviceConfig_R000098_9813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000098_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000098_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000098_0 + 9) & 15;

    union TelemetryField_R000098_9813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 20) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 35) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 36) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 51) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 22) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 37) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 17) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 32) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 33) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 48) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 37) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 52) {
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
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

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
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 23) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 38) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[0] ^ 47) & 3;
    switch (stage_v_44) {
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

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (out_sink > 100) ? (chk_sum & 31) : (52 & 31);
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= (stage_v_47 << 1) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 17) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 32) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 28) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 43) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 19) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 34) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 22) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 37) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_5 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000098_15) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000098_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_14 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000098_15) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000098_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000098_17) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_8 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000098_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000098_9) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_1 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000098_9) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000098_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_0 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000098_13) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000098_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_14 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000098_0) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_0 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000098_19) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000098_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_17 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000098_0) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000098_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_15 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000098_6) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000098_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_6 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000098_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000098_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000098_8) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_12 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000098_1) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000098_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000098_7) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000098_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000098_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000098_20) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000098_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000098_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_65 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000098_9) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000098_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_16 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000098_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000098_17) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000098_22) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000098_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_86 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000098_5) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000098_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000098_5) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000098_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_14 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000098_1) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000098_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000098_5) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000098_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000098_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000098_15) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000098_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_13 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000098_19) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000098_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000098_6) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000098_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000098_21) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000098_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_14 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000098_17) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000098_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000098_8) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000098_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_7 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000098_22) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000098_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000098_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000098_0) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000098_21) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000098_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000098_16) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000098_12) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000098_18) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000098_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_16 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000098_20) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000098_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_12 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000098_21) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000098_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_81 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000098_0) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000098_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_6 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000098_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000098_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_2 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000098_5) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000098_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_4 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000098_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000098_15) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000098_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000098_12) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000098_15) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000098_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_8 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_1 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000098_17) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000098_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000098_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000098_20) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000098_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_14 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000098_15) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000098_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_16 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000098_20) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000098_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000098_22) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000098_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000098_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_5 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000098_19) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000098_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000098_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000098_7) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000098_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000098_13) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_4 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000098_12) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000098_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000098_2) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000098_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_12 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000098_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_7 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000098_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_0 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000098_7) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000098_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000098_1) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000098_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_5 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000098_21) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000098_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000098_17) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000098_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000098_10) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_16 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000098_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_119 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000098_2) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000098_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_15 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000098_3) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000098_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000098_22) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000098_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000098_7) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000098_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000098_8) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000098_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_5 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000098_19) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000098_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000098_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_15 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000098_6) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000098_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000098_22) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000098_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_150 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000098_0) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000098_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_17 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000098_22) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_132 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000098_18) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000098_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000098_16) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000098_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_148 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000098_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000098_5) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000098_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_7 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000098_14) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000098_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_13 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000098_9) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000098_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_154 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000098_18) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000098_5) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000098_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_163 = (stage_v_163 + step * 4 + pub_r000098_8) & 63;
        } else {
            stage_v_163 = (stage_v_163 + pub_r000098_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_163) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_8 & 1) == step) {
            stage_v_164 = (stage_v_164 + step * 4 + pub_r000098_11) & 63;
        } else {
            stage_v_164 = (stage_v_164 + pub_r000098_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_164) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_8 & 1) == step) {
            stage_v_165 = (stage_v_165 + step * 4 + pub_r000098_12) & 63;
        } else {
            stage_v_165 = (stage_v_165 + pub_r000098_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_14 & 1) == step) {
            stage_v_166 = (stage_v_166 + step * 4 + pub_r000098_3) & 63;
        } else {
            stage_v_166 = (stage_v_166 + pub_r000098_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_127 & 1) == step) {
            stage_v_167 = (stage_v_167 + step * 4 + pub_r000098_6) & 63;
        } else {
            stage_v_167 = (stage_v_167 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_7 & 1) == step) {
            stage_v_168 = (stage_v_168 + step * 4 + pub_r000098_6) & 63;
        } else {
            stage_v_168 = (stage_v_168 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_135 & 1) == step) {
            stage_v_169 = (stage_v_169 + step * 4 + pub_r000098_3) & 63;
        } else {
            stage_v_169 = (stage_v_169 + pub_r000098_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000098_13 & 1) == step) {
            stage_v_170 = (stage_v_170 + step * 4 + pub_r000098_4) & 63;
        } else {
            stage_v_170 = (stage_v_170 + pub_r000098_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_171 = (stage_v_171 + step * 4 + pub_r000098_21) & 63;
        } else {
            stage_v_171 = (stage_v_171 + pub_r000098_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
