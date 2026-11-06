/*
 * Benchmark Program: R000604
 * Security Family: arithmetic_flow
 * Generator Seed: 560413
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000604_413_0 {
    int pitch;
    int norm_sq;
    int coord_x;
    short coord_y;
    short coord_z;
    short heading;
    int buffer[3];
};

struct CipherContext_R000604_413_1 {
    short nonce;
    unsigned char tag;
    unsigned char flags;
    unsigned char iv;
    int round_key;
    int buffer[3];
};

struct EventLog_R000604_413_2 {
    unsigned char severity;
    short facility;
    unsigned char signature;
    short timestamp;
    int code;
    int buffer[3];
};

union PacketPayload_R000604_413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000604_413_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000604_413_0(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int weight_58 = (aux + st.buffer[1]) & 3;
    switch (weight_58) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_51 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_51 > 26) {
        acc = (acc + anchor_51 * 2 + 5) & 127;
        aux ^= (anchor_51 & 15);
    } else {
        acc = (acc - anchor_51 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_52 = local_arr[aux % 3];
    acc = (acc + margin_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_1(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int vector_99 = local_arr[aux % 3];
    acc = (acc + vector_99 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_2(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quantum_56 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_56 > 13) {
        acc = (acc + quantum_56 * 2 + 5) & 127;
        aux ^= (quantum_56 & 15);
    } else {
        acc = (acc - quantum_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_3(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_77 = local_arr[aux % 3];
    acc = (acc + parity_77 * 2) & 127;
    int index_reg_39 = (aux + st.buffer[1]) & 3;
    switch (index_reg_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_4(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000604_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int factor_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_47) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_56 = local_arr[aux % 3];
    acc = (acc + mask_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_5(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_10 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_10 > 44) {
        acc = (acc + factor_10 * 2 + 5) & 127;
        aux ^= (factor_10 & 15);
    } else {
        acc = (acc - factor_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_85 = local_arr[aux % 3];
    acc = (acc + bound_85 * 2) & 127;
    int mask_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_6(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int coefficient_49 = local_arr[aux % 3];
    acc = (acc + coefficient_49 * 2) & 127;
    int stride_30 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_30 > 21) {
        acc = (acc + stride_30 * 2 + 5) & 127;
        aux ^= (stride_30 & 15);
    } else {
        acc = (acc - stride_30 + 11) & 127;
        aux += 3;
    }
    int coefficient_79 = (aux + st.buffer[1]) & 3;
    switch (coefficient_79) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000604_413_7(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000604_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int scale_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_25) & 63;
    acc ^= aux;
    int delta_59 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_59 > 15) {
        acc = (acc + delta_59 * 2 + 5) & 127;
        aux ^= (delta_59 & 15);
    } else {
        acc = (acc - delta_59 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_47 = local_arr[aux % 3];
    acc = (acc + factor_47 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int accumulator_34 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_34 > 45) {
        acc = (acc + accumulator_34 * 2 + 5) & 127;
        aux ^= (accumulator_34 & 15);
    } else {
        acc = (acc - accumulator_34 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_68 = (aux + st.buffer[1]) & 3;
    switch (checksum_68) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_41) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_9(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int tracker_83 = local_arr[aux % 3];
    acc = (acc + tracker_83 * 2) & 127;
    int vector_82 = (aux + st.buffer[1]) & 3;
    switch (vector_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000604_413_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000604_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_51) & 63;
    acc ^= aux;
    int bound_29 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_29 > 27) {
        acc = (acc + bound_29 * 2 + 5) & 127;
        aux ^= (bound_29 & 15);
    } else {
        acc = (acc - bound_29 + 11) & 127;
        aux += 3;
    }
    int pivot_77 = (aux + st.buffer[1]) & 3;
    switch (pivot_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000604_413_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000604_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int threshold_90 = (aux + st.buffer[1]) & 3;
    switch (threshold_90) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_80) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_82) & 63;
    acc ^= aux;
    int margin_18 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_18 > 35) {
        acc = (acc + margin_18 * 2 + 5) & 127;
        aux ^= (margin_18 & 15);
    } else {
        acc = (acc - margin_18 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000604_413_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int vector_16 = (aux + st.buffer[1]) & 3;
    switch (vector_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_32 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_32 > 38) {
        acc = (acc + factor_32 * 2 + 5) & 127;
        aux ^= (factor_32 & 15);
    } else {
        acc = (acc - factor_32 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_48 = local_arr[aux % 3];
    acc = (acc + vector_48 * 2) & 127;
    int window_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_35) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_12 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_12 > 41) {
        acc = (acc + threshold_12 * 2 + 5) & 127;
        aux ^= (threshold_12 & 15);
    } else {
        acc = (acc - threshold_12 + 11) & 127;
        aux += 3;
    }
    int phase_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_15(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_56 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_56 > 18) {
        acc = (acc + weight_56 * 2 + 5) & 127;
        aux ^= (weight_56 & 15);
    } else {
        acc = (acc - weight_56 + 11) & 127;
        aux += 3;
    }
    int segment_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_73) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_16(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000604_413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int scale_25 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_25 > 18) {
        acc = (acc + scale_25 * 2 + 5) & 127;
        aux ^= (scale_25 & 15);
    } else {
        acc = (acc - scale_25 + 11) & 127;
        aux += 3;
    }
    int quantum_58 = (aux + st.buffer[1]) & 3;
    switch (quantum_58) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_79 = local_arr[aux % 3];
    acc = (acc + phase_79 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000604_413_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int cursor_27 = (aux + st.buffer[1]) & 3;
    switch (cursor_27) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_85 = local_arr[aux % 3];
    acc = (acc + offset_85 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_20(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000604_413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int metric_68 = (aux + st.buffer[1]) & 3;
    switch (metric_68) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_26 = local_arr[aux % 3];
    acc = (acc + cursor_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000604_413_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_47 = local_arr[aux % 3];
    acc = (acc + damping_47 * 2) & 127;
    int segment_86 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_86 > 21) {
        acc = (acc + segment_86 * 2 + 5) & 127;
        aux ^= (segment_86 & 15);
    } else {
        acc = (acc - segment_86 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000604_413_22(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000604_413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_56) & 63;
    acc ^= aux;
    int factor_17 = (aux + st.buffer[1]) & 3;
    switch (factor_17) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_53 = local_arr[aux % 3];
    acc = (acc + threshold_53 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000604_0;
    int sec_r000604_1;
    int sec_r000604_2;
    int sec_r000604_3;
    int sec_r000604_4;
    int sec_r000604_5;
    int sec_r000604_6;
    int sec_r000604_7;
    int sec_r000604_8;
    int sec_r000604_9;
    int sec_r000604_10;
    int sec_r000604_11;
    int sec_r000604_12;
    int sec_r000604_13;
    int sec_r000604_14;
    int sec_r000604_15;
    int sec_r000604_16;
    int pub_r000604_0;
    int pub_r000604_1;
    int pub_r000604_2;
    int pub_r000604_3;
    int pub_r000604_4;
    int pub_r000604_5;
    int pub_r000604_6;
    int pub_r000604_7;
    int pub_r000604_8;
    int pub_r000604_9;
    int pub_r000604_10;
    int pub_r000604_11;
    int pub_r000604_12;
    int pub_r000604_13;
    int pub_r000604_14;
    int pub_r000604_15;
    int pub_r000604_16;
    int pub_r000604_17;
    int pub_r000604_18;
    int pub_r000604_19;
    int pub_r000604_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000604_0 >= -100 && pub_r000604_0 <= 100);
    __CPROVER_assume(pub_r000604_1 >= -100 && pub_r000604_1 <= 100);
    __CPROVER_assume(pub_r000604_2 >= -100 && pub_r000604_2 <= 100);
    __CPROVER_assume(pub_r000604_3 >= -100 && pub_r000604_3 <= 100);
    __CPROVER_assume(pub_r000604_4 >= -100 && pub_r000604_4 <= 100);
    __CPROVER_assume(pub_r000604_5 >= -100 && pub_r000604_5 <= 100);
    __CPROVER_assume(pub_r000604_6 >= -100 && pub_r000604_6 <= 100);
    __CPROVER_assume(pub_r000604_7 >= -100 && pub_r000604_7 <= 100);
    __CPROVER_assume(pub_r000604_8 >= -100 && pub_r000604_8 <= 100);
    __CPROVER_assume(pub_r000604_9 >= -100 && pub_r000604_9 <= 100);
    __CPROVER_assume(pub_r000604_10 >= -100 && pub_r000604_10 <= 100);
    __CPROVER_assume(pub_r000604_11 >= -100 && pub_r000604_11 <= 100);
    __CPROVER_assume(pub_r000604_12 >= -100 && pub_r000604_12 <= 100);
    __CPROVER_assume(pub_r000604_13 >= -100 && pub_r000604_13 <= 100);
    __CPROVER_assume(pub_r000604_14 >= -100 && pub_r000604_14 <= 100);
    __CPROVER_assume(pub_r000604_15 >= -100 && pub_r000604_15 <= 100);
    __CPROVER_assume(pub_r000604_16 >= -100 && pub_r000604_16 <= 100);
    __CPROVER_assume(pub_r000604_17 >= -100 && pub_r000604_17 <= 100);
    __CPROVER_assume(pub_r000604_18 >= -100 && pub_r000604_18 <= 100);
    __CPROVER_assume(pub_r000604_19 >= -100 && pub_r000604_19 <= 100);
    __CPROVER_assume(pub_r000604_20 >= -100 && pub_r000604_20 <= 100);
    __CPROVER_assume(sec_r000604_0 >= 0 && sec_r000604_0 <= 255);
    __CPROVER_assume(sec_r000604_1 >= 0 && sec_r000604_1 <= 255);
    __CPROVER_assume(sec_r000604_2 >= 0 && sec_r000604_2 <= 255);
    __CPROVER_assume(sec_r000604_3 >= 0 && sec_r000604_3 <= 255);
    __CPROVER_assume(sec_r000604_4 >= 0 && sec_r000604_4 <= 255);
    __CPROVER_assume(sec_r000604_5 >= 0 && sec_r000604_5 <= 255);
    __CPROVER_assume(sec_r000604_6 >= 0 && sec_r000604_6 <= 255);
    __CPROVER_assume(sec_r000604_7 >= 0 && sec_r000604_7 <= 255);
    __CPROVER_assume(sec_r000604_8 >= 0 && sec_r000604_8 <= 255);
    __CPROVER_assume(sec_r000604_9 >= 0 && sec_r000604_9 <= 255);
    __CPROVER_assume(sec_r000604_10 >= 0 && sec_r000604_10 <= 255);
    __CPROVER_assume(sec_r000604_11 >= 0 && sec_r000604_11 <= 255);
    __CPROVER_assume(sec_r000604_12 >= 0 && sec_r000604_12 <= 255);
    __CPROVER_assume(sec_r000604_13 >= 0 && sec_r000604_13 <= 255);
    __CPROVER_assume(sec_r000604_14 >= 0 && sec_r000604_14 <= 255);
    __CPROVER_assume(sec_r000604_15 >= 0 && sec_r000604_15 <= 255);
    __CPROVER_assume(sec_r000604_16 >= 0 && sec_r000604_16 <= 255);

    struct Vector3D_R000604_413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000604_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000604_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000604_0 + 7) & 15;
    struct CipherContext_R000604_413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000604_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000604_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000604_0 + 9) & 15;
    struct EventLog_R000604_413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000604_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000604_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000604_0 + 11) & 15;

    union PacketPayload_R000604_413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 14) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 29) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 24) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 39) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 32) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 47) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 36) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 51) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 13) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 28) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r000604_1 * 3) + (sec_r000604_1 * 2) - pub_r000604_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_20 * 3) + (sec_r000604_15 * 2) - pub_r000604_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_20 * 3) + (sec_r000604_13 * 2) - pub_r000604_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_11 + 15) & 127;
    sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((sec_r000604_0 * 3) + (sec_r000604_0 * 2) - pub_r000604_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_24 * 3) + (sec_r000604_3 * 2) - pub_r000604_19 + 4) & 127;
    sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r000604_13 * 3) + (sec_r000604_13 * 2) - pub_r000604_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r000604_11 * 3) + (sec_r000604_11 * 2) - pub_r000604_19 + 35) & 127;
    sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_20 * 3) + (sec_r000604_15 * 2) - pub_r000604_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_23 * 3) + (sec_r000604_11 * 2) - pub_r000604_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r000604_0 * 3) + (sec_r000604_0 * 2) - pub_r000604_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_28 * 3) + (sec_r000604_15 * 2) - pub_r000604_20 + 26) & 127;
    sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_5 + 16) & 127;
    sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r000604_14 * 3) + (sec_r000604_14 * 2) - pub_r000604_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_19 + 18) & 127;
    sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_28 * 3) + (sec_r000604_4 * 2) - pub_r000604_7 + 18) & 127;
    sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_23 * 3) + (sec_r000604_7 * 2) - pub_r000604_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_30 * 3) + (sec_r000604_9 * 2) - pub_r000604_17 + 5) & 127;
    sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_29 * 3) + (sec_r000604_2 * 2) - pub_r000604_13 + 15) & 127;
    sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_21 * 3) + (sec_r000604_16 * 2) - pub_r000604_7 + 7) & 127;
    sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_19 + 29) & 127;
    sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_20 * 3) + (sec_r000604_1 * 2) - pub_r000604_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_43 * 3) + (sec_r000604_2 * 2) - pub_r000604_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_45 * 2) & 255;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r000604_7 * 3) + (sec_r000604_7 * 2) - pub_r000604_18 + 21) & 127;
    sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_46 * 3) + (sec_r000604_10 * 2) - pub_r000604_4 + 12) & 127;
    sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_32 * 3) + (sec_r000604_14 * 2) - pub_r000604_17 + 9) & 127;
    sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_37 * 3) + (sec_r000604_0 * 2) - pub_r000604_19 + 12) & 127;
    sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_47 * 3) + (sec_r000604_10 * 2) - pub_r000604_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000604_14 * 3) + (sec_r000604_14 * 2) - pub_r000604_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_26 * 3) + (sec_r000604_13 * 2) - pub_r000604_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_27 * 3) + (sec_r000604_11 * 2) - pub_r000604_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_52 * 3) + (sec_r000604_4 * 2) - pub_r000604_14 + 7) & 127;
    sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_7 + 19) & 127;
    sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_33 * 3) + (sec_r000604_4 * 2) - pub_r000604_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_13 + 19) & 127;
    sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000604_7 * 3) + (sec_r000604_7 * 2) - pub_r000604_19 + 10) & 127;
    sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r000604_11 * 3) + (sec_r000604_11 * 2) - pub_r000604_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_36 * 3) + (sec_r000604_6 * 2) - pub_r000604_14 + 36) & 127;
    sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_36 * 3) + (sec_r000604_8 * 2) - pub_r000604_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_58 * 3) + (sec_r000604_9 * 2) - pub_r000604_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r000604_10 * 3) + (sec_r000604_10 * 2) - pub_r000604_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r000604_7 * 3) + (sec_r000604_7 * 2) - pub_r000604_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_17 + 17) & 127;
    sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_25 * 3) + (sec_r000604_14 * 2) - pub_r000604_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_23 * 3) + (sec_r000604_4 * 2) - pub_r000604_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000604_10 * 3) + (sec_r000604_10 * 2) - pub_r000604_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_26 * 3) + (sec_r000604_5 * 2) - pub_r000604_10 + 19) & 127;
    sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_65 * 3) + (sec_r000604_10 * 2) - pub_r000604_5 + 30) & 127;
    sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_46 * 3) + (sec_r000604_9 * 2) - pub_r000604_12 + 7) & 127;
    sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_20 + 18) & 127;
    sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_55 * 3) + (sec_r000604_15 * 2) - pub_r000604_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_47 * 3) + (sec_r000604_7 * 2) - pub_r000604_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_48 * 3) + (sec_r000604_13 * 2) - pub_r000604_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_44 * 3) + (sec_r000604_1 * 2) - pub_r000604_20 + 37) & 127;
    sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_77 * 3) + (sec_r000604_7 * 2) - pub_r000604_14 + 13) & 127;
    sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_71 * 3) + (sec_r000604_9 * 2) - pub_r000604_18 + 14) & 127;
    sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_25 * 3) + (sec_r000604_12 * 2) - pub_r000604_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r000604_5 * 3) + (sec_r000604_5 * 2) - pub_r000604_7 + 37) & 127;
    sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_66 * 3) + (sec_r000604_14 * 2) - pub_r000604_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_39 * 3) + (sec_r000604_11 * 2) - pub_r000604_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_41 * 3) + (sec_r000604_3 * 2) - pub_r000604_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_30 * 3) + (sec_r000604_16 * 2) - pub_r000604_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_27 * 3) + (sec_r000604_2 * 2) - pub_r000604_20 + 20) & 127;
    sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_41 * 3) + (sec_r000604_12 * 2) - pub_r000604_15 + 8) & 127;
    sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_27 * 3) + (sec_r000604_16 * 2) - pub_r000604_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_96 * 3) + (sec_r000604_13 * 2) - pub_r000604_18 + 17) & 127;
    sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_96 * 3) + (sec_r000604_9 * 2) - pub_r000604_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_86 * 3) + (sec_r000604_4 * 2) - pub_r000604_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r000604_13 * 3) + (sec_r000604_13 * 2) - pub_r000604_12 + 9) & 127;
    sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_82 * 3) + (sec_r000604_12 * 2) - pub_r000604_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_53 * 3) + (sec_r000604_16 * 2) - pub_r000604_2 + 3) & 127;
    sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_25 * 3) + (sec_r000604_10 * 2) - pub_r000604_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_52 * 3) + (sec_r000604_8 * 2) - pub_r000604_2 + 33) & 127;
    sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_20 + 4) & 127;
    sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_53 * 3) + (sec_r000604_13 * 2) - pub_r000604_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_27 * 3) + (sec_r000604_11 * 2) - pub_r000604_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_77 * 3) + (sec_r000604_4 * 2) - pub_r000604_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_109 * 3) + (sec_r000604_2 * 2) - pub_r000604_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_26 * 3) + (sec_r000604_10 * 2) - pub_r000604_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_1 + 8) & 127;
    sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_48 * 3) + (sec_r000604_8 * 2) - pub_r000604_15 + 22) & 127;
    sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_30 * 3) + (sec_r000604_8 * 2) - pub_r000604_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_88 * 3) + (sec_r000604_1 * 2) - pub_r000604_17 + 33) & 127;
    sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_106 * 3) + (sec_r000604_16 * 2) - pub_r000604_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_101 * 3) + (sec_r000604_15 * 2) - pub_r000604_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_88 * 3) + (sec_r000604_1 * 2) - pub_r000604_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_38 * 3) + (sec_r000604_7 * 2) - pub_r000604_3 + 26) & 127;
    sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000604_5 * 3) + (sec_r000604_5 * 2) - pub_r000604_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_116 * 3) + (sec_r000604_11 * 2) - pub_r000604_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_61 * 3) + (sec_r000604_11 * 2) - pub_r000604_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_115 * 3) + (sec_r000604_15 * 2) - pub_r000604_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_54 * 3) + (sec_r000604_6 * 2) - pub_r000604_6 + 22) & 127;
    sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000604_0 * 3) + (sec_r000604_0 * 2) - pub_r000604_1 + 12) & 127;
    sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_74 * 3) + (sec_r000604_16 * 2) - pub_r000604_20 + 10) & 127;
    sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_48 * 3) + (sec_r000604_9 * 2) - pub_r000604_17 + 24) & 127;
    sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_94 * 3) + (sec_r000604_7 * 2) - pub_r000604_0 + 35) & 127;
    sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_97 * 3) + (sec_r000604_1 * 2) - pub_r000604_4 + 6) & 127;
    sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_42 * 3) + (sec_r000604_10 * 2) - pub_r000604_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_90 * 3) + (sec_r000604_12 * 2) - pub_r000604_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_110 * 3) + (sec_r000604_14 * 2) - pub_r000604_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_134 * 3) + (sec_r000604_14 * 2) - pub_r000604_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_127 * 3) + (sec_r000604_6 * 2) - pub_r000604_17 + 20) & 127;
    sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_27 * 3) + (sec_r000604_3 * 2) - pub_r000604_13 + 6) & 127;
    sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_37 * 3) + (sec_r000604_4 * 2) - pub_r000604_2 + 31) & 127;
    sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_100 * 3) + (sec_r000604_6 * 2) - pub_r000604_19 + 22) & 127;
    sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_7 + 33) & 127;
    sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r000604_0 * 3) + (sec_r000604_0 * 2) - pub_r000604_4 + 32) & 127;
    sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_65 * 3) + (sec_r000604_3 * 2) - pub_r000604_19 + 7) & 127;
    sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_101 * 3) + (sec_r000604_2 * 2) - pub_r000604_15 + 21) & 127;
    sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_3 + 31) & 127;
    sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_9 + 7) & 127;
    sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_81 * 3) + (sec_r000604_16 * 2) - pub_r000604_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_7 + 21) & 127;
    sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_92 * 3) + (sec_r000604_3 * 2) - pub_r000604_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_15 + 25) & 127;
    sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_115 * 3) + (sec_r000604_4 * 2) - pub_r000604_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_29 * 3) + (sec_r000604_6 * 2) - pub_r000604_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_50 * 3) + (sec_r000604_14 * 2) - pub_r000604_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_2 + 26) & 127;
    sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_96 * 3) + (sec_r000604_5 * 2) - pub_r000604_10 + 16) & 127;
    sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_46 * 3) + (sec_r000604_8 * 2) - pub_r000604_18 + 9) & 127;
    sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_33 * 3) + (sec_r000604_11 * 2) - pub_r000604_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_120 * 3) + (sec_r000604_8 * 2) - pub_r000604_18 + 12) & 127;
    sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000604_5 * 3) + (sec_r000604_5 * 2) - pub_r000604_20 + 36) & 127;
    sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_10 + 18) & 127;
    sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_16 + 8) & 127;
    sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_137 * 3) + (sec_r000604_14 * 2) - pub_r000604_20 + 33) & 127;
    sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_23 * 3) + (sec_r000604_5 * 2) - pub_r000604_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_39 * 3) + (sec_r000604_8 * 2) - pub_r000604_12 + 26) & 127;
    sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_51 * 3) + (sec_r000604_15 * 2) - pub_r000604_14 + 23) & 127;
    sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_53 * 3) + (sec_r000604_6 * 2) - pub_r000604_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_38 * 3) + (sec_r000604_16 * 2) - pub_r000604_12 + 36) & 127;
    sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_156 * 3) + (sec_r000604_4 * 2) - pub_r000604_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_103 * 3) + (sec_r000604_9 * 2) - pub_r000604_4 + 20) & 127;
    sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_90 * 3) + (sec_r000604_12 * 2) - pub_r000604_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_10 + 30) & 127;
    sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000604_11 * 3) + (sec_r000604_11 * 2) - pub_r000604_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_129 * 3) + (sec_r000604_7 * 2) - pub_r000604_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_176 * 3) + (sec_r000604_8 * 2) - pub_r000604_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_94 * 3) + (sec_r000604_4 * 2) - pub_r000604_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r000604_0 * 3) + (sec_r000604_0 * 2) - pub_r000604_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((sec_r000604_10 * 3) + (sec_r000604_10 * 2) - pub_r000604_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_0 + 5) & 127;
    sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_31 * 3) + (sec_r000604_13 * 2) - pub_r000604_17 + 37) & 127;
    sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_13 + 31) & 127;
    sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_75 * 3) + (sec_r000604_9 * 2) - pub_r000604_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_2 + 28) & 127;
    sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_69 * 3) + (sec_r000604_0 * 2) - pub_r000604_11 + 31) & 127;
    sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_127 * 3) + (sec_r000604_6 * 2) - pub_r000604_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_175 * 3) + (sec_r000604_11 * 2) - pub_r000604_20 + 29) & 127;
    sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_29 * 3) + (sec_r000604_3 * 2) - pub_r000604_18 + 20) & 127;
    sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_3 + 34) & 127;
    sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_30 * 3) + (sec_r000604_4 * 2) - pub_r000604_1 + 21) & 127;
    sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_82 * 3) + (sec_r000604_6 * 2) - pub_r000604_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_163 * 3) + (sec_r000604_8 * 2) - pub_r000604_13 + 30) & 127;
    sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_138 * 3) + (sec_r000604_8 * 2) - pub_r000604_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_147 * 3) + (sec_r000604_0 * 2) - pub_r000604_18 + 7) & 127;
    sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_84 * 3) + (sec_r000604_10 * 2) - pub_r000604_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_110 * 3) + (sec_r000604_12 * 2) - pub_r000604_5 + 27) & 127;
    sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_37 * 3) + (sec_r000604_16 * 2) - pub_r000604_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_54 * 3) + (sec_r000604_12 * 2) - pub_r000604_3 + 31) & 127;
    sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_31 * 3) + (sec_r000604_13 * 2) - pub_r000604_8 + 24) & 127;
    sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_199 * 3) + (sec_r000604_8 * 2) - pub_r000604_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_72 * 3) + (sec_r000604_5 * 2) - pub_r000604_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_150 * 3) + (sec_r000604_11 * 2) - pub_r000604_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_80 * 3) + (sec_r000604_1 * 2) - pub_r000604_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_168 * 3) + (sec_r000604_3 * 2) - pub_r000604_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_211 * 3) + (sec_r000604_14 * 2) - pub_r000604_16 + 10) & 127;
    sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_167 * 3) + (sec_r000604_13 * 2) - pub_r000604_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((sec_r000604_11 * 3) + (sec_r000604_11 * 2) - pub_r000604_7 + 11) & 127;
    sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_20 + 19) & 127;
    sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((sec_r000604_7 * 3) + (sec_r000604_7 * 2) - pub_r000604_20 + 34) & 127;
    sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_126 * 3) + (sec_r000604_1 * 2) - pub_r000604_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_146 * 3) + (sec_r000604_16 * 2) - pub_r000604_12 + 31) & 127;
    sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_153 * 3) + (sec_r000604_6 * 2) - pub_r000604_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_97 * 3) + (sec_r000604_11 * 2) - pub_r000604_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_65 * 3) + (sec_r000604_4 * 2) - pub_r000604_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_55 * 3) + (sec_r000604_5 * 2) - pub_r000604_20 + 5) & 127;
    sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_81 * 3) + (sec_r000604_3 * 2) - pub_r000604_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_22 * 3) + (sec_r000604_4 * 2) - pub_r000604_11 + 16) & 127;
    sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_90 * 3) + (sec_r000604_7 * 2) - pub_r000604_4 + 8) & 127;
    sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_163 * 3) + (sec_r000604_4 * 2) - pub_r000604_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r000604_14 * 3) + (sec_r000604_14 * 2) - pub_r000604_3 + 10) & 127;
    sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r000604_5 * 3) + (sec_r000604_5 * 2) - pub_r000604_7 + 10) & 127;
    sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_1 + 16) & 127;
    sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_143 * 3) + (sec_r000604_11 * 2) - pub_r000604_6 + 4) & 127;
    sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_166 * 3) + (sec_r000604_11 * 2) - pub_r000604_11 + 37) & 127;
    sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_220 * 3) + (sec_r000604_4 * 2) - pub_r000604_11 + 33) & 127;
    sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_159 * 3) + (sec_r000604_16 * 2) - pub_r000604_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_190 * 3) + (sec_r000604_7 * 2) - pub_r000604_12 + 15) & 127;
    sec_accum = (sec_accum + stage_v_235 * 2) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_92 * 3) + (sec_r000604_3 * 2) - pub_r000604_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_169 * 3) + (sec_r000604_4 * 2) - pub_r000604_19 + 16) & 127;
    sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_40 * 3) + (sec_r000604_14 * 2) - pub_r000604_14 + 28) & 127;
    sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_78 * 3) + (sec_r000604_13 * 2) - pub_r000604_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_240 * 2) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_13 + 32) & 127;
    sec_accum = (sec_accum + stage_v_241 * 2) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r000604_10 * 3) + (sec_r000604_10 * 2) - pub_r000604_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((sec_r000604_5 * 3) + (sec_r000604_5 * 2) - pub_r000604_9 + 23) & 127;
    sec_accum = (sec_accum + stage_v_243 * 2) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_181 * 3) + (sec_r000604_5 * 2) - pub_r000604_5 + 28) & 127;
    sec_accum = (sec_accum + stage_v_244 * 2) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_190 * 3) + (sec_r000604_7 * 2) - pub_r000604_7 + 10) & 127;
    sec_accum = (sec_accum + stage_v_245 * 2) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_134 * 3) + (sec_r000604_15 * 2) - pub_r000604_18 + 3) & 127;
    sec_accum = (sec_accum + stage_v_246 * 2) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_67 * 3) + (sec_r000604_11 * 2) - pub_r000604_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_247 * 2) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_130 * 3) + (sec_r000604_5 * 2) - pub_r000604_16 + 4) & 127;
    sec_accum = (sec_accum + stage_v_248 * 2) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_18 + 20) & 127;
    sec_accum = (sec_accum + stage_v_249 * 2) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_20 + 32) & 127;
    sec_accum = (sec_accum + stage_v_250 * 2) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_251 * 2) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r000604_13 * 3) + (sec_r000604_13 * 2) - pub_r000604_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_252 * 2) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_76 * 3) + (sec_r000604_10 * 2) - pub_r000604_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_253 * 2) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_173 * 3) + (sec_r000604_8 * 2) - pub_r000604_8 + 7) & 127;
    sec_accum = (sec_accum + stage_v_254 * 2) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_253 * 3) + (sec_r000604_1 * 2) - pub_r000604_20 + 23) & 127;
    sec_accum = (sec_accum + stage_v_255 * 2) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_213 * 3) + (sec_r000604_16 * 2) - pub_r000604_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_256 * 2) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_32 * 3) + (sec_r000604_2 * 2) - pub_r000604_12 + 21) & 127;
    sec_accum = (sec_accum + stage_v_257 * 2) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_258 * 2) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_15 + 7) & 127;
    sec_accum = (sec_accum + stage_v_259 * 2) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_246 * 3) + (sec_r000604_5 * 2) - pub_r000604_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_260 * 2) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_258 * 3) + (sec_r000604_2 * 2) - pub_r000604_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_261 * 2) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_226 * 3) + (sec_r000604_14 * 2) - pub_r000604_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_262 * 2) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_173 * 3) + (sec_r000604_14 * 2) - pub_r000604_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_263 * 2) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_251 * 3) + (sec_r000604_1 * 2) - pub_r000604_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_264 * 2) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_184 * 3) + (sec_r000604_15 * 2) - pub_r000604_20 + 25) & 127;
    sec_accum = (sec_accum + stage_v_265 * 2) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_167 * 3) + (sec_r000604_6 * 2) - pub_r000604_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_266 * 2) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_235 * 3) + (sec_r000604_9 * 2) - pub_r000604_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_267 * 2) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_159 * 3) + (sec_r000604_12 * 2) - pub_r000604_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_268 * 2) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_269 * 2) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_131 * 3) + (sec_r000604_13 * 2) - pub_r000604_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_270 * 2) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_14 + 22) & 127;
    sec_accum = (sec_accum + stage_v_271 * 2) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_204 * 3) + (sec_r000604_7 * 2) - pub_r000604_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_272 * 2) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_71 * 3) + (sec_r000604_9 * 2) - pub_r000604_14 + 9) & 127;
    sec_accum = (sec_accum + stage_v_273 * 2) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r000604_1 * 3) + (sec_r000604_1 * 2) - pub_r000604_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_274 * 2) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_244 * 3) + (sec_r000604_0 * 2) - pub_r000604_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_275 * 2) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_187 * 3) + (sec_r000604_7 * 2) - pub_r000604_18 + 6) & 127;
    sec_accum = (sec_accum + stage_v_276 * 2) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_1 + 24) & 127;
    sec_accum = (sec_accum + stage_v_277 * 2) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_19 + 9) & 127;
    sec_accum = (sec_accum + stage_v_278 * 2) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_169 * 3) + (sec_r000604_9 * 2) - pub_r000604_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_279 * 2) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((sec_r000604_7 * 3) + (sec_r000604_7 * 2) - pub_r000604_2 + 27) & 127;
    sec_accum = (sec_accum + stage_v_280 * 2) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_77 * 3) + (sec_r000604_8 * 2) - pub_r000604_6 + 5) & 127;
    sec_accum = (sec_accum + stage_v_281 * 2) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_34 * 3) + (sec_r000604_16 * 2) - pub_r000604_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_282 * 2) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r000604_7 * 3) + (sec_r000604_7 * 2) - pub_r000604_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_283 * 2) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((sec_r000604_15 * 3) + (sec_r000604_15 * 2) - pub_r000604_14 + 11) & 127;
    sec_accum = (sec_accum + stage_v_284 * 2) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_122 * 3) + (sec_r000604_14 * 2) - pub_r000604_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_285 * 2) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_162 * 3) + (sec_r000604_1 * 2) - pub_r000604_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_286 * 2) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_273 * 3) + (sec_r000604_6 * 2) - pub_r000604_2 + 15) & 127;
    sec_accum = (sec_accum + stage_v_287 * 2) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_102 * 3) + (sec_r000604_1 * 2) - pub_r000604_5 + 4) & 127;
    sec_accum = (sec_accum + stage_v_288 * 2) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_267 * 3) + (sec_r000604_1 * 2) - pub_r000604_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_289 * 2) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_69 * 3) + (sec_r000604_6 * 2) - pub_r000604_9 + 27) & 127;
    sec_accum = (sec_accum + stage_v_290 * 2) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_85 * 3) + (sec_r000604_14 * 2) - pub_r000604_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_291 * 2) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_250 * 3) + (sec_r000604_11 * 2) - pub_r000604_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_292 * 2) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_195 * 3) + (sec_r000604_8 * 2) - pub_r000604_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_293 * 2) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_18 + 16) & 127;
    sec_accum = (sec_accum + stage_v_294 * 2) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_183 * 3) + (sec_r000604_9 * 2) - pub_r000604_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_295 * 2) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_296 * 2) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_267 * 3) + (sec_r000604_13 * 2) - pub_r000604_9 + 23) & 127;
    sec_accum = (sec_accum + stage_v_297 * 2) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_109 * 3) + (sec_r000604_13 * 2) - pub_r000604_18 + 11) & 127;
    sec_accum = (sec_accum + stage_v_298 * 2) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_269 * 3) + (sec_r000604_3 * 2) - pub_r000604_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_299 * 2) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((sec_r000604_5 * 3) + (sec_r000604_5 * 2) - pub_r000604_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_300 * 2) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_133 * 3) + (sec_r000604_11 * 2) - pub_r000604_12 + 19) & 127;
    sec_accum = (sec_accum + stage_v_301 * 2) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_302 * 2) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_303 * 2) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_213 * 3) + (sec_r000604_4 * 2) - pub_r000604_9 + 9) & 127;
    sec_accum = (sec_accum + stage_v_304 * 2) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_61 * 3) + (sec_r000604_10 * 2) - pub_r000604_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_305 * 2) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_67 * 3) + (sec_r000604_15 * 2) - pub_r000604_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_306 * 2) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_219 * 3) + (sec_r000604_14 * 2) - pub_r000604_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_307 * 2) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_268 * 3) + (sec_r000604_8 * 2) - pub_r000604_1 + 14) & 127;
    sec_accum = (sec_accum + stage_v_308 * 2) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_72 * 3) + (sec_r000604_0 * 2) - pub_r000604_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_309 * 2) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_85 * 3) + (sec_r000604_16 * 2) - pub_r000604_20 + 5) & 127;
    sec_accum = (sec_accum + stage_v_310 * 2) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_210 * 3) + (sec_r000604_9 * 2) - pub_r000604_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_311 * 2) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((sec_r000604_9 * 3) + (sec_r000604_9 * 2) - pub_r000604_19 + 14) & 127;
    sec_accum = (sec_accum + stage_v_312 * 2) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_38 * 3) + (sec_r000604_3 * 2) - pub_r000604_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_313 * 2) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_19 + 11) & 127;
    sec_accum = (sec_accum + stage_v_314 * 2) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_205 * 3) + (sec_r000604_8 * 2) - pub_r000604_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_315 * 2) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((sec_r000604_1 * 3) + (sec_r000604_1 * 2) - pub_r000604_19 + 19) & 127;
    sec_accum = (sec_accum + stage_v_316 * 2) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_317 * 2) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_121 * 3) + (sec_r000604_16 * 2) - pub_r000604_4 + 24) & 127;
    sec_accum = (sec_accum + stage_v_318 * 2) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_6 + 16) & 127;
    sec_accum = (sec_accum + stage_v_319 * 2) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r000604_1 * 3) + (sec_r000604_1 * 2) - pub_r000604_1 + 18) & 127;
    sec_accum = (sec_accum + stage_v_320 * 2) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_244 * 3) + (sec_r000604_12 * 2) - pub_r000604_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_321 * 2) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_74 * 3) + (sec_r000604_5 * 2) - pub_r000604_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_322 * 2) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_239 * 3) + (sec_r000604_0 * 2) - pub_r000604_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_323 * 2) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_324 * 2) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((sec_r000604_10 * 3) + (sec_r000604_10 * 2) - pub_r000604_5 + 15) & 127;
    sec_accum = (sec_accum + stage_v_325 * 2) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_324 * 3) + (sec_r000604_4 * 2) - pub_r000604_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_326 * 2) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((sec_r000604_8 * 3) + (sec_r000604_8 * 2) - pub_r000604_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_327 * 2) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((sec_r000604_0 * 3) + (sec_r000604_0 * 2) - pub_r000604_18 + 28) & 127;
    sec_accum = (sec_accum + stage_v_328 * 2) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_107 * 3) + (sec_r000604_6 * 2) - pub_r000604_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_329 * 2) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_268 * 3) + (sec_r000604_12 * 2) - pub_r000604_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_330 * 2) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_258 * 3) + (sec_r000604_6 * 2) - pub_r000604_12 + 9) & 127;
    sec_accum = (sec_accum + stage_v_331 * 2) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_26 * 3) + (sec_r000604_6 * 2) - pub_r000604_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_332 * 2) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_320 * 3) + (sec_r000604_4 * 2) - pub_r000604_2 + 29) & 127;
    sec_accum = (sec_accum + stage_v_333 * 2) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_334 * 2) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_264 * 3) + (sec_r000604_10 * 2) - pub_r000604_4 + 16) & 127;
    sec_accum = (sec_accum + stage_v_335 * 2) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_50 * 3) + (sec_r000604_0 * 2) - pub_r000604_10 + 32) & 127;
    sec_accum = (sec_accum + stage_v_336 * 2) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_69 * 3) + (sec_r000604_16 * 2) - pub_r000604_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_337 * 2) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((sec_r000604_3 * 3) + (sec_r000604_3 * 2) - pub_r000604_16 + 20) & 127;
    sec_accum = (sec_accum + stage_v_338 * 2) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((stage_v_72 * 3) + (sec_r000604_4 * 2) - pub_r000604_16 + 32) & 127;
    sec_accum = (sec_accum + stage_v_339 * 2) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_159 * 3) + (sec_r000604_9 * 2) - pub_r000604_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_340 * 2) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_292 * 3) + (sec_r000604_6 * 2) - pub_r000604_10 + 4) & 127;
    sec_accum = (sec_accum + stage_v_341 * 2) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((sec_r000604_4 * 3) + (sec_r000604_4 * 2) - pub_r000604_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_342 * 2) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((stage_v_105 * 3) + (sec_r000604_9 * 2) - pub_r000604_8 + 21) & 127;
    sec_accum = (sec_accum + stage_v_343 * 2) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_240 * 3) + (sec_r000604_15 * 2) - pub_r000604_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_344 * 2) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((stage_v_287 * 3) + (sec_r000604_9 * 2) - pub_r000604_17 + 36) & 127;
    sec_accum = (sec_accum + stage_v_345 * 2) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = ((sec_r000604_6 * 3) + (sec_r000604_6 * 2) - pub_r000604_20 + 37) & 127;
    sec_accum = (sec_accum + stage_v_346 * 2) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((sec_r000604_14 * 3) + (sec_r000604_14 * 2) - pub_r000604_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_347 * 2) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_68 * 3) + (sec_r000604_7 * 2) - pub_r000604_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_348 * 2) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = ((stage_v_68 * 3) + (sec_r000604_16 * 2) - pub_r000604_2 + 4) & 127;
    sec_accum = (sec_accum + stage_v_349 * 2) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_268 * 3) + (sec_r000604_10 * 2) - pub_r000604_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_350 * 2) & 255;
    out_sink = (out_sink + stage_v_350) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_283 * 3) + (sec_r000604_15 * 2) - pub_r000604_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_351 * 2) & 255;
    out_sink = (out_sink + stage_v_351) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = ((stage_v_194 * 3) + (sec_r000604_10 * 2) - pub_r000604_20 + 31) & 127;
    sec_accum = (sec_accum + stage_v_352 * 2) & 255;
    out_sink = (out_sink + stage_v_352) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_25 * 3) + (sec_r000604_3 * 2) - pub_r000604_16 + 7) & 127;
    sec_accum = (sec_accum + stage_v_353 * 2) & 255;
    out_sink = (out_sink + stage_v_353) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_331 * 3) + (sec_r000604_9 * 2) - pub_r000604_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_354 * 2) & 255;
    out_sink = (out_sink + stage_v_354) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = ((sec_r000604_2 * 3) + (sec_r000604_2 * 2) - pub_r000604_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_355 * 2) & 255;
    out_sink = (out_sink + stage_v_355) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_204 * 3) + (sec_r000604_6 * 2) - pub_r000604_18 + 29) & 127;
    sec_accum = (sec_accum + stage_v_356 * 2) & 255;
    out_sink = (out_sink + stage_v_356) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_116 * 3) + (sec_r000604_7 * 2) - pub_r000604_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_357 * 2) & 255;
    out_sink = (out_sink + stage_v_357) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_69 * 3) + (sec_r000604_4 * 2) - pub_r000604_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_358 * 2) & 255;
    out_sink = (out_sink + stage_v_358) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_128 * 3) + (sec_r000604_13 * 2) - pub_r000604_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_359 * 2) & 255;
    out_sink = (out_sink + stage_v_359) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_322 * 3) + (sec_r000604_6 * 2) - pub_r000604_19 + 12) & 127;
    sec_accum = (sec_accum + stage_v_360 * 2) & 255;
    out_sink = (out_sink + stage_v_360) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_311 * 3) + (sec_r000604_8 * 2) - pub_r000604_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_361 * 2) & 255;
    out_sink = (out_sink + stage_v_361) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_269 * 3) + (sec_r000604_15 * 2) - pub_r000604_19 + 28) & 127;
    sec_accum = (sec_accum + stage_v_362 * 2) & 255;
    out_sink = (out_sink + stage_v_362) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((sec_r000604_12 * 3) + (sec_r000604_12 * 2) - pub_r000604_18 + 36) & 127;
    sec_accum = (sec_accum + stage_v_363 * 2) & 255;
    out_sink = (out_sink + stage_v_363) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_133 * 3) + (sec_r000604_5 * 2) - pub_r000604_7 + 9) & 127;
    sec_accum = (sec_accum + stage_v_364 * 2) & 255;
    out_sink = (out_sink + stage_v_364) & 255;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_343 * 3) + (sec_r000604_11 * 2) - pub_r000604_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_365 * 2) & 255;
    out_sink = (out_sink + stage_v_365) & 255;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_291 * 3) + (sec_r000604_1 * 2) - pub_r000604_11 + 3) & 127;
    sec_accum = (sec_accum + stage_v_366 * 2) & 255;
    out_sink = (out_sink + stage_v_366) & 255;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_367 * 2) & 255;
    out_sink = (out_sink + stage_v_367) & 255;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_200 * 3) + (sec_r000604_11 * 2) - pub_r000604_5 + 25) & 127;
    sec_accum = (sec_accum + stage_v_368 * 2) & 255;
    out_sink = (out_sink + stage_v_368) & 255;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = ((sec_r000604_16 * 3) + (sec_r000604_16 * 2) - pub_r000604_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_369 * 2) & 255;
    out_sink = (out_sink + stage_v_369) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
