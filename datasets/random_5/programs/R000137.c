/*
 * Benchmark Program: R000137
 * Security Family: nested_implicit_flow
 * Generator Seed: 513713
 * High Inputs: 19 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000137_3713_0 {
    int capacity;
    int state;
    short tail;
    int buffer[3];
};

struct Vector3D_R000137_3713_1 {
    short heading;
    unsigned char norm_sq;
    short coord_x;
    int coord_y;
    short coord_z;
    int pitch;
    int buffer[3];
};

union TelemetryField_R000137_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000137_3713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000137_3713_0(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int checksum_12 = local_arr[aux % 3];
    acc = (acc + checksum_12 * 2) & 127;
    int margin_89 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_89 > 49) {
        acc = (acc + margin_89 * 2 + 5) & 127;
        aux ^= (margin_89 & 15);
    } else {
        acc = (acc - margin_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000137_3713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_99 = local_arr[aux % 3];
    acc = (acc + damping_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_2(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int threshold_81 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_81 > 20) {
        acc = (acc + threshold_81 * 2 + 5) & 127;
        aux ^= (threshold_81 & 15);
    } else {
        acc = (acc - threshold_81 + 11) & 127;
        aux += 3;
    }
    int bound_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_78 = local_arr[aux % 3];
    acc = (acc + bound_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_3(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_89 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_89 > 31) {
        acc = (acc + quantum_89 * 2 + 5) & 127;
        aux ^= (quantum_89 & 15);
    } else {
        acc = (acc - quantum_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_99) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_45 = local_arr[aux % 3];
    acc = (acc + bound_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_4(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_31 = local_arr[aux % 3];
    acc = (acc + pivot_31 * 2) & 127;
    int stride_47 = (aux + st.buffer[1]) & 3;
    switch (stride_47) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000137_3713_5(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_81 = (aux + st.buffer[1]) & 3;
    switch (segment_81) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000137_3713_6(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_41 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_41 > 25) {
        acc = (acc + segment_41 * 2 + 5) & 127;
        aux ^= (segment_41 & 15);
    } else {
        acc = (acc - segment_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_12 = (aux + st.buffer[1]) & 3;
    switch (threshold_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000137_3713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int cursor_74 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_74 > 33) {
        acc = (acc + cursor_74 * 2 + 5) & 127;
        aux ^= (cursor_74 & 15);
    } else {
        acc = (acc - cursor_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_90 = (aux + st.buffer[1]) & 3;
    switch (delta_90) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000137_3713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_86 = (aux + st.buffer[1]) & 3;
    switch (anchor_86) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int factor_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_18) & 63;
    acc ^= aux;
    int threshold_22 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_22 > 42) {
        acc = (acc + threshold_22 * 2 + 5) & 127;
        aux ^= (threshold_22 & 15);
    } else {
        acc = (acc - threshold_22 + 11) & 127;
        aux += 3;
    }
    int delta_91 = (aux + st.buffer[1]) & 3;
    switch (delta_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_49 = local_arr[aux % 3];
    acc = (acc + accumulator_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tracker_96 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_96 > 49) {
        acc = (acc + tracker_96 * 2 + 5) & 127;
        aux ^= (tracker_96 & 15);
    } else {
        acc = (acc - tracker_96 + 11) & 127;
        aux += 3;
    }
    int weight_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000137_3713_11(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int damping_35 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_35 > 22) {
        acc = (acc + damping_35 * 2 + 5) & 127;
        aux ^= (damping_35 & 15);
    } else {
        acc = (acc - damping_35 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_12(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_44 = (aux + st.buffer[1]) & 3;
    switch (quotient_44) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_79 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_79 > 24) {
        acc = (acc + residue_79 * 2 + 5) & 127;
        aux ^= (residue_79 & 15);
    } else {
        acc = (acc - residue_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_37 = local_arr[aux % 3];
    acc = (acc + delta_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_13(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int sample_41 = local_arr[aux % 3];
    acc = (acc + sample_41 * 2) & 127;
    int tracker_84 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_84 > 39) {
        acc = (acc + tracker_84 * 2 + 5) & 127;
        aux ^= (tracker_84 & 15);
    } else {
        acc = (acc - tracker_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000137_3713_14(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int parity_28 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_28 > 35) {
        acc = (acc + parity_28 * 2 + 5) & 127;
        aux ^= (parity_28 & 15);
    } else {
        acc = (acc - parity_28 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_15(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int offset_46 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_46 > 20) {
        acc = (acc + offset_46 * 2 + 5) & 127;
        aux ^= (offset_46 & 15);
    } else {
        acc = (acc - offset_46 + 11) & 127;
        aux += 3;
    }
    int pivot_44 = (aux + st.buffer[1]) & 3;
    switch (pivot_44) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_96 = local_arr[aux % 3];
    acc = (acc + phase_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_87 = (aux + st.buffer[1]) & 3;
    switch (phase_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_34 = local_arr[aux % 3];
    acc = (acc + mask_34 * 2) & 127;
    int threshold_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_17(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int metric_31 = local_arr[aux % 3];
    acc = (acc + metric_31 * 2) & 127;
    int accumulator_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_36) & 63;
    acc ^= aux;
    int cursor_51 = (aux + st.buffer[1]) & 3;
    switch (cursor_51) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_63 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_63 > 21) {
        acc = (acc + factor_63 * 2 + 5) & 127;
        aux ^= (factor_63 & 15);
    } else {
        acc = (acc - factor_63 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000137_3713_18(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int mask_38 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_38 > 45) {
        acc = (acc + mask_38 * 2 + 5) & 127;
        aux ^= (mask_38 & 15);
    } else {
        acc = (acc - mask_38 + 11) & 127;
        aux += 3;
    }
    int tally_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_95) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int delta_83 = (aux + st.buffer[1]) & 3;
    switch (delta_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_66) & 63;
    acc ^= aux;
    int metric_31 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_31 > 37) {
        acc = (acc + metric_31 * 2 + 5) & 127;
        aux ^= (metric_31 & 15);
    } else {
        acc = (acc - metric_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000137_3713_20(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_89 = local_arr[aux % 3];
    acc = (acc + factor_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000137_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_70 = local_arr[aux % 3];
    acc = (acc + damping_70 * 2) & 127;
    int weight_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000137_3713_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_55) & 63;
    acc ^= aux;
    int parity_29 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_29 > 12) {
        acc = (acc + parity_29 * 2 + 5) & 127;
        aux ^= (parity_29 & 15);
    } else {
        acc = (acc - parity_29 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000137_3713_23(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000137_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_51 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_51 > 33) {
        acc = (acc + coefficient_51 * 2 + 5) & 127;
        aux ^= (coefficient_51 & 15);
    } else {
        acc = (acc - coefficient_51 + 11) & 127;
        aux += 3;
    }
    int coefficient_36 = (aux + st.buffer[1]) & 3;
    switch (coefficient_36) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_22 = local_arr[aux % 3];
    acc = (acc + margin_22 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000137_0;
    int sec_r000137_1;
    int sec_r000137_2;
    int sec_r000137_3;
    int sec_r000137_4;
    int sec_r000137_5;
    int sec_r000137_6;
    int sec_r000137_7;
    int sec_r000137_8;
    int sec_r000137_9;
    int sec_r000137_10;
    int sec_r000137_11;
    int sec_r000137_12;
    int sec_r000137_13;
    int sec_r000137_14;
    int sec_r000137_15;
    int sec_r000137_16;
    int sec_r000137_17;
    int sec_r000137_18;
    int pub_r000137_0;
    int pub_r000137_1;
    int pub_r000137_2;
    int pub_r000137_3;
    int pub_r000137_4;
    int pub_r000137_5;
    int pub_r000137_6;
    int pub_r000137_7;
    int pub_r000137_8;
    int pub_r000137_9;
    int pub_r000137_10;
    int pub_r000137_11;
    int pub_r000137_12;
    int pub_r000137_13;
    int pub_r000137_14;
    int pub_r000137_15;
    int pub_r000137_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000137_0 >= -100 && pub_r000137_0 <= 100);
    __CPROVER_assume(pub_r000137_1 >= -100 && pub_r000137_1 <= 100);
    __CPROVER_assume(pub_r000137_2 >= -100 && pub_r000137_2 <= 100);
    __CPROVER_assume(pub_r000137_3 >= -100 && pub_r000137_3 <= 100);
    __CPROVER_assume(pub_r000137_4 >= -100 && pub_r000137_4 <= 100);
    __CPROVER_assume(pub_r000137_5 >= -100 && pub_r000137_5 <= 100);
    __CPROVER_assume(pub_r000137_6 >= -100 && pub_r000137_6 <= 100);
    __CPROVER_assume(pub_r000137_7 >= -100 && pub_r000137_7 <= 100);
    __CPROVER_assume(pub_r000137_8 >= -100 && pub_r000137_8 <= 100);
    __CPROVER_assume(pub_r000137_9 >= -100 && pub_r000137_9 <= 100);
    __CPROVER_assume(pub_r000137_10 >= -100 && pub_r000137_10 <= 100);
    __CPROVER_assume(pub_r000137_11 >= -100 && pub_r000137_11 <= 100);
    __CPROVER_assume(pub_r000137_12 >= -100 && pub_r000137_12 <= 100);
    __CPROVER_assume(pub_r000137_13 >= -100 && pub_r000137_13 <= 100);
    __CPROVER_assume(pub_r000137_14 >= -100 && pub_r000137_14 <= 100);
    __CPROVER_assume(pub_r000137_15 >= -100 && pub_r000137_15 <= 100);
    __CPROVER_assume(pub_r000137_16 >= -100 && pub_r000137_16 <= 100);
    __CPROVER_assume(sec_r000137_0 >= 0 && sec_r000137_0 <= 255);
    __CPROVER_assume(sec_r000137_1 >= 0 && sec_r000137_1 <= 255);
    __CPROVER_assume(sec_r000137_2 >= 0 && sec_r000137_2 <= 255);
    __CPROVER_assume(sec_r000137_3 >= 0 && sec_r000137_3 <= 255);
    __CPROVER_assume(sec_r000137_4 >= 0 && sec_r000137_4 <= 255);
    __CPROVER_assume(sec_r000137_5 >= 0 && sec_r000137_5 <= 255);
    __CPROVER_assume(sec_r000137_6 >= 0 && sec_r000137_6 <= 255);
    __CPROVER_assume(sec_r000137_7 >= 0 && sec_r000137_7 <= 255);
    __CPROVER_assume(sec_r000137_8 >= 0 && sec_r000137_8 <= 255);
    __CPROVER_assume(sec_r000137_9 >= 0 && sec_r000137_9 <= 255);
    __CPROVER_assume(sec_r000137_10 >= 0 && sec_r000137_10 <= 255);
    __CPROVER_assume(sec_r000137_11 >= 0 && sec_r000137_11 <= 255);
    __CPROVER_assume(sec_r000137_12 >= 0 && sec_r000137_12 <= 255);
    __CPROVER_assume(sec_r000137_13 >= 0 && sec_r000137_13 <= 255);
    __CPROVER_assume(sec_r000137_14 >= 0 && sec_r000137_14 <= 255);
    __CPROVER_assume(sec_r000137_15 >= 0 && sec_r000137_15 <= 255);
    __CPROVER_assume(sec_r000137_16 >= 0 && sec_r000137_16 <= 255);
    __CPROVER_assume(sec_r000137_17 >= 0 && sec_r000137_17 <= 255);
    __CPROVER_assume(sec_r000137_18 >= 0 && sec_r000137_18 <= 255);

    struct StreamBuffer_R000137_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000137_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000137_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000137_0 + 7) & 15;
    struct Vector3D_R000137_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000137_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000137_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000137_0 + 9) & 15;

    union TelemetryField_R000137_3713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 23) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 38) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

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
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 18) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 33) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 54) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((sec_r000137_8 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_27 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((sec_r000137_2 & 1) != 0) {
        if ((sec_r000137_15 & 2) != 0) {
            stage_v_28 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_29 = (pub_r000137_15 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000137_15 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000137_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000137_3 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_30 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000137_8 & 2) != 0) {
            stage_v_31 = (pub_r000137_13 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000137_13 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000137_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((sec_r000137_16 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_32 = (pub_r000137_13 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000137_13 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000137_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_33 = (pub_r000137_16 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000137_16 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000137_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000137_6 & 1) != 0) {
        if ((sec_r000137_12 & 2) != 0) {
            stage_v_34 = (pub_r000137_12 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000137_12 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000137_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_35 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000137_10 & 2) != 0) {
            stage_v_36 = (pub_r000137_15 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000137_15 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000137_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_37 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000137_0 & 2) != 0) {
            stage_v_38 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000137_13 & 1) != 0) {
        if ((sec_r000137_9 & 2) != 0) {
            stage_v_39 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000137_18 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_40 = (pub_r000137_11 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000137_11 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000137_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_41 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_42 = (pub_r000137_10 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000137_10 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000137_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_43 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_44 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000137_2 & 2) != 0) {
            stage_v_45 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_46 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000137_0 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_47 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000137_3 & 1) != 0) {
        if ((sec_r000137_2 & 2) != 0) {
            stage_v_48 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000137_5 & 2) != 0) {
            stage_v_49 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000137_2 & 2) != 0) {
            stage_v_50 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_51 = (pub_r000137_12 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000137_12 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000137_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000137_8 & 2) != 0) {
            stage_v_52 = (pub_r000137_11 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000137_11 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000137_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_53 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_54 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000137_6 & 2) != 0) {
            stage_v_55 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000137_16 & 1) != 0) {
        if ((sec_r000137_12 & 2) != 0) {
            stage_v_56 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000137_4 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_57 = (pub_r000137_10 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000137_10 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000137_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000137_0 & 2) != 0) {
            stage_v_58 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000137_8 & 1) != 0) {
        if ((sec_r000137_8 & 2) != 0) {
            stage_v_59 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000137_10 & 1) != 0) {
        if ((sec_r000137_17 & 2) != 0) {
            stage_v_60 = (pub_r000137_16 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000137_16 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000137_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_61 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_62 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_63 = (pub_r000137_14 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000137_14 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000137_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_64 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_65 = (pub_r000137_16 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000137_16 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000137_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000137_2 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_66 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000137_13 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_67 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000137_2 & 2) != 0) {
            stage_v_68 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_69 = (pub_r000137_3 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000137_3 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000137_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000137_16 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_70 = (pub_r000137_0 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000137_0 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000137_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000137_0 & 2) != 0) {
            stage_v_71 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000137_8 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_72 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000137_15 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_73 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000137_18 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_74 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000137_9 & 2) != 0) {
            stage_v_75 = (pub_r000137_12 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000137_12 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000137_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_76 = (pub_r000137_12 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000137_12 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000137_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000137_4 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_77 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000137_18 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_78 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000137_1 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_79 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000137_3 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_80 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000137_11 & 2) != 0) {
            stage_v_81 = (pub_r000137_13 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000137_13 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000137_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_82 = (pub_r000137_11 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000137_11 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000137_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000137_15 & 2) != 0) {
            stage_v_83 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_84 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000137_12 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_85 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_86 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000137_12 & 2) != 0) {
            stage_v_87 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000137_5 & 2) != 0) {
            stage_v_88 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000137_0 & 1) != 0) {
        if ((sec_r000137_10 & 2) != 0) {
            stage_v_89 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_90 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_91 = (pub_r000137_0 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000137_0 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000137_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000137_2 & 2) != 0) {
            stage_v_92 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000137_10 & 2) != 0) {
            stage_v_93 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000137_0 & 2) != 0) {
            stage_v_94 = (pub_r000137_9 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000137_9 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000137_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_95 = (pub_r000137_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000137_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000137_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000137_0 & 2) != 0) {
            stage_v_96 = (pub_r000137_3 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000137_3 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000137_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_97 = (pub_r000137_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000137_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000137_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000137_18 & 2) != 0) {
            stage_v_98 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000137_8 & 2) != 0) {
            stage_v_99 = (pub_r000137_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000137_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000137_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000137_6 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_100 = (pub_r000137_3 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000137_3 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000137_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_101 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000137_12 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_102 = (pub_r000137_3 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000137_3 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000137_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000137_6 & 2) != 0) {
            stage_v_103 = (pub_r000137_8 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000137_8 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000137_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((sec_r000137_14 & 1) != 0) {
        if ((sec_r000137_7 & 2) != 0) {
            stage_v_104 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_105 = (pub_r000137_14 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000137_14 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000137_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000137_17 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_106 = (pub_r000137_12 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000137_12 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000137_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000137_6 & 2) != 0) {
            stage_v_107 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000137_10 & 2) != 0) {
            stage_v_108 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000137_2 & 2) != 0) {
            stage_v_109 = (pub_r000137_7 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000137_7 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000137_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000137_0 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_110 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000137_6 & 2) != 0) {
            stage_v_111 = (pub_r000137_16 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000137_16 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000137_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000137_10 & 2) != 0) {
            stage_v_112 = (pub_r000137_3 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000137_3 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000137_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000137_13 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_113 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_114 = (pub_r000137_2 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000137_2 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000137_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000137_5 & 2) != 0) {
            stage_v_115 = (pub_r000137_6 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000137_6 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000137_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000137_3 & 1) != 0) {
        if ((sec_r000137_9 & 2) != 0) {
            stage_v_116 = (pub_r000137_10 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000137_10 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000137_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_117 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000137_0 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_118 = (pub_r000137_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000137_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000137_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000137_14 & 1) != 0) {
        if ((sec_r000137_14 & 2) != 0) {
            stage_v_119 = (pub_r000137_5 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000137_5 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000137_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000137_3 & 2) != 0) {
            stage_v_120 = (pub_r000137_3 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000137_3 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000137_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000137_8 & 2) != 0) {
            stage_v_121 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000137_5 & 2) != 0) {
            stage_v_122 = (pub_r000137_11 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000137_11 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000137_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000137_17 & 1) != 0) {
        if ((sec_r000137_13 & 2) != 0) {
            stage_v_123 = (pub_r000137_4 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000137_4 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000137_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000137_2 & 1) != 0) {
        if ((sec_r000137_1 & 2) != 0) {
            stage_v_124 = (pub_r000137_1 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000137_1 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000137_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000137_16 & 2) != 0) {
            stage_v_125 = (pub_r000137_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000137_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000137_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
