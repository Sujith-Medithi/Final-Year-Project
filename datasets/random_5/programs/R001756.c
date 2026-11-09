/*
 * Benchmark Program: R001756
 * Security Family: implicit_flow
 * Generator Seed: 675613
 * High Inputs: 17 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001756_5613_0 {
    short heading;
    int coord_x;
    int coord_y;
    int pitch;
    int buffer[3];
};

struct StreamBuffer_R001756_5613_1 {
    int watermark;
    short capacity;
    unsigned char tail;
    short head;
    int buffer[3];
};

union RegisterBank_R001756_5613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001756_5613_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int delta_44 = (aux + st.buffer[1]) & 3;
    switch (delta_44) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_14) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int quotient_19 = local_arr[aux % 3];
    acc = (acc + quotient_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001756_5613_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int metric_97 = local_arr[aux % 3];
    acc = (acc + metric_97 * 2) & 127;
    int parity_43 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_43 > 33) {
        acc = (acc + parity_43 * 2 + 5) & 127;
        aux ^= (parity_43 & 15);
    } else {
        acc = (acc - parity_43 + 11) & 127;
        aux += 3;
    }
    int bound_50 = 0;
    for (int k = 0; k < 3; k++) {
        bound_50 = (bound_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + bound_50) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int segment_11 = (aux + st.buffer[1]) & 3;
    switch (segment_11) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_12) & 63;
    acc ^= aux;
    int residue_40 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_40 > 33) {
        acc = (acc + residue_40 * 2 + 5) & 127;
        aux ^= (residue_40 & 15);
    } else {
        acc = (acc - residue_40 + 11) & 127;
        aux += 3;
    }
    int segment_22 = 0;
    for (int k = 0; k < 3; k++) {
        segment_22 = (segment_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_16 = 0;
    for (int k = 0; k < 3; k++) {
        sample_16 = (sample_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_16) & 127;
    }
    int damping_15 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_15 > 14) {
        acc = (acc + damping_15 * 2 + 5) & 127;
        aux ^= (damping_15 & 15);
    } else {
        acc = (acc - damping_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001756_5613_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int vector_11 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_11 > 28) {
        acc = (acc + vector_11 * 2 + 5) & 127;
        aux ^= (vector_11 & 15);
    } else {
        acc = (acc - vector_11 + 11) & 127;
        aux += 3;
    }
    int window_18 = (aux + st.buffer[1]) & 3;
    switch (window_18) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_14 = local_arr[aux % 3];
    acc = (acc + damping_14 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001756_5613_5(int p0, int p1) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_33 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_33 > 29) {
        acc = (acc + checksum_33 * 2 + 5) & 127;
        aux ^= (checksum_33 & 15);
    } else {
        acc = (acc - checksum_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_17 = local_arr[aux % 3];
    acc = (acc + sample_17 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001756_5613_6(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int anchor_90 = local_arr[aux % 3];
    acc = (acc + anchor_90 * 2) & 127;
    int phase_16 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_16 > 23) {
        acc = (acc + phase_16 * 2 + 5) & 127;
        aux ^= (phase_16 & 15);
    } else {
        acc = (acc - phase_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_7(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int accumulator_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_38) & 63;
    acc ^= aux;
    int factor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_68 > 31) {
        acc = (acc + factor_68 * 2 + 5) & 127;
        aux ^= (factor_68 & 15);
    } else {
        acc = (acc - factor_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_8(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int parity_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_73) & 63;
    acc ^= aux;
    int threshold_94 = (aux + st.buffer[1]) & 3;
    switch (threshold_94) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_16 = local_arr[aux % 3];
    acc = (acc + anchor_16 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001756_5613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_99) & 63;
    acc ^= aux;
    int window_31 = 0;
    for (int k = 0; k < 3; k++) {
        window_31 = (window_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_31) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int damping_65 = (aux + st.buffer[1]) & 3;
    switch (damping_65) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_46 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_46 > 45) {
        acc = (acc + quotient_46 * 2 + 5) & 127;
        aux ^= (quotient_46 & 15);
    } else {
        acc = (acc - quotient_46 + 11) & 127;
        aux += 3;
    }
    int tally_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_32) & 63;
    acc ^= aux;
    int weight_83 = 0;
    for (int k = 0; k < 2; k++) {
        weight_83 = (weight_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + weight_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int index_reg_32 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_32 > 32) {
        acc = (acc + index_reg_32 * 2 + 5) & 127;
        aux ^= (index_reg_32 & 15);
    } else {
        acc = (acc - index_reg_32 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_52 = local_arr[aux % 3];
    acc = (acc + vector_52 * 2) & 127;
    int phase_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_35) & 63;
    acc ^= aux;
    int mask_98 = 0;
    for (int k = 0; k < 2; k++) {
        mask_98 = (mask_98 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_98) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int sample_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_74) & 63;
    acc ^= aux;
    int pivot_35 = (aux + st.buffer[1]) & 3;
    switch (pivot_35) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_89 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_89 > 28) {
        acc = (acc + offset_89 * 2 + 5) & 127;
        aux ^= (offset_89 & 15);
    } else {
        acc = (acc - offset_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_13(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_35 = (aux + st.buffer[1]) & 3;
    switch (accumulator_35) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_35 = local_arr[aux % 3];
    acc = (acc + residue_35 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001756_5613_14(int p0, int p1, int p2) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_32) & 63;
    acc ^= aux;
    int delta_55 = 0;
    for (int k = 0; k < 3; k++) {
        delta_55 = (delta_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_55) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_15(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_38) & 63;
    acc ^= aux;
    int factor_91 = 0;
    for (int k = 0; k < 3; k++) {
        factor_91 = (factor_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_91) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001756_5613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int coefficient_56 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_56 = (coefficient_56 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_56) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_63) & 63;
    acc ^= aux;
    int sample_91 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_91 > 12) {
        acc = (acc + sample_91 * 2 + 5) & 127;
        aux ^= (sample_91 & 15);
    } else {
        acc = (acc - sample_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001756_5613_17(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001756_5613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int segment_68 = local_arr[aux % 3];
    acc = (acc + segment_68 * 2) & 127;
    int margin_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_10) & 63;
    acc ^= aux;
    int index_reg_61 = 0;
    for (int k = 0; k < 3; k++) {
        index_reg_61 = (index_reg_61 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_61) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001756_0;
    int sec_r001756_1;
    int sec_r001756_2;
    int sec_r001756_3;
    int sec_r001756_4;
    int sec_r001756_5;
    int sec_r001756_6;
    int sec_r001756_7;
    int sec_r001756_8;
    int sec_r001756_9;
    int sec_r001756_10;
    int sec_r001756_11;
    int sec_r001756_12;
    int sec_r001756_13;
    int sec_r001756_14;
    int sec_r001756_15;
    int sec_r001756_16;
    int pub_r001756_0;
    int pub_r001756_1;
    int pub_r001756_2;
    int pub_r001756_3;
    int pub_r001756_4;
    int pub_r001756_5;
    int pub_r001756_6;
    int pub_r001756_7;
    int pub_r001756_8;
    int pub_r001756_9;
    int pub_r001756_10;
    int pub_r001756_11;
    int pub_r001756_12;
    int pub_r001756_13;
    int pub_r001756_14;
    int pub_r001756_15;
    int pub_r001756_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001756_0 >= -100 && pub_r001756_0 <= 100);
    __CPROVER_assume(pub_r001756_1 >= -100 && pub_r001756_1 <= 100);
    __CPROVER_assume(pub_r001756_2 >= -100 && pub_r001756_2 <= 100);
    __CPROVER_assume(pub_r001756_3 >= -100 && pub_r001756_3 <= 100);
    __CPROVER_assume(pub_r001756_4 >= -100 && pub_r001756_4 <= 100);
    __CPROVER_assume(pub_r001756_5 >= -100 && pub_r001756_5 <= 100);
    __CPROVER_assume(pub_r001756_6 >= -100 && pub_r001756_6 <= 100);
    __CPROVER_assume(pub_r001756_7 >= -100 && pub_r001756_7 <= 100);
    __CPROVER_assume(pub_r001756_8 >= -100 && pub_r001756_8 <= 100);
    __CPROVER_assume(pub_r001756_9 >= -100 && pub_r001756_9 <= 100);
    __CPROVER_assume(pub_r001756_10 >= -100 && pub_r001756_10 <= 100);
    __CPROVER_assume(pub_r001756_11 >= -100 && pub_r001756_11 <= 100);
    __CPROVER_assume(pub_r001756_12 >= -100 && pub_r001756_12 <= 100);
    __CPROVER_assume(pub_r001756_13 >= -100 && pub_r001756_13 <= 100);
    __CPROVER_assume(pub_r001756_14 >= -100 && pub_r001756_14 <= 100);
    __CPROVER_assume(pub_r001756_15 >= -100 && pub_r001756_15 <= 100);
    __CPROVER_assume(pub_r001756_16 >= -100 && pub_r001756_16 <= 100);
    __CPROVER_assume(sec_r001756_0 >= 0 && sec_r001756_0 <= 255);
    __CPROVER_assume(sec_r001756_1 >= 0 && sec_r001756_1 <= 255);
    __CPROVER_assume(sec_r001756_2 >= 0 && sec_r001756_2 <= 255);
    __CPROVER_assume(sec_r001756_3 >= 0 && sec_r001756_3 <= 255);
    __CPROVER_assume(sec_r001756_4 >= 0 && sec_r001756_4 <= 255);
    __CPROVER_assume(sec_r001756_5 >= 0 && sec_r001756_5 <= 255);
    __CPROVER_assume(sec_r001756_6 >= 0 && sec_r001756_6 <= 255);
    __CPROVER_assume(sec_r001756_7 >= 0 && sec_r001756_7 <= 255);
    __CPROVER_assume(sec_r001756_8 >= 0 && sec_r001756_8 <= 255);
    __CPROVER_assume(sec_r001756_9 >= 0 && sec_r001756_9 <= 255);
    __CPROVER_assume(sec_r001756_10 >= 0 && sec_r001756_10 <= 255);
    __CPROVER_assume(sec_r001756_11 >= 0 && sec_r001756_11 <= 255);
    __CPROVER_assume(sec_r001756_12 >= 0 && sec_r001756_12 <= 255);
    __CPROVER_assume(sec_r001756_13 >= 0 && sec_r001756_13 <= 255);
    __CPROVER_assume(sec_r001756_14 >= 0 && sec_r001756_14 <= 255);
    __CPROVER_assume(sec_r001756_15 >= 0 && sec_r001756_15 <= 255);
    __CPROVER_assume(sec_r001756_16 >= 0 && sec_r001756_16 <= 255);

    struct Vector3D_R001756_5613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001756_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001756_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001756_0 + 7) & 15;
    struct StreamBuffer_R001756_5613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001756_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001756_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001756_0 + 9) & 15;

    union RegisterBank_R001756_5613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001756_5613_0(sec_r001756_0, sec_r001756_1, pub_r001756_2, pub_r001756_3);
    int helper_flow_1 = fn_R001756_5613_1(sec_r001756_1, sec_r001756_2, pub_r001756_3, pub_r001756_4, pub_r001756_5);
    int helper_flow_2 = fn_R001756_5613_2(sec_r001756_2, pub_r001756_3, pub_r001756_4, pub_r001756_5);
    int helper_flow_3 = fn_R001756_5613_3(sec_r001756_3, pub_r001756_4, pub_r001756_5, pub_r001756_6);
    int helper_flow_4 = fn_R001756_5613_4(sec_r001756_4, sec_r001756_5, pub_r001756_6, pub_r001756_7);
    int helper_flow_5 = fn_R001756_5613_5(sec_r001756_5, pub_r001756_6);
    int helper_flow_6 = fn_R001756_5613_6(sec_r001756_6, sec_r001756_7, pub_r001756_8);
    int helper_flow_7 = fn_R001756_5613_7(sec_r001756_7, sec_r001756_8, pub_r001756_9);
    int helper_flow_8 = fn_R001756_5613_8(sec_r001756_8, pub_r001756_9, pub_r001756_10);
    int helper_flow_9 = fn_R001756_5613_9(sec_r001756_9, sec_r001756_10, pub_r001756_11, pub_r001756_12, pub_r001756_13);
    int helper_flow_10 = fn_R001756_5613_10(sec_r001756_10, pub_r001756_11, pub_r001756_12, pub_r001756_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001756_8 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (sec_r001756_1 + pub_r001756_2 * 2 + 8) & 127;
    if (stage_v_1 > 52) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
        sec_accum ^= (stage_v_1 & 31);
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001756_11 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_10 + pub_r001756_5 * 2 + 14) & 127;
    if (stage_v_3 > 17) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_4 + pub_r001756_12 * 2 + 17) & 127;
    if (stage_v_4 > 44) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001756_16 + pub_r001756_1 * 2 + 20) & 127;
    if (stage_v_5 > 21) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001756_15 + pub_r001756_9 * 2 + 23) & 127;
    if (stage_v_6 > 28) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (helper_flow_10 + pub_r001756_16 * 2 + 26) & 127;
    if (stage_v_7 > 58) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
        sec_accum ^= (stage_v_7 & 31);
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (stage_v_3 + pub_r001756_3 * 2 + 29) & 127;
    if (stage_v_8 > 55) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (pub_r001756_13 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_9) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001756_1 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001756_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001756_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001756_15 + pub_r001756_11 * 2 + 44) & 127;
    if (stage_v_13 > 57) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
        sec_accum ^= (stage_v_13 & 31);
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_13 + pub_r001756_16 * 2 + 47) & 127;
    if (stage_v_14 > 51) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001756_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001756_0 + pub_r001756_0 * 2 + 53) & 127;
    if (stage_v_16 > 29) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
        sec_accum ^= (stage_v_16 & 31);
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (helper_flow_0 + pub_r001756_13 * 2 + 56) & 127;
    if (stage_v_17 > 34) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
        sec_accum ^= (stage_v_17 & 31);
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_5 + pub_r001756_6 * 2 + 59) & 127;
    if (stage_v_18 > 19) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001756_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001756_2 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (stage_v_14 + pub_r001756_4 * 2 + 68) & 127;
    if (stage_v_21 > 34) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
        sec_accum ^= (stage_v_21 & 31);
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_21 + pub_r001756_7 * 2 + 71) & 127;
    if (stage_v_22 > 59) {
        out_sink = (out_sink + stage_v_22 * 2 + 7) & 255;
        sec_accum ^= (stage_v_22 & 31);
    } else {
        out_sink = (out_sink - stage_v_22 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_17 + pub_r001756_5 * 2 + 74) & 127;
    if (stage_v_23 > 42) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001756_8 + pub_r001756_16 * 2 + 77) & 127;
    if (stage_v_24 > 50) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001756_11 + pub_r001756_14 * 2 + 80) & 127;
    if (stage_v_25 > 44) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (sec_r001756_3 + pub_r001756_0 * 2 + 83) & 127;
    if (stage_v_26 > 27) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
        sec_accum ^= (stage_v_26 & 31);
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001756_9 + pub_r001756_13 * 2 + 86) & 127;
    if (stage_v_27 > 50) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001756_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001756_7 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001756_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (sec_r001756_15 + pub_r001756_1 * 2 + 98) & 127;
    if (stage_v_31 > 48) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001756_16 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001756_16 + pub_r001756_0 * 2 + 104) & 127;
    if (stage_v_33 > 47) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (helper_flow_5 + pub_r001756_14 * 2 + 107) & 127;
    if (stage_v_34 > 48) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
        sec_accum ^= (stage_v_34 & 31);
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001756_9 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001756_13 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001756_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (helper_flow_0 + pub_r001756_3 * 2 + 119) & 127;
    if (stage_v_38 > 39) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001756_7 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001756_15 + pub_r001756_12 * 2 + 125) & 127;
    if (stage_v_40 > 40) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (stage_v_17 + pub_r001756_7 * 2 + 128) & 127;
    if (stage_v_41 > 23) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
        sec_accum ^= (stage_v_41 & 31);
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001756_6 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001756_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001756_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (helper_flow_7 + pub_r001756_14 * 2 + 140) & 127;
    if (stage_v_45 > 27) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (stage_v_33 + pub_r001756_11 * 2 + 143) & 127;
    if (stage_v_46 > 27) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (helper_flow_7 + pub_r001756_6 * 2 + 146) & 127;
    if (stage_v_47 > 54) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (helper_flow_6 + pub_r001756_1 * 2 + 149) & 127;
    if (stage_v_48 > 18) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_23 + pub_r001756_7 * 2 + 152) & 127;
    if (stage_v_49 > 23) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_0 + pub_r001756_16 * 2 + 155) & 127;
    if (stage_v_50 > 16) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (sec_r001756_12 + pub_r001756_12 * 2 + 158) & 127;
    if (stage_v_51 > 60) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_48 + pub_r001756_9 * 2 + 161) & 127;
    if (stage_v_52 > 28) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
        sec_accum ^= (stage_v_52 & 31);
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (stage_v_24 + pub_r001756_12 * 2 + 164) & 127;
    if (stage_v_53 > 60) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
        sec_accum ^= (stage_v_53 & 31);
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001756_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (stage_v_51 + pub_r001756_12 * 2 + 170) & 127;
    if (stage_v_55 > 31) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
        sec_accum ^= (stage_v_55 & 31);
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_23 + pub_r001756_5 * 2 + 173) & 127;
    if (stage_v_56 > 34) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
        sec_accum ^= (stage_v_56 & 31);
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001756_1 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (stage_v_23 + pub_r001756_13 * 2 + 179) & 127;
    if (stage_v_58 > 36) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (stage_v_24 + pub_r001756_3 * 2 + 182) & 127;
    if (stage_v_59 > 50) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
        sec_accum ^= (stage_v_59 & 31);
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (pub_r001756_16 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_60) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001756_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001756_0 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_55 + pub_r001756_16 * 2 + 194) & 127;
    if (stage_v_63 > 54) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_5 + pub_r001756_12 * 2 + 197) & 127;
    if (stage_v_64 > 35) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
        sec_accum ^= (stage_v_64 & 31);
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001756_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001756_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001756_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001756_11 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001756_0 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001756_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (pub_r001756_15 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_71) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_24 + pub_r001756_5 * 2 + 221) & 127;
    if (stage_v_72 > 20) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001756_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_51 + pub_r001756_16 * 2 + 227) & 127;
    if (stage_v_74 > 47) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (sec_r001756_4 + pub_r001756_13 * 2 + 230) & 127;
    if (stage_v_75 > 19) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
        sec_accum ^= (stage_v_75 & 31);
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001756_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (sec_r001756_10 + pub_r001756_4 * 2 + 236) & 127;
    if (stage_v_77 > 31) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
        sec_accum ^= (stage_v_77 & 31);
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_45 + pub_r001756_11 * 2 + 239) & 127;
    if (stage_v_78 > 54) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
        sec_accum ^= (stage_v_78 & 31);
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_24 + pub_r001756_10 * 2 + 242) & 127;
    if (stage_v_79 > 17) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_6 + pub_r001756_16 * 2 + 245) & 127;
    if (stage_v_80 > 32) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_33 + pub_r001756_16 * 2 + 248) & 127;
    if (stage_v_81 > 51) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_16 + pub_r001756_14 * 2 + 251) & 127;
    if (stage_v_82 > 40) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_51 + pub_r001756_14 * 2 + 254) & 127;
    if (stage_v_83 > 60) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_26 + pub_r001756_5 * 2 + 257) & 127;
    if (stage_v_84 > 56) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_84 + pub_r001756_11 * 2 + 260) & 127;
    if (stage_v_85 > 38) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001756_14 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001756_2 + pub_r001756_9 * 2 + 266) & 127;
    if (stage_v_87 > 36) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_5 + pub_r001756_4 * 2 + 269) & 127;
    if (stage_v_88 > 52) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001756_3 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_5 + pub_r001756_5 * 2 + 275) & 127;
    if (stage_v_90 > 37) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_40 + pub_r001756_14 * 2 + 278) & 127;
    if (stage_v_91 > 52) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001756_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001756_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001756_9 + pub_r001756_12 * 2 + 287) & 127;
    if (stage_v_94 > 20) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
        sec_accum ^= (stage_v_94 & 31);
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_21 + pub_r001756_8 * 2 + 290) & 127;
    if (stage_v_95 > 31) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_84 + pub_r001756_4 * 2 + 293) & 127;
    if (stage_v_96 > 39) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001756_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_55 + pub_r001756_7 * 2 + 299) & 127;
    if (stage_v_98 > 39) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_77 + pub_r001756_16 * 2 + 302) & 127;
    if (stage_v_99 > 38) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
        sec_accum ^= (stage_v_99 & 31);
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (sec_r001756_12 + pub_r001756_3 * 2 + 305) & 127;
    if (stage_v_100 > 39) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001756_13 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_63 + pub_r001756_10 * 2 + 311) & 127;
    if (stage_v_102 > 29) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_23 + pub_r001756_11 * 2 + 314) & 127;
    if (stage_v_103 > 32) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001756_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001756_12 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001756_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001756_5 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_33 + pub_r001756_11 * 2 + 329) & 127;
    if (stage_v_108 > 39) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001756_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001756_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_59 + pub_r001756_11 * 2 + 338) & 127;
    if (stage_v_111 > 60) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001756_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_18 + pub_r001756_10 * 2 + 344) & 127;
    if (stage_v_113 > 47) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
        sec_accum ^= (stage_v_113 & 31);
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001756_13 + pub_r001756_0 * 2 + 347) & 127;
    if (stage_v_114 > 22) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001756_11 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (helper_flow_5 + pub_r001756_13 * 2 + 353) & 127;
    if (stage_v_116 > 40) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
        sec_accum ^= (stage_v_116 & 31);
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001756_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_116 + pub_r001756_7 * 2 + 359) & 127;
    if (stage_v_118 > 25) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001756_9 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001756_0 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001756_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001756_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (sec_r001756_14 + pub_r001756_8 * 2 + 374) & 127;
    if (stage_v_123 > 22) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
        sec_accum ^= (stage_v_123 & 31);
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_96 + pub_r001756_5 * 2 + 377) & 127;
    if (stage_v_124 > 21) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
        sec_accum ^= (stage_v_124 & 31);
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_8 + pub_r001756_3 * 2 + 380) & 127;
    if (stage_v_125 > 18) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (sec_r001756_14 + pub_r001756_10 * 2 + 383) & 127;
    if (stage_v_126 > 54) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
        sec_accum ^= (stage_v_126 & 31);
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (sec_r001756_4 + pub_r001756_3 * 2 + 386) & 127;
    if (stage_v_127 > 53) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_47 + pub_r001756_6 * 2 + 389) & 127;
    if (stage_v_128 > 16) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_100 + pub_r001756_3 * 2 + 392) & 127;
    if (stage_v_129 > 44) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
        sec_accum ^= (stage_v_129 & 31);
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_63 + pub_r001756_13 * 2 + 395) & 127;
    if (stage_v_130 > 38) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_5 + pub_r001756_7 * 2 + 398) & 127;
    if (stage_v_131 > 29) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
        sec_accum ^= (stage_v_131 & 31);
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001756_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_45 + pub_r001756_8 * 2 + 404) & 127;
    if (stage_v_133 > 20) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
        sec_accum ^= (stage_v_133 & 31);
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_103 + pub_r001756_0 * 2 + 407) & 127;
    if (stage_v_134 > 18) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001756_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001756_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001756_9 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001756_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001756_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (stage_v_58 + pub_r001756_1 * 2 + 425) & 127;
    if (stage_v_140 > 23) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
        sec_accum ^= (stage_v_140 & 31);
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001756_10 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001756_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_133 + pub_r001756_6 * 2 + 434) & 127;
    if (stage_v_143 > 15) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
        sec_accum ^= (stage_v_143 & 31);
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (stage_v_51 + pub_r001756_7 * 2 + 437) & 127;
    if (stage_v_144 > 35) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
        sec_accum ^= (stage_v_144 & 31);
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001756_0 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_48 + pub_r001756_16 * 2 + 443) & 127;
    if (stage_v_146 > 36) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
        sec_accum ^= (stage_v_146 & 31);
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001756_5 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_79 + pub_r001756_10 * 2 + 449) & 127;
    if (stage_v_148 > 58) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001756_16 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_40 + pub_r001756_10 * 2 + 455) & 127;
    if (stage_v_150 > 21) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_75 + pub_r001756_7 * 2 + 458) & 127;
    if (stage_v_151 > 23) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
        sec_accum ^= (stage_v_151 & 31);
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001756_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_75 + pub_r001756_1 * 2 + 464) & 127;
    if (stage_v_153 > 27) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
        sec_accum ^= (stage_v_153 & 31);
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_108 + pub_r001756_2 * 2 + 467) & 127;
    if (stage_v_154 > 42) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
        sec_accum ^= (stage_v_154 & 31);
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_55 + pub_r001756_7 * 2 + 470) & 127;
    if (stage_v_155 > 45) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_113 + pub_r001756_0 * 2 + 473) & 127;
    if (stage_v_156 > 56) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_78 + pub_r001756_16 * 2 + 476) & 127;
    if (stage_v_157 > 49) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (sec_r001756_11 + pub_r001756_14 * 2 + 479) & 127;
    if (stage_v_158 > 36) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001756_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (helper_flow_2 + pub_r001756_1 * 2 + 485) & 127;
    if (stage_v_160 > 36) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
        sec_accum ^= (stage_v_160 & 31);
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_52 + pub_r001756_13 * 2 + 488) & 127;
    if (stage_v_161 > 27) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
        sec_accum ^= (stage_v_161 & 31);
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (sec_r001756_4 + pub_r001756_12 * 2 + 491) & 127;
    if (stage_v_162 > 46) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
        sec_accum ^= (stage_v_162 & 31);
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001756_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001756_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_102 + pub_r001756_1 * 2 + 500) & 127;
    if (stage_v_165 > 20) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
        sec_accum ^= (stage_v_165 & 31);
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_127 + pub_r001756_7 * 2 + 503) & 127;
    if (stage_v_166 > 53) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
        sec_accum ^= (stage_v_166 & 31);
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_96 + pub_r001756_11 * 2 + 506) & 127;
    if (stage_v_167 > 26) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_150 + pub_r001756_10 * 2 + 509) & 127;
    if (stage_v_168 > 43) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
        sec_accum ^= (stage_v_168 & 31);
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (sec_r001756_15 + pub_r001756_16 * 2 + 512) & 127;
    if (stage_v_169 > 45) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (sec_r001756_16 + pub_r001756_1 * 2 + 515) & 127;
    if (stage_v_170 > 34) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_168 + pub_r001756_10 * 2 + 518) & 127;
    if (stage_v_171 > 24) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_1 + pub_r001756_4 * 2 + 521) & 127;
    if (stage_v_172 > 29) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
        sec_accum ^= (stage_v_172 & 31);
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001756_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001756_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (sec_r001756_2 + pub_r001756_9 * 2 + 530) & 127;
    if (stage_v_175 > 22) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
        sec_accum ^= (stage_v_175 & 31);
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (stage_v_3 + pub_r001756_13 * 2 + 533) & 127;
    if (stage_v_176 > 33) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
        sec_accum ^= (stage_v_176 & 31);
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001756_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_116 + pub_r001756_0 * 2 + 539) & 127;
    if (stage_v_178 > 52) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (pub_r001756_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_179) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_118 + pub_r001756_7 * 2 + 545) & 127;
    if (stage_v_180 > 27) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001756_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_81 + pub_r001756_9 * 2 + 551) & 127;
    if (stage_v_182 > 50) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001756_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_98 + pub_r001756_13 * 2 + 557) & 127;
    if (stage_v_184 > 37) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
        sec_accum ^= (stage_v_184 & 31);
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_125 + pub_r001756_11 * 2 + 560) & 127;
    if (stage_v_185 > 42) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001756_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_87 + pub_r001756_8 * 2 + 566) & 127;
    if (stage_v_187 > 47) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001756_4 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001756_2 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_158 + pub_r001756_11 * 2 + 575) & 127;
    if (stage_v_190 > 49) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
        sec_accum ^= (stage_v_190 & 31);
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_133 + pub_r001756_14 * 2 + 578) & 127;
    if (stage_v_191 > 54) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
        sec_accum ^= (stage_v_191 & 31);
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_59 + pub_r001756_14 * 2 + 581) & 127;
    if (stage_v_192 > 51) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (helper_flow_1 + pub_r001756_9 * 2 + 584) & 127;
    if (stage_v_193 > 43) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001756_12 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_6 + pub_r001756_16 * 2 + 590) & 127;
    if (stage_v_195 > 19) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
        sec_accum ^= (stage_v_195 & 31);
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (stage_v_133 + pub_r001756_15 * 2 + 593) & 127;
    if (stage_v_196 > 25) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
        sec_accum ^= (stage_v_196 & 31);
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_143 + pub_r001756_0 * 2 + 596) & 127;
    if (stage_v_197 > 56) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001756_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001756_10 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001756_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (helper_flow_6 + pub_r001756_16 * 2 + 608) & 127;
    if (stage_v_201 > 16) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001756_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001756_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_172 + pub_r001756_15 * 2 + 617) & 127;
    if (stage_v_204 > 51) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001756_14 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001756_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001756_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_38 + pub_r001756_1 * 2 + 629) & 127;
    if (stage_v_208 > 58) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
        sec_accum ^= (stage_v_208 & 31);
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001756_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001756_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_176 + pub_r001756_2 * 2 + 638) & 127;
    if (stage_v_211 > 15) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001756_14 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_148 + pub_r001756_5 * 2 + 644) & 127;
    if (stage_v_213 > 57) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_33 + pub_r001756_2 * 2 + 647) & 127;
    if (stage_v_214 > 60) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (sec_r001756_15 + pub_r001756_7 * 2 + 650) & 127;
    if (stage_v_215 > 45) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (helper_flow_3 + pub_r001756_16 * 2 + 653) & 127;
    if (stage_v_216 > 26) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r001756_2 + pub_r001756_0 * 2 + 656) & 127;
    if (stage_v_217 > 23) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_182 + pub_r001756_9 * 2 + 659) & 127;
    if (stage_v_218 > 21) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (helper_flow_9 + pub_r001756_0 * 2 + 662) & 127;
    if (stage_v_219 > 41) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
        sec_accum ^= (stage_v_219 & 31);
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_128 + pub_r001756_11 * 2 + 665) & 127;
    if (stage_v_220 > 59) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_204 + pub_r001756_0 * 2 + 668) & 127;
    if (stage_v_221 > 28) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001756_6 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (stage_v_178 + pub_r001756_9 * 2 + 674) & 127;
    if (stage_v_223 > 23) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
        sec_accum ^= (stage_v_223 & 31);
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001756_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001756_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001756_13 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001756_4 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_95 + pub_r001756_8 * 2 + 689) & 127;
    if (stage_v_228 > 56) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (sec_r001756_6 + pub_r001756_2 * 2 + 692) & 127;
    if (stage_v_229 > 22) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_215 + pub_r001756_4 * 2 + 695) & 127;
    if (stage_v_230 > 17) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (stage_v_98 + pub_r001756_10 * 2 + 698) & 127;
    if (stage_v_231 > 38) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
        sec_accum ^= (stage_v_231 & 31);
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
