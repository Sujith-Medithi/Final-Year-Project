/*
 * Benchmark Program: R000286
 * Family: multi_step_explicit
 * Generator Seed: 428613
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000286_8613_0 {
    int facility;
    unsigned char seq;
    short signature;
    int severity;
    int timestamp;
    int buffer[3];
};

struct DeviceConfig_R000286_8613_1 {
    int baud_rate;
    int timeout;
    int parity;
    int id;
    short stop_bits;
    int buffer[3];
};

struct StreamBuffer_R000286_8613_2 {
    unsigned char checksum;
    int watermark;
    int state;
    short head;
    int buffer[3];
};

union RegisterBank_R000286_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000286_8613_0(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000286_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int segment_80 = (aux + st.buffer[1]) & 3;
    switch (segment_80) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_33 = local_arr[aux % 3];
    acc = (acc + vector_33 * 2) & 127;
    int phase_25 = 0;
    for (int k = 0; k < 2; k++) {
        phase_25 = (phase_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int vector_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_34) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_92 = local_arr[aux % 3];
    acc = (acc + sample_92 * 2) & 127;
    int checksum_28 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_28 = (checksum_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_2(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int damping_34 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_34 > 45) {
        acc = (acc + damping_34 * 2 + 5) & 127;
        aux ^= (damping_34 & 15);
    } else {
        acc = (acc - damping_34 + 11) & 127;
        aux += 3;
    }
    int threshold_55 = (aux + st.buffer[1]) & 3;
    switch (threshold_55) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int anchor_61 = local_arr[aux % 3];
    acc = (acc + anchor_61 * 2) & 127;
    int threshold_27 = (aux + st.buffer[1]) & 3;
    switch (threshold_27) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_4(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_35 = 0;
    for (int k = 0; k < 3; k++) {
        scale_35 = (scale_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_35) & 127;
    }
    int accumulator_56 = (aux + st.buffer[1]) & 3;
    switch (accumulator_56) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_54 = local_arr[aux % 3];
    acc = (acc + segment_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_5(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_73 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_73 = (tracker_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_73) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_36 = local_arr[aux % 3];
    acc = (acc + accumulator_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_6(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_67 = 0;
    for (int k = 0; k < 2; k++) {
        mask_67 = (mask_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_67) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_13 = local_arr[aux % 3];
    acc = (acc + mask_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000286_8613_7(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int coefficient_82 = (aux + st.buffer[1]) & 3;
    switch (coefficient_82) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_62 = local_arr[aux % 3];
    acc = (acc + margin_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_8(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_35) & 63;
    acc ^= aux;
    int window_72 = (st.buffer[0] * 3 + aux) & 63;
    if (window_72 > 28) {
        acc = (acc + window_72 * 2 + 5) & 127;
        aux ^= (window_72 & 15);
    } else {
        acc = (acc - window_72 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_14 = local_arr[aux % 3];
    acc = (acc + index_reg_14 * 2) & 127;
    int segment_31 = 0;
    for (int k = 0; k < 2; k++) {
        segment_31 = (segment_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_9(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000286_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int coefficient_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_46) & 63;
    acc ^= aux;
    int weight_49 = 0;
    for (int k = 0; k < 3; k++) {
        weight_49 = (weight_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_49) & 127;
    }
    int threshold_99 = (aux + st.buffer[1]) & 3;
    switch (threshold_99) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_45) & 63;
    acc ^= aux;
    int vector_21 = (aux + st.buffer[1]) & 3;
    switch (vector_21) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_11(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_84) & 63;
    acc ^= aux;
    int sample_40 = (aux + st.buffer[1]) & 3;
    switch (sample_40) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_89 = local_arr[aux % 3];
    acc = (acc + vector_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_12(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000286_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int checksum_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_70) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_41 = local_arr[aux % 3];
    acc = (acc + damping_41 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_73 = (aux + st.buffer[1]) & 3;
    switch (segment_73) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int scale_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_50) & 63;
    acc ^= aux;
    int mask_40 = 0;
    for (int k = 0; k < 2; k++) {
        mask_40 = (mask_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_14(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000286_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int quotient_15 = local_arr[aux % 3];
    acc = (acc + quotient_15 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_62) & 63;
    acc ^= aux;
    int vector_62 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_62 > 40) {
        acc = (acc + vector_62 * 2 + 5) & 127;
        aux ^= (vector_62 & 15);
    } else {
        acc = (acc - vector_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_31) & 63;
    acc ^= aux;
    int metric_96 = (aux + st.buffer[1]) & 3;
    switch (metric_96) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_16(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int metric_91 = (aux + st.buffer[1]) & 3;
    switch (metric_91) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_63 = local_arr[aux % 3];
    acc = (acc + weight_63 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000286_8613_17(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000286_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int scale_79 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_79 > 23) {
        acc = (acc + scale_79 * 2 + 5) & 127;
        aux ^= (scale_79 & 15);
    } else {
        acc = (acc - scale_79 + 11) & 127;
        aux += 3;
    }
    int quantum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_10) & 63;
    acc ^= aux;
    int pivot_53 = (aux + st.buffer[1]) & 3;
    switch (pivot_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_51 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_51 = (pivot_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_51) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_18(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000286_8613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int offset_92 = (aux + st.buffer[1]) & 3;
    switch (offset_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_11 = local_arr[aux % 3];
    acc = (acc + checksum_11 * 2) & 127;
    int threshold_83 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_83 > 15) {
        acc = (acc + threshold_83 * 2 + 5) & 127;
        aux ^= (threshold_83 & 15);
    } else {
        acc = (acc - threshold_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000286_8613_19(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000286_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int scale_37 = local_arr[aux % 3];
    acc = (acc + scale_37 * 2) & 127;
    int vector_58 = 0;
    for (int k = 0; k < 3; k++) {
        vector_58 = (vector_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_58) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000286_0;
    int sec_r000286_1;
    int sec_r000286_2;
    int sec_r000286_3;
    int sec_r000286_4;
    int sec_r000286_5;
    int sec_r000286_6;
    int sec_r000286_7;
    int sec_r000286_8;
    int sec_r000286_9;
    int sec_r000286_10;
    int sec_r000286_11;
    int sec_r000286_12;
    int sec_r000286_13;
    int sec_r000286_14;
    int sec_r000286_15;
    int sec_r000286_16;
    int sec_r000286_17;
    int pub_r000286_0;
    int pub_r000286_1;
    int pub_r000286_2;
    int pub_r000286_3;
    int pub_r000286_4;
    int pub_r000286_5;
    int pub_r000286_6;
    int pub_r000286_7;
    int pub_r000286_8;
    int pub_r000286_9;
    int pub_r000286_10;
    int pub_r000286_11;
    int pub_r000286_12;
    int pub_r000286_13;
    int pub_r000286_14;
    int pub_r000286_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000286_0 >= -100 && pub_r000286_0 <= 100);
    __CPROVER_assume(pub_r000286_1 >= -100 && pub_r000286_1 <= 100);
    __CPROVER_assume(pub_r000286_2 >= -100 && pub_r000286_2 <= 100);
    __CPROVER_assume(pub_r000286_3 >= -100 && pub_r000286_3 <= 100);
    __CPROVER_assume(pub_r000286_4 >= -100 && pub_r000286_4 <= 100);
    __CPROVER_assume(pub_r000286_5 >= -100 && pub_r000286_5 <= 100);
    __CPROVER_assume(pub_r000286_6 >= -100 && pub_r000286_6 <= 100);
    __CPROVER_assume(pub_r000286_7 >= -100 && pub_r000286_7 <= 100);
    __CPROVER_assume(pub_r000286_8 >= -100 && pub_r000286_8 <= 100);
    __CPROVER_assume(pub_r000286_9 >= -100 && pub_r000286_9 <= 100);
    __CPROVER_assume(pub_r000286_10 >= -100 && pub_r000286_10 <= 100);
    __CPROVER_assume(pub_r000286_11 >= -100 && pub_r000286_11 <= 100);
    __CPROVER_assume(pub_r000286_12 >= -100 && pub_r000286_12 <= 100);
    __CPROVER_assume(pub_r000286_13 >= -100 && pub_r000286_13 <= 100);
    __CPROVER_assume(pub_r000286_14 >= -100 && pub_r000286_14 <= 100);
    __CPROVER_assume(pub_r000286_15 >= -100 && pub_r000286_15 <= 100);
    __CPROVER_assume(sec_r000286_0 >= 0 && sec_r000286_0 <= 255);
    __CPROVER_assume(sec_r000286_1 >= 0 && sec_r000286_1 <= 255);
    __CPROVER_assume(sec_r000286_2 >= 0 && sec_r000286_2 <= 255);
    __CPROVER_assume(sec_r000286_3 >= 0 && sec_r000286_3 <= 255);
    __CPROVER_assume(sec_r000286_4 >= 0 && sec_r000286_4 <= 255);
    __CPROVER_assume(sec_r000286_5 >= 0 && sec_r000286_5 <= 255);
    __CPROVER_assume(sec_r000286_6 >= 0 && sec_r000286_6 <= 255);
    __CPROVER_assume(sec_r000286_7 >= 0 && sec_r000286_7 <= 255);
    __CPROVER_assume(sec_r000286_8 >= 0 && sec_r000286_8 <= 255);
    __CPROVER_assume(sec_r000286_9 >= 0 && sec_r000286_9 <= 255);
    __CPROVER_assume(sec_r000286_10 >= 0 && sec_r000286_10 <= 255);
    __CPROVER_assume(sec_r000286_11 >= 0 && sec_r000286_11 <= 255);
    __CPROVER_assume(sec_r000286_12 >= 0 && sec_r000286_12 <= 255);
    __CPROVER_assume(sec_r000286_13 >= 0 && sec_r000286_13 <= 255);
    __CPROVER_assume(sec_r000286_14 >= 0 && sec_r000286_14 <= 255);
    __CPROVER_assume(sec_r000286_15 >= 0 && sec_r000286_15 <= 255);
    __CPROVER_assume(sec_r000286_16 >= 0 && sec_r000286_16 <= 255);
    __CPROVER_assume(sec_r000286_17 >= 0 && sec_r000286_17 <= 255);

    struct EventLog_R000286_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000286_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000286_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000286_0 + 7) & 15;
    struct DeviceConfig_R000286_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000286_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000286_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000286_0 + 9) & 15;
    struct StreamBuffer_R000286_8613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000286_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000286_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000286_0 + 11) & 15;

    union RegisterBank_R000286_8613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 39) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 54) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 35) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 50) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 31) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 46) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 22) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 37) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 31) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 46) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[0] ^ 56) & 3;
    switch (stage_v_53) {
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

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 10) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 25) {
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
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 40) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 55) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 20) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 35) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 19) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 34) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
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
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_1.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] ^ 87) & 3;
    switch (stage_v_84) {
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

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[0] ^ 88) & 3;
    switch (stage_v_85) {
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

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (out_sink > 100) ? (chk_sum & 31) : (97 & 31);
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= (stage_v_92 << 1) & 127;

    /* Execution Pipeline Stage 93 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 94) & 15;
    int stage_v_93 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= stage_v_93;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (out_sink > 100) ? (chk_sum & 31) : (100 & 31);
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= (stage_v_95 << 1) & 127;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 99) & 15;
    int stage_v_98 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= stage_v_98;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 16) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 31) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 39) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 54) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 104) & 15;
    int stage_v_103 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= stage_v_103;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (out_sink > 100) ? (chk_sum & 31) : (112 & 31);
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= (stage_v_107 << 1) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 28) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 43) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_110 = (stage_v_110 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 18) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 33) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 12) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 27) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 12) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 27) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_2.buffer[0] ^ 119) & 3;
    switch (stage_v_116) {
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

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_2.buffer[0] ^ 122) & 3;
    switch (stage_v_119) {
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

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_120 = (stage_v_120 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (out_sink > 100) ? (chk_sum & 31) : (127 & 31);
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= (stage_v_122 << 1) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_125 = (stage_v_125 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 131) & 15;
    int stage_v_130 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    chk_sum ^= stage_v_130;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_134 = (stage_v_134 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 140) & 15;
    int stage_v_139 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= stage_v_139;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_145 = (stage_v_145 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = table[1];
    table[1] = (table[2] + 299) & 63;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = table[2];
    table[2] = (table[3] + 301) & 63;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] * 2 + 466) & 63;
    if (stage_v_153 > 30) {
        out_sink = (out_sink + stage_v_153 - 5) & 255;
        if (stage_v_153 > 45) {
            chk_sum ^= (stage_v_153 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_153 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_1.buffer[0] ^ 157) & 3;
    switch (stage_v_154) {
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

    /* Execution Pipeline Stage 155 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_156 = (stage_v_156 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_158 = (stage_v_158 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] * 2 + 484) & 63;
    if (stage_v_159 > 12) {
        out_sink = (out_sink + stage_v_159 - 5) & 255;
        if (stage_v_159 > 27) {
            chk_sum ^= (stage_v_159 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_159 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = table[1];
    table[1] = (table[2] + 323) & 63;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (out_sink > 100) ? (chk_sum & 31) : (167 & 31);
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= (stage_v_162 << 1) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = table[3];
    table[3] = (table[0] + 327) & 63;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (out_sink > 100) ? (chk_sum & 31) : (170 & 31);
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= (stage_v_165 << 1) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_1.buffer[1] * 2 + 505) & 63;
    if (stage_v_166 > 27) {
        out_sink = (out_sink + stage_v_166 - 5) & 255;
        if (stage_v_166 > 42) {
            chk_sum ^= (stage_v_166 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_166 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_167 = (stage_v_167 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_168 = (stage_v_168 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_168) & 127;
    }
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[1] * 2 + 514) & 63;
    if (stage_v_169 > 17) {
        out_sink = (out_sink + stage_v_169 - 5) & 255;
        if (stage_v_169 > 32) {
            chk_sum ^= (stage_v_169 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_169 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = table[2];
    table[2] = (table[3] + 341) & 63;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 173) & 15;
    int stage_v_172 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= stage_v_172;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[0] ^ 178) & 3;
    switch (stage_v_175) {
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

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[0] ^ 179) & 3;
    switch (stage_v_176) {
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

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (out_sink > 100) ? (chk_sum & 31) : (182 & 31);
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= (stage_v_177 << 1) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (out_sink > 100) ? (chk_sum & 31) : (183 & 31);
    out_sink = (out_sink + stage_v_178) & 255;
    chk_sum ^= (stage_v_178 << 1) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_179 = (stage_v_179 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = table[0];
    table[0] = (table[1] + 361) & 63;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = table[1];
    table[1] = (table[2] + 363) & 63;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_2.buffer[0] ^ 185) & 3;
    switch (stage_v_182) {
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

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (out_sink > 100) ? (chk_sum & 31) : (188 & 31);
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= (stage_v_183 << 1) & 127;

    /* Execution Pipeline Stage 184 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 185) & 15;
    int stage_v_184 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= stage_v_184;

    /* Execution Pipeline Stage 185 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 186) & 15;
    int stage_v_185 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= stage_v_185;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (out_sink > 100) ? (chk_sum & 31) : (191 & 31);
    out_sink = (out_sink + stage_v_186) & 255;
    chk_sum ^= (stage_v_186 << 1) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[1] * 2 + 568) & 63;
    if (stage_v_187 > 30) {
        out_sink = (out_sink + stage_v_187 - 5) & 255;
        if (stage_v_187 > 45) {
            chk_sum ^= (stage_v_187 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_187 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Security Information Flow: Family = multi_step_explicit */
    int m_step_0 = (sec_r000286_15 + pub_r000286_9 + 29) & 127;
    int m_step_1 = (m_step_0 + pub_r000286_5 + 23) & 127;
    int m_step_2 = (m_step_1 + pub_r000286_11 + 6) & 127;
    out_sink = (out_sink + m_step_2) & 255;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
