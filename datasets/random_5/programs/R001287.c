/*
 * Benchmark Program: R001287
 * Security Family: nested_implicit_flow
 * Generator Seed: 628713
 * High Inputs: 21 | Low Inputs: 17
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001287_8713_0 {
    int prev_out;
    int damping;
    int prev_in;
    int gain_db;
    int buffer[3];
};

struct Vector3D_R001287_8713_1 {
    int norm_sq;
    int coord_y;
    int coord_x;
    int heading;
    unsigned char coord_z;
    int pitch;
    int buffer[3];
};

union ColorPixel_R001287_8713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001287_8713_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001287_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int segment_71 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_71 > 41) {
        acc = (acc + segment_71 * 2 + 5) & 127;
        aux ^= (segment_71 & 15);
    } else {
        acc = (acc - segment_71 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_12 = local_arr[aux % 3];
    acc = (acc + anchor_12 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001287_8713_1(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_22 = local_arr[aux % 3];
    acc = (acc + margin_22 * 2) & 127;
    int parity_12 = (aux + st.buffer[1]) & 3;
    switch (parity_12) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_99 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_99 > 45) {
        acc = (acc + residue_99 * 2 + 5) & 127;
        aux ^= (residue_99 & 15);
    } else {
        acc = (acc - residue_99 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_2(int p0, int p1, int p2) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int mask_75 = 0;
    for (int k = 0; k < 2; k++) {
        mask_75 = (mask_75 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_75) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001287_8713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_82 = (aux + st.buffer[1]) & 3;
    switch (damping_82) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_44 = 0;
    for (int k = 0; k < 2; k++) {
        metric_44 = (metric_44 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_44) & 127;
    }
    int pivot_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001287_8713_5(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001287_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int anchor_35 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_35 = (anchor_35 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_35) & 127;
    }
    int coefficient_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_35) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int sample_96 = local_arr[aux % 3];
    acc = (acc + sample_96 * 2) & 127;
    int weight_50 = (aux + st.buffer[1]) & 3;
    switch (weight_50) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_6(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int residue_11 = local_arr[aux % 3];
    acc = (acc + residue_11 * 2) & 127;
    int cursor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_54 > 38) {
        acc = (acc + cursor_54 * 2 + 5) & 127;
        aux ^= (cursor_54 & 15);
    } else {
        acc = (acc - cursor_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_7(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001287_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int pivot_67 = (aux + st.buffer[1]) & 3;
    switch (pivot_67) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001287_8713_8(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int bound_83 = local_arr[aux % 3];
    acc = (acc + bound_83 * 2) & 127;
    int scale_87 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_87 > 23) {
        acc = (acc + scale_87 * 2 + 5) & 127;
        aux ^= (scale_87 & 15);
    } else {
        acc = (acc - scale_87 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int factor_41 = 0;
    for (int k = 0; k < 2; k++) {
        factor_41 = (factor_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_41) & 127;
    }
    int vector_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_92) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001287_8713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001287_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_81 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_81) & 63;
    acc ^= aux;
    int threshold_62 = (aux + st.buffer[1]) & 3;
    switch (threshold_62) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_37 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_37 > 40) {
        acc = (acc + threshold_37 * 2 + 5) & 127;
        aux ^= (threshold_37 & 15);
    } else {
        acc = (acc - threshold_37 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_11(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_63 = (aux + st.buffer[1]) & 3;
    switch (sample_63) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int damping_42 = local_arr[aux % 3];
    acc = (acc + damping_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001287_8713_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_68 > 49) {
        acc = (acc + anchor_68 * 2 + 5) & 127;
        aux ^= (anchor_68 & 15);
    } else {
        acc = (acc - anchor_68 + 11) & 127;
        aux += 3;
    }
    int bound_53 = (aux + st.buffer[1]) & 3;
    switch (bound_53) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_68 = local_arr[aux % 3];
    acc = (acc + margin_68 * 2) & 127;
    int factor_45 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_45) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001287_8713_13(int p0, int p1, int p2) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_62 = local_arr[aux % 3];
    acc = (acc + parity_62 * 2) & 127;
    int index_reg_63 = 0;
    for (int k = 0; k < 2; k++) {
        index_reg_63 = (index_reg_63 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + index_reg_63) & 127;
    }
    int damping_84 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_84 > 23) {
        acc = (acc + damping_84 * 2 + 5) & 127;
        aux ^= (damping_84 & 15);
    } else {
        acc = (acc - damping_84 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int tally_33 = 0;
    for (int k = 0; k < 2; k++) {
        tally_33 = (tally_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_33) & 127;
    }
    int coefficient_19 = (aux + st.buffer[1]) & 3;
    switch (coefficient_19) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_14) & 63;
    acc ^= aux;
    int metric_66 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_66 > 16) {
        acc = (acc + metric_66 * 2 + 5) & 127;
        aux ^= (metric_66 & 15);
    } else {
        acc = (acc - metric_66 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_15(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001287_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int vector_61 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_61 > 15) {
        acc = (acc + vector_61 * 2 + 5) & 127;
        aux ^= (vector_61 & 15);
    } else {
        acc = (acc - vector_61 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_31 = local_arr[aux % 3];
    acc = (acc + bound_31 * 2) & 127;
    int sample_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_13) & 63;
    acc ^= aux;
    int anchor_97 = (aux + st.buffer[1]) & 3;
    switch (anchor_97) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_16(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001287_8713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_37 = local_arr[aux % 3];
    acc = (acc + weight_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001287_8713_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int pivot_22 = local_arr[aux % 3];
    acc = (acc + pivot_22 * 2) & 127;
    int parity_94 = (aux + st.buffer[1]) & 3;
    switch (parity_94) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_85 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_85 = (accumulator_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_85) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001287_8713_18(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001287_8713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int tracker_44 = (aux + st.buffer[1]) & 3;
    switch (tracker_44) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_33) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001287_0;
    int sec_r001287_1;
    int sec_r001287_2;
    int sec_r001287_3;
    int sec_r001287_4;
    int sec_r001287_5;
    int sec_r001287_6;
    int sec_r001287_7;
    int sec_r001287_8;
    int sec_r001287_9;
    int sec_r001287_10;
    int sec_r001287_11;
    int sec_r001287_12;
    int sec_r001287_13;
    int sec_r001287_14;
    int sec_r001287_15;
    int sec_r001287_16;
    int sec_r001287_17;
    int sec_r001287_18;
    int sec_r001287_19;
    int sec_r001287_20;
    int pub_r001287_0;
    int pub_r001287_1;
    int pub_r001287_2;
    int pub_r001287_3;
    int pub_r001287_4;
    int pub_r001287_5;
    int pub_r001287_6;
    int pub_r001287_7;
    int pub_r001287_8;
    int pub_r001287_9;
    int pub_r001287_10;
    int pub_r001287_11;
    int pub_r001287_12;
    int pub_r001287_13;
    int pub_r001287_14;
    int pub_r001287_15;
    int pub_r001287_16;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001287_0 >= -100 && pub_r001287_0 <= 100);
    __CPROVER_assume(pub_r001287_1 >= -100 && pub_r001287_1 <= 100);
    __CPROVER_assume(pub_r001287_2 >= -100 && pub_r001287_2 <= 100);
    __CPROVER_assume(pub_r001287_3 >= -100 && pub_r001287_3 <= 100);
    __CPROVER_assume(pub_r001287_4 >= -100 && pub_r001287_4 <= 100);
    __CPROVER_assume(pub_r001287_5 >= -100 && pub_r001287_5 <= 100);
    __CPROVER_assume(pub_r001287_6 >= -100 && pub_r001287_6 <= 100);
    __CPROVER_assume(pub_r001287_7 >= -100 && pub_r001287_7 <= 100);
    __CPROVER_assume(pub_r001287_8 >= -100 && pub_r001287_8 <= 100);
    __CPROVER_assume(pub_r001287_9 >= -100 && pub_r001287_9 <= 100);
    __CPROVER_assume(pub_r001287_10 >= -100 && pub_r001287_10 <= 100);
    __CPROVER_assume(pub_r001287_11 >= -100 && pub_r001287_11 <= 100);
    __CPROVER_assume(pub_r001287_12 >= -100 && pub_r001287_12 <= 100);
    __CPROVER_assume(pub_r001287_13 >= -100 && pub_r001287_13 <= 100);
    __CPROVER_assume(pub_r001287_14 >= -100 && pub_r001287_14 <= 100);
    __CPROVER_assume(pub_r001287_15 >= -100 && pub_r001287_15 <= 100);
    __CPROVER_assume(pub_r001287_16 >= -100 && pub_r001287_16 <= 100);
    __CPROVER_assume(sec_r001287_0 >= 0 && sec_r001287_0 <= 255);
    __CPROVER_assume(sec_r001287_1 >= 0 && sec_r001287_1 <= 255);
    __CPROVER_assume(sec_r001287_2 >= 0 && sec_r001287_2 <= 255);
    __CPROVER_assume(sec_r001287_3 >= 0 && sec_r001287_3 <= 255);
    __CPROVER_assume(sec_r001287_4 >= 0 && sec_r001287_4 <= 255);
    __CPROVER_assume(sec_r001287_5 >= 0 && sec_r001287_5 <= 255);
    __CPROVER_assume(sec_r001287_6 >= 0 && sec_r001287_6 <= 255);
    __CPROVER_assume(sec_r001287_7 >= 0 && sec_r001287_7 <= 255);
    __CPROVER_assume(sec_r001287_8 >= 0 && sec_r001287_8 <= 255);
    __CPROVER_assume(sec_r001287_9 >= 0 && sec_r001287_9 <= 255);
    __CPROVER_assume(sec_r001287_10 >= 0 && sec_r001287_10 <= 255);
    __CPROVER_assume(sec_r001287_11 >= 0 && sec_r001287_11 <= 255);
    __CPROVER_assume(sec_r001287_12 >= 0 && sec_r001287_12 <= 255);
    __CPROVER_assume(sec_r001287_13 >= 0 && sec_r001287_13 <= 255);
    __CPROVER_assume(sec_r001287_14 >= 0 && sec_r001287_14 <= 255);
    __CPROVER_assume(sec_r001287_15 >= 0 && sec_r001287_15 <= 255);
    __CPROVER_assume(sec_r001287_16 >= 0 && sec_r001287_16 <= 255);
    __CPROVER_assume(sec_r001287_17 >= 0 && sec_r001287_17 <= 255);
    __CPROVER_assume(sec_r001287_18 >= 0 && sec_r001287_18 <= 255);
    __CPROVER_assume(sec_r001287_19 >= 0 && sec_r001287_19 <= 255);
    __CPROVER_assume(sec_r001287_20 >= 0 && sec_r001287_20 <= 255);

    struct FilterState_R001287_8713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001287_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001287_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001287_0 + 7) & 15;
    struct Vector3D_R001287_8713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001287_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001287_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001287_0 + 9) & 15;

    union ColorPixel_R001287_8713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001287_8713_0(sec_r001287_0, sec_r001287_1, pub_r001287_2, pub_r001287_3, pub_r001287_4);
    int helper_flow_1 = fn_R001287_8713_1(sec_r001287_1, sec_r001287_2);
    int helper_flow_2 = fn_R001287_8713_2(sec_r001287_2, pub_r001287_3, pub_r001287_4);
    int helper_flow_3 = fn_R001287_8713_3(sec_r001287_3, pub_r001287_4, pub_r001287_5, pub_r001287_6);
    int helper_flow_4 = fn_R001287_8713_4(sec_r001287_4, sec_r001287_5, pub_r001287_6, pub_r001287_7);
    int helper_flow_5 = fn_R001287_8713_5(sec_r001287_5, sec_r001287_6, pub_r001287_7);
    int helper_flow_6 = fn_R001287_8713_6(sec_r001287_6, sec_r001287_7, pub_r001287_8);
    int helper_flow_7 = fn_R001287_8713_7(sec_r001287_7, pub_r001287_8, pub_r001287_9);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001287_2 ^ pub_r001287_2) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001287_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (helper_flow_3 ^ pub_r001287_5) & 63;
    if ((stage_v_1 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_1 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_1 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_1 * 2) & 255;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001287_3 ^ pub_r001287_6) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001287_4 ^ pub_r001287_2) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001287_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_0 ^ pub_r001287_9) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001287_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_2 ^ pub_r001287_7) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((sec_r001287_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001287_16 ^ pub_r001287_2) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001287_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (sec_r001287_0 ^ pub_r001287_0) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001287_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001287_2 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001287_1 ^ pub_r001287_0) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001287_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001287_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001287_0 ^ pub_r001287_16) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_6 ^ pub_r001287_10) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001287_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001287_13 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001287_7 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001287_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (stage_v_3 ^ pub_r001287_11) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001287_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001287_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_3 ^ pub_r001287_11) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001287_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (helper_flow_3 ^ pub_r001287_10) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_6 ^ pub_r001287_5) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001287_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001287_11 ^ pub_r001287_9) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (pub_r001287_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_23) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (helper_flow_7 ^ pub_r001287_8) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001287_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001287_6 ^ pub_r001287_14) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (stage_v_21 ^ pub_r001287_3) & 63;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r001287_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_26 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_26 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_26 * 2) & 255;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001287_18 ^ pub_r001287_3) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001287_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001287_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001287_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001287_1 ^ pub_r001287_12) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_4 ^ pub_r001287_11) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (sec_r001287_18 ^ pub_r001287_11) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001287_5 ^ pub_r001287_4) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_3 ^ pub_r001287_0) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r001287_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (pub_r001287_15 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_35) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (stage_v_2 ^ pub_r001287_8) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_34 ^ pub_r001287_14) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r001287_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001287_2 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_24 ^ pub_r001287_14) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (sec_r001287_5 ^ pub_r001287_11) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001287_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (stage_v_26 ^ pub_r001287_13) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001287_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001287_17 ^ pub_r001287_1) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001287_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001287_7 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (helper_flow_1 ^ pub_r001287_7) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r001287_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_32 ^ pub_r001287_3) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001287_14 ^ pub_r001287_8) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001287_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (helper_flow_0 ^ pub_r001287_8) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_4 ^ pub_r001287_9) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_48 ^ pub_r001287_14) & 63;
    if ((stage_v_51 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_51 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_51 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_51 * 2) & 255;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (stage_v_17 ^ pub_r001287_11) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001287_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001287_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_22 ^ pub_r001287_15) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001287_7 ^ pub_r001287_1) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001287_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001287_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (sec_r001287_3 ^ pub_r001287_2) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (helper_flow_7 ^ pub_r001287_6) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001287_4 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_17 ^ pub_r001287_10) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001287_16 ^ pub_r001287_2) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (stage_v_25 ^ pub_r001287_3) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r001287_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001287_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001287_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001287_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001287_0 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001287_10 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001287_5 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_39 ^ pub_r001287_6) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001287_7 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_44 ^ pub_r001287_14) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_54 ^ pub_r001287_8) & 63;
    if ((stage_v_72 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_72 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_72 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_72 * 2) & 255;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_3 ^ pub_r001287_11) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001287_0 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_24 ^ pub_r001287_16) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r001287_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (sec_r001287_15 ^ pub_r001287_15) & 63;
    if ((stage_v_76 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_76 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_76 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_76 * 2) & 255;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (helper_flow_7 ^ pub_r001287_16) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_72 ^ pub_r001287_10) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001287_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001287_11 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001287_8 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001287_8 ^ pub_r001287_8) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (pub_r001287_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_82) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (sec_r001287_9 ^ pub_r001287_9) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_26 ^ pub_r001287_14) & 63;
    if ((stage_v_84 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_84 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_84 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (sec_r001287_17 ^ pub_r001287_7) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (sec_r001287_20 ^ pub_r001287_8) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_6 ^ pub_r001287_11) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (stage_v_69 ^ pub_r001287_4) & 63;
    if ((stage_v_88 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_88 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_88 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (pub_r001287_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_89) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_3 ^ pub_r001287_13) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_51 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001287_7 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001287_16 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (helper_flow_6 ^ pub_r001287_1) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_83 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (helper_flow_5 ^ pub_r001287_7) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_31 ^ pub_r001287_7) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_90 ^ pub_r001287_10) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (stage_v_90 ^ pub_r001287_15) & 63;
    if ((stage_v_97 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_97 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_97 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_21 ^ pub_r001287_11) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001287_13 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (helper_flow_2 ^ pub_r001287_13) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((sec_r001287_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_4 ^ pub_r001287_10) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r001287_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001287_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001287_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (sec_r001287_2 ^ pub_r001287_15) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_97 ^ pub_r001287_11) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_24 ^ pub_r001287_0) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r001287_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (stage_v_78 ^ pub_r001287_15) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((stage_v_42 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001287_3 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001287_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001287_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_50 ^ pub_r001287_4) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (stage_v_100 ^ pub_r001287_14) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_97 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001287_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (sec_r001287_5 ^ pub_r001287_2) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r001287_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001287_3 ^ pub_r001287_16) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001287_5 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001287_2 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001287_2 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (sec_r001287_16 ^ pub_r001287_5) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (helper_flow_2 ^ pub_r001287_12) & 63;
    if ((stage_v_120 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_120 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_120 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001287_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (stage_v_71 ^ pub_r001287_3) & 63;
    if ((stage_v_122 & 1) != 0) {
        if ((stage_v_47 & 2) != 0) {
            out_sink = (out_sink + stage_v_122 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_122 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_27 ^ pub_r001287_15) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_32 ^ pub_r001287_16) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (helper_flow_2 ^ pub_r001287_3) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_26 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_95 ^ pub_r001287_4) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001287_4 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_24 ^ pub_r001287_5) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (stage_v_40 ^ pub_r001287_8) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001287_1 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001287_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_88 ^ pub_r001287_4) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r001287_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_98 ^ pub_r001287_8) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_49 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001287_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001287_7 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_22 ^ pub_r001287_11) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_0 ^ pub_r001287_14) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (sec_r001287_18 ^ pub_r001287_3) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (sec_r001287_18 ^ pub_r001287_12) & 63;
    if ((stage_v_139 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_139 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_139 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (sec_r001287_15 ^ pub_r001287_9) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (helper_flow_4 ^ pub_r001287_13) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_77 ^ pub_r001287_6) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (stage_v_22 ^ pub_r001287_8) & 63;
    if ((stage_v_143 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_143 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_143 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (sec_r001287_1 ^ pub_r001287_11) & 63;
    if ((stage_v_144 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_144 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_144 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_124 ^ pub_r001287_3) & 63;
    if ((stage_v_145 & 1) != 0) {
        if ((sec_r001287_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_145 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_145 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (sec_r001287_19 ^ pub_r001287_5) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_76 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_2 ^ pub_r001287_6) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_126 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001287_10 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (pub_r001287_8 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_149) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_76 ^ pub_r001287_2) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_12 ^ pub_r001287_11) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_32 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_0 ^ pub_r001287_8) & 63;
    if ((stage_v_152 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_152 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_152 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (stage_v_9 ^ pub_r001287_0) & 63;
    if ((stage_v_153 & 1) != 0) {
        if ((sec_r001287_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_153 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_153 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_19 ^ pub_r001287_16) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_78 ^ pub_r001287_13) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (pub_r001287_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_156) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_40 ^ pub_r001287_13) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001287_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (helper_flow_7 ^ pub_r001287_9) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (stage_v_101 ^ pub_r001287_3) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_86 ^ pub_r001287_10) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (stage_v_143 ^ pub_r001287_14) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_161 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001287_11 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (stage_v_61 ^ pub_r001287_11) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_26 ^ pub_r001287_11) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_85 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (stage_v_69 ^ pub_r001287_6) & 63;
    if ((stage_v_166 & 1) != 0) {
        if ((stage_v_52 & 2) != 0) {
            out_sink = (out_sink + stage_v_166 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_166 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_25 ^ pub_r001287_4) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001287_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_151 ^ pub_r001287_13) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_94 ^ pub_r001287_6) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (helper_flow_4 ^ pub_r001287_11) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((sec_r001287_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (helper_flow_3 ^ pub_r001287_12) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_72 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (stage_v_95 ^ pub_r001287_8) & 63;
    if ((stage_v_173 & 1) != 0) {
        if ((sec_r001287_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_173 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_173 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (sec_r001287_6 ^ pub_r001287_16) & 63;
    if ((stage_v_174 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_174 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_174 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_140 ^ pub_r001287_0) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001287_12 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
