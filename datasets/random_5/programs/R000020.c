/*
 * Benchmark Program: R000020
 * Security Family: mixed_control_data
 * Generator Seed: 502013
 * High Inputs: 23 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000020_2013_0 {
    short trace;
    short determinant;
    unsigned char scale;
    int density;
    int buffer[3];
};

struct Transaction_R000020_2013_1 {
    int rate;
    int account_id;
    unsigned char balance;
    short fee;
    short status;
    int buffer[3];
};

struct AudioFrame_R000020_2013_2 {
    int envelope;
    int sample_rate;
    short channels;
    unsigned char gain;
    int peak;
    int rms;
    int buffer[3];
};

struct SensorNode_R000020_2013_3 {
    int threshold;
    unsigned char status;
    int offset;
    int gain;
    int buffer[3];
};

union PacketPayload_R000020_2013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000020_2013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000020_2013_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000020_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_84) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_1(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int bound_67 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_67 > 36) {
        acc = (acc + bound_67 * 2 + 5) & 127;
        aux ^= (bound_67 & 15);
    } else {
        acc = (acc - bound_67 + 11) & 127;
        aux += 3;
    }
    int sample_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000020_2013_2(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000020_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int anchor_34 = (aux + st.buffer[1]) & 3;
    switch (anchor_34) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_39 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_39 > 13) {
        acc = (acc + sample_39 * 2 + 5) & 127;
        aux ^= (sample_39 & 15);
    } else {
        acc = (acc - sample_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int threshold_21 = (aux + st.buffer[1]) & 3;
    switch (threshold_21) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000020_2013_4(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000020_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int mask_72 = local_arr[aux % 3];
    acc = (acc + mask_72 * 2) & 127;
    int scale_31 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_31 > 42) {
        acc = (acc + scale_31 * 2 + 5) & 127;
        aux ^= (scale_31 & 15);
    } else {
        acc = (acc - scale_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_5(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000020_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int segment_78 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_78 > 30) {
        acc = (acc + segment_78 * 2 + 5) & 127;
        aux ^= (segment_78 & 15);
    } else {
        acc = (acc - segment_78 + 11) & 127;
        aux += 3;
    }
    int scale_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000020_2013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000020_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int residue_58 = (aux + st.buffer[1]) & 3;
    switch (residue_58) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_96 = local_arr[aux % 3];
    acc = (acc + segment_96 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000020_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int metric_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_76) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_26 = (aux + st.buffer[1]) & 3;
    switch (threshold_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_38 = local_arr[aux % 3];
    acc = (acc + residue_38 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int stride_12 = local_arr[aux % 3];
    acc = (acc + stride_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_99 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_99 > 33) {
        acc = (acc + scale_99 * 2 + 5) & 127;
        aux ^= (scale_99 & 15);
    } else {
        acc = (acc - scale_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_9(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000020_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int bound_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_59) & 63;
    acc ^= aux;
    int metric_54 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_54 > 16) {
        acc = (acc + metric_54 * 2 + 5) & 127;
        aux ^= (metric_54 & 15);
    } else {
        acc = (acc - metric_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_65 = local_arr[aux % 3];
    acc = (acc + residue_65 * 2) & 127;
    int parity_41 = (aux + st.buffer[1]) & 3;
    switch (parity_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000020_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int segment_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_89) & 63;
    acc ^= aux;
    int tally_96 = (aux + st.buffer[1]) & 3;
    switch (tally_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_91 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_91 > 22) {
        acc = (acc + threshold_91 * 2 + 5) & 127;
        aux ^= (threshold_91 & 15);
    } else {
        acc = (acc - threshold_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000020_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int anchor_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_58) & 63;
    acc ^= aux;
    int coefficient_12 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_12 > 27) {
        acc = (acc + coefficient_12 * 2 + 5) & 127;
        aux ^= (coefficient_12 & 15);
    } else {
        acc = (acc - coefficient_12 + 11) & 127;
        aux += 3;
    }
    int anchor_69 = (aux + st.buffer[1]) & 3;
    switch (anchor_69) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_62 = local_arr[aux % 3];
    acc = (acc + vector_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_12(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000020_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int factor_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_66) & 63;
    acc ^= aux;
    int parity_78 = (aux + st.buffer[1]) & 3;
    switch (parity_78) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000020_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int index_reg_24 = (aux + st.buffer[1]) & 3;
    switch (index_reg_24) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_64) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_46 = local_arr[aux % 3];
    acc = (acc + sample_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int threshold_55 = local_arr[aux % 3];
    acc = (acc + threshold_55 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_71 = (aux + st.buffer[1]) & 3;
    switch (tracker_71) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_13) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000020_2013_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000020_2013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_50 = (aux + st.buffer[1]) & 3;
    switch (anchor_50) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_73 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_73 > 31) {
        acc = (acc + parity_73 * 2 + 5) & 127;
        aux ^= (parity_73 & 15);
    } else {
        acc = (acc - parity_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_16(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000020_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int window_21 = (st.buffer[0] * 3 + aux) & 63;
    if (window_21 > 27) {
        acc = (acc + window_21 * 2 + 5) & 127;
        aux ^= (window_21 & 15);
    } else {
        acc = (acc - window_21 + 11) & 127;
        aux += 3;
    }
    int delta_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_73) & 63;
    acc ^= aux;
    int metric_16 = (aux + st.buffer[1]) & 3;
    switch (metric_16) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000020_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int damping_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000020_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int stride_98 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_98 > 18) {
        acc = (acc + stride_98 * 2 + 5) & 127;
        aux ^= (stride_98 & 15);
    } else {
        acc = (acc - stride_98 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_58 = local_arr[aux % 3];
    acc = (acc + anchor_58 * 2) & 127;
    int sample_93 = (aux + st.buffer[1]) & 3;
    switch (sample_93) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000020_2013_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int accumulator_98 = (aux + st.buffer[1]) & 3;
    switch (accumulator_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000020_2013_20(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000020_2013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_43 = (aux + st.buffer[1]) & 3;
    switch (checksum_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_66 = local_arr[aux % 3];
    acc = (acc + anchor_66 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000020_2013_21(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000020_2013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int segment_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_63 = local_arr[aux % 3];
    acc = (acc + margin_63 * 2) & 127;
    int quantum_11 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_11 > 39) {
        acc = (acc + quantum_11 * 2 + 5) & 127;
        aux ^= (quantum_11 & 15);
    } else {
        acc = (acc - quantum_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_22(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int tally_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_85) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_87 = local_arr[aux % 3];
    acc = (acc + tracker_87 * 2) & 127;
    int offset_53 = (aux + st.buffer[1]) & 3;
    switch (offset_53) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_10 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_10 > 10) {
        acc = (acc + delta_10 * 2 + 5) & 127;
        aux ^= (delta_10 & 15);
    } else {
        acc = (acc - delta_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000020_2013_23(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000020_2013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int accumulator_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_77) & 63;
    acc ^= aux;
    int tally_62 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_62 > 31) {
        acc = (acc + tally_62 * 2 + 5) & 127;
        aux ^= (tally_62 & 15);
    } else {
        acc = (acc - tally_62 + 11) & 127;
        aux += 3;
    }
    int segment_87 = (aux + st.buffer[1]) & 3;
    switch (segment_87) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_72 = local_arr[aux % 3];
    acc = (acc + bound_72 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000020_0;
    int sec_r000020_1;
    int sec_r000020_2;
    int sec_r000020_3;
    int sec_r000020_4;
    int sec_r000020_5;
    int sec_r000020_6;
    int sec_r000020_7;
    int sec_r000020_8;
    int sec_r000020_9;
    int sec_r000020_10;
    int sec_r000020_11;
    int sec_r000020_12;
    int sec_r000020_13;
    int sec_r000020_14;
    int sec_r000020_15;
    int sec_r000020_16;
    int sec_r000020_17;
    int sec_r000020_18;
    int sec_r000020_19;
    int sec_r000020_20;
    int sec_r000020_21;
    int sec_r000020_22;
    int pub_r000020_0;
    int pub_r000020_1;
    int pub_r000020_2;
    int pub_r000020_3;
    int pub_r000020_4;
    int pub_r000020_5;
    int pub_r000020_6;
    int pub_r000020_7;
    int pub_r000020_8;
    int pub_r000020_9;
    int pub_r000020_10;
    int pub_r000020_11;
    int pub_r000020_12;
    int pub_r000020_13;
    int pub_r000020_14;
    int pub_r000020_15;
    int pub_r000020_16;
    int pub_r000020_17;
    int pub_r000020_18;
    int pub_r000020_19;
    int pub_r000020_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000020_0 >= -100 && pub_r000020_0 <= 100);
    __CPROVER_assume(pub_r000020_1 >= -100 && pub_r000020_1 <= 100);
    __CPROVER_assume(pub_r000020_2 >= -100 && pub_r000020_2 <= 100);
    __CPROVER_assume(pub_r000020_3 >= -100 && pub_r000020_3 <= 100);
    __CPROVER_assume(pub_r000020_4 >= -100 && pub_r000020_4 <= 100);
    __CPROVER_assume(pub_r000020_5 >= -100 && pub_r000020_5 <= 100);
    __CPROVER_assume(pub_r000020_6 >= -100 && pub_r000020_6 <= 100);
    __CPROVER_assume(pub_r000020_7 >= -100 && pub_r000020_7 <= 100);
    __CPROVER_assume(pub_r000020_8 >= -100 && pub_r000020_8 <= 100);
    __CPROVER_assume(pub_r000020_9 >= -100 && pub_r000020_9 <= 100);
    __CPROVER_assume(pub_r000020_10 >= -100 && pub_r000020_10 <= 100);
    __CPROVER_assume(pub_r000020_11 >= -100 && pub_r000020_11 <= 100);
    __CPROVER_assume(pub_r000020_12 >= -100 && pub_r000020_12 <= 100);
    __CPROVER_assume(pub_r000020_13 >= -100 && pub_r000020_13 <= 100);
    __CPROVER_assume(pub_r000020_14 >= -100 && pub_r000020_14 <= 100);
    __CPROVER_assume(pub_r000020_15 >= -100 && pub_r000020_15 <= 100);
    __CPROVER_assume(pub_r000020_16 >= -100 && pub_r000020_16 <= 100);
    __CPROVER_assume(pub_r000020_17 >= -100 && pub_r000020_17 <= 100);
    __CPROVER_assume(pub_r000020_18 >= -100 && pub_r000020_18 <= 100);
    __CPROVER_assume(pub_r000020_19 >= -100 && pub_r000020_19 <= 100);
    __CPROVER_assume(pub_r000020_20 >= -100 && pub_r000020_20 <= 100);
    __CPROVER_assume(sec_r000020_0 >= 0 && sec_r000020_0 <= 255);
    __CPROVER_assume(sec_r000020_1 >= 0 && sec_r000020_1 <= 255);
    __CPROVER_assume(sec_r000020_2 >= 0 && sec_r000020_2 <= 255);
    __CPROVER_assume(sec_r000020_3 >= 0 && sec_r000020_3 <= 255);
    __CPROVER_assume(sec_r000020_4 >= 0 && sec_r000020_4 <= 255);
    __CPROVER_assume(sec_r000020_5 >= 0 && sec_r000020_5 <= 255);
    __CPROVER_assume(sec_r000020_6 >= 0 && sec_r000020_6 <= 255);
    __CPROVER_assume(sec_r000020_7 >= 0 && sec_r000020_7 <= 255);
    __CPROVER_assume(sec_r000020_8 >= 0 && sec_r000020_8 <= 255);
    __CPROVER_assume(sec_r000020_9 >= 0 && sec_r000020_9 <= 255);
    __CPROVER_assume(sec_r000020_10 >= 0 && sec_r000020_10 <= 255);
    __CPROVER_assume(sec_r000020_11 >= 0 && sec_r000020_11 <= 255);
    __CPROVER_assume(sec_r000020_12 >= 0 && sec_r000020_12 <= 255);
    __CPROVER_assume(sec_r000020_13 >= 0 && sec_r000020_13 <= 255);
    __CPROVER_assume(sec_r000020_14 >= 0 && sec_r000020_14 <= 255);
    __CPROVER_assume(sec_r000020_15 >= 0 && sec_r000020_15 <= 255);
    __CPROVER_assume(sec_r000020_16 >= 0 && sec_r000020_16 <= 255);
    __CPROVER_assume(sec_r000020_17 >= 0 && sec_r000020_17 <= 255);
    __CPROVER_assume(sec_r000020_18 >= 0 && sec_r000020_18 <= 255);
    __CPROVER_assume(sec_r000020_19 >= 0 && sec_r000020_19 <= 255);
    __CPROVER_assume(sec_r000020_20 >= 0 && sec_r000020_20 <= 255);
    __CPROVER_assume(sec_r000020_21 >= 0 && sec_r000020_21 <= 255);
    __CPROVER_assume(sec_r000020_22 >= 0 && sec_r000020_22 <= 255);

    struct MatrixBlock_R000020_2013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000020_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000020_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000020_0 + 7) & 15;
    struct Transaction_R000020_2013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000020_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000020_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000020_0 + 9) & 15;
    struct AudioFrame_R000020_2013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000020_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000020_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000020_0 + 11) & 15;
    struct SensorNode_R000020_2013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000020_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000020_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000020_0 + 13) & 15;

    union PacketPayload_R000020_2013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 27) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 42) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 34) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 49) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 14) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 29) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 30) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 45) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((sec_r000020_7 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_12 > 20) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((stage_v_12 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_13 > 35) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((stage_v_13 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_12 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_15 > 35) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_12 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_16 > 40) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_12 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_17 > 49) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r000020_19 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_18 > 39) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r000020_3 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_12 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_20 > 26) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_20 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_21 > 44) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((stage_v_20 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_22 > 34) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_18 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_23 > 21) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_18 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_24 > 32) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_21 ^ 0x2A) + pub_r000020_16) & 127;
    if (stage_v_25 > 36) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_22 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_26 > 50) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_19 ^ 0x2A) + pub_r000020_16) & 127;
    if (stage_v_27 > 28) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_19 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_28 > 44) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_19 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_29 > 31) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_26 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_30 > 34) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_29 ^ 0x2A) + pub_r000020_11) & 127;
    if (stage_v_31 > 33) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_20 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_32 > 37) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000020_15 ^ 0x2A) + pub_r000020_12) & 127;
    if (stage_v_33 > 37) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_17 ^ 0x2A) + pub_r000020_16) & 127;
    if (stage_v_34 > 36) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_19 ^ 0x2A) + pub_r000020_20) & 127;
    if (stage_v_35 > 27) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_19 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_36 > 44) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r000020_1 ^ 0x2A) + pub_r000020_12) & 127;
    if (stage_v_37 > 50) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_33 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_38 > 49) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_16 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_39 > 25) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_12 ^ 0x2A) + pub_r000020_12) & 127;
    if (stage_v_40 > 36) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_23 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_41 > 23) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_38 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_42 > 43) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((sec_r000020_9 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_43 > 20) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r000020_2 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_44 > 34) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_13 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_45 > 37) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_20 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_46 > 20) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_29 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_47 > 42) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_15 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_48 > 46) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((stage_v_33 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_49 > 22) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r000020_5 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_50 > 48) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_23 ^ 0x2A) + pub_r000020_11) & 127;
    if (stage_v_51 > 43) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_44 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_52 > 25) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_21 ^ 0x2A) + pub_r000020_12) & 127;
    if (stage_v_53 > 37) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_19 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_54 > 26) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r000020_3 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_55 > 29) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r000020_1 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_56 > 40) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r000020_15 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_57 > 49) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_42 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_58 > 29) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_48 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_59 > 31) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_28 ^ 0x2A) + pub_r000020_16) & 127;
    if (stage_v_60 > 22) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_35 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_61 > 50) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_39 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_62 > 37) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_20 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_63 > 33) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_34 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_64 > 36) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r000020_12 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_65 > 41) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_36 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_66 > 38) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_55 ^ 0x2A) + pub_r000020_14) & 127;
    if (stage_v_67 > 26) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_45 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_68 > 33) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r000020_1 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_69 > 20) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000020_8 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_70 > 35) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_25 ^ 0x2A) + pub_r000020_11) & 127;
    if (stage_v_71 > 27) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r000020_10 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_72 > 33) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_46 ^ 0x2A) + pub_r000020_14) & 127;
    if (stage_v_73 > 25) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000020_13 ^ 0x2A) + pub_r000020_20) & 127;
    if (stage_v_74 > 42) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_28 ^ 0x2A) + pub_r000020_20) & 127;
    if (stage_v_75 > 31) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_71 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_76 > 30) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((sec_r000020_14 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_77 > 26) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_73 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_78 > 37) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_48 ^ 0x2A) + pub_r000020_14) & 127;
    if (stage_v_79 > 28) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_42 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_80 > 23) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_69 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_81 > 24) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_14 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_82 > 30) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_64 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_83 > 26) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000020_21 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_84 > 35) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_75 ^ 0x2A) + pub_r000020_11) & 127;
    if (stage_v_85 > 46) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_13 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_84 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_87 > 39) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_55 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_88 > 38) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000020_6 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_89 > 22) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((sec_r000020_22 ^ 0x2A) + pub_r000020_20) & 127;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000020_8 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_91 > 50) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_74 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_92 > 35) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000020_11 ^ 0x2A) + pub_r000020_14) & 127;
    if (stage_v_93 > 43) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r000020_11 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_94 > 41) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_85 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_95 > 47) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_74 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_96 > 38) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((sec_r000020_7 ^ 0x2A) + pub_r000020_16) & 127;
    if (stage_v_97 > 31) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r000020_19 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_98 > 41) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000020_11 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_99 > 27) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000020_0 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_100 > 31) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r000020_12 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_101 > 47) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_21 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_102 > 40) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_13 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_103 > 29) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_23 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_104 > 32) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_78 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_105 > 25) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r000020_3 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_106 > 24) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((sec_r000020_8 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_107 > 38) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((sec_r000020_20 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_108 > 30) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_49 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_109 > 23) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000020_7 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_110 > 41) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000020_1 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_111 > 31) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_58 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_112 > 36) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r000020_21 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_113 > 33) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_59 ^ 0x2A) + pub_r000020_16) & 127;
    if (stage_v_114 > 46) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r000020_20 ^ 0x2A) + pub_r000020_20) & 127;
    if (stage_v_115 > 50) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r000020_10 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_116 > 41) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((sec_r000020_1 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_117 > 35) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_14 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_118 > 30) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_39 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_119 > 48) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_52 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_120 > 39) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_31 ^ 0x2A) + pub_r000020_20) & 127;
    if (stage_v_121 > 32) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_71 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_122 > 39) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_63 ^ 0x2A) + pub_r000020_11) & 127;
    if (stage_v_123 > 35) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r000020_12 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_124 > 38) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_16 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_125 > 22) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000020_7 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_126 > 29) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_122 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_127 > 41) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_15 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_128 > 25) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_61 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_129 > 31) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000020_10 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_130 > 38) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_21 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_131 > 25) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r000020_2 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_132 > 41) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_71 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_133 > 27) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_92 ^ 0x2A) + pub_r000020_11) & 127;
    if (stage_v_134 > 45) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000020_18 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_135 > 46) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_108 ^ 0x2A) + pub_r000020_12) & 127;
    if (stage_v_136 > 44) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((sec_r000020_20 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_137 > 50) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r000020_7 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_138 > 29) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_42 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_139 > 50) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_76 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_140 > 48) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_67 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_141 > 46) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_59 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_142 > 42) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((sec_r000020_8 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_143 > 50) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_95 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_144 > 28) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r000020_4 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_145 > 39) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_118 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_146 > 23) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_23 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_147 > 45) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_37 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_148 > 44) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_144 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_149 > 47) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_129 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_150 > 34) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000020_18 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_151 > 34) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r000020_2 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_152 > 20) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_92 ^ 0x2A) + pub_r000020_8) & 127;
    if (stage_v_153 > 24) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_48 ^ 0x2A) + pub_r000020_14) & 127;
    if (stage_v_154 > 29) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_103 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_155 > 20) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_97 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_156 > 29) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000020_17 ^ 0x2A) + pub_r000020_14) & 127;
    if (stage_v_157 > 44) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_49 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_158 > 28) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000020_9 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_159 > 47) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_52 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_160 > 24) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000020_16 ^ 0x2A) + pub_r000020_3) & 127;
    if (stage_v_161 > 49) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_104 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_162 > 39) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((sec_r000020_10 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_163 > 46) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_105 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_164 > 27) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000020_19 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_165 > 45) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_69 ^ 0x2A) + pub_r000020_3) & 127;
    if (stage_v_166 > 47) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_90 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_167 > 29) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_144 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_168 > 36) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_106 ^ 0x2A) + pub_r000020_13) & 127;
    if (stage_v_169 > 48) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_28 ^ 0x2A) + pub_r000020_17) & 127;
    if (stage_v_170 > 41) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_21 ^ 0x2A) + pub_r000020_4) & 127;
    if (stage_v_171 > 30) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_139 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_172 > 30) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((sec_r000020_0 ^ 0x2A) + pub_r000020_10) & 127;
    if (stage_v_173 > 39) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r000020_2 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_174 > 47) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_171 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_175 > 46) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_125 ^ 0x2A) + pub_r000020_18) & 127;
    if (stage_v_176 > 49) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_83 ^ 0x2A) + pub_r000020_5) & 127;
    if (stage_v_177 > 40) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_51 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_178 > 25) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_29 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_179 > 44) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000020_15 ^ 0x2A) + pub_r000020_19) & 127;
    if (stage_v_180 > 23) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_51 ^ 0x2A) + pub_r000020_9) & 127;
    if (stage_v_181 > 41) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000020_19 ^ 0x2A) + pub_r000020_15) & 127;
    if (stage_v_182 > 39) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_90 ^ 0x2A) + pub_r000020_2) & 127;
    if (stage_v_183 > 43) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r000020_13 ^ 0x2A) + pub_r000020_0) & 127;
    if (stage_v_184 > 29) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_70 ^ 0x2A) + pub_r000020_1) & 127;
    if (stage_v_185 > 50) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_77 ^ 0x2A) + pub_r000020_6) & 127;
    if (stage_v_186 > 48) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_90 ^ 0x2A) + pub_r000020_7) & 127;
    if (stage_v_187 > 36) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
