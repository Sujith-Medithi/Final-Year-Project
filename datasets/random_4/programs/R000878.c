/*
 * Benchmark Program: R000878
 * Family: secret_dependent_array
 * Generator Seed: 537817
 * High Inputs: 17 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000878_7817_0 {
    int coord_x;
    unsigned char coord_z;
    int coord_y;
    int buffer[3];
};

struct DeviceConfig_R000878_7817_1 {
    short baud_rate;
    int timeout;
    int parity;
    int buffer[3];
};

union TelemetryField_R000878_7817_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000878_7817_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000878_7817_0(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int residue_92 = local_arr[aux % 3];
    acc = (acc + residue_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000878_7817_1(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int bound_89 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_89 > 47) {
        acc = (acc + bound_89 * 2 + 5) & 127;
        aux ^= (bound_89 & 15);
    } else {
        acc = (acc - bound_89 + 11) & 127;
        aux += 3;
    }
    int checksum_64 = (aux + st.buffer[1]) & 3;
    switch (checksum_64) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_2(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_80 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_80 > 27) {
        acc = (acc + segment_80 * 2 + 5) & 127;
        aux ^= (segment_80 & 15);
    } else {
        acc = (acc - segment_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_3(int p0, int p1) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int checksum_32 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_32 = (checksum_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_32) & 127;
    }
    int coefficient_70 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_70 > 18) {
        acc = (acc + coefficient_70 * 2 + 5) & 127;
        aux ^= (coefficient_70 & 15);
    } else {
        acc = (acc - coefficient_70 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_57 = local_arr[aux % 3];
    acc = (acc + bound_57 * 2) & 127;
    int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000878_7817_4(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int threshold_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_12) & 63;
    acc ^= aux;
    int quantum_34 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_34 > 21) {
        acc = (acc + quantum_34 * 2 + 5) & 127;
        aux ^= (quantum_34 & 15);
    } else {
        acc = (acc - quantum_34 + 11) & 127;
        aux += 3;
    }
    int accumulator_33 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_33 = (accumulator_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_33) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000878_7817_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int cursor_73 = local_arr[aux % 3];
    acc = (acc + cursor_73 * 2) & 127;
    int phase_65 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_65 > 46) {
        acc = (acc + phase_65 * 2 + 5) & 127;
        aux ^= (phase_65 & 15);
    } else {
        acc = (acc - phase_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_76 = (aux + st.buffer[1]) & 3;
    switch (quotient_76) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int coefficient_71 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_71 > 24) {
        acc = (acc + coefficient_71 * 2 + 5) & 127;
        aux ^= (coefficient_71 & 15);
    } else {
        acc = (acc - coefficient_71 + 11) & 127;
        aux += 3;
    }
    int tally_83 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_83) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000878_7817_7(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_28 = (aux + st.buffer[1]) & 3;
    switch (accumulator_28) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_10 = local_arr[aux % 3];
    acc = (acc + stride_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000878_7817_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int offset_98 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + offset_98) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_19 = 0;
    for (int k = 0; k < 2; k++) {
        factor_19 = (factor_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_19) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int quotient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_96) & 63;
    acc ^= aux;
    int factor_99 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_99 > 17) {
        acc = (acc + factor_99 * 2 + 5) & 127;
        aux ^= (factor_99 & 15);
    } else {
        acc = (acc - factor_99 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_46 = local_arr[aux % 3];
    acc = (acc + residue_46 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000878_7817_10(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int weight_17 = local_arr[aux % 3];
    acc = (acc + weight_17 * 2) & 127;
    int sample_56 = 0;
    for (int k = 0; k < 2; k++) {
        sample_56 = (sample_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_56) & 127;
    }
    int checksum_88 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_88 > 19) {
        acc = (acc + checksum_88 * 2 + 5) & 127;
        aux ^= (checksum_88 & 15);
    } else {
        acc = (acc - checksum_88 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_11(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int damping_54 = 0;
    for (int k = 0; k < 2; k++) {
        damping_54 = (damping_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_54) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_91) & 63;
    acc ^= aux;
    int stride_35 = (aux + st.buffer[1]) & 3;
    switch (stride_35) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000878_7817_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int window_66 = local_arr[aux % 3];
    acc = (acc + window_66 * 2) & 127;
    int accumulator_95 = (aux + st.buffer[1]) & 3;
    switch (accumulator_95) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000878_7817_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000878_7817_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_66 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_66 > 12) {
        acc = (acc + offset_66 * 2 + 5) & 127;
        aux ^= (offset_66 & 15);
    } else {
        acc = (acc - offset_66 + 11) & 127;
        aux += 3;
    }
    int quantum_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_21) & 63;
    acc ^= aux;
    int sample_32 = 0;
    for (int k = 0; k < 3; k++) {
        sample_32 = (sample_32 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_32) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000878_0;
    int sec_r000878_1;
    int sec_r000878_2;
    int sec_r000878_3;
    int sec_r000878_4;
    int sec_r000878_5;
    int sec_r000878_6;
    int sec_r000878_7;
    int sec_r000878_8;
    int sec_r000878_9;
    int sec_r000878_10;
    int sec_r000878_11;
    int sec_r000878_12;
    int sec_r000878_13;
    int sec_r000878_14;
    int sec_r000878_15;
    int sec_r000878_16;
    int pub_r000878_0;
    int pub_r000878_1;
    int pub_r000878_2;
    int pub_r000878_3;
    int pub_r000878_4;
    int pub_r000878_5;
    int pub_r000878_6;
    int pub_r000878_7;
    int pub_r000878_8;
    int pub_r000878_9;
    int pub_r000878_10;
    int pub_r000878_11;
    int pub_r000878_12;
    int pub_r000878_13;
    int pub_r000878_14;
    int pub_r000878_15;
    int pub_r000878_16;
    int pub_r000878_17;
    int pub_r000878_18;
    int pub_r000878_19;
    int pub_r000878_20;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000878_0 >= -100 && pub_r000878_0 <= 100);
    __CPROVER_assume(pub_r000878_1 >= -100 && pub_r000878_1 <= 100);
    __CPROVER_assume(pub_r000878_2 >= -100 && pub_r000878_2 <= 100);
    __CPROVER_assume(pub_r000878_3 >= -100 && pub_r000878_3 <= 100);
    __CPROVER_assume(pub_r000878_4 >= -100 && pub_r000878_4 <= 100);
    __CPROVER_assume(pub_r000878_5 >= -100 && pub_r000878_5 <= 100);
    __CPROVER_assume(pub_r000878_6 >= -100 && pub_r000878_6 <= 100);
    __CPROVER_assume(pub_r000878_7 >= -100 && pub_r000878_7 <= 100);
    __CPROVER_assume(pub_r000878_8 >= -100 && pub_r000878_8 <= 100);
    __CPROVER_assume(pub_r000878_9 >= -100 && pub_r000878_9 <= 100);
    __CPROVER_assume(pub_r000878_10 >= -100 && pub_r000878_10 <= 100);
    __CPROVER_assume(pub_r000878_11 >= -100 && pub_r000878_11 <= 100);
    __CPROVER_assume(pub_r000878_12 >= -100 && pub_r000878_12 <= 100);
    __CPROVER_assume(pub_r000878_13 >= -100 && pub_r000878_13 <= 100);
    __CPROVER_assume(pub_r000878_14 >= -100 && pub_r000878_14 <= 100);
    __CPROVER_assume(pub_r000878_15 >= -100 && pub_r000878_15 <= 100);
    __CPROVER_assume(pub_r000878_16 >= -100 && pub_r000878_16 <= 100);
    __CPROVER_assume(pub_r000878_17 >= -100 && pub_r000878_17 <= 100);
    __CPROVER_assume(pub_r000878_18 >= -100 && pub_r000878_18 <= 100);
    __CPROVER_assume(pub_r000878_19 >= -100 && pub_r000878_19 <= 100);
    __CPROVER_assume(pub_r000878_20 >= -100 && pub_r000878_20 <= 100);
    __CPROVER_assume(sec_r000878_0 >= 0 && sec_r000878_0 <= 255);
    __CPROVER_assume(sec_r000878_1 >= 0 && sec_r000878_1 <= 255);
    __CPROVER_assume(sec_r000878_2 >= 0 && sec_r000878_2 <= 255);
    __CPROVER_assume(sec_r000878_3 >= 0 && sec_r000878_3 <= 255);
    __CPROVER_assume(sec_r000878_4 >= 0 && sec_r000878_4 <= 255);
    __CPROVER_assume(sec_r000878_5 >= 0 && sec_r000878_5 <= 255);
    __CPROVER_assume(sec_r000878_6 >= 0 && sec_r000878_6 <= 255);
    __CPROVER_assume(sec_r000878_7 >= 0 && sec_r000878_7 <= 255);
    __CPROVER_assume(sec_r000878_8 >= 0 && sec_r000878_8 <= 255);
    __CPROVER_assume(sec_r000878_9 >= 0 && sec_r000878_9 <= 255);
    __CPROVER_assume(sec_r000878_10 >= 0 && sec_r000878_10 <= 255);
    __CPROVER_assume(sec_r000878_11 >= 0 && sec_r000878_11 <= 255);
    __CPROVER_assume(sec_r000878_12 >= 0 && sec_r000878_12 <= 255);
    __CPROVER_assume(sec_r000878_13 >= 0 && sec_r000878_13 <= 255);
    __CPROVER_assume(sec_r000878_14 >= 0 && sec_r000878_14 <= 255);
    __CPROVER_assume(sec_r000878_15 >= 0 && sec_r000878_15 <= 255);
    __CPROVER_assume(sec_r000878_16 >= 0 && sec_r000878_16 <= 255);

    struct Vector3D_R000878_7817_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000878_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000878_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000878_0 + 7) & 15;
    struct DeviceConfig_R000878_7817_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000878_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000878_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000878_0 + 9) & 15;

    union TelemetryField_R000878_7817_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 37) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 52) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_1.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_6 = (stage_v_6 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_6) & 127;
    }
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 10) & 15;
    int stage_v_9 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= stage_v_9;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

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
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 12) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 27) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 23) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 38) {
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
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 25) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 40) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 31) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 46) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 34) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 49) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[0] ^ 34) & 3;
    switch (stage_v_31) {
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

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 35 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 36) & 15;
    int stage_v_35 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_35) & 255;
    chk_sum ^= stage_v_35;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 23) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 38) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_0.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 23) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 38) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_1.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 34) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 49) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] ^ 57) & 3;
    switch (stage_v_54) {
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

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_0.buffer[2] * 2 + 175) & 63;
    if (stage_v_56 > 32) {
        out_sink = (out_sink + stage_v_56 - 5) & 255;
        if (stage_v_56 > 47) {
            chk_sum ^= (stage_v_56 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_56 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 35) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 50) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = table[0];
    table[0] = (table[1] + 129) & 63;
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (out_sink > 100) ? (chk_sum & 31) : (77 & 31);
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= (stage_v_72 << 1) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 36) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 51) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_75 = (stage_v_75 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_75) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 26) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 41) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (out_sink > 100) ? (chk_sum & 31) : (93 & 31);
    out_sink = (out_sink + stage_v_88) & 255;
    chk_sum ^= (stage_v_88 << 1) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_1.buffer[2] * 2 + 274) & 63;
    if (stage_v_89 > 10) {
        out_sink = (out_sink + stage_v_89 - 5) & 255;
        if (stage_v_89 > 25) {
            chk_sum ^= (stage_v_89 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_89 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = table[3];
    table[3] = (table[0] + 191) & 63;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[1] * 2 + 298) & 63;
    if (stage_v_97 > 13) {
        out_sink = (out_sink + stage_v_97 - 5) & 255;
        if (stage_v_97 > 28) {
            chk_sum ^= (stage_v_97 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_97 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_0.buffer[0] ^ 101) & 3;
    switch (stage_v_98) {
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

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (out_sink > 100) ? (chk_sum & 31) : (104 & 31);
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= (stage_v_99 << 1) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_100 = (stage_v_100 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 15) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 30) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_104 = (stage_v_104 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_111 = (stage_v_111 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_112 = (stage_v_112 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (out_sink > 100) ? (chk_sum & 31) : (118 & 31);
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= (stage_v_113 << 1) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 116) & 15;
    int stage_v_115 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= stage_v_115;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_0.buffer[0] ^ 119) & 3;
    switch (stage_v_116) {
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

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_1.buffer[0] ^ 122) & 3;
    switch (stage_v_119) {
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

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (out_sink > 100) ? (chk_sum & 31) : (128 & 31);
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= (stage_v_123 << 1) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 126) & 15;
    int stage_v_125 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= stage_v_125;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 16) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 31) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_128 = (stage_v_128 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1];
    table[1] = (table[2] + 259) & 63;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 134) & 15;
    int stage_v_133 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= stage_v_133;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (out_sink > 100) ? (chk_sum & 31) : (139 & 31);
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= (stage_v_134 << 1) & 127;

    /* Execution Pipeline Stage 135 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 136) & 15;
    int stage_v_135 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= stage_v_135;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_1.buffer[2] * 2 + 418) & 63;
    if (stage_v_137 > 16) {
        out_sink = (out_sink + stage_v_137 - 5) & 255;
        if (stage_v_137 > 31) {
            chk_sum ^= (stage_v_137 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_137 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 144) & 15;
    int stage_v_143 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= stage_v_143;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] * 2 + 439) & 63;
    if (stage_v_144 > 23) {
        out_sink = (out_sink + stage_v_144 - 5) & 255;
        if (stage_v_144 > 38) {
            chk_sum ^= (stage_v_144 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_144 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_145 = (stage_v_145 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_146 = (stage_v_146 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_1.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 28) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 43) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 32) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 47) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (out_sink > 100) ? (chk_sum & 31) : (155 & 31);
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= (stage_v_150 << 1) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = table[0];
    table[0] = (table[1] + 305) & 63;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = table[1];
    table[1] = (table[2] + 307) & 63;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_0.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 10) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 25) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_1.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = table[1];
    table[1] = (table[2] + 323) & 63;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 163) & 15;
    int stage_v_162 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= stage_v_162;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[0] ^ 167) & 3;
    switch (stage_v_164) {
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

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 24) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 39) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_0.buffer[0] ^ 169) & 3;
    switch (stage_v_166) {
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

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_167 = (stage_v_167 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 21) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 36) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[1] * 2 + 514) & 63;
    if (stage_v_169 > 32) {
        out_sink = (out_sink + stage_v_169 - 5) & 255;
        if (stage_v_169 > 47) {
            chk_sum ^= (stage_v_169 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_169 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_1.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 27) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 42) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] ^ 177) & 3;
    switch (stage_v_174) {
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

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_175 = (stage_v_175 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (out_sink > 100) ? (chk_sum & 31) : (182 & 31);
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= (stage_v_177 << 1) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_0.buffer[1] * 2 + 541) & 63;
    if (stage_v_178 > 19) {
        out_sink = (out_sink + stage_v_178 - 5) & 255;
        if (stage_v_178 > 34) {
            chk_sum ^= (stage_v_178 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_178 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_1.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 32) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 47) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_180 = (stage_v_180 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_180) & 127;
    }
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (out_sink > 100) ? (chk_sum & 31) : (187 & 31);
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= (stage_v_182 << 1) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_183 = (stage_v_183 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (out_sink > 100) ? (chk_sum & 31) : (189 & 31);
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= (stage_v_184 << 1) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (st_var_1.buffer[2] * 2 + 562) & 63;
    if (stage_v_185 > 17) {
        out_sink = (out_sink + stage_v_185 - 5) & 255;
        if (stage_v_185 > 32) {
            chk_sum ^= (stage_v_185 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_185 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] ^ 189) & 3;
    switch (stage_v_186) {
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

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[0] ^ 190) & 3;
    switch (stage_v_187) {
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

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_189 = (stage_v_189 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_189) & 127;
    }
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (out_sink > 100) ? (chk_sum & 31) : (196 & 31);
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= (stage_v_191 << 1) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] * 2 + 583) & 63;
    if (stage_v_192 > 17) {
        out_sink = (out_sink + stage_v_192 - 5) & 255;
        if (stage_v_192 > 32) {
            chk_sum ^= (stage_v_192 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_192 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (st_var_0.buffer[0] ^ 197) & 3;
    switch (stage_v_194) {
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

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = table[3];
    table[3] = (table[0] + 391) & 63;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_196 = (stage_v_196 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_196) & 127;
    }
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_197 = (stage_v_197 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_197) & 127;
    }
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (out_sink > 100) ? (chk_sum & 31) : (203 & 31);
    out_sink = (out_sink + stage_v_198) & 255;
    chk_sum ^= (stage_v_198 << 1) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (out_sink > 100) ? (chk_sum & 31) : (204 & 31);
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= (stage_v_199 << 1) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_200 = (stage_v_200 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_200) & 127;
    }
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (st_var_1.buffer[0] ^ 204) & 3;
    switch (stage_v_201) {
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

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (st_var_0.buffer[1] * 2 + 613) & 63;
    if (stage_v_202 > 33) {
        out_sink = (out_sink + stage_v_202 - 5) & 255;
        if (stage_v_202 > 48) {
            chk_sum ^= (stage_v_202 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_202 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (st_var_1.buffer[0] ^ 206) & 3;
    switch (stage_v_203) {
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

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (out_sink > 100) ? (chk_sum & 31) : (209 & 31);
    out_sink = (out_sink + stage_v_204) & 255;
    chk_sum ^= (stage_v_204 << 1) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (st_var_1.buffer[0] ^ 208) & 3;
    switch (stage_v_205) {
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

    /* Execution Pipeline Stage 206 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 207) & 15;
    int stage_v_206 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_206) & 255;
    chk_sum ^= stage_v_206;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_207 = (stage_v_207 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_207) & 127;
    }
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = table[0];
    table[0] = (table[1] + 417) & 63;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (out_sink > 100) ? (chk_sum & 31) : (215 & 31);
    out_sink = (out_sink + stage_v_210) & 255;
    chk_sum ^= (stage_v_210 << 1) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = table[3];
    table[3] = (table[0] + 423) & 63;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (st_var_0.buffer[0] ^ 215) & 3;
    switch (stage_v_212) {
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

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = table[1];
    table[1] = (table[2] + 427) & 63;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 215) & 15;
    int stage_v_214 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_214) & 255;
    chk_sum ^= stage_v_214;

    /* Execution Pipeline Stage 215 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 216) & 15;
    int stage_v_215 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_215) & 255;
    chk_sum ^= stage_v_215;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_216 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_217 = (stage_v_217 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_217) & 127;
    }
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (st_var_0.buffer[0] ^ 221) & 3;
    switch (stage_v_218) {
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

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = table[3];
    table[3] = (table[0] + 439) & 63;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 221) & 15;
    int stage_v_220 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_220) & 255;
    chk_sum ^= stage_v_220;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (out_sink > 100) ? (chk_sum & 31) : (226 & 31);
    out_sink = (out_sink + stage_v_221) & 255;
    chk_sum ^= (stage_v_221 << 1) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = table[2];
    table[2] = (table[3] + 445) & 63;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (out_sink > 100) ? (chk_sum & 31) : (228 & 31);
    out_sink = (out_sink + stage_v_223) & 255;
    chk_sum ^= (stage_v_223 << 1) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_224 = (stage_v_224 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_224) & 127;
    }
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_225 = (stage_v_225 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_225) & 127;
    }
    out_sink = (out_sink + stage_v_225) & 255;

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 80, 67, 59, 23 };
    int s_idx = (sec_r000878_16 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
