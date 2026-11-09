/*
 * Benchmark Program: R001378
 * Security Family: secret_dependent_loops
 * Generator Seed: 637813
 * High Inputs: 19 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001378_7813_0 {
    short balance;
    int fee;
    int auth_code;
    int account_id;
    int buffer[3];
};

struct DeviceConfig_R001378_7813_1 {
    short port;
    int timeout;
    int baud_rate;
    int buffer[3];
};

union TelemetryField_R001378_7813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001378_7813_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001378_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int mask_77 = 0;
    for (int k = 0; k < 2; k++) {
        mask_77 = (mask_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_77) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001378_7813_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int index_reg_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_66) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_59 = 0;
    for (int k = 0; k < 3; k++) {
        damping_59 = (damping_59 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_59) & 127;
    }
    int tracker_33 = (aux + st.buffer[1]) & 3;
    switch (tracker_33) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_47 = (aux + st.buffer[1]) & 3;
    switch (coefficient_47) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_71 = 0;
    for (int k = 0; k < 3; k++) {
        quotient_71 = (quotient_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_71) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_3(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int accumulator_14 = local_arr[aux % 3];
    acc = (acc + accumulator_14 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_60 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_60 > 41) {
        acc = (acc + quantum_60 * 2 + 5) & 127;
        aux ^= (quantum_60 & 15);
    } else {
        acc = (acc - quantum_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_4(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int checksum_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_57) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_61 = 0;
    for (int k = 0; k < 3; k++) {
        window_61 = (window_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_61) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_5(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001378_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int offset_21 = 0;
    for (int k = 0; k < 3; k++) {
        offset_21 = (offset_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_21) & 127;
    }
    int checksum_62 = (aux + st.buffer[1]) & 3;
    switch (checksum_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int phase_91 = local_arr[aux % 3];
    acc = (acc + phase_91 * 2) & 127;
    int quotient_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_14) & 63;
    acc ^= aux;
    int offset_94 = 0;
    for (int k = 0; k < 3; k++) {
        offset_94 = (offset_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_94) & 127;
    }
    int cursor_48 = (aux + st.buffer[1]) & 3;
    switch (cursor_48) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int phase_67 = 0;
    for (int k = 0; k < 3; k++) {
        phase_67 = (phase_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_67) & 127;
    }
    int coefficient_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001378_7813_8(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001378_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_20 = (aux + st.buffer[1]) & 3;
    switch (cursor_20) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_39 = local_arr[aux % 3];
    acc = (acc + offset_39 * 2) & 127;
    int segment_84 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_84 > 25) {
        acc = (acc + segment_84 * 2 + 5) & 127;
        aux ^= (segment_84 & 15);
    } else {
        acc = (acc - segment_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_9(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001378_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int threshold_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_18) & 63;
    acc ^= aux;
    int quantum_19 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_19 > 47) {
        acc = (acc + quantum_19 * 2 + 5) & 127;
        aux ^= (quantum_19 & 15);
    } else {
        acc = (acc - quantum_19 + 11) & 127;
        aux += 3;
    }
    int segment_53 = 0;
    for (int k = 0; k < 3; k++) {
        segment_53 = (segment_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_53) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_91 = local_arr[aux % 3];
    acc = (acc + factor_91 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001378_7813_10(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int phase_82 = (aux + st.buffer[1]) & 3;
    switch (phase_82) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_80 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_80 > 19) {
        acc = (acc + quotient_80 * 2 + 5) & 127;
        aux ^= (quotient_80 & 15);
    } else {
        acc = (acc - quotient_80 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_49 = local_arr[aux % 3];
    acc = (acc + pivot_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001378_7813_11(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int phase_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_83) & 63;
    acc ^= aux;
    int margin_78 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_78 > 15) {
        acc = (acc + margin_78 * 2 + 5) & 127;
        aux ^= (margin_78 & 15);
    } else {
        acc = (acc - margin_78 + 11) & 127;
        aux += 3;
    }
    int weight_56 = (aux + st.buffer[1]) & 3;
    switch (weight_56) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_12(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int damping_31 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_31 > 41) {
        acc = (acc + damping_31 * 2 + 5) & 127;
        aux ^= (damping_31 & 15);
    } else {
        acc = (acc - damping_31 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_68 = local_arr[aux % 3];
    acc = (acc + delta_68 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001378_7813_13(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001378_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_12 = 0;
    for (int k = 0; k < 3; k++) {
        vector_12 = (vector_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + vector_12) & 127;
    }
    int parity_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_90) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001378_7813_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001378_7813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int weight_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_71) & 63;
    acc ^= aux;
    int parity_85 = (aux + st.buffer[1]) & 3;
    switch (parity_85) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_41 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_41 > 38) {
        acc = (acc + parity_41 * 2 + 5) & 127;
        aux ^= (parity_41 & 15);
    } else {
        acc = (acc - parity_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_31 = local_arr[aux % 3];
    acc = (acc + index_reg_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001378_7813_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int margin_98 = 0;
    for (int k = 0; k < 3; k++) {
        margin_98 = (margin_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_98) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_57 = local_arr[aux % 3];
    acc = (acc + parity_57 * 2) & 127;
    int residue_41 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_41 > 42) {
        acc = (acc + residue_41 * 2 + 5) & 127;
        aux ^= (residue_41 & 15);
    } else {
        acc = (acc - residue_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001378_7813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_11 = (aux + st.buffer[1]) & 3;
    switch (metric_11) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001378_7813_17(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001378_7813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int index_reg_74 = (aux + st.buffer[1]) & 3;
    switch (index_reg_74) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_44) & 63;
    acc ^= aux;
    int delta_47 = 0;
    for (int k = 0; k < 3; k++) {
        delta_47 = (delta_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_47) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001378_0;
    int sec_r001378_1;
    int sec_r001378_2;
    int sec_r001378_3;
    int sec_r001378_4;
    int sec_r001378_5;
    int sec_r001378_6;
    int sec_r001378_7;
    int sec_r001378_8;
    int sec_r001378_9;
    int sec_r001378_10;
    int sec_r001378_11;
    int sec_r001378_12;
    int sec_r001378_13;
    int sec_r001378_14;
    int sec_r001378_15;
    int sec_r001378_16;
    int sec_r001378_17;
    int sec_r001378_18;
    int pub_r001378_0;
    int pub_r001378_1;
    int pub_r001378_2;
    int pub_r001378_3;
    int pub_r001378_4;
    int pub_r001378_5;
    int pub_r001378_6;
    int pub_r001378_7;
    int pub_r001378_8;
    int pub_r001378_9;
    int pub_r001378_10;
    int pub_r001378_11;
    int pub_r001378_12;
    int pub_r001378_13;
    int pub_r001378_14;
    int pub_r001378_15;
    int pub_r001378_16;
    int pub_r001378_17;
    int pub_r001378_18;
    int pub_r001378_19;
    int pub_r001378_20;
    int pub_r001378_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001378_0 >= -100 && pub_r001378_0 <= 100);
    __CPROVER_assume(pub_r001378_1 >= -100 && pub_r001378_1 <= 100);
    __CPROVER_assume(pub_r001378_2 >= -100 && pub_r001378_2 <= 100);
    __CPROVER_assume(pub_r001378_3 >= -100 && pub_r001378_3 <= 100);
    __CPROVER_assume(pub_r001378_4 >= -100 && pub_r001378_4 <= 100);
    __CPROVER_assume(pub_r001378_5 >= -100 && pub_r001378_5 <= 100);
    __CPROVER_assume(pub_r001378_6 >= -100 && pub_r001378_6 <= 100);
    __CPROVER_assume(pub_r001378_7 >= -100 && pub_r001378_7 <= 100);
    __CPROVER_assume(pub_r001378_8 >= -100 && pub_r001378_8 <= 100);
    __CPROVER_assume(pub_r001378_9 >= -100 && pub_r001378_9 <= 100);
    __CPROVER_assume(pub_r001378_10 >= -100 && pub_r001378_10 <= 100);
    __CPROVER_assume(pub_r001378_11 >= -100 && pub_r001378_11 <= 100);
    __CPROVER_assume(pub_r001378_12 >= -100 && pub_r001378_12 <= 100);
    __CPROVER_assume(pub_r001378_13 >= -100 && pub_r001378_13 <= 100);
    __CPROVER_assume(pub_r001378_14 >= -100 && pub_r001378_14 <= 100);
    __CPROVER_assume(pub_r001378_15 >= -100 && pub_r001378_15 <= 100);
    __CPROVER_assume(pub_r001378_16 >= -100 && pub_r001378_16 <= 100);
    __CPROVER_assume(pub_r001378_17 >= -100 && pub_r001378_17 <= 100);
    __CPROVER_assume(pub_r001378_18 >= -100 && pub_r001378_18 <= 100);
    __CPROVER_assume(pub_r001378_19 >= -100 && pub_r001378_19 <= 100);
    __CPROVER_assume(pub_r001378_20 >= -100 && pub_r001378_20 <= 100);
    __CPROVER_assume(pub_r001378_21 >= -100 && pub_r001378_21 <= 100);
    __CPROVER_assume(sec_r001378_0 >= 0 && sec_r001378_0 <= 255);
    __CPROVER_assume(sec_r001378_1 >= 0 && sec_r001378_1 <= 255);
    __CPROVER_assume(sec_r001378_2 >= 0 && sec_r001378_2 <= 255);
    __CPROVER_assume(sec_r001378_3 >= 0 && sec_r001378_3 <= 255);
    __CPROVER_assume(sec_r001378_4 >= 0 && sec_r001378_4 <= 255);
    __CPROVER_assume(sec_r001378_5 >= 0 && sec_r001378_5 <= 255);
    __CPROVER_assume(sec_r001378_6 >= 0 && sec_r001378_6 <= 255);
    __CPROVER_assume(sec_r001378_7 >= 0 && sec_r001378_7 <= 255);
    __CPROVER_assume(sec_r001378_8 >= 0 && sec_r001378_8 <= 255);
    __CPROVER_assume(sec_r001378_9 >= 0 && sec_r001378_9 <= 255);
    __CPROVER_assume(sec_r001378_10 >= 0 && sec_r001378_10 <= 255);
    __CPROVER_assume(sec_r001378_11 >= 0 && sec_r001378_11 <= 255);
    __CPROVER_assume(sec_r001378_12 >= 0 && sec_r001378_12 <= 255);
    __CPROVER_assume(sec_r001378_13 >= 0 && sec_r001378_13 <= 255);
    __CPROVER_assume(sec_r001378_14 >= 0 && sec_r001378_14 <= 255);
    __CPROVER_assume(sec_r001378_15 >= 0 && sec_r001378_15 <= 255);
    __CPROVER_assume(sec_r001378_16 >= 0 && sec_r001378_16 <= 255);
    __CPROVER_assume(sec_r001378_17 >= 0 && sec_r001378_17 <= 255);
    __CPROVER_assume(sec_r001378_18 >= 0 && sec_r001378_18 <= 255);

    struct Transaction_R001378_7813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001378_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001378_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001378_0 + 7) & 15;
    struct DeviceConfig_R001378_7813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001378_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001378_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001378_0 + 9) & 15;

    union TelemetryField_R001378_7813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001378_7813_0(sec_r001378_0, pub_r001378_1, pub_r001378_2, pub_r001378_3, pub_r001378_4);
    int helper_flow_1 = fn_R001378_7813_1(sec_r001378_1, sec_r001378_2, pub_r001378_3, pub_r001378_4);
    int helper_flow_2 = fn_R001378_7813_2(sec_r001378_2, pub_r001378_3, pub_r001378_4, pub_r001378_5, pub_r001378_6);
    int helper_flow_3 = fn_R001378_7813_3(sec_r001378_3, sec_r001378_4, pub_r001378_5);
    int helper_flow_4 = fn_R001378_7813_4(sec_r001378_4, pub_r001378_5);
    int helper_flow_5 = fn_R001378_7813_5(sec_r001378_5, sec_r001378_6, pub_r001378_7);
    int helper_flow_6 = fn_R001378_7813_6(sec_r001378_6, sec_r001378_7, pub_r001378_8, pub_r001378_9, pub_r001378_10);
    int helper_flow_7 = fn_R001378_7813_7(sec_r001378_7, pub_r001378_8, pub_r001378_9, pub_r001378_10, pub_r001378_11);
    int helper_flow_8 = fn_R001378_7813_8(sec_r001378_8, pub_r001378_9, pub_r001378_10);
    int helper_flow_9 = fn_R001378_7813_9(sec_r001378_9, sec_r001378_10, pub_r001378_11);
    int helper_flow_10 = fn_R001378_7813_10(sec_r001378_10, sec_r001378_11, pub_r001378_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_0 = (stage_v_0 + it * 3 + (sec_r001378_17 & 15)) & 63;
        if ((sec_r001378_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_0 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_0 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001378_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (sec_r001378_18 & 15)) & 63;
        if ((sec_r001378_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_3 = (stage_v_3 + it * 3 + (sec_r001378_17 & 15)) & 63;
        if ((sec_r001378_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_3 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_3 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001378_0 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001378_16 & 15)) & 63;
        if ((sec_r001378_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (sec_r001378_14 & 15)) & 63;
        if ((sec_r001378_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001378_18 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001378_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001378_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001378_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001378_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_14 = (stage_v_14 + it * 3 + (sec_r001378_3 & 15)) & 63;
        if ((sec_r001378_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_14 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_14 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_15 = (stage_v_15 + it * 3 + (sec_r001378_15 & 15)) & 63;
        if ((sec_r001378_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_15 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_15 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001378_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001378_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_18 = (stage_v_18 + it * 3 + (sec_r001378_11 & 15)) & 63;
        if ((sec_r001378_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_18 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_18 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (helper_flow_0 & 15)) & 63;
        if ((helper_flow_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_21 = (stage_v_21 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_21 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_21 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001378_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (sec_r001378_18 & 15)) & 63;
        if ((sec_r001378_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_24 = (stage_v_24 + it * 3 + (sec_r001378_13 & 15)) & 63;
        if ((sec_r001378_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_24 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_24 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001378_1 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_26 = (stage_v_26 + it * 3 + (sec_r001378_11 & 15)) & 63;
        if ((sec_r001378_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_26 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_26 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001378_15 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_28 = (stage_v_28 + it * 3 + (sec_r001378_0 & 15)) & 63;
        if ((sec_r001378_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_28 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_28 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_29 = (stage_v_29 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_29 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_29 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (sec_r001378_3 & 15)) & 63;
        if ((sec_r001378_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_32 = (stage_v_32 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_32 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_32 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001378_10 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_34 = (stage_v_34 + it * 3 + (sec_r001378_17 & 15)) & 63;
        if ((sec_r001378_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_34 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_34 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_35 = (stage_v_35 + it * 3 + (helper_flow_10 & 15)) & 63;
        if ((helper_flow_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_35 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_35 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (sec_r001378_18 & 15)) & 63;
        if ((sec_r001378_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (sec_r001378_5 & 15)) & 63;
        if ((sec_r001378_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_38 = (stage_v_38 + it * 3 + (stage_v_15 & 15)) & 63;
        if ((stage_v_15 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_38 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_38 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_39 = (stage_v_39 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_39 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_39 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001378_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_41 = (stage_v_41 + it * 3 + (sec_r001378_0 & 15)) & 63;
        if ((sec_r001378_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_41 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_41 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (sec_r001378_12 & 15)) & 63;
        if ((sec_r001378_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (sec_r001378_16 & 15)) & 63;
        if ((sec_r001378_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001378_6 & 15)) & 63;
        if ((sec_r001378_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001378_8 & 15)) & 63;
        if ((sec_r001378_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_48 = (stage_v_48 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_48 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_48 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_49 = (stage_v_49 + it * 3 + (sec_r001378_11 & 15)) & 63;
        if ((sec_r001378_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_49 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_49 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_50 = (stage_v_50 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_50 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_50 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_51 = (stage_v_51 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_51 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_51 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_52 = (stage_v_52 + it * 3 + (sec_r001378_2 & 15)) & 63;
        if ((sec_r001378_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_52 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_52 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (sec_r001378_5 & 15)) & 63;
        if ((sec_r001378_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_54 = (stage_v_54 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_54 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_54 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_55 = (stage_v_55 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_55 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_55 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001378_21 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001378_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_58 = (stage_v_58 + it * 3 + (helper_flow_9 & 15)) & 63;
        if ((helper_flow_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_58 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_58 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001378_1 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001378_21 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001378_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001378_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_64 = (stage_v_64 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_64 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_64 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001378_20 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_66 = (stage_v_66 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_66 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_66 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (sec_r001378_0 & 15)) & 63;
        if ((sec_r001378_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001378_2 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_69 = (stage_v_69 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_69 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_69 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001378_17 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001378_15 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001378_12 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_75 = (stage_v_75 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_75 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_75 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001378_8 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001378_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (sec_r001378_0 & 15)) & 63;
        if ((sec_r001378_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_81 = (stage_v_81 + it * 3 + (stage_v_30 & 15)) & 63;
        if ((stage_v_30 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_81 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_81 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_82 = (stage_v_82 + it * 3 + (sec_r001378_5 & 15)) & 63;
        if ((sec_r001378_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_82 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_82 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (stage_v_47 & 15)) & 63;
        if ((stage_v_47 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (sec_r001378_1 & 15)) & 63;
        if ((sec_r001378_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001378_19 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001378_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001378_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_89 = (stage_v_89 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_89 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_89 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_93 = (stage_v_93 + it * 3 + (sec_r001378_2 & 15)) & 63;
        if ((sec_r001378_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_93 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_93 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_95 = (stage_v_95 + it * 3 + (sec_r001378_11 & 15)) & 63;
        if ((sec_r001378_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_95 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_95 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001378_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (stage_v_95 & 15)) & 63;
        if ((stage_v_95 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_98 = (stage_v_98 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_98 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_98 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (stage_v_55 & 15)) & 63;
        if ((stage_v_55 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001378_5 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (stage_v_81 & 15)) & 63;
        if ((stage_v_81 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001378_0 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_105 = (stage_v_105 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_105 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_105 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_106 = (stage_v_106 + it * 3 + (stage_v_93 & 15)) & 63;
        if ((stage_v_93 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_106 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_106 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_107 = (stage_v_107 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_107 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_107 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001378_2 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_109 = (stage_v_109 + it * 3 + (sec_r001378_14 & 15)) & 63;
        if ((sec_r001378_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_109 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_109 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_111 = (stage_v_111 + it * 3 + (stage_v_81 & 15)) & 63;
        if ((stage_v_81 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_111 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_111 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001378_7 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_113 = (stage_v_113 + it * 3 + (sec_r001378_18 & 15)) & 63;
        if ((sec_r001378_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_113 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_113 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_114 = (stage_v_114 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_114 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_114 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001378_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_116 = (stage_v_116 + it * 3 + (sec_r001378_1 & 15)) & 63;
        if ((sec_r001378_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_116 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_116 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_117 = (stage_v_117 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_117 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_117 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_119 = (stage_v_119 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_119 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_119 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001378_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001378_2 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_123 = (stage_v_123 + it * 3 + (stage_v_48 & 15)) & 63;
        if ((stage_v_48 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_123 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_123 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001378_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_125 = (stage_v_125 + it * 3 + (stage_v_105 & 15)) & 63;
        if ((stage_v_105 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_125 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_125 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001378_21 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (stage_v_18 & 15)) & 63;
        if ((stage_v_18 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_128 = (stage_v_128 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_128 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_128 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_129 = (stage_v_129 + it * 3 + (stage_v_46 & 15)) & 63;
        if ((stage_v_46 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_129 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_129 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001378_1 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001378_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_132 = (stage_v_132 + it * 3 + (stage_v_113 & 15)) & 63;
        if ((stage_v_113 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_132 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_132 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001378_21 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001378_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001378_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_137 = (stage_v_137 + it * 3 + (stage_v_117 & 15)) & 63;
        if ((stage_v_117 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_137 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_137 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001378_19 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_139 = (stage_v_139 + it * 3 + (stage_v_58 & 15)) & 63;
        if ((stage_v_58 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_139 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_139 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_141 = (stage_v_141 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
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
    int stage_v_143 = (pub_r001378_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_144 = (stage_v_144 + it * 3 + (stage_v_107 & 15)) & 63;
        if ((stage_v_107 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_144 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_144 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001378_21 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001378_21 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_148 = (stage_v_148 + it * 3 + (sec_r001378_3 & 15)) & 63;
        if ((sec_r001378_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_148 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_148 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001378_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_150 = (stage_v_150 + it * 3 + (stage_v_66 & 15)) & 63;
        if ((stage_v_66 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_150 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_150 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_151 = (stage_v_151 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_151 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_151 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001378_0 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001378_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_154 = (stage_v_154 + it * 3 + (sec_r001378_1 & 15)) & 63;
        if ((sec_r001378_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_154 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_154 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_155 = (stage_v_155 + it * 3 + (stage_v_125 & 15)) & 63;
        if ((stage_v_125 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_155 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_155 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001378_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_158 = (stage_v_158 + it * 3 + (stage_v_132 & 15)) & 63;
        if ((stage_v_132 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_158 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_158 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001378_16 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_160 = (stage_v_160 + it * 3 + (stage_v_142 & 15)) & 63;
        if ((stage_v_142 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_160 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_160 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001378_21 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (stage_v_121 & 15)) & 63;
        if ((stage_v_121 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (stage_v_125 & 15)) & 63;
        if ((stage_v_125 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001378_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001378_8 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001378_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001378_12 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (stage_v_34 & 15)) & 63;
        if ((stage_v_34 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001378_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001378_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (sec_r001378_7 & 15)) & 63;
        if ((sec_r001378_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_169 & 15)) & 63;
        if ((stage_v_169 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_174 = (stage_v_174 + it * 3 + (stage_v_99 & 15)) & 63;
        if ((stage_v_99 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_174 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_174 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_175 = (stage_v_175 + it * 3 + (stage_v_162 & 15)) & 63;
        if ((stage_v_162 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_175 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_175 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001378_19 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_97 & 15)) & 63;
        if ((stage_v_97 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001378_21 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001378_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_92 & 15)) & 63;
        if ((stage_v_92 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_169 & 15)) & 63;
        if ((stage_v_169 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001378_15 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001378_7 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (sec_r001378_17 & 15)) & 63;
        if ((sec_r001378_17 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (stage_v_163 & 15)) & 63;
        if ((stage_v_163 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_188 = (stage_v_188 + it * 3 + (stage_v_132 & 15)) & 63;
        if ((stage_v_132 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_188 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_188 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001378_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (sec_r001378_16 & 15)) & 63;
        if ((sec_r001378_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_191 = (stage_v_191 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_191 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_191 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001378_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_193 = (stage_v_193 + it * 3 + (sec_r001378_3 & 15)) & 63;
        if ((sec_r001378_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_193 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_193 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_194 = (stage_v_194 + it * 3 + (stage_v_59 & 15)) & 63;
        if ((stage_v_59 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_194 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_194 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001378_18 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_196 = (stage_v_196 + it * 3 + (stage_v_28 & 15)) & 63;
        if ((stage_v_28 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_196 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_196 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_197 = (stage_v_197 + it * 3 + (stage_v_139 & 15)) & 63;
        if ((stage_v_139 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_197 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_197 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001378_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_199 = (stage_v_199 + it * 3 + (stage_v_163 & 15)) & 63;
        if ((stage_v_163 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_199 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_199 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001378_11 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_201 = (stage_v_201 + it * 3 + (stage_v_129 & 15)) & 63;
        if ((stage_v_129 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_201 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_201 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_202 = (stage_v_202 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_202 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_202 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001378_19 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_204 = (stage_v_204 + it * 3 + (stage_v_92 & 15)) & 63;
        if ((stage_v_92 & 1) != 0) {
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
    int stage_v_206 = (pub_r001378_11 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001378_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_208 = (stage_v_208 + it * 3 + (stage_v_5 & 15)) & 63;
        if ((stage_v_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_208 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_208 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_209 = (stage_v_209 + it * 3 + (stage_v_42 & 15)) & 63;
        if ((stage_v_42 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_209 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_209 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_210 = (stage_v_210 + it * 3 + (stage_v_111 & 15)) & 63;
        if ((stage_v_111 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_210 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_210 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_211 = (stage_v_211 + it * 3 + (stage_v_132 & 15)) & 63;
        if ((stage_v_132 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_211 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_211 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001378_6 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001378_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (pub_r001378_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_214) & 127;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_215 = (stage_v_215 + it * 3 + (stage_v_103 & 15)) & 63;
        if ((stage_v_103 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_215 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_215 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001378_10 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001378_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_218 = (stage_v_218 + it * 3 + (stage_v_140 & 15)) & 63;
        if ((stage_v_140 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_218 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_218 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001378_16 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_220 = (stage_v_220 + it * 3 + (stage_v_21 & 15)) & 63;
        if ((stage_v_21 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_220 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_220 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001378_4 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_222 = (stage_v_222 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_222 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_222 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001378_17 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_224 = (stage_v_224 + it * 3 + (stage_v_205 & 15)) & 63;
        if ((stage_v_205 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_224 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_224 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001378_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_226 = (stage_v_226 + it * 3 + (stage_v_224 & 15)) & 63;
        if ((stage_v_224 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_226 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_226 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001378_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_228 = (stage_v_228 + it * 3 + (stage_v_177 & 15)) & 63;
        if ((stage_v_177 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_228 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_228 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_229 = (stage_v_229 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_229 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_229 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_230 = (stage_v_230 + it * 3 + (stage_v_43 & 15)) & 63;
        if ((stage_v_43 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_230 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_230 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
