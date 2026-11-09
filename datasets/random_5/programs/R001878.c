/*
 * Benchmark Program: R001878
 * Security Family: secret_dependent_loops
 * Generator Seed: 687813
 * High Inputs: 23 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R001878_7813_0 {
    short watermark;
    short capacity;
    int checksum;
    short state;
    short head;
    short tail;
    int buffer[3];
};

struct Vector3D_R001878_7813_1 {
    short norm_sq;
    unsigned char pitch;
    short coord_z;
    int buffer[3];
};

struct DeviceConfig_R001878_7813_2 {
    unsigned char parity;
    short baud_rate;
    int id;
    int buffer[3];
};

union TelemetryField_R001878_7813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001878_7813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int residue_55 = (aux + st.buffer[1]) & 3;
    switch (residue_55) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_99 = 0;
    for (int k = 0; k < 3; k++) {
        segment_99 = (segment_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_99) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int window_10 = local_arr[aux % 3];
    acc = (acc + window_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_1(int p0, int p1) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int tracker_59 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_59 = (tracker_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_59) & 127;
    }
    int metric_17 = (aux + st.buffer[1]) & 3;
    switch (metric_17) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001878_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int scale_99 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_99 > 46) {
        acc = (acc + scale_99 * 2 + 5) & 127;
        aux ^= (scale_99 & 15);
    } else {
        acc = (acc - scale_99 + 11) & 127;
        aux += 3;
    }
    int cursor_29 = (aux + st.buffer[1]) & 3;
    switch (cursor_29) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_75 = local_arr[aux % 3];
    acc = (acc + anchor_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int phase_39 = local_arr[aux % 3];
    acc = (acc + phase_39 * 2) & 127;
    int scale_73 = 0;
    for (int k = 0; k < 3; k++) {
        scale_73 = (scale_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_73) & 127;
    }
    int delta_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_19) & 63;
    acc ^= aux;
    int checksum_82 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_82 > 22) {
        acc = (acc + checksum_82 * 2 + 5) & 127;
        aux ^= (checksum_82 & 15);
    } else {
        acc = (acc - checksum_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_76 = (aux + st.buffer[1]) & 3;
    switch (phase_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_68 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_68 > 34) {
        acc = (acc + weight_68 * 2 + 5) & 127;
        aux ^= (weight_68 & 15);
    } else {
        acc = (acc - weight_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_5(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_55 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_55 = (quotient_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_55) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_39) & 63;
    acc ^= aux;
    int mask_80 = (aux + st.buffer[1]) & 3;
    switch (mask_80) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_6(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int scale_14 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_14 > 33) {
        acc = (acc + scale_14 * 2 + 5) & 127;
        aux ^= (scale_14 & 15);
    } else {
        acc = (acc - scale_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_61 = local_arr[aux % 3];
    acc = (acc + margin_61 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int scale_73 = 0;
    for (int k = 0; k < 3; k++) {
        scale_73 = (scale_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + scale_73) & 127;
    }
    int weight_25 = (aux + st.buffer[1]) & 3;
    switch (weight_25) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int margin_48 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_48 > 36) {
        acc = (acc + margin_48 * 2 + 5) & 127;
        aux ^= (margin_48 & 15);
    } else {
        acc = (acc - margin_48 + 11) & 127;
        aux += 3;
    }
    int checksum_37 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_37 = (checksum_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_37) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int bound_26 = local_arr[aux % 3];
    acc = (acc + bound_26 * 2) & 127;
    int parity_94 = (aux + st.buffer[1]) & 3;
    switch (parity_94) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_10(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int segment_76 = 0;
    for (int k = 0; k < 3; k++) {
        segment_76 = (segment_76 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_76) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_65 = local_arr[aux % 3];
    acc = (acc + damping_65 * 2) & 127;
    int metric_46 = (aux + st.buffer[1]) & 3;
    switch (metric_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001878_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int factor_21 = local_arr[aux % 3];
    acc = (acc + factor_21 * 2) & 127;
    int margin_27 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_27 > 29) {
        acc = (acc + margin_27 * 2 + 5) & 127;
        aux ^= (margin_27 & 15);
    } else {
        acc = (acc - margin_27 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_40 = 0;
    for (int k = 0; k < 2; k++) {
        mask_40 = (mask_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_40) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_12(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001878_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int quotient_46 = (aux + st.buffer[1]) & 3;
    switch (quotient_46) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_95 = local_arr[aux % 3];
    acc = (acc + bound_95 * 2) & 127;
    int parity_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_62) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001878_7813_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_87 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_87 = (index_reg_87 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_87) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_14(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int window_32 = (aux + st.buffer[1]) & 3;
    switch (window_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_51 = 0;
    for (int k = 0; k < 3; k++) {
        factor_51 = (factor_51 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_51) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001878_7813_15(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001878_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int metric_14 = (aux + st.buffer[1]) & 3;
    switch (metric_14) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_80 = 0;
    for (int k = 0; k < 3; k++) {
        damping_80 = (damping_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_80) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001878_7813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    int sample_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_17(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001878_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int cursor_50 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_50 = (cursor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_50) & 127;
    }
    int phase_62 = (aux + st.buffer[1]) & 3;
    switch (phase_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_78 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_78 > 37) {
        acc = (acc + weight_78 * 2 + 5) & 127;
        aux ^= (weight_78 & 15);
    } else {
        acc = (acc - weight_78 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int parity_25 = (aux + st.buffer[1]) & 3;
    switch (parity_25) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_68 = 0;
    for (int k = 0; k < 2; k++) {
        phase_68 = (phase_68 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_68) & 127;
    }
    int parity_15 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_15 > 48) {
        acc = (acc + parity_15 * 2 + 5) & 127;
        aux ^= (parity_15 & 15);
    } else {
        acc = (acc - parity_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001878_7813_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_17 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_17 = (coefficient_17 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_17) & 127;
    }
    int scale_88 = (aux + st.buffer[1]) & 3;
    switch (scale_88) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_68 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_68 > 50) {
        acc = (acc + phase_68 * 2 + 5) & 127;
        aux ^= (phase_68 & 15);
    } else {
        acc = (acc - phase_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001878_7813_20(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001878_7813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_73 = (aux + st.buffer[1]) & 3;
    switch (residue_73) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_63 = local_arr[aux % 3];
    acc = (acc + checksum_63 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_42) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001878_0;
    int sec_r001878_1;
    int sec_r001878_2;
    int sec_r001878_3;
    int sec_r001878_4;
    int sec_r001878_5;
    int sec_r001878_6;
    int sec_r001878_7;
    int sec_r001878_8;
    int sec_r001878_9;
    int sec_r001878_10;
    int sec_r001878_11;
    int sec_r001878_12;
    int sec_r001878_13;
    int sec_r001878_14;
    int sec_r001878_15;
    int sec_r001878_16;
    int sec_r001878_17;
    int sec_r001878_18;
    int sec_r001878_19;
    int sec_r001878_20;
    int sec_r001878_21;
    int sec_r001878_22;
    int pub_r001878_0;
    int pub_r001878_1;
    int pub_r001878_2;
    int pub_r001878_3;
    int pub_r001878_4;
    int pub_r001878_5;
    int pub_r001878_6;
    int pub_r001878_7;
    int pub_r001878_8;
    int pub_r001878_9;
    int pub_r001878_10;
    int pub_r001878_11;
    int pub_r001878_12;
    int pub_r001878_13;
    int pub_r001878_14;
    int pub_r001878_15;
    int pub_r001878_16;
    int pub_r001878_17;
    int pub_r001878_18;
    int pub_r001878_19;
    int pub_r001878_20;
    int pub_r001878_21;
    int pub_r001878_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001878_0 >= -100 && pub_r001878_0 <= 100);
    __CPROVER_assume(pub_r001878_1 >= -100 && pub_r001878_1 <= 100);
    __CPROVER_assume(pub_r001878_2 >= -100 && pub_r001878_2 <= 100);
    __CPROVER_assume(pub_r001878_3 >= -100 && pub_r001878_3 <= 100);
    __CPROVER_assume(pub_r001878_4 >= -100 && pub_r001878_4 <= 100);
    __CPROVER_assume(pub_r001878_5 >= -100 && pub_r001878_5 <= 100);
    __CPROVER_assume(pub_r001878_6 >= -100 && pub_r001878_6 <= 100);
    __CPROVER_assume(pub_r001878_7 >= -100 && pub_r001878_7 <= 100);
    __CPROVER_assume(pub_r001878_8 >= -100 && pub_r001878_8 <= 100);
    __CPROVER_assume(pub_r001878_9 >= -100 && pub_r001878_9 <= 100);
    __CPROVER_assume(pub_r001878_10 >= -100 && pub_r001878_10 <= 100);
    __CPROVER_assume(pub_r001878_11 >= -100 && pub_r001878_11 <= 100);
    __CPROVER_assume(pub_r001878_12 >= -100 && pub_r001878_12 <= 100);
    __CPROVER_assume(pub_r001878_13 >= -100 && pub_r001878_13 <= 100);
    __CPROVER_assume(pub_r001878_14 >= -100 && pub_r001878_14 <= 100);
    __CPROVER_assume(pub_r001878_15 >= -100 && pub_r001878_15 <= 100);
    __CPROVER_assume(pub_r001878_16 >= -100 && pub_r001878_16 <= 100);
    __CPROVER_assume(pub_r001878_17 >= -100 && pub_r001878_17 <= 100);
    __CPROVER_assume(pub_r001878_18 >= -100 && pub_r001878_18 <= 100);
    __CPROVER_assume(pub_r001878_19 >= -100 && pub_r001878_19 <= 100);
    __CPROVER_assume(pub_r001878_20 >= -100 && pub_r001878_20 <= 100);
    __CPROVER_assume(pub_r001878_21 >= -100 && pub_r001878_21 <= 100);
    __CPROVER_assume(pub_r001878_22 >= -100 && pub_r001878_22 <= 100);
    __CPROVER_assume(sec_r001878_0 >= 0 && sec_r001878_0 <= 255);
    __CPROVER_assume(sec_r001878_1 >= 0 && sec_r001878_1 <= 255);
    __CPROVER_assume(sec_r001878_2 >= 0 && sec_r001878_2 <= 255);
    __CPROVER_assume(sec_r001878_3 >= 0 && sec_r001878_3 <= 255);
    __CPROVER_assume(sec_r001878_4 >= 0 && sec_r001878_4 <= 255);
    __CPROVER_assume(sec_r001878_5 >= 0 && sec_r001878_5 <= 255);
    __CPROVER_assume(sec_r001878_6 >= 0 && sec_r001878_6 <= 255);
    __CPROVER_assume(sec_r001878_7 >= 0 && sec_r001878_7 <= 255);
    __CPROVER_assume(sec_r001878_8 >= 0 && sec_r001878_8 <= 255);
    __CPROVER_assume(sec_r001878_9 >= 0 && sec_r001878_9 <= 255);
    __CPROVER_assume(sec_r001878_10 >= 0 && sec_r001878_10 <= 255);
    __CPROVER_assume(sec_r001878_11 >= 0 && sec_r001878_11 <= 255);
    __CPROVER_assume(sec_r001878_12 >= 0 && sec_r001878_12 <= 255);
    __CPROVER_assume(sec_r001878_13 >= 0 && sec_r001878_13 <= 255);
    __CPROVER_assume(sec_r001878_14 >= 0 && sec_r001878_14 <= 255);
    __CPROVER_assume(sec_r001878_15 >= 0 && sec_r001878_15 <= 255);
    __CPROVER_assume(sec_r001878_16 >= 0 && sec_r001878_16 <= 255);
    __CPROVER_assume(sec_r001878_17 >= 0 && sec_r001878_17 <= 255);
    __CPROVER_assume(sec_r001878_18 >= 0 && sec_r001878_18 <= 255);
    __CPROVER_assume(sec_r001878_19 >= 0 && sec_r001878_19 <= 255);
    __CPROVER_assume(sec_r001878_20 >= 0 && sec_r001878_20 <= 255);
    __CPROVER_assume(sec_r001878_21 >= 0 && sec_r001878_21 <= 255);
    __CPROVER_assume(sec_r001878_22 >= 0 && sec_r001878_22 <= 255);

    struct StreamBuffer_R001878_7813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001878_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001878_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001878_0 + 7) & 15;
    struct Vector3D_R001878_7813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001878_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001878_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001878_0 + 9) & 15;
    struct DeviceConfig_R001878_7813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001878_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001878_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001878_0 + 11) & 15;

    union TelemetryField_R001878_7813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001878_7813_0(sec_r001878_0, sec_r001878_1, pub_r001878_2, pub_r001878_3, pub_r001878_4);
    int helper_flow_1 = fn_R001878_7813_1(sec_r001878_1, pub_r001878_2);
    int helper_flow_2 = fn_R001878_7813_2(sec_r001878_2, sec_r001878_3, pub_r001878_4, pub_r001878_5);
    int helper_flow_3 = fn_R001878_7813_3(sec_r001878_3, pub_r001878_4, pub_r001878_5, pub_r001878_6);
    int helper_flow_4 = fn_R001878_7813_4(sec_r001878_4, sec_r001878_5, pub_r001878_6, pub_r001878_7);
    int helper_flow_5 = fn_R001878_7813_5(sec_r001878_5, pub_r001878_6, pub_r001878_7);
    int helper_flow_6 = fn_R001878_7813_6(sec_r001878_6, sec_r001878_7);
    int helper_flow_7 = fn_R001878_7813_7(sec_r001878_7, pub_r001878_8, pub_r001878_9, pub_r001878_10);
    int helper_flow_8 = fn_R001878_7813_8(sec_r001878_8, pub_r001878_9, pub_r001878_10, pub_r001878_11);
    int helper_flow_9 = fn_R001878_7813_9(sec_r001878_9, pub_r001878_10, pub_r001878_11, pub_r001878_12);
    int helper_flow_10 = fn_R001878_7813_10(sec_r001878_10, pub_r001878_11, pub_r001878_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001878_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (sec_r001878_15 & 15)) & 63;
        if ((sec_r001878_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001878_21 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001878_22 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001878_4 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001878_18 & 15)) & 63;
        if ((sec_r001878_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (sec_r001878_7 & 15)) & 63;
        if ((sec_r001878_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (sec_r001878_20 & 15)) & 63;
        if ((sec_r001878_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_8 = (stage_v_8 + it * 3 + (sec_r001878_7 & 15)) & 63;
        if ((sec_r001878_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_8 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_8 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001878_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_10 = (stage_v_10 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_10 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_10 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_11 = (stage_v_11 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_11 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_11 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (sec_r001878_11 & 15)) & 63;
        if ((sec_r001878_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001878_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_15 = (stage_v_15 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_15 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_15 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (sec_r001878_16 & 15)) & 63;
        if ((sec_r001878_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_17 = (stage_v_17 + it * 3 + (sec_r001878_16 & 15)) & 63;
        if ((sec_r001878_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_17 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_17 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001878_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (sec_r001878_9 & 15)) & 63;
        if ((sec_r001878_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (sec_r001878_15 & 15)) & 63;
        if ((sec_r001878_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_22 = (stage_v_22 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_22 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_22 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (sec_r001878_19 & 15)) & 63;
        if ((sec_r001878_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_24 = (stage_v_24 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_24 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_24 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001878_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_27 = (stage_v_27 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_27 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_27 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001878_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001878_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001878_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_32 = (stage_v_32 + it * 3 + (sec_r001878_14 & 15)) & 63;
        if ((sec_r001878_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_32 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_32 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_33 = (stage_v_33 + it * 3 + (sec_r001878_17 & 15)) & 63;
        if ((sec_r001878_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_33 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_33 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001878_8 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001878_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001878_21 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001878_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_38 = (stage_v_38 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_38 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_38 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_39 = (stage_v_39 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_39 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_39 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_40 = (stage_v_40 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_40 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_40 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_41 = (stage_v_41 + it * 3 + (sec_r001878_12 & 15)) & 63;
        if ((sec_r001878_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_41 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_41 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001878_6 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (sec_r001878_1 & 15)) & 63;
        if ((sec_r001878_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (sec_r001878_4 & 15)) & 63;
        if ((sec_r001878_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001878_12 & 15)) & 63;
        if ((sec_r001878_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001878_2 & 15)) & 63;
        if ((sec_r001878_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001878_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001878_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001878_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001878_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001878_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_54 = (stage_v_54 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_54 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_54 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (sec_r001878_21 & 15)) & 63;
        if ((sec_r001878_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_56 = (stage_v_56 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_56 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_56 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001878_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001878_8 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001878_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001878_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001878_15 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001878_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001878_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001878_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001878_22 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001878_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_68 = (stage_v_68 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_68 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_68 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001878_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001878_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001878_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (stage_v_10 & 15)) & 63;
        if ((stage_v_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_74 = (stage_v_74 + it * 3 + (sec_r001878_11 & 15)) & 63;
        if ((sec_r001878_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_74 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_74 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001878_20 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001878_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (stage_v_17 & 15)) & 63;
        if ((stage_v_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (sec_r001878_10 & 15)) & 63;
        if ((sec_r001878_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_81 = (stage_v_81 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_81 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_81 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001878_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (sec_r001878_16 & 15)) & 63;
        if ((sec_r001878_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_86 = (stage_v_86 + it * 3 + (sec_r001878_22 & 15)) & 63;
        if ((sec_r001878_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_86 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_86 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001878_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_88 = (stage_v_88 + it * 3 + (sec_r001878_15 & 15)) & 63;
        if ((sec_r001878_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_88 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_88 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_89 = (stage_v_89 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_89 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_89 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001878_19 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (sec_r001878_18 & 15)) & 63;
        if ((sec_r001878_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001878_20 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001878_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001878_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (sec_r001878_7 & 15)) & 63;
        if ((sec_r001878_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001878_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (stage_v_94 & 15)) & 63;
        if ((stage_v_94 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_100 = (stage_v_100 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_100 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_100 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (sec_r001878_8 & 15)) & 63;
        if ((sec_r001878_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001878_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_86 & 15)) & 63;
        if ((stage_v_86 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (stage_v_101 & 15)) & 63;
        if ((stage_v_101 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001878_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001878_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001878_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_108 = (stage_v_108 + it * 3 + (sec_r001878_20 & 15)) & 63;
        if ((sec_r001878_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_108 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_108 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001878_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001878_12 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_89 & 15)) & 63;
        if ((stage_v_89 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_112 = (stage_v_112 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_112 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_112 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_113 = (stage_v_113 + it * 3 + (sec_r001878_22 & 15)) & 63;
        if ((sec_r001878_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_113 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_113 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_115 = (stage_v_115 + it * 3 + (stage_v_103 & 15)) & 63;
        if ((stage_v_103 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_115 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_115 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001878_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001878_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (stage_v_26 & 15)) & 63;
        if ((stage_v_26 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001878_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001878_15 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (sec_r001878_13 & 15)) & 63;
        if ((sec_r001878_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_122 = (stage_v_122 + it * 3 + (stage_v_80 & 15)) & 63;
        if ((stage_v_80 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_122 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_122 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_123 = (stage_v_123 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_123 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_123 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (sec_r001878_10 & 15)) & 63;
        if ((sec_r001878_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001878_21 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (sec_r001878_21 & 15)) & 63;
        if ((sec_r001878_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_128 = (stage_v_128 + it * 3 + (sec_r001878_22 & 15)) & 63;
        if ((sec_r001878_22 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_128 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_128 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001878_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_131 = (stage_v_131 + it * 3 + (stage_v_75 & 15)) & 63;
        if ((stage_v_75 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_131 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_131 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_132 = (stage_v_132 + it * 3 + (stage_v_40 & 15)) & 63;
        if ((stage_v_40 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_132 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_132 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_133 = (stage_v_133 + it * 3 + (sec_r001878_14 & 15)) & 63;
        if ((sec_r001878_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_133 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_133 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_134 = (stage_v_134 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_134 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_134 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001878_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_136 = (stage_v_136 + it * 3 + (sec_r001878_10 & 15)) & 63;
        if ((sec_r001878_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_136 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_136 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001878_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (stage_v_124 & 15)) & 63;
        if ((stage_v_124 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001878_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001878_9 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_141 = (stage_v_141 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_141 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_141 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_142 = (stage_v_142 + it * 3 + (stage_v_94 & 15)) & 63;
        if ((stage_v_94 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_142 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_142 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_143 = (stage_v_143 + it * 3 + (stage_v_89 & 15)) & 63;
        if ((stage_v_89 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_143 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_143 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001878_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_145 = (stage_v_145 + it * 3 + (sec_r001878_10 & 15)) & 63;
        if ((sec_r001878_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_145 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_145 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (stage_v_97 & 15)) & 63;
        if ((stage_v_97 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (sec_r001878_4 & 15)) & 63;
        if ((sec_r001878_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (stage_v_138 & 15)) & 63;
        if ((stage_v_138 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001878_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_41 & 15)) & 63;
        if ((stage_v_41 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_152 = (stage_v_152 + it * 3 + (sec_r001878_2 & 15)) & 63;
        if ((sec_r001878_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_152 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_152 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_153 = (stage_v_153 + it * 3 + (sec_r001878_11 & 15)) & 63;
        if ((sec_r001878_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_153 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_153 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001878_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001878_15 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001878_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001878_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001878_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_159 = (stage_v_159 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_159 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_159 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001878_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (stage_v_74 & 15)) & 63;
        if ((stage_v_74 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001878_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001878_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_166 = (stage_v_166 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_166 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_166 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_167 = (stage_v_167 + it * 3 + (stage_v_54 & 15)) & 63;
        if ((stage_v_54 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_167 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_167 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (stage_v_146 & 15)) & 63;
        if ((stage_v_146 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001878_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_170 = (stage_v_170 + it * 3 + (stage_v_118 & 15)) & 63;
        if ((stage_v_118 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_170 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_170 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_171 = (stage_v_171 + it * 3 + (sec_r001878_3 & 15)) & 63;
        if ((sec_r001878_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_171 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_171 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001878_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_17 & 15)) & 63;
        if ((stage_v_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001878_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_179 = (stage_v_179 + it * 3 + (stage_v_40 & 15)) & 63;
        if ((stage_v_40 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_179 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_179 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (stage_v_148 & 15)) & 63;
        if ((stage_v_148 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001878_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001878_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001878_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001878_21 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (stage_v_45 & 15)) & 63;
        if ((stage_v_45 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001878_22 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001878_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001878_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_192 = (stage_v_192 + it * 3 + (stage_v_177 & 15)) & 63;
        if ((stage_v_177 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_192 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_192 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (stage_v_43 & 15)) & 63;
        if ((stage_v_43 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_194 = (stage_v_194 + it * 3 + (stage_v_131 & 15)) & 63;
        if ((stage_v_131 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_194 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_194 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001878_3 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_196 = (stage_v_196 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_196 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_196 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_198 = (stage_v_198 + it * 3 + (stage_v_163 & 15)) & 63;
        if ((stage_v_163 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_198 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_198 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_200 = (stage_v_200 + it * 3 + (stage_v_173 & 15)) & 63;
        if ((stage_v_173 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_200 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_200 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001878_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001878_5 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001878_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_204 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_204 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_205 = (stage_v_205 + it * 3 + (stage_v_89 & 15)) & 63;
        if ((stage_v_89 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_205 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_205 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_206 = (stage_v_206 + it * 3 + (stage_v_176 & 15)) & 63;
        if ((stage_v_176 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_206 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_206 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001878_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001878_21 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001878_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_210 = (stage_v_210 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_210 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_210 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_211 = (stage_v_211 + it * 3 + (stage_v_200 & 15)) & 63;
        if ((stage_v_200 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_211 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_211 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001878_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001878_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001878_21 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_215 = (stage_v_215 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_215 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_215 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_216 = (stage_v_216 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_216 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_216 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_217 = (stage_v_217 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_217 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_217 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001878_17 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001878_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_220 = (stage_v_220 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_220 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_220 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001878_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_222 = (stage_v_222 + it * 3 + (sec_r001878_1 & 15)) & 63;
        if ((sec_r001878_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_222 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_222 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_223 = (stage_v_223 + it * 3 + (sec_r001878_8 & 15)) & 63;
        if ((sec_r001878_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_223 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_223 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001878_21 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001878_19 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001878_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_227 = (stage_v_227 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_227 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_227 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_228 = (stage_v_228 + it * 3 + (stage_v_145 & 15)) & 63;
        if ((stage_v_145 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_228 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_228 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (pub_r001878_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_229) & 127;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_230 = (stage_v_230 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_230 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_230 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001878_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_232 = (stage_v_232 + it * 3 + (stage_v_128 & 15)) & 63;
        if ((stage_v_128 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_232 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_232 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001878_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001878_4 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001878_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_236 = (stage_v_236 + it * 3 + (stage_v_33 & 15)) & 63;
        if ((stage_v_33 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_236 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_236 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
