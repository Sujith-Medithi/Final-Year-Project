/*
 * Benchmark Program: R000588
 * Security Family: secret_dependent_loops
 * Generator Seed: 558813
 * High Inputs: 16 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000588_8813_0 {
    unsigned char balance;
    int auth_code;
    int status;
    int rate;
    unsigned char account_id;
    int buffer[3];
};

struct AudioFrame_R000588_8813_1 {
    short channels;
    int peak;
    int sample_rate;
    int envelope;
    short gain;
    short rms;
    int buffer[3];
};

union RegisterBank_R000588_8813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000588_8813_0(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int phase_88 = (aux + st.buffer[1]) & 3;
    switch (phase_88) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_96 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_96 > 24) {
        acc = (acc + phase_96 * 2 + 5) & 127;
        aux ^= (phase_96 & 15);
    } else {
        acc = (acc - phase_96 + 11) & 127;
        aux += 3;
    }
    int segment_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000588_8813_1(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_34 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_34 > 23) {
        acc = (acc + residue_34 * 2 + 5) & 127;
        aux ^= (residue_34 & 15);
    } else {
        acc = (acc - residue_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_87 = local_arr[aux % 3];
    acc = (acc + segment_87 * 2) & 127;
    int scale_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000588_8813_2(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int quotient_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_74) & 63;
    acc ^= aux;
    int factor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_33 > 38) {
        acc = (acc + factor_33 * 2 + 5) & 127;
        aux ^= (factor_33 & 15);
    } else {
        acc = (acc - factor_33 + 11) & 127;
        aux += 3;
    }
    int pivot_83 = (aux + st.buffer[1]) & 3;
    switch (pivot_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_3(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int offset_88 = local_arr[aux % 3];
    acc = (acc + offset_88 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_37 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_37 > 45) {
        acc = (acc + threshold_37 * 2 + 5) & 127;
        aux ^= (threshold_37 & 15);
    } else {
        acc = (acc - threshold_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_4(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_51 = (aux + st.buffer[1]) & 3;
    switch (accumulator_51) {
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

int fn_R000588_8813_5(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_11) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_58 = local_arr[aux % 3];
    acc = (acc + stride_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_27 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_27 > 44) {
        acc = (acc + damping_27 * 2 + 5) & 127;
        aux ^= (damping_27 & 15);
    } else {
        acc = (acc - damping_27 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_6(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_50 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_50 > 28) {
        acc = (acc + threshold_50 * 2 + 5) & 127;
        aux ^= (threshold_50 & 15);
    } else {
        acc = (acc - threshold_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_96 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_96 > 50) {
        acc = (acc + mask_96 * 2 + 5) & 127;
        aux ^= (mask_96 & 15);
    } else {
        acc = (acc - mask_96 + 11) & 127;
        aux += 3;
    }
    int coefficient_53 = (aux + st.buffer[1]) & 3;
    switch (coefficient_53) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_8(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int cursor_92 = local_arr[aux % 3];
    acc = (acc + cursor_92 * 2) & 127;
    int pivot_39 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_39 > 30) {
        acc = (acc + pivot_39 * 2 + 5) & 127;
        aux ^= (pivot_39 & 15);
    } else {
        acc = (acc - pivot_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_9(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_34 = (aux + st.buffer[1]) & 3;
    switch (parity_34) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_21 = local_arr[aux % 3];
    acc = (acc + index_reg_21 * 2) & 127;
    int checksum_46 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_46 > 40) {
        acc = (acc + checksum_46 * 2 + 5) & 127;
        aux ^= (checksum_46 & 15);
    } else {
        acc = (acc - checksum_46 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_10(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int window_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_25) & 63;
    acc ^= aux;
    int residue_20 = (aux + st.buffer[1]) & 3;
    switch (residue_20) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_73 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_73 > 23) {
        acc = (acc + bound_73 * 2 + 5) & 127;
        aux ^= (bound_73 & 15);
    } else {
        acc = (acc - bound_73 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_30 = local_arr[aux % 3];
    acc = (acc + tally_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_50 = (aux + st.buffer[1]) & 3;
    switch (quotient_50) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_13 = local_arr[aux % 3];
    acc = (acc + window_13 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int quantum_48 = local_arr[aux % 3];
    acc = (acc + quantum_48 * 2) & 127;
    int delta_33 = (aux + st.buffer[1]) & 3;
    switch (delta_33) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_13(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_54 = local_arr[aux % 3];
    acc = (acc + weight_54 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int mask_50 = local_arr[aux % 3];
    acc = (acc + mask_50 * 2) & 127;
    int scale_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_11) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_15(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int parity_16 = (aux + st.buffer[1]) & 3;
    switch (parity_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_35 = local_arr[aux % 3];
    acc = (acc + offset_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_16(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_35 = local_arr[aux % 3];
    acc = (acc + bound_35 * 2) & 127;
    int sample_62 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_62 > 42) {
        acc = (acc + sample_62 * 2 + 5) & 127;
        aux ^= (sample_62 & 15);
    } else {
        acc = (acc - sample_62 + 11) & 127;
        aux += 3;
    }
    int quotient_41 = (aux + st.buffer[1]) & 3;
    switch (quotient_41) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_83 = local_arr[aux % 3];
    acc = (acc + tracker_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000588_8813_18(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000588_8813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int sample_64 = (aux + st.buffer[1]) & 3;
    switch (sample_64) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_12 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_12 > 13) {
        acc = (acc + damping_12 * 2 + 5) & 127;
        aux ^= (damping_12 & 15);
    } else {
        acc = (acc - damping_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_19(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_48 = (aux + st.buffer[1]) & 3;
    switch (window_48) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_79 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_79 > 32) {
        acc = (acc + delta_79 * 2 + 5) & 127;
        aux ^= (delta_79 & 15);
    } else {
        acc = (acc - delta_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000588_8813_20(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000588_8813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tally_64 = (aux + st.buffer[1]) & 3;
    switch (tally_64) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_64 = local_arr[aux % 3];
    acc = (acc + offset_64 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000588_0;
    int sec_r000588_1;
    int sec_r000588_2;
    int sec_r000588_3;
    int sec_r000588_4;
    int sec_r000588_5;
    int sec_r000588_6;
    int sec_r000588_7;
    int sec_r000588_8;
    int sec_r000588_9;
    int sec_r000588_10;
    int sec_r000588_11;
    int sec_r000588_12;
    int sec_r000588_13;
    int sec_r000588_14;
    int sec_r000588_15;
    int pub_r000588_0;
    int pub_r000588_1;
    int pub_r000588_2;
    int pub_r000588_3;
    int pub_r000588_4;
    int pub_r000588_5;
    int pub_r000588_6;
    int pub_r000588_7;
    int pub_r000588_8;
    int pub_r000588_9;
    int pub_r000588_10;
    int pub_r000588_11;
    int pub_r000588_12;
    int pub_r000588_13;
    int pub_r000588_14;
    int pub_r000588_15;
    int pub_r000588_16;
    int pub_r000588_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000588_0 >= -100 && pub_r000588_0 <= 100);
    __CPROVER_assume(pub_r000588_1 >= -100 && pub_r000588_1 <= 100);
    __CPROVER_assume(pub_r000588_2 >= -100 && pub_r000588_2 <= 100);
    __CPROVER_assume(pub_r000588_3 >= -100 && pub_r000588_3 <= 100);
    __CPROVER_assume(pub_r000588_4 >= -100 && pub_r000588_4 <= 100);
    __CPROVER_assume(pub_r000588_5 >= -100 && pub_r000588_5 <= 100);
    __CPROVER_assume(pub_r000588_6 >= -100 && pub_r000588_6 <= 100);
    __CPROVER_assume(pub_r000588_7 >= -100 && pub_r000588_7 <= 100);
    __CPROVER_assume(pub_r000588_8 >= -100 && pub_r000588_8 <= 100);
    __CPROVER_assume(pub_r000588_9 >= -100 && pub_r000588_9 <= 100);
    __CPROVER_assume(pub_r000588_10 >= -100 && pub_r000588_10 <= 100);
    __CPROVER_assume(pub_r000588_11 >= -100 && pub_r000588_11 <= 100);
    __CPROVER_assume(pub_r000588_12 >= -100 && pub_r000588_12 <= 100);
    __CPROVER_assume(pub_r000588_13 >= -100 && pub_r000588_13 <= 100);
    __CPROVER_assume(pub_r000588_14 >= -100 && pub_r000588_14 <= 100);
    __CPROVER_assume(pub_r000588_15 >= -100 && pub_r000588_15 <= 100);
    __CPROVER_assume(pub_r000588_16 >= -100 && pub_r000588_16 <= 100);
    __CPROVER_assume(pub_r000588_17 >= -100 && pub_r000588_17 <= 100);
    __CPROVER_assume(sec_r000588_0 >= 0 && sec_r000588_0 <= 255);
    __CPROVER_assume(sec_r000588_1 >= 0 && sec_r000588_1 <= 255);
    __CPROVER_assume(sec_r000588_2 >= 0 && sec_r000588_2 <= 255);
    __CPROVER_assume(sec_r000588_3 >= 0 && sec_r000588_3 <= 255);
    __CPROVER_assume(sec_r000588_4 >= 0 && sec_r000588_4 <= 255);
    __CPROVER_assume(sec_r000588_5 >= 0 && sec_r000588_5 <= 255);
    __CPROVER_assume(sec_r000588_6 >= 0 && sec_r000588_6 <= 255);
    __CPROVER_assume(sec_r000588_7 >= 0 && sec_r000588_7 <= 255);
    __CPROVER_assume(sec_r000588_8 >= 0 && sec_r000588_8 <= 255);
    __CPROVER_assume(sec_r000588_9 >= 0 && sec_r000588_9 <= 255);
    __CPROVER_assume(sec_r000588_10 >= 0 && sec_r000588_10 <= 255);
    __CPROVER_assume(sec_r000588_11 >= 0 && sec_r000588_11 <= 255);
    __CPROVER_assume(sec_r000588_12 >= 0 && sec_r000588_12 <= 255);
    __CPROVER_assume(sec_r000588_13 >= 0 && sec_r000588_13 <= 255);
    __CPROVER_assume(sec_r000588_14 >= 0 && sec_r000588_14 <= 255);
    __CPROVER_assume(sec_r000588_15 >= 0 && sec_r000588_15 <= 255);

    struct Transaction_R000588_8813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000588_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000588_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000588_0 + 7) & 15;
    struct AudioFrame_R000588_8813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000588_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000588_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000588_0 + 9) & 15;

    union RegisterBank_R000588_8813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[0] ^ 5) & 3;
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
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 22) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 37) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

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
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 29) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 44) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 24) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 39) {
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
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[1] * 2 + 109) & 63;
    if (stage_v_34 > 21) {
        out_sink = (out_sink + stage_v_34 - 5) & 255;
        if (stage_v_34 > 36) {
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
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 21) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 36) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 21) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 36) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 30) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 45) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = table[1];
    table[1] = (table[2] + 99) & 63;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_57 = (st_var_1.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_58 = (stage_v_58 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 29) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 44) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 22) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 37) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_62 = (stage_v_62 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_1.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 17) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 32) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (out_sink > 100) ? (chk_sum & 31) : (72 & 31);
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= (stage_v_67 << 1) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 14) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 29) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 26) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 41) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_3 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000588_12) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000588_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000588_7) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000588_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000588_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000588_10) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000588_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000588_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_14 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000588_16) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000588_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000588_5) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000588_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000588_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000588_4) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000588_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_0 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000588_16) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000588_13) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000588_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000588_13) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000588_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000588_10) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_15 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000588_4) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000588_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_1 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000588_14) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_14 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000588_9) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000588_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000588_3) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000588_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_4 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000588_3) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000588_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000588_11) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000588_14) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_80 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000588_10) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000588_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_84 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000588_16) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000588_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000588_0) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000588_15) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000588_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000588_15) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000588_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000588_6) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000588_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000588_15) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000588_6) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000588_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_1 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000588_12) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000588_9) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000588_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_5 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000588_9) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000588_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000588_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000588_12) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000588_13) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000588_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_11 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000588_4) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000588_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000588_10) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000588_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000588_15) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000588_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_85 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000588_2) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000588_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_2 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000588_12) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000588_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_79 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000588_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_111 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000588_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000588_16) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000588_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000588_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_12 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000588_11) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000588_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000588_0) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000588_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_83 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000588_2) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000588_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_97 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000588_12) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_6 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000588_16) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000588_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_2 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000588_11) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000588_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000588_12) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000588_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_9 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000588_15) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000588_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_11 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000588_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000588_10) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000588_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000588_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_13 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000588_4) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000588_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000588_13) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000588_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_10 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000588_8) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000588_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_118 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000588_0) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000588_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000588_6) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_12 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000588_9) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000588_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000588_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_9 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000588_13) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000588_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_4 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000588_11) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000588_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_113 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000588_11) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000588_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_78 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000588_0) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_5 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000588_0) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000588_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_117 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000588_3) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000588_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_7 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000588_17) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000588_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000588_7) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000588_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_121 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000588_11) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_4 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000588_7) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000588_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000588_3) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000588_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_9 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000588_7) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000588_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_8 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000588_15) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000588_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_13 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000588_1) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000588_14 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000588_4) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000588_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_102 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000588_9) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000588_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_122 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000588_7) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000588_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
