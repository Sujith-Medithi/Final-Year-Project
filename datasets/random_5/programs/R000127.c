/*
 * Benchmark Program: R000127
 * Security Family: nested_implicit_flow
 * Generator Seed: 512713
 * High Inputs: 21 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000127_2713_0 {
    short severity;
    unsigned char signature;
    short facility;
    int buffer[3];
};

struct DeviceConfig_R000127_2713_1 {
    int id;
    int port;
    short timeout;
    int baud_rate;
    int buffer[3];
};

struct FilterState_R000127_2713_2 {
    int damping;
    unsigned char prev_out;
    int gain_db;
    int buffer[3];
};

struct SensorNode_R000127_2713_3 {
    short threshold;
    short offset;
    short gain;
    int buffer[3];
};

union RegisterBank_R000127_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000127_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000127_2713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000127_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_95 = (aux + st.buffer[1]) & 3;
    switch (delta_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_25) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_97 = local_arr[aux % 3];
    acc = (acc + damping_97 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_1(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_76 = (aux + st.buffer[1]) & 3;
    switch (phase_76) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_71 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_71 > 25) {
        acc = (acc + accumulator_71 * 2 + 5) & 127;
        aux ^= (accumulator_71 & 15);
    } else {
        acc = (acc - accumulator_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000127_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_87 = (aux + st.buffer[1]) & 3;
    switch (segment_87) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_53 = local_arr[aux % 3];
    acc = (acc + index_reg_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_4(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000127_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int weight_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_5(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_89) & 63;
    acc ^= aux;
    int segment_48 = (aux + st.buffer[1]) & 3;
    switch (segment_48) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_22 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_22 > 49) {
        acc = (acc + checksum_22 * 2 + 5) & 127;
        aux ^= (checksum_22 & 15);
    } else {
        acc = (acc - checksum_22 + 11) & 127;
        aux += 3;
    }
    int scale_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000127_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_98 = local_arr[aux % 3];
    acc = (acc + accumulator_98 * 2) & 127;
    int phase_58 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_58 > 41) {
        acc = (acc + phase_58 * 2 + 5) & 127;
        aux ^= (phase_58 & 15);
    } else {
        acc = (acc - phase_58 + 11) & 127;
        aux += 3;
    }
    int anchor_79 = (aux + st.buffer[1]) & 3;
    switch (anchor_79) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_61 = local_arr[aux % 3];
    acc = (acc + scale_61 * 2) & 127;
    int index_reg_71 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_71 > 37) {
        acc = (acc + index_reg_71 * 2 + 5) & 127;
        aux ^= (index_reg_71 & 15);
    } else {
        acc = (acc - index_reg_71 + 11) & 127;
        aux += 3;
    }
    int tracker_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000127_2713_9(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int index_reg_83 = (aux + st.buffer[1]) & 3;
    switch (index_reg_83) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_75 = local_arr[aux % 3];
    acc = (acc + weight_75 * 2) & 127;
    int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000127_2713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_24 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_24 > 22) {
        acc = (acc + bound_24 * 2 + 5) & 127;
        aux ^= (bound_24 & 15);
    } else {
        acc = (acc - bound_24 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_91 = local_arr[aux % 3];
    acc = (acc + accumulator_91 * 2) & 127;
    int phase_68 = (aux + st.buffer[1]) & 3;
    switch (phase_68) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_11(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000127_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int index_reg_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_10) & 63;
    acc ^= aux;
    int vector_73 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_73 > 39) {
        acc = (acc + vector_73 * 2 + 5) & 127;
        aux ^= (vector_73 & 15);
    } else {
        acc = (acc - vector_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000127_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_67 = (aux + st.buffer[1]) & 3;
    switch (quotient_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_48) & 63;
    acc ^= aux;
    int accumulator_95 = (aux + st.buffer[1]) & 3;
    switch (accumulator_95) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_14(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000127_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int window_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_18) & 63;
    acc ^= aux;
    int residue_64 = (aux + st.buffer[1]) & 3;
    switch (residue_64) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_15(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_81 = (aux + st.buffer[1]) & 3;
    switch (delta_81) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_86 = local_arr[aux % 3];
    acc = (acc + sample_86 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int metric_33 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_33 > 46) {
        acc = (acc + metric_33 * 2 + 5) & 127;
        aux ^= (metric_33 & 15);
    } else {
        acc = (acc - metric_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_90 = local_arr[aux % 3];
    acc = (acc + quotient_90 * 2) & 127;
    int window_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000127_2713_17(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int segment_39 = (aux + st.buffer[1]) & 3;
    switch (segment_39) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_31 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_31 > 47) {
        acc = (acc + anchor_31 * 2 + 5) & 127;
        aux ^= (anchor_31 & 15);
    } else {
        acc = (acc - anchor_31 + 11) & 127;
        aux += 3;
    }
    int anchor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000127_2713_18(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int factor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_80) & 63;
    acc ^= aux;
    int margin_40 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_40 > 45) {
        acc = (acc + margin_40 * 2 + 5) & 127;
        aux ^= (margin_40 & 15);
    } else {
        acc = (acc - margin_40 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_19(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int cursor_24 = local_arr[aux % 3];
    acc = (acc + cursor_24 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_72 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_72 > 16) {
        acc = (acc + tracker_72 * 2 + 5) & 127;
        aux ^= (tracker_72 & 15);
    } else {
        acc = (acc - tracker_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000127_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_30 = local_arr[aux % 3];
    acc = (acc + tally_30 * 2) & 127;
    int vector_45 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_45 > 25) {
        acc = (acc + vector_45 * 2 + 5) & 127;
        aux ^= (vector_45 & 15);
    } else {
        acc = (acc - vector_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000127_2713_21(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000127_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int damping_24 = local_arr[aux % 3];
    acc = (acc + damping_24 * 2) & 127;
    int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_56) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000127_2713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000127_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int vector_69 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_69 > 24) {
        acc = (acc + vector_69 * 2 + 5) & 127;
        aux ^= (vector_69 & 15);
    } else {
        acc = (acc - vector_69 + 11) & 127;
        aux += 3;
    }
    int damping_55 = (aux + st.buffer[1]) & 3;
    switch (damping_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000127_0;
    int sec_r000127_1;
    int sec_r000127_2;
    int sec_r000127_3;
    int sec_r000127_4;
    int sec_r000127_5;
    int sec_r000127_6;
    int sec_r000127_7;
    int sec_r000127_8;
    int sec_r000127_9;
    int sec_r000127_10;
    int sec_r000127_11;
    int sec_r000127_12;
    int sec_r000127_13;
    int sec_r000127_14;
    int sec_r000127_15;
    int sec_r000127_16;
    int sec_r000127_17;
    int sec_r000127_18;
    int sec_r000127_19;
    int sec_r000127_20;
    int pub_r000127_0;
    int pub_r000127_1;
    int pub_r000127_2;
    int pub_r000127_3;
    int pub_r000127_4;
    int pub_r000127_5;
    int pub_r000127_6;
    int pub_r000127_7;
    int pub_r000127_8;
    int pub_r000127_9;
    int pub_r000127_10;
    int pub_r000127_11;
    int pub_r000127_12;
    int pub_r000127_13;
    int pub_r000127_14;
    int pub_r000127_15;
    int pub_r000127_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000127_0 >= -100 && pub_r000127_0 <= 100);
    __CPROVER_assume(pub_r000127_1 >= -100 && pub_r000127_1 <= 100);
    __CPROVER_assume(pub_r000127_2 >= -100 && pub_r000127_2 <= 100);
    __CPROVER_assume(pub_r000127_3 >= -100 && pub_r000127_3 <= 100);
    __CPROVER_assume(pub_r000127_4 >= -100 && pub_r000127_4 <= 100);
    __CPROVER_assume(pub_r000127_5 >= -100 && pub_r000127_5 <= 100);
    __CPROVER_assume(pub_r000127_6 >= -100 && pub_r000127_6 <= 100);
    __CPROVER_assume(pub_r000127_7 >= -100 && pub_r000127_7 <= 100);
    __CPROVER_assume(pub_r000127_8 >= -100 && pub_r000127_8 <= 100);
    __CPROVER_assume(pub_r000127_9 >= -100 && pub_r000127_9 <= 100);
    __CPROVER_assume(pub_r000127_10 >= -100 && pub_r000127_10 <= 100);
    __CPROVER_assume(pub_r000127_11 >= -100 && pub_r000127_11 <= 100);
    __CPROVER_assume(pub_r000127_12 >= -100 && pub_r000127_12 <= 100);
    __CPROVER_assume(pub_r000127_13 >= -100 && pub_r000127_13 <= 100);
    __CPROVER_assume(pub_r000127_14 >= -100 && pub_r000127_14 <= 100);
    __CPROVER_assume(pub_r000127_15 >= -100 && pub_r000127_15 <= 100);
    __CPROVER_assume(pub_r000127_16 >= -100 && pub_r000127_16 <= 100);
    __CPROVER_assume(sec_r000127_0 >= 0 && sec_r000127_0 <= 255);
    __CPROVER_assume(sec_r000127_1 >= 0 && sec_r000127_1 <= 255);
    __CPROVER_assume(sec_r000127_2 >= 0 && sec_r000127_2 <= 255);
    __CPROVER_assume(sec_r000127_3 >= 0 && sec_r000127_3 <= 255);
    __CPROVER_assume(sec_r000127_4 >= 0 && sec_r000127_4 <= 255);
    __CPROVER_assume(sec_r000127_5 >= 0 && sec_r000127_5 <= 255);
    __CPROVER_assume(sec_r000127_6 >= 0 && sec_r000127_6 <= 255);
    __CPROVER_assume(sec_r000127_7 >= 0 && sec_r000127_7 <= 255);
    __CPROVER_assume(sec_r000127_8 >= 0 && sec_r000127_8 <= 255);
    __CPROVER_assume(sec_r000127_9 >= 0 && sec_r000127_9 <= 255);
    __CPROVER_assume(sec_r000127_10 >= 0 && sec_r000127_10 <= 255);
    __CPROVER_assume(sec_r000127_11 >= 0 && sec_r000127_11 <= 255);
    __CPROVER_assume(sec_r000127_12 >= 0 && sec_r000127_12 <= 255);
    __CPROVER_assume(sec_r000127_13 >= 0 && sec_r000127_13 <= 255);
    __CPROVER_assume(sec_r000127_14 >= 0 && sec_r000127_14 <= 255);
    __CPROVER_assume(sec_r000127_15 >= 0 && sec_r000127_15 <= 255);
    __CPROVER_assume(sec_r000127_16 >= 0 && sec_r000127_16 <= 255);
    __CPROVER_assume(sec_r000127_17 >= 0 && sec_r000127_17 <= 255);
    __CPROVER_assume(sec_r000127_18 >= 0 && sec_r000127_18 <= 255);
    __CPROVER_assume(sec_r000127_19 >= 0 && sec_r000127_19 <= 255);
    __CPROVER_assume(sec_r000127_20 >= 0 && sec_r000127_20 <= 255);

    struct EventLog_R000127_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000127_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000127_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000127_0 + 7) & 15;
    struct DeviceConfig_R000127_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000127_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000127_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000127_0 + 9) & 15;
    struct FilterState_R000127_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000127_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000127_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000127_0 + 11) & 15;
    struct SensorNode_R000127_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000127_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000127_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000127_0 + 13) & 15;

    union RegisterBank_R000127_2713_0 u_var;
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
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 17) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 32) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 21) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 36) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 36) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 51) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 18) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 33) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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
    int stage_v_23 = (st_var_3.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 36) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 51) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 13) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 28) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 27) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 42) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 31) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 46) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 15) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 30) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 32) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 47) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000127_2 & 1) != 0) {
        if ((sec_r000127_15 & 2) != 0) {
            stage_v_49 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000127_16 & 2) != 0) {
            stage_v_50 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000127_18 & 2) != 0) {
            stage_v_51 = (pub_r000127_0 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000127_0 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000127_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000127_4 & 2) != 0) {
            stage_v_52 = (pub_r000127_15 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000127_15 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000127_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000127_12 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_53 = (pub_r000127_12 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000127_12 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000127_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000127_15 & 1) != 0) {
        if ((sec_r000127_2 & 2) != 0) {
            stage_v_54 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000127_1 & 1) != 0) {
        if ((sec_r000127_17 & 2) != 0) {
            stage_v_55 = (pub_r000127_9 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000127_9 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000127_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000127_1 & 2) != 0) {
            stage_v_56 = (pub_r000127_9 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000127_9 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000127_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000127_20 & 1) != 0) {
        if ((sec_r000127_2 & 2) != 0) {
            stage_v_57 = (pub_r000127_15 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000127_15 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000127_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000127_3 & 1) != 0) {
        if ((sec_r000127_0 & 2) != 0) {
            stage_v_58 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000127_6 & 1) != 0) {
        if ((sec_r000127_13 & 2) != 0) {
            stage_v_59 = (pub_r000127_5 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000127_5 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000127_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000127_2 & 2) != 0) {
            stage_v_60 = (pub_r000127_9 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000127_9 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000127_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000127_17 & 2) != 0) {
            stage_v_61 = (pub_r000127_13 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000127_13 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000127_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000127_12 & 2) != 0) {
            stage_v_62 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000127_20 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_63 = (pub_r000127_14 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000127_14 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000127_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000127_9 & 2) != 0) {
            stage_v_64 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000127_6 & 1) != 0) {
        if ((sec_r000127_13 & 2) != 0) {
            stage_v_65 = (pub_r000127_7 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000127_7 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000127_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000127_16 & 2) != 0) {
            stage_v_66 = (pub_r000127_16 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000127_16 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000127_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000127_8 & 2) != 0) {
            stage_v_67 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000127_5 & 2) != 0) {
            stage_v_68 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000127_2 & 1) != 0) {
        if ((sec_r000127_14 & 2) != 0) {
            stage_v_69 = (pub_r000127_0 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000127_0 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000127_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000127_4 & 2) != 0) {
            stage_v_70 = (pub_r000127_10 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000127_10 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000127_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000127_15 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_71 = (pub_r000127_0 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000127_0 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000127_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000127_5 & 2) != 0) {
            stage_v_72 = (pub_r000127_5 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000127_5 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000127_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000127_1 & 2) != 0) {
            stage_v_73 = (pub_r000127_10 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000127_10 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000127_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000127_3 & 1) != 0) {
        if ((sec_r000127_12 & 2) != 0) {
            stage_v_74 = (pub_r000127_2 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000127_2 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000127_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000127_0 & 1) != 0) {
        if ((sec_r000127_14 & 2) != 0) {
            stage_v_75 = (pub_r000127_14 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000127_14 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000127_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000127_9 & 1) != 0) {
        if ((sec_r000127_4 & 2) != 0) {
            stage_v_76 = (pub_r000127_3 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000127_3 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000127_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000127_6 & 1) != 0) {
        if ((sec_r000127_1 & 2) != 0) {
            stage_v_77 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000127_0 & 2) != 0) {
            stage_v_78 = (pub_r000127_15 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000127_15 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000127_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000127_4 & 2) != 0) {
            stage_v_79 = (pub_r000127_4 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000127_4 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000127_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000127_1 & 1) != 0) {
        if ((sec_r000127_15 & 2) != 0) {
            stage_v_80 = (pub_r000127_13 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000127_13 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000127_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000127_18 & 2) != 0) {
            stage_v_81 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000127_6 & 2) != 0) {
            stage_v_82 = (pub_r000127_7 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000127_7 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000127_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000127_10 & 1) != 0) {
        if ((sec_r000127_0 & 2) != 0) {
            stage_v_83 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_84 = (pub_r000127_13 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000127_13 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000127_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000127_7 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_85 = (pub_r000127_16 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000127_16 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000127_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000127_19 & 2) != 0) {
            stage_v_86 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_87 = (pub_r000127_5 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000127_5 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000127_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000127_19 & 1) != 0) {
        if ((sec_r000127_7 & 2) != 0) {
            stage_v_88 = (pub_r000127_4 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000127_4 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000127_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000127_10 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_89 = (pub_r000127_14 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000127_14 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000127_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_90 = (pub_r000127_10 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000127_10 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000127_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000127_6 & 1) != 0) {
        if ((sec_r000127_10 & 2) != 0) {
            stage_v_91 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000127_17 & 2) != 0) {
            stage_v_92 = (pub_r000127_3 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000127_3 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000127_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000127_10 & 2) != 0) {
            stage_v_93 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000127_17 & 2) != 0) {
            stage_v_94 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000127_6 & 1) != 0) {
        if ((sec_r000127_20 & 2) != 0) {
            stage_v_95 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000127_5 & 1) != 0) {
        if ((sec_r000127_2 & 2) != 0) {
            stage_v_96 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000127_8 & 2) != 0) {
            stage_v_97 = (pub_r000127_4 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000127_4 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000127_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000127_12 & 1) != 0) {
        if ((sec_r000127_6 & 2) != 0) {
            stage_v_98 = (pub_r000127_12 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000127_12 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000127_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000127_1 & 2) != 0) {
            stage_v_99 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_100 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000127_7 & 2) != 0) {
            stage_v_101 = (pub_r000127_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000127_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000127_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000127_20 & 2) != 0) {
            stage_v_102 = (pub_r000127_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000127_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000127_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000127_12 & 1) != 0) {
        if ((sec_r000127_8 & 2) != 0) {
            stage_v_103 = (pub_r000127_16 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000127_16 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000127_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000127_5 & 2) != 0) {
            stage_v_104 = (pub_r000127_2 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000127_2 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000127_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000127_9 & 1) != 0) {
        if ((sec_r000127_13 & 2) != 0) {
            stage_v_105 = (pub_r000127_0 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000127_0 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000127_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000127_20 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_106 = (pub_r000127_1 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000127_1 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000127_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000127_13 & 2) != 0) {
            stage_v_107 = (pub_r000127_3 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000127_3 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000127_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000127_6 & 2) != 0) {
            stage_v_108 = (pub_r000127_13 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000127_13 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000127_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000127_0 & 2) != 0) {
            stage_v_109 = (pub_r000127_2 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000127_2 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000127_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000127_6 & 2) != 0) {
            stage_v_110 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000127_7 & 1) != 0) {
        if ((sec_r000127_9 & 2) != 0) {
            stage_v_111 = (pub_r000127_16 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000127_16 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000127_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000127_17 & 1) != 0) {
        if ((sec_r000127_12 & 2) != 0) {
            stage_v_112 = (pub_r000127_13 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000127_13 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000127_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000127_8 & 1) != 0) {
        if ((sec_r000127_12 & 2) != 0) {
            stage_v_113 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000127_12 & 1) != 0) {
        if ((sec_r000127_6 & 2) != 0) {
            stage_v_114 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000127_16 & 2) != 0) {
            stage_v_115 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000127_12 & 2) != 0) {
            stage_v_116 = (pub_r000127_2 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000127_2 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000127_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000127_16 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_117 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000127_5 & 2) != 0) {
            stage_v_118 = (pub_r000127_3 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000127_3 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000127_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000127_18 & 2) != 0) {
            stage_v_119 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000127_2 & 2) != 0) {
            stage_v_120 = (pub_r000127_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000127_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000127_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000127_9 & 2) != 0) {
            stage_v_121 = (pub_r000127_10 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000127_10 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000127_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((sec_r000127_8 & 1) != 0) {
        if ((sec_r000127_15 & 2) != 0) {
            stage_v_122 = (pub_r000127_9 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000127_9 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000127_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000127_9 & 2) != 0) {
            stage_v_123 = (pub_r000127_14 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000127_14 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000127_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000127_1 & 1) != 0) {
        if ((sec_r000127_10 & 2) != 0) {
            stage_v_124 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000127_18 & 1) != 0) {
        if ((sec_r000127_1 & 2) != 0) {
            stage_v_125 = (pub_r000127_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000127_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000127_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000127_3 & 1) != 0) {
        if ((sec_r000127_12 & 2) != 0) {
            stage_v_126 = (pub_r000127_0 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000127_0 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000127_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000127_14 & 1) != 0) {
        if ((sec_r000127_11 & 2) != 0) {
            stage_v_127 = (pub_r000127_10 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000127_10 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000127_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000127_5 & 2) != 0) {
            stage_v_128 = (pub_r000127_7 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000127_7 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000127_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000127_4 & 1) != 0) {
        if ((sec_r000127_13 & 2) != 0) {
            stage_v_129 = (pub_r000127_9 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000127_9 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000127_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000127_3 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_130 = (pub_r000127_14 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000127_14 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000127_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000127_15 & 2) != 0) {
            stage_v_131 = (pub_r000127_2 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000127_2 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000127_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000127_3 & 2) != 0) {
            stage_v_132 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000127_17 & 1) != 0) {
        if ((sec_r000127_7 & 2) != 0) {
            stage_v_133 = (pub_r000127_13 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000127_13 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000127_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000127_15 & 2) != 0) {
            stage_v_134 = (pub_r000127_8 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000127_8 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000127_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
