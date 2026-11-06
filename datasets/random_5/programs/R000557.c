/*
 * Benchmark Program: R000557
 * Security Family: nested_implicit_flow
 * Generator Seed: 555713
 * High Inputs: 22 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct SensorNode_R000557_5713_0 {
    short threshold;
    int reading;
    int gain;
    int offset;
    int buffer[3];
};

struct EventLog_R000557_5713_1 {
    int code;
    short signature;
    int facility;
    int severity;
    int timestamp;
    int seq;
    int buffer[3];
};

struct FilterState_R000557_5713_2 {
    short prev_out;
    int damping;
    int cutoff;
    short mode;
    unsigned char gain_db;
    int buffer[3];
};

union PacketPayload_R000557_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000557_5713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000557_5713_0(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_34 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_34 > 32) {
        acc = (acc + quotient_34 * 2 + 5) & 127;
        aux ^= (quotient_34 & 15);
    } else {
        acc = (acc - quotient_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000557_5713_1(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int margin_12 = (aux + st.buffer[1]) & 3;
    switch (margin_12) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_28 = local_arr[aux % 3];
    acc = (acc + mask_28 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_37 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_37 > 39) {
        acc = (acc + anchor_37 * 2 + 5) & 127;
        aux ^= (anchor_37 & 15);
    } else {
        acc = (acc - anchor_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000557_5713_2(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000557_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int window_48 = (st.buffer[0] * 3 + aux) & 63;
    if (window_48 > 23) {
        acc = (acc + window_48 * 2 + 5) & 127;
        aux ^= (window_48 & 15);
    } else {
        acc = (acc - window_48 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_3(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000557_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_13) & 63;
    acc ^= aux;
    int residue_17 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_17 > 24) {
        acc = (acc + residue_17 * 2 + 5) & 127;
        aux ^= (residue_17 & 15);
    } else {
        acc = (acc - residue_17 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_70 = local_arr[aux % 3];
    acc = (acc + quantum_70 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int phase_28 = local_arr[aux % 3];
    acc = (acc + phase_28 * 2) & 127;
    int delta_96 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_96 > 31) {
        acc = (acc + delta_96 * 2 + 5) & 127;
        aux ^= (delta_96 & 15);
    } else {
        acc = (acc - delta_96 + 11) & 127;
        aux += 3;
    }
    int factor_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_55) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_5(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000557_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tracker_18 = (aux + st.buffer[1]) & 3;
    switch (tracker_18) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_40 = local_arr[aux % 3];
    acc = (acc + anchor_40 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int vector_25 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_25 > 44) {
        acc = (acc + vector_25 * 2 + 5) & 127;
        aux ^= (vector_25 & 15);
    } else {
        acc = (acc - vector_25 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_98) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000557_5713_7(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int stride_81 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_81 > 24) {
        acc = (acc + stride_81 * 2 + 5) & 127;
        aux ^= (stride_81 & 15);
    } else {
        acc = (acc - stride_81 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_50 = local_arr[aux % 3];
    acc = (acc + tally_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_13) & 63;
    acc ^= aux;
    int phase_80 = (aux + st.buffer[1]) & 3;
    switch (phase_80) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_37 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_37 > 43) {
        acc = (acc + pivot_37 * 2 + 5) & 127;
        aux ^= (pivot_37 & 15);
    } else {
        acc = (acc - pivot_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000557_5713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quotient_43 = (aux + st.buffer[1]) & 3;
    switch (quotient_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_10(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int mask_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_57) & 63;
    acc ^= aux;
    int mask_32 = (aux + st.buffer[1]) & 3;
    switch (mask_32) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_68 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_68 > 23) {
        acc = (acc + quotient_68 * 2 + 5) & 127;
        aux ^= (quotient_68 & 15);
    } else {
        acc = (acc - quotient_68 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_10 = local_arr[aux % 3];
    acc = (acc + window_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_11(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_78) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_87 = (aux + st.buffer[1]) & 3;
    switch (stride_87) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_68 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_68 > 24) {
        acc = (acc + accumulator_68 * 2 + 5) & 127;
        aux ^= (accumulator_68 & 15);
    } else {
        acc = (acc - accumulator_68 + 11) & 127;
        aux += 3;
    }
    int mask_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000557_5713_13(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_47 = (aux + st.buffer[1]) & 3;
    switch (phase_47) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_51 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_51 > 14) {
        acc = (acc + anchor_51 * 2 + 5) & 127;
        aux ^= (anchor_51 & 15);
    } else {
        acc = (acc - anchor_51 + 11) & 127;
        aux += 3;
    }
    int quantum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000557_5713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int index_reg_43 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_43 > 35) {
        acc = (acc + index_reg_43 * 2 + 5) & 127;
        aux ^= (index_reg_43 & 15);
    } else {
        acc = (acc - index_reg_43 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_13 = local_arr[aux % 3];
    acc = (acc + window_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_15(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int coefficient_31 = local_arr[aux % 3];
    acc = (acc + coefficient_31 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_85 = (aux + st.buffer[1]) & 3;
    switch (weight_85) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000557_5713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000557_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_89 = (aux + st.buffer[1]) & 3;
    switch (residue_89) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000557_5713_17(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int window_39 = (st.buffer[0] * 3 + aux) & 63;
    if (window_39 > 47) {
        acc = (acc + window_39 * 2 + 5) & 127;
        aux ^= (window_39 & 15);
    } else {
        acc = (acc - window_39 + 11) & 127;
        aux += 3;
    }
    int checksum_57 = (aux + st.buffer[1]) & 3;
    switch (checksum_57) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000557_5713_18(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000557_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int pivot_90 = local_arr[aux % 3];
    acc = (acc + pivot_90 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_19(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000557_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_76) & 63;
    acc ^= aux;
    int segment_39 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_39 > 25) {
        acc = (acc + segment_39 * 2 + 5) & 127;
        aux ^= (segment_39 & 15);
    } else {
        acc = (acc - segment_39 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000557_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int coefficient_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_88) & 63;
    acc ^= aux;
    int margin_20 = (aux + st.buffer[1]) & 3;
    switch (margin_20) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000557_5713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int sample_39 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_39 > 13) {
        acc = (acc + sample_39 * 2 + 5) & 127;
        aux ^= (sample_39 & 15);
    } else {
        acc = (acc - sample_39 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000557_5713_22(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000557_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int factor_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_41) & 63;
    acc ^= aux;
    int weight_99 = (aux + st.buffer[1]) & 3;
    switch (weight_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000557_0;
    int sec_r000557_1;
    int sec_r000557_2;
    int sec_r000557_3;
    int sec_r000557_4;
    int sec_r000557_5;
    int sec_r000557_6;
    int sec_r000557_7;
    int sec_r000557_8;
    int sec_r000557_9;
    int sec_r000557_10;
    int sec_r000557_11;
    int sec_r000557_12;
    int sec_r000557_13;
    int sec_r000557_14;
    int sec_r000557_15;
    int sec_r000557_16;
    int sec_r000557_17;
    int sec_r000557_18;
    int sec_r000557_19;
    int sec_r000557_20;
    int sec_r000557_21;
    int pub_r000557_0;
    int pub_r000557_1;
    int pub_r000557_2;
    int pub_r000557_3;
    int pub_r000557_4;
    int pub_r000557_5;
    int pub_r000557_6;
    int pub_r000557_7;
    int pub_r000557_8;
    int pub_r000557_9;
    int pub_r000557_10;
    int pub_r000557_11;
    int pub_r000557_12;
    int pub_r000557_13;
    int pub_r000557_14;
    int pub_r000557_15;
    int pub_r000557_16;
    int pub_r000557_17;
    int pub_r000557_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000557_0 >= -100 && pub_r000557_0 <= 100);
    __CPROVER_assume(pub_r000557_1 >= -100 && pub_r000557_1 <= 100);
    __CPROVER_assume(pub_r000557_2 >= -100 && pub_r000557_2 <= 100);
    __CPROVER_assume(pub_r000557_3 >= -100 && pub_r000557_3 <= 100);
    __CPROVER_assume(pub_r000557_4 >= -100 && pub_r000557_4 <= 100);
    __CPROVER_assume(pub_r000557_5 >= -100 && pub_r000557_5 <= 100);
    __CPROVER_assume(pub_r000557_6 >= -100 && pub_r000557_6 <= 100);
    __CPROVER_assume(pub_r000557_7 >= -100 && pub_r000557_7 <= 100);
    __CPROVER_assume(pub_r000557_8 >= -100 && pub_r000557_8 <= 100);
    __CPROVER_assume(pub_r000557_9 >= -100 && pub_r000557_9 <= 100);
    __CPROVER_assume(pub_r000557_10 >= -100 && pub_r000557_10 <= 100);
    __CPROVER_assume(pub_r000557_11 >= -100 && pub_r000557_11 <= 100);
    __CPROVER_assume(pub_r000557_12 >= -100 && pub_r000557_12 <= 100);
    __CPROVER_assume(pub_r000557_13 >= -100 && pub_r000557_13 <= 100);
    __CPROVER_assume(pub_r000557_14 >= -100 && pub_r000557_14 <= 100);
    __CPROVER_assume(pub_r000557_15 >= -100 && pub_r000557_15 <= 100);
    __CPROVER_assume(pub_r000557_16 >= -100 && pub_r000557_16 <= 100);
    __CPROVER_assume(pub_r000557_17 >= -100 && pub_r000557_17 <= 100);
    __CPROVER_assume(pub_r000557_18 >= -100 && pub_r000557_18 <= 100);
    __CPROVER_assume(sec_r000557_0 >= 0 && sec_r000557_0 <= 255);
    __CPROVER_assume(sec_r000557_1 >= 0 && sec_r000557_1 <= 255);
    __CPROVER_assume(sec_r000557_2 >= 0 && sec_r000557_2 <= 255);
    __CPROVER_assume(sec_r000557_3 >= 0 && sec_r000557_3 <= 255);
    __CPROVER_assume(sec_r000557_4 >= 0 && sec_r000557_4 <= 255);
    __CPROVER_assume(sec_r000557_5 >= 0 && sec_r000557_5 <= 255);
    __CPROVER_assume(sec_r000557_6 >= 0 && sec_r000557_6 <= 255);
    __CPROVER_assume(sec_r000557_7 >= 0 && sec_r000557_7 <= 255);
    __CPROVER_assume(sec_r000557_8 >= 0 && sec_r000557_8 <= 255);
    __CPROVER_assume(sec_r000557_9 >= 0 && sec_r000557_9 <= 255);
    __CPROVER_assume(sec_r000557_10 >= 0 && sec_r000557_10 <= 255);
    __CPROVER_assume(sec_r000557_11 >= 0 && sec_r000557_11 <= 255);
    __CPROVER_assume(sec_r000557_12 >= 0 && sec_r000557_12 <= 255);
    __CPROVER_assume(sec_r000557_13 >= 0 && sec_r000557_13 <= 255);
    __CPROVER_assume(sec_r000557_14 >= 0 && sec_r000557_14 <= 255);
    __CPROVER_assume(sec_r000557_15 >= 0 && sec_r000557_15 <= 255);
    __CPROVER_assume(sec_r000557_16 >= 0 && sec_r000557_16 <= 255);
    __CPROVER_assume(sec_r000557_17 >= 0 && sec_r000557_17 <= 255);
    __CPROVER_assume(sec_r000557_18 >= 0 && sec_r000557_18 <= 255);
    __CPROVER_assume(sec_r000557_19 >= 0 && sec_r000557_19 <= 255);
    __CPROVER_assume(sec_r000557_20 >= 0 && sec_r000557_20 <= 255);
    __CPROVER_assume(sec_r000557_21 >= 0 && sec_r000557_21 <= 255);

    struct SensorNode_R000557_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000557_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000557_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000557_0 + 7) & 15;
    struct EventLog_R000557_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000557_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000557_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000557_0 + 9) & 15;
    struct FilterState_R000557_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000557_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000557_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000557_0 + 11) & 15;

    union PacketPayload_R000557_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 33) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 48) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 20) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 35) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_23 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 20) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 35) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((sec_r000557_1 & 1) != 0) {
        if ((sec_r000557_6 & 2) != 0) {
            stage_v_37 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_38 = (pub_r000557_4 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000557_4 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000557_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_39 = (pub_r000557_11 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000557_11 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000557_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000557_11 & 2) != 0) {
            stage_v_40 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_41 = (pub_r000557_13 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000557_13 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000557_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000557_11 & 2) != 0) {
            stage_v_42 = (pub_r000557_8 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000557_8 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000557_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000557_0 & 2) != 0) {
            stage_v_43 = (pub_r000557_0 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000557_0 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000557_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000557_10 & 2) != 0) {
            stage_v_44 = (pub_r000557_13 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000557_13 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000557_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000557_1 & 2) != 0) {
            stage_v_45 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000557_20 & 1) != 0) {
        if ((sec_r000557_0 & 2) != 0) {
            stage_v_46 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_47 = (pub_r000557_10 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000557_10 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000557_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000557_19 & 2) != 0) {
            stage_v_48 = (pub_r000557_9 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000557_9 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000557_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000557_13 & 2) != 0) {
            stage_v_49 = (pub_r000557_9 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000557_9 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000557_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000557_19 & 2) != 0) {
            stage_v_50 = (pub_r000557_9 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000557_9 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000557_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_51 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_52 = (pub_r000557_8 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000557_8 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000557_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_53 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000557_0 & 1) != 0) {
        if ((sec_r000557_11 & 2) != 0) {
            stage_v_54 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000557_12 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_55 = (pub_r000557_15 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000557_15 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000557_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000557_9 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_56 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000557_10 & 2) != 0) {
            stage_v_57 = (pub_r000557_4 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000557_4 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000557_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((sec_r000557_13 & 1) != 0) {
        if ((sec_r000557_13 & 2) != 0) {
            stage_v_58 = (pub_r000557_8 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000557_8 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000557_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000557_5 & 2) != 0) {
            stage_v_59 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000557_17 & 2) != 0) {
            stage_v_60 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000557_2 & 1) != 0) {
        if ((sec_r000557_6 & 2) != 0) {
            stage_v_61 = (pub_r000557_6 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000557_6 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000557_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000557_4 & 1) != 0) {
        if ((sec_r000557_9 & 2) != 0) {
            stage_v_62 = (pub_r000557_10 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000557_10 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000557_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000557_6 & 2) != 0) {
            stage_v_63 = (pub_r000557_16 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000557_16 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000557_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000557_1 & 1) != 0) {
        if ((sec_r000557_15 & 2) != 0) {
            stage_v_64 = (pub_r000557_13 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000557_13 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000557_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000557_11 & 1) != 0) {
        if ((sec_r000557_17 & 2) != 0) {
            stage_v_65 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000557_8 & 1) != 0) {
        if ((sec_r000557_13 & 2) != 0) {
            stage_v_66 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000557_19 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_67 = (pub_r000557_6 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000557_6 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000557_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000557_4 & 2) != 0) {
            stage_v_68 = (pub_r000557_4 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000557_4 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000557_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000557_14 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_69 = (pub_r000557_6 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000557_6 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000557_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_70 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000557_19 & 2) != 0) {
            stage_v_71 = (pub_r000557_4 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000557_4 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000557_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_72 = (pub_r000557_1 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000557_1 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000557_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_73 = (pub_r000557_6 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000557_6 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000557_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000557_19 & 1) != 0) {
        if ((sec_r000557_9 & 2) != 0) {
            stage_v_74 = (pub_r000557_7 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000557_7 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000557_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000557_8 & 2) != 0) {
            stage_v_75 = (pub_r000557_2 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000557_2 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000557_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000557_11 & 2) != 0) {
            stage_v_76 = (pub_r000557_1 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000557_1 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000557_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000557_10 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_77 = (pub_r000557_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000557_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000557_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000557_15 & 2) != 0) {
            stage_v_78 = (pub_r000557_16 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000557_16 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000557_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000557_0 & 2) != 0) {
            stage_v_79 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000557_2 & 2) != 0) {
            stage_v_80 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000557_17 & 2) != 0) {
            stage_v_81 = (pub_r000557_9 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000557_9 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000557_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000557_4 & 2) != 0) {
            stage_v_82 = (pub_r000557_1 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000557_1 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000557_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000557_2 & 2) != 0) {
            stage_v_83 = (pub_r000557_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000557_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000557_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000557_8 & 2) != 0) {
            stage_v_84 = (pub_r000557_13 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000557_13 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000557_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000557_8 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_85 = (pub_r000557_1 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000557_1 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000557_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_86 = (pub_r000557_8 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000557_8 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000557_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_87 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_88 = (pub_r000557_7 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000557_7 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000557_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000557_6 & 1) != 0) {
        if ((sec_r000557_0 & 2) != 0) {
            stage_v_89 = (pub_r000557_10 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000557_10 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000557_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000557_13 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_90 = (pub_r000557_17 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000557_17 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000557_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_91 = (pub_r000557_16 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000557_16 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000557_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_92 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000557_13 & 1) != 0) {
        if ((sec_r000557_5 & 2) != 0) {
            stage_v_93 = (pub_r000557_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000557_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000557_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_94 = (pub_r000557_10 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000557_10 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000557_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000557_13 & 2) != 0) {
            stage_v_95 = (pub_r000557_8 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000557_8 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000557_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000557_8 & 2) != 0) {
            stage_v_96 = (pub_r000557_15 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000557_15 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000557_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000557_7 & 2) != 0) {
            stage_v_97 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000557_10 & 1) != 0) {
        if ((sec_r000557_12 & 2) != 0) {
            stage_v_98 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_54 & 1) != 0) {
        if ((sec_r000557_6 & 2) != 0) {
            stage_v_99 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000557_0 & 1) != 0) {
        if ((sec_r000557_4 & 2) != 0) {
            stage_v_100 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000557_15 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_101 = (pub_r000557_1 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000557_1 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000557_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000557_0 & 2) != 0) {
            stage_v_102 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000557_4 & 2) != 0) {
            stage_v_103 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000557_2 & 2) != 0) {
            stage_v_104 = (pub_r000557_17 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000557_17 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000557_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000557_17 & 2) != 0) {
            stage_v_105 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000557_4 & 2) != 0) {
            stage_v_106 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000557_11 & 1) != 0) {
        if ((sec_r000557_12 & 2) != 0) {
            stage_v_107 = (pub_r000557_2 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000557_2 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000557_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000557_2 & 2) != 0) {
            stage_v_108 = (pub_r000557_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000557_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000557_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000557_0 & 1) != 0) {
        if ((sec_r000557_17 & 2) != 0) {
            stage_v_109 = (pub_r000557_6 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000557_6 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000557_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_110 = (pub_r000557_17 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000557_17 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000557_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_111 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r000557_15 & 2) != 0) {
            stage_v_112 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000557_14 & 2) != 0) {
            stage_v_113 = (pub_r000557_8 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000557_8 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000557_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000557_21 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_114 = (pub_r000557_14 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000557_14 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000557_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000557_12 & 2) != 0) {
            stage_v_115 = (pub_r000557_16 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000557_16 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000557_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000557_5 & 1) != 0) {
        if ((sec_r000557_8 & 2) != 0) {
            stage_v_116 = (pub_r000557_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000557_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000557_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000557_8 & 2) != 0) {
            stage_v_117 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000557_2 & 2) != 0) {
            stage_v_118 = (pub_r000557_7 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000557_7 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000557_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000557_13 & 2) != 0) {
            stage_v_119 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000557_14 & 2) != 0) {
            stage_v_120 = (pub_r000557_9 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000557_9 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000557_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000557_2 & 2) != 0) {
            stage_v_121 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000557_11 & 2) != 0) {
            stage_v_122 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000557_10 & 1) != 0) {
        if ((sec_r000557_12 & 2) != 0) {
            stage_v_123 = (pub_r000557_4 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000557_4 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000557_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000557_21 & 2) != 0) {
            stage_v_124 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000557_16 & 1) != 0) {
        if ((sec_r000557_13 & 2) != 0) {
            stage_v_125 = (pub_r000557_5 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000557_5 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000557_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000557_19 & 2) != 0) {
            stage_v_126 = (pub_r000557_15 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000557_15 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000557_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000557_5 & 1) != 0) {
        if ((sec_r000557_12 & 2) != 0) {
            stage_v_127 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000557_12 & 2) != 0) {
            stage_v_128 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000557_10 & 1) != 0) {
        if ((sec_r000557_9 & 2) != 0) {
            stage_v_129 = (pub_r000557_3 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000557_3 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000557_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000557_21 & 1) != 0) {
        if ((sec_r000557_20 & 2) != 0) {
            stage_v_130 = (pub_r000557_15 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000557_15 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000557_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000557_13 & 1) != 0) {
        if ((sec_r000557_16 & 2) != 0) {
            stage_v_131 = (pub_r000557_12 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000557_12 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000557_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000557_9 & 2) != 0) {
            stage_v_132 = (pub_r000557_15 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000557_15 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000557_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000557_8 & 2) != 0) {
            stage_v_133 = (pub_r000557_18 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000557_18 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000557_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000557_1 & 2) != 0) {
            stage_v_134 = (pub_r000557_7 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000557_7 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000557_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000557_0 & 1) != 0) {
        if ((sec_r000557_14 & 2) != 0) {
            stage_v_135 = (pub_r000557_10 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000557_10 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000557_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
