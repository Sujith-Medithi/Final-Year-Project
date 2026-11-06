/*
 * Benchmark Program: R000573
 * Security Family: multi_step_explicit
 * Generator Seed: 557313
 * High Inputs: 21 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000573_7313_0 {
    int status;
    short rate;
    int auth_code;
    int balance;
    int buffer[3];
};

struct MatrixBlock_R000573_7313_1 {
    int trace;
    unsigned char dim;
    int scale;
    short stride;
    int buffer[3];
};

struct CipherContext_R000573_7313_2 {
    int flags;
    unsigned char round_key;
    int counter;
    short iv;
    unsigned char nonce;
    int tag;
    int buffer[3];
};

struct SensorNode_R000573_7313_3 {
    int reading;
    short offset;
    short calib;
    int gain;
    int buffer[3];
};

union RegisterBank_R000573_7313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000573_7313_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000573_7313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_13 = (aux + st.buffer[1]) & 3;
    switch (margin_13) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_1(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000573_7313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int parity_12 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_12 > 44) {
        acc = (acc + parity_12 * 2 + 5) & 127;
        aux ^= (parity_12 & 15);
    } else {
        acc = (acc - parity_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_47 = local_arr[aux % 3];
    acc = (acc + phase_47 * 2) & 127;
    int bound_99 = (aux + st.buffer[1]) & 3;
    switch (bound_99) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_38) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000573_7313_2(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000573_7313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_66) & 63;
    acc ^= aux;
    int phase_19 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_19 > 30) {
        acc = (acc + phase_19 * 2 + 5) & 127;
        aux ^= (phase_19 & 15);
    } else {
        acc = (acc - phase_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_14 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_14 > 28) {
        acc = (acc + vector_14 * 2 + 5) & 127;
        aux ^= (vector_14 & 15);
    } else {
        acc = (acc - vector_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_60 = local_arr[aux % 3];
    acc = (acc + damping_60 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000573_7313_4(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000573_7313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int bound_67 = (aux + st.buffer[1]) & 3;
    switch (bound_67) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_58 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_58 > 25) {
        acc = (acc + index_reg_58 * 2 + 5) & 127;
        aux ^= (index_reg_58 & 15);
    } else {
        acc = (acc - index_reg_58 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_5(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_61 = (aux + st.buffer[1]) & 3;
    switch (phase_61) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_84) & 63;
    acc ^= aux;
    int threshold_69 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_69 > 49) {
        acc = (acc + threshold_69 * 2 + 5) & 127;
        aux ^= (threshold_69 & 15);
    } else {
        acc = (acc - threshold_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000573_7313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int offset_22 = local_arr[aux % 3];
    acc = (acc + offset_22 * 2) & 127;
    int bound_39 = (aux + st.buffer[1]) & 3;
    switch (bound_39) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_12 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_12 > 16) {
        acc = (acc + tally_12 * 2 + 5) & 127;
        aux ^= (tally_12 & 15);
    } else {
        acc = (acc - tally_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int pivot_29 = local_arr[aux % 3];
    acc = (acc + pivot_29 * 2) & 127;
    int damping_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_33) & 63;
    acc ^= aux;
    int cursor_34 = (aux + st.buffer[1]) & 3;
    switch (cursor_34) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_33 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_33 > 44) {
        acc = (acc + tracker_33 * 2 + 5) & 127;
        aux ^= (tracker_33 & 15);
    } else {
        acc = (acc - tracker_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_8(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000573_7313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int scale_58 = local_arr[aux % 3];
    acc = (acc + scale_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000573_7313_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000573_7313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int pivot_50 = local_arr[aux % 3];
    acc = (acc + pivot_50 * 2) & 127;
    int pivot_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_36) & 63;
    acc ^= aux;
    int metric_29 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_29 > 20) {
        acc = (acc + metric_29 * 2 + 5) & 127;
        aux ^= (metric_29 & 15);
    } else {
        acc = (acc - metric_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quantum_21 = (aux + st.buffer[1]) & 3;
    switch (quantum_21) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_12 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_12 > 30) {
        acc = (acc + factor_12 * 2 + 5) & 127;
        aux ^= (factor_12 & 15);
    } else {
        acc = (acc - factor_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_93 = local_arr[aux % 3];
    acc = (acc + tally_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000573_7313_11(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_93 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_93 > 50) {
        acc = (acc + stride_93 * 2 + 5) & 127;
        aux ^= (stride_93 & 15);
    } else {
        acc = (acc - stride_93 + 11) & 127;
        aux += 3;
    }
    int scale_30 = (aux + st.buffer[1]) & 3;
    switch (scale_30) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_68 = local_arr[aux % 3];
    acc = (acc + stride_68 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000573_7313_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int window_73 = (st.buffer[0] * 3 + aux) & 63;
    if (window_73 > 23) {
        acc = (acc + window_73 * 2 + 5) & 127;
        aux ^= (window_73 & 15);
    } else {
        acc = (acc - window_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_94) & 63;
    acc ^= aux;
    int threshold_27 = (aux + st.buffer[1]) & 3;
    switch (threshold_27) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000573_7313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int offset_56 = local_arr[aux % 3];
    acc = (acc + offset_56 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000573_7313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000573_7313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int tally_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_17) & 63;
    acc ^= aux;
    int scale_68 = (aux + st.buffer[1]) & 3;
    switch (scale_68) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_16 = (aux + st.buffer[1]) & 3;
    switch (vector_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_57 = local_arr[aux % 3];
    acc = (acc + threshold_57 * 2) & 127;
    int parity_27 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_27 > 16) {
        acc = (acc + parity_27 * 2 + 5) & 127;
        aux ^= (parity_27 & 15);
    } else {
        acc = (acc - parity_27 + 11) & 127;
        aux += 3;
    }
    int index_reg_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000573_7313_16(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000573_7313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_22) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_54 = local_arr[aux % 3];
    acc = (acc + parity_54 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_86 = (aux + st.buffer[1]) & 3;
    switch (sample_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_17(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000573_7313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_20 = local_arr[aux % 3];
    acc = (acc + delta_20 * 2) & 127;
    int scale_34 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_34 > 19) {
        acc = (acc + scale_34 * 2 + 5) & 127;
        aux ^= (scale_34 & 15);
    } else {
        acc = (acc - scale_34 + 11) & 127;
        aux += 3;
    }
    int delta_56 = (aux + st.buffer[1]) & 3;
    switch (delta_56) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_18(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000573_7313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int bound_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_44) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_40 = local_arr[aux % 3];
    acc = (acc + sample_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_77 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_77 > 33) {
        acc = (acc + metric_77 * 2 + 5) & 127;
        aux ^= (metric_77 & 15);
    } else {
        acc = (acc - metric_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000573_7313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quantum_61 = (aux + st.buffer[1]) & 3;
    switch (quantum_61) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_32 = local_arr[aux % 3];
    acc = (acc + bound_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000573_7313_20(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000573_7313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int segment_17 = (aux + st.buffer[1]) & 3;
    switch (segment_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000573_7313_21(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000573_7313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quotient_94 = (aux + st.buffer[1]) & 3;
    switch (quotient_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_31 = local_arr[aux % 3];
    acc = (acc + quantum_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000573_7313_22(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000573_7313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int threshold_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_98) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_20 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_20 > 19) {
        acc = (acc + residue_20 * 2 + 5) & 127;
        aux ^= (residue_20 & 15);
    } else {
        acc = (acc - residue_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000573_7313_23(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000573_7313_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int checksum_99 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_99 > 48) {
        acc = (acc + checksum_99 * 2 + 5) & 127;
        aux ^= (checksum_99 & 15);
    } else {
        acc = (acc - checksum_99 + 11) & 127;
        aux += 3;
    }
    int margin_84 = (aux + st.buffer[1]) & 3;
    switch (margin_84) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000573_0;
    int sec_r000573_1;
    int sec_r000573_2;
    int sec_r000573_3;
    int sec_r000573_4;
    int sec_r000573_5;
    int sec_r000573_6;
    int sec_r000573_7;
    int sec_r000573_8;
    int sec_r000573_9;
    int sec_r000573_10;
    int sec_r000573_11;
    int sec_r000573_12;
    int sec_r000573_13;
    int sec_r000573_14;
    int sec_r000573_15;
    int sec_r000573_16;
    int sec_r000573_17;
    int sec_r000573_18;
    int sec_r000573_19;
    int sec_r000573_20;
    int pub_r000573_0;
    int pub_r000573_1;
    int pub_r000573_2;
    int pub_r000573_3;
    int pub_r000573_4;
    int pub_r000573_5;
    int pub_r000573_6;
    int pub_r000573_7;
    int pub_r000573_8;
    int pub_r000573_9;
    int pub_r000573_10;
    int pub_r000573_11;
    int pub_r000573_12;
    int pub_r000573_13;
    int pub_r000573_14;
    int pub_r000573_15;
    int pub_r000573_16;
    int pub_r000573_17;
    int pub_r000573_18;
    int pub_r000573_19;
    int pub_r000573_20;
    int pub_r000573_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000573_0 >= -100 && pub_r000573_0 <= 100);
    __CPROVER_assume(pub_r000573_1 >= -100 && pub_r000573_1 <= 100);
    __CPROVER_assume(pub_r000573_2 >= -100 && pub_r000573_2 <= 100);
    __CPROVER_assume(pub_r000573_3 >= -100 && pub_r000573_3 <= 100);
    __CPROVER_assume(pub_r000573_4 >= -100 && pub_r000573_4 <= 100);
    __CPROVER_assume(pub_r000573_5 >= -100 && pub_r000573_5 <= 100);
    __CPROVER_assume(pub_r000573_6 >= -100 && pub_r000573_6 <= 100);
    __CPROVER_assume(pub_r000573_7 >= -100 && pub_r000573_7 <= 100);
    __CPROVER_assume(pub_r000573_8 >= -100 && pub_r000573_8 <= 100);
    __CPROVER_assume(pub_r000573_9 >= -100 && pub_r000573_9 <= 100);
    __CPROVER_assume(pub_r000573_10 >= -100 && pub_r000573_10 <= 100);
    __CPROVER_assume(pub_r000573_11 >= -100 && pub_r000573_11 <= 100);
    __CPROVER_assume(pub_r000573_12 >= -100 && pub_r000573_12 <= 100);
    __CPROVER_assume(pub_r000573_13 >= -100 && pub_r000573_13 <= 100);
    __CPROVER_assume(pub_r000573_14 >= -100 && pub_r000573_14 <= 100);
    __CPROVER_assume(pub_r000573_15 >= -100 && pub_r000573_15 <= 100);
    __CPROVER_assume(pub_r000573_16 >= -100 && pub_r000573_16 <= 100);
    __CPROVER_assume(pub_r000573_17 >= -100 && pub_r000573_17 <= 100);
    __CPROVER_assume(pub_r000573_18 >= -100 && pub_r000573_18 <= 100);
    __CPROVER_assume(pub_r000573_19 >= -100 && pub_r000573_19 <= 100);
    __CPROVER_assume(pub_r000573_20 >= -100 && pub_r000573_20 <= 100);
    __CPROVER_assume(pub_r000573_21 >= -100 && pub_r000573_21 <= 100);
    __CPROVER_assume(sec_r000573_0 >= 0 && sec_r000573_0 <= 255);
    __CPROVER_assume(sec_r000573_1 >= 0 && sec_r000573_1 <= 255);
    __CPROVER_assume(sec_r000573_2 >= 0 && sec_r000573_2 <= 255);
    __CPROVER_assume(sec_r000573_3 >= 0 && sec_r000573_3 <= 255);
    __CPROVER_assume(sec_r000573_4 >= 0 && sec_r000573_4 <= 255);
    __CPROVER_assume(sec_r000573_5 >= 0 && sec_r000573_5 <= 255);
    __CPROVER_assume(sec_r000573_6 >= 0 && sec_r000573_6 <= 255);
    __CPROVER_assume(sec_r000573_7 >= 0 && sec_r000573_7 <= 255);
    __CPROVER_assume(sec_r000573_8 >= 0 && sec_r000573_8 <= 255);
    __CPROVER_assume(sec_r000573_9 >= 0 && sec_r000573_9 <= 255);
    __CPROVER_assume(sec_r000573_10 >= 0 && sec_r000573_10 <= 255);
    __CPROVER_assume(sec_r000573_11 >= 0 && sec_r000573_11 <= 255);
    __CPROVER_assume(sec_r000573_12 >= 0 && sec_r000573_12 <= 255);
    __CPROVER_assume(sec_r000573_13 >= 0 && sec_r000573_13 <= 255);
    __CPROVER_assume(sec_r000573_14 >= 0 && sec_r000573_14 <= 255);
    __CPROVER_assume(sec_r000573_15 >= 0 && sec_r000573_15 <= 255);
    __CPROVER_assume(sec_r000573_16 >= 0 && sec_r000573_16 <= 255);
    __CPROVER_assume(sec_r000573_17 >= 0 && sec_r000573_17 <= 255);
    __CPROVER_assume(sec_r000573_18 >= 0 && sec_r000573_18 <= 255);
    __CPROVER_assume(sec_r000573_19 >= 0 && sec_r000573_19 <= 255);
    __CPROVER_assume(sec_r000573_20 >= 0 && sec_r000573_20 <= 255);

    struct Transaction_R000573_7313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000573_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000573_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000573_0 + 7) & 15;
    struct MatrixBlock_R000573_7313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000573_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000573_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000573_0 + 9) & 15;
    struct CipherContext_R000573_7313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000573_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000573_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000573_0 + 11) & 15;
    struct SensorNode_R000573_7313_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000573_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000573_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000573_0 + 13) & 15;

    union RegisterBank_R000573_7313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 22) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 37) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

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
    int stage_v_34 = (st_var_2.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 37) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 52) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
        case 0:
            out_sink = (out_sink + 6) & 255;
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 33) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 48) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_2.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (out_sink > 100) ? (chk_sum & 31) : (53 & 31);
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= (stage_v_48 << 1) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_3.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 19) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 34) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
        case 0:
            out_sink = (out_sink + 2) & 255;
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 37) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 52) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 20) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 35) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 29) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 44) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 36) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 51) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 27) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 42) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
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

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int sub_step_78 = (sec_r000573_1 + pub_r000573_17 + 27) & 127;
    int stage_v_78 = (sub_step_78 * 2 + pub_r000573_3) & 127;
    st_var_2.buffer[0] = (stage_v_78 & 15);
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int sub_step_79 = (stage_v_78 + pub_r000573_12 + 11) & 127;
    int stage_v_79 = (sub_step_79 * 2 + pub_r000573_16) & 127;
    st_var_3.buffer[1] = (stage_v_79 & 15);
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int sub_step_80 = (sub_step_78 + pub_r000573_15 + 27) & 127;
    int stage_v_80 = (sub_step_80 * 2 + pub_r000573_13) & 127;
    st_var_0.buffer[2] = (stage_v_80 & 15);
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int sub_step_81 = (sec_r000573_3 + pub_r000573_12 + 13) & 127;
    int stage_v_81 = (sub_step_81 * 2 + pub_r000573_19) & 127;
    st_var_1.buffer[0] = (stage_v_81 & 15);
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int sub_step_82 = (sec_r000573_20 + pub_r000573_8 + 9) & 127;
    int stage_v_82 = (sub_step_82 * 2 + pub_r000573_13) & 127;
    st_var_2.buffer[1] = (stage_v_82 & 15);
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int sub_step_83 = (sec_r000573_12 + pub_r000573_6 + 23) & 127;
    int stage_v_83 = (sub_step_83 * 2 + pub_r000573_14) & 127;
    st_var_3.buffer[2] = (stage_v_83 & 15);
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int sub_step_84 = (stage_v_83 + pub_r000573_16 + 18) & 127;
    int stage_v_84 = (sub_step_84 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[0] = (stage_v_84 & 15);
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int sub_step_85 = (sec_r000573_5 + pub_r000573_21 + 28) & 127;
    int stage_v_85 = (sub_step_85 * 2 + pub_r000573_13) & 127;
    st_var_1.buffer[1] = (stage_v_85 & 15);
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int sub_step_86 = (sec_r000573_2 + pub_r000573_5 + 34) & 127;
    int stage_v_86 = (sub_step_86 * 2 + pub_r000573_4) & 127;
    st_var_2.buffer[2] = (stage_v_86 & 15);
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int sub_step_87 = (sec_r000573_2 + pub_r000573_3 + 8) & 127;
    int stage_v_87 = (sub_step_87 * 2 + pub_r000573_15) & 127;
    st_var_3.buffer[0] = (stage_v_87 & 15);
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int sub_step_88 = (sec_r000573_0 + pub_r000573_13 + 34) & 127;
    int stage_v_88 = (sub_step_88 * 2 + pub_r000573_14) & 127;
    st_var_0.buffer[1] = (stage_v_88 & 15);
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (stage_v_81 + pub_r000573_16 + 10) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000573_6) & 127;
    st_var_1.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (stage_v_79 + pub_r000573_13 + 30) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000573_7) & 127;
    st_var_2.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000573_18 + pub_r000573_16 + 8) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000573_21) & 127;
    st_var_3.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (sec_r000573_10 + pub_r000573_20 + 34) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000573_14) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sub_step_80 + pub_r000573_21 + 11) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000573_18) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sec_r000573_13 + pub_r000573_0 + 35) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000573_17) & 127;
    st_var_2.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (sec_r000573_2 + pub_r000573_7 + 24) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000573_21) & 127;
    st_var_3.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sec_r000573_20 + pub_r000573_17 + 34) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (stage_v_95 + pub_r000573_12 + 17) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000573_10) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (stage_v_94 + pub_r000573_19 + 11) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000573_3) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sec_r000573_11 + pub_r000573_20 + 21) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000573_3) & 127;
    st_var_3.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (sec_r000573_4 + pub_r000573_13 + 14) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000573_16) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (stage_v_91 + pub_r000573_10 + 9) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000573_11) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (stage_v_94 + pub_r000573_5 + 33) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000573_2) & 127;
    st_var_2.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sec_r000573_2 + pub_r000573_8 + 20) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000573_6) & 127;
    st_var_3.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (sec_r000573_0 + pub_r000573_0 + 34) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sec_r000573_17 + pub_r000573_14 + 32) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000573_1) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (stage_v_94 + pub_r000573_9 + 11) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000573_10) & 127;
    st_var_2.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sec_r000573_17 + pub_r000573_21 + 32) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000573_3) & 127;
    st_var_3.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_79 + pub_r000573_0 + 29) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000573_15) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (stage_v_86 + pub_r000573_19 + 29) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000573_7) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (sec_r000573_14 + pub_r000573_19 + 11) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000573_15) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (stage_v_87 + pub_r000573_17 + 10) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000573_0) & 127;
    st_var_3.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (sec_r000573_1 + pub_r000573_4 + 21) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000573_18) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sec_r000573_1 + pub_r000573_19 + 29) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000573_17) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (sub_step_94 + pub_r000573_7 + 22) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000573_13) & 127;
    st_var_2.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sub_step_78 + pub_r000573_0 + 23) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000573_1) & 127;
    st_var_3.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (sub_step_84 + pub_r000573_11 + 32) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000573_3) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_86 + pub_r000573_16 + 9) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000573_19) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sub_step_85 + pub_r000573_19 + 33) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000573_3) & 127;
    st_var_2.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (stage_v_84 + pub_r000573_5 + 7) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000573_16) & 127;
    st_var_3.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (stage_v_105 + pub_r000573_2 + 18) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000573_13) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sec_r000573_2 + pub_r000573_10 + 26) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000573_7) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000573_20 + pub_r000573_16 + 8) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000573_3) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sec_r000573_6 + pub_r000573_3 + 6) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000573_15) & 127;
    st_var_3.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sec_r000573_7 + pub_r000573_6 + 15) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000573_2) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (stage_v_118 + pub_r000573_1 + 19) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000573_20) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_122 + pub_r000573_7 + 11) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000573_12) & 127;
    st_var_2.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sec_r000573_7 + pub_r000573_12 + 30) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000573_10) & 127;
    st_var_3.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_92 + pub_r000573_19 + 25) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000573_2) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sec_r000573_15 + pub_r000573_11 + 22) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000573_5) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sub_step_99 + pub_r000573_20 + 10) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000573_3) & 127;
    st_var_2.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sec_r000573_19 + pub_r000573_17 + 10) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000573_1) & 127;
    st_var_3.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_119 + pub_r000573_6 + 30) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000573_8) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (sec_r000573_2 + pub_r000573_21 + 13) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000573_3) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (stage_v_93 + pub_r000573_17 + 25) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000573_10) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (sec_r000573_19 + pub_r000573_18 + 26) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000573_12) & 127;
    st_var_3.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_87 + pub_r000573_20 + 22) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000573_11) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (stage_v_92 + pub_r000573_14 + 16) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000573_11) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sec_r000573_13 + pub_r000573_12 + 7) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000573_9) & 127;
    st_var_2.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sub_step_84 + pub_r000573_20 + 22) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000573_18) & 127;
    st_var_3.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (sec_r000573_6 + pub_r000573_11 + 12) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000573_9) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sec_r000573_8 + pub_r000573_0 + 16) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000573_9) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sec_r000573_17 + pub_r000573_3 + 12) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000573_16) & 127;
    st_var_2.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sub_step_139 + pub_r000573_1 + 29) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000573_15) & 127;
    st_var_3.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (stage_v_131 + pub_r000573_16 + 34) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000573_18) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (stage_v_143 + pub_r000573_14 + 29) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000573_10) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (stage_v_125 + pub_r000573_6 + 30) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000573_10) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sec_r000573_6 + pub_r000573_0 + 28) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000573_11) & 127;
    st_var_3.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (stage_v_146 + pub_r000573_3 + 23) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000573_8) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (sec_r000573_3 + pub_r000573_3 + 16) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000573_11) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (stage_v_93 + pub_r000573_18 + 13) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000573_9) & 127;
    st_var_2.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000573_20 + pub_r000573_7 + 34) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000573_21) & 127;
    st_var_3.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sec_r000573_4 + pub_r000573_2 + 29) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000573_15) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (stage_v_115 + pub_r000573_18 + 27) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000573_8) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (sec_r000573_5 + pub_r000573_15 + 10) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000573_17) & 127;
    st_var_2.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sec_r000573_2 + pub_r000573_1 + 17) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000573_8) & 127;
    st_var_3.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000573_3 + pub_r000573_15 + 35) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000573_14) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sec_r000573_0 + pub_r000573_17 + 26) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000573_9) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sub_step_124 + pub_r000573_16 + 16) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000573_0) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (stage_v_118 + pub_r000573_19 + 28) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000573_15) & 127;
    st_var_3.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (stage_v_126 + pub_r000573_10 + 30) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000573_3) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sec_r000573_6 + pub_r000573_12 + 34) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000573_2) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sub_step_100 + pub_r000573_2 + 15) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000573_17) & 127;
    st_var_2.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_90 + pub_r000573_18 + 17) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000573_1) & 127;
    st_var_3.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (sec_r000573_2 + pub_r000573_15 + 32) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (stage_v_103 + pub_r000573_18 + 23) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000573_20) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sub_step_112 + pub_r000573_13 + 22) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000573_4) & 127;
    st_var_2.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sec_r000573_10 + pub_r000573_5 + 29) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000573_5) & 127;
    st_var_3.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sub_step_111 + pub_r000573_10 + 5) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000573_19) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sub_step_155 + pub_r000573_9 + 16) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000573_3) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (stage_v_121 + pub_r000573_20 + 13) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000573_8) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sec_r000573_8 + pub_r000573_19 + 9) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000573_1) & 127;
    st_var_3.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sub_step_154 + pub_r000573_17 + 27) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000573_15) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (stage_v_87 + pub_r000573_10 + 9) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000573_0) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sub_step_134 + pub_r000573_14 + 14) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000573_9) & 127;
    st_var_2.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_117 + pub_r000573_18 + 13) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000573_7) & 127;
    st_var_3.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sec_r000573_6 + pub_r000573_2 + 24) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000573_21) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sub_step_139 + pub_r000573_15 + 6) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000573_0) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sub_step_168 + pub_r000573_12 + 25) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000573_5) & 127;
    st_var_2.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (stage_v_142 + pub_r000573_21 + 25) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000573_14) & 127;
    st_var_3.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sub_step_96 + pub_r000573_5 + 9) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000573_9) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (stage_v_135 + pub_r000573_7 + 12) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000573_18) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (stage_v_121 + pub_r000573_16 + 11) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000573_9) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sub_step_154 + pub_r000573_14 + 25) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000573_7) & 127;
    st_var_3.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sub_step_102 + pub_r000573_19 + 19) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000573_14) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (sec_r000573_14 + pub_r000573_0 + 35) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000573_18) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sec_r000573_3 + pub_r000573_8 + 29) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000573_5) & 127;
    st_var_2.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (stage_v_153 + pub_r000573_2 + 26) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000573_15) & 127;
    st_var_3.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (stage_v_120 + pub_r000573_21 + 12) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000573_11) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sub_step_132 + pub_r000573_13 + 23) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000573_8) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sec_r000573_7 + pub_r000573_8 + 7) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000573_19) & 127;
    st_var_2.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (sec_r000573_13 + pub_r000573_19 + 19) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000573_3) & 127;
    st_var_3.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (stage_v_84 + pub_r000573_0 + 28) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000573_7) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sub_step_94 + pub_r000573_16 + 17) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000573_6) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_168 + pub_r000573_16 + 29) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000573_9) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sec_r000573_1 + pub_r000573_3 + 11) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000573_7) & 127;
    st_var_3.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (sub_step_164 + pub_r000573_19 + 35) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000573_6) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sec_r000573_5 + pub_r000573_16 + 17) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000573_17) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sub_step_139 + pub_r000573_14 + 17) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000573_1) & 127;
    st_var_2.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (sub_step_185 + pub_r000573_19 + 33) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000573_16) & 127;
    st_var_3.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sec_r000573_8 + pub_r000573_2 + 35) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000573_7) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sub_step_98 + pub_r000573_7 + 20) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000573_17) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sec_r000573_6 + pub_r000573_11 + 24) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000573_7) & 127;
    st_var_2.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sec_r000573_18 + pub_r000573_7 + 7) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000573_7) & 127;
    st_var_3.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sec_r000573_1 + pub_r000573_19 + 28) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sub_step_187 + pub_r000573_1 + 9) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000573_10) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sec_r000573_9 + pub_r000573_9 + 30) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000573_18) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sub_step_119 + pub_r000573_13 + 35) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000573_1) & 127;
    st_var_3.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sec_r000573_17 + pub_r000573_6 + 7) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000573_15) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (stage_v_127 + pub_r000573_12 + 35) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000573_5) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (stage_v_203 + pub_r000573_18 + 21) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000573_6) & 127;
    st_var_2.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000573_9 + pub_r000573_18 + 26) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000573_13) & 127;
    st_var_3.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (stage_v_124 + pub_r000573_14 + 34) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000573_21) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (sub_step_104 + pub_r000573_16 + 29) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000573_3) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_183 + pub_r000573_10 + 15) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000573_8) & 127;
    st_var_2.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (stage_v_176 + pub_r000573_20 + 28) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000573_8) & 127;
    st_var_3.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (stage_v_149 + pub_r000573_16 + 22) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000573_2) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sub_step_126 + pub_r000573_1 + 16) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000573_15) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (stage_v_204 + pub_r000573_0 + 12) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000573_3) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (stage_v_152 + pub_r000573_6 + 26) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000573_16) & 127;
    st_var_3.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (stage_v_80 + pub_r000573_0 + 27) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sec_r000573_13 + pub_r000573_19 + 22) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000573_1) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sub_step_144 + pub_r000573_0 + 15) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000573_21) & 127;
    st_var_2.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sec_r000573_2 + pub_r000573_4 + 26) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000573_19) & 127;
    st_var_3.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sec_r000573_19 + pub_r000573_7 + 23) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000573_10) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (stage_v_109 + pub_r000573_1 + 15) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000573_15) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sec_r000573_15 + pub_r000573_19 + 9) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000573_9) & 127;
    st_var_2.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sec_r000573_11 + pub_r000573_21 + 15) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000573_19) & 127;
    st_var_3.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (stage_v_179 + pub_r000573_11 + 27) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000573_16) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (stage_v_194 + pub_r000573_17 + 23) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000573_2) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (stage_v_208 + pub_r000573_2 + 16) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000573_12) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sec_r000573_18 + pub_r000573_7 + 25) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000573_4) & 127;
    st_var_3.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (stage_v_226 + pub_r000573_18 + 11) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000573_9) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (stage_v_125 + pub_r000573_2 + 5) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000573_7) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sub_step_101 + pub_r000573_20 + 27) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000573_19) & 127;
    st_var_2.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
