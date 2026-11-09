/*
 * Benchmark Program: R001390
 * Security Family: mixed_control_data
 * Generator Seed: 639013
 * High Inputs: 20 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001390_9013_0 {
    int sample_rate;
    int gain;
    short envelope;
    unsigned char peak;
    int channels;
    int rms;
    int buffer[3];
};

struct DeviceConfig_R001390_9013_1 {
    int baud_rate;
    short id;
    short port;
    int timeout;
    int parity;
    int stop_bits;
    int buffer[3];
};

struct CipherContext_R001390_9013_2 {
    int tag;
    int flags;
    int iv;
    int buffer[3];
};

union RegisterBank_R001390_9013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001390_9013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001390_9013_0(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001390_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int factor_34 = local_arr[aux % 3];
    acc = (acc + factor_34 * 2) & 127;
    int residue_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_13) & 63;
    acc ^= aux;
    int tally_42 = 0;
    for (int k = 0; k < 2; k++) {
        tally_42 = (tally_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_42) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_1(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001390_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int delta_10 = (aux + st.buffer[1]) & 3;
    switch (delta_10) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_33 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_33 > 23) {
        acc = (acc + weight_33 * 2 + 5) & 127;
        aux ^= (weight_33 & 15);
    } else {
        acc = (acc - weight_33 + 11) & 127;
        aux += 3;
    }
    int index_reg_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_92) & 63;
    acc ^= aux;
    int bound_64 = 0;
    for (int k = 0; k < 2; k++) {
        bound_64 = (bound_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_2(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001390_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_23 = (aux + st.buffer[1]) & 3;
    switch (cursor_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_71 = 0;
    for (int k = 0; k < 2; k++) {
        offset_71 = (offset_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_71) & 127;
    }
    int window_66 = (st.buffer[0] * 3 + aux) & 63;
    if (window_66 > 14) {
        acc = (acc + window_66 * 2 + 5) & 127;
        aux ^= (window_66 & 15);
    } else {
        acc = (acc - window_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_4(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_65 = (aux + st.buffer[1]) & 3;
    switch (segment_65) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001390_9013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quantum_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_40) & 63;
    acc ^= aux;
    int tally_58 = (aux + st.buffer[1]) & 3;
    switch (tally_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_6(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001390_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_61 = 0;
    for (int k = 0; k < 2; k++) {
        offset_61 = (offset_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_61) & 127;
    }
    int metric_16 = (aux + st.buffer[1]) & 3;
    switch (metric_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001390_9013_7(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001390_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_90 = (aux + st.buffer[1]) & 3;
    switch (index_reg_90) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_84 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_84 > 24) {
        acc = (acc + accumulator_84 * 2 + 5) & 127;
        aux ^= (accumulator_84 & 15);
    } else {
        acc = (acc - accumulator_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001390_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int index_reg_37 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_37 > 46) {
        acc = (acc + index_reg_37 * 2 + 5) & 127;
        aux ^= (index_reg_37 & 15);
    } else {
        acc = (acc - index_reg_37 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int accumulator_78 = (aux + st.buffer[1]) & 3;
    switch (accumulator_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_97 = local_arr[aux % 3];
    acc = (acc + anchor_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_10(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_14 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_14 = (anchor_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_14) & 127;
    }
    int metric_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_32) & 63;
    acc ^= aux;
    int coefficient_14 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_14 > 49) {
        acc = (acc + coefficient_14 * 2 + 5) & 127;
        aux ^= (coefficient_14 & 15);
    } else {
        acc = (acc - coefficient_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_63 = local_arr[aux % 3];
    acc = (acc + factor_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001390_9013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quotient_44 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_44 = (quotient_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_44) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_58 = local_arr[aux % 3];
    acc = (acc + window_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_37) & 63;
    acc ^= aux;
    int stride_66 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_66 > 37) {
        acc = (acc + stride_66 * 2 + 5) & 127;
        aux ^= (stride_66 & 15);
    } else {
        acc = (acc - stride_66 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_20 = local_arr[aux % 3];
    acc = (acc + margin_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int offset_92 = local_arr[aux % 3];
    acc = (acc + offset_92 * 2) & 127;
    int pivot_25 = (aux + st.buffer[1]) & 3;
    switch (pivot_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int offset_96 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_96 > 45) {
        acc = (acc + offset_96 * 2 + 5) & 127;
        aux ^= (offset_96 & 15);
    } else {
        acc = (acc - offset_96 + 11) & 127;
        aux += 3;
    }
    int quotient_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001390_9013_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001390_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int sample_37 = local_arr[aux % 3];
    acc = (acc + sample_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_35 = (aux + st.buffer[1]) & 3;
    switch (anchor_35) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_79 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_79 > 46) {
        acc = (acc + bound_79 * 2 + 5) & 127;
        aux ^= (bound_79 & 15);
    } else {
        acc = (acc - bound_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_15(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001390_9013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int mask_56 = local_arr[aux % 3];
    acc = (acc + mask_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001390_9013_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001390_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int threshold_58 = local_arr[aux % 3];
    acc = (acc + threshold_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001390_9013_17(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001390_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int cursor_78 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_78 = (cursor_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_78) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_54 = (aux + st.buffer[1]) & 3;
    switch (tracker_54) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001390_9013_18(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001390_9013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_58 = local_arr[aux % 3];
    acc = (acc + stride_58 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001390_0;
    int sec_r001390_1;
    int sec_r001390_2;
    int sec_r001390_3;
    int sec_r001390_4;
    int sec_r001390_5;
    int sec_r001390_6;
    int sec_r001390_7;
    int sec_r001390_8;
    int sec_r001390_9;
    int sec_r001390_10;
    int sec_r001390_11;
    int sec_r001390_12;
    int sec_r001390_13;
    int sec_r001390_14;
    int sec_r001390_15;
    int sec_r001390_16;
    int sec_r001390_17;
    int sec_r001390_18;
    int sec_r001390_19;
    int pub_r001390_0;
    int pub_r001390_1;
    int pub_r001390_2;
    int pub_r001390_3;
    int pub_r001390_4;
    int pub_r001390_5;
    int pub_r001390_6;
    int pub_r001390_7;
    int pub_r001390_8;
    int pub_r001390_9;
    int pub_r001390_10;
    int pub_r001390_11;
    int pub_r001390_12;
    int pub_r001390_13;
    int pub_r001390_14;
    int pub_r001390_15;
    int pub_r001390_16;
    int pub_r001390_17;
    int pub_r001390_18;
    int pub_r001390_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001390_0 >= -100 && pub_r001390_0 <= 100);
    __CPROVER_assume(pub_r001390_1 >= -100 && pub_r001390_1 <= 100);
    __CPROVER_assume(pub_r001390_2 >= -100 && pub_r001390_2 <= 100);
    __CPROVER_assume(pub_r001390_3 >= -100 && pub_r001390_3 <= 100);
    __CPROVER_assume(pub_r001390_4 >= -100 && pub_r001390_4 <= 100);
    __CPROVER_assume(pub_r001390_5 >= -100 && pub_r001390_5 <= 100);
    __CPROVER_assume(pub_r001390_6 >= -100 && pub_r001390_6 <= 100);
    __CPROVER_assume(pub_r001390_7 >= -100 && pub_r001390_7 <= 100);
    __CPROVER_assume(pub_r001390_8 >= -100 && pub_r001390_8 <= 100);
    __CPROVER_assume(pub_r001390_9 >= -100 && pub_r001390_9 <= 100);
    __CPROVER_assume(pub_r001390_10 >= -100 && pub_r001390_10 <= 100);
    __CPROVER_assume(pub_r001390_11 >= -100 && pub_r001390_11 <= 100);
    __CPROVER_assume(pub_r001390_12 >= -100 && pub_r001390_12 <= 100);
    __CPROVER_assume(pub_r001390_13 >= -100 && pub_r001390_13 <= 100);
    __CPROVER_assume(pub_r001390_14 >= -100 && pub_r001390_14 <= 100);
    __CPROVER_assume(pub_r001390_15 >= -100 && pub_r001390_15 <= 100);
    __CPROVER_assume(pub_r001390_16 >= -100 && pub_r001390_16 <= 100);
    __CPROVER_assume(pub_r001390_17 >= -100 && pub_r001390_17 <= 100);
    __CPROVER_assume(pub_r001390_18 >= -100 && pub_r001390_18 <= 100);
    __CPROVER_assume(pub_r001390_19 >= -100 && pub_r001390_19 <= 100);
    __CPROVER_assume(sec_r001390_0 >= 0 && sec_r001390_0 <= 255);
    __CPROVER_assume(sec_r001390_1 >= 0 && sec_r001390_1 <= 255);
    __CPROVER_assume(sec_r001390_2 >= 0 && sec_r001390_2 <= 255);
    __CPROVER_assume(sec_r001390_3 >= 0 && sec_r001390_3 <= 255);
    __CPROVER_assume(sec_r001390_4 >= 0 && sec_r001390_4 <= 255);
    __CPROVER_assume(sec_r001390_5 >= 0 && sec_r001390_5 <= 255);
    __CPROVER_assume(sec_r001390_6 >= 0 && sec_r001390_6 <= 255);
    __CPROVER_assume(sec_r001390_7 >= 0 && sec_r001390_7 <= 255);
    __CPROVER_assume(sec_r001390_8 >= 0 && sec_r001390_8 <= 255);
    __CPROVER_assume(sec_r001390_9 >= 0 && sec_r001390_9 <= 255);
    __CPROVER_assume(sec_r001390_10 >= 0 && sec_r001390_10 <= 255);
    __CPROVER_assume(sec_r001390_11 >= 0 && sec_r001390_11 <= 255);
    __CPROVER_assume(sec_r001390_12 >= 0 && sec_r001390_12 <= 255);
    __CPROVER_assume(sec_r001390_13 >= 0 && sec_r001390_13 <= 255);
    __CPROVER_assume(sec_r001390_14 >= 0 && sec_r001390_14 <= 255);
    __CPROVER_assume(sec_r001390_15 >= 0 && sec_r001390_15 <= 255);
    __CPROVER_assume(sec_r001390_16 >= 0 && sec_r001390_16 <= 255);
    __CPROVER_assume(sec_r001390_17 >= 0 && sec_r001390_17 <= 255);
    __CPROVER_assume(sec_r001390_18 >= 0 && sec_r001390_18 <= 255);
    __CPROVER_assume(sec_r001390_19 >= 0 && sec_r001390_19 <= 255);

    struct AudioFrame_R001390_9013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001390_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001390_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001390_0 + 7) & 15;
    struct DeviceConfig_R001390_9013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001390_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001390_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001390_0 + 9) & 15;
    struct CipherContext_R001390_9013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001390_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001390_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001390_0 + 11) & 15;

    union RegisterBank_R001390_9013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001390_9013_0(sec_r001390_0, pub_r001390_1);
    int helper_flow_1 = fn_R001390_9013_1(sec_r001390_1, sec_r001390_2, pub_r001390_3);
    int helper_flow_2 = fn_R001390_9013_2(sec_r001390_2, sec_r001390_3, pub_r001390_4);
    int helper_flow_3 = fn_R001390_9013_3(sec_r001390_3, pub_r001390_4, pub_r001390_5, pub_r001390_6, pub_r001390_7);
    int helper_flow_4 = fn_R001390_9013_4(sec_r001390_4, pub_r001390_5);
    int helper_flow_5 = fn_R001390_9013_5(sec_r001390_5, pub_r001390_6, pub_r001390_7, pub_r001390_8);
    int helper_flow_6 = fn_R001390_9013_6(sec_r001390_6, sec_r001390_7, pub_r001390_8);
    int helper_flow_7 = fn_R001390_9013_7(sec_r001390_7, pub_r001390_8, pub_r001390_9);
    int helper_flow_8 = fn_R001390_9013_8(sec_r001390_8, sec_r001390_9, pub_r001390_10, pub_r001390_11, pub_r001390_12);
    int helper_flow_9 = fn_R001390_9013_9(sec_r001390_9, pub_r001390_10, pub_r001390_11, pub_r001390_12, pub_r001390_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_0 > 45) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001390_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001390_16 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_2 > 43) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_3 > 42) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001390_2 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_4 > 22) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001390_4 ^ 0x2A) * 2 + pub_r001390_14) & 127;
    if (stage_v_5 > 20) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_6 > 20) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_7 > 30) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001390_13 ^ 0x2A) * 2 + pub_r001390_3) & 127;
    if (stage_v_8 > 46) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001390_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_10 > 47) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_11 > 32) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001390_10 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_12 > 25) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_13 > 22) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001390_14 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_14 > 42) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((sec_r001390_17 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_15 > 31) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_16 > 29) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001390_15 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_17 > 49) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001390_9 ^ 0x2A) * 2 + pub_r001390_14) & 127;
    if (stage_v_18 > 20) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001390_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001390_0 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_20 > 27) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_21 > 44) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001390_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001390_4 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_23 > 20) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001390_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_25 > 46) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_26 > 38) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001390_17 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_27 > 32) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_28 > 30) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((sec_r001390_17 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_29 > 46) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_30 > 38) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001390_2 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_31 > 47) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001390_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_33 > 49) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001390_9 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_34 > 49) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_35 > 27) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_36 > 24) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001390_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_38 > 39) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001390_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001390_1 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_40 > 32) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001390_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_42 > 44) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001390_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001390_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_45 > 38) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_46 > 24) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001390_14) & 127;
    if (stage_v_47 > 45) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r001390_19 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_48 > 42) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001390_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001390_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001390_13 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_51 > 28) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_52 > 44) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_53 > 30) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_54 > 28) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001390_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_56 > 26) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001390_7 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_57 > 25) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_58 > 20) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001390_16 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_59 > 49) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r001390_14 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_60 > 36) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_61 > 35) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001390_3) & 127;
    if (stage_v_62 > 42) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_63 > 23) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001390_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001390_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001390_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001390_4 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_67 > 24) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_68 > 30) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_69 > 35) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_70 > 27) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_71 > 43) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001390_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_73 > 30) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001390_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001390_19 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_75 > 29) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001390_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001390_6 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_77 > 25) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_78 > 25) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001390_1 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_79 > 32) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_80 > 24) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001390_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001390_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_83 > 38) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001390_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_85 > 24) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_86 > 39) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_87 > 33) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001390_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_89 > 23) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r001390_7 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_90 > 26) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001390_15 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_91 > 28) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_92 > 37) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001390_17 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_93 > 24) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001390_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_95 > 31) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_96 > 25) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_97 > 45) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001390_16 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001390_6 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_99 > 23) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001390_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001390_1 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_101 > 47) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001390_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001390_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001390_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001390_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_106 > 24) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_107 > 35) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001390_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001390_2 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_109 > 28) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001390_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_111 > 21) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_112 > 44) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_113 > 50) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_114 > 37) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_115 > 34) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001390_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_117 > 35) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_118 > 45) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_119 > 50) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_120 > 34) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_121 > 44) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001390_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_123 > 44) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_124 > 30) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_125 > 25) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_126 > 43) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_127 > 32) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_128 > 23) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001390_17 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_129 > 37) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_130 > 43) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_106 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_131 > 24) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_132 > 28) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((sec_r001390_1 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_133 > 45) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_134 > 35) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_135 > 33) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_136 > 28) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_137 > 21) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_137 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_138 > 23) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_139 > 22) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_140 > 47) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001390_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001390_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_143 > 23) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_144 > 40) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_145 > 43) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_146 > 37) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001390_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_148 > 31) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_149 > 46) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r001390_1 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_150 > 23) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_151 > 39) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_152 > 38) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_153 > 36) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_154 > 33) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_155 > 39) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001390_3) & 127;
    if (stage_v_156 > 40) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_157 > 20) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001390_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r001390_15 ^ 0x2A) * 2 + pub_r001390_3) & 127;
    if (stage_v_159 > 49) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_160 > 43) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001390_13) & 127;
    if (stage_v_161 > 21) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_162 > 24) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001390_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_164 > 48) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_165 > 30) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_166 > 25) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_167 > 23) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_168 > 42) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_169 > 50) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_170 > 22) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_171 > 44) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_172 > 47) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001390_3) & 127;
    if (stage_v_173 > 42) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001390_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001390_18 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_176 > 28) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001390_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_179 > 42) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_180 > 34) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001390_6) & 127;
    if (stage_v_181 > 33) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001390_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_183 > 37) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_184 > 29) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_185 > 33) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001390_3) & 127;
    if (stage_v_186 > 38) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001390_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_188 > 32) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_189 > 45) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001390_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_90 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_191 > 20) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_87 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_192 > 20) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_193 > 48) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_194 > 31) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_194 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_195 > 46) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_189 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_196 > 38) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001390_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_198 > 35) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001390_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001390_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001390_2) & 127;
    if (stage_v_201 > 50) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_202 > 35) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_203 > 28) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_188 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_204 > 23) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001390_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001390_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_207 > 20) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001390_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r001390_1 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_209 > 26) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_210 > 31) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001390_14) & 127;
    if (stage_v_211 > 28) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001390_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001390_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001390_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_215 > 34) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_216 > 50) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001390_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((sec_r001390_9 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_218 > 49) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_219 > 50) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001390_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001390_3 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_222 > 25) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001390_4) & 127;
    if (stage_v_223 > 25) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001390_19) & 127;
    if (stage_v_224 > 43) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_225 > 34) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_226 > 29) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001390_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_228 > 20) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_229 > 42) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_67 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_230 > 44) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_231 > 25) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_232 > 25) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r001390_8 ^ 0x2A) * 2 + pub_r001390_8) & 127;
    if (stage_v_233 > 27) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001390_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001390_9) & 127;
    if (stage_v_235 > 39) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_236 > 23) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001390_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001390_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001390_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_210 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_240 > 36) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001390_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001390_9 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_242 > 25) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001390_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001390_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_245 > 38) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_152 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_246 > 45) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((sec_r001390_16 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_247 > 22) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001390_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001390_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001390_19 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001390_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r001390_9 ^ 0x2A) * 2 + pub_r001390_1) & 127;
    if (stage_v_252 > 27) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r001390_3 ^ 0x2A) * 2 + pub_r001390_7) & 127;
    if (stage_v_253 > 22) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001390_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_193 ^ 0x2A) * 2 + pub_r001390_0) & 127;
    if (stage_v_255 > 40) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_256 > 37) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_257 > 44) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001390_16) & 127;
    if (stage_v_258 > 47) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001390_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001390_15) & 127;
    if (stage_v_260 > 36) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (pub_r001390_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_261) & 127;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_262 > 48) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001390_5) & 127;
    if (stage_v_263 > 30) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001390_11) & 127;
    if (stage_v_264 > 24) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_240 ^ 0x2A) * 2 + pub_r001390_18) & 127;
    if (stage_v_265 > 42) {
        out_sink = (out_sink + stage_v_265 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_265 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001390_17) & 127;
    if (stage_v_266 > 24) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_51 ^ 0x2A) * 2 + pub_r001390_10) & 127;
    if (stage_v_267 > 46) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r001390_13 ^ 0x2A) * 2 + pub_r001390_12) & 127;
    if (stage_v_268 > 50) {
        out_sink = (out_sink + stage_v_268 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_268 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_268) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
