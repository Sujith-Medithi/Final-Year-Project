/*
 * Benchmark Program: R001280
 * Security Family: mixed_control_data
 * Generator Seed: 628013
 * High Inputs: 17 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R001280_8013_0 {
    int pitch;
    int coord_x;
    int norm_sq;
    unsigned char coord_z;
    int buffer[3];
};

struct StreamBuffer_R001280_8013_1 {
    unsigned char watermark;
    unsigned char state;
    int checksum;
    unsigned char capacity;
    int head;
    short tail;
    int buffer[3];
};

struct FilterState_R001280_8013_2 {
    short prev_in;
    int gain_db;
    int damping;
    int cutoff;
    int buffer[3];
};

union ColorPixel_R001280_8013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001280_8013_0(int p0, int p1, int p2) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001280_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int residue_32 = local_arr[aux % 3];
    acc = (acc + residue_32 * 2) & 127;
    int stride_84 = 0;
    for (int k = 0; k < 2; k++) {
        stride_84 = (stride_84 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_84) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_1(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int weight_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_47) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_59 = (aux + st.buffer[1]) & 3;
    switch (tracker_59) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_75 = local_arr[aux % 3];
    acc = (acc + weight_75 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001280_8013_2(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_34) & 63;
    acc ^= aux;
    int phase_70 = 0;
    for (int k = 0; k < 3; k++) {
        phase_70 = (phase_70 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + phase_70) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_3(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_57 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_57 = (anchor_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_57) & 127;
    }
    int coefficient_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001280_8013_4(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001280_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int factor_45 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_45 > 20) {
        acc = (acc + factor_45 * 2 + 5) & 127;
        aux ^= (factor_45 & 15);
    } else {
        acc = (acc - factor_45 + 11) & 127;
        aux += 3;
    }
    int damping_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_28) & 63;
    acc ^= aux;
    int margin_46 = 0;
    for (int k = 0; k < 3; k++) {
        margin_46 = (margin_46 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_46) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int quantum_74 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_74 > 46) {
        acc = (acc + quantum_74 * 2 + 5) & 127;
        aux ^= (quantum_74 & 15);
    } else {
        acc = (acc - quantum_74 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_87 = local_arr[aux % 3];
    acc = (acc + index_reg_87 * 2) & 127;
    int weight_23 = (aux + st.buffer[1]) & 3;
    switch (weight_23) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001280_8013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_67 = 0;
    for (int k = 0; k < 2; k++) {
        delta_67 = (delta_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_67) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001280_8013_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int residue_10 = (aux + st.buffer[1]) & 3;
    switch (residue_10) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_19 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_19 > 11) {
        acc = (acc + factor_19 * 2 + 5) & 127;
        aux ^= (factor_19 & 15);
    } else {
        acc = (acc - factor_19 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_80 = 0;
    for (int k = 0; k < 2; k++) {
        tally_80 = (tally_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_80) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_9(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001280_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int local_arr[3] = {4, 9, 15};
    int phase_27 = local_arr[aux % 3];
    acc = (acc + phase_27 * 2) & 127;
    int index_reg_52 = (aux + st.buffer[1]) & 3;
    switch (index_reg_52) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_98 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_98 > 31) {
        acc = (acc + threshold_98 * 2 + 5) & 127;
        aux ^= (threshold_98 & 15);
    } else {
        acc = (acc - threshold_98 + 11) & 127;
        aux += 3;
    }
    int index_reg_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001280_8013_10(int p0, int p1, int p2) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int index_reg_46 = (aux + st.buffer[1]) & 3;
    switch (index_reg_46) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_56 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_56) & 63;
    acc ^= aux;
    int tally_37 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_37 > 34) {
        acc = (acc + tally_37 * 2 + 5) & 127;
        aux ^= (tally_37 & 15);
    } else {
        acc = (acc - tally_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int stride_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_66) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_31 = 0;
    for (int k = 0; k < 3; k++) {
        parity_31 = (parity_31 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + parity_31) & 127;
    }
    int margin_97 = (aux + st.buffer[1]) & 3;
    switch (margin_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int margin_70 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_70 > 17) {
        acc = (acc + margin_70 * 2 + 5) & 127;
        aux ^= (margin_70 & 15);
    } else {
        acc = (acc - margin_70 + 11) & 127;
        aux += 3;
    }
    int coefficient_15 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_15 = (coefficient_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_15) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_90 = local_arr[aux % 3];
    acc = (acc + accumulator_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001280_8013_13(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001280_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int index_reg_39 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_39 = (index_reg_39 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_39) & 127;
    }
    int delta_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_65) & 63;
    acc ^= aux;
    int sample_76 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_76 > 15) {
        acc = (acc + sample_76 * 2 + 5) & 127;
        aux ^= (sample_76 & 15);
    } else {
        acc = (acc - sample_76 + 11) & 127;
        aux += 3;
    }
    int coefficient_34 = (aux + st.buffer[1]) & 3;
    switch (coefficient_34) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_14(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int offset_12 = 0;
    for (int k = 0; k < 2; k++) {
        offset_12 = (offset_12 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_12) & 127;
    }
    int tally_15 = (aux + st.buffer[1]) & 3;
    switch (tally_15) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_18 = local_arr[aux % 3];
    acc = (acc + damping_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001280_8013_15(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int coefficient_40 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_40 = (coefficient_40 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_40) & 127;
    }
    int coefficient_13 = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient_13 > 41) {
        acc = (acc + coefficient_13 * 2 + 5) & 127;
        aux ^= (coefficient_13 & 15);
    } else {
        acc = (acc - coefficient_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001280_8013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int anchor_56 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_56 > 34) {
        acc = (acc + anchor_56 * 2 + 5) & 127;
        aux ^= (anchor_56 & 15);
    } else {
        acc = (acc - anchor_56 + 11) & 127;
        aux += 3;
    }
    int tally_24 = (aux + st.buffer[1]) & 3;
    switch (tally_24) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_67 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_67 = (cursor_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_67) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R001280_8013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int metric_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_41) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int delta_42 = 0;
    for (int k = 0; k < 3; k++) {
        delta_42 = (delta_42 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + delta_42) & 127;
    }
    int anchor_14 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_14 > 12) {
        acc = (acc + anchor_14 * 2 + 5) & 127;
        aux ^= (anchor_14 & 15);
    } else {
        acc = (acc - anchor_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001280_8013_18(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001280_8013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int metric_66 = 0;
    for (int k = 0; k < 3; k++) {
        metric_66 = (metric_66 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_66) & 127;
    }
    int phase_11 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_11 > 31) {
        acc = (acc + phase_11 * 2 + 5) & 127;
        aux ^= (phase_11 & 15);
    } else {
        acc = (acc - phase_11 + 11) & 127;
        aux += 3;
    }
    int quotient_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_47) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001280_0;
    int sec_r001280_1;
    int sec_r001280_2;
    int sec_r001280_3;
    int sec_r001280_4;
    int sec_r001280_5;
    int sec_r001280_6;
    int sec_r001280_7;
    int sec_r001280_8;
    int sec_r001280_9;
    int sec_r001280_10;
    int sec_r001280_11;
    int sec_r001280_12;
    int sec_r001280_13;
    int sec_r001280_14;
    int sec_r001280_15;
    int sec_r001280_16;
    int pub_r001280_0;
    int pub_r001280_1;
    int pub_r001280_2;
    int pub_r001280_3;
    int pub_r001280_4;
    int pub_r001280_5;
    int pub_r001280_6;
    int pub_r001280_7;
    int pub_r001280_8;
    int pub_r001280_9;
    int pub_r001280_10;
    int pub_r001280_11;
    int pub_r001280_12;
    int pub_r001280_13;
    int pub_r001280_14;
    int pub_r001280_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001280_0 >= -100 && pub_r001280_0 <= 100);
    __CPROVER_assume(pub_r001280_1 >= -100 && pub_r001280_1 <= 100);
    __CPROVER_assume(pub_r001280_2 >= -100 && pub_r001280_2 <= 100);
    __CPROVER_assume(pub_r001280_3 >= -100 && pub_r001280_3 <= 100);
    __CPROVER_assume(pub_r001280_4 >= -100 && pub_r001280_4 <= 100);
    __CPROVER_assume(pub_r001280_5 >= -100 && pub_r001280_5 <= 100);
    __CPROVER_assume(pub_r001280_6 >= -100 && pub_r001280_6 <= 100);
    __CPROVER_assume(pub_r001280_7 >= -100 && pub_r001280_7 <= 100);
    __CPROVER_assume(pub_r001280_8 >= -100 && pub_r001280_8 <= 100);
    __CPROVER_assume(pub_r001280_9 >= -100 && pub_r001280_9 <= 100);
    __CPROVER_assume(pub_r001280_10 >= -100 && pub_r001280_10 <= 100);
    __CPROVER_assume(pub_r001280_11 >= -100 && pub_r001280_11 <= 100);
    __CPROVER_assume(pub_r001280_12 >= -100 && pub_r001280_12 <= 100);
    __CPROVER_assume(pub_r001280_13 >= -100 && pub_r001280_13 <= 100);
    __CPROVER_assume(pub_r001280_14 >= -100 && pub_r001280_14 <= 100);
    __CPROVER_assume(pub_r001280_15 >= -100 && pub_r001280_15 <= 100);
    __CPROVER_assume(sec_r001280_0 >= 0 && sec_r001280_0 <= 255);
    __CPROVER_assume(sec_r001280_1 >= 0 && sec_r001280_1 <= 255);
    __CPROVER_assume(sec_r001280_2 >= 0 && sec_r001280_2 <= 255);
    __CPROVER_assume(sec_r001280_3 >= 0 && sec_r001280_3 <= 255);
    __CPROVER_assume(sec_r001280_4 >= 0 && sec_r001280_4 <= 255);
    __CPROVER_assume(sec_r001280_5 >= 0 && sec_r001280_5 <= 255);
    __CPROVER_assume(sec_r001280_6 >= 0 && sec_r001280_6 <= 255);
    __CPROVER_assume(sec_r001280_7 >= 0 && sec_r001280_7 <= 255);
    __CPROVER_assume(sec_r001280_8 >= 0 && sec_r001280_8 <= 255);
    __CPROVER_assume(sec_r001280_9 >= 0 && sec_r001280_9 <= 255);
    __CPROVER_assume(sec_r001280_10 >= 0 && sec_r001280_10 <= 255);
    __CPROVER_assume(sec_r001280_11 >= 0 && sec_r001280_11 <= 255);
    __CPROVER_assume(sec_r001280_12 >= 0 && sec_r001280_12 <= 255);
    __CPROVER_assume(sec_r001280_13 >= 0 && sec_r001280_13 <= 255);
    __CPROVER_assume(sec_r001280_14 >= 0 && sec_r001280_14 <= 255);
    __CPROVER_assume(sec_r001280_15 >= 0 && sec_r001280_15 <= 255);
    __CPROVER_assume(sec_r001280_16 >= 0 && sec_r001280_16 <= 255);

    struct Vector3D_R001280_8013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001280_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001280_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001280_0 + 7) & 15;
    struct StreamBuffer_R001280_8013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001280_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001280_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001280_0 + 9) & 15;
    struct FilterState_R001280_8013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001280_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001280_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001280_0 + 11) & 15;

    union ColorPixel_R001280_8013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001280_8013_0(sec_r001280_0, pub_r001280_1, pub_r001280_2);
    int helper_flow_1 = fn_R001280_8013_1(sec_r001280_1, pub_r001280_2);
    int helper_flow_2 = fn_R001280_8013_2(sec_r001280_2, sec_r001280_3, pub_r001280_4);
    int helper_flow_3 = fn_R001280_8013_3(sec_r001280_3, sec_r001280_4);
    int helper_flow_4 = fn_R001280_8013_4(sec_r001280_4, sec_r001280_5, pub_r001280_6);
    int helper_flow_5 = fn_R001280_8013_5(sec_r001280_5, pub_r001280_6, pub_r001280_7, pub_r001280_8, pub_r001280_9);
    int helper_flow_6 = fn_R001280_8013_6(sec_r001280_6, sec_r001280_7, pub_r001280_8, pub_r001280_9, pub_r001280_10);
    int helper_flow_7 = fn_R001280_8013_7(sec_r001280_7, sec_r001280_8, pub_r001280_9, pub_r001280_10);
    int helper_flow_8 = fn_R001280_8013_8(sec_r001280_8, sec_r001280_9, pub_r001280_10, pub_r001280_11, pub_r001280_12);
    int helper_flow_9 = fn_R001280_8013_9(sec_r001280_9, pub_r001280_10, pub_r001280_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((sec_r001280_2 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_0 > 44) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001280_14 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((sec_r001280_0 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_2 > 50) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_3 > 22) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_4 > 27) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_5 > 31) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001280_2 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_6 > 21) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001280_2 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_7 > 26) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_8 > 40) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_9 > 40) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001280_15 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_10 > 45) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001280_6 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_12 > 44) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001280_16 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_13 > 35) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001280_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001280_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_16 > 32) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001280_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((sec_r001280_11 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_18 > 27) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_19 > 40) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((sec_r001280_3 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_20 > 48) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((sec_r001280_12 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_21 > 26) {
        out_sink = (out_sink + stage_v_21 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_21 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001280_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_23 > 30) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_24 > 43) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r001280_8 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_25 > 22) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r001280_7 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_26 > 42) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r001280_8 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_27 > 40) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_21 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_28 > 47) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001280_9 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001280_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_31 > 37) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001280_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_33 > 45) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001280_3 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_34 > 20) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_35 > 22) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_36 > 35) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_37 > 45) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_38 > 40) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r001280_3 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_39 > 36) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_40 > 50) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001280_12 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_41 > 40) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_42 > 45) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001280_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001280_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_45 > 29) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_46 > 41) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_47 > 34) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_48 > 42) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001280_8 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_50 > 20) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001280_3 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_52 > 49) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001280_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_8 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_54 > 36) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_33 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_55 > 29) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_56 > 21) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_57 > 28) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r001280_2 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_58 > 34) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_59 > 50) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_60 > 40) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_61 > 35) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001280_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_63 > 37) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_54 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_64 > 31) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001280_4 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_65 > 50) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_66 > 34) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((sec_r001280_6 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_67 > 26) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001280_10 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_69 > 45) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_70 > 41) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((sec_r001280_1 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_71 > 23) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((sec_r001280_3 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_72 > 40) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_2 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_73 > 45) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_74 > 30) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_75 > 34) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_76 > 21) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_77 > 44) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_78 > 36) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_79 > 29) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_80 > 31) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_81 > 43) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_82 > 47) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r001280_14 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_83 > 48) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_84 > 40) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_85 > 47) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_86 > 50) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_87 > 36) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r001280_3 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_88 > 21) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_89 > 31) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_90 > 24) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_82 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_91 > 21) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_92 > 50) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001280_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_94 > 47) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001280_13 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_55 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_96 > 23) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_26 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_97 > 42) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001280_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001280_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_100 > 44) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((sec_r001280_0 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_101 > 50) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r001280_10 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_102 > 46) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_66 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_103 > 34) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_104 > 41) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001280_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r001280_10 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_106 > 40) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_107 > 43) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001280_7 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_109 > 46) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001280_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_111 > 48) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_72 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_112 > 33) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_113 > 33) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001280_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_115 > 23) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001280_4 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_116 > 21) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_117 > 33) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001280_3 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_119 > 37) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_120 > 38) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001280_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001280_3 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_123 > 46) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((sec_r001280_10 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_124 > 35) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001280_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_126 > 37) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_127 > 46) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_116 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_128 > 27) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_129 > 50) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_103 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_130 > 37) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001280_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_132 > 41) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_133 > 34) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_124 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_134 > 37) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_135 > 36) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_136 > 25) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_137 > 42) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((sec_r001280_1 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_138 > 21) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_139 > 37) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((stage_v_139 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_140 > 42) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_141 > 20) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_142 > 40) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_143 > 29) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_133 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_144 > 31) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001280_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_146 > 44) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_147 > 43) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_148 > 40) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_149 > 41) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_140 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_150 > 26) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_151 > 28) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((sec_r001280_13 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_152 > 34) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_153 > 42) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001280_13) & 127;
    if (stage_v_154 > 39) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_84 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_155 > 49) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_80 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_156 > 28) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001280_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((sec_r001280_5 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_158 > 47) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r001280_4 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_159 > 28) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_160 > 41) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_161 > 44) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_162 > 39) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001280_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r001280_3 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_164 > 46) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_136 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_165 > 33) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_69 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_166 > 27) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_151 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_167 > 40) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001280_7 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001280_4 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001280_11 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_171 > 26) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_172 > 50) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_173 > 26) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_117 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_174 > 40) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_175 > 38) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001280_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_86 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_177 > 31) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_178 > 38) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_179 > 47) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (pub_r001280_15 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_180) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_181 > 37) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_182 > 31) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r001280_15 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_183 > 40) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_61 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_184 > 25) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001280_1 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_71 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_186 > 32) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001280_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_138 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_188 > 21) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_189 > 31) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001280_0 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001280_3 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_102 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_192 > 50) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_64 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_193 > 32) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_194 > 41) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_79 ^ 0x2A) * 2 + pub_r001280_0) & 127;
    if (stage_v_195 > 24) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_189 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_196 > 37) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001280_1 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_198 > 28) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_199 > 30) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_200 > 35) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_201 > 45) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_195 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_202 > 47) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_203 > 30) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_160 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_204 > 22) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_205 > 27) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_206 > 26) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_96 ^ 0x2A) * 2 + pub_r001280_15) & 127;
    if (stage_v_207 > 26) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_205 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_208 > 47) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001280_10 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((sec_r001280_8 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_210 > 50) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_211 > 20) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((stage_v_94 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_212 > 28) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_213 > 24) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_214 > 31) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_128 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_215 > 41) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_216 > 40) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_217 > 29) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_200 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_218 > 41) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_177 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_219 > 27) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_211 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_220 > 47) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (pub_r001280_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_221) & 127;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_60 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_222 > 28) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001280_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (pub_r001280_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_224) & 127;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (pub_r001280_9 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_225) & 127;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_141 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_226 > 40) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001280_8 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_158 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_228 > 22) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_210 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_229 > 31) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (pub_r001280_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_230) & 127;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001280_5) & 127;
    if (stage_v_231 > 20) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_111 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_232 > 37) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (pub_r001280_7 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_233) & 127;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001280_11) & 127;
    if (stage_v_234 > 50) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_204 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_235 > 48) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_236 > 44) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_135 ^ 0x2A) * 2 + pub_r001280_10) & 127;
    if (stage_v_237 > 20) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_182 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_238 > 47) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_239 > 50) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001280_1) & 127;
    if (stage_v_240 > 46) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (pub_r001280_10 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_241) & 127;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_242 > 26) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_243 > 38) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001280_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001280_3 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_28 ^ 0x2A) * 2 + pub_r001280_6) & 127;
    if (stage_v_246 > 30) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_174 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_247 > 22) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_199 ^ 0x2A) * 2 + pub_r001280_2) & 127;
    if (stage_v_248 > 46) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((sec_r001280_5 ^ 0x2A) * 2 + pub_r001280_7) & 127;
    if (stage_v_249 > 33) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_181 ^ 0x2A) * 2 + pub_r001280_3) & 127;
    if (stage_v_250 > 45) {
        out_sink = (out_sink + stage_v_250 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_250 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_107 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_251 > 24) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_238 ^ 0x2A) * 2 + pub_r001280_12) & 127;
    if (stage_v_252 > 27) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001280_14) & 127;
    if (stage_v_253 > 23) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_92 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_254 > 50) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_18 ^ 0x2A) * 2 + pub_r001280_9) & 127;
    if (stage_v_255 > 48) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001280_8) & 127;
    if (stage_v_256 > 36) {
        out_sink = (out_sink + stage_v_256 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_256 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_109 ^ 0x2A) * 2 + pub_r001280_4) & 127;
    if (stage_v_257 > 26) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
