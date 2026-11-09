/*
 * Benchmark Program: R001065
 * Security Family: bitwise_flow
 * Generator Seed: 606513
 * High Inputs: 22 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001065_6513_0 {
    int facility;
    int timestamp;
    unsigned char signature;
    short seq;
    int severity;
    int code;
    int buffer[3];
};

struct StreamBuffer_R001065_6513_1 {
    int head;
    int checksum;
    short state;
    int tail;
    int buffer[3];
};

struct CipherContext_R001065_6513_2 {
    int tag;
    int iv;
    int nonce;
    int counter;
    int round_key;
    int flags;
    int buffer[3];
};

struct AudioFrame_R001065_6513_3 {
    int gain;
    unsigned char channels;
    int sample_rate;
    unsigned char peak;
    unsigned char rms;
    short envelope;
    int buffer[3];
};

union PacketPayload_R001065_6513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union TelemetryField_R001065_6513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001065_6513_0(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001065_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_37 = (aux + st.buffer[1]) & 3;
    switch (sample_37) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_50 = (st.buffer[0] * 3 + aux) & 63;
    if (window_50 > 43) {
        acc = (acc + window_50 * 2 + 5) & 127;
        aux ^= (window_50 & 15);
    } else {
        acc = (acc - window_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_1(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int damping_88 = local_arr[aux % 3];
    acc = (acc + damping_88 * 2) & 127;
    int damping_45 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_45 > 10) {
        acc = (acc + damping_45 * 2 + 5) & 127;
        aux ^= (damping_45 & 15);
    } else {
        acc = (acc - damping_45 + 11) & 127;
        aux += 3;
    }
    int residue_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_28) & 63;
    acc ^= aux;
    int quantum_10 = (aux + st.buffer[1]) & 3;
    switch (quantum_10) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001065_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int threshold_67 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_67 > 41) {
        acc = (acc + threshold_67 * 2 + 5) & 127;
        aux ^= (threshold_67 & 15);
    } else {
        acc = (acc - threshold_67 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_52 = local_arr[aux % 3];
    acc = (acc + index_reg_52 * 2) & 127;
    int accumulator_69 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_69 = (accumulator_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_69) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_3(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001065_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int cursor_42 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_42 > 38) {
        acc = (acc + cursor_42 * 2 + 5) & 127;
        aux ^= (cursor_42 & 15);
    } else {
        acc = (acc - cursor_42 + 11) & 127;
        aux += 3;
    }
    int window_82 = (aux + st.buffer[1]) & 3;
    switch (window_82) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_95 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_95 = (quotient_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_95) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_4(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001065_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int segment_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_34) & 63;
    acc ^= aux;
    int metric_53 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_53 > 37) {
        acc = (acc + metric_53 * 2 + 5) & 127;
        aux ^= (metric_53 & 15);
    } else {
        acc = (acc - metric_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_5(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001065_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int scale_36 = 0;
    for (int k = 0; k < 2; k++) {
        scale_36 = (scale_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_36) & 127;
    }
    int damping_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_6(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_19 = 0;
    for (int k = 0; k < 3; k++) {
        phase_19 = (phase_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_19) & 127;
    }
    int pivot_64 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_64 > 17) {
        acc = (acc + pivot_64 * 2 + 5) & 127;
        aux ^= (pivot_64 & 15);
    } else {
        acc = (acc - pivot_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_25 = local_arr[aux % 3];
    acc = (acc + threshold_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001065_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_51 = 0;
    for (int k = 0; k < 2; k++) {
        damping_51 = (damping_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_51) & 127;
    }
    int threshold_52 = (aux + st.buffer[1]) & 3;
    switch (threshold_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_11 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_11 > 24) {
        acc = (acc + anchor_11 * 2 + 5) & 127;
        aux ^= (anchor_11 & 15);
    } else {
        acc = (acc - anchor_11 + 11) & 127;
        aux += 3;
    }
    int window_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int bound_90 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_90 > 23) {
        acc = (acc + bound_90 * 2 + 5) & 127;
        aux ^= (bound_90 & 15);
    } else {
        acc = (acc - bound_90 + 11) & 127;
        aux += 3;
    }
    int damping_40 = 0;
    for (int k = 0; k < 3; k++) {
        damping_40 = (damping_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_40) & 127;
    }
    int metric_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_9(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int scale_43 = local_arr[aux % 3];
    acc = (acc + scale_43 * 2) & 127;
    int tally_42 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_42 > 20) {
        acc = (acc + tally_42 * 2 + 5) & 127;
        aux ^= (tally_42 & 15);
    } else {
        acc = (acc - tally_42 + 11) & 127;
        aux += 3;
    }
    int index_reg_43 = (aux + st.buffer[1]) & 3;
    switch (index_reg_43) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_40) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001065_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_78 = (aux + st.buffer[1]) & 3;
    switch (quantum_78) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_11(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001065_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_94 = 0;
    for (int k = 0; k < 2; k++) {
        phase_94 = (phase_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_94) & 127;
    }
    int metric_28 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_28 > 20) {
        acc = (acc + metric_28 * 2 + 5) & 127;
        aux ^= (metric_28 & 15);
    } else {
        acc = (acc - metric_28 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_25 = local_arr[aux % 3];
    acc = (acc + cursor_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_12(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001065_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int sample_92 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_92 > 50) {
        acc = (acc + sample_92 * 2 + 5) & 127;
        aux ^= (sample_92 & 15);
    } else {
        acc = (acc - sample_92 + 11) & 127;
        aux += 3;
    }
    int scale_32 = 0;
    for (int k = 0; k < 2; k++) {
        scale_32 = (scale_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_32) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int offset_15 = (aux + st.buffer[1]) & 3;
    switch (offset_15) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_33 = 0;
    for (int k = 0; k < 3; k++) {
        offset_33 = (offset_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_33) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_14(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001065_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_51 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_51 > 31) {
        acc = (acc + delta_51 * 2 + 5) & 127;
        aux ^= (delta_51 & 15);
    } else {
        acc = (acc - delta_51 + 11) & 127;
        aux += 3;
    }
    int pivot_50 = (aux + st.buffer[1]) & 3;
    switch (pivot_50) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001065_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_93 = (aux + st.buffer[1]) & 3;
    switch (vector_93) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_62) & 63;
    acc ^= aux;
    int factor_48 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_48 > 13) {
        acc = (acc + factor_48 * 2 + 5) & 127;
        aux ^= (factor_48 & 15);
    } else {
        acc = (acc - factor_48 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001065_6513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int stride_97 = (aux + st.buffer[1]) & 3;
    switch (stride_97) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_88 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_88 = (pivot_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_88) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_17(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001065_6513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int vector_26 = local_arr[aux % 3];
    acc = (acc + vector_26 * 2) & 127;
    int phase_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_18(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001065_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int index_reg_24 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_24 > 40) {
        acc = (acc + index_reg_24 * 2 + 5) & 127;
        aux ^= (index_reg_24 & 15);
    } else {
        acc = (acc - index_reg_24 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_79 = local_arr[aux % 3];
    acc = (acc + weight_79 * 2) & 127;
    int bound_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001065_6513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int offset_70 = 0;
    for (int k = 0; k < 2; k++) {
        offset_70 = (offset_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_70) & 127;
    }
    int tracker_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int coefficient_80 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_80 = (coefficient_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_80) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_69 = local_arr[aux % 3];
    acc = (acc + threshold_69 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001065_6513_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001065_6513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int stride_30 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_30 > 26) {
        acc = (acc + stride_30 * 2 + 5) & 127;
        aux ^= (stride_30 & 15);
    } else {
        acc = (acc - stride_30 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001065_6513_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001065_6513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_83 = 0;
    for (int k = 0; k < 3; k++) {
        residue_83 = (residue_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_83) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_41 = local_arr[aux % 3];
    acc = (acc + phase_41 * 2) & 127;
    int sample_29 = (aux + st.buffer[1]) & 3;
    switch (sample_29) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001065_0;
    int sec_r001065_1;
    int sec_r001065_2;
    int sec_r001065_3;
    int sec_r001065_4;
    int sec_r001065_5;
    int sec_r001065_6;
    int sec_r001065_7;
    int sec_r001065_8;
    int sec_r001065_9;
    int sec_r001065_10;
    int sec_r001065_11;
    int sec_r001065_12;
    int sec_r001065_13;
    int sec_r001065_14;
    int sec_r001065_15;
    int sec_r001065_16;
    int sec_r001065_17;
    int sec_r001065_18;
    int sec_r001065_19;
    int sec_r001065_20;
    int sec_r001065_21;
    int pub_r001065_0;
    int pub_r001065_1;
    int pub_r001065_2;
    int pub_r001065_3;
    int pub_r001065_4;
    int pub_r001065_5;
    int pub_r001065_6;
    int pub_r001065_7;
    int pub_r001065_8;
    int pub_r001065_9;
    int pub_r001065_10;
    int pub_r001065_11;
    int pub_r001065_12;
    int pub_r001065_13;
    int pub_r001065_14;
    int pub_r001065_15;
    int pub_r001065_16;
    int pub_r001065_17;
    int pub_r001065_18;
    int pub_r001065_19;
    int pub_r001065_20;
    int pub_r001065_21;
    int pub_r001065_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001065_0 >= -100 && pub_r001065_0 <= 100);
    __CPROVER_assume(pub_r001065_1 >= -100 && pub_r001065_1 <= 100);
    __CPROVER_assume(pub_r001065_2 >= -100 && pub_r001065_2 <= 100);
    __CPROVER_assume(pub_r001065_3 >= -100 && pub_r001065_3 <= 100);
    __CPROVER_assume(pub_r001065_4 >= -100 && pub_r001065_4 <= 100);
    __CPROVER_assume(pub_r001065_5 >= -100 && pub_r001065_5 <= 100);
    __CPROVER_assume(pub_r001065_6 >= -100 && pub_r001065_6 <= 100);
    __CPROVER_assume(pub_r001065_7 >= -100 && pub_r001065_7 <= 100);
    __CPROVER_assume(pub_r001065_8 >= -100 && pub_r001065_8 <= 100);
    __CPROVER_assume(pub_r001065_9 >= -100 && pub_r001065_9 <= 100);
    __CPROVER_assume(pub_r001065_10 >= -100 && pub_r001065_10 <= 100);
    __CPROVER_assume(pub_r001065_11 >= -100 && pub_r001065_11 <= 100);
    __CPROVER_assume(pub_r001065_12 >= -100 && pub_r001065_12 <= 100);
    __CPROVER_assume(pub_r001065_13 >= -100 && pub_r001065_13 <= 100);
    __CPROVER_assume(pub_r001065_14 >= -100 && pub_r001065_14 <= 100);
    __CPROVER_assume(pub_r001065_15 >= -100 && pub_r001065_15 <= 100);
    __CPROVER_assume(pub_r001065_16 >= -100 && pub_r001065_16 <= 100);
    __CPROVER_assume(pub_r001065_17 >= -100 && pub_r001065_17 <= 100);
    __CPROVER_assume(pub_r001065_18 >= -100 && pub_r001065_18 <= 100);
    __CPROVER_assume(pub_r001065_19 >= -100 && pub_r001065_19 <= 100);
    __CPROVER_assume(pub_r001065_20 >= -100 && pub_r001065_20 <= 100);
    __CPROVER_assume(pub_r001065_21 >= -100 && pub_r001065_21 <= 100);
    __CPROVER_assume(pub_r001065_22 >= -100 && pub_r001065_22 <= 100);
    __CPROVER_assume(sec_r001065_0 >= 0 && sec_r001065_0 <= 255);
    __CPROVER_assume(sec_r001065_1 >= 0 && sec_r001065_1 <= 255);
    __CPROVER_assume(sec_r001065_2 >= 0 && sec_r001065_2 <= 255);
    __CPROVER_assume(sec_r001065_3 >= 0 && sec_r001065_3 <= 255);
    __CPROVER_assume(sec_r001065_4 >= 0 && sec_r001065_4 <= 255);
    __CPROVER_assume(sec_r001065_5 >= 0 && sec_r001065_5 <= 255);
    __CPROVER_assume(sec_r001065_6 >= 0 && sec_r001065_6 <= 255);
    __CPROVER_assume(sec_r001065_7 >= 0 && sec_r001065_7 <= 255);
    __CPROVER_assume(sec_r001065_8 >= 0 && sec_r001065_8 <= 255);
    __CPROVER_assume(sec_r001065_9 >= 0 && sec_r001065_9 <= 255);
    __CPROVER_assume(sec_r001065_10 >= 0 && sec_r001065_10 <= 255);
    __CPROVER_assume(sec_r001065_11 >= 0 && sec_r001065_11 <= 255);
    __CPROVER_assume(sec_r001065_12 >= 0 && sec_r001065_12 <= 255);
    __CPROVER_assume(sec_r001065_13 >= 0 && sec_r001065_13 <= 255);
    __CPROVER_assume(sec_r001065_14 >= 0 && sec_r001065_14 <= 255);
    __CPROVER_assume(sec_r001065_15 >= 0 && sec_r001065_15 <= 255);
    __CPROVER_assume(sec_r001065_16 >= 0 && sec_r001065_16 <= 255);
    __CPROVER_assume(sec_r001065_17 >= 0 && sec_r001065_17 <= 255);
    __CPROVER_assume(sec_r001065_18 >= 0 && sec_r001065_18 <= 255);
    __CPROVER_assume(sec_r001065_19 >= 0 && sec_r001065_19 <= 255);
    __CPROVER_assume(sec_r001065_20 >= 0 && sec_r001065_20 <= 255);
    __CPROVER_assume(sec_r001065_21 >= 0 && sec_r001065_21 <= 255);

    struct EventLog_R001065_6513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001065_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001065_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001065_0 + 7) & 15;
    struct StreamBuffer_R001065_6513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001065_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001065_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001065_0 + 9) & 15;
    struct CipherContext_R001065_6513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001065_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001065_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001065_0 + 11) & 15;
    struct AudioFrame_R001065_6513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001065_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001065_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001065_0 + 13) & 15;

    union PacketPayload_R001065_6513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001065_6513_0(sec_r001065_0, sec_r001065_1, pub_r001065_2);
    int helper_flow_1 = fn_R001065_6513_1(sec_r001065_1, pub_r001065_2, pub_r001065_3);
    int helper_flow_2 = fn_R001065_6513_2(sec_r001065_2, sec_r001065_3, pub_r001065_4, pub_r001065_5);
    int helper_flow_3 = fn_R001065_6513_3(sec_r001065_3, pub_r001065_4, pub_r001065_5);
    int helper_flow_4 = fn_R001065_6513_4(sec_r001065_4, pub_r001065_5);
    int helper_flow_5 = fn_R001065_6513_5(sec_r001065_5, sec_r001065_6, pub_r001065_7);
    int helper_flow_6 = fn_R001065_6513_6(sec_r001065_6, pub_r001065_7, pub_r001065_8);
    int helper_flow_7 = fn_R001065_6513_7(sec_r001065_7, pub_r001065_8, pub_r001065_9, pub_r001065_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001065_13 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001065_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_5 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_2 + 1) & 15;
    out_sink ^= (stage_v_2 & 63);

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001065_17 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_1 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_4 + 1) & 15;
    out_sink ^= (stage_v_4 & 63);

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001065_18 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001065_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001065_6 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((sec_r001065_21 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001065_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001065_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001065_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001065_10 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001065_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((helper_flow_1 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_4 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001065_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001065_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001065_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001065_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_0 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001065_16 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001065_8 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001065_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001065_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_20 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001065_12 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001065_20 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001065_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_26 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001065_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_12 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_12 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((stage_v_14 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001065_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001065_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001065_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001065_9 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_2 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001065_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001065_21 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_1 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001065_1 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001065_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001065_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_5 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_0 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_7 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((helper_flow_4 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_48 + 1) & 15;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001065_2 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_14 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001065_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001065_8 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001065_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001065_16 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001065_15 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_55 + 1) & 15;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_3 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001065_12 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001065_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_37 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_12 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001065_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_54 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001065_11 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r001065_21 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_59 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_65 + 1) & 15;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001065_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001065_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r001065_15 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001065_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001065_22 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001065_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001065_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001065_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001065_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001065_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001065_8 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_65 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001065_12 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001065_14 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_46 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001065_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001065_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001065_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001065_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001065_9 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001065_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_48 << 1) ^ (pub_r001065_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_87 + 1) & 15;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_68 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001065_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_56 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_90 + 1) & 15;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_47 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001065_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((helper_flow_5 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001065_22 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001065_15 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001065_14 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_12 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_50 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001065_18 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001065_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001065_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001065_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001065_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001065_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_31 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001065_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((helper_flow_0 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001065_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_48 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001065_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001065_0 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001065_22 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001065_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001065_20 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001065_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_79 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_54 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001065_12 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001065_22 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001065_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_48 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_105 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((helper_flow_3 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_21 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001065_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001065_2 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_126 + 1) & 15;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_20 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001065_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001065_13 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001065_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001065_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r001065_4 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_118 << 1) ^ (pub_r001065_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001065_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_31 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_8 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001065_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001065_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001065_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_31 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r001065_14 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001065_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r001065_0 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_60 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001065_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r001065_21 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_146 + 1) & 15;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_85 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001065_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001065_19 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001065_21 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_38 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001065_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001065_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((helper_flow_1 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r001065_15 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_25 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_118 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_31 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001065_20 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001065_13 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001065_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001065_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001065_18 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_54 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001065_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_2 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001065_15 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_46 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_80 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_41 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_170 + 1) & 15;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001065_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001065_20 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001065_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001065_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_98 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_52 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_176 + 1) & 15;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001065_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_93 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001065_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_164 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001065_11 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001065_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_5 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_126 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001065_19 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_46 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_180 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_187 + 1) & 15;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_166 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_116 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_57 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_32 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001065_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001065_9 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r001065_12 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_194 + 1) & 15;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001065_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_140 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_196 + 1) & 15;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_191 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001065_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_90 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((helper_flow_7 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001065_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_199 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001065_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_4 << 1) ^ (pub_r001065_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001065_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001065_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_117 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_207 + 1) & 15;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001065_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_143 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_88 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001065_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_190 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_63 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_7 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001065_21 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001065_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_21 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001065_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_169 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001065_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001065_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001065_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001065_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_194 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_124 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r001065_16 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_48 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001065_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_175 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001065_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_90 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001065_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001065_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001065_21 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001065_19 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001065_20 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_38 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_237 + 1) & 15;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_157 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001065_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r001065_14 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_57 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_241 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_242 + 1) & 15;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_133 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_243 + 1) & 15;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001065_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001065_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_240 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001065_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_7 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001065_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_170 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001065_17 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001065_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_52 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_204 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((sec_r001065_1 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_59 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001065_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_99 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r001065_10 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_259 + 1) & 15;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_59 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_187 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_76 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((sec_r001065_17 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_57 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r001065_9 << 1) ^ (pub_r001065_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001065_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((sec_r001065_13 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_140 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_268 + 1) & 15;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001065_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_52 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001065_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001065_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_186 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001065_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((helper_flow_0 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_87 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_135 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001065_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((sec_r001065_11 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((helper_flow_5 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001065_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001065_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (pub_r001065_20 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_283) & 127;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_276 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001065_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_209 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (pub_r001065_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_287) & 127;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_121 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_213 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r001065_6 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001065_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (pub_r001065_10 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_292) & 127;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001065_19 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001065_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001065_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (pub_r001065_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_296) & 127;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_258 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((helper_flow_7 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001065_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_60 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((helper_flow_1 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001065_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_7 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (pub_r001065_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_304) & 127;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001065_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001065_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001065_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_209 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (pub_r001065_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_309) & 127;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_122 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001065_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r001065_21 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001065_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001065_7 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_14 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001065_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001065_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_136 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (pub_r001065_8 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_319) & 127;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001065_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001065_18 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_227 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_322 + 1) & 15;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_157 << 1) ^ (pub_r001065_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001065_18 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001065_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_240 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001065_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001065_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_262 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_62 << 1) ^ (pub_r001065_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((helper_flow_5 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r001065_11 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((helper_flow_0 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_196 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001065_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_141 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((helper_flow_4 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001065_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (pub_r001065_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_339) & 127;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001065_22 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_80 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((sec_r001065_18 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001065_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001065_20 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (pub_r001065_16 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_345) & 127;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001065_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_237 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (pub_r001065_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_348) & 127;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_265 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_349 + 1) & 15;
    out_sink ^= (stage_v_349 & 63);

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((helper_flow_5 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001065_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001065_21 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((helper_flow_3 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_336 << 1) ^ (pub_r001065_1 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((stage_v_267 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_355 + 1) & 15;
    out_sink ^= (stage_v_355 & 63);

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_178 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_57 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_248 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_226 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_246 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_7 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_176 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001065_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001065_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001065_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_194 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_79 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001065_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((stage_v_194 << 1) ^ (pub_r001065_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_369 + 1) & 15;
    out_sink ^= (stage_v_369 & 63);

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_350 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = ((stage_v_87 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_371 + 1) & 15;
    out_sink ^= (stage_v_371 & 63);

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001065_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001065_22 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = (pub_r001065_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_374) & 127;

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_254 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_180 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001065_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001065_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_97 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001065_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_258 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = (pub_r001065_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_382) & 127;

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001065_22 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001065_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001065_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_362 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = (pub_r001065_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_387) & 127;

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_183 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_15 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001065_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_261 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((sec_r001065_1 << 1) ^ (pub_r001065_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001065_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_20 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = ((stage_v_170 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_395 + 1) & 15;
    out_sink ^= (stage_v_395 & 63);

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((sec_r001065_20 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_8 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001065_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_124 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001065_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_262 << 1) ^ (pub_r001065_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_46 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((stage_v_99 << 1) ^ (pub_r001065_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001065_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = ((stage_v_155 << 1) ^ (pub_r001065_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_405 + 1) & 15;
    out_sink ^= (stage_v_405 & 63);

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_48 << 1) ^ (pub_r001065_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((sec_r001065_15 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001065_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_213 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_169 << 1) ^ (pub_r001065_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001065_3 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_260 << 1) ^ (pub_r001065_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001065_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001065_21 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((helper_flow_4 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((sec_r001065_4 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = (pub_r001065_8 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_417) & 127;

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_191 << 1) ^ (pub_r001065_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = (pub_r001065_18 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_419) & 127;

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_350 << 1) ^ (pub_r001065_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_227 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001065_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = (pub_r001065_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_423) & 127;

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001065_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001065_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001065_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001065_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = ((stage_v_91 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_428 + 1) & 15;
    out_sink ^= (stage_v_428 & 63);

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = ((stage_v_268 << 1) ^ (pub_r001065_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_429 + 1) & 15;
    out_sink ^= (stage_v_429 & 63);

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001065_21 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_212 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_367 << 1) ^ (pub_r001065_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_432 + 1) & 15;
    out_sink ^= (stage_v_432 & 63);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001065_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_396 << 1) ^ (pub_r001065_22 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_147 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = (pub_r001065_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_436) & 127;

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_56 << 1) ^ (pub_r001065_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001065_21 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_226 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001065_21 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = (pub_r001065_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_441) & 127;

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001065_22 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_105 << 1) ^ (pub_r001065_20 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001065_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_20 << 1) ^ (pub_r001065_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_277 << 1) ^ (pub_r001065_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = (pub_r001065_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_447) & 127;

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_415 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_79 << 1) ^ (pub_r001065_21 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = (pub_r001065_22 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_450) & 127;

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = ((stage_v_260 << 1) ^ (pub_r001065_18 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_451 + 1) & 15;
    out_sink ^= (stage_v_451 & 63);

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = ((stage_v_410 << 1) ^ (pub_r001065_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_452 + 1) & 15;
    out_sink ^= (stage_v_452 & 63);

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = ((stage_v_402 << 1) ^ (pub_r001065_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_453 + 1) & 15;
    out_sink ^= (stage_v_453 & 63);

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_98 << 1) ^ (pub_r001065_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_454 + 1) & 15;
    out_sink ^= (stage_v_454 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
