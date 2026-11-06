/*
 * Benchmark Program: R000627
 * Security Family: nested_implicit_flow
 * Generator Seed: 562713
 * High Inputs: 20 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000627_2713_0 {
    short trace;
    int determinant;
    int scale;
    int buffer[3];
};

struct CipherContext_R000627_2713_1 {
    unsigned char iv;
    short counter;
    unsigned char tag;
    int buffer[3];
};

struct SensorNode_R000627_2713_2 {
    short reading;
    int gain;
    int threshold;
    int buffer[3];
};

struct StreamBuffer_R000627_2713_3 {
    int tail;
    short capacity;
    int watermark;
    int head;
    int buffer[3];
};

union PacketPayload_R000627_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000627_2713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tracker_19 = (aux + st.buffer[1]) & 3;
    switch (tracker_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_68) & 63;
    acc ^= aux;
    int tracker_67 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_67 > 21) {
        acc = (acc + tracker_67 * 2 + 5) & 127;
        aux ^= (tracker_67 & 15);
    } else {
        acc = (acc - tracker_67 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_1(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int phase_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_39) & 63;
    acc ^= aux;
    int bound_19 = (aux + st.buffer[1]) & 3;
    switch (bound_19) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_2(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int offset_97 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_97 > 45) {
        acc = (acc + offset_97 * 2 + 5) & 127;
        aux ^= (offset_97 & 15);
    } else {
        acc = (acc - offset_97 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_42 = local_arr[aux % 3];
    acc = (acc + anchor_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_87) & 63;
    acc ^= aux;
    int anchor_82 = (aux + st.buffer[1]) & 3;
    switch (anchor_82) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_20 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_20 > 28) {
        acc = (acc + mask_20 * 2 + 5) & 127;
        aux ^= (mask_20 & 15);
    } else {
        acc = (acc - mask_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_4(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int anchor_46 = local_arr[aux % 3];
    acc = (acc + anchor_46 * 2) & 127;
    int offset_87 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_87 > 24) {
        acc = (acc + offset_87 * 2 + 5) & 127;
        aux ^= (offset_87 & 15);
    } else {
        acc = (acc - offset_87 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_59 = (aux + st.buffer[1]) & 3;
    switch (checksum_59) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_5(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quotient_73 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_73 > 45) {
        acc = (acc + quotient_73 * 2 + 5) & 127;
        aux ^= (quotient_73 & 15);
    } else {
        acc = (acc - quotient_73 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_54 = local_arr[aux % 3];
    acc = (acc + damping_54 * 2) & 127;
    int sample_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000627_2713_6(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int quantum_46 = local_arr[aux % 3];
    acc = (acc + quantum_46 * 2) & 127;
    int stride_81 = (aux + st.buffer[1]) & 3;
    switch (stride_81) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_7(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int stride_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_32) & 63;
    acc ^= aux;
    int coefficient_82 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_82 > 15) {
        acc = (acc + coefficient_82 * 2 + 5) & 127;
        aux ^= (coefficient_82 & 15);
    } else {
        acc = (acc - coefficient_82 + 11) & 127;
        aux += 3;
    }
    int weight_62 = (aux + st.buffer[1]) & 3;
    switch (weight_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int anchor_10 = local_arr[aux % 3];
    acc = (acc + anchor_10 * 2) & 127;
    int residue_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_93 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_93) & 63;
    acc ^= aux;
    int margin_90 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_90 > 22) {
        acc = (acc + margin_90 * 2 + 5) & 127;
        aux ^= (margin_90 & 15);
    } else {
        acc = (acc - margin_90 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_30 = local_arr[aux % 3];
    acc = (acc + factor_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_10(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int cursor_37 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_37 > 46) {
        acc = (acc + cursor_37 * 2 + 5) & 127;
        aux ^= (cursor_37 & 15);
    } else {
        acc = (acc - cursor_37 + 11) & 127;
        aux += 3;
    }
    int threshold_92 = (aux + st.buffer[1]) & 3;
    switch (threshold_92) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_11(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int delta_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_97) & 63;
    acc ^= aux;
    int bound_76 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_76 > 41) {
        acc = (acc + bound_76 * 2 + 5) & 127;
        aux ^= (bound_76 & 15);
    } else {
        acc = (acc - bound_76 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_12(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int phase_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_23) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_99 = (aux + st.buffer[1]) & 3;
    switch (coefficient_99) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_73 = local_arr[aux % 3];
    acc = (acc + quantum_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_13(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000627_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_72 = local_arr[aux % 3];
    acc = (acc + anchor_72 * 2) & 127;
    int checksum_10 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_10 > 33) {
        acc = (acc + checksum_10 * 2 + 5) & 127;
        aux ^= (checksum_10 & 15);
    } else {
        acc = (acc - checksum_10 + 11) & 127;
        aux += 3;
    }
    int weight_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000627_2713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int phase_44 = local_arr[aux % 3];
    acc = (acc + phase_44 * 2) & 127;
    int weight_14 = (aux + st.buffer[1]) & 3;
    switch (weight_14) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int anchor_34 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_34 > 50) {
        acc = (acc + anchor_34 * 2 + 5) & 127;
        aux ^= (anchor_34 & 15);
    } else {
        acc = (acc - anchor_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_74 = local_arr[aux % 3];
    acc = (acc + margin_74 * 2) & 127;
    int metric_16 = (aux + st.buffer[1]) & 3;
    switch (metric_16) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000627_2713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int vector_24 = local_arr[aux % 3];
    acc = (acc + vector_24 * 2) & 127;
    int delta_83 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_83 > 10) {
        acc = (acc + delta_83 * 2 + 5) & 127;
        aux ^= (delta_83 & 15);
    } else {
        acc = (acc - delta_83 + 11) & 127;
        aux += 3;
    }
    int quantum_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000627_2713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000627_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_96 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_96 > 21) {
        acc = (acc + scale_96 * 2 + 5) & 127;
        aux ^= (scale_96 & 15);
    } else {
        acc = (acc - scale_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_18) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_61 = local_arr[aux % 3];
    acc = (acc + bound_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_18(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_92 = (aux + st.buffer[1]) & 3;
    switch (bound_92) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_11) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000627_2713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000627_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int anchor_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_73) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_17 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_17 > 23) {
        acc = (acc + weight_17 * 2 + 5) & 127;
        aux ^= (weight_17 & 15);
    } else {
        acc = (acc - weight_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_94 = local_arr[aux % 3];
    acc = (acc + quotient_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_20(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quantum_26 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_26 > 34) {
        acc = (acc + quantum_26 * 2 + 5) & 127;
        aux ^= (quantum_26 & 15);
    } else {
        acc = (acc - quantum_26 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_27 = local_arr[aux % 3];
    acc = (acc + vector_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000627_2713_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_28) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_99 = local_arr[aux % 3];
    acc = (acc + margin_99 * 2) & 127;
    int factor_43 = (aux + st.buffer[1]) & 3;
    switch (factor_43) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_22(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int mask_27 = (aux + st.buffer[1]) & 3;
    switch (mask_27) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_59 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_59 > 39) {
        acc = (acc + quantum_59 * 2 + 5) & 127;
        aux ^= (quantum_59 & 15);
    } else {
        acc = (acc - quantum_59 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000627_2713_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000627_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_11 = (aux + st.buffer[1]) & 3;
    switch (segment_11) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int scale_26 = local_arr[aux % 3];
    acc = (acc + scale_26 * 2) & 127;
    int window_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000627_0;
    int sec_r000627_1;
    int sec_r000627_2;
    int sec_r000627_3;
    int sec_r000627_4;
    int sec_r000627_5;
    int sec_r000627_6;
    int sec_r000627_7;
    int sec_r000627_8;
    int sec_r000627_9;
    int sec_r000627_10;
    int sec_r000627_11;
    int sec_r000627_12;
    int sec_r000627_13;
    int sec_r000627_14;
    int sec_r000627_15;
    int sec_r000627_16;
    int sec_r000627_17;
    int sec_r000627_18;
    int sec_r000627_19;
    int pub_r000627_0;
    int pub_r000627_1;
    int pub_r000627_2;
    int pub_r000627_3;
    int pub_r000627_4;
    int pub_r000627_5;
    int pub_r000627_6;
    int pub_r000627_7;
    int pub_r000627_8;
    int pub_r000627_9;
    int pub_r000627_10;
    int pub_r000627_11;
    int pub_r000627_12;
    int pub_r000627_13;
    int pub_r000627_14;
    int pub_r000627_15;
    int pub_r000627_16;
    int pub_r000627_17;
    int pub_r000627_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000627_0 >= -100 && pub_r000627_0 <= 100);
    __CPROVER_assume(pub_r000627_1 >= -100 && pub_r000627_1 <= 100);
    __CPROVER_assume(pub_r000627_2 >= -100 && pub_r000627_2 <= 100);
    __CPROVER_assume(pub_r000627_3 >= -100 && pub_r000627_3 <= 100);
    __CPROVER_assume(pub_r000627_4 >= -100 && pub_r000627_4 <= 100);
    __CPROVER_assume(pub_r000627_5 >= -100 && pub_r000627_5 <= 100);
    __CPROVER_assume(pub_r000627_6 >= -100 && pub_r000627_6 <= 100);
    __CPROVER_assume(pub_r000627_7 >= -100 && pub_r000627_7 <= 100);
    __CPROVER_assume(pub_r000627_8 >= -100 && pub_r000627_8 <= 100);
    __CPROVER_assume(pub_r000627_9 >= -100 && pub_r000627_9 <= 100);
    __CPROVER_assume(pub_r000627_10 >= -100 && pub_r000627_10 <= 100);
    __CPROVER_assume(pub_r000627_11 >= -100 && pub_r000627_11 <= 100);
    __CPROVER_assume(pub_r000627_12 >= -100 && pub_r000627_12 <= 100);
    __CPROVER_assume(pub_r000627_13 >= -100 && pub_r000627_13 <= 100);
    __CPROVER_assume(pub_r000627_14 >= -100 && pub_r000627_14 <= 100);
    __CPROVER_assume(pub_r000627_15 >= -100 && pub_r000627_15 <= 100);
    __CPROVER_assume(pub_r000627_16 >= -100 && pub_r000627_16 <= 100);
    __CPROVER_assume(pub_r000627_17 >= -100 && pub_r000627_17 <= 100);
    __CPROVER_assume(pub_r000627_18 >= -100 && pub_r000627_18 <= 100);
    __CPROVER_assume(sec_r000627_0 >= 0 && sec_r000627_0 <= 255);
    __CPROVER_assume(sec_r000627_1 >= 0 && sec_r000627_1 <= 255);
    __CPROVER_assume(sec_r000627_2 >= 0 && sec_r000627_2 <= 255);
    __CPROVER_assume(sec_r000627_3 >= 0 && sec_r000627_3 <= 255);
    __CPROVER_assume(sec_r000627_4 >= 0 && sec_r000627_4 <= 255);
    __CPROVER_assume(sec_r000627_5 >= 0 && sec_r000627_5 <= 255);
    __CPROVER_assume(sec_r000627_6 >= 0 && sec_r000627_6 <= 255);
    __CPROVER_assume(sec_r000627_7 >= 0 && sec_r000627_7 <= 255);
    __CPROVER_assume(sec_r000627_8 >= 0 && sec_r000627_8 <= 255);
    __CPROVER_assume(sec_r000627_9 >= 0 && sec_r000627_9 <= 255);
    __CPROVER_assume(sec_r000627_10 >= 0 && sec_r000627_10 <= 255);
    __CPROVER_assume(sec_r000627_11 >= 0 && sec_r000627_11 <= 255);
    __CPROVER_assume(sec_r000627_12 >= 0 && sec_r000627_12 <= 255);
    __CPROVER_assume(sec_r000627_13 >= 0 && sec_r000627_13 <= 255);
    __CPROVER_assume(sec_r000627_14 >= 0 && sec_r000627_14 <= 255);
    __CPROVER_assume(sec_r000627_15 >= 0 && sec_r000627_15 <= 255);
    __CPROVER_assume(sec_r000627_16 >= 0 && sec_r000627_16 <= 255);
    __CPROVER_assume(sec_r000627_17 >= 0 && sec_r000627_17 <= 255);
    __CPROVER_assume(sec_r000627_18 >= 0 && sec_r000627_18 <= 255);
    __CPROVER_assume(sec_r000627_19 >= 0 && sec_r000627_19 <= 255);

    struct MatrixBlock_R000627_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000627_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000627_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000627_0 + 7) & 15;
    struct CipherContext_R000627_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000627_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000627_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000627_0 + 9) & 15;
    struct SensorNode_R000627_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000627_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000627_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000627_0 + 11) & 15;
    struct StreamBuffer_R000627_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000627_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000627_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000627_0 + 13) & 15;

    union PacketPayload_R000627_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

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
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 17) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 32) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 15) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 30) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 40) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 55) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 19) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 34) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000627_18 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_21 = (pub_r000627_16 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000627_16 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000627_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_22 = (pub_r000627_18 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000627_18 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000627_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000627_17 & 2) != 0) {
            stage_v_23 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_24 = (pub_r000627_7 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000627_7 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000627_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_25 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_26 = (pub_r000627_3 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000627_3 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000627_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000627_6 & 2) != 0) {
            stage_v_27 = (pub_r000627_9 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000627_9 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000627_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_28 = (pub_r000627_18 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000627_18 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000627_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_29 = (pub_r000627_13 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000627_13 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000627_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000627_1 & 2) != 0) {
            stage_v_30 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_31 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_32 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_33 = (pub_r000627_15 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000627_15 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000627_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000627_17 & 2) != 0) {
            stage_v_34 = (pub_r000627_11 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000627_11 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000627_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000627_6 & 2) != 0) {
            stage_v_35 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((sec_r000627_11 & 1) != 0) {
        if ((sec_r000627_6 & 2) != 0) {
            stage_v_36 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000627_9 & 2) != 0) {
            stage_v_37 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_38 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_39 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000627_7 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_40 = (pub_r000627_13 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000627_13 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000627_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_41 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000627_16 & 2) != 0) {
            stage_v_42 = (pub_r000627_9 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000627_9 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000627_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000627_5 & 2) != 0) {
            stage_v_43 = (pub_r000627_12 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000627_12 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000627_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_44 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_45 = (pub_r000627_12 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000627_12 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000627_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000627_13 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_46 = (pub_r000627_9 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000627_9 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000627_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000627_17 & 1) != 0) {
        if ((sec_r000627_14 & 2) != 0) {
            stage_v_47 = (pub_r000627_18 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000627_18 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000627_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((sec_r000627_11 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_48 = (pub_r000627_15 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000627_15 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000627_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000627_8 & 2) != 0) {
            stage_v_49 = (pub_r000627_16 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000627_16 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000627_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_50 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000627_12 & 2) != 0) {
            stage_v_51 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((sec_r000627_5 & 1) != 0) {
        if ((sec_r000627_3 & 2) != 0) {
            stage_v_52 = (pub_r000627_16 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000627_16 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000627_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000627_12 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_53 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000627_6 & 2) != 0) {
            stage_v_54 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000627_15 & 1) != 0) {
        if ((sec_r000627_10 & 2) != 0) {
            stage_v_55 = (pub_r000627_18 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000627_18 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000627_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_56 = (pub_r000627_15 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000627_15 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000627_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_57 = (pub_r000627_15 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000627_15 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000627_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_58 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_59 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_60 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000627_11 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_61 = (pub_r000627_15 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000627_15 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000627_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000627_14 & 2) != 0) {
            stage_v_62 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_63 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_64 = (pub_r000627_10 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000627_10 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000627_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000627_5 & 1) != 0) {
        if ((sec_r000627_1 & 2) != 0) {
            stage_v_65 = (pub_r000627_14 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000627_14 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000627_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000627_13 & 1) != 0) {
        if ((sec_r000627_13 & 2) != 0) {
            stage_v_66 = (pub_r000627_14 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000627_14 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000627_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_67 = (pub_r000627_13 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000627_13 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000627_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000627_14 & 2) != 0) {
            stage_v_68 = (pub_r000627_13 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000627_13 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000627_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000627_19 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_69 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000627_14 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_70 = (pub_r000627_14 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000627_14 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000627_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_71 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000627_1 & 2) != 0) {
            stage_v_72 = (pub_r000627_3 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000627_3 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000627_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_73 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_74 = (pub_r000627_11 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000627_11 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000627_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_75 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000627_0 & 2) != 0) {
            stage_v_76 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000627_10 & 2) != 0) {
            stage_v_77 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_78 = (pub_r000627_10 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000627_10 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000627_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000627_7 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_79 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000627_14 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_80 = (pub_r000627_18 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000627_18 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000627_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000627_7 & 1) != 0) {
        if ((sec_r000627_17 & 2) != 0) {
            stage_v_81 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000627_0 & 2) != 0) {
            stage_v_82 = (pub_r000627_11 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000627_11 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000627_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000627_10 & 2) != 0) {
            stage_v_83 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_84 = (pub_r000627_12 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000627_12 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000627_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000627_10 & 2) != 0) {
            stage_v_85 = (pub_r000627_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000627_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000627_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000627_17 & 2) != 0) {
            stage_v_86 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000627_17 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_87 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000627_1 & 2) != 0) {
            stage_v_88 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000627_13 & 2) != 0) {
            stage_v_89 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_90 = (pub_r000627_17 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000627_17 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000627_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000627_4 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_91 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000627_9 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_92 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000627_9 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_93 = (pub_r000627_3 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000627_3 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000627_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000627_17 & 1) != 0) {
        if ((sec_r000627_10 & 2) != 0) {
            stage_v_94 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000627_10 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_95 = (pub_r000627_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000627_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000627_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000627_10 & 2) != 0) {
            stage_v_96 = (pub_r000627_9 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000627_9 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000627_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000627_8 & 2) != 0) {
            stage_v_97 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000627_4 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_98 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000627_17 & 1) != 0) {
        if ((sec_r000627_16 & 2) != 0) {
            stage_v_99 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000627_8 & 2) != 0) {
            stage_v_100 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_101 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000627_11 & 2) != 0) {
            stage_v_102 = (pub_r000627_2 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000627_2 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000627_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000627_3 & 2) != 0) {
            stage_v_103 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_104 = (pub_r000627_14 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000627_14 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000627_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_105 = (pub_r000627_17 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000627_17 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000627_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_106 = (pub_r000627_3 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000627_3 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000627_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000627_0 & 1) != 0) {
        if ((sec_r000627_16 & 2) != 0) {
            stage_v_107 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000627_1 & 2) != 0) {
            stage_v_108 = (pub_r000627_9 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000627_9 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000627_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000627_7 & 2) != 0) {
            stage_v_109 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000627_16 & 2) != 0) {
            stage_v_110 = (pub_r000627_7 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000627_7 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000627_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000627_2 & 1) != 0) {
        if ((sec_r000627_13 & 2) != 0) {
            stage_v_111 = (pub_r000627_17 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000627_17 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000627_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000627_5 & 2) != 0) {
            stage_v_112 = (pub_r000627_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000627_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000627_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000627_16 & 1) != 0) {
        if ((sec_r000627_3 & 2) != 0) {
            stage_v_113 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000627_2 & 2) != 0) {
            stage_v_114 = (pub_r000627_15 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000627_15 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000627_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000627_9 & 2) != 0) {
            stage_v_115 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000627_0 & 2) != 0) {
            stage_v_116 = (pub_r000627_11 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000627_11 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000627_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000627_17 & 1) != 0) {
        if ((sec_r000627_12 & 2) != 0) {
            stage_v_117 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000627_3 & 2) != 0) {
            stage_v_118 = (pub_r000627_16 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000627_16 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000627_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_119 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000627_5 & 2) != 0) {
            stage_v_120 = (pub_r000627_17 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000627_17 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000627_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000627_3 & 2) != 0) {
            stage_v_121 = (pub_r000627_5 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000627_5 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000627_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000627_3 & 2) != 0) {
            stage_v_122 = (pub_r000627_14 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000627_14 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000627_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000627_14 & 1) != 0) {
        if ((sec_r000627_15 & 2) != 0) {
            stage_v_123 = (pub_r000627_10 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000627_10 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000627_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000627_12 & 2) != 0) {
            stage_v_124 = (pub_r000627_13 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000627_13 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000627_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000627_14 & 2) != 0) {
            stage_v_125 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000627_0 & 1) != 0) {
        if ((sec_r000627_18 & 2) != 0) {
            stage_v_126 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000627_0 & 2) != 0) {
            stage_v_127 = (pub_r000627_6 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000627_6 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000627_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000627_5 & 2) != 0) {
            stage_v_128 = (pub_r000627_1 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000627_1 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000627_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000627_19 & 1) != 0) {
        if ((sec_r000627_13 & 2) != 0) {
            stage_v_129 = (pub_r000627_14 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000627_14 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000627_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000627_17 & 2) != 0) {
            stage_v_130 = (pub_r000627_13 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000627_13 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000627_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000627_4 & 2) != 0) {
            stage_v_131 = (pub_r000627_4 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000627_4 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000627_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000627_4 & 1) != 0) {
        if ((sec_r000627_17 & 2) != 0) {
            stage_v_132 = (pub_r000627_0 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000627_0 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000627_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000627_19 & 2) != 0) {
            stage_v_133 = (pub_r000627_17 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000627_17 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000627_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
