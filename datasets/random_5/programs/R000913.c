/*
 * Benchmark Program: R000913
 * Security Family: multi_step_explicit
 * Generator Seed: 591313
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000913_1313_0 {
    int iv;
    int round_key;
    int counter;
    int buffer[3];
};

struct Vector3D_R000913_1313_1 {
    int coord_y;
    int heading;
    short coord_z;
    unsigned char coord_x;
    unsigned char norm_sq;
    int buffer[3];
};

union TelemetryField_R000913_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000913_1313_0(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_96 = (aux + st.buffer[1]) & 3;
    switch (tally_96) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_81 = local_arr[aux % 3];
    acc = (acc + bound_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_1(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_21) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_12 = local_arr[aux % 3];
    acc = (acc + tracker_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_31 = (aux + st.buffer[1]) & 3;
    switch (quotient_31) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_87 = local_arr[aux % 3];
    acc = (acc + parity_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_3(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_69 = (aux + st.buffer[1]) & 3;
    switch (residue_69) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_33) & 63;
    acc ^= aux;
    int weight_26 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_26 > 13) {
        acc = (acc + weight_26 * 2 + 5) & 127;
        aux ^= (weight_26 & 15);
    } else {
        acc = (acc - weight_26 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int accumulator_42 = (aux + st.buffer[1]) & 3;
    switch (accumulator_42) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_26 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_26 > 44) {
        acc = (acc + factor_26 * 2 + 5) & 127;
        aux ^= (factor_26 & 15);
    } else {
        acc = (acc - factor_26 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000913_1313_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000913_1313_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int weight_95 = (aux + st.buffer[1]) & 3;
    switch (weight_95) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000913_1313_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int accumulator_65 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_65 > 43) {
        acc = (acc + accumulator_65 * 2 + 5) & 127;
        aux ^= (accumulator_65 & 15);
    } else {
        acc = (acc - accumulator_65 + 11) & 127;
        aux += 3;
    }
    int quantum_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_49) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_52 = local_arr[aux % 3];
    acc = (acc + residue_52 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tracker_41 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_41 > 25) {
        acc = (acc + tracker_41 * 2 + 5) & 127;
        aux ^= (tracker_41 & 15);
    } else {
        acc = (acc - tracker_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_63) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000913_1313_9(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_63 = (aux + st.buffer[1]) & 3;
    switch (segment_63) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000913_1313_10(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_28) & 63;
    acc ^= aux;
    int offset_88 = (aux + st.buffer[1]) & 3;
    switch (offset_88) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int coefficient_65 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_65 > 17) {
        acc = (acc + coefficient_65 * 2 + 5) & 127;
        aux ^= (coefficient_65 & 15);
    } else {
        acc = (acc - coefficient_65 + 11) & 127;
        aux += 3;
    }
    int segment_74 = (aux + st.buffer[1]) & 3;
    switch (segment_74) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000913_1313_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int parity_20 = local_arr[aux % 3];
    acc = (acc + parity_20 * 2) & 127;
    int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_50) & 63;
    acc ^= aux;
    int quantum_96 = (aux + st.buffer[1]) & 3;
    switch (quantum_96) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000913_1313_13(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_94 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_94 > 45) {
        acc = (acc + margin_94 * 2 + 5) & 127;
        aux ^= (margin_94 & 15);
    } else {
        acc = (acc - margin_94 + 11) & 127;
        aux += 3;
    }
    int checksum_10 = (aux + st.buffer[1]) & 3;
    switch (checksum_10) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_15(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_30 = (aux + st.buffer[1]) & 3;
    switch (quantum_30) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int coefficient_29 = local_arr[aux % 3];
    acc = (acc + coefficient_29 * 2) & 127;
    int pivot_76 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_76 > 42) {
        acc = (acc + pivot_76 * 2 + 5) & 127;
        aux ^= (pivot_76 & 15);
    } else {
        acc = (acc - pivot_76 + 11) & 127;
        aux += 3;
    }
    int metric_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_26) & 63;
    acc ^= aux;
    int cursor_29 = (aux + st.buffer[1]) & 3;
    switch (cursor_29) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000913_1313_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int coefficient_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_50) & 63;
    acc ^= aux;
    int scale_15 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_15 > 10) {
        acc = (acc + scale_15 * 2 + 5) & 127;
        aux ^= (scale_15 & 15);
    } else {
        acc = (acc - scale_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000913_1313_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000913_1313_19(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int stride_76 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_76 > 49) {
        acc = (acc + stride_76 * 2 + 5) & 127;
        aux ^= (stride_76 & 15);
    } else {
        acc = (acc - stride_76 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_32 = local_arr[aux % 3];
    acc = (acc + delta_32 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000913_1313_20(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000913_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int metric_22 = local_arr[aux % 3];
    acc = (acc + metric_22 * 2) & 127;
    int threshold_58 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_58) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000913_1313_21(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000913_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tally_65 = (aux + st.buffer[1]) & 3;
    switch (tally_65) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_34) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000913_0;
    int sec_r000913_1;
    int sec_r000913_2;
    int sec_r000913_3;
    int sec_r000913_4;
    int sec_r000913_5;
    int sec_r000913_6;
    int sec_r000913_7;
    int sec_r000913_8;
    int sec_r000913_9;
    int sec_r000913_10;
    int sec_r000913_11;
    int sec_r000913_12;
    int sec_r000913_13;
    int sec_r000913_14;
    int sec_r000913_15;
    int sec_r000913_16;
    int pub_r000913_0;
    int pub_r000913_1;
    int pub_r000913_2;
    int pub_r000913_3;
    int pub_r000913_4;
    int pub_r000913_5;
    int pub_r000913_6;
    int pub_r000913_7;
    int pub_r000913_8;
    int pub_r000913_9;
    int pub_r000913_10;
    int pub_r000913_11;
    int pub_r000913_12;
    int pub_r000913_13;
    int pub_r000913_14;
    int pub_r000913_15;
    int pub_r000913_16;
    int pub_r000913_17;
    int pub_r000913_18;
    int pub_r000913_19;
    int pub_r000913_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000913_0 >= -100 && pub_r000913_0 <= 100);
    __CPROVER_assume(pub_r000913_1 >= -100 && pub_r000913_1 <= 100);
    __CPROVER_assume(pub_r000913_2 >= -100 && pub_r000913_2 <= 100);
    __CPROVER_assume(pub_r000913_3 >= -100 && pub_r000913_3 <= 100);
    __CPROVER_assume(pub_r000913_4 >= -100 && pub_r000913_4 <= 100);
    __CPROVER_assume(pub_r000913_5 >= -100 && pub_r000913_5 <= 100);
    __CPROVER_assume(pub_r000913_6 >= -100 && pub_r000913_6 <= 100);
    __CPROVER_assume(pub_r000913_7 >= -100 && pub_r000913_7 <= 100);
    __CPROVER_assume(pub_r000913_8 >= -100 && pub_r000913_8 <= 100);
    __CPROVER_assume(pub_r000913_9 >= -100 && pub_r000913_9 <= 100);
    __CPROVER_assume(pub_r000913_10 >= -100 && pub_r000913_10 <= 100);
    __CPROVER_assume(pub_r000913_11 >= -100 && pub_r000913_11 <= 100);
    __CPROVER_assume(pub_r000913_12 >= -100 && pub_r000913_12 <= 100);
    __CPROVER_assume(pub_r000913_13 >= -100 && pub_r000913_13 <= 100);
    __CPROVER_assume(pub_r000913_14 >= -100 && pub_r000913_14 <= 100);
    __CPROVER_assume(pub_r000913_15 >= -100 && pub_r000913_15 <= 100);
    __CPROVER_assume(pub_r000913_16 >= -100 && pub_r000913_16 <= 100);
    __CPROVER_assume(pub_r000913_17 >= -100 && pub_r000913_17 <= 100);
    __CPROVER_assume(pub_r000913_18 >= -100 && pub_r000913_18 <= 100);
    __CPROVER_assume(pub_r000913_19 >= -100 && pub_r000913_19 <= 100);
    __CPROVER_assume(pub_r000913_20 >= -100 && pub_r000913_20 <= 100);
    __CPROVER_assume(sec_r000913_0 >= 0 && sec_r000913_0 <= 255);
    __CPROVER_assume(sec_r000913_1 >= 0 && sec_r000913_1 <= 255);
    __CPROVER_assume(sec_r000913_2 >= 0 && sec_r000913_2 <= 255);
    __CPROVER_assume(sec_r000913_3 >= 0 && sec_r000913_3 <= 255);
    __CPROVER_assume(sec_r000913_4 >= 0 && sec_r000913_4 <= 255);
    __CPROVER_assume(sec_r000913_5 >= 0 && sec_r000913_5 <= 255);
    __CPROVER_assume(sec_r000913_6 >= 0 && sec_r000913_6 <= 255);
    __CPROVER_assume(sec_r000913_7 >= 0 && sec_r000913_7 <= 255);
    __CPROVER_assume(sec_r000913_8 >= 0 && sec_r000913_8 <= 255);
    __CPROVER_assume(sec_r000913_9 >= 0 && sec_r000913_9 <= 255);
    __CPROVER_assume(sec_r000913_10 >= 0 && sec_r000913_10 <= 255);
    __CPROVER_assume(sec_r000913_11 >= 0 && sec_r000913_11 <= 255);
    __CPROVER_assume(sec_r000913_12 >= 0 && sec_r000913_12 <= 255);
    __CPROVER_assume(sec_r000913_13 >= 0 && sec_r000913_13 <= 255);
    __CPROVER_assume(sec_r000913_14 >= 0 && sec_r000913_14 <= 255);
    __CPROVER_assume(sec_r000913_15 >= 0 && sec_r000913_15 <= 255);
    __CPROVER_assume(sec_r000913_16 >= 0 && sec_r000913_16 <= 255);

    struct CipherContext_R000913_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000913_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000913_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000913_0 + 7) & 15;
    struct Vector3D_R000913_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000913_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000913_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000913_0 + 9) & 15;

    union TelemetryField_R000913_1313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_0 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 36) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 51) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 21) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 36) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = table[0];
    table[0] = (table[1] + 33) & 63;
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 24) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 39) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (out_sink > 100) ? (chk_sum & 31) : (25 & 31);
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= (stage_v_20 << 1) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
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
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 19) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 34) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 34) & 15;
    int stage_v_33 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= stage_v_33;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (out_sink > 100) ? (chk_sum & 31) : (40 & 31);
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= (stage_v_35 << 1) & 127;

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
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_1.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 49) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 51) & 15;
    int stage_v_50 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= stage_v_50;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 37) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 52) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

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
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 13) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 28) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 34) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 49) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 34) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 49) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 30) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 45) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 19) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 34) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 26) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 41) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (out_sink > 100) ? (chk_sum & 31) : (94 & 31);
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= (stage_v_89 << 1) & 127;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sec_r000913_4 + pub_r000913_20 + 29) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000913_8) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000913_2 + pub_r000913_0 + 18) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000913_15) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (stage_v_90 + pub_r000913_10 + 19) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000913_5) & 127;
    st_var_0.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sub_step_91 + pub_r000913_10 + 31) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000913_14) & 127;
    st_var_1.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (stage_v_91 + pub_r000913_19 + 13) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000913_4) & 127;
    st_var_0.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (stage_v_93 + pub_r000913_20 + 9) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000913_14) & 127;
    st_var_1.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (stage_v_90 + pub_r000913_1 + 11) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (stage_v_91 + pub_r000913_0 + 11) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000913_4) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (stage_v_95 + pub_r000913_3 + 18) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000913_20) & 127;
    st_var_0.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sec_r000913_15 + pub_r000913_17 + 35) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000913_9) & 127;
    st_var_1.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (stage_v_92 + pub_r000913_17 + 10) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000913_12) & 127;
    st_var_0.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sec_r000913_16 + pub_r000913_15 + 16) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (sub_step_97 + pub_r000913_19 + 16) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000913_15) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sub_step_97 + pub_r000913_4 + 20) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000913_2) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (sec_r000913_4 + pub_r000913_11 + 14) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000913_2) & 127;
    st_var_0.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sub_step_100 + pub_r000913_19 + 5) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (sub_step_92 + pub_r000913_5 + 6) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000913_8) & 127;
    st_var_0.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (sec_r000913_14 + pub_r000913_8 + 17) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000913_5) & 127;
    st_var_1.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (sub_step_97 + pub_r000913_2 + 10) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000913_4) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sec_r000913_15 + pub_r000913_0 + 30) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000913_15) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (stage_v_105 + pub_r000913_20 + 17) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000913_18) & 127;
    st_var_0.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (stage_v_98 + pub_r000913_10 + 31) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (stage_v_99 + pub_r000913_5 + 13) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000913_0) & 127;
    st_var_0.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (stage_v_105 + pub_r000913_1 + 9) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000913_15) & 127;
    st_var_1.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (stage_v_94 + pub_r000913_2 + 26) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (sec_r000913_3 + pub_r000913_4 + 12) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000913_15) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (stage_v_98 + pub_r000913_10 + 13) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000913_9) & 127;
    st_var_0.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (stage_v_100 + pub_r000913_10 + 12) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sec_r000913_15 + pub_r000913_12 + 7) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000913_18) & 127;
    st_var_0.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sub_step_101 + pub_r000913_10 + 11) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sub_step_115 + pub_r000913_14 + 9) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000913_8) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (stage_v_99 + pub_r000913_7 + 11) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000913_13) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000913_7 + pub_r000913_10 + 8) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sub_step_90 + pub_r000913_9 + 29) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000913_10) & 127;
    st_var_1.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sub_step_96 + pub_r000913_4 + 11) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000913_18) & 127;
    st_var_0.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sec_r000913_2 + pub_r000913_17 + 20) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000913_11) & 127;
    st_var_1.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_101 + pub_r000913_12 + 23) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000913_20) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sub_step_121 + pub_r000913_14 + 17) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000913_9) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_103 + pub_r000913_17 + 32) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sec_r000913_9 + pub_r000913_18 + 7) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000913_16) & 127;
    st_var_1.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (sub_step_124 + pub_r000913_15 + 21) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000913_17) & 127;
    st_var_0.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sec_r000913_11 + pub_r000913_18 + 10) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000913_15) & 127;
    st_var_1.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (stage_v_93 + pub_r000913_12 + 17) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000913_19) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (stage_v_123 + pub_r000913_11 + 18) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000913_17) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sub_step_104 + pub_r000913_10 + 35) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (sec_r000913_3 + pub_r000913_19 + 33) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000913_0) & 127;
    st_var_1.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sub_step_118 + pub_r000913_15 + 13) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (stage_v_101 + pub_r000913_12 + 29) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sub_step_122 + pub_r000913_4 + 9) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (sec_r000913_0 + pub_r000913_1 + 29) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (stage_v_117 + pub_r000913_3 + 10) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000913_5) & 127;
    st_var_0.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (sub_step_106 + pub_r000913_6 + 16) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000913_7) & 127;
    st_var_1.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sub_step_127 + pub_r000913_16 + 14) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (sec_r000913_10 + pub_r000913_3 + 13) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000913_8) & 127;
    st_var_1.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (sub_step_97 + pub_r000913_8 + 31) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000913_2) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (stage_v_142 + pub_r000913_3 + 11) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000913_10) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sub_step_137 + pub_r000913_10 + 31) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000913_8) & 127;
    st_var_0.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sub_step_99 + pub_r000913_1 + 31) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000913_20) & 127;
    st_var_1.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000913_6 + pub_r000913_19 + 32) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000913_20) & 127;
    st_var_0.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (sub_step_142 + pub_r000913_0 + 35) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000913_4) & 127;
    st_var_1.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (stage_v_99 + pub_r000913_6 + 16) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000913_14) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sub_step_116 + pub_r000913_13 + 30) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000913_13) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sec_r000913_0 + pub_r000913_0 + 26) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000913_14) & 127;
    st_var_0.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (stage_v_123 + pub_r000913_8 + 28) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000913_4) & 127;
    st_var_1.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (stage_v_90 + pub_r000913_17 + 30) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000913_9) & 127;
    st_var_0.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sec_r000913_8 + pub_r000913_5 + 28) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000913_11) & 127;
    st_var_1.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000913_0 + pub_r000913_12 + 13) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000913_0) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sub_step_105 + pub_r000913_11 + 29) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000913_12) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (sec_r000913_4 + pub_r000913_4 + 18) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000913_17) & 127;
    st_var_0.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sec_r000913_15 + pub_r000913_17 + 26) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000913_5) & 127;
    st_var_1.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (sub_step_110 + pub_r000913_3 + 16) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000913_15) & 127;
    st_var_0.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sec_r000913_16 + pub_r000913_10 + 9) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000913_13) & 127;
    st_var_1.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sec_r000913_2 + pub_r000913_7 + 8) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (sub_step_132 + pub_r000913_12 + 31) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (stage_v_99 + pub_r000913_18 + 20) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000913_16) & 127;
    st_var_0.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (sub_step_103 + pub_r000913_20 + 28) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000913_15) & 127;
    st_var_1.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (stage_v_131 + pub_r000913_18 + 24) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000913_7) & 127;
    st_var_0.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sec_r000913_10 + pub_r000913_10 + 26) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000913_8) & 127;
    st_var_1.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (stage_v_98 + pub_r000913_16 + 11) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000913_14) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sec_r000913_15 + pub_r000913_2 + 17) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000913_2) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sec_r000913_3 + pub_r000913_3 + 14) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000913_16) & 127;
    st_var_0.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sec_r000913_15 + pub_r000913_6 + 18) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000913_10) & 127;
    st_var_1.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sub_step_136 + pub_r000913_11 + 24) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000913_16) & 127;
    st_var_0.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sec_r000913_13 + pub_r000913_3 + 35) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000913_7) & 127;
    st_var_1.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (sec_r000913_15 + pub_r000913_10 + 25) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000913_1) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (stage_v_130 + pub_r000913_8 + 5) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000913_2) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sec_r000913_0 + pub_r000913_3 + 34) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000913_16) & 127;
    st_var_0.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sub_step_111 + pub_r000913_6 + 14) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000913_0) & 127;
    st_var_1.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (stage_v_126 + pub_r000913_7 + 13) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000913_19) & 127;
    st_var_0.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sec_r000913_10 + pub_r000913_16 + 18) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000913_20) & 127;
    st_var_1.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sec_r000913_8 + pub_r000913_16 + 34) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000913_5) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sec_r000913_13 + pub_r000913_0 + 11) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000913_5) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sub_step_178 + pub_r000913_5 + 17) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000913_12) & 127;
    st_var_0.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sec_r000913_5 + pub_r000913_17 + 10) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000913_17) & 127;
    st_var_1.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sub_step_112 + pub_r000913_13 + 21) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000913_20) & 127;
    st_var_0.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (stage_v_127 + pub_r000913_1 + 5) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000913_20) & 127;
    st_var_1.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sec_r000913_3 + pub_r000913_10 + 32) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000913_20) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (stage_v_178 + pub_r000913_3 + 26) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000913_5) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sub_step_159 + pub_r000913_18 + 17) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000913_4) & 127;
    st_var_0.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (stage_v_148 + pub_r000913_3 + 20) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sub_step_110 + pub_r000913_9 + 24) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000913_0) & 127;
    st_var_0.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_118 + pub_r000913_4 + 9) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000913_13) & 127;
    st_var_1.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sec_r000913_11 + pub_r000913_10 + 28) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000913_7) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sec_r000913_12 + pub_r000913_17 + 6) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000913_1) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_166 + pub_r000913_9 + 24) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000913_6) & 127;
    st_var_0.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sub_step_185 + pub_r000913_6 + 31) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000913_19) & 127;
    st_var_1.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (stage_v_181 + pub_r000913_0 + 29) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000913_7) & 127;
    st_var_0.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (sub_step_136 + pub_r000913_7 + 21) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000913_13) & 127;
    st_var_1.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (sub_step_166 + pub_r000913_12 + 17) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000913_6) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (sub_step_117 + pub_r000913_17 + 35) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000913_4) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sub_step_123 + pub_r000913_18 + 10) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sec_r000913_5 + pub_r000913_13 + 17) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (stage_v_157 + pub_r000913_11 + 35) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sec_r000913_3 + pub_r000913_18 + 29) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000913_14) & 127;
    st_var_1.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (stage_v_113 + pub_r000913_6 + 21) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sec_r000913_4 + pub_r000913_9 + 18) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000913_2) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sec_r000913_16 + pub_r000913_1 + 33) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (stage_v_163 + pub_r000913_1 + 24) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000913_19) & 127;
    st_var_1.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (stage_v_105 + pub_r000913_14 + 31) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000913_4) & 127;
    st_var_0.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sub_step_182 + pub_r000913_9 + 32) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000913_17) & 127;
    st_var_1.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (sec_r000913_12 + pub_r000913_13 + 5) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000913_17) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000913_1 + pub_r000913_1 + 6) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000913_0) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sub_step_123 + pub_r000913_18 + 15) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000913_0) & 127;
    st_var_0.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (stage_v_151 + pub_r000913_16 + 5) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000913_12) & 127;
    st_var_1.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (stage_v_193 + pub_r000913_9 + 5) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000913_9) & 127;
    st_var_0.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_91 + pub_r000913_8 + 11) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000913_10) & 127;
    st_var_1.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sec_r000913_15 + pub_r000913_6 + 34) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000913_2) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sub_step_213 + pub_r000913_11 + 16) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000913_18) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (sub_step_113 + pub_r000913_1 + 28) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000913_5) & 127;
    st_var_0.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sec_r000913_7 + pub_r000913_17 + 35) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (sec_r000913_5 + pub_r000913_2 + 18) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000913_3) & 127;
    st_var_0.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (stage_v_213 + pub_r000913_12 + 15) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000913_14) & 127;
    st_var_1.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sec_r000913_1 + pub_r000913_9 + 32) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000913_16) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sec_r000913_16 + pub_r000913_17 + 30) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sub_step_223 + pub_r000913_8 + 26) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000913_13) & 127;
    st_var_0.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_128 + pub_r000913_14 + 24) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000913_1) & 127;
    st_var_1.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (sec_r000913_4 + pub_r000913_12 + 28) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000913_9) & 127;
    st_var_0.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sec_r000913_15 + pub_r000913_18 + 27) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000913_6) & 127;
    st_var_1.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (sub_step_95 + pub_r000913_10 + 13) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000913_9) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (stage_v_204 + pub_r000913_9 + 21) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sec_r000913_7 + pub_r000913_19 + 7) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000913_4) & 127;
    st_var_0.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (stage_v_141 + pub_r000913_17 + 26) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000913_4) & 127;
    st_var_1.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (sub_step_93 + pub_r000913_12 + 23) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000913_7) & 127;
    st_var_0.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sec_r000913_2 + pub_r000913_20 + 30) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000913_10) & 127;
    st_var_1.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sec_r000913_13 + pub_r000913_8 + 20) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000913_5) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sec_r000913_0 + pub_r000913_6 + 34) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000913_0) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (stage_v_171 + pub_r000913_17 + 16) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000913_10) & 127;
    st_var_0.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (stage_v_233 + pub_r000913_5 + 28) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000913_3) & 127;
    st_var_1.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (stage_v_93 + pub_r000913_5 + 23) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000913_0) & 127;
    st_var_0.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sub_step_167 + pub_r000913_9 + 7) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000913_18) & 127;
    st_var_1.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sec_r000913_4 + pub_r000913_19 + 25) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000913_16) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sub_step_119 + pub_r000913_8 + 35) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000913_10) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sec_r000913_11 + pub_r000913_19 + 12) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000913_4) & 127;
    st_var_0.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sec_r000913_14 + pub_r000913_9 + 32) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000913_13) & 127;
    st_var_1.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (stage_v_177 + pub_r000913_12 + 23) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000913_5) & 127;
    st_var_0.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sec_r000913_8 + pub_r000913_0 + 31) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000913_1) & 127;
    st_var_1.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (stage_v_143 + pub_r000913_12 + 30) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000913_3) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (sec_r000913_13 + pub_r000913_20 + 6) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000913_20) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
