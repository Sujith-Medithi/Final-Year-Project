/*
 * Benchmark Program: R001066
 * Security Family: implicit_flow
 * Generator Seed: 606613
 * High Inputs: 17 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R001066_6613_0 {
    unsigned char envelope;
    short channels;
    int rms;
    int sample_rate;
    short peak;
    int buffer[3];
};

struct DeviceConfig_R001066_6613_1 {
    unsigned char port;
    short baud_rate;
    unsigned char parity;
    short stop_bits;
    int id;
    unsigned char timeout;
    int buffer[3];
};

union PacketPayload_R001066_6613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001066_6613_0(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quotient_94 = (aux + st.buffer[1]) & 3;
    switch (quotient_94) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_98 = local_arr[aux % 3];
    acc = (acc + cursor_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001066_6613_1(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_60 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_60 > 48) {
        acc = (acc + phase_60 * 2 + 5) & 127;
        aux ^= (phase_60 & 15);
    } else {
        acc = (acc - phase_60 + 11) & 127;
        aux += 3;
    }
    int scale_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001066_6613_2(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_25) & 63;
    acc ^= aux;
    int sample_65 = (aux + st.buffer[1]) & 3;
    switch (sample_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_18 = local_arr[aux % 3];
    acc = (acc + mask_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001066_6613_3(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int residue_57 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_57 > 17) {
        acc = (acc + residue_57 * 2 + 5) & 127;
        aux ^= (residue_57 & 15);
    } else {
        acc = (acc - residue_57 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_51 = local_arr[aux % 3];
    acc = (acc + anchor_51 * 2) & 127;
    int pivot_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001066_6613_4(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int segment_58 = 0;
    for (int k = 0; k < 2; k++) {
        segment_58 = (segment_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_58) & 127;
    }
    int checksum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_79 > 30) {
        acc = (acc + checksum_79 * 2 + 5) & 127;
        aux ^= (checksum_79 & 15);
    } else {
        acc = (acc - checksum_79 + 11) & 127;
        aux += 3;
    }
    int anchor_49 = (aux + st.buffer[1]) & 3;
    switch (anchor_49) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_40 = local_arr[aux % 3];
    acc = (acc + parity_40 * 2) & 127;
    int anchor_57 = (aux + st.buffer[1]) & 3;
    switch (anchor_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_6(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int margin_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_64) & 63;
    acc ^= aux;
    int parity_28 = (aux + st.buffer[1]) & 3;
    switch (parity_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_13 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_13 > 18) {
        acc = (acc + segment_13 * 2 + 5) & 127;
        aux ^= (segment_13 & 15);
    } else {
        acc = (acc - segment_13 + 11) & 127;
        aux += 3;
    }
    int quantum_22 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_22 = (quantum_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_8(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_94 = 0;
    for (int k = 0; k < 2; k++) {
        scale_94 = (scale_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_94) & 127;
    }
    int pivot_50 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_50 > 25) {
        acc = (acc + pivot_50 * 2 + 5) & 127;
        aux ^= (pivot_50 & 15);
    } else {
        acc = (acc - pivot_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_9(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int sample_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_28) & 63;
    acc ^= aux;
    int accumulator_87 = (aux + st.buffer[1]) & 3;
    switch (accumulator_87) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_79 = 0;
    for (int k = 0; k < 2; k++) {
        delta_79 = (delta_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_79) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_75 = local_arr[aux % 3];
    acc = (acc + weight_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001066_6613_10(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int offset_37 = local_arr[aux % 3];
    acc = (acc + offset_37 * 2) & 127;
    int bound_58 = (aux + st.buffer[1]) & 3;
    switch (bound_58) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_29 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_29 > 47) {
        acc = (acc + quantum_29 * 2 + 5) & 127;
        aux ^= (quantum_29 & 15);
    } else {
        acc = (acc - quantum_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_11(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int parity_12 = local_arr[aux % 3];
    acc = (acc + parity_12 * 2) & 127;
    int scale_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_61) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001066_6613_12(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_54 > 25) {
        acc = (acc + factor_54 * 2 + 5) & 127;
        aux ^= (factor_54 & 15);
    } else {
        acc = (acc - factor_54 + 11) & 127;
        aux += 3;
    }
    int mask_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_50) & 63;
    acc ^= aux;
    int tracker_94 = (aux + st.buffer[1]) & 3;
    switch (tracker_94) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_13(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int bound_91 = (aux + st.buffer[1]) & 3;
    switch (bound_91) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_16 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_16 > 27) {
        acc = (acc + anchor_16 * 2 + 5) & 127;
        aux ^= (anchor_16 & 15);
    } else {
        acc = (acc - anchor_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_14(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_99 = (aux + st.buffer[1]) & 3;
    switch (cursor_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_15(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_21 = local_arr[aux % 3];
    acc = (acc + weight_21 * 2) & 127;
    int bound_37 = 0;
    for (int k = 0; k < 3; k++) {
        bound_37 = (bound_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_37) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_16(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001066_6613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int pivot_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_67) & 63;
    acc ^= aux;
    int coefficient_79 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_79 = (coefficient_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_79) & 127;
    }
    int weight_94 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_94 > 44) {
        acc = (acc + weight_94 * 2 + 5) & 127;
        aux ^= (weight_94 & 15);
    } else {
        acc = (acc - weight_94 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int sample_72 = 0;
    for (int k = 0; k < 3; k++) {
        sample_72 = (sample_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_72) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_10) & 63;
    acc ^= aux;
    int quotient_73 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_73 > 13) {
        acc = (acc + quotient_73 * 2 + 5) & 127;
        aux ^= (quotient_73 & 15);
    } else {
        acc = (acc - quotient_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001066_6613_18(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001066_6613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int tally_21 = local_arr[aux % 3];
    acc = (acc + tally_21 * 2) & 127;
    int margin_21 = 0;
    for (int k = 0; k < 2; k++) {
        margin_21 = (margin_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_21) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001066_0;
    int sec_r001066_1;
    int sec_r001066_2;
    int sec_r001066_3;
    int sec_r001066_4;
    int sec_r001066_5;
    int sec_r001066_6;
    int sec_r001066_7;
    int sec_r001066_8;
    int sec_r001066_9;
    int sec_r001066_10;
    int sec_r001066_11;
    int sec_r001066_12;
    int sec_r001066_13;
    int sec_r001066_14;
    int sec_r001066_15;
    int sec_r001066_16;
    int pub_r001066_0;
    int pub_r001066_1;
    int pub_r001066_2;
    int pub_r001066_3;
    int pub_r001066_4;
    int pub_r001066_5;
    int pub_r001066_6;
    int pub_r001066_7;
    int pub_r001066_8;
    int pub_r001066_9;
    int pub_r001066_10;
    int pub_r001066_11;
    int pub_r001066_12;
    int pub_r001066_13;
    int pub_r001066_14;
    int pub_r001066_15;
    int pub_r001066_16;
    int pub_r001066_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001066_0 >= -100 && pub_r001066_0 <= 100);
    __CPROVER_assume(pub_r001066_1 >= -100 && pub_r001066_1 <= 100);
    __CPROVER_assume(pub_r001066_2 >= -100 && pub_r001066_2 <= 100);
    __CPROVER_assume(pub_r001066_3 >= -100 && pub_r001066_3 <= 100);
    __CPROVER_assume(pub_r001066_4 >= -100 && pub_r001066_4 <= 100);
    __CPROVER_assume(pub_r001066_5 >= -100 && pub_r001066_5 <= 100);
    __CPROVER_assume(pub_r001066_6 >= -100 && pub_r001066_6 <= 100);
    __CPROVER_assume(pub_r001066_7 >= -100 && pub_r001066_7 <= 100);
    __CPROVER_assume(pub_r001066_8 >= -100 && pub_r001066_8 <= 100);
    __CPROVER_assume(pub_r001066_9 >= -100 && pub_r001066_9 <= 100);
    __CPROVER_assume(pub_r001066_10 >= -100 && pub_r001066_10 <= 100);
    __CPROVER_assume(pub_r001066_11 >= -100 && pub_r001066_11 <= 100);
    __CPROVER_assume(pub_r001066_12 >= -100 && pub_r001066_12 <= 100);
    __CPROVER_assume(pub_r001066_13 >= -100 && pub_r001066_13 <= 100);
    __CPROVER_assume(pub_r001066_14 >= -100 && pub_r001066_14 <= 100);
    __CPROVER_assume(pub_r001066_15 >= -100 && pub_r001066_15 <= 100);
    __CPROVER_assume(pub_r001066_16 >= -100 && pub_r001066_16 <= 100);
    __CPROVER_assume(pub_r001066_17 >= -100 && pub_r001066_17 <= 100);
    __CPROVER_assume(sec_r001066_0 >= 0 && sec_r001066_0 <= 255);
    __CPROVER_assume(sec_r001066_1 >= 0 && sec_r001066_1 <= 255);
    __CPROVER_assume(sec_r001066_2 >= 0 && sec_r001066_2 <= 255);
    __CPROVER_assume(sec_r001066_3 >= 0 && sec_r001066_3 <= 255);
    __CPROVER_assume(sec_r001066_4 >= 0 && sec_r001066_4 <= 255);
    __CPROVER_assume(sec_r001066_5 >= 0 && sec_r001066_5 <= 255);
    __CPROVER_assume(sec_r001066_6 >= 0 && sec_r001066_6 <= 255);
    __CPROVER_assume(sec_r001066_7 >= 0 && sec_r001066_7 <= 255);
    __CPROVER_assume(sec_r001066_8 >= 0 && sec_r001066_8 <= 255);
    __CPROVER_assume(sec_r001066_9 >= 0 && sec_r001066_9 <= 255);
    __CPROVER_assume(sec_r001066_10 >= 0 && sec_r001066_10 <= 255);
    __CPROVER_assume(sec_r001066_11 >= 0 && sec_r001066_11 <= 255);
    __CPROVER_assume(sec_r001066_12 >= 0 && sec_r001066_12 <= 255);
    __CPROVER_assume(sec_r001066_13 >= 0 && sec_r001066_13 <= 255);
    __CPROVER_assume(sec_r001066_14 >= 0 && sec_r001066_14 <= 255);
    __CPROVER_assume(sec_r001066_15 >= 0 && sec_r001066_15 <= 255);
    __CPROVER_assume(sec_r001066_16 >= 0 && sec_r001066_16 <= 255);

    struct AudioFrame_R001066_6613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001066_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001066_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001066_0 + 7) & 15;
    struct DeviceConfig_R001066_6613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001066_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001066_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001066_0 + 9) & 15;

    union PacketPayload_R001066_6613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001066_6613_0(sec_r001066_0, pub_r001066_1);
    int helper_flow_1 = fn_R001066_6613_1(sec_r001066_1, pub_r001066_2);
    int helper_flow_2 = fn_R001066_6613_2(sec_r001066_2, sec_r001066_3, pub_r001066_4);
    int helper_flow_3 = fn_R001066_6613_3(sec_r001066_3, pub_r001066_4, pub_r001066_5);
    int helper_flow_4 = fn_R001066_6613_4(sec_r001066_4, pub_r001066_5);
    int helper_flow_5 = fn_R001066_6613_5(sec_r001066_5, pub_r001066_6, pub_r001066_7, pub_r001066_8, pub_r001066_9);
    int helper_flow_6 = fn_R001066_6613_6(sec_r001066_6, sec_r001066_7);
    int helper_flow_7 = fn_R001066_6613_7(sec_r001066_7, pub_r001066_8, pub_r001066_9, pub_r001066_10, pub_r001066_11);
    int helper_flow_8 = fn_R001066_6613_8(sec_r001066_8, pub_r001066_9, pub_r001066_10);
    int helper_flow_9 = fn_R001066_6613_9(sec_r001066_9, pub_r001066_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001066_0 + pub_r001066_2 * 2 + 5) & 127;
    if (stage_v_0 > 21) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001066_0 + pub_r001066_6 * 2 + 8) & 127;
    if (stage_v_1 > 48) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001066_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_6 + pub_r001066_1 * 2 + 14) & 127;
    if (stage_v_3 > 50) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001066_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001066_7 + pub_r001066_8 * 2 + 20) & 127;
    if (stage_v_5 > 34) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001066_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001066_3 + pub_r001066_2 * 2 + 26) & 127;
    if (stage_v_7 > 42) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001066_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_1 + pub_r001066_12 * 2 + 32) & 127;
    if (stage_v_9 > 45) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001066_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (stage_v_0 + pub_r001066_8 * 2 + 38) & 127;
    if (stage_v_11 > 51) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001066_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001066_13 + pub_r001066_10 * 2 + 44) & 127;
    if (stage_v_13 > 28) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001066_15 + pub_r001066_5 * 2 + 47) & 127;
    if (stage_v_14 > 52) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_4 + pub_r001066_0 * 2 + 50) & 127;
    if (stage_v_15 > 33) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_0 + pub_r001066_14 * 2 + 53) & 127;
    if (stage_v_16 > 28) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001066_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001066_0 + pub_r001066_1 * 2 + 59) & 127;
    if (stage_v_18 > 59) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_5 + pub_r001066_15 * 2 + 62) & 127;
    if (stage_v_19 > 36) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001066_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_4 + pub_r001066_11 * 2 + 68) & 127;
    if (stage_v_21 > 49) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (helper_flow_5 + pub_r001066_14 * 2 + 71) & 127;
    if (stage_v_22 > 34) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001066_0 + pub_r001066_16 * 2 + 74) & 127;
    if (stage_v_23 > 18) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001066_2 + pub_r001066_8 * 2 + 77) & 127;
    if (stage_v_24 > 54) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_5 + pub_r001066_2 * 2 + 80) & 127;
    if (stage_v_25 > 33) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001066_16 + pub_r001066_0 * 2 + 83) & 127;
    if (stage_v_26 > 54) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_23 + pub_r001066_4 * 2 + 86) & 127;
    if (stage_v_27 > 26) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (stage_v_0 + pub_r001066_6 * 2 + 89) & 127;
    if (stage_v_28 > 58) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
        sec_accum ^= (stage_v_28 & 31);
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001066_0 + pub_r001066_12 * 2 + 92) & 127;
    if (stage_v_29 > 15) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (helper_flow_7 + pub_r001066_17 * 2 + 95) & 127;
    if (stage_v_30 > 30) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_2 + pub_r001066_17 * 2 + 98) & 127;
    if (stage_v_31 > 47) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_0 + pub_r001066_12 * 2 + 101) & 127;
    if (stage_v_32 > 58) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_32 + pub_r001066_1 * 2 + 104) & 127;
    if (stage_v_33 > 20) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001066_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (helper_flow_7 + pub_r001066_9 * 2 + 110) & 127;
    if (stage_v_35 > 46) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001066_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001066_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_19 + pub_r001066_14 * 2 + 119) & 127;
    if (stage_v_38 > 31) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_18 + pub_r001066_8 * 2 + 122) & 127;
    if (stage_v_39 > 39) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_5 + pub_r001066_2 * 2 + 125) & 127;
    if (stage_v_40 > 49) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_30 + pub_r001066_1 * 2 + 128) & 127;
    if (stage_v_41 > 26) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_9 + pub_r001066_12 * 2 + 131) & 127;
    if (stage_v_42 > 33) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
        sec_accum ^= (stage_v_42 & 31);
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001066_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (helper_flow_8 + pub_r001066_0 * 2 + 137) & 127;
    if (stage_v_44 > 45) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_8 + pub_r001066_14 * 2 + 140) & 127;
    if (stage_v_45 > 25) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001066_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_33 + pub_r001066_7 * 2 + 146) & 127;
    if (stage_v_47 > 58) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001066_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001066_14 + pub_r001066_17 * 2 + 152) & 127;
    if (stage_v_49 > 23) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001066_13 + pub_r001066_12 * 2 + 155) & 127;
    if (stage_v_50 > 29) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001066_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001066_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_39 + pub_r001066_13 * 2 + 164) & 127;
    if (stage_v_53 > 50) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_32 + pub_r001066_13 * 2 + 167) & 127;
    if (stage_v_54 > 54) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_38 + pub_r001066_0 * 2 + 170) & 127;
    if (stage_v_55 > 26) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_1 + pub_r001066_3 * 2 + 173) & 127;
    if (stage_v_56 > 23) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001066_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001066_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (helper_flow_6 + pub_r001066_2 * 2 + 182) & 127;
    if (stage_v_59 > 48) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001066_6 + pub_r001066_11 * 2 + 185) & 127;
    if (stage_v_60 > 53) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_35 + pub_r001066_15 * 2 + 188) & 127;
    if (stage_v_61 > 37) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001066_12 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001066_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001066_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001066_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001066_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001066_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r001066_11 + pub_r001066_15 * 2 + 209) & 127;
    if (stage_v_68 > 21) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_30 + pub_r001066_15 * 2 + 212) & 127;
    if (stage_v_69 > 47) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_68 + pub_r001066_3 * 2 + 215) & 127;
    if (stage_v_70 > 29) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001066_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (helper_flow_3 + pub_r001066_12 * 2 + 221) & 127;
    if (stage_v_72 > 46) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001066_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001066_3 + pub_r001066_9 * 2 + 227) & 127;
    if (stage_v_74 > 53) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001066_14 + pub_r001066_7 * 2 + 230) & 127;
    if (stage_v_75 > 20) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_49 + pub_r001066_7 * 2 + 233) & 127;
    if (stage_v_76 > 38) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_19 + pub_r001066_15 * 2 + 236) & 127;
    if (stage_v_77 > 58) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_5 + pub_r001066_13 * 2 + 239) & 127;
    if (stage_v_78 > 45) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_74 + pub_r001066_0 * 2 + 242) & 127;
    if (stage_v_79 > 55) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001066_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_7 + pub_r001066_9 * 2 + 248) & 127;
    if (stage_v_81 > 20) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_24 + pub_r001066_2 * 2 + 251) & 127;
    if (stage_v_82 > 51) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_38 + pub_r001066_11 * 2 + 254) & 127;
    if (stage_v_83 > 36) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_9 + pub_r001066_2 * 2 + 257) & 127;
    if (stage_v_84 > 42) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001066_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001066_1 + pub_r001066_8 * 2 + 263) & 127;
    if (stage_v_86 > 28) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001066_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001066_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001066_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_0 + pub_r001066_14 * 2 + 275) & 127;
    if (stage_v_90 > 44) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (helper_flow_4 + pub_r001066_1 * 2 + 278) & 127;
    if (stage_v_91 > 36) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_68 + pub_r001066_6 * 2 + 281) & 127;
    if (stage_v_92 > 26) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_7 + pub_r001066_8 * 2 + 284) & 127;
    if (stage_v_93 > 56) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_0 + pub_r001066_7 * 2 + 287) & 127;
    if (stage_v_94 > 24) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_11 + pub_r001066_10 * 2 + 290) & 127;
    if (stage_v_95 > 43) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_19 + pub_r001066_3 * 2 + 293) & 127;
    if (stage_v_96 > 27) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001066_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_82 + pub_r001066_12 * 2 + 299) & 127;
    if (stage_v_98 > 21) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_1 + pub_r001066_8 * 2 + 302) & 127;
    if (stage_v_99 > 26) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_99 + pub_r001066_4 * 2 + 305) & 127;
    if (stage_v_100 > 25) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_55 + pub_r001066_10 * 2 + 308) & 127;
    if (stage_v_101 > 51) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001066_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_56 + pub_r001066_8 * 2 + 314) & 127;
    if (stage_v_103 > 16) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (helper_flow_0 + pub_r001066_11 * 2 + 317) & 127;
    if (stage_v_104 > 40) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001066_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (helper_flow_2 + pub_r001066_8 * 2 + 323) & 127;
    if (stage_v_106 > 20) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_103 + pub_r001066_14 * 2 + 326) & 127;
    if (stage_v_107 > 48) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001066_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001066_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001066_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_82 + pub_r001066_17 * 2 + 338) & 127;
    if (stage_v_111 > 15) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_18 + pub_r001066_2 * 2 + 341) & 127;
    if (stage_v_112 > 28) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001066_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001066_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001066_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (helper_flow_2 + pub_r001066_1 * 2 + 353) & 127;
    if (stage_v_116 > 36) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001066_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_15 + pub_r001066_8 * 2 + 359) & 127;
    if (stage_v_118 > 19) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_0 + pub_r001066_8 * 2 + 362) & 127;
    if (stage_v_119 > 47) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001066_2 + pub_r001066_13 * 2 + 365) & 127;
    if (stage_v_120 > 56) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001066_4 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001066_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001066_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_60 + pub_r001066_16 * 2 + 377) & 127;
    if (stage_v_124 > 30) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_106 + pub_r001066_11 * 2 + 380) & 127;
    if (stage_v_125 > 28) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_38 + pub_r001066_14 * 2 + 383) & 127;
    if (stage_v_126 > 16) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001066_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001066_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001066_3 + pub_r001066_0 * 2 + 392) & 127;
    if (stage_v_129 > 51) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001066_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_91 + pub_r001066_11 * 2 + 398) & 127;
    if (stage_v_131 > 22) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_38 + pub_r001066_0 * 2 + 401) & 127;
    if (stage_v_132 > 16) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001066_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_19 + pub_r001066_10 * 2 + 407) & 127;
    if (stage_v_134 > 40) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_50 + pub_r001066_17 * 2 + 410) & 127;
    if (stage_v_135 > 27) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_38 + pub_r001066_14 * 2 + 413) & 127;
    if (stage_v_136 > 30) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_0 + pub_r001066_6 * 2 + 416) & 127;
    if (stage_v_137 > 36) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_106 + pub_r001066_2 * 2 + 419) & 127;
    if (stage_v_138 > 24) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001066_2 + pub_r001066_8 * 2 + 422) & 127;
    if (stage_v_139 > 42) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_106 + pub_r001066_17 * 2 + 425) & 127;
    if (stage_v_140 > 28) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_100 + pub_r001066_9 * 2 + 428) & 127;
    if (stage_v_141 > 32) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_95 + pub_r001066_5 * 2 + 431) & 127;
    if (stage_v_142 > 51) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (sec_r001066_11 + pub_r001066_5 * 2 + 434) & 127;
    if (stage_v_143 > 21) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001066_11 + pub_r001066_6 * 2 + 437) & 127;
    if (stage_v_144 > 23) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (sec_r001066_13 + pub_r001066_17 * 2 + 440) & 127;
    if (stage_v_145 > 17) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001066_7 + pub_r001066_7 * 2 + 443) & 127;
    if (stage_v_146 > 43) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_78 + pub_r001066_3 * 2 + 446) & 127;
    if (stage_v_147 > 39) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r001066_13 + pub_r001066_5 * 2 + 449) & 127;
    if (stage_v_148 > 42) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001066_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_79 + pub_r001066_2 * 2 + 455) & 127;
    if (stage_v_150 > 50) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_38 + pub_r001066_13 * 2 + 458) & 127;
    if (stage_v_151 > 38) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001066_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (sec_r001066_14 + pub_r001066_0 * 2 + 464) & 127;
    if (stage_v_153 > 17) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001066_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_7 + pub_r001066_16 * 2 + 470) & 127;
    if (stage_v_155 > 56) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (helper_flow_5 + pub_r001066_14 * 2 + 473) & 127;
    if (stage_v_156 > 15) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (helper_flow_1 + pub_r001066_17 * 2 + 476) & 127;
    if (stage_v_157 > 35) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_151 + pub_r001066_2 * 2 + 479) & 127;
    if (stage_v_158 > 28) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_135 + pub_r001066_6 * 2 + 482) & 127;
    if (stage_v_159 > 31) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r001066_13 + pub_r001066_5 * 2 + 485) & 127;
    if (stage_v_160 > 21) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001066_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001066_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001066_9 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001066_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_91 + pub_r001066_16 * 2 + 500) & 127;
    if (stage_v_165 > 51) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_159 + pub_r001066_5 * 2 + 503) & 127;
    if (stage_v_166 > 42) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_77 + pub_r001066_9 * 2 + 506) & 127;
    if (stage_v_167 > 31) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_33 + pub_r001066_16 * 2 + 509) & 127;
    if (stage_v_168 > 32) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_126 + pub_r001066_6 * 2 + 512) & 127;
    if (stage_v_169 > 16) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001066_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001066_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001066_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001066_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_74 + pub_r001066_2 * 2 + 527) & 127;
    if (stage_v_174 > 50) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_33 + pub_r001066_14 * 2 + 530) & 127;
    if (stage_v_175 > 58) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (helper_flow_3 + pub_r001066_8 * 2 + 533) & 127;
    if (stage_v_176 > 41) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_148 + pub_r001066_5 * 2 + 536) & 127;
    if (stage_v_177 > 31) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001066_6 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001066_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_0 + pub_r001066_15 * 2 + 545) & 127;
    if (stage_v_180 > 56) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001066_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_30 + pub_r001066_9 * 2 + 551) & 127;
    if (stage_v_182 > 33) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_167 + pub_r001066_15 * 2 + 554) & 127;
    if (stage_v_183 > 20) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_3 + pub_r001066_1 * 2 + 557) & 127;
    if (stage_v_184 > 60) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001066_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_38 + pub_r001066_4 * 2 + 563) & 127;
    if (stage_v_186 > 40) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_112 + pub_r001066_2 * 2 + 566) & 127;
    if (stage_v_187 > 28) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001066_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r001066_12 + pub_r001066_6 * 2 + 572) & 127;
    if (stage_v_189 > 31) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_174 + pub_r001066_7 * 2 + 575) & 127;
    if (stage_v_190 > 26) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_27 + pub_r001066_12 * 2 + 578) & 127;
    if (stage_v_191 > 36) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_134 + pub_r001066_2 * 2 + 581) & 127;
    if (stage_v_192 > 50) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_146 + pub_r001066_4 * 2 + 584) & 127;
    if (stage_v_193 > 32) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_134 + pub_r001066_5 * 2 + 587) & 127;
    if (stage_v_194 > 52) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001066_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_31 + pub_r001066_10 * 2 + 593) & 127;
    if (stage_v_196 > 27) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_5 + pub_r001066_8 * 2 + 596) & 127;
    if (stage_v_197 > 43) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (sec_r001066_4 + pub_r001066_16 * 2 + 599) & 127;
    if (stage_v_198 > 49) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_111 + pub_r001066_12 * 2 + 602) & 127;
    if (stage_v_199 > 22) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_146 + pub_r001066_2 * 2 + 605) & 127;
    if (stage_v_200 > 25) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001066_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_28 + pub_r001066_9 * 2 + 611) & 127;
    if (stage_v_202 > 32) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (helper_flow_6 + pub_r001066_13 * 2 + 614) & 127;
    if (stage_v_203 > 55) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
        sec_accum ^= (stage_v_203 & 31);
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_55 + pub_r001066_13 * 2 + 617) & 127;
    if (stage_v_204 > 50) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001066_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_78 + pub_r001066_4 * 2 + 623) & 127;
    if (stage_v_206 > 24) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001066_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001066_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001066_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001066_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_90 + pub_r001066_1 * 2 + 638) & 127;
    if (stage_v_211 > 32) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_160 + pub_r001066_7 * 2 + 641) & 127;
    if (stage_v_212 > 34) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_165 + pub_r001066_14 * 2 + 644) & 127;
    if (stage_v_213 > 60) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_86 + pub_r001066_4 * 2 + 647) & 127;
    if (stage_v_214 > 35) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001066_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (sec_r001066_14 + pub_r001066_13 * 2 + 653) & 127;
    if (stage_v_216 > 37) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_76 + pub_r001066_10 * 2 + 656) & 127;
    if (stage_v_217 > 17) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_132 + pub_r001066_11 * 2 + 659) & 127;
    if (stage_v_218 > 41) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_77 + pub_r001066_2 * 2 + 662) & 127;
    if (stage_v_219 > 60) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001066_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_94 + pub_r001066_13 * 2 + 668) & 127;
    if (stage_v_221 > 32) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_5 + pub_r001066_5 * 2 + 671) & 127;
    if (stage_v_222 > 36) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (sec_r001066_8 + pub_r001066_14 * 2 + 674) & 127;
    if (stage_v_223 > 27) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_182 + pub_r001066_15 * 2 + 677) & 127;
    if (stage_v_224 > 37) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001066_2 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_19 + pub_r001066_9 * 2 + 683) & 127;
    if (stage_v_226 > 21) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001066_9 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001066_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001066_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_77 + pub_r001066_5 * 2 + 695) & 127;
    if (stage_v_230 > 15) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001066_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_190 + pub_r001066_4 * 2 + 701) & 127;
    if (stage_v_232 > 33) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (sec_r001066_7 + pub_r001066_6 * 2 + 704) & 127;
    if (stage_v_233 > 44) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001066_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_44 + pub_r001066_6 * 2 + 710) & 127;
    if (stage_v_235 > 55) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001066_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_70 + pub_r001066_13 * 2 + 716) & 127;
    if (stage_v_237 > 43) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001066_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_150 + pub_r001066_0 * 2 + 722) & 127;
    if (stage_v_239 > 57) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
        sec_accum ^= (stage_v_239 & 31);
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (pub_r001066_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_240) & 127;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001066_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (sec_r001066_5 + pub_r001066_8 * 2 + 731) & 127;
    if (stage_v_242 > 45) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_204 + pub_r001066_1 * 2 + 734) & 127;
    if (stage_v_243 > 50) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (helper_flow_8 + pub_r001066_16 * 2 + 737) & 127;
    if (stage_v_244 > 44) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
        sec_accum ^= (stage_v_244 & 31);
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001066_14 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_33 + pub_r001066_2 * 2 + 743) & 127;
    if (stage_v_246 > 36) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_26 + pub_r001066_6 * 2 + 746) & 127;
    if (stage_v_247 > 40) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
        sec_accum ^= (stage_v_247 & 31);
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001066_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001066_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (sec_r001066_3 + pub_r001066_15 * 2 + 755) & 127;
    if (stage_v_250 > 30) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001066_7 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001066_7 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_175 + pub_r001066_13 * 2 + 764) & 127;
    if (stage_v_253 > 31) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_100 + pub_r001066_10 * 2 + 767) & 127;
    if (stage_v_254 > 32) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
        sec_accum ^= (stage_v_254 & 31);
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (stage_v_120 + pub_r001066_11 * 2 + 770) & 127;
    if (stage_v_255 > 22) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_243 + pub_r001066_5 * 2 + 773) & 127;
    if (stage_v_256 > 52) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
        sec_accum ^= (stage_v_256 & 31);
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001066_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_146 + pub_r001066_8 * 2 + 779) & 127;
    if (stage_v_258 > 55) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
        sec_accum ^= (stage_v_258 & 31);
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_138 + pub_r001066_2 * 2 + 782) & 127;
    if (stage_v_259 > 47) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
        sec_accum ^= (stage_v_259 & 31);
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (stage_v_39 + pub_r001066_15 * 2 + 785) & 127;
    if (stage_v_260 > 36) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
        sec_accum ^= (stage_v_260 & 31);
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
