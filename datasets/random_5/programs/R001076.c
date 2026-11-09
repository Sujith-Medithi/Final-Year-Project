/*
 * Benchmark Program: R001076
 * Security Family: implicit_flow
 * Generator Seed: 607613
 * High Inputs: 17 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001076_7613_0 {
    short code;
    int severity;
    int timestamp;
    int facility;
    unsigned char signature;
    unsigned char seq;
    int buffer[3];
};

struct CipherContext_R001076_7613_1 {
    unsigned char flags;
    short round_key;
    unsigned char nonce;
    unsigned char tag;
    unsigned char iv;
    int buffer[3];
};

struct SensorNode_R001076_7613_2 {
    short gain;
    int threshold;
    short calib;
    short offset;
    unsigned char reading;
    int buffer[3];
};

union PacketPayload_R001076_7613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001076_7613_0(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_48 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_48) & 63;
    acc ^= aux;
    int bound_28 = (aux + st.buffer[1]) & 3;
    switch (bound_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_1(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int coefficient_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_64) & 63;
    acc ^= aux;
    int factor_87 = 0;
    for (int k = 0; k < 3; k++) {
        factor_87 = (factor_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_87) & 127;
    }
    int scale_79 = (aux + st.buffer[1]) & 3;
    switch (scale_79) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_2(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_33 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_33 > 33) {
        acc = (acc + parity_33 * 2 + 5) & 127;
        aux ^= (parity_33 & 15);
    } else {
        acc = (acc - parity_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_98 = local_arr[aux % 3];
    acc = (acc + sample_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001076_7613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_75 = local_arr[aux % 3];
    acc = (acc + quotient_75 * 2) & 127;
    int bound_32 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_32 > 24) {
        acc = (acc + bound_32 * 2 + 5) & 127;
        aux ^= (bound_32 & 15);
    } else {
        acc = (acc - bound_32 + 11) & 127;
        aux += 3;
    }
    int damping_32 = (aux + st.buffer[1]) & 3;
    switch (damping_32) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_4(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int offset_63 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_63 > 14) {
        acc = (acc + offset_63 * 2 + 5) & 127;
        aux ^= (offset_63 & 15);
    } else {
        acc = (acc - offset_63 + 11) & 127;
        aux += 3;
    }
    int metric_55 = 0;
    for (int k = 0; k < 3; k++) {
        metric_55 = (metric_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_5(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int quotient_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_30) & 63;
    acc ^= aux;
    int factor_38 = (aux + st.buffer[1]) & 3;
    switch (factor_38) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_6(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_33 = local_arr[aux % 3];
    acc = (acc + index_reg_33 * 2) & 127;
    int stride_29 = (aux + st.buffer[1]) & 3;
    switch (stride_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001076_7613_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int delta_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_95) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int accumulator_36 = local_arr[aux % 3];
    acc = (acc + accumulator_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001076_7613_8(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_21 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_21 = (checksum_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_21) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int vector_55 = 0;
    for (int k = 0; k < 2; k++) {
        vector_55 = (vector_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_55) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_80 = local_arr[aux % 3];
    acc = (acc + scale_80 * 2) & 127;
    int threshold_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001076_7613_10(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_98 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_98 = (cursor_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_98) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_63 = (aux + st.buffer[1]) & 3;
    switch (quantum_63) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_63 = (aux + st.buffer[1]) & 3;
    switch (accumulator_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_76 = 0;
    for (int k = 0; k < 3; k++) {
        margin_76 = (margin_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_76) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_62 = local_arr[aux % 3];
    acc = (acc + checksum_62 * 2) & 127;
    int stride_67 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_67 > 47) {
        acc = (acc + stride_67 * 2 + 5) & 127;
        aux ^= (stride_67 & 15);
    } else {
        acc = (acc - stride_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_12(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int vector_37 = local_arr[aux % 3];
    acc = (acc + vector_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_58) & 63;
    acc ^= aux;
    int tally_72 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_72 > 21) {
        acc = (acc + tally_72 * 2 + 5) & 127;
        aux ^= (tally_72 & 15);
    } else {
        acc = (acc - tally_72 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_30 = (aux + st.buffer[1]) & 3;
    switch (metric_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_91 = local_arr[aux % 3];
    acc = (acc + window_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001076_7613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_36 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_36 > 41) {
        acc = (acc + sample_36 * 2 + 5) & 127;
        aux ^= (sample_36 & 15);
    } else {
        acc = (acc - sample_36 + 11) & 127;
        aux += 3;
    }
    int scale_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_29) & 63;
    acc ^= aux;
    int quotient_25 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_25 = (quotient_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_25) & 127;
    }
    int phase_33 = (aux + st.buffer[1]) & 3;
    switch (phase_33) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_15(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tally_76 = (aux + st.buffer[1]) & 3;
    switch (tally_76) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_75 = 0;
    for (int k = 0; k < 3; k++) {
        margin_75 = (margin_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_75) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_22 = local_arr[aux % 3];
    acc = (acc + bound_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001076_7613_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int index_reg_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_16) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_42 = local_arr[aux % 3];
    acc = (acc + checksum_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001076_7613_17(int p0, int p1) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int index_reg_73 = (aux + st.buffer[1]) & 3;
    switch (index_reg_73) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_97) & 63;
    acc ^= aux;
    int mask_63 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_63 > 11) {
        acc = (acc + mask_63 * 2 + 5) & 127;
        aux ^= (mask_63 & 15);
    } else {
        acc = (acc - mask_63 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001076_7613_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int metric_69 = (aux + st.buffer[1]) & 3;
    switch (metric_69) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_16 = local_arr[aux % 3];
    acc = (acc + tracker_16 * 2) & 127;
    int metric_61 = 0;
    for (int k = 0; k < 2; k++) {
        metric_61 = (metric_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_19(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001076_7613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_77 = local_arr[aux % 3];
    acc = (acc + stride_77 * 2) & 127;
    int sample_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001076_7613_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int threshold_53 = (aux + st.buffer[1]) & 3;
    switch (threshold_53) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_85 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_85 > 33) {
        acc = (acc + factor_85 * 2 + 5) & 127;
        aux ^= (factor_85 & 15);
    } else {
        acc = (acc - factor_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001076_7613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_26 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_26 > 14) {
        acc = (acc + mask_26 * 2 + 5) & 127;
        aux ^= (mask_26 & 15);
    } else {
        acc = (acc - mask_26 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_91 = local_arr[aux % 3];
    acc = (acc + offset_91 * 2) & 127;
    int segment_21 = (aux + st.buffer[1]) & 3;
    switch (segment_21) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_60 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_60 = (cursor_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_60) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001076_7613_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001076_7613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_22 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_22 > 10) {
        acc = (acc + residue_22 * 2 + 5) & 127;
        aux ^= (residue_22 & 15);
    } else {
        acc = (acc - residue_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001076_0;
    int sec_r001076_1;
    int sec_r001076_2;
    int sec_r001076_3;
    int sec_r001076_4;
    int sec_r001076_5;
    int sec_r001076_6;
    int sec_r001076_7;
    int sec_r001076_8;
    int sec_r001076_9;
    int sec_r001076_10;
    int sec_r001076_11;
    int sec_r001076_12;
    int sec_r001076_13;
    int sec_r001076_14;
    int sec_r001076_15;
    int sec_r001076_16;
    int pub_r001076_0;
    int pub_r001076_1;
    int pub_r001076_2;
    int pub_r001076_3;
    int pub_r001076_4;
    int pub_r001076_5;
    int pub_r001076_6;
    int pub_r001076_7;
    int pub_r001076_8;
    int pub_r001076_9;
    int pub_r001076_10;
    int pub_r001076_11;
    int pub_r001076_12;
    int pub_r001076_13;
    int pub_r001076_14;
    int pub_r001076_15;
    int pub_r001076_16;
    int pub_r001076_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001076_0 >= -100 && pub_r001076_0 <= 100);
    __CPROVER_assume(pub_r001076_1 >= -100 && pub_r001076_1 <= 100);
    __CPROVER_assume(pub_r001076_2 >= -100 && pub_r001076_2 <= 100);
    __CPROVER_assume(pub_r001076_3 >= -100 && pub_r001076_3 <= 100);
    __CPROVER_assume(pub_r001076_4 >= -100 && pub_r001076_4 <= 100);
    __CPROVER_assume(pub_r001076_5 >= -100 && pub_r001076_5 <= 100);
    __CPROVER_assume(pub_r001076_6 >= -100 && pub_r001076_6 <= 100);
    __CPROVER_assume(pub_r001076_7 >= -100 && pub_r001076_7 <= 100);
    __CPROVER_assume(pub_r001076_8 >= -100 && pub_r001076_8 <= 100);
    __CPROVER_assume(pub_r001076_9 >= -100 && pub_r001076_9 <= 100);
    __CPROVER_assume(pub_r001076_10 >= -100 && pub_r001076_10 <= 100);
    __CPROVER_assume(pub_r001076_11 >= -100 && pub_r001076_11 <= 100);
    __CPROVER_assume(pub_r001076_12 >= -100 && pub_r001076_12 <= 100);
    __CPROVER_assume(pub_r001076_13 >= -100 && pub_r001076_13 <= 100);
    __CPROVER_assume(pub_r001076_14 >= -100 && pub_r001076_14 <= 100);
    __CPROVER_assume(pub_r001076_15 >= -100 && pub_r001076_15 <= 100);
    __CPROVER_assume(pub_r001076_16 >= -100 && pub_r001076_16 <= 100);
    __CPROVER_assume(pub_r001076_17 >= -100 && pub_r001076_17 <= 100);
    __CPROVER_assume(sec_r001076_0 >= 0 && sec_r001076_0 <= 255);
    __CPROVER_assume(sec_r001076_1 >= 0 && sec_r001076_1 <= 255);
    __CPROVER_assume(sec_r001076_2 >= 0 && sec_r001076_2 <= 255);
    __CPROVER_assume(sec_r001076_3 >= 0 && sec_r001076_3 <= 255);
    __CPROVER_assume(sec_r001076_4 >= 0 && sec_r001076_4 <= 255);
    __CPROVER_assume(sec_r001076_5 >= 0 && sec_r001076_5 <= 255);
    __CPROVER_assume(sec_r001076_6 >= 0 && sec_r001076_6 <= 255);
    __CPROVER_assume(sec_r001076_7 >= 0 && sec_r001076_7 <= 255);
    __CPROVER_assume(sec_r001076_8 >= 0 && sec_r001076_8 <= 255);
    __CPROVER_assume(sec_r001076_9 >= 0 && sec_r001076_9 <= 255);
    __CPROVER_assume(sec_r001076_10 >= 0 && sec_r001076_10 <= 255);
    __CPROVER_assume(sec_r001076_11 >= 0 && sec_r001076_11 <= 255);
    __CPROVER_assume(sec_r001076_12 >= 0 && sec_r001076_12 <= 255);
    __CPROVER_assume(sec_r001076_13 >= 0 && sec_r001076_13 <= 255);
    __CPROVER_assume(sec_r001076_14 >= 0 && sec_r001076_14 <= 255);
    __CPROVER_assume(sec_r001076_15 >= 0 && sec_r001076_15 <= 255);
    __CPROVER_assume(sec_r001076_16 >= 0 && sec_r001076_16 <= 255);

    struct EventLog_R001076_7613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001076_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001076_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001076_0 + 7) & 15;
    struct CipherContext_R001076_7613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001076_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001076_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001076_0 + 9) & 15;
    struct SensorNode_R001076_7613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001076_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001076_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001076_0 + 11) & 15;

    union PacketPayload_R001076_7613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001076_7613_0(sec_r001076_0, pub_r001076_1, pub_r001076_2);
    int helper_flow_1 = fn_R001076_7613_1(sec_r001076_1, pub_r001076_2, pub_r001076_3);
    int helper_flow_2 = fn_R001076_7613_2(sec_r001076_2, pub_r001076_3, pub_r001076_4);
    int helper_flow_3 = fn_R001076_7613_3(sec_r001076_3, pub_r001076_4, pub_r001076_5, pub_r001076_6);
    int helper_flow_4 = fn_R001076_7613_4(sec_r001076_4, pub_r001076_5, pub_r001076_6);
    int helper_flow_5 = fn_R001076_7613_5(sec_r001076_5, pub_r001076_6, pub_r001076_7);
    int helper_flow_6 = fn_R001076_7613_6(sec_r001076_6, pub_r001076_7, pub_r001076_8);
    int helper_flow_7 = fn_R001076_7613_7(sec_r001076_7, sec_r001076_8, pub_r001076_9, pub_r001076_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001076_1 + pub_r001076_14 * 2 + 5) & 127;
    if (stage_v_0 > 44) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001076_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001076_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001076_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001076_4 + pub_r001076_14 * 2 + 17) & 127;
    if (stage_v_4 > 60) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001076_11 + pub_r001076_4 * 2 + 20) & 127;
    if (stage_v_5 > 18) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001076_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001076_11 + pub_r001076_10 * 2 + 26) & 127;
    if (stage_v_7 > 60) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_0 + pub_r001076_7 * 2 + 29) & 127;
    if (stage_v_8 > 29) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_7 + pub_r001076_3 * 2 + 32) & 127;
    if (stage_v_9 > 16) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (helper_flow_1 + pub_r001076_14 * 2 + 35) & 127;
    if (stage_v_10 > 23) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_7 + pub_r001076_16 * 2 + 38) & 127;
    if (stage_v_11 > 23) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001076_13 + pub_r001076_10 * 2 + 41) & 127;
    if (stage_v_12 > 50) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001076_11 + pub_r001076_9 * 2 + 44) & 127;
    if (stage_v_13 > 45) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (sec_r001076_12 + pub_r001076_8 * 2 + 47) & 127;
    if (stage_v_14 > 34) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (helper_flow_5 + pub_r001076_2 * 2 + 50) & 127;
    if (stage_v_15 > 40) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001076_10 + pub_r001076_14 * 2 + 53) & 127;
    if (stage_v_16 > 21) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001076_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (sec_r001076_11 + pub_r001076_3 * 2 + 59) & 127;
    if (stage_v_18 > 49) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001076_12 + pub_r001076_8 * 2 + 62) & 127;
    if (stage_v_19 > 28) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
        sec_accum ^= (stage_v_19 & 31);
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_10 + pub_r001076_4 * 2 + 65) & 127;
    if (stage_v_20 > 26) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
        sec_accum ^= (stage_v_20 & 31);
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_10 + pub_r001076_0 * 2 + 68) & 127;
    if (stage_v_21 > 28) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001076_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_20 + pub_r001076_3 * 2 + 74) & 127;
    if (stage_v_23 > 50) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001076_1 + pub_r001076_15 * 2 + 77) & 127;
    if (stage_v_24 > 27) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (stage_v_23 + pub_r001076_5 * 2 + 80) & 127;
    if (stage_v_25 > 51) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001076_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001076_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001076_14 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_18 + pub_r001076_16 * 2 + 92) & 127;
    if (stage_v_29 > 36) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001076_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001076_7 + pub_r001076_7 * 2 + 98) & 127;
    if (stage_v_31 > 45) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_10 + pub_r001076_6 * 2 + 101) & 127;
    if (stage_v_32 > 28) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
        sec_accum ^= (stage_v_32 & 31);
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001076_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_7 + pub_r001076_10 * 2 + 107) & 127;
    if (stage_v_34 > 58) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001076_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_29 + pub_r001076_2 * 2 + 113) & 127;
    if (stage_v_36 > 21) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
        sec_accum ^= (stage_v_36 & 31);
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_36 + pub_r001076_7 * 2 + 116) & 127;
    if (stage_v_37 > 17) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001076_2 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_23 + pub_r001076_8 * 2 + 122) & 127;
    if (stage_v_39 > 21) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_5 + pub_r001076_0 * 2 + 125) & 127;
    if (stage_v_40 > 34) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001076_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001076_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001076_9 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001076_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_5 + pub_r001076_14 * 2 + 140) & 127;
    if (stage_v_45 > 34) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_29 + pub_r001076_8 * 2 + 143) & 127;
    if (stage_v_46 > 25) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001076_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001076_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001076_14 + pub_r001076_5 * 2 + 152) & 127;
    if (stage_v_49 > 19) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_18 + pub_r001076_4 * 2 + 155) & 127;
    if (stage_v_50 > 46) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001076_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_12 + pub_r001076_6 * 2 + 161) & 127;
    if (stage_v_52 > 56) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (helper_flow_3 + pub_r001076_6 * 2 + 164) & 127;
    if (stage_v_53 > 21) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_39 + pub_r001076_2 * 2 + 167) & 127;
    if (stage_v_54 > 16) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001076_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001076_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001076_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001076_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001076_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_49 + pub_r001076_8 * 2 + 185) & 127;
    if (stage_v_60 > 34) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001076_3 + pub_r001076_5 * 2 + 188) & 127;
    if (stage_v_61 > 16) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_20 + pub_r001076_6 * 2 + 191) & 127;
    if (stage_v_62 > 22) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
        sec_accum ^= (stage_v_62 & 31);
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (helper_flow_7 + pub_r001076_10 * 2 + 194) & 127;
    if (stage_v_63 > 47) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001076_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_61 + pub_r001076_0 * 2 + 200) & 127;
    if (stage_v_65 > 22) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_3 + pub_r001076_10 * 2 + 203) & 127;
    if (stage_v_66 > 15) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001076_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001076_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001076_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001076_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_7 + pub_r001076_16 * 2 + 218) & 127;
    if (stage_v_71 > 36) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_52 + pub_r001076_17 * 2 + 221) & 127;
    if (stage_v_72 > 46) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (helper_flow_7 + pub_r001076_2 * 2 + 224) & 127;
    if (stage_v_73 > 59) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
        sec_accum ^= (stage_v_73 & 31);
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_6 + pub_r001076_6 * 2 + 227) & 127;
    if (stage_v_74 > 42) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_49 + pub_r001076_0 * 2 + 230) & 127;
    if (stage_v_75 > 35) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_18 + pub_r001076_0 * 2 + 233) & 127;
    if (stage_v_76 > 21) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
        sec_accum ^= (stage_v_76 & 31);
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001076_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001076_3 + pub_r001076_3 * 2 + 239) & 127;
    if (stage_v_78 > 17) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001076_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (sec_r001076_7 + pub_r001076_4 * 2 + 245) & 127;
    if (stage_v_80 > 52) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001076_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_65 + pub_r001076_3 * 2 + 251) & 127;
    if (stage_v_82 > 26) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_50 + pub_r001076_5 * 2 + 254) & 127;
    if (stage_v_83 > 38) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001076_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001076_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_60 + pub_r001076_14 * 2 + 263) & 127;
    if (stage_v_86 > 43) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001076_15 + pub_r001076_5 * 2 + 266) & 127;
    if (stage_v_87 > 28) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (sec_r001076_4 + pub_r001076_6 * 2 + 269) & 127;
    if (stage_v_88 > 46) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001076_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001076_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_49 + pub_r001076_15 * 2 + 278) & 127;
    if (stage_v_91 > 22) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001076_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001076_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_7 + pub_r001076_0 * 2 + 287) & 127;
    if (stage_v_94 > 52) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r001076_15 + pub_r001076_4 * 2 + 290) & 127;
    if (stage_v_95 > 57) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (helper_flow_1 + pub_r001076_16 * 2 + 293) & 127;
    if (stage_v_96 > 21) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_72 + pub_r001076_2 * 2 + 296) & 127;
    if (stage_v_97 > 18) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
        sec_accum ^= (stage_v_97 & 31);
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (helper_flow_5 + pub_r001076_3 * 2 + 299) & 127;
    if (stage_v_98 > 55) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (helper_flow_2 + pub_r001076_16 * 2 + 302) & 127;
    if (stage_v_99 > 15) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001076_6 + pub_r001076_0 * 2 + 305) & 127;
    if (stage_v_100 > 55) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_78 + pub_r001076_1 * 2 + 308) & 127;
    if (stage_v_101 > 59) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
        sec_accum ^= (stage_v_101 & 31);
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001076_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_32 + pub_r001076_15 * 2 + 314) & 127;
    if (stage_v_103 > 53) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_98 + pub_r001076_6 * 2 + 317) & 127;
    if (stage_v_104 > 38) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_37 + pub_r001076_5 * 2 + 320) & 127;
    if (stage_v_105 > 52) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_104 + pub_r001076_17 * 2 + 323) & 127;
    if (stage_v_106 > 50) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001076_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001076_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_54 + pub_r001076_13 * 2 + 332) & 127;
    if (stage_v_109 > 24) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_29 + pub_r001076_8 * 2 + 335) & 127;
    if (stage_v_110 > 26) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
        sec_accum ^= (stage_v_110 & 31);
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001076_5 + pub_r001076_10 * 2 + 338) & 127;
    if (stage_v_111 > 41) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001076_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001076_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (helper_flow_1 + pub_r001076_3 * 2 + 347) & 127;
    if (stage_v_114 > 17) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_103 + pub_r001076_11 * 2 + 350) & 127;
    if (stage_v_115 > 57) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001076_5 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_34 + pub_r001076_15 * 2 + 356) & 127;
    if (stage_v_117 > 30) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
        sec_accum ^= (stage_v_117 & 31);
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_45 + pub_r001076_9 * 2 + 359) & 127;
    if (stage_v_118 > 28) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_95 + pub_r001076_16 * 2 + 362) & 127;
    if (stage_v_119 > 41) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
        sec_accum ^= (stage_v_119 & 31);
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_61 + pub_r001076_17 * 2 + 365) & 127;
    if (stage_v_120 > 37) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_21 + pub_r001076_0 * 2 + 368) & 127;
    if (stage_v_121 > 41) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
        sec_accum ^= (stage_v_121 & 31);
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_111 + pub_r001076_16 * 2 + 371) & 127;
    if (stage_v_122 > 43) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
        sec_accum ^= (stage_v_122 & 31);
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_111 + pub_r001076_7 * 2 + 374) & 127;
    if (stage_v_123 > 16) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_74 + pub_r001076_3 * 2 + 377) & 127;
    if (stage_v_124 > 60) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_109 + pub_r001076_7 * 2 + 380) & 127;
    if (stage_v_125 > 34) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001076_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_4 + pub_r001076_7 * 2 + 386) & 127;
    if (stage_v_127 > 17) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_80 + pub_r001076_12 * 2 + 389) & 127;
    if (stage_v_128 > 49) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_120 + pub_r001076_13 * 2 + 392) & 127;
    if (stage_v_129 > 39) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_9 + pub_r001076_7 * 2 + 395) & 127;
    if (stage_v_130 > 23) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_50 + pub_r001076_7 * 2 + 398) & 127;
    if (stage_v_131 > 49) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001076_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_65 + pub_r001076_3 * 2 + 404) & 127;
    if (stage_v_133 > 32) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001076_16 + pub_r001076_7 * 2 + 407) & 127;
    if (stage_v_134 > 16) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_133 + pub_r001076_1 * 2 + 410) & 127;
    if (stage_v_135 > 55) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_80 + pub_r001076_17 * 2 + 413) & 127;
    if (stage_v_136 > 16) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_115 + pub_r001076_0 * 2 + 416) & 127;
    if (stage_v_137 > 59) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
        sec_accum ^= (stage_v_137 & 31);
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001076_9 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_32 + pub_r001076_11 * 2 + 422) & 127;
    if (stage_v_139 > 22) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_52 + pub_r001076_1 * 2 + 425) & 127;
    if (stage_v_140 > 52) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_66 + pub_r001076_2 * 2 + 428) & 127;
    if (stage_v_141 > 60) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001076_6 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_37 + pub_r001076_6 * 2 + 434) & 127;
    if (stage_v_143 > 17) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001076_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001076_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001076_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_32 + pub_r001076_0 * 2 + 446) & 127;
    if (stage_v_147 > 50) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001076_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_19 + pub_r001076_0 * 2 + 452) & 127;
    if (stage_v_149 > 59) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001076_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_12 + pub_r001076_5 * 2 + 458) & 127;
    if (stage_v_151 > 33) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_134 + pub_r001076_9 * 2 + 461) & 127;
    if (stage_v_152 > 17) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001076_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_66 + pub_r001076_5 * 2 + 467) & 127;
    if (stage_v_154 > 26) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_140 + pub_r001076_14 * 2 + 470) & 127;
    if (stage_v_155 > 53) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_29 + pub_r001076_12 * 2 + 473) & 127;
    if (stage_v_156 > 44) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001076_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001076_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_4 + pub_r001076_9 * 2 + 482) & 127;
    if (stage_v_159 > 50) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_72 + pub_r001076_9 * 2 + 485) & 127;
    if (stage_v_160 > 59) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_46 + pub_r001076_16 * 2 + 488) & 127;
    if (stage_v_161 > 19) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (sec_r001076_13 + pub_r001076_1 * 2 + 491) & 127;
    if (stage_v_162 > 43) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_103 + pub_r001076_17 * 2 + 494) & 127;
    if (stage_v_163 > 24) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_98 + pub_r001076_4 * 2 + 497) & 127;
    if (stage_v_164 > 56) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
        sec_accum ^= (stage_v_164 & 31);
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_162 + pub_r001076_8 * 2 + 500) & 127;
    if (stage_v_165 > 42) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_4 + pub_r001076_4 * 2 + 503) & 127;
    if (stage_v_166 > 31) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_166 + pub_r001076_12 * 2 + 506) & 127;
    if (stage_v_167 > 28) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_140 + pub_r001076_3 * 2 + 509) & 127;
    if (stage_v_168 > 49) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_52 + pub_r001076_13 * 2 + 512) & 127;
    if (stage_v_169 > 38) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001076_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001076_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001076_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_25 + pub_r001076_12 * 2 + 524) & 127;
    if (stage_v_173 > 16) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
        sec_accum ^= (stage_v_173 & 31);
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001076_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001076_17 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001076_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001076_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (sec_r001076_16 + pub_r001076_16 * 2 + 539) & 127;
    if (stage_v_178 > 52) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001076_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_53 + pub_r001076_15 * 2 + 545) & 127;
    if (stage_v_180 > 40) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001076_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_96 + pub_r001076_4 * 2 + 551) & 127;
    if (stage_v_182 > 60) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_128 + pub_r001076_14 * 2 + 554) & 127;
    if (stage_v_183 > 55) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_105 + pub_r001076_12 * 2 + 557) & 127;
    if (stage_v_184 > 40) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001076_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (sec_r001076_0 + pub_r001076_5 * 2 + 563) & 127;
    if (stage_v_186 > 54) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001076_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001076_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (sec_r001076_15 + pub_r001076_8 * 2 + 572) & 127;
    if (stage_v_189 > 41) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
        sec_accum ^= (stage_v_189 & 31);
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_183 + pub_r001076_14 * 2 + 575) & 127;
    if (stage_v_190 > 35) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001076_1 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001076_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001076_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_147 + pub_r001076_12 * 2 + 587) & 127;
    if (stage_v_194 > 33) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
        sec_accum ^= (stage_v_194 & 31);
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001076_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_110 + pub_r001076_5 * 2 + 593) & 127;
    if (stage_v_196 > 52) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_161 + pub_r001076_16 * 2 + 596) & 127;
    if (stage_v_197 > 34) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_14 + pub_r001076_7 * 2 + 599) & 127;
    if (stage_v_198 > 39) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
        sec_accum ^= (stage_v_198 & 31);
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_173 + pub_r001076_7 * 2 + 602) & 127;
    if (stage_v_199 > 26) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001076_0 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_61 + pub_r001076_1 * 2 + 608) & 127;
    if (stage_v_201 > 34) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (sec_r001076_12 + pub_r001076_15 * 2 + 611) & 127;
    if (stage_v_202 > 24) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
        sec_accum ^= (stage_v_202 & 31);
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001076_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_62 + pub_r001076_2 * 2 + 617) & 127;
    if (stage_v_204 > 47) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (sec_r001076_2 + pub_r001076_9 * 2 + 620) & 127;
    if (stage_v_205 > 38) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
        sec_accum ^= (stage_v_205 & 31);
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001076_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (helper_flow_0 + pub_r001076_8 * 2 + 626) & 127;
    if (stage_v_207 > 22) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001076_12 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001076_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001076_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_32 + pub_r001076_13 * 2 + 638) & 127;
    if (stage_v_211 > 31) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001076_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001076_16 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (helper_flow_3 + pub_r001076_15 * 2 + 647) & 127;
    if (stage_v_214 > 20) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_82 + pub_r001076_1 * 2 + 650) & 127;
    if (stage_v_215 > 27) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001076_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_111 + pub_r001076_11 * 2 + 656) & 127;
    if (stage_v_217 > 41) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_0 + pub_r001076_17 * 2 + 659) & 127;
    if (stage_v_218 > 54) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_60 + pub_r001076_12 * 2 + 662) & 127;
    if (stage_v_219 > 48) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (pub_r001076_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_220) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (sec_r001076_10 + pub_r001076_11 * 2 + 668) & 127;
    if (stage_v_221 > 21) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_122 + pub_r001076_2 * 2 + 671) & 127;
    if (stage_v_222 > 22) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001076_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_135 + pub_r001076_14 * 2 + 677) & 127;
    if (stage_v_224 > 54) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001076_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_190 + pub_r001076_17 * 2 + 683) & 127;
    if (stage_v_226 > 56) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
        sec_accum ^= (stage_v_226 & 31);
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (helper_flow_0 + pub_r001076_4 * 2 + 686) & 127;
    if (stage_v_227 > 52) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
        sec_accum ^= (stage_v_227 & 31);
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001076_17 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_14 + pub_r001076_10 * 2 + 692) & 127;
    if (stage_v_229 > 27) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_10 + pub_r001076_5 * 2 + 695) & 127;
    if (stage_v_230 > 31) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
