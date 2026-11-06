/*
 * Benchmark Program: R000319
 * Security Family: secret_dependent_array
 * Generator Seed: 533924
 * High Inputs: 23 | Low Inputs: 24
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000319_3924_0 {
    int id;
    int timeout;
    int port;
    short parity;
    short baud_rate;
    int stop_bits;
    int buffer[3];
};

struct Vector3D_R000319_3924_1 {
    unsigned char heading;
    int coord_y;
    int coord_z;
    unsigned char pitch;
    int norm_sq;
    short coord_x;
    int buffer[3];
};

union PacketPayload_R000319_3924_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000319_3924_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int tally_17 = local_arr[aux % 3];
    acc = (acc + tally_17 * 2) & 127;
    int tracker_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_64) & 63;
    acc ^= aux;
    int margin_43 = (aux + st.buffer[1]) & 3;
    switch (margin_43) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_62 = (aux + st.buffer[1]) & 3;
    switch (sample_62) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_25 = local_arr[aux % 3];
    acc = (acc + accumulator_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int checksum_62 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_62 > 25) {
        acc = (acc + checksum_62 * 2 + 5) & 127;
        aux ^= (checksum_62 & 15);
    } else {
        acc = (acc - checksum_62 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_86 = local_arr[aux % 3];
    acc = (acc + stride_86 * 2) & 127;
    int stride_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_3(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_46 = (aux + st.buffer[1]) & 3;
    switch (accumulator_46) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_27 = local_arr[aux % 3];
    acc = (acc + tracker_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int offset_69 = local_arr[aux % 3];
    acc = (acc + offset_69 * 2) & 127;
    int margin_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_55) & 63;
    acc ^= aux;
    int scale_10 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_10 > 42) {
        acc = (acc + scale_10 * 2 + 5) & 127;
        aux ^= (scale_10 & 15);
    } else {
        acc = (acc - scale_10 + 11) & 127;
        aux += 3;
    }
    int factor_61 = (aux + st.buffer[1]) & 3;
    switch (factor_61) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_5(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int parity_57 = local_arr[aux % 3];
    acc = (acc + parity_57 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_23 = (aux + st.buffer[1]) & 3;
    switch (metric_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_20 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_20 > 43) {
        acc = (acc + cursor_20 * 2 + 5) & 127;
        aux ^= (cursor_20 & 15);
    } else {
        acc = (acc - cursor_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_6(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_77 = local_arr[aux % 3];
    acc = (acc + stride_77 * 2) & 127;
    int mask_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_51) & 63;
    acc ^= aux;
    int damping_62 = (aux + st.buffer[1]) & 3;
    switch (damping_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_7(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int coefficient_89 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_89 > 26) {
        acc = (acc + coefficient_89 * 2 + 5) & 127;
        aux ^= (coefficient_89 & 15);
    } else {
        acc = (acc - coefficient_89 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int mask_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_68) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_11 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_11 > 23) {
        acc = (acc + mask_11 * 2 + 5) & 127;
        aux ^= (mask_11 & 15);
    } else {
        acc = (acc - mask_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int weight_50 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_50 > 36) {
        acc = (acc + weight_50 * 2 + 5) & 127;
        aux ^= (weight_50 & 15);
    } else {
        acc = (acc - weight_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_66 = (aux + st.buffer[1]) & 3;
    switch (segment_66) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_72 = local_arr[aux % 3];
    acc = (acc + window_72 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_10(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int anchor_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_77 = local_arr[aux % 3];
    acc = (acc + mask_77 * 2) & 127;
    int phase_56 = (aux + st.buffer[1]) & 3;
    switch (phase_56) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_11(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_75 = local_arr[aux % 3];
    acc = (acc + index_reg_75 * 2) & 127;
    int delta_19 = (aux + st.buffer[1]) & 3;
    switch (delta_19) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_3924_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_87 = local_arr[aux % 3];
    acc = (acc + factor_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000319_3924_13(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_27 = (aux + st.buffer[1]) & 3;
    switch (accumulator_27) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_3924_14(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int scale_64 = (aux + st.buffer[1]) & 3;
    switch (scale_64) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_97 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_97 > 47) {
        acc = (acc + delta_97 * 2 + 5) & 127;
        aux ^= (delta_97 & 15);
    } else {
        acc = (acc - delta_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_15(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int weight_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_32) & 63;
    acc ^= aux;
    int tally_17 = (aux + st.buffer[1]) & 3;
    switch (tally_17) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_53 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_53 > 23) {
        acc = (acc + sample_53 * 2 + 5) & 127;
        aux ^= (sample_53 & 15);
    } else {
        acc = (acc - sample_53 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_55 = (st.buffer[0] * 3 + aux) & 63;
    if (window_55 > 30) {
        acc = (acc + window_55 * 2 + 5) & 127;
        aux ^= (window_55 & 15);
    } else {
        acc = (acc - window_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_99 = local_arr[aux % 3];
    acc = (acc + checksum_99 * 2) & 127;
    int bound_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_3924_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int residue_11 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_11) & 63;
    acc ^= aux;
    int tally_69 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_69 > 12) {
        acc = (acc + tally_69 * 2 + 5) & 127;
        aux ^= (tally_69 & 15);
    } else {
        acc = (acc - tally_69 + 11) & 127;
        aux += 3;
    }
    int tally_32 = (aux + st.buffer[1]) & 3;
    switch (tally_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_18(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_18 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_18 > 18) {
        acc = (acc + sample_18 * 2 + 5) & 127;
        aux ^= (sample_18 & 15);
    } else {
        acc = (acc - sample_18 + 11) & 127;
        aux += 3;
    }
    int coefficient_50 = (aux + st.buffer[1]) & 3;
    switch (coefficient_50) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_21) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000319_3924_19(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_47 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_47 > 38) {
        acc = (acc + delta_47 * 2 + 5) & 127;
        aux ^= (delta_47 & 15);
    } else {
        acc = (acc - delta_47 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_20(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000319_3924_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int bound_85 = local_arr[aux % 3];
    acc = (acc + bound_85 * 2) & 127;
    int quantum_50 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_50 > 27) {
        acc = (acc + quantum_50 * 2 + 5) & 127;
        aux ^= (quantum_50 & 15);
    } else {
        acc = (acc - quantum_50 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_76 = (aux + st.buffer[1]) & 3;
    switch (damping_76) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000319_3924_21(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000319_3924_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int scale_49 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_49 > 26) {
        acc = (acc + scale_49 * 2 + 5) & 127;
        aux ^= (scale_49 & 15);
    } else {
        acc = (acc - scale_49 + 11) & 127;
        aux += 3;
    }
    int metric_76 = (aux + st.buffer[1]) & 3;
    switch (metric_76) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_93 = local_arr[aux % 3];
    acc = (acc + checksum_93 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000319_0;
    int sec_r000319_1;
    int sec_r000319_2;
    int sec_r000319_3;
    int sec_r000319_4;
    int sec_r000319_5;
    int sec_r000319_6;
    int sec_r000319_7;
    int sec_r000319_8;
    int sec_r000319_9;
    int sec_r000319_10;
    int sec_r000319_11;
    int sec_r000319_12;
    int sec_r000319_13;
    int sec_r000319_14;
    int sec_r000319_15;
    int sec_r000319_16;
    int sec_r000319_17;
    int sec_r000319_18;
    int sec_r000319_19;
    int sec_r000319_20;
    int sec_r000319_21;
    int sec_r000319_22;
    int pub_r000319_0;
    int pub_r000319_1;
    int pub_r000319_2;
    int pub_r000319_3;
    int pub_r000319_4;
    int pub_r000319_5;
    int pub_r000319_6;
    int pub_r000319_7;
    int pub_r000319_8;
    int pub_r000319_9;
    int pub_r000319_10;
    int pub_r000319_11;
    int pub_r000319_12;
    int pub_r000319_13;
    int pub_r000319_14;
    int pub_r000319_15;
    int pub_r000319_16;
    int pub_r000319_17;
    int pub_r000319_18;
    int pub_r000319_19;
    int pub_r000319_20;
    int pub_r000319_21;
    int pub_r000319_22;
    int pub_r000319_23;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000319_0 >= -100 && pub_r000319_0 <= 100);
    __CPROVER_assume(pub_r000319_1 >= -100 && pub_r000319_1 <= 100);
    __CPROVER_assume(pub_r000319_2 >= -100 && pub_r000319_2 <= 100);
    __CPROVER_assume(pub_r000319_3 >= -100 && pub_r000319_3 <= 100);
    __CPROVER_assume(pub_r000319_4 >= -100 && pub_r000319_4 <= 100);
    __CPROVER_assume(pub_r000319_5 >= -100 && pub_r000319_5 <= 100);
    __CPROVER_assume(pub_r000319_6 >= -100 && pub_r000319_6 <= 100);
    __CPROVER_assume(pub_r000319_7 >= -100 && pub_r000319_7 <= 100);
    __CPROVER_assume(pub_r000319_8 >= -100 && pub_r000319_8 <= 100);
    __CPROVER_assume(pub_r000319_9 >= -100 && pub_r000319_9 <= 100);
    __CPROVER_assume(pub_r000319_10 >= -100 && pub_r000319_10 <= 100);
    __CPROVER_assume(pub_r000319_11 >= -100 && pub_r000319_11 <= 100);
    __CPROVER_assume(pub_r000319_12 >= -100 && pub_r000319_12 <= 100);
    __CPROVER_assume(pub_r000319_13 >= -100 && pub_r000319_13 <= 100);
    __CPROVER_assume(pub_r000319_14 >= -100 && pub_r000319_14 <= 100);
    __CPROVER_assume(pub_r000319_15 >= -100 && pub_r000319_15 <= 100);
    __CPROVER_assume(pub_r000319_16 >= -100 && pub_r000319_16 <= 100);
    __CPROVER_assume(pub_r000319_17 >= -100 && pub_r000319_17 <= 100);
    __CPROVER_assume(pub_r000319_18 >= -100 && pub_r000319_18 <= 100);
    __CPROVER_assume(pub_r000319_19 >= -100 && pub_r000319_19 <= 100);
    __CPROVER_assume(pub_r000319_20 >= -100 && pub_r000319_20 <= 100);
    __CPROVER_assume(pub_r000319_21 >= -100 && pub_r000319_21 <= 100);
    __CPROVER_assume(pub_r000319_22 >= -100 && pub_r000319_22 <= 100);
    __CPROVER_assume(pub_r000319_23 >= -100 && pub_r000319_23 <= 100);
    __CPROVER_assume(sec_r000319_0 >= 0 && sec_r000319_0 <= 255);
    __CPROVER_assume(sec_r000319_1 >= 0 && sec_r000319_1 <= 255);
    __CPROVER_assume(sec_r000319_2 >= 0 && sec_r000319_2 <= 255);
    __CPROVER_assume(sec_r000319_3 >= 0 && sec_r000319_3 <= 255);
    __CPROVER_assume(sec_r000319_4 >= 0 && sec_r000319_4 <= 255);
    __CPROVER_assume(sec_r000319_5 >= 0 && sec_r000319_5 <= 255);
    __CPROVER_assume(sec_r000319_6 >= 0 && sec_r000319_6 <= 255);
    __CPROVER_assume(sec_r000319_7 >= 0 && sec_r000319_7 <= 255);
    __CPROVER_assume(sec_r000319_8 >= 0 && sec_r000319_8 <= 255);
    __CPROVER_assume(sec_r000319_9 >= 0 && sec_r000319_9 <= 255);
    __CPROVER_assume(sec_r000319_10 >= 0 && sec_r000319_10 <= 255);
    __CPROVER_assume(sec_r000319_11 >= 0 && sec_r000319_11 <= 255);
    __CPROVER_assume(sec_r000319_12 >= 0 && sec_r000319_12 <= 255);
    __CPROVER_assume(sec_r000319_13 >= 0 && sec_r000319_13 <= 255);
    __CPROVER_assume(sec_r000319_14 >= 0 && sec_r000319_14 <= 255);
    __CPROVER_assume(sec_r000319_15 >= 0 && sec_r000319_15 <= 255);
    __CPROVER_assume(sec_r000319_16 >= 0 && sec_r000319_16 <= 255);
    __CPROVER_assume(sec_r000319_17 >= 0 && sec_r000319_17 <= 255);
    __CPROVER_assume(sec_r000319_18 >= 0 && sec_r000319_18 <= 255);
    __CPROVER_assume(sec_r000319_19 >= 0 && sec_r000319_19 <= 255);
    __CPROVER_assume(sec_r000319_20 >= 0 && sec_r000319_20 <= 255);
    __CPROVER_assume(sec_r000319_21 >= 0 && sec_r000319_21 <= 255);
    __CPROVER_assume(sec_r000319_22 >= 0 && sec_r000319_22 <= 255);

    struct DeviceConfig_R000319_3924_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000319_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000319_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000319_0 + 7) & 15;
    struct Vector3D_R000319_3924_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000319_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000319_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000319_0 + 9) & 15;

    union PacketPayload_R000319_3924_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 7) & 15;
    int stage_v_6 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= stage_v_6;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 13) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 28) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 39) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 54) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 37) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 52) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 16) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 31) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 28) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 43) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int s_idx_36 = (sec_r000319_6 & 3);
    int stage_v_36 = (table[s_idx_36] + pub_r000319_20) & 127;
    table[s_idx_36] = (stage_v_36 + 7) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int s_idx_37 = (sec_r000319_2 & 3);
    int stage_v_37 = (table[s_idx_37] + pub_r000319_19) & 127;
    table[s_idx_37] = (stage_v_37 + 7) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int s_idx_38 = (stage_v_37 & 3);
    int stage_v_38 = (table[s_idx_38] + pub_r000319_16) & 127;
    table[s_idx_38] = (stage_v_38 + 7) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int s_idx_39 = (stage_v_36 & 3);
    int stage_v_39 = (table[s_idx_39] + pub_r000319_4) & 127;
    table[s_idx_39] = (stage_v_39 + 7) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int s_idx_40 = (stage_v_36 & 3);
    int stage_v_40 = (table[s_idx_40] + pub_r000319_7) & 127;
    table[s_idx_40] = (stage_v_40 + 7) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int s_idx_41 = (sec_r000319_6 & 3);
    int stage_v_41 = (table[s_idx_41] + pub_r000319_22) & 127;
    table[s_idx_41] = (stage_v_41 + 7) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int s_idx_42 = (stage_v_38 & 3);
    int stage_v_42 = (table[s_idx_42] + pub_r000319_6) & 127;
    table[s_idx_42] = (stage_v_42 + 7) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int s_idx_43 = (stage_v_39 & 3);
    int stage_v_43 = (table[s_idx_43] + pub_r000319_2) & 127;
    table[s_idx_43] = (stage_v_43 + 7) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int s_idx_44 = (stage_v_43 & 3);
    int stage_v_44 = (table[s_idx_44] + pub_r000319_19) & 127;
    table[s_idx_44] = (stage_v_44 + 7) & 63;
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int s_idx_45 = (stage_v_39 & 3);
    int stage_v_45 = (table[s_idx_45] + pub_r000319_3) & 127;
    table[s_idx_45] = (stage_v_45 + 7) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int s_idx_46 = (stage_v_42 & 3);
    int stage_v_46 = (table[s_idx_46] + pub_r000319_21) & 127;
    table[s_idx_46] = (stage_v_46 + 7) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int s_idx_47 = (sec_r000319_12 & 3);
    int stage_v_47 = (table[s_idx_47] + pub_r000319_13) & 127;
    table[s_idx_47] = (stage_v_47 + 7) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int s_idx_48 = (stage_v_37 & 3);
    int stage_v_48 = (table[s_idx_48] + pub_r000319_8) & 127;
    table[s_idx_48] = (stage_v_48 + 7) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int s_idx_49 = (stage_v_38 & 3);
    int stage_v_49 = (table[s_idx_49] + pub_r000319_10) & 127;
    table[s_idx_49] = (stage_v_49 + 7) & 63;
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int s_idx_50 = (sec_r000319_2 & 3);
    int stage_v_50 = (table[s_idx_50] + pub_r000319_9) & 127;
    table[s_idx_50] = (stage_v_50 + 7) & 63;
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int s_idx_51 = (sec_r000319_1 & 3);
    int stage_v_51 = (table[s_idx_51] + pub_r000319_7) & 127;
    table[s_idx_51] = (stage_v_51 + 7) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int s_idx_52 = (stage_v_47 & 3);
    int stage_v_52 = (table[s_idx_52] + pub_r000319_16) & 127;
    table[s_idx_52] = (stage_v_52 + 7) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int s_idx_53 = (sec_r000319_18 & 3);
    int stage_v_53 = (table[s_idx_53] + pub_r000319_6) & 127;
    table[s_idx_53] = (stage_v_53 + 7) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int s_idx_54 = (stage_v_47 & 3);
    int stage_v_54 = (table[s_idx_54] + pub_r000319_12) & 127;
    table[s_idx_54] = (stage_v_54 + 7) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int s_idx_55 = (sec_r000319_16 & 3);
    int stage_v_55 = (table[s_idx_55] + pub_r000319_10) & 127;
    table[s_idx_55] = (stage_v_55 + 7) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int s_idx_56 = (sec_r000319_11 & 3);
    int stage_v_56 = (table[s_idx_56] + pub_r000319_22) & 127;
    table[s_idx_56] = (stage_v_56 + 7) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int s_idx_57 = (stage_v_44 & 3);
    int stage_v_57 = (table[s_idx_57] + pub_r000319_23) & 127;
    table[s_idx_57] = (stage_v_57 + 7) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int s_idx_58 = (stage_v_51 & 3);
    int stage_v_58 = (table[s_idx_58] + pub_r000319_13) & 127;
    table[s_idx_58] = (stage_v_58 + 7) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int s_idx_59 = (stage_v_49 & 3);
    int stage_v_59 = (table[s_idx_59] + pub_r000319_6) & 127;
    table[s_idx_59] = (stage_v_59 + 7) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int s_idx_60 = (stage_v_50 & 3);
    int stage_v_60 = (table[s_idx_60] + pub_r000319_1) & 127;
    table[s_idx_60] = (stage_v_60 + 7) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int s_idx_61 = (sec_r000319_1 & 3);
    int stage_v_61 = (table[s_idx_61] + pub_r000319_18) & 127;
    table[s_idx_61] = (stage_v_61 + 7) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int s_idx_62 = (sec_r000319_4 & 3);
    int stage_v_62 = (table[s_idx_62] + pub_r000319_5) & 127;
    table[s_idx_62] = (stage_v_62 + 7) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int s_idx_63 = (sec_r000319_10 & 3);
    int stage_v_63 = (table[s_idx_63] + pub_r000319_12) & 127;
    table[s_idx_63] = (stage_v_63 + 7) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int s_idx_64 = (sec_r000319_15 & 3);
    int stage_v_64 = (table[s_idx_64] + pub_r000319_10) & 127;
    table[s_idx_64] = (stage_v_64 + 7) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int s_idx_65 = (sec_r000319_3 & 3);
    int stage_v_65 = (table[s_idx_65] + pub_r000319_21) & 127;
    table[s_idx_65] = (stage_v_65 + 7) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int s_idx_66 = (stage_v_53 & 3);
    int stage_v_66 = (table[s_idx_66] + pub_r000319_2) & 127;
    table[s_idx_66] = (stage_v_66 + 7) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int s_idx_67 = (stage_v_42 & 3);
    int stage_v_67 = (table[s_idx_67] + pub_r000319_16) & 127;
    table[s_idx_67] = (stage_v_67 + 7) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int s_idx_68 = (sec_r000319_21 & 3);
    int stage_v_68 = (table[s_idx_68] + pub_r000319_9) & 127;
    table[s_idx_68] = (stage_v_68 + 7) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int s_idx_69 = (stage_v_49 & 3);
    int stage_v_69 = (table[s_idx_69] + pub_r000319_10) & 127;
    table[s_idx_69] = (stage_v_69 + 7) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int s_idx_70 = (stage_v_45 & 3);
    int stage_v_70 = (table[s_idx_70] + pub_r000319_19) & 127;
    table[s_idx_70] = (stage_v_70 + 7) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int s_idx_71 = (sec_r000319_16 & 3);
    int stage_v_71 = (table[s_idx_71] + pub_r000319_12) & 127;
    table[s_idx_71] = (stage_v_71 + 7) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int s_idx_72 = (stage_v_40 & 3);
    int stage_v_72 = (table[s_idx_72] + pub_r000319_21) & 127;
    table[s_idx_72] = (stage_v_72 + 7) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int s_idx_73 = (stage_v_38 & 3);
    int stage_v_73 = (table[s_idx_73] + pub_r000319_17) & 127;
    table[s_idx_73] = (stage_v_73 + 7) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int s_idx_74 = (sec_r000319_22 & 3);
    int stage_v_74 = (table[s_idx_74] + pub_r000319_13) & 127;
    table[s_idx_74] = (stage_v_74 + 7) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int s_idx_75 = (sec_r000319_7 & 3);
    int stage_v_75 = (table[s_idx_75] + pub_r000319_16) & 127;
    table[s_idx_75] = (stage_v_75 + 7) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int s_idx_76 = (sec_r000319_20 & 3);
    int stage_v_76 = (table[s_idx_76] + pub_r000319_9) & 127;
    table[s_idx_76] = (stage_v_76 + 7) & 63;
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int s_idx_77 = (sec_r000319_10 & 3);
    int stage_v_77 = (table[s_idx_77] + pub_r000319_14) & 127;
    table[s_idx_77] = (stage_v_77 + 7) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int s_idx_78 = (sec_r000319_15 & 3);
    int stage_v_78 = (table[s_idx_78] + pub_r000319_8) & 127;
    table[s_idx_78] = (stage_v_78 + 7) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int s_idx_79 = (sec_r000319_11 & 3);
    int stage_v_79 = (table[s_idx_79] + pub_r000319_19) & 127;
    table[s_idx_79] = (stage_v_79 + 7) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int s_idx_80 = (sec_r000319_14 & 3);
    int stage_v_80 = (table[s_idx_80] + pub_r000319_5) & 127;
    table[s_idx_80] = (stage_v_80 + 7) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int s_idx_81 = (stage_v_71 & 3);
    int stage_v_81 = (table[s_idx_81] + pub_r000319_8) & 127;
    table[s_idx_81] = (stage_v_81 + 7) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int s_idx_82 = (sec_r000319_10 & 3);
    int stage_v_82 = (table[s_idx_82] + pub_r000319_21) & 127;
    table[s_idx_82] = (stage_v_82 + 7) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int s_idx_83 = (stage_v_58 & 3);
    int stage_v_83 = (table[s_idx_83] + pub_r000319_5) & 127;
    table[s_idx_83] = (stage_v_83 + 7) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int s_idx_84 = (stage_v_66 & 3);
    int stage_v_84 = (table[s_idx_84] + pub_r000319_2) & 127;
    table[s_idx_84] = (stage_v_84 + 7) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int s_idx_85 = (stage_v_43 & 3);
    int stage_v_85 = (table[s_idx_85] + pub_r000319_4) & 127;
    table[s_idx_85] = (stage_v_85 + 7) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int s_idx_86 = (stage_v_80 & 3);
    int stage_v_86 = (table[s_idx_86] + pub_r000319_18) & 127;
    table[s_idx_86] = (stage_v_86 + 7) & 63;
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int s_idx_87 = (sec_r000319_0 & 3);
    int stage_v_87 = (table[s_idx_87] + pub_r000319_14) & 127;
    table[s_idx_87] = (stage_v_87 + 7) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int s_idx_88 = (stage_v_40 & 3);
    int stage_v_88 = (table[s_idx_88] + pub_r000319_23) & 127;
    table[s_idx_88] = (stage_v_88 + 7) & 63;
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int s_idx_89 = (stage_v_59 & 3);
    int stage_v_89 = (table[s_idx_89] + pub_r000319_14) & 127;
    table[s_idx_89] = (stage_v_89 + 7) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int s_idx_90 = (sec_r000319_21 & 3);
    int stage_v_90 = (table[s_idx_90] + pub_r000319_13) & 127;
    table[s_idx_90] = (stage_v_90 + 7) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int s_idx_91 = (stage_v_71 & 3);
    int stage_v_91 = (table[s_idx_91] + pub_r000319_14) & 127;
    table[s_idx_91] = (stage_v_91 + 7) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int s_idx_92 = (stage_v_67 & 3);
    int stage_v_92 = (table[s_idx_92] + pub_r000319_4) & 127;
    table[s_idx_92] = (stage_v_92 + 7) & 63;
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int s_idx_93 = (stage_v_48 & 3);
    int stage_v_93 = (table[s_idx_93] + pub_r000319_19) & 127;
    table[s_idx_93] = (stage_v_93 + 7) & 63;
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int s_idx_94 = (stage_v_65 & 3);
    int stage_v_94 = (table[s_idx_94] + pub_r000319_15) & 127;
    table[s_idx_94] = (stage_v_94 + 7) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int s_idx_95 = (sec_r000319_16 & 3);
    int stage_v_95 = (table[s_idx_95] + pub_r000319_19) & 127;
    table[s_idx_95] = (stage_v_95 + 7) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int s_idx_96 = (stage_v_54 & 3);
    int stage_v_96 = (table[s_idx_96] + pub_r000319_0) & 127;
    table[s_idx_96] = (stage_v_96 + 7) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int s_idx_97 = (sec_r000319_0 & 3);
    int stage_v_97 = (table[s_idx_97] + pub_r000319_3) & 127;
    table[s_idx_97] = (stage_v_97 + 7) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int s_idx_98 = (stage_v_59 & 3);
    int stage_v_98 = (table[s_idx_98] + pub_r000319_20) & 127;
    table[s_idx_98] = (stage_v_98 + 7) & 63;
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int s_idx_99 = (sec_r000319_3 & 3);
    int stage_v_99 = (table[s_idx_99] + pub_r000319_20) & 127;
    table[s_idx_99] = (stage_v_99 + 7) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int s_idx_100 = (stage_v_92 & 3);
    int stage_v_100 = (table[s_idx_100] + pub_r000319_23) & 127;
    table[s_idx_100] = (stage_v_100 + 7) & 63;
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int s_idx_101 = (stage_v_86 & 3);
    int stage_v_101 = (table[s_idx_101] + pub_r000319_3) & 127;
    table[s_idx_101] = (stage_v_101 + 7) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int s_idx_102 = (sec_r000319_1 & 3);
    int stage_v_102 = (table[s_idx_102] + pub_r000319_12) & 127;
    table[s_idx_102] = (stage_v_102 + 7) & 63;
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int s_idx_103 = (stage_v_63 & 3);
    int stage_v_103 = (table[s_idx_103] + pub_r000319_17) & 127;
    table[s_idx_103] = (stage_v_103 + 7) & 63;
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int s_idx_104 = (stage_v_46 & 3);
    int stage_v_104 = (table[s_idx_104] + pub_r000319_9) & 127;
    table[s_idx_104] = (stage_v_104 + 7) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int s_idx_105 = (stage_v_69 & 3);
    int stage_v_105 = (table[s_idx_105] + pub_r000319_20) & 127;
    table[s_idx_105] = (stage_v_105 + 7) & 63;
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int s_idx_106 = (stage_v_54 & 3);
    int stage_v_106 = (table[s_idx_106] + pub_r000319_10) & 127;
    table[s_idx_106] = (stage_v_106 + 7) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int s_idx_107 = (stage_v_100 & 3);
    int stage_v_107 = (table[s_idx_107] + pub_r000319_11) & 127;
    table[s_idx_107] = (stage_v_107 + 7) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int s_idx_108 = (stage_v_107 & 3);
    int stage_v_108 = (table[s_idx_108] + pub_r000319_16) & 127;
    table[s_idx_108] = (stage_v_108 + 7) & 63;
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int s_idx_109 = (stage_v_36 & 3);
    int stage_v_109 = (table[s_idx_109] + pub_r000319_8) & 127;
    table[s_idx_109] = (stage_v_109 + 7) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int s_idx_110 = (sec_r000319_19 & 3);
    int stage_v_110 = (table[s_idx_110] + pub_r000319_2) & 127;
    table[s_idx_110] = (stage_v_110 + 7) & 63;
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int s_idx_111 = (stage_v_81 & 3);
    int stage_v_111 = (table[s_idx_111] + pub_r000319_1) & 127;
    table[s_idx_111] = (stage_v_111 + 7) & 63;
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int s_idx_112 = (stage_v_97 & 3);
    int stage_v_112 = (table[s_idx_112] + pub_r000319_3) & 127;
    table[s_idx_112] = (stage_v_112 + 7) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int s_idx_113 = (sec_r000319_14 & 3);
    int stage_v_113 = (table[s_idx_113] + pub_r000319_21) & 127;
    table[s_idx_113] = (stage_v_113 + 7) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int s_idx_114 = (stage_v_101 & 3);
    int stage_v_114 = (table[s_idx_114] + pub_r000319_17) & 127;
    table[s_idx_114] = (stage_v_114 + 7) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int s_idx_115 = (stage_v_73 & 3);
    int stage_v_115 = (table[s_idx_115] + pub_r000319_15) & 127;
    table[s_idx_115] = (stage_v_115 + 7) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int s_idx_116 = (stage_v_108 & 3);
    int stage_v_116 = (table[s_idx_116] + pub_r000319_3) & 127;
    table[s_idx_116] = (stage_v_116 + 7) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int s_idx_117 = (stage_v_91 & 3);
    int stage_v_117 = (table[s_idx_117] + pub_r000319_13) & 127;
    table[s_idx_117] = (stage_v_117 + 7) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int s_idx_118 = (sec_r000319_13 & 3);
    int stage_v_118 = (table[s_idx_118] + pub_r000319_17) & 127;
    table[s_idx_118] = (stage_v_118 + 7) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int s_idx_119 = (stage_v_86 & 3);
    int stage_v_119 = (table[s_idx_119] + pub_r000319_21) & 127;
    table[s_idx_119] = (stage_v_119 + 7) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int s_idx_120 = (stage_v_69 & 3);
    int stage_v_120 = (table[s_idx_120] + pub_r000319_7) & 127;
    table[s_idx_120] = (stage_v_120 + 7) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int s_idx_121 = (sec_r000319_14 & 3);
    int stage_v_121 = (table[s_idx_121] + pub_r000319_15) & 127;
    table[s_idx_121] = (stage_v_121 + 7) & 63;
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int s_idx_122 = (stage_v_49 & 3);
    int stage_v_122 = (table[s_idx_122] + pub_r000319_0) & 127;
    table[s_idx_122] = (stage_v_122 + 7) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int s_idx_123 = (sec_r000319_20 & 3);
    int stage_v_123 = (table[s_idx_123] + pub_r000319_4) & 127;
    table[s_idx_123] = (stage_v_123 + 7) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int s_idx_124 = (sec_r000319_11 & 3);
    int stage_v_124 = (table[s_idx_124] + pub_r000319_18) & 127;
    table[s_idx_124] = (stage_v_124 + 7) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int s_idx_125 = (stage_v_95 & 3);
    int stage_v_125 = (table[s_idx_125] + pub_r000319_12) & 127;
    table[s_idx_125] = (stage_v_125 + 7) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int s_idx_126 = (stage_v_119 & 3);
    int stage_v_126 = (table[s_idx_126] + pub_r000319_13) & 127;
    table[s_idx_126] = (stage_v_126 + 7) & 63;
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int s_idx_127 = (sec_r000319_19 & 3);
    int stage_v_127 = (table[s_idx_127] + pub_r000319_11) & 127;
    table[s_idx_127] = (stage_v_127 + 7) & 63;
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int s_idx_128 = (sec_r000319_15 & 3);
    int stage_v_128 = (table[s_idx_128] + pub_r000319_23) & 127;
    table[s_idx_128] = (stage_v_128 + 7) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int s_idx_129 = (sec_r000319_13 & 3);
    int stage_v_129 = (table[s_idx_129] + pub_r000319_14) & 127;
    table[s_idx_129] = (stage_v_129 + 7) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int s_idx_130 = (stage_v_106 & 3);
    int stage_v_130 = (table[s_idx_130] + pub_r000319_13) & 127;
    table[s_idx_130] = (stage_v_130 + 7) & 63;
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int s_idx_131 = (stage_v_50 & 3);
    int stage_v_131 = (table[s_idx_131] + pub_r000319_13) & 127;
    table[s_idx_131] = (stage_v_131 + 7) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int s_idx_132 = (stage_v_102 & 3);
    int stage_v_132 = (table[s_idx_132] + pub_r000319_6) & 127;
    table[s_idx_132] = (stage_v_132 + 7) & 63;
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int s_idx_133 = (stage_v_42 & 3);
    int stage_v_133 = (table[s_idx_133] + pub_r000319_3) & 127;
    table[s_idx_133] = (stage_v_133 + 7) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int s_idx_134 = (stage_v_105 & 3);
    int stage_v_134 = (table[s_idx_134] + pub_r000319_0) & 127;
    table[s_idx_134] = (stage_v_134 + 7) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int s_idx_135 = (stage_v_104 & 3);
    int stage_v_135 = (table[s_idx_135] + pub_r000319_9) & 127;
    table[s_idx_135] = (stage_v_135 + 7) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int s_idx_136 = (stage_v_52 & 3);
    int stage_v_136 = (table[s_idx_136] + pub_r000319_7) & 127;
    table[s_idx_136] = (stage_v_136 + 7) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int s_idx_137 = (stage_v_80 & 3);
    int stage_v_137 = (table[s_idx_137] + pub_r000319_18) & 127;
    table[s_idx_137] = (stage_v_137 + 7) & 63;
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int s_idx_138 = (stage_v_52 & 3);
    int stage_v_138 = (table[s_idx_138] + pub_r000319_2) & 127;
    table[s_idx_138] = (stage_v_138 + 7) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int s_idx_139 = (stage_v_79 & 3);
    int stage_v_139 = (table[s_idx_139] + pub_r000319_1) & 127;
    table[s_idx_139] = (stage_v_139 + 7) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int s_idx_140 = (stage_v_96 & 3);
    int stage_v_140 = (table[s_idx_140] + pub_r000319_8) & 127;
    table[s_idx_140] = (stage_v_140 + 7) & 63;
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int s_idx_141 = (stage_v_69 & 3);
    int stage_v_141 = (table[s_idx_141] + pub_r000319_9) & 127;
    table[s_idx_141] = (stage_v_141 + 7) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int s_idx_142 = (stage_v_85 & 3);
    int stage_v_142 = (table[s_idx_142] + pub_r000319_0) & 127;
    table[s_idx_142] = (stage_v_142 + 7) & 63;
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int s_idx_143 = (stage_v_75 & 3);
    int stage_v_143 = (table[s_idx_143] + pub_r000319_10) & 127;
    table[s_idx_143] = (stage_v_143 + 7) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int s_idx_144 = (stage_v_98 & 3);
    int stage_v_144 = (table[s_idx_144] + pub_r000319_12) & 127;
    table[s_idx_144] = (stage_v_144 + 7) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int s_idx_145 = (stage_v_46 & 3);
    int stage_v_145 = (table[s_idx_145] + pub_r000319_7) & 127;
    table[s_idx_145] = (stage_v_145 + 7) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int s_idx_146 = (stage_v_69 & 3);
    int stage_v_146 = (table[s_idx_146] + pub_r000319_12) & 127;
    table[s_idx_146] = (stage_v_146 + 7) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int s_idx_147 = (stage_v_52 & 3);
    int stage_v_147 = (table[s_idx_147] + pub_r000319_11) & 127;
    table[s_idx_147] = (stage_v_147 + 7) & 63;
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int s_idx_148 = (stage_v_65 & 3);
    int stage_v_148 = (table[s_idx_148] + pub_r000319_19) & 127;
    table[s_idx_148] = (stage_v_148 + 7) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int s_idx_149 = (stage_v_139 & 3);
    int stage_v_149 = (table[s_idx_149] + pub_r000319_1) & 127;
    table[s_idx_149] = (stage_v_149 + 7) & 63;
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int s_idx_150 = (stage_v_41 & 3);
    int stage_v_150 = (table[s_idx_150] + pub_r000319_17) & 127;
    table[s_idx_150] = (stage_v_150 + 7) & 63;
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int s_idx_151 = (stage_v_42 & 3);
    int stage_v_151 = (table[s_idx_151] + pub_r000319_17) & 127;
    table[s_idx_151] = (stage_v_151 + 7) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int s_idx_152 = (sec_r000319_17 & 3);
    int stage_v_152 = (table[s_idx_152] + pub_r000319_23) & 127;
    table[s_idx_152] = (stage_v_152 + 7) & 63;
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int s_idx_153 = (stage_v_105 & 3);
    int stage_v_153 = (table[s_idx_153] + pub_r000319_3) & 127;
    table[s_idx_153] = (stage_v_153 + 7) & 63;
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int s_idx_154 = (sec_r000319_4 & 3);
    int stage_v_154 = (table[s_idx_154] + pub_r000319_20) & 127;
    table[s_idx_154] = (stage_v_154 + 7) & 63;
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int s_idx_155 = (stage_v_142 & 3);
    int stage_v_155 = (table[s_idx_155] + pub_r000319_10) & 127;
    table[s_idx_155] = (stage_v_155 + 7) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int s_idx_156 = (sec_r000319_21 & 3);
    int stage_v_156 = (table[s_idx_156] + pub_r000319_10) & 127;
    table[s_idx_156] = (stage_v_156 + 7) & 63;
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int s_idx_157 = (stage_v_49 & 3);
    int stage_v_157 = (table[s_idx_157] + pub_r000319_12) & 127;
    table[s_idx_157] = (stage_v_157 + 7) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int s_idx_158 = (stage_v_62 & 3);
    int stage_v_158 = (table[s_idx_158] + pub_r000319_13) & 127;
    table[s_idx_158] = (stage_v_158 + 7) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int s_idx_159 = (sec_r000319_16 & 3);
    int stage_v_159 = (table[s_idx_159] + pub_r000319_6) & 127;
    table[s_idx_159] = (stage_v_159 + 7) & 63;
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int s_idx_160 = (stage_v_130 & 3);
    int stage_v_160 = (table[s_idx_160] + pub_r000319_11) & 127;
    table[s_idx_160] = (stage_v_160 + 7) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int s_idx_161 = (stage_v_45 & 3);
    int stage_v_161 = (table[s_idx_161] + pub_r000319_22) & 127;
    table[s_idx_161] = (stage_v_161 + 7) & 63;
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int s_idx_162 = (sec_r000319_15 & 3);
    int stage_v_162 = (table[s_idx_162] + pub_r000319_21) & 127;
    table[s_idx_162] = (stage_v_162 + 7) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int s_idx_163 = (stage_v_161 & 3);
    int stage_v_163 = (table[s_idx_163] + pub_r000319_17) & 127;
    table[s_idx_163] = (stage_v_163 + 7) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int s_idx_164 = (stage_v_117 & 3);
    int stage_v_164 = (table[s_idx_164] + pub_r000319_1) & 127;
    table[s_idx_164] = (stage_v_164 + 7) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int s_idx_165 = (sec_r000319_12 & 3);
    int stage_v_165 = (table[s_idx_165] + pub_r000319_21) & 127;
    table[s_idx_165] = (stage_v_165 + 7) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int s_idx_166 = (stage_v_98 & 3);
    int stage_v_166 = (table[s_idx_166] + pub_r000319_7) & 127;
    table[s_idx_166] = (stage_v_166 + 7) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int s_idx_167 = (stage_v_152 & 3);
    int stage_v_167 = (table[s_idx_167] + pub_r000319_23) & 127;
    table[s_idx_167] = (stage_v_167 + 7) & 63;
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int s_idx_168 = (stage_v_157 & 3);
    int stage_v_168 = (table[s_idx_168] + pub_r000319_1) & 127;
    table[s_idx_168] = (stage_v_168 + 7) & 63;
    out_sink = (out_sink + stage_v_168) & 255;
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int s_idx_169 = (sec_r000319_5 & 3);
    int stage_v_169 = (table[s_idx_169] + pub_r000319_7) & 127;
    table[s_idx_169] = (stage_v_169 + 7) & 63;
    out_sink = (out_sink + stage_v_169) & 255;
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int s_idx_170 = (stage_v_139 & 3);
    int stage_v_170 = (table[s_idx_170] + pub_r000319_22) & 127;
    table[s_idx_170] = (stage_v_170 + 7) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int s_idx_171 = (sec_r000319_14 & 3);
    int stage_v_171 = (table[s_idx_171] + pub_r000319_6) & 127;
    table[s_idx_171] = (stage_v_171 + 7) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int s_idx_172 = (stage_v_50 & 3);
    int stage_v_172 = (table[s_idx_172] + pub_r000319_15) & 127;
    table[s_idx_172] = (stage_v_172 + 7) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int s_idx_173 = (stage_v_69 & 3);
    int stage_v_173 = (table[s_idx_173] + pub_r000319_22) & 127;
    table[s_idx_173] = (stage_v_173 + 7) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int s_idx_174 = (stage_v_123 & 3);
    int stage_v_174 = (table[s_idx_174] + pub_r000319_19) & 127;
    table[s_idx_174] = (stage_v_174 + 7) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int s_idx_175 = (sec_r000319_5 & 3);
    int stage_v_175 = (table[s_idx_175] + pub_r000319_12) & 127;
    table[s_idx_175] = (stage_v_175 + 7) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int s_idx_176 = (sec_r000319_4 & 3);
    int stage_v_176 = (table[s_idx_176] + pub_r000319_11) & 127;
    table[s_idx_176] = (stage_v_176 + 7) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int s_idx_177 = (stage_v_132 & 3);
    int stage_v_177 = (table[s_idx_177] + pub_r000319_12) & 127;
    table[s_idx_177] = (stage_v_177 + 7) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int s_idx_178 = (sec_r000319_15 & 3);
    int stage_v_178 = (table[s_idx_178] + pub_r000319_11) & 127;
    table[s_idx_178] = (stage_v_178 + 7) & 63;
    out_sink = (out_sink + stage_v_178) & 255;
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int s_idx_179 = (stage_v_87 & 3);
    int stage_v_179 = (table[s_idx_179] + pub_r000319_23) & 127;
    table[s_idx_179] = (stage_v_179 + 7) & 63;
    out_sink = (out_sink + stage_v_179) & 255;
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int s_idx_180 = (stage_v_169 & 3);
    int stage_v_180 = (table[s_idx_180] + pub_r000319_22) & 127;
    table[s_idx_180] = (stage_v_180 + 7) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int s_idx_181 = (stage_v_154 & 3);
    int stage_v_181 = (table[s_idx_181] + pub_r000319_7) & 127;
    table[s_idx_181] = (stage_v_181 + 7) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int s_idx_182 = (stage_v_52 & 3);
    int stage_v_182 = (table[s_idx_182] + pub_r000319_1) & 127;
    table[s_idx_182] = (stage_v_182 + 7) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int s_idx_183 = (stage_v_71 & 3);
    int stage_v_183 = (table[s_idx_183] + pub_r000319_10) & 127;
    table[s_idx_183] = (stage_v_183 + 7) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int s_idx_184 = (stage_v_62 & 3);
    int stage_v_184 = (table[s_idx_184] + pub_r000319_3) & 127;
    table[s_idx_184] = (stage_v_184 + 7) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int s_idx_185 = (stage_v_124 & 3);
    int stage_v_185 = (table[s_idx_185] + pub_r000319_11) & 127;
    table[s_idx_185] = (stage_v_185 + 7) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int s_idx_186 = (sec_r000319_21 & 3);
    int stage_v_186 = (table[s_idx_186] + pub_r000319_14) & 127;
    table[s_idx_186] = (stage_v_186 + 7) & 63;
    out_sink = (out_sink + stage_v_186) & 255;
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int s_idx_187 = (stage_v_154 & 3);
    int stage_v_187 = (table[s_idx_187] + pub_r000319_7) & 127;
    table[s_idx_187] = (stage_v_187 + 7) & 63;
    out_sink = (out_sink + stage_v_187) & 255;
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int s_idx_188 = (sec_r000319_12 & 3);
    int stage_v_188 = (table[s_idx_188] + pub_r000319_7) & 127;
    table[s_idx_188] = (stage_v_188 + 7) & 63;
    out_sink = (out_sink + stage_v_188) & 255;
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int s_idx_189 = (stage_v_183 & 3);
    int stage_v_189 = (table[s_idx_189] + pub_r000319_19) & 127;
    table[s_idx_189] = (stage_v_189 + 7) & 63;
    out_sink = (out_sink + stage_v_189) & 255;
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int s_idx_190 = (stage_v_187 & 3);
    int stage_v_190 = (table[s_idx_190] + pub_r000319_17) & 127;
    table[s_idx_190] = (stage_v_190 + 7) & 63;
    out_sink = (out_sink + stage_v_190) & 255;
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int s_idx_191 = (stage_v_83 & 3);
    int stage_v_191 = (table[s_idx_191] + pub_r000319_23) & 127;
    table[s_idx_191] = (stage_v_191 + 7) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int s_idx_192 = (stage_v_56 & 3);
    int stage_v_192 = (table[s_idx_192] + pub_r000319_11) & 127;
    table[s_idx_192] = (stage_v_192 + 7) & 63;
    out_sink = (out_sink + stage_v_192) & 255;
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int s_idx_193 = (stage_v_103 & 3);
    int stage_v_193 = (table[s_idx_193] + pub_r000319_20) & 127;
    table[s_idx_193] = (stage_v_193 + 7) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int s_idx_194 = (stage_v_126 & 3);
    int stage_v_194 = (table[s_idx_194] + pub_r000319_1) & 127;
    table[s_idx_194] = (stage_v_194 + 7) & 63;
    out_sink = (out_sink + stage_v_194) & 255;
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int s_idx_195 = (sec_r000319_13 & 3);
    int stage_v_195 = (table[s_idx_195] + pub_r000319_11) & 127;
    table[s_idx_195] = (stage_v_195 + 7) & 63;
    out_sink = (out_sink + stage_v_195) & 255;
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int s_idx_196 = (stage_v_64 & 3);
    int stage_v_196 = (table[s_idx_196] + pub_r000319_16) & 127;
    table[s_idx_196] = (stage_v_196 + 7) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int s_idx_197 = (sec_r000319_8 & 3);
    int stage_v_197 = (table[s_idx_197] + pub_r000319_4) & 127;
    table[s_idx_197] = (stage_v_197 + 7) & 63;
    out_sink = (out_sink + stage_v_197) & 255;
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int s_idx_198 = (sec_r000319_21 & 3);
    int stage_v_198 = (table[s_idx_198] + pub_r000319_22) & 127;
    table[s_idx_198] = (stage_v_198 + 7) & 63;
    out_sink = (out_sink + stage_v_198) & 255;
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int s_idx_199 = (sec_r000319_21 & 3);
    int stage_v_199 = (table[s_idx_199] + pub_r000319_1) & 127;
    table[s_idx_199] = (stage_v_199 + 7) & 63;
    out_sink = (out_sink + stage_v_199) & 255;
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int s_idx_200 = (stage_v_118 & 3);
    int stage_v_200 = (table[s_idx_200] + pub_r000319_21) & 127;
    table[s_idx_200] = (stage_v_200 + 7) & 63;
    out_sink = (out_sink + stage_v_200) & 255;
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int s_idx_201 = (sec_r000319_5 & 3);
    int stage_v_201 = (table[s_idx_201] + pub_r000319_23) & 127;
    table[s_idx_201] = (stage_v_201 + 7) & 63;
    out_sink = (out_sink + stage_v_201) & 255;
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int s_idx_202 = (stage_v_36 & 3);
    int stage_v_202 = (table[s_idx_202] + pub_r000319_5) & 127;
    table[s_idx_202] = (stage_v_202 + 7) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int s_idx_203 = (stage_v_146 & 3);
    int stage_v_203 = (table[s_idx_203] + pub_r000319_7) & 127;
    table[s_idx_203] = (stage_v_203 + 7) & 63;
    out_sink = (out_sink + stage_v_203) & 255;
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int s_idx_204 = (sec_r000319_11 & 3);
    int stage_v_204 = (table[s_idx_204] + pub_r000319_10) & 127;
    table[s_idx_204] = (stage_v_204 + 7) & 63;
    out_sink = (out_sink + stage_v_204) & 255;
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int s_idx_205 = (stage_v_173 & 3);
    int stage_v_205 = (table[s_idx_205] + pub_r000319_23) & 127;
    table[s_idx_205] = (stage_v_205 + 7) & 63;
    out_sink = (out_sink + stage_v_205) & 255;
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int s_idx_206 = (sec_r000319_17 & 3);
    int stage_v_206 = (table[s_idx_206] + pub_r000319_1) & 127;
    table[s_idx_206] = (stage_v_206 + 7) & 63;
    out_sink = (out_sink + stage_v_206) & 255;
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int s_idx_207 = (sec_r000319_16 & 3);
    int stage_v_207 = (table[s_idx_207] + pub_r000319_19) & 127;
    table[s_idx_207] = (stage_v_207 + 7) & 63;
    out_sink = (out_sink + stage_v_207) & 255;
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int s_idx_208 = (sec_r000319_11 & 3);
    int stage_v_208 = (table[s_idx_208] + pub_r000319_3) & 127;
    table[s_idx_208] = (stage_v_208 + 7) & 63;
    out_sink = (out_sink + stage_v_208) & 255;
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int s_idx_209 = (stage_v_62 & 3);
    int stage_v_209 = (table[s_idx_209] + pub_r000319_3) & 127;
    table[s_idx_209] = (stage_v_209 + 7) & 63;
    out_sink = (out_sink + stage_v_209) & 255;
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int s_idx_210 = (stage_v_182 & 3);
    int stage_v_210 = (table[s_idx_210] + pub_r000319_20) & 127;
    table[s_idx_210] = (stage_v_210 + 7) & 63;
    out_sink = (out_sink + stage_v_210) & 255;
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int s_idx_211 = (stage_v_138 & 3);
    int stage_v_211 = (table[s_idx_211] + pub_r000319_4) & 127;
    table[s_idx_211] = (stage_v_211 + 7) & 63;
    out_sink = (out_sink + stage_v_211) & 255;
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int s_idx_212 = (stage_v_127 & 3);
    int stage_v_212 = (table[s_idx_212] + pub_r000319_3) & 127;
    table[s_idx_212] = (stage_v_212 + 7) & 63;
    out_sink = (out_sink + stage_v_212) & 255;
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int s_idx_213 = (stage_v_171 & 3);
    int stage_v_213 = (table[s_idx_213] + pub_r000319_1) & 127;
    table[s_idx_213] = (stage_v_213 + 7) & 63;
    out_sink = (out_sink + stage_v_213) & 255;
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int s_idx_214 = (stage_v_212 & 3);
    int stage_v_214 = (table[s_idx_214] + pub_r000319_22) & 127;
    table[s_idx_214] = (stage_v_214 + 7) & 63;
    out_sink = (out_sink + stage_v_214) & 255;
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int s_idx_215 = (sec_r000319_14 & 3);
    int stage_v_215 = (table[s_idx_215] + pub_r000319_17) & 127;
    table[s_idx_215] = (stage_v_215 + 7) & 63;
    out_sink = (out_sink + stage_v_215) & 255;
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int s_idx_216 = (stage_v_164 & 3);
    int stage_v_216 = (table[s_idx_216] + pub_r000319_1) & 127;
    table[s_idx_216] = (stage_v_216 + 7) & 63;
    out_sink = (out_sink + stage_v_216) & 255;
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int s_idx_217 = (stage_v_191 & 3);
    int stage_v_217 = (table[s_idx_217] + pub_r000319_11) & 127;
    table[s_idx_217] = (stage_v_217 + 7) & 63;
    out_sink = (out_sink + stage_v_217) & 255;
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int s_idx_218 = (stage_v_70 & 3);
    int stage_v_218 = (table[s_idx_218] + pub_r000319_4) & 127;
    table[s_idx_218] = (stage_v_218 + 7) & 63;
    out_sink = (out_sink + stage_v_218) & 255;
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int s_idx_219 = (stage_v_185 & 3);
    int stage_v_219 = (table[s_idx_219] + pub_r000319_17) & 127;
    table[s_idx_219] = (stage_v_219 + 7) & 63;
    out_sink = (out_sink + stage_v_219) & 255;
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int s_idx_220 = (stage_v_98 & 3);
    int stage_v_220 = (table[s_idx_220] + pub_r000319_13) & 127;
    table[s_idx_220] = (stage_v_220 + 7) & 63;
    out_sink = (out_sink + stage_v_220) & 255;
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int s_idx_221 = (stage_v_82 & 3);
    int stage_v_221 = (table[s_idx_221] + pub_r000319_9) & 127;
    table[s_idx_221] = (stage_v_221 + 7) & 63;
    out_sink = (out_sink + stage_v_221) & 255;
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int s_idx_222 = (stage_v_127 & 3);
    int stage_v_222 = (table[s_idx_222] + pub_r000319_16) & 127;
    table[s_idx_222] = (stage_v_222 + 7) & 63;
    out_sink = (out_sink + stage_v_222) & 255;
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int s_idx_223 = (sec_r000319_22 & 3);
    int stage_v_223 = (table[s_idx_223] + pub_r000319_17) & 127;
    table[s_idx_223] = (stage_v_223 + 7) & 63;
    out_sink = (out_sink + stage_v_223) & 255;
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int s_idx_224 = (stage_v_109 & 3);
    int stage_v_224 = (table[s_idx_224] + pub_r000319_3) & 127;
    table[s_idx_224] = (stage_v_224 + 7) & 63;
    out_sink = (out_sink + stage_v_224) & 255;
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int s_idx_225 = (sec_r000319_21 & 3);
    int stage_v_225 = (table[s_idx_225] + pub_r000319_3) & 127;
    table[s_idx_225] = (stage_v_225 + 7) & 63;
    out_sink = (out_sink + stage_v_225) & 255;
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int s_idx_226 = (stage_v_84 & 3);
    int stage_v_226 = (table[s_idx_226] + pub_r000319_23) & 127;
    table[s_idx_226] = (stage_v_226 + 7) & 63;
    out_sink = (out_sink + stage_v_226) & 255;
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int s_idx_227 = (sec_r000319_12 & 3);
    int stage_v_227 = (table[s_idx_227] + pub_r000319_16) & 127;
    table[s_idx_227] = (stage_v_227 + 7) & 63;
    out_sink = (out_sink + stage_v_227) & 255;
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int s_idx_228 = (stage_v_204 & 3);
    int stage_v_228 = (table[s_idx_228] + pub_r000319_2) & 127;
    table[s_idx_228] = (stage_v_228 + 7) & 63;
    out_sink = (out_sink + stage_v_228) & 255;
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int s_idx_229 = (stage_v_182 & 3);
    int stage_v_229 = (table[s_idx_229] + pub_r000319_10) & 127;
    table[s_idx_229] = (stage_v_229 + 7) & 63;
    out_sink = (out_sink + stage_v_229) & 255;
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int s_idx_230 = (sec_r000319_2 & 3);
    int stage_v_230 = (table[s_idx_230] + pub_r000319_4) & 127;
    table[s_idx_230] = (stage_v_230 + 7) & 63;
    out_sink = (out_sink + stage_v_230) & 255;
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int s_idx_231 = (stage_v_147 & 3);
    int stage_v_231 = (table[s_idx_231] + pub_r000319_2) & 127;
    table[s_idx_231] = (stage_v_231 + 7) & 63;
    out_sink = (out_sink + stage_v_231) & 255;
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int s_idx_232 = (stage_v_131 & 3);
    int stage_v_232 = (table[s_idx_232] + pub_r000319_22) & 127;
    table[s_idx_232] = (stage_v_232 + 7) & 63;
    out_sink = (out_sink + stage_v_232) & 255;
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int s_idx_233 = (sec_r000319_2 & 3);
    int stage_v_233 = (table[s_idx_233] + pub_r000319_23) & 127;
    table[s_idx_233] = (stage_v_233 + 7) & 63;
    out_sink = (out_sink + stage_v_233) & 255;
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int s_idx_234 = (stage_v_41 & 3);
    int stage_v_234 = (table[s_idx_234] + pub_r000319_11) & 127;
    table[s_idx_234] = (stage_v_234 + 7) & 63;
    out_sink = (out_sink + stage_v_234) & 255;
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int s_idx_235 = (stage_v_90 & 3);
    int stage_v_235 = (table[s_idx_235] + pub_r000319_8) & 127;
    table[s_idx_235] = (stage_v_235 + 7) & 63;
    out_sink = (out_sink + stage_v_235) & 255;
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int s_idx_236 = (stage_v_101 & 3);
    int stage_v_236 = (table[s_idx_236] + pub_r000319_17) & 127;
    table[s_idx_236] = (stage_v_236 + 7) & 63;
    out_sink = (out_sink + stage_v_236) & 255;
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int s_idx_237 = (stage_v_102 & 3);
    int stage_v_237 = (table[s_idx_237] + pub_r000319_6) & 127;
    table[s_idx_237] = (stage_v_237 + 7) & 63;
    out_sink = (out_sink + stage_v_237) & 255;
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int s_idx_238 = (stage_v_226 & 3);
    int stage_v_238 = (table[s_idx_238] + pub_r000319_10) & 127;
    table[s_idx_238] = (stage_v_238 + 7) & 63;
    out_sink = (out_sink + stage_v_238) & 255;
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int s_idx_239 = (sec_r000319_14 & 3);
    int stage_v_239 = (table[s_idx_239] + pub_r000319_8) & 127;
    table[s_idx_239] = (stage_v_239 + 7) & 63;
    out_sink = (out_sink + stage_v_239) & 255;
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int s_idx_240 = (stage_v_196 & 3);
    int stage_v_240 = (table[s_idx_240] + pub_r000319_22) & 127;
    table[s_idx_240] = (stage_v_240 + 7) & 63;
    out_sink = (out_sink + stage_v_240) & 255;
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int s_idx_241 = (stage_v_107 & 3);
    int stage_v_241 = (table[s_idx_241] + pub_r000319_15) & 127;
    table[s_idx_241] = (stage_v_241 + 7) & 63;
    out_sink = (out_sink + stage_v_241) & 255;
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int s_idx_242 = (stage_v_73 & 3);
    int stage_v_242 = (table[s_idx_242] + pub_r000319_1) & 127;
    table[s_idx_242] = (stage_v_242 + 7) & 63;
    out_sink = (out_sink + stage_v_242) & 255;
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int s_idx_243 = (sec_r000319_4 & 3);
    int stage_v_243 = (table[s_idx_243] + pub_r000319_10) & 127;
    table[s_idx_243] = (stage_v_243 + 7) & 63;
    out_sink = (out_sink + stage_v_243) & 255;
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int s_idx_244 = (stage_v_197 & 3);
    int stage_v_244 = (table[s_idx_244] + pub_r000319_8) & 127;
    table[s_idx_244] = (stage_v_244 + 7) & 63;
    out_sink = (out_sink + stage_v_244) & 255;
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int s_idx_245 = (sec_r000319_12 & 3);
    int stage_v_245 = (table[s_idx_245] + pub_r000319_17) & 127;
    table[s_idx_245] = (stage_v_245 + 7) & 63;
    out_sink = (out_sink + stage_v_245) & 255;
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int s_idx_246 = (sec_r000319_21 & 3);
    int stage_v_246 = (table[s_idx_246] + pub_r000319_3) & 127;
    table[s_idx_246] = (stage_v_246 + 7) & 63;
    out_sink = (out_sink + stage_v_246) & 255;
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int s_idx_247 = (stage_v_89 & 3);
    int stage_v_247 = (table[s_idx_247] + pub_r000319_15) & 127;
    table[s_idx_247] = (stage_v_247 + 7) & 63;
    out_sink = (out_sink + stage_v_247) & 255;
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int s_idx_248 = (stage_v_169 & 3);
    int stage_v_248 = (table[s_idx_248] + pub_r000319_11) & 127;
    table[s_idx_248] = (stage_v_248 + 7) & 63;
    out_sink = (out_sink + stage_v_248) & 255;
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int s_idx_249 = (stage_v_63 & 3);
    int stage_v_249 = (table[s_idx_249] + pub_r000319_17) & 127;
    table[s_idx_249] = (stage_v_249 + 7) & 63;
    out_sink = (out_sink + stage_v_249) & 255;
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int s_idx_250 = (stage_v_229 & 3);
    int stage_v_250 = (table[s_idx_250] + pub_r000319_18) & 127;
    table[s_idx_250] = (stage_v_250 + 7) & 63;
    out_sink = (out_sink + stage_v_250) & 255;
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int s_idx_251 = (stage_v_220 & 3);
    int stage_v_251 = (table[s_idx_251] + pub_r000319_16) & 127;
    table[s_idx_251] = (stage_v_251 + 7) & 63;
    out_sink = (out_sink + stage_v_251) & 255;
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int s_idx_252 = (stage_v_44 & 3);
    int stage_v_252 = (table[s_idx_252] + pub_r000319_1) & 127;
    table[s_idx_252] = (stage_v_252 + 7) & 63;
    out_sink = (out_sink + stage_v_252) & 255;
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int s_idx_253 = (sec_r000319_9 & 3);
    int stage_v_253 = (table[s_idx_253] + pub_r000319_8) & 127;
    table[s_idx_253] = (stage_v_253 + 7) & 63;
    out_sink = (out_sink + stage_v_253) & 255;
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int s_idx_254 = (sec_r000319_21 & 3);
    int stage_v_254 = (table[s_idx_254] + pub_r000319_20) & 127;
    table[s_idx_254] = (stage_v_254 + 7) & 63;
    out_sink = (out_sink + stage_v_254) & 255;
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int s_idx_255 = (stage_v_91 & 3);
    int stage_v_255 = (table[s_idx_255] + pub_r000319_22) & 127;
    table[s_idx_255] = (stage_v_255 + 7) & 63;
    out_sink = (out_sink + stage_v_255) & 255;
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int s_idx_256 = (sec_r000319_6 & 3);
    int stage_v_256 = (table[s_idx_256] + pub_r000319_22) & 127;
    table[s_idx_256] = (stage_v_256 + 7) & 63;
    out_sink = (out_sink + stage_v_256) & 255;
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
