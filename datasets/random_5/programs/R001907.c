/*
 * Benchmark Program: R001907
 * Security Family: nested_implicit_flow
 * Generator Seed: 690713
 * High Inputs: 22 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001907_713_0 {
    unsigned char offset;
    int gain;
    int reading;
    short calib;
    int status;
    int buffer[3];
};

struct Vector3D_R001907_713_1 {
    int coord_x;
    int norm_sq;
    short heading;
    int buffer[3];
};

struct FilterState_R001907_713_2 {
    int damping;
    int mode;
    int prev_in;
    int buffer[3];
};

struct DeviceConfig_R001907_713_3 {
    short baud_rate;
    short id;
    int timeout;
    int stop_bits;
    int parity;
    int buffer[3];
};

union PacketPayload_R001907_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001907_713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int weight_23 = (aux + st.buffer[1]) & 3;
    switch (weight_23) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_17 = local_arr[aux % 3];
    acc = (acc + quantum_17 * 2) & 127;
    int residue_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001907_713_1(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001907_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_17 = (aux + st.buffer[1]) & 3;
    switch (quantum_17) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_28 = local_arr[aux % 3];
    acc = (acc + sample_28 * 2) & 127;
    int mask_57 = 0;
    for (int k = 0; k < 2; k++) {
        mask_57 = (mask_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_57) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_2(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int damping_58 = (aux + st.buffer[1]) & 3;
    switch (damping_58) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_96 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_96 = (index_reg_96 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_96) & 127;
    }
    int phase_25 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_25 > 23) {
        acc = (acc + phase_25 * 2 + 5) & 127;
        aux ^= (phase_25 & 15);
    } else {
        acc = (acc - phase_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_3(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_73 = (aux + st.buffer[1]) & 3;
    switch (metric_73) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_70 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_70 > 44) {
        acc = (acc + quotient_70 * 2 + 5) & 127;
        aux ^= (quotient_70 & 15);
    } else {
        acc = (acc - quotient_70 + 11) & 127;
        aux += 3;
    }
    int mask_70 = 0;
    for (int k = 0; k < 3; k++) {
        mask_70 = (mask_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_70) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_96 = local_arr[aux % 3];
    acc = (acc + residue_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001907_713_5(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_52 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_52 > 23) {
        acc = (acc + residue_52 * 2 + 5) & 127;
        aux ^= (residue_52 & 15);
    } else {
        acc = (acc - residue_52 + 11) & 127;
        aux += 3;
    }
    int checksum_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001907_713_6(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001907_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int margin_40 = local_arr[aux % 3];
    acc = (acc + margin_40 * 2) & 127;
    int quotient_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_73) & 63;
    acc ^= aux;
    int tracker_51 = (aux + st.buffer[1]) & 3;
    switch (tracker_51) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_52 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_52 > 24) {
        acc = (acc + threshold_52 * 2 + 5) & 127;
        aux ^= (threshold_52 & 15);
    } else {
        acc = (acc - threshold_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_7(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int damping_91 = local_arr[aux % 3];
    acc = (acc + damping_91 * 2) & 127;
    int delta_48 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_48 > 48) {
        acc = (acc + delta_48 * 2 + 5) & 127;
        aux ^= (delta_48 & 15);
    } else {
        acc = (acc - delta_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001907_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_96 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_96 > 15) {
        acc = (acc + accumulator_96 * 2 + 5) & 127;
        aux ^= (accumulator_96 & 15);
    } else {
        acc = (acc - accumulator_96 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_89 = local_arr[aux % 3];
    acc = (acc + pivot_89 * 2) & 127;
    int quotient_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_75) & 63;
    acc ^= aux;
    int vector_78 = 0;
    for (int k = 0; k < 2; k++) {
        vector_78 = (vector_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_78) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_9(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int delta_58 = 0;
    for (int k = 0; k < 3; k++) {
        delta_58 = (delta_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_58) & 127;
    }
    int tally_78 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_78 > 25) {
        acc = (acc + tally_78 * 2 + 5) & 127;
        aux ^= (tally_78 & 15);
    } else {
        acc = (acc - tally_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001907_713_10(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int checksum_89 = local_arr[aux % 3];
    acc = (acc + checksum_89 * 2) & 127;
    int parity_83 = 0;
    for (int k = 0; k < 2; k++) {
        parity_83 = (parity_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_83) & 127;
    }
    int weight_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001907_713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int sample_18 = local_arr[aux % 3];
    acc = (acc + sample_18 * 2) & 127;
    int quantum_67 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_67 = (quantum_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_17 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_17 > 28) {
        acc = (acc + bound_17 * 2 + 5) & 127;
        aux ^= (bound_17 & 15);
    } else {
        acc = (acc - bound_17 + 11) & 127;
        aux += 3;
    }
    int accumulator_97 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_97 = (accumulator_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_97) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_72 = local_arr[aux % 3];
    acc = (acc + factor_72 * 2) & 127;
    int quotient_18 = (aux + st.buffer[1]) & 3;
    switch (quotient_18) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_13(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int stride_68 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_68 > 19) {
        acc = (acc + stride_68 * 2 + 5) & 127;
        aux ^= (stride_68 & 15);
    } else {
        acc = (acc - stride_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_37 = local_arr[aux % 3];
    acc = (acc + weight_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001907_713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_63) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_57 = local_arr[aux % 3];
    acc = (acc + parity_57 * 2) & 127;
    int quantum_62 = (aux + st.buffer[1]) & 3;
    switch (quantum_62) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001907_713_15(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_97 = 0;
    for (int k = 0; k < 2; k++) {
        phase_97 = (phase_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_97) & 127;
    }
    int threshold_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_93) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001907_713_16(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int threshold_77 = local_arr[aux % 3];
    acc = (acc + threshold_77 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_70 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_70 = (quotient_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_70) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int window_72 = (st.buffer[0] * 3 + aux) & 63;
    if (window_72 > 11) {
        acc = (acc + window_72 * 2 + 5) & 127;
        aux ^= (window_72 & 15);
    } else {
        acc = (acc - window_72 + 11) & 127;
        aux += 3;
    }
    int segment_95 = 0;
    for (int k = 0; k < 2; k++) {
        segment_95 = (segment_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_18(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_49 = (aux + st.buffer[1]) & 3;
    switch (tally_49) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_38) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int offset_72 = local_arr[aux % 3];
    acc = (acc + offset_72 * 2) & 127;
    int checksum_99 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_99 = (checksum_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001907_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quantum_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_55 > 35) {
        acc = (acc + quantum_55 * 2 + 5) & 127;
        aux ^= (quantum_55 & 15);
    } else {
        acc = (acc - quantum_55 + 11) & 127;
        aux += 3;
    }
    int delta_68 = (aux + st.buffer[1]) & 3;
    switch (delta_68) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_20(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001907_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int anchor_72 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_72 = (anchor_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_72) & 127;
    }
    int tally_45 = (aux + st.buffer[1]) & 3;
    switch (tally_45) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_41 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_41 > 33) {
        acc = (acc + accumulator_41 * 2 + 5) & 127;
        aux ^= (accumulator_41 & 15);
    } else {
        acc = (acc - accumulator_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_61 = local_arr[aux % 3];
    acc = (acc + tracker_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001907_713_21(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tally_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_99) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_92 = local_arr[aux % 3];
    acc = (acc + metric_92 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_99 = 0;
    for (int k = 0; k < 3; k++) {
        offset_99 = (offset_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001907_713_22(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001907_713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_30) & 63;
    acc ^= aux;
    int sample_84 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_84 > 17) {
        acc = (acc + sample_84 * 2 + 5) & 127;
        aux ^= (sample_84 & 15);
    } else {
        acc = (acc - sample_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_64 = local_arr[aux % 3];
    acc = (acc + cursor_64 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001907_0;
    int sec_r001907_1;
    int sec_r001907_2;
    int sec_r001907_3;
    int sec_r001907_4;
    int sec_r001907_5;
    int sec_r001907_6;
    int sec_r001907_7;
    int sec_r001907_8;
    int sec_r001907_9;
    int sec_r001907_10;
    int sec_r001907_11;
    int sec_r001907_12;
    int sec_r001907_13;
    int sec_r001907_14;
    int sec_r001907_15;
    int sec_r001907_16;
    int sec_r001907_17;
    int sec_r001907_18;
    int sec_r001907_19;
    int sec_r001907_20;
    int sec_r001907_21;
    int pub_r001907_0;
    int pub_r001907_1;
    int pub_r001907_2;
    int pub_r001907_3;
    int pub_r001907_4;
    int pub_r001907_5;
    int pub_r001907_6;
    int pub_r001907_7;
    int pub_r001907_8;
    int pub_r001907_9;
    int pub_r001907_10;
    int pub_r001907_11;
    int pub_r001907_12;
    int pub_r001907_13;
    int pub_r001907_14;
    int pub_r001907_15;
    int pub_r001907_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001907_0 >= -100 && pub_r001907_0 <= 100);
    __CPROVER_assume(pub_r001907_1 >= -100 && pub_r001907_1 <= 100);
    __CPROVER_assume(pub_r001907_2 >= -100 && pub_r001907_2 <= 100);
    __CPROVER_assume(pub_r001907_3 >= -100 && pub_r001907_3 <= 100);
    __CPROVER_assume(pub_r001907_4 >= -100 && pub_r001907_4 <= 100);
    __CPROVER_assume(pub_r001907_5 >= -100 && pub_r001907_5 <= 100);
    __CPROVER_assume(pub_r001907_6 >= -100 && pub_r001907_6 <= 100);
    __CPROVER_assume(pub_r001907_7 >= -100 && pub_r001907_7 <= 100);
    __CPROVER_assume(pub_r001907_8 >= -100 && pub_r001907_8 <= 100);
    __CPROVER_assume(pub_r001907_9 >= -100 && pub_r001907_9 <= 100);
    __CPROVER_assume(pub_r001907_10 >= -100 && pub_r001907_10 <= 100);
    __CPROVER_assume(pub_r001907_11 >= -100 && pub_r001907_11 <= 100);
    __CPROVER_assume(pub_r001907_12 >= -100 && pub_r001907_12 <= 100);
    __CPROVER_assume(pub_r001907_13 >= -100 && pub_r001907_13 <= 100);
    __CPROVER_assume(pub_r001907_14 >= -100 && pub_r001907_14 <= 100);
    __CPROVER_assume(pub_r001907_15 >= -100 && pub_r001907_15 <= 100);
    __CPROVER_assume(pub_r001907_16 >= -100 && pub_r001907_16 <= 100);
    __CPROVER_assume(sec_r001907_0 >= 0 && sec_r001907_0 <= 255);
    __CPROVER_assume(sec_r001907_1 >= 0 && sec_r001907_1 <= 255);
    __CPROVER_assume(sec_r001907_2 >= 0 && sec_r001907_2 <= 255);
    __CPROVER_assume(sec_r001907_3 >= 0 && sec_r001907_3 <= 255);
    __CPROVER_assume(sec_r001907_4 >= 0 && sec_r001907_4 <= 255);
    __CPROVER_assume(sec_r001907_5 >= 0 && sec_r001907_5 <= 255);
    __CPROVER_assume(sec_r001907_6 >= 0 && sec_r001907_6 <= 255);
    __CPROVER_assume(sec_r001907_7 >= 0 && sec_r001907_7 <= 255);
    __CPROVER_assume(sec_r001907_8 >= 0 && sec_r001907_8 <= 255);
    __CPROVER_assume(sec_r001907_9 >= 0 && sec_r001907_9 <= 255);
    __CPROVER_assume(sec_r001907_10 >= 0 && sec_r001907_10 <= 255);
    __CPROVER_assume(sec_r001907_11 >= 0 && sec_r001907_11 <= 255);
    __CPROVER_assume(sec_r001907_12 >= 0 && sec_r001907_12 <= 255);
    __CPROVER_assume(sec_r001907_13 >= 0 && sec_r001907_13 <= 255);
    __CPROVER_assume(sec_r001907_14 >= 0 && sec_r001907_14 <= 255);
    __CPROVER_assume(sec_r001907_15 >= 0 && sec_r001907_15 <= 255);
    __CPROVER_assume(sec_r001907_16 >= 0 && sec_r001907_16 <= 255);
    __CPROVER_assume(sec_r001907_17 >= 0 && sec_r001907_17 <= 255);
    __CPROVER_assume(sec_r001907_18 >= 0 && sec_r001907_18 <= 255);
    __CPROVER_assume(sec_r001907_19 >= 0 && sec_r001907_19 <= 255);
    __CPROVER_assume(sec_r001907_20 >= 0 && sec_r001907_20 <= 255);
    __CPROVER_assume(sec_r001907_21 >= 0 && sec_r001907_21 <= 255);

    struct SensorNode_R001907_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001907_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001907_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001907_0 + 7) & 15;
    struct Vector3D_R001907_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001907_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001907_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001907_0 + 9) & 15;
    struct FilterState_R001907_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001907_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001907_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001907_0 + 11) & 15;
    struct DeviceConfig_R001907_713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001907_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001907_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001907_0 + 13) & 15;

    union PacketPayload_R001907_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001907_713_0(sec_r001907_0, pub_r001907_1, pub_r001907_2, pub_r001907_3, pub_r001907_4);
    int helper_flow_1 = fn_R001907_713_1(sec_r001907_1, pub_r001907_2);
    int helper_flow_2 = fn_R001907_713_2(sec_r001907_2, pub_r001907_3);
    int helper_flow_3 = fn_R001907_713_3(sec_r001907_3, pub_r001907_4, pub_r001907_5);
    int helper_flow_4 = fn_R001907_713_4(sec_r001907_4, sec_r001907_5, pub_r001907_6, pub_r001907_7, pub_r001907_8);
    int helper_flow_5 = fn_R001907_713_5(sec_r001907_5, pub_r001907_6, pub_r001907_7);
    int helper_flow_6 = fn_R001907_713_6(sec_r001907_6, pub_r001907_7);
    int helper_flow_7 = fn_R001907_713_7(sec_r001907_7, pub_r001907_8);
    int helper_flow_8 = fn_R001907_713_8(sec_r001907_8, sec_r001907_9, pub_r001907_10, pub_r001907_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001907_4 ^ pub_r001907_2) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001907_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_0 ^ pub_r001907_16) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001907_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001907_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_7 ^ pub_r001907_15) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001907_4 ^ pub_r001907_13) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001907_19 ^ pub_r001907_16) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_2 ^ pub_r001907_15) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001907_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001907_21 ^ pub_r001907_6) & 63;
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
    int stage_v_9 = (pub_r001907_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001907_12 ^ pub_r001907_7) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001907_18 ^ pub_r001907_15) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001907_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_10 ^ pub_r001907_9) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001907_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001907_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_5 ^ pub_r001907_6) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r001907_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_10 ^ pub_r001907_12) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001907_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001907_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001907_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (stage_v_15 ^ pub_r001907_2) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001907_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001907_3 ^ pub_r001907_6) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001907_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001907_3 ^ pub_r001907_3) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_8 ^ pub_r001907_6) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_7 ^ pub_r001907_2) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001907_11 ^ pub_r001907_16) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r001907_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001907_13 ^ pub_r001907_14) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r001907_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_0 ^ pub_r001907_13) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001907_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001907_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001907_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001907_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_6 ^ pub_r001907_14) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001907_7 ^ pub_r001907_3) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_27 ^ pub_r001907_12) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001907_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001907_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_21 ^ pub_r001907_4) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001907_6 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001907_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_6 ^ pub_r001907_14) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001907_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001907_9 ^ pub_r001907_1) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_35 ^ pub_r001907_16) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r001907_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001907_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001907_20 ^ pub_r001907_7) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_22 ^ pub_r001907_4) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001907_21 ^ pub_r001907_8) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001907_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001907_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001907_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001907_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001907_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001907_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_10 ^ pub_r001907_2) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_24 ^ pub_r001907_13) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001907_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_26 ^ pub_r001907_11) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_8 ^ pub_r001907_6) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001907_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001907_4 ^ pub_r001907_15) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_5 ^ pub_r001907_14) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (helper_flow_3 ^ pub_r001907_11) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001907_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001907_10 ^ pub_r001907_1) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_5 ^ pub_r001907_10) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001907_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001907_18 ^ pub_r001907_2) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001907_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001907_12 ^ pub_r001907_0) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001907_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001907_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001907_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_56 ^ pub_r001907_14) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r001907_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r001907_14 ^ pub_r001907_0) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r001907_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001907_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_10 ^ pub_r001907_10) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r001907_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (helper_flow_2 ^ pub_r001907_12) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001907_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001907_21 ^ pub_r001907_7) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001907_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001907_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_27 ^ pub_r001907_6) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_54 ^ pub_r001907_8) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001907_7 ^ pub_r001907_7) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001907_11 ^ pub_r001907_3) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001907_13 ^ pub_r001907_1) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_53 ^ pub_r001907_9) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001907_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001907_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001907_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_59 ^ pub_r001907_1) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_24 ^ pub_r001907_2) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_53 ^ pub_r001907_14) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_44 ^ pub_r001907_12) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r001907_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_73 ^ pub_r001907_2) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_40 ^ pub_r001907_13) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_40 ^ pub_r001907_11) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001907_16 ^ pub_r001907_12) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_24 ^ pub_r001907_12) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001907_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_54 ^ pub_r001907_12) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_85 ^ pub_r001907_12) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001907_18 ^ pub_r001907_4) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r001907_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001907_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001907_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001907_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001907_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001907_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (helper_flow_4 ^ pub_r001907_12) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_39 ^ pub_r001907_3) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_53 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001907_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001907_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001907_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001907_9 ^ pub_r001907_4) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r001907_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_38 ^ pub_r001907_8) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_40 ^ pub_r001907_16) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001907_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_15 ^ pub_r001907_4) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001907_12 ^ pub_r001907_11) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_73 ^ pub_r001907_2) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001907_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001907_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_26 ^ pub_r001907_7) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_27 ^ pub_r001907_7) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_26 ^ pub_r001907_8) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_82 ^ pub_r001907_8) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001907_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_15 ^ pub_r001907_1) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_40 ^ pub_r001907_3) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r001907_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001907_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_59 ^ pub_r001907_1) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_6 ^ pub_r001907_4) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001907_15 ^ pub_r001907_9) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_50 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (sec_r001907_9 ^ pub_r001907_1) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001907_3 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001907_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_43 ^ pub_r001907_2) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r001907_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (helper_flow_5 ^ pub_r001907_8) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001907_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_124 ^ pub_r001907_1) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_121 ^ pub_r001907_9) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_11 ^ pub_r001907_2) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_69 ^ pub_r001907_7) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_32 ^ pub_r001907_16) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r001907_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001907_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_2 ^ pub_r001907_7) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r001907_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_104 ^ pub_r001907_7) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_99 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_40 ^ pub_r001907_13) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_53 ^ pub_r001907_11) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001907_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001907_7 ^ pub_r001907_6) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_85 ^ pub_r001907_7) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r001907_2 ^ pub_r001907_15) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_11 ^ pub_r001907_5) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((sec_r001907_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001907_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (helper_flow_2 ^ pub_r001907_8) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001907_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_26 ^ pub_r001907_6) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r001907_9 ^ pub_r001907_1) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r001907_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (helper_flow_2 ^ pub_r001907_14) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_100 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_31 ^ pub_r001907_12) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((sec_r001907_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (sec_r001907_10 ^ pub_r001907_9) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_25 ^ pub_r001907_0) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_152 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001907_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_84 ^ pub_r001907_11) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((sec_r001907_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_155 ^ pub_r001907_0) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_13 ^ pub_r001907_12) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_50 ^ pub_r001907_6) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_35 ^ pub_r001907_12) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_89 ^ pub_r001907_6) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001907_2 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_50 ^ pub_r001907_5) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_156 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_143 ^ pub_r001907_10) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_146 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_152 ^ pub_r001907_10) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r001907_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_100 ^ pub_r001907_16) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
