/*
 * Benchmark Program: R000982
 * Security Family: direct_leakage
 * Generator Seed: 598213
 * High Inputs: 18 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000982_8213_0 {
    short signature;
    unsigned char facility;
    int timestamp;
    int buffer[3];
};

struct Vector3D_R000982_8213_1 {
    int norm_sq;
    unsigned char coord_y;
    unsigned char heading;
    int pitch;
    int coord_x;
    short coord_z;
    int buffer[3];
};

union TelemetryField_R000982_8213_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000982_8213_0(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int phase_89 = (aux + st.buffer[1]) & 3;
    switch (phase_89) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000982_8213_1(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int damping_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_23) & 63;
    acc ^= aux;
    int accumulator_33 = (aux + st.buffer[1]) & 3;
    switch (accumulator_33) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_30 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_30 > 26) {
        acc = (acc + mask_30 * 2 + 5) & 127;
        aux ^= (mask_30 & 15);
    } else {
        acc = (acc - mask_30 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_2(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int offset_32 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_32 > 45) {
        acc = (acc + offset_32 * 2 + 5) & 127;
        aux ^= (offset_32 & 15);
    } else {
        acc = (acc - offset_32 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_58 = local_arr[aux % 3];
    acc = (acc + metric_58 * 2) & 127;
    int phase_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_70) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000982_8213_3(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_77) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_60 = local_arr[aux % 3];
    acc = (acc + sample_60 * 2) & 127;
    int margin_46 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_46 > 48) {
        acc = (acc + margin_46 * 2 + 5) & 127;
        aux ^= (margin_46 & 15);
    } else {
        acc = (acc - margin_46 + 11) & 127;
        aux += 3;
    }
    int parity_81 = (aux + st.buffer[1]) & 3;
    switch (parity_81) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int cursor_50 = local_arr[aux % 3];
    acc = (acc + cursor_50 * 2) & 127;
    int margin_69 = (aux + st.buffer[1]) & 3;
    switch (margin_69) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_81) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000982_8213_5(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_46 = (aux + st.buffer[1]) & 3;
    switch (delta_46) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int bound_87 = (aux + st.buffer[1]) & 3;
    switch (bound_87) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_37) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000982_8213_7(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int offset_54 = local_arr[aux % 3];
    acc = (acc + offset_54 * 2) & 127;
    int margin_86 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_86 > 37) {
        acc = (acc + margin_86 * 2 + 5) & 127;
        aux ^= (margin_86 & 15);
    } else {
        acc = (acc - margin_86 + 11) & 127;
        aux += 3;
    }
    int stride_84 = (aux + st.buffer[1]) & 3;
    switch (stride_84) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_24) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000982_8213_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int bound_53 = (aux + st.buffer[1]) & 3;
    switch (bound_53) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_70 = local_arr[aux % 3];
    acc = (acc + margin_70 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_80 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_80 > 21) {
        acc = (acc + vector_80 * 2 + 5) & 127;
        aux ^= (vector_80 & 15);
    } else {
        acc = (acc - vector_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int coefficient_20 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_20 > 28) {
        acc = (acc + coefficient_20 * 2 + 5) & 127;
        aux ^= (coefficient_20 & 15);
    } else {
        acc = (acc - coefficient_20 + 11) & 127;
        aux += 3;
    }
    int phase_86 = (aux + st.buffer[1]) & 3;
    switch (phase_86) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_35 = local_arr[aux % 3];
    acc = (acc + pivot_35 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000982_8213_10(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_26 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_26 > 28) {
        acc = (acc + tally_26 * 2 + 5) & 127;
        aux ^= (tally_26 & 15);
    } else {
        acc = (acc - tally_26 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_44 = local_arr[aux % 3];
    acc = (acc + cursor_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000982_8213_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_67 = (aux + st.buffer[1]) & 3;
    switch (tracker_67) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_37 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_37 > 22) {
        acc = (acc + index_reg_37 * 2 + 5) & 127;
        aux ^= (index_reg_37 & 15);
    } else {
        acc = (acc - index_reg_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_12(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int stride_62 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_62 > 20) {
        acc = (acc + stride_62 * 2 + 5) & 127;
        aux ^= (stride_62 & 15);
    } else {
        acc = (acc - stride_62 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_26 = local_arr[aux % 3];
    acc = (acc + stride_26 * 2) & 127;
    int scale_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000982_8213_13(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int factor_56 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_56 > 39) {
        acc = (acc + factor_56 * 2 + 5) & 127;
        aux ^= (factor_56 & 15);
    } else {
        acc = (acc - factor_56 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_52 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_52) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000982_8213_14(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int weight_37 = (aux + st.buffer[1]) & 3;
    switch (weight_37) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_22 = local_arr[aux % 3];
    acc = (acc + sample_22 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000982_8213_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_78 = (aux + st.buffer[1]) & 3;
    switch (accumulator_78) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int coefficient_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_74) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_80 = local_arr[aux % 3];
    acc = (acc + stride_80 * 2) & 127;
    int checksum_34 = (aux + st.buffer[1]) & 3;
    switch (checksum_34) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_17(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int residue_19 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_19 > 26) {
        acc = (acc + residue_19 * 2 + 5) & 127;
        aux ^= (residue_19 & 15);
    } else {
        acc = (acc - residue_19 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_27 = local_arr[aux % 3];
    acc = (acc + cursor_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000982_8213_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000982_8213_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int sample_30 = (aux + st.buffer[1]) & 3;
    switch (sample_30) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_19(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int scale_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_10) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_14 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_14 > 43) {
        acc = (acc + factor_14 * 2 + 5) & 127;
        aux ^= (factor_14 & 15);
    } else {
        acc = (acc - factor_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000982_8213_20(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_49 = local_arr[aux % 3];
    acc = (acc + tally_49 * 2) & 127;
    int vector_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000982_8213_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000982_8213_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_36 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_36 > 13) {
        acc = (acc + vector_36 * 2 + 5) & 127;
        aux ^= (vector_36 & 15);
    } else {
        acc = (acc - vector_36 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_74 = local_arr[aux % 3];
    acc = (acc + checksum_74 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000982_0;
    int sec_r000982_1;
    int sec_r000982_2;
    int sec_r000982_3;
    int sec_r000982_4;
    int sec_r000982_5;
    int sec_r000982_6;
    int sec_r000982_7;
    int sec_r000982_8;
    int sec_r000982_9;
    int sec_r000982_10;
    int sec_r000982_11;
    int sec_r000982_12;
    int sec_r000982_13;
    int sec_r000982_14;
    int sec_r000982_15;
    int sec_r000982_16;
    int sec_r000982_17;
    int pub_r000982_0;
    int pub_r000982_1;
    int pub_r000982_2;
    int pub_r000982_3;
    int pub_r000982_4;
    int pub_r000982_5;
    int pub_r000982_6;
    int pub_r000982_7;
    int pub_r000982_8;
    int pub_r000982_9;
    int pub_r000982_10;
    int pub_r000982_11;
    int pub_r000982_12;
    int pub_r000982_13;
    int pub_r000982_14;
    int pub_r000982_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000982_0 >= -100 && pub_r000982_0 <= 100);
    __CPROVER_assume(pub_r000982_1 >= -100 && pub_r000982_1 <= 100);
    __CPROVER_assume(pub_r000982_2 >= -100 && pub_r000982_2 <= 100);
    __CPROVER_assume(pub_r000982_3 >= -100 && pub_r000982_3 <= 100);
    __CPROVER_assume(pub_r000982_4 >= -100 && pub_r000982_4 <= 100);
    __CPROVER_assume(pub_r000982_5 >= -100 && pub_r000982_5 <= 100);
    __CPROVER_assume(pub_r000982_6 >= -100 && pub_r000982_6 <= 100);
    __CPROVER_assume(pub_r000982_7 >= -100 && pub_r000982_7 <= 100);
    __CPROVER_assume(pub_r000982_8 >= -100 && pub_r000982_8 <= 100);
    __CPROVER_assume(pub_r000982_9 >= -100 && pub_r000982_9 <= 100);
    __CPROVER_assume(pub_r000982_10 >= -100 && pub_r000982_10 <= 100);
    __CPROVER_assume(pub_r000982_11 >= -100 && pub_r000982_11 <= 100);
    __CPROVER_assume(pub_r000982_12 >= -100 && pub_r000982_12 <= 100);
    __CPROVER_assume(pub_r000982_13 >= -100 && pub_r000982_13 <= 100);
    __CPROVER_assume(pub_r000982_14 >= -100 && pub_r000982_14 <= 100);
    __CPROVER_assume(pub_r000982_15 >= -100 && pub_r000982_15 <= 100);
    __CPROVER_assume(sec_r000982_0 >= 0 && sec_r000982_0 <= 255);
    __CPROVER_assume(sec_r000982_1 >= 0 && sec_r000982_1 <= 255);
    __CPROVER_assume(sec_r000982_2 >= 0 && sec_r000982_2 <= 255);
    __CPROVER_assume(sec_r000982_3 >= 0 && sec_r000982_3 <= 255);
    __CPROVER_assume(sec_r000982_4 >= 0 && sec_r000982_4 <= 255);
    __CPROVER_assume(sec_r000982_5 >= 0 && sec_r000982_5 <= 255);
    __CPROVER_assume(sec_r000982_6 >= 0 && sec_r000982_6 <= 255);
    __CPROVER_assume(sec_r000982_7 >= 0 && sec_r000982_7 <= 255);
    __CPROVER_assume(sec_r000982_8 >= 0 && sec_r000982_8 <= 255);
    __CPROVER_assume(sec_r000982_9 >= 0 && sec_r000982_9 <= 255);
    __CPROVER_assume(sec_r000982_10 >= 0 && sec_r000982_10 <= 255);
    __CPROVER_assume(sec_r000982_11 >= 0 && sec_r000982_11 <= 255);
    __CPROVER_assume(sec_r000982_12 >= 0 && sec_r000982_12 <= 255);
    __CPROVER_assume(sec_r000982_13 >= 0 && sec_r000982_13 <= 255);
    __CPROVER_assume(sec_r000982_14 >= 0 && sec_r000982_14 <= 255);
    __CPROVER_assume(sec_r000982_15 >= 0 && sec_r000982_15 <= 255);
    __CPROVER_assume(sec_r000982_16 >= 0 && sec_r000982_16 <= 255);
    __CPROVER_assume(sec_r000982_17 >= 0 && sec_r000982_17 <= 255);

    struct EventLog_R000982_8213_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000982_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000982_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000982_0 + 7) & 15;
    struct Vector3D_R000982_8213_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000982_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000982_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000982_0 + 9) & 15;

    union TelemetryField_R000982_8213_0 u_var;
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
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 10) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 25) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_12 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 36) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 51) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (out_sink > 100) ? (chk_sum & 31) : (22 & 31);
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= (stage_v_17 << 1) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_23 = (stage_v_23 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_23) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 12) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 27) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
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
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 18) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 33) {
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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 11) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 26) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 17) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 32) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r000982_8 + pub_r000982_15 + 13) & 127;
    sec_accum = (sec_accum + stage_v_46) & 255;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_46 + pub_r000982_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_47) & 255;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_46 + pub_r000982_6 + 41) & 127;
    sec_accum = (sec_accum + stage_v_48) & 255;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_46 + pub_r000982_7 + 30) & 127;
    sec_accum = (sec_accum + stage_v_49) & 255;
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_46 + pub_r000982_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_50) & 255;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_46 + pub_r000982_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_51) & 255;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r000982_13 + pub_r000982_7 + 46) & 127;
    sec_accum = (sec_accum + stage_v_52) & 255;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (sec_r000982_4 + pub_r000982_14 + 45) & 127;
    sec_accum = (sec_accum + stage_v_53) & 255;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r000982_3 + pub_r000982_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_54) & 255;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r000982_7 + pub_r000982_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_55) & 255;
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_54 + pub_r000982_7 + 3) & 127;
    sec_accum = (sec_accum + stage_v_56) & 255;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r000982_15 + pub_r000982_11 + 27) & 127;
    sec_accum = (sec_accum + stage_v_57) & 255;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_54 + pub_r000982_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_58) & 255;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (sec_r000982_17 + pub_r000982_10 + 33) & 127;
    sec_accum = (sec_accum + stage_v_59) & 255;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_48 + pub_r000982_14 + 20) & 127;
    sec_accum = (sec_accum + stage_v_60) & 255;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_50 + pub_r000982_9 + 16) & 127;
    sec_accum = (sec_accum + stage_v_61) & 255;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_53 + pub_r000982_6 + 23) & 127;
    sec_accum = (sec_accum + stage_v_62) & 255;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_51 + pub_r000982_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_63) & 255;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_61 + pub_r000982_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_64) & 255;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (sec_r000982_15 + pub_r000982_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_65) & 255;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_62 + pub_r000982_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_66) & 255;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (sec_r000982_1 + pub_r000982_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_67) & 255;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (sec_r000982_14 + pub_r000982_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_68) & 255;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (sec_r000982_14 + pub_r000982_14 + 6) & 127;
    sec_accum = (sec_accum + stage_v_69) & 255;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (sec_r000982_9 + pub_r000982_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_70) & 255;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_46 + pub_r000982_11 + 14) & 127;
    sec_accum = (sec_accum + stage_v_71) & 255;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (sec_r000982_2 + pub_r000982_15 + 4) & 127;
    sec_accum = (sec_accum + stage_v_72) & 255;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_46 + pub_r000982_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_73) & 255;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_61 + pub_r000982_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_74) & 255;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r000982_2 + pub_r000982_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_75) & 255;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (stage_v_69 + pub_r000982_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_76) & 255;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_58 + pub_r000982_12 + 28) & 127;
    sec_accum = (sec_accum + stage_v_77) & 255;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r000982_11 + pub_r000982_11 + 21) & 127;
    sec_accum = (sec_accum + stage_v_78) & 255;
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_62 + pub_r000982_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_79) & 255;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_50 + pub_r000982_15 + 37) & 127;
    sec_accum = (sec_accum + stage_v_80) & 255;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_66 + pub_r000982_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_81) & 255;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_58 + pub_r000982_7 + 29) & 127;
    sec_accum = (sec_accum + stage_v_82) & 255;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_71 + pub_r000982_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_83) & 255;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r000982_3 + pub_r000982_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_84) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_82 + pub_r000982_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_85) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_78 + pub_r000982_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_86) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r000982_2 + pub_r000982_3 + 25) & 127;
    sec_accum = (sec_accum + stage_v_87) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_73 + pub_r000982_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_88) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r000982_15 + pub_r000982_2 + 35) & 127;
    sec_accum = (sec_accum + stage_v_89) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (sec_r000982_15 + pub_r000982_5 + 45) & 127;
    sec_accum = (sec_accum + stage_v_90) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_78 + pub_r000982_5 + 19) & 127;
    sec_accum = (sec_accum + stage_v_91) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (sec_r000982_12 + pub_r000982_5 + 12) & 127;
    sec_accum = (sec_accum + stage_v_92) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_60 + pub_r000982_9 + 17) & 127;
    sec_accum = (sec_accum + stage_v_93) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r000982_14 + pub_r000982_15 + 22) & 127;
    sec_accum = (sec_accum + stage_v_94) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (sec_r000982_7 + pub_r000982_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_95) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_64 + pub_r000982_5 + 13) & 127;
    sec_accum = (sec_accum + stage_v_96) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_50 + pub_r000982_10 + 28) & 127;
    sec_accum = (sec_accum + stage_v_97) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_55 + pub_r000982_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_98) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_47 + pub_r000982_10 + 3) & 127;
    sec_accum = (sec_accum + stage_v_99) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_95 + pub_r000982_10 + 24) & 127;
    sec_accum = (sec_accum + stage_v_100) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_96 + pub_r000982_4 + 47) & 127;
    sec_accum = (sec_accum + stage_v_101) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (sec_r000982_9 + pub_r000982_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_102) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_62 + pub_r000982_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_103) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_93 + pub_r000982_6 + 35) & 127;
    sec_accum = (sec_accum + stage_v_104) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_93 + pub_r000982_8 + 34) & 127;
    sec_accum = (sec_accum + stage_v_105) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_67 + pub_r000982_6 + 12) & 127;
    sec_accum = (sec_accum + stage_v_106) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_96 + pub_r000982_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_107) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_90 + pub_r000982_10 + 31) & 127;
    sec_accum = (sec_accum + stage_v_108) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_107 + pub_r000982_9 + 12) & 127;
    sec_accum = (sec_accum + stage_v_109) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_90 + pub_r000982_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_110) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r000982_12 + pub_r000982_13 + 23) & 127;
    sec_accum = (sec_accum + stage_v_111) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_81 + pub_r000982_10 + 19) & 127;
    sec_accum = (sec_accum + stage_v_112) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_87 + pub_r000982_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_113) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r000982_12 + pub_r000982_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_114) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_77 + pub_r000982_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_115) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_84 + pub_r000982_11 + 20) & 127;
    sec_accum = (sec_accum + stage_v_116) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_51 + pub_r000982_1 + 41) & 127;
    sec_accum = (sec_accum + stage_v_117) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (sec_r000982_8 + pub_r000982_1 + 19) & 127;
    sec_accum = (sec_accum + stage_v_118) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r000982_15 + pub_r000982_7 + 43) & 127;
    sec_accum = (sec_accum + stage_v_119) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (sec_r000982_1 + pub_r000982_15 + 20) & 127;
    sec_accum = (sec_accum + stage_v_120) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_50 + pub_r000982_1 + 32) & 127;
    sec_accum = (sec_accum + stage_v_121) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_63 + pub_r000982_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_122) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_90 + pub_r000982_12 + 20) & 127;
    sec_accum = (sec_accum + stage_v_123) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_52 + pub_r000982_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_124) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r000982_9 + pub_r000982_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_125) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_105 + pub_r000982_15 + 38) & 127;
    sec_accum = (sec_accum + stage_v_126) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r000982_7 + pub_r000982_2 + 48) & 127;
    sec_accum = (sec_accum + stage_v_127) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (sec_r000982_13 + pub_r000982_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_128) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_81 + pub_r000982_5 + 33) & 127;
    sec_accum = (sec_accum + stage_v_129) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (sec_r000982_8 + pub_r000982_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_130) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r000982_7 + pub_r000982_4 + 18) & 127;
    sec_accum = (sec_accum + stage_v_131) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_82 + pub_r000982_10 + 45) & 127;
    sec_accum = (sec_accum + stage_v_132) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (sec_r000982_4 + pub_r000982_10 + 29) & 127;
    sec_accum = (sec_accum + stage_v_133) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r000982_2 + pub_r000982_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_134) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r000982_0 + pub_r000982_3 + 33) & 127;
    sec_accum = (sec_accum + stage_v_135) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_56 + pub_r000982_8 + 11) & 127;
    sec_accum = (sec_accum + stage_v_136) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_76 + pub_r000982_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_137) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_92 + pub_r000982_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_138) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_122 + pub_r000982_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_139) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_78 + pub_r000982_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_140) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r000982_15 + pub_r000982_2 + 10) & 127;
    sec_accum = (sec_accum + stage_v_141) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_112 + pub_r000982_9 + 40) & 127;
    sec_accum = (sec_accum + stage_v_142) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_76 + pub_r000982_11 + 26) & 127;
    sec_accum = (sec_accum + stage_v_143) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r000982_4 + pub_r000982_11 + 9) & 127;
    sec_accum = (sec_accum + stage_v_144) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (sec_r000982_2 + pub_r000982_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_145) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_71 + pub_r000982_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_146) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_57 + pub_r000982_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_147) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (sec_r000982_1 + pub_r000982_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_148) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_53 + pub_r000982_11 + 11) & 127;
    sec_accum = (sec_accum + stage_v_149) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (sec_r000982_1 + pub_r000982_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_150) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_150 + pub_r000982_6 + 42) & 127;
    sec_accum = (sec_accum + stage_v_151) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_68 + pub_r000982_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_152) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_152 + pub_r000982_15 + 31) & 127;
    sec_accum = (sec_accum + stage_v_153) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_51 + pub_r000982_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_154) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_62 + pub_r000982_3 + 7) & 127;
    sec_accum = (sec_accum + stage_v_155) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_48 + pub_r000982_14 + 31) & 127;
    sec_accum = (sec_accum + stage_v_156) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_146 + pub_r000982_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_157) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r000982_0 + pub_r000982_13 + 48) & 127;
    sec_accum = (sec_accum + stage_v_158) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (sec_r000982_15 + pub_r000982_1 + 37) & 127;
    sec_accum = (sec_accum + stage_v_159) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_51 + pub_r000982_12 + 30) & 127;
    sec_accum = (sec_accum + stage_v_160) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (sec_r000982_5 + pub_r000982_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_161) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_72 + pub_r000982_5 + 40) & 127;
    sec_accum = (sec_accum + stage_v_162) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_75 + pub_r000982_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_163) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r000982_14 + pub_r000982_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_164) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_91 + pub_r000982_10 + 42) & 127;
    sec_accum = (sec_accum + stage_v_165) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_126 + pub_r000982_15 + 3) & 127;
    sec_accum = (sec_accum + stage_v_166) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (sec_r000982_6 + pub_r000982_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_167) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_46 + pub_r000982_1 + 45) & 127;
    sec_accum = (sec_accum + stage_v_168) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_49 + pub_r000982_8 + 47) & 127;
    sec_accum = (sec_accum + stage_v_169) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_154 + pub_r000982_11 + 5) & 127;
    sec_accum = (sec_accum + stage_v_170) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (sec_r000982_12 + pub_r000982_7 + 8) & 127;
    sec_accum = (sec_accum + stage_v_171) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_66 + pub_r000982_13 + 47) & 127;
    sec_accum = (sec_accum + stage_v_172) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (sec_r000982_7 + pub_r000982_11 + 40) & 127;
    sec_accum = (sec_accum + stage_v_173) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r000982_6 + pub_r000982_5 + 46) & 127;
    sec_accum = (sec_accum + stage_v_174) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_128 + pub_r000982_8 + 38) & 127;
    sec_accum = (sec_accum + stage_v_175) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_106 + pub_r000982_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_176) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_77 + pub_r000982_12 + 23) & 127;
    sec_accum = (sec_accum + stage_v_177) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_48 + pub_r000982_3 + 5) & 127;
    sec_accum = (sec_accum + stage_v_178) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (sec_r000982_2 + pub_r000982_2 + 16) & 127;
    sec_accum = (sec_accum + stage_v_179) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_121 + pub_r000982_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_180) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_112 + pub_r000982_0 + 33) & 127;
    sec_accum = (sec_accum + stage_v_181) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_130 + pub_r000982_2 + 36) & 127;
    sec_accum = (sec_accum + stage_v_182) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_67 + pub_r000982_14 + 34) & 127;
    sec_accum = (sec_accum + stage_v_183) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (sec_r000982_12 + pub_r000982_13 + 25) & 127;
    sec_accum = (sec_accum + stage_v_184) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r000982_14 + pub_r000982_0 + 36) & 127;
    sec_accum = (sec_accum + stage_v_185) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_160 + pub_r000982_9 + 31) & 127;
    sec_accum = (sec_accum + stage_v_186) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_56 + pub_r000982_11 + 34) & 127;
    sec_accum = (sec_accum + stage_v_187) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_171 + pub_r000982_4 + 4) & 127;
    sec_accum = (sec_accum + stage_v_188) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_168 + pub_r000982_3 + 46) & 127;
    sec_accum = (sec_accum + stage_v_189) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_67 + pub_r000982_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_190) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_61 + pub_r000982_14 + 29) & 127;
    sec_accum = (sec_accum + stage_v_191) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_144 + pub_r000982_15 + 42) & 127;
    sec_accum = (sec_accum + stage_v_192) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_128 + pub_r000982_13 + 29) & 127;
    sec_accum = (sec_accum + stage_v_193) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (sec_r000982_10 + pub_r000982_6 + 48) & 127;
    sec_accum = (sec_accum + stage_v_194) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (sec_r000982_15 + pub_r000982_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_195) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_52 + pub_r000982_1 + 41) & 127;
    sec_accum = (sec_accum + stage_v_196) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (sec_r000982_1 + pub_r000982_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_197) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (sec_r000982_2 + pub_r000982_0 + 48) & 127;
    sec_accum = (sec_accum + stage_v_198) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (sec_r000982_15 + pub_r000982_0 + 5) & 127;
    sec_accum = (sec_accum + stage_v_199) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_194 + pub_r000982_7 + 23) & 127;
    sec_accum = (sec_accum + stage_v_200) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (sec_r000982_14 + pub_r000982_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_201) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (sec_r000982_0 + pub_r000982_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_202) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_91 + pub_r000982_5 + 47) & 127;
    sec_accum = (sec_accum + stage_v_203) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (sec_r000982_13 + pub_r000982_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_204) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (sec_r000982_15 + pub_r000982_14 + 8) & 127;
    sec_accum = (sec_accum + stage_v_205) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_59 + pub_r000982_14 + 41) & 127;
    sec_accum = (sec_accum + stage_v_206) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_120 + pub_r000982_14 + 5) & 127;
    sec_accum = (sec_accum + stage_v_207) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_174 + pub_r000982_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_208) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_82 + pub_r000982_4 + 29) & 127;
    sec_accum = (sec_accum + stage_v_209) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_152 + pub_r000982_15 + 36) & 127;
    sec_accum = (sec_accum + stage_v_210) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_120 + pub_r000982_14 + 35) & 127;
    sec_accum = (sec_accum + stage_v_211) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_164 + pub_r000982_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_212) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_150 + pub_r000982_0 + 11) & 127;
    sec_accum = (sec_accum + stage_v_213) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_92 + pub_r000982_11 + 48) & 127;
    sec_accum = (sec_accum + stage_v_214) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_173 + pub_r000982_13 + 14) & 127;
    sec_accum = (sec_accum + stage_v_215) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_134 + pub_r000982_8 + 28) & 127;
    sec_accum = (sec_accum + stage_v_216) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (stage_v_121 + pub_r000982_4 + 47) & 127;
    sec_accum = (sec_accum + stage_v_217) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (sec_r000982_12 + pub_r000982_0 + 34) & 127;
    sec_accum = (sec_accum + stage_v_218) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (stage_v_97 + pub_r000982_15 + 48) & 127;
    sec_accum = (sec_accum + stage_v_219) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (sec_r000982_0 + pub_r000982_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_220) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (sec_r000982_1 + pub_r000982_13 + 46) & 127;
    sec_accum = (sec_accum + stage_v_221) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_53 + pub_r000982_12 + 3) & 127;
    sec_accum = (sec_accum + stage_v_222) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_190 + pub_r000982_4 + 45) & 127;
    sec_accum = (sec_accum + stage_v_223) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_114 + pub_r000982_9 + 46) & 127;
    sec_accum = (sec_accum + stage_v_224) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_77 + pub_r000982_0 + 26) & 127;
    sec_accum = (sec_accum + stage_v_225) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (stage_v_126 + pub_r000982_2 + 32) & 127;
    sec_accum = (sec_accum + stage_v_226) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (sec_r000982_9 + pub_r000982_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_227) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_102 + pub_r000982_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_228) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_49 + pub_r000982_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_229) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (sec_r000982_10 + pub_r000982_8 + 46) & 127;
    sec_accum = (sec_accum + stage_v_230) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (sec_r000982_6 + pub_r000982_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_231) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (sec_r000982_17 + pub_r000982_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_232) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_59 + pub_r000982_4 + 40) & 127;
    sec_accum = (sec_accum + stage_v_233) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (sec_r000982_10 + pub_r000982_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_234) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_63 + pub_r000982_11 + 26) & 127;
    sec_accum = (sec_accum + stage_v_235) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_137 + pub_r000982_9 + 33) & 127;
    sec_accum = (sec_accum + stage_v_236) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (sec_r000982_8 + pub_r000982_6 + 19) & 127;
    sec_accum = (sec_accum + stage_v_237) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (stage_v_178 + pub_r000982_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_238) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (stage_v_135 + pub_r000982_8 + 23) & 127;
    sec_accum = (sec_accum + stage_v_239) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_92 + pub_r000982_14 + 15) & 127;
    sec_accum = (sec_accum + stage_v_240) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_153 + pub_r000982_9 + 34) & 127;
    sec_accum = (sec_accum + stage_v_241) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (sec_r000982_13 + pub_r000982_9 + 32) & 127;
    sec_accum = (sec_accum + stage_v_242) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (stage_v_78 + pub_r000982_13 + 9) & 127;
    sec_accum = (sec_accum + stage_v_243) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (stage_v_176 + pub_r000982_4 + 46) & 127;
    sec_accum = (sec_accum + stage_v_244) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (sec_r000982_13 + pub_r000982_6 + 25) & 127;
    sec_accum = (sec_accum + stage_v_245) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (sec_r000982_1 + pub_r000982_5 + 49) & 127;
    sec_accum = (sec_accum + stage_v_246) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (stage_v_171 + pub_r000982_3 + 21) & 127;
    sec_accum = (sec_accum + stage_v_247) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (stage_v_219 + pub_r000982_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_248) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_218 + pub_r000982_9 + 39) & 127;
    sec_accum = (sec_accum + stage_v_249) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (stage_v_238 + pub_r000982_4 + 43) & 127;
    sec_accum = (sec_accum + stage_v_250) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (sec_r000982_17 + pub_r000982_12 + 44) & 127;
    sec_accum = (sec_accum + stage_v_251) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (sec_r000982_7 + pub_r000982_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_252) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (stage_v_78 + pub_r000982_0 + 49) & 127;
    sec_accum = (sec_accum + stage_v_253) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (sec_r000982_17 + pub_r000982_13 + 38) & 127;
    sec_accum = (sec_accum + stage_v_254) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (sec_r000982_4 + pub_r000982_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_255) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (stage_v_169 + pub_r000982_8 + 25) & 127;
    sec_accum = (sec_accum + stage_v_256) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (stage_v_119 + pub_r000982_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_257) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_66 + pub_r000982_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_258) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (sec_r000982_6 + pub_r000982_10 + 23) & 127;
    sec_accum = (sec_accum + stage_v_259) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (sec_r000982_15 + pub_r000982_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_260) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (sec_r000982_14 + pub_r000982_12 + 43) & 127;
    sec_accum = (sec_accum + stage_v_261) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_208 + pub_r000982_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_262) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (stage_v_117 + pub_r000982_11 + 38) & 127;
    sec_accum = (sec_accum + stage_v_263) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (sec_r000982_5 + pub_r000982_2 + 4) & 127;
    sec_accum = (sec_accum + stage_v_264) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (stage_v_60 + pub_r000982_10 + 9) & 127;
    sec_accum = (sec_accum + stage_v_265) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (stage_v_186 + pub_r000982_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_266) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (stage_v_192 + pub_r000982_6 + 8) & 127;
    sec_accum = (sec_accum + stage_v_267) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (stage_v_219 + pub_r000982_10 + 25) & 127;
    sec_accum = (sec_accum + stage_v_268) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (sec_r000982_13 + pub_r000982_6 + 40) & 127;
    sec_accum = (sec_accum + stage_v_269) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (stage_v_74 + pub_r000982_12 + 32) & 127;
    sec_accum = (sec_accum + stage_v_270) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (sec_r000982_16 + pub_r000982_2 + 17) & 127;
    sec_accum = (sec_accum + stage_v_271) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (sec_r000982_13 + pub_r000982_11 + 44) & 127;
    sec_accum = (sec_accum + stage_v_272) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (stage_v_204 + pub_r000982_7 + 24) & 127;
    sec_accum = (sec_accum + stage_v_273) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (stage_v_246 + pub_r000982_1 + 48) & 127;
    sec_accum = (sec_accum + stage_v_274) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (sec_r000982_3 + pub_r000982_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_275) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = (stage_v_78 + pub_r000982_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_276) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (stage_v_214 + pub_r000982_15 + 47) & 127;
    sec_accum = (sec_accum + stage_v_277) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (stage_v_84 + pub_r000982_9 + 42) & 127;
    sec_accum = (sec_accum + stage_v_278) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (stage_v_95 + pub_r000982_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_279) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = (stage_v_213 + pub_r000982_2 + 18) & 127;
    sec_accum = (sec_accum + stage_v_280) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = (sec_r000982_11 + pub_r000982_3 + 29) & 127;
    sec_accum = (sec_accum + stage_v_281) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (stage_v_230 + pub_r000982_11 + 19) & 127;
    sec_accum = (sec_accum + stage_v_282) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = (stage_v_261 + pub_r000982_1 + 7) & 127;
    sec_accum = (sec_accum + stage_v_283) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (sec_r000982_5 + pub_r000982_8 + 36) & 127;
    sec_accum = (sec_accum + stage_v_284) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = (sec_r000982_6 + pub_r000982_1 + 30) & 127;
    sec_accum = (sec_accum + stage_v_285) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (stage_v_223 + pub_r000982_13 + 3) & 127;
    sec_accum = (sec_accum + stage_v_286) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = (stage_v_237 + pub_r000982_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_287) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (sec_r000982_3 + pub_r000982_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_288) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (sec_r000982_3 + pub_r000982_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_289) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (stage_v_153 + pub_r000982_15 + 14) & 127;
    sec_accum = (sec_accum + stage_v_290) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (stage_v_112 + pub_r000982_5 + 48) & 127;
    sec_accum = (sec_accum + stage_v_291) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = (stage_v_227 + pub_r000982_5 + 38) & 127;
    sec_accum = (sec_accum + stage_v_292) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (stage_v_251 + pub_r000982_12 + 27) & 127;
    sec_accum = (sec_accum + stage_v_293) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (sec_r000982_16 + pub_r000982_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_294) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (stage_v_287 + pub_r000982_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_295) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = (sec_r000982_14 + pub_r000982_10 + 11) & 127;
    sec_accum = (sec_accum + stage_v_296) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = (stage_v_235 + pub_r000982_9 + 29) & 127;
    sec_accum = (sec_accum + stage_v_297) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (stage_v_127 + pub_r000982_13 + 21) & 127;
    sec_accum = (sec_accum + stage_v_298) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (stage_v_185 + pub_r000982_1 + 36) & 127;
    sec_accum = (sec_accum + stage_v_299) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = (stage_v_272 + pub_r000982_13 + 5) & 127;
    sec_accum = (sec_accum + stage_v_300) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (sec_r000982_15 + pub_r000982_7 + 15) & 127;
    sec_accum = (sec_accum + stage_v_301) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = (stage_v_88 + pub_r000982_5 + 36) & 127;
    sec_accum = (sec_accum + stage_v_302) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = (stage_v_168 + pub_r000982_6 + 14) & 127;
    sec_accum = (sec_accum + stage_v_303) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = (sec_r000982_10 + pub_r000982_9 + 13) & 127;
    sec_accum = (sec_accum + stage_v_304) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (stage_v_293 + pub_r000982_0 + 3) & 127;
    sec_accum = (sec_accum + stage_v_305) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (stage_v_79 + pub_r000982_4 + 17) & 127;
    sec_accum = (sec_accum + stage_v_306) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (stage_v_298 + pub_r000982_4 + 19) & 127;
    sec_accum = (sec_accum + stage_v_307) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (stage_v_277 + pub_r000982_13 + 46) & 127;
    sec_accum = (sec_accum + stage_v_308) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = (sec_r000982_14 + pub_r000982_12 + 47) & 127;
    sec_accum = (sec_accum + stage_v_309) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (sec_r000982_1 + pub_r000982_9 + 30) & 127;
    sec_accum = (sec_accum + stage_v_310) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (stage_v_160 + pub_r000982_15 + 45) & 127;
    sec_accum = (sec_accum + stage_v_311) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (stage_v_287 + pub_r000982_6 + 7) & 127;
    sec_accum = (sec_accum + stage_v_312) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = (sec_r000982_13 + pub_r000982_12 + 48) & 127;
    sec_accum = (sec_accum + stage_v_313) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (sec_r000982_3 + pub_r000982_7 + 48) & 127;
    sec_accum = (sec_accum + stage_v_314) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (stage_v_248 + pub_r000982_1 + 28) & 127;
    sec_accum = (sec_accum + stage_v_315) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (sec_r000982_12 + pub_r000982_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_316) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (stage_v_97 + pub_r000982_1 + 44) & 127;
    sec_accum = (sec_accum + stage_v_317) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (stage_v_252 + pub_r000982_7 + 38) & 127;
    sec_accum = (sec_accum + stage_v_318) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = (stage_v_133 + pub_r000982_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_319) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = (stage_v_139 + pub_r000982_1 + 23) & 127;
    sec_accum = (sec_accum + stage_v_320) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (stage_v_205 + pub_r000982_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_321) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (sec_r000982_11 + pub_r000982_0 + 16) & 127;
    sec_accum = (sec_accum + stage_v_322) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (sec_r000982_16 + pub_r000982_10 + 41) & 127;
    sec_accum = (sec_accum + stage_v_323) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (sec_r000982_7 + pub_r000982_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_324) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = (stage_v_254 + pub_r000982_5 + 26) & 127;
    sec_accum = (sec_accum + stage_v_325) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = (sec_r000982_10 + pub_r000982_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_326) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (stage_v_290 + pub_r000982_10 + 37) & 127;
    sec_accum = (sec_accum + stage_v_327) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = (sec_r000982_0 + pub_r000982_11 + 43) & 127;
    sec_accum = (sec_accum + stage_v_328) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (stage_v_255 + pub_r000982_14 + 19) & 127;
    sec_accum = (sec_accum + stage_v_329) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = (stage_v_276 + pub_r000982_9 + 6) & 127;
    sec_accum = (sec_accum + stage_v_330) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (sec_r000982_10 + pub_r000982_3 + 19) & 127;
    sec_accum = (sec_accum + stage_v_331) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (sec_r000982_14 + pub_r000982_2 + 13) & 127;
    sec_accum = (sec_accum + stage_v_332) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (sec_r000982_15 + pub_r000982_9 + 38) & 127;
    sec_accum = (sec_accum + stage_v_333) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (stage_v_78 + pub_r000982_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_334) & 255;
    out_sink = (out_sink + stage_v_334) & 255;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = (stage_v_70 + pub_r000982_14 + 16) & 127;
    sec_accum = (sec_accum + stage_v_335) & 255;
    out_sink = (out_sink + stage_v_335) & 255;

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (stage_v_98 + pub_r000982_15 + 19) & 127;
    sec_accum = (sec_accum + stage_v_336) & 255;
    out_sink = (out_sink + stage_v_336) & 255;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = (stage_v_267 + pub_r000982_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_337) & 255;
    out_sink = (out_sink + stage_v_337) & 255;

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (sec_r000982_17 + pub_r000982_8 + 26) & 127;
    sec_accum = (sec_accum + stage_v_338) & 255;
    out_sink = (out_sink + stage_v_338) & 255;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = (sec_r000982_2 + pub_r000982_4 + 42) & 127;
    sec_accum = (sec_accum + stage_v_339) & 255;
    out_sink = (out_sink + stage_v_339) & 255;

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = (stage_v_265 + pub_r000982_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_340) & 255;
    out_sink = (out_sink + stage_v_340) & 255;

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (sec_r000982_13 + pub_r000982_3 + 18) & 127;
    sec_accum = (sec_accum + stage_v_341) & 255;
    out_sink = (out_sink + stage_v_341) & 255;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (sec_r000982_17 + pub_r000982_0 + 20) & 127;
    sec_accum = (sec_accum + stage_v_342) & 255;
    out_sink = (out_sink + stage_v_342) & 255;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (sec_r000982_17 + pub_r000982_6 + 39) & 127;
    sec_accum = (sec_accum + stage_v_343) & 255;
    out_sink = (out_sink + stage_v_343) & 255;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = (stage_v_288 + pub_r000982_9 + 15) & 127;
    sec_accum = (sec_accum + stage_v_344) & 255;
    out_sink = (out_sink + stage_v_344) & 255;

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = (sec_r000982_2 + pub_r000982_5 + 6) & 127;
    sec_accum = (sec_accum + stage_v_345) & 255;
    out_sink = (out_sink + stage_v_345) & 255;

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (stage_v_304 + pub_r000982_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_346) & 255;
    out_sink = (out_sink + stage_v_346) & 255;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (sec_r000982_7 + pub_r000982_2 + 38) & 127;
    sec_accum = (sec_accum + stage_v_347) & 255;
    out_sink = (out_sink + stage_v_347) & 255;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = (stage_v_292 + pub_r000982_10 + 9) & 127;
    sec_accum = (sec_accum + stage_v_348) & 255;
    out_sink = (out_sink + stage_v_348) & 255;

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (stage_v_310 + pub_r000982_9 + 35) & 127;
    sec_accum = (sec_accum + stage_v_349) & 255;
    out_sink = (out_sink + stage_v_349) & 255;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (stage_v_151 + pub_r000982_15 + 43) & 127;
    sec_accum = (sec_accum + stage_v_350) & 255;
    out_sink = (out_sink + stage_v_350) & 255;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (sec_r000982_7 + pub_r000982_10 + 20) & 127;
    sec_accum = (sec_accum + stage_v_351) & 255;
    out_sink = (out_sink + stage_v_351) & 255;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (sec_r000982_8 + pub_r000982_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_352) & 255;
    out_sink = (out_sink + stage_v_352) & 255;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = (stage_v_230 + pub_r000982_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_353) & 255;
    out_sink = (out_sink + stage_v_353) & 255;

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (stage_v_211 + pub_r000982_14 + 49) & 127;
    sec_accum = (sec_accum + stage_v_354) & 255;
    out_sink = (out_sink + stage_v_354) & 255;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (stage_v_156 + pub_r000982_15 + 5) & 127;
    sec_accum = (sec_accum + stage_v_355) & 255;
    out_sink = (out_sink + stage_v_355) & 255;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = (stage_v_126 + pub_r000982_8 + 40) & 127;
    sec_accum = (sec_accum + stage_v_356) & 255;
    out_sink = (out_sink + stage_v_356) & 255;

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (sec_r000982_3 + pub_r000982_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_357) & 255;
    out_sink = (out_sink + stage_v_357) & 255;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (sec_r000982_10 + pub_r000982_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_358) & 255;
    out_sink = (out_sink + stage_v_358) & 255;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (sec_r000982_4 + pub_r000982_0 + 32) & 127;
    sec_accum = (sec_accum + stage_v_359) & 255;
    out_sink = (out_sink + stage_v_359) & 255;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = (stage_v_84 + pub_r000982_1 + 46) & 127;
    sec_accum = (sec_accum + stage_v_360) & 255;
    out_sink = (out_sink + stage_v_360) & 255;

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = (stage_v_112 + pub_r000982_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_361) & 255;
    out_sink = (out_sink + stage_v_361) & 255;

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (sec_r000982_11 + pub_r000982_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_362) & 255;
    out_sink = (out_sink + stage_v_362) & 255;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (stage_v_130 + pub_r000982_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_363) & 255;
    out_sink = (out_sink + stage_v_363) & 255;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (sec_r000982_8 + pub_r000982_10 + 8) & 127;
    sec_accum = (sec_accum + stage_v_364) & 255;
    out_sink = (out_sink + stage_v_364) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
