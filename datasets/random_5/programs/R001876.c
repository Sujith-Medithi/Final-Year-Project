/*
 * Benchmark Program: R001876
 * Security Family: implicit_flow
 * Generator Seed: 687613
 * High Inputs: 22 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R001876_7613_0 {
    int calib;
    int gain;
    int offset;
    int reading;
    short threshold;
    int status;
    int buffer[3];
};

struct FilterState_R001876_7613_1 {
    int gain_db;
    unsigned char mode;
    short prev_out;
    short prev_in;
    int buffer[3];
};

struct StreamBuffer_R001876_7613_2 {
    short checksum;
    unsigned char head;
    unsigned char tail;
    int buffer[3];
};

struct EventLog_R001876_7613_3 {
    int signature;
    short facility;
    int severity;
    int code;
    int seq;
    unsigned char timestamp;
    int buffer[3];
};

union PacketPayload_R001876_7613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001876_7613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001876_7613_0(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001876_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_38 = 0;
    for (int k = 0; k < 2; k++) {
        residue_38 = (residue_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_38) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_98 = local_arr[aux % 3];
    acc = (acc + stride_98 * 2) & 127;
    int window_71 = (aux + st.buffer[1]) & 3;
    switch (window_71) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_46 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_46 > 35) {
        acc = (acc + margin_46 * 2 + 5) & 127;
        aux ^= (margin_46 & 15);
    } else {
        acc = (acc - margin_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_1(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001876_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_66 = (aux + st.buffer[1]) & 3;
    switch (residue_66) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_32 = 0;
    for (int k = 0; k < 2; k++) {
        vector_32 = (vector_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_32) & 127;
    }
    int threshold_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001876_7613_2(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001876_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int threshold_25 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_25 = (threshold_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_25) & 127;
    }
    int bound_14 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_14 > 19) {
        acc = (acc + bound_14 * 2 + 5) & 127;
        aux ^= (bound_14 & 15);
    } else {
        acc = (acc - bound_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_3(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001876_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quotient_59 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_59 = (quotient_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_59) & 127;
    }
    int checksum_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_26) & 63;
    acc ^= aux;
    int sample_34 = (aux + st.buffer[1]) & 3;
    switch (sample_34) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001876_7613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001876_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_24) & 63;
    acc ^= aux;
    int quantum_71 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_71 = (quantum_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_5(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001876_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_25 = 0;
    for (int k = 0; k < 3; k++) {
        scale_25 = (scale_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_25) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001876_7613_6(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001876_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int tally_69 = local_arr[aux % 3];
    acc = (acc + tally_69 * 2) & 127;
    int residue_77 = 0;
    for (int k = 0; k < 3; k++) {
        residue_77 = (residue_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_77) & 127;
    }
    int damping_25 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_25 > 40) {
        acc = (acc + damping_25 * 2 + 5) & 127;
        aux ^= (damping_25 & 15);
    } else {
        acc = (acc - damping_25 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001876_7613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001876_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int metric_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_96) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_70 = local_arr[aux % 3];
    acc = (acc + cursor_70 * 2) & 127;
    int stride_24 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_24 > 42) {
        acc = (acc + stride_24 * 2 + 5) & 127;
        aux ^= (stride_24 & 15);
    } else {
        acc = (acc - stride_24 + 11) & 127;
        aux += 3;
    }
    int accumulator_58 = (aux + st.buffer[1]) & 3;
    switch (accumulator_58) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_8(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001876_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int sample_45 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_45 > 41) {
        acc = (acc + sample_45 * 2 + 5) & 127;
        aux ^= (sample_45 & 15);
    } else {
        acc = (acc - sample_45 + 11) & 127;
        aux += 3;
    }
    int window_57 = (aux + st.buffer[1]) & 3;
    switch (window_57) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_74 = local_arr[aux % 3];
    acc = (acc + threshold_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001876_7613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001876_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int coefficient_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_69) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_67 = (aux + st.buffer[1]) & 3;
    switch (margin_67) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_87 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_87 > 40) {
        acc = (acc + quotient_87 * 2 + 5) & 127;
        aux ^= (quotient_87 & 15);
    } else {
        acc = (acc - quotient_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_10(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001876_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int cursor_75 = local_arr[aux % 3];
    acc = (acc + cursor_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_95 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_95 > 38) {
        acc = (acc + bound_95 * 2 + 5) & 127;
        aux ^= (bound_95 & 15);
    } else {
        acc = (acc - bound_95 + 11) & 127;
        aux += 3;
    }
    int phase_55 = 0;
    for (int k = 0; k < 2; k++) {
        phase_55 = (phase_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001876_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_16 = (aux + st.buffer[1]) & 3;
    switch (damping_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_65 = local_arr[aux % 3];
    acc = (acc + accumulator_65 * 2) & 127;
    int segment_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001876_7613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001876_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int delta_17 = local_arr[aux % 3];
    acc = (acc + delta_17 * 2) & 127;
    int mask_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_31) & 63;
    acc ^= aux;
    int anchor_76 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_76 = (anchor_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_76) & 127;
    }
    int offset_44 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_44 > 35) {
        acc = (acc + offset_44 * 2 + 5) & 127;
        aux ^= (offset_44 & 15);
    } else {
        acc = (acc - offset_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_13(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001876_7613_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int anchor_29 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_29 > 34) {
        acc = (acc + anchor_29 * 2 + 5) & 127;
        aux ^= (anchor_29 & 15);
    } else {
        acc = (acc - anchor_29 + 11) & 127;
        aux += 3;
    }
    int threshold_55 = 0;
    for (int k = 0; k < 2; k++) {
        threshold_55 = (threshold_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_14(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001876_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int vector_27 = (aux + st.buffer[1]) & 3;
    switch (vector_27) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_39 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_39 > 36) {
        acc = (acc + anchor_39 * 2 + 5) & 127;
        aux ^= (anchor_39 & 15);
    } else {
        acc = (acc - anchor_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001876_7613_15(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001876_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_18 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_18 > 18) {
        acc = (acc + sample_18 * 2 + 5) & 127;
        aux ^= (sample_18 & 15);
    } else {
        acc = (acc - sample_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_19 = local_arr[aux % 3];
    acc = (acc + threshold_19 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001876_0;
    int sec_r001876_1;
    int sec_r001876_2;
    int sec_r001876_3;
    int sec_r001876_4;
    int sec_r001876_5;
    int sec_r001876_6;
    int sec_r001876_7;
    int sec_r001876_8;
    int sec_r001876_9;
    int sec_r001876_10;
    int sec_r001876_11;
    int sec_r001876_12;
    int sec_r001876_13;
    int sec_r001876_14;
    int sec_r001876_15;
    int sec_r001876_16;
    int sec_r001876_17;
    int sec_r001876_18;
    int sec_r001876_19;
    int sec_r001876_20;
    int sec_r001876_21;
    int pub_r001876_0;
    int pub_r001876_1;
    int pub_r001876_2;
    int pub_r001876_3;
    int pub_r001876_4;
    int pub_r001876_5;
    int pub_r001876_6;
    int pub_r001876_7;
    int pub_r001876_8;
    int pub_r001876_9;
    int pub_r001876_10;
    int pub_r001876_11;
    int pub_r001876_12;
    int pub_r001876_13;
    int pub_r001876_14;
    int pub_r001876_15;
    int pub_r001876_16;
    int pub_r001876_17;
    int pub_r001876_18;
    int pub_r001876_19;
    int pub_r001876_20;
    int pub_r001876_21;
    int pub_r001876_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001876_0 >= -100 && pub_r001876_0 <= 100);
    __CPROVER_assume(pub_r001876_1 >= -100 && pub_r001876_1 <= 100);
    __CPROVER_assume(pub_r001876_2 >= -100 && pub_r001876_2 <= 100);
    __CPROVER_assume(pub_r001876_3 >= -100 && pub_r001876_3 <= 100);
    __CPROVER_assume(pub_r001876_4 >= -100 && pub_r001876_4 <= 100);
    __CPROVER_assume(pub_r001876_5 >= -100 && pub_r001876_5 <= 100);
    __CPROVER_assume(pub_r001876_6 >= -100 && pub_r001876_6 <= 100);
    __CPROVER_assume(pub_r001876_7 >= -100 && pub_r001876_7 <= 100);
    __CPROVER_assume(pub_r001876_8 >= -100 && pub_r001876_8 <= 100);
    __CPROVER_assume(pub_r001876_9 >= -100 && pub_r001876_9 <= 100);
    __CPROVER_assume(pub_r001876_10 >= -100 && pub_r001876_10 <= 100);
    __CPROVER_assume(pub_r001876_11 >= -100 && pub_r001876_11 <= 100);
    __CPROVER_assume(pub_r001876_12 >= -100 && pub_r001876_12 <= 100);
    __CPROVER_assume(pub_r001876_13 >= -100 && pub_r001876_13 <= 100);
    __CPROVER_assume(pub_r001876_14 >= -100 && pub_r001876_14 <= 100);
    __CPROVER_assume(pub_r001876_15 >= -100 && pub_r001876_15 <= 100);
    __CPROVER_assume(pub_r001876_16 >= -100 && pub_r001876_16 <= 100);
    __CPROVER_assume(pub_r001876_17 >= -100 && pub_r001876_17 <= 100);
    __CPROVER_assume(pub_r001876_18 >= -100 && pub_r001876_18 <= 100);
    __CPROVER_assume(pub_r001876_19 >= -100 && pub_r001876_19 <= 100);
    __CPROVER_assume(pub_r001876_20 >= -100 && pub_r001876_20 <= 100);
    __CPROVER_assume(pub_r001876_21 >= -100 && pub_r001876_21 <= 100);
    __CPROVER_assume(pub_r001876_22 >= -100 && pub_r001876_22 <= 100);
    __CPROVER_assume(sec_r001876_0 >= 0 && sec_r001876_0 <= 255);
    __CPROVER_assume(sec_r001876_1 >= 0 && sec_r001876_1 <= 255);
    __CPROVER_assume(sec_r001876_2 >= 0 && sec_r001876_2 <= 255);
    __CPROVER_assume(sec_r001876_3 >= 0 && sec_r001876_3 <= 255);
    __CPROVER_assume(sec_r001876_4 >= 0 && sec_r001876_4 <= 255);
    __CPROVER_assume(sec_r001876_5 >= 0 && sec_r001876_5 <= 255);
    __CPROVER_assume(sec_r001876_6 >= 0 && sec_r001876_6 <= 255);
    __CPROVER_assume(sec_r001876_7 >= 0 && sec_r001876_7 <= 255);
    __CPROVER_assume(sec_r001876_8 >= 0 && sec_r001876_8 <= 255);
    __CPROVER_assume(sec_r001876_9 >= 0 && sec_r001876_9 <= 255);
    __CPROVER_assume(sec_r001876_10 >= 0 && sec_r001876_10 <= 255);
    __CPROVER_assume(sec_r001876_11 >= 0 && sec_r001876_11 <= 255);
    __CPROVER_assume(sec_r001876_12 >= 0 && sec_r001876_12 <= 255);
    __CPROVER_assume(sec_r001876_13 >= 0 && sec_r001876_13 <= 255);
    __CPROVER_assume(sec_r001876_14 >= 0 && sec_r001876_14 <= 255);
    __CPROVER_assume(sec_r001876_15 >= 0 && sec_r001876_15 <= 255);
    __CPROVER_assume(sec_r001876_16 >= 0 && sec_r001876_16 <= 255);
    __CPROVER_assume(sec_r001876_17 >= 0 && sec_r001876_17 <= 255);
    __CPROVER_assume(sec_r001876_18 >= 0 && sec_r001876_18 <= 255);
    __CPROVER_assume(sec_r001876_19 >= 0 && sec_r001876_19 <= 255);
    __CPROVER_assume(sec_r001876_20 >= 0 && sec_r001876_20 <= 255);
    __CPROVER_assume(sec_r001876_21 >= 0 && sec_r001876_21 <= 255);

    struct SensorNode_R001876_7613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001876_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001876_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001876_0 + 7) & 15;
    struct FilterState_R001876_7613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001876_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001876_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001876_0 + 9) & 15;
    struct StreamBuffer_R001876_7613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001876_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001876_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001876_0 + 11) & 15;
    struct EventLog_R001876_7613_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001876_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001876_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001876_0 + 13) & 15;

    union PacketPayload_R001876_7613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001876_7613_0(sec_r001876_0, sec_r001876_1);
    int helper_flow_1 = fn_R001876_7613_1(sec_r001876_1, sec_r001876_2);
    int helper_flow_2 = fn_R001876_7613_2(sec_r001876_2, pub_r001876_3);
    int helper_flow_3 = fn_R001876_7613_3(sec_r001876_3, pub_r001876_4);
    int helper_flow_4 = fn_R001876_7613_4(sec_r001876_4, pub_r001876_5, pub_r001876_6, pub_r001876_7);
    int helper_flow_5 = fn_R001876_7613_5(sec_r001876_5, sec_r001876_6, pub_r001876_7);
    int helper_flow_6 = fn_R001876_7613_6(sec_r001876_6, pub_r001876_7);
    int helper_flow_7 = fn_R001876_7613_7(sec_r001876_7, sec_r001876_8, pub_r001876_9, pub_r001876_10);
    int helper_flow_8 = fn_R001876_7613_8(sec_r001876_8, pub_r001876_9, pub_r001876_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001876_12 + pub_r001876_5 * 2 + 5) & 127;
    if (stage_v_0 > 32) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001876_13 + pub_r001876_4 * 2 + 8) & 127;
    if (stage_v_1 > 51) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001876_19 + pub_r001876_9 * 2 + 11) & 127;
    if (stage_v_2 > 53) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001876_2 + pub_r001876_18 * 2 + 14) & 127;
    if (stage_v_3 > 15) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001876_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_0 + pub_r001876_7 * 2 + 20) & 127;
    if (stage_v_5 > 30) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001876_15 + pub_r001876_15 * 2 + 23) & 127;
    if (stage_v_6 > 35) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001876_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_6 + pub_r001876_2 * 2 + 29) & 127;
    if (stage_v_8 > 21) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (helper_flow_8 + pub_r001876_17 * 2 + 32) & 127;
    if (stage_v_9 > 44) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001876_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001876_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_2 + pub_r001876_8 * 2 + 41) & 127;
    if (stage_v_12 > 32) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001876_4 + pub_r001876_0 * 2 + 44) & 127;
    if (stage_v_13 > 15) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_4 + pub_r001876_3 * 2 + 47) & 127;
    if (stage_v_14 > 41) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001876_20 + pub_r001876_12 * 2 + 50) & 127;
    if (stage_v_15 > 22) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001876_8 + pub_r001876_12 * 2 + 53) & 127;
    if (stage_v_16 > 27) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001876_20 + pub_r001876_3 * 2 + 56) & 127;
    if (stage_v_17 > 37) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001876_5 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001876_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_1 + pub_r001876_11 * 2 + 65) & 127;
    if (stage_v_20 > 26) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_8 + pub_r001876_11 * 2 + 68) & 127;
    if (stage_v_21 > 27) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001876_8 + pub_r001876_5 * 2 + 71) & 127;
    if (stage_v_22 > 34) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001876_19 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001876_15 + pub_r001876_8 * 2 + 77) & 127;
    if (stage_v_24 > 21) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001876_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001876_3 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_0 + pub_r001876_16 * 2 + 86) & 127;
    if (stage_v_27 > 49) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001876_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001876_9 + pub_r001876_1 * 2 + 92) & 127;
    if (stage_v_29 > 60) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_3 + pub_r001876_2 * 2 + 95) & 127;
    if (stage_v_30 > 33) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_1 + pub_r001876_10 * 2 + 98) & 127;
    if (stage_v_31 > 30) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001876_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001876_20 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_5 + pub_r001876_17 * 2 + 107) & 127;
    if (stage_v_34 > 38) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_15 + pub_r001876_12 * 2 + 110) & 127;
    if (stage_v_35 > 36) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (helper_flow_1 + pub_r001876_19 * 2 + 113) & 127;
    if (stage_v_36 > 25) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001876_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_21 + pub_r001876_15 * 2 + 119) & 127;
    if (stage_v_38 > 43) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001876_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001876_19 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001876_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001876_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_8 + pub_r001876_12 * 2 + 134) & 127;
    if (stage_v_43 > 50) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001876_6 + pub_r001876_14 * 2 + 137) & 127;
    if (stage_v_44 > 22) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_16 + pub_r001876_6 * 2 + 140) & 127;
    if (stage_v_45 > 57) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001876_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001876_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001876_13 + pub_r001876_15 * 2 + 149) & 127;
    if (stage_v_48 > 23) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001876_20 + pub_r001876_19 * 2 + 152) & 127;
    if (stage_v_49 > 57) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_44 + pub_r001876_2 * 2 + 155) & 127;
    if (stage_v_50 > 48) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (helper_flow_4 + pub_r001876_16 * 2 + 158) & 127;
    if (stage_v_51 > 38) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001876_17 + pub_r001876_11 * 2 + 161) & 127;
    if (stage_v_52 > 48) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001876_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001876_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001876_18 + pub_r001876_3 * 2 + 170) & 127;
    if (stage_v_55 > 45) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001876_20 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_17 + pub_r001876_7 * 2 + 176) & 127;
    if (stage_v_57 > 20) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
        sec_accum ^= (stage_v_57 & 31);
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001876_6 + pub_r001876_15 * 2 + 179) & 127;
    if (stage_v_58 > 41) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r001876_14 + pub_r001876_9 * 2 + 182) & 127;
    if (stage_v_59 > 52) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (sec_r001876_11 + pub_r001876_22 * 2 + 185) & 127;
    if (stage_v_60 > 42) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001876_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001876_4 + pub_r001876_21 * 2 + 191) & 127;
    if (stage_v_62 > 18) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_31 + pub_r001876_8 * 2 + 194) & 127;
    if (stage_v_63 > 51) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001876_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_35 + pub_r001876_9 * 2 + 200) & 127;
    if (stage_v_65 > 44) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001876_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001876_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001876_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r001876_9 + pub_r001876_21 * 2 + 212) & 127;
    if (stage_v_69 > 38) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
        sec_accum ^= (stage_v_69 & 31);
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001876_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (sec_r001876_14 + pub_r001876_17 * 2 + 218) & 127;
    if (stage_v_71 > 38) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_71 + pub_r001876_8 * 2 + 221) & 127;
    if (stage_v_72 > 24) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001876_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001876_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001876_6 + pub_r001876_5 * 2 + 230) & 127;
    if (stage_v_75 > 52) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_60 + pub_r001876_14 * 2 + 233) & 127;
    if (stage_v_76 > 23) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_34 + pub_r001876_11 * 2 + 236) & 127;
    if (stage_v_77 > 36) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_31 + pub_r001876_9 * 2 + 239) & 127;
    if (stage_v_78 > 40) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (sec_r001876_21 + pub_r001876_19 * 2 + 242) & 127;
    if (stage_v_79 > 24) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001876_21 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_43 + pub_r001876_10 * 2 + 248) & 127;
    if (stage_v_81 > 55) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001876_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001876_20 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_58 + pub_r001876_1 * 2 + 257) & 127;
    if (stage_v_84 > 29) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_63 + pub_r001876_14 * 2 + 260) & 127;
    if (stage_v_85 > 56) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_21 + pub_r001876_19 * 2 + 263) & 127;
    if (stage_v_86 > 56) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_44 + pub_r001876_16 * 2 + 266) & 127;
    if (stage_v_87 > 16) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_5 + pub_r001876_11 * 2 + 269) & 127;
    if (stage_v_88 > 17) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001876_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001876_12 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001876_5 + pub_r001876_2 * 2 + 278) & 127;
    if (stage_v_91 > 44) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001876_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001876_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_69 + pub_r001876_19 * 2 + 287) & 127;
    if (stage_v_94 > 58) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001876_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_13 + pub_r001876_17 * 2 + 293) & 127;
    if (stage_v_96 > 48) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_58 + pub_r001876_19 * 2 + 296) & 127;
    if (stage_v_97 > 46) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001876_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001876_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001876_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_30 + pub_r001876_11 * 2 + 308) & 127;
    if (stage_v_101 > 45) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001876_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001876_5 + pub_r001876_16 * 2 + 314) & 127;
    if (stage_v_103 > 49) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001876_17 + pub_r001876_8 * 2 + 317) & 127;
    if (stage_v_104 > 49) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_97 + pub_r001876_15 * 2 + 320) & 127;
    if (stage_v_105 > 32) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_20 + pub_r001876_22 * 2 + 323) & 127;
    if (stage_v_106 > 41) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001876_8 + pub_r001876_0 * 2 + 326) & 127;
    if (stage_v_107 > 43) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001876_22 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001876_21 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_17 + pub_r001876_4 * 2 + 335) & 127;
    if (stage_v_110 > 39) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_27 + pub_r001876_20 * 2 + 338) & 127;
    if (stage_v_111 > 28) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_43 + pub_r001876_20 * 2 + 341) & 127;
    if (stage_v_112 > 54) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
        sec_accum ^= (stage_v_112 & 31);
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (helper_flow_3 + pub_r001876_20 * 2 + 344) & 127;
    if (stage_v_113 > 25) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001876_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_101 + pub_r001876_22 * 2 + 350) & 127;
    if (stage_v_115 > 34) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_31 + pub_r001876_15 * 2 + 353) & 127;
    if (stage_v_116 > 33) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_65 + pub_r001876_17 * 2 + 356) & 127;
    if (stage_v_117 > 41) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r001876_4 + pub_r001876_1 * 2 + 359) & 127;
    if (stage_v_118 > 24) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_8 + pub_r001876_12 * 2 + 362) & 127;
    if (stage_v_119 > 31) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001876_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_104 + pub_r001876_14 * 2 + 368) & 127;
    if (stage_v_121 > 59) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_97 + pub_r001876_1 * 2 + 371) & 127;
    if (stage_v_122 > 22) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (helper_flow_3 + pub_r001876_22 * 2 + 374) & 127;
    if (stage_v_123 > 43) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001876_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001876_20 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_55 + pub_r001876_11 * 2 + 383) & 127;
    if (stage_v_126 > 23) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001876_22 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_105 + pub_r001876_19 * 2 + 389) & 127;
    if (stage_v_128 > 36) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_116 + pub_r001876_8 * 2 + 392) & 127;
    if (stage_v_129 > 52) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001876_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001876_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001876_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_59 + pub_r001876_4 * 2 + 404) & 127;
    if (stage_v_133 > 42) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001876_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001876_8 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_117 + pub_r001876_11 * 2 + 413) & 127;
    if (stage_v_136 > 33) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_34 + pub_r001876_22 * 2 + 416) & 127;
    if (stage_v_137 > 50) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001876_6 + pub_r001876_9 * 2 + 419) & 127;
    if (stage_v_138 > 59) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
        sec_accum ^= (stage_v_138 & 31);
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (helper_flow_4 + pub_r001876_8 * 2 + 422) & 127;
    if (stage_v_139 > 46) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001876_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_136 + pub_r001876_16 * 2 + 428) & 127;
    if (stage_v_141 > 43) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_55 + pub_r001876_20 * 2 + 431) & 127;
    if (stage_v_142 > 58) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001876_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001876_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_81 + pub_r001876_11 * 2 + 440) & 127;
    if (stage_v_145 > 26) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_52 + pub_r001876_15 * 2 + 443) & 127;
    if (stage_v_146 > 19) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (sec_r001876_8 + pub_r001876_2 * 2 + 446) & 127;
    if (stage_v_147 > 58) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_59 + pub_r001876_9 * 2 + 449) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001876_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001876_7 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_9 + pub_r001876_13 * 2 + 458) & 127;
    if (stage_v_151 > 30) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_38 + pub_r001876_18 * 2 + 461) & 127;
    if (stage_v_152 > 35) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001876_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001876_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001876_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_119 + pub_r001876_10 * 2 + 473) & 127;
    if (stage_v_156 > 30) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_145 + pub_r001876_0 * 2 + 476) & 127;
    if (stage_v_157 > 17) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_112 + pub_r001876_12 * 2 + 479) & 127;
    if (stage_v_158 > 52) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_94 + pub_r001876_10 * 2 + 482) & 127;
    if (stage_v_159 > 47) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_65 + pub_r001876_8 * 2 + 485) & 127;
    if (stage_v_160 > 53) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001876_22 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_119 + pub_r001876_22 * 2 + 491) & 127;
    if (stage_v_162 > 50) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_63 + pub_r001876_21 * 2 + 494) & 127;
    if (stage_v_163 > 16) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001876_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_111 + pub_r001876_2 * 2 + 500) & 127;
    if (stage_v_165 > 31) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001876_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001876_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_21 + pub_r001876_0 * 2 + 509) & 127;
    if (stage_v_168 > 20) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_107 + pub_r001876_20 * 2 + 512) & 127;
    if (stage_v_169 > 51) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001876_22 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_31 + pub_r001876_21 * 2 + 518) & 127;
    if (stage_v_171 > 53) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_45 + pub_r001876_11 * 2 + 521) & 127;
    if (stage_v_172 > 16) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_59 + pub_r001876_13 * 2 + 524) & 127;
    if (stage_v_173 > 50) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_30 + pub_r001876_12 * 2 + 527) & 127;
    if (stage_v_174 > 23) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
        sec_accum ^= (stage_v_174 & 31);
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_168 + pub_r001876_19 * 2 + 530) & 127;
    if (stage_v_175 > 33) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_115 + pub_r001876_9 * 2 + 533) & 127;
    if (stage_v_176 > 33) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_115 + pub_r001876_11 * 2 + 536) & 127;
    if (stage_v_177 > 24) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
        sec_accum ^= (stage_v_177 & 31);
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_101 + pub_r001876_20 * 2 + 539) & 127;
    if (stage_v_178 > 50) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_6 + pub_r001876_7 * 2 + 542) & 127;
    if (stage_v_179 > 55) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_36 + pub_r001876_7 * 2 + 545) & 127;
    if (stage_v_180 > 46) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001876_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_71 + pub_r001876_6 * 2 + 551) & 127;
    if (stage_v_182 > 22) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_59 + pub_r001876_22 * 2 + 554) & 127;
    if (stage_v_183 > 30) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_69 + pub_r001876_9 * 2 + 557) & 127;
    if (stage_v_184 > 28) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001876_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001876_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_20 + pub_r001876_10 * 2 + 566) & 127;
    if (stage_v_187 > 35) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_133 + pub_r001876_12 * 2 + 569) & 127;
    if (stage_v_188 > 48) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
        sec_accum ^= (stage_v_188 & 31);
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_35 + pub_r001876_10 * 2 + 572) & 127;
    if (stage_v_189 > 58) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001876_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (sec_r001876_2 + pub_r001876_10 * 2 + 578) & 127;
    if (stage_v_191 > 30) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_86 + pub_r001876_16 * 2 + 581) & 127;
    if (stage_v_192 > 35) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001876_22 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (helper_flow_5 + pub_r001876_2 * 2 + 587) & 127;
    if (stage_v_194 > 20) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r001876_21 + pub_r001876_15 * 2 + 590) & 127;
    if (stage_v_195 > 48) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001876_18 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001876_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_103 + pub_r001876_15 * 2 + 599) & 127;
    if (stage_v_198 > 50) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (sec_r001876_17 + pub_r001876_3 * 2 + 602) & 127;
    if (stage_v_199 > 15) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_104 + pub_r001876_21 * 2 + 605) & 127;
    if (stage_v_200 > 51) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
        sec_accum ^= (stage_v_200 & 31);
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r001876_17 + pub_r001876_7 * 2 + 608) & 127;
    if (stage_v_201 > 60) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_85 + pub_r001876_0 * 2 + 611) & 127;
    if (stage_v_202 > 16) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001876_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r001876_8 + pub_r001876_7 * 2 + 617) & 127;
    if (stage_v_204 > 56) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_159 + pub_r001876_4 * 2 + 620) & 127;
    if (stage_v_205 > 31) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_48 + pub_r001876_6 * 2 + 623) & 127;
    if (stage_v_206 > 20) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
        sec_accum ^= (stage_v_206 & 31);
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001876_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_59 + pub_r001876_20 * 2 + 629) & 127;
    if (stage_v_208 > 32) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_118 + pub_r001876_19 * 2 + 632) & 127;
    if (stage_v_209 > 43) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001876_20 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001876_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001876_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001876_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_202 + pub_r001876_20 * 2 + 647) & 127;
    if (stage_v_214 > 51) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r001876_4 + pub_r001876_16 * 2 + 650) & 127;
    if (stage_v_215 > 42) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001876_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_202 + pub_r001876_12 * 2 + 656) & 127;
    if (stage_v_217 > 26) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_5 + pub_r001876_21 * 2 + 659) & 127;
    if (stage_v_218 > 32) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_17 + pub_r001876_12 * 2 + 662) & 127;
    if (stage_v_219 > 18) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_58 + pub_r001876_12 * 2 + 665) & 127;
    if (stage_v_220 > 40) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_60 + pub_r001876_16 * 2 + 668) & 127;
    if (stage_v_221 > 16) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_137 + pub_r001876_5 * 2 + 671) & 127;
    if (stage_v_222 > 34) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_110 + pub_r001876_1 * 2 + 674) & 127;
    if (stage_v_223 > 21) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_205 + pub_r001876_5 * 2 + 677) & 127;
    if (stage_v_224 > 38) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001876_19 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001876_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (sec_r001876_8 + pub_r001876_17 * 2 + 686) & 127;
    if (stage_v_227 > 46) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_16 + pub_r001876_14 * 2 + 689) & 127;
    if (stage_v_228 > 51) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001876_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_198 + pub_r001876_1 * 2 + 695) & 127;
    if (stage_v_230 > 47) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001876_9 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (stage_v_107 + pub_r001876_2 * 2 + 701) & 127;
    if (stage_v_232 > 36) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
        sec_accum ^= (stage_v_232 & 31);
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_133 + pub_r001876_20 * 2 + 704) & 127;
    if (stage_v_233 > 44) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001876_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_118 + pub_r001876_16 * 2 + 710) & 127;
    if (stage_v_235 > 40) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_38 + pub_r001876_8 * 2 + 713) & 127;
    if (stage_v_236 > 60) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (stage_v_148 + pub_r001876_8 * 2 + 716) & 127;
    if (stage_v_237 > 38) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
        sec_accum ^= (stage_v_237 & 31);
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001876_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001876_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (sec_r001876_15 + pub_r001876_22 * 2 + 725) & 127;
    if (stage_v_240 > 52) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_76 + pub_r001876_7 * 2 + 728) & 127;
    if (stage_v_241 > 22) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001876_20 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_148 + pub_r001876_3 * 2 + 734) & 127;
    if (stage_v_243 > 32) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
        sec_accum ^= (stage_v_243 & 31);
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001876_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (stage_v_133 + pub_r001876_6 * 2 + 740) & 127;
    if (stage_v_245 > 19) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
        sec_accum ^= (stage_v_245 & 31);
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001876_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001876_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001876_5 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_217 + pub_r001876_11 * 2 + 752) & 127;
    if (stage_v_249 > 26) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_121 + pub_r001876_16 * 2 + 755) & 127;
    if (stage_v_250 > 60) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
        sec_accum ^= (stage_v_250 & 31);
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (sec_r001876_7 + pub_r001876_10 * 2 + 758) & 127;
    if (stage_v_251 > 39) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (stage_v_76 + pub_r001876_3 * 2 + 761) & 127;
    if (stage_v_252 > 44) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
        sec_accum ^= (stage_v_252 & 31);
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_86 + pub_r001876_15 * 2 + 764) & 127;
    if (stage_v_253 > 49) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
        sec_accum ^= (stage_v_253 & 31);
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (stage_v_21 + pub_r001876_6 * 2 + 767) & 127;
    if (stage_v_254 > 17) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
        sec_accum ^= (stage_v_254 & 31);
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (sec_r001876_17 + pub_r001876_12 * 2 + 770) & 127;
    if (stage_v_255 > 22) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001876_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001876_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001876_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001876_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001876_16 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (stage_v_205 + pub_r001876_15 * 2 + 788) & 127;
    if (stage_v_261 > 21) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
        sec_accum ^= (stage_v_261 & 31);
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_159 + pub_r001876_0 * 2 + 791) & 127;
    if (stage_v_262 > 35) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
        sec_accum ^= (stage_v_262 & 31);
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (stage_v_14 + pub_r001876_4 * 2 + 794) & 127;
    if (stage_v_263 > 23) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
        sec_accum ^= (stage_v_263 & 31);
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001876_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001876_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001876_8 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (stage_v_1 + pub_r001876_17 * 2 + 806) & 127;
    if (stage_v_267 > 19) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
        sec_accum ^= (stage_v_267 & 31);
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (stage_v_5 + pub_r001876_2 * 2 + 809) & 127;
    if (stage_v_268 > 45) {
        out_sink = (out_sink + stage_v_268 * 2 + 7) & 255;
        sec_accum ^= (stage_v_268 & 31);
    } else {
        out_sink = (out_sink - stage_v_268 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (stage_v_163 + pub_r001876_1 * 2 + 812) & 127;
    if (stage_v_269 > 48) {
        out_sink = (out_sink + stage_v_269 * 2 + 7) & 255;
        sec_accum ^= (stage_v_269 & 31);
    } else {
        out_sink = (out_sink - stage_v_269 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (stage_v_21 + pub_r001876_15 * 2 + 815) & 127;
    if (stage_v_270 > 23) {
        out_sink = (out_sink + stage_v_270 * 2 + 7) & 255;
        sec_accum ^= (stage_v_270 & 31);
    } else {
        out_sink = (out_sink - stage_v_270 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (stage_v_71 + pub_r001876_3 * 2 + 818) & 127;
    if (stage_v_271 > 53) {
        out_sink = (out_sink + stage_v_271 * 2 + 7) & 255;
        sec_accum ^= (stage_v_271 & 31);
    } else {
        out_sink = (out_sink - stage_v_271 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
