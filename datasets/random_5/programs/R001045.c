/*
 * Benchmark Program: R001045
 * Security Family: bitwise_flow
 * Generator Seed: 604513
 * High Inputs: 24 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001045_4513_0 {
    int timestamp;
    int severity;
    int code;
    int buffer[3];
};

struct AudioFrame_R001045_4513_1 {
    unsigned char rms;
    int peak;
    short gain;
    unsigned char sample_rate;
    int envelope;
    int buffer[3];
};

struct SensorNode_R001045_4513_2 {
    int threshold;
    int offset;
    unsigned char status;
    int gain;
    unsigned char reading;
    unsigned char calib;
    int buffer[3];
};

struct CipherContext_R001045_4513_3 {
    int tag;
    int nonce;
    short counter;
    int flags;
    int iv;
    int buffer[3];
};

union PacketPayload_R001045_4513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001045_4513_0(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_14 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_14 = (quantum_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_14) & 127;
    }
    int factor_72 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_72 > 23) {
        acc = (acc + factor_72 * 2 + 5) & 127;
        aux ^= (factor_72 & 15);
    } else {
        acc = (acc - factor_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001045_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int metric_24 = (aux + st.buffer[1]) & 3;
    switch (metric_24) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_88 = 0;
    for (int k = 0; k < 3; k++) {
        weight_88 = (weight_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_88) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001045_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int damping_43 = 0;
    for (int k = 0; k < 2; k++) {
        damping_43 = (damping_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_43) & 127;
    }
    int mask_62 = (aux + st.buffer[1]) & 3;
    switch (mask_62) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_87 = local_arr[aux % 3];
    acc = (acc + pivot_87 * 2) & 127;
    int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001045_4513_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001045_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_87 = 0;
    for (int k = 0; k < 3; k++) {
        damping_87 = (damping_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_87) & 127;
    }
    int checksum_58 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_58 > 33) {
        acc = (acc + checksum_58 * 2 + 5) & 127;
        aux ^= (checksum_58 & 15);
    } else {
        acc = (acc - checksum_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001045_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int metric_74 = 0;
    for (int k = 0; k < 3; k++) {
        metric_74 = (metric_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_74) & 127;
    }
    int window_54 = (aux + st.buffer[1]) & 3;
    switch (window_54) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001045_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int quantum_80 = (aux + st.buffer[1]) & 3;
    switch (quantum_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_35 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_35 > 39) {
        acc = (acc + checksum_35 * 2 + 5) & 127;
        aux ^= (checksum_35 & 15);
    } else {
        acc = (acc - checksum_35 + 11) & 127;
        aux += 3;
    }
    int sample_12 = 0;
    for (int k = 0; k < 2; k++) {
        sample_12 = (sample_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_6(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001045_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int stride_11 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_11 > 34) {
        acc = (acc + stride_11 * 2 + 5) & 127;
        aux ^= (stride_11 & 15);
    } else {
        acc = (acc - stride_11 + 11) & 127;
        aux += 3;
    }
    int stride_14 = 0;
    for (int k = 0; k < 3; k++) {
        stride_14 = (stride_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_14) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_68 = local_arr[aux % 3];
    acc = (acc + quotient_68 * 2) & 127;
    int accumulator_29 = (aux + st.buffer[1]) & 3;
    switch (accumulator_29) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_7(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_68 = 0;
    for (int k = 0; k < 3; k++) {
        damping_68 = (damping_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_68) & 127;
    }
    int window_18 = (st.buffer[0] * 3 + aux) & 63;
    if (window_18 > 40) {
        acc = (acc + window_18 * 2 + 5) & 127;
        aux ^= (window_18 & 15);
    } else {
        acc = (acc - window_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_8(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_64 = (aux + st.buffer[1]) & 3;
    switch (quantum_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_17 = local_arr[aux % 3];
    acc = (acc + index_reg_17 * 2) & 127;
    int residue_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001045_4513_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001045_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int anchor_56 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_56 = (anchor_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_56) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_40 = local_arr[aux % 3];
    acc = (acc + coefficient_40 * 2) & 127;
    int pivot_25 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_25 > 45) {
        acc = (acc + pivot_25 * 2 + 5) & 127;
        aux ^= (pivot_25 & 15);
    } else {
        acc = (acc - pivot_25 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001045_4513_10(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001045_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int weight_51 = local_arr[aux % 3];
    acc = (acc + weight_51 * 2) & 127;
    int coefficient_97 = (aux + st.buffer[1]) & 3;
    switch (coefficient_97) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_11(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001045_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int delta_50 = local_arr[aux % 3];
    acc = (acc + delta_50 * 2) & 127;
    int stride_19 = (aux + st.buffer[1]) & 3;
    switch (stride_19) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_12(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001045_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int window_43 = (st.buffer[0] * 3 + aux) & 63;
    if (window_43 > 45) {
        acc = (acc + window_43 * 2 + 5) & 127;
        aux ^= (window_43 & 15);
    } else {
        acc = (acc - window_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_95 = local_arr[aux % 3];
    acc = (acc + offset_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001045_4513_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001045_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int parity_28 = local_arr[aux % 3];
    acc = (acc + parity_28 * 2) & 127;
    int window_81 = (aux + st.buffer[1]) & 3;
    switch (window_81) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_14(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001045_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int stride_54 = 0;
    for (int k = 0; k < 3; k++) {
        stride_54 = (stride_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_54) & 127;
    }
    int pivot_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001045_4513_15(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001045_4513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_74 = (aux + st.buffer[1]) & 3;
    switch (delta_74) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_65) & 63;
    acc ^= aux;
    int margin_14 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_14 > 24) {
        acc = (acc + margin_14 * 2 + 5) & 127;
        aux ^= (margin_14 & 15);
    } else {
        acc = (acc - margin_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_74 = local_arr[aux % 3];
    acc = (acc + accumulator_74 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001045_4513_16(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int cursor_54 = local_arr[aux % 3];
    acc = (acc + cursor_54 * 2) & 127;
    int accumulator_90 = (aux + st.buffer[1]) & 3;
    switch (accumulator_90) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_62 = (st.buffer[0] * 3 + aux) & 63;
    if (window_62 > 49) {
        acc = (acc + window_62 * 2 + 5) & 127;
        aux ^= (window_62 & 15);
    } else {
        acc = (acc - window_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001045_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_32 = (aux + st.buffer[1]) & 3;
    switch (margin_32) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001045_4513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int scale_10 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_10 > 38) {
        acc = (acc + scale_10 * 2 + 5) & 127;
        aux ^= (scale_10 & 15);
    } else {
        acc = (acc - scale_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_97 = local_arr[aux % 3];
    acc = (acc + tracker_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001045_4513_19(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int parity_29 = (aux + st.buffer[1]) & 3;
    switch (parity_29) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_54 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_54 > 14) {
        acc = (acc + mask_54 * 2 + 5) & 127;
        aux ^= (mask_54 & 15);
    } else {
        acc = (acc - mask_54 + 11) & 127;
        aux += 3;
    }
    int pivot_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001045_4513_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_62) & 63;
    acc ^= aux;
    int stride_86 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_86 > 19) {
        acc = (acc + stride_86 * 2 + 5) & 127;
        aux ^= (stride_86 & 15);
    } else {
        acc = (acc - stride_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001045_4513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int delta_71 = local_arr[aux % 3];
    acc = (acc + delta_71 * 2) & 127;
    int sample_86 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_86 > 30) {
        acc = (acc + sample_86 * 2 + 5) & 127;
        aux ^= (sample_86 & 15);
    } else {
        acc = (acc - sample_86 + 11) & 127;
        aux += 3;
    }
    int stride_39 = 0;
    for (int k = 0; k < 3; k++) {
        stride_39 = (stride_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001045_4513_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001045_4513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int index_reg_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_90) & 63;
    acc ^= aux;
    int damping_40 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_40 > 42) {
        acc = (acc + damping_40 * 2 + 5) & 127;
        aux ^= (damping_40 & 15);
    } else {
        acc = (acc - damping_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001045_0;
    int sec_r001045_1;
    int sec_r001045_2;
    int sec_r001045_3;
    int sec_r001045_4;
    int sec_r001045_5;
    int sec_r001045_6;
    int sec_r001045_7;
    int sec_r001045_8;
    int sec_r001045_9;
    int sec_r001045_10;
    int sec_r001045_11;
    int sec_r001045_12;
    int sec_r001045_13;
    int sec_r001045_14;
    int sec_r001045_15;
    int sec_r001045_16;
    int sec_r001045_17;
    int sec_r001045_18;
    int sec_r001045_19;
    int sec_r001045_20;
    int sec_r001045_21;
    int sec_r001045_22;
    int sec_r001045_23;
    int pub_r001045_0;
    int pub_r001045_1;
    int pub_r001045_2;
    int pub_r001045_3;
    int pub_r001045_4;
    int pub_r001045_5;
    int pub_r001045_6;
    int pub_r001045_7;
    int pub_r001045_8;
    int pub_r001045_9;
    int pub_r001045_10;
    int pub_r001045_11;
    int pub_r001045_12;
    int pub_r001045_13;
    int pub_r001045_14;
    int pub_r001045_15;
    int pub_r001045_16;
    int pub_r001045_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001045_0 >= -100 && pub_r001045_0 <= 100);
    __CPROVER_assume(pub_r001045_1 >= -100 && pub_r001045_1 <= 100);
    __CPROVER_assume(pub_r001045_2 >= -100 && pub_r001045_2 <= 100);
    __CPROVER_assume(pub_r001045_3 >= -100 && pub_r001045_3 <= 100);
    __CPROVER_assume(pub_r001045_4 >= -100 && pub_r001045_4 <= 100);
    __CPROVER_assume(pub_r001045_5 >= -100 && pub_r001045_5 <= 100);
    __CPROVER_assume(pub_r001045_6 >= -100 && pub_r001045_6 <= 100);
    __CPROVER_assume(pub_r001045_7 >= -100 && pub_r001045_7 <= 100);
    __CPROVER_assume(pub_r001045_8 >= -100 && pub_r001045_8 <= 100);
    __CPROVER_assume(pub_r001045_9 >= -100 && pub_r001045_9 <= 100);
    __CPROVER_assume(pub_r001045_10 >= -100 && pub_r001045_10 <= 100);
    __CPROVER_assume(pub_r001045_11 >= -100 && pub_r001045_11 <= 100);
    __CPROVER_assume(pub_r001045_12 >= -100 && pub_r001045_12 <= 100);
    __CPROVER_assume(pub_r001045_13 >= -100 && pub_r001045_13 <= 100);
    __CPROVER_assume(pub_r001045_14 >= -100 && pub_r001045_14 <= 100);
    __CPROVER_assume(pub_r001045_15 >= -100 && pub_r001045_15 <= 100);
    __CPROVER_assume(pub_r001045_16 >= -100 && pub_r001045_16 <= 100);
    __CPROVER_assume(pub_r001045_17 >= -100 && pub_r001045_17 <= 100);
    __CPROVER_assume(sec_r001045_0 >= 0 && sec_r001045_0 <= 255);
    __CPROVER_assume(sec_r001045_1 >= 0 && sec_r001045_1 <= 255);
    __CPROVER_assume(sec_r001045_2 >= 0 && sec_r001045_2 <= 255);
    __CPROVER_assume(sec_r001045_3 >= 0 && sec_r001045_3 <= 255);
    __CPROVER_assume(sec_r001045_4 >= 0 && sec_r001045_4 <= 255);
    __CPROVER_assume(sec_r001045_5 >= 0 && sec_r001045_5 <= 255);
    __CPROVER_assume(sec_r001045_6 >= 0 && sec_r001045_6 <= 255);
    __CPROVER_assume(sec_r001045_7 >= 0 && sec_r001045_7 <= 255);
    __CPROVER_assume(sec_r001045_8 >= 0 && sec_r001045_8 <= 255);
    __CPROVER_assume(sec_r001045_9 >= 0 && sec_r001045_9 <= 255);
    __CPROVER_assume(sec_r001045_10 >= 0 && sec_r001045_10 <= 255);
    __CPROVER_assume(sec_r001045_11 >= 0 && sec_r001045_11 <= 255);
    __CPROVER_assume(sec_r001045_12 >= 0 && sec_r001045_12 <= 255);
    __CPROVER_assume(sec_r001045_13 >= 0 && sec_r001045_13 <= 255);
    __CPROVER_assume(sec_r001045_14 >= 0 && sec_r001045_14 <= 255);
    __CPROVER_assume(sec_r001045_15 >= 0 && sec_r001045_15 <= 255);
    __CPROVER_assume(sec_r001045_16 >= 0 && sec_r001045_16 <= 255);
    __CPROVER_assume(sec_r001045_17 >= 0 && sec_r001045_17 <= 255);
    __CPROVER_assume(sec_r001045_18 >= 0 && sec_r001045_18 <= 255);
    __CPROVER_assume(sec_r001045_19 >= 0 && sec_r001045_19 <= 255);
    __CPROVER_assume(sec_r001045_20 >= 0 && sec_r001045_20 <= 255);
    __CPROVER_assume(sec_r001045_21 >= 0 && sec_r001045_21 <= 255);
    __CPROVER_assume(sec_r001045_22 >= 0 && sec_r001045_22 <= 255);
    __CPROVER_assume(sec_r001045_23 >= 0 && sec_r001045_23 <= 255);

    struct EventLog_R001045_4513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001045_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001045_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001045_0 + 7) & 15;
    struct AudioFrame_R001045_4513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001045_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001045_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001045_0 + 9) & 15;
    struct SensorNode_R001045_4513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001045_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001045_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001045_0 + 11) & 15;
    struct CipherContext_R001045_4513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001045_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001045_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001045_0 + 13) & 15;

    union PacketPayload_R001045_4513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001045_4513_0(sec_r001045_0, sec_r001045_1, pub_r001045_2);
    int helper_flow_1 = fn_R001045_4513_1(sec_r001045_1, pub_r001045_2, pub_r001045_3, pub_r001045_4);
    int helper_flow_2 = fn_R001045_4513_2(sec_r001045_2, sec_r001045_3, pub_r001045_4, pub_r001045_5, pub_r001045_6);
    int helper_flow_3 = fn_R001045_4513_3(sec_r001045_3, pub_r001045_4, pub_r001045_5, pub_r001045_6);
    int helper_flow_4 = fn_R001045_4513_4(sec_r001045_4, pub_r001045_5, pub_r001045_6, pub_r001045_7, pub_r001045_8);
    int helper_flow_5 = fn_R001045_4513_5(sec_r001045_5, sec_r001045_6, pub_r001045_7, pub_r001045_8);
    int helper_flow_6 = fn_R001045_4513_6(sec_r001045_6, sec_r001045_7);
    int helper_flow_7 = fn_R001045_4513_7(sec_r001045_7, sec_r001045_8, pub_r001045_9);
    int helper_flow_8 = fn_R001045_4513_8(sec_r001045_8, sec_r001045_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001045_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001045_0 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_1 + 1) & 15;
    out_sink ^= (stage_v_1 & 63);

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001045_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001045_22 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001045_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_2 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_5 + 1) & 15;
    out_sink ^= (stage_v_5 & 63);

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((helper_flow_8 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001045_0 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001045_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001045_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001045_3 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001045_7 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r001045_14 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_12 + 1) & 15;
    out_sink ^= (stage_v_12 & 63);

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_1 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_13 + 1) & 15;
    out_sink ^= (stage_v_13 & 63);

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001045_3 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_14 + 1) & 15;
    out_sink ^= (stage_v_14 & 63);

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((helper_flow_2 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_15 + 1) & 15;
    out_sink ^= (stage_v_15 & 63);

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001045_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001045_11 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001045_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001045_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_7 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001045_14 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_11 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_2 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r001045_7 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001045_21 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_24 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_26 + 1) & 15;
    out_sink ^= (stage_v_26 & 63);

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001045_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001045_8 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001045_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001045_19 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_11 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((helper_flow_3 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_32 + 1) & 15;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_7 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001045_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001045_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_15 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_36 + 1) & 15;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001045_14 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_37 + 1) & 15;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001045_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_25 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_39 + 1) & 15;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_6 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_40 + 1) & 15;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001045_7 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001045_12 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r001045_18 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_11 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001045_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_21 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001045_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001045_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r001045_6 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_31 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_14 << 1) ^ (pub_r001045_8 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001045_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((sec_r001045_13 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_14 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_54 + 1) & 15;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001045_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001045_6 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_51 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_32 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001045_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001045_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_22 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001045_4 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r001045_6 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001045_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001045_7 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((helper_flow_8 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001045_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001045_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_31 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_30 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_70 + 1) & 15;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001045_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_12 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001045_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001045_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001045_2 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_75 + 1) & 15;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r001045_16 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r001045_6 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_77 + 1) & 15;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_26 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001045_9 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001045_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001045_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_22 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001045_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_1 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_84 + 1) & 15;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001045_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001045_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001045_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001045_16 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001045_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001045_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001045_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_22 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_1 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001045_10 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001045_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001045_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001045_8 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((helper_flow_0 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_98 + 1) & 15;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001045_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_46 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_100 + 1) & 15;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_93 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r001045_13 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_76 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_103 + 1) & 15;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_72 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001045_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001045_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001045_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001045_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r001045_19 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_15 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001045_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001045_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001045_6 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001045_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_13 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_40 << 1) ^ (pub_r001045_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r001045_2 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001045_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_72 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001045_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_78 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001045_22 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_102 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_6 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_124 + 1) & 15;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_103 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001045_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_75 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_53 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001045_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_63 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_78 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001045_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001045_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_69 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001045_20 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_13 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_136 + 1) & 15;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001045_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001045_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_125 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_70 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_33 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_141 + 1) & 15;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((sec_r001045_1 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_28 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_11 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_144 + 1) & 15;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001045_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001045_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_63 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_147 + 1) & 15;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001045_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_5 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_51 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_24 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_151 + 1) & 15;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((helper_flow_2 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001045_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001045_7 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_28 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001045_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_92 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_121 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001045_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_158 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001045_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001045_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001045_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_41 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_164 + 1) & 15;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001045_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001045_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001045_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001045_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_22 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001045_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_31 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001045_22 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_172 + 1) & 15;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001045_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_102 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_13 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_175 + 1) & 15;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001045_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001045_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_164 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001045_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((helper_flow_2 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001045_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001045_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_94 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_183 + 1) & 15;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001045_5 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r001045_22 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001045_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001045_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001045_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_20 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001045_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_92 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001045_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_66 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001045_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001045_21 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001045_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_98 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_197 + 1) & 15;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001045_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001045_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_109 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_200 + 1) & 15;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_1 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_37 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001045_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001045_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_171 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_205 + 1) & 15;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_100 << 1) ^ (pub_r001045_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001045_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_88 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_202 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_209 + 1) & 15;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001045_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001045_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_185 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r001045_21 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_136 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001045_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001045_11 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001045_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_57 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_174 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001045_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_175 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_94 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001045_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_25 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_93 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_116 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_143 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_84 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_157 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_121 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001045_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001045_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001045_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_98 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_158 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_235 + 1) & 15;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_128 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001045_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001045_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((helper_flow_1 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_131 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001045_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001045_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001045_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_92 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001045_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001045_17 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001045_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001045_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001045_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001045_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_76 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_251 + 1) & 15;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001045_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((sec_r001045_16 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001045_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001045_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_20 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_164 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_257 + 1) & 15;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_189 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001045_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_20 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_150 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_201 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_262 + 1) & 15;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_13 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001045_7 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_134 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_265 + 1) & 15;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_144 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001045_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001045_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001045_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_84 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (pub_r001045_8 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_271) & 127;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_75 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_235 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001045_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001045_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_265 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_141 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001045_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_178 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_158 << 1) ^ (pub_r001045_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (pub_r001045_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_281) & 127;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_261 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r001045_19 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_76 << 1) ^ (pub_r001045_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (pub_r001045_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_285) & 127;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_100 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_286 + 1) & 15;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_41 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001045_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_134 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_229 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_150 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_291 + 1) & 15;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_3 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001045_13 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001045_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_258 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r001045_3 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (pub_r001045_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_297) & 127;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_272 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_93 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (pub_r001045_6 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_300) & 127;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001045_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (pub_r001045_16 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_302) & 127;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_280 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_66 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001045_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_175 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_306 + 1) & 15;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001045_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001045_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_13 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_282 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_240 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_103 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_312 + 1) & 15;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (pub_r001045_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_313) & 127;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001045_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_7 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001045_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_21 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_239 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_104 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (pub_r001045_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_320) & 127;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_26 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001045_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001045_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_225 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (pub_r001045_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_325) & 127;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_6 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((helper_flow_2 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_327 + 1) & 15;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (pub_r001045_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_328) & 127;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_265 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_324 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_32 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r001045_17 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_287 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_287 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (pub_r001045_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_335) & 127;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_115 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_336 + 1) & 15;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (pub_r001045_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_337) & 127;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_236 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((sec_r001045_14 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (pub_r001045_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_340) & 127;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001045_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_332 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_44 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (pub_r001045_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_344) & 127;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_283 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((helper_flow_8 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_346 + 1) & 15;
    out_sink ^= (stage_v_346 & 63);

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001045_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((sec_r001045_12 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001045_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_311 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001045_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001045_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (pub_r001045_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_353) & 127;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001045_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001045_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((sec_r001045_12 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_144 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_127 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_345 << 1) ^ (pub_r001045_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_263 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (pub_r001045_6 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_361) & 127;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_49 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((sec_r001045_4 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001045_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001045_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_20 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((sec_r001045_0 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((sec_r001045_8 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001045_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_142 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001045_11 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((sec_r001045_22 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_103 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_122 << 1) ^ (pub_r001045_5 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001045_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001045_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001045_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_214 << 1) ^ (pub_r001045_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = ((stage_v_78 << 1) ^ (pub_r001045_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_379 + 1) & 15;
    out_sink ^= (stage_v_379 & 63);

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((helper_flow_4 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = (pub_r001045_9 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_381) & 127;

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_92 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_36 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = (pub_r001045_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_384) & 127;

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_280 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001045_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_94 << 1) ^ (pub_r001045_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001045_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((stage_v_202 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001045_5 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_70 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_298 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_228 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_357 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001045_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001045_0 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001045_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001045_17 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001045_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = (pub_r001045_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_400) & 127;

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_379 << 1) ^ (pub_r001045_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_205 << 1) ^ (pub_r001045_17 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001045_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001045_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001045_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = (pub_r001045_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_406) & 127;

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = ((stage_v_143 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_407 + 1) & 15;
    out_sink ^= (stage_v_407 & 63);

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((stage_v_125 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_57 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_282 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = ((stage_v_78 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_411 + 1) & 15;
    out_sink ^= (stage_v_411 & 63);

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = (pub_r001045_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_412) & 127;

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = ((stage_v_39 << 1) ^ (pub_r001045_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_413 + 1) & 15;
    out_sink ^= (stage_v_413 & 63);

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = ((sec_r001045_9 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_414 + 1) & 15;
    out_sink ^= (stage_v_414 & 63);

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001045_15 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001045_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((sec_r001045_15 << 1) ^ (pub_r001045_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_101 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_15 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_41 << 1) ^ (pub_r001045_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_374 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001045_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_127 << 1) ^ (pub_r001045_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = ((stage_v_379 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_424 + 1) & 15;
    out_sink ^= (stage_v_424 & 63);

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = (pub_r001045_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_425) & 127;

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = ((stage_v_104 << 1) ^ (pub_r001045_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_426 + 1) & 15;
    out_sink ^= (stage_v_426 & 63);

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = ((stage_v_82 << 1) ^ (pub_r001045_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_427 + 1) & 15;
    out_sink ^= (stage_v_427 & 63);

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001045_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001045_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = ((helper_flow_3 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_430 + 1) & 15;
    out_sink ^= (stage_v_430 & 63);

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_144 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = (pub_r001045_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_432) & 127;

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = ((stage_v_359 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_433 + 1) & 15;
    out_sink ^= (stage_v_433 & 63);

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = (pub_r001045_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_434) & 127;

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = (pub_r001045_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_435) & 127;

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_282 << 1) ^ (pub_r001045_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_291 << 1) ^ (pub_r001045_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = ((stage_v_401 << 1) ^ (pub_r001045_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_438 + 1) & 15;
    out_sink ^= (stage_v_438 & 63);

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = ((stage_v_178 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_439 + 1) & 15;
    out_sink ^= (stage_v_439 & 63);

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001045_17 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_292 << 1) ^ (pub_r001045_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = (pub_r001045_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_442) & 127;

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((sec_r001045_18 << 1) ^ (pub_r001045_12 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001045_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
