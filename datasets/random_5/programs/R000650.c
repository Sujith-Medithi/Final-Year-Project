/*
 * Benchmark Program: R000650
 * Security Family: mixed_control_data
 * Generator Seed: 565013
 * High Inputs: 23 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000650_5013_0 {
    unsigned char auth_code;
    unsigned char balance;
    int fee;
    int buffer[3];
};

struct AudioFrame_R000650_5013_1 {
    short rms;
    short peak;
    short envelope;
    short gain;
    int buffer[3];
};

struct Vector3D_R000650_5013_2 {
    int coord_x;
    unsigned char norm_sq;
    int heading;
    short pitch;
    int coord_y;
    int coord_z;
    int buffer[3];
};

union TelemetryField_R000650_5013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000650_5013_0(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000650_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int bound_17 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_17 > 41) {
        acc = (acc + bound_17 * 2 + 5) & 127;
        aux ^= (bound_17 & 15);
    } else {
        acc = (acc - bound_17 + 11) & 127;
        aux += 3;
    }
    int accumulator_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_29) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int vector_17 = local_arr[aux % 3];
    acc = (acc + vector_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000650_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int parity_14 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_14 > 16) {
        acc = (acc + parity_14 * 2 + 5) & 127;
        aux ^= (parity_14 & 15);
    } else {
        acc = (acc - parity_14 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_20 = local_arr[aux % 3];
    acc = (acc + checksum_20 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_2(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000650_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quotient_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_42) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int threshold_49 = local_arr[aux % 3];
    acc = (acc + threshold_49 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_3(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000650_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int phase_39 = (aux + st.buffer[1]) & 3;
    switch (phase_39) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_85) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_79 = local_arr[aux % 3];
    acc = (acc + tally_79 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000650_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_65) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int metric_10 = local_arr[aux % 3];
    acc = (acc + metric_10 * 2) & 127;
    int residue_54 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_54 > 14) {
        acc = (acc + residue_54 * 2 + 5) & 127;
        aux ^= (residue_54 & 15);
    } else {
        acc = (acc - residue_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000650_5013_5(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000650_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int window_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_12) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int anchor_37 = local_arr[aux % 3];
    acc = (acc + anchor_37 * 2) & 127;
    int tally_42 = (aux + st.buffer[1]) & 3;
    switch (tally_42) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int parity_46 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_46 > 31) {
        acc = (acc + parity_46 * 2 + 5) & 127;
        aux ^= (parity_46 & 15);
    } else {
        acc = (acc - parity_46 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000650_5013_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000650_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int mask_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_12) & 63;
    acc ^= aux;
    int accumulator_97 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_97 > 16) {
        acc = (acc + accumulator_97 * 2 + 5) & 127;
        aux ^= (accumulator_97 & 15);
    } else {
        acc = (acc - accumulator_97 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000650_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int bound_14 = local_arr[aux % 3];
    acc = (acc + bound_14 * 2) & 127;
    int offset_20 = (aux + st.buffer[1]) & 3;
    switch (offset_20) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_8(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000650_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_90 = local_arr[aux % 3];
    acc = (acc + parity_90 * 2) & 127;
    int weight_69 = (aux + st.buffer[1]) & 3;
    switch (weight_69) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000650_5013_9(int p0, int p1, int p2) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000650_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int accumulator_27 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_27 > 45) {
        acc = (acc + accumulator_27 * 2 + 5) & 127;
        aux ^= (accumulator_27 & 15);
    } else {
        acc = (acc - accumulator_27 + 11) & 127;
        aux += 3;
    }
    int threshold_40 = (aux + st.buffer[1]) & 3;
    switch (threshold_40) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000650_5013_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000650_5013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int vector_45 = (aux + st.buffer[1]) & 3;
    switch (vector_45) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int mask_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_29) & 63;
    acc ^= aux;
    int residue_12 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_12 > 46) {
        acc = (acc + residue_12 * 2 + 5) & 127;
        aux ^= (residue_12 & 15);
    } else {
        acc = (acc - residue_12 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int factor_59 = local_arr[aux % 3];
    acc = (acc + factor_59 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000650_5013_11(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000650_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int threshold_57 = (aux + st.buffer[1]) & 3;
    switch (threshold_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_47 = local_arr[aux % 3];
    acc = (acc + scale_47 * 2) & 127;
    int stride_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_65) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000650_5013_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000650_5013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int anchor_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_33) & 63;
    acc ^= aux;
    int phase_81 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_81 > 31) {
        acc = (acc + phase_81 * 2 + 5) & 127;
        aux ^= (phase_81 & 15);
    } else {
        acc = (acc - phase_81 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000650_5013_13(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000650_5013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int tracker_69 = (aux + st.buffer[1]) & 3;
    switch (tracker_69) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_82 = local_arr[aux % 3];
    acc = (acc + mask_82 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000650_0;
    int sec_r000650_1;
    int sec_r000650_2;
    int sec_r000650_3;
    int sec_r000650_4;
    int sec_r000650_5;
    int sec_r000650_6;
    int sec_r000650_7;
    int sec_r000650_8;
    int sec_r000650_9;
    int sec_r000650_10;
    int sec_r000650_11;
    int sec_r000650_12;
    int sec_r000650_13;
    int sec_r000650_14;
    int sec_r000650_15;
    int sec_r000650_16;
    int sec_r000650_17;
    int sec_r000650_18;
    int sec_r000650_19;
    int sec_r000650_20;
    int sec_r000650_21;
    int sec_r000650_22;
    int pub_r000650_0;
    int pub_r000650_1;
    int pub_r000650_2;
    int pub_r000650_3;
    int pub_r000650_4;
    int pub_r000650_5;
    int pub_r000650_6;
    int pub_r000650_7;
    int pub_r000650_8;
    int pub_r000650_9;
    int pub_r000650_10;
    int pub_r000650_11;
    int pub_r000650_12;
    int pub_r000650_13;
    int pub_r000650_14;
    int pub_r000650_15;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000650_0 >= -100 && pub_r000650_0 <= 100);
    __CPROVER_assume(pub_r000650_1 >= -100 && pub_r000650_1 <= 100);
    __CPROVER_assume(pub_r000650_2 >= -100 && pub_r000650_2 <= 100);
    __CPROVER_assume(pub_r000650_3 >= -100 && pub_r000650_3 <= 100);
    __CPROVER_assume(pub_r000650_4 >= -100 && pub_r000650_4 <= 100);
    __CPROVER_assume(pub_r000650_5 >= -100 && pub_r000650_5 <= 100);
    __CPROVER_assume(pub_r000650_6 >= -100 && pub_r000650_6 <= 100);
    __CPROVER_assume(pub_r000650_7 >= -100 && pub_r000650_7 <= 100);
    __CPROVER_assume(pub_r000650_8 >= -100 && pub_r000650_8 <= 100);
    __CPROVER_assume(pub_r000650_9 >= -100 && pub_r000650_9 <= 100);
    __CPROVER_assume(pub_r000650_10 >= -100 && pub_r000650_10 <= 100);
    __CPROVER_assume(pub_r000650_11 >= -100 && pub_r000650_11 <= 100);
    __CPROVER_assume(pub_r000650_12 >= -100 && pub_r000650_12 <= 100);
    __CPROVER_assume(pub_r000650_13 >= -100 && pub_r000650_13 <= 100);
    __CPROVER_assume(pub_r000650_14 >= -100 && pub_r000650_14 <= 100);
    __CPROVER_assume(pub_r000650_15 >= -100 && pub_r000650_15 <= 100);
    __CPROVER_assume(sec_r000650_0 >= 0 && sec_r000650_0 <= 255);
    __CPROVER_assume(sec_r000650_1 >= 0 && sec_r000650_1 <= 255);
    __CPROVER_assume(sec_r000650_2 >= 0 && sec_r000650_2 <= 255);
    __CPROVER_assume(sec_r000650_3 >= 0 && sec_r000650_3 <= 255);
    __CPROVER_assume(sec_r000650_4 >= 0 && sec_r000650_4 <= 255);
    __CPROVER_assume(sec_r000650_5 >= 0 && sec_r000650_5 <= 255);
    __CPROVER_assume(sec_r000650_6 >= 0 && sec_r000650_6 <= 255);
    __CPROVER_assume(sec_r000650_7 >= 0 && sec_r000650_7 <= 255);
    __CPROVER_assume(sec_r000650_8 >= 0 && sec_r000650_8 <= 255);
    __CPROVER_assume(sec_r000650_9 >= 0 && sec_r000650_9 <= 255);
    __CPROVER_assume(sec_r000650_10 >= 0 && sec_r000650_10 <= 255);
    __CPROVER_assume(sec_r000650_11 >= 0 && sec_r000650_11 <= 255);
    __CPROVER_assume(sec_r000650_12 >= 0 && sec_r000650_12 <= 255);
    __CPROVER_assume(sec_r000650_13 >= 0 && sec_r000650_13 <= 255);
    __CPROVER_assume(sec_r000650_14 >= 0 && sec_r000650_14 <= 255);
    __CPROVER_assume(sec_r000650_15 >= 0 && sec_r000650_15 <= 255);
    __CPROVER_assume(sec_r000650_16 >= 0 && sec_r000650_16 <= 255);
    __CPROVER_assume(sec_r000650_17 >= 0 && sec_r000650_17 <= 255);
    __CPROVER_assume(sec_r000650_18 >= 0 && sec_r000650_18 <= 255);
    __CPROVER_assume(sec_r000650_19 >= 0 && sec_r000650_19 <= 255);
    __CPROVER_assume(sec_r000650_20 >= 0 && sec_r000650_20 <= 255);
    __CPROVER_assume(sec_r000650_21 >= 0 && sec_r000650_21 <= 255);
    __CPROVER_assume(sec_r000650_22 >= 0 && sec_r000650_22 <= 255);

    struct Transaction_R000650_5013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000650_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000650_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000650_0 + 7) & 15;
    struct AudioFrame_R000650_5013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000650_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000650_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000650_0 + 9) & 15;
    struct Vector3D_R000650_5013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000650_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000650_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000650_0 + 11) & 15;

    union TelemetryField_R000650_5013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[2] * 2 + 22) & 63;
    if (stage_v_5 > 30) {
        out_sink = (out_sink + stage_v_5 - 5) & 255;
        if (stage_v_5 > 45) {
            chk_sum ^= (stage_v_5 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_5 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 28) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 43) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[0] ^ 14) & 3;
    switch (stage_v_11) {
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

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_13 = (stage_v_13 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_13) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 32) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 47) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_0.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 35) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 50) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((sec_r000650_17 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_25 > 27) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((sec_r000650_19 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_26 > 35) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((sec_r000650_16 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_27 > 21) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((stage_v_26 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_28 > 27) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_28 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_29 > 34) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_26 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_30 > 29) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_29 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_31 > 41) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((stage_v_27 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_32 > 44) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000650_10 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_33 > 20) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_26 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_34 > 33) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r000650_11 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_35 > 46) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_28 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_36 > 33) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((stage_v_26 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_37 > 46) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_28 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_38 > 25) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((sec_r000650_3 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_39 > 48) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_37 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_40 > 28) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_25 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_41 > 34) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r000650_8 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_42 > 40) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_34 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_43 > 31) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((stage_v_40 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_44 > 32) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r000650_12 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_45 > 23) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_38 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_46 > 46) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r000650_18 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_47 > 48) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_34 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_48 > 50) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000650_16 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_49 > 20) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_27 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_50 > 22) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_30 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_51 > 48) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_30 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_52 > 34) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_26 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_53 > 45) {
        out_sink = (out_sink + stage_v_53 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_53 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((stage_v_45 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_54 > 35) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_47 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_55 > 47) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r000650_4 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_56 > 45) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_41 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_57 > 32) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((sec_r000650_9 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_58 > 31) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_56 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_59 > 25) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((sec_r000650_20 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_60 > 31) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((stage_v_47 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_61 > 20) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000650_17 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_62 > 30) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((sec_r000650_1 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_63 > 48) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000650_21 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_64 > 31) {
        out_sink = (out_sink + stage_v_64 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_64 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((stage_v_26 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_65 > 21) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((sec_r000650_13 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_66 > 43) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_43 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_67 > 41) {
        out_sink = (out_sink + stage_v_67 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_67 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_62 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_68 > 27) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_43 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_69 > 28) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_67 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_70 > 21) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_30 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_71 > 43) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_66 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_72 > 46) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((sec_r000650_0 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_73 > 45) {
        out_sink = (out_sink + stage_v_73 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_73 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_40 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_74 > 30) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_51 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_75 > 39) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((sec_r000650_6 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_76 > 34) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_39 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_77 > 33) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((sec_r000650_8 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_78 > 41) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_41 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_79 > 22) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_29 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_80 > 40) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_61 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_81 > 38) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_72 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_82 > 34) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((sec_r000650_8 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_83 > 48) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000650_17 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_84 > 41) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_73 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_85 > 32) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r000650_6 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_86 > 45) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((sec_r000650_14 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_87 > 44) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_45 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_88 > 30) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r000650_6 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_89 > 46) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_65 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_90 > 33) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_81 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_91 > 25) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_90 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_92 > 27) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((sec_r000650_7 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_93 > 21) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r000650_22 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_94 > 50) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r000650_5 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_95 > 39) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r000650_20 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_96 > 26) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_96 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_97 > 46) {
        out_sink = (out_sink + stage_v_97 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_97 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_67 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_98 > 24) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000650_19 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_99 > 47) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000650_18 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_100 > 32) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_58 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_101 > 32) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((sec_r000650_5 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_102 > 41) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((sec_r000650_19 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_103 > 29) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_82 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_104 > 36) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_68 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_105 > 28) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_77 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_106 > 21) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_100 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_107 > 32) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_65 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_108 > 48) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_104 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_109 > 33) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((sec_r000650_1 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_110 > 28) {
        out_sink = (out_sink + stage_v_110 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_110 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_43 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_111 > 26) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_31 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_112 > 39) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r000650_14 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_113 > 20) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_104 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_114 > 32) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((sec_r000650_11 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_115 > 27) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_91 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_116 > 44) {
        out_sink = (out_sink + stage_v_116 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_116 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_31 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_117 > 40) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000650_9 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_118 > 44) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_112 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_119 > 43) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((sec_r000650_7 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_120 > 31) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_80 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_121 > 35) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000650_12 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_122 > 20) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_52 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_123 > 36) {
        out_sink = (out_sink + stage_v_123 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_123 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_46 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_124 > 45) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_93 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_125 > 36) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000650_12 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_126 > 20) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((sec_r000650_11 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_127 > 27) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r000650_20 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_128 > 32) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_119 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_129 > 20) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r000650_19 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_130 > 39) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_119 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_131 > 24) {
        out_sink = (out_sink + stage_v_131 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_131 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_46 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_132 > 45) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_82 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_133 > 31) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000650_9 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_134 > 33) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_50 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_135 > 50) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_47 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_136 > 28) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_99 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_137 > 21) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_132 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_138 > 31) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_30 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_139 > 35) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000650_21 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_140 > 29) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r000650_7 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_141 > 38) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_121 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_142 > 43) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_98 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_143 > 36) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_33 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_144 > 47) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((sec_r000650_16 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_145 > 38) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((stage_v_48 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_146 > 28) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000650_4 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_147 > 29) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_112 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_148 > 27) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r000650_21 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_149 > 22) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000650_14 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_150 > 49) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000650_21 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_151 > 42) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_74 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_152 > 29) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_93 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_153 > 26) {
        out_sink = (out_sink + stage_v_153 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_153 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_72 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_154 > 36) {
        out_sink = (out_sink + stage_v_154 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_154 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r000650_10 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_155 > 48) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_85 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_156 > 43) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_68 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_157 > 42) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_149 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_158 > 32) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((stage_v_120 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_159 > 26) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_126 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_160 > 43) {
        out_sink = (out_sink + stage_v_160 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_160 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000650_0 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_161 > 37) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_53 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_162 > 30) {
        out_sink = (out_sink + stage_v_162 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_162 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_42 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_163 > 30) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_106 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_164 > 29) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_109 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_165 > 36) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000650_11 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_166 > 24) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_95 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_167 > 24) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000650_2 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_168 > 29) {
        out_sink = (out_sink + stage_v_168 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_168 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_145 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_169 > 22) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((sec_r000650_7 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_170 > 46) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((sec_r000650_19 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_171 > 34) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000650_6 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_172 > 27) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_81 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_173 > 28) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_139 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_174 > 28) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_115 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_175 > 41) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((sec_r000650_18 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_176 > 35) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000650_4 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_177 > 43) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000650_22 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_178 > 21) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r000650_8 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_179 > 37) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_168 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_180 > 40) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_146 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_181 > 35) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((stage_v_99 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_182 > 41) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_181 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_183 > 28) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r000650_7 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_184 > 23) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_43 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_185 > 50) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000650_18 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_186 > 24) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_165 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_187 > 45) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_140 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_188 > 34) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_140 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_189 > 43) {
        out_sink = (out_sink + stage_v_189 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_189 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_69 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_190 > 49) {
        out_sink = (out_sink + stage_v_190 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_190 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_147 ^ 0x2A) + pub_r000650_4) & 127;
    if (stage_v_191 > 35) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_89 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_192 > 30) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((stage_v_121 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_193 > 39) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((sec_r000650_2 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_194 > 49) {
        out_sink = (out_sink + stage_v_194 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_194 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r000650_1 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_195 > 22) {
        out_sink = (out_sink + stage_v_195 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_195 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000650_4 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_196 > 33) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000650_8 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_197 > 29) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_102 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_198 > 47) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_107 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_199 > 49) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_130 ^ 0x2A) + pub_r000650_5) & 127;
    if (stage_v_200 > 41) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_68 ^ 0x2A) + pub_r000650_10) & 127;
    if (stage_v_201 > 29) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_164 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_202 > 33) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_36 ^ 0x2A) + pub_r000650_0) & 127;
    if (stage_v_203 > 29) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_45 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_204 > 29) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_122 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_205 > 45) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_115 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_206 > 24) {
        out_sink = (out_sink + stage_v_206 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_206 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r000650_1 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_207 > 30) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_32 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_208 > 23) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r000650_13 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_209 > 31) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_171 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_210 > 39) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_128 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_211 > 41) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000650_17 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_212 > 29) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r000650_8 ^ 0x2A) + pub_r000650_14) & 127;
    if (stage_v_213 > 44) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_98 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_214 > 46) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_183 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_215 > 35) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_125 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_216 > 46) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_143 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_217 > 45) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_72 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_218 > 37) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_149 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_219 > 40) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_150 ^ 0x2A) + pub_r000650_2) & 127;
    if (stage_v_220 > 28) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_39 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_221 > 21) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_87 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_222 > 33) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r000650_3 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_223 > 29) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_92 ^ 0x2A) + pub_r000650_6) & 127;
    if (stage_v_224 > 29) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_196 ^ 0x2A) + pub_r000650_13) & 127;
    if (stage_v_225 > 23) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_126 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_226 > 29) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000650_12 ^ 0x2A) + pub_r000650_8) & 127;
    if (stage_v_227 > 44) {
        out_sink = (out_sink + stage_v_227 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_227 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_133 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_228 > 35) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r000650_19 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_229 > 20) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_92 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_230 > 25) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_130 ^ 0x2A) + pub_r000650_12) & 127;
    if (stage_v_231 > 33) {
        out_sink = (out_sink + stage_v_231 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_231 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_128 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_232 > 37) {
        out_sink = (out_sink + stage_v_232 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_232 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_135 ^ 0x2A) + pub_r000650_3) & 127;
    if (stage_v_233 > 31) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_216 ^ 0x2A) + pub_r000650_1) & 127;
    if (stage_v_234 > 20) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((sec_r000650_4 ^ 0x2A) + pub_r000650_9) & 127;
    if (stage_v_235 > 44) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_170 ^ 0x2A) + pub_r000650_15) & 127;
    if (stage_v_236 > 48) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_51 ^ 0x2A) + pub_r000650_11) & 127;
    if (stage_v_237 > 21) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((sec_r000650_6 ^ 0x2A) + pub_r000650_7) & 127;
    if (stage_v_238 > 28) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
