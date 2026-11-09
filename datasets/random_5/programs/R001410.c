/*
 * Benchmark Program: R001410
 * Security Family: mixed_control_data
 * Generator Seed: 641013
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001410_1013_0 {
    int seq;
    short code;
    int facility;
    unsigned char severity;
    int buffer[3];
};

struct DeviceConfig_R001410_1013_1 {
    int stop_bits;
    short id;
    int timeout;
    int port;
    int buffer[3];
};

struct AudioFrame_R001410_1013_2 {
    int envelope;
    short peak;
    unsigned char sample_rate;
    int buffer[3];
};

union ColorPixel_R001410_1013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001410_1013_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001410_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int bound_87 = local_arr[aux % 3];
    acc = (acc + bound_87 * 2) & 127;
    int window_24 = (st.buffer[0] * 3 + aux) & 63;
    if (window_24 > 37) {
        acc = (acc + window_24 * 2 + 5) & 127;
        aux ^= (window_24 & 15);
    } else {
        acc = (acc - window_24 + 11) & 127;
        aux += 3;
    }
    int threshold_13 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_13 = (threshold_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_13) & 127;
    }
    int stride_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001410_1013_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int coefficient_79 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_79 > 33) {
        acc = (acc + coefficient_79 * 2 + 5) & 127;
        aux ^= (coefficient_79 & 15);
    } else {
        acc = (acc - coefficient_79 + 11) & 127;
        aux += 3;
    }
    int sample_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_21) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_39 = local_arr[aux % 3];
    acc = (acc + phase_39 * 2) & 127;
    int mask_31 = 0;
    for (int k = 0; k < 3; k++) {
        mask_31 = (mask_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_2(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001410_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int offset_73 = local_arr[aux % 3];
    acc = (acc + offset_73 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_15 = (aux + st.buffer[1]) & 3;
    switch (stride_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_3(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tally_96 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_96 > 26) {
        acc = (acc + tally_96 * 2 + 5) & 127;
        aux ^= (tally_96 & 15);
    } else {
        acc = (acc - tally_96 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_95 = local_arr[aux % 3];
    acc = (acc + mask_95 * 2) & 127;
    int mask_73 = 0;
    for (int k = 0; k < 3; k++) {
        mask_73 = (mask_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_4(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001410_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_65 = 0;
    for (int k = 0; k < 3; k++) {
        segment_65 = (segment_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_65) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_67 = local_arr[aux % 3];
    acc = (acc + scale_67 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001410_1013_5(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001410_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int margin_47 = 0;
    for (int k = 0; k < 3; k++) {
        margin_47 = (margin_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_47) & 127;
    }
    int tracker_46 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_46 > 13) {
        acc = (acc + tracker_46 * 2 + 5) & 127;
        aux ^= (tracker_46 & 15);
    } else {
        acc = (acc - tracker_46 + 11) & 127;
        aux += 3;
    }
    int offset_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001410_1013_6(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_80 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_80 > 36) {
        acc = (acc + residue_80 * 2 + 5) & 127;
        aux ^= (residue_80 & 15);
    } else {
        acc = (acc - residue_80 + 11) & 127;
        aux += 3;
    }
    int vector_90 = (aux + st.buffer[1]) & 3;
    switch (vector_90) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_55 = (aux + st.buffer[1]) & 3;
    switch (scale_55) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_83 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_83 > 27) {
        acc = (acc + coefficient_83 * 2 + 5) & 127;
        aux ^= (coefficient_83 & 15);
    } else {
        acc = (acc - coefficient_83 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_82 = local_arr[aux % 3];
    acc = (acc + accumulator_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001410_1013_8(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001410_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int stride_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_44 = local_arr[aux % 3];
    acc = (acc + vector_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001410_1013_9(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001410_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_45 = (aux + st.buffer[1]) & 3;
    switch (anchor_45) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_93 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_93 > 29) {
        acc = (acc + mask_93 * 2 + 5) & 127;
        aux ^= (mask_93 & 15);
    } else {
        acc = (acc - mask_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_10(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_27 = 0;
    for (int k = 0; k < 3; k++) {
        offset_27 = (offset_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_27) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001410_1013_11(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int segment_79 = 0;
    for (int k = 0; k < 2; k++) {
        segment_79 = (segment_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_79) & 127;
    }
    int scale_29 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_29 > 30) {
        acc = (acc + scale_29 * 2 + 5) & 127;
        aux ^= (scale_29 & 15);
    } else {
        acc = (acc - scale_29 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001410_1013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int accumulator_64 = (aux + st.buffer[1]) & 3;
    switch (accumulator_64) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_22 = 0;
    for (int k = 0; k < 3; k++) {
        weight_22 = (weight_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_22) & 127;
    }
    int residue_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_67) & 63;
    acc ^= aux;
    int scale_80 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_80 > 49) {
        acc = (acc + scale_80 * 2 + 5) & 127;
        aux ^= (scale_80 & 15);
    } else {
        acc = (acc - scale_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001410_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_58 = local_arr[aux % 3];
    acc = (acc + pivot_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001410_1013_14(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int phase_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_49) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_55 = (aux + st.buffer[1]) & 3;
    switch (checksum_55) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_95 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_95 > 19) {
        acc = (acc + sample_95 * 2 + 5) & 127;
        aux ^= (sample_95 & 15);
    } else {
        acc = (acc - sample_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001410_1013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001410_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_26 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_26 > 50) {
        acc = (acc + bound_26 * 2 + 5) & 127;
        aux ^= (bound_26 & 15);
    } else {
        acc = (acc - bound_26 + 11) & 127;
        aux += 3;
    }
    int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001410_1013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001410_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int anchor_99 = local_arr[aux % 3];
    acc = (acc + anchor_99 * 2) & 127;
    int quotient_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001410_0;
    int sec_r001410_1;
    int sec_r001410_2;
    int sec_r001410_3;
    int sec_r001410_4;
    int sec_r001410_5;
    int sec_r001410_6;
    int sec_r001410_7;
    int sec_r001410_8;
    int sec_r001410_9;
    int sec_r001410_10;
    int sec_r001410_11;
    int sec_r001410_12;
    int sec_r001410_13;
    int sec_r001410_14;
    int sec_r001410_15;
    int sec_r001410_16;
    int sec_r001410_17;
    int sec_r001410_18;
    int pub_r001410_0;
    int pub_r001410_1;
    int pub_r001410_2;
    int pub_r001410_3;
    int pub_r001410_4;
    int pub_r001410_5;
    int pub_r001410_6;
    int pub_r001410_7;
    int pub_r001410_8;
    int pub_r001410_9;
    int pub_r001410_10;
    int pub_r001410_11;
    int pub_r001410_12;
    int pub_r001410_13;
    int pub_r001410_14;
    int pub_r001410_15;
    int pub_r001410_16;
    int pub_r001410_17;
    int pub_r001410_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001410_0 >= -100 && pub_r001410_0 <= 100);
    __CPROVER_assume(pub_r001410_1 >= -100 && pub_r001410_1 <= 100);
    __CPROVER_assume(pub_r001410_2 >= -100 && pub_r001410_2 <= 100);
    __CPROVER_assume(pub_r001410_3 >= -100 && pub_r001410_3 <= 100);
    __CPROVER_assume(pub_r001410_4 >= -100 && pub_r001410_4 <= 100);
    __CPROVER_assume(pub_r001410_5 >= -100 && pub_r001410_5 <= 100);
    __CPROVER_assume(pub_r001410_6 >= -100 && pub_r001410_6 <= 100);
    __CPROVER_assume(pub_r001410_7 >= -100 && pub_r001410_7 <= 100);
    __CPROVER_assume(pub_r001410_8 >= -100 && pub_r001410_8 <= 100);
    __CPROVER_assume(pub_r001410_9 >= -100 && pub_r001410_9 <= 100);
    __CPROVER_assume(pub_r001410_10 >= -100 && pub_r001410_10 <= 100);
    __CPROVER_assume(pub_r001410_11 >= -100 && pub_r001410_11 <= 100);
    __CPROVER_assume(pub_r001410_12 >= -100 && pub_r001410_12 <= 100);
    __CPROVER_assume(pub_r001410_13 >= -100 && pub_r001410_13 <= 100);
    __CPROVER_assume(pub_r001410_14 >= -100 && pub_r001410_14 <= 100);
    __CPROVER_assume(pub_r001410_15 >= -100 && pub_r001410_15 <= 100);
    __CPROVER_assume(pub_r001410_16 >= -100 && pub_r001410_16 <= 100);
    __CPROVER_assume(pub_r001410_17 >= -100 && pub_r001410_17 <= 100);
    __CPROVER_assume(pub_r001410_18 >= -100 && pub_r001410_18 <= 100);
    __CPROVER_assume(sec_r001410_0 >= 0 && sec_r001410_0 <= 255);
    __CPROVER_assume(sec_r001410_1 >= 0 && sec_r001410_1 <= 255);
    __CPROVER_assume(sec_r001410_2 >= 0 && sec_r001410_2 <= 255);
    __CPROVER_assume(sec_r001410_3 >= 0 && sec_r001410_3 <= 255);
    __CPROVER_assume(sec_r001410_4 >= 0 && sec_r001410_4 <= 255);
    __CPROVER_assume(sec_r001410_5 >= 0 && sec_r001410_5 <= 255);
    __CPROVER_assume(sec_r001410_6 >= 0 && sec_r001410_6 <= 255);
    __CPROVER_assume(sec_r001410_7 >= 0 && sec_r001410_7 <= 255);
    __CPROVER_assume(sec_r001410_8 >= 0 && sec_r001410_8 <= 255);
    __CPROVER_assume(sec_r001410_9 >= 0 && sec_r001410_9 <= 255);
    __CPROVER_assume(sec_r001410_10 >= 0 && sec_r001410_10 <= 255);
    __CPROVER_assume(sec_r001410_11 >= 0 && sec_r001410_11 <= 255);
    __CPROVER_assume(sec_r001410_12 >= 0 && sec_r001410_12 <= 255);
    __CPROVER_assume(sec_r001410_13 >= 0 && sec_r001410_13 <= 255);
    __CPROVER_assume(sec_r001410_14 >= 0 && sec_r001410_14 <= 255);
    __CPROVER_assume(sec_r001410_15 >= 0 && sec_r001410_15 <= 255);
    __CPROVER_assume(sec_r001410_16 >= 0 && sec_r001410_16 <= 255);
    __CPROVER_assume(sec_r001410_17 >= 0 && sec_r001410_17 <= 255);
    __CPROVER_assume(sec_r001410_18 >= 0 && sec_r001410_18 <= 255);

    struct EventLog_R001410_1013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001410_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001410_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001410_0 + 7) & 15;
    struct DeviceConfig_R001410_1013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001410_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001410_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001410_0 + 9) & 15;
    struct AudioFrame_R001410_1013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001410_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001410_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001410_0 + 11) & 15;

    union ColorPixel_R001410_1013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001410_1013_0(sec_r001410_0, sec_r001410_1, pub_r001410_2, pub_r001410_3, pub_r001410_4);
    int helper_flow_1 = fn_R001410_1013_1(sec_r001410_1, pub_r001410_2, pub_r001410_3, pub_r001410_4, pub_r001410_5);
    int helper_flow_2 = fn_R001410_1013_2(sec_r001410_2, sec_r001410_3);
    int helper_flow_3 = fn_R001410_1013_3(sec_r001410_3, pub_r001410_4, pub_r001410_5);
    int helper_flow_4 = fn_R001410_1013_4(sec_r001410_4, pub_r001410_5, pub_r001410_6);
    int helper_flow_5 = fn_R001410_1013_5(sec_r001410_5, sec_r001410_6);
    int helper_flow_6 = fn_R001410_1013_6(sec_r001410_6, pub_r001410_7, pub_r001410_8);
    int helper_flow_7 = fn_R001410_1013_7(sec_r001410_7, sec_r001410_8, pub_r001410_9, pub_r001410_10);
    int helper_flow_8 = fn_R001410_1013_8(sec_r001410_8, pub_r001410_9, pub_r001410_10);
    int helper_flow_9 = fn_R001410_1013_9(sec_r001410_9, sec_r001410_10, pub_r001410_11);
    int helper_flow_10 = fn_R001410_1013_10(sec_r001410_10, pub_r001410_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001410_4 ^ 0x2A) * 2 + pub_r001410_4) & 127;
    if (stage_v_0 > 25) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001410_14 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_1 > 37) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001410_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001410_12 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_3 > 30) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001410_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_5 > 35) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_6 > 42) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001410_4) & 127;
    if (stage_v_7 > 31) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001410_8 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_8 > 21) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_9 > 36) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001410_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001410_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_12 > 30) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001410_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_14 > 33) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_15 > 47) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((sec_r001410_16 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_16 > 50) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_17 > 46) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001410_11 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_18 > 30) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001410_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001410_8 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_20 > 47) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001410_17 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_21 > 25) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_22 > 28) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001410_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_24 > 29) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001410_3 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_25 > 42) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001410_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001410_3 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_27 > 50) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_28 > 31) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_29 > 27) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001410_12 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_30 > 22) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001410_7 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_31 > 43) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_32 > 36) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_33 > 26) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001410_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001410_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001410_18 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_36 > 24) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_37 > 23) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_38 > 21) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001410_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001410_2 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_40 > 31) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001410_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001410_12 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_42 > 21) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_43 > 46) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_44 > 40) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001410_3 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_45 > 24) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_46 > 48) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001410_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001410_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001410_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_50 > 22) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_51 > 31) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_52 > 44) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001410_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001410_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001410_13 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001410_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001410_11 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_57 > 44) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_58 > 41) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001410_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001410_4 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_60 > 29) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001410_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001410_4 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_62 > 25) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001410_1 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_63 > 38) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_64 > 36) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_65 > 29) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001410_10 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_66 > 43) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_67 > 41) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_68 > 49) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001410_15 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_69 > 46) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_70 > 44) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_71 > 36) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001410_2 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_72 > 36) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_73 > 41) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001410_15 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_74 > 44) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001410_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_76 > 31) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001410_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_78 > 44) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_79 > 37) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_80 > 25) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_81 > 50) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_82 > 27) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001410_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_73 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_84 > 33) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_85 > 38) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_86 > 27) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_87 > 39) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_88 > 20) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001410_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_90 > 37) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_91 > 29) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001410_4) & 127;
    if (stage_v_92 > 39) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_93 > 30) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_94 > 23) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001410_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_96 > 24) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r001410_2 ^ 0x2A) * 2 + pub_r001410_2) & 127;
    if (stage_v_97 > 31) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_98 > 37) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001410_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001410_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001410_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_102 > 31) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001410_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001410_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001410_4) & 127;
    if (stage_v_105 > 43) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_106 > 46) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_107 > 45) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_108 > 38) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_109 > 24) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_110 > 33) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_111 > 32) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001410_2) & 127;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r001410_3 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_113 > 50) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_114 > 47) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001410_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001410_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_117 > 34) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001410_13 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_118 > 32) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001410_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_120 > 39) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_121 > 41) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001410_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001410_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_124 > 45) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_125 > 49) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_126 > 30) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_127 > 33) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_128 > 33) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001410_13 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_129 > 37) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001410_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_131 > 38) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001410_17 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_132 > 45) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_133 > 20) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_134 > 42) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001410_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_136 > 37) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001410_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001410_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_139 > 31) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_140 > 44) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_141 > 25) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_142 > 46) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001410_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_144 > 49) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_145 > 38) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_146 > 22) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_147 > 43) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001410_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_150 > 21) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r001410_12 ^ 0x2A) * 2 + pub_r001410_4) & 127;
    if (stage_v_151 > 46) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_70 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_153 > 27) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001410_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_155 > 25) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_156 > 29) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_157 > 23) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001410_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_159 > 41) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001410_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_161 > 36) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_162 > 30) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_163 > 48) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001410_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_165 > 50) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001410_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001410_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001410_3) & 127;
    if (stage_v_168 > 36) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001410_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001410_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001410_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_172 > 31) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001410_4) & 127;
    if (stage_v_173 > 21) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001410_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001410_11) & 127;
    if (stage_v_175 > 30) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001410_17 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_176 > 23) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001410_17 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_177 > 37) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001410_14 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_178 > 50) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_179 > 48) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_180 > 27) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001410_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001410_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_183 > 22) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001410_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_185 > 21) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_186 > 39) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_163 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_187 > 44) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_188 > 27) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001410_0 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_190 > 42) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001410_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001410_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_193 > 40) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_194 > 35) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001410_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_196 > 24) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001410_3 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_161 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_198 > 38) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_199 > 41) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001410_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_145 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_201 > 20) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001410_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_203 > 50) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_204 > 20) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_205 > 37) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001410_2) & 127;
    if (stage_v_206 > 48) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_207 > 45) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_208 > 40) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001410_2) & 127;
    if (stage_v_209 > 50) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001410_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r001410_1 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_211 > 40) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_212 > 30) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_213 > 40) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_214 > 43) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001410_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_216 > 41) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001410_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_162 ^ 0x2A) * 2 + pub_r001410_13) & 127;
    if (stage_v_218 > 39) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_219 > 33) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_220 > 27) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001410_15) & 127;
    if (stage_v_221 > 22) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_222 > 49) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_223 > 40) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_224 > 21) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_147 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_225 > 23) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001410_2) & 127;
    if (stage_v_226 > 45) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_227 > 46) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001410_13 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001410_16) & 127;
    if (stage_v_229 > 47) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_230 > 46) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((sec_r001410_6 ^ 0x2A) * 2 + pub_r001410_5) & 127;
    if (stage_v_231 > 38) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((sec_r001410_3 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_232 > 31) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_233 > 25) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_220 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_234 > 30) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001410_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r001410_7 ^ 0x2A) * 2 + pub_r001410_14) & 127;
    if (stage_v_236 > 24) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001410_6) & 127;
    if (stage_v_237 > 26) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_221 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_238 > 50) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001410_7) & 127;
    if (stage_v_239 > 45) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001410_12) & 127;
    if (stage_v_240 > 47) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001410_9) & 127;
    if (stage_v_241 > 26) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001410_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001410_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001410_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001410_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_229 ^ 0x2A) * 2 + pub_r001410_0) & 127;
    if (stage_v_246 > 30) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_247 > 38) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001410_17) & 127;
    if (stage_v_248 > 31) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_249 > 33) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001410_8) & 127;
    if (stage_v_250 > 30) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_251 > 25) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_221 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_252 > 21) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001410_18) & 127;
    if (stage_v_253 > 39) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_180 ^ 0x2A) * 2 + pub_r001410_1) & 127;
    if (stage_v_254 > 39) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001410_10) & 127;
    if (stage_v_255 > 28) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
