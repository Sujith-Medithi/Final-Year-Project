/*
 * Benchmark Program: R001120
 * Security Family: mixed_control_data
 * Generator Seed: 612013
 * High Inputs: 24 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001120_2013_0 {
    int nonce;
    short round_key;
    short flags;
    int buffer[3];
};

struct AudioFrame_R001120_2013_1 {
    int peak;
    int envelope;
    short sample_rate;
    int rms;
    int buffer[3];
};

struct EventLog_R001120_2013_2 {
    unsigned char code;
    unsigned char severity;
    int signature;
    int buffer[3];
};

union TelemetryField_R001120_2013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001120_2013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int factor_44 = local_arr[aux % 3];
    acc = (acc + factor_44 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_1(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int delta_19 = local_arr[aux % 3];
    acc = (acc + delta_19 * 2) & 127;
    int segment_81 = (aux + st.buffer[1]) & 3;
    switch (segment_81) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_60) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001120_2013_2(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quantum_56 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_56 = (quantum_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_56) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_82 = local_arr[aux % 3];
    acc = (acc + cursor_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_31 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_31 > 13) {
        acc = (acc + coefficient_31 * 2 + 5) & 127;
        aux ^= (coefficient_31 & 15);
    } else {
        acc = (acc - coefficient_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_68 = local_arr[aux % 3];
    acc = (acc + sample_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001120_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int vector_48 = local_arr[aux % 3];
    acc = (acc + vector_48 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_66 = 0;
    for (int k = 0; k < 3; k++) {
        segment_66 = (segment_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_66) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_56 = local_arr[aux % 3];
    acc = (acc + quotient_56 * 2) & 127;
    int bound_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001120_2013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_37 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_37 > 30) {
        acc = (acc + offset_37 * 2 + 5) & 127;
        aux ^= (offset_37 & 15);
    } else {
        acc = (acc - offset_37 + 11) & 127;
        aux += 3;
    }
    int checksum_33 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_33 = (checksum_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_33) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_66 = local_arr[aux % 3];
    acc = (acc + phase_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001120_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int mask_97 = 0;
    for (int k = 0; k < 3; k++) {
        mask_97 = (mask_97 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_97) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_89 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_89 > 35) {
        acc = (acc + scale_89 * 2 + 5) & 127;
        aux ^= (scale_89 & 15);
    } else {
        acc = (acc - scale_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001120_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_56) & 63;
    acc ^= aux;
    int phase_90 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_90 > 33) {
        acc = (acc + phase_90 * 2 + 5) & 127;
        aux ^= (phase_90 & 15);
    } else {
        acc = (acc - phase_90 + 11) & 127;
        aux += 3;
    }
    int pivot_42 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_42 = (pivot_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_10(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quotient_40 = (aux + st.buffer[1]) & 3;
    switch (quotient_40) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_50 = 0;
    for (int k = 0; k < 3; k++) {
        damping_50 = (damping_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_11(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int pivot_29 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_29 > 30) {
        acc = (acc + pivot_29 * 2 + 5) & 127;
        aux ^= (pivot_29 & 15);
    } else {
        acc = (acc - pivot_29 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_13 = local_arr[aux % 3];
    acc = (acc + index_reg_13 * 2) & 127;
    int bound_95 = 0;
    for (int k = 0; k < 2; k++) {
        bound_95 = (bound_95 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_95) & 127;
    }
    int pivot_26 = (aux + st.buffer[1]) & 3;
    switch (pivot_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001120_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tally_82 = (aux + st.buffer[1]) & 3;
    switch (tally_82) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_89 = local_arr[aux % 3];
    acc = (acc + quantum_89 * 2) & 127;
    int threshold_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_43) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001120_2013_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_76) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_49 = local_arr[aux % 3];
    acc = (acc + quotient_49 * 2) & 127;
    int offset_30 = (aux + st.buffer[1]) & 3;
    switch (offset_30) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_14(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int residue_13 = (aux + st.buffer[1]) & 3;
    switch (residue_13) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_89 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_89 > 18) {
        acc = (acc + quantum_89 * 2 + 5) & 127;
        aux ^= (quantum_89 & 15);
    } else {
        acc = (acc - quantum_89 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_43 = local_arr[aux % 3];
    acc = (acc + vector_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int scale_89 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_89 > 45) {
        acc = (acc + scale_89 * 2 + 5) & 127;
        aux ^= (scale_89 & 15);
    } else {
        acc = (acc - scale_89 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_75 = local_arr[aux % 3];
    acc = (acc + delta_75 * 2) & 127;
    int pivot_69 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_69 = (pivot_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_69) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_16(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int phase_32 = 0;
    for (int k = 0; k < 3; k++) {
        phase_32 = (phase_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_32) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_82 = (aux + st.buffer[1]) & 3;
    switch (accumulator_82) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_24) & 63;
    acc ^= aux;
    int stride_78 = 0;
    for (int k = 0; k < 2; k++) {
        stride_78 = (stride_78 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_78) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_65 = (aux + st.buffer[1]) & 3;
    switch (tracker_65) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_84) & 63;
    acc ^= aux;
    int vector_91 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_91 > 20) {
        acc = (acc + vector_91 * 2 + 5) & 127;
        aux ^= (vector_91 & 15);
    } else {
        acc = (acc - vector_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_19(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_76 = (aux + st.buffer[1]) & 3;
    switch (mask_76) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_23 = local_arr[aux % 3];
    acc = (acc + residue_23 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001120_2013_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001120_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_19 = local_arr[aux % 3];
    acc = (acc + threshold_19 * 2) & 127;
    int threshold_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001120_2013_21(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001120_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_74) & 63;
    acc ^= aux;
    int tally_83 = 0;
    for (int k = 0; k < 2; k++) {
        tally_83 = (tally_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_83) & 127;
    }
    int window_16 = (aux + st.buffer[1]) & 3;
    switch (window_16) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001120_2013_22(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001120_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_43 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_43 > 16) {
        acc = (acc + mask_43 * 2 + 5) & 127;
        aux ^= (mask_43 & 15);
    } else {
        acc = (acc - mask_43 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001120_2013_23(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001120_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_37 = (aux + st.buffer[1]) & 3;
    switch (bound_37) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001120_0;
    int sec_r001120_1;
    int sec_r001120_2;
    int sec_r001120_3;
    int sec_r001120_4;
    int sec_r001120_5;
    int sec_r001120_6;
    int sec_r001120_7;
    int sec_r001120_8;
    int sec_r001120_9;
    int sec_r001120_10;
    int sec_r001120_11;
    int sec_r001120_12;
    int sec_r001120_13;
    int sec_r001120_14;
    int sec_r001120_15;
    int sec_r001120_16;
    int sec_r001120_17;
    int sec_r001120_18;
    int sec_r001120_19;
    int sec_r001120_20;
    int sec_r001120_21;
    int sec_r001120_22;
    int sec_r001120_23;
    int pub_r001120_0;
    int pub_r001120_1;
    int pub_r001120_2;
    int pub_r001120_3;
    int pub_r001120_4;
    int pub_r001120_5;
    int pub_r001120_6;
    int pub_r001120_7;
    int pub_r001120_8;
    int pub_r001120_9;
    int pub_r001120_10;
    int pub_r001120_11;
    int pub_r001120_12;
    int pub_r001120_13;
    int pub_r001120_14;
    int pub_r001120_15;
    int pub_r001120_16;
    int pub_r001120_17;
    int pub_r001120_18;
    int pub_r001120_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001120_0 >= -100 && pub_r001120_0 <= 100);
    __CPROVER_assume(pub_r001120_1 >= -100 && pub_r001120_1 <= 100);
    __CPROVER_assume(pub_r001120_2 >= -100 && pub_r001120_2 <= 100);
    __CPROVER_assume(pub_r001120_3 >= -100 && pub_r001120_3 <= 100);
    __CPROVER_assume(pub_r001120_4 >= -100 && pub_r001120_4 <= 100);
    __CPROVER_assume(pub_r001120_5 >= -100 && pub_r001120_5 <= 100);
    __CPROVER_assume(pub_r001120_6 >= -100 && pub_r001120_6 <= 100);
    __CPROVER_assume(pub_r001120_7 >= -100 && pub_r001120_7 <= 100);
    __CPROVER_assume(pub_r001120_8 >= -100 && pub_r001120_8 <= 100);
    __CPROVER_assume(pub_r001120_9 >= -100 && pub_r001120_9 <= 100);
    __CPROVER_assume(pub_r001120_10 >= -100 && pub_r001120_10 <= 100);
    __CPROVER_assume(pub_r001120_11 >= -100 && pub_r001120_11 <= 100);
    __CPROVER_assume(pub_r001120_12 >= -100 && pub_r001120_12 <= 100);
    __CPROVER_assume(pub_r001120_13 >= -100 && pub_r001120_13 <= 100);
    __CPROVER_assume(pub_r001120_14 >= -100 && pub_r001120_14 <= 100);
    __CPROVER_assume(pub_r001120_15 >= -100 && pub_r001120_15 <= 100);
    __CPROVER_assume(pub_r001120_16 >= -100 && pub_r001120_16 <= 100);
    __CPROVER_assume(pub_r001120_17 >= -100 && pub_r001120_17 <= 100);
    __CPROVER_assume(pub_r001120_18 >= -100 && pub_r001120_18 <= 100);
    __CPROVER_assume(pub_r001120_19 >= -100 && pub_r001120_19 <= 100);
    __CPROVER_assume(sec_r001120_0 >= 0 && sec_r001120_0 <= 255);
    __CPROVER_assume(sec_r001120_1 >= 0 && sec_r001120_1 <= 255);
    __CPROVER_assume(sec_r001120_2 >= 0 && sec_r001120_2 <= 255);
    __CPROVER_assume(sec_r001120_3 >= 0 && sec_r001120_3 <= 255);
    __CPROVER_assume(sec_r001120_4 >= 0 && sec_r001120_4 <= 255);
    __CPROVER_assume(sec_r001120_5 >= 0 && sec_r001120_5 <= 255);
    __CPROVER_assume(sec_r001120_6 >= 0 && sec_r001120_6 <= 255);
    __CPROVER_assume(sec_r001120_7 >= 0 && sec_r001120_7 <= 255);
    __CPROVER_assume(sec_r001120_8 >= 0 && sec_r001120_8 <= 255);
    __CPROVER_assume(sec_r001120_9 >= 0 && sec_r001120_9 <= 255);
    __CPROVER_assume(sec_r001120_10 >= 0 && sec_r001120_10 <= 255);
    __CPROVER_assume(sec_r001120_11 >= 0 && sec_r001120_11 <= 255);
    __CPROVER_assume(sec_r001120_12 >= 0 && sec_r001120_12 <= 255);
    __CPROVER_assume(sec_r001120_13 >= 0 && sec_r001120_13 <= 255);
    __CPROVER_assume(sec_r001120_14 >= 0 && sec_r001120_14 <= 255);
    __CPROVER_assume(sec_r001120_15 >= 0 && sec_r001120_15 <= 255);
    __CPROVER_assume(sec_r001120_16 >= 0 && sec_r001120_16 <= 255);
    __CPROVER_assume(sec_r001120_17 >= 0 && sec_r001120_17 <= 255);
    __CPROVER_assume(sec_r001120_18 >= 0 && sec_r001120_18 <= 255);
    __CPROVER_assume(sec_r001120_19 >= 0 && sec_r001120_19 <= 255);
    __CPROVER_assume(sec_r001120_20 >= 0 && sec_r001120_20 <= 255);
    __CPROVER_assume(sec_r001120_21 >= 0 && sec_r001120_21 <= 255);
    __CPROVER_assume(sec_r001120_22 >= 0 && sec_r001120_22 <= 255);
    __CPROVER_assume(sec_r001120_23 >= 0 && sec_r001120_23 <= 255);

    struct CipherContext_R001120_2013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001120_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001120_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001120_0 + 7) & 15;
    struct AudioFrame_R001120_2013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001120_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001120_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001120_0 + 9) & 15;
    struct EventLog_R001120_2013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001120_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001120_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001120_0 + 11) & 15;

    union TelemetryField_R001120_2013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001120_2013_0(sec_r001120_0, pub_r001120_1, pub_r001120_2, pub_r001120_3);
    int helper_flow_1 = fn_R001120_2013_1(sec_r001120_1, pub_r001120_2);
    int helper_flow_2 = fn_R001120_2013_2(sec_r001120_2, sec_r001120_3);
    int helper_flow_3 = fn_R001120_2013_3(sec_r001120_3, sec_r001120_4, pub_r001120_5, pub_r001120_6);
    int helper_flow_4 = fn_R001120_2013_4(sec_r001120_4, sec_r001120_5, pub_r001120_6, pub_r001120_7, pub_r001120_8);
    int helper_flow_5 = fn_R001120_2013_5(sec_r001120_5, pub_r001120_6, pub_r001120_7, pub_r001120_8);
    int helper_flow_6 = fn_R001120_2013_6(sec_r001120_6, pub_r001120_7, pub_r001120_8, pub_r001120_9);
    int helper_flow_7 = fn_R001120_2013_7(sec_r001120_7, pub_r001120_8, pub_r001120_9, pub_r001120_10, pub_r001120_11);
    int helper_flow_8 = fn_R001120_2013_8(sec_r001120_8, sec_r001120_9, pub_r001120_10, pub_r001120_11);
    int helper_flow_9 = fn_R001120_2013_9(sec_r001120_9, sec_r001120_10, pub_r001120_11, pub_r001120_12);
    int helper_flow_10 = fn_R001120_2013_10(sec_r001120_10, pub_r001120_11, pub_r001120_12);
    int helper_flow_11 = fn_R001120_2013_11(sec_r001120_11, pub_r001120_12);
    int helper_flow_12 = fn_R001120_2013_12(sec_r001120_12, pub_r001120_13, pub_r001120_14, pub_r001120_15, pub_r001120_16);
    int helper_flow_13 = fn_R001120_2013_13(sec_r001120_13, pub_r001120_14, pub_r001120_15, pub_r001120_16);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001120_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((sec_r001120_12 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_1 > 35) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001120_19 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_2 > 30) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((sec_r001120_23 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_3 > 45) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_4 > 48) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001120_10 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_5 > 33) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001120_20 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_6 > 41) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001120_0 ^ 0x2A) * 2 + pub_r001120_12) & 127;
    if (stage_v_7 > 37) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_8 > 24) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001120_17 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_9 > 37) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_10 > 28) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001120_7 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_11 > 28) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001120_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_13 > 35) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001120_9 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_14 > 28) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001120_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001120_11) & 127;
    if (stage_v_16 > 36) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001120_23 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_17 > 31) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_18 > 32) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_19 > 48) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001120_6 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_20 > 39) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001120_9 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_21 > 45) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_22 > 25) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001120_9 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_23 > 38) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_24 > 46) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001120_18 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_26 > 32) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001120_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_28 > 34) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_29 > 37) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_30 > 43) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_31 > 22) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001120_6 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001120_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((helper_flow_12 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_34 > 33) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001120_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r001120_17 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_36 > 46) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_37 > 41) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_38 > 45) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_39 > 21) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001120_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_41 > 41) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001120_12 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_43 > 40) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001120_4 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_44 > 29) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_45 > 34) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_46 > 43) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001120_5 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_47 > 37) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_48 > 49) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_49 > 47) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_50 > 27) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r001120_7 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_51 > 38) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001120_19 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_52 > 50) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_53 > 30) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_54 > 31) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r001120_3 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_55 > 42) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_56 > 26) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_57 > 29) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_58 > 25) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_59 > 45) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_60 > 21) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_61 > 31) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r001120_3 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_62 > 41) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_63 > 25) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_64 > 46) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001120_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_66 > 30) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_67 > 21) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_68 > 42) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_69 > 32) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r001120_19 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_70 > 21) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001120_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_72 > 47) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_73 > 32) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001120_4 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_74 > 45) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_75 > 21) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_76 > 49) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_77 > 41) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001120_16 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_78 > 41) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001120_18 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_79 > 32) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_80 > 30) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_81 > 50) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((sec_r001120_5 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_82 > 23) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_83 > 39) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_84 > 33) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_85 > 22) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001120_13 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_86 > 25) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_87 > 29) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001120_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_89 > 43) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_90 > 38) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001120_4 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_92 > 41) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001120_19 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_93 > 50) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001120_12) & 127;
    if (stage_v_94 > 46) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_95 > 39) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001120_8 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_96 > 34) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001120_12) & 127;
    if (stage_v_97 > 35) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_98 > 45) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001120_15 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_99 > 48) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001120_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_101 > 28) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001120_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_103 > 42) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001120_16 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_105 > 43) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_106 > 47) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_107 > 44) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_108 > 31) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_109 > 23) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001120_11) & 127;
    if (stage_v_110 > 39) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001120_12) & 127;
    if (stage_v_111 > 21) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_112 > 25) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_113 > 32) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r001120_19 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_114 > 31) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001120_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001120_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_113 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_117 > 46) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_118 > 45) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001120_1 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_119 > 27) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_120 > 28) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_121 > 41) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_122 > 36) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_114 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_123 > 50) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_124 > 40) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001120_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_126 > 46) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_127 > 44) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001120_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_53 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_129 > 39) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_130 > 26) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r001120_3 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_131 > 21) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_132 > 40) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001120_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r001120_5 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_134 > 48) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001120_11) & 127;
    if (stage_v_135 > 28) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_136 > 24) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001120_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001120_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_139 > 30) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001120_17 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_140 > 33) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_141 > 36) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_142 > 34) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_143 > 27) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_110 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_144 > 41) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r001120_23 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_145 > 39) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001120_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001120_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_148 > 31) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_149 > 21) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_150 > 29) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_151 > 46) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001120_13 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_152 > 29) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001120_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001120_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001120_12) & 127;
    if (stage_v_155 > 39) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_156 > 42) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_157 > 49) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_150 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_158 > 49) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_159 > 26) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r001120_11 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_160 > 25) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r001120_20 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_161 > 48) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_162 > 33) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_163 > 40) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_22 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_164 > 30) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001120_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001120_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_167 > 29) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_168 > 31) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_169 > 25) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_170 > 22) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001120_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_172 > 38) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_45 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_173 > 26) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001120_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001120_16 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_176 > 27) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r001120_5 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_177 > 45) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_178 > 30) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_179 > 45) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001120_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001120_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_182 > 21) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001120_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_184 > 43) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_185 > 35) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r001120_8 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_186 > 23) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001120_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_188 > 24) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_189 > 24) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_190 > 37) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_191 > 50) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_192 > 27) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001120_10 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_194 > 41) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001120_11) & 127;
    if (stage_v_195 > 43) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_196 > 38) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_197 > 24) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_198 > 23) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_199 > 33) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001120_17 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((sec_r001120_23 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_201 > 23) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001120_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_203 > 26) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_204 > 33) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001120_5 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_108 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_206 > 43) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_178 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_207 > 49) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_170 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_208 > 35) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001120_18 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001120_19) & 127;
    if (stage_v_210 > 34) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001120_0) & 127;
    if (stage_v_211 > 49) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001120_5) & 127;
    if (stage_v_212 > 34) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001120_6) & 127;
    if (stage_v_213 > 49) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001120_16) & 127;
    if (stage_v_214 > 28) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (pub_r001120_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_215) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001120_9 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r001120_0 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_217 > 24) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_197 ^ 0x2A) * 2 + pub_r001120_7) & 127;
    if (stage_v_218 > 20) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001120_3) & 127;
    if (stage_v_219 > 29) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001120_15) & 127;
    if (stage_v_220 > 45) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_221 > 26) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_192 ^ 0x2A) * 2 + pub_r001120_1) & 127;
    if (stage_v_222 > 38) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001120_2 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_223 > 30) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001120_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_225 > 26) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001120_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_148 ^ 0x2A) * 2 + pub_r001120_8) & 127;
    if (stage_v_227 > 46) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_228 > 27) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001120_23 ^ 0x2A) * 2 + pub_r001120_18) & 127;
    if (stage_v_229 > 49) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_212 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_230 > 46) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001120_12 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001120_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_233 > 49) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((sec_r001120_2 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_234 > 46) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001120_17) & 127;
    if (stage_v_235 > 26) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001120_19 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_93 ^ 0x2A) * 2 + pub_r001120_2) & 127;
    if (stage_v_237 > 50) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001120_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_144 ^ 0x2A) * 2 + pub_r001120_9) & 127;
    if (stage_v_239 > 37) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_240 > 39) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001120_4) & 127;
    if (stage_v_241 > 33) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r001120_8 ^ 0x2A) * 2 + pub_r001120_13) & 127;
    if (stage_v_242 > 42) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001120_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001120_10) & 127;
    if (stage_v_244 > 25) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001120_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_237 ^ 0x2A) * 2 + pub_r001120_14) & 127;
    if (stage_v_246 > 28) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
