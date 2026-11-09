/*
 * Benchmark Program: R001585
 * Security Family: bitwise_flow
 * Generator Seed: 658513
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001585_8513_0 {
    short prev_in;
    unsigned char damping;
    short mode;
    int prev_out;
    int cutoff;
    int buffer[3];
};

struct AudioFrame_R001585_8513_1 {
    int gain;
    unsigned char peak;
    int channels;
    short rms;
    int envelope;
    unsigned char sample_rate;
    int buffer[3];
};

struct EventLog_R001585_8513_2 {
    int timestamp;
    int signature;
    short severity;
    int buffer[3];
};

struct StreamBuffer_R001585_8513_3 {
    unsigned char tail;
    int capacity;
    int watermark;
    int buffer[3];
};

union TelemetryField_R001585_8513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001585_8513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001585_8513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_83 = local_arr[aux % 3];
    acc = (acc + margin_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_1(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001585_8513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int phase_39 = local_arr[aux % 3];
    acc = (acc + phase_39 * 2) & 127;
    int parity_98 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_98 > 29) {
        acc = (acc + parity_98 * 2 + 5) & 127;
        aux ^= (parity_98 & 15);
    } else {
        acc = (acc - parity_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001585_8513_2(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001585_8513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_27 = (aux + st.buffer[1]) & 3;
    switch (weight_27) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001585_8513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int margin_49 = local_arr[aux % 3];
    acc = (acc + margin_49 * 2) & 127;
    int pivot_99 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_99 > 36) {
        acc = (acc + pivot_99 * 2 + 5) & 127;
        aux ^= (pivot_99 & 15);
    } else {
        acc = (acc - pivot_99 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001585_8513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001585_8513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int bound_75 = 0;
    for (int k = 0; k < 3; k++) {
        bound_75 = (bound_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_75) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_29 = local_arr[aux % 3];
    acc = (acc + bound_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001585_8513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int weight_82 = local_arr[aux % 3];
    acc = (acc + weight_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001585_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int checksum_67 = (aux + st.buffer[1]) & 3;
    switch (checksum_67) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_68 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_68 > 13) {
        acc = (acc + index_reg_68 * 2 + 5) & 127;
        aux ^= (index_reg_68 & 15);
    } else {
        acc = (acc - index_reg_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001585_8513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001585_8513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_51 = 0;
    for (int k = 0; k < 3; k++) {
        vector_51 = (vector_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_51) & 127;
    }
    int segment_90 = (aux + st.buffer[1]) & 3;
    switch (segment_90) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_82 > 15) {
        acc = (acc + quantum_82 * 2 + 5) & 127;
        aux ^= (quantum_82 & 15);
    } else {
        acc = (acc - quantum_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001585_8513_8(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001585_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int stride_16 = local_arr[aux % 3];
    acc = (acc + stride_16 * 2) & 127;
    int offset_81 = (aux + st.buffer[1]) & 3;
    switch (offset_81) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001585_8513_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001585_8513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int checksum_60 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_60 > 43) {
        acc = (acc + checksum_60 * 2 + 5) & 127;
        aux ^= (checksum_60 & 15);
    } else {
        acc = (acc - checksum_60 + 11) & 127;
        aux += 3;
    }
    int mask_24 = (aux + st.buffer[1]) & 3;
    switch (mask_24) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001585_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int segment_57 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_57 > 36) {
        acc = (acc + segment_57 * 2 + 5) & 127;
        aux ^= (segment_57 & 15);
    } else {
        acc = (acc - segment_57 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_25 = (aux + st.buffer[1]) & 3;
    switch (anchor_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001585_8513_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001585_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_27 = (aux + st.buffer[1]) & 3;
    switch (damping_27) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_12(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001585_8513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_11 = (aux + st.buffer[1]) & 3;
    switch (offset_11) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001585_8513_13(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001585_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int accumulator_27 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_27 = (accumulator_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_27) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_58 = local_arr[aux % 3];
    acc = (acc + accumulator_58 * 2) & 127;
    int factor_97 = (aux + st.buffer[1]) & 3;
    switch (factor_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001585_8513_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001585_8513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_34) & 63;
    acc ^= aux;
    int tracker_80 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_80 > 12) {
        acc = (acc + tracker_80 * 2 + 5) & 127;
        aux ^= (tracker_80 & 15);
    } else {
        acc = (acc - tracker_80 + 11) & 127;
        aux += 3;
    }
    int tally_72 = (aux + st.buffer[1]) & 3;
    switch (tally_72) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_11 = local_arr[aux % 3];
    acc = (acc + tally_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001585_8513_15(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001585_8513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int factor_85 = local_arr[aux % 3];
    acc = (acc + factor_85 * 2) & 127;
    int sample_16 = (aux + st.buffer[1]) & 3;
    switch (sample_16) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_42 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_42 > 20) {
        acc = (acc + margin_42 * 2 + 5) & 127;
        aux ^= (margin_42 & 15);
    } else {
        acc = (acc - margin_42 + 11) & 127;
        aux += 3;
    }
    int bound_72 = 0;
    for (int k = 0; k < 3; k++) {
        bound_72 = (bound_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_72) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001585_8513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001585_8513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_63) & 63;
    acc ^= aux;
    int quantum_79 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_79 = (quantum_79 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_79) & 127;
    }
    int metric_17 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_17 > 19) {
        acc = (acc + metric_17 * 2 + 5) & 127;
        aux ^= (metric_17 & 15);
    } else {
        acc = (acc - metric_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001585_0;
    int sec_r001585_1;
    int sec_r001585_2;
    int sec_r001585_3;
    int sec_r001585_4;
    int sec_r001585_5;
    int sec_r001585_6;
    int sec_r001585_7;
    int sec_r001585_8;
    int sec_r001585_9;
    int sec_r001585_10;
    int sec_r001585_11;
    int sec_r001585_12;
    int sec_r001585_13;
    int sec_r001585_14;
    int sec_r001585_15;
    int pub_r001585_0;
    int pub_r001585_1;
    int pub_r001585_2;
    int pub_r001585_3;
    int pub_r001585_4;
    int pub_r001585_5;
    int pub_r001585_6;
    int pub_r001585_7;
    int pub_r001585_8;
    int pub_r001585_9;
    int pub_r001585_10;
    int pub_r001585_11;
    int pub_r001585_12;
    int pub_r001585_13;
    int pub_r001585_14;
    int pub_r001585_15;
    int pub_r001585_16;
    int pub_r001585_17;
    int pub_r001585_18;
    int pub_r001585_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001585_0 >= -100 && pub_r001585_0 <= 100);
    __CPROVER_assume(pub_r001585_1 >= -100 && pub_r001585_1 <= 100);
    __CPROVER_assume(pub_r001585_2 >= -100 && pub_r001585_2 <= 100);
    __CPROVER_assume(pub_r001585_3 >= -100 && pub_r001585_3 <= 100);
    __CPROVER_assume(pub_r001585_4 >= -100 && pub_r001585_4 <= 100);
    __CPROVER_assume(pub_r001585_5 >= -100 && pub_r001585_5 <= 100);
    __CPROVER_assume(pub_r001585_6 >= -100 && pub_r001585_6 <= 100);
    __CPROVER_assume(pub_r001585_7 >= -100 && pub_r001585_7 <= 100);
    __CPROVER_assume(pub_r001585_8 >= -100 && pub_r001585_8 <= 100);
    __CPROVER_assume(pub_r001585_9 >= -100 && pub_r001585_9 <= 100);
    __CPROVER_assume(pub_r001585_10 >= -100 && pub_r001585_10 <= 100);
    __CPROVER_assume(pub_r001585_11 >= -100 && pub_r001585_11 <= 100);
    __CPROVER_assume(pub_r001585_12 >= -100 && pub_r001585_12 <= 100);
    __CPROVER_assume(pub_r001585_13 >= -100 && pub_r001585_13 <= 100);
    __CPROVER_assume(pub_r001585_14 >= -100 && pub_r001585_14 <= 100);
    __CPROVER_assume(pub_r001585_15 >= -100 && pub_r001585_15 <= 100);
    __CPROVER_assume(pub_r001585_16 >= -100 && pub_r001585_16 <= 100);
    __CPROVER_assume(pub_r001585_17 >= -100 && pub_r001585_17 <= 100);
    __CPROVER_assume(pub_r001585_18 >= -100 && pub_r001585_18 <= 100);
    __CPROVER_assume(pub_r001585_19 >= -100 && pub_r001585_19 <= 100);
    __CPROVER_assume(sec_r001585_0 >= 0 && sec_r001585_0 <= 255);
    __CPROVER_assume(sec_r001585_1 >= 0 && sec_r001585_1 <= 255);
    __CPROVER_assume(sec_r001585_2 >= 0 && sec_r001585_2 <= 255);
    __CPROVER_assume(sec_r001585_3 >= 0 && sec_r001585_3 <= 255);
    __CPROVER_assume(sec_r001585_4 >= 0 && sec_r001585_4 <= 255);
    __CPROVER_assume(sec_r001585_5 >= 0 && sec_r001585_5 <= 255);
    __CPROVER_assume(sec_r001585_6 >= 0 && sec_r001585_6 <= 255);
    __CPROVER_assume(sec_r001585_7 >= 0 && sec_r001585_7 <= 255);
    __CPROVER_assume(sec_r001585_8 >= 0 && sec_r001585_8 <= 255);
    __CPROVER_assume(sec_r001585_9 >= 0 && sec_r001585_9 <= 255);
    __CPROVER_assume(sec_r001585_10 >= 0 && sec_r001585_10 <= 255);
    __CPROVER_assume(sec_r001585_11 >= 0 && sec_r001585_11 <= 255);
    __CPROVER_assume(sec_r001585_12 >= 0 && sec_r001585_12 <= 255);
    __CPROVER_assume(sec_r001585_13 >= 0 && sec_r001585_13 <= 255);
    __CPROVER_assume(sec_r001585_14 >= 0 && sec_r001585_14 <= 255);
    __CPROVER_assume(sec_r001585_15 >= 0 && sec_r001585_15 <= 255);

    struct FilterState_R001585_8513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001585_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001585_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001585_0 + 7) & 15;
    struct AudioFrame_R001585_8513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001585_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001585_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001585_0 + 9) & 15;
    struct EventLog_R001585_8513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001585_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001585_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001585_0 + 11) & 15;
    struct StreamBuffer_R001585_8513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001585_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001585_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001585_0 + 13) & 15;

    union TelemetryField_R001585_8513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001585_8513_0(sec_r001585_0, sec_r001585_1, pub_r001585_2, pub_r001585_3);
    int helper_flow_1 = fn_R001585_8513_1(sec_r001585_1, sec_r001585_2, pub_r001585_3);
    int helper_flow_2 = fn_R001585_8513_2(sec_r001585_2, pub_r001585_3);
    int helper_flow_3 = fn_R001585_8513_3(sec_r001585_3, pub_r001585_4, pub_r001585_5, pub_r001585_6, pub_r001585_7);
    int helper_flow_4 = fn_R001585_8513_4(sec_r001585_4, sec_r001585_5, pub_r001585_6, pub_r001585_7, pub_r001585_8);
    int helper_flow_5 = fn_R001585_8513_5(sec_r001585_5, pub_r001585_6, pub_r001585_7, pub_r001585_8, pub_r001585_9);
    int helper_flow_6 = fn_R001585_8513_6(sec_r001585_6, sec_r001585_7, pub_r001585_8, pub_r001585_9, pub_r001585_10);
    int helper_flow_7 = fn_R001585_8513_7(sec_r001585_7, sec_r001585_8, pub_r001585_9, pub_r001585_10, pub_r001585_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001585_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001585_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_7 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001585_6 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_0 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001585_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_6 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((helper_flow_4 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001585_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001585_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001585_12 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001585_5 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((helper_flow_2 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001585_3 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001585_13 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001585_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_11 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001585_10 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001585_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001585_7 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001585_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((helper_flow_4 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001585_8 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001585_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001585_11 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_11 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_3 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001585_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_12 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001585_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001585_6 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_22 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001585_7 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_6 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001585_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r001585_4 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_6 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001585_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001585_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_5 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001585_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_21 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_13 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001585_3 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_42 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001585_1 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((helper_flow_2 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_2 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_30 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001585_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001585_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001585_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001585_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_2 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001585_0 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001585_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001585_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_42 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001585_12 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001585_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001585_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001585_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001585_0 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_41 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001585_15 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001585_11 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001585_3 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001585_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001585_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_48 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001585_5 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001585_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_43 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_25 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001585_2 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001585_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001585_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001585_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001585_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001585_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_13 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_16 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001585_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_81 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001585_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_44 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_25 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_43 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001585_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_72 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001585_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001585_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_25 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001585_5 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_57 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001585_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_36 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001585_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001585_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_19 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_33 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_3 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_99 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_14 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001585_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001585_7 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001585_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001585_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_41 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001585_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001585_19 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r001585_7 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_21 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_112 + 1) & 15;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001585_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001585_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_46 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_65 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001585_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_13 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001585_5 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_57 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001585_2 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001585_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001585_5 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001585_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001585_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001585_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001585_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_10 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_87 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_101 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001585_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001585_12 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001585_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001585_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001585_6 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001585_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001585_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001585_5 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001585_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001585_19 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001585_14 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_36 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_105 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001585_16 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001585_15 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_145 + 1) & 15;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_10 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001585_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_112 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001585_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001585_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_128 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001585_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001585_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001585_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_130 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001585_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r001585_12 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_19 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_86 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_159 + 1) & 15;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001585_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_92 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r001585_11 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_103 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_163 + 1) & 15;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001585_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_2 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_93 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001585_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001585_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001585_10 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001585_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001585_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_80 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_172 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_173 + 1) & 15;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001585_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_158 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_25 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001585_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_166 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_74 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001585_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r001585_3 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r001585_1 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_182 + 1) & 15;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001585_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001585_3 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_46 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r001585_5 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r001585_6 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((helper_flow_3 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001585_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_86 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001585_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001585_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_100 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001585_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001585_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r001585_3 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001585_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_13 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001585_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001585_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001585_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((sec_r001585_13 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_92 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_203 + 1) & 15;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_93 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_2 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001585_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001585_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001585_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_45 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_190 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_22 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001585_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001585_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_19 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_47 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_193 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_65 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001585_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001585_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_101 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001585_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_211 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_166 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_63 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((helper_flow_6 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_187 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_25 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001585_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001585_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001585_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_10 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001585_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_119 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_190 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_120 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001585_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001585_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_233 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_69 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_16 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_53 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001585_5 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001585_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001585_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_101 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001585_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_158 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_173 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001585_17 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001585_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_165 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_210 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_158 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_26 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_185 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001585_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001585_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_43 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_19 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_47 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_36 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((helper_flow_1 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_111 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001585_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001585_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_13 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((helper_flow_0 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((sec_r001585_14 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_266 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_269 + 1) & 15;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001585_9 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001585_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001585_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_181 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001585_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_188 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_57 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001585_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001585_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001585_17 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (pub_r001585_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_280) & 127;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001585_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001585_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_220 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_14 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((sec_r001585_9 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001585_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_196 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_142 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001585_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001585_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_48 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001585_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_120 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_41 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_46 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001585_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001585_2 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_220 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001585_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001585_19 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001585_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001585_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_25 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_89 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001585_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001585_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_43 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_123 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((helper_flow_2 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001585_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_83 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((helper_flow_5 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((helper_flow_4 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_241 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((sec_r001585_12 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001585_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_216 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((sec_r001585_4 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_198 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001585_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((helper_flow_5 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001585_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001585_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_238 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_266 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (pub_r001585_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_326) & 127;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001585_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_255 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001585_18 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_47 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001585_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r001585_1 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001585_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001585_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001585_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001585_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_224 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_119 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_102 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001585_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001585_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_266 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001585_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_13 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_273 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((stage_v_312 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001585_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_227 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_178 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001585_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_245 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((helper_flow_2 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_352 + 1) & 15;
    out_sink ^= (stage_v_352 & 63);

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_202 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_225 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001585_7 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((sec_r001585_3 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_165 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((helper_flow_6 << 1) ^ (pub_r001585_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((sec_r001585_10 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_48 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_129 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001585_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001585_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_231 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_70 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_234 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_85 << 1) ^ (pub_r001585_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001585_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_304 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_332 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001585_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001585_4 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001585_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_179 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_223 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001585_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001585_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_190 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001585_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((helper_flow_3 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_344 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_72 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_63 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001585_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_196 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((sec_r001585_9 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001585_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001585_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_383 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001585_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_46 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_89 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_214 << 1) ^ (pub_r001585_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_94 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001585_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_186 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_295 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001585_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_204 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_255 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_66 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_190 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001585_4 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((sec_r001585_10 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_46 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001585_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001585_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_36 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_148 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = (pub_r001585_0 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_410) & 127;

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001585_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_309 << 1) ^ (pub_r001585_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_276 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((stage_v_393 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_148 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_342 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_253 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_276 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_57 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_366 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = (pub_r001585_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_421) & 127;

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = ((stage_v_112 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_422 + 1) & 15;
    out_sink ^= (stage_v_422 & 63);

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001585_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_359 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001585_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001585_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001585_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((sec_r001585_8 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_123 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((stage_v_378 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = (pub_r001585_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_431) & 127;

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001585_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001585_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_165 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_25 << 1) ^ (pub_r001585_18 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001585_1 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = (pub_r001585_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_437) & 127;

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001585_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_402 << 1) ^ (pub_r001585_10 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001585_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_409 << 1) ^ (pub_r001585_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_190 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_21 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = ((stage_v_397 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_444 + 1) & 15;
    out_sink ^= (stage_v_444 & 63);

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = (pub_r001585_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_445) & 127;

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = (pub_r001585_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_446) & 127;

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_11 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_202 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = (pub_r001585_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_449) & 127;

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((stage_v_148 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_159 << 1) ^ (pub_r001585_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_108 << 1) ^ (pub_r001585_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_452 + 1) & 15;
    out_sink ^= (stage_v_452 & 63);

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001585_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_374 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_454 + 1) & 15;
    out_sink ^= (stage_v_454 & 63);

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = ((stage_v_374 << 1) ^ (pub_r001585_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_455 + 1) & 15;
    out_sink ^= (stage_v_455 & 63);

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001585_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001585_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001585_11 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = ((stage_v_241 << 1) ^ (pub_r001585_8 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_459 + 1) & 15;
    out_sink ^= (stage_v_459 & 63);

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_48 << 1) ^ (pub_r001585_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = ((stage_v_105 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_461 + 1) & 15;
    out_sink ^= (stage_v_461 & 63);

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = ((stage_v_269 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_462 + 1) & 15;
    out_sink ^= (stage_v_462 & 63);

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = ((stage_v_315 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_463 + 1) & 15;
    out_sink ^= (stage_v_463 & 63);

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001585_1 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = (pub_r001585_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_465) & 127;

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = ((stage_v_459 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_466 + 1) & 15;
    out_sink ^= (stage_v_466 & 63);

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_187 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_338 << 1) ^ (pub_r001585_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = ((stage_v_118 << 1) ^ (pub_r001585_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_469 + 1) & 15;
    out_sink ^= (stage_v_469 & 63);

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001585_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001585_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_266 << 1) ^ (pub_r001585_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = ((stage_v_361 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_473 + 1) & 15;
    out_sink ^= (stage_v_473 & 63);

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = ((stage_v_163 << 1) ^ (pub_r001585_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_474 + 1) & 15;
    out_sink ^= (stage_v_474 & 63);

    /* Execution Pipeline Stage 475 */
    int stage_v_475 = ((stage_v_324 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_475 + 1) & 15;
    out_sink ^= (stage_v_475 & 63);

    /* Execution Pipeline Stage 476 */
    int stage_v_476 = (pub_r001585_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_476) & 127;

    /* Execution Pipeline Stage 477 */
    int stage_v_477 = (pub_r001585_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_477) & 127;

    /* Execution Pipeline Stage 478 */
    int stage_v_478 = ((stage_v_16 << 1) ^ (pub_r001585_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_478 + 1) & 15;
    out_sink ^= (stage_v_478 & 63);

    /* Execution Pipeline Stage 479 */
    int stage_v_479 = ((stage_v_57 << 1) ^ (pub_r001585_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_479 + 1) & 15;
    out_sink ^= (stage_v_479 & 63);

    /* Execution Pipeline Stage 480 */
    int stage_v_480 = (pub_r001585_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_480) & 127;

    /* Execution Pipeline Stage 481 */
    int stage_v_481 = (pub_r001585_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_481) & 127;

    /* Execution Pipeline Stage 482 */
    int stage_v_482 = ((stage_v_419 << 1) ^ (pub_r001585_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_482 + 1) & 15;
    out_sink ^= (stage_v_482 & 63);

    /* Execution Pipeline Stage 483 */
    int stage_v_483 = (pub_r001585_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_483) & 127;

    /* Execution Pipeline Stage 484 */
    int stage_v_484 = (pub_r001585_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_484) & 127;

    /* Execution Pipeline Stage 485 */
    int stage_v_485 = (pub_r001585_17 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_485) & 127;

    /* Execution Pipeline Stage 486 */
    int stage_v_486 = (pub_r001585_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_486) & 127;

    /* Execution Pipeline Stage 487 */
    int stage_v_487 = (pub_r001585_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_487) & 127;

    /* Execution Pipeline Stage 488 */
    int stage_v_488 = ((stage_v_455 << 1) ^ (pub_r001585_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_488 + 1) & 15;
    out_sink ^= (stage_v_488 & 63);

    /* Execution Pipeline Stage 489 */
    int stage_v_489 = (pub_r001585_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_489) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
