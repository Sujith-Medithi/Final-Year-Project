/*
 * Benchmark Program: R000641
 * Security Family: zero_leakage
 * Generator Seed: 564113
 * High Inputs: 17 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000641_4113_0 {
    int seq;
    unsigned char severity;
    short code;
    short timestamp;
    int buffer[3];
};

struct Transaction_R000641_4113_1 {
    int fee;
    int status;
    int account_id;
    int balance;
    int buffer[3];
};

union PacketPayload_R000641_4113_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000641_4113_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000641_4113_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int local_arr[3] = {4, 9, 15};
    int offset_42 = local_arr[aux % 3];
    acc = (acc + offset_42 * 2) & 127;
    int weight_37 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_37 > 10) {
        acc = (acc + weight_37 * 2 + 5) & 127;
        aux ^= (weight_37 & 15);
    } else {
        acc = (acc - weight_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_40 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_40 > 49) {
        acc = (acc + quotient_40 * 2 + 5) & 127;
        aux ^= (quotient_40 & 15);
    } else {
        acc = (acc - quotient_40 + 11) & 127;
        aux += 3;
    }
    int cursor_92 = (aux + st.buffer[1]) & 3;
    switch (cursor_92) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_2(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_70 = local_arr[aux % 3];
    acc = (acc + tracker_70 * 2) & 127;
    int accumulator_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_25) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int vector_39 = local_arr[aux % 3];
    acc = (acc + vector_39 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int scale_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_41) & 63;
    acc ^= aux;
    int mask_29 = (aux + st.buffer[1]) & 3;
    switch (mask_29) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_45 = local_arr[aux % 3];
    acc = (acc + tracker_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int cursor_82 = local_arr[aux % 3];
    acc = (acc + cursor_82 * 2) & 127;
    int segment_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_97) & 63;
    acc ^= aux;
    int segment_66 = (aux + st.buffer[1]) & 3;
    switch (segment_66) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_6(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_80 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_80 > 34) {
        acc = (acc + scale_80 * 2 + 5) & 127;
        aux ^= (scale_80 & 15);
    } else {
        acc = (acc - scale_80 + 11) & 127;
        aux += 3;
    }
    int tracker_47 = (aux + st.buffer[1]) & 3;
    switch (tracker_47) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_74 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_74 > 34) {
        acc = (acc + factor_74 * 2 + 5) & 127;
        aux ^= (factor_74 & 15);
    } else {
        acc = (acc - factor_74 + 11) & 127;
        aux += 3;
    }
    int offset_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_8(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000641_4113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int residue_33 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_33 > 49) {
        acc = (acc + residue_33 * 2 + 5) & 127;
        aux ^= (residue_33 & 15);
    } else {
        acc = (acc - residue_33 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_9(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int anchor_42 = local_arr[aux % 3];
    acc = (acc + anchor_42 * 2) & 127;
    int pivot_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_76) & 63;
    acc ^= aux;
    int weight_84 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_84 > 20) {
        acc = (acc + weight_84 * 2 + 5) & 127;
        aux ^= (weight_84 & 15);
    } else {
        acc = (acc - weight_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int margin_11 = local_arr[aux % 3];
    acc = (acc + margin_11 * 2) & 127;
    int pivot_79 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_79 > 33) {
        acc = (acc + pivot_79 * 2 + 5) & 127;
        aux ^= (pivot_79 & 15);
    } else {
        acc = (acc - pivot_79 + 11) & 127;
        aux += 3;
    }
    int tracker_99 = (aux + st.buffer[1]) & 3;
    switch (tracker_99) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_11(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_56 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_56 > 20) {
        acc = (acc + metric_56 * 2 + 5) & 127;
        aux ^= (metric_56 & 15);
    } else {
        acc = (acc - metric_56 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_52 = local_arr[aux % 3];
    acc = (acc + quotient_52 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_68 = (aux + st.buffer[1]) & 3;
    switch (checksum_68) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quotient_30 = (aux + st.buffer[1]) & 3;
    switch (quotient_30) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_29 = (aux + st.buffer[1]) & 3;
    switch (parity_29) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_87 = local_arr[aux % 3];
    acc = (acc + tally_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000641_4113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int quantum_63 = (aux + st.buffer[1]) & 3;
    switch (quantum_63) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_72 = local_arr[aux % 3];
    acc = (acc + threshold_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_81) & 63;
    acc ^= aux;
    int margin_21 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_21 > 47) {
        acc = (acc + margin_21 * 2 + 5) & 127;
        aux ^= (margin_21 & 15);
    } else {
        acc = (acc - margin_21 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_55 = local_arr[aux % 3];
    acc = (acc + pivot_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_16(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000641_4113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int stride_18 = (aux + st.buffer[1]) & 3;
    switch (stride_18) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_34 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_34 > 17) {
        acc = (acc + phase_34 * 2 + 5) & 127;
        aux ^= (phase_34 & 15);
    } else {
        acc = (acc - phase_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_22 = local_arr[aux % 3];
    acc = (acc + tally_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_17(int p0, int p1, int p2) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000641_4113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_66 = (aux + st.buffer[1]) & 3;
    switch (bound_66) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_75) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_13 = local_arr[aux % 3];
    acc = (acc + metric_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000641_4113_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int metric_61 = (aux + st.buffer[1]) & 3;
    switch (metric_61) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_79 = local_arr[aux % 3];
    acc = (acc + anchor_79 * 2) & 127;
    int damping_85 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_85 > 41) {
        acc = (acc + damping_85 * 2 + 5) & 127;
        aux ^= (damping_85 & 15);
    } else {
        acc = (acc - damping_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000641_4113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int quotient_48 = local_arr[aux % 3];
    acc = (acc + quotient_48 * 2) & 127;
    int bound_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int pivot_16 = (aux + st.buffer[1]) & 3;
    switch (pivot_16) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int window_96 = (aux + st.buffer[1]) & 3;
    switch (window_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_90 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_90 > 16) {
        acc = (acc + quantum_90 * 2 + 5) & 127;
        aux ^= (quantum_90 & 15);
    } else {
        acc = (acc - quantum_90 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000641_4113_22(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000641_4113_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int stride_39 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_39 > 18) {
        acc = (acc + stride_39 * 2 + 5) & 127;
        aux ^= (stride_39 & 15);
    } else {
        acc = (acc - stride_39 + 11) & 127;
        aux += 3;
    }
    int parity_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000641_4113_23(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000641_4113_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_84 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_84 > 27) {
        acc = (acc + phase_84 * 2 + 5) & 127;
        aux ^= (phase_84 & 15);
    } else {
        acc = (acc - phase_84 + 11) & 127;
        aux += 3;
    }
    int phase_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_34) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quantum_49 = local_arr[aux % 3];
    acc = (acc + quantum_49 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000641_0;
    int sec_r000641_1;
    int sec_r000641_2;
    int sec_r000641_3;
    int sec_r000641_4;
    int sec_r000641_5;
    int sec_r000641_6;
    int sec_r000641_7;
    int sec_r000641_8;
    int sec_r000641_9;
    int sec_r000641_10;
    int sec_r000641_11;
    int sec_r000641_12;
    int sec_r000641_13;
    int sec_r000641_14;
    int sec_r000641_15;
    int sec_r000641_16;
    int pub_r000641_0;
    int pub_r000641_1;
    int pub_r000641_2;
    int pub_r000641_3;
    int pub_r000641_4;
    int pub_r000641_5;
    int pub_r000641_6;
    int pub_r000641_7;
    int pub_r000641_8;
    int pub_r000641_9;
    int pub_r000641_10;
    int pub_r000641_11;
    int pub_r000641_12;
    int pub_r000641_13;
    int pub_r000641_14;
    int pub_r000641_15;
    int pub_r000641_16;
    int pub_r000641_17;
    int pub_r000641_18;
    int pub_r000641_19;
    int pub_r000641_20;
    int pub_r000641_21;
    int pub_r000641_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000641_0 >= -100 && pub_r000641_0 <= 100);
    __CPROVER_assume(pub_r000641_1 >= -100 && pub_r000641_1 <= 100);
    __CPROVER_assume(pub_r000641_2 >= -100 && pub_r000641_2 <= 100);
    __CPROVER_assume(pub_r000641_3 >= -100 && pub_r000641_3 <= 100);
    __CPROVER_assume(pub_r000641_4 >= -100 && pub_r000641_4 <= 100);
    __CPROVER_assume(pub_r000641_5 >= -100 && pub_r000641_5 <= 100);
    __CPROVER_assume(pub_r000641_6 >= -100 && pub_r000641_6 <= 100);
    __CPROVER_assume(pub_r000641_7 >= -100 && pub_r000641_7 <= 100);
    __CPROVER_assume(pub_r000641_8 >= -100 && pub_r000641_8 <= 100);
    __CPROVER_assume(pub_r000641_9 >= -100 && pub_r000641_9 <= 100);
    __CPROVER_assume(pub_r000641_10 >= -100 && pub_r000641_10 <= 100);
    __CPROVER_assume(pub_r000641_11 >= -100 && pub_r000641_11 <= 100);
    __CPROVER_assume(pub_r000641_12 >= -100 && pub_r000641_12 <= 100);
    __CPROVER_assume(pub_r000641_13 >= -100 && pub_r000641_13 <= 100);
    __CPROVER_assume(pub_r000641_14 >= -100 && pub_r000641_14 <= 100);
    __CPROVER_assume(pub_r000641_15 >= -100 && pub_r000641_15 <= 100);
    __CPROVER_assume(pub_r000641_16 >= -100 && pub_r000641_16 <= 100);
    __CPROVER_assume(pub_r000641_17 >= -100 && pub_r000641_17 <= 100);
    __CPROVER_assume(pub_r000641_18 >= -100 && pub_r000641_18 <= 100);
    __CPROVER_assume(pub_r000641_19 >= -100 && pub_r000641_19 <= 100);
    __CPROVER_assume(pub_r000641_20 >= -100 && pub_r000641_20 <= 100);
    __CPROVER_assume(pub_r000641_21 >= -100 && pub_r000641_21 <= 100);
    __CPROVER_assume(pub_r000641_22 >= -100 && pub_r000641_22 <= 100);
    __CPROVER_assume(sec_r000641_0 >= 0 && sec_r000641_0 <= 255);
    __CPROVER_assume(sec_r000641_1 >= 0 && sec_r000641_1 <= 255);
    __CPROVER_assume(sec_r000641_2 >= 0 && sec_r000641_2 <= 255);
    __CPROVER_assume(sec_r000641_3 >= 0 && sec_r000641_3 <= 255);
    __CPROVER_assume(sec_r000641_4 >= 0 && sec_r000641_4 <= 255);
    __CPROVER_assume(sec_r000641_5 >= 0 && sec_r000641_5 <= 255);
    __CPROVER_assume(sec_r000641_6 >= 0 && sec_r000641_6 <= 255);
    __CPROVER_assume(sec_r000641_7 >= 0 && sec_r000641_7 <= 255);
    __CPROVER_assume(sec_r000641_8 >= 0 && sec_r000641_8 <= 255);
    __CPROVER_assume(sec_r000641_9 >= 0 && sec_r000641_9 <= 255);
    __CPROVER_assume(sec_r000641_10 >= 0 && sec_r000641_10 <= 255);
    __CPROVER_assume(sec_r000641_11 >= 0 && sec_r000641_11 <= 255);
    __CPROVER_assume(sec_r000641_12 >= 0 && sec_r000641_12 <= 255);
    __CPROVER_assume(sec_r000641_13 >= 0 && sec_r000641_13 <= 255);
    __CPROVER_assume(sec_r000641_14 >= 0 && sec_r000641_14 <= 255);
    __CPROVER_assume(sec_r000641_15 >= 0 && sec_r000641_15 <= 255);
    __CPROVER_assume(sec_r000641_16 >= 0 && sec_r000641_16 <= 255);

    struct EventLog_R000641_4113_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000641_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000641_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000641_0 + 7) & 15;
    struct Transaction_R000641_4113_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000641_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000641_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000641_0 + 9) & 15;

    union PacketPayload_R000641_4113_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 23) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 38) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 22) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 37) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 10) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 25) {
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
    if (stage_v_13 > 29) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 44) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 24) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 39) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 39) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 54) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 26) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 41) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 27) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 42) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 28) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 43) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 12) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 27) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 87) & 15;
    int stage_v_86 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= stage_v_86;

    /* Execution Pipeline Stage 87 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 27) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 42) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 27) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 42) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 93) & 15;
    int stage_v_92 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    chk_sum ^= stage_v_92;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (st_var_0.buffer[0] ^ 97) & 3;
    switch (stage_v_94) {
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

    /* Execution Pipeline Stage 95 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 96) & 15;
    int stage_v_95 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= stage_v_95;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (out_sink > 100) ? (chk_sum & 31) : (101 & 31);
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= (stage_v_96 << 1) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 29) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 44) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = table[3];
    table[3] = (table[0] + 199) & 63;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_1.buffer[0] ^ 104) & 3;
    switch (stage_v_101) {
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

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 33) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 48) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_1.buffer[0] ^ 108) & 3;
    switch (stage_v_105) {
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

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_1.buffer[2] * 2 + 328) & 63;
    if (stage_v_107 > 16) {
        out_sink = (out_sink + stage_v_107 - 5) & 255;
        if (stage_v_107 > 31) {
            chk_sum ^= (stage_v_107 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_107 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = table[0];
    table[0] = (table[1] + 217) & 63;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[1] * 2 + 334) & 63;
    if (stage_v_109 > 19) {
        out_sink = (out_sink + stage_v_109 - 5) & 255;
        if (stage_v_109 > 34) {
            chk_sum ^= (stage_v_109 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_109 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_0.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
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

    /* Execution Pipeline Stage 111 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 112) & 15;
    int stage_v_111 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= stage_v_111;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_0.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 17) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 32) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 117 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (out_sink > 100) ? (chk_sum & 31) : (123 & 31);
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= (stage_v_118 << 1) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_1.buffer[0] ^ 122) & 3;
    switch (stage_v_119) {
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

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_0.buffer[0] ^ 125) & 3;
    switch (stage_v_122) {
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

    /* Execution Pipeline Stage 123 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (out_sink > 100) ? (chk_sum & 31) : (131 & 31);
    out_sink = (out_sink + stage_v_126) & 255;
    chk_sum ^= (stage_v_126 << 1) & 127;

    /* Execution Pipeline Stage 127 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 128) & 15;
    int stage_v_127 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= stage_v_127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] * 2 + 394) & 63;
    if (stage_v_129 > 39) {
        out_sink = (out_sink + stage_v_129 - 5) & 255;
        if (stage_v_129 > 54) {
            chk_sum ^= (stage_v_129 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_129 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_0.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 25) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 40) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (out_sink > 100) ? (chk_sum & 31) : (136 & 31);
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= (stage_v_131 << 1) & 127;

    /* Execution Pipeline Stage 132 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 133) & 15;
    int stage_v_132 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= stage_v_132;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = table[2];
    table[2] = (table[3] + 269) & 63;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 16) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 31) {
            chk_sum ^= (stage_v_140 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_140 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_1.buffer[0] ^ 144) & 3;
    switch (stage_v_141) {
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

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (out_sink > 100) ? (chk_sum & 31) : (151 & 31);
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= (stage_v_146 << 1) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_1.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 149 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 150) & 15;
    int stage_v_149 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= stage_v_149;

    /* Execution Pipeline Stage 150 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 151) & 15;
    int stage_v_150 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= stage_v_150;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_0.buffer[0] ^ 155) & 3;
    switch (stage_v_152) {
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

    /* Execution Pipeline Stage 153 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 154) & 15;
    int stage_v_153 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= stage_v_153;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] ^ 159) & 3;
    switch (stage_v_156) {
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

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = table[1];
    table[1] = (table[2] + 315) & 63;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (out_sink > 100) ? (chk_sum & 31) : (163 & 31);
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= (stage_v_158 << 1) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = table[3];
    table[3] = (table[0] + 319) & 63;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 35) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 50) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 17) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 32) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 168) & 15;
    int stage_v_167 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= stage_v_167;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (out_sink > 100) ? (chk_sum & 31) : (173 & 31);
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= (stage_v_168 << 1) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
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

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_1.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 20) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 35) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 173) & 15;
    int stage_v_172 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= stage_v_172;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (out_sink > 100) ? (chk_sum & 31) : (180 & 31);
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= (stage_v_175 << 1) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_177 = (stage_v_177 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_177) & 127;
    }
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_178 = (stage_v_178 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 181) & 15;
    int stage_v_180 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= stage_v_180;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = table[1];
    table[1] = (table[2] + 363) & 63;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (st_var_0.buffer[2] * 2 + 553) & 63;
    if (stage_v_182 > 18) {
        out_sink = (out_sink + stage_v_182 - 5) & 255;
        if (stage_v_182 > 33) {
            chk_sum ^= (stage_v_182 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_182 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (out_sink > 100) ? (chk_sum & 31) : (189 & 31);
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= (stage_v_184 << 1) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = table[1];
    table[1] = (table[2] + 371) & 63;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_186 = (stage_v_186 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_186) & 127;
    }
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_187 = (stage_v_187 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_187) & 127;
    }
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (st_var_1.buffer[0] ^ 192) & 3;
    switch (stage_v_189) {
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

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_0.buffer[0] ^ 193) & 3;
    switch (stage_v_190) {
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

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_1.buffer[0] ^ 194) & 3;
    switch (stage_v_191) {
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

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] * 2 + 583) & 63;
    if (stage_v_192 > 15) {
        out_sink = (out_sink + stage_v_192 - 5) & 255;
        if (stage_v_192 > 30) {
            chk_sum ^= (stage_v_192 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_192 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = table[2];
    table[2] = (table[3] + 389) & 63;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (out_sink > 100) ? (chk_sum & 31) : (200 & 31);
    out_sink = (out_sink + stage_v_195) & 255;
    chk_sum ^= (stage_v_195 << 1) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_0.buffer[0] ^ 199) & 3;
    switch (stage_v_196) {
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

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (st_var_1.buffer[0] ^ 200) & 3;
    switch (stage_v_197) {
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

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] * 2 + 601) & 63;
    if (stage_v_198 > 14) {
        out_sink = (out_sink + stage_v_198 - 5) & 255;
        if (stage_v_198 > 29) {
            chk_sum ^= (stage_v_198 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_198 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (out_sink > 100) ? (chk_sum & 31) : (204 & 31);
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= (stage_v_199 << 1) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = table[1];
    table[1] = (table[2] + 403) & 63;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (st_var_0.buffer[1] * 2 + 613) & 63;
    if (stage_v_202 > 40) {
        out_sink = (out_sink + stage_v_202 - 5) & 255;
        if (stage_v_202 > 55) {
            chk_sum ^= (stage_v_202 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_202 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = table[3];
    table[3] = (table[0] + 407) & 63;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_204 = (stage_v_204 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_204) & 127;
    }
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = table[1];
    table[1] = (table[2] + 411) & 63;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (out_sink > 100) ? (chk_sum & 31) : (211 & 31);
    out_sink = (out_sink + stage_v_206) & 255;
    chk_sum ^= (stage_v_206 << 1) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (st_var_1.buffer[0] ^ 210) & 3;
    switch (stage_v_207) {
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

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_208 = (stage_v_208 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_208) & 127;
    }
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = table[1];
    table[1] = (table[2] + 419) & 63;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (st_var_0.buffer[0] * 2 + 637) & 63;
    if (stage_v_210 > 36) {
        out_sink = (out_sink + stage_v_210 - 5) & 255;
        if (stage_v_210 > 51) {
            chk_sum ^= (stage_v_210 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_210 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (st_var_1.buffer[1] * 2 + 640) & 63;
    if (stage_v_211 > 24) {
        out_sink = (out_sink + stage_v_211 - 5) & 255;
        if (stage_v_211 > 39) {
            chk_sum ^= (stage_v_211 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_211 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (out_sink > 100) ? (chk_sum & 31) : (217 & 31);
    out_sink = (out_sink + stage_v_212) & 255;
    chk_sum ^= (stage_v_212 << 1) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (out_sink > 100) ? (chk_sum & 31) : (218 & 31);
    out_sink = (out_sink + stage_v_213) & 255;
    chk_sum ^= (stage_v_213 << 1) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_214 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_215 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_216 = (stage_v_216 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_216) & 127;
    }
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (out_sink > 100) ? (chk_sum & 31) : (222 & 31);
    out_sink = (out_sink + stage_v_217) & 255;
    chk_sum ^= (stage_v_217 << 1) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (st_var_0.buffer[0] ^ 221) & 3;
    switch (stage_v_218) {
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

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (st_var_1.buffer[0] * 2 + 664) & 63;
    if (stage_v_219 > 18) {
        out_sink = (out_sink + stage_v_219 - 5) & 255;
        if (stage_v_219 > 33) {
            chk_sum ^= (stage_v_219 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_219 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (st_var_1.buffer[0] ^ 224) & 3;
    switch (stage_v_221) {
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

    /* Zero Leakage Neutralization */
    int dead_sec_0 = (sec_r000641_0 ^ sec_r000641_0) * 0;
    int dead_sec_1 = (sec_r000641_1 ^ sec_r000641_1) * 0;
    int dead_sec_2 = (sec_r000641_2 ^ sec_r000641_2) * 0;
    int dead_sec_3 = (sec_r000641_3 ^ sec_r000641_3) * 0;
    out_sink = (out_sink + dead_sec_0 + dead_sec_1 + dead_sec_2 + dead_sec_3) & 255;
    g_out = out_sink;
    g_chk = chk_sum;
    g_telemetry = (chk_sum ^ 0x55) & 127;
    return 0;
}
