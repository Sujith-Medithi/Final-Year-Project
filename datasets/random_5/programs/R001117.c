/*
 * Benchmark Program: R001117
 * Security Family: nested_implicit_flow
 * Generator Seed: 611713
 * High Inputs: 24 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001117_1713_0 {
    short balance;
    int status;
    short fee;
    short rate;
    int buffer[3];
};

struct FilterState_R001117_1713_1 {
    int mode;
    short gain_db;
    unsigned char prev_in;
    short cutoff;
    short prev_out;
    int buffer[3];
};

union TelemetryField_R001117_1713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001117_1713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int bound_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_57) & 63;
    acc ^= aux;
    int tracker_53 = (aux + st.buffer[1]) & 3;
    switch (tracker_53) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_1(int p0, int p1) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int index_reg_99 = local_arr[aux % 3];
    acc = (acc + index_reg_99 * 2) & 127;
    int index_reg_26 = (aux + st.buffer[1]) & 3;
    switch (index_reg_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_94 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_94 > 49) {
        acc = (acc + checksum_94 * 2 + 5) & 127;
        aux ^= (checksum_94 & 15);
    } else {
        acc = (acc - checksum_94 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_11 = local_arr[aux % 3];
    acc = (acc + tracker_11 * 2) & 127;
    int residue_29 = (aux + st.buffer[1]) & 3;
    switch (residue_29) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_34) & 63;
    acc ^= aux;
    int index_reg_17 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_17 = (index_reg_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_17) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_63 = local_arr[aux % 3];
    acc = (acc + segment_63 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_4(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int mask_62 = (aux + st.buffer[1]) & 3;
    switch (mask_62) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_14 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_14 > 20) {
        acc = (acc + residue_14 * 2 + 5) & 127;
        aux ^= (residue_14 & 15);
    } else {
        acc = (acc - residue_14 + 11) & 127;
        aux += 3;
    }
    int tally_25 = 0;
    for (int k = 0; k < 3; k++) {
        tally_25 = (tally_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_25) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_5(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_29 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_29 > 19) {
        acc = (acc + checksum_29 * 2 + 5) & 127;
        aux ^= (checksum_29 & 15);
    } else {
        acc = (acc - checksum_29 + 11) & 127;
        aux += 3;
    }
    int coefficient_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001117_1713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int checksum_40 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_40 = (checksum_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_40) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_43 = local_arr[aux % 3];
    acc = (acc + quantum_43 * 2) & 127;
    int phase_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001117_1713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int weight_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_14) & 63;
    acc ^= aux;
    int index_reg_82 = (aux + st.buffer[1]) & 3;
    switch (index_reg_82) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_26 = local_arr[aux % 3];
    acc = (acc + cursor_26 * 2) & 127;
    int coefficient_34 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_34 = (coefficient_34 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_34) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_8(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int weight_30 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_30 > 41) {
        acc = (acc + weight_30 * 2 + 5) & 127;
        aux ^= (weight_30 & 15);
    } else {
        acc = (acc - weight_30 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_64 = local_arr[aux % 3];
    acc = (acc + checksum_64 * 2) & 127;
    int accumulator_72 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_72 = (accumulator_72 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_72) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_9(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int sample_49 = local_arr[aux % 3];
    acc = (acc + sample_49 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_76 = (aux + st.buffer[1]) & 3;
    switch (sample_76) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_42 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_42 = (checksum_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_42) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_10(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int coefficient_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_14) & 63;
    acc ^= aux;
    int damping_27 = (aux + st.buffer[1]) & 3;
    switch (damping_27) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_44 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_44 > 47) {
        acc = (acc + coefficient_44 * 2 + 5) & 127;
        aux ^= (coefficient_44 & 15);
    } else {
        acc = (acc - coefficient_44 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_16 = local_arr[aux % 3];
    acc = (acc + coefficient_16 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_11(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int stride_37 = 0;
    for (int k = 0; k < 3; k++) {
        stride_37 = (stride_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_37) & 127;
    }
    int stride_55 = (aux + st.buffer[1]) & 3;
    switch (stride_55) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_21 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_21 > 13) {
        acc = (acc + threshold_21 * 2 + 5) & 127;
        aux ^= (threshold_21 & 15);
    } else {
        acc = (acc - threshold_21 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int phase_98 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_98 > 12) {
        acc = (acc + phase_98 * 2 + 5) & 127;
        aux ^= (phase_98 & 15);
    } else {
        acc = (acc - phase_98 + 11) & 127;
        aux += 3;
    }
    int tally_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001117_1713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int index_reg_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_84) & 63;
    acc ^= aux;
    int margin_26 = (aux + st.buffer[1]) & 3;
    switch (margin_26) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_64 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_64 > 41) {
        acc = (acc + tracker_64 * 2 + 5) & 127;
        aux ^= (tracker_64 & 15);
    } else {
        acc = (acc - tracker_64 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_39 = local_arr[aux % 3];
    acc = (acc + weight_39 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int factor_42 = local_arr[aux % 3];
    acc = (acc + factor_42 * 2) & 127;
    int tally_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_26) & 63;
    acc ^= aux;
    int anchor_12 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_12 > 34) {
        acc = (acc + anchor_12 * 2 + 5) & 127;
        aux ^= (anchor_12 & 15);
    } else {
        acc = (acc - anchor_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int parity_66 = (aux + st.buffer[1]) & 3;
    switch (parity_66) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_99 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_99 > 41) {
        acc = (acc + margin_99 * 2 + 5) & 127;
        aux ^= (margin_99 & 15);
    } else {
        acc = (acc - margin_99 + 11) & 127;
        aux += 3;
    }
    int sample_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001117_1713_16(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int phase_32 = (aux + st.buffer[1]) & 3;
    switch (phase_32) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_45 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_45 > 14) {
        acc = (acc + residue_45 * 2 + 5) & 127;
        aux ^= (residue_45 & 15);
    } else {
        acc = (acc - residue_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int residue_77 = local_arr[aux % 3];
    acc = (acc + residue_77 * 2) & 127;
    int coefficient_96 = (aux + st.buffer[1]) & 3;
    switch (coefficient_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_16 = 0;
    for (int k = 0; k < 3; k++) {
        scale_16 = (scale_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_16) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_18(int p0, int p1, int p2) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int anchor_51 = local_arr[aux % 3];
    acc = (acc + anchor_51 * 2) & 127;
    int weight_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_19(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int parity_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_84) & 63;
    acc ^= aux;
    int phase_27 = 0;
    for (int k = 0; k < 3; k++) {
        phase_27 = (phase_27 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_27) & 127;
    }
    int segment_70 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_70 > 39) {
        acc = (acc + segment_70 * 2 + 5) & 127;
        aux ^= (segment_70 & 15);
    } else {
        acc = (acc - segment_70 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001117_1713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int accumulator_11 = (aux + st.buffer[1]) & 3;
    switch (accumulator_11) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_36 = local_arr[aux % 3];
    acc = (acc + parity_36 * 2) & 127;
    int bound_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_26) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001117_1713_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001117_1713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_54 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_54 > 26) {
        acc = (acc + index_reg_54 * 2 + 5) & 127;
        aux ^= (index_reg_54 & 15);
    } else {
        acc = (acc - index_reg_54 + 11) & 127;
        aux += 3;
    }
    int segment_46 = (aux + st.buffer[1]) & 3;
    switch (segment_46) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int scale_54 = 0;
    for (int k = 0; k < 3; k++) {
        scale_54 = (scale_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_54) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_22(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int window_28 = (st.buffer[0] * 3 + aux) & 63;
    if (window_28 > 37) {
        acc = (acc + window_28 * 2 + 5) & 127;
        aux ^= (window_28 & 15);
    } else {
        acc = (acc - window_28 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_59 = local_arr[aux % 3];
    acc = (acc + pivot_59 * 2) & 127;
    int tracker_59 = (aux + st.buffer[1]) & 3;
    switch (tracker_59) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_93 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_93 = (anchor_93 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_93) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001117_1713_23(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001117_1713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int mask_55 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_55 > 37) {
        acc = (acc + mask_55 * 2 + 5) & 127;
        aux ^= (mask_55 & 15);
    } else {
        acc = (acc - mask_55 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_60 = 0;
    for (int k = 0; k < 2; k++) {
        delta_60 = (delta_60 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_60) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_68 = local_arr[aux % 3];
    acc = (acc + quotient_68 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001117_0;
    int sec_r001117_1;
    int sec_r001117_2;
    int sec_r001117_3;
    int sec_r001117_4;
    int sec_r001117_5;
    int sec_r001117_6;
    int sec_r001117_7;
    int sec_r001117_8;
    int sec_r001117_9;
    int sec_r001117_10;
    int sec_r001117_11;
    int sec_r001117_12;
    int sec_r001117_13;
    int sec_r001117_14;
    int sec_r001117_15;
    int sec_r001117_16;
    int sec_r001117_17;
    int sec_r001117_18;
    int sec_r001117_19;
    int sec_r001117_20;
    int sec_r001117_21;
    int sec_r001117_22;
    int sec_r001117_23;
    int pub_r001117_0;
    int pub_r001117_1;
    int pub_r001117_2;
    int pub_r001117_3;
    int pub_r001117_4;
    int pub_r001117_5;
    int pub_r001117_6;
    int pub_r001117_7;
    int pub_r001117_8;
    int pub_r001117_9;
    int pub_r001117_10;
    int pub_r001117_11;
    int pub_r001117_12;
    int pub_r001117_13;
    int pub_r001117_14;
    int pub_r001117_15;
    int pub_r001117_16;
    int pub_r001117_17;
    int pub_r001117_18;
    int pub_r001117_19;
    int pub_r001117_20;
    int pub_r001117_21;
    int pub_r001117_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001117_0 >= -100 && pub_r001117_0 <= 100);
    __CPROVER_assume(pub_r001117_1 >= -100 && pub_r001117_1 <= 100);
    __CPROVER_assume(pub_r001117_2 >= -100 && pub_r001117_2 <= 100);
    __CPROVER_assume(pub_r001117_3 >= -100 && pub_r001117_3 <= 100);
    __CPROVER_assume(pub_r001117_4 >= -100 && pub_r001117_4 <= 100);
    __CPROVER_assume(pub_r001117_5 >= -100 && pub_r001117_5 <= 100);
    __CPROVER_assume(pub_r001117_6 >= -100 && pub_r001117_6 <= 100);
    __CPROVER_assume(pub_r001117_7 >= -100 && pub_r001117_7 <= 100);
    __CPROVER_assume(pub_r001117_8 >= -100 && pub_r001117_8 <= 100);
    __CPROVER_assume(pub_r001117_9 >= -100 && pub_r001117_9 <= 100);
    __CPROVER_assume(pub_r001117_10 >= -100 && pub_r001117_10 <= 100);
    __CPROVER_assume(pub_r001117_11 >= -100 && pub_r001117_11 <= 100);
    __CPROVER_assume(pub_r001117_12 >= -100 && pub_r001117_12 <= 100);
    __CPROVER_assume(pub_r001117_13 >= -100 && pub_r001117_13 <= 100);
    __CPROVER_assume(pub_r001117_14 >= -100 && pub_r001117_14 <= 100);
    __CPROVER_assume(pub_r001117_15 >= -100 && pub_r001117_15 <= 100);
    __CPROVER_assume(pub_r001117_16 >= -100 && pub_r001117_16 <= 100);
    __CPROVER_assume(pub_r001117_17 >= -100 && pub_r001117_17 <= 100);
    __CPROVER_assume(pub_r001117_18 >= -100 && pub_r001117_18 <= 100);
    __CPROVER_assume(pub_r001117_19 >= -100 && pub_r001117_19 <= 100);
    __CPROVER_assume(pub_r001117_20 >= -100 && pub_r001117_20 <= 100);
    __CPROVER_assume(pub_r001117_21 >= -100 && pub_r001117_21 <= 100);
    __CPROVER_assume(pub_r001117_22 >= -100 && pub_r001117_22 <= 100);
    __CPROVER_assume(sec_r001117_0 >= 0 && sec_r001117_0 <= 255);
    __CPROVER_assume(sec_r001117_1 >= 0 && sec_r001117_1 <= 255);
    __CPROVER_assume(sec_r001117_2 >= 0 && sec_r001117_2 <= 255);
    __CPROVER_assume(sec_r001117_3 >= 0 && sec_r001117_3 <= 255);
    __CPROVER_assume(sec_r001117_4 >= 0 && sec_r001117_4 <= 255);
    __CPROVER_assume(sec_r001117_5 >= 0 && sec_r001117_5 <= 255);
    __CPROVER_assume(sec_r001117_6 >= 0 && sec_r001117_6 <= 255);
    __CPROVER_assume(sec_r001117_7 >= 0 && sec_r001117_7 <= 255);
    __CPROVER_assume(sec_r001117_8 >= 0 && sec_r001117_8 <= 255);
    __CPROVER_assume(sec_r001117_9 >= 0 && sec_r001117_9 <= 255);
    __CPROVER_assume(sec_r001117_10 >= 0 && sec_r001117_10 <= 255);
    __CPROVER_assume(sec_r001117_11 >= 0 && sec_r001117_11 <= 255);
    __CPROVER_assume(sec_r001117_12 >= 0 && sec_r001117_12 <= 255);
    __CPROVER_assume(sec_r001117_13 >= 0 && sec_r001117_13 <= 255);
    __CPROVER_assume(sec_r001117_14 >= 0 && sec_r001117_14 <= 255);
    __CPROVER_assume(sec_r001117_15 >= 0 && sec_r001117_15 <= 255);
    __CPROVER_assume(sec_r001117_16 >= 0 && sec_r001117_16 <= 255);
    __CPROVER_assume(sec_r001117_17 >= 0 && sec_r001117_17 <= 255);
    __CPROVER_assume(sec_r001117_18 >= 0 && sec_r001117_18 <= 255);
    __CPROVER_assume(sec_r001117_19 >= 0 && sec_r001117_19 <= 255);
    __CPROVER_assume(sec_r001117_20 >= 0 && sec_r001117_20 <= 255);
    __CPROVER_assume(sec_r001117_21 >= 0 && sec_r001117_21 <= 255);
    __CPROVER_assume(sec_r001117_22 >= 0 && sec_r001117_22 <= 255);
    __CPROVER_assume(sec_r001117_23 >= 0 && sec_r001117_23 <= 255);

    struct Transaction_R001117_1713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001117_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001117_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001117_0 + 7) & 15;
    struct FilterState_R001117_1713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001117_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001117_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001117_0 + 9) & 15;

    union TelemetryField_R001117_1713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001117_1713_0(sec_r001117_0, sec_r001117_1, pub_r001117_2, pub_r001117_3);
    int helper_flow_1 = fn_R001117_1713_1(sec_r001117_1, pub_r001117_2);
    int helper_flow_2 = fn_R001117_1713_2(sec_r001117_2, pub_r001117_3, pub_r001117_4, pub_r001117_5);
    int helper_flow_3 = fn_R001117_1713_3(sec_r001117_3, sec_r001117_4, pub_r001117_5, pub_r001117_6, pub_r001117_7);
    int helper_flow_4 = fn_R001117_1713_4(sec_r001117_4, sec_r001117_5, pub_r001117_6);
    int helper_flow_5 = fn_R001117_1713_5(sec_r001117_5, pub_r001117_6, pub_r001117_7);
    int helper_flow_6 = fn_R001117_1713_6(sec_r001117_6, pub_r001117_7, pub_r001117_8, pub_r001117_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_0 ^ pub_r001117_7) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001117_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001117_9 ^ pub_r001117_7) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001117_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001117_18 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001117_12 ^ pub_r001117_0) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001117_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001117_21 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_4 ^ pub_r001117_13) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001117_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001117_11 ^ pub_r001117_7) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001117_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_6 ^ pub_r001117_21) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001117_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001117_20 ^ pub_r001117_14) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001117_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001117_20 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_8 ^ pub_r001117_2) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (helper_flow_2 ^ pub_r001117_2) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001117_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001117_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001117_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001117_9 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (sec_r001117_10 ^ pub_r001117_20) & 63;
    if ((stage_v_15 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_15 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_15 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_15 * 2) & 255;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (stage_v_3 ^ pub_r001117_14) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001117_18 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001117_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001117_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001117_10 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_4 ^ pub_r001117_1) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001117_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001117_2 ^ pub_r001117_1) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001117_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_1 ^ pub_r001117_0) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001117_12 ^ pub_r001117_0) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r001117_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_1 ^ pub_r001117_8) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001117_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001117_18 ^ pub_r001117_12) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (helper_flow_5 ^ pub_r001117_6) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r001117_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001117_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_0 ^ pub_r001117_3) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r001117_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_5 ^ pub_r001117_7) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r001117_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001117_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_6 ^ pub_r001117_13) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_15 ^ pub_r001117_3) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001117_11 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001117_16 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001117_14 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001117_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001117_15 ^ pub_r001117_1) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (sec_r001117_9 ^ pub_r001117_7) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r001117_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001117_10 ^ pub_r001117_16) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_41 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_21 ^ pub_r001117_9) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_15 ^ pub_r001117_5) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001117_9 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001117_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001117_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001117_20 ^ pub_r001117_15) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001117_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (sec_r001117_21 ^ pub_r001117_8) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r001117_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (sec_r001117_0 ^ pub_r001117_18) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_49 ^ pub_r001117_14) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001117_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001117_11 ^ pub_r001117_16) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_34 ^ pub_r001117_4) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r001117_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001117_22 ^ pub_r001117_13) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001117_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001117_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001117_19 ^ pub_r001117_12) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r001117_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_3 ^ pub_r001117_0) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_3 ^ pub_r001117_16) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r001117_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_49 ^ pub_r001117_9) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001117_8 ^ pub_r001117_22) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r001117_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001117_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001117_9 ^ pub_r001117_3) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001117_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001117_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_43 ^ pub_r001117_1) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r001117_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001117_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (stage_v_31 ^ pub_r001117_11) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_10 ^ pub_r001117_16) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_32 ^ pub_r001117_2) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r001117_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_0 ^ pub_r001117_2) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001117_14 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r001117_2 ^ pub_r001117_12) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_0 ^ pub_r001117_5) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001117_7 ^ pub_r001117_16) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001117_4 ^ pub_r001117_10) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_48 ^ pub_r001117_15) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_48 ^ pub_r001117_18) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r001117_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_76 ^ pub_r001117_0) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001117_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_40 ^ pub_r001117_15) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001117_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_63 ^ pub_r001117_15) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_61 ^ pub_r001117_19) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001117_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (helper_flow_5 ^ pub_r001117_4) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_43 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001117_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001117_18 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001117_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_54 ^ pub_r001117_18) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001117_1 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_53 ^ pub_r001117_11) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001117_14 ^ pub_r001117_10) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001117_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001117_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_63 ^ pub_r001117_15) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (helper_flow_1 ^ pub_r001117_15) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001117_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_82 ^ pub_r001117_21) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_31 ^ pub_r001117_11) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r001117_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_51 ^ pub_r001117_5) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_8 ^ pub_r001117_5) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r001117_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (sec_r001117_23 ^ pub_r001117_9) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001117_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_75 ^ pub_r001117_14) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_21 ^ pub_r001117_14) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_25 ^ pub_r001117_14) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001117_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_82 ^ pub_r001117_4) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r001117_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (helper_flow_4 ^ pub_r001117_10) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r001117_22 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_0 ^ pub_r001117_7) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_35 ^ pub_r001117_5) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r001117_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001117_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001117_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_1 ^ pub_r001117_7) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001117_16 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001117_17 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_51 ^ pub_r001117_12) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (sec_r001117_12 ^ pub_r001117_1) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001117_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001117_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001117_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001117_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (sec_r001117_21 ^ pub_r001117_0) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001117_20 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001117_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001117_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_98 ^ pub_r001117_19) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_107 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001117_17 ^ pub_r001117_22) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_88 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (helper_flow_0 ^ pub_r001117_0) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_128 ^ pub_r001117_13) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((sec_r001117_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001117_12 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (helper_flow_3 ^ pub_r001117_7) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_113 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001117_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001117_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001117_7 ^ pub_r001117_14) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_90 ^ pub_r001117_11) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((sec_r001117_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_95 ^ pub_r001117_17) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_134 ^ pub_r001117_4) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r001117_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001117_17 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_34 ^ pub_r001117_14) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_91 ^ pub_r001117_8) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_52 ^ pub_r001117_11) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_129 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_50 ^ pub_r001117_8) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001117_9 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001117_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_122 ^ pub_r001117_16) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r001117_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001117_6 ^ pub_r001117_17) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_101 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001117_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001117_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001117_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_52 ^ pub_r001117_1) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r001117_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001117_19 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_67 ^ pub_r001117_18) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_77 ^ pub_r001117_11) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((stage_v_127 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001117_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001117_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_15 ^ pub_r001117_12) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001117_1 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_16 ^ pub_r001117_0) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001117_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r001117_16 ^ pub_r001117_16) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_0 ^ pub_r001117_22) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
