/*
 * Benchmark Program: R001315
 * Security Family: bitwise_flow
 * Generator Seed: 631513
 * High Inputs: 19 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001315_1513_0 {
    int norm_sq;
    unsigned char heading;
    int coord_y;
    int coord_x;
    int pitch;
    int coord_z;
    int buffer[3];
};

struct EventLog_R001315_1513_1 {
    unsigned char severity;
    unsigned char signature;
    short facility;
    int buffer[3];
};

struct DeviceConfig_R001315_1513_2 {
    unsigned char port;
    int id;
    int baud_rate;
    int buffer[3];
};

struct CipherContext_R001315_1513_3 {
    int nonce;
    int flags;
    short tag;
    short round_key;
    int iv;
    int buffer[3];
};

union PacketPayload_R001315_1513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001315_1513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001315_1513_0(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001315_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_52 = (st.buffer[0] * 3 + aux) & 63;
    if (window_52 > 20) {
        acc = (acc + window_52 * 2 + 5) & 127;
        aux ^= (window_52 & 15);
    } else {
        acc = (acc - window_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_1(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001315_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int mask_82 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_82) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int mask_16 = local_arr[aux % 3];
    acc = (acc + mask_16 * 2) & 127;
    int factor_98 = (aux + st.buffer[1]) & 3;
    switch (factor_98) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001315_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_33 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_33 = (threshold_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_33) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_29 = local_arr[aux % 3];
    acc = (acc + threshold_29 * 2) & 127;
    int factor_50 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_50 > 47) {
        acc = (acc + factor_50 * 2 + 5) & 127;
        aux ^= (factor_50 & 15);
    } else {
        acc = (acc - factor_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_3(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001315_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int window_45 = (st.buffer[0] * 3 + aux) & 63;
    if (window_45 > 21) {
        acc = (acc + window_45 * 2 + 5) & 127;
        aux ^= (window_45 & 15);
    } else {
        acc = (acc - window_45 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_67 = local_arr[aux % 3];
    acc = (acc + bound_67 * 2) & 127;
    int threshold_79 = (aux + st.buffer[1]) & 3;
    switch (threshold_79) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001315_1513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int residue_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_97) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001315_1513_5(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001315_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int bound_73 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_73 > 39) {
        acc = (acc + bound_73 * 2 + 5) & 127;
        aux ^= (bound_73 & 15);
    } else {
        acc = (acc - bound_73 + 11) & 127;
        aux += 3;
    }
    int accumulator_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_90) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001315_1513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001315_1513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int damping_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001315_1513_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001315_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quantum_32 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_32 > 50) {
        acc = (acc + quantum_32 * 2 + 5) & 127;
        aux ^= (quantum_32 & 15);
    } else {
        acc = (acc - quantum_32 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_61 = local_arr[aux % 3];
    acc = (acc + tally_61 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_62 = 0;
    for (int k = 0; k < 3; k++) {
        parity_62 = (parity_62 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_62) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001315_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int residue_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_69) & 63;
    acc ^= aux;
    int threshold_32 = (aux + st.buffer[1]) & 3;
    switch (threshold_32) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001315_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int segment_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_22) & 63;
    acc ^= aux;
    int coefficient_12 = (aux + st.buffer[1]) & 3;
    switch (coefficient_12) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_25 = 0;
    for (int k = 0; k < 2; k++) {
        bound_25 = (bound_25 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_25) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001315_1513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int scale_85 = (aux + st.buffer[1]) & 3;
    switch (scale_85) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_49 = local_arr[aux % 3];
    acc = (acc + mask_49 * 2) & 127;
    int accumulator_73 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_73 = (accumulator_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_73) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001315_1513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int residue_59 = 0;
    for (int k = 0; k < 2; k++) {
        residue_59 = (residue_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_59) & 127;
    }
    int bound_25 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_25 > 47) {
        acc = (acc + bound_25 * 2 + 5) & 127;
        aux ^= (bound_25 & 15);
    } else {
        acc = (acc - bound_25 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_12(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001315_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int sample_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_74) & 63;
    acc ^= aux;
    int threshold_94 = 0;
    for (int k = 0; k < 3; k++) {
        threshold_94 = (threshold_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + threshold_94) & 127;
    }
    int damping_47 = (aux + st.buffer[1]) & 3;
    switch (damping_47) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_81 = local_arr[aux % 3];
    acc = (acc + checksum_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001315_1513_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001315_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quantum_23 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_23 = (quantum_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_23) & 127;
    }
    int coefficient_21 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_21 > 31) {
        acc = (acc + coefficient_21 * 2 + 5) & 127;
        aux ^= (coefficient_21 & 15);
    } else {
        acc = (acc - coefficient_21 + 11) & 127;
        aux += 3;
    }
    int offset_91 = (aux + st.buffer[1]) & 3;
    switch (offset_91) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001315_1513_14(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001315_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quotient_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_42) & 63;
    acc ^= aux;
    int segment_59 = (aux + st.buffer[1]) & 3;
    switch (segment_59) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_58 = local_arr[aux % 3];
    acc = (acc + tracker_58 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001315_1513_15(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001315_1513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_95 = (aux + st.buffer[1]) & 3;
    switch (weight_95) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_61 = 0;
    for (int k = 0; k < 3; k++) {
        quantum_61 = (quantum_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_61) & 127;
    }
    int window_77 = (st.buffer[0] * 3 + aux) & 63;
    if (window_77 > 46) {
        acc = (acc + window_77 * 2 + 5) & 127;
        aux ^= (window_77 & 15);
    } else {
        acc = (acc - window_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001315_1513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int local_arr[3] = {4, 9, 15};
    int scale_82 = local_arr[aux % 3];
    acc = (acc + scale_82 * 2) & 127;
    int parity_97 = (aux + st.buffer[1]) & 3;
    switch (parity_97) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_65 = 0;
    for (int k = 0; k < 2; k++) {
        residue_65 = (residue_65 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_65) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_17(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001315_1513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int coefficient_31 = local_arr[aux % 3];
    acc = (acc + coefficient_31 * 2) & 127;
    int residue_62 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_62) & 63;
    acc ^= aux;
    int quantum_28 = (aux + st.buffer[1]) & 3;
    switch (quantum_28) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_47 = 0;
    for (int k = 0; k < 3; k++) {
        sample_47 = (sample_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_47) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001315_1513_18(int p0, int p1) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001315_1513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int delta_18 = (aux + st.buffer[1]) & 3;
    switch (delta_18) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_33 = local_arr[aux % 3];
    acc = (acc + window_33 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001315_0;
    int sec_r001315_1;
    int sec_r001315_2;
    int sec_r001315_3;
    int sec_r001315_4;
    int sec_r001315_5;
    int sec_r001315_6;
    int sec_r001315_7;
    int sec_r001315_8;
    int sec_r001315_9;
    int sec_r001315_10;
    int sec_r001315_11;
    int sec_r001315_12;
    int sec_r001315_13;
    int sec_r001315_14;
    int sec_r001315_15;
    int sec_r001315_16;
    int sec_r001315_17;
    int sec_r001315_18;
    int pub_r001315_0;
    int pub_r001315_1;
    int pub_r001315_2;
    int pub_r001315_3;
    int pub_r001315_4;
    int pub_r001315_5;
    int pub_r001315_6;
    int pub_r001315_7;
    int pub_r001315_8;
    int pub_r001315_9;
    int pub_r001315_10;
    int pub_r001315_11;
    int pub_r001315_12;
    int pub_r001315_13;
    int pub_r001315_14;
    int pub_r001315_15;
    int pub_r001315_16;
    int pub_r001315_17;
    int pub_r001315_18;
    int pub_r001315_19;
    int pub_r001315_20;
    int pub_r001315_21;
    int pub_r001315_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001315_0 >= -100 && pub_r001315_0 <= 100);
    __CPROVER_assume(pub_r001315_1 >= -100 && pub_r001315_1 <= 100);
    __CPROVER_assume(pub_r001315_2 >= -100 && pub_r001315_2 <= 100);
    __CPROVER_assume(pub_r001315_3 >= -100 && pub_r001315_3 <= 100);
    __CPROVER_assume(pub_r001315_4 >= -100 && pub_r001315_4 <= 100);
    __CPROVER_assume(pub_r001315_5 >= -100 && pub_r001315_5 <= 100);
    __CPROVER_assume(pub_r001315_6 >= -100 && pub_r001315_6 <= 100);
    __CPROVER_assume(pub_r001315_7 >= -100 && pub_r001315_7 <= 100);
    __CPROVER_assume(pub_r001315_8 >= -100 && pub_r001315_8 <= 100);
    __CPROVER_assume(pub_r001315_9 >= -100 && pub_r001315_9 <= 100);
    __CPROVER_assume(pub_r001315_10 >= -100 && pub_r001315_10 <= 100);
    __CPROVER_assume(pub_r001315_11 >= -100 && pub_r001315_11 <= 100);
    __CPROVER_assume(pub_r001315_12 >= -100 && pub_r001315_12 <= 100);
    __CPROVER_assume(pub_r001315_13 >= -100 && pub_r001315_13 <= 100);
    __CPROVER_assume(pub_r001315_14 >= -100 && pub_r001315_14 <= 100);
    __CPROVER_assume(pub_r001315_15 >= -100 && pub_r001315_15 <= 100);
    __CPROVER_assume(pub_r001315_16 >= -100 && pub_r001315_16 <= 100);
    __CPROVER_assume(pub_r001315_17 >= -100 && pub_r001315_17 <= 100);
    __CPROVER_assume(pub_r001315_18 >= -100 && pub_r001315_18 <= 100);
    __CPROVER_assume(pub_r001315_19 >= -100 && pub_r001315_19 <= 100);
    __CPROVER_assume(pub_r001315_20 >= -100 && pub_r001315_20 <= 100);
    __CPROVER_assume(pub_r001315_21 >= -100 && pub_r001315_21 <= 100);
    __CPROVER_assume(pub_r001315_22 >= -100 && pub_r001315_22 <= 100);
    __CPROVER_assume(sec_r001315_0 >= 0 && sec_r001315_0 <= 255);
    __CPROVER_assume(sec_r001315_1 >= 0 && sec_r001315_1 <= 255);
    __CPROVER_assume(sec_r001315_2 >= 0 && sec_r001315_2 <= 255);
    __CPROVER_assume(sec_r001315_3 >= 0 && sec_r001315_3 <= 255);
    __CPROVER_assume(sec_r001315_4 >= 0 && sec_r001315_4 <= 255);
    __CPROVER_assume(sec_r001315_5 >= 0 && sec_r001315_5 <= 255);
    __CPROVER_assume(sec_r001315_6 >= 0 && sec_r001315_6 <= 255);
    __CPROVER_assume(sec_r001315_7 >= 0 && sec_r001315_7 <= 255);
    __CPROVER_assume(sec_r001315_8 >= 0 && sec_r001315_8 <= 255);
    __CPROVER_assume(sec_r001315_9 >= 0 && sec_r001315_9 <= 255);
    __CPROVER_assume(sec_r001315_10 >= 0 && sec_r001315_10 <= 255);
    __CPROVER_assume(sec_r001315_11 >= 0 && sec_r001315_11 <= 255);
    __CPROVER_assume(sec_r001315_12 >= 0 && sec_r001315_12 <= 255);
    __CPROVER_assume(sec_r001315_13 >= 0 && sec_r001315_13 <= 255);
    __CPROVER_assume(sec_r001315_14 >= 0 && sec_r001315_14 <= 255);
    __CPROVER_assume(sec_r001315_15 >= 0 && sec_r001315_15 <= 255);
    __CPROVER_assume(sec_r001315_16 >= 0 && sec_r001315_16 <= 255);
    __CPROVER_assume(sec_r001315_17 >= 0 && sec_r001315_17 <= 255);
    __CPROVER_assume(sec_r001315_18 >= 0 && sec_r001315_18 <= 255);

    struct Vector3D_R001315_1513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001315_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001315_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001315_0 + 7) & 15;
    struct EventLog_R001315_1513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001315_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001315_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001315_0 + 9) & 15;
    struct DeviceConfig_R001315_1513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001315_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001315_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001315_0 + 11) & 15;
    struct CipherContext_R001315_1513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001315_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001315_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001315_0 + 13) & 15;

    union PacketPayload_R001315_1513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001315_1513_0(sec_r001315_0, pub_r001315_1, pub_r001315_2);
    int helper_flow_1 = fn_R001315_1513_1(sec_r001315_1, sec_r001315_2, pub_r001315_3);
    int helper_flow_2 = fn_R001315_1513_2(sec_r001315_2, pub_r001315_3, pub_r001315_4, pub_r001315_5, pub_r001315_6);
    int helper_flow_3 = fn_R001315_1513_3(sec_r001315_3, pub_r001315_4);
    int helper_flow_4 = fn_R001315_1513_4(sec_r001315_4, sec_r001315_5, pub_r001315_6, pub_r001315_7, pub_r001315_8);
    int helper_flow_5 = fn_R001315_1513_5(sec_r001315_5, pub_r001315_6);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001315_13 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_0 + 1) & 15;
    out_sink ^= (stage_v_0 & 63);

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001315_5 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001315_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((stage_v_0 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001315_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001315_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001315_15 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_6 + 1) & 15;
    out_sink ^= (stage_v_6 & 63);

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001315_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((stage_v_0 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001315_8 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((helper_flow_3 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_10 + 1) & 15;
    out_sink ^= (stage_v_10 & 63);

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001315_6 << 1) ^ (pub_r001315_2 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001315_19 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001315_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001315_8 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001315_8 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_2 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_16 + 1) & 15;
    out_sink ^= (stage_v_16 & 63);

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((sec_r001315_3 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_17 + 1) & 15;
    out_sink ^= (stage_v_17 & 63);

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001315_14 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_18 + 1) & 15;
    out_sink ^= (stage_v_18 & 63);

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001315_17 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001315_1 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((stage_v_11 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_21 + 1) & 15;
    out_sink ^= (stage_v_21 & 63);

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((sec_r001315_9 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001315_4 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_5 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_24 + 1) & 15;
    out_sink ^= (stage_v_24 & 63);

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001315_22 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001315_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001315_19 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001315_7 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((helper_flow_5 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001315_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((sec_r001315_0 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_31 + 1) & 15;
    out_sink ^= (stage_v_31 & 63);

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001315_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_5 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_33 + 1) & 15;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001315_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((stage_v_8 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001315_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001315_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((sec_r001315_5 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001315_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001315_1 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((helper_flow_1 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_41 + 1) & 15;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001315_1 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((helper_flow_0 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_35 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_44 + 1) & 15;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_21 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_42 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_46 + 1) & 15;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_5 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_47 + 1) & 15;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001315_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001315_21 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001315_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001315_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((sec_r001315_6 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_52 + 1) & 15;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_17 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_53 + 1) & 15;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001315_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001315_7 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001315_12 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_35 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001315_16 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_58 + 1) & 15;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001315_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001315_6 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_1 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((helper_flow_1 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_33 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_31 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001315_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_61 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001315_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_2 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001315_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001315_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_63 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001315_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001315_5 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r001315_1 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_74 + 1) & 15;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001315_7 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001315_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001315_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r001315_12 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_78 + 1) & 15;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001315_17 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_79 + 1) & 15;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001315_15 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_57 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_81 + 1) & 15;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_28 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001315_14 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_83 + 1) & 15;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001315_10 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_43 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_85 + 1) & 15;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_63 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_86 + 1) & 15;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001315_0 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001315_5 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_88 + 1) & 15;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_71 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001315_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_88 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_79 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_92 + 1) & 15;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_68 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_88 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001315_19 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_58 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_96 + 1) & 15;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_58 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_97 + 1) & 15;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001315_18 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_43 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001315_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001315_8 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001315_0 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001315_6 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001315_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((helper_flow_3 << 1) ^ (pub_r001315_21 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((helper_flow_1 << 1) ^ (pub_r001315_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001315_0 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_21 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001315_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_79 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_108 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001315_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001315_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001315_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_21 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_115 + 1) & 15;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_96 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_116 << 1) ^ (pub_r001315_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r001315_1 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_118 + 1) & 15;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001315_3 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r001315_5 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001315_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_45 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001315_0 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001315_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001315_3 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001315_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_94 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r001315_10 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_92 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_129 + 1) & 15;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001315_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_52 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_131 + 1) & 15;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001315_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_66 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_133 + 1) & 15;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001315_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_88 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_135 + 1) & 15;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001315_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001315_22 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001315_20 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001315_6 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((helper_flow_4 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_140 + 1) & 15;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001315_9 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_118 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_142 + 1) & 15;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_142 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001315_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001315_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001315_4 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001315_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001315_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((helper_flow_0 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_44 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_150 + 1) & 15;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001315_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_0 << 1) ^ (pub_r001315_21 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_152 + 1) & 15;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_0 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001315_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_57 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001315_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_86 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_157 + 1) & 15;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_152 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001315_5 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001315_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_20 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_45 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001315_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001315_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_17 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_31 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_166 + 1) & 15;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_158 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_167 + 1) & 15;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((stage_v_135 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_168 + 1) & 15;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001315_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001315_21 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_3 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_171 + 1) & 15;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001315_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001315_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_44 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001315_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001315_16 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001315_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_21 << 1) ^ (pub_r001315_5 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_88 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_117 << 1) ^ (pub_r001315_21 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001315_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001315_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001315_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001315_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_171 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_185 + 1) & 15;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_61 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001315_21 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_178 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_188 + 1) & 15;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r001315_7 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((helper_flow_0 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001315_19 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001315_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_64 << 1) ^ (pub_r001315_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001315_4 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001315_16 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001315_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001315_12 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001315_22 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((sec_r001315_10 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_199 + 1) & 15;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001315_18 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001315_19 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001315_20 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001315_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_133 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_204 + 1) & 15;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001315_5 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001315_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001315_8 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_88 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_208 + 1) & 15;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001315_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001315_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_150 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_35 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_212 + 1) & 15;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_79 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_213 + 1) & 15;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001315_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((sec_r001315_17 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_212 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_180 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_217 + 1) & 15;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001315_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_189 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_57 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001315_14 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_105 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_222 + 1) & 15;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_78 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_223 + 1) & 15;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((sec_r001315_0 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001315_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((helper_flow_5 << 1) ^ (pub_r001315_21 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_89 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_195 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r001315_6 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001315_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_47 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001315_13 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_129 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (pub_r001315_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_234) & 127;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001315_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001315_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001315_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r001315_16 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001315_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_93 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_66 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001315_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001315_2 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_92 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_135 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_86 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_246 + 1) & 15;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_38 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_247 + 1) & 15;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001315_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001315_3 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_224 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001315_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_43 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_66 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (pub_r001315_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_254) & 127;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_28 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_255 + 1) & 15;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_89 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_256 + 1) & 15;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001315_18 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (pub_r001315_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_258) & 127;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001315_17 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r001315_16 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_260 + 1) & 15;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_127 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001315_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_91 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_263 + 1) & 15;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_58 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_264 + 1) & 15;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001315_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_122 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_266 + 1) & 15;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (pub_r001315_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_267) & 127;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001315_21 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001315_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_11 << 1) ^ (pub_r001315_2 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_158 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_62 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_118 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_273 + 1) & 15;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_252 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_274 + 1) & 15;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_204 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_275 + 1) & 15;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_217 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = (pub_r001315_0 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_277) & 127;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((stage_v_204 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_278 + 1) & 15;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_128 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_279 + 1) & 15;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_52 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_238 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = (pub_r001315_2 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_282) & 127;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r001315_8 << 1) ^ (pub_r001315_2 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_105 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_284 + 1) & 15;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_224 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001315_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((sec_r001315_16 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((stage_v_106 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_288 + 1) & 15;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = (pub_r001315_13 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_289) & 127;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r001315_2 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_290 + 1) & 15;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001315_15 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_253 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = (pub_r001315_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_293) & 127;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_47 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_294 + 1) & 15;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_89 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_295 + 1) & 15;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_245 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_204 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = (pub_r001315_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_298) & 127;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = (pub_r001315_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_299) & 127;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((sec_r001315_13 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_208 << 1) ^ (pub_r001315_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_301 + 1) & 15;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_158 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_300 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_302 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_222 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_305 + 1) & 15;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001315_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = (pub_r001315_9 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_307) & 127;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = (pub_r001315_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_308) & 127;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r001315_0 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_81 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_310 + 1) & 15;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = (pub_r001315_19 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_311) & 127;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001315_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_149 << 1) ^ (pub_r001315_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_157 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_314 + 1) & 15;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_204 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_315 + 1) & 15;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((sec_r001315_0 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_316 + 1) & 15;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = (pub_r001315_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_317) & 127;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_35 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_318 + 1) & 15;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_305 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_223 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_300 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_321 + 1) & 15;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001315_2 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = (pub_r001315_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_323) & 127;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((helper_flow_5 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_324 + 1) & 15;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((helper_flow_0 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_228 << 1) ^ (pub_r001315_2 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001315_12 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_178 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_273 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_329 + 1) & 15;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_288 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_324 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_331 + 1) & 15;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_283 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_332 + 1) & 15;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_21 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_333 + 1) & 15;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((stage_v_71 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_334 + 1) & 15;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_66 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001315_2 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_334 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = (pub_r001315_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_338) & 127;

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((sec_r001315_0 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((sec_r001315_0 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = ((stage_v_128 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_341 + 1) & 15;
    out_sink ^= (stage_v_341 & 63);

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = (pub_r001315_20 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_342) & 127;

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = (pub_r001315_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_343) & 127;

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_193 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((sec_r001315_10 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001315_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = (pub_r001315_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_347) & 127;

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((helper_flow_2 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001315_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = ((stage_v_157 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_350 + 1) & 15;
    out_sink ^= (stage_v_350 & 63);

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = ((stage_v_189 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_351 + 1) & 15;
    out_sink ^= (stage_v_351 & 63);

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001315_3 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_179 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = (pub_r001315_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_354) & 127;

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001315_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_11 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = (pub_r001315_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_357) & 127;

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = (pub_r001315_4 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_358) & 127;

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = (pub_r001315_21 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_359) & 127;

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((stage_v_215 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((stage_v_71 << 1) ^ (pub_r001315_13 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = (pub_r001315_4 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_362) & 127;

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = ((stage_v_215 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_363 + 1) & 15;
    out_sink ^= (stage_v_363 & 63);

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = (pub_r001315_9 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_364) & 127;

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = (pub_r001315_11 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_365) & 127;

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = (pub_r001315_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_366) & 127;

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = ((stage_v_283 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_367 + 1) & 15;
    out_sink ^= (stage_v_367 & 63);

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = ((stage_v_330 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_368 + 1) & 15;
    out_sink ^= (stage_v_368 & 63);

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001315_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_204 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001315_7 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = ((stage_v_261 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_372 + 1) & 15;
    out_sink ^= (stage_v_372 & 63);

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = (pub_r001315_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_373) & 127;

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_46 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = ((stage_v_273 << 1) ^ (pub_r001315_6 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_375 + 1) & 15;
    out_sink ^= (stage_v_375 & 63);

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = (pub_r001315_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_376) & 127;

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = ((stage_v_276 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_377 + 1) & 15;
    out_sink ^= (stage_v_377 & 63);

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = ((stage_v_303 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_378 + 1) & 15;
    out_sink ^= (stage_v_378 & 63);

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001315_17 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = ((sec_r001315_17 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_380 + 1) & 15;
    out_sink ^= (stage_v_380 & 63);

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_66 << 1) ^ (pub_r001315_0 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_283 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = (pub_r001315_16 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_383) & 127;

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((stage_v_278 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = ((stage_v_161 << 1) ^ (pub_r001315_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_385 + 1) & 15;
    out_sink ^= (stage_v_385 & 63);

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = (pub_r001315_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_386) & 127;

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_288 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = (pub_r001315_14 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_388) & 127;

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((sec_r001315_13 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001315_14 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((stage_v_89 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_3.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = (pub_r001315_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_392) & 127;

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = ((stage_v_380 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_393 + 1) & 15;
    out_sink ^= (stage_v_393 & 63);

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_21 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001315_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = ((stage_v_264 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_396 + 1) & 15;
    out_sink ^= (stage_v_396 & 63);

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = (pub_r001315_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_397) & 127;

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001315_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = ((stage_v_389 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_399 + 1) & 15;
    out_sink ^= (stage_v_399 & 63);

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_213 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = ((stage_v_3 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_401 + 1) & 15;
    out_sink ^= (stage_v_401 & 63);

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = (pub_r001315_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_402) & 127;

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = (pub_r001315_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_403) & 127;

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = ((stage_v_35 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_404 + 1) & 15;
    out_sink ^= (stage_v_404 & 63);

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001315_15 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_57 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001315_0 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = ((sec_r001315_14 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_408 + 1) & 15;
    out_sink ^= (stage_v_408 & 63);

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = ((stage_v_264 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_409 + 1) & 15;
    out_sink ^= (stage_v_409 & 63);

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_229 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001315_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_303 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001315_21 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001315_13 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = (pub_r001315_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_415) & 127;

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = ((stage_v_179 << 1) ^ (pub_r001315_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_416 + 1) & 15;
    out_sink ^= (stage_v_416 & 63);

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_240 << 1) ^ (pub_r001315_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Execution Pipeline Stage 418 */
    int stage_v_418 = ((stage_v_143 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_418 + 1) & 15;
    out_sink ^= (stage_v_418 & 63);

    /* Execution Pipeline Stage 419 */
    int stage_v_419 = ((stage_v_231 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_419 + 1) & 15;
    out_sink ^= (stage_v_419 & 63);

    /* Execution Pipeline Stage 420 */
    int stage_v_420 = ((stage_v_409 << 1) ^ (pub_r001315_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_420 + 1) & 15;
    out_sink ^= (stage_v_420 & 63);

    /* Execution Pipeline Stage 421 */
    int stage_v_421 = ((stage_v_409 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_421 + 1) & 15;
    out_sink ^= (stage_v_421 & 63);

    /* Execution Pipeline Stage 422 */
    int stage_v_422 = (pub_r001315_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_422) & 127;

    /* Execution Pipeline Stage 423 */
    int stage_v_423 = ((stage_v_348 << 1) ^ (pub_r001315_10 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_423 + 1) & 15;
    out_sink ^= (stage_v_423 & 63);

    /* Execution Pipeline Stage 424 */
    int stage_v_424 = (pub_r001315_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_424) & 127;

    /* Execution Pipeline Stage 425 */
    int stage_v_425 = ((stage_v_348 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_425 + 1) & 15;
    out_sink ^= (stage_v_425 & 63);

    /* Execution Pipeline Stage 426 */
    int stage_v_426 = (pub_r001315_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_426) & 127;

    /* Execution Pipeline Stage 427 */
    int stage_v_427 = (pub_r001315_5 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_427) & 127;

    /* Execution Pipeline Stage 428 */
    int stage_v_428 = (pub_r001315_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_428) & 127;

    /* Execution Pipeline Stage 429 */
    int stage_v_429 = (pub_r001315_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_429) & 127;

    /* Execution Pipeline Stage 430 */
    int stage_v_430 = (pub_r001315_12 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_430) & 127;

    /* Execution Pipeline Stage 431 */
    int stage_v_431 = ((stage_v_106 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_431 + 1) & 15;
    out_sink ^= (stage_v_431 & 63);

    /* Execution Pipeline Stage 432 */
    int stage_v_432 = ((stage_v_158 << 1) ^ (pub_r001315_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_432 + 1) & 15;
    out_sink ^= (stage_v_432 & 63);

    /* Execution Pipeline Stage 433 */
    int stage_v_433 = (pub_r001315_20 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_433) & 127;

    /* Execution Pipeline Stage 434 */
    int stage_v_434 = ((stage_v_278 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_434 + 1) & 15;
    out_sink ^= (stage_v_434 & 63);

    /* Execution Pipeline Stage 435 */
    int stage_v_435 = ((stage_v_57 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_435 + 1) & 15;
    out_sink ^= (stage_v_435 & 63);

    /* Execution Pipeline Stage 436 */
    int stage_v_436 = ((stage_v_400 << 1) ^ (pub_r001315_21 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_436 + 1) & 15;
    out_sink ^= (stage_v_436 & 63);

    /* Execution Pipeline Stage 437 */
    int stage_v_437 = ((stage_v_186 << 1) ^ (pub_r001315_22 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_437 + 1) & 15;
    out_sink ^= (stage_v_437 & 63);

    /* Execution Pipeline Stage 438 */
    int stage_v_438 = (pub_r001315_7 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_438) & 127;

    /* Execution Pipeline Stage 439 */
    int stage_v_439 = (pub_r001315_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_439) & 127;

    /* Execution Pipeline Stage 440 */
    int stage_v_440 = (pub_r001315_4 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_440) & 127;

    /* Execution Pipeline Stage 441 */
    int stage_v_441 = ((stage_v_216 << 1) ^ (pub_r001315_17 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_441 + 1) & 15;
    out_sink ^= (stage_v_441 & 63);

    /* Execution Pipeline Stage 442 */
    int stage_v_442 = ((stage_v_406 << 1) ^ (pub_r001315_20 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_442 + 1) & 15;
    out_sink ^= (stage_v_442 & 63);

    /* Execution Pipeline Stage 443 */
    int stage_v_443 = ((stage_v_89 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_443 + 1) & 15;
    out_sink ^= (stage_v_443 & 63);

    /* Execution Pipeline Stage 444 */
    int stage_v_444 = (pub_r001315_6 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_444) & 127;

    /* Execution Pipeline Stage 445 */
    int stage_v_445 = ((stage_v_152 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_445 + 1) & 15;
    out_sink ^= (stage_v_445 & 63);

    /* Execution Pipeline Stage 446 */
    int stage_v_446 = ((stage_v_273 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_2.buffer[2] = (stage_v_446 + 1) & 15;
    out_sink ^= (stage_v_446 & 63);

    /* Execution Pipeline Stage 447 */
    int stage_v_447 = ((stage_v_297 << 1) ^ (pub_r001315_18 >> 1)) & 127;
    st_var_3.buffer[0] = (stage_v_447 + 1) & 15;
    out_sink ^= (stage_v_447 & 63);

    /* Execution Pipeline Stage 448 */
    int stage_v_448 = ((stage_v_224 << 1) ^ (pub_r001315_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_448 + 1) & 15;
    out_sink ^= (stage_v_448 & 63);

    /* Execution Pipeline Stage 449 */
    int stage_v_449 = ((stage_v_42 << 1) ^ (pub_r001315_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_449 + 1) & 15;
    out_sink ^= (stage_v_449 & 63);

    /* Execution Pipeline Stage 450 */
    int stage_v_450 = ((sec_r001315_17 << 1) ^ (pub_r001315_4 >> 1)) & 127;
    st_var_2.buffer[0] = (stage_v_450 + 1) & 15;
    out_sink ^= (stage_v_450 & 63);

    /* Execution Pipeline Stage 451 */
    int stage_v_451 = (pub_r001315_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_451) & 127;

    /* Execution Pipeline Stage 452 */
    int stage_v_452 = (pub_r001315_19 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_452) & 127;

    /* Execution Pipeline Stage 453 */
    int stage_v_453 = (pub_r001315_16 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_453) & 127;

    /* Execution Pipeline Stage 454 */
    int stage_v_454 = ((stage_v_188 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_2.buffer[1] = (stage_v_454 + 1) & 15;
    out_sink ^= (stage_v_454 & 63);

    /* Execution Pipeline Stage 455 */
    int stage_v_455 = (pub_r001315_1 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_455) & 127;

    /* Execution Pipeline Stage 456 */
    int stage_v_456 = (pub_r001315_4 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_456) & 127;

    /* Execution Pipeline Stage 457 */
    int stage_v_457 = (pub_r001315_0 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_457) & 127;

    /* Execution Pipeline Stage 458 */
    int stage_v_458 = (pub_r001315_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_458) & 127;

    /* Execution Pipeline Stage 459 */
    int stage_v_459 = (pub_r001315_21 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_459) & 127;

    /* Execution Pipeline Stage 460 */
    int stage_v_460 = ((stage_v_278 << 1) ^ (pub_r001315_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_460 + 1) & 15;
    out_sink ^= (stage_v_460 & 63);

    /* Execution Pipeline Stage 461 */
    int stage_v_461 = (pub_r001315_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_461) & 127;

    /* Execution Pipeline Stage 462 */
    int stage_v_462 = (pub_r001315_4 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_462) & 127;

    /* Execution Pipeline Stage 463 */
    int stage_v_463 = (pub_r001315_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_463) & 127;

    /* Execution Pipeline Stage 464 */
    int stage_v_464 = (pub_r001315_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_464) & 127;

    /* Execution Pipeline Stage 465 */
    int stage_v_465 = ((stage_v_418 << 1) ^ (pub_r001315_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_465 + 1) & 15;
    out_sink ^= (stage_v_465 & 63);

    /* Execution Pipeline Stage 466 */
    int stage_v_466 = (pub_r001315_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_466) & 127;

    /* Execution Pipeline Stage 467 */
    int stage_v_467 = ((stage_v_276 << 1) ^ (pub_r001315_14 >> 1)) & 127;
    st_var_3.buffer[2] = (stage_v_467 + 1) & 15;
    out_sink ^= (stage_v_467 & 63);

    /* Execution Pipeline Stage 468 */
    int stage_v_468 = ((stage_v_275 << 1) ^ (pub_r001315_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_468 + 1) & 15;
    out_sink ^= (stage_v_468 & 63);

    /* Execution Pipeline Stage 469 */
    int stage_v_469 = (pub_r001315_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_469) & 127;

    /* Execution Pipeline Stage 470 */
    int stage_v_470 = (pub_r001315_1 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_470) & 127;

    /* Execution Pipeline Stage 471 */
    int stage_v_471 = (pub_r001315_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_471) & 127;

    /* Execution Pipeline Stage 472 */
    int stage_v_472 = ((stage_v_152 << 1) ^ (pub_r001315_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_472 + 1) & 15;
    out_sink ^= (stage_v_472 & 63);

    /* Execution Pipeline Stage 473 */
    int stage_v_473 = (pub_r001315_0 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_473) & 127;

    /* Execution Pipeline Stage 474 */
    int stage_v_474 = (pub_r001315_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_474) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
