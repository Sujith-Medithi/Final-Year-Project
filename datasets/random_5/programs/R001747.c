/*
 * Benchmark Program: R001747
 * Security Family: nested_implicit_flow
 * Generator Seed: 674713
 * High Inputs: 21 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001747_4713_0 {
    int mode;
    unsigned char gain_db;
    int cutoff;
    unsigned char prev_in;
    int buffer[3];
};

struct MatrixBlock_R001747_4713_1 {
    short density;
    int stride;
    short trace;
    int buffer[3];
};

struct EventLog_R001747_4713_2 {
    short severity;
    short signature;
    unsigned char seq;
    int facility;
    int buffer[3];
};

struct DeviceConfig_R001747_4713_3 {
    unsigned char id;
    unsigned char parity;
    int port;
    unsigned char baud_rate;
    int buffer[3];
};

union PacketPayload_R001747_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001747_4713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001747_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_17 = (aux + st.buffer[1]) & 3;
    switch (sample_17) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_1(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_94 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_94 > 34) {
        acc = (acc + sample_94 * 2 + 5) & 127;
        aux ^= (sample_94 & 15);
    } else {
        acc = (acc - sample_94 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_2(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quotient_55 = (aux + st.buffer[1]) & 3;
    switch (quotient_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_28 = 0;
    for (int k = 0; k < 2; k++) {
        metric_28 = (metric_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_28) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001747_4713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001747_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_52 = 0;
    for (int k = 0; k < 3; k++) {
        sample_52 = (sample_52 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_52) & 127;
    }
    int damping_87 = (aux + st.buffer[1]) & 3;
    switch (damping_87) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001747_4713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int metric_11 = local_arr[aux % 3];
    acc = (acc + metric_11 * 2) & 127;
    int pivot_73 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_73 > 32) {
        acc = (acc + pivot_73 * 2 + 5) & 127;
        aux ^= (pivot_73 & 15);
    } else {
        acc = (acc - pivot_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001747_4713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int window_61 = 0;
    for (int k = 0; k < 3; k++) {
        window_61 = (window_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_61) & 127;
    }
    int window_17 = (st.buffer[0] * 3 + aux) & 63;
    if (window_17 > 16) {
        acc = (acc + window_17 * 2 + 5) & 127;
        aux ^= (window_17 & 15);
    } else {
        acc = (acc - window_17 + 11) & 127;
        aux += 3;
    }
    int quantum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_63 = local_arr[aux % 3];
    acc = (acc + stride_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int accumulator_93 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_93 > 12) {
        acc = (acc + accumulator_93 * 2 + 5) & 127;
        aux ^= (accumulator_93 & 15);
    } else {
        acc = (acc - accumulator_93 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_21 = local_arr[aux % 3];
    acc = (acc + mask_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_7(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int residue_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_49) & 63;
    acc ^= aux;
    int weight_46 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_46 > 10) {
        acc = (acc + weight_46 * 2 + 5) & 127;
        aux ^= (weight_46 & 15);
    } else {
        acc = (acc - weight_46 + 11) & 127;
        aux += 3;
    }
    int phase_49 = (aux + st.buffer[1]) & 3;
    switch (phase_49) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001747_4713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001747_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int weight_60 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_60 > 11) {
        acc = (acc + weight_60 * 2 + 5) & 127;
        aux ^= (weight_60 & 15);
    } else {
        acc = (acc - weight_60 + 11) & 127;
        aux += 3;
    }
    int tracker_19 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_19 = (tracker_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_19) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_92 = local_arr[aux % 3];
    acc = (acc + segment_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int quantum_46 = local_arr[aux % 3];
    acc = (acc + quantum_46 * 2) & 127;
    int tally_65 = 0;
    for (int k = 0; k < 3; k++) {
        tally_65 = (tally_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_65) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_20 = (aux + st.buffer[1]) & 3;
    switch (parity_20) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001747_4713_10(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001747_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_71 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_71 > 41) {
        acc = (acc + stride_71 * 2 + 5) & 127;
        aux ^= (stride_71 & 15);
    } else {
        acc = (acc - stride_71 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001747_4713_11(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001747_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int checksum_69 = local_arr[aux % 3];
    acc = (acc + checksum_69 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int checksum_89 = local_arr[aux % 3];
    acc = (acc + checksum_89 * 2) & 127;
    int parity_59 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_59 > 15) {
        acc = (acc + parity_59 * 2 + 5) & 127;
        aux ^= (parity_59 & 15);
    } else {
        acc = (acc - parity_59 + 11) & 127;
        aux += 3;
    }
    int window_73 = 0;
    for (int k = 0; k < 2; k++) {
        window_73 = (window_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_73) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001747_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int delta_55 = 0;
    for (int k = 0; k < 3; k++) {
        delta_55 = (delta_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_55) & 127;
    }
    int coefficient_34 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_34 > 28) {
        acc = (acc + coefficient_34 * 2 + 5) & 127;
        aux ^= (coefficient_34 & 15);
    } else {
        acc = (acc - coefficient_34 + 11) & 127;
        aux += 3;
    }
    int coefficient_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_73) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001747_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_39 = (aux + st.buffer[1]) & 3;
    switch (segment_39) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_87 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_87 > 49) {
        acc = (acc + sample_87 * 2 + 5) & 127;
        aux ^= (sample_87 & 15);
    } else {
        acc = (acc - sample_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001747_4713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001747_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_66) & 63;
    acc ^= aux;
    int vector_18 = 0;
    for (int k = 0; k < 3; k++) {
        vector_18 = (vector_18 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_18) & 127;
    }
    int window_29 = (st.buffer[0] * 3 + aux) & 63;
    if (window_29 > 43) {
        acc = (acc + window_29 * 2 + 5) & 127;
        aux ^= (window_29 & 15);
    } else {
        acc = (acc - window_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_89 = local_arr[aux % 3];
    acc = (acc + vector_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001747_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int vector_62 = (aux + st.buffer[1]) & 3;
    switch (vector_62) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_97 = local_arr[aux % 3];
    acc = (acc + parity_97 * 2) & 127;
    int damping_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001747_4713_17(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001747_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int cursor_85 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_85 > 24) {
        acc = (acc + cursor_85 * 2 + 5) & 127;
        aux ^= (cursor_85 & 15);
    } else {
        acc = (acc - cursor_85 + 11) & 127;
        aux += 3;
    }
    int weight_27 = 0;
    for (int k = 0; k < 2; k++) {
        weight_27 = (weight_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_27) & 127;
    }
    int anchor_64 = (aux + st.buffer[1]) & 3;
    switch (anchor_64) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001747_0;
    int sec_r001747_1;
    int sec_r001747_2;
    int sec_r001747_3;
    int sec_r001747_4;
    int sec_r001747_5;
    int sec_r001747_6;
    int sec_r001747_7;
    int sec_r001747_8;
    int sec_r001747_9;
    int sec_r001747_10;
    int sec_r001747_11;
    int sec_r001747_12;
    int sec_r001747_13;
    int sec_r001747_14;
    int sec_r001747_15;
    int sec_r001747_16;
    int sec_r001747_17;
    int sec_r001747_18;
    int sec_r001747_19;
    int sec_r001747_20;
    int pub_r001747_0;
    int pub_r001747_1;
    int pub_r001747_2;
    int pub_r001747_3;
    int pub_r001747_4;
    int pub_r001747_5;
    int pub_r001747_6;
    int pub_r001747_7;
    int pub_r001747_8;
    int pub_r001747_9;
    int pub_r001747_10;
    int pub_r001747_11;
    int pub_r001747_12;
    int pub_r001747_13;
    int pub_r001747_14;
    int pub_r001747_15;
    int pub_r001747_16;
    int pub_r001747_17;
    int pub_r001747_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001747_0 >= -100 && pub_r001747_0 <= 100);
    __CPROVER_assume(pub_r001747_1 >= -100 && pub_r001747_1 <= 100);
    __CPROVER_assume(pub_r001747_2 >= -100 && pub_r001747_2 <= 100);
    __CPROVER_assume(pub_r001747_3 >= -100 && pub_r001747_3 <= 100);
    __CPROVER_assume(pub_r001747_4 >= -100 && pub_r001747_4 <= 100);
    __CPROVER_assume(pub_r001747_5 >= -100 && pub_r001747_5 <= 100);
    __CPROVER_assume(pub_r001747_6 >= -100 && pub_r001747_6 <= 100);
    __CPROVER_assume(pub_r001747_7 >= -100 && pub_r001747_7 <= 100);
    __CPROVER_assume(pub_r001747_8 >= -100 && pub_r001747_8 <= 100);
    __CPROVER_assume(pub_r001747_9 >= -100 && pub_r001747_9 <= 100);
    __CPROVER_assume(pub_r001747_10 >= -100 && pub_r001747_10 <= 100);
    __CPROVER_assume(pub_r001747_11 >= -100 && pub_r001747_11 <= 100);
    __CPROVER_assume(pub_r001747_12 >= -100 && pub_r001747_12 <= 100);
    __CPROVER_assume(pub_r001747_13 >= -100 && pub_r001747_13 <= 100);
    __CPROVER_assume(pub_r001747_14 >= -100 && pub_r001747_14 <= 100);
    __CPROVER_assume(pub_r001747_15 >= -100 && pub_r001747_15 <= 100);
    __CPROVER_assume(pub_r001747_16 >= -100 && pub_r001747_16 <= 100);
    __CPROVER_assume(pub_r001747_17 >= -100 && pub_r001747_17 <= 100);
    __CPROVER_assume(pub_r001747_18 >= -100 && pub_r001747_18 <= 100);
    __CPROVER_assume(sec_r001747_0 >= 0 && sec_r001747_0 <= 255);
    __CPROVER_assume(sec_r001747_1 >= 0 && sec_r001747_1 <= 255);
    __CPROVER_assume(sec_r001747_2 >= 0 && sec_r001747_2 <= 255);
    __CPROVER_assume(sec_r001747_3 >= 0 && sec_r001747_3 <= 255);
    __CPROVER_assume(sec_r001747_4 >= 0 && sec_r001747_4 <= 255);
    __CPROVER_assume(sec_r001747_5 >= 0 && sec_r001747_5 <= 255);
    __CPROVER_assume(sec_r001747_6 >= 0 && sec_r001747_6 <= 255);
    __CPROVER_assume(sec_r001747_7 >= 0 && sec_r001747_7 <= 255);
    __CPROVER_assume(sec_r001747_8 >= 0 && sec_r001747_8 <= 255);
    __CPROVER_assume(sec_r001747_9 >= 0 && sec_r001747_9 <= 255);
    __CPROVER_assume(sec_r001747_10 >= 0 && sec_r001747_10 <= 255);
    __CPROVER_assume(sec_r001747_11 >= 0 && sec_r001747_11 <= 255);
    __CPROVER_assume(sec_r001747_12 >= 0 && sec_r001747_12 <= 255);
    __CPROVER_assume(sec_r001747_13 >= 0 && sec_r001747_13 <= 255);
    __CPROVER_assume(sec_r001747_14 >= 0 && sec_r001747_14 <= 255);
    __CPROVER_assume(sec_r001747_15 >= 0 && sec_r001747_15 <= 255);
    __CPROVER_assume(sec_r001747_16 >= 0 && sec_r001747_16 <= 255);
    __CPROVER_assume(sec_r001747_17 >= 0 && sec_r001747_17 <= 255);
    __CPROVER_assume(sec_r001747_18 >= 0 && sec_r001747_18 <= 255);
    __CPROVER_assume(sec_r001747_19 >= 0 && sec_r001747_19 <= 255);
    __CPROVER_assume(sec_r001747_20 >= 0 && sec_r001747_20 <= 255);

    struct FilterState_R001747_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001747_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001747_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001747_0 + 7) & 15;
    struct MatrixBlock_R001747_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001747_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001747_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001747_0 + 9) & 15;
    struct EventLog_R001747_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001747_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001747_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001747_0 + 11) & 15;
    struct DeviceConfig_R001747_4713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001747_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001747_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001747_0 + 13) & 15;

    union PacketPayload_R001747_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001747_4713_0(sec_r001747_0, sec_r001747_1, pub_r001747_2, pub_r001747_3, pub_r001747_4);
    int helper_flow_1 = fn_R001747_4713_1(sec_r001747_1, sec_r001747_2, pub_r001747_3);
    int helper_flow_2 = fn_R001747_4713_2(sec_r001747_2, sec_r001747_3);
    int helper_flow_3 = fn_R001747_4713_3(sec_r001747_3, pub_r001747_4, pub_r001747_5, pub_r001747_6);
    int helper_flow_4 = fn_R001747_4713_4(sec_r001747_4, pub_r001747_5, pub_r001747_6, pub_r001747_7, pub_r001747_8);
    int helper_flow_5 = fn_R001747_4713_5(sec_r001747_5, pub_r001747_6, pub_r001747_7, pub_r001747_8);
    int helper_flow_6 = fn_R001747_4713_6(sec_r001747_6, sec_r001747_7, pub_r001747_8, pub_r001747_9);
    int helper_flow_7 = fn_R001747_4713_7(sec_r001747_7, pub_r001747_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001747_9 ^ pub_r001747_6) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001747_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001747_19 ^ pub_r001747_9) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001747_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001747_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001747_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (stage_v_1 ^ pub_r001747_0) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001747_16 ^ pub_r001747_6) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001747_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001747_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001747_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001747_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001747_10 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001747_3 ^ pub_r001747_16) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001747_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001747_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001747_19 ^ pub_r001747_4) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001747_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (stage_v_10 ^ pub_r001747_16) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001747_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001747_3 ^ pub_r001747_16) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001747_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001747_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001747_5 ^ pub_r001747_6) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001747_17 ^ pub_r001747_0) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001747_2 ^ pub_r001747_8) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001747_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001747_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_1 ^ pub_r001747_9) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001747_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001747_14 ^ pub_r001747_0) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001747_9 ^ pub_r001747_14) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001747_7 ^ pub_r001747_7) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001747_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (helper_flow_2 ^ pub_r001747_15) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r001747_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001747_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001747_8 ^ pub_r001747_13) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001747_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (helper_flow_0 ^ pub_r001747_7) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_14 ^ pub_r001747_13) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001747_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001747_0 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_7 ^ pub_r001747_4) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_5 ^ pub_r001747_15) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001747_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_12 ^ pub_r001747_0) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_29 ^ pub_r001747_6) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001747_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001747_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001747_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_33 ^ pub_r001747_7) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_35 ^ pub_r001747_7) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (helper_flow_7 ^ pub_r001747_13) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001747_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001747_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (sec_r001747_15 ^ pub_r001747_9) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001747_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001747_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_10 ^ pub_r001747_17) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r001747_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_40 ^ pub_r001747_4) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001747_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_17 ^ pub_r001747_8) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001747_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001747_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_12 ^ pub_r001747_18) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001747_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001747_15 ^ pub_r001747_6) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r001747_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001747_14 ^ pub_r001747_9) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001747_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_18 ^ pub_r001747_4) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001747_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001747_1 ^ pub_r001747_12) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_27 ^ pub_r001747_3) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001747_19 ^ pub_r001747_14) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_17 ^ pub_r001747_6) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_60 ^ pub_r001747_8) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r001747_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001747_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001747_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001747_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001747_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_52 ^ pub_r001747_9) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001747_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001747_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001747_3 ^ pub_r001747_7) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r001747_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_43 ^ pub_r001747_2) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001747_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_32 ^ pub_r001747_5) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_0 ^ pub_r001747_12) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r001747_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_5 ^ pub_r001747_18) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001747_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001747_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001747_7 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_39 ^ pub_r001747_13) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (helper_flow_4 ^ pub_r001747_14) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_69 ^ pub_r001747_10) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001747_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_56 ^ pub_r001747_2) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r001747_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001747_5 ^ pub_r001747_5) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001747_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_73 ^ pub_r001747_18) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r001747_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_58 ^ pub_r001747_12) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_25 ^ pub_r001747_9) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_5 ^ pub_r001747_9) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_69 ^ pub_r001747_8) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r001747_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001747_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001747_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (helper_flow_5 ^ pub_r001747_1) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001747_14 ^ pub_r001747_15) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001747_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_59 ^ pub_r001747_16) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r001747_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (sec_r001747_10 ^ pub_r001747_18) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_35 ^ pub_r001747_13) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001747_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_79 ^ pub_r001747_2) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001747_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_22 ^ pub_r001747_10) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r001747_3 ^ pub_r001747_10) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_27 ^ pub_r001747_17) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_32 ^ pub_r001747_2) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r001747_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_70 ^ pub_r001747_9) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r001747_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_39 ^ pub_r001747_5) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_1 ^ pub_r001747_18) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r001747_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001747_17 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_85 ^ pub_r001747_0) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_105 ^ pub_r001747_16) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_56 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001747_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001747_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_54 ^ pub_r001747_6) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001747_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001747_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001747_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001747_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_49 ^ pub_r001747_13) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001747_3 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r001747_1 ^ pub_r001747_0) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_82 ^ pub_r001747_10) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_12 ^ pub_r001747_16) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (helper_flow_0 ^ pub_r001747_17) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001747_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_121 ^ pub_r001747_4) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001747_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001747_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r001747_0 ^ pub_r001747_11) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001747_0 ^ pub_r001747_3) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_23 ^ pub_r001747_18) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001747_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_61 ^ pub_r001747_9) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_89 ^ pub_r001747_18) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_128 ^ pub_r001747_14) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001747_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_32 ^ pub_r001747_0) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_73 ^ pub_r001747_0) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001747_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001747_11 ^ pub_r001747_7) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001747_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_46 ^ pub_r001747_4) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_78 ^ pub_r001747_3) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_92 ^ pub_r001747_14) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r001747_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_80 ^ pub_r001747_16) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_86 ^ pub_r001747_3) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_82 ^ pub_r001747_1) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((sec_r001747_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001747_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001747_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_17 ^ pub_r001747_7) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((sec_r001747_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_88 ^ pub_r001747_14) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_142 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_34 ^ pub_r001747_8) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001747_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (sec_r001747_16 ^ pub_r001747_9) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_118 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001747_19 ^ pub_r001747_10) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_59 ^ pub_r001747_13) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_129 ^ pub_r001747_8) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_10 ^ pub_r001747_10) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_82 ^ pub_r001747_12) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_139 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_156 ^ pub_r001747_15) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_40 ^ pub_r001747_12) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r001747_16 ^ pub_r001747_9) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (helper_flow_1 ^ pub_r001747_15) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_137 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_101 ^ pub_r001747_11) & 63;
    if ((stage_v_163 & 1) != 0) {
        if ((stage_v_150 & 2) != 0) {
            out_sink = (out_sink + stage_v_163 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_163 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001747_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001747_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001747_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_47 ^ pub_r001747_0) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((sec_r001747_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_129 ^ pub_r001747_6) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_163 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (helper_flow_4 ^ pub_r001747_10) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_122 ^ pub_r001747_5) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_55 ^ pub_r001747_1) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001747_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001747_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_79 ^ pub_r001747_11) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_150 ^ pub_r001747_8) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001747_0 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_86 ^ pub_r001747_2) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001747_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_151 ^ pub_r001747_14) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_125 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_54 ^ pub_r001747_11) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((sec_r001747_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001747_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001747_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_174 ^ pub_r001747_7) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_158 ^ pub_r001747_15) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_132 ^ pub_r001747_9) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r001747_18 ^ pub_r001747_0) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((sec_r001747_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001747_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_17 ^ pub_r001747_14) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001747_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001747_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (helper_flow_5 ^ pub_r001747_12) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_170 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_125 ^ pub_r001747_16) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
