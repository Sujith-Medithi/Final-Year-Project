/*
 * Benchmark Program: R001160
 * Security Family: mixed_control_data
 * Generator Seed: 616013
 * High Inputs: 23 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001160_6013_0 {
    int nonce;
    int iv;
    short counter;
    int buffer[3];
};

struct Vector3D_R001160_6013_1 {
    int coord_z;
    int coord_x;
    short norm_sq;
    int heading;
    unsigned char coord_y;
    int buffer[3];
};

struct DeviceConfig_R001160_6013_2 {
    int parity;
    short timeout;
    int id;
    int baud_rate;
    int port;
    int buffer[3];
};

struct Transaction_R001160_6013_3 {
    int fee;
    int account_id;
    int auth_code;
    int buffer[3];
};

union PacketPayload_R001160_6013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R001160_6013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001160_6013_0(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001160_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_19 = (aux + st.buffer[1]) & 3;
    switch (index_reg_19) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_87) & 63;
    acc ^= aux;
    int window_17 = (st.buffer[0] * 3 + aux) & 63;
    if (window_17 > 25) {
        acc = (acc + window_17 * 2 + 5) & 127;
        aux ^= (window_17 & 15);
    } else {
        acc = (acc - window_17 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_1(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001160_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int coefficient_29 = local_arr[aux % 3];
    acc = (acc + coefficient_29 * 2) & 127;
    int cursor_15 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_15 > 16) {
        acc = (acc + cursor_15 * 2 + 5) & 127;
        aux ^= (cursor_15 & 15);
    } else {
        acc = (acc - cursor_15 + 11) & 127;
        aux += 3;
    }
    int mask_20 = (aux + st.buffer[1]) & 3;
    switch (mask_20) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001160_6013_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001160_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int quantum_81 = (aux + st.buffer[1]) & 3;
    switch (quantum_81) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001160_6013_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001160_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int scale_83 = (aux + st.buffer[1]) & 3;
    switch (scale_83) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_32 = 0;
    for (int k = 0; k < 2; k++) {
        margin_32 = (margin_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_32) & 127;
    }
    int checksum_20 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_20 > 19) {
        acc = (acc + checksum_20 * 2 + 5) & 127;
        aux ^= (checksum_20 & 15);
    } else {
        acc = (acc - checksum_20 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_4(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001160_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_80 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_80 > 17) {
        acc = (acc + stride_80 * 2 + 5) & 127;
        aux ^= (stride_80 & 15);
    } else {
        acc = (acc - stride_80 + 11) & 127;
        aux += 3;
    }
    int damping_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001160_6013_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001160_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int accumulator_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_39) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_30 = local_arr[aux % 3];
    acc = (acc + residue_30 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001160_6013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001160_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int parity_97 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_97 > 14) {
        acc = (acc + parity_97 * 2 + 5) & 127;
        aux ^= (parity_97 & 15);
    } else {
        acc = (acc - parity_97 + 11) & 127;
        aux += 3;
    }
    int cursor_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_85) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_97 = local_arr[aux % 3];
    acc = (acc + pivot_97 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001160_6013_7(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001160_6013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int pivot_64 = (aux + st.buffer[1]) & 3;
    switch (pivot_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_43 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_43 > 10) {
        acc = (acc + phase_43 * 2 + 5) & 127;
        aux ^= (phase_43 & 15);
    } else {
        acc = (acc - phase_43 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_8(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001160_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int tracker_50 = (aux + st.buffer[1]) & 3;
    switch (tracker_50) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001160_6013_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001160_6013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int factor_21 = 0;
    for (int k = 0; k < 2; k++) {
        factor_21 = (factor_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_21) & 127;
    }
    int quantum_45 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_45 > 23) {
        acc = (acc + quantum_45 * 2 + 5) & 127;
        aux ^= (quantum_45 & 15);
    } else {
        acc = (acc - quantum_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_10(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001160_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_54 > 13) {
        acc = (acc + anchor_54 * 2 + 5) & 127;
        aux ^= (anchor_54 & 15);
    } else {
        acc = (acc - anchor_54 + 11) & 127;
        aux += 3;
    }
    int segment_77 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_77) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001160_6013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001160_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int local_arr[3] = {4, 9, 15};
    int cursor_27 = local_arr[aux % 3];
    acc = (acc + cursor_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_91 = (aux + st.buffer[1]) & 3;
    switch (parity_91) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_46 = (st.buffer[0] * 3 + aux) & 63;
    if (window_46 > 42) {
        acc = (acc + window_46 * 2 + 5) & 127;
        aux ^= (window_46 & 15);
    } else {
        acc = (acc - window_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_12(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001160_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int pivot_21 = 0;
    for (int k = 0; k < 2; k++) {
        pivot_21 = (pivot_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_21) & 127;
    }
    int quantum_55 = (aux + st.buffer[1]) & 3;
    switch (quantum_55) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_47 = local_arr[aux % 3];
    acc = (acc + checksum_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001160_6013_13(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001160_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int pivot_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_71) & 63;
    acc ^= aux;
    int quantum_78 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_78 > 48) {
        acc = (acc + quantum_78 * 2 + 5) & 127;
        aux ^= (quantum_78 & 15);
    } else {
        acc = (acc - quantum_78 + 11) & 127;
        aux += 3;
    }
    int scale_22 = (aux + st.buffer[1]) & 3;
    switch (scale_22) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_14(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001160_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int quantum_62 = local_arr[aux % 3];
    acc = (acc + quantum_62 * 2) & 127;
    int metric_70 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_70) & 63;
    acc ^= aux;
    int checksum_62 = (aux + st.buffer[1]) & 3;
    switch (checksum_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001160_6013_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001160_6013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int weight_72 = local_arr[aux % 3];
    acc = (acc + weight_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_20 = 0;
    for (int k = 0; k < 3; k++) {
        margin_20 = (margin_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_20) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001160_6013_16(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001160_6013_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int pivot_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_92) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int cursor_51 = local_arr[aux % 3];
    acc = (acc + cursor_51 * 2) & 127;
    int coefficient_55 = 0;
    for (int k = 0; k < 3; k++) {
        coefficient_55 = (coefficient_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_55) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001160_0;
    int sec_r001160_1;
    int sec_r001160_2;
    int sec_r001160_3;
    int sec_r001160_4;
    int sec_r001160_5;
    int sec_r001160_6;
    int sec_r001160_7;
    int sec_r001160_8;
    int sec_r001160_9;
    int sec_r001160_10;
    int sec_r001160_11;
    int sec_r001160_12;
    int sec_r001160_13;
    int sec_r001160_14;
    int sec_r001160_15;
    int sec_r001160_16;
    int sec_r001160_17;
    int sec_r001160_18;
    int sec_r001160_19;
    int sec_r001160_20;
    int sec_r001160_21;
    int sec_r001160_22;
    int pub_r001160_0;
    int pub_r001160_1;
    int pub_r001160_2;
    int pub_r001160_3;
    int pub_r001160_4;
    int pub_r001160_5;
    int pub_r001160_6;
    int pub_r001160_7;
    int pub_r001160_8;
    int pub_r001160_9;
    int pub_r001160_10;
    int pub_r001160_11;
    int pub_r001160_12;
    int pub_r001160_13;
    int pub_r001160_14;
    int pub_r001160_15;
    int pub_r001160_16;
    int pub_r001160_17;
    int pub_r001160_18;
    int pub_r001160_19;
    int pub_r001160_20;
    int pub_r001160_21;
    int pub_r001160_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001160_0 >= -100 && pub_r001160_0 <= 100);
    __CPROVER_assume(pub_r001160_1 >= -100 && pub_r001160_1 <= 100);
    __CPROVER_assume(pub_r001160_2 >= -100 && pub_r001160_2 <= 100);
    __CPROVER_assume(pub_r001160_3 >= -100 && pub_r001160_3 <= 100);
    __CPROVER_assume(pub_r001160_4 >= -100 && pub_r001160_4 <= 100);
    __CPROVER_assume(pub_r001160_5 >= -100 && pub_r001160_5 <= 100);
    __CPROVER_assume(pub_r001160_6 >= -100 && pub_r001160_6 <= 100);
    __CPROVER_assume(pub_r001160_7 >= -100 && pub_r001160_7 <= 100);
    __CPROVER_assume(pub_r001160_8 >= -100 && pub_r001160_8 <= 100);
    __CPROVER_assume(pub_r001160_9 >= -100 && pub_r001160_9 <= 100);
    __CPROVER_assume(pub_r001160_10 >= -100 && pub_r001160_10 <= 100);
    __CPROVER_assume(pub_r001160_11 >= -100 && pub_r001160_11 <= 100);
    __CPROVER_assume(pub_r001160_12 >= -100 && pub_r001160_12 <= 100);
    __CPROVER_assume(pub_r001160_13 >= -100 && pub_r001160_13 <= 100);
    __CPROVER_assume(pub_r001160_14 >= -100 && pub_r001160_14 <= 100);
    __CPROVER_assume(pub_r001160_15 >= -100 && pub_r001160_15 <= 100);
    __CPROVER_assume(pub_r001160_16 >= -100 && pub_r001160_16 <= 100);
    __CPROVER_assume(pub_r001160_17 >= -100 && pub_r001160_17 <= 100);
    __CPROVER_assume(pub_r001160_18 >= -100 && pub_r001160_18 <= 100);
    __CPROVER_assume(pub_r001160_19 >= -100 && pub_r001160_19 <= 100);
    __CPROVER_assume(pub_r001160_20 >= -100 && pub_r001160_20 <= 100);
    __CPROVER_assume(pub_r001160_21 >= -100 && pub_r001160_21 <= 100);
    __CPROVER_assume(pub_r001160_22 >= -100 && pub_r001160_22 <= 100);
    __CPROVER_assume(sec_r001160_0 >= 0 && sec_r001160_0 <= 255);
    __CPROVER_assume(sec_r001160_1 >= 0 && sec_r001160_1 <= 255);
    __CPROVER_assume(sec_r001160_2 >= 0 && sec_r001160_2 <= 255);
    __CPROVER_assume(sec_r001160_3 >= 0 && sec_r001160_3 <= 255);
    __CPROVER_assume(sec_r001160_4 >= 0 && sec_r001160_4 <= 255);
    __CPROVER_assume(sec_r001160_5 >= 0 && sec_r001160_5 <= 255);
    __CPROVER_assume(sec_r001160_6 >= 0 && sec_r001160_6 <= 255);
    __CPROVER_assume(sec_r001160_7 >= 0 && sec_r001160_7 <= 255);
    __CPROVER_assume(sec_r001160_8 >= 0 && sec_r001160_8 <= 255);
    __CPROVER_assume(sec_r001160_9 >= 0 && sec_r001160_9 <= 255);
    __CPROVER_assume(sec_r001160_10 >= 0 && sec_r001160_10 <= 255);
    __CPROVER_assume(sec_r001160_11 >= 0 && sec_r001160_11 <= 255);
    __CPROVER_assume(sec_r001160_12 >= 0 && sec_r001160_12 <= 255);
    __CPROVER_assume(sec_r001160_13 >= 0 && sec_r001160_13 <= 255);
    __CPROVER_assume(sec_r001160_14 >= 0 && sec_r001160_14 <= 255);
    __CPROVER_assume(sec_r001160_15 >= 0 && sec_r001160_15 <= 255);
    __CPROVER_assume(sec_r001160_16 >= 0 && sec_r001160_16 <= 255);
    __CPROVER_assume(sec_r001160_17 >= 0 && sec_r001160_17 <= 255);
    __CPROVER_assume(sec_r001160_18 >= 0 && sec_r001160_18 <= 255);
    __CPROVER_assume(sec_r001160_19 >= 0 && sec_r001160_19 <= 255);
    __CPROVER_assume(sec_r001160_20 >= 0 && sec_r001160_20 <= 255);
    __CPROVER_assume(sec_r001160_21 >= 0 && sec_r001160_21 <= 255);
    __CPROVER_assume(sec_r001160_22 >= 0 && sec_r001160_22 <= 255);

    struct CipherContext_R001160_6013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001160_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001160_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001160_0 + 7) & 15;
    struct Vector3D_R001160_6013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001160_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001160_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001160_0 + 9) & 15;
    struct DeviceConfig_R001160_6013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001160_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001160_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001160_0 + 11) & 15;
    struct Transaction_R001160_6013_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001160_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001160_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001160_0 + 13) & 15;

    union PacketPayload_R001160_6013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001160_6013_0(sec_r001160_0, sec_r001160_1, pub_r001160_2);
    int helper_flow_1 = fn_R001160_6013_1(sec_r001160_1, pub_r001160_2);
    int helper_flow_2 = fn_R001160_6013_2(sec_r001160_2, pub_r001160_3, pub_r001160_4, pub_r001160_5);
    int helper_flow_3 = fn_R001160_6013_3(sec_r001160_3, sec_r001160_4, pub_r001160_5, pub_r001160_6);
    int helper_flow_4 = fn_R001160_6013_4(sec_r001160_4, pub_r001160_5, pub_r001160_6);
    int helper_flow_5 = fn_R001160_6013_5(sec_r001160_5, sec_r001160_6, pub_r001160_7, pub_r001160_8);
    int helper_flow_6 = fn_R001160_6013_6(sec_r001160_6, pub_r001160_7, pub_r001160_8, pub_r001160_9, pub_r001160_10);
    int helper_flow_7 = fn_R001160_6013_7(sec_r001160_7, sec_r001160_8, pub_r001160_9);
    int helper_flow_8 = fn_R001160_6013_8(sec_r001160_8, sec_r001160_9);
    int helper_flow_9 = fn_R001160_6013_9(sec_r001160_9, sec_r001160_10, pub_r001160_11, pub_r001160_12, pub_r001160_13);
    int helper_flow_10 = fn_R001160_6013_10(sec_r001160_10, pub_r001160_11, pub_r001160_12);
    int helper_flow_11 = fn_R001160_6013_11(sec_r001160_11, sec_r001160_12, pub_r001160_13, pub_r001160_14, pub_r001160_15);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001160_3 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_1 > 41) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001160_2 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_3 > 47) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001160_6 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_4 > 49) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001160_2 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_5 > 29) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001160_9 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_6 > 32) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001160_16 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001160_16 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001160_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001160_4 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_10 > 22) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001160_19 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_11 > 34) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001160_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_13 > 34) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001160_21 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001160_8) & 127;
    if (stage_v_15 > 26) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001160_6 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001160_7 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001160_9 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_18 > 37) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_19 > 22) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_20 > 39) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001160_0 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_21 > 28) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001160_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_23 > 24) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_24 > 50) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001160_12 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_25 > 47) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_26 > 39) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_27 > 46) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_28 > 27) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_29 > 37) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((sec_r001160_20 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_30 > 25) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001160_6 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_31 > 45) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_32 > 32) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001160_20) & 127;
    if (stage_v_33 > 22) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001160_6) & 127;
    if (stage_v_34 > 23) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_35 > 35) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_36 > 36) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001160_14 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001160_1 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_38 > 22) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_39 > 40) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001160_18 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_40 > 31) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_34 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_41 > 50) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_42 > 34) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_43 > 29) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r001160_14 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_44 > 25) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001160_7 ^ 0x2A) * 2 + pub_r001160_8) & 127;
    if (stage_v_45 > 36) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_46 > 47) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_47 > 24) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_48 > 41) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((sec_r001160_2 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_50 > 35) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_51 > 46) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001160_4 ^ 0x2A) * 2 + pub_r001160_8) & 127;
    if (stage_v_52 > 32) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001160_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r001160_1 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_54 > 23) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_38 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_55 > 27) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001160_12) & 127;
    if (stage_v_56 > 38) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r001160_9 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_57 > 44) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001160_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_59 > 39) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001160_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001160_20) & 127;
    if (stage_v_61 > 31) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001160_6) & 127;
    if (stage_v_62 > 26) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001160_6 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001160_4) & 127;
    if (stage_v_64 > 27) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_65 > 50) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r001160_0 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_66 > 50) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001160_20 ^ 0x2A) * 2 + pub_r001160_12) & 127;
    if (stage_v_67 > 24) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001160_14 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_69 > 34) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001160_20 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_71 > 37) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001160_16 ^ 0x2A) * 2 + pub_r001160_6) & 127;
    if (stage_v_72 > 23) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r001160_16 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_73 > 21) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001160_8) & 127;
    if (stage_v_74 > 34) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((sec_r001160_6 ^ 0x2A) * 2 + pub_r001160_20) & 127;
    if (stage_v_75 > 46) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001160_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_77 > 34) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_78 > 33) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001160_1 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_79 > 48) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_80 > 41) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_81 > 45) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_82 > 38) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_83 > 22) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r001160_13 ^ 0x2A) * 2 + pub_r001160_12) & 127;
    if (stage_v_84 > 45) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001160_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_86 > 20) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001160_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001160_0 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001160_22 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001160_17) & 127;
    if (stage_v_90 > 33) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r001160_7 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_91 > 35) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_92 > 31) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r001160_5 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_93 > 48) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r001160_19 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_94 > 22) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_95 > 30) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_96 > 42) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_44 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_97 > 22) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001160_20) & 127;
    if (stage_v_98 > 45) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_99 > 24) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001160_2 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_101 > 25) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_102 > 34) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001160_3 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_104 > 27) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001160_12 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001160_17) & 127;
    if (stage_v_106 > 36) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001160_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_108 > 45) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_109 > 34) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001160_6) & 127;
    if (stage_v_110 > 30) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_111 > 27) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((sec_r001160_9 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_112 > 29) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((helper_flow_11 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_113 > 38) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001160_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001160_20 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001160_12 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001160_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001160_20 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_118 > 29) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001160_8 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_119 > 26) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001160_10 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_121 > 39) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_122 > 38) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_123 > 42) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_97 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_124 > 22) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_125 > 46) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_59 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_126 > 49) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r001160_10 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_127 > 23) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_128 > 25) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r001160_4 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_129 > 48) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001160_22 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_121 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_131 > 35) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_62 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_132 > 36) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_133 > 37) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001160_4) & 127;
    if (stage_v_134 > 28) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r001160_4 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_135 > 44) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_136 > 22) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_95 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_137 > 45) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_138 > 42) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_139 > 40) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_140 > 28) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001160_18 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_98 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_142 > 39) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001160_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001160_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_127 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_145 > 30) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_146 > 21) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001160_6) & 127;
    if (stage_v_147 > 37) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_148 > 21) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_149 > 42) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_150 > 36) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_151 > 27) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001160_11) & 127;
    if (stage_v_152 > 28) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001160_5) & 127;
    if (stage_v_153 > 33) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_154 > 32) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_155 > 47) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001160_4) & 127;
    if (stage_v_156 > 44) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001160_8 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001160_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_159 > 48) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001160_11) & 127;
    if (stage_v_160 > 35) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_161 > 23) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001160_22 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_163 > 46) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001160_4) & 127;
    if (stage_v_164 > 38) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_165 > 32) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r001160_18 ^ 0x2A) * 2 + pub_r001160_10) & 127;
    if (stage_v_166 > 50) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((sec_r001160_21 ^ 0x2A) * 2 + pub_r001160_17) & 127;
    if (stage_v_167 > 41) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_168 > 38) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001160_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_170 > 46) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_171 > 31) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001160_12 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_172 > 40) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_173 > 42) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_174 > 45) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_175 > 32) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_154 ^ 0x2A) * 2 + pub_r001160_12) & 127;
    if (stage_v_176 > 26) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((helper_flow_9 ^ 0x2A) * 2 + pub_r001160_8) & 127;
    if (stage_v_177 > 29) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_178 > 21) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001160_11 ^ 0x2A) * 2 + pub_r001160_17) & 127;
    if (stage_v_179 > 36) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001160_11) & 127;
    if (stage_v_180 > 34) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001160_11) & 127;
    if (stage_v_181 > 26) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001160_14) & 127;
    if (stage_v_182 > 24) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001160_16 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001160_16 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001160_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001160_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001160_21) & 127;
    if (stage_v_187 > 29) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001160_22) & 127;
    if (stage_v_188 > 39) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001160_2) & 127;
    if (stage_v_189 > 31) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001160_11) & 127;
    if (stage_v_190 > 50) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001160_20) & 127;
    if (stage_v_191 > 49) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001160_20) & 127;
    if (stage_v_192 > 48) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001160_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_194 > 33) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001160_13) & 127;
    if (stage_v_195 > 32) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001160_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001160_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((helper_flow_10 ^ 0x2A) * 2 + pub_r001160_7) & 127;
    if (stage_v_198 > 20) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001160_15 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_199 > 41) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_156 ^ 0x2A) * 2 + pub_r001160_4) & 127;
    if (stage_v_200 > 41) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_172 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_201 > 31) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001160_1) & 127;
    if (stage_v_202 > 26) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001160_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_131 ^ 0x2A) * 2 + pub_r001160_8) & 127;
    if (stage_v_204 > 49) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001160_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r001160_1 ^ 0x2A) * 2 + pub_r001160_12) & 127;
    if (stage_v_206 > 30) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001160_0) & 127;
    if (stage_v_207 > 36) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r001160_20 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_208 > 36) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_209 > 49) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_210 > 35) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001160_4) & 127;
    if (stage_v_211 > 49) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001160_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001160_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_214 > 38) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r001160_9 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_215 > 39) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_75 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_216 > 50) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001160_9) & 127;
    if (stage_v_217 > 33) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_218 > 46) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_219 > 41) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001160_19) & 127;
    if (stage_v_220 > 30) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_3 ^ 0x2A) * 2 + pub_r001160_3) & 127;
    if (stage_v_221 > 36) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001160_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001160_20 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001160_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((sec_r001160_20 ^ 0x2A) * 2 + pub_r001160_6) & 127;
    if (stage_v_225 > 47) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001160_18) & 127;
    if (stage_v_226 > 42) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_227 > 31) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (pub_r001160_20 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_228) & 127;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_125 ^ 0x2A) * 2 + pub_r001160_15) & 127;
    if (stage_v_229 > 38) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_49 ^ 0x2A) * 2 + pub_r001160_16) & 127;
    if (stage_v_230 > 25) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
