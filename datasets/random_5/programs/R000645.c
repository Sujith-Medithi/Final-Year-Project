/*
 * Benchmark Program: R000645
 * Security Family: bitwise_flow
 * Generator Seed: 564513
 * High Inputs: 24 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000645_4513_0 {
    short coord_x;
    unsigned char norm_sq;
    short coord_z;
    int buffer[3];
};

struct DeviceConfig_R000645_4513_1 {
    int port;
    int timeout;
    unsigned char baud_rate;
    int buffer[3];
};

struct SensorNode_R000645_4513_2 {
    unsigned char threshold;
    short reading;
    short calib;
    short offset;
    short status;
    int buffer[3];
};

struct EventLog_R000645_4513_3 {
    short seq;
    int severity;
    int code;
    int facility;
    short signature;
    int timestamp;
    int buffer[3];
};

union ColorPixel_R000645_4513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000645_4513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000645_4513_0(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000645_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tracker_86 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_86 > 22) {
        acc = (acc + tracker_86 * 2 + 5) & 127;
        aux ^= (tracker_86 & 15);
    } else {
        acc = (acc - tracker_86 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_33 = local_arr[aux % 3];
    acc = (acc + mask_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_1(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quotient_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int weight_58 = local_arr[aux % 3];
    acc = (acc + weight_58 * 2) & 127;
    int bound_68 = (aux + st.buffer[1]) & 3;
    switch (bound_68) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_2(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int cursor_41 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_41 > 24) {
        acc = (acc + cursor_41 * 2 + 5) & 127;
        aux ^= (cursor_41 & 15);
    } else {
        acc = (acc - cursor_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_94 = local_arr[aux % 3];
    acc = (acc + phase_94 * 2) & 127;
    int scale_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_81) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_3(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_88 = (aux + st.buffer[1]) & 3;
    switch (anchor_88) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_95) & 63;
    acc ^= aux;
    int coefficient_66 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_66 > 47) {
        acc = (acc + coefficient_66 * 2 + 5) & 127;
        aux ^= (coefficient_66 & 15);
    } else {
        acc = (acc - coefficient_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_4(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int pivot_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_97) & 63;
    acc ^= aux;
    int scale_32 = (aux + st.buffer[1]) & 3;
    switch (scale_32) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_52) & 63;
    acc ^= aux;
    int index_reg_70 = (aux + st.buffer[1]) & 3;
    switch (index_reg_70) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_6(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int pivot_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_88 = local_arr[aux % 3];
    acc = (acc + scale_88 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_99 = local_arr[aux % 3];
    acc = (acc + window_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_66 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_66 > 40) {
        acc = (acc + phase_66 * 2 + 5) & 127;
        aux ^= (phase_66 & 15);
    } else {
        acc = (acc - phase_66 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_47 = (aux + st.buffer[1]) & 3;
    switch (stride_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_71 = (aux + st.buffer[1]) & 3;
    switch (checksum_71) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_10 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_10 > 20) {
        acc = (acc + stride_10 * 2 + 5) & 127;
        aux ^= (stride_10 & 15);
    } else {
        acc = (acc - stride_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_38 = local_arr[aux % 3];
    acc = (acc + sample_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_10(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int segment_35 = local_arr[aux % 3];
    acc = (acc + segment_35 * 2) & 127;
    int stride_82 = (aux + st.buffer[1]) & 3;
    switch (stride_82) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_89 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_89 > 22) {
        acc = (acc + tracker_89 * 2 + 5) & 127;
        aux ^= (tracker_89 & 15);
    } else {
        acc = (acc - tracker_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_12(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int offset_14 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_14 > 46) {
        acc = (acc + offset_14 * 2 + 5) & 127;
        aux ^= (offset_14 & 15);
    } else {
        acc = (acc - offset_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_85 = local_arr[aux % 3];
    acc = (acc + bound_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000645_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int segment_71 = local_arr[aux % 3];
    acc = (acc + segment_71 * 2) & 127;
    int vector_80 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_80 > 46) {
        acc = (acc + vector_80 * 2 + 5) & 127;
        aux ^= (vector_80 & 15);
    } else {
        acc = (acc - vector_80 + 11) & 127;
        aux += 3;
    }
    int parity_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000645_4513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_31 > 49) {
        acc = (acc + anchor_31 * 2 + 5) & 127;
        aux ^= (anchor_31 & 15);
    } else {
        acc = (acc - anchor_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_15(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000645_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_95 = local_arr[aux % 3];
    acc = (acc + index_reg_95 * 2) & 127;
    int margin_27 = (aux + st.buffer[1]) & 3;
    switch (margin_27) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_16(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_67 = (aux + st.buffer[1]) & 3;
    switch (quantum_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_89 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_89 > 45) {
        acc = (acc + sample_89 * 2 + 5) & 127;
        aux ^= (sample_89 & 15);
    } else {
        acc = (acc - sample_89 + 11) & 127;
        aux += 3;
    }
    int checksum_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000645_4513_17(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_83 = (aux + st.buffer[1]) & 3;
    switch (checksum_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_18(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000645_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_90 = (aux + st.buffer[1]) & 3;
    switch (stride_90) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_44) & 63;
    acc ^= aux;
    int threshold_23 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_23 > 45) {
        acc = (acc + threshold_23 * 2 + 5) & 127;
        aux ^= (threshold_23 & 15);
    } else {
        acc = (acc - threshold_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000645_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int scale_72 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_72 > 32) {
        acc = (acc + scale_72 * 2 + 5) & 127;
        aux ^= (scale_72 & 15);
    } else {
        acc = (acc - scale_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_85 = local_arr[aux % 3];
    acc = (acc + window_85 * 2) & 127;
    int bound_57 = (aux + st.buffer[1]) & 3;
    switch (bound_57) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000645_4513_20(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int accumulator_79 = local_arr[aux % 3];
    acc = (acc + accumulator_79 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_68 = (aux + st.buffer[1]) & 3;
    switch (index_reg_68) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000645_4513_21(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000645_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int weight_38 = (aux + st.buffer[1]) & 3;
    switch (weight_38) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_37 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_37 > 22) {
        acc = (acc + parity_37 * 2 + 5) & 127;
        aux ^= (parity_37 & 15);
    } else {
        acc = (acc - parity_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000645_4513_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000645_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int quantum_85 = local_arr[aux % 3];
    acc = (acc + quantum_85 * 2) & 127;
    int damping_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_52) & 63;
    acc ^= aux;
    int delta_32 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_32 > 38) {
        acc = (acc + delta_32 * 2 + 5) & 127;
        aux ^= (delta_32 & 15);
    } else {
        acc = (acc - delta_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000645_0;
    int sec_r000645_1;
    int sec_r000645_2;
    int sec_r000645_3;
    int sec_r000645_4;
    int sec_r000645_5;
    int sec_r000645_6;
    int sec_r000645_7;
    int sec_r000645_8;
    int sec_r000645_9;
    int sec_r000645_10;
    int sec_r000645_11;
    int sec_r000645_12;
    int sec_r000645_13;
    int sec_r000645_14;
    int sec_r000645_15;
    int sec_r000645_16;
    int sec_r000645_17;
    int sec_r000645_18;
    int sec_r000645_19;
    int sec_r000645_20;
    int sec_r000645_21;
    int sec_r000645_22;
    int sec_r000645_23;
    int pub_r000645_0;
    int pub_r000645_1;
    int pub_r000645_2;
    int pub_r000645_3;
    int pub_r000645_4;
    int pub_r000645_5;
    int pub_r000645_6;
    int pub_r000645_7;
    int pub_r000645_8;
    int pub_r000645_9;
    int pub_r000645_10;
    int pub_r000645_11;
    int pub_r000645_12;
    int pub_r000645_13;
    int pub_r000645_14;
    int pub_r000645_15;
    int pub_r000645_16;
    int pub_r000645_17;
    int pub_r000645_18;
    int pub_r000645_19;
    int pub_r000645_20;
    int pub_r000645_21;
    int pub_r000645_22;
    int pub_r000645_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000645_0 >= -100 && pub_r000645_0 <= 100);
    __CPROVER_assume(pub_r000645_1 >= -100 && pub_r000645_1 <= 100);
    __CPROVER_assume(pub_r000645_2 >= -100 && pub_r000645_2 <= 100);
    __CPROVER_assume(pub_r000645_3 >= -100 && pub_r000645_3 <= 100);
    __CPROVER_assume(pub_r000645_4 >= -100 && pub_r000645_4 <= 100);
    __CPROVER_assume(pub_r000645_5 >= -100 && pub_r000645_5 <= 100);
    __CPROVER_assume(pub_r000645_6 >= -100 && pub_r000645_6 <= 100);
    __CPROVER_assume(pub_r000645_7 >= -100 && pub_r000645_7 <= 100);
    __CPROVER_assume(pub_r000645_8 >= -100 && pub_r000645_8 <= 100);
    __CPROVER_assume(pub_r000645_9 >= -100 && pub_r000645_9 <= 100);
    __CPROVER_assume(pub_r000645_10 >= -100 && pub_r000645_10 <= 100);
    __CPROVER_assume(pub_r000645_11 >= -100 && pub_r000645_11 <= 100);
    __CPROVER_assume(pub_r000645_12 >= -100 && pub_r000645_12 <= 100);
    __CPROVER_assume(pub_r000645_13 >= -100 && pub_r000645_13 <= 100);
    __CPROVER_assume(pub_r000645_14 >= -100 && pub_r000645_14 <= 100);
    __CPROVER_assume(pub_r000645_15 >= -100 && pub_r000645_15 <= 100);
    __CPROVER_assume(pub_r000645_16 >= -100 && pub_r000645_16 <= 100);
    __CPROVER_assume(pub_r000645_17 >= -100 && pub_r000645_17 <= 100);
    __CPROVER_assume(pub_r000645_18 >= -100 && pub_r000645_18 <= 100);
    __CPROVER_assume(pub_r000645_19 >= -100 && pub_r000645_19 <= 100);
    __CPROVER_assume(pub_r000645_20 >= -100 && pub_r000645_20 <= 100);
    __CPROVER_assume(pub_r000645_21 >= -100 && pub_r000645_21 <= 100);
    __CPROVER_assume(pub_r000645_22 >= -100 && pub_r000645_22 <= 100);
    __CPROVER_assume(pub_r000645_23 >= -100 && pub_r000645_23 <= 100);
    __CPROVER_assume(sec_r000645_0 >= 0 && sec_r000645_0 <= 255);
    __CPROVER_assume(sec_r000645_1 >= 0 && sec_r000645_1 <= 255);
    __CPROVER_assume(sec_r000645_2 >= 0 && sec_r000645_2 <= 255);
    __CPROVER_assume(sec_r000645_3 >= 0 && sec_r000645_3 <= 255);
    __CPROVER_assume(sec_r000645_4 >= 0 && sec_r000645_4 <= 255);
    __CPROVER_assume(sec_r000645_5 >= 0 && sec_r000645_5 <= 255);
    __CPROVER_assume(sec_r000645_6 >= 0 && sec_r000645_6 <= 255);
    __CPROVER_assume(sec_r000645_7 >= 0 && sec_r000645_7 <= 255);
    __CPROVER_assume(sec_r000645_8 >= 0 && sec_r000645_8 <= 255);
    __CPROVER_assume(sec_r000645_9 >= 0 && sec_r000645_9 <= 255);
    __CPROVER_assume(sec_r000645_10 >= 0 && sec_r000645_10 <= 255);
    __CPROVER_assume(sec_r000645_11 >= 0 && sec_r000645_11 <= 255);
    __CPROVER_assume(sec_r000645_12 >= 0 && sec_r000645_12 <= 255);
    __CPROVER_assume(sec_r000645_13 >= 0 && sec_r000645_13 <= 255);
    __CPROVER_assume(sec_r000645_14 >= 0 && sec_r000645_14 <= 255);
    __CPROVER_assume(sec_r000645_15 >= 0 && sec_r000645_15 <= 255);
    __CPROVER_assume(sec_r000645_16 >= 0 && sec_r000645_16 <= 255);
    __CPROVER_assume(sec_r000645_17 >= 0 && sec_r000645_17 <= 255);
    __CPROVER_assume(sec_r000645_18 >= 0 && sec_r000645_18 <= 255);
    __CPROVER_assume(sec_r000645_19 >= 0 && sec_r000645_19 <= 255);
    __CPROVER_assume(sec_r000645_20 >= 0 && sec_r000645_20 <= 255);
    __CPROVER_assume(sec_r000645_21 >= 0 && sec_r000645_21 <= 255);
    __CPROVER_assume(sec_r000645_22 >= 0 && sec_r000645_22 <= 255);
    __CPROVER_assume(sec_r000645_23 >= 0 && sec_r000645_23 <= 255);

    struct Vector3D_R000645_4513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000645_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000645_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000645_0 + 7) & 15;
    struct DeviceConfig_R000645_4513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000645_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000645_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000645_0 + 9) & 15;
    struct SensorNode_R000645_4513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000645_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000645_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000645_0 + 11) & 15;
    struct EventLog_R000645_4513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000645_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000645_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000645_0 + 13) & 15;

    union ColorPixel_R000645_4513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 16) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 31) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 27) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 42) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 10) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 25) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 28) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 43) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

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
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 26) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 41) {
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
    if (stage_v_22 > 22) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 37) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_3.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 19) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 34) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 31) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 46) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 17) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 32) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 21) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 36) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 16) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 31) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 18) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 33) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 19) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 34) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 15) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 30) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 26) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 41) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 36) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 51) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 17) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 32) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 31) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 46) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] ^ 69) & 3;
    switch (stage_v_66) {
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

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

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
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_86 = (stage_v_86 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_3.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 32) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 47) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000645_10 << 2) ^ (sec_r000645_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_89 << 1) ^ (sec_r000645_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000645_11 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r000645_14 << 2) ^ (sec_r000645_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_90 << 2) ^ (sec_r000645_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_93 << 2) ^ (sec_r000645_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_91 << 1) ^ (sec_r000645_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_89 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r000645_11 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_93 << 2) ^ (sec_r000645_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_97 << 2) ^ (sec_r000645_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_94 << 2) ^ (sec_r000645_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_97 << 1) ^ (sec_r000645_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_89 << 2) ^ (sec_r000645_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_92 << 2) ^ (sec_r000645_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_91 << 1) ^ (sec_r000645_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_95 << 1) ^ (sec_r000645_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r000645_1 << 2) ^ (sec_r000645_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_94 << 2) ^ (sec_r000645_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000645_17 << 2) ^ (sec_r000645_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_103 << 2) ^ (sec_r000645_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_101 << 1) ^ (sec_r000645_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_102 << 1) ^ (sec_r000645_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r000645_21 << 2) ^ (sec_r000645_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_91 << 2) ^ (sec_r000645_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_89 << 2) ^ (sec_r000645_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r000645_1 << 2) ^ (sec_r000645_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r000645_5 << 2) ^ (sec_r000645_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_99 << 2) ^ (sec_r000645_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_115 << 2) ^ (sec_r000645_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_116 << 2) ^ (sec_r000645_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_111 << 2) ^ (sec_r000645_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_89 << 1) ^ (sec_r000645_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_93 << 1) ^ (sec_r000645_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_93 << 1) ^ (sec_r000645_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r000645_16 << 1) ^ (sec_r000645_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_119 << 1) ^ (sec_r000645_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000645_12 << 1) ^ (sec_r000645_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r000645_17 << 1) ^ (sec_r000645_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_93 << 2) ^ (sec_r000645_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r000645_12 << 1) ^ (sec_r000645_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_95 << 1) ^ (sec_r000645_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000645_21 << 2) ^ (sec_r000645_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_118 << 2) ^ (sec_r000645_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_106 << 1) ^ (sec_r000645_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000645_19 << 1) ^ (sec_r000645_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_117 << 2) ^ (sec_r000645_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_93 << 1) ^ (sec_r000645_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r000645_1 << 1) ^ (sec_r000645_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_135 << 1) ^ (sec_r000645_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_123 << 1) ^ (sec_r000645_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000645_8 << 2) ^ (sec_r000645_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_93 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_139 << 1) ^ (sec_r000645_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_103 << 2) ^ (sec_r000645_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_142 << 2) ^ (sec_r000645_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r000645_23 << 2) ^ (sec_r000645_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000645_12 << 1) ^ (sec_r000645_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000645_7 << 2) ^ (sec_r000645_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_132 << 2) ^ (sec_r000645_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_116 << 2) ^ (sec_r000645_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_131 << 2) ^ (sec_r000645_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_97 << 1) ^ (sec_r000645_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_106 << 2) ^ (sec_r000645_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((sec_r000645_16 << 1) ^ (sec_r000645_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_98 << 2) ^ (sec_r000645_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_141 << 1) ^ (sec_r000645_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000645_22 << 2) ^ (sec_r000645_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000645_18 << 1) ^ (sec_r000645_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r000645_8 << 1) ^ (sec_r000645_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000645_7 << 2) ^ (sec_r000645_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r000645_15 << 2) ^ (sec_r000645_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_150 << 2) ^ (sec_r000645_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r000645_13 << 1) ^ (sec_r000645_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_97 << 2) ^ (sec_r000645_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r000645_2 << 1) ^ (sec_r000645_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_163 << 2) ^ (sec_r000645_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000645_5 << 1) ^ (sec_r000645_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000645_23 << 1) ^ (sec_r000645_23 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000645_12 << 2) ^ (sec_r000645_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_109 << 2) ^ (sec_r000645_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_166 << 2) ^ (sec_r000645_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_166 << 1) ^ (sec_r000645_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000645_16 << 2) ^ (sec_r000645_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000645_17 << 2) ^ (sec_r000645_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r000645_21 << 1) ^ (sec_r000645_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_158 << 1) ^ (sec_r000645_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_122 << 2) ^ (sec_r000645_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000645_2 << 2) ^ (sec_r000645_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000645_1 << 2) ^ (sec_r000645_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_174 << 2) ^ (sec_r000645_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_134 << 1) ^ (sec_r000645_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_141 << 2) ^ (sec_r000645_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_173 << 2) ^ (sec_r000645_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r000645_11 << 1) ^ (sec_r000645_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r000645_11 << 1) ^ (sec_r000645_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_182 << 1) ^ (sec_r000645_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_135 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_186 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000645_8 << 1) ^ (sec_r000645_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000645_21 << 1) ^ (sec_r000645_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_135 << 2) ^ (sec_r000645_23 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r000645_3 << 2) ^ (sec_r000645_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_89 << 1) ^ (sec_r000645_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r000645_14 << 1) ^ (sec_r000645_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_124 << 2) ^ (sec_r000645_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_160 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r000645_20 << 2) ^ (sec_r000645_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000645_10 << 2) ^ (sec_r000645_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_196 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000645_7 << 2) ^ (sec_r000645_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((sec_r000645_20 << 2) ^ (sec_r000645_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r000645_22 << 2) ^ (sec_r000645_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_199 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((sec_r000645_16 << 1) ^ (sec_r000645_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_151 << 1) ^ (sec_r000645_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_201 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r000645_0 << 1) ^ (sec_r000645_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_202 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r000645_11 << 1) ^ (sec_r000645_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_203 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((sec_r000645_20 << 2) ^ (sec_r000645_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_204 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_91 << 1) ^ (sec_r000645_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_205 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_192 << 1) ^ (sec_r000645_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_206 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r000645_1 << 1) ^ (sec_r000645_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_207 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_146 << 2) ^ (sec_r000645_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_208 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_164 << 2) ^ (sec_r000645_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_101 << 2) ^ (sec_r000645_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_210 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_210 << 2) ^ (sec_r000645_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_211 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000645_15 << 2) ^ (sec_r000645_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_122 << 1) ^ (sec_r000645_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_213 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_123 << 2) ^ (sec_r000645_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_214 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_191 << 2) ^ (sec_r000645_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_215 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_93 << 1) ^ (sec_r000645_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_216 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r000645_3 << 1) ^ (sec_r000645_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_163 << 2) ^ (sec_r000645_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_218 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_130 << 1) ^ (sec_r000645_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((sec_r000645_22 << 1) ^ (sec_r000645_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_184 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_221 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_202 << 2) ^ (sec_r000645_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_222 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_178 << 2) ^ (sec_r000645_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_223 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((sec_r000645_21 << 1) ^ (sec_r000645_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_224 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_178 << 2) ^ (sec_r000645_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_225 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_203 << 2) ^ (sec_r000645_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_226 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000645_7 << 1) ^ (sec_r000645_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_227 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_204 << 2) ^ (sec_r000645_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_228 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_115 << 1) ^ (sec_r000645_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_229 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_146 << 1) ^ (sec_r000645_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_230 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_218 << 2) ^ (sec_r000645_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_231 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_231 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
