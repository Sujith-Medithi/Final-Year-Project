/*
 * Benchmark Program: R000637
 * Security Family: nested_implicit_flow
 * Generator Seed: 563713
 * High Inputs: 19 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000637_3713_0 {
    int round_key;
    int nonce;
    int flags;
    short iv;
    int tag;
    unsigned char counter;
    int buffer[3];
};

struct DeviceConfig_R000637_3713_1 {
    int stop_bits;
    unsigned char parity;
    int baud_rate;
    int buffer[3];
};

struct Vector3D_R000637_3713_2 {
    unsigned char coord_z;
    int heading;
    int coord_x;
    int pitch;
    int coord_y;
    int buffer[3];
};

union TelemetryField_R000637_3713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000637_3713_0(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int weight_76 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_76 > 47) {
        acc = (acc + weight_76 * 2 + 5) & 127;
        aux ^= (weight_76 & 15);
    } else {
        acc = (acc - weight_76 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_89 = local_arr[aux % 3];
    acc = (acc + vector_89 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_45 = (aux + st.buffer[1]) & 3;
    switch (checksum_45) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int offset_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_50 = local_arr[aux % 3];
    acc = (acc + factor_50 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int local_arr[3] = {4, 9, 15};
    int pivot_81 = local_arr[aux % 3];
    acc = (acc + pivot_81 * 2) & 127;
    int damping_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_19) & 63;
    acc ^= aux;
    int tally_11 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_11 > 17) {
        acc = (acc + tally_11 * 2 + 5) & 127;
        aux ^= (tally_11 & 15);
    } else {
        acc = (acc - tally_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_82 = local_arr[aux % 3];
    acc = (acc + weight_82 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int scale_42 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_42 > 30) {
        acc = (acc + scale_42 * 2 + 5) & 127;
        aux ^= (scale_42 & 15);
    } else {
        acc = (acc - scale_42 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_48 = local_arr[aux % 3];
    acc = (acc + accumulator_48 * 2) & 127;
    int bound_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_20) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_78 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_78 > 40) {
        acc = (acc + checksum_78 * 2 + 5) & 127;
        aux ^= (checksum_78 & 15);
    } else {
        acc = (acc - checksum_78 + 11) & 127;
        aux += 3;
    }
    int pivot_15 = (aux + st.buffer[1]) & 3;
    switch (pivot_15) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000637_3713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000637_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int bound_86 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_86) & 63;
    acc ^= aux;
    int pivot_84 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_84 > 18) {
        acc = (acc + pivot_84 * 2 + 5) & 127;
        aux ^= (pivot_84 & 15);
    } else {
        acc = (acc - pivot_84 + 11) & 127;
        aux += 3;
    }
    int weight_16 = (aux + st.buffer[1]) & 3;
    switch (weight_16) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_36 = local_arr[aux % 3];
    acc = (acc + phase_36 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_7(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_26 = (aux + st.buffer[1]) & 3;
    switch (vector_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_38) & 63;
    acc ^= aux;
    int factor_15 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_15 > 19) {
        acc = (acc + factor_15 * 2 + 5) & 127;
        aux ^= (factor_15 & 15);
    } else {
        acc = (acc - factor_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int parity_12 = local_arr[aux % 3];
    acc = (acc + parity_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_72 = (aux + st.buffer[1]) & 3;
    switch (quotient_72) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000637_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int parity_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_99) & 63;
    acc ^= aux;
    int delta_93 = (aux + st.buffer[1]) & 3;
    switch (delta_93) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_47 = local_arr[aux % 3];
    acc = (acc + coefficient_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_10(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int phase_68 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_68 > 23) {
        acc = (acc + phase_68 * 2 + 5) & 127;
        aux ^= (phase_68 & 15);
    } else {
        acc = (acc - phase_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_68 = (aux + st.buffer[1]) & 3;
    switch (tracker_68) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tally_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_29) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_12(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000637_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int checksum_63 = (aux + st.buffer[1]) & 3;
    switch (checksum_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_94) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000637_3713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int weight_65 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_65 > 14) {
        acc = (acc + weight_65 * 2 + 5) & 127;
        aux ^= (weight_65 & 15);
    } else {
        acc = (acc - weight_65 + 11) & 127;
        aux += 3;
    }
    int metric_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_31) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_72 = local_arr[aux % 3];
    acc = (acc + threshold_72 * 2) & 127;
    int segment_25 = (aux + st.buffer[1]) & 3;
    switch (segment_25) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int bound_31 = (aux + st.buffer[1]) & 3;
    switch (bound_31) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_44 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_44 > 41) {
        acc = (acc + parity_44 * 2 + 5) & 127;
        aux ^= (parity_44 & 15);
    } else {
        acc = (acc - parity_44 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_15(int p0, int p1, int p2) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int damping_25 = (aux + st.buffer[1]) & 3;
    switch (damping_25) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_39 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_39 > 37) {
        acc = (acc + checksum_39 * 2 + 5) & 127;
        aux ^= (checksum_39 & 15);
    } else {
        acc = (acc - checksum_39 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_16(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int offset_69 = (aux + st.buffer[1]) & 3;
    switch (offset_69) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_55 = local_arr[aux % 3];
    acc = (acc + accumulator_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000637_3713_17(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000637_3713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int cursor_46 = (aux + st.buffer[1]) & 3;
    switch (cursor_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_96 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_96 > 38) {
        acc = (acc + tracker_96 * 2 + 5) & 127;
        aux ^= (tracker_96 & 15);
    } else {
        acc = (acc - tracker_96 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000637_3713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000637_3713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int phase_14 = local_arr[aux % 3];
    acc = (acc + phase_14 * 2) & 127;
    int tally_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_52) & 63;
    acc ^= aux;
    int offset_58 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_58 > 46) {
        acc = (acc + offset_58 * 2 + 5) & 127;
        aux ^= (offset_58 & 15);
    } else {
        acc = (acc - offset_58 + 11) & 127;
        aux += 3;
    }
    int offset_25 = (aux + st.buffer[1]) & 3;
    switch (offset_25) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000637_3713_19(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000637_3713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int threshold_17 = (aux + st.buffer[1]) & 3;
    switch (threshold_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_83 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_83 > 15) {
        acc = (acc + residue_83 * 2 + 5) & 127;
        aux ^= (residue_83 & 15);
    } else {
        acc = (acc - residue_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000637_0;
    int sec_r000637_1;
    int sec_r000637_2;
    int sec_r000637_3;
    int sec_r000637_4;
    int sec_r000637_5;
    int sec_r000637_6;
    int sec_r000637_7;
    int sec_r000637_8;
    int sec_r000637_9;
    int sec_r000637_10;
    int sec_r000637_11;
    int sec_r000637_12;
    int sec_r000637_13;
    int sec_r000637_14;
    int sec_r000637_15;
    int sec_r000637_16;
    int sec_r000637_17;
    int sec_r000637_18;
    int pub_r000637_0;
    int pub_r000637_1;
    int pub_r000637_2;
    int pub_r000637_3;
    int pub_r000637_4;
    int pub_r000637_5;
    int pub_r000637_6;
    int pub_r000637_7;
    int pub_r000637_8;
    int pub_r000637_9;
    int pub_r000637_10;
    int pub_r000637_11;
    int pub_r000637_12;
    int pub_r000637_13;
    int pub_r000637_14;
    int pub_r000637_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000637_0 >= -100 && pub_r000637_0 <= 100);
    __CPROVER_assume(pub_r000637_1 >= -100 && pub_r000637_1 <= 100);
    __CPROVER_assume(pub_r000637_2 >= -100 && pub_r000637_2 <= 100);
    __CPROVER_assume(pub_r000637_3 >= -100 && pub_r000637_3 <= 100);
    __CPROVER_assume(pub_r000637_4 >= -100 && pub_r000637_4 <= 100);
    __CPROVER_assume(pub_r000637_5 >= -100 && pub_r000637_5 <= 100);
    __CPROVER_assume(pub_r000637_6 >= -100 && pub_r000637_6 <= 100);
    __CPROVER_assume(pub_r000637_7 >= -100 && pub_r000637_7 <= 100);
    __CPROVER_assume(pub_r000637_8 >= -100 && pub_r000637_8 <= 100);
    __CPROVER_assume(pub_r000637_9 >= -100 && pub_r000637_9 <= 100);
    __CPROVER_assume(pub_r000637_10 >= -100 && pub_r000637_10 <= 100);
    __CPROVER_assume(pub_r000637_11 >= -100 && pub_r000637_11 <= 100);
    __CPROVER_assume(pub_r000637_12 >= -100 && pub_r000637_12 <= 100);
    __CPROVER_assume(pub_r000637_13 >= -100 && pub_r000637_13 <= 100);
    __CPROVER_assume(pub_r000637_14 >= -100 && pub_r000637_14 <= 100);
    __CPROVER_assume(pub_r000637_15 >= -100 && pub_r000637_15 <= 100);
    __CPROVER_assume(sec_r000637_0 >= 0 && sec_r000637_0 <= 255);
    __CPROVER_assume(sec_r000637_1 >= 0 && sec_r000637_1 <= 255);
    __CPROVER_assume(sec_r000637_2 >= 0 && sec_r000637_2 <= 255);
    __CPROVER_assume(sec_r000637_3 >= 0 && sec_r000637_3 <= 255);
    __CPROVER_assume(sec_r000637_4 >= 0 && sec_r000637_4 <= 255);
    __CPROVER_assume(sec_r000637_5 >= 0 && sec_r000637_5 <= 255);
    __CPROVER_assume(sec_r000637_6 >= 0 && sec_r000637_6 <= 255);
    __CPROVER_assume(sec_r000637_7 >= 0 && sec_r000637_7 <= 255);
    __CPROVER_assume(sec_r000637_8 >= 0 && sec_r000637_8 <= 255);
    __CPROVER_assume(sec_r000637_9 >= 0 && sec_r000637_9 <= 255);
    __CPROVER_assume(sec_r000637_10 >= 0 && sec_r000637_10 <= 255);
    __CPROVER_assume(sec_r000637_11 >= 0 && sec_r000637_11 <= 255);
    __CPROVER_assume(sec_r000637_12 >= 0 && sec_r000637_12 <= 255);
    __CPROVER_assume(sec_r000637_13 >= 0 && sec_r000637_13 <= 255);
    __CPROVER_assume(sec_r000637_14 >= 0 && sec_r000637_14 <= 255);
    __CPROVER_assume(sec_r000637_15 >= 0 && sec_r000637_15 <= 255);
    __CPROVER_assume(sec_r000637_16 >= 0 && sec_r000637_16 <= 255);
    __CPROVER_assume(sec_r000637_17 >= 0 && sec_r000637_17 <= 255);
    __CPROVER_assume(sec_r000637_18 >= 0 && sec_r000637_18 <= 255);

    struct CipherContext_R000637_3713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000637_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000637_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000637_0 + 7) & 15;
    struct DeviceConfig_R000637_3713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000637_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000637_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000637_0 + 9) & 15;
    struct Vector3D_R000637_3713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000637_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000637_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000637_0 + 11) & 15;

    union TelemetryField_R000637_3713_0 u_var;
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
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 19) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 34) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 38) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 53) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 30) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 45) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

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
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (out_sink > 100) ? (chk_sum & 31) : (30 & 31);
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= (stage_v_25 << 1) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
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
    int stage_v_28 = (st_var_1.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

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
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_37 = (stage_v_37 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_37) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 15) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 30) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[0] ^ 46) & 3;
    switch (stage_v_43) {
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

    /* Execution Pipeline Stage 44 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 45) & 15;
    int stage_v_44 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= stage_v_44;

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_2.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 50) & 15;
    int stage_v_49 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= stage_v_49;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 38) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 53) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 21) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 36) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 28) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 43) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 17) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 32) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 36) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 51) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (out_sink > 100) ? (chk_sum & 31) : (65 & 31);
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= (stage_v_60 << 1) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_2.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 36) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 51) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000637_14 & 1) != 0) {
        if ((sec_r000637_1 & 2) != 0) {
            stage_v_74 = (pub_r000637_1 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000637_1 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000637_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000637_8 & 1) != 0) {
        if ((sec_r000637_10 & 2) != 0) {
            stage_v_75 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000637_6 & 2) != 0) {
            stage_v_76 = (pub_r000637_4 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000637_4 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000637_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000637_15 & 2) != 0) {
            stage_v_77 = (pub_r000637_0 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000637_0 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000637_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000637_13 & 1) != 0) {
        if ((sec_r000637_5 & 2) != 0) {
            stage_v_78 = (pub_r000637_10 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000637_10 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000637_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000637_9 & 2) != 0) {
            stage_v_79 = (pub_r000637_10 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000637_10 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000637_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000637_2 & 2) != 0) {
            stage_v_80 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000637_1 & 2) != 0) {
            stage_v_81 = (pub_r000637_4 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000637_4 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000637_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000637_11 & 1) != 0) {
        if ((sec_r000637_2 & 2) != 0) {
            stage_v_82 = (pub_r000637_0 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000637_0 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000637_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000637_8 & 2) != 0) {
            stage_v_83 = (pub_r000637_12 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000637_12 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000637_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000637_17 & 2) != 0) {
            stage_v_84 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000637_9 & 2) != 0) {
            stage_v_85 = (pub_r000637_1 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000637_1 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000637_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000637_13 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_86 = (pub_r000637_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000637_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000637_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000637_0 & 1) != 0) {
        if ((sec_r000637_10 & 2) != 0) {
            stage_v_87 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000637_8 & 1) != 0) {
        if ((sec_r000637_4 & 2) != 0) {
            stage_v_88 = (pub_r000637_14 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000637_14 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000637_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000637_3 & 2) != 0) {
            stage_v_89 = (pub_r000637_8 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000637_8 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000637_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000637_4 & 2) != 0) {
            stage_v_90 = (pub_r000637_10 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000637_10 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000637_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000637_15 & 2) != 0) {
            stage_v_91 = (pub_r000637_11 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000637_11 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000637_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000637_9 & 2) != 0) {
            stage_v_92 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000637_5 & 1) != 0) {
        if ((sec_r000637_7 & 2) != 0) {
            stage_v_93 = (pub_r000637_1 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000637_1 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000637_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_94 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000637_10 & 1) != 0) {
        if ((sec_r000637_8 & 2) != 0) {
            stage_v_95 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000637_7 & 1) != 0) {
        if ((sec_r000637_4 & 2) != 0) {
            stage_v_96 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000637_11 & 2) != 0) {
            stage_v_97 = (pub_r000637_2 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000637_2 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000637_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000637_15 & 1) != 0) {
        if ((sec_r000637_1 & 2) != 0) {
            stage_v_98 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000637_6 & 2) != 0) {
            stage_v_99 = (pub_r000637_12 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000637_12 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000637_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000637_0 & 2) != 0) {
            stage_v_100 = (pub_r000637_10 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000637_10 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000637_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000637_9 & 1) != 0) {
        if ((sec_r000637_12 & 2) != 0) {
            stage_v_101 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000637_18 & 2) != 0) {
            stage_v_102 = (pub_r000637_8 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000637_8 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000637_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000637_2 & 1) != 0) {
        if ((sec_r000637_9 & 2) != 0) {
            stage_v_103 = (pub_r000637_7 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000637_7 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000637_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000637_0 & 2) != 0) {
            stage_v_104 = (pub_r000637_13 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000637_13 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000637_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000637_1 & 2) != 0) {
            stage_v_105 = (pub_r000637_12 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000637_12 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000637_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000637_11 & 2) != 0) {
            stage_v_106 = (pub_r000637_9 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000637_9 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000637_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_107 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000637_17 & 1) != 0) {
        if ((sec_r000637_2 & 2) != 0) {
            stage_v_108 = (pub_r000637_12 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000637_12 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000637_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000637_18 & 2) != 0) {
            stage_v_109 = (pub_r000637_8 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000637_8 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000637_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000637_3 & 1) != 0) {
        if ((sec_r000637_6 & 2) != 0) {
            stage_v_110 = (pub_r000637_9 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000637_9 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000637_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000637_11 & 2) != 0) {
            stage_v_111 = (pub_r000637_8 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000637_8 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000637_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000637_1 & 1) != 0) {
        if ((sec_r000637_17 & 2) != 0) {
            stage_v_112 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_77 & 1) != 0) {
        if ((sec_r000637_15 & 2) != 0) {
            stage_v_113 = (pub_r000637_1 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000637_1 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000637_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000637_6 & 2) != 0) {
            stage_v_114 = (pub_r000637_13 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000637_13 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000637_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_109 & 1) != 0) {
        if ((sec_r000637_6 & 2) != 0) {
            stage_v_115 = (pub_r000637_12 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000637_12 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000637_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000637_16 & 1) != 0) {
        if ((sec_r000637_0 & 2) != 0) {
            stage_v_116 = (pub_r000637_0 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000637_0 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000637_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000637_7 & 1) != 0) {
        if ((sec_r000637_8 & 2) != 0) {
            stage_v_117 = (pub_r000637_10 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000637_10 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000637_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000637_18 & 1) != 0) {
        if ((sec_r000637_13 & 2) != 0) {
            stage_v_118 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000637_8 & 1) != 0) {
        if ((sec_r000637_3 & 2) != 0) {
            stage_v_119 = (pub_r000637_14 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000637_14 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000637_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_120 = (pub_r000637_13 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000637_13 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000637_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000637_2 & 2) != 0) {
            stage_v_121 = (pub_r000637_15 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000637_15 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000637_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000637_15 & 2) != 0) {
            stage_v_122 = (pub_r000637_7 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000637_7 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000637_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((sec_r000637_2 & 1) != 0) {
        if ((sec_r000637_2 & 2) != 0) {
            stage_v_123 = (pub_r000637_14 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000637_14 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000637_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000637_3 & 1) != 0) {
        if ((sec_r000637_1 & 2) != 0) {
            stage_v_124 = (pub_r000637_1 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000637_1 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000637_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000637_10 & 1) != 0) {
        if ((sec_r000637_9 & 2) != 0) {
            stage_v_125 = (pub_r000637_7 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000637_7 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000637_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000637_18 & 2) != 0) {
            stage_v_126 = (pub_r000637_11 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000637_11 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000637_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_127 = (pub_r000637_14 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000637_14 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000637_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000637_13 & 1) != 0) {
        if ((sec_r000637_0 & 2) != 0) {
            stage_v_128 = (pub_r000637_9 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000637_9 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000637_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000637_4 & 2) != 0) {
            stage_v_129 = (pub_r000637_13 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000637_13 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000637_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_130 = (pub_r000637_4 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000637_4 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000637_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_123 & 1) != 0) {
        if ((sec_r000637_8 & 2) != 0) {
            stage_v_131 = (pub_r000637_3 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000637_3 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000637_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_120 & 1) != 0) {
        if ((sec_r000637_11 & 2) != 0) {
            stage_v_132 = (pub_r000637_10 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000637_10 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000637_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000637_11 & 1) != 0) {
        if ((sec_r000637_16 & 2) != 0) {
            stage_v_133 = (pub_r000637_13 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000637_13 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000637_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000637_18 & 2) != 0) {
            stage_v_134 = (pub_r000637_4 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000637_4 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000637_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000637_17 & 2) != 0) {
            stage_v_135 = (pub_r000637_4 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000637_4 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000637_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000637_10 & 2) != 0) {
            stage_v_136 = (pub_r000637_3 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000637_3 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000637_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000637_5 & 1) != 0) {
        if ((sec_r000637_5 & 2) != 0) {
            stage_v_137 = (pub_r000637_5 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000637_5 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000637_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000637_15 & 1) != 0) {
        if ((sec_r000637_15 & 2) != 0) {
            stage_v_138 = (pub_r000637_2 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000637_2 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000637_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000637_13 & 2) != 0) {
            stage_v_139 = (pub_r000637_0 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000637_0 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000637_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000637_5 & 1) != 0) {
        if ((sec_r000637_5 & 2) != 0) {
            stage_v_140 = (pub_r000637_3 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000637_3 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000637_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000637_15 & 2) != 0) {
            stage_v_141 = (pub_r000637_12 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000637_12 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000637_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000637_8 & 1) != 0) {
        if ((sec_r000637_13 & 2) != 0) {
            stage_v_142 = (pub_r000637_6 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000637_6 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000637_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000637_0 & 1) != 0) {
        if ((sec_r000637_7 & 2) != 0) {
            stage_v_143 = (pub_r000637_13 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000637_13 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000637_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
