/*
 * Benchmark Program: R001097
 * Security Family: nested_implicit_flow
 * Generator Seed: 609713
 * High Inputs: 21 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001097_9713_0 {
    short stop_bits;
    short baud_rate;
    int port;
    int timeout;
    short parity;
    int buffer[3];
};

struct FilterState_R001097_9713_1 {
    int cutoff;
    short prev_in;
    unsigned char mode;
    int prev_out;
    unsigned char gain_db;
    int buffer[3];
};

struct Vector3D_R001097_9713_2 {
    int pitch;
    short coord_x;
    short norm_sq;
    int coord_y;
    int buffer[3];
};

struct StreamBuffer_R001097_9713_3 {
    short checksum;
    int head;
    int capacity;
    int buffer[3];
};

union PacketPayload_R001097_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001097_9713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int sample_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_18) & 63;
    acc ^= aux;
    int parity_26 = (aux + st.buffer[1]) & 3;
    switch (parity_26) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_61 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_61 = (index_reg_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_61) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001097_9713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tally_14 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_14 > 33) {
        acc = (acc + tally_14 * 2 + 5) & 127;
        aux ^= (tally_14 & 15);
    } else {
        acc = (acc - tally_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_89 = 0;
    for (int k = 0; k < 3; k++) {
        bound_89 = (bound_89 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_89) & 127;
    }
    int sample_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001097_9713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_48 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_48 > 38) {
        acc = (acc + residue_48 * 2 + 5) & 127;
        aux ^= (residue_48 & 15);
    } else {
        acc = (acc - residue_48 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_76 = local_arr[aux % 3];
    acc = (acc + stride_76 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001097_9713_3(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int bound_16 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_16 > 36) {
        acc = (acc + bound_16 * 2 + 5) & 127;
        aux ^= (bound_16 & 15);
    } else {
        acc = (acc - bound_16 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_85 = local_arr[aux % 3];
    acc = (acc + metric_85 * 2) & 127;
    int phase_31 = 0;
    for (int k = 0; k < 3; k++) {
        phase_31 = (phase_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_31) & 127;
    }
    int weight_84 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_84) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001097_9713_4(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001097_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int window_38 = 0;
    for (int k = 0; k < 2; k++) {
        window_38 = (window_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_38) & 127;
    }
    int bound_98 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_98 > 49) {
        acc = (acc + bound_98 * 2 + 5) & 127;
        aux ^= (bound_98 & 15);
    } else {
        acc = (acc - bound_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001097_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int coefficient_28 = (aux + st.buffer[1]) & 3;
    switch (coefficient_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_81 = local_arr[aux % 3];
    acc = (acc + residue_81 * 2) & 127;
    int coefficient_63 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_63 = (coefficient_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_63) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_6(int p0, int p1, int p2) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001097_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int tally_26 = 0;
    for (int k = 0; k < 3; k++) {
        tally_26 = (tally_26 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_26) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_47 = local_arr[aux % 3];
    acc = (acc + cursor_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001097_9713_7(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001097_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int factor_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_19) & 63;
    acc ^= aux;
    int coefficient_45 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_45 = (coefficient_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_45) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001097_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int anchor_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_72) & 63;
    acc ^= aux;
    int checksum_12 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_12 = (checksum_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_12) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001097_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int window_77 = (aux + st.buffer[1]) & 3;
    switch (window_77) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_58 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_58 = (checksum_58 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_58) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_10(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_97 = (aux + st.buffer[1]) & 3;
    switch (damping_97) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_25 = local_arr[aux % 3];
    acc = (acc + cursor_25 * 2) & 127;
    int sample_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_85) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001097_9713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001097_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int checksum_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_51) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_29 = local_arr[aux % 3];
    acc = (acc + quotient_29 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001097_9713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int checksum_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_98) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_66 = local_arr[aux % 3];
    acc = (acc + segment_66 * 2) & 127;
    int threshold_58 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_58 > 48) {
        acc = (acc + threshold_58 * 2 + 5) & 127;
        aux ^= (threshold_58 & 15);
    } else {
        acc = (acc - threshold_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001097_9713_13(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001097_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int accumulator_65 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_65 > 42) {
        acc = (acc + accumulator_65 * 2 + 5) & 127;
        aux ^= (accumulator_65 & 15);
    } else {
        acc = (acc - accumulator_65 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001097_9713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001097_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int factor_93 = (aux + st.buffer[1]) & 3;
    switch (factor_93) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_51 = local_arr[aux % 3];
    acc = (acc + delta_51 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_31 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_31 = (checksum_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001097_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int quantum_58 = local_arr[aux % 3];
    acc = (acc + quantum_58 * 2) & 127;
    int quantum_87 = (aux + st.buffer[1]) & 3;
    switch (quantum_87) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_18) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001097_9713_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001097_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001097_9713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001097_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int window_71 = (st.buffer[0] * 3 + aux) & 63;
    if (window_71 > 26) {
        acc = (acc + window_71 * 2 + 5) & 127;
        aux ^= (window_71 & 15);
    } else {
        acc = (acc - window_71 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_32 = local_arr[aux % 3];
    acc = (acc + scale_32 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_39 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_39 = (quantum_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_39) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001097_9713_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001097_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int bound_45 = 0;
    for (int k = 0; k < 3; k++) {
        bound_45 = (bound_45 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_45) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_22) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001097_9713_19(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001097_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int coefficient_20 = (aux + st.buffer[1]) & 3;
    switch (coefficient_20) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001097_0;
    int sec_r001097_1;
    int sec_r001097_2;
    int sec_r001097_3;
    int sec_r001097_4;
    int sec_r001097_5;
    int sec_r001097_6;
    int sec_r001097_7;
    int sec_r001097_8;
    int sec_r001097_9;
    int sec_r001097_10;
    int sec_r001097_11;
    int sec_r001097_12;
    int sec_r001097_13;
    int sec_r001097_14;
    int sec_r001097_15;
    int sec_r001097_16;
    int sec_r001097_17;
    int sec_r001097_18;
    int sec_r001097_19;
    int sec_r001097_20;
    int pub_r001097_0;
    int pub_r001097_1;
    int pub_r001097_2;
    int pub_r001097_3;
    int pub_r001097_4;
    int pub_r001097_5;
    int pub_r001097_6;
    int pub_r001097_7;
    int pub_r001097_8;
    int pub_r001097_9;
    int pub_r001097_10;
    int pub_r001097_11;
    int pub_r001097_12;
    int pub_r001097_13;
    int pub_r001097_14;
    int pub_r001097_15;
    int pub_r001097_16;
    int pub_r001097_17;
    int pub_r001097_18;
    int pub_r001097_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001097_0 >= -100 && pub_r001097_0 <= 100);
    __CPROVER_assume(pub_r001097_1 >= -100 && pub_r001097_1 <= 100);
    __CPROVER_assume(pub_r001097_2 >= -100 && pub_r001097_2 <= 100);
    __CPROVER_assume(pub_r001097_3 >= -100 && pub_r001097_3 <= 100);
    __CPROVER_assume(pub_r001097_4 >= -100 && pub_r001097_4 <= 100);
    __CPROVER_assume(pub_r001097_5 >= -100 && pub_r001097_5 <= 100);
    __CPROVER_assume(pub_r001097_6 >= -100 && pub_r001097_6 <= 100);
    __CPROVER_assume(pub_r001097_7 >= -100 && pub_r001097_7 <= 100);
    __CPROVER_assume(pub_r001097_8 >= -100 && pub_r001097_8 <= 100);
    __CPROVER_assume(pub_r001097_9 >= -100 && pub_r001097_9 <= 100);
    __CPROVER_assume(pub_r001097_10 >= -100 && pub_r001097_10 <= 100);
    __CPROVER_assume(pub_r001097_11 >= -100 && pub_r001097_11 <= 100);
    __CPROVER_assume(pub_r001097_12 >= -100 && pub_r001097_12 <= 100);
    __CPROVER_assume(pub_r001097_13 >= -100 && pub_r001097_13 <= 100);
    __CPROVER_assume(pub_r001097_14 >= -100 && pub_r001097_14 <= 100);
    __CPROVER_assume(pub_r001097_15 >= -100 && pub_r001097_15 <= 100);
    __CPROVER_assume(pub_r001097_16 >= -100 && pub_r001097_16 <= 100);
    __CPROVER_assume(pub_r001097_17 >= -100 && pub_r001097_17 <= 100);
    __CPROVER_assume(pub_r001097_18 >= -100 && pub_r001097_18 <= 100);
    __CPROVER_assume(pub_r001097_19 >= -100 && pub_r001097_19 <= 100);
    __CPROVER_assume(sec_r001097_0 >= 0 && sec_r001097_0 <= 255);
    __CPROVER_assume(sec_r001097_1 >= 0 && sec_r001097_1 <= 255);
    __CPROVER_assume(sec_r001097_2 >= 0 && sec_r001097_2 <= 255);
    __CPROVER_assume(sec_r001097_3 >= 0 && sec_r001097_3 <= 255);
    __CPROVER_assume(sec_r001097_4 >= 0 && sec_r001097_4 <= 255);
    __CPROVER_assume(sec_r001097_5 >= 0 && sec_r001097_5 <= 255);
    __CPROVER_assume(sec_r001097_6 >= 0 && sec_r001097_6 <= 255);
    __CPROVER_assume(sec_r001097_7 >= 0 && sec_r001097_7 <= 255);
    __CPROVER_assume(sec_r001097_8 >= 0 && sec_r001097_8 <= 255);
    __CPROVER_assume(sec_r001097_9 >= 0 && sec_r001097_9 <= 255);
    __CPROVER_assume(sec_r001097_10 >= 0 && sec_r001097_10 <= 255);
    __CPROVER_assume(sec_r001097_11 >= 0 && sec_r001097_11 <= 255);
    __CPROVER_assume(sec_r001097_12 >= 0 && sec_r001097_12 <= 255);
    __CPROVER_assume(sec_r001097_13 >= 0 && sec_r001097_13 <= 255);
    __CPROVER_assume(sec_r001097_14 >= 0 && sec_r001097_14 <= 255);
    __CPROVER_assume(sec_r001097_15 >= 0 && sec_r001097_15 <= 255);
    __CPROVER_assume(sec_r001097_16 >= 0 && sec_r001097_16 <= 255);
    __CPROVER_assume(sec_r001097_17 >= 0 && sec_r001097_17 <= 255);
    __CPROVER_assume(sec_r001097_18 >= 0 && sec_r001097_18 <= 255);
    __CPROVER_assume(sec_r001097_19 >= 0 && sec_r001097_19 <= 255);
    __CPROVER_assume(sec_r001097_20 >= 0 && sec_r001097_20 <= 255);

    struct DeviceConfig_R001097_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001097_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001097_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001097_0 + 7) & 15;
    struct FilterState_R001097_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001097_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001097_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001097_0 + 9) & 15;
    struct Vector3D_R001097_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001097_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001097_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001097_0 + 11) & 15;
    struct StreamBuffer_R001097_9713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001097_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001097_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001097_0 + 13) & 15;

    union PacketPayload_R001097_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001097_9713_0(sec_r001097_0, pub_r001097_1, pub_r001097_2, pub_r001097_3);
    int helper_flow_1 = fn_R001097_9713_1(sec_r001097_1, pub_r001097_2, pub_r001097_3, pub_r001097_4, pub_r001097_5);
    int helper_flow_2 = fn_R001097_9713_2(sec_r001097_2, sec_r001097_3, pub_r001097_4, pub_r001097_5, pub_r001097_6);
    int helper_flow_3 = fn_R001097_9713_3(sec_r001097_3, pub_r001097_4, pub_r001097_5);
    int helper_flow_4 = fn_R001097_9713_4(sec_r001097_4, sec_r001097_5);
    int helper_flow_5 = fn_R001097_9713_5(sec_r001097_5, sec_r001097_6, pub_r001097_7, pub_r001097_8, pub_r001097_9);
    int helper_flow_6 = fn_R001097_9713_6(sec_r001097_6, pub_r001097_7, pub_r001097_8);
    int helper_flow_7 = fn_R001097_9713_7(sec_r001097_7, pub_r001097_8, pub_r001097_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001097_16 ^ pub_r001097_13) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001097_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001097_17 ^ pub_r001097_2) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((sec_r001097_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001097_20 ^ pub_r001097_1) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001097_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001097_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_5 ^ pub_r001097_19) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001097_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001097_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001097_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001097_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001097_17 ^ pub_r001097_11) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001097_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001097_14 ^ pub_r001097_14) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r001097_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001097_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001097_18 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001097_5 ^ pub_r001097_2) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001097_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001097_17 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001097_10 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001097_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001097_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_7 ^ pub_r001097_6) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_7 ^ pub_r001097_11) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001097_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_5 ^ pub_r001097_4) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r001097_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001097_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001097_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001097_17 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_19 ^ pub_r001097_16) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001097_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001097_10 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001097_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (stage_v_10 ^ pub_r001097_13) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (sec_r001097_0 ^ pub_r001097_5) & 63;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r001097_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_28 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_28 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_28 * 2) & 255;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001097_6 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001097_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001097_16 ^ pub_r001097_5) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (stage_v_1 ^ pub_r001097_18) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001097_20 ^ pub_r001097_1) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (sec_r001097_8 ^ pub_r001097_1) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((stage_v_28 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_13 ^ pub_r001097_0) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001097_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001097_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001097_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_27 ^ pub_r001097_14) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r001097_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (helper_flow_4 ^ pub_r001097_17) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001097_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_10 ^ pub_r001097_17) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001097_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001097_17 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (stage_v_9 ^ pub_r001097_12) & 63;
    if ((stage_v_43 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_43 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_43 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_43 * 2) & 255;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001097_2 ^ pub_r001097_19) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001097_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001097_6 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (sec_r001097_4 ^ pub_r001097_7) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_19 ^ pub_r001097_15) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001097_8 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001097_9 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_33 ^ pub_r001097_15) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r001097_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_24 ^ pub_r001097_2) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001097_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_18 ^ pub_r001097_3) & 63;
    if ((stage_v_53 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_53 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_53 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_53 * 2) & 255;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (sec_r001097_7 ^ pub_r001097_5) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001097_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001097_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001097_13 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001097_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_54 ^ pub_r001097_16) & 63;
    if ((stage_v_59 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_59 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_59 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_59 * 2) & 255;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_35 ^ pub_r001097_3) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001097_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001097_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_54 ^ pub_r001097_7) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r001097_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_62 ^ pub_r001097_4) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001097_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (helper_flow_3 ^ pub_r001097_17) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r001097_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_48 ^ pub_r001097_8) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_6 ^ pub_r001097_14) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (helper_flow_3 ^ pub_r001097_4) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_19 ^ pub_r001097_1) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001097_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_40 ^ pub_r001097_18) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r001097_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_48 ^ pub_r001097_11) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_53 ^ pub_r001097_8) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_9 ^ pub_r001097_10) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r001097_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (sec_r001097_15 ^ pub_r001097_12) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001097_2 ^ pub_r001097_7) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_65 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001097_12 ^ pub_r001097_2) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r001097_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001097_4 ^ pub_r001097_11) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001097_17 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (sec_r001097_0 ^ pub_r001097_10) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_63 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_40 ^ pub_r001097_0) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001097_3 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_6 ^ pub_r001097_19) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r001097_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001097_1 ^ pub_r001097_11) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r001097_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001097_1 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (sec_r001097_18 ^ pub_r001097_6) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_38 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_28 ^ pub_r001097_6) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001097_1 ^ pub_r001097_15) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001097_10 ^ pub_r001097_8) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r001097_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001097_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001097_9 ^ pub_r001097_18) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_20 ^ pub_r001097_16) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (sec_r001097_0 ^ pub_r001097_7) & 63;
    if ((stage_v_91 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_91 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_91 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001097_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_86 ^ pub_r001097_15) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001097_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001097_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_10 ^ pub_r001097_15) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001097_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (sec_r001097_6 ^ pub_r001097_2) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001097_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_10 ^ pub_r001097_8) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (helper_flow_3 ^ pub_r001097_10) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_54 ^ pub_r001097_11) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r001097_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_79 ^ pub_r001097_9) & 63;
    if ((stage_v_102 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_102 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_102 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_90 ^ pub_r001097_8) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001097_1 ^ pub_r001097_1) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_39 ^ pub_r001097_13) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_74 ^ pub_r001097_17) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001097_2 ^ pub_r001097_6) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001097_2 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (sec_r001097_3 ^ pub_r001097_13) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_47 ^ pub_r001097_12) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_69 ^ pub_r001097_5) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (sec_r001097_19 ^ pub_r001097_17) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((sec_r001097_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001097_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_1 ^ pub_r001097_12) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_81 ^ pub_r001097_15) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (sec_r001097_12 ^ pub_r001097_4) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001097_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001097_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001097_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_85 ^ pub_r001097_7) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_18 ^ pub_r001097_12) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_93 ^ pub_r001097_19) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_102 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_33 ^ pub_r001097_17) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_114 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_1 ^ pub_r001097_3) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_44 ^ pub_r001097_10) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_34 ^ pub_r001097_18) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((sec_r001097_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001097_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_93 ^ pub_r001097_17) & 63;
    if ((stage_v_127 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_127 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_127 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001097_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001097_3 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_87 ^ pub_r001097_13) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (sec_r001097_6 ^ pub_r001097_8) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001097_17 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_73 ^ pub_r001097_16) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001097_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (sec_r001097_14 ^ pub_r001097_12) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_68 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001097_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_74 ^ pub_r001097_2) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001097_2 ^ pub_r001097_11) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001097_19 ^ pub_r001097_13) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_115 ^ pub_r001097_10) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((sec_r001097_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_60 ^ pub_r001097_8) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_122 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001097_13 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_62 ^ pub_r001097_17) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r001097_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001097_15 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_135 ^ pub_r001097_19) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_69 ^ pub_r001097_7) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_137 ^ pub_r001097_1) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r001097_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_82 ^ pub_r001097_0) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((sec_r001097_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001097_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_112 ^ pub_r001097_10) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((sec_r001097_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001097_19 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_20 ^ pub_r001097_8) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_90 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001097_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (sec_r001097_2 ^ pub_r001097_5) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_85 ^ pub_r001097_11) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (sec_r001097_5 ^ pub_r001097_9) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_65 ^ pub_r001097_3) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_81 ^ pub_r001097_9) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001097_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_43 ^ pub_r001097_11) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_7 ^ pub_r001097_11) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_127 ^ pub_r001097_2) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001097_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001097_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (sec_r001097_17 ^ pub_r001097_6) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_133 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_4 ^ pub_r001097_2) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_127 ^ pub_r001097_16) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((sec_r001097_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_141 ^ pub_r001097_5) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001097_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (helper_flow_0 ^ pub_r001097_7) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_87 ^ pub_r001097_10) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (helper_flow_7 ^ pub_r001097_12) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001097_11 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (stage_v_166 ^ pub_r001097_13) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_43 ^ pub_r001097_3) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_145 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_168 ^ pub_r001097_13) & 63;
    if ((stage_v_176 & 1) != 0) {
        if ((stage_v_139 & 2) != 0) {
            out_sink = (out_sink + stage_v_176 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_176 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (stage_v_135 ^ pub_r001097_17) & 63;
    if ((stage_v_177 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_177 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_177 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (pub_r001097_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_178) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_81 ^ pub_r001097_18) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_2 ^ pub_r001097_16) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (helper_flow_6 ^ pub_r001097_0) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001097_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_135 ^ pub_r001097_14) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_84 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (sec_r001097_5 ^ pub_r001097_17) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_160 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_172 ^ pub_r001097_11) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_183 ^ pub_r001097_19) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_158 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_150 ^ pub_r001097_11) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (stage_v_187 ^ pub_r001097_19) & 63;
    if ((stage_v_188 & 1) != 0) {
        if ((stage_v_123 & 2) != 0) {
            out_sink = (out_sink + stage_v_188 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_188 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_135 ^ pub_r001097_11) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((stage_v_135 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001097_10 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_59 ^ pub_r001097_13) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_31 ^ pub_r001097_3) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_43 ^ pub_r001097_2) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_155 ^ pub_r001097_3) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((stage_v_120 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001097_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001097_2 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_170 ^ pub_r001097_18) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001097_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_52 ^ pub_r001097_11) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_59 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001097_0 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_100 ^ pub_r001097_13) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_47 ^ pub_r001097_0) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_75 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001097_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_74 ^ pub_r001097_4) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((stage_v_180 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_82 ^ pub_r001097_14) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
