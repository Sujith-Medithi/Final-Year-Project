/*
 * Benchmark Program: R001170
 * Security Family: mixed_control_data
 * Generator Seed: 617013
 * High Inputs: 23 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001170_7013_0 {
    short gain_db;
    int prev_out;
    int damping;
    int buffer[3];
};

struct DeviceConfig_R001170_7013_1 {
    unsigned char timeout;
    short stop_bits;
    unsigned char parity;
    short id;
    short port;
    int baud_rate;
    int buffer[3];
};

struct Transaction_R001170_7013_2 {
    short account_id;
    int fee;
    short balance;
    unsigned char rate;
    int auth_code;
    unsigned char status;
    int buffer[3];
};

struct SensorNode_R001170_7013_3 {
    unsigned char threshold;
    unsigned char reading;
    unsigned char gain;
    int calib;
    int offset;
    int buffer[3];
};

union PacketPayload_R001170_7013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001170_7013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001170_7013_0(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tracker_95 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_95 = (tracker_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_95) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_84 = local_arr[aux % 3];
    acc = (acc + offset_84 * 2) & 127;
    int index_reg_42 = (aux + st.buffer[1]) & 3;
    switch (index_reg_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_1(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int factor_35 = local_arr[aux % 3];
    acc = (acc + factor_35 * 2) & 127;
    int margin_14 = (aux + st.buffer[1]) & 3;
    switch (margin_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_2(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_38 = 0;
    for (int k = 0; k < 2; k++) {
        tally_38 = (tally_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_38) & 127;
    }
    int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_72) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_85 = local_arr[aux % 3];
    acc = (acc + coefficient_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int damping_56 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_56 > 34) {
        acc = (acc + damping_56 * 2 + 5) & 127;
        aux ^= (damping_56 & 15);
    } else {
        acc = (acc - damping_56 + 11) & 127;
        aux += 3;
    }
    int vector_94 = 0;
    for (int k = 0; k < 3; k++) {
        vector_94 = (vector_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_94) & 127;
    }
    int checksum_61 = (aux + st.buffer[1]) & 3;
    switch (checksum_61) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int factor_64 = local_arr[aux % 3];
    acc = (acc + factor_64 * 2) & 127;
    int phase_42 = (aux + st.buffer[1]) & 3;
    switch (phase_42) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_63 = (aux + st.buffer[1]) & 3;
    switch (metric_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_52 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_52 > 48) {
        acc = (acc + factor_52 * 2 + 5) & 127;
        aux ^= (factor_52 & 15);
    } else {
        acc = (acc - factor_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_63 = local_arr[aux % 3];
    acc = (acc + residue_63 * 2) & 127;
    int bound_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001170_7013_6(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_67 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_67 > 43) {
        acc = (acc + metric_67 * 2 + 5) & 127;
        aux ^= (metric_67 & 15);
    } else {
        acc = (acc - metric_67 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_90 = local_arr[aux % 3];
    acc = (acc + accumulator_90 * 2) & 127;
    int damping_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_55) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_7(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_86 = (aux + st.buffer[1]) & 3;
    switch (segment_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001170_7013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_96) & 63;
    acc ^= aux;
    int mask_30 = 0;
    for (int k = 0; k < 3; k++) {
        mask_30 = (mask_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_30) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_9(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int vector_80 = 0;
    for (int k = 0; k < 3; k++) {
        vector_80 = (vector_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_80) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_91 = (aux + st.buffer[1]) & 3;
    switch (stride_91) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_90 = local_arr[aux % 3];
    acc = (acc + coefficient_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001170_7013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int coefficient_39 = local_arr[aux % 3];
    acc = (acc + coefficient_39 * 2) & 127;
    int weight_34 = 0;
    for (int k = 0; k < 2; k++) {
        weight_34 = (weight_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_11(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int offset_85 = 0;
    for (int k = 0; k < 3; k++) {
        offset_85 = (offset_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_85) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_78 = local_arr[aux % 3];
    acc = (acc + coefficient_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_12(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_67) & 63;
    acc ^= aux;
    int threshold_82 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_82 > 38) {
        acc = (acc + threshold_82 * 2 + 5) & 127;
        aux ^= (threshold_82 & 15);
    } else {
        acc = (acc - threshold_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_13(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int checksum_18 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_18 = (checksum_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_18) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_13 = local_arr[aux % 3];
    acc = (acc + coefficient_13 * 2) & 127;
    int vector_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_18) & 63;
    acc ^= aux;
    int threshold_14 = (aux + st.buffer[1]) & 3;
    switch (threshold_14) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int phase_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_71) & 63;
    acc ^= aux;
    int offset_96 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_96 > 27) {
        acc = (acc + offset_96 * 2 + 5) & 127;
        aux ^= (offset_96 & 15);
    } else {
        acc = (acc - offset_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_15(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001170_7013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int weight_77 = 0;
    for (int k = 0; k < 2; k++) {
        weight_77 = (weight_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_77) & 127;
    }
    int delta_87 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_87 > 44) {
        acc = (acc + delta_87 * 2 + 5) & 127;
        aux ^= (delta_87 & 15);
    } else {
        acc = (acc - delta_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_16(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001170_7013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_44 = local_arr[aux % 3];
    acc = (acc + coefficient_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001170_7013_17(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int delta_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_88) & 63;
    acc ^= aux;
    int mask_97 = (aux + st.buffer[1]) & 3;
    switch (mask_97) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_87 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_87 > 14) {
        acc = (acc + bound_87 * 2 + 5) & 127;
        aux ^= (bound_87 & 15);
    } else {
        acc = (acc - bound_87 + 11) & 127;
        aux += 3;
    }
    int segment_73 = 0;
    for (int k = 0; k < 2; k++) {
        segment_73 = (segment_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001170_7013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001170_7013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int pivot_54 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_54 = (pivot_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_54) & 127;
    }
    int vector_63 = (aux + st.buffer[1]) & 3;
    switch (vector_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001170_0;
    int sec_r001170_1;
    int sec_r001170_2;
    int sec_r001170_3;
    int sec_r001170_4;
    int sec_r001170_5;
    int sec_r001170_6;
    int sec_r001170_7;
    int sec_r001170_8;
    int sec_r001170_9;
    int sec_r001170_10;
    int sec_r001170_11;
    int sec_r001170_12;
    int sec_r001170_13;
    int sec_r001170_14;
    int sec_r001170_15;
    int sec_r001170_16;
    int sec_r001170_17;
    int sec_r001170_18;
    int sec_r001170_19;
    int sec_r001170_20;
    int sec_r001170_21;
    int sec_r001170_22;
    int pub_r001170_0;
    int pub_r001170_1;
    int pub_r001170_2;
    int pub_r001170_3;
    int pub_r001170_4;
    int pub_r001170_5;
    int pub_r001170_6;
    int pub_r001170_7;
    int pub_r001170_8;
    int pub_r001170_9;
    int pub_r001170_10;
    int pub_r001170_11;
    int pub_r001170_12;
    int pub_r001170_13;
    int pub_r001170_14;
    int pub_r001170_15;
    int pub_r001170_16;
    int pub_r001170_17;
    int pub_r001170_18;
    int pub_r001170_19;
    int pub_r001170_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001170_0 >= -100 && pub_r001170_0 <= 100);
    __CPROVER_assume(pub_r001170_1 >= -100 && pub_r001170_1 <= 100);
    __CPROVER_assume(pub_r001170_2 >= -100 && pub_r001170_2 <= 100);
    __CPROVER_assume(pub_r001170_3 >= -100 && pub_r001170_3 <= 100);
    __CPROVER_assume(pub_r001170_4 >= -100 && pub_r001170_4 <= 100);
    __CPROVER_assume(pub_r001170_5 >= -100 && pub_r001170_5 <= 100);
    __CPROVER_assume(pub_r001170_6 >= -100 && pub_r001170_6 <= 100);
    __CPROVER_assume(pub_r001170_7 >= -100 && pub_r001170_7 <= 100);
    __CPROVER_assume(pub_r001170_8 >= -100 && pub_r001170_8 <= 100);
    __CPROVER_assume(pub_r001170_9 >= -100 && pub_r001170_9 <= 100);
    __CPROVER_assume(pub_r001170_10 >= -100 && pub_r001170_10 <= 100);
    __CPROVER_assume(pub_r001170_11 >= -100 && pub_r001170_11 <= 100);
    __CPROVER_assume(pub_r001170_12 >= -100 && pub_r001170_12 <= 100);
    __CPROVER_assume(pub_r001170_13 >= -100 && pub_r001170_13 <= 100);
    __CPROVER_assume(pub_r001170_14 >= -100 && pub_r001170_14 <= 100);
    __CPROVER_assume(pub_r001170_15 >= -100 && pub_r001170_15 <= 100);
    __CPROVER_assume(pub_r001170_16 >= -100 && pub_r001170_16 <= 100);
    __CPROVER_assume(pub_r001170_17 >= -100 && pub_r001170_17 <= 100);
    __CPROVER_assume(pub_r001170_18 >= -100 && pub_r001170_18 <= 100);
    __CPROVER_assume(pub_r001170_19 >= -100 && pub_r001170_19 <= 100);
    __CPROVER_assume(pub_r001170_20 >= -100 && pub_r001170_20 <= 100);
    __CPROVER_assume(sec_r001170_0 >= 0 && sec_r001170_0 <= 255);
    __CPROVER_assume(sec_r001170_1 >= 0 && sec_r001170_1 <= 255);
    __CPROVER_assume(sec_r001170_2 >= 0 && sec_r001170_2 <= 255);
    __CPROVER_assume(sec_r001170_3 >= 0 && sec_r001170_3 <= 255);
    __CPROVER_assume(sec_r001170_4 >= 0 && sec_r001170_4 <= 255);
    __CPROVER_assume(sec_r001170_5 >= 0 && sec_r001170_5 <= 255);
    __CPROVER_assume(sec_r001170_6 >= 0 && sec_r001170_6 <= 255);
    __CPROVER_assume(sec_r001170_7 >= 0 && sec_r001170_7 <= 255);
    __CPROVER_assume(sec_r001170_8 >= 0 && sec_r001170_8 <= 255);
    __CPROVER_assume(sec_r001170_9 >= 0 && sec_r001170_9 <= 255);
    __CPROVER_assume(sec_r001170_10 >= 0 && sec_r001170_10 <= 255);
    __CPROVER_assume(sec_r001170_11 >= 0 && sec_r001170_11 <= 255);
    __CPROVER_assume(sec_r001170_12 >= 0 && sec_r001170_12 <= 255);
    __CPROVER_assume(sec_r001170_13 >= 0 && sec_r001170_13 <= 255);
    __CPROVER_assume(sec_r001170_14 >= 0 && sec_r001170_14 <= 255);
    __CPROVER_assume(sec_r001170_15 >= 0 && sec_r001170_15 <= 255);
    __CPROVER_assume(sec_r001170_16 >= 0 && sec_r001170_16 <= 255);
    __CPROVER_assume(sec_r001170_17 >= 0 && sec_r001170_17 <= 255);
    __CPROVER_assume(sec_r001170_18 >= 0 && sec_r001170_18 <= 255);
    __CPROVER_assume(sec_r001170_19 >= 0 && sec_r001170_19 <= 255);
    __CPROVER_assume(sec_r001170_20 >= 0 && sec_r001170_20 <= 255);
    __CPROVER_assume(sec_r001170_21 >= 0 && sec_r001170_21 <= 255);
    __CPROVER_assume(sec_r001170_22 >= 0 && sec_r001170_22 <= 255);

    struct FilterState_R001170_7013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001170_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001170_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001170_0 + 7) & 15;
    struct DeviceConfig_R001170_7013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001170_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001170_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001170_0 + 9) & 15;
    struct Transaction_R001170_7013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001170_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001170_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001170_0 + 11) & 15;
    struct SensorNode_R001170_7013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001170_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001170_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001170_0 + 13) & 15;

    union PacketPayload_R001170_7013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001170_7013_0(sec_r001170_0, sec_r001170_1, pub_r001170_2);
    int helper_flow_1 = fn_R001170_7013_1(sec_r001170_1, sec_r001170_2, pub_r001170_3);
    int helper_flow_2 = fn_R001170_7013_2(sec_r001170_2, pub_r001170_3, pub_r001170_4);
    int helper_flow_3 = fn_R001170_7013_3(sec_r001170_3, sec_r001170_4, pub_r001170_5, pub_r001170_6, pub_r001170_7);
    int helper_flow_4 = fn_R001170_7013_4(sec_r001170_4, pub_r001170_5, pub_r001170_6, pub_r001170_7, pub_r001170_8);
    int helper_flow_5 = fn_R001170_7013_5(sec_r001170_5, sec_r001170_6, pub_r001170_7, pub_r001170_8);
    int helper_flow_6 = fn_R001170_7013_6(sec_r001170_6, pub_r001170_7, pub_r001170_8);
    int helper_flow_7 = fn_R001170_7013_7(sec_r001170_7, pub_r001170_8);
    int helper_flow_8 = fn_R001170_7013_8(sec_r001170_8, sec_r001170_9, pub_r001170_10, pub_r001170_11, pub_r001170_12);
    int helper_flow_9 = fn_R001170_7013_9(sec_r001170_9, sec_r001170_10);
    int helper_flow_10 = fn_R001170_7013_10(sec_r001170_10, sec_r001170_11, pub_r001170_12, pub_r001170_13, pub_r001170_14);
    int helper_flow_11 = fn_R001170_7013_11(sec_r001170_11, pub_r001170_12, pub_r001170_13);
    int helper_flow_12 = fn_R001170_7013_12(sec_r001170_12, sec_r001170_13, pub_r001170_14);
    int helper_flow_13 = fn_R001170_7013_13(sec_r001170_13, sec_r001170_14);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001170_1 ^ 0x2A) * 2 + pub_r001170_17) & 127;
    if (stage_v_0 > 27) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_1 > 33) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_2 > 27) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001170_20 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_3 > 36) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_4 > 34) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_5 > 41) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001170_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001170_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001170_0 ^ 0x2A) * 2 + pub_r001170_11) & 127;
    if (stage_v_8 > 25) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001170_22 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_9 > 49) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001170_16 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_10 > 25) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001170_22 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_11 > 44) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001170_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001170_19 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_14 > 28) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001170_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_16 > 47) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_17 > 31) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001170_18 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_18 > 35) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_19 > 25) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001170_13 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_20 > 29) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_21 > 20) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001170_15 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_22 > 47) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001170_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_24 > 33) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001170_14 ^ 0x2A) * 2 + pub_r001170_11) & 127;
    if (stage_v_25 > 26) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_26 > 48) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001170_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_28 > 27) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001170_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001170_8 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_30 > 37) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_31 > 50) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001170_0 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_32 > 43) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_33 > 20) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001170_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_35 > 26) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001170_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_37 > 23) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_39 > 46) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_40 > 40) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_41 > 47) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_42 > 27) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001170_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_44 > 46) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_13 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_45 > 39) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001170_2 ^ 0x2A) * 2 + pub_r001170_11) & 127;
    if (stage_v_46 > 26) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001170_4 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_47 > 30) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001170_5) & 127;
    if (stage_v_48 > 34) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_49 > 40) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_50 > 42) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_51 > 22) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001170_3) & 127;
    if (stage_v_52 > 28) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_53 > 26) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001170_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001170_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_56 > 35) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001170_19 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_58 > 49) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001170_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_60 > 36) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_61 > 25) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001170_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_63 > 41) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_64 > 29) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001170_17) & 127;
    if (stage_v_65 > 42) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001170_7 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001170_8 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_67 > 48) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001170_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_69 > 27) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_70 > 50) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001170_9 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_71 > 31) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001170_0 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_72 > 23) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001170_3) & 127;
    if (stage_v_73 > 28) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_74 > 23) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_75 > 41) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001170_3) & 127;
    if (stage_v_76 > 21) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_77 > 22) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_78 > 35) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001170_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_80 > 43) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_81 > 27) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_82 > 23) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_83 > 26) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_84 > 37) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_85 > 21) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_86 > 36) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001170_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001170_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_89 > 46) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001170_22 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_90 > 38) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_91 > 22) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_92 > 31) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_93 > 34) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_94 > 40) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001170_14 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001170_7 ^ 0x2A) * 2 + pub_r001170_17) & 127;
    if (stage_v_96 > 37) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001170_5) & 127;
    if (stage_v_97 > 27) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_98 > 23) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001170_5) & 127;
    if (stage_v_99 > 28) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001170_5) & 127;
    if (stage_v_100 > 37) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_101 > 38) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r001170_4 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_102 > 28) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_103 > 33) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001170_11 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_104 > 48) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_105 > 23) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_106 > 33) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_107 > 36) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_108 > 26) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_109 > 25) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001170_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_111 > 50) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_112 > 31) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_113 > 47) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_114 > 49) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r001170_12 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_115 > 44) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001170_5) & 127;
    if (stage_v_116 > 28) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001170_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_118 > 38) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_119 > 33) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001170_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_121 > 49) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001170_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_123 > 21) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001170_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_125 > 29) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_126 > 37) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001170_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001170_22 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_128 > 37) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001170_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001170_6 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_131 > 49) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001170_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((sec_r001170_11 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_133 > 45) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001170_3) & 127;
    if (stage_v_134 > 23) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_135 > 45) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001170_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001170_16 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001170_14 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_138 > 20) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001170_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_140 > 46) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001170_10 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_141 > 24) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001170_14 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001170_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_144 > 28) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_145 > 33) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_146 > 25) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_147 > 23) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r001170_22 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_148 > 30) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001170_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_150 > 33) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001170_15 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_151 > 39) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001170_17) & 127;
    if (stage_v_152 > 48) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_153 > 49) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_154 > 42) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001170_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_156 > 22) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_157 > 32) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001170_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_159 > 50) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_160 > 29) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001170_20 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_162 > 45) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_163 > 50) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001170_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_165 > 26) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001170_7 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_166 > 29) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_167 > 25) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r001170_10 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_168 > 21) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001170_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_167 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_170 > 41) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001170_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_172 > 45) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_173 > 35) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_174 > 25) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_175 > 35) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_176 > 41) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_177 > 38) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001170_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_179 > 24) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_180 > 24) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001170_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_182 > 29) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_183 > 25) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_184 > 41) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_185 > 38) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_186 > 41) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_187 > 36) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_188 > 49) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_189 > 23) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001170_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001170_17) & 127;
    if (stage_v_191 > 24) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001170_11) & 127;
    if (stage_v_192 > 22) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_193 > 20) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_194 > 32) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001170_3) & 127;
    if (stage_v_195 > 34) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_196 > 28) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_197 > 44) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001170_20 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001170_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_200 > 41) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_201 > 24) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001170_15) & 127;
    if (stage_v_202 > 35) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001170_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001170_19) & 127;
    if (stage_v_204 > 36) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_205 > 43) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001170_11) & 127;
    if (stage_v_206 > 45) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_207 > 24) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001170_11 ^ 0x2A) * 2 + pub_r001170_4) & 127;
    if (stage_v_208 > 48) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001170_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001170_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001170_20 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_211 > 26) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_212 > 41) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_213 > 33) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001170_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001170_6) & 127;
    if (stage_v_215 > 38) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001170_8) & 127;
    if (stage_v_216 > 29) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_217 > 46) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001170_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((sec_r001170_8 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_219 > 31) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001170_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_52 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_221 > 27) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001170_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001170_16) & 127;
    if (stage_v_223 > 47) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001170_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_225 > 47) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001170_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001170_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_228 > 37) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_208 ^ 0x2A) * 2 + pub_r001170_12) & 127;
    if (stage_v_229 > 34) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_230 > 50) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_187 ^ 0x2A) * 2 + pub_r001170_14) & 127;
    if (stage_v_231 > 23) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001170_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_200 ^ 0x2A) * 2 + pub_r001170_17) & 127;
    if (stage_v_233 > 26) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001170_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r001170_0 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_235 > 37) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_168 ^ 0x2A) * 2 + pub_r001170_9) & 127;
    if (stage_v_236 > 24) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_237 > 22) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_216 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_238 > 24) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001170_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_240 > 45) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001170_2) & 127;
    if (stage_v_241 > 37) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_242 > 32) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001170_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r001170_17 ^ 0x2A) * 2 + pub_r001170_10) & 127;
    if (stage_v_244 > 40) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_237 ^ 0x2A) * 2 + pub_r001170_13) & 127;
    if (stage_v_245 > 48) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_241 ^ 0x2A) * 2 + pub_r001170_18) & 127;
    if (stage_v_246 > 50) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_247 > 42) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001170_3) & 127;
    if (stage_v_248 > 26) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001170_0) & 127;
    if (stage_v_249 > 25) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_245 ^ 0x2A) * 2 + pub_r001170_20) & 127;
    if (stage_v_250 > 22) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r001170_15 ^ 0x2A) * 2 + pub_r001170_1) & 127;
    if (stage_v_251 > 28) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001170_7) & 127;
    if (stage_v_252 > 21) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001170_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
