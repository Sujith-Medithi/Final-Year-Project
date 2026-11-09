/*
 * Benchmark Program: R001400
 * Security Family: mixed_control_data
 * Generator Seed: 640013
 * High Inputs: 17 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001400_13_0 {
    short code;
    int severity;
    int facility;
    int buffer[3];
};

struct SensorNode_R001400_13_1 {
    short reading;
    short calib;
    short offset;
    short threshold;
    int gain;
    int status;
    int buffer[3];
};

struct DeviceConfig_R001400_13_2 {
    int timeout;
    int port;
    short baud_rate;
    int parity;
    int id;
    unsigned char stop_bits;
    int buffer[3];
};

struct FilterState_R001400_13_3 {
    int prev_out;
    unsigned char gain_db;
    int cutoff;
    int buffer[3];
};

union ColorPixel_R001400_13_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001400_13_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001400_13_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001400_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int delta_51 = local_arr[aux % 3];
    acc = (acc + delta_51 * 2) & 127;
    int damping_49 = (aux + st.buffer[1]) & 3;
    switch (damping_49) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_19 = 0;
    for (int k = 0; k < 3; k++) {
        residue_19 = (residue_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_19) & 127;
    }
    int segment_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001400_13_1(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001400_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_36) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_2(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001400_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_17 = 0;
    for (int k = 0; k < 3; k++) {
        margin_17 = (margin_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_17) & 127;
    }
    int parity_46 = (aux + st.buffer[1]) & 3;
    switch (parity_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_3(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001400_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int damping_64 = (aux + st.buffer[1]) & 3;
    switch (damping_64) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_11 = local_arr[aux % 3];
    acc = (acc + phase_11 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_4(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001400_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_79 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_79 > 22) {
        acc = (acc + parity_79 * 2 + 5) & 127;
        aux ^= (parity_79 & 15);
    } else {
        acc = (acc - parity_79 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_67 = local_arr[aux % 3];
    acc = (acc + factor_67 * 2) & 127;
    int mask_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001400_13_5(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001400_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int vector_31 = 0;
    for (int k = 0; k < 2; k++) {
        vector_31 = (vector_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_31) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_35 = (aux + st.buffer[1]) & 3;
    switch (checksum_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_6(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001400_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int offset_74 = 0;
    for (int k = 0; k < 3; k++) {
        offset_74 = (offset_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_74) & 127;
    }
    int offset_78 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_78 > 24) {
        acc = (acc + offset_78 * 2 + 5) & 127;
        aux ^= (offset_78 & 15);
    } else {
        acc = (acc - offset_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001400_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int pivot_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_16) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int delta_21 = local_arr[aux % 3];
    acc = (acc + delta_21 * 2) & 127;
    int vector_84 = (aux + st.buffer[1]) & 3;
    switch (vector_84) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001400_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_23 = (aux + st.buffer[1]) & 3;
    switch (window_23) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_67 = local_arr[aux % 3];
    acc = (acc + checksum_67 * 2) & 127;
    int delta_88 = 0;
    for (int k = 0; k < 2; k++) {
        delta_88 = (delta_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_88) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_9(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001400_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int pivot_46 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_46 > 26) {
        acc = (acc + pivot_46 * 2 + 5) & 127;
        aux ^= (pivot_46 & 15);
    } else {
        acc = (acc - pivot_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_87 = local_arr[aux % 3];
    acc = (acc + margin_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_10(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001400_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_81 = (aux + st.buffer[1]) & 3;
    switch (accumulator_81) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_47 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_47 = (checksum_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_47) & 127;
    }
    int cursor_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_65) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001400_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int pivot_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_48) & 63;
    acc ^= aux;
    int segment_25 = (aux + st.buffer[1]) & 3;
    switch (segment_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_95 = local_arr[aux % 3];
    acc = (acc + parity_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001400_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_26 = (aux + st.buffer[1]) & 3;
    switch (sample_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_79) & 63;
    acc ^= aux;
    int phase_96 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_96 > 30) {
        acc = (acc + phase_96 * 2 + 5) & 127;
        aux ^= (phase_96 & 15);
    } else {
        acc = (acc - phase_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_13(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001400_13_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int cursor_57 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_57 = (cursor_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_57) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_20 = local_arr[aux % 3];
    acc = (acc + threshold_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_14(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001400_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tracker_24 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_24 > 14) {
        acc = (acc + tracker_24 * 2 + 5) & 127;
        aux ^= (tracker_24 & 15);
    } else {
        acc = (acc - tracker_24 + 11) & 127;
        aux += 3;
    }
    int anchor_41 = (aux + st.buffer[1]) & 3;
    switch (anchor_41) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_15(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001400_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int metric_43 = local_arr[aux % 3];
    acc = (acc + metric_43 * 2) & 127;
    int weight_95 = (aux + st.buffer[1]) & 3;
    switch (weight_95) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_47) & 63;
    acc ^= aux;
    int damping_45 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_45 > 16) {
        acc = (acc + damping_45 * 2 + 5) & 127;
        aux ^= (damping_45 & 15);
    } else {
        acc = (acc - damping_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001400_13_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_77 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_77 > 19) {
        acc = (acc + coefficient_77 * 2 + 5) & 127;
        aux ^= (coefficient_77 & 15);
    } else {
        acc = (acc - coefficient_77 + 11) & 127;
        aux += 3;
    }
    int sample_90 = (aux + st.buffer[1]) & 3;
    switch (sample_90) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001400_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_17 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_17 > 38) {
        acc = (acc + pivot_17 * 2 + 5) & 127;
        aux ^= (pivot_17 & 15);
    } else {
        acc = (acc - pivot_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_86 = local_arr[aux % 3];
    acc = (acc + weight_86 * 2) & 127;
    int delta_50 = 0;
    for (int k = 0; k < 2; k++) {
        delta_50 = (delta_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001400_13_18(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001400_13_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_40) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001400_13_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001400_13_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int bound_58 = 0;
    for (int k = 0; k < 2; k++) {
        bound_58 = (bound_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_58) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_94 = local_arr[aux % 3];
    acc = (acc + tracker_94 * 2) & 127;
    int quotient_98 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_98 > 31) {
        acc = (acc + quotient_98 * 2 + 5) & 127;
        aux ^= (quotient_98 & 15);
    } else {
        acc = (acc - quotient_98 + 11) & 127;
        aux += 3;
    }
    int cursor_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001400_0;
    int sec_r001400_1;
    int sec_r001400_2;
    int sec_r001400_3;
    int sec_r001400_4;
    int sec_r001400_5;
    int sec_r001400_6;
    int sec_r001400_7;
    int sec_r001400_8;
    int sec_r001400_9;
    int sec_r001400_10;
    int sec_r001400_11;
    int sec_r001400_12;
    int sec_r001400_13;
    int sec_r001400_14;
    int sec_r001400_15;
    int sec_r001400_16;
    int pub_r001400_0;
    int pub_r001400_1;
    int pub_r001400_2;
    int pub_r001400_3;
    int pub_r001400_4;
    int pub_r001400_5;
    int pub_r001400_6;
    int pub_r001400_7;
    int pub_r001400_8;
    int pub_r001400_9;
    int pub_r001400_10;
    int pub_r001400_11;
    int pub_r001400_12;
    int pub_r001400_13;
    int pub_r001400_14;
    int pub_r001400_15;
    int pub_r001400_16;
    int pub_r001400_17;
    int pub_r001400_18;
    int pub_r001400_19;
    int pub_r001400_20;
    int pub_r001400_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001400_0 >= -100 && pub_r001400_0 <= 100);
    __CPROVER_assume(pub_r001400_1 >= -100 && pub_r001400_1 <= 100);
    __CPROVER_assume(pub_r001400_2 >= -100 && pub_r001400_2 <= 100);
    __CPROVER_assume(pub_r001400_3 >= -100 && pub_r001400_3 <= 100);
    __CPROVER_assume(pub_r001400_4 >= -100 && pub_r001400_4 <= 100);
    __CPROVER_assume(pub_r001400_5 >= -100 && pub_r001400_5 <= 100);
    __CPROVER_assume(pub_r001400_6 >= -100 && pub_r001400_6 <= 100);
    __CPROVER_assume(pub_r001400_7 >= -100 && pub_r001400_7 <= 100);
    __CPROVER_assume(pub_r001400_8 >= -100 && pub_r001400_8 <= 100);
    __CPROVER_assume(pub_r001400_9 >= -100 && pub_r001400_9 <= 100);
    __CPROVER_assume(pub_r001400_10 >= -100 && pub_r001400_10 <= 100);
    __CPROVER_assume(pub_r001400_11 >= -100 && pub_r001400_11 <= 100);
    __CPROVER_assume(pub_r001400_12 >= -100 && pub_r001400_12 <= 100);
    __CPROVER_assume(pub_r001400_13 >= -100 && pub_r001400_13 <= 100);
    __CPROVER_assume(pub_r001400_14 >= -100 && pub_r001400_14 <= 100);
    __CPROVER_assume(pub_r001400_15 >= -100 && pub_r001400_15 <= 100);
    __CPROVER_assume(pub_r001400_16 >= -100 && pub_r001400_16 <= 100);
    __CPROVER_assume(pub_r001400_17 >= -100 && pub_r001400_17 <= 100);
    __CPROVER_assume(pub_r001400_18 >= -100 && pub_r001400_18 <= 100);
    __CPROVER_assume(pub_r001400_19 >= -100 && pub_r001400_19 <= 100);
    __CPROVER_assume(pub_r001400_20 >= -100 && pub_r001400_20 <= 100);
    __CPROVER_assume(pub_r001400_21 >= -100 && pub_r001400_21 <= 100);
    __CPROVER_assume(sec_r001400_0 >= 0 && sec_r001400_0 <= 255);
    __CPROVER_assume(sec_r001400_1 >= 0 && sec_r001400_1 <= 255);
    __CPROVER_assume(sec_r001400_2 >= 0 && sec_r001400_2 <= 255);
    __CPROVER_assume(sec_r001400_3 >= 0 && sec_r001400_3 <= 255);
    __CPROVER_assume(sec_r001400_4 >= 0 && sec_r001400_4 <= 255);
    __CPROVER_assume(sec_r001400_5 >= 0 && sec_r001400_5 <= 255);
    __CPROVER_assume(sec_r001400_6 >= 0 && sec_r001400_6 <= 255);
    __CPROVER_assume(sec_r001400_7 >= 0 && sec_r001400_7 <= 255);
    __CPROVER_assume(sec_r001400_8 >= 0 && sec_r001400_8 <= 255);
    __CPROVER_assume(sec_r001400_9 >= 0 && sec_r001400_9 <= 255);
    __CPROVER_assume(sec_r001400_10 >= 0 && sec_r001400_10 <= 255);
    __CPROVER_assume(sec_r001400_11 >= 0 && sec_r001400_11 <= 255);
    __CPROVER_assume(sec_r001400_12 >= 0 && sec_r001400_12 <= 255);
    __CPROVER_assume(sec_r001400_13 >= 0 && sec_r001400_13 <= 255);
    __CPROVER_assume(sec_r001400_14 >= 0 && sec_r001400_14 <= 255);
    __CPROVER_assume(sec_r001400_15 >= 0 && sec_r001400_15 <= 255);
    __CPROVER_assume(sec_r001400_16 >= 0 && sec_r001400_16 <= 255);

    struct EventLog_R001400_13_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001400_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001400_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001400_0 + 7) & 15;
    struct SensorNode_R001400_13_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001400_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001400_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001400_0 + 9) & 15;
    struct DeviceConfig_R001400_13_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001400_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001400_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001400_0 + 11) & 15;
    struct FilterState_R001400_13_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001400_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001400_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001400_0 + 13) & 15;

    union ColorPixel_R001400_13_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001400_13_0(sec_r001400_0, pub_r001400_1, pub_r001400_2, pub_r001400_3, pub_r001400_4);
    int helper_flow_1 = fn_R001400_13_1(sec_r001400_1, pub_r001400_2);
    int helper_flow_2 = fn_R001400_13_2(sec_r001400_2, pub_r001400_3, pub_r001400_4);
    int helper_flow_3 = fn_R001400_13_3(sec_r001400_3, sec_r001400_4);
    int helper_flow_4 = fn_R001400_13_4(sec_r001400_4, pub_r001400_5);
    int helper_flow_5 = fn_R001400_13_5(sec_r001400_5, sec_r001400_6, pub_r001400_7);
    int helper_flow_6 = fn_R001400_13_6(sec_r001400_6, sec_r001400_7, pub_r001400_8);
    int helper_flow_7 = fn_R001400_13_7(sec_r001400_7, sec_r001400_8, pub_r001400_9, pub_r001400_10, pub_r001400_11);
    int helper_flow_8 = fn_R001400_13_8(sec_r001400_8, sec_r001400_9, pub_r001400_10, pub_r001400_11);
    int helper_flow_9 = fn_R001400_13_9(sec_r001400_9, pub_r001400_10);
    int helper_flow_10 = fn_R001400_13_10(sec_r001400_10, sec_r001400_11, pub_r001400_12);
    int helper_flow_11 = fn_R001400_13_11(sec_r001400_11, sec_r001400_12, pub_r001400_13, pub_r001400_14);
    int helper_flow_12 = fn_R001400_13_12(sec_r001400_12, sec_r001400_13, pub_r001400_14, pub_r001400_15, pub_r001400_16);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_0 > 42) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001400_3 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_1 > 48) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001400_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001400_12) & 127;
    if (stage_v_3 > 36) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_4 > 28) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_5 > 33) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_6 > 49) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001400_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_8 > 29) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001400_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001400_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_11 > 33) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_12 > 37) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_13 > 49) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001400_7) & 127;
    if (stage_v_14 > 35) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_15 > 50) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_16 > 20) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001400_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_18 > 29) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001400_9 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_19 > 20) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001400_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_21 > 48) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_22 > 22) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_23 > 31) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001400_11 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_24 > 49) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_25 > 25) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001400_7) & 127;
    if (stage_v_26 > 50) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_27 > 29) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001400_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_29 > 46) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001400_1 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_30 > 22) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001400_12) & 127;
    if (stage_v_31 > 23) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001400_0 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_32 > 21) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_33 > 22) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_34 > 21) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001400_3 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_35 > 31) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_36 > 41) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_37 > 28) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001400_8) & 127;
    if (stage_v_38 > 43) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_39 > 21) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001400_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001400_0 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_41 > 43) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_42 > 50) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001400_0 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_43 > 27) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_44 > 43) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001400_1 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_45 > 47) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_46 > 41) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_47 > 43) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001400_4 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_48 > 27) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_49 > 28) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001400_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_51 > 46) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_52 > 41) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001400_8 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_53 > 38) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_54 > 41) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001400_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001400_20 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_57 > 23) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_58 > 26) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_59 > 49) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001400_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001400_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001400_13 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_62 > 40) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001400_21 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_64 > 37) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001400_3 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_65 > 49) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001400_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001400_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_68 > 25) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_69 > 26) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_70 > 40) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001400_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_72 > 33) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_73 > 31) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_74 > 30) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001400_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001400_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_77 > 40) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001400_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_79 > 34) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r001400_5 ^ 0x2A) * 2 + pub_r001400_7) & 127;
    if (stage_v_80 > 35) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001400_7) & 127;
    if (stage_v_81 > 41) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_82 > 20) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001400_14 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001400_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_85 > 30) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001400_2 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_86 > 46) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_87 > 29) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_88 > 38) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001400_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001400_13 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_90 > 32) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_91 > 46) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r001400_1 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_92 > 43) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_93 > 33) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001400_3 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_94 > 43) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001400_10 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_95 > 37) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_96 > 36) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_97 > 25) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_98 > 46) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_99 > 30) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_100 > 48) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_101 > 39) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001400_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_103 > 38) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_104 > 29) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_105 > 38) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001400_8) & 127;
    if (stage_v_106 > 30) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r001400_6 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_107 > 29) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001400_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001400_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001400_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001400_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_113 > 33) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001400_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_115 > 45) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_116 > 46) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_117 > 23) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001400_20 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_119 > 23) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_120 > 45) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_121 > 25) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001400_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001400_12) & 127;
    if (stage_v_123 > 25) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_124 > 24) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001400_20 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_126 > 34) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_127 > 43) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_128 > 31) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_129 > 29) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001400_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_131 > 50) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001400_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_133 > 33) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_134 > 31) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_135 > 32) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001400_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r001400_9 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_137 > 46) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_138 > 37) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_139 > 48) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001400_11 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001400_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_142 > 38) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_143 > 21) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001400_12) & 127;
    if (stage_v_144 > 20) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001400_6 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_145 > 30) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001400_12) & 127;
    if (stage_v_146 > 41) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_147 > 46) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_148 > 43) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001400_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_150 > 33) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_151 > 29) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001400_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_153 > 35) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_154 > 34) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_155 > 35) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_156 > 22) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_157 > 22) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001400_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_159 > 47) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_160 > 20) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001400_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001400_7) & 127;
    if (stage_v_162 > 40) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_129 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_163 > 41) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_164 > 42) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001400_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001400_8) & 127;
    if (stage_v_166 > 40) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_167 > 38) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001400_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001400_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001400_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001400_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001400_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001400_7) & 127;
    if (stage_v_173 > 41) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_174 > 26) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r001400_3 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_175 > 45) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_176 > 30) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_177 > 30) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_178 > 25) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_179 > 40) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_180 > 48) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001400_15) & 127;
    if (stage_v_181 > 23) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_182 > 40) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_183 > 20) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_104 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_184 > 34) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_185 > 40) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001400_6 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001400_8) & 127;
    if (stage_v_187 > 39) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_188 > 50) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001400_20 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_190 > 38) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_191 > 43) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001400_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001400_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001400_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001400_8) & 127;
    if (stage_v_195 > 39) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_196 > 28) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001400_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001400_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_199 > 33) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001400_21 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_201 > 33) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001400_11) & 127;
    if (stage_v_202 > 43) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_203 > 23) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_204 > 46) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001400_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_206 > 46) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_123 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_207 > 41) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_208 > 30) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_209 > 22) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001400_3) & 127;
    if (stage_v_210 > 39) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001400_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001400_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_206 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_213 > 26) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_166 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_214 > 21) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001400_14) & 127;
    if (stage_v_215 > 27) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_216 > 49) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_217 > 46) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001400_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_219 > 48) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001400_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_221 > 28) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_222 > 32) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001400_1) & 127;
    if (stage_v_223 > 20) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((sec_r001400_14 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_224 > 44) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_225 > 32) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_226 > 30) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_224 ^ 0x2A) * 2 + pub_r001400_13) & 127;
    if (stage_v_227 > 48) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001400_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_229 > 23) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r001400_9 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_230 > 29) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001400_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001400_13 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001400_5) & 127;
    if (stage_v_233 > 24) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001400_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001400_17) & 127;
    if (stage_v_235 > 21) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_236 > 48) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_237 > 26) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001400_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_239 > 20) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001400_21 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001400_16) & 127;
    if (stage_v_241 > 41) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001400_10) & 127;
    if (stage_v_242 > 46) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_243 > 33) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001400_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001400_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001400_20) & 127;
    if (stage_v_246 > 49) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_247 > 48) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_239 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_248 > 33) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001400_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001400_21) & 127;
    if (stage_v_250 > 40) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_251 > 21) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001400_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_100 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_253 > 46) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001400_4) & 127;
    if (stage_v_254 > 35) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001400_18) & 127;
    if (stage_v_255 > 45) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_209 ^ 0x2A) * 2 + pub_r001400_9) & 127;
    if (stage_v_256 > 35) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_257 > 25) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_153 ^ 0x2A) * 2 + pub_r001400_0) & 127;
    if (stage_v_258 > 29) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001400_19) & 127;
    if (stage_v_259 > 34) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001400_12) & 127;
    if (stage_v_260 > 31) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001400_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001400_2) & 127;
    if (stage_v_262 > 26) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001400_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_255 ^ 0x2A) * 2 + pub_r001400_6) & 127;
    if (stage_v_264 > 27) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
