/*
 * Benchmark Program: R000617
 * Security Family: nested_implicit_flow
 * Generator Seed: 561713
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000617_1713_0 {
    int envelope;
    short rms;
    int sample_rate;
    int buffer[3];
};

struct MatrixBlock_R000617_1713_1 {
    int dim;
    int scale;
    int determinant;
    int stride;
    short density;
    int buffer[3];
};

struct SensorNode_R000617_1713_2 {
    int status;
    unsigned char offset;
    short threshold;
    short gain;
    int buffer[3];
};

union PacketPayload_R000617_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000617_1713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000617_1713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int vector_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_99) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_80 = local_arr[aux % 3];
    acc = (acc + mask_80 * 2) & 127;
    int segment_93 = (aux + st.buffer[1]) & 3;
    switch (segment_93) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_68 > 21) {
        acc = (acc + factor_68 * 2 + 5) & 127;
        aux ^= (factor_68 & 15);
    } else {
        acc = (acc - factor_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_1(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000617_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quantum_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_42) & 63;
    acc ^= aux;
    int segment_53 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_53 > 31) {
        acc = (acc + segment_53 * 2 + 5) & 127;
        aux ^= (segment_53 & 15);
    } else {
        acc = (acc - segment_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_2(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000617_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tally_22 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_22 > 43) {
        acc = (acc + tally_22 * 2 + 5) & 127;
        aux ^= (tally_22 & 15);
    } else {
        acc = (acc - tally_22 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_3(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_79) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_29 = local_arr[aux % 3];
    acc = (acc + tracker_29 * 2) & 127;
    int tally_68 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_68 > 46) {
        acc = (acc + tally_68 * 2 + 5) & 127;
        aux ^= (tally_68 & 15);
    } else {
        acc = (acc - tally_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000617_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int segment_35 = local_arr[aux % 3];
    acc = (acc + segment_35 * 2) & 127;
    int residue_16 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_16 > 20) {
        acc = (acc + residue_16 * 2 + 5) & 127;
        aux ^= (residue_16 & 15);
    } else {
        acc = (acc - residue_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int stride_81 = local_arr[aux % 3];
    acc = (acc + stride_81 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_6(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_36 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_36 > 38) {
        acc = (acc + delta_36 * 2 + 5) & 127;
        aux ^= (delta_36 & 15);
    } else {
        acc = (acc - delta_36 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_33 = local_arr[aux % 3];
    acc = (acc + anchor_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_96 = (aux + st.buffer[1]) & 3;
    switch (threshold_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_76) & 63;
    acc ^= aux;
    int residue_39 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_39 > 18) {
        acc = (acc + residue_39 * 2 + 5) & 127;
        aux ^= (residue_39 & 15);
    } else {
        acc = (acc - residue_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_8(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000617_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int threshold_25 = local_arr[aux % 3];
    acc = (acc + threshold_25 * 2) & 127;
    int residue_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_14) & 63;
    acc ^= aux;
    int window_85 = (aux + st.buffer[1]) & 3;
    switch (window_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_69 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_69 > 29) {
        acc = (acc + damping_69 * 2 + 5) & 127;
        aux ^= (damping_69 & 15);
    } else {
        acc = (acc - damping_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta_51 = (aux + st.buffer[1]) & 3;
    switch (delta_51) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_51 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_51 > 25) {
        acc = (acc + parity_51 * 2 + 5) & 127;
        aux ^= (parity_51 & 15);
    } else {
        acc = (acc - parity_51 + 11) & 127;
        aux += 3;
    }
    int threshold_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000617_1713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_29) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_73 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_73 > 25) {
        acc = (acc + accumulator_73 * 2 + 5) & 127;
        aux ^= (accumulator_73 & 15);
    } else {
        acc = (acc - accumulator_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_11(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_34 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_34 > 23) {
        acc = (acc + delta_34 * 2 + 5) & 127;
        aux ^= (delta_34 & 15);
    } else {
        acc = (acc - delta_34 + 11) & 127;
        aux += 3;
    }
    int checksum_60 = (aux + st.buffer[1]) & 3;
    switch (checksum_60) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000617_1713_12(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000617_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_16 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_16 > 28) {
        acc = (acc + bound_16 * 2 + 5) & 127;
        aux ^= (bound_16 & 15);
    } else {
        acc = (acc - bound_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_33 = local_arr[aux % 3];
    acc = (acc + quotient_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int threshold_83 = local_arr[aux % 3];
    acc = (acc + threshold_83 * 2) & 127;
    int threshold_66 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_66 > 27) {
        acc = (acc + threshold_66 * 2 + 5) & 127;
        aux ^= (threshold_66 & 15);
    } else {
        acc = (acc - threshold_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int residue_45 = local_arr[aux % 3];
    acc = (acc + residue_45 * 2) & 127;
    int weight_91 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_91 > 30) {
        acc = (acc + weight_91 * 2 + 5) & 127;
        aux ^= (weight_91 & 15);
    } else {
        acc = (acc - weight_91 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_15(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quantum_49 = (aux + st.buffer[1]) & 3;
    switch (quantum_49) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_62 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_62 > 11) {
        acc = (acc + accumulator_62 * 2 + 5) & 127;
        aux ^= (accumulator_62 & 15);
    } else {
        acc = (acc - accumulator_62 + 11) & 127;
        aux += 3;
    }
    int pivot_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_50) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_94 = local_arr[aux % 3];
    acc = (acc + margin_94 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_16(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int damping_40 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_40 > 26) {
        acc = (acc + damping_40 * 2 + 5) & 127;
        aux ^= (damping_40 & 15);
    } else {
        acc = (acc - damping_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_99 = local_arr[aux % 3];
    acc = (acc + metric_99 * 2) & 127;
    int accumulator_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_78) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000617_1713_17(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000617_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_52) & 63;
    acc ^= aux;
    int quotient_10 = (aux + st.buffer[1]) & 3;
    switch (quotient_10) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int threshold_20 = local_arr[aux % 3];
    acc = (acc + threshold_20 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_80 = (aux + st.buffer[1]) & 3;
    switch (pivot_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_93 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_93 > 43) {
        acc = (acc + cursor_93 * 2 + 5) & 127;
        aux ^= (cursor_93 & 15);
    } else {
        acc = (acc - cursor_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000617_1713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000617_1713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_68 = local_arr[aux % 3];
    acc = (acc + bound_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000617_1713_20(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000617_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_94) & 63;
    acc ^= aux;
    int factor_42 = (aux + st.buffer[1]) & 3;
    switch (factor_42) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000617_0;
    int sec_r000617_1;
    int sec_r000617_2;
    int sec_r000617_3;
    int sec_r000617_4;
    int sec_r000617_5;
    int sec_r000617_6;
    int sec_r000617_7;
    int sec_r000617_8;
    int sec_r000617_9;
    int sec_r000617_10;
    int sec_r000617_11;
    int sec_r000617_12;
    int sec_r000617_13;
    int sec_r000617_14;
    int sec_r000617_15;
    int sec_r000617_16;
    int sec_r000617_17;
    int sec_r000617_18;
    int sec_r000617_19;
    int sec_r000617_20;
    int pub_r000617_0;
    int pub_r000617_1;
    int pub_r000617_2;
    int pub_r000617_3;
    int pub_r000617_4;
    int pub_r000617_5;
    int pub_r000617_6;
    int pub_r000617_7;
    int pub_r000617_8;
    int pub_r000617_9;
    int pub_r000617_10;
    int pub_r000617_11;
    int pub_r000617_12;
    int pub_r000617_13;
    int pub_r000617_14;
    int pub_r000617_15;
    int pub_r000617_16;
    int pub_r000617_17;
    int pub_r000617_18;
    int pub_r000617_19;
    int pub_r000617_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000617_0 >= -100 && pub_r000617_0 <= 100);
    __CPROVER_assume(pub_r000617_1 >= -100 && pub_r000617_1 <= 100);
    __CPROVER_assume(pub_r000617_2 >= -100 && pub_r000617_2 <= 100);
    __CPROVER_assume(pub_r000617_3 >= -100 && pub_r000617_3 <= 100);
    __CPROVER_assume(pub_r000617_4 >= -100 && pub_r000617_4 <= 100);
    __CPROVER_assume(pub_r000617_5 >= -100 && pub_r000617_5 <= 100);
    __CPROVER_assume(pub_r000617_6 >= -100 && pub_r000617_6 <= 100);
    __CPROVER_assume(pub_r000617_7 >= -100 && pub_r000617_7 <= 100);
    __CPROVER_assume(pub_r000617_8 >= -100 && pub_r000617_8 <= 100);
    __CPROVER_assume(pub_r000617_9 >= -100 && pub_r000617_9 <= 100);
    __CPROVER_assume(pub_r000617_10 >= -100 && pub_r000617_10 <= 100);
    __CPROVER_assume(pub_r000617_11 >= -100 && pub_r000617_11 <= 100);
    __CPROVER_assume(pub_r000617_12 >= -100 && pub_r000617_12 <= 100);
    __CPROVER_assume(pub_r000617_13 >= -100 && pub_r000617_13 <= 100);
    __CPROVER_assume(pub_r000617_14 >= -100 && pub_r000617_14 <= 100);
    __CPROVER_assume(pub_r000617_15 >= -100 && pub_r000617_15 <= 100);
    __CPROVER_assume(pub_r000617_16 >= -100 && pub_r000617_16 <= 100);
    __CPROVER_assume(pub_r000617_17 >= -100 && pub_r000617_17 <= 100);
    __CPROVER_assume(pub_r000617_18 >= -100 && pub_r000617_18 <= 100);
    __CPROVER_assume(pub_r000617_19 >= -100 && pub_r000617_19 <= 100);
    __CPROVER_assume(pub_r000617_20 >= -100 && pub_r000617_20 <= 100);
    __CPROVER_assume(sec_r000617_0 >= 0 && sec_r000617_0 <= 255);
    __CPROVER_assume(sec_r000617_1 >= 0 && sec_r000617_1 <= 255);
    __CPROVER_assume(sec_r000617_2 >= 0 && sec_r000617_2 <= 255);
    __CPROVER_assume(sec_r000617_3 >= 0 && sec_r000617_3 <= 255);
    __CPROVER_assume(sec_r000617_4 >= 0 && sec_r000617_4 <= 255);
    __CPROVER_assume(sec_r000617_5 >= 0 && sec_r000617_5 <= 255);
    __CPROVER_assume(sec_r000617_6 >= 0 && sec_r000617_6 <= 255);
    __CPROVER_assume(sec_r000617_7 >= 0 && sec_r000617_7 <= 255);
    __CPROVER_assume(sec_r000617_8 >= 0 && sec_r000617_8 <= 255);
    __CPROVER_assume(sec_r000617_9 >= 0 && sec_r000617_9 <= 255);
    __CPROVER_assume(sec_r000617_10 >= 0 && sec_r000617_10 <= 255);
    __CPROVER_assume(sec_r000617_11 >= 0 && sec_r000617_11 <= 255);
    __CPROVER_assume(sec_r000617_12 >= 0 && sec_r000617_12 <= 255);
    __CPROVER_assume(sec_r000617_13 >= 0 && sec_r000617_13 <= 255);
    __CPROVER_assume(sec_r000617_14 >= 0 && sec_r000617_14 <= 255);
    __CPROVER_assume(sec_r000617_15 >= 0 && sec_r000617_15 <= 255);
    __CPROVER_assume(sec_r000617_16 >= 0 && sec_r000617_16 <= 255);
    __CPROVER_assume(sec_r000617_17 >= 0 && sec_r000617_17 <= 255);
    __CPROVER_assume(sec_r000617_18 >= 0 && sec_r000617_18 <= 255);
    __CPROVER_assume(sec_r000617_19 >= 0 && sec_r000617_19 <= 255);
    __CPROVER_assume(sec_r000617_20 >= 0 && sec_r000617_20 <= 255);

    struct AudioFrame_R000617_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000617_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000617_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000617_0 + 7) & 15;
    struct MatrixBlock_R000617_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000617_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000617_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000617_0 + 9) & 15;
    struct SensorNode_R000617_1713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000617_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000617_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000617_0 + 11) & 15;

    union PacketPayload_R000617_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 17) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 32) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

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
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 22) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 37) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 28) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 43) {
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
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 33) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 48) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 13) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 28) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 11) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 26) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 15) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 30) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 10) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 25) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 23) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 38) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000617_11 & 1) != 0) {
        if ((sec_r000617_2 & 2) != 0) {
            stage_v_47 = (pub_r000617_8 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000617_8 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000617_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000617_15 & 2) != 0) {
            stage_v_48 = (pub_r000617_9 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000617_9 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000617_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000617_8 & 2) != 0) {
            stage_v_49 = (pub_r000617_1 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000617_1 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000617_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((sec_r000617_12 & 1) != 0) {
        if ((sec_r000617_7 & 2) != 0) {
            stage_v_50 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000617_19 & 2) != 0) {
            stage_v_51 = (pub_r000617_7 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000617_7 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000617_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_52 = (pub_r000617_11 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000617_11 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000617_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((sec_r000617_15 & 1) != 0) {
        if ((sec_r000617_16 & 2) != 0) {
            stage_v_53 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000617_15 & 1) != 0) {
        if ((sec_r000617_15 & 2) != 0) {
            stage_v_54 = (pub_r000617_13 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000617_13 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000617_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000617_4 & 1) != 0) {
        if ((sec_r000617_20 & 2) != 0) {
            stage_v_55 = (pub_r000617_13 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000617_13 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000617_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000617_0 & 2) != 0) {
            stage_v_56 = (pub_r000617_6 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000617_6 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000617_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000617_19 & 2) != 0) {
            stage_v_57 = (pub_r000617_6 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000617_6 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000617_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000617_3 & 2) != 0) {
            stage_v_58 = (pub_r000617_11 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000617_11 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000617_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000617_14 & 2) != 0) {
            stage_v_59 = (pub_r000617_2 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000617_2 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000617_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000617_17 & 2) != 0) {
            stage_v_60 = (pub_r000617_19 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000617_19 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000617_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000617_1 & 1) != 0) {
        if ((sec_r000617_14 & 2) != 0) {
            stage_v_61 = (pub_r000617_13 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000617_13 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000617_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000617_14 & 2) != 0) {
            stage_v_62 = (pub_r000617_15 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000617_15 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000617_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000617_17 & 1) != 0) {
        if ((sec_r000617_10 & 2) != 0) {
            stage_v_63 = (pub_r000617_15 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000617_15 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000617_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000617_1 & 2) != 0) {
            stage_v_64 = (pub_r000617_11 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000617_11 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000617_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000617_9 & 2) != 0) {
            stage_v_65 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000617_16 & 1) != 0) {
        if ((sec_r000617_7 & 2) != 0) {
            stage_v_66 = (pub_r000617_11 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000617_11 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000617_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000617_13 & 2) != 0) {
            stage_v_67 = (pub_r000617_10 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000617_10 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000617_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000617_18 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_68 = (pub_r000617_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000617_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000617_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000617_12 & 2) != 0) {
            stage_v_69 = (pub_r000617_3 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000617_3 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000617_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000617_1 & 2) != 0) {
            stage_v_70 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000617_0 & 2) != 0) {
            stage_v_71 = (pub_r000617_16 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000617_16 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000617_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000617_14 & 2) != 0) {
            stage_v_72 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_73 = (pub_r000617_20 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000617_20 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000617_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000617_8 & 2) != 0) {
            stage_v_74 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000617_1 & 1) != 0) {
        if ((sec_r000617_20 & 2) != 0) {
            stage_v_75 = (pub_r000617_7 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000617_7 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000617_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_76 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000617_5 & 2) != 0) {
            stage_v_77 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000617_6 & 2) != 0) {
            stage_v_78 = (pub_r000617_11 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000617_11 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000617_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000617_2 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_79 = (pub_r000617_14 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000617_14 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000617_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000617_8 & 1) != 0) {
        if ((sec_r000617_10 & 2) != 0) {
            stage_v_80 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000617_5 & 1) != 0) {
        if ((sec_r000617_9 & 2) != 0) {
            stage_v_81 = (pub_r000617_9 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000617_9 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000617_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_82 = (pub_r000617_14 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000617_14 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000617_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000617_3 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_83 = (pub_r000617_7 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000617_7 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000617_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_84 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000617_13 & 2) != 0) {
            stage_v_85 = (pub_r000617_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000617_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000617_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000617_18 & 1) != 0) {
        if ((sec_r000617_6 & 2) != 0) {
            stage_v_86 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000617_13 & 2) != 0) {
            stage_v_87 = (pub_r000617_6 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000617_6 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000617_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000617_10 & 2) != 0) {
            stage_v_88 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000617_8 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_89 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000617_5 & 1) != 0) {
        if ((sec_r000617_2 & 2) != 0) {
            stage_v_90 = (pub_r000617_10 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000617_10 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000617_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((sec_r000617_5 & 1) != 0) {
        if ((sec_r000617_8 & 2) != 0) {
            stage_v_91 = (pub_r000617_7 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000617_7 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000617_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000617_2 & 2) != 0) {
            stage_v_92 = (pub_r000617_19 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000617_19 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000617_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000617_0 & 1) != 0) {
        if ((sec_r000617_5 & 2) != 0) {
            stage_v_93 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000617_2 & 2) != 0) {
            stage_v_94 = (pub_r000617_9 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000617_9 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000617_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000617_0 & 1) != 0) {
        if ((sec_r000617_17 & 2) != 0) {
            stage_v_95 = (pub_r000617_2 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000617_2 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000617_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000617_14 & 2) != 0) {
            stage_v_96 = (pub_r000617_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000617_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000617_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000617_0 & 2) != 0) {
            stage_v_97 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000617_15 & 2) != 0) {
            stage_v_98 = (pub_r000617_4 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000617_4 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000617_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000617_19 & 2) != 0) {
            stage_v_99 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000617_0 & 2) != 0) {
            stage_v_100 = (pub_r000617_3 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000617_3 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000617_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000617_15 & 1) != 0) {
        if ((sec_r000617_12 & 2) != 0) {
            stage_v_101 = (pub_r000617_1 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000617_1 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000617_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000617_4 & 2) != 0) {
            stage_v_102 = (pub_r000617_16 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000617_16 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000617_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000617_16 & 1) != 0) {
        if ((sec_r000617_20 & 2) != 0) {
            stage_v_103 = (pub_r000617_2 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000617_2 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000617_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000617_13 & 2) != 0) {
            stage_v_104 = (pub_r000617_0 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000617_0 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000617_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000617_6 & 1) != 0) {
        if ((sec_r000617_8 & 2) != 0) {
            stage_v_105 = (pub_r000617_0 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000617_0 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000617_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_106 = (pub_r000617_15 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000617_15 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000617_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000617_6 & 2) != 0) {
            stage_v_107 = (pub_r000617_4 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000617_4 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000617_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000617_2 & 1) != 0) {
        if ((sec_r000617_17 & 2) != 0) {
            stage_v_108 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000617_2 & 1) != 0) {
        if ((sec_r000617_17 & 2) != 0) {
            stage_v_109 = (pub_r000617_8 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000617_8 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000617_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_110 = (pub_r000617_17 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000617_17 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000617_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000617_0 & 2) != 0) {
            stage_v_111 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000617_9 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_112 = (pub_r000617_8 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000617_8 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000617_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000617_20 & 1) != 0) {
        if ((sec_r000617_1 & 2) != 0) {
            stage_v_113 = (pub_r000617_13 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000617_13 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000617_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000617_15 & 2) != 0) {
            stage_v_114 = (pub_r000617_10 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000617_10 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000617_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000617_9 & 1) != 0) {
        if ((sec_r000617_3 & 2) != 0) {
            stage_v_115 = (pub_r000617_14 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000617_14 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000617_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000617_18 & 1) != 0) {
        if ((sec_r000617_4 & 2) != 0) {
            stage_v_116 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_117 = (pub_r000617_6 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000617_6 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000617_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000617_7 & 1) != 0) {
        if ((sec_r000617_15 & 2) != 0) {
            stage_v_118 = (pub_r000617_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000617_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000617_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000617_19 & 2) != 0) {
            stage_v_119 = (pub_r000617_16 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000617_16 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000617_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000617_7 & 1) != 0) {
        if ((sec_r000617_14 & 2) != 0) {
            stage_v_120 = (pub_r000617_1 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000617_1 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000617_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000617_19 & 2) != 0) {
            stage_v_121 = (pub_r000617_2 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000617_2 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000617_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_122 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000617_12 & 2) != 0) {
            stage_v_123 = (pub_r000617_10 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000617_10 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000617_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000617_3 & 1) != 0) {
        if ((sec_r000617_17 & 2) != 0) {
            stage_v_124 = (pub_r000617_3 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000617_3 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000617_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000617_3 & 2) != 0) {
            stage_v_125 = (pub_r000617_20 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000617_20 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000617_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000617_3 & 2) != 0) {
            stage_v_126 = (pub_r000617_16 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000617_16 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000617_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000617_19 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_127 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000617_9 & 2) != 0) {
            stage_v_128 = (pub_r000617_18 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000617_18 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000617_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000617_13 & 2) != 0) {
            stage_v_129 = (pub_r000617_11 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000617_11 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000617_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000617_8 & 1) != 0) {
        if ((sec_r000617_11 & 2) != 0) {
            stage_v_130 = (pub_r000617_7 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000617_7 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000617_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000617_17 & 2) != 0) {
            stage_v_131 = (pub_r000617_15 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000617_15 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000617_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000617_18 & 2) != 0) {
            stage_v_132 = (pub_r000617_10 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000617_10 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000617_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000617_16 & 2) != 0) {
            stage_v_133 = (pub_r000617_15 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000617_15 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000617_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_128 & 1) != 0) {
        if ((sec_r000617_3 & 2) != 0) {
            stage_v_134 = (pub_r000617_12 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000617_12 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000617_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
