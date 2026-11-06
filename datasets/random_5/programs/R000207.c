/*
 * Benchmark Program: R000207
 * Security Family: nested_implicit_flow
 * Generator Seed: 520713
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000207_713_0 {
    short damping;
    int prev_in;
    int mode;
    int buffer[3];
};

struct AudioFrame_R000207_713_1 {
    int peak;
    int envelope;
    short channels;
    unsigned char gain;
    int buffer[3];
};

struct StreamBuffer_R000207_713_2 {
    unsigned char watermark;
    int state;
    unsigned char head;
    int checksum;
    int capacity;
    int tail;
    int buffer[3];
};

union RegisterBank_R000207_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000207_713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int bound_88 = (aux + st.buffer[1]) & 3;
    switch (bound_88) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_89 = local_arr[aux % 3];
    acc = (acc + tracker_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_1(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_41) & 63;
    acc ^= aux;
    int mask_20 = (aux + st.buffer[1]) & 3;
    switch (mask_20) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_65 = local_arr[aux % 3];
    acc = (acc + margin_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int cursor_69 = (aux + st.buffer[1]) & 3;
    switch (cursor_69) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_35) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int segment_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_97 = local_arr[aux % 3];
    acc = (acc + residue_97 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_43 = (aux + st.buffer[1]) & 3;
    switch (checksum_43) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_5(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int tally_64 = (aux + st.buffer[1]) & 3;
    switch (tally_64) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_75 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_75 > 21) {
        acc = (acc + cursor_75 * 2 + 5) & 127;
        aux ^= (cursor_75 & 15);
    } else {
        acc = (acc - cursor_75 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_26 = local_arr[aux % 3];
    acc = (acc + damping_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_6(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int offset_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_80) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_72 = local_arr[aux % 3];
    acc = (acc + sample_72 * 2) & 127;
    int window_52 = (st.buffer[0] * 3 + aux) & 63;
    if (window_52 > 18) {
        acc = (acc + window_52 * 2 + 5) & 127;
        aux ^= (window_52 & 15);
    } else {
        acc = (acc - window_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_7(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_44 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_44 > 16) {
        acc = (acc + segment_44 * 2 + 5) & 127;
        aux ^= (segment_44 & 15);
    } else {
        acc = (acc - segment_44 + 11) & 127;
        aux += 3;
    }
    int phase_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_57) & 63;
    acc ^= aux;
    int residue_49 = (aux + st.buffer[1]) & 3;
    switch (residue_49) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_8(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quantum_60 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_60 > 49) {
        acc = (acc + quantum_60 * 2 + 5) & 127;
        aux ^= (quantum_60 & 15);
    } else {
        acc = (acc - quantum_60 + 11) & 127;
        aux += 3;
    }
    int index_reg_37 = (aux + st.buffer[1]) & 3;
    switch (index_reg_37) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_87) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_48 = local_arr[aux % 3];
    acc = (acc + parity_48 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_9(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int threshold_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_23) & 63;
    acc ^= aux;
    int segment_18 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_18 > 16) {
        acc = (acc + segment_18 * 2 + 5) & 127;
        aux ^= (segment_18 & 15);
    } else {
        acc = (acc - segment_18 + 11) & 127;
        aux += 3;
    }
    int coefficient_42 = (aux + st.buffer[1]) & 3;
    switch (coefficient_42) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000207_713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_16 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_16 > 21) {
        acc = (acc + phase_16 * 2 + 5) & 127;
        aux ^= (phase_16 & 15);
    } else {
        acc = (acc - phase_16 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_11(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int tally_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_82 = local_arr[aux % 3];
    acc = (acc + factor_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int damping_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_78) & 63;
    acc ^= aux;
    int pivot_16 = (aux + st.buffer[1]) & 3;
    switch (pivot_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000207_713_13(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int index_reg_40 = local_arr[aux % 3];
    acc = (acc + index_reg_40 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_15 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_15) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000207_713_14(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_73 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_73 > 50) {
        acc = (acc + bound_73 * 2 + 5) & 127;
        aux ^= (bound_73 & 15);
    } else {
        acc = (acc - bound_73 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_43 = local_arr[aux % 3];
    acc = (acc + window_43 * 2) & 127;
    int factor_63 = (aux + st.buffer[1]) & 3;
    switch (factor_63) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_15(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int weight_54 = local_arr[aux % 3];
    acc = (acc + weight_54 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_11 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_11 > 14) {
        acc = (acc + damping_11 * 2 + 5) & 127;
        aux ^= (damping_11 & 15);
    } else {
        acc = (acc - damping_11 + 11) & 127;
        aux += 3;
    }
    int residue_95 = (aux + st.buffer[1]) & 3;
    switch (residue_95) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000207_713_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_83 = (aux + st.buffer[1]) & 3;
    switch (tracker_83) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_55 = local_arr[aux % 3];
    acc = (acc + anchor_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_17(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_90 = (aux + st.buffer[1]) & 3;
    switch (mask_90) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_67 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_67 > 12) {
        acc = (acc + factor_67 * 2 + 5) & 127;
        aux ^= (factor_67 & 15);
    } else {
        acc = (acc - factor_67 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int metric_84 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_84 > 33) {
        acc = (acc + metric_84 * 2 + 5) & 127;
        aux ^= (metric_84 & 15);
    } else {
        acc = (acc - metric_84 + 11) & 127;
        aux += 3;
    }
    int mask_79 = (aux + st.buffer[1]) & 3;
    switch (mask_79) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_67 = local_arr[aux % 3];
    acc = (acc + checksum_67 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int metric_22 = local_arr[aux % 3];
    acc = (acc + metric_22 * 2) & 127;
    int quotient_62 = (aux + st.buffer[1]) & 3;
    switch (quotient_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_66 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_66 > 42) {
        acc = (acc + bound_66 * 2 + 5) & 127;
        aux ^= (bound_66 & 15);
    } else {
        acc = (acc - bound_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000207_713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int scale_56 = (aux + st.buffer[1]) & 3;
    switch (scale_56) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_77 = local_arr[aux % 3];
    acc = (acc + window_77 * 2) & 127;
    int delta_87 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_87 > 34) {
        acc = (acc + delta_87 * 2 + 5) & 127;
        aux ^= (delta_87 & 15);
    } else {
        acc = (acc - delta_87 + 11) & 127;
        aux += 3;
    }
    int bound_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000207_713_21(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000207_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int margin_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_22(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000207_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_72 = (aux + st.buffer[1]) & 3;
    switch (stride_72) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_11 = local_arr[aux % 3];
    acc = (acc + threshold_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000207_713_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000207_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int window_53 = local_arr[aux % 3];
    acc = (acc + window_53 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_84 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_84 > 50) {
        acc = (acc + margin_84 * 2 + 5) & 127;
        aux ^= (margin_84 & 15);
    } else {
        acc = (acc - margin_84 + 11) & 127;
        aux += 3;
    }
    int bound_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000207_0;
    int sec_r000207_1;
    int sec_r000207_2;
    int sec_r000207_3;
    int sec_r000207_4;
    int sec_r000207_5;
    int sec_r000207_6;
    int sec_r000207_7;
    int sec_r000207_8;
    int sec_r000207_9;
    int sec_r000207_10;
    int sec_r000207_11;
    int sec_r000207_12;
    int sec_r000207_13;
    int sec_r000207_14;
    int sec_r000207_15;
    int sec_r000207_16;
    int sec_r000207_17;
    int sec_r000207_18;
    int sec_r000207_19;
    int pub_r000207_0;
    int pub_r000207_1;
    int pub_r000207_2;
    int pub_r000207_3;
    int pub_r000207_4;
    int pub_r000207_5;
    int pub_r000207_6;
    int pub_r000207_7;
    int pub_r000207_8;
    int pub_r000207_9;
    int pub_r000207_10;
    int pub_r000207_11;
    int pub_r000207_12;
    int pub_r000207_13;
    int pub_r000207_14;
    int pub_r000207_15;
    int pub_r000207_16;
    int pub_r000207_17;
    int pub_r000207_18;
    int pub_r000207_19;
    int pub_r000207_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000207_0 >= -100 && pub_r000207_0 <= 100);
    __CPROVER_assume(pub_r000207_1 >= -100 && pub_r000207_1 <= 100);
    __CPROVER_assume(pub_r000207_2 >= -100 && pub_r000207_2 <= 100);
    __CPROVER_assume(pub_r000207_3 >= -100 && pub_r000207_3 <= 100);
    __CPROVER_assume(pub_r000207_4 >= -100 && pub_r000207_4 <= 100);
    __CPROVER_assume(pub_r000207_5 >= -100 && pub_r000207_5 <= 100);
    __CPROVER_assume(pub_r000207_6 >= -100 && pub_r000207_6 <= 100);
    __CPROVER_assume(pub_r000207_7 >= -100 && pub_r000207_7 <= 100);
    __CPROVER_assume(pub_r000207_8 >= -100 && pub_r000207_8 <= 100);
    __CPROVER_assume(pub_r000207_9 >= -100 && pub_r000207_9 <= 100);
    __CPROVER_assume(pub_r000207_10 >= -100 && pub_r000207_10 <= 100);
    __CPROVER_assume(pub_r000207_11 >= -100 && pub_r000207_11 <= 100);
    __CPROVER_assume(pub_r000207_12 >= -100 && pub_r000207_12 <= 100);
    __CPROVER_assume(pub_r000207_13 >= -100 && pub_r000207_13 <= 100);
    __CPROVER_assume(pub_r000207_14 >= -100 && pub_r000207_14 <= 100);
    __CPROVER_assume(pub_r000207_15 >= -100 && pub_r000207_15 <= 100);
    __CPROVER_assume(pub_r000207_16 >= -100 && pub_r000207_16 <= 100);
    __CPROVER_assume(pub_r000207_17 >= -100 && pub_r000207_17 <= 100);
    __CPROVER_assume(pub_r000207_18 >= -100 && pub_r000207_18 <= 100);
    __CPROVER_assume(pub_r000207_19 >= -100 && pub_r000207_19 <= 100);
    __CPROVER_assume(pub_r000207_20 >= -100 && pub_r000207_20 <= 100);
    __CPROVER_assume(sec_r000207_0 >= 0 && sec_r000207_0 <= 255);
    __CPROVER_assume(sec_r000207_1 >= 0 && sec_r000207_1 <= 255);
    __CPROVER_assume(sec_r000207_2 >= 0 && sec_r000207_2 <= 255);
    __CPROVER_assume(sec_r000207_3 >= 0 && sec_r000207_3 <= 255);
    __CPROVER_assume(sec_r000207_4 >= 0 && sec_r000207_4 <= 255);
    __CPROVER_assume(sec_r000207_5 >= 0 && sec_r000207_5 <= 255);
    __CPROVER_assume(sec_r000207_6 >= 0 && sec_r000207_6 <= 255);
    __CPROVER_assume(sec_r000207_7 >= 0 && sec_r000207_7 <= 255);
    __CPROVER_assume(sec_r000207_8 >= 0 && sec_r000207_8 <= 255);
    __CPROVER_assume(sec_r000207_9 >= 0 && sec_r000207_9 <= 255);
    __CPROVER_assume(sec_r000207_10 >= 0 && sec_r000207_10 <= 255);
    __CPROVER_assume(sec_r000207_11 >= 0 && sec_r000207_11 <= 255);
    __CPROVER_assume(sec_r000207_12 >= 0 && sec_r000207_12 <= 255);
    __CPROVER_assume(sec_r000207_13 >= 0 && sec_r000207_13 <= 255);
    __CPROVER_assume(sec_r000207_14 >= 0 && sec_r000207_14 <= 255);
    __CPROVER_assume(sec_r000207_15 >= 0 && sec_r000207_15 <= 255);
    __CPROVER_assume(sec_r000207_16 >= 0 && sec_r000207_16 <= 255);
    __CPROVER_assume(sec_r000207_17 >= 0 && sec_r000207_17 <= 255);
    __CPROVER_assume(sec_r000207_18 >= 0 && sec_r000207_18 <= 255);
    __CPROVER_assume(sec_r000207_19 >= 0 && sec_r000207_19 <= 255);

    struct FilterState_R000207_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000207_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000207_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000207_0 + 7) & 15;
    struct AudioFrame_R000207_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000207_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000207_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000207_0 + 9) & 15;
    struct StreamBuffer_R000207_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000207_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000207_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000207_0 + 11) & 15;

    union RegisterBank_R000207_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 31) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 46) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 11) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 26) {
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
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

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
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

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
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 32) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 47) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 37) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 52) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 23) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 38) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 27) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 42) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
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
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 18) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 33) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 23) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 38) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 19) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 34) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000207_19 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_64 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000207_9 & 1) != 0) {
        if ((sec_r000207_9 & 2) != 0) {
            stage_v_65 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000207_0 & 2) != 0) {
            stage_v_66 = (pub_r000207_20 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000207_20 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000207_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000207_1 & 2) != 0) {
            stage_v_67 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((sec_r000207_17 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_68 = (pub_r000207_3 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000207_3 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000207_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000207_4 & 2) != 0) {
            stage_v_69 = (pub_r000207_2 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000207_2 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000207_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000207_10 & 2) != 0) {
            stage_v_70 = (pub_r000207_12 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000207_12 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000207_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000207_10 & 2) != 0) {
            stage_v_71 = (pub_r000207_3 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000207_3 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000207_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000207_6 & 2) != 0) {
            stage_v_72 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_73 = (pub_r000207_13 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000207_13 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000207_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000207_14 & 2) != 0) {
            stage_v_74 = (pub_r000207_17 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000207_17 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000207_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000207_1 & 2) != 0) {
            stage_v_75 = (pub_r000207_1 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000207_1 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000207_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000207_19 & 1) != 0) {
        if ((sec_r000207_2 & 2) != 0) {
            stage_v_76 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000207_18 & 2) != 0) {
            stage_v_77 = (pub_r000207_14 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000207_14 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000207_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000207_16 & 2) != 0) {
            stage_v_78 = (pub_r000207_6 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000207_6 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000207_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000207_1 & 1) != 0) {
        if ((sec_r000207_19 & 2) != 0) {
            stage_v_79 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000207_14 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_80 = (pub_r000207_8 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000207_8 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000207_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_81 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000207_19 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_82 = (pub_r000207_12 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000207_12 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000207_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_83 = (pub_r000207_14 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000207_14 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000207_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000207_11 & 2) != 0) {
            stage_v_84 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000207_12 & 2) != 0) {
            stage_v_85 = (pub_r000207_7 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000207_7 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000207_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000207_19 & 2) != 0) {
            stage_v_86 = (pub_r000207_3 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000207_3 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000207_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000207_7 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_87 = (pub_r000207_10 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000207_10 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000207_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000207_19 & 2) != 0) {
            stage_v_88 = (pub_r000207_19 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000207_19 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000207_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000207_19 & 2) != 0) {
            stage_v_89 = (pub_r000207_13 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000207_13 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000207_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000207_0 & 1) != 0) {
        if ((sec_r000207_13 & 2) != 0) {
            stage_v_90 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000207_10 & 2) != 0) {
            stage_v_91 = (pub_r000207_15 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000207_15 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000207_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000207_18 & 2) != 0) {
            stage_v_92 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000207_12 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_93 = (pub_r000207_10 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000207_10 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000207_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000207_11 & 1) != 0) {
        if ((sec_r000207_16 & 2) != 0) {
            stage_v_94 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_95 = (pub_r000207_17 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000207_17 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000207_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000207_16 & 2) != 0) {
            stage_v_96 = (pub_r000207_6 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000207_6 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000207_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_97 = (pub_r000207_8 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000207_8 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000207_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_98 = (pub_r000207_4 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000207_4 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000207_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000207_0 & 1) != 0) {
        if ((sec_r000207_10 & 2) != 0) {
            stage_v_99 = (pub_r000207_18 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000207_18 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000207_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000207_15 & 2) != 0) {
            stage_v_100 = (pub_r000207_12 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000207_12 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000207_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000207_15 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_101 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_102 = (pub_r000207_0 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000207_0 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000207_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000207_11 & 2) != 0) {
            stage_v_103 = (pub_r000207_6 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000207_6 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000207_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_104 = (pub_r000207_14 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000207_14 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000207_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000207_8 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_105 = (pub_r000207_4 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000207_4 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000207_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000207_6 & 2) != 0) {
            stage_v_106 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000207_9 & 2) != 0) {
            stage_v_107 = (pub_r000207_3 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000207_3 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000207_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000207_14 & 2) != 0) {
            stage_v_108 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000207_11 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_109 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000207_8 & 2) != 0) {
            stage_v_110 = (pub_r000207_8 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000207_8 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000207_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000207_2 & 2) != 0) {
            stage_v_111 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000207_12 & 2) != 0) {
            stage_v_112 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_113 = (pub_r000207_19 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000207_19 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000207_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000207_14 & 2) != 0) {
            stage_v_114 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r000207_9 & 2) != 0) {
            stage_v_115 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000207_1 & 1) != 0) {
        if ((sec_r000207_16 & 2) != 0) {
            stage_v_116 = (pub_r000207_11 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000207_11 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000207_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000207_10 & 1) != 0) {
        if ((sec_r000207_15 & 2) != 0) {
            stage_v_117 = (pub_r000207_2 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000207_2 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000207_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_118 = (pub_r000207_8 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000207_8 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000207_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000207_14 & 1) != 0) {
        if ((sec_r000207_0 & 2) != 0) {
            stage_v_119 = (pub_r000207_20 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000207_20 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000207_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000207_2 & 2) != 0) {
            stage_v_120 = (pub_r000207_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000207_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000207_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000207_4 & 2) != 0) {
            stage_v_121 = (pub_r000207_3 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000207_3 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000207_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000207_10 & 2) != 0) {
            stage_v_122 = (pub_r000207_17 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000207_17 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000207_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000207_2 & 2) != 0) {
            stage_v_123 = (pub_r000207_11 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000207_11 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000207_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000207_11 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_124 = (pub_r000207_18 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000207_18 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000207_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000207_7 & 1) != 0) {
        if ((sec_r000207_16 & 2) != 0) {
            stage_v_125 = (pub_r000207_13 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000207_13 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000207_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000207_12 & 2) != 0) {
            stage_v_126 = (pub_r000207_5 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000207_5 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000207_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000207_2 & 1) != 0) {
        if ((sec_r000207_10 & 2) != 0) {
            stage_v_127 = (pub_r000207_15 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000207_15 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000207_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000207_9 & 2) != 0) {
            stage_v_128 = (pub_r000207_15 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000207_15 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000207_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000207_15 & 2) != 0) {
            stage_v_129 = (pub_r000207_7 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000207_7 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000207_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_130 = (pub_r000207_1 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000207_1 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000207_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000207_6 & 1) != 0) {
        if ((sec_r000207_5 & 2) != 0) {
            stage_v_131 = (pub_r000207_18 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000207_18 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000207_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000207_19 & 2) != 0) {
            stage_v_132 = (pub_r000207_9 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000207_9 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000207_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_127 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_133 = (pub_r000207_16 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000207_16 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000207_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000207_3 & 2) != 0) {
            stage_v_134 = (pub_r000207_13 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000207_13 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000207_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000207_16 & 2) != 0) {
            stage_v_135 = (pub_r000207_4 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000207_4 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000207_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000207_0 & 1) != 0) {
        if ((sec_r000207_1 & 2) != 0) {
            stage_v_136 = (pub_r000207_4 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000207_4 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000207_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
