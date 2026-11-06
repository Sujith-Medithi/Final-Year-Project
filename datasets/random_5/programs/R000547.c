/*
 * Benchmark Program: R000547
 * Security Family: nested_implicit_flow
 * Generator Seed: 554713
 * High Inputs: 20 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000547_4713_0 {
    short dim;
    short trace;
    short determinant;
    short density;
    int buffer[3];
};

struct FilterState_R000547_4713_1 {
    unsigned char prev_out;
    int prev_in;
    unsigned char cutoff;
    unsigned char damping;
    unsigned char gain_db;
    int buffer[3];
};

struct EventLog_R000547_4713_2 {
    int seq;
    int severity;
    short code;
    int timestamp;
    int buffer[3];
};

struct Transaction_R000547_4713_3 {
    unsigned char fee;
    unsigned char status;
    int balance;
    int buffer[3];
};

union ColorPixel_R000547_4713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000547_4713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000547_4713_0(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int stride_78 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_78 > 25) {
        acc = (acc + stride_78 * 2 + 5) & 127;
        aux ^= (stride_78 & 15);
    } else {
        acc = (acc - stride_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000547_4713_1(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000547_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_56 = (aux + st.buffer[1]) & 3;
    switch (vector_56) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_88) & 63;
    acc ^= aux;
    int phase_10 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_10 > 27) {
        acc = (acc + phase_10 * 2 + 5) & 127;
        aux ^= (phase_10 & 15);
    } else {
        acc = (acc - phase_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000547_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int vector_70 = local_arr[aux % 3];
    acc = (acc + vector_70 * 2) & 127;
    int tracker_51 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_51 > 45) {
        acc = (acc + tracker_51 * 2 + 5) & 127;
        aux ^= (tracker_51 & 15);
    } else {
        acc = (acc - tracker_51 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int mask_48 = (aux + st.buffer[1]) & 3;
    switch (mask_48) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_80 = local_arr[aux % 3];
    acc = (acc + quantum_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_4(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000547_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_72) & 63;
    acc ^= aux;
    int tracker_97 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_97 > 13) {
        acc = (acc + tracker_97 * 2 + 5) & 127;
        aux ^= (tracker_97 & 15);
    } else {
        acc = (acc - tracker_97 + 11) & 127;
        aux += 3;
    }
    int phase_16 = (aux + st.buffer[1]) & 3;
    switch (phase_16) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_84 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_84 > 32) {
        acc = (acc + quantum_84 * 2 + 5) & 127;
        aux ^= (quantum_84 & 15);
    } else {
        acc = (acc - quantum_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000547_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_28) & 63;
    acc ^= aux;
    int quotient_75 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_75 > 13) {
        acc = (acc + quotient_75 * 2 + 5) & 127;
        aux ^= (quotient_75 & 15);
    } else {
        acc = (acc - quotient_75 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_76 = (aux + st.buffer[1]) & 3;
    switch (threshold_76) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_24 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_24 > 25) {
        acc = (acc + offset_24 * 2 + 5) & 127;
        aux ^= (offset_24 & 15);
    } else {
        acc = (acc - offset_24 + 11) & 127;
        aux += 3;
    }
    int bound_38 = (aux + st.buffer[1]) & 3;
    switch (bound_38) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_63 = local_arr[aux % 3];
    acc = (acc + margin_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_8(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int delta_91 = (aux + st.buffer[1]) & 3;
    switch (delta_91) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_20 = local_arr[aux % 3];
    acc = (acc + vector_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_9(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000547_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int window_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_37) & 63;
    acc ^= aux;
    int tracker_66 = (aux + st.buffer[1]) & 3;
    switch (tracker_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_80 = local_arr[aux % 3];
    acc = (acc + tally_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_10(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int vector_84 = (aux + st.buffer[1]) & 3;
    switch (vector_84) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_49 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_49 > 22) {
        acc = (acc + segment_49 * 2 + 5) & 127;
        aux ^= (segment_49 & 15);
    } else {
        acc = (acc - segment_49 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000547_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_64 = local_arr[aux % 3];
    acc = (acc + coefficient_64 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_12(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000547_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int parity_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_56 = local_arr[aux % 3];
    acc = (acc + index_reg_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000547_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_48 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_48 > 37) {
        acc = (acc + quotient_48 * 2 + 5) & 127;
        aux ^= (quotient_48 & 15);
    } else {
        acc = (acc - quotient_48 + 11) & 127;
        aux += 3;
    }
    int checksum_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_96) & 63;
    acc ^= aux;
    int margin_57 = (aux + st.buffer[1]) & 3;
    switch (margin_57) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_14(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int mask_57 = (aux + st.buffer[1]) & 3;
    switch (mask_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_45 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_45 > 29) {
        acc = (acc + quantum_45 * 2 + 5) & 127;
        aux ^= (quantum_45 & 15);
    } else {
        acc = (acc - quantum_45 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_93 = local_arr[aux % 3];
    acc = (acc + parity_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000547_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int cursor_50 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_50 > 39) {
        acc = (acc + cursor_50 * 2 + 5) & 127;
        aux ^= (cursor_50 & 15);
    } else {
        acc = (acc - cursor_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_16(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tally_19 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_19 > 44) {
        acc = (acc + tally_19 * 2 + 5) & 127;
        aux ^= (tally_19 & 15);
    } else {
        acc = (acc - tally_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_11) & 63;
    acc ^= aux;
    int coefficient_64 = (aux + st.buffer[1]) & 3;
    switch (coefficient_64) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_17(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int parity_19 = (aux + st.buffer[1]) & 3;
    switch (parity_19) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_14 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_14 > 20) {
        acc = (acc + delta_14 * 2 + 5) & 127;
        aux ^= (delta_14 & 15);
    } else {
        acc = (acc - delta_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_93 = local_arr[aux % 3];
    acc = (acc + stride_93 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_18(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000547_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_76 = (st.buffer[0] * 3 + aux) & 63;
    if (window_76 > 20) {
        acc = (acc + window_76 * 2 + 5) & 127;
        aux ^= (window_76 & 15);
    } else {
        acc = (acc - window_76 + 11) & 127;
        aux += 3;
    }
    int quantum_10 = (aux + st.buffer[1]) & 3;
    switch (quantum_10) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000547_4713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_48 = local_arr[aux % 3];
    acc = (acc + bound_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000547_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_55 = (aux + st.buffer[1]) & 3;
    switch (window_55) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000547_4713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000547_4713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_92 = (aux + st.buffer[1]) & 3;
    switch (anchor_92) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_92 = local_arr[aux % 3];
    acc = (acc + quotient_92 * 2) & 127;
    int weight_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000547_4713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000547_4713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int stride_69 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_69 > 28) {
        acc = (acc + stride_69 * 2 + 5) & 127;
        aux ^= (stride_69 & 15);
    } else {
        acc = (acc - stride_69 + 11) & 127;
        aux += 3;
    }
    int segment_65 = (aux + st.buffer[1]) & 3;
    switch (segment_65) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000547_4713_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000547_4713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int index_reg_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_56) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_19 = local_arr[aux % 3];
    acc = (acc + cursor_19 * 2) & 127;
    int weight_70 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_70 > 20) {
        acc = (acc + weight_70 * 2 + 5) & 127;
        aux ^= (weight_70 & 15);
    } else {
        acc = (acc - weight_70 + 11) & 127;
        aux += 3;
    }
    int segment_81 = (aux + st.buffer[1]) & 3;
    switch (segment_81) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000547_0;
    int sec_r000547_1;
    int sec_r000547_2;
    int sec_r000547_3;
    int sec_r000547_4;
    int sec_r000547_5;
    int sec_r000547_6;
    int sec_r000547_7;
    int sec_r000547_8;
    int sec_r000547_9;
    int sec_r000547_10;
    int sec_r000547_11;
    int sec_r000547_12;
    int sec_r000547_13;
    int sec_r000547_14;
    int sec_r000547_15;
    int sec_r000547_16;
    int sec_r000547_17;
    int sec_r000547_18;
    int sec_r000547_19;
    int pub_r000547_0;
    int pub_r000547_1;
    int pub_r000547_2;
    int pub_r000547_3;
    int pub_r000547_4;
    int pub_r000547_5;
    int pub_r000547_6;
    int pub_r000547_7;
    int pub_r000547_8;
    int pub_r000547_9;
    int pub_r000547_10;
    int pub_r000547_11;
    int pub_r000547_12;
    int pub_r000547_13;
    int pub_r000547_14;
    int pub_r000547_15;
    int pub_r000547_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000547_0 >= -100 && pub_r000547_0 <= 100);
    __CPROVER_assume(pub_r000547_1 >= -100 && pub_r000547_1 <= 100);
    __CPROVER_assume(pub_r000547_2 >= -100 && pub_r000547_2 <= 100);
    __CPROVER_assume(pub_r000547_3 >= -100 && pub_r000547_3 <= 100);
    __CPROVER_assume(pub_r000547_4 >= -100 && pub_r000547_4 <= 100);
    __CPROVER_assume(pub_r000547_5 >= -100 && pub_r000547_5 <= 100);
    __CPROVER_assume(pub_r000547_6 >= -100 && pub_r000547_6 <= 100);
    __CPROVER_assume(pub_r000547_7 >= -100 && pub_r000547_7 <= 100);
    __CPROVER_assume(pub_r000547_8 >= -100 && pub_r000547_8 <= 100);
    __CPROVER_assume(pub_r000547_9 >= -100 && pub_r000547_9 <= 100);
    __CPROVER_assume(pub_r000547_10 >= -100 && pub_r000547_10 <= 100);
    __CPROVER_assume(pub_r000547_11 >= -100 && pub_r000547_11 <= 100);
    __CPROVER_assume(pub_r000547_12 >= -100 && pub_r000547_12 <= 100);
    __CPROVER_assume(pub_r000547_13 >= -100 && pub_r000547_13 <= 100);
    __CPROVER_assume(pub_r000547_14 >= -100 && pub_r000547_14 <= 100);
    __CPROVER_assume(pub_r000547_15 >= -100 && pub_r000547_15 <= 100);
    __CPROVER_assume(pub_r000547_16 >= -100 && pub_r000547_16 <= 100);
    __CPROVER_assume(sec_r000547_0 >= 0 && sec_r000547_0 <= 255);
    __CPROVER_assume(sec_r000547_1 >= 0 && sec_r000547_1 <= 255);
    __CPROVER_assume(sec_r000547_2 >= 0 && sec_r000547_2 <= 255);
    __CPROVER_assume(sec_r000547_3 >= 0 && sec_r000547_3 <= 255);
    __CPROVER_assume(sec_r000547_4 >= 0 && sec_r000547_4 <= 255);
    __CPROVER_assume(sec_r000547_5 >= 0 && sec_r000547_5 <= 255);
    __CPROVER_assume(sec_r000547_6 >= 0 && sec_r000547_6 <= 255);
    __CPROVER_assume(sec_r000547_7 >= 0 && sec_r000547_7 <= 255);
    __CPROVER_assume(sec_r000547_8 >= 0 && sec_r000547_8 <= 255);
    __CPROVER_assume(sec_r000547_9 >= 0 && sec_r000547_9 <= 255);
    __CPROVER_assume(sec_r000547_10 >= 0 && sec_r000547_10 <= 255);
    __CPROVER_assume(sec_r000547_11 >= 0 && sec_r000547_11 <= 255);
    __CPROVER_assume(sec_r000547_12 >= 0 && sec_r000547_12 <= 255);
    __CPROVER_assume(sec_r000547_13 >= 0 && sec_r000547_13 <= 255);
    __CPROVER_assume(sec_r000547_14 >= 0 && sec_r000547_14 <= 255);
    __CPROVER_assume(sec_r000547_15 >= 0 && sec_r000547_15 <= 255);
    __CPROVER_assume(sec_r000547_16 >= 0 && sec_r000547_16 <= 255);
    __CPROVER_assume(sec_r000547_17 >= 0 && sec_r000547_17 <= 255);
    __CPROVER_assume(sec_r000547_18 >= 0 && sec_r000547_18 <= 255);
    __CPROVER_assume(sec_r000547_19 >= 0 && sec_r000547_19 <= 255);

    struct MatrixBlock_R000547_4713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000547_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000547_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000547_0 + 7) & 15;
    struct FilterState_R000547_4713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000547_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000547_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000547_0 + 9) & 15;
    struct EventLog_R000547_4713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000547_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000547_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000547_0 + 11) & 15;
    struct Transaction_R000547_4713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000547_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000547_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000547_0 + 13) & 15;

    union ColorPixel_R000547_4713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 30) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 45) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 26) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 41) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 26) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 41) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
        case 0:
            out_sink = (out_sink + 3) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 20) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 35) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 28) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 43) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_2.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
        case 0:
            out_sink = (out_sink + 7) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 18) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 33) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
        case 0:
            out_sink = (out_sink + 8) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 21) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 36) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
        case 0:
            out_sink = (out_sink + 9) & 255;
            break;
        case 1:
            chk_sum ^= 0x3F;
            break;
        case 2:
            out_sink = (out_sink ^ 0x2A) & 255;
            break;
        default:
            chk_sum = (chk_sum + 7) & 127;
            break;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000547_7 & 1) != 0) {
        if ((sec_r000547_10 & 2) != 0) {
            stage_v_53 = (pub_r000547_9 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000547_9 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000547_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000547_13 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_54 = (pub_r000547_14 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000547_14 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000547_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000547_1 & 2) != 0) {
            stage_v_55 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000547_11 & 2) != 0) {
            stage_v_56 = (pub_r000547_5 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000547_5 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000547_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_7 & 2) != 0) {
            stage_v_57 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000547_16 & 2) != 0) {
            stage_v_58 = (pub_r000547_4 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000547_4 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000547_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_17 & 2) != 0) {
            stage_v_59 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000547_10 & 2) != 0) {
            stage_v_60 = (pub_r000547_12 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000547_12 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000547_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000547_14 & 2) != 0) {
            stage_v_61 = (pub_r000547_9 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000547_9 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000547_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_16 & 2) != 0) {
            stage_v_62 = (pub_r000547_9 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000547_9 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000547_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_14 & 2) != 0) {
            stage_v_63 = (pub_r000547_5 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000547_5 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000547_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000547_18 & 1) != 0) {
        if ((sec_r000547_4 & 2) != 0) {
            stage_v_64 = (pub_r000547_5 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000547_5 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000547_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000547_3 & 2) != 0) {
            stage_v_65 = (pub_r000547_6 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000547_6 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000547_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000547_7 & 2) != 0) {
            stage_v_66 = (pub_r000547_14 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000547_14 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000547_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000547_14 & 2) != 0) {
            stage_v_67 = (pub_r000547_4 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000547_4 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000547_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000547_6 & 2) != 0) {
            stage_v_68 = (pub_r000547_14 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000547_14 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000547_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_69 = (pub_r000547_10 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000547_10 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000547_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000547_16 & 2) != 0) {
            stage_v_70 = (pub_r000547_12 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000547_12 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000547_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((sec_r000547_17 & 1) != 0) {
        if ((sec_r000547_17 & 2) != 0) {
            stage_v_71 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000547_14 & 2) != 0) {
            stage_v_72 = (pub_r000547_5 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000547_5 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000547_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000547_1 & 1) != 0) {
        if ((sec_r000547_17 & 2) != 0) {
            stage_v_73 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000547_11 & 2) != 0) {
            stage_v_74 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000547_6 & 2) != 0) {
            stage_v_75 = (pub_r000547_9 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000547_9 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000547_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000547_10 & 2) != 0) {
            stage_v_76 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000547_3 & 1) != 0) {
        if ((sec_r000547_4 & 2) != 0) {
            stage_v_77 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000547_14 & 1) != 0) {
        if ((sec_r000547_14 & 2) != 0) {
            stage_v_78 = (pub_r000547_9 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000547_9 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000547_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000547_1 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_79 = (pub_r000547_15 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000547_15 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000547_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000547_6 & 2) != 0) {
            stage_v_80 = (pub_r000547_16 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000547_16 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000547_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000547_15 & 1) != 0) {
        if ((sec_r000547_1 & 2) != 0) {
            stage_v_81 = (pub_r000547_7 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000547_7 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000547_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000547_13 & 2) != 0) {
            stage_v_82 = (pub_r000547_8 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000547_8 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000547_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000547_17 & 2) != 0) {
            stage_v_83 = (pub_r000547_0 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000547_0 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000547_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_16 & 2) != 0) {
            stage_v_84 = (pub_r000547_12 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000547_12 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000547_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_18 & 2) != 0) {
            stage_v_85 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_86 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000547_10 & 1) != 0) {
        if ((sec_r000547_1 & 2) != 0) {
            stage_v_87 = (pub_r000547_14 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000547_14 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000547_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000547_15 & 2) != 0) {
            stage_v_88 = (pub_r000547_1 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000547_1 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000547_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000547_4 & 2) != 0) {
            stage_v_89 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000547_7 & 1) != 0) {
        if ((sec_r000547_12 & 2) != 0) {
            stage_v_90 = (pub_r000547_5 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000547_5 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000547_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000547_16 & 1) != 0) {
        if ((sec_r000547_10 & 2) != 0) {
            stage_v_91 = (pub_r000547_4 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000547_4 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000547_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000547_19 & 2) != 0) {
            stage_v_92 = (pub_r000547_5 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000547_5 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000547_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000547_15 & 2) != 0) {
            stage_v_93 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000547_13 & 2) != 0) {
            stage_v_94 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000547_5 & 2) != 0) {
            stage_v_95 = (pub_r000547_1 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000547_1 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000547_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000547_18 & 1) != 0) {
        if ((sec_r000547_12 & 2) != 0) {
            stage_v_96 = (pub_r000547_4 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000547_4 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000547_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000547_2 & 2) != 0) {
            stage_v_97 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000547_14 & 2) != 0) {
            stage_v_98 = (pub_r000547_15 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000547_15 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000547_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000547_19 & 2) != 0) {
            stage_v_99 = (pub_r000547_4 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000547_4 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000547_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000547_3 & 1) != 0) {
        if ((sec_r000547_16 & 2) != 0) {
            stage_v_100 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000547_12 & 1) != 0) {
        if ((sec_r000547_1 & 2) != 0) {
            stage_v_101 = (pub_r000547_6 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000547_6 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000547_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_102 = (pub_r000547_8 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000547_8 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000547_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000547_12 & 1) != 0) {
        if ((sec_r000547_8 & 2) != 0) {
            stage_v_103 = (pub_r000547_16 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000547_16 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000547_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000547_19 & 2) != 0) {
            stage_v_104 = (pub_r000547_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000547_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000547_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000547_1 & 1) != 0) {
        if ((sec_r000547_6 & 2) != 0) {
            stage_v_105 = (pub_r000547_15 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000547_15 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000547_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000547_16 & 1) != 0) {
        if ((sec_r000547_2 & 2) != 0) {
            stage_v_106 = (pub_r000547_10 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000547_10 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000547_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000547_8 & 1) != 0) {
        if ((sec_r000547_16 & 2) != 0) {
            stage_v_107 = (pub_r000547_14 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000547_14 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000547_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000547_11 & 2) != 0) {
            stage_v_108 = (pub_r000547_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000547_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000547_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_109 = (pub_r000547_1 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000547_1 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000547_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000547_11 & 2) != 0) {
            stage_v_110 = (pub_r000547_12 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000547_12 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000547_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000547_2 & 2) != 0) {
            stage_v_111 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000547_19 & 1) != 0) {
        if ((sec_r000547_1 & 2) != 0) {
            stage_v_112 = (pub_r000547_3 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000547_3 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000547_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000547_15 & 1) != 0) {
        if ((sec_r000547_19 & 2) != 0) {
            stage_v_113 = (pub_r000547_16 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000547_16 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000547_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000547_13 & 2) != 0) {
            stage_v_114 = (pub_r000547_15 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000547_15 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000547_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000547_3 & 2) != 0) {
            stage_v_115 = (pub_r000547_1 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000547_1 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000547_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000547_2 & 1) != 0) {
        if ((sec_r000547_8 & 2) != 0) {
            stage_v_116 = (pub_r000547_10 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000547_10 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000547_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000547_17 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_117 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000547_18 & 2) != 0) {
            stage_v_118 = (pub_r000547_10 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000547_10 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000547_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000547_19 & 2) != 0) {
            stage_v_119 = (pub_r000547_12 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000547_12 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000547_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000547_0 & 2) != 0) {
            stage_v_120 = (pub_r000547_12 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000547_12 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000547_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000547_14 & 1) != 0) {
        if ((sec_r000547_5 & 2) != 0) {
            stage_v_121 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000547_9 & 2) != 0) {
            stage_v_122 = (pub_r000547_11 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000547_11 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000547_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000547_12 & 1) != 0) {
        if ((sec_r000547_2 & 2) != 0) {
            stage_v_123 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000547_2 & 2) != 0) {
            stage_v_124 = (pub_r000547_10 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000547_10 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000547_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000547_15 & 1) != 0) {
        if ((sec_r000547_13 & 2) != 0) {
            stage_v_125 = (pub_r000547_13 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000547_13 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000547_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
