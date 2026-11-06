/*
 * Benchmark Program: R000513
 * Security Family: multi_step_explicit
 * Generator Seed: 551313
 * High Inputs: 18 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000513_1313_0 {
    short prev_out;
    short cutoff;
    int prev_in;
    unsigned char gain_db;
    int mode;
    int buffer[3];
};

struct SensorNode_R000513_1313_1 {
    unsigned char gain;
    unsigned char calib;
    unsigned char reading;
    int buffer[3];
};

struct Vector3D_R000513_1313_2 {
    unsigned char coord_z;
    short heading;
    int norm_sq;
    unsigned char coord_y;
    int coord_x;
    int buffer[3];
};

union TelemetryField_R000513_1313_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000513_1313_0(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000513_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int window_57 = local_arr[aux % 3];
    acc = (acc + window_57 * 2) & 127;
    int tracker_46 = (aux + st.buffer[1]) & 3;
    switch (tracker_46) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_72) & 63;
    acc ^= aux;
    int delta_83 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_83 > 36) {
        acc = (acc + delta_83 * 2 + 5) & 127;
        aux ^= (delta_83 & 15);
    } else {
        acc = (acc - delta_83 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000513_1313_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000513_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int residue_68 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_68 > 32) {
        acc = (acc + residue_68 * 2 + 5) & 127;
        aux ^= (residue_68 & 15);
    } else {
        acc = (acc - residue_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int segment_17 = local_arr[aux % 3];
    acc = (acc + segment_17 * 2) & 127;
    int segment_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000513_1313_2(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000513_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int coefficient_60 = local_arr[aux % 3];
    acc = (acc + coefficient_60 * 2) & 127;
    int quantum_63 = (aux + st.buffer[1]) & 3;
    switch (quantum_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_68 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_68 > 22) {
        acc = (acc + mask_68 * 2 + 5) & 127;
        aux ^= (mask_68 & 15);
    } else {
        acc = (acc - mask_68 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000513_1313_3(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000513_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int threshold_70 = local_arr[aux % 3];
    acc = (acc + threshold_70 * 2) & 127;
    int threshold_77 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_77 > 27) {
        acc = (acc + threshold_77 * 2 + 5) & 127;
        aux ^= (threshold_77 & 15);
    } else {
        acc = (acc - threshold_77 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000513_1313_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000513_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_74 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_74 > 46) {
        acc = (acc + mask_74 * 2 + 5) & 127;
        aux ^= (mask_74 & 15);
    } else {
        acc = (acc - mask_74 + 11) & 127;
        aux += 3;
    }
    int quotient_73 = (aux + st.buffer[1]) & 3;
    switch (quotient_73) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_46 = local_arr[aux % 3];
    acc = (acc + checksum_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000513_1313_5(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000513_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int pivot_83 = local_arr[aux % 3];
    acc = (acc + pivot_83 * 2) & 127;
    int factor_74 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_74 > 35) {
        acc = (acc + factor_74 * 2 + 5) & 127;
        aux ^= (factor_74 & 15);
    } else {
        acc = (acc - factor_74 + 11) & 127;
        aux += 3;
    }
    int bound_63 = (aux + st.buffer[1]) & 3;
    switch (bound_63) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000513_1313_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000513_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int margin_94 = (aux + st.buffer[1]) & 3;
    switch (margin_94) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_20 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_20 > 44) {
        acc = (acc + threshold_20 * 2 + 5) & 127;
        aux ^= (threshold_20 & 15);
    } else {
        acc = (acc - threshold_20 + 11) & 127;
        aux += 3;
    }
    int metric_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_17) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int bound_78 = local_arr[aux % 3];
    acc = (acc + bound_78 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000513_1313_7(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000513_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int tally_38 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_38 > 37) {
        acc = (acc + tally_38 * 2 + 5) & 127;
        aux ^= (tally_38 & 15);
    } else {
        acc = (acc - tally_38 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_42 = local_arr[aux % 3];
    acc = (acc + margin_42 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000513_1313_8(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000513_1313_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int bound_39 = local_arr[aux % 3];
    acc = (acc + bound_39 * 2) & 127;
    int segment_53 = (aux + st.buffer[1]) & 3;
    switch (segment_53) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000513_1313_9(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000513_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int factor_50 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_50 > 38) {
        acc = (acc + factor_50 * 2 + 5) & 127;
        aux ^= (factor_50 & 15);
    } else {
        acc = (acc - factor_50 + 11) & 127;
        aux += 3;
    }
    int vector_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_46) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000513_1313_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000513_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int bound_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_97) & 63;
    acc ^= aux;
    int accumulator_83 = (aux + st.buffer[1]) & 3;
    switch (accumulator_83) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_85 = local_arr[aux % 3];
    acc = (acc + pivot_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000513_1313_11(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000513_1313_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int coefficient_20 = local_arr[aux % 3];
    acc = (acc + coefficient_20 * 2) & 127;
    int residue_84 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_84 > 24) {
        acc = (acc + residue_84 * 2 + 5) & 127;
        aux ^= (residue_84 & 15);
    } else {
        acc = (acc - residue_84 + 11) & 127;
        aux += 3;
    }
    int metric_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_20) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000513_1313_12(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000513_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int pivot_33 = (aux + st.buffer[1]) & 3;
    switch (pivot_33) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_41 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_41 > 30) {
        acc = (acc + stride_41 * 2 + 5) & 127;
        aux ^= (stride_41 & 15);
    } else {
        acc = (acc - stride_41 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000513_1313_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000513_1313_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_60) & 63;
    acc ^= aux;
    int stride_91 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_91 > 46) {
        acc = (acc + stride_91 * 2 + 5) & 127;
        aux ^= (stride_91 & 15);
    } else {
        acc = (acc - stride_91 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000513_0;
    int sec_r000513_1;
    int sec_r000513_2;
    int sec_r000513_3;
    int sec_r000513_4;
    int sec_r000513_5;
    int sec_r000513_6;
    int sec_r000513_7;
    int sec_r000513_8;
    int sec_r000513_9;
    int sec_r000513_10;
    int sec_r000513_11;
    int sec_r000513_12;
    int sec_r000513_13;
    int sec_r000513_14;
    int sec_r000513_15;
    int sec_r000513_16;
    int sec_r000513_17;
    int pub_r000513_0;
    int pub_r000513_1;
    int pub_r000513_2;
    int pub_r000513_3;
    int pub_r000513_4;
    int pub_r000513_5;
    int pub_r000513_6;
    int pub_r000513_7;
    int pub_r000513_8;
    int pub_r000513_9;
    int pub_r000513_10;
    int pub_r000513_11;
    int pub_r000513_12;
    int pub_r000513_13;
    int pub_r000513_14;
    int pub_r000513_15;
    int pub_r000513_16;
    int pub_r000513_17;
    int pub_r000513_18;
    int pub_r000513_19;
    int pub_r000513_20;
    int pub_r000513_21;
    int pub_r000513_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000513_0 >= -100 && pub_r000513_0 <= 100);
    __CPROVER_assume(pub_r000513_1 >= -100 && pub_r000513_1 <= 100);
    __CPROVER_assume(pub_r000513_2 >= -100 && pub_r000513_2 <= 100);
    __CPROVER_assume(pub_r000513_3 >= -100 && pub_r000513_3 <= 100);
    __CPROVER_assume(pub_r000513_4 >= -100 && pub_r000513_4 <= 100);
    __CPROVER_assume(pub_r000513_5 >= -100 && pub_r000513_5 <= 100);
    __CPROVER_assume(pub_r000513_6 >= -100 && pub_r000513_6 <= 100);
    __CPROVER_assume(pub_r000513_7 >= -100 && pub_r000513_7 <= 100);
    __CPROVER_assume(pub_r000513_8 >= -100 && pub_r000513_8 <= 100);
    __CPROVER_assume(pub_r000513_9 >= -100 && pub_r000513_9 <= 100);
    __CPROVER_assume(pub_r000513_10 >= -100 && pub_r000513_10 <= 100);
    __CPROVER_assume(pub_r000513_11 >= -100 && pub_r000513_11 <= 100);
    __CPROVER_assume(pub_r000513_12 >= -100 && pub_r000513_12 <= 100);
    __CPROVER_assume(pub_r000513_13 >= -100 && pub_r000513_13 <= 100);
    __CPROVER_assume(pub_r000513_14 >= -100 && pub_r000513_14 <= 100);
    __CPROVER_assume(pub_r000513_15 >= -100 && pub_r000513_15 <= 100);
    __CPROVER_assume(pub_r000513_16 >= -100 && pub_r000513_16 <= 100);
    __CPROVER_assume(pub_r000513_17 >= -100 && pub_r000513_17 <= 100);
    __CPROVER_assume(pub_r000513_18 >= -100 && pub_r000513_18 <= 100);
    __CPROVER_assume(pub_r000513_19 >= -100 && pub_r000513_19 <= 100);
    __CPROVER_assume(pub_r000513_20 >= -100 && pub_r000513_20 <= 100);
    __CPROVER_assume(pub_r000513_21 >= -100 && pub_r000513_21 <= 100);
    __CPROVER_assume(pub_r000513_22 >= -100 && pub_r000513_22 <= 100);
    __CPROVER_assume(sec_r000513_0 >= 0 && sec_r000513_0 <= 255);
    __CPROVER_assume(sec_r000513_1 >= 0 && sec_r000513_1 <= 255);
    __CPROVER_assume(sec_r000513_2 >= 0 && sec_r000513_2 <= 255);
    __CPROVER_assume(sec_r000513_3 >= 0 && sec_r000513_3 <= 255);
    __CPROVER_assume(sec_r000513_4 >= 0 && sec_r000513_4 <= 255);
    __CPROVER_assume(sec_r000513_5 >= 0 && sec_r000513_5 <= 255);
    __CPROVER_assume(sec_r000513_6 >= 0 && sec_r000513_6 <= 255);
    __CPROVER_assume(sec_r000513_7 >= 0 && sec_r000513_7 <= 255);
    __CPROVER_assume(sec_r000513_8 >= 0 && sec_r000513_8 <= 255);
    __CPROVER_assume(sec_r000513_9 >= 0 && sec_r000513_9 <= 255);
    __CPROVER_assume(sec_r000513_10 >= 0 && sec_r000513_10 <= 255);
    __CPROVER_assume(sec_r000513_11 >= 0 && sec_r000513_11 <= 255);
    __CPROVER_assume(sec_r000513_12 >= 0 && sec_r000513_12 <= 255);
    __CPROVER_assume(sec_r000513_13 >= 0 && sec_r000513_13 <= 255);
    __CPROVER_assume(sec_r000513_14 >= 0 && sec_r000513_14 <= 255);
    __CPROVER_assume(sec_r000513_15 >= 0 && sec_r000513_15 <= 255);
    __CPROVER_assume(sec_r000513_16 >= 0 && sec_r000513_16 <= 255);
    __CPROVER_assume(sec_r000513_17 >= 0 && sec_r000513_17 <= 255);

    struct FilterState_R000513_1313_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000513_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000513_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000513_0 + 7) & 15;
    struct SensorNode_R000513_1313_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000513_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000513_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000513_0 + 9) & 15;
    struct Vector3D_R000513_1313_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000513_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000513_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000513_0 + 11) & 15;

    union TelemetryField_R000513_1313_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 26) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 41) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 34) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 49) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (out_sink > 100) ? (chk_sum & 31) : (12 & 31);
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= (stage_v_7 << 1) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_2.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 27) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 42) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 17) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 32) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_1.buffer[1] * 2 + 55) & 63;
    if (stage_v_16 > 32) {
        out_sink = (out_sink + stage_v_16 - 5) & 255;
        if (stage_v_16 > 47) {
            chk_sum ^= (stage_v_16 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_16 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 32) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 47) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 20) & 15;
    int stage_v_19 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= stage_v_19;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 23) & 15;
    int stage_v_22 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= stage_v_22;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] ^ 27) & 3;
    switch (stage_v_24) {
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

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 27) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 42) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] ^ 39) & 3;
    switch (stage_v_36) {
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

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 21) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 36) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 13) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 28) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 38) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 53) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 26) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 41) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[1] * 2 + 154) & 63;
    if (stage_v_49 > 34) {
        out_sink = (out_sink + stage_v_49 - 5) & 255;
        if (stage_v_49 > 49) {
            chk_sum ^= (stage_v_49 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_49 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 10) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 25) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (st_var_2.buffer[2] * 2 + 166) & 63;
    if (stage_v_53 > 21) {
        out_sink = (out_sink + stage_v_53 - 5) & 255;
        if (stage_v_53 > 36) {
            chk_sum ^= (stage_v_53 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_53 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 10) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 25) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 16) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 31) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = table[0];
    table[0] = (table[1] + 121) & 63;
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_61 = (stage_v_61 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_61) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (out_sink > 100) ? (chk_sum & 31) : (70 & 31);
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= (stage_v_65 << 1) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 17) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 32) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_1.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 23) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 38) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 31) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 46) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (out_sink > 100) ? (chk_sum & 31) : (80 & 31);
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= (stage_v_75 << 1) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_77 = (stage_v_77 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_77) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_78 = (stage_v_78 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_78) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_79 = (stage_v_79 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_79) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_2.buffer[0] ^ 86) & 3;
    switch (stage_v_83) {
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

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    int sub_step_89 = (sec_r000513_7 + pub_r000513_8 + 10) & 127;
    int stage_v_89 = (sub_step_89 * 2 + pub_r000513_19) & 127;
    st_var_2.buffer[2] = (stage_v_89 & 15);
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int sub_step_90 = (sec_r000513_14 + pub_r000513_1 + 33) & 127;
    int stage_v_90 = (sub_step_90 * 2 + pub_r000513_21) & 127;
    st_var_0.buffer[0] = (stage_v_90 & 15);
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int sub_step_91 = (sec_r000513_1 + pub_r000513_9 + 26) & 127;
    int stage_v_91 = (sub_step_91 * 2 + pub_r000513_4) & 127;
    st_var_1.buffer[1] = (stage_v_91 & 15);
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int sub_step_92 = (stage_v_91 + pub_r000513_21 + 18) & 127;
    int stage_v_92 = (sub_step_92 * 2 + pub_r000513_21) & 127;
    st_var_2.buffer[2] = (stage_v_92 & 15);
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int sub_step_93 = (sec_r000513_1 + pub_r000513_14 + 15) & 127;
    int stage_v_93 = (sub_step_93 * 2 + pub_r000513_10) & 127;
    st_var_0.buffer[0] = (stage_v_93 & 15);
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int sub_step_94 = (sec_r000513_11 + pub_r000513_14 + 31) & 127;
    int stage_v_94 = (sub_step_94 * 2 + pub_r000513_20) & 127;
    st_var_1.buffer[1] = (stage_v_94 & 15);
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int sub_step_95 = (stage_v_91 + pub_r000513_14 + 12) & 127;
    int stage_v_95 = (sub_step_95 * 2 + pub_r000513_1) & 127;
    st_var_2.buffer[2] = (stage_v_95 & 15);
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int sub_step_96 = (sub_step_91 + pub_r000513_5 + 35) & 127;
    int stage_v_96 = (sub_step_96 * 2 + pub_r000513_22) & 127;
    st_var_0.buffer[0] = (stage_v_96 & 15);
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int sub_step_97 = (stage_v_93 + pub_r000513_10 + 19) & 127;
    int stage_v_97 = (sub_step_97 * 2 + pub_r000513_9) & 127;
    st_var_1.buffer[1] = (stage_v_97 & 15);
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int sub_step_98 = (sec_r000513_7 + pub_r000513_12 + 27) & 127;
    int stage_v_98 = (sub_step_98 * 2 + pub_r000513_1) & 127;
    st_var_2.buffer[2] = (stage_v_98 & 15);
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int sub_step_99 = (sec_r000513_8 + pub_r000513_2 + 24) & 127;
    int stage_v_99 = (sub_step_99 * 2 + pub_r000513_16) & 127;
    st_var_0.buffer[0] = (stage_v_99 & 15);
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int sub_step_100 = (stage_v_89 + pub_r000513_19 + 32) & 127;
    int stage_v_100 = (sub_step_100 * 2 + pub_r000513_19) & 127;
    st_var_1.buffer[1] = (stage_v_100 & 15);
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int sub_step_101 = (sub_step_100 + pub_r000513_14 + 9) & 127;
    int stage_v_101 = (sub_step_101 * 2 + pub_r000513_3) & 127;
    st_var_2.buffer[2] = (stage_v_101 & 15);
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int sub_step_102 = (stage_v_97 + pub_r000513_6 + 29) & 127;
    int stage_v_102 = (sub_step_102 * 2 + pub_r000513_14) & 127;
    st_var_0.buffer[0] = (stage_v_102 & 15);
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int sub_step_103 = (sec_r000513_8 + pub_r000513_14 + 33) & 127;
    int stage_v_103 = (sub_step_103 * 2 + pub_r000513_17) & 127;
    st_var_1.buffer[1] = (stage_v_103 & 15);
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int sub_step_104 = (stage_v_99 + pub_r000513_21 + 7) & 127;
    int stage_v_104 = (sub_step_104 * 2 + pub_r000513_9) & 127;
    st_var_2.buffer[2] = (stage_v_104 & 15);
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int sub_step_105 = (sec_r000513_14 + pub_r000513_12 + 8) & 127;
    int stage_v_105 = (sub_step_105 * 2 + pub_r000513_17) & 127;
    st_var_0.buffer[0] = (stage_v_105 & 15);
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int sub_step_106 = (sec_r000513_0 + pub_r000513_11 + 33) & 127;
    int stage_v_106 = (sub_step_106 * 2 + pub_r000513_11) & 127;
    st_var_1.buffer[1] = (stage_v_106 & 15);
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int sub_step_107 = (stage_v_104 + pub_r000513_12 + 9) & 127;
    int stage_v_107 = (sub_step_107 * 2 + pub_r000513_20) & 127;
    st_var_2.buffer[2] = (stage_v_107 & 15);
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int sub_step_108 = (stage_v_100 + pub_r000513_21 + 13) & 127;
    int stage_v_108 = (sub_step_108 * 2 + pub_r000513_22) & 127;
    st_var_0.buffer[0] = (stage_v_108 & 15);
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int sub_step_109 = (sub_step_91 + pub_r000513_8 + 29) & 127;
    int stage_v_109 = (sub_step_109 * 2 + pub_r000513_7) & 127;
    st_var_1.buffer[1] = (stage_v_109 & 15);
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int sub_step_110 = (stage_v_105 + pub_r000513_16 + 34) & 127;
    int stage_v_110 = (sub_step_110 * 2 + pub_r000513_20) & 127;
    st_var_2.buffer[2] = (stage_v_110 & 15);
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int sub_step_111 = (stage_v_94 + pub_r000513_0 + 25) & 127;
    int stage_v_111 = (sub_step_111 * 2 + pub_r000513_9) & 127;
    st_var_0.buffer[0] = (stage_v_111 & 15);
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int sub_step_112 = (stage_v_107 + pub_r000513_20 + 35) & 127;
    int stage_v_112 = (sub_step_112 * 2 + pub_r000513_1) & 127;
    st_var_1.buffer[1] = (stage_v_112 & 15);
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int sub_step_113 = (sec_r000513_16 + pub_r000513_0 + 33) & 127;
    int stage_v_113 = (sub_step_113 * 2 + pub_r000513_17) & 127;
    st_var_2.buffer[2] = (stage_v_113 & 15);
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int sub_step_114 = (stage_v_110 + pub_r000513_5 + 10) & 127;
    int stage_v_114 = (sub_step_114 * 2 + pub_r000513_8) & 127;
    st_var_0.buffer[0] = (stage_v_114 & 15);
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int sub_step_115 = (stage_v_109 + pub_r000513_22 + 11) & 127;
    int stage_v_115 = (sub_step_115 * 2 + pub_r000513_19) & 127;
    st_var_1.buffer[1] = (stage_v_115 & 15);
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int sub_step_116 = (stage_v_113 + pub_r000513_19 + 9) & 127;
    int stage_v_116 = (sub_step_116 * 2 + pub_r000513_11) & 127;
    st_var_2.buffer[2] = (stage_v_116 & 15);
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int sub_step_117 = (sub_step_110 + pub_r000513_5 + 11) & 127;
    int stage_v_117 = (sub_step_117 * 2 + pub_r000513_16) & 127;
    st_var_0.buffer[0] = (stage_v_117 & 15);
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int sub_step_118 = (sec_r000513_16 + pub_r000513_8 + 32) & 127;
    int stage_v_118 = (sub_step_118 * 2 + pub_r000513_7) & 127;
    st_var_1.buffer[1] = (stage_v_118 & 15);
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int sub_step_119 = (sub_step_118 + pub_r000513_1 + 30) & 127;
    int stage_v_119 = (sub_step_119 * 2 + pub_r000513_15) & 127;
    st_var_2.buffer[2] = (stage_v_119 & 15);
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int sub_step_120 = (sec_r000513_11 + pub_r000513_18 + 11) & 127;
    int stage_v_120 = (sub_step_120 * 2 + pub_r000513_3) & 127;
    st_var_0.buffer[0] = (stage_v_120 & 15);
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int sub_step_121 = (sec_r000513_1 + pub_r000513_6 + 15) & 127;
    int stage_v_121 = (sub_step_121 * 2 + pub_r000513_16) & 127;
    st_var_1.buffer[1] = (stage_v_121 & 15);
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int sub_step_122 = (sec_r000513_7 + pub_r000513_12 + 31) & 127;
    int stage_v_122 = (sub_step_122 * 2 + pub_r000513_20) & 127;
    st_var_2.buffer[2] = (stage_v_122 & 15);
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int sub_step_123 = (sub_step_97 + pub_r000513_20 + 6) & 127;
    int stage_v_123 = (sub_step_123 * 2 + pub_r000513_2) & 127;
    st_var_0.buffer[0] = (stage_v_123 & 15);
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int sub_step_124 = (sec_r000513_5 + pub_r000513_3 + 7) & 127;
    int stage_v_124 = (sub_step_124 * 2 + pub_r000513_16) & 127;
    st_var_1.buffer[1] = (stage_v_124 & 15);
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int sub_step_125 = (sub_step_111 + pub_r000513_3 + 13) & 127;
    int stage_v_125 = (sub_step_125 * 2 + pub_r000513_5) & 127;
    st_var_2.buffer[2] = (stage_v_125 & 15);
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int sub_step_126 = (stage_v_109 + pub_r000513_17 + 30) & 127;
    int stage_v_126 = (sub_step_126 * 2 + pub_r000513_5) & 127;
    st_var_0.buffer[0] = (stage_v_126 & 15);
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int sub_step_127 = (sec_r000513_7 + pub_r000513_18 + 31) & 127;
    int stage_v_127 = (sub_step_127 * 2 + pub_r000513_4) & 127;
    st_var_1.buffer[1] = (stage_v_127 & 15);
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int sub_step_128 = (stage_v_106 + pub_r000513_1 + 35) & 127;
    int stage_v_128 = (sub_step_128 * 2 + pub_r000513_12) & 127;
    st_var_2.buffer[2] = (stage_v_128 & 15);
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int sub_step_129 = (sec_r000513_5 + pub_r000513_9 + 22) & 127;
    int stage_v_129 = (sub_step_129 * 2 + pub_r000513_1) & 127;
    st_var_0.buffer[0] = (stage_v_129 & 15);
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int sub_step_130 = (stage_v_116 + pub_r000513_21 + 10) & 127;
    int stage_v_130 = (sub_step_130 * 2 + pub_r000513_9) & 127;
    st_var_1.buffer[1] = (stage_v_130 & 15);
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int sub_step_131 = (sub_step_127 + pub_r000513_0 + 34) & 127;
    int stage_v_131 = (sub_step_131 * 2 + pub_r000513_2) & 127;
    st_var_2.buffer[2] = (stage_v_131 & 15);
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int sub_step_132 = (sec_r000513_17 + pub_r000513_4 + 14) & 127;
    int stage_v_132 = (sub_step_132 * 2 + pub_r000513_21) & 127;
    st_var_0.buffer[0] = (stage_v_132 & 15);
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int sub_step_133 = (sec_r000513_5 + pub_r000513_19 + 32) & 127;
    int stage_v_133 = (sub_step_133 * 2 + pub_r000513_14) & 127;
    st_var_1.buffer[1] = (stage_v_133 & 15);
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int sub_step_134 = (sec_r000513_13 + pub_r000513_19 + 27) & 127;
    int stage_v_134 = (sub_step_134 * 2 + pub_r000513_20) & 127;
    st_var_2.buffer[2] = (stage_v_134 & 15);
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int sub_step_135 = (stage_v_125 + pub_r000513_18 + 26) & 127;
    int stage_v_135 = (sub_step_135 * 2 + pub_r000513_3) & 127;
    st_var_0.buffer[0] = (stage_v_135 & 15);
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int sub_step_136 = (sec_r000513_12 + pub_r000513_0 + 28) & 127;
    int stage_v_136 = (sub_step_136 * 2 + pub_r000513_7) & 127;
    st_var_1.buffer[1] = (stage_v_136 & 15);
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int sub_step_137 = (sec_r000513_16 + pub_r000513_8 + 20) & 127;
    int stage_v_137 = (sub_step_137 * 2 + pub_r000513_6) & 127;
    st_var_2.buffer[2] = (stage_v_137 & 15);
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int sub_step_138 = (sub_step_137 + pub_r000513_19 + 34) & 127;
    int stage_v_138 = (sub_step_138 * 2 + pub_r000513_17) & 127;
    st_var_0.buffer[0] = (stage_v_138 & 15);
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int sub_step_139 = (stage_v_130 + pub_r000513_15 + 13) & 127;
    int stage_v_139 = (sub_step_139 * 2 + pub_r000513_20) & 127;
    st_var_1.buffer[1] = (stage_v_139 & 15);
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int sub_step_140 = (stage_v_133 + pub_r000513_21 + 17) & 127;
    int stage_v_140 = (sub_step_140 * 2 + pub_r000513_12) & 127;
    st_var_2.buffer[2] = (stage_v_140 & 15);
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int sub_step_141 = (stage_v_93 + pub_r000513_21 + 9) & 127;
    int stage_v_141 = (sub_step_141 * 2 + pub_r000513_21) & 127;
    st_var_0.buffer[0] = (stage_v_141 & 15);
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int sub_step_142 = (sub_step_102 + pub_r000513_4 + 22) & 127;
    int stage_v_142 = (sub_step_142 * 2 + pub_r000513_14) & 127;
    st_var_1.buffer[1] = (stage_v_142 & 15);
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int sub_step_143 = (stage_v_103 + pub_r000513_10 + 27) & 127;
    int stage_v_143 = (sub_step_143 * 2 + pub_r000513_22) & 127;
    st_var_2.buffer[2] = (stage_v_143 & 15);
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int sub_step_144 = (sec_r000513_4 + pub_r000513_6 + 24) & 127;
    int stage_v_144 = (sub_step_144 * 2 + pub_r000513_15) & 127;
    st_var_0.buffer[0] = (stage_v_144 & 15);
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int sub_step_145 = (sec_r000513_16 + pub_r000513_17 + 12) & 127;
    int stage_v_145 = (sub_step_145 * 2 + pub_r000513_4) & 127;
    st_var_1.buffer[1] = (stage_v_145 & 15);
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int sub_step_146 = (sub_step_105 + pub_r000513_9 + 26) & 127;
    int stage_v_146 = (sub_step_146 * 2 + pub_r000513_20) & 127;
    st_var_2.buffer[2] = (stage_v_146 & 15);
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int sub_step_147 = (sub_step_114 + pub_r000513_14 + 8) & 127;
    int stage_v_147 = (sub_step_147 * 2 + pub_r000513_13) & 127;
    st_var_0.buffer[0] = (stage_v_147 & 15);
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int sub_step_148 = (sec_r000513_13 + pub_r000513_14 + 17) & 127;
    int stage_v_148 = (sub_step_148 * 2 + pub_r000513_17) & 127;
    st_var_1.buffer[1] = (stage_v_148 & 15);
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int sub_step_149 = (stage_v_125 + pub_r000513_11 + 6) & 127;
    int stage_v_149 = (sub_step_149 * 2 + pub_r000513_1) & 127;
    st_var_2.buffer[2] = (stage_v_149 & 15);
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int sub_step_150 = (stage_v_131 + pub_r000513_16 + 19) & 127;
    int stage_v_150 = (sub_step_150 * 2 + pub_r000513_13) & 127;
    st_var_0.buffer[0] = (stage_v_150 & 15);
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int sub_step_151 = (sec_r000513_3 + pub_r000513_4 + 24) & 127;
    int stage_v_151 = (sub_step_151 * 2 + pub_r000513_9) & 127;
    st_var_1.buffer[1] = (stage_v_151 & 15);
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int sub_step_152 = (sub_step_136 + pub_r000513_11 + 20) & 127;
    int stage_v_152 = (sub_step_152 * 2 + pub_r000513_3) & 127;
    st_var_2.buffer[2] = (stage_v_152 & 15);
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int sub_step_153 = (stage_v_102 + pub_r000513_13 + 10) & 127;
    int stage_v_153 = (sub_step_153 * 2 + pub_r000513_20) & 127;
    st_var_0.buffer[0] = (stage_v_153 & 15);
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int sub_step_154 = (stage_v_153 + pub_r000513_17 + 6) & 127;
    int stage_v_154 = (sub_step_154 * 2 + pub_r000513_10) & 127;
    st_var_1.buffer[1] = (stage_v_154 & 15);
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int sub_step_155 = (sub_step_111 + pub_r000513_11 + 23) & 127;
    int stage_v_155 = (sub_step_155 * 2 + pub_r000513_11) & 127;
    st_var_2.buffer[2] = (stage_v_155 & 15);
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int sub_step_156 = (sec_r000513_0 + pub_r000513_9 + 10) & 127;
    int stage_v_156 = (sub_step_156 * 2 + pub_r000513_0) & 127;
    st_var_0.buffer[0] = (stage_v_156 & 15);
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int sub_step_157 = (sec_r000513_8 + pub_r000513_6 + 25) & 127;
    int stage_v_157 = (sub_step_157 * 2 + pub_r000513_15) & 127;
    st_var_1.buffer[1] = (stage_v_157 & 15);
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int sub_step_158 = (stage_v_130 + pub_r000513_19 + 12) & 127;
    int stage_v_158 = (sub_step_158 * 2 + pub_r000513_8) & 127;
    st_var_2.buffer[2] = (stage_v_158 & 15);
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int sub_step_159 = (sub_step_117 + pub_r000513_7 + 29) & 127;
    int stage_v_159 = (sub_step_159 * 2 + pub_r000513_19) & 127;
    st_var_0.buffer[0] = (stage_v_159 & 15);
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int sub_step_160 = (stage_v_95 + pub_r000513_15 + 5) & 127;
    int stage_v_160 = (sub_step_160 * 2 + pub_r000513_2) & 127;
    st_var_1.buffer[1] = (stage_v_160 & 15);
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int sub_step_161 = (sub_step_142 + pub_r000513_1 + 28) & 127;
    int stage_v_161 = (sub_step_161 * 2 + pub_r000513_16) & 127;
    st_var_2.buffer[2] = (stage_v_161 & 15);
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int sub_step_162 = (sec_r000513_15 + pub_r000513_10 + 7) & 127;
    int stage_v_162 = (sub_step_162 * 2 + pub_r000513_2) & 127;
    st_var_0.buffer[0] = (stage_v_162 & 15);
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int sub_step_163 = (stage_v_103 + pub_r000513_18 + 30) & 127;
    int stage_v_163 = (sub_step_163 * 2 + pub_r000513_1) & 127;
    st_var_1.buffer[1] = (stage_v_163 & 15);
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int sub_step_164 = (stage_v_152 + pub_r000513_19 + 10) & 127;
    int stage_v_164 = (sub_step_164 * 2 + pub_r000513_19) & 127;
    st_var_2.buffer[2] = (stage_v_164 & 15);
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int sub_step_165 = (stage_v_120 + pub_r000513_2 + 7) & 127;
    int stage_v_165 = (sub_step_165 * 2 + pub_r000513_12) & 127;
    st_var_0.buffer[0] = (stage_v_165 & 15);
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int sub_step_166 = (sub_step_138 + pub_r000513_1 + 30) & 127;
    int stage_v_166 = (sub_step_166 * 2 + pub_r000513_21) & 127;
    st_var_1.buffer[1] = (stage_v_166 & 15);
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int sub_step_167 = (sub_step_146 + pub_r000513_14 + 30) & 127;
    int stage_v_167 = (sub_step_167 * 2 + pub_r000513_6) & 127;
    st_var_2.buffer[2] = (stage_v_167 & 15);
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int sub_step_168 = (sec_r000513_17 + pub_r000513_15 + 26) & 127;
    int stage_v_168 = (sub_step_168 * 2 + pub_r000513_17) & 127;
    st_var_0.buffer[0] = (stage_v_168 & 15);
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int sub_step_169 = (sub_step_98 + pub_r000513_1 + 17) & 127;
    int stage_v_169 = (sub_step_169 * 2 + pub_r000513_8) & 127;
    st_var_1.buffer[1] = (stage_v_169 & 15);
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int sub_step_170 = (sub_step_150 + pub_r000513_4 + 30) & 127;
    int stage_v_170 = (sub_step_170 * 2 + pub_r000513_4) & 127;
    st_var_2.buffer[2] = (stage_v_170 & 15);
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int sub_step_171 = (sub_step_139 + pub_r000513_5 + 28) & 127;
    int stage_v_171 = (sub_step_171 * 2 + pub_r000513_15) & 127;
    st_var_0.buffer[0] = (stage_v_171 & 15);
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int sub_step_172 = (sub_step_114 + pub_r000513_8 + 6) & 127;
    int stage_v_172 = (sub_step_172 * 2 + pub_r000513_4) & 127;
    st_var_1.buffer[1] = (stage_v_172 & 15);
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int sub_step_173 = (sub_step_143 + pub_r000513_22 + 32) & 127;
    int stage_v_173 = (sub_step_173 * 2 + pub_r000513_21) & 127;
    st_var_2.buffer[2] = (stage_v_173 & 15);
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int sub_step_174 = (stage_v_115 + pub_r000513_7 + 10) & 127;
    int stage_v_174 = (sub_step_174 * 2 + pub_r000513_7) & 127;
    st_var_0.buffer[0] = (stage_v_174 & 15);
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int sub_step_175 = (sec_r000513_2 + pub_r000513_11 + 24) & 127;
    int stage_v_175 = (sub_step_175 * 2 + pub_r000513_5) & 127;
    st_var_1.buffer[1] = (stage_v_175 & 15);
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int sub_step_176 = (sub_step_164 + pub_r000513_16 + 16) & 127;
    int stage_v_176 = (sub_step_176 * 2 + pub_r000513_18) & 127;
    st_var_2.buffer[2] = (stage_v_176 & 15);
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int sub_step_177 = (sub_step_123 + pub_r000513_0 + 11) & 127;
    int stage_v_177 = (sub_step_177 * 2 + pub_r000513_11) & 127;
    st_var_0.buffer[0] = (stage_v_177 & 15);
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int sub_step_178 = (sec_r000513_4 + pub_r000513_19 + 7) & 127;
    int stage_v_178 = (sub_step_178 * 2 + pub_r000513_21) & 127;
    st_var_1.buffer[1] = (stage_v_178 & 15);
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int sub_step_179 = (sub_step_121 + pub_r000513_18 + 20) & 127;
    int stage_v_179 = (sub_step_179 * 2 + pub_r000513_12) & 127;
    st_var_2.buffer[2] = (stage_v_179 & 15);
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int sub_step_180 = (sub_step_95 + pub_r000513_11 + 10) & 127;
    int stage_v_180 = (sub_step_180 * 2 + pub_r000513_18) & 127;
    st_var_0.buffer[0] = (stage_v_180 & 15);
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int sub_step_181 = (sec_r000513_11 + pub_r000513_13 + 34) & 127;
    int stage_v_181 = (sub_step_181 * 2 + pub_r000513_4) & 127;
    st_var_1.buffer[1] = (stage_v_181 & 15);
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int sub_step_182 = (sub_step_100 + pub_r000513_17 + 20) & 127;
    int stage_v_182 = (sub_step_182 * 2 + pub_r000513_7) & 127;
    st_var_2.buffer[2] = (stage_v_182 & 15);
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int sub_step_183 = (sec_r000513_4 + pub_r000513_19 + 32) & 127;
    int stage_v_183 = (sub_step_183 * 2 + pub_r000513_3) & 127;
    st_var_0.buffer[0] = (stage_v_183 & 15);
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int sub_step_184 = (sub_step_98 + pub_r000513_17 + 6) & 127;
    int stage_v_184 = (sub_step_184 * 2 + pub_r000513_19) & 127;
    st_var_1.buffer[1] = (stage_v_184 & 15);
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int sub_step_185 = (stage_v_141 + pub_r000513_6 + 21) & 127;
    int stage_v_185 = (sub_step_185 * 2 + pub_r000513_18) & 127;
    st_var_2.buffer[2] = (stage_v_185 & 15);
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int sub_step_186 = (sub_step_161 + pub_r000513_19 + 21) & 127;
    int stage_v_186 = (sub_step_186 * 2 + pub_r000513_0) & 127;
    st_var_0.buffer[0] = (stage_v_186 & 15);
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int sub_step_187 = (sec_r000513_0 + pub_r000513_4 + 28) & 127;
    int stage_v_187 = (sub_step_187 * 2 + pub_r000513_0) & 127;
    st_var_1.buffer[1] = (stage_v_187 & 15);
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int sub_step_188 = (sub_step_156 + pub_r000513_18 + 11) & 127;
    int stage_v_188 = (sub_step_188 * 2 + pub_r000513_7) & 127;
    st_var_2.buffer[2] = (stage_v_188 & 15);
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int sub_step_189 = (sub_step_138 + pub_r000513_8 + 11) & 127;
    int stage_v_189 = (sub_step_189 * 2 + pub_r000513_5) & 127;
    st_var_0.buffer[0] = (stage_v_189 & 15);
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int sub_step_190 = (sec_r000513_11 + pub_r000513_22 + 5) & 127;
    int stage_v_190 = (sub_step_190 * 2 + pub_r000513_2) & 127;
    st_var_1.buffer[1] = (stage_v_190 & 15);
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int sub_step_191 = (stage_v_127 + pub_r000513_14 + 17) & 127;
    int stage_v_191 = (sub_step_191 * 2 + pub_r000513_10) & 127;
    st_var_2.buffer[2] = (stage_v_191 & 15);
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int sub_step_192 = (sub_step_145 + pub_r000513_18 + 32) & 127;
    int stage_v_192 = (sub_step_192 * 2 + pub_r000513_9) & 127;
    st_var_0.buffer[0] = (stage_v_192 & 15);
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int sub_step_193 = (sub_step_107 + pub_r000513_15 + 15) & 127;
    int stage_v_193 = (sub_step_193 * 2 + pub_r000513_1) & 127;
    st_var_1.buffer[1] = (stage_v_193 & 15);
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int sub_step_194 = (stage_v_98 + pub_r000513_12 + 31) & 127;
    int stage_v_194 = (sub_step_194 * 2 + pub_r000513_2) & 127;
    st_var_2.buffer[2] = (stage_v_194 & 15);
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int sub_step_195 = (sub_step_90 + pub_r000513_2 + 30) & 127;
    int stage_v_195 = (sub_step_195 * 2 + pub_r000513_2) & 127;
    st_var_0.buffer[0] = (stage_v_195 & 15);
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int sub_step_196 = (stage_v_193 + pub_r000513_10 + 19) & 127;
    int stage_v_196 = (sub_step_196 * 2 + pub_r000513_7) & 127;
    st_var_1.buffer[1] = (stage_v_196 & 15);
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int sub_step_197 = (stage_v_109 + pub_r000513_22 + 28) & 127;
    int stage_v_197 = (sub_step_197 * 2 + pub_r000513_16) & 127;
    st_var_2.buffer[2] = (stage_v_197 & 15);
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int sub_step_198 = (stage_v_138 + pub_r000513_1 + 10) & 127;
    int stage_v_198 = (sub_step_198 * 2 + pub_r000513_16) & 127;
    st_var_0.buffer[0] = (stage_v_198 & 15);
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int sub_step_199 = (sub_step_154 + pub_r000513_21 + 26) & 127;
    int stage_v_199 = (sub_step_199 * 2 + pub_r000513_20) & 127;
    st_var_1.buffer[1] = (stage_v_199 & 15);
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int sub_step_200 = (sub_step_114 + pub_r000513_16 + 19) & 127;
    int stage_v_200 = (sub_step_200 * 2 + pub_r000513_13) & 127;
    st_var_2.buffer[2] = (stage_v_200 & 15);
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int sub_step_201 = (sec_r000513_17 + pub_r000513_8 + 32) & 127;
    int stage_v_201 = (sub_step_201 * 2 + pub_r000513_2) & 127;
    st_var_0.buffer[0] = (stage_v_201 & 15);
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int sub_step_202 = (sub_step_114 + pub_r000513_7 + 30) & 127;
    int stage_v_202 = (sub_step_202 * 2 + pub_r000513_3) & 127;
    st_var_1.buffer[1] = (stage_v_202 & 15);
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int sub_step_203 = (sec_r000513_14 + pub_r000513_5 + 12) & 127;
    int stage_v_203 = (sub_step_203 * 2 + pub_r000513_1) & 127;
    st_var_2.buffer[2] = (stage_v_203 & 15);
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int sub_step_204 = (sec_r000513_13 + pub_r000513_8 + 15) & 127;
    int stage_v_204 = (sub_step_204 * 2 + pub_r000513_16) & 127;
    st_var_0.buffer[0] = (stage_v_204 & 15);
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int sub_step_205 = (sec_r000513_15 + pub_r000513_3 + 22) & 127;
    int stage_v_205 = (sub_step_205 * 2 + pub_r000513_8) & 127;
    st_var_1.buffer[1] = (stage_v_205 & 15);
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int sub_step_206 = (sec_r000513_0 + pub_r000513_1 + 29) & 127;
    int stage_v_206 = (sub_step_206 * 2 + pub_r000513_4) & 127;
    st_var_2.buffer[2] = (stage_v_206 & 15);
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int sub_step_207 = (sub_step_167 + pub_r000513_16 + 27) & 127;
    int stage_v_207 = (sub_step_207 * 2 + pub_r000513_13) & 127;
    st_var_0.buffer[0] = (stage_v_207 & 15);
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int sub_step_208 = (sub_step_198 + pub_r000513_12 + 34) & 127;
    int stage_v_208 = (sub_step_208 * 2 + pub_r000513_7) & 127;
    st_var_1.buffer[1] = (stage_v_208 & 15);
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int sub_step_209 = (sub_step_106 + pub_r000513_5 + 26) & 127;
    int stage_v_209 = (sub_step_209 * 2 + pub_r000513_18) & 127;
    st_var_2.buffer[2] = (stage_v_209 & 15);
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int sub_step_210 = (stage_v_181 + pub_r000513_16 + 29) & 127;
    int stage_v_210 = (sub_step_210 * 2 + pub_r000513_4) & 127;
    st_var_0.buffer[0] = (stage_v_210 & 15);
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int sub_step_211 = (sec_r000513_6 + pub_r000513_14 + 33) & 127;
    int stage_v_211 = (sub_step_211 * 2 + pub_r000513_5) & 127;
    st_var_1.buffer[1] = (stage_v_211 & 15);
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int sub_step_212 = (sub_step_129 + pub_r000513_17 + 31) & 127;
    int stage_v_212 = (sub_step_212 * 2 + pub_r000513_17) & 127;
    st_var_2.buffer[2] = (stage_v_212 & 15);
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int sub_step_213 = (sec_r000513_4 + pub_r000513_10 + 23) & 127;
    int stage_v_213 = (sub_step_213 * 2 + pub_r000513_18) & 127;
    st_var_0.buffer[0] = (stage_v_213 & 15);
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int sub_step_214 = (sec_r000513_15 + pub_r000513_12 + 16) & 127;
    int stage_v_214 = (sub_step_214 * 2 + pub_r000513_2) & 127;
    st_var_1.buffer[1] = (stage_v_214 & 15);
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int sub_step_215 = (sub_step_114 + pub_r000513_18 + 9) & 127;
    int stage_v_215 = (sub_step_215 * 2 + pub_r000513_10) & 127;
    st_var_2.buffer[2] = (stage_v_215 & 15);
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int sub_step_216 = (sub_step_138 + pub_r000513_22 + 20) & 127;
    int stage_v_216 = (sub_step_216 * 2 + pub_r000513_0) & 127;
    st_var_0.buffer[0] = (stage_v_216 & 15);
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int sub_step_217 = (sub_step_132 + pub_r000513_4 + 20) & 127;
    int stage_v_217 = (sub_step_217 * 2 + pub_r000513_12) & 127;
    st_var_1.buffer[1] = (stage_v_217 & 15);
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int sub_step_218 = (stage_v_128 + pub_r000513_2 + 13) & 127;
    int stage_v_218 = (sub_step_218 * 2 + pub_r000513_1) & 127;
    st_var_2.buffer[2] = (stage_v_218 & 15);
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int sub_step_219 = (sub_step_113 + pub_r000513_17 + 23) & 127;
    int stage_v_219 = (sub_step_219 * 2 + pub_r000513_16) & 127;
    st_var_0.buffer[0] = (stage_v_219 & 15);
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int sub_step_220 = (sec_r000513_1 + pub_r000513_20 + 25) & 127;
    int stage_v_220 = (sub_step_220 * 2 + pub_r000513_16) & 127;
    st_var_1.buffer[1] = (stage_v_220 & 15);
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int sub_step_221 = (sec_r000513_5 + pub_r000513_9 + 6) & 127;
    int stage_v_221 = (sub_step_221 * 2 + pub_r000513_3) & 127;
    st_var_2.buffer[2] = (stage_v_221 & 15);
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int sub_step_222 = (sec_r000513_1 + pub_r000513_11 + 35) & 127;
    int stage_v_222 = (sub_step_222 * 2 + pub_r000513_12) & 127;
    st_var_0.buffer[0] = (stage_v_222 & 15);
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int sub_step_223 = (sub_step_108 + pub_r000513_17 + 7) & 127;
    int stage_v_223 = (sub_step_223 * 2 + pub_r000513_9) & 127;
    st_var_1.buffer[1] = (stage_v_223 & 15);
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int sub_step_224 = (sec_r000513_0 + pub_r000513_6 + 12) & 127;
    int stage_v_224 = (sub_step_224 * 2 + pub_r000513_3) & 127;
    st_var_2.buffer[2] = (stage_v_224 & 15);
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int sub_step_225 = (sub_step_188 + pub_r000513_11 + 8) & 127;
    int stage_v_225 = (sub_step_225 * 2 + pub_r000513_20) & 127;
    st_var_0.buffer[0] = (stage_v_225 & 15);
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int sub_step_226 = (stage_v_167 + pub_r000513_22 + 18) & 127;
    int stage_v_226 = (sub_step_226 * 2 + pub_r000513_9) & 127;
    st_var_1.buffer[1] = (stage_v_226 & 15);
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int sub_step_227 = (sub_step_215 + pub_r000513_1 + 28) & 127;
    int stage_v_227 = (sub_step_227 * 2 + pub_r000513_14) & 127;
    st_var_2.buffer[2] = (stage_v_227 & 15);
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int sub_step_228 = (sub_step_213 + pub_r000513_7 + 16) & 127;
    int stage_v_228 = (sub_step_228 * 2 + pub_r000513_4) & 127;
    st_var_0.buffer[0] = (stage_v_228 & 15);
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int sub_step_229 = (sub_step_125 + pub_r000513_12 + 17) & 127;
    int stage_v_229 = (sub_step_229 * 2 + pub_r000513_16) & 127;
    st_var_1.buffer[1] = (stage_v_229 & 15);
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int sub_step_230 = (sub_step_90 + pub_r000513_15 + 30) & 127;
    int stage_v_230 = (sub_step_230 * 2 + pub_r000513_9) & 127;
    st_var_2.buffer[2] = (stage_v_230 & 15);
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int sub_step_231 = (sec_r000513_17 + pub_r000513_18 + 27) & 127;
    int stage_v_231 = (sub_step_231 * 2 + pub_r000513_19) & 127;
    st_var_0.buffer[0] = (stage_v_231 & 15);
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int sub_step_232 = (stage_v_134 + pub_r000513_4 + 16) & 127;
    int stage_v_232 = (sub_step_232 * 2 + pub_r000513_18) & 127;
    st_var_1.buffer[1] = (stage_v_232 & 15);
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int sub_step_233 = (sub_step_228 + pub_r000513_22 + 35) & 127;
    int stage_v_233 = (sub_step_233 * 2 + pub_r000513_1) & 127;
    st_var_2.buffer[2] = (stage_v_233 & 15);
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int sub_step_234 = (sec_r000513_17 + pub_r000513_0 + 11) & 127;
    int stage_v_234 = (sub_step_234 * 2 + pub_r000513_11) & 127;
    st_var_0.buffer[0] = (stage_v_234 & 15);
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int sub_step_235 = (sub_step_113 + pub_r000513_7 + 30) & 127;
    int stage_v_235 = (sub_step_235 * 2 + pub_r000513_8) & 127;
    st_var_1.buffer[1] = (stage_v_235 & 15);
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int sub_step_236 = (sec_r000513_12 + pub_r000513_22 + 18) & 127;
    int stage_v_236 = (sub_step_236 * 2 + pub_r000513_22) & 127;
    st_var_2.buffer[2] = (stage_v_236 & 15);
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int sub_step_237 = (sec_r000513_4 + pub_r000513_12 + 22) & 127;
    int stage_v_237 = (sub_step_237 * 2 + pub_r000513_22) & 127;
    st_var_0.buffer[0] = (stage_v_237 & 15);
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int sub_step_238 = (sec_r000513_4 + pub_r000513_14 + 15) & 127;
    int stage_v_238 = (sub_step_238 * 2 + pub_r000513_14) & 127;
    st_var_1.buffer[1] = (stage_v_238 & 15);
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int sub_step_239 = (sec_r000513_0 + pub_r000513_4 + 16) & 127;
    int stage_v_239 = (sub_step_239 * 2 + pub_r000513_22) & 127;
    st_var_2.buffer[2] = (stage_v_239 & 15);
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int sub_step_240 = (sub_step_184 + pub_r000513_18 + 11) & 127;
    int stage_v_240 = (sub_step_240 * 2 + pub_r000513_13) & 127;
    st_var_0.buffer[0] = (stage_v_240 & 15);
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int sub_step_241 = (sec_r000513_1 + pub_r000513_7 + 6) & 127;
    int stage_v_241 = (sub_step_241 * 2 + pub_r000513_14) & 127;
    st_var_1.buffer[1] = (stage_v_241 & 15);
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int sub_step_242 = (sub_step_159 + pub_r000513_3 + 22) & 127;
    int stage_v_242 = (sub_step_242 * 2 + pub_r000513_6) & 127;
    st_var_2.buffer[2] = (stage_v_242 & 15);
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int sub_step_243 = (sub_step_166 + pub_r000513_4 + 10) & 127;
    int stage_v_243 = (sub_step_243 * 2 + pub_r000513_7) & 127;
    st_var_0.buffer[0] = (stage_v_243 & 15);
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int sub_step_244 = (sub_step_97 + pub_r000513_4 + 29) & 127;
    int stage_v_244 = (sub_step_244 * 2 + pub_r000513_22) & 127;
    st_var_1.buffer[1] = (stage_v_244 & 15);
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int sub_step_245 = (sub_step_141 + pub_r000513_7 + 16) & 127;
    int stage_v_245 = (sub_step_245 * 2 + pub_r000513_9) & 127;
    st_var_2.buffer[2] = (stage_v_245 & 15);
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int sub_step_246 = (sub_step_143 + pub_r000513_8 + 8) & 127;
    int stage_v_246 = (sub_step_246 * 2 + pub_r000513_12) & 127;
    st_var_0.buffer[0] = (stage_v_246 & 15);
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int sub_step_247 = (sub_step_182 + pub_r000513_14 + 9) & 127;
    int stage_v_247 = (sub_step_247 * 2 + pub_r000513_21) & 127;
    st_var_1.buffer[1] = (stage_v_247 & 15);
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int sub_step_248 = (stage_v_142 + pub_r000513_6 + 24) & 127;
    int stage_v_248 = (sub_step_248 * 2 + pub_r000513_10) & 127;
    st_var_2.buffer[2] = (stage_v_248 & 15);
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int sub_step_249 = (sub_step_247 + pub_r000513_8 + 23) & 127;
    int stage_v_249 = (sub_step_249 * 2 + pub_r000513_7) & 127;
    st_var_0.buffer[0] = (stage_v_249 & 15);
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int sub_step_250 = (sec_r000513_3 + pub_r000513_5 + 12) & 127;
    int stage_v_250 = (sub_step_250 * 2 + pub_r000513_16) & 127;
    st_var_1.buffer[1] = (stage_v_250 & 15);
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int sub_step_251 = (sub_step_156 + pub_r000513_3 + 29) & 127;
    int stage_v_251 = (sub_step_251 * 2 + pub_r000513_2) & 127;
    st_var_2.buffer[2] = (stage_v_251 & 15);
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int sub_step_252 = (sub_step_131 + pub_r000513_19 + 12) & 127;
    int stage_v_252 = (sub_step_252 * 2 + pub_r000513_2) & 127;
    st_var_0.buffer[0] = (stage_v_252 & 15);
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int sub_step_253 = (stage_v_136 + pub_r000513_11 + 7) & 127;
    int stage_v_253 = (sub_step_253 * 2 + pub_r000513_13) & 127;
    st_var_1.buffer[1] = (stage_v_253 & 15);
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int sub_step_254 = (sub_step_196 + pub_r000513_17 + 35) & 127;
    int stage_v_254 = (sub_step_254 * 2 + pub_r000513_22) & 127;
    st_var_2.buffer[2] = (stage_v_254 & 15);
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int sub_step_255 = (sub_step_128 + pub_r000513_12 + 11) & 127;
    int stage_v_255 = (sub_step_255 * 2 + pub_r000513_21) & 127;
    st_var_0.buffer[0] = (stage_v_255 & 15);
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int sub_step_256 = (sec_r000513_11 + pub_r000513_3 + 33) & 127;
    int stage_v_256 = (sub_step_256 * 2 + pub_r000513_13) & 127;
    st_var_1.buffer[1] = (stage_v_256 & 15);
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int sub_step_257 = (stage_v_236 + pub_r000513_14 + 14) & 127;
    int stage_v_257 = (sub_step_257 * 2 + pub_r000513_18) & 127;
    st_var_2.buffer[2] = (stage_v_257 & 15);
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int sub_step_258 = (stage_v_132 + pub_r000513_10 + 30) & 127;
    int stage_v_258 = (sub_step_258 * 2 + pub_r000513_4) & 127;
    st_var_0.buffer[0] = (stage_v_258 & 15);
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int sub_step_259 = (sec_r000513_16 + pub_r000513_6 + 10) & 127;
    int stage_v_259 = (sub_step_259 * 2 + pub_r000513_9) & 127;
    st_var_1.buffer[1] = (stage_v_259 & 15);
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int sub_step_260 = (sub_step_134 + pub_r000513_9 + 26) & 127;
    int stage_v_260 = (sub_step_260 * 2 + pub_r000513_3) & 127;
    st_var_2.buffer[2] = (stage_v_260 & 15);
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int sub_step_261 = (sec_r000513_4 + pub_r000513_13 + 10) & 127;
    int stage_v_261 = (sub_step_261 * 2 + pub_r000513_9) & 127;
    st_var_0.buffer[0] = (stage_v_261 & 15);
    out_sink = (out_sink + stage_v_261) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
