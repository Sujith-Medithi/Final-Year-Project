/*
 * Benchmark Program: R001377
 * Security Family: nested_implicit_flow
 * Generator Seed: 637713
 * High Inputs: 24 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001377_7713_0 {
    int stop_bits;
    int timeout;
    short baud_rate;
    int buffer[3];
};

struct Vector3D_R001377_7713_1 {
    int pitch;
    int heading;
    int coord_x;
    int coord_y;
    unsigned char norm_sq;
    int coord_z;
    int buffer[3];
};

struct SensorNode_R001377_7713_2 {
    short calib;
    unsigned char gain;
    int offset;
    unsigned char threshold;
    int reading;
    unsigned char status;
    int buffer[3];
};

struct AudioFrame_R001377_7713_3 {
    unsigned char channels;
    short sample_rate;
    short envelope;
    int rms;
    int peak;
    unsigned char gain;
    int buffer[3];
};

union TelemetryField_R001377_7713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001377_7713_0(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_26 = 0;
    for (int k = 0; k < 2; k++) {
        metric_26 = (metric_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_26) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_71 = local_arr[aux % 3];
    acc = (acc + segment_71 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_69 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_69 > 34) {
        acc = (acc + metric_69 * 2 + 5) & 127;
        aux ^= (metric_69 & 15);
    } else {
        acc = (acc - metric_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int index_reg_53 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_53 > 46) {
        acc = (acc + index_reg_53 * 2 + 5) & 127;
        aux ^= (index_reg_53 & 15);
    } else {
        acc = (acc - index_reg_53 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001377_7713_2(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int factor_10 = local_arr[aux % 3];
    acc = (acc + factor_10 * 2) & 127;
    int window_89 = (aux + st.buffer[1]) & 3;
    switch (window_89) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_3(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_19) & 63;
    acc ^= aux;
    int coefficient_46 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_46 = (coefficient_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_46) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_4(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001377_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_86 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_86 = (quotient_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_86) & 127;
    }
    int vector_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001377_7713_5(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int pivot_59 = (aux + st.buffer[1]) & 3;
    switch (pivot_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_33 = local_arr[aux % 3];
    acc = (acc + tracker_33 * 2) & 127;
    int mask_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_34) & 63;
    acc ^= aux;
    int checksum_82 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_82 = (checksum_82 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_82) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_6(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_43 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_43 > 40) {
        acc = (acc + index_reg_43 * 2 + 5) & 127;
        aux ^= (index_reg_43 & 15);
    } else {
        acc = (acc - index_reg_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_7(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_15 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_15 > 29) {
        acc = (acc + scale_15 * 2 + 5) & 127;
        aux ^= (scale_15 & 15);
    } else {
        acc = (acc - scale_15 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_20 = local_arr[aux % 3];
    acc = (acc + checksum_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001377_7713_8(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int anchor_39 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_39 = (anchor_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_39) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_70 = local_arr[aux % 3];
    acc = (acc + parity_70 * 2) & 127;
    int pivot_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_54) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001377_7713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_49 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_49 > 18) {
        acc = (acc + tracker_49 * 2 + 5) & 127;
        aux ^= (tracker_49 & 15);
    } else {
        acc = (acc - tracker_49 + 11) & 127;
        aux += 3;
    }
    int coefficient_95 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_95 = (coefficient_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_95) & 127;
    }
    int tally_11 = (aux + st.buffer[1]) & 3;
    switch (tally_11) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001377_7713_10(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_70 = (aux + st.buffer[1]) & 3;
    switch (sample_70) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_96 = local_arr[aux % 3];
    acc = (acc + delta_96 * 2) & 127;
    int window_91 = 0;
    for (int k = 0; k < 2; k++) {
        window_91 = (window_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_91) & 127;
    }
    int margin_38 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_38 > 11) {
        acc = (acc + margin_38 * 2 + 5) & 127;
        aux ^= (margin_38 & 15);
    } else {
        acc = (acc - margin_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int coefficient_43 = local_arr[aux % 3];
    acc = (acc + coefficient_43 * 2) & 127;
    int anchor_45 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_45 = (anchor_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_45) & 127;
    }
    int damping_89 = (aux + st.buffer[1]) & 3;
    switch (damping_89) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_75 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_75 > 48) {
        acc = (acc + quantum_75 * 2 + 5) & 127;
        aux ^= (quantum_75 & 15);
    } else {
        acc = (acc - quantum_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_11 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_11 = (accumulator_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_11) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_76 = local_arr[aux % 3];
    acc = (acc + bound_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001377_7713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int factor_15 = (aux + st.buffer[1]) & 3;
    switch (factor_15) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001377_7713_14(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_93 = 0;
    for (int k = 0; k < 3; k++) {
        damping_93 = (damping_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_93) & 127;
    }
    int sample_27 = (aux + st.buffer[1]) & 3;
    switch (sample_27) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_15(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001377_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_93 = 0;
    for (int k = 0; k < 2; k++) {
        damping_93 = (damping_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_93) & 127;
    }
    int damping_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_32) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_11 = local_arr[aux % 3];
    acc = (acc + factor_11 * 2) & 127;
    int scale_10 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_10 > 35) {
        acc = (acc + scale_10 * 2 + 5) & 127;
        aux ^= (scale_10 & 15);
    } else {
        acc = (acc - scale_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_16(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int delta_86 = local_arr[aux % 3];
    acc = (acc + delta_86 * 2) & 127;
    int stride_63 = (aux + st.buffer[1]) & 3;
    switch (stride_63) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_71) & 63;
    acc ^= aux;
    int residue_98 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_98 > 36) {
        acc = (acc + residue_98 * 2 + 5) & 127;
        aux ^= (residue_98 & 15);
    } else {
        acc = (acc - residue_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001377_7713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int weight_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_48) & 63;
    acc ^= aux;
    int factor_12 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_12 > 35) {
        acc = (acc + factor_12 * 2 + 5) & 127;
        aux ^= (factor_12 & 15);
    } else {
        acc = (acc - factor_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_26 = local_arr[aux % 3];
    acc = (acc + coefficient_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001377_7713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001377_7713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int weight_38 = 0;
    for (int k = 0; k < 2; k++) {
        weight_38 = (weight_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_38) & 127;
    }
    int vector_78 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_78 > 20) {
        acc = (acc + vector_78 * 2 + 5) & 127;
        aux ^= (vector_78 & 15);
    } else {
        acc = (acc - vector_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_72 = local_arr[aux % 3];
    acc = (acc + index_reg_72 * 2) & 127;
    int sample_85 = (aux + st.buffer[1]) & 3;
    switch (sample_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_19(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001377_7713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_59 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_59 > 22) {
        acc = (acc + scale_59 * 2 + 5) & 127;
        aux ^= (scale_59 & 15);
    } else {
        acc = (acc - scale_59 + 11) & 127;
        aux += 3;
    }
    int quantum_86 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_86 = (quantum_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_86) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001377_7713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001377_7713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_66 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_66 > 47) {
        acc = (acc + coefficient_66 * 2 + 5) & 127;
        aux ^= (coefficient_66 & 15);
    } else {
        acc = (acc - coefficient_66 + 11) & 127;
        aux += 3;
    }
    int cursor_46 = (aux + st.buffer[1]) & 3;
    switch (cursor_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_31 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_31 = (quantum_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_31) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001377_0;
    int sec_r001377_1;
    int sec_r001377_2;
    int sec_r001377_3;
    int sec_r001377_4;
    int sec_r001377_5;
    int sec_r001377_6;
    int sec_r001377_7;
    int sec_r001377_8;
    int sec_r001377_9;
    int sec_r001377_10;
    int sec_r001377_11;
    int sec_r001377_12;
    int sec_r001377_13;
    int sec_r001377_14;
    int sec_r001377_15;
    int sec_r001377_16;
    int sec_r001377_17;
    int sec_r001377_18;
    int sec_r001377_19;
    int sec_r001377_20;
    int sec_r001377_21;
    int sec_r001377_22;
    int sec_r001377_23;
    int pub_r001377_0;
    int pub_r001377_1;
    int pub_r001377_2;
    int pub_r001377_3;
    int pub_r001377_4;
    int pub_r001377_5;
    int pub_r001377_6;
    int pub_r001377_7;
    int pub_r001377_8;
    int pub_r001377_9;
    int pub_r001377_10;
    int pub_r001377_11;
    int pub_r001377_12;
    int pub_r001377_13;
    int pub_r001377_14;
    int pub_r001377_15;
    int pub_r001377_16;
    int pub_r001377_17;
    int pub_r001377_18;
    int pub_r001377_19;
    int pub_r001377_20;
    int pub_r001377_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001377_0 >= -100 && pub_r001377_0 <= 100);
    __CPROVER_assume(pub_r001377_1 >= -100 && pub_r001377_1 <= 100);
    __CPROVER_assume(pub_r001377_2 >= -100 && pub_r001377_2 <= 100);
    __CPROVER_assume(pub_r001377_3 >= -100 && pub_r001377_3 <= 100);
    __CPROVER_assume(pub_r001377_4 >= -100 && pub_r001377_4 <= 100);
    __CPROVER_assume(pub_r001377_5 >= -100 && pub_r001377_5 <= 100);
    __CPROVER_assume(pub_r001377_6 >= -100 && pub_r001377_6 <= 100);
    __CPROVER_assume(pub_r001377_7 >= -100 && pub_r001377_7 <= 100);
    __CPROVER_assume(pub_r001377_8 >= -100 && pub_r001377_8 <= 100);
    __CPROVER_assume(pub_r001377_9 >= -100 && pub_r001377_9 <= 100);
    __CPROVER_assume(pub_r001377_10 >= -100 && pub_r001377_10 <= 100);
    __CPROVER_assume(pub_r001377_11 >= -100 && pub_r001377_11 <= 100);
    __CPROVER_assume(pub_r001377_12 >= -100 && pub_r001377_12 <= 100);
    __CPROVER_assume(pub_r001377_13 >= -100 && pub_r001377_13 <= 100);
    __CPROVER_assume(pub_r001377_14 >= -100 && pub_r001377_14 <= 100);
    __CPROVER_assume(pub_r001377_15 >= -100 && pub_r001377_15 <= 100);
    __CPROVER_assume(pub_r001377_16 >= -100 && pub_r001377_16 <= 100);
    __CPROVER_assume(pub_r001377_17 >= -100 && pub_r001377_17 <= 100);
    __CPROVER_assume(pub_r001377_18 >= -100 && pub_r001377_18 <= 100);
    __CPROVER_assume(pub_r001377_19 >= -100 && pub_r001377_19 <= 100);
    __CPROVER_assume(pub_r001377_20 >= -100 && pub_r001377_20 <= 100);
    __CPROVER_assume(pub_r001377_21 >= -100 && pub_r001377_21 <= 100);
    __CPROVER_assume(sec_r001377_0 >= 0 && sec_r001377_0 <= 255);
    __CPROVER_assume(sec_r001377_1 >= 0 && sec_r001377_1 <= 255);
    __CPROVER_assume(sec_r001377_2 >= 0 && sec_r001377_2 <= 255);
    __CPROVER_assume(sec_r001377_3 >= 0 && sec_r001377_3 <= 255);
    __CPROVER_assume(sec_r001377_4 >= 0 && sec_r001377_4 <= 255);
    __CPROVER_assume(sec_r001377_5 >= 0 && sec_r001377_5 <= 255);
    __CPROVER_assume(sec_r001377_6 >= 0 && sec_r001377_6 <= 255);
    __CPROVER_assume(sec_r001377_7 >= 0 && sec_r001377_7 <= 255);
    __CPROVER_assume(sec_r001377_8 >= 0 && sec_r001377_8 <= 255);
    __CPROVER_assume(sec_r001377_9 >= 0 && sec_r001377_9 <= 255);
    __CPROVER_assume(sec_r001377_10 >= 0 && sec_r001377_10 <= 255);
    __CPROVER_assume(sec_r001377_11 >= 0 && sec_r001377_11 <= 255);
    __CPROVER_assume(sec_r001377_12 >= 0 && sec_r001377_12 <= 255);
    __CPROVER_assume(sec_r001377_13 >= 0 && sec_r001377_13 <= 255);
    __CPROVER_assume(sec_r001377_14 >= 0 && sec_r001377_14 <= 255);
    __CPROVER_assume(sec_r001377_15 >= 0 && sec_r001377_15 <= 255);
    __CPROVER_assume(sec_r001377_16 >= 0 && sec_r001377_16 <= 255);
    __CPROVER_assume(sec_r001377_17 >= 0 && sec_r001377_17 <= 255);
    __CPROVER_assume(sec_r001377_18 >= 0 && sec_r001377_18 <= 255);
    __CPROVER_assume(sec_r001377_19 >= 0 && sec_r001377_19 <= 255);
    __CPROVER_assume(sec_r001377_20 >= 0 && sec_r001377_20 <= 255);
    __CPROVER_assume(sec_r001377_21 >= 0 && sec_r001377_21 <= 255);
    __CPROVER_assume(sec_r001377_22 >= 0 && sec_r001377_22 <= 255);
    __CPROVER_assume(sec_r001377_23 >= 0 && sec_r001377_23 <= 255);

    struct DeviceConfig_R001377_7713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001377_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001377_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001377_0 + 7) & 15;
    struct Vector3D_R001377_7713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001377_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001377_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001377_0 + 9) & 15;
    struct SensorNode_R001377_7713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001377_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001377_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001377_0 + 11) & 15;
    struct AudioFrame_R001377_7713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001377_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001377_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001377_0 + 13) & 15;

    union TelemetryField_R001377_7713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001377_7713_0(sec_r001377_0, sec_r001377_1, pub_r001377_2);
    int helper_flow_1 = fn_R001377_7713_1(sec_r001377_1, sec_r001377_2, pub_r001377_3, pub_r001377_4, pub_r001377_5);
    int helper_flow_2 = fn_R001377_7713_2(sec_r001377_2, pub_r001377_3);
    int helper_flow_3 = fn_R001377_7713_3(sec_r001377_3, pub_r001377_4, pub_r001377_5);
    int helper_flow_4 = fn_R001377_7713_4(sec_r001377_4, sec_r001377_5);
    int helper_flow_5 = fn_R001377_7713_5(sec_r001377_5, pub_r001377_6, pub_r001377_7);
    int helper_flow_6 = fn_R001377_7713_6(sec_r001377_6, sec_r001377_7, pub_r001377_8);
    int helper_flow_7 = fn_R001377_7713_7(sec_r001377_7, sec_r001377_8);
    int helper_flow_8 = fn_R001377_7713_8(sec_r001377_8, pub_r001377_9, pub_r001377_10);
    int helper_flow_9 = fn_R001377_7713_9(sec_r001377_9, sec_r001377_10, pub_r001377_11, pub_r001377_12, pub_r001377_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001377_21 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_6 ^ pub_r001377_9) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001377_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001377_8 ^ pub_r001377_15) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001377_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_9 ^ pub_r001377_20) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001377_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001377_5 ^ pub_r001377_14) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001377_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001377_21 ^ pub_r001377_9) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001377_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001377_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_9 ^ pub_r001377_2) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_5 ^ pub_r001377_12) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_8 ^ pub_r001377_9) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001377_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001377_4 ^ pub_r001377_10) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001377_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (stage_v_9 ^ pub_r001377_14) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001377_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001377_1 ^ pub_r001377_8) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001377_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001377_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001377_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001377_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_5 ^ pub_r001377_8) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001377_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001377_5 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001377_10 ^ pub_r001377_7) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001377_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_8 ^ pub_r001377_21) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001377_9 ^ pub_r001377_21) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001377_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (helper_flow_3 ^ pub_r001377_5) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_8 ^ pub_r001377_8) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001377_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001377_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001377_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (helper_flow_3 ^ pub_r001377_20) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001377_0 ^ pub_r001377_20) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001377_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001377_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001377_20 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001377_19 ^ pub_r001377_9) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_20 ^ pub_r001377_0) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001377_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001377_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_27 ^ pub_r001377_18) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001377_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_7 ^ pub_r001377_20) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r001377_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001377_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_3 ^ pub_r001377_17) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001377_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (helper_flow_3 ^ pub_r001377_5) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001377_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (sec_r001377_3 ^ pub_r001377_3) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001377_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001377_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001377_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001377_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001377_21 ^ pub_r001377_12) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r001377_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001377_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_19 ^ pub_r001377_6) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001377_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_1 ^ pub_r001377_13) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_3 ^ pub_r001377_2) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_7 ^ pub_r001377_1) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001377_8 ^ pub_r001377_0) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_8 ^ pub_r001377_5) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001377_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001377_18 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001377_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_10 ^ pub_r001377_12) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001377_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (sec_r001377_0 ^ pub_r001377_7) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001377_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_9 ^ pub_r001377_20) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r001377_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_11 ^ pub_r001377_2) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001377_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_22 ^ pub_r001377_11) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001377_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_3 ^ pub_r001377_15) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001377_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (helper_flow_9 ^ pub_r001377_13) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (sec_r001377_17 ^ pub_r001377_10) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001377_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_56 ^ pub_r001377_12) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001377_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001377_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001377_16 ^ pub_r001377_13) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_22 ^ pub_r001377_6) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001377_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001377_10 ^ pub_r001377_12) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001377_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001377_7 ^ pub_r001377_14) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r001377_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_44 ^ pub_r001377_14) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001377_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001377_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_7 ^ pub_r001377_15) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r001377_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001377_19 ^ pub_r001377_11) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001377_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_33 ^ pub_r001377_18) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_19 ^ pub_r001377_2) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001377_17 ^ pub_r001377_17) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r001377_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_20 ^ pub_r001377_11) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001377_12 ^ pub_r001377_4) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001377_8 ^ pub_r001377_3) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_83 ^ pub_r001377_10) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_73 ^ pub_r001377_7) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_36 ^ pub_r001377_18) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001377_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001377_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_4 ^ pub_r001377_4) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r001377_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_49 ^ pub_r001377_16) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_4 ^ pub_r001377_11) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r001377_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001377_16 ^ pub_r001377_6) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001377_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001377_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_9 ^ pub_r001377_9) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_47 ^ pub_r001377_17) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_13 ^ pub_r001377_17) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001377_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001377_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001377_13 ^ pub_r001377_11) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_31 ^ pub_r001377_20) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r001377_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_79 ^ pub_r001377_8) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r001377_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001377_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001377_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_38 ^ pub_r001377_19) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001377_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_20 ^ pub_r001377_17) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_60 ^ pub_r001377_19) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001377_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (helper_flow_8 ^ pub_r001377_7) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r001377_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001377_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_30 ^ pub_r001377_6) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r001377_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (helper_flow_6 ^ pub_r001377_16) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (helper_flow_9 ^ pub_r001377_14) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_102 ^ pub_r001377_16) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001377_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_1 ^ pub_r001377_3) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_116 ^ pub_r001377_12) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r001377_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001377_23 ^ pub_r001377_6) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_9 ^ pub_r001377_7) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001377_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_120 ^ pub_r001377_2) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r001377_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001377_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (helper_flow_1 ^ pub_r001377_8) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001377_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001377_1 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_111 ^ pub_r001377_9) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r001377_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_84 ^ pub_r001377_4) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001377_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001377_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001377_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001377_20 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_70 ^ pub_r001377_21) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r001377_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001377_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001377_23 ^ pub_r001377_3) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001377_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001377_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_36 ^ pub_r001377_6) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_109 ^ pub_r001377_16) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (helper_flow_2 ^ pub_r001377_7) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001377_23 ^ pub_r001377_7) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_17 ^ pub_r001377_13) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001377_21 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001377_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_70 ^ pub_r001377_14) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_142 ^ pub_r001377_12) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001377_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001377_2 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001377_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_64 ^ pub_r001377_19) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_91 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_34 ^ pub_r001377_20) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((sec_r001377_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001377_23 ^ pub_r001377_14) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_7 ^ pub_r001377_16) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (helper_flow_5 ^ pub_r001377_14) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001377_1 ^ pub_r001377_16) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001377_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_70 ^ pub_r001377_11) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_80 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (helper_flow_2 ^ pub_r001377_5) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_91 ^ pub_r001377_15) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_154 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_109 ^ pub_r001377_1) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_151 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_47 ^ pub_r001377_11) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((sec_r001377_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001377_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_91 ^ pub_r001377_19) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_157 ^ pub_r001377_9) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
