/*
 * Benchmark Program: R000892
 * Family: secret_dependent_array
 * Generator Seed: 539217
 * High Inputs: 16 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000892_9217_0 {
    int sample_rate;
    unsigned char gain;
    unsigned char rms;
    int envelope;
    unsigned char peak;
    int buffer[3];
};

struct Transaction_R000892_9217_1 {
    int balance;
    unsigned char account_id;
    int status;
    unsigned char auth_code;
    unsigned char rate;
    int buffer[3];
};

union ColorPixel_R000892_9217_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000892_9217_0(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_47 = (aux + st.buffer[1]) & 3;
    switch (damping_47) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_16 = 0;
    for (int k = 0; k < 2; k++) {
        window_16 = (window_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000892_9217_1(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_45 = (aux + st.buffer[1]) & 3;
    switch (accumulator_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_80 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_80 > 16) {
        acc = (acc + metric_80 * 2 + 5) & 127;
        aux ^= (metric_80 & 15);
    } else {
        acc = (acc - metric_80 + 11) & 127;
        aux += 3;
    }
    int bound_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000892_9217_2(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int margin_84 = local_arr[aux % 3];
    acc = (acc + margin_84 * 2) & 127;
    int coefficient_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_38) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_3(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int accumulator_12 = (aux + st.buffer[1]) & 3;
    switch (accumulator_12) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_94 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_94 = (pivot_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_94) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_86 = local_arr[aux % 3];
    acc = (acc + margin_86 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_4(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_26 = local_arr[aux % 3];
    acc = (acc + segment_26 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_5(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int anchor_40 = local_arr[aux % 3];
    acc = (acc + anchor_40 * 2) & 127;
    int cursor_12 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_12 = (cursor_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_12) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_87 = (aux + st.buffer[1]) & 3;
    switch (factor_87) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_14 = 0;
    for (int k = 0; k < 3; k++) {
        damping_14 = (damping_14 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_14) & 127;
    }
    int stride_31 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_31 > 15) {
        acc = (acc + stride_31 * 2 + 5) & 127;
        aux ^= (stride_31 & 15);
    } else {
        acc = (acc - stride_31 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000892_9217_7(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_88 = (aux + st.buffer[1]) & 3;
    switch (tracker_88) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_29 = 0;
    for (int k = 0; k < 2; k++) {
        window_29 = (window_29 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_29) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int window_34 = local_arr[aux % 3];
    acc = (acc + window_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_8(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_97 = (aux + st.buffer[1]) & 3;
    switch (anchor_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_17 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_17 = (threshold_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_17) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000892_9217_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int margin_42 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_42 > 18) {
        acc = (acc + margin_42 * 2 + 5) & 127;
        aux ^= (margin_42 & 15);
    } else {
        acc = (acc - margin_42 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_55 = local_arr[aux % 3];
    acc = (acc + damping_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int metric_12 = (aux + st.buffer[1]) & 3;
    switch (metric_12) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_50 = local_arr[aux % 3];
    acc = (acc + quantum_50 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_11(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_71 = (aux + st.buffer[1]) & 3;
    switch (tally_71) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_57) & 63;
    acc ^= aux;
    int cursor_59 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_59 > 28) {
        acc = (acc + cursor_59 * 2 + 5) & 127;
        aux ^= (cursor_59 & 15);
    } else {
        acc = (acc - cursor_59 + 11) & 127;
        aux += 3;
    }
    int residue_16 = 0;
    for (int k = 0; k < 2; k++) {
        residue_16 = (residue_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000892_9217_13(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int parity_29 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_29 > 39) {
        acc = (acc + parity_29 * 2 + 5) & 127;
        aux ^= (parity_29 & 15);
    } else {
        acc = (acc - parity_29 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_45 = (aux + st.buffer[1]) & 3;
    switch (residue_45) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000892_9217_14(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int damping_58 = (aux + st.buffer[1]) & 3;
    switch (damping_58) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_32 = local_arr[aux % 3];
    acc = (acc + residue_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int quantum_56 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_56 > 41) {
        acc = (acc + quantum_56 * 2 + 5) & 127;
        aux ^= (quantum_56 & 15);
    } else {
        acc = (acc - quantum_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int mask_72 = local_arr[aux % 3];
    acc = (acc + mask_72 * 2) & 127;
    int sample_47 = 0;
    for (int k = 0; k < 3; k++) {
        sample_47 = (sample_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_47) & 127;
    }
    int phase_65 = (aux + st.buffer[1]) & 3;
    switch (phase_65) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_17(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int bound_67 = (aux + st.buffer[1]) & 3;
    switch (bound_67) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_51) & 63;
    acc ^= aux;
    int bound_93 = 0;
    for (int k = 0; k < 3; k++) {
        bound_93 = (bound_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000892_9217_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int pivot_33 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_33 > 45) {
        acc = (acc + pivot_33 * 2 + 5) & 127;
        aux ^= (pivot_33 & 15);
    } else {
        acc = (acc - pivot_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_81 = local_arr[aux % 3];
    acc = (acc + sample_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int coefficient_84 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_84 > 20) {
        acc = (acc + coefficient_84 * 2 + 5) & 127;
        aux ^= (coefficient_84 & 15);
    } else {
        acc = (acc - coefficient_84 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_62 = local_arr[aux % 3];
    acc = (acc + factor_62 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000892_9217_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quotient_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_32) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_82 = (aux + st.buffer[1]) & 3;
    switch (residue_82) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_30 = local_arr[aux % 3];
    acc = (acc + metric_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000892_9217_21(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000892_9217_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int delta_69 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_69 > 12) {
        acc = (acc + delta_69 * 2 + 5) & 127;
        aux ^= (delta_69 & 15);
    } else {
        acc = (acc - delta_69 + 11) & 127;
        aux += 3;
    }
    int weight_91 = 0;
    for (int k = 0; k < 2; k++) {
        weight_91 = (weight_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_91) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000892_0;
    int sec_r000892_1;
    int sec_r000892_2;
    int sec_r000892_3;
    int sec_r000892_4;
    int sec_r000892_5;
    int sec_r000892_6;
    int sec_r000892_7;
    int sec_r000892_8;
    int sec_r000892_9;
    int sec_r000892_10;
    int sec_r000892_11;
    int sec_r000892_12;
    int sec_r000892_13;
    int sec_r000892_14;
    int sec_r000892_15;
    int pub_r000892_0;
    int pub_r000892_1;
    int pub_r000892_2;
    int pub_r000892_3;
    int pub_r000892_4;
    int pub_r000892_5;
    int pub_r000892_6;
    int pub_r000892_7;
    int pub_r000892_8;
    int pub_r000892_9;
    int pub_r000892_10;
    int pub_r000892_11;
    int pub_r000892_12;
    int pub_r000892_13;
    int pub_r000892_14;
    int pub_r000892_15;
    int pub_r000892_16;
    int pub_r000892_17;
    int pub_r000892_18;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000892_0 >= -100 && pub_r000892_0 <= 100);
    __CPROVER_assume(pub_r000892_1 >= -100 && pub_r000892_1 <= 100);
    __CPROVER_assume(pub_r000892_2 >= -100 && pub_r000892_2 <= 100);
    __CPROVER_assume(pub_r000892_3 >= -100 && pub_r000892_3 <= 100);
    __CPROVER_assume(pub_r000892_4 >= -100 && pub_r000892_4 <= 100);
    __CPROVER_assume(pub_r000892_5 >= -100 && pub_r000892_5 <= 100);
    __CPROVER_assume(pub_r000892_6 >= -100 && pub_r000892_6 <= 100);
    __CPROVER_assume(pub_r000892_7 >= -100 && pub_r000892_7 <= 100);
    __CPROVER_assume(pub_r000892_8 >= -100 && pub_r000892_8 <= 100);
    __CPROVER_assume(pub_r000892_9 >= -100 && pub_r000892_9 <= 100);
    __CPROVER_assume(pub_r000892_10 >= -100 && pub_r000892_10 <= 100);
    __CPROVER_assume(pub_r000892_11 >= -100 && pub_r000892_11 <= 100);
    __CPROVER_assume(pub_r000892_12 >= -100 && pub_r000892_12 <= 100);
    __CPROVER_assume(pub_r000892_13 >= -100 && pub_r000892_13 <= 100);
    __CPROVER_assume(pub_r000892_14 >= -100 && pub_r000892_14 <= 100);
    __CPROVER_assume(pub_r000892_15 >= -100 && pub_r000892_15 <= 100);
    __CPROVER_assume(pub_r000892_16 >= -100 && pub_r000892_16 <= 100);
    __CPROVER_assume(pub_r000892_17 >= -100 && pub_r000892_17 <= 100);
    __CPROVER_assume(pub_r000892_18 >= -100 && pub_r000892_18 <= 100);
    __CPROVER_assume(sec_r000892_0 >= 0 && sec_r000892_0 <= 255);
    __CPROVER_assume(sec_r000892_1 >= 0 && sec_r000892_1 <= 255);
    __CPROVER_assume(sec_r000892_2 >= 0 && sec_r000892_2 <= 255);
    __CPROVER_assume(sec_r000892_3 >= 0 && sec_r000892_3 <= 255);
    __CPROVER_assume(sec_r000892_4 >= 0 && sec_r000892_4 <= 255);
    __CPROVER_assume(sec_r000892_5 >= 0 && sec_r000892_5 <= 255);
    __CPROVER_assume(sec_r000892_6 >= 0 && sec_r000892_6 <= 255);
    __CPROVER_assume(sec_r000892_7 >= 0 && sec_r000892_7 <= 255);
    __CPROVER_assume(sec_r000892_8 >= 0 && sec_r000892_8 <= 255);
    __CPROVER_assume(sec_r000892_9 >= 0 && sec_r000892_9 <= 255);
    __CPROVER_assume(sec_r000892_10 >= 0 && sec_r000892_10 <= 255);
    __CPROVER_assume(sec_r000892_11 >= 0 && sec_r000892_11 <= 255);
    __CPROVER_assume(sec_r000892_12 >= 0 && sec_r000892_12 <= 255);
    __CPROVER_assume(sec_r000892_13 >= 0 && sec_r000892_13 <= 255);
    __CPROVER_assume(sec_r000892_14 >= 0 && sec_r000892_14 <= 255);
    __CPROVER_assume(sec_r000892_15 >= 0 && sec_r000892_15 <= 255);

    struct AudioFrame_R000892_9217_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000892_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000892_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000892_0 + 7) & 15;
    struct Transaction_R000892_9217_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000892_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000892_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000892_0 + 9) & 15;

    union ColorPixel_R000892_9217_0 u_var;
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
    int stage_v_1 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 34) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 49) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

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
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 35) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 50) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 32) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 47) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 16) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 31) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 31) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 46) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[1] * 2 + 73) & 63;
    if (stage_v_22 > 36) {
        out_sink = (out_sink + stage_v_22 - 5) & 255;
        if (stage_v_22 > 51) {
            chk_sum ^= (stage_v_22 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_22 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

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
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 12) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 27) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 34) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 49) {
            chk_sum ^= (stage_v_34 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_34 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 35 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 15) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 30) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_0.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 27) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 42) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 15) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 30) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

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

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 17) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 32) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[1] * 2 + 145) & 63;
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
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 27) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 42) {
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
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[1] * 2 + 172) & 63;
    if (stage_v_55 > 16) {
        out_sink = (out_sink + stage_v_55 - 5) & 255;
        if (stage_v_55 > 31) {
            chk_sum ^= (stage_v_55 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_55 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_57 = (stage_v_57 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 32) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 47) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 30) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 45) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 35) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (out_sink > 100) ? (chk_sum & 31) : (67 & 31);
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= (stage_v_62 << 1) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 29) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 44) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 26) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 41) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 31) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 46) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 21) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 36) {
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
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 20) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 35) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[1] * 2 + 253) & 63;
    if (stage_v_82 > 22) {
        out_sink = (out_sink + stage_v_82 - 5) & 255;
        if (stage_v_82 > 37) {
            chk_sum ^= (stage_v_82 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_82 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_89 = (stage_v_89 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (out_sink > 100) ? (chk_sum & 31) : (98 & 31);
    out_sink = (out_sink + stage_v_93) & 255;
    chk_sum ^= (stage_v_93 << 1) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 33) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 48) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_97 = (stage_v_97 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_0.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 24) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 39) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 101 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 32) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 47) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_0.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 19) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 34) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 33) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 48) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_109 = (stage_v_109 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = table[3];
    table[3] = (table[0] + 223) & 63;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_0.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 34) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 49) {
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
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_115 = (stage_v_115 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] * 2 + 358) & 63;
    if (stage_v_117 > 32) {
        out_sink = (out_sink + stage_v_117 - 5) & 255;
        if (stage_v_117 > 47) {
            chk_sum ^= (stage_v_117 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_117 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_0.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 28) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 43) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_1.buffer[0] ^ 122) & 3;
    switch (stage_v_119) {
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

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 34) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 49) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (st_var_0.buffer[1] * 2 + 379) & 63;
    if (stage_v_124 > 39) {
        out_sink = (out_sink + stage_v_124 - 5) & 255;
        if (stage_v_124 > 54) {
            chk_sum ^= (stage_v_124 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_124 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_127 = (stage_v_127 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[2] * 2 + 391) & 63;
    if (stage_v_128 > 10) {
        out_sink = (out_sink + stage_v_128 - 5) & 255;
        if (stage_v_128 > 25) {
            chk_sum ^= (stage_v_128 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_128 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_129 = (stage_v_129 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = table[3];
    table[3] = (table[0] + 263) & 63;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] * 2 + 403) & 63;
    if (stage_v_132 > 17) {
        out_sink = (out_sink + stage_v_132 - 5) & 255;
        if (stage_v_132 > 32) {
            chk_sum ^= (stage_v_132 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_132 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_1.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 20) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 35) {
            chk_sum ^= (stage_v_140 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_140 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = table[1];
    table[1] = (table[2] + 283) & 63;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = table[2];
    table[2] = (table[3] + 285) & 63;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] ^ 147) & 3;
    switch (stage_v_144) {
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

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2];
    table[2] = (table[3] + 293) & 63;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 148) & 15;
    int stage_v_147 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= stage_v_147;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_149 = (stage_v_149 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (out_sink > 100) ? (chk_sum & 31) : (155 & 31);
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= (stage_v_150 << 1) & 127;

    /* Execution Pipeline Stage 151 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 154) & 15;
    int stage_v_153 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= stage_v_153;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_1.buffer[0] * 2 + 484) & 63;
    if (stage_v_159 > 38) {
        out_sink = (out_sink + stage_v_159 - 5) & 255;
        if (stage_v_159 > 53) {
            chk_sum ^= (stage_v_159 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_159 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 34) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 49) {
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
    int stage_v_167 = (st_var_1.buffer[0] ^ 170) & 3;
    switch (stage_v_167) {
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

    /* Execution Pipeline Stage 168 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 169) & 15;
    int stage_v_168 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    chk_sum ^= stage_v_168;

    /* Execution Pipeline Stage 169 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 170) & 15;
    int stage_v_169 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= stage_v_169;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_170 = (stage_v_170 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_170) & 127;
    }
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_171 = (stage_v_171 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_171) & 127;
    }
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_173 = (stage_v_173 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_176 = (stage_v_176 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 22) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 37) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_179 = (stage_v_179 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_179) & 127;
    }
    out_sink = (out_sink + stage_v_179) & 255;

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 25, 21, 38, 31 };
    int s_idx = (sec_r000892_7 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
