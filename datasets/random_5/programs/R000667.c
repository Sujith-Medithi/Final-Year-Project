/*
 * Benchmark Program: R000667
 * Security Family: nested_implicit_flow
 * Generator Seed: 566713
 * High Inputs: 22 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000667_6713_0 {
    unsigned char watermark;
    int state;
    int head;
    short tail;
    int buffer[3];
};

struct SensorNode_R000667_6713_1 {
    int offset;
    short status;
    int calib;
    int buffer[3];
};

struct DeviceConfig_R000667_6713_2 {
    int stop_bits;
    short baud_rate;
    short port;
    int buffer[3];
};

union PacketPayload_R000667_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000667_6713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000667_6713_0(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000667_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_18 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_18 > 16) {
        acc = (acc + accumulator_18 * 2 + 5) & 127;
        aux ^= (accumulator_18 & 15);
    } else {
        acc = (acc - accumulator_18 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int phase_56 = local_arr[aux % 3];
    acc = (acc + phase_56 * 2) & 127;
    int checksum_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_95) & 63;
    acc ^= aux;
    int quantum_91 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_91 > 39) {
        acc = (acc + quantum_91 * 2 + 5) & 127;
        aux ^= (quantum_91 & 15);
    } else {
        acc = (acc - quantum_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000667_6713_2(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int residue_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_73) & 63;
    acc ^= aux;
    int window_25 = (st.buffer[0] * 3 + aux) & 63;
    if (window_25 > 48) {
        acc = (acc + window_25 * 2 + 5) & 127;
        aux ^= (window_25 & 15);
    } else {
        acc = (acc - window_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000667_6713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000667_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int mask_70 = (aux + st.buffer[1]) & 3;
    switch (mask_70) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_14 = local_arr[aux % 3];
    acc = (acc + mask_14 * 2) & 127;
    int margin_74 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_74 > 42) {
        acc = (acc + margin_74 * 2 + 5) & 127;
        aux ^= (margin_74 & 15);
    } else {
        acc = (acc - margin_74 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_4(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int damping_72 = local_arr[aux % 3];
    acc = (acc + damping_72 * 2) & 127;
    int tracker_62 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_62 > 45) {
        acc = (acc + tracker_62 * 2 + 5) & 127;
        aux ^= (tracker_62 & 15);
    } else {
        acc = (acc - tracker_62 + 11) & 127;
        aux += 3;
    }
    int tracker_59 = (aux + st.buffer[1]) & 3;
    switch (tracker_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000667_6713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int cursor_88 = local_arr[aux % 3];
    acc = (acc + cursor_88 * 2) & 127;
    int phase_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_61 = local_arr[aux % 3];
    acc = (acc + parity_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int segment_93 = (aux + st.buffer[1]) & 3;
    switch (segment_93) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int phase_82 = local_arr[aux % 3];
    acc = (acc + phase_82 * 2) & 127;
    int quantum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_45) & 63;
    acc ^= aux;
    int threshold_92 = (aux + st.buffer[1]) & 3;
    switch (threshold_92) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_9(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int offset_25 = local_arr[aux % 3];
    acc = (acc + offset_25 * 2) & 127;
    int parity_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_42) & 63;
    acc ^= aux;
    int window_87 = (st.buffer[0] * 3 + aux) & 63;
    if (window_87 > 35) {
        acc = (acc + window_87 * 2 + 5) & 127;
        aux ^= (window_87 & 15);
    } else {
        acc = (acc - window_87 + 11) & 127;
        aux += 3;
    }
    int sample_61 = (aux + st.buffer[1]) & 3;
    switch (sample_61) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000667_6713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_47) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_83 = (aux + st.buffer[1]) & 3;
    switch (segment_83) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_68 > 32) {
        acc = (acc + cursor_68 * 2 + 5) & 127;
        aux ^= (cursor_68 & 15);
    } else {
        acc = (acc - cursor_68 + 11) & 127;
        aux += 3;
    }
    int phase_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000667_6713_12(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int vector_14 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_14 > 17) {
        acc = (acc + vector_14 * 2 + 5) & 127;
        aux ^= (vector_14 & 15);
    } else {
        acc = (acc - vector_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_93 = local_arr[aux % 3];
    acc = (acc + metric_93 * 2) & 127;
    int weight_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000667_6713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_43) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_27 = local_arr[aux % 3];
    acc = (acc + factor_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_13 = (aux + st.buffer[1]) & 3;
    switch (cursor_13) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000667_6713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000667_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_44 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_44 > 35) {
        acc = (acc + tally_44 * 2 + 5) & 127;
        aux ^= (tally_44 & 15);
    } else {
        acc = (acc - tally_44 + 11) & 127;
        aux += 3;
    }
    int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000667_6713_15(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int accumulator_91 = (aux + st.buffer[1]) & 3;
    switch (accumulator_91) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_56 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_56 > 28) {
        acc = (acc + phase_56 * 2 + 5) & 127;
        aux ^= (phase_56 & 15);
    } else {
        acc = (acc - phase_56 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_95 = local_arr[aux % 3];
    acc = (acc + quantum_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_16(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int scale_29 = local_arr[aux % 3];
    acc = (acc + scale_29 * 2) & 127;
    int margin_91 = (aux + st.buffer[1]) & 3;
    switch (margin_91) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_31 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_31 > 16) {
        acc = (acc + stride_31 * 2 + 5) & 127;
        aux ^= (stride_31 & 15);
    } else {
        acc = (acc - stride_31 + 11) & 127;
        aux += 3;
    }
    int parity_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000667_6713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_77 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_77 > 25) {
        acc = (acc + threshold_77 * 2 + 5) & 127;
        aux ^= (threshold_77 & 15);
    } else {
        acc = (acc - threshold_77 + 11) & 127;
        aux += 3;
    }
    int bound_59 = (aux + st.buffer[1]) & 3;
    switch (bound_59) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000667_6713_18(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_67) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_56 = local_arr[aux % 3];
    acc = (acc + checksum_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_19(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000667_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int bound_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_15 = (aux + st.buffer[1]) & 3;
    switch (anchor_15) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_58 = local_arr[aux % 3];
    acc = (acc + mask_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_20(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000667_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int pivot_68 = (aux + st.buffer[1]) & 3;
    switch (pivot_68) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_16) & 63;
    acc ^= aux;
    int quotient_98 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_98 > 10) {
        acc = (acc + quotient_98 * 2 + 5) & 127;
        aux ^= (quotient_98 & 15);
    } else {
        acc = (acc - quotient_98 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_21(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int threshold_35 = local_arr[aux % 3];
    acc = (acc + threshold_35 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000667_6713_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000667_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int metric_29 = (aux + st.buffer[1]) & 3;
    switch (metric_29) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_97 = local_arr[aux % 3];
    acc = (acc + bound_97 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000667_0;
    int sec_r000667_1;
    int sec_r000667_2;
    int sec_r000667_3;
    int sec_r000667_4;
    int sec_r000667_5;
    int sec_r000667_6;
    int sec_r000667_7;
    int sec_r000667_8;
    int sec_r000667_9;
    int sec_r000667_10;
    int sec_r000667_11;
    int sec_r000667_12;
    int sec_r000667_13;
    int sec_r000667_14;
    int sec_r000667_15;
    int sec_r000667_16;
    int sec_r000667_17;
    int sec_r000667_18;
    int sec_r000667_19;
    int sec_r000667_20;
    int sec_r000667_21;
    int pub_r000667_0;
    int pub_r000667_1;
    int pub_r000667_2;
    int pub_r000667_3;
    int pub_r000667_4;
    int pub_r000667_5;
    int pub_r000667_6;
    int pub_r000667_7;
    int pub_r000667_8;
    int pub_r000667_9;
    int pub_r000667_10;
    int pub_r000667_11;
    int pub_r000667_12;
    int pub_r000667_13;
    int pub_r000667_14;
    int pub_r000667_15;
    int pub_r000667_16;
    int pub_r000667_17;
    int pub_r000667_18;
    int pub_r000667_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000667_0 >= -100 && pub_r000667_0 <= 100);
    __CPROVER_assume(pub_r000667_1 >= -100 && pub_r000667_1 <= 100);
    __CPROVER_assume(pub_r000667_2 >= -100 && pub_r000667_2 <= 100);
    __CPROVER_assume(pub_r000667_3 >= -100 && pub_r000667_3 <= 100);
    __CPROVER_assume(pub_r000667_4 >= -100 && pub_r000667_4 <= 100);
    __CPROVER_assume(pub_r000667_5 >= -100 && pub_r000667_5 <= 100);
    __CPROVER_assume(pub_r000667_6 >= -100 && pub_r000667_6 <= 100);
    __CPROVER_assume(pub_r000667_7 >= -100 && pub_r000667_7 <= 100);
    __CPROVER_assume(pub_r000667_8 >= -100 && pub_r000667_8 <= 100);
    __CPROVER_assume(pub_r000667_9 >= -100 && pub_r000667_9 <= 100);
    __CPROVER_assume(pub_r000667_10 >= -100 && pub_r000667_10 <= 100);
    __CPROVER_assume(pub_r000667_11 >= -100 && pub_r000667_11 <= 100);
    __CPROVER_assume(pub_r000667_12 >= -100 && pub_r000667_12 <= 100);
    __CPROVER_assume(pub_r000667_13 >= -100 && pub_r000667_13 <= 100);
    __CPROVER_assume(pub_r000667_14 >= -100 && pub_r000667_14 <= 100);
    __CPROVER_assume(pub_r000667_15 >= -100 && pub_r000667_15 <= 100);
    __CPROVER_assume(pub_r000667_16 >= -100 && pub_r000667_16 <= 100);
    __CPROVER_assume(pub_r000667_17 >= -100 && pub_r000667_17 <= 100);
    __CPROVER_assume(pub_r000667_18 >= -100 && pub_r000667_18 <= 100);
    __CPROVER_assume(pub_r000667_19 >= -100 && pub_r000667_19 <= 100);
    __CPROVER_assume(sec_r000667_0 >= 0 && sec_r000667_0 <= 255);
    __CPROVER_assume(sec_r000667_1 >= 0 && sec_r000667_1 <= 255);
    __CPROVER_assume(sec_r000667_2 >= 0 && sec_r000667_2 <= 255);
    __CPROVER_assume(sec_r000667_3 >= 0 && sec_r000667_3 <= 255);
    __CPROVER_assume(sec_r000667_4 >= 0 && sec_r000667_4 <= 255);
    __CPROVER_assume(sec_r000667_5 >= 0 && sec_r000667_5 <= 255);
    __CPROVER_assume(sec_r000667_6 >= 0 && sec_r000667_6 <= 255);
    __CPROVER_assume(sec_r000667_7 >= 0 && sec_r000667_7 <= 255);
    __CPROVER_assume(sec_r000667_8 >= 0 && sec_r000667_8 <= 255);
    __CPROVER_assume(sec_r000667_9 >= 0 && sec_r000667_9 <= 255);
    __CPROVER_assume(sec_r000667_10 >= 0 && sec_r000667_10 <= 255);
    __CPROVER_assume(sec_r000667_11 >= 0 && sec_r000667_11 <= 255);
    __CPROVER_assume(sec_r000667_12 >= 0 && sec_r000667_12 <= 255);
    __CPROVER_assume(sec_r000667_13 >= 0 && sec_r000667_13 <= 255);
    __CPROVER_assume(sec_r000667_14 >= 0 && sec_r000667_14 <= 255);
    __CPROVER_assume(sec_r000667_15 >= 0 && sec_r000667_15 <= 255);
    __CPROVER_assume(sec_r000667_16 >= 0 && sec_r000667_16 <= 255);
    __CPROVER_assume(sec_r000667_17 >= 0 && sec_r000667_17 <= 255);
    __CPROVER_assume(sec_r000667_18 >= 0 && sec_r000667_18 <= 255);
    __CPROVER_assume(sec_r000667_19 >= 0 && sec_r000667_19 <= 255);
    __CPROVER_assume(sec_r000667_20 >= 0 && sec_r000667_20 <= 255);
    __CPROVER_assume(sec_r000667_21 >= 0 && sec_r000667_21 <= 255);

    struct StreamBuffer_R000667_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000667_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000667_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000667_0 + 7) & 15;
    struct SensorNode_R000667_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000667_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000667_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000667_0 + 9) & 15;
    struct DeviceConfig_R000667_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000667_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000667_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000667_0 + 11) & 15;

    union PacketPayload_R000667_6713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 35) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 50) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 33) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 48) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 10) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 25) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 32) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 47) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 28) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 43) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 17) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 32) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
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
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((sec_r000667_12 & 1) != 0) {
        if ((sec_r000667_3 & 2) != 0) {
            stage_v_35 = (pub_r000667_16 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000667_16 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000667_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000667_9 & 2) != 0) {
            stage_v_36 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((sec_r000667_17 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_37 = (pub_r000667_9 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000667_9 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000667_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000667_14 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_38 = (pub_r000667_18 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000667_18 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000667_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_39 = (pub_r000667_11 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000667_11 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000667_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_40 = (pub_r000667_13 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000667_13 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000667_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000667_2 & 2) != 0) {
            stage_v_41 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_42 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((sec_r000667_15 & 1) != 0) {
        if ((sec_r000667_10 & 2) != 0) {
            stage_v_43 = (pub_r000667_5 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000667_5 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000667_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000667_11 & 2) != 0) {
            stage_v_44 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000667_11 & 2) != 0) {
            stage_v_45 = (pub_r000667_15 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000667_15 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000667_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000667_15 & 2) != 0) {
            stage_v_46 = (pub_r000667_11 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000667_11 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000667_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000667_2 & 2) != 0) {
            stage_v_47 = (pub_r000667_3 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000667_3 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000667_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000667_11 & 2) != 0) {
            stage_v_48 = (pub_r000667_16 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000667_16 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000667_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000667_11 & 1) != 0) {
        if ((sec_r000667_16 & 2) != 0) {
            stage_v_49 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_50 = (pub_r000667_15 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000667_15 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000667_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000667_19 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_51 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000667_5 & 1) != 0) {
        if ((sec_r000667_15 & 2) != 0) {
            stage_v_52 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000667_18 & 2) != 0) {
            stage_v_53 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_54 = (pub_r000667_18 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000667_18 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000667_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_55 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000667_14 & 2) != 0) {
            stage_v_56 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_57 = (pub_r000667_5 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000667_5 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000667_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000667_3 & 2) != 0) {
            stage_v_58 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000667_9 & 2) != 0) {
            stage_v_59 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((sec_r000667_10 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_60 = (pub_r000667_11 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000667_11 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000667_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_61 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000667_8 & 2) != 0) {
            stage_v_62 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000667_14 & 2) != 0) {
            stage_v_63 = (pub_r000667_9 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000667_9 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000667_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000667_10 & 2) != 0) {
            stage_v_64 = (pub_r000667_0 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000667_0 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000667_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_65 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000667_12 & 2) != 0) {
            stage_v_66 = (pub_r000667_13 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000667_13 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000667_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000667_13 & 2) != 0) {
            stage_v_67 = (pub_r000667_13 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000667_13 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000667_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000667_1 & 1) != 0) {
        if ((sec_r000667_6 & 2) != 0) {
            stage_v_68 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000667_4 & 1) != 0) {
        if ((sec_r000667_21 & 2) != 0) {
            stage_v_69 = (pub_r000667_15 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000667_15 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000667_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000667_5 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_70 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_71 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000667_10 & 2) != 0) {
            stage_v_72 = (pub_r000667_11 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000667_11 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000667_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_73 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000667_14 & 2) != 0) {
            stage_v_74 = (pub_r000667_3 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000667_3 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000667_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000667_16 & 2) != 0) {
            stage_v_75 = (pub_r000667_2 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000667_2 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000667_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000667_8 & 1) != 0) {
        if ((sec_r000667_10 & 2) != 0) {
            stage_v_76 = (pub_r000667_10 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000667_10 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000667_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000667_21 & 1) != 0) {
        if ((sec_r000667_12 & 2) != 0) {
            stage_v_77 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000667_18 & 2) != 0) {
            stage_v_78 = (pub_r000667_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000667_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000667_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000667_2 & 1) != 0) {
        if ((sec_r000667_10 & 2) != 0) {
            stage_v_79 = (pub_r000667_16 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000667_16 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000667_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_80 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_81 = (pub_r000667_9 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000667_9 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000667_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000667_13 & 2) != 0) {
            stage_v_82 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000667_7 & 1) != 0) {
        if ((sec_r000667_2 & 2) != 0) {
            stage_v_83 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000667_13 & 1) != 0) {
        if ((sec_r000667_15 & 2) != 0) {
            stage_v_84 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000667_1 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_85 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000667_11 & 2) != 0) {
            stage_v_86 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_87 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000667_7 & 2) != 0) {
            stage_v_88 = (pub_r000667_2 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000667_2 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000667_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000667_12 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_89 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000667_13 & 1) != 0) {
        if ((sec_r000667_9 & 2) != 0) {
            stage_v_90 = (pub_r000667_18 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000667_18 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000667_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000667_16 & 1) != 0) {
        if ((sec_r000667_15 & 2) != 0) {
            stage_v_91 = (pub_r000667_3 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000667_3 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000667_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_92 = (pub_r000667_15 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000667_15 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000667_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000667_11 & 1) != 0) {
        if ((sec_r000667_7 & 2) != 0) {
            stage_v_93 = (pub_r000667_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000667_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000667_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000667_13 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_94 = (pub_r000667_8 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000667_8 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000667_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000667_4 & 1) != 0) {
        if ((sec_r000667_21 & 2) != 0) {
            stage_v_95 = (pub_r000667_9 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000667_9 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000667_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000667_16 & 1) != 0) {
        if ((sec_r000667_3 & 2) != 0) {
            stage_v_96 = (pub_r000667_2 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000667_2 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000667_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000667_13 & 1) != 0) {
        if ((sec_r000667_18 & 2) != 0) {
            stage_v_97 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000667_4 & 2) != 0) {
            stage_v_98 = (pub_r000667_5 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000667_5 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000667_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000667_10 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_99 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000667_6 & 1) != 0) {
        if ((sec_r000667_11 & 2) != 0) {
            stage_v_100 = (pub_r000667_13 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000667_13 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000667_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000667_14 & 2) != 0) {
            stage_v_101 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000667_3 & 2) != 0) {
            stage_v_102 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000667_3 & 2) != 0) {
            stage_v_103 = (pub_r000667_11 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000667_11 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000667_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000667_21 & 2) != 0) {
            stage_v_104 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000667_15 & 2) != 0) {
            stage_v_105 = (pub_r000667_9 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000667_9 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000667_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_106 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_107 = (pub_r000667_10 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000667_10 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000667_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000667_21 & 2) != 0) {
            stage_v_108 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000667_9 & 1) != 0) {
        if ((sec_r000667_20 & 2) != 0) {
            stage_v_109 = (pub_r000667_17 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000667_17 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000667_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000667_6 & 2) != 0) {
            stage_v_110 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000667_2 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_111 = (pub_r000667_18 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000667_18 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000667_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000667_20 & 2) != 0) {
            stage_v_112 = (pub_r000667_9 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000667_9 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000667_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000667_18 & 1) != 0) {
        if ((sec_r000667_21 & 2) != 0) {
            stage_v_113 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000667_5 & 2) != 0) {
            stage_v_114 = (pub_r000667_15 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000667_15 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000667_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000667_8 & 2) != 0) {
            stage_v_115 = (pub_r000667_17 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000667_17 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000667_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_116 = (pub_r000667_2 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000667_2 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000667_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_117 = (pub_r000667_16 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000667_16 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000667_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000667_3 & 2) != 0) {
            stage_v_118 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_119 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000667_13 & 2) != 0) {
            stage_v_120 = (pub_r000667_18 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000667_18 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000667_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_121 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000667_2 & 2) != 0) {
            stage_v_122 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_123 = (pub_r000667_7 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000667_7 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000667_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000667_3 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_124 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_125 = (pub_r000667_19 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000667_19 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000667_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000667_17 & 1) != 0) {
        if ((sec_r000667_17 & 2) != 0) {
            stage_v_126 = (pub_r000667_4 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000667_4 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000667_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000667_21 & 2) != 0) {
            stage_v_127 = (pub_r000667_1 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000667_1 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000667_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000667_20 & 1) != 0) {
        if ((sec_r000667_1 & 2) != 0) {
            stage_v_128 = (pub_r000667_13 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000667_13 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000667_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000667_11 & 1) != 0) {
        if ((sec_r000667_13 & 2) != 0) {
            stage_v_129 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000667_14 & 2) != 0) {
            stage_v_130 = (pub_r000667_12 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000667_12 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000667_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000667_10 & 1) != 0) {
        if ((sec_r000667_0 & 2) != 0) {
            stage_v_131 = (pub_r000667_6 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000667_6 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000667_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000667_3 & 1) != 0) {
        if ((sec_r000667_20 & 2) != 0) {
            stage_v_132 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000667_16 & 2) != 0) {
            stage_v_133 = (pub_r000667_5 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000667_5 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000667_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000667_16 & 1) != 0) {
        if ((sec_r000667_5 & 2) != 0) {
            stage_v_134 = (pub_r000667_13 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000667_13 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000667_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000667_12 & 1) != 0) {
        if ((sec_r000667_19 & 2) != 0) {
            stage_v_135 = (pub_r000667_10 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000667_10 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000667_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000667_13 & 2) != 0) {
            stage_v_136 = (pub_r000667_14 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000667_14 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000667_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
