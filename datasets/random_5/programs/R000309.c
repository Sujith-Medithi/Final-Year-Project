/*
 * Benchmark Program: R000309
 * Security Family: secret_dependent_array
 * Generator Seed: 530913
 * High Inputs: 23 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000309_913_0 {
    int gain;
    int threshold;
    unsigned char status;
    unsigned char calib;
    unsigned char offset;
    unsigned char reading;
    int buffer[3];
};

struct CipherContext_R000309_913_1 {
    int counter;
    int round_key;
    unsigned char flags;
    short nonce;
    int iv;
    int buffer[3];
};

struct EventLog_R000309_913_2 {
    unsigned char seq;
    int signature;
    int timestamp;
    short severity;
    int buffer[3];
};

union PacketPayload_R000309_913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000309_913_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_34 = local_arr[aux % 3];
    acc = (acc + offset_34 * 2) & 127;
    int threshold_56 = (aux + st.buffer[1]) & 3;
    switch (threshold_56) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_14 = (aux + st.buffer[1]) & 3;
    switch (threshold_14) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_47 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_47 > 44) {
        acc = (acc + segment_47 * 2 + 5) & 127;
        aux ^= (segment_47 & 15);
    } else {
        acc = (acc - segment_47 + 11) & 127;
        aux += 3;
    }
    int metric_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000309_913_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_12 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_12 > 32) {
        acc = (acc + stride_12 * 2 + 5) & 127;
        aux ^= (stride_12 & 15);
    } else {
        acc = (acc - stride_12 + 11) & 127;
        aux += 3;
    }
    int quantum_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_58) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_28 = local_arr[aux % 3];
    acc = (acc + phase_28 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_3(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int damping_57 = (aux + st.buffer[1]) & 3;
    switch (damping_57) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_54) & 63;
    acc ^= aux;
    int scale_31 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_31 > 39) {
        acc = (acc + scale_31 * 2 + 5) & 127;
        aux ^= (scale_31 & 15);
    } else {
        acc = (acc - scale_31 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_61 = local_arr[aux % 3];
    acc = (acc + sample_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_27 = local_arr[aux % 3];
    acc = (acc + parity_27 * 2) & 127;
    int quantum_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_95) & 63;
    acc ^= aux;
    int checksum_12 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_12 > 39) {
        acc = (acc + checksum_12 * 2 + 5) & 127;
        aux ^= (checksum_12 & 15);
    } else {
        acc = (acc - checksum_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_5(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int delta_91 = (aux + st.buffer[1]) & 3;
    switch (delta_91) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_75 = local_arr[aux % 3];
    acc = (acc + index_reg_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_6(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000309_913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int bound_78 = (aux + st.buffer[1]) & 3;
    switch (bound_78) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_93 = local_arr[aux % 3];
    acc = (acc + tally_93 * 2) & 127;
    int vector_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_43) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int parity_46 = (aux + st.buffer[1]) & 3;
    switch (parity_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_13 = local_arr[aux % 3];
    acc = (acc + segment_13 * 2) & 127;
    int weight_50 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_50 > 48) {
        acc = (acc + weight_50 * 2 + 5) & 127;
        aux ^= (weight_50 & 15);
    } else {
        acc = (acc - weight_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_8(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_18 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_18 > 24) {
        acc = (acc + anchor_18 * 2 + 5) & 127;
        aux ^= (anchor_18 & 15);
    } else {
        acc = (acc - anchor_18 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_33 = local_arr[aux % 3];
    acc = (acc + quantum_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000309_913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_73 = (aux + st.buffer[1]) & 3;
    switch (sample_73) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_90) & 63;
    acc ^= aux;
    int scale_93 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_93 > 49) {
        acc = (acc + scale_93 * 2 + 5) & 127;
        aux ^= (scale_93 & 15);
    } else {
        acc = (acc - scale_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_34 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_34 > 20) {
        acc = (acc + damping_34 * 2 + 5) & 127;
        aux ^= (damping_34 & 15);
    } else {
        acc = (acc - damping_34 + 11) & 127;
        aux += 3;
    }
    int stride_26 = (aux + st.buffer[1]) & 3;
    switch (stride_26) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int weight_34 = (aux + st.buffer[1]) & 3;
    switch (weight_34) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_59 = local_arr[aux % 3];
    acc = (acc + threshold_59 * 2) & 127;
    int tracker_92 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_92 > 18) {
        acc = (acc + tracker_92 * 2 + 5) & 127;
        aux ^= (tracker_92 & 15);
    } else {
        acc = (acc - tracker_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_12(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int margin_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_10) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int window_80 = local_arr[aux % 3];
    acc = (acc + window_80 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_63 = (aux + st.buffer[1]) & 3;
    switch (index_reg_63) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_13(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int delta_61 = local_arr[aux % 3];
    acc = (acc + delta_61 * 2) & 127;
    int offset_60 = (aux + st.buffer[1]) & 3;
    switch (offset_60) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_14(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int window_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_67) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_16 = local_arr[aux % 3];
    acc = (acc + damping_16 * 2) & 127;
    int margin_33 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_33 > 16) {
        acc = (acc + margin_33 * 2 + 5) & 127;
        aux ^= (margin_33 & 15);
    } else {
        acc = (acc - margin_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_25 = (aux + st.buffer[1]) & 3;
    switch (offset_25) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_67 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_67 > 29) {
        acc = (acc + margin_67 * 2 + 5) & 127;
        aux ^= (margin_67 & 15);
    } else {
        acc = (acc - margin_67 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_36 = local_arr[aux % 3];
    acc = (acc + damping_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_16(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_60 = local_arr[aux % 3];
    acc = (acc + tally_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_17(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_48 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_48 > 18) {
        acc = (acc + tally_48 * 2 + 5) & 127;
        aux ^= (tally_48 & 15);
    } else {
        acc = (acc - tally_48 + 11) & 127;
        aux += 3;
    }
    int factor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_42) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_18(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int delta_88 = local_arr[aux % 3];
    acc = (acc + delta_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_57) & 63;
    acc ^= aux;
    int index_reg_28 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_28 > 14) {
        acc = (acc + index_reg_28 * 2 + 5) & 127;
        aux ^= (index_reg_28 & 15);
    } else {
        acc = (acc - index_reg_28 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_92 = (aux + st.buffer[1]) & 3;
    switch (sample_92) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_96 = local_arr[aux % 3];
    acc = (acc + index_reg_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000309_913_20(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000309_913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int cursor_81 = local_arr[aux % 3];
    acc = (acc + cursor_81 * 2) & 127;
    int quantum_35 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_35 > 41) {
        acc = (acc + quantum_35 * 2 + 5) & 127;
        aux ^= (quantum_35 & 15);
    } else {
        acc = (acc - quantum_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_21(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000309_913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_52 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_52 > 47) {
        acc = (acc + cursor_52 * 2 + 5) & 127;
        aux ^= (cursor_52 & 15);
    } else {
        acc = (acc - cursor_52 + 11) & 127;
        aux += 3;
    }
    int pivot_67 = (aux + st.buffer[1]) & 3;
    switch (pivot_67) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000309_913_22(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000309_913_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int sample_93 = local_arr[aux % 3];
    acc = (acc + sample_93 * 2) & 127;
    int tracker_15 = (aux + st.buffer[1]) & 3;
    switch (tracker_15) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000309_0;
    int sec_r000309_1;
    int sec_r000309_2;
    int sec_r000309_3;
    int sec_r000309_4;
    int sec_r000309_5;
    int sec_r000309_6;
    int sec_r000309_7;
    int sec_r000309_8;
    int sec_r000309_9;
    int sec_r000309_10;
    int sec_r000309_11;
    int sec_r000309_12;
    int sec_r000309_13;
    int sec_r000309_14;
    int sec_r000309_15;
    int sec_r000309_16;
    int sec_r000309_17;
    int sec_r000309_18;
    int sec_r000309_19;
    int sec_r000309_20;
    int sec_r000309_21;
    int sec_r000309_22;
    int pub_r000309_0;
    int pub_r000309_1;
    int pub_r000309_2;
    int pub_r000309_3;
    int pub_r000309_4;
    int pub_r000309_5;
    int pub_r000309_6;
    int pub_r000309_7;
    int pub_r000309_8;
    int pub_r000309_9;
    int pub_r000309_10;
    int pub_r000309_11;
    int pub_r000309_12;
    int pub_r000309_13;
    int pub_r000309_14;
    int pub_r000309_15;
    int pub_r000309_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000309_0 >= -100 && pub_r000309_0 <= 100);
    __CPROVER_assume(pub_r000309_1 >= -100 && pub_r000309_1 <= 100);
    __CPROVER_assume(pub_r000309_2 >= -100 && pub_r000309_2 <= 100);
    __CPROVER_assume(pub_r000309_3 >= -100 && pub_r000309_3 <= 100);
    __CPROVER_assume(pub_r000309_4 >= -100 && pub_r000309_4 <= 100);
    __CPROVER_assume(pub_r000309_5 >= -100 && pub_r000309_5 <= 100);
    __CPROVER_assume(pub_r000309_6 >= -100 && pub_r000309_6 <= 100);
    __CPROVER_assume(pub_r000309_7 >= -100 && pub_r000309_7 <= 100);
    __CPROVER_assume(pub_r000309_8 >= -100 && pub_r000309_8 <= 100);
    __CPROVER_assume(pub_r000309_9 >= -100 && pub_r000309_9 <= 100);
    __CPROVER_assume(pub_r000309_10 >= -100 && pub_r000309_10 <= 100);
    __CPROVER_assume(pub_r000309_11 >= -100 && pub_r000309_11 <= 100);
    __CPROVER_assume(pub_r000309_12 >= -100 && pub_r000309_12 <= 100);
    __CPROVER_assume(pub_r000309_13 >= -100 && pub_r000309_13 <= 100);
    __CPROVER_assume(pub_r000309_14 >= -100 && pub_r000309_14 <= 100);
    __CPROVER_assume(pub_r000309_15 >= -100 && pub_r000309_15 <= 100);
    __CPROVER_assume(pub_r000309_16 >= -100 && pub_r000309_16 <= 100);
    __CPROVER_assume(sec_r000309_0 >= 0 && sec_r000309_0 <= 255);
    __CPROVER_assume(sec_r000309_1 >= 0 && sec_r000309_1 <= 255);
    __CPROVER_assume(sec_r000309_2 >= 0 && sec_r000309_2 <= 255);
    __CPROVER_assume(sec_r000309_3 >= 0 && sec_r000309_3 <= 255);
    __CPROVER_assume(sec_r000309_4 >= 0 && sec_r000309_4 <= 255);
    __CPROVER_assume(sec_r000309_5 >= 0 && sec_r000309_5 <= 255);
    __CPROVER_assume(sec_r000309_6 >= 0 && sec_r000309_6 <= 255);
    __CPROVER_assume(sec_r000309_7 >= 0 && sec_r000309_7 <= 255);
    __CPROVER_assume(sec_r000309_8 >= 0 && sec_r000309_8 <= 255);
    __CPROVER_assume(sec_r000309_9 >= 0 && sec_r000309_9 <= 255);
    __CPROVER_assume(sec_r000309_10 >= 0 && sec_r000309_10 <= 255);
    __CPROVER_assume(sec_r000309_11 >= 0 && sec_r000309_11 <= 255);
    __CPROVER_assume(sec_r000309_12 >= 0 && sec_r000309_12 <= 255);
    __CPROVER_assume(sec_r000309_13 >= 0 && sec_r000309_13 <= 255);
    __CPROVER_assume(sec_r000309_14 >= 0 && sec_r000309_14 <= 255);
    __CPROVER_assume(sec_r000309_15 >= 0 && sec_r000309_15 <= 255);
    __CPROVER_assume(sec_r000309_16 >= 0 && sec_r000309_16 <= 255);
    __CPROVER_assume(sec_r000309_17 >= 0 && sec_r000309_17 <= 255);
    __CPROVER_assume(sec_r000309_18 >= 0 && sec_r000309_18 <= 255);
    __CPROVER_assume(sec_r000309_19 >= 0 && sec_r000309_19 <= 255);
    __CPROVER_assume(sec_r000309_20 >= 0 && sec_r000309_20 <= 255);
    __CPROVER_assume(sec_r000309_21 >= 0 && sec_r000309_21 <= 255);
    __CPROVER_assume(sec_r000309_22 >= 0 && sec_r000309_22 <= 255);

    struct SensorNode_R000309_913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000309_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000309_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000309_0 + 7) & 15;
    struct CipherContext_R000309_913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000309_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000309_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000309_0 + 9) & 15;
    struct EventLog_R000309_913_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000309_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000309_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000309_0 + 11) & 15;

    union PacketPayload_R000309_913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 39) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 54) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
        case 0:
            out_sink = (out_sink + 4) & 255;
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

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 17) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 32) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 40) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 55) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 31) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 46) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 27) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 42) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 25) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 40) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
        case 0:
            out_sink = (out_sink + 5) & 255;
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 28) & 15;
    int stage_v_27 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= stage_v_27;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int s_idx_37 = (sec_r000309_15 & 3);
    int stage_v_37 = (table[s_idx_37] + pub_r000309_4) & 127;
    table[s_idx_37] = (stage_v_37 + 7) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int s_idx_38 = (sec_r000309_12 & 3);
    int stage_v_38 = (table[s_idx_38] + pub_r000309_4) & 127;
    table[s_idx_38] = (stage_v_38 + 7) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int s_idx_39 = (stage_v_38 & 3);
    int stage_v_39 = (table[s_idx_39] + pub_r000309_8) & 127;
    table[s_idx_39] = (stage_v_39 + 7) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int s_idx_40 = (sec_r000309_4 & 3);
    int stage_v_40 = (table[s_idx_40] + pub_r000309_13) & 127;
    table[s_idx_40] = (stage_v_40 + 7) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int s_idx_41 = (stage_v_39 & 3);
    int stage_v_41 = (table[s_idx_41] + pub_r000309_10) & 127;
    table[s_idx_41] = (stage_v_41 + 7) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int s_idx_42 = (stage_v_37 & 3);
    int stage_v_42 = (table[s_idx_42] + pub_r000309_8) & 127;
    table[s_idx_42] = (stage_v_42 + 7) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int s_idx_43 = (stage_v_38 & 3);
    int stage_v_43 = (table[s_idx_43] + pub_r000309_15) & 127;
    table[s_idx_43] = (stage_v_43 + 7) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int s_idx_44 = (stage_v_40 & 3);
    int stage_v_44 = (table[s_idx_44] + pub_r000309_6) & 127;
    table[s_idx_44] = (stage_v_44 + 7) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int s_idx_45 = (sec_r000309_2 & 3);
    int stage_v_45 = (table[s_idx_45] + pub_r000309_13) & 127;
    table[s_idx_45] = (stage_v_45 + 7) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int s_idx_46 = (sec_r000309_14 & 3);
    int stage_v_46 = (table[s_idx_46] + pub_r000309_1) & 127;
    table[s_idx_46] = (stage_v_46 + 7) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int s_idx_47 = (stage_v_39 & 3);
    int stage_v_47 = (table[s_idx_47] + pub_r000309_7) & 127;
    table[s_idx_47] = (stage_v_47 + 7) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int s_idx_48 = (stage_v_45 & 3);
    int stage_v_48 = (table[s_idx_48] + pub_r000309_13) & 127;
    table[s_idx_48] = (stage_v_48 + 7) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int s_idx_49 = (stage_v_39 & 3);
    int stage_v_49 = (table[s_idx_49] + pub_r000309_0) & 127;
    table[s_idx_49] = (stage_v_49 + 7) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int s_idx_50 = (stage_v_37 & 3);
    int stage_v_50 = (table[s_idx_50] + pub_r000309_8) & 127;
    table[s_idx_50] = (stage_v_50 + 7) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int s_idx_51 = (stage_v_46 & 3);
    int stage_v_51 = (table[s_idx_51] + pub_r000309_4) & 127;
    table[s_idx_51] = (stage_v_51 + 7) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int s_idx_52 = (sec_r000309_5 & 3);
    int stage_v_52 = (table[s_idx_52] + pub_r000309_14) & 127;
    table[s_idx_52] = (stage_v_52 + 7) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int s_idx_53 = (stage_v_40 & 3);
    int stage_v_53 = (table[s_idx_53] + pub_r000309_11) & 127;
    table[s_idx_53] = (stage_v_53 + 7) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int s_idx_54 = (stage_v_53 & 3);
    int stage_v_54 = (table[s_idx_54] + pub_r000309_16) & 127;
    table[s_idx_54] = (stage_v_54 + 7) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int s_idx_55 = (stage_v_38 & 3);
    int stage_v_55 = (table[s_idx_55] + pub_r000309_13) & 127;
    table[s_idx_55] = (stage_v_55 + 7) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int s_idx_56 = (sec_r000309_12 & 3);
    int stage_v_56 = (table[s_idx_56] + pub_r000309_4) & 127;
    table[s_idx_56] = (stage_v_56 + 7) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int s_idx_57 = (stage_v_45 & 3);
    int stage_v_57 = (table[s_idx_57] + pub_r000309_16) & 127;
    table[s_idx_57] = (stage_v_57 + 7) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int s_idx_58 = (stage_v_55 & 3);
    int stage_v_58 = (table[s_idx_58] + pub_r000309_2) & 127;
    table[s_idx_58] = (stage_v_58 + 7) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int s_idx_59 = (stage_v_45 & 3);
    int stage_v_59 = (table[s_idx_59] + pub_r000309_5) & 127;
    table[s_idx_59] = (stage_v_59 + 7) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int s_idx_60 = (stage_v_37 & 3);
    int stage_v_60 = (table[s_idx_60] + pub_r000309_7) & 127;
    table[s_idx_60] = (stage_v_60 + 7) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int s_idx_61 = (stage_v_51 & 3);
    int stage_v_61 = (table[s_idx_61] + pub_r000309_7) & 127;
    table[s_idx_61] = (stage_v_61 + 7) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int s_idx_62 = (stage_v_39 & 3);
    int stage_v_62 = (table[s_idx_62] + pub_r000309_0) & 127;
    table[s_idx_62] = (stage_v_62 + 7) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int s_idx_63 = (sec_r000309_5 & 3);
    int stage_v_63 = (table[s_idx_63] + pub_r000309_3) & 127;
    table[s_idx_63] = (stage_v_63 + 7) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int s_idx_64 = (sec_r000309_14 & 3);
    int stage_v_64 = (table[s_idx_64] + pub_r000309_1) & 127;
    table[s_idx_64] = (stage_v_64 + 7) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int s_idx_65 = (sec_r000309_2 & 3);
    int stage_v_65 = (table[s_idx_65] + pub_r000309_5) & 127;
    table[s_idx_65] = (stage_v_65 + 7) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int s_idx_66 = (stage_v_38 & 3);
    int stage_v_66 = (table[s_idx_66] + pub_r000309_11) & 127;
    table[s_idx_66] = (stage_v_66 + 7) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int s_idx_67 = (stage_v_49 & 3);
    int stage_v_67 = (table[s_idx_67] + pub_r000309_15) & 127;
    table[s_idx_67] = (stage_v_67 + 7) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int s_idx_68 = (stage_v_37 & 3);
    int stage_v_68 = (table[s_idx_68] + pub_r000309_15) & 127;
    table[s_idx_68] = (stage_v_68 + 7) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int s_idx_69 = (stage_v_58 & 3);
    int stage_v_69 = (table[s_idx_69] + pub_r000309_15) & 127;
    table[s_idx_69] = (stage_v_69 + 7) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int s_idx_70 = (sec_r000309_3 & 3);
    int stage_v_70 = (table[s_idx_70] + pub_r000309_11) & 127;
    table[s_idx_70] = (stage_v_70 + 7) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int s_idx_71 = (stage_v_43 & 3);
    int stage_v_71 = (table[s_idx_71] + pub_r000309_4) & 127;
    table[s_idx_71] = (stage_v_71 + 7) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int s_idx_72 = (stage_v_42 & 3);
    int stage_v_72 = (table[s_idx_72] + pub_r000309_6) & 127;
    table[s_idx_72] = (stage_v_72 + 7) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int s_idx_73 = (stage_v_61 & 3);
    int stage_v_73 = (table[s_idx_73] + pub_r000309_16) & 127;
    table[s_idx_73] = (stage_v_73 + 7) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int s_idx_74 = (stage_v_63 & 3);
    int stage_v_74 = (table[s_idx_74] + pub_r000309_14) & 127;
    table[s_idx_74] = (stage_v_74 + 7) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int s_idx_75 = (stage_v_62 & 3);
    int stage_v_75 = (table[s_idx_75] + pub_r000309_9) & 127;
    table[s_idx_75] = (stage_v_75 + 7) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int s_idx_76 = (stage_v_54 & 3);
    int stage_v_76 = (table[s_idx_76] + pub_r000309_4) & 127;
    table[s_idx_76] = (stage_v_76 + 7) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int s_idx_77 = (stage_v_52 & 3);
    int stage_v_77 = (table[s_idx_77] + pub_r000309_9) & 127;
    table[s_idx_77] = (stage_v_77 + 7) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int s_idx_78 = (stage_v_38 & 3);
    int stage_v_78 = (table[s_idx_78] + pub_r000309_13) & 127;
    table[s_idx_78] = (stage_v_78 + 7) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int s_idx_79 = (stage_v_37 & 3);
    int stage_v_79 = (table[s_idx_79] + pub_r000309_10) & 127;
    table[s_idx_79] = (stage_v_79 + 7) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int s_idx_80 = (stage_v_70 & 3);
    int stage_v_80 = (table[s_idx_80] + pub_r000309_5) & 127;
    table[s_idx_80] = (stage_v_80 + 7) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int s_idx_81 = (stage_v_72 & 3);
    int stage_v_81 = (table[s_idx_81] + pub_r000309_9) & 127;
    table[s_idx_81] = (stage_v_81 + 7) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int s_idx_82 = (sec_r000309_10 & 3);
    int stage_v_82 = (table[s_idx_82] + pub_r000309_9) & 127;
    table[s_idx_82] = (stage_v_82 + 7) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int s_idx_83 = (sec_r000309_16 & 3);
    int stage_v_83 = (table[s_idx_83] + pub_r000309_4) & 127;
    table[s_idx_83] = (stage_v_83 + 7) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int s_idx_84 = (stage_v_39 & 3);
    int stage_v_84 = (table[s_idx_84] + pub_r000309_13) & 127;
    table[s_idx_84] = (stage_v_84 + 7) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int s_idx_85 = (stage_v_45 & 3);
    int stage_v_85 = (table[s_idx_85] + pub_r000309_8) & 127;
    table[s_idx_85] = (stage_v_85 + 7) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int s_idx_86 = (stage_v_85 & 3);
    int stage_v_86 = (table[s_idx_86] + pub_r000309_5) & 127;
    table[s_idx_86] = (stage_v_86 + 7) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int s_idx_87 = (stage_v_76 & 3);
    int stage_v_87 = (table[s_idx_87] + pub_r000309_0) & 127;
    table[s_idx_87] = (stage_v_87 + 7) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int s_idx_88 = (stage_v_61 & 3);
    int stage_v_88 = (table[s_idx_88] + pub_r000309_9) & 127;
    table[s_idx_88] = (stage_v_88 + 7) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int s_idx_89 = (sec_r000309_21 & 3);
    int stage_v_89 = (table[s_idx_89] + pub_r000309_4) & 127;
    table[s_idx_89] = (stage_v_89 + 7) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int s_idx_90 = (sec_r000309_2 & 3);
    int stage_v_90 = (table[s_idx_90] + pub_r000309_4) & 127;
    table[s_idx_90] = (stage_v_90 + 7) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int s_idx_91 = (stage_v_51 & 3);
    int stage_v_91 = (table[s_idx_91] + pub_r000309_1) & 127;
    table[s_idx_91] = (stage_v_91 + 7) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int s_idx_92 = (sec_r000309_17 & 3);
    int stage_v_92 = (table[s_idx_92] + pub_r000309_0) & 127;
    table[s_idx_92] = (stage_v_92 + 7) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int s_idx_93 = (stage_v_75 & 3);
    int stage_v_93 = (table[s_idx_93] + pub_r000309_3) & 127;
    table[s_idx_93] = (stage_v_93 + 7) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int s_idx_94 = (stage_v_88 & 3);
    int stage_v_94 = (table[s_idx_94] + pub_r000309_16) & 127;
    table[s_idx_94] = (stage_v_94 + 7) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int s_idx_95 = (stage_v_91 & 3);
    int stage_v_95 = (table[s_idx_95] + pub_r000309_15) & 127;
    table[s_idx_95] = (stage_v_95 + 7) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int s_idx_96 = (stage_v_52 & 3);
    int stage_v_96 = (table[s_idx_96] + pub_r000309_6) & 127;
    table[s_idx_96] = (stage_v_96 + 7) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int s_idx_97 = (stage_v_70 & 3);
    int stage_v_97 = (table[s_idx_97] + pub_r000309_2) & 127;
    table[s_idx_97] = (stage_v_97 + 7) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int s_idx_98 = (sec_r000309_19 & 3);
    int stage_v_98 = (table[s_idx_98] + pub_r000309_5) & 127;
    table[s_idx_98] = (stage_v_98 + 7) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int s_idx_99 = (stage_v_42 & 3);
    int stage_v_99 = (table[s_idx_99] + pub_r000309_15) & 127;
    table[s_idx_99] = (stage_v_99 + 7) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int s_idx_100 = (stage_v_44 & 3);
    int stage_v_100 = (table[s_idx_100] + pub_r000309_7) & 127;
    table[s_idx_100] = (stage_v_100 + 7) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int s_idx_101 = (stage_v_61 & 3);
    int stage_v_101 = (table[s_idx_101] + pub_r000309_4) & 127;
    table[s_idx_101] = (stage_v_101 + 7) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int s_idx_102 = (stage_v_69 & 3);
    int stage_v_102 = (table[s_idx_102] + pub_r000309_8) & 127;
    table[s_idx_102] = (stage_v_102 + 7) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int s_idx_103 = (stage_v_94 & 3);
    int stage_v_103 = (table[s_idx_103] + pub_r000309_7) & 127;
    table[s_idx_103] = (stage_v_103 + 7) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int s_idx_104 = (sec_r000309_11 & 3);
    int stage_v_104 = (table[s_idx_104] + pub_r000309_16) & 127;
    table[s_idx_104] = (stage_v_104 + 7) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int s_idx_105 = (sec_r000309_15 & 3);
    int stage_v_105 = (table[s_idx_105] + pub_r000309_10) & 127;
    table[s_idx_105] = (stage_v_105 + 7) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int s_idx_106 = (stage_v_53 & 3);
    int stage_v_106 = (table[s_idx_106] + pub_r000309_4) & 127;
    table[s_idx_106] = (stage_v_106 + 7) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int s_idx_107 = (stage_v_48 & 3);
    int stage_v_107 = (table[s_idx_107] + pub_r000309_10) & 127;
    table[s_idx_107] = (stage_v_107 + 7) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int s_idx_108 = (stage_v_105 & 3);
    int stage_v_108 = (table[s_idx_108] + pub_r000309_10) & 127;
    table[s_idx_108] = (stage_v_108 + 7) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int s_idx_109 = (sec_r000309_9 & 3);
    int stage_v_109 = (table[s_idx_109] + pub_r000309_11) & 127;
    table[s_idx_109] = (stage_v_109 + 7) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int s_idx_110 = (sec_r000309_7 & 3);
    int stage_v_110 = (table[s_idx_110] + pub_r000309_4) & 127;
    table[s_idx_110] = (stage_v_110 + 7) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int s_idx_111 = (stage_v_41 & 3);
    int stage_v_111 = (table[s_idx_111] + pub_r000309_3) & 127;
    table[s_idx_111] = (stage_v_111 + 7) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int s_idx_112 = (stage_v_53 & 3);
    int stage_v_112 = (table[s_idx_112] + pub_r000309_9) & 127;
    table[s_idx_112] = (stage_v_112 + 7) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int s_idx_113 = (sec_r000309_4 & 3);
    int stage_v_113 = (table[s_idx_113] + pub_r000309_16) & 127;
    table[s_idx_113] = (stage_v_113 + 7) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int s_idx_114 = (stage_v_100 & 3);
    int stage_v_114 = (table[s_idx_114] + pub_r000309_15) & 127;
    table[s_idx_114] = (stage_v_114 + 7) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int s_idx_115 = (stage_v_67 & 3);
    int stage_v_115 = (table[s_idx_115] + pub_r000309_1) & 127;
    table[s_idx_115] = (stage_v_115 + 7) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int s_idx_116 = (sec_r000309_12 & 3);
    int stage_v_116 = (table[s_idx_116] + pub_r000309_4) & 127;
    table[s_idx_116] = (stage_v_116 + 7) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int s_idx_117 = (stage_v_51 & 3);
    int stage_v_117 = (table[s_idx_117] + pub_r000309_5) & 127;
    table[s_idx_117] = (stage_v_117 + 7) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int s_idx_118 = (stage_v_70 & 3);
    int stage_v_118 = (table[s_idx_118] + pub_r000309_3) & 127;
    table[s_idx_118] = (stage_v_118 + 7) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int s_idx_119 = (stage_v_43 & 3);
    int stage_v_119 = (table[s_idx_119] + pub_r000309_15) & 127;
    table[s_idx_119] = (stage_v_119 + 7) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int s_idx_120 = (stage_v_100 & 3);
    int stage_v_120 = (table[s_idx_120] + pub_r000309_6) & 127;
    table[s_idx_120] = (stage_v_120 + 7) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int s_idx_121 = (stage_v_100 & 3);
    int stage_v_121 = (table[s_idx_121] + pub_r000309_0) & 127;
    table[s_idx_121] = (stage_v_121 + 7) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int s_idx_122 = (stage_v_45 & 3);
    int stage_v_122 = (table[s_idx_122] + pub_r000309_1) & 127;
    table[s_idx_122] = (stage_v_122 + 7) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int s_idx_123 = (stage_v_74 & 3);
    int stage_v_123 = (table[s_idx_123] + pub_r000309_8) & 127;
    table[s_idx_123] = (stage_v_123 + 7) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int s_idx_124 = (sec_r000309_12 & 3);
    int stage_v_124 = (table[s_idx_124] + pub_r000309_11) & 127;
    table[s_idx_124] = (stage_v_124 + 7) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int s_idx_125 = (stage_v_75 & 3);
    int stage_v_125 = (table[s_idx_125] + pub_r000309_1) & 127;
    table[s_idx_125] = (stage_v_125 + 7) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int s_idx_126 = (sec_r000309_11 & 3);
    int stage_v_126 = (table[s_idx_126] + pub_r000309_16) & 127;
    table[s_idx_126] = (stage_v_126 + 7) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int s_idx_127 = (stage_v_46 & 3);
    int stage_v_127 = (table[s_idx_127] + pub_r000309_8) & 127;
    table[s_idx_127] = (stage_v_127 + 7) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int s_idx_128 = (stage_v_65 & 3);
    int stage_v_128 = (table[s_idx_128] + pub_r000309_2) & 127;
    table[s_idx_128] = (stage_v_128 + 7) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int s_idx_129 = (stage_v_112 & 3);
    int stage_v_129 = (table[s_idx_129] + pub_r000309_1) & 127;
    table[s_idx_129] = (stage_v_129 + 7) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int s_idx_130 = (stage_v_121 & 3);
    int stage_v_130 = (table[s_idx_130] + pub_r000309_12) & 127;
    table[s_idx_130] = (stage_v_130 + 7) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int s_idx_131 = (sec_r000309_20 & 3);
    int stage_v_131 = (table[s_idx_131] + pub_r000309_8) & 127;
    table[s_idx_131] = (stage_v_131 + 7) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int s_idx_132 = (stage_v_56 & 3);
    int stage_v_132 = (table[s_idx_132] + pub_r000309_9) & 127;
    table[s_idx_132] = (stage_v_132 + 7) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int s_idx_133 = (sec_r000309_2 & 3);
    int stage_v_133 = (table[s_idx_133] + pub_r000309_1) & 127;
    table[s_idx_133] = (stage_v_133 + 7) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int s_idx_134 = (sec_r000309_15 & 3);
    int stage_v_134 = (table[s_idx_134] + pub_r000309_7) & 127;
    table[s_idx_134] = (stage_v_134 + 7) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int s_idx_135 = (stage_v_129 & 3);
    int stage_v_135 = (table[s_idx_135] + pub_r000309_2) & 127;
    table[s_idx_135] = (stage_v_135 + 7) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int s_idx_136 = (stage_v_52 & 3);
    int stage_v_136 = (table[s_idx_136] + pub_r000309_7) & 127;
    table[s_idx_136] = (stage_v_136 + 7) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int s_idx_137 = (stage_v_68 & 3);
    int stage_v_137 = (table[s_idx_137] + pub_r000309_9) & 127;
    table[s_idx_137] = (stage_v_137 + 7) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int s_idx_138 = (sec_r000309_0 & 3);
    int stage_v_138 = (table[s_idx_138] + pub_r000309_12) & 127;
    table[s_idx_138] = (stage_v_138 + 7) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int s_idx_139 = (stage_v_80 & 3);
    int stage_v_139 = (table[s_idx_139] + pub_r000309_13) & 127;
    table[s_idx_139] = (stage_v_139 + 7) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int s_idx_140 = (stage_v_136 & 3);
    int stage_v_140 = (table[s_idx_140] + pub_r000309_9) & 127;
    table[s_idx_140] = (stage_v_140 + 7) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int s_idx_141 = (stage_v_133 & 3);
    int stage_v_141 = (table[s_idx_141] + pub_r000309_9) & 127;
    table[s_idx_141] = (stage_v_141 + 7) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int s_idx_142 = (stage_v_88 & 3);
    int stage_v_142 = (table[s_idx_142] + pub_r000309_0) & 127;
    table[s_idx_142] = (stage_v_142 + 7) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int s_idx_143 = (sec_r000309_10 & 3);
    int stage_v_143 = (table[s_idx_143] + pub_r000309_14) & 127;
    table[s_idx_143] = (stage_v_143 + 7) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int s_idx_144 = (sec_r000309_6 & 3);
    int stage_v_144 = (table[s_idx_144] + pub_r000309_14) & 127;
    table[s_idx_144] = (stage_v_144 + 7) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int s_idx_145 = (stage_v_142 & 3);
    int stage_v_145 = (table[s_idx_145] + pub_r000309_13) & 127;
    table[s_idx_145] = (stage_v_145 + 7) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int s_idx_146 = (stage_v_103 & 3);
    int stage_v_146 = (table[s_idx_146] + pub_r000309_14) & 127;
    table[s_idx_146] = (stage_v_146 + 7) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int s_idx_147 = (sec_r000309_10 & 3);
    int stage_v_147 = (table[s_idx_147] + pub_r000309_16) & 127;
    table[s_idx_147] = (stage_v_147 + 7) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int s_idx_148 = (stage_v_112 & 3);
    int stage_v_148 = (table[s_idx_148] + pub_r000309_5) & 127;
    table[s_idx_148] = (stage_v_148 + 7) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int s_idx_149 = (sec_r000309_5 & 3);
    int stage_v_149 = (table[s_idx_149] + pub_r000309_10) & 127;
    table[s_idx_149] = (stage_v_149 + 7) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int s_idx_150 = (stage_v_68 & 3);
    int stage_v_150 = (table[s_idx_150] + pub_r000309_1) & 127;
    table[s_idx_150] = (stage_v_150 + 7) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int s_idx_151 = (stage_v_72 & 3);
    int stage_v_151 = (table[s_idx_151] + pub_r000309_11) & 127;
    table[s_idx_151] = (stage_v_151 + 7) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int s_idx_152 = (stage_v_121 & 3);
    int stage_v_152 = (table[s_idx_152] + pub_r000309_16) & 127;
    table[s_idx_152] = (stage_v_152 + 7) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int s_idx_153 = (sec_r000309_19 & 3);
    int stage_v_153 = (table[s_idx_153] + pub_r000309_8) & 127;
    table[s_idx_153] = (stage_v_153 + 7) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int s_idx_154 = (sec_r000309_17 & 3);
    int stage_v_154 = (table[s_idx_154] + pub_r000309_10) & 127;
    table[s_idx_154] = (stage_v_154 + 7) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int s_idx_155 = (stage_v_151 & 3);
    int stage_v_155 = (table[s_idx_155] + pub_r000309_1) & 127;
    table[s_idx_155] = (stage_v_155 + 7) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int s_idx_156 = (stage_v_139 & 3);
    int stage_v_156 = (table[s_idx_156] + pub_r000309_4) & 127;
    table[s_idx_156] = (stage_v_156 + 7) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int s_idx_157 = (sec_r000309_9 & 3);
    int stage_v_157 = (table[s_idx_157] + pub_r000309_13) & 127;
    table[s_idx_157] = (stage_v_157 + 7) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int s_idx_158 = (sec_r000309_2 & 3);
    int stage_v_158 = (table[s_idx_158] + pub_r000309_13) & 127;
    table[s_idx_158] = (stage_v_158 + 7) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int s_idx_159 = (stage_v_153 & 3);
    int stage_v_159 = (table[s_idx_159] + pub_r000309_4) & 127;
    table[s_idx_159] = (stage_v_159 + 7) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int s_idx_160 = (stage_v_100 & 3);
    int stage_v_160 = (table[s_idx_160] + pub_r000309_5) & 127;
    table[s_idx_160] = (stage_v_160 + 7) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int s_idx_161 = (stage_v_133 & 3);
    int stage_v_161 = (table[s_idx_161] + pub_r000309_5) & 127;
    table[s_idx_161] = (stage_v_161 + 7) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int s_idx_162 = (stage_v_75 & 3);
    int stage_v_162 = (table[s_idx_162] + pub_r000309_1) & 127;
    table[s_idx_162] = (stage_v_162 + 7) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int s_idx_163 = (stage_v_123 & 3);
    int stage_v_163 = (table[s_idx_163] + pub_r000309_9) & 127;
    table[s_idx_163] = (stage_v_163 + 7) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int s_idx_164 = (sec_r000309_11 & 3);
    int stage_v_164 = (table[s_idx_164] + pub_r000309_1) & 127;
    table[s_idx_164] = (stage_v_164 + 7) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int s_idx_165 = (stage_v_112 & 3);
    int stage_v_165 = (table[s_idx_165] + pub_r000309_4) & 127;
    table[s_idx_165] = (stage_v_165 + 7) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int s_idx_166 = (stage_v_80 & 3);
    int stage_v_166 = (table[s_idx_166] + pub_r000309_13) & 127;
    table[s_idx_166] = (stage_v_166 + 7) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int s_idx_167 = (stage_v_91 & 3);
    int stage_v_167 = (table[s_idx_167] + pub_r000309_1) & 127;
    table[s_idx_167] = (stage_v_167 + 7) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int s_idx_168 = (stage_v_87 & 3);
    int stage_v_168 = (table[s_idx_168] + pub_r000309_12) & 127;
    table[s_idx_168] = (stage_v_168 + 7) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int s_idx_169 = (stage_v_146 & 3);
    int stage_v_169 = (table[s_idx_169] + pub_r000309_14) & 127;
    table[s_idx_169] = (stage_v_169 + 7) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int s_idx_170 = (sec_r000309_6 & 3);
    int stage_v_170 = (table[s_idx_170] + pub_r000309_0) & 127;
    table[s_idx_170] = (stage_v_170 + 7) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int s_idx_171 = (stage_v_106 & 3);
    int stage_v_171 = (table[s_idx_171] + pub_r000309_0) & 127;
    table[s_idx_171] = (stage_v_171 + 7) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int s_idx_172 = (sec_r000309_0 & 3);
    int stage_v_172 = (table[s_idx_172] + pub_r000309_0) & 127;
    table[s_idx_172] = (stage_v_172 + 7) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int s_idx_173 = (stage_v_80 & 3);
    int stage_v_173 = (table[s_idx_173] + pub_r000309_8) & 127;
    table[s_idx_173] = (stage_v_173 + 7) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int s_idx_174 = (sec_r000309_10 & 3);
    int stage_v_174 = (table[s_idx_174] + pub_r000309_9) & 127;
    table[s_idx_174] = (stage_v_174 + 7) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int s_idx_175 = (sec_r000309_15 & 3);
    int stage_v_175 = (table[s_idx_175] + pub_r000309_12) & 127;
    table[s_idx_175] = (stage_v_175 + 7) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int s_idx_176 = (sec_r000309_4 & 3);
    int stage_v_176 = (table[s_idx_176] + pub_r000309_10) & 127;
    table[s_idx_176] = (stage_v_176 + 7) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int s_idx_177 = (stage_v_97 & 3);
    int stage_v_177 = (table[s_idx_177] + pub_r000309_11) & 127;
    table[s_idx_177] = (stage_v_177 + 7) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int s_idx_178 = (sec_r000309_2 & 3);
    int stage_v_178 = (table[s_idx_178] + pub_r000309_14) & 127;
    table[s_idx_178] = (stage_v_178 + 7) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int s_idx_179 = (stage_v_122 & 3);
    int stage_v_179 = (table[s_idx_179] + pub_r000309_1) & 127;
    table[s_idx_179] = (stage_v_179 + 7) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int s_idx_180 = (stage_v_169 & 3);
    int stage_v_180 = (table[s_idx_180] + pub_r000309_11) & 127;
    table[s_idx_180] = (stage_v_180 + 7) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int s_idx_181 = (stage_v_101 & 3);
    int stage_v_181 = (table[s_idx_181] + pub_r000309_4) & 127;
    table[s_idx_181] = (stage_v_181 + 7) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int s_idx_182 = (sec_r000309_14 & 3);
    int stage_v_182 = (table[s_idx_182] + pub_r000309_5) & 127;
    table[s_idx_182] = (stage_v_182 + 7) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int s_idx_183 = (stage_v_132 & 3);
    int stage_v_183 = (table[s_idx_183] + pub_r000309_13) & 127;
    table[s_idx_183] = (stage_v_183 + 7) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int s_idx_184 = (sec_r000309_15 & 3);
    int stage_v_184 = (table[s_idx_184] + pub_r000309_11) & 127;
    table[s_idx_184] = (stage_v_184 + 7) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int s_idx_185 = (sec_r000309_3 & 3);
    int stage_v_185 = (table[s_idx_185] + pub_r000309_4) & 127;
    table[s_idx_185] = (stage_v_185 + 7) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int s_idx_186 = (stage_v_128 & 3);
    int stage_v_186 = (table[s_idx_186] + pub_r000309_11) & 127;
    table[s_idx_186] = (stage_v_186 + 7) & 63;
    out_sink = (out_sink + stage_v_186) & 255;
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int s_idx_187 = (sec_r000309_2 & 3);
    int stage_v_187 = (table[s_idx_187] + pub_r000309_0) & 127;
    table[s_idx_187] = (stage_v_187 + 7) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int s_idx_188 = (stage_v_80 & 3);
    int stage_v_188 = (table[s_idx_188] + pub_r000309_10) & 127;
    table[s_idx_188] = (stage_v_188 + 7) & 63;
    out_sink = (out_sink + stage_v_188) & 255;
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int s_idx_189 = (sec_r000309_2 & 3);
    int stage_v_189 = (table[s_idx_189] + pub_r000309_6) & 127;
    table[s_idx_189] = (stage_v_189 + 7) & 63;
    out_sink = (out_sink + stage_v_189) & 255;
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int s_idx_190 = (stage_v_162 & 3);
    int stage_v_190 = (table[s_idx_190] + pub_r000309_11) & 127;
    table[s_idx_190] = (stage_v_190 + 7) & 63;
    out_sink = (out_sink + stage_v_190) & 255;
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int s_idx_191 = (stage_v_157 & 3);
    int stage_v_191 = (table[s_idx_191] + pub_r000309_9) & 127;
    table[s_idx_191] = (stage_v_191 + 7) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int s_idx_192 = (sec_r000309_20 & 3);
    int stage_v_192 = (table[s_idx_192] + pub_r000309_2) & 127;
    table[s_idx_192] = (stage_v_192 + 7) & 63;
    out_sink = (out_sink + stage_v_192) & 255;
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int s_idx_193 = (stage_v_113 & 3);
    int stage_v_193 = (table[s_idx_193] + pub_r000309_1) & 127;
    table[s_idx_193] = (stage_v_193 + 7) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int s_idx_194 = (stage_v_44 & 3);
    int stage_v_194 = (table[s_idx_194] + pub_r000309_5) & 127;
    table[s_idx_194] = (stage_v_194 + 7) & 63;
    out_sink = (out_sink + stage_v_194) & 255;
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int s_idx_195 = (stage_v_91 & 3);
    int stage_v_195 = (table[s_idx_195] + pub_r000309_5) & 127;
    table[s_idx_195] = (stage_v_195 + 7) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int s_idx_196 = (stage_v_168 & 3);
    int stage_v_196 = (table[s_idx_196] + pub_r000309_5) & 127;
    table[s_idx_196] = (stage_v_196 + 7) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int s_idx_197 = (sec_r000309_8 & 3);
    int stage_v_197 = (table[s_idx_197] + pub_r000309_0) & 127;
    table[s_idx_197] = (stage_v_197 + 7) & 63;
    out_sink = (out_sink + stage_v_197) & 255;
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int s_idx_198 = (stage_v_123 & 3);
    int stage_v_198 = (table[s_idx_198] + pub_r000309_7) & 127;
    table[s_idx_198] = (stage_v_198 + 7) & 63;
    out_sink = (out_sink + stage_v_198) & 255;
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int s_idx_199 = (stage_v_55 & 3);
    int stage_v_199 = (table[s_idx_199] + pub_r000309_14) & 127;
    table[s_idx_199] = (stage_v_199 + 7) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int s_idx_200 = (stage_v_49 & 3);
    int stage_v_200 = (table[s_idx_200] + pub_r000309_15) & 127;
    table[s_idx_200] = (stage_v_200 + 7) & 63;
    out_sink = (out_sink + stage_v_200) & 255;
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int s_idx_201 = (sec_r000309_11 & 3);
    int stage_v_201 = (table[s_idx_201] + pub_r000309_3) & 127;
    table[s_idx_201] = (stage_v_201 + 7) & 63;
    out_sink = (out_sink + stage_v_201) & 255;
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int s_idx_202 = (stage_v_90 & 3);
    int stage_v_202 = (table[s_idx_202] + pub_r000309_9) & 127;
    table[s_idx_202] = (stage_v_202 + 7) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int s_idx_203 = (stage_v_201 & 3);
    int stage_v_203 = (table[s_idx_203] + pub_r000309_7) & 127;
    table[s_idx_203] = (stage_v_203 + 7) & 63;
    out_sink = (out_sink + stage_v_203) & 255;
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int s_idx_204 = (stage_v_115 & 3);
    int stage_v_204 = (table[s_idx_204] + pub_r000309_4) & 127;
    table[s_idx_204] = (stage_v_204 + 7) & 63;
    out_sink = (out_sink + stage_v_204) & 255;
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int s_idx_205 = (stage_v_201 & 3);
    int stage_v_205 = (table[s_idx_205] + pub_r000309_10) & 127;
    table[s_idx_205] = (stage_v_205 + 7) & 63;
    out_sink = (out_sink + stage_v_205) & 255;
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int s_idx_206 = (stage_v_161 & 3);
    int stage_v_206 = (table[s_idx_206] + pub_r000309_12) & 127;
    table[s_idx_206] = (stage_v_206 + 7) & 63;
    out_sink = (out_sink + stage_v_206) & 255;
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int s_idx_207 = (stage_v_198 & 3);
    int stage_v_207 = (table[s_idx_207] + pub_r000309_9) & 127;
    table[s_idx_207] = (stage_v_207 + 7) & 63;
    out_sink = (out_sink + stage_v_207) & 255;
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int s_idx_208 = (stage_v_82 & 3);
    int stage_v_208 = (table[s_idx_208] + pub_r000309_16) & 127;
    table[s_idx_208] = (stage_v_208 + 7) & 63;
    out_sink = (out_sink + stage_v_208) & 255;
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int s_idx_209 = (sec_r000309_16 & 3);
    int stage_v_209 = (table[s_idx_209] + pub_r000309_9) & 127;
    table[s_idx_209] = (stage_v_209 + 7) & 63;
    out_sink = (out_sink + stage_v_209) & 255;
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int s_idx_210 = (stage_v_171 & 3);
    int stage_v_210 = (table[s_idx_210] + pub_r000309_16) & 127;
    table[s_idx_210] = (stage_v_210 + 7) & 63;
    out_sink = (out_sink + stage_v_210) & 255;
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int s_idx_211 = (stage_v_61 & 3);
    int stage_v_211 = (table[s_idx_211] + pub_r000309_15) & 127;
    table[s_idx_211] = (stage_v_211 + 7) & 63;
    out_sink = (out_sink + stage_v_211) & 255;
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int s_idx_212 = (stage_v_171 & 3);
    int stage_v_212 = (table[s_idx_212] + pub_r000309_6) & 127;
    table[s_idx_212] = (stage_v_212 + 7) & 63;
    out_sink = (out_sink + stage_v_212) & 255;
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int s_idx_213 = (stage_v_52 & 3);
    int stage_v_213 = (table[s_idx_213] + pub_r000309_16) & 127;
    table[s_idx_213] = (stage_v_213 + 7) & 63;
    out_sink = (out_sink + stage_v_213) & 255;
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int s_idx_214 = (stage_v_187 & 3);
    int stage_v_214 = (table[s_idx_214] + pub_r000309_5) & 127;
    table[s_idx_214] = (stage_v_214 + 7) & 63;
    out_sink = (out_sink + stage_v_214) & 255;
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int s_idx_215 = (stage_v_155 & 3);
    int stage_v_215 = (table[s_idx_215] + pub_r000309_12) & 127;
    table[s_idx_215] = (stage_v_215 + 7) & 63;
    out_sink = (out_sink + stage_v_215) & 255;
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int s_idx_216 = (stage_v_105 & 3);
    int stage_v_216 = (table[s_idx_216] + pub_r000309_10) & 127;
    table[s_idx_216] = (stage_v_216 + 7) & 63;
    out_sink = (out_sink + stage_v_216) & 255;
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int s_idx_217 = (stage_v_202 & 3);
    int stage_v_217 = (table[s_idx_217] + pub_r000309_10) & 127;
    table[s_idx_217] = (stage_v_217 + 7) & 63;
    out_sink = (out_sink + stage_v_217) & 255;
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int s_idx_218 = (stage_v_130 & 3);
    int stage_v_218 = (table[s_idx_218] + pub_r000309_1) & 127;
    table[s_idx_218] = (stage_v_218 + 7) & 63;
    out_sink = (out_sink + stage_v_218) & 255;
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int s_idx_219 = (stage_v_106 & 3);
    int stage_v_219 = (table[s_idx_219] + pub_r000309_12) & 127;
    table[s_idx_219] = (stage_v_219 + 7) & 63;
    out_sink = (out_sink + stage_v_219) & 255;
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int s_idx_220 = (sec_r000309_12 & 3);
    int stage_v_220 = (table[s_idx_220] + pub_r000309_15) & 127;
    table[s_idx_220] = (stage_v_220 + 7) & 63;
    out_sink = (out_sink + stage_v_220) & 255;
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int s_idx_221 = (sec_r000309_2 & 3);
    int stage_v_221 = (table[s_idx_221] + pub_r000309_1) & 127;
    table[s_idx_221] = (stage_v_221 + 7) & 63;
    out_sink = (out_sink + stage_v_221) & 255;
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int s_idx_222 = (stage_v_68 & 3);
    int stage_v_222 = (table[s_idx_222] + pub_r000309_8) & 127;
    table[s_idx_222] = (stage_v_222 + 7) & 63;
    out_sink = (out_sink + stage_v_222) & 255;
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
