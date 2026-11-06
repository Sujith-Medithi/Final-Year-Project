/*
 * Benchmark Program: R000658
 * Security Family: secret_dependent_loops
 * Generator Seed: 565813
 * High Inputs: 18 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000658_5813_0 {
    int coord_y;
    int coord_x;
    int pitch;
    short coord_z;
    int buffer[3];
};

struct DeviceConfig_R000658_5813_1 {
    short port;
    unsigned char stop_bits;
    unsigned char parity;
    short baud_rate;
    int buffer[3];
};

struct FilterState_R000658_5813_2 {
    short damping;
    short cutoff;
    short prev_in;
    int prev_out;
    int buffer[3];
};

union TelemetryField_R000658_5813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000658_5813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000658_5813_0(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000658_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int window_72 = local_arr[aux % 3];
    acc = (acc + window_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_1(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_79 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_79 > 25) {
        acc = (acc + checksum_79 * 2 + 5) & 127;
        aux ^= (checksum_79 & 15);
    } else {
        acc = (acc - checksum_79 + 11) & 127;
        aux += 3;
    }
    int threshold_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_19 = local_arr[aux % 3];
    acc = (acc + threshold_19 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_2(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_98 = (aux + st.buffer[1]) & 3;
    switch (coefficient_98) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_86) & 63;
    acc ^= aux;
    int mask_38 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_38 > 20) {
        acc = (acc + mask_38 * 2 + 5) & 127;
        aux ^= (mask_38 & 15);
    } else {
        acc = (acc - mask_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000658_5813_3(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000658_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_61 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_61 > 44) {
        acc = (acc + damping_61 * 2 + 5) & 127;
        aux ^= (damping_61 & 15);
    } else {
        acc = (acc - damping_61 + 11) & 127;
        aux += 3;
    }
    int index_reg_98 = (aux + st.buffer[1]) & 3;
    switch (index_reg_98) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_38 = local_arr[aux % 3];
    acc = (acc + margin_38 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000658_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int mask_82 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_82 > 40) {
        acc = (acc + mask_82 * 2 + 5) & 127;
        aux ^= (mask_82 & 15);
    } else {
        acc = (acc - mask_82 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_83 = local_arr[aux % 3];
    acc = (acc + window_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int factor_46 = local_arr[aux % 3];
    acc = (acc + factor_46 * 2) & 127;
    int coefficient_58 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_58 > 15) {
        acc = (acc + coefficient_58 * 2 + 5) & 127;
        aux ^= (coefficient_58 & 15);
    } else {
        acc = (acc - coefficient_58 + 11) & 127;
        aux += 3;
    }
    int bound_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_69) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int quotient_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_13) & 63;
    acc ^= aux;
    int index_reg_77 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_77 > 43) {
        acc = (acc + index_reg_77 * 2 + 5) & 127;
        aux ^= (index_reg_77 & 15);
    } else {
        acc = (acc - index_reg_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000658_5813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quantum_64 = (aux + st.buffer[1]) & 3;
    switch (quantum_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_88) & 63;
    acc ^= aux;
    int residue_87 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_87 > 34) {
        acc = (acc + residue_87 * 2 + 5) & 127;
        aux ^= (residue_87 & 15);
    } else {
        acc = (acc - residue_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000658_5813_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int sample_50 = (aux + st.buffer[1]) & 3;
    switch (sample_50) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_41 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_41 > 26) {
        acc = (acc + index_reg_41 * 2 + 5) & 127;
        aux ^= (index_reg_41 & 15);
    } else {
        acc = (acc - index_reg_41 + 11) & 127;
        aux += 3;
    }
    int threshold_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000658_5813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000658_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int margin_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_34) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_99 = local_arr[aux % 3];
    acc = (acc + residue_99 * 2) & 127;
    int anchor_61 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_61 > 24) {
        acc = (acc + anchor_61 * 2 + 5) & 127;
        aux ^= (anchor_61 & 15);
    } else {
        acc = (acc - anchor_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000658_5813_10(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int delta_61 = (aux + st.buffer[1]) & 3;
    switch (delta_61) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_26 = local_arr[aux % 3];
    acc = (acc + mask_26 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_51) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000658_5813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int quotient_84 = (aux + st.buffer[1]) & 3;
    switch (quotient_84) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_12(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_79 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_79 > 39) {
        acc = (acc + anchor_79 * 2 + 5) & 127;
        aux ^= (anchor_79 & 15);
    } else {
        acc = (acc - anchor_79 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_15 = (aux + st.buffer[1]) & 3;
    switch (phase_15) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_45) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_57 = local_arr[aux % 3];
    acc = (acc + residue_57 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int checksum_93 = local_arr[aux % 3];
    acc = (acc + checksum_93 * 2) & 127;
    int offset_99 = (aux + st.buffer[1]) & 3;
    switch (offset_99) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000658_5813_15(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int offset_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_94 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_94 > 14) {
        acc = (acc + tally_94 * 2 + 5) & 127;
        aux ^= (tally_94 & 15);
    } else {
        acc = (acc - tally_94 + 11) & 127;
        aux += 3;
    }
    int bound_23 = (aux + st.buffer[1]) & 3;
    switch (bound_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000658_5813_16(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int residue_48 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_48 > 12) {
        acc = (acc + residue_48 * 2 + 5) & 127;
        aux ^= (residue_48 & 15);
    } else {
        acc = (acc - residue_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_67 = local_arr[aux % 3];
    acc = (acc + coefficient_67 * 2) & 127;
    int scale_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000658_5813_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000658_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_76 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_76 > 18) {
        acc = (acc + delta_76 * 2 + 5) & 127;
        aux ^= (delta_76 & 15);
    } else {
        acc = (acc - delta_76 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_91 = local_arr[aux % 3];
    acc = (acc + mask_91 * 2) & 127;
    int quantum_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_65) & 63;
    acc ^= aux;
    int weight_22 = (aux + st.buffer[1]) & 3;
    switch (weight_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000658_5813_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int coefficient_42 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_42 > 12) {
        acc = (acc + coefficient_42 * 2 + 5) & 127;
        aux ^= (coefficient_42 & 15);
    } else {
        acc = (acc - coefficient_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_67 = local_arr[aux % 3];
    acc = (acc + pivot_67 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_19(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000658_5813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int tally_96 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_96 > 18) {
        acc = (acc + tally_96 * 2 + 5) & 127;
        aux ^= (tally_96 & 15);
    } else {
        acc = (acc - tally_96 + 11) & 127;
        aux += 3;
    }
    int checksum_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_43 = local_arr[aux % 3];
    acc = (acc + offset_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_20(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000658_5813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int anchor_19 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_19 > 27) {
        acc = (acc + anchor_19 * 2 + 5) & 127;
        aux ^= (anchor_19 & 15);
    } else {
        acc = (acc - anchor_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000658_5813_21(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000658_5813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_54) & 63;
    acc ^= aux;
    int metric_59 = (aux + st.buffer[1]) & 3;
    switch (metric_59) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000658_0;
    int sec_r000658_1;
    int sec_r000658_2;
    int sec_r000658_3;
    int sec_r000658_4;
    int sec_r000658_5;
    int sec_r000658_6;
    int sec_r000658_7;
    int sec_r000658_8;
    int sec_r000658_9;
    int sec_r000658_10;
    int sec_r000658_11;
    int sec_r000658_12;
    int sec_r000658_13;
    int sec_r000658_14;
    int sec_r000658_15;
    int sec_r000658_16;
    int sec_r000658_17;
    int pub_r000658_0;
    int pub_r000658_1;
    int pub_r000658_2;
    int pub_r000658_3;
    int pub_r000658_4;
    int pub_r000658_5;
    int pub_r000658_6;
    int pub_r000658_7;
    int pub_r000658_8;
    int pub_r000658_9;
    int pub_r000658_10;
    int pub_r000658_11;
    int pub_r000658_12;
    int pub_r000658_13;
    int pub_r000658_14;
    int pub_r000658_15;
    int pub_r000658_16;
    int pub_r000658_17;
    int pub_r000658_18;
    int pub_r000658_19;
    int pub_r000658_20;
    int pub_r000658_21;
    int pub_r000658_22;
    int pub_r000658_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000658_0 >= -100 && pub_r000658_0 <= 100);
    __CPROVER_assume(pub_r000658_1 >= -100 && pub_r000658_1 <= 100);
    __CPROVER_assume(pub_r000658_2 >= -100 && pub_r000658_2 <= 100);
    __CPROVER_assume(pub_r000658_3 >= -100 && pub_r000658_3 <= 100);
    __CPROVER_assume(pub_r000658_4 >= -100 && pub_r000658_4 <= 100);
    __CPROVER_assume(pub_r000658_5 >= -100 && pub_r000658_5 <= 100);
    __CPROVER_assume(pub_r000658_6 >= -100 && pub_r000658_6 <= 100);
    __CPROVER_assume(pub_r000658_7 >= -100 && pub_r000658_7 <= 100);
    __CPROVER_assume(pub_r000658_8 >= -100 && pub_r000658_8 <= 100);
    __CPROVER_assume(pub_r000658_9 >= -100 && pub_r000658_9 <= 100);
    __CPROVER_assume(pub_r000658_10 >= -100 && pub_r000658_10 <= 100);
    __CPROVER_assume(pub_r000658_11 >= -100 && pub_r000658_11 <= 100);
    __CPROVER_assume(pub_r000658_12 >= -100 && pub_r000658_12 <= 100);
    __CPROVER_assume(pub_r000658_13 >= -100 && pub_r000658_13 <= 100);
    __CPROVER_assume(pub_r000658_14 >= -100 && pub_r000658_14 <= 100);
    __CPROVER_assume(pub_r000658_15 >= -100 && pub_r000658_15 <= 100);
    __CPROVER_assume(pub_r000658_16 >= -100 && pub_r000658_16 <= 100);
    __CPROVER_assume(pub_r000658_17 >= -100 && pub_r000658_17 <= 100);
    __CPROVER_assume(pub_r000658_18 >= -100 && pub_r000658_18 <= 100);
    __CPROVER_assume(pub_r000658_19 >= -100 && pub_r000658_19 <= 100);
    __CPROVER_assume(pub_r000658_20 >= -100 && pub_r000658_20 <= 100);
    __CPROVER_assume(pub_r000658_21 >= -100 && pub_r000658_21 <= 100);
    __CPROVER_assume(pub_r000658_22 >= -100 && pub_r000658_22 <= 100);
    __CPROVER_assume(pub_r000658_23 >= -100 && pub_r000658_23 <= 100);
    __CPROVER_assume(sec_r000658_0 >= 0 && sec_r000658_0 <= 255);
    __CPROVER_assume(sec_r000658_1 >= 0 && sec_r000658_1 <= 255);
    __CPROVER_assume(sec_r000658_2 >= 0 && sec_r000658_2 <= 255);
    __CPROVER_assume(sec_r000658_3 >= 0 && sec_r000658_3 <= 255);
    __CPROVER_assume(sec_r000658_4 >= 0 && sec_r000658_4 <= 255);
    __CPROVER_assume(sec_r000658_5 >= 0 && sec_r000658_5 <= 255);
    __CPROVER_assume(sec_r000658_6 >= 0 && sec_r000658_6 <= 255);
    __CPROVER_assume(sec_r000658_7 >= 0 && sec_r000658_7 <= 255);
    __CPROVER_assume(sec_r000658_8 >= 0 && sec_r000658_8 <= 255);
    __CPROVER_assume(sec_r000658_9 >= 0 && sec_r000658_9 <= 255);
    __CPROVER_assume(sec_r000658_10 >= 0 && sec_r000658_10 <= 255);
    __CPROVER_assume(sec_r000658_11 >= 0 && sec_r000658_11 <= 255);
    __CPROVER_assume(sec_r000658_12 >= 0 && sec_r000658_12 <= 255);
    __CPROVER_assume(sec_r000658_13 >= 0 && sec_r000658_13 <= 255);
    __CPROVER_assume(sec_r000658_14 >= 0 && sec_r000658_14 <= 255);
    __CPROVER_assume(sec_r000658_15 >= 0 && sec_r000658_15 <= 255);
    __CPROVER_assume(sec_r000658_16 >= 0 && sec_r000658_16 <= 255);
    __CPROVER_assume(sec_r000658_17 >= 0 && sec_r000658_17 <= 255);

    struct Vector3D_R000658_5813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000658_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000658_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000658_0 + 7) & 15;
    struct DeviceConfig_R000658_5813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000658_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000658_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000658_0 + 9) & 15;
    struct FilterState_R000658_5813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000658_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000658_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000658_0 + 11) & 15;

    union TelemetryField_R000658_5813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
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
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 22) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 37) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 26) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 41) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 17) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 32) {
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
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 11) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 26) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 34) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 49) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_35 = (stage_v_35 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_35) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_7 & 1) == step) {
            stage_v_43 = (stage_v_43 + step * 4 + pub_r000658_20) & 63;
        } else {
            stage_v_43 = (stage_v_43 + pub_r000658_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_44 = (stage_v_44 + step * 4 + pub_r000658_21) & 63;
        } else {
            stage_v_44 = (stage_v_44 + pub_r000658_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_45 = (stage_v_45 + step * 4 + pub_r000658_6) & 63;
        } else {
            stage_v_45 = (stage_v_45 + pub_r000658_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_46 = (stage_v_46 + step * 4 + pub_r000658_10) & 63;
        } else {
            stage_v_46 = (stage_v_46 + pub_r000658_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_16 & 1) == step) {
            stage_v_47 = (stage_v_47 + step * 4 + pub_r000658_7) & 63;
        } else {
            stage_v_47 = (stage_v_47 + pub_r000658_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_48 = (stage_v_48 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_48 = (stage_v_48 + pub_r000658_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_7 & 1) == step) {
            stage_v_49 = (stage_v_49 + step * 4 + pub_r000658_8) & 63;
        } else {
            stage_v_49 = (stage_v_49 + pub_r000658_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_2 & 1) == step) {
            stage_v_50 = (stage_v_50 + step * 4 + pub_r000658_9) & 63;
        } else {
            stage_v_50 = (stage_v_50 + pub_r000658_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_51 = (stage_v_51 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_51 = (stage_v_51 + pub_r000658_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_9 & 1) == step) {
            stage_v_52 = (stage_v_52 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_52 = (stage_v_52 + pub_r000658_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_2 & 1) == step) {
            stage_v_53 = (stage_v_53 + step * 4 + pub_r000658_0) & 63;
        } else {
            stage_v_53 = (stage_v_53 + pub_r000658_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_4 & 1) == step) {
            stage_v_54 = (stage_v_54 + step * 4 + pub_r000658_10) & 63;
        } else {
            stage_v_54 = (stage_v_54 + pub_r000658_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_14 & 1) == step) {
            stage_v_55 = (stage_v_55 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_55 = (stage_v_55 + pub_r000658_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_56 = (stage_v_56 + step * 4 + pub_r000658_16) & 63;
        } else {
            stage_v_56 = (stage_v_56 + pub_r000658_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_9 & 1) == step) {
            stage_v_57 = (stage_v_57 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_57 = (stage_v_57 + pub_r000658_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_57) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_43 & 1) == step) {
            stage_v_58 = (stage_v_58 + step * 4 + pub_r000658_2) & 63;
        } else {
            stage_v_58 = (stage_v_58 + pub_r000658_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_58) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_59 = (stage_v_59 + step * 4 + pub_r000658_0) & 63;
        } else {
            stage_v_59 = (stage_v_59 + pub_r000658_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_60 = (stage_v_60 + step * 4 + pub_r000658_20) & 63;
        } else {
            stage_v_60 = (stage_v_60 + pub_r000658_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_17 & 1) == step) {
            stage_v_61 = (stage_v_61 + step * 4 + pub_r000658_18) & 63;
        } else {
            stage_v_61 = (stage_v_61 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_62 = (stage_v_62 + step * 4 + pub_r000658_1) & 63;
        } else {
            stage_v_62 = (stage_v_62 + pub_r000658_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_62) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_61 & 1) == step) {
            stage_v_63 = (stage_v_63 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_63 = (stage_v_63 + pub_r000658_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_64 = (stage_v_64 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_64 = (stage_v_64 + pub_r000658_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_65 = (stage_v_65 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_65 = (stage_v_65 + pub_r000658_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_57 & 1) == step) {
            stage_v_66 = (stage_v_66 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_66 = (stage_v_66 + pub_r000658_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_67 = (stage_v_67 + step * 4 + pub_r000658_4) & 63;
        } else {
            stage_v_67 = (stage_v_67 + pub_r000658_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_53 & 1) == step) {
            stage_v_68 = (stage_v_68 + step * 4 + pub_r000658_21) & 63;
        } else {
            stage_v_68 = (stage_v_68 + pub_r000658_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_67 & 1) == step) {
            stage_v_69 = (stage_v_69 + step * 4 + pub_r000658_5) & 63;
        } else {
            stage_v_69 = (stage_v_69 + pub_r000658_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_70 = (stage_v_70 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_70 = (stage_v_70 + pub_r000658_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_51 & 1) == step) {
            stage_v_71 = (stage_v_71 + step * 4 + pub_r000658_4) & 63;
        } else {
            stage_v_71 = (stage_v_71 + pub_r000658_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_58 & 1) == step) {
            stage_v_72 = (stage_v_72 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_72 = (stage_v_72 + pub_r000658_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_15 & 1) == step) {
            stage_v_73 = (stage_v_73 + step * 4 + pub_r000658_21) & 63;
        } else {
            stage_v_73 = (stage_v_73 + pub_r000658_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_74 = (stage_v_74 + step * 4 + pub_r000658_10) & 63;
        } else {
            stage_v_74 = (stage_v_74 + pub_r000658_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_75 = (stage_v_75 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_75 = (stage_v_75 + pub_r000658_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_76 = (stage_v_76 + step * 4 + pub_r000658_14) & 63;
        } else {
            stage_v_76 = (stage_v_76 + pub_r000658_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_7 & 1) == step) {
            stage_v_77 = (stage_v_77 + step * 4 + pub_r000658_7) & 63;
        } else {
            stage_v_77 = (stage_v_77 + pub_r000658_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_55 & 1) == step) {
            stage_v_78 = (stage_v_78 + step * 4 + pub_r000658_10) & 63;
        } else {
            stage_v_78 = (stage_v_78 + pub_r000658_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_6 & 1) == step) {
            stage_v_79 = (stage_v_79 + step * 4 + pub_r000658_1) & 63;
        } else {
            stage_v_79 = (stage_v_79 + pub_r000658_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_80 = (stage_v_80 + step * 4 + pub_r000658_4) & 63;
        } else {
            stage_v_80 = (stage_v_80 + pub_r000658_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_4 & 1) == step) {
            stage_v_81 = (stage_v_81 + step * 4 + pub_r000658_7) & 63;
        } else {
            stage_v_81 = (stage_v_81 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_9 & 1) == step) {
            stage_v_82 = (stage_v_82 + step * 4 + pub_r000658_2) & 63;
        } else {
            stage_v_82 = (stage_v_82 + pub_r000658_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_17 & 1) == step) {
            stage_v_83 = (stage_v_83 + step * 4 + pub_r000658_7) & 63;
        } else {
            stage_v_83 = (stage_v_83 + pub_r000658_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_84 = (stage_v_84 + step * 4 + pub_r000658_1) & 63;
        } else {
            stage_v_84 = (stage_v_84 + pub_r000658_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_85 = (stage_v_85 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_85 = (stage_v_85 + pub_r000658_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000658_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_9 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000658_23) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000658_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_73 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000658_5) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000658_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_49 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000658_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_62 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000658_0) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000658_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_16 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000658_16) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000658_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000658_21) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000658_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_75 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000658_1) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000658_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_46 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000658_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_14 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000658_14) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000658_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_45 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000658_22) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000658_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_13 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000658_16) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000658_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_71 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000658_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_10 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000658_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_77 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000658_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000658_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_16 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000658_5) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000658_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_13 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000658_6) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000658_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_74 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000658_18) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000658_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_13 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000658_9) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000658_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000658_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_99 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000658_23) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000658_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000658_14) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000658_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_1 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000658_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_10 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000658_21) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000658_4) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000658_1) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000658_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_60 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000658_8) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000658_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_10 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000658_2) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000658_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_7 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000658_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000658_5) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000658_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_56 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000658_9) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000658_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_14 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000658_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_5 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000658_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000658_19) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000658_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_6 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000658_0) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000658_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_11 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000658_12) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_3 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000658_5) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000658_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_5 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000658_22) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000658_9) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000658_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_8 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000658_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000658_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000658_21) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000658_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_12 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000658_11) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000658_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000658_8) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000658_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_15 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000658_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_72 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000658_7) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000658_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_14 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000658_5) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000658_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_47 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000658_20) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000658_9 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_17 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000658_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_54 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000658_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_48 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000658_9) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000658_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_17 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000658_22) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000658_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_131 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000658_19) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000658_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_6 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000658_7) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000658_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_12 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000658_15) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000658_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000658_22) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000658_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_44 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000658_11) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000658_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000658_9 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000658_3) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000658_23 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_76 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000658_0) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000658_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_69 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000658_11) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000658_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_50 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000658_17) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000658_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000658_13) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000658_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_145 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000658_9) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000658_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000658_20) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000658_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
