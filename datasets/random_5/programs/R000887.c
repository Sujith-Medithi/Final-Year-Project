/*
 * Benchmark Program: R000887
 * Security Family: nested_implicit_flow
 * Generator Seed: 588713
 * High Inputs: 21 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000887_8713_0 {
    unsigned char signature;
    int seq;
    int facility;
    int timestamp;
    short severity;
    unsigned char code;
    int buffer[3];
};

struct DeviceConfig_R000887_8713_1 {
    int baud_rate;
    int id;
    int parity;
    short stop_bits;
    unsigned char timeout;
    int buffer[3];
};

struct Transaction_R000887_8713_2 {
    unsigned char status;
    unsigned char balance;
    int account_id;
    int buffer[3];
};

union ColorPixel_R000887_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000887_8713_0(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000887_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tracker_49 = (aux + st.buffer[1]) & 3;
    switch (tracker_49) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_34 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_34 > 33) {
        acc = (acc + bound_34 * 2 + 5) & 127;
        aux ^= (bound_34 & 15);
    } else {
        acc = (acc - bound_34 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_1(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int sample_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_2(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_77 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_77 > 19) {
        acc = (acc + margin_77 * 2 + 5) & 127;
        aux ^= (margin_77 & 15);
    } else {
        acc = (acc - margin_77 + 11) & 127;
        aux += 3;
    }
    int weight_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000887_8713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int scale_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_83) & 63;
    acc ^= aux;
    int factor_62 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_62 > 45) {
        acc = (acc + factor_62 * 2 + 5) & 127;
        aux ^= (factor_62 & 15);
    } else {
        acc = (acc - factor_62 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_4(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int damping_98 = local_arr[aux % 3];
    acc = (acc + damping_98 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000887_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int scale_87 = (aux + st.buffer[1]) & 3;
    switch (scale_87) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000887_8713_6(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000887_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int coefficient_21 = local_arr[aux % 3];
    acc = (acc + coefficient_21 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_85 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_85 > 16) {
        acc = (acc + weight_85 * 2 + 5) & 127;
        aux ^= (weight_85 & 15);
    } else {
        acc = (acc - weight_85 + 11) & 127;
        aux += 3;
    }
    int checksum_92 = (aux + st.buffer[1]) & 3;
    switch (checksum_92) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int delta_20 = local_arr[aux % 3];
    acc = (acc + delta_20 * 2) & 127;
    int metric_49 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_49 > 50) {
        acc = (acc + metric_49 * 2 + 5) & 127;
        aux ^= (metric_49 & 15);
    } else {
        acc = (acc - metric_49 + 11) & 127;
        aux += 3;
    }
    int factor_84 = (aux + st.buffer[1]) & 3;
    switch (factor_84) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_8(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000887_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_65) & 63;
    acc ^= aux;
    int margin_33 = (aux + st.buffer[1]) & 3;
    switch (margin_33) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_68 = local_arr[aux % 3];
    acc = (acc + residue_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_9(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int segment_64 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_64 > 11) {
        acc = (acc + segment_64 * 2 + 5) & 127;
        aux ^= (segment_64 & 15);
    } else {
        acc = (acc - segment_64 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_28 = (aux + st.buffer[1]) & 3;
    switch (index_reg_28) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000887_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_83 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_83 > 34) {
        acc = (acc + pivot_83 * 2 + 5) & 127;
        aux ^= (pivot_83 & 15);
    } else {
        acc = (acc - pivot_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_11(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int vector_18 = (aux + st.buffer[1]) & 3;
    switch (vector_18) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_84 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_84 > 30) {
        acc = (acc + accumulator_84 * 2 + 5) & 127;
        aux ^= (accumulator_84 & 15);
    } else {
        acc = (acc - accumulator_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int threshold_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_76) & 63;
    acc ^= aux;
    int quantum_29 = (aux + st.buffer[1]) & 3;
    switch (quantum_29) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_25 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_25 > 34) {
        acc = (acc + index_reg_25 * 2 + 5) & 127;
        aux ^= (index_reg_25 & 15);
    } else {
        acc = (acc - index_reg_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_13(int p0, int p1) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int coefficient_86 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_86 > 21) {
        acc = (acc + coefficient_86 * 2 + 5) & 127;
        aux ^= (coefficient_86 & 15);
    } else {
        acc = (acc - coefficient_86 + 11) & 127;
        aux += 3;
    }
    int tally_39 = (aux + st.buffer[1]) & 3;
    switch (tally_39) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000887_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int factor_14 = local_arr[aux % 3];
    acc = (acc + factor_14 * 2) & 127;
    int tally_74 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_74 > 18) {
        acc = (acc + tally_74 * 2 + 5) & 127;
        aux ^= (tally_74 & 15);
    } else {
        acc = (acc - tally_74 + 11) & 127;
        aux += 3;
    }
    int anchor_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_80) & 63;
    acc ^= aux;
    int pivot_69 = (aux + st.buffer[1]) & 3;
    switch (pivot_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000887_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int cursor_16 = local_arr[aux % 3];
    acc = (acc + cursor_16 * 2) & 127;
    int segment_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_70) & 63;
    acc ^= aux;
    int cursor_74 = (aux + st.buffer[1]) & 3;
    switch (cursor_74) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_16(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000887_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int cursor_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_17) & 63;
    acc ^= aux;
    int parity_89 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_89 > 11) {
        acc = (acc + parity_89 * 2 + 5) & 127;
        aux ^= (parity_89 & 15);
    } else {
        acc = (acc - parity_89 + 11) & 127;
        aux += 3;
    }
    int factor_48 = (aux + st.buffer[1]) & 3;
    switch (factor_48) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000887_8713_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000887_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int threshold_77 = (aux + st.buffer[1]) & 3;
    switch (threshold_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_91) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_95 = local_arr[aux % 3];
    acc = (acc + pivot_95 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000887_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quantum_88 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_88 > 11) {
        acc = (acc + quantum_88 * 2 + 5) & 127;
        aux ^= (quantum_88 & 15);
    } else {
        acc = (acc - quantum_88 + 11) & 127;
        aux += 3;
    }
    int delta_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_77) & 63;
    acc ^= aux;
    int checksum_14 = (aux + st.buffer[1]) & 3;
    switch (checksum_14) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000887_8713_19(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000887_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000887_8713_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000887_8713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_51 = local_arr[aux % 3];
    acc = (acc + tally_51 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000887_0;
    int sec_r000887_1;
    int sec_r000887_2;
    int sec_r000887_3;
    int sec_r000887_4;
    int sec_r000887_5;
    int sec_r000887_6;
    int sec_r000887_7;
    int sec_r000887_8;
    int sec_r000887_9;
    int sec_r000887_10;
    int sec_r000887_11;
    int sec_r000887_12;
    int sec_r000887_13;
    int sec_r000887_14;
    int sec_r000887_15;
    int sec_r000887_16;
    int sec_r000887_17;
    int sec_r000887_18;
    int sec_r000887_19;
    int sec_r000887_20;
    int pub_r000887_0;
    int pub_r000887_1;
    int pub_r000887_2;
    int pub_r000887_3;
    int pub_r000887_4;
    int pub_r000887_5;
    int pub_r000887_6;
    int pub_r000887_7;
    int pub_r000887_8;
    int pub_r000887_9;
    int pub_r000887_10;
    int pub_r000887_11;
    int pub_r000887_12;
    int pub_r000887_13;
    int pub_r000887_14;
    int pub_r000887_15;
    int pub_r000887_16;
    int pub_r000887_17;
    int pub_r000887_18;
    int pub_r000887_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000887_0 >= -100 && pub_r000887_0 <= 100);
    __CPROVER_assume(pub_r000887_1 >= -100 && pub_r000887_1 <= 100);
    __CPROVER_assume(pub_r000887_2 >= -100 && pub_r000887_2 <= 100);
    __CPROVER_assume(pub_r000887_3 >= -100 && pub_r000887_3 <= 100);
    __CPROVER_assume(pub_r000887_4 >= -100 && pub_r000887_4 <= 100);
    __CPROVER_assume(pub_r000887_5 >= -100 && pub_r000887_5 <= 100);
    __CPROVER_assume(pub_r000887_6 >= -100 && pub_r000887_6 <= 100);
    __CPROVER_assume(pub_r000887_7 >= -100 && pub_r000887_7 <= 100);
    __CPROVER_assume(pub_r000887_8 >= -100 && pub_r000887_8 <= 100);
    __CPROVER_assume(pub_r000887_9 >= -100 && pub_r000887_9 <= 100);
    __CPROVER_assume(pub_r000887_10 >= -100 && pub_r000887_10 <= 100);
    __CPROVER_assume(pub_r000887_11 >= -100 && pub_r000887_11 <= 100);
    __CPROVER_assume(pub_r000887_12 >= -100 && pub_r000887_12 <= 100);
    __CPROVER_assume(pub_r000887_13 >= -100 && pub_r000887_13 <= 100);
    __CPROVER_assume(pub_r000887_14 >= -100 && pub_r000887_14 <= 100);
    __CPROVER_assume(pub_r000887_15 >= -100 && pub_r000887_15 <= 100);
    __CPROVER_assume(pub_r000887_16 >= -100 && pub_r000887_16 <= 100);
    __CPROVER_assume(pub_r000887_17 >= -100 && pub_r000887_17 <= 100);
    __CPROVER_assume(pub_r000887_18 >= -100 && pub_r000887_18 <= 100);
    __CPROVER_assume(pub_r000887_19 >= -100 && pub_r000887_19 <= 100);
    __CPROVER_assume(sec_r000887_0 >= 0 && sec_r000887_0 <= 255);
    __CPROVER_assume(sec_r000887_1 >= 0 && sec_r000887_1 <= 255);
    __CPROVER_assume(sec_r000887_2 >= 0 && sec_r000887_2 <= 255);
    __CPROVER_assume(sec_r000887_3 >= 0 && sec_r000887_3 <= 255);
    __CPROVER_assume(sec_r000887_4 >= 0 && sec_r000887_4 <= 255);
    __CPROVER_assume(sec_r000887_5 >= 0 && sec_r000887_5 <= 255);
    __CPROVER_assume(sec_r000887_6 >= 0 && sec_r000887_6 <= 255);
    __CPROVER_assume(sec_r000887_7 >= 0 && sec_r000887_7 <= 255);
    __CPROVER_assume(sec_r000887_8 >= 0 && sec_r000887_8 <= 255);
    __CPROVER_assume(sec_r000887_9 >= 0 && sec_r000887_9 <= 255);
    __CPROVER_assume(sec_r000887_10 >= 0 && sec_r000887_10 <= 255);
    __CPROVER_assume(sec_r000887_11 >= 0 && sec_r000887_11 <= 255);
    __CPROVER_assume(sec_r000887_12 >= 0 && sec_r000887_12 <= 255);
    __CPROVER_assume(sec_r000887_13 >= 0 && sec_r000887_13 <= 255);
    __CPROVER_assume(sec_r000887_14 >= 0 && sec_r000887_14 <= 255);
    __CPROVER_assume(sec_r000887_15 >= 0 && sec_r000887_15 <= 255);
    __CPROVER_assume(sec_r000887_16 >= 0 && sec_r000887_16 <= 255);
    __CPROVER_assume(sec_r000887_17 >= 0 && sec_r000887_17 <= 255);
    __CPROVER_assume(sec_r000887_18 >= 0 && sec_r000887_18 <= 255);
    __CPROVER_assume(sec_r000887_19 >= 0 && sec_r000887_19 <= 255);
    __CPROVER_assume(sec_r000887_20 >= 0 && sec_r000887_20 <= 255);

    struct EventLog_R000887_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000887_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000887_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000887_0 + 7) & 15;
    struct DeviceConfig_R000887_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000887_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000887_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000887_0 + 9) & 15;
    struct Transaction_R000887_8713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000887_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000887_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000887_0 + 11) & 15;

    union ColorPixel_R000887_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
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
    int stage_v_15 = (st_var_0.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 12) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 27) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 34) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 49) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 36) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 51) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 25) & 15;
    int stage_v_24 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= stage_v_24;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 29) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 44) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 28) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 43) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_33 = (stage_v_33 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_33) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 16) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 31) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] * 2 + 142) & 63;
    if (stage_v_45 > 22) {
        out_sink = (out_sink + stage_v_45 - 5) & 255;
        if (stage_v_45 > 37) {
            chk_sum ^= (stage_v_45 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_45 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 36) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 51) {
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
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 10) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 25) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

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
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000887_10 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_62 = (pub_r000887_10 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000887_10 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000887_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000887_20 & 2) != 0) {
            stage_v_63 = (pub_r000887_5 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000887_5 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000887_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000887_1 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_64 = (pub_r000887_15 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000887_15 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000887_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000887_14 & 2) != 0) {
            stage_v_65 = (pub_r000887_7 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000887_7 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000887_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000887_8 & 1) != 0) {
        if ((sec_r000887_16 & 2) != 0) {
            stage_v_66 = (pub_r000887_17 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000887_17 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000887_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000887_16 & 2) != 0) {
            stage_v_67 = (pub_r000887_6 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000887_6 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000887_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000887_9 & 2) != 0) {
            stage_v_68 = (pub_r000887_3 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000887_3 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000887_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_69 = (pub_r000887_9 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000887_9 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000887_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_70 = (pub_r000887_12 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000887_12 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000887_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_71 = (pub_r000887_0 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000887_0 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000887_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_72 = (pub_r000887_11 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000887_11 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000887_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000887_0 & 1) != 0) {
        if ((sec_r000887_12 & 2) != 0) {
            stage_v_73 = (pub_r000887_17 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000887_17 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000887_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_74 = (pub_r000887_13 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000887_13 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000887_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000887_20 & 1) != 0) {
        if ((sec_r000887_4 & 2) != 0) {
            stage_v_75 = (pub_r000887_11 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000887_11 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000887_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_76 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000887_11 & 2) != 0) {
            stage_v_77 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000887_2 & 1) != 0) {
        if ((sec_r000887_20 & 2) != 0) {
            stage_v_78 = (pub_r000887_2 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000887_2 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000887_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_79 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000887_0 & 1) != 0) {
        if ((sec_r000887_0 & 2) != 0) {
            stage_v_80 = (pub_r000887_3 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000887_3 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000887_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000887_10 & 2) != 0) {
            stage_v_81 = (pub_r000887_1 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000887_1 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000887_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000887_5 & 2) != 0) {
            stage_v_82 = (pub_r000887_4 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000887_4 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000887_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000887_0 & 2) != 0) {
            stage_v_83 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000887_9 & 1) != 0) {
        if ((sec_r000887_9 & 2) != 0) {
            stage_v_84 = (pub_r000887_2 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000887_2 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000887_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_85 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000887_9 & 2) != 0) {
            stage_v_86 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000887_6 & 1) != 0) {
        if ((sec_r000887_20 & 2) != 0) {
            stage_v_87 = (pub_r000887_0 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000887_0 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000887_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000887_13 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_88 = (pub_r000887_6 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000887_6 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000887_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000887_20 & 1) != 0) {
        if ((sec_r000887_17 & 2) != 0) {
            stage_v_89 = (pub_r000887_1 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000887_1 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000887_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000887_6 & 2) != 0) {
            stage_v_90 = (pub_r000887_17 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000887_17 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000887_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_91 = (pub_r000887_6 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000887_6 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000887_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000887_19 & 2) != 0) {
            stage_v_92 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000887_0 & 1) != 0) {
        if ((sec_r000887_4 & 2) != 0) {
            stage_v_93 = (pub_r000887_3 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000887_3 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000887_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000887_0 & 2) != 0) {
            stage_v_94 = (pub_r000887_8 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000887_8 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000887_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000887_4 & 2) != 0) {
            stage_v_95 = (pub_r000887_10 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000887_10 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000887_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_96 = (pub_r000887_8 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000887_8 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000887_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000887_9 & 1) != 0) {
        if ((sec_r000887_20 & 2) != 0) {
            stage_v_97 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_98 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000887_10 & 2) != 0) {
            stage_v_99 = (pub_r000887_13 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000887_13 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000887_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000887_9 & 2) != 0) {
            stage_v_100 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000887_16 & 2) != 0) {
            stage_v_101 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((sec_r000887_12 & 1) != 0) {
        if ((sec_r000887_6 & 2) != 0) {
            stage_v_102 = (pub_r000887_15 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000887_15 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000887_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000887_11 & 1) != 0) {
        if ((sec_r000887_13 & 2) != 0) {
            stage_v_103 = (pub_r000887_11 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000887_11 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000887_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000887_7 & 2) != 0) {
            stage_v_104 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000887_20 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_105 = (pub_r000887_0 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000887_0 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000887_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000887_4 & 2) != 0) {
            stage_v_106 = (pub_r000887_0 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000887_0 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000887_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000887_17 & 2) != 0) {
            stage_v_107 = (pub_r000887_15 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000887_15 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000887_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000887_6 & 2) != 0) {
            stage_v_108 = (pub_r000887_0 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000887_0 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000887_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000887_13 & 2) != 0) {
            stage_v_109 = (pub_r000887_6 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000887_6 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000887_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_110 = (pub_r000887_16 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000887_16 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000887_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_111 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000887_20 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_112 = (pub_r000887_1 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000887_1 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000887_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000887_2 & 2) != 0) {
            stage_v_113 = (pub_r000887_2 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000887_2 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000887_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000887_7 & 2) != 0) {
            stage_v_114 = (pub_r000887_9 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000887_9 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000887_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_115 = (pub_r000887_7 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000887_7 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000887_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_116 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_117 = (pub_r000887_17 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000887_17 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000887_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000887_0 & 1) != 0) {
        if ((sec_r000887_2 & 2) != 0) {
            stage_v_118 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000887_1 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_119 = (pub_r000887_16 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000887_16 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000887_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000887_10 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_120 = (pub_r000887_16 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000887_16 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000887_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000887_5 & 2) != 0) {
            stage_v_121 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000887_19 & 2) != 0) {
            stage_v_122 = (pub_r000887_17 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000887_17 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000887_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000887_14 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_123 = (pub_r000887_11 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000887_11 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000887_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000887_1 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_124 = (pub_r000887_19 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000887_19 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000887_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_125 = (pub_r000887_1 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000887_1 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000887_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_126 = (pub_r000887_4 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000887_4 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000887_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_127 = (pub_r000887_10 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000887_10 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000887_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r000887_2 & 2) != 0) {
            stage_v_128 = (pub_r000887_4 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000887_4 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000887_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000887_15 & 2) != 0) {
            stage_v_129 = (pub_r000887_6 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000887_6 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000887_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_130 = (pub_r000887_5 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000887_5 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000887_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((sec_r000887_2 & 1) != 0) {
        if ((sec_r000887_19 & 2) != 0) {
            stage_v_131 = (pub_r000887_19 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000887_19 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000887_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000887_7 & 2) != 0) {
            stage_v_132 = (pub_r000887_8 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000887_8 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000887_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000887_13 & 2) != 0) {
            stage_v_133 = (pub_r000887_9 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000887_9 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000887_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000887_16 & 2) != 0) {
            stage_v_134 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000887_17 & 2) != 0) {
            stage_v_135 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000887_15 & 1) != 0) {
        if ((sec_r000887_20 & 2) != 0) {
            stage_v_136 = (pub_r000887_12 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000887_12 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000887_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000887_17 & 1) != 0) {
        if ((sec_r000887_12 & 2) != 0) {
            stage_v_137 = (pub_r000887_10 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000887_10 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000887_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000887_1 & 1) != 0) {
        if ((sec_r000887_11 & 2) != 0) {
            stage_v_138 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000887_2 & 2) != 0) {
            stage_v_139 = (pub_r000887_4 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000887_4 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000887_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000887_14 & 1) != 0) {
        if ((sec_r000887_2 & 2) != 0) {
            stage_v_140 = (pub_r000887_11 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000887_11 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000887_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000887_14 & 1) != 0) {
        if ((sec_r000887_9 & 2) != 0) {
            stage_v_141 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r000887_7 & 2) != 0) {
            stage_v_142 = (pub_r000887_2 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000887_2 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000887_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000887_5 & 2) != 0) {
            stage_v_143 = (pub_r000887_9 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000887_9 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000887_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000887_4 & 2) != 0) {
            stage_v_144 = (pub_r000887_4 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000887_4 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000887_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000887_1 & 2) != 0) {
            stage_v_145 = (pub_r000887_15 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000887_15 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000887_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r000887_4 & 2) != 0) {
            stage_v_146 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((sec_r000887_5 & 1) != 0) {
        if ((sec_r000887_8 & 2) != 0) {
            stage_v_147 = (pub_r000887_9 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000887_9 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000887_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000887_20 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_148 = (pub_r000887_14 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000887_14 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000887_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000887_12 & 1) != 0) {
        if ((sec_r000887_7 & 2) != 0) {
            stage_v_149 = (pub_r000887_0 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000887_0 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000887_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000887_14 & 1) != 0) {
        if ((sec_r000887_19 & 2) != 0) {
            stage_v_150 = (pub_r000887_7 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000887_7 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000887_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_121 & 1) != 0) {
        if ((sec_r000887_18 & 2) != 0) {
            stage_v_151 = (pub_r000887_17 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000887_17 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000887_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000887_16 & 2) != 0) {
            stage_v_152 = (pub_r000887_10 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000887_10 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000887_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_113 & 1) != 0) {
        if ((sec_r000887_12 & 2) != 0) {
            stage_v_153 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_154 = (pub_r000887_6 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000887_6 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000887_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000887_12 & 1) != 0) {
        if ((sec_r000887_13 & 2) != 0) {
            stage_v_155 = (pub_r000887_12 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000887_12 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000887_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000887_2 & 1) != 0) {
        if ((sec_r000887_6 & 2) != 0) {
            stage_v_156 = (pub_r000887_12 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000887_12 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000887_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_139 & 1) != 0) {
        if ((sec_r000887_7 & 2) != 0) {
            stage_v_157 = (pub_r000887_12 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000887_12 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000887_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000887_3 & 2) != 0) {
            stage_v_158 = (pub_r000887_18 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000887_18 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000887_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
