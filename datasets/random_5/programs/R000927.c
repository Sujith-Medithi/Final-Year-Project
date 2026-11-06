/*
 * Benchmark Program: R000927
 * Security Family: nested_implicit_flow
 * Generator Seed: 592713
 * High Inputs: 24 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000927_2713_0 {
    short gain_db;
    unsigned char prev_out;
    short cutoff;
    int buffer[3];
};

struct AudioFrame_R000927_2713_1 {
    int sample_rate;
    int peak;
    short envelope;
    int channels;
    int rms;
    int buffer[3];
};

struct Transaction_R000927_2713_2 {
    unsigned char account_id;
    unsigned char auth_code;
    unsigned char fee;
    int buffer[3];
};

union RegisterBank_R000927_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000927_2713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quantum_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_36 = local_arr[aux % 3];
    acc = (acc + anchor_36 * 2) & 127;
    int offset_55 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_55 > 48) {
        acc = (acc + offset_55 * 2 + 5) & 127;
        aux ^= (offset_55 & 15);
    } else {
        acc = (acc - offset_55 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_42 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_42 > 26) {
        acc = (acc + offset_42 * 2 + 5) & 127;
        aux ^= (offset_42 & 15);
    } else {
        acc = (acc - offset_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_71 = local_arr[aux % 3];
    acc = (acc + tally_71 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int index_reg_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_34) & 63;
    acc ^= aux;
    int metric_44 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_44 > 16) {
        acc = (acc + metric_44 * 2 + 5) & 127;
        aux ^= (metric_44 & 15);
    } else {
        acc = (acc - metric_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_52 = local_arr[aux % 3];
    acc = (acc + mask_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_3(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int checksum_37 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_37 > 22) {
        acc = (acc + checksum_37 * 2 + 5) & 127;
        aux ^= (checksum_37 & 15);
    } else {
        acc = (acc - checksum_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_64 = local_arr[aux % 3];
    acc = (acc + anchor_64 * 2) & 127;
    int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000927_2713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int factor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_21) & 63;
    acc ^= aux;
    int checksum_85 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_85 > 29) {
        acc = (acc + checksum_85 * 2 + 5) & 127;
        aux ^= (checksum_85 & 15);
    } else {
        acc = (acc - checksum_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_5(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tracker_53 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_53 > 22) {
        acc = (acc + tracker_53 * 2 + 5) & 127;
        aux ^= (tracker_53 & 15);
    } else {
        acc = (acc - tracker_53 + 11) & 127;
        aux += 3;
    }
    int tracker_60 = (aux + st.buffer[1]) & 3;
    switch (tracker_60) {
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

int fn_R000927_2713_6(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_42) & 63;
    acc ^= aux;
    int coefficient_27 = (aux + st.buffer[1]) & 3;
    switch (coefficient_27) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int scale_25 = (aux + st.buffer[1]) & 3;
    switch (scale_25) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_20 = local_arr[aux % 3];
    acc = (acc + quantum_20 * 2) & 127;
    int segment_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_92) & 63;
    acc ^= aux;
    int accumulator_35 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_35 > 32) {
        acc = (acc + accumulator_35 * 2 + 5) & 127;
        aux ^= (accumulator_35 & 15);
    } else {
        acc = (acc - accumulator_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int damping_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_81) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int index_reg_62 = local_arr[aux % 3];
    acc = (acc + index_reg_62 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_9(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int tracker_70 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_70 > 50) {
        acc = (acc + tracker_70 * 2 + 5) & 127;
        aux ^= (tracker_70 & 15);
    } else {
        acc = (acc - tracker_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_10(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int factor_90 = local_arr[aux % 3];
    acc = (acc + factor_90 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_11(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_22 = local_arr[aux % 3];
    acc = (acc + checksum_22 * 2) & 127;
    int stride_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000927_2713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_89 = local_arr[aux % 3];
    acc = (acc + parity_89 * 2) & 127;
    int delta_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_94) & 63;
    acc ^= aux;
    int margin_83 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_83 > 33) {
        acc = (acc + margin_83 * 2 + 5) & 127;
        aux ^= (margin_83 & 15);
    } else {
        acc = (acc - margin_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_13(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_92) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_41 = local_arr[aux % 3];
    acc = (acc + bound_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_78 = (aux + st.buffer[1]) & 3;
    switch (pivot_78) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_79) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_15(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int offset_45 = local_arr[aux % 3];
    acc = (acc + offset_45 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_30 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_30 > 25) {
        acc = (acc + anchor_30 * 2 + 5) & 127;
        aux ^= (anchor_30 & 15);
    } else {
        acc = (acc - anchor_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_16(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000927_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int cursor_50 = local_arr[aux % 3];
    acc = (acc + cursor_50 * 2) & 127;
    int segment_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000927_2713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int window_81 = (aux + st.buffer[1]) & 3;
    switch (window_81) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_88) & 63;
    acc ^= aux;
    int mask_22 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_22 > 40) {
        acc = (acc + mask_22 * 2 + 5) & 127;
        aux ^= (mask_22 & 15);
    } else {
        acc = (acc - mask_22 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_26 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_26 > 26) {
        acc = (acc + mask_26 * 2 + 5) & 127;
        aux ^= (mask_26 & 15);
    } else {
        acc = (acc - mask_26 + 11) & 127;
        aux += 3;
    }
    int coefficient_80 = (aux + st.buffer[1]) & 3;
    switch (coefficient_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_86 = (aux + st.buffer[1]) & 3;
    switch (coefficient_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000927_2713_20(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int cursor_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_50) & 63;
    acc ^= aux;
    int parity_48 = (aux + st.buffer[1]) & 3;
    switch (parity_48) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000927_2713_21(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000927_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int bound_22 = (aux + st.buffer[1]) & 3;
    switch (bound_22) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_82 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_82 > 20) {
        acc = (acc + index_reg_82 * 2 + 5) & 127;
        aux ^= (index_reg_82 & 15);
    } else {
        acc = (acc - index_reg_82 + 11) & 127;
        aux += 3;
    }
    int vector_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_51) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_93 = local_arr[aux % 3];
    acc = (acc + threshold_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_22(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_87 = (aux + st.buffer[1]) & 3;
    switch (residue_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_92 = local_arr[aux % 3];
    acc = (acc + cursor_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000927_2713_23(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000927_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int scale_91 = (aux + st.buffer[1]) & 3;
    switch (scale_91) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_97 = (st.buffer[0] * 3 + aux) & 63;
    if (window_97 > 23) {
        acc = (acc + window_97 * 2 + 5) & 127;
        aux ^= (window_97 & 15);
    } else {
        acc = (acc - window_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000927_0;
    int sec_r000927_1;
    int sec_r000927_2;
    int sec_r000927_3;
    int sec_r000927_4;
    int sec_r000927_5;
    int sec_r000927_6;
    int sec_r000927_7;
    int sec_r000927_8;
    int sec_r000927_9;
    int sec_r000927_10;
    int sec_r000927_11;
    int sec_r000927_12;
    int sec_r000927_13;
    int sec_r000927_14;
    int sec_r000927_15;
    int sec_r000927_16;
    int sec_r000927_17;
    int sec_r000927_18;
    int sec_r000927_19;
    int sec_r000927_20;
    int sec_r000927_21;
    int sec_r000927_22;
    int sec_r000927_23;
    int pub_r000927_0;
    int pub_r000927_1;
    int pub_r000927_2;
    int pub_r000927_3;
    int pub_r000927_4;
    int pub_r000927_5;
    int pub_r000927_6;
    int pub_r000927_7;
    int pub_r000927_8;
    int pub_r000927_9;
    int pub_r000927_10;
    int pub_r000927_11;
    int pub_r000927_12;
    int pub_r000927_13;
    int pub_r000927_14;
    int pub_r000927_15;
    int pub_r000927_16;
    int pub_r000927_17;
    int pub_r000927_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000927_0 >= -100 && pub_r000927_0 <= 100);
    __CPROVER_assume(pub_r000927_1 >= -100 && pub_r000927_1 <= 100);
    __CPROVER_assume(pub_r000927_2 >= -100 && pub_r000927_2 <= 100);
    __CPROVER_assume(pub_r000927_3 >= -100 && pub_r000927_3 <= 100);
    __CPROVER_assume(pub_r000927_4 >= -100 && pub_r000927_4 <= 100);
    __CPROVER_assume(pub_r000927_5 >= -100 && pub_r000927_5 <= 100);
    __CPROVER_assume(pub_r000927_6 >= -100 && pub_r000927_6 <= 100);
    __CPROVER_assume(pub_r000927_7 >= -100 && pub_r000927_7 <= 100);
    __CPROVER_assume(pub_r000927_8 >= -100 && pub_r000927_8 <= 100);
    __CPROVER_assume(pub_r000927_9 >= -100 && pub_r000927_9 <= 100);
    __CPROVER_assume(pub_r000927_10 >= -100 && pub_r000927_10 <= 100);
    __CPROVER_assume(pub_r000927_11 >= -100 && pub_r000927_11 <= 100);
    __CPROVER_assume(pub_r000927_12 >= -100 && pub_r000927_12 <= 100);
    __CPROVER_assume(pub_r000927_13 >= -100 && pub_r000927_13 <= 100);
    __CPROVER_assume(pub_r000927_14 >= -100 && pub_r000927_14 <= 100);
    __CPROVER_assume(pub_r000927_15 >= -100 && pub_r000927_15 <= 100);
    __CPROVER_assume(pub_r000927_16 >= -100 && pub_r000927_16 <= 100);
    __CPROVER_assume(pub_r000927_17 >= -100 && pub_r000927_17 <= 100);
    __CPROVER_assume(pub_r000927_18 >= -100 && pub_r000927_18 <= 100);
    __CPROVER_assume(sec_r000927_0 >= 0 && sec_r000927_0 <= 255);
    __CPROVER_assume(sec_r000927_1 >= 0 && sec_r000927_1 <= 255);
    __CPROVER_assume(sec_r000927_2 >= 0 && sec_r000927_2 <= 255);
    __CPROVER_assume(sec_r000927_3 >= 0 && sec_r000927_3 <= 255);
    __CPROVER_assume(sec_r000927_4 >= 0 && sec_r000927_4 <= 255);
    __CPROVER_assume(sec_r000927_5 >= 0 && sec_r000927_5 <= 255);
    __CPROVER_assume(sec_r000927_6 >= 0 && sec_r000927_6 <= 255);
    __CPROVER_assume(sec_r000927_7 >= 0 && sec_r000927_7 <= 255);
    __CPROVER_assume(sec_r000927_8 >= 0 && sec_r000927_8 <= 255);
    __CPROVER_assume(sec_r000927_9 >= 0 && sec_r000927_9 <= 255);
    __CPROVER_assume(sec_r000927_10 >= 0 && sec_r000927_10 <= 255);
    __CPROVER_assume(sec_r000927_11 >= 0 && sec_r000927_11 <= 255);
    __CPROVER_assume(sec_r000927_12 >= 0 && sec_r000927_12 <= 255);
    __CPROVER_assume(sec_r000927_13 >= 0 && sec_r000927_13 <= 255);
    __CPROVER_assume(sec_r000927_14 >= 0 && sec_r000927_14 <= 255);
    __CPROVER_assume(sec_r000927_15 >= 0 && sec_r000927_15 <= 255);
    __CPROVER_assume(sec_r000927_16 >= 0 && sec_r000927_16 <= 255);
    __CPROVER_assume(sec_r000927_17 >= 0 && sec_r000927_17 <= 255);
    __CPROVER_assume(sec_r000927_18 >= 0 && sec_r000927_18 <= 255);
    __CPROVER_assume(sec_r000927_19 >= 0 && sec_r000927_19 <= 255);
    __CPROVER_assume(sec_r000927_20 >= 0 && sec_r000927_20 <= 255);
    __CPROVER_assume(sec_r000927_21 >= 0 && sec_r000927_21 <= 255);
    __CPROVER_assume(sec_r000927_22 >= 0 && sec_r000927_22 <= 255);
    __CPROVER_assume(sec_r000927_23 >= 0 && sec_r000927_23 <= 255);

    struct FilterState_R000927_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000927_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000927_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000927_0 + 7) & 15;
    struct AudioFrame_R000927_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000927_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000927_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000927_0 + 9) & 15;
    struct Transaction_R000927_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000927_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000927_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000927_0 + 11) & 15;

    union RegisterBank_R000927_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
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
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 15) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 30) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
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
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 16) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 31) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

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
    if (stage_v_13 > 10) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 25) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 20) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 35) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 15) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 30) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 24) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 39) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 29) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 44) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 32) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 47) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000927_22 & 1) != 0) {
        if ((sec_r000927_21 & 2) != 0) {
            stage_v_57 = (pub_r000927_18 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000927_18 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000927_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000927_17 & 2) != 0) {
            stage_v_58 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000927_10 & 1) != 0) {
        if ((sec_r000927_7 & 2) != 0) {
            stage_v_59 = (pub_r000927_5 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000927_5 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000927_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_60 = (pub_r000927_17 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000927_17 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000927_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000927_12 & 2) != 0) {
            stage_v_61 = (pub_r000927_1 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000927_1 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000927_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000927_8 & 2) != 0) {
            stage_v_62 = (pub_r000927_6 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000927_6 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000927_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000927_18 & 1) != 0) {
        if ((sec_r000927_20 & 2) != 0) {
            stage_v_63 = (pub_r000927_15 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000927_15 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000927_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000927_12 & 2) != 0) {
            stage_v_64 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_65 = (pub_r000927_8 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000927_8 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000927_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000927_3 & 2) != 0) {
            stage_v_66 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000927_0 & 1) != 0) {
        if ((sec_r000927_3 & 2) != 0) {
            stage_v_67 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000927_21 & 2) != 0) {
            stage_v_68 = (pub_r000927_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000927_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000927_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000927_13 & 2) != 0) {
            stage_v_69 = (pub_r000927_7 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000927_7 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000927_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000927_20 & 1) != 0) {
        if ((sec_r000927_23 & 2) != 0) {
            stage_v_70 = (pub_r000927_18 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000927_18 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000927_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000927_20 & 2) != 0) {
            stage_v_71 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_72 = (pub_r000927_2 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000927_2 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000927_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000927_18 & 1) != 0) {
        if ((sec_r000927_19 & 2) != 0) {
            stage_v_73 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000927_17 & 2) != 0) {
            stage_v_74 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000927_21 & 2) != 0) {
            stage_v_75 = (pub_r000927_15 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000927_15 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000927_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000927_10 & 2) != 0) {
            stage_v_76 = (pub_r000927_13 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000927_13 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000927_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((sec_r000927_11 & 1) != 0) {
        if ((sec_r000927_21 & 2) != 0) {
            stage_v_77 = (pub_r000927_4 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000927_4 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000927_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000927_8 & 2) != 0) {
            stage_v_78 = (pub_r000927_4 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000927_4 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000927_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000927_15 & 2) != 0) {
            stage_v_79 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000927_15 & 2) != 0) {
            stage_v_80 = (pub_r000927_11 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000927_11 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000927_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000927_23 & 2) != 0) {
            stage_v_81 = (pub_r000927_18 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000927_18 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000927_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000927_18 & 1) != 0) {
        if ((sec_r000927_7 & 2) != 0) {
            stage_v_82 = (pub_r000927_17 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000927_17 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000927_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000927_4 & 2) != 0) {
            stage_v_83 = (pub_r000927_18 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000927_18 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000927_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000927_17 & 2) != 0) {
            stage_v_84 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000927_23 & 1) != 0) {
        if ((sec_r000927_13 & 2) != 0) {
            stage_v_85 = (pub_r000927_17 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000927_17 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000927_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000927_2 & 2) != 0) {
            stage_v_86 = (pub_r000927_2 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000927_2 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000927_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000927_4 & 2) != 0) {
            stage_v_87 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000927_6 & 1) != 0) {
        if ((sec_r000927_8 & 2) != 0) {
            stage_v_88 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000927_18 & 2) != 0) {
            stage_v_89 = (pub_r000927_6 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000927_6 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000927_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000927_14 & 2) != 0) {
            stage_v_90 = (pub_r000927_5 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000927_5 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000927_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000927_12 & 2) != 0) {
            stage_v_91 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000927_16 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_92 = (pub_r000927_7 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000927_7 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000927_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000927_17 & 2) != 0) {
            stage_v_93 = (pub_r000927_1 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000927_1 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000927_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000927_8 & 1) != 0) {
        if ((sec_r000927_0 & 2) != 0) {
            stage_v_94 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000927_4 & 2) != 0) {
            stage_v_95 = (pub_r000927_6 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000927_6 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000927_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_96 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000927_6 & 1) != 0) {
        if ((sec_r000927_6 & 2) != 0) {
            stage_v_97 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000927_11 & 1) != 0) {
        if ((sec_r000927_13 & 2) != 0) {
            stage_v_98 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000927_23 & 2) != 0) {
            stage_v_99 = (pub_r000927_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000927_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000927_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000927_12 & 2) != 0) {
            stage_v_100 = (pub_r000927_17 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000927_17 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000927_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000927_20 & 1) != 0) {
        if ((sec_r000927_12 & 2) != 0) {
            stage_v_101 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000927_9 & 2) != 0) {
            stage_v_102 = (pub_r000927_11 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000927_11 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000927_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000927_14 & 1) != 0) {
        if ((sec_r000927_8 & 2) != 0) {
            stage_v_103 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000927_4 & 2) != 0) {
            stage_v_104 = (pub_r000927_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000927_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000927_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_105 = (pub_r000927_6 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000927_6 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000927_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000927_7 & 1) != 0) {
        if ((sec_r000927_2 & 2) != 0) {
            stage_v_106 = (pub_r000927_9 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000927_9 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000927_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000927_5 & 2) != 0) {
            stage_v_107 = (pub_r000927_9 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000927_9 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000927_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000927_16 & 2) != 0) {
            stage_v_108 = (pub_r000927_8 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000927_8 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000927_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000927_0 & 2) != 0) {
            stage_v_109 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000927_18 & 2) != 0) {
            stage_v_110 = (pub_r000927_6 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000927_6 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000927_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000927_11 & 1) != 0) {
        if ((sec_r000927_9 & 2) != 0) {
            stage_v_111 = (pub_r000927_12 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000927_12 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000927_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000927_5 & 2) != 0) {
            stage_v_112 = (pub_r000927_15 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000927_15 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000927_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000927_23 & 2) != 0) {
            stage_v_113 = (pub_r000927_15 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000927_15 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000927_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000927_14 & 1) != 0) {
        if ((sec_r000927_12 & 2) != 0) {
            stage_v_114 = (pub_r000927_12 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000927_12 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000927_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000927_6 & 1) != 0) {
        if ((sec_r000927_23 & 2) != 0) {
            stage_v_115 = (pub_r000927_8 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000927_8 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000927_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000927_18 & 1) != 0) {
        if ((sec_r000927_9 & 2) != 0) {
            stage_v_116 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000927_10 & 2) != 0) {
            stage_v_117 = (pub_r000927_11 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000927_11 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000927_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000927_18 & 2) != 0) {
            stage_v_118 = (pub_r000927_8 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000927_8 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000927_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000927_5 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_119 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000927_8 & 2) != 0) {
            stage_v_120 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000927_8 & 1) != 0) {
        if ((sec_r000927_19 & 2) != 0) {
            stage_v_121 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000927_11 & 2) != 0) {
            stage_v_122 = (pub_r000927_4 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000927_4 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000927_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000927_23 & 1) != 0) {
        if ((sec_r000927_20 & 2) != 0) {
            stage_v_123 = (pub_r000927_13 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000927_13 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000927_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000927_15 & 2) != 0) {
            stage_v_124 = (pub_r000927_9 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000927_9 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000927_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000927_3 & 2) != 0) {
            stage_v_125 = (pub_r000927_7 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000927_7 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000927_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000927_5 & 2) != 0) {
            stage_v_126 = (pub_r000927_1 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000927_1 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000927_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000927_11 & 2) != 0) {
            stage_v_127 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000927_16 & 2) != 0) {
            stage_v_128 = (pub_r000927_7 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000927_7 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000927_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000927_6 & 1) != 0) {
        if ((sec_r000927_13 & 2) != 0) {
            stage_v_129 = (pub_r000927_8 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000927_8 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000927_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000927_8 & 2) != 0) {
            stage_v_130 = (pub_r000927_5 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000927_5 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000927_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000927_19 & 1) != 0) {
        if ((sec_r000927_16 & 2) != 0) {
            stage_v_131 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000927_21 & 2) != 0) {
            stage_v_132 = (pub_r000927_2 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000927_2 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000927_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000927_22 & 1) != 0) {
        if ((sec_r000927_23 & 2) != 0) {
            stage_v_133 = (pub_r000927_8 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000927_8 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000927_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000927_18 & 2) != 0) {
            stage_v_134 = (pub_r000927_10 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000927_10 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000927_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000927_15 & 1) != 0) {
        if ((sec_r000927_5 & 2) != 0) {
            stage_v_135 = (pub_r000927_9 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000927_9 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000927_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000927_13 & 2) != 0) {
            stage_v_136 = (pub_r000927_17 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000927_17 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000927_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000927_16 & 2) != 0) {
            stage_v_137 = (pub_r000927_7 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000927_7 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000927_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r000927_15 & 2) != 0) {
            stage_v_138 = (pub_r000927_16 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000927_16 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000927_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_139 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000927_3 & 2) != 0) {
            stage_v_140 = (pub_r000927_12 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000927_12 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000927_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000927_0 & 2) != 0) {
            stage_v_141 = (pub_r000927_14 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000927_14 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000927_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r000927_0 & 2) != 0) {
            stage_v_142 = (pub_r000927_0 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000927_0 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000927_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000927_16 & 1) != 0) {
        if ((sec_r000927_11 & 2) != 0) {
            stage_v_143 = (pub_r000927_18 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000927_18 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000927_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000927_3 & 1) != 0) {
        if ((sec_r000927_1 & 2) != 0) {
            stage_v_144 = (pub_r000927_3 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000927_3 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000927_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
