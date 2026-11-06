/*
 * Benchmark Program: R000308
 * Security Family: secret_dependent_loops
 * Generator Seed: 530813
 * High Inputs: 20 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000308_813_0 {
    unsigned char channels;
    int gain;
    unsigned char sample_rate;
    int envelope;
    int buffer[3];
};

struct DeviceConfig_R000308_813_1 {
    int port;
    short baud_rate;
    short id;
    int buffer[3];
};

struct MatrixBlock_R000308_813_2 {
    int stride;
    unsigned char density;
    int dim;
    int buffer[3];
};

struct CipherContext_R000308_813_3 {
    int nonce;
    int round_key;
    short flags;
    int buffer[3];
};

union PacketPayload_R000308_813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000308_813_0(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int cursor_56 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_56 > 11) {
        acc = (acc + cursor_56 * 2 + 5) & 127;
        aux ^= (cursor_56 & 15);
    } else {
        acc = (acc - cursor_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000308_813_1(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_85 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_85 > 37) {
        acc = (acc + pivot_85 * 2 + 5) & 127;
        aux ^= (pivot_85 & 15);
    } else {
        acc = (acc - pivot_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_2(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000308_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int stride_78 = local_arr[aux % 3];
    acc = (acc + stride_78 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_69 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_69 > 22) {
        acc = (acc + threshold_69 * 2 + 5) & 127;
        aux ^= (threshold_69 & 15);
    } else {
        acc = (acc - threshold_69 + 11) & 127;
        aux += 3;
    }
    int index_reg_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000308_813_3(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000308_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int stride_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_83) & 63;
    acc ^= aux;
    int quotient_42 = (aux + st.buffer[1]) & 3;
    switch (quotient_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_75 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_75 > 14) {
        acc = (acc + mask_75 * 2 + 5) & 127;
        aux ^= (mask_75 & 15);
    } else {
        acc = (acc - mask_75 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_72) & 63;
    acc ^= aux;
    int window_76 = (st.buffer[0] * 3 + aux) & 63;
    if (window_76 > 13) {
        acc = (acc + window_76 * 2 + 5) & 127;
        aux ^= (window_76 & 15);
    } else {
        acc = (acc - window_76 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_97 = local_arr[aux % 3];
    acc = (acc + tally_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000308_813_5(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int factor_29 = local_arr[aux % 3];
    acc = (acc + factor_29 * 2) & 127;
    int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_62) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_13 = (aux + st.buffer[1]) & 3;
    switch (quantum_13) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_11 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_11 > 37) {
        acc = (acc + quotient_11 * 2 + 5) & 127;
        aux ^= (quotient_11 & 15);
    } else {
        acc = (acc - quotient_11 + 11) & 127;
        aux += 3;
    }
    int pivot_19 = (aux + st.buffer[1]) & 3;
    switch (pivot_19) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_86 = local_arr[aux % 3];
    acc = (acc + factor_86 * 2) & 127;
    int parity_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000308_813_7(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int pivot_44 = local_arr[aux % 3];
    acc = (acc + pivot_44 * 2) & 127;
    int margin_53 = (aux + st.buffer[1]) & 3;
    switch (margin_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_17 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_17 > 15) {
        acc = (acc + stride_17 * 2 + 5) & 127;
        aux ^= (stride_17 & 15);
    } else {
        acc = (acc - stride_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int factor_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_52) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_47 = local_arr[aux % 3];
    acc = (acc + parity_47 * 2) & 127;
    int segment_98 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_98 > 43) {
        acc = (acc + segment_98 * 2 + 5) & 127;
        aux ^= (segment_98 & 15);
    } else {
        acc = (acc - segment_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_9(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000308_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int checksum_22 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_22 > 42) {
        acc = (acc + checksum_22 * 2 + 5) & 127;
        aux ^= (checksum_22 & 15);
    } else {
        acc = (acc - checksum_22 + 11) & 127;
        aux += 3;
    }
    int cursor_65 = (aux + st.buffer[1]) & 3;
    switch (cursor_65) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000308_813_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_12 = local_arr[aux % 3];
    acc = (acc + accumulator_12 * 2) & 127;
    int mask_95 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_95 > 30) {
        acc = (acc + mask_95 * 2 + 5) & 127;
        aux ^= (mask_95 & 15);
    } else {
        acc = (acc - mask_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_11(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int delta_92 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_92 > 22) {
        acc = (acc + delta_92 * 2 + 5) & 127;
        aux ^= (delta_92 & 15);
    } else {
        acc = (acc - delta_92 + 11) & 127;
        aux += 3;
    }
    int threshold_51 = (aux + st.buffer[1]) & 3;
    switch (threshold_51) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_83 = local_arr[aux % 3];
    acc = (acc + vector_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000308_813_12(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_72 = (aux + st.buffer[1]) & 3;
    switch (window_72) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_13(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_11 = (aux + st.buffer[1]) & 3;
    switch (metric_11) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_14(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000308_813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int quotient_59 = local_arr[aux % 3];
    acc = (acc + quotient_59 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_52 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_52 > 33) {
        acc = (acc + offset_52 * 2 + 5) & 127;
        aux ^= (offset_52 & 15);
    } else {
        acc = (acc - offset_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000308_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int factor_92 = (aux + st.buffer[1]) & 3;
    switch (factor_92) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_46 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_46 > 22) {
        acc = (acc + bound_46 * 2 + 5) & 127;
        aux ^= (bound_46 & 15);
    } else {
        acc = (acc - bound_46 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_70 = local_arr[aux % 3];
    acc = (acc + tally_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000308_813_16(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000308_813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_93 = (aux + st.buffer[1]) & 3;
    switch (sample_93) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_28 = local_arr[aux % 3];
    acc = (acc + tracker_28 * 2) & 127;
    int parity_92 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_92 > 30) {
        acc = (acc + parity_92 * 2 + 5) & 127;
        aux ^= (parity_92 & 15);
    } else {
        acc = (acc - parity_92 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_17(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int delta_55 = (aux + st.buffer[1]) & 3;
    switch (delta_55) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_13 = local_arr[aux % 3];
    acc = (acc + factor_13 * 2) & 127;
    int residue_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000308_813_18(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000308_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int stride_46 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_46 > 37) {
        acc = (acc + stride_46 * 2 + 5) & 127;
        aux ^= (stride_46 & 15);
    } else {
        acc = (acc - stride_46 + 11) & 127;
        aux += 3;
    }
    int phase_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000308_813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int damping_79 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_79 > 14) {
        acc = (acc + damping_79 * 2 + 5) & 127;
        aux ^= (damping_79 & 15);
    } else {
        acc = (acc - damping_79 + 11) & 127;
        aux += 3;
    }
    int residue_14 = (aux + st.buffer[1]) & 3;
    switch (residue_14) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000308_813_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000308_813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_61 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_61 > 21) {
        acc = (acc + tally_61 * 2 + 5) & 127;
        aux ^= (tally_61 & 15);
    } else {
        acc = (acc - tally_61 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_45) & 63;
    acc ^= aux;
    int bound_79 = (aux + st.buffer[1]) & 3;
    switch (bound_79) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000308_813_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_18 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_18 > 42) {
        acc = (acc + quotient_18 * 2 + 5) & 127;
        aux ^= (quotient_18 & 15);
    } else {
        acc = (acc - quotient_18 + 11) & 127;
        aux += 3;
    }
    int damping_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_50) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000308_813_22(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000308_813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_65 = (aux + st.buffer[1]) & 3;
    switch (cursor_65) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_84 = local_arr[aux % 3];
    acc = (acc + weight_84 * 2) & 127;
    int vector_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000308_0;
    int sec_r000308_1;
    int sec_r000308_2;
    int sec_r000308_3;
    int sec_r000308_4;
    int sec_r000308_5;
    int sec_r000308_6;
    int sec_r000308_7;
    int sec_r000308_8;
    int sec_r000308_9;
    int sec_r000308_10;
    int sec_r000308_11;
    int sec_r000308_12;
    int sec_r000308_13;
    int sec_r000308_14;
    int sec_r000308_15;
    int sec_r000308_16;
    int sec_r000308_17;
    int sec_r000308_18;
    int sec_r000308_19;
    int pub_r000308_0;
    int pub_r000308_1;
    int pub_r000308_2;
    int pub_r000308_3;
    int pub_r000308_4;
    int pub_r000308_5;
    int pub_r000308_6;
    int pub_r000308_7;
    int pub_r000308_8;
    int pub_r000308_9;
    int pub_r000308_10;
    int pub_r000308_11;
    int pub_r000308_12;
    int pub_r000308_13;
    int pub_r000308_14;
    int pub_r000308_15;
    int pub_r000308_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000308_0 >= -100 && pub_r000308_0 <= 100);
    __CPROVER_assume(pub_r000308_1 >= -100 && pub_r000308_1 <= 100);
    __CPROVER_assume(pub_r000308_2 >= -100 && pub_r000308_2 <= 100);
    __CPROVER_assume(pub_r000308_3 >= -100 && pub_r000308_3 <= 100);
    __CPROVER_assume(pub_r000308_4 >= -100 && pub_r000308_4 <= 100);
    __CPROVER_assume(pub_r000308_5 >= -100 && pub_r000308_5 <= 100);
    __CPROVER_assume(pub_r000308_6 >= -100 && pub_r000308_6 <= 100);
    __CPROVER_assume(pub_r000308_7 >= -100 && pub_r000308_7 <= 100);
    __CPROVER_assume(pub_r000308_8 >= -100 && pub_r000308_8 <= 100);
    __CPROVER_assume(pub_r000308_9 >= -100 && pub_r000308_9 <= 100);
    __CPROVER_assume(pub_r000308_10 >= -100 && pub_r000308_10 <= 100);
    __CPROVER_assume(pub_r000308_11 >= -100 && pub_r000308_11 <= 100);
    __CPROVER_assume(pub_r000308_12 >= -100 && pub_r000308_12 <= 100);
    __CPROVER_assume(pub_r000308_13 >= -100 && pub_r000308_13 <= 100);
    __CPROVER_assume(pub_r000308_14 >= -100 && pub_r000308_14 <= 100);
    __CPROVER_assume(pub_r000308_15 >= -100 && pub_r000308_15 <= 100);
    __CPROVER_assume(pub_r000308_16 >= -100 && pub_r000308_16 <= 100);
    __CPROVER_assume(sec_r000308_0 >= 0 && sec_r000308_0 <= 255);
    __CPROVER_assume(sec_r000308_1 >= 0 && sec_r000308_1 <= 255);
    __CPROVER_assume(sec_r000308_2 >= 0 && sec_r000308_2 <= 255);
    __CPROVER_assume(sec_r000308_3 >= 0 && sec_r000308_3 <= 255);
    __CPROVER_assume(sec_r000308_4 >= 0 && sec_r000308_4 <= 255);
    __CPROVER_assume(sec_r000308_5 >= 0 && sec_r000308_5 <= 255);
    __CPROVER_assume(sec_r000308_6 >= 0 && sec_r000308_6 <= 255);
    __CPROVER_assume(sec_r000308_7 >= 0 && sec_r000308_7 <= 255);
    __CPROVER_assume(sec_r000308_8 >= 0 && sec_r000308_8 <= 255);
    __CPROVER_assume(sec_r000308_9 >= 0 && sec_r000308_9 <= 255);
    __CPROVER_assume(sec_r000308_10 >= 0 && sec_r000308_10 <= 255);
    __CPROVER_assume(sec_r000308_11 >= 0 && sec_r000308_11 <= 255);
    __CPROVER_assume(sec_r000308_12 >= 0 && sec_r000308_12 <= 255);
    __CPROVER_assume(sec_r000308_13 >= 0 && sec_r000308_13 <= 255);
    __CPROVER_assume(sec_r000308_14 >= 0 && sec_r000308_14 <= 255);
    __CPROVER_assume(sec_r000308_15 >= 0 && sec_r000308_15 <= 255);
    __CPROVER_assume(sec_r000308_16 >= 0 && sec_r000308_16 <= 255);
    __CPROVER_assume(sec_r000308_17 >= 0 && sec_r000308_17 <= 255);
    __CPROVER_assume(sec_r000308_18 >= 0 && sec_r000308_18 <= 255);
    __CPROVER_assume(sec_r000308_19 >= 0 && sec_r000308_19 <= 255);

    struct AudioFrame_R000308_813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000308_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000308_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000308_0 + 7) & 15;
    struct DeviceConfig_R000308_813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000308_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000308_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000308_0 + 9) & 15;
    struct MatrixBlock_R000308_813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000308_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000308_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000308_0 + 11) & 15;
    struct CipherContext_R000308_813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000308_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000308_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000308_0 + 13) & 15;

    union PacketPayload_R000308_813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_3.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 24) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 39) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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
    int stage_v_15 = (st_var_3.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 32) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 47) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_29 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 22) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 37) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_2.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_3.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 12) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 27) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_14 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000308_12) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000308_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000308_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_14 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000308_5) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000308_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000308_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000308_0) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000308_7) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000308_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_0 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000308_14) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000308_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000308_13) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000308_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_12 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000308_12) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000308_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_16 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000308_11) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000308_7) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000308_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000308_4) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_5 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000308_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000308_14) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_66 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000308_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_12 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000308_11) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000308_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_14 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000308_3) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000308_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000308_16) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000308_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000308_13) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000308_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000308_5) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_5 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000308_0) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000308_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000308_5) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000308_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000308_4) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000308_15) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000308_16) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000308_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_7 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000308_16) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000308_6) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000308_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_8 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_1 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000308_14) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000308_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000308_3) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000308_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_11 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000308_6) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000308_7) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000308_0) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_6 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000308_12) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000308_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000308_15) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000308_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000308_3) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000308_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_70 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000308_0) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_68 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000308_5) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000308_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000308_5) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000308_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000308_1) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_8 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000308_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000308_16) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000308_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000308_12) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000308_6) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000308_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000308_1) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000308_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_108 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000308_1) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000308_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_111 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000308_3) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000308_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_120 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000308_4) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000308_11) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000308_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000308_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000308_14) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000308_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000308_4) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000308_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_0 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000308_4) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000308_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000308_0) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000308_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000308_11) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000308_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000308_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_125 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000308_1) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000308_6) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000308_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_104 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000308_16) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000308_3) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000308_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_5 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000308_5) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000308_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000308_15) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000308_9) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000308_1) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000308_14) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000308_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_5 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000308_6) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000308_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_138 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000308_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_82 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000308_14) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000308_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000308_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000308_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000308_8) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000308_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000308_10) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000308_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000308_10 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000308_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000308_2) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000308_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_63 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000308_15) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000308_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
