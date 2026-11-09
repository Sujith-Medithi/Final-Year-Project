/*
 * Benchmark Program: R001210
 * Security Family: mixed_control_data
 * Generator Seed: 621013
 * High Inputs: 16 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R001210_1013_0 {
    unsigned char damping;
    int prev_in;
    int cutoff;
    int buffer[3];
};

struct EventLog_R001210_1013_1 {
    unsigned char seq;
    int facility;
    int signature;
    short code;
    int severity;
    int buffer[3];
};

struct Vector3D_R001210_1013_2 {
    int heading;
    short coord_y;
    int pitch;
    int coord_z;
    int coord_x;
    int norm_sq;
    int buffer[3];
};

union PacketPayload_R001210_1013_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R001210_1013_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001210_1013_0(int p0, int p1) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001210_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int local_arr[3] = {4, 9, 15};
    int window_37 = local_arr[aux % 3];
    acc = (acc + window_37 * 2) & 127;
    int margin_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_54) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_16 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_16 > 13) {
        acc = (acc + tracker_16 * 2 + 5) & 127;
        aux ^= (tracker_16 & 15);
    } else {
        acc = (acc - tracker_16 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001210_1013_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 48) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001210_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int mask_62 = (aux + st.buffer[1]) & 3;
    switch (mask_62) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_33 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_33 > 30) {
        acc = (acc + anchor_33 * 2 + 5) & 127;
        aux ^= (anchor_33 & 15);
    } else {
        acc = (acc - anchor_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001210_1013_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001210_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tally_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_83 = local_arr[aux % 3];
    acc = (acc + vector_83 * 2) & 127;
    int index_reg_22 = (aux + st.buffer[1]) & 3;
    switch (index_reg_22) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001210_1013_3(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001210_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int bound_84 = (aux + st.buffer[1]) & 3;
    switch (bound_84) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_74) & 63;
    acc ^= aux;
    int pivot_45 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_45 > 32) {
        acc = (acc + pivot_45 * 2 + 5) & 127;
        aux ^= (pivot_45 & 15);
    } else {
        acc = (acc - pivot_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001210_1013_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001210_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int coefficient_55 = local_arr[aux % 3];
    acc = (acc + coefficient_55 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001210_1013_5(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001210_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_91 = 0;
    for (int k = 0; k < 2; k++) {
        residue_91 = (residue_91 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_91) & 127;
    }
    int residue_50 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_50 > 25) {
        acc = (acc + residue_50 * 2 + 5) & 127;
        aux ^= (residue_50 & 15);
    } else {
        acc = (acc - residue_50 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001210_1013_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001210_1013_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_53 = (aux + st.buffer[1]) & 3;
    switch (residue_53) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_28 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_28 > 46) {
        acc = (acc + checksum_28 * 2 + 5) & 127;
        aux ^= (checksum_28 & 15);
    } else {
        acc = (acc - checksum_28 + 11) & 127;
        aux += 3;
    }
    int tracker_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_34) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001210_1013_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001210_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int accumulator_88 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_88 > 25) {
        acc = (acc + accumulator_88 * 2 + 5) & 127;
        aux ^= (accumulator_88 & 15);
    } else {
        acc = (acc - accumulator_88 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int tally_43 = local_arr[aux % 3];
    acc = (acc + tally_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001210_1013_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001210_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int tally_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_40 > 45) {
        acc = (acc + tally_40 * 2 + 5) & 127;
        aux ^= (tally_40 & 15);
    } else {
        acc = (acc - tally_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quotient_27 = local_arr[aux % 3];
    acc = (acc + quotient_27 * 2) & 127;
    int delta_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001210_1013_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001210_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_71 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_71 > 50) {
        acc = (acc + damping_71 * 2 + 5) & 127;
        aux ^= (damping_71 & 15);
    } else {
        acc = (acc - damping_71 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_68 = local_arr[aux % 3];
    acc = (acc + quantum_68 * 2) & 127;
    int bound_60 = (aux + st.buffer[1]) & 3;
    switch (bound_60) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001210_1013_10(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001210_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_29 = (aux + st.buffer[1]) & 3;
    switch (scale_29) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001210_1013_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001210_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001210_1013_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R001210_1013_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int tally_77 = (aux + st.buffer[1]) & 3;
    switch (tally_77) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001210_1013_13(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001210_1013_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int parity_83 = (aux + st.buffer[1]) & 3;
    switch (parity_83) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int damping_94 = local_arr[aux % 3];
    acc = (acc + damping_94 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001210_0;
    int sec_r001210_1;
    int sec_r001210_2;
    int sec_r001210_3;
    int sec_r001210_4;
    int sec_r001210_5;
    int sec_r001210_6;
    int sec_r001210_7;
    int sec_r001210_8;
    int sec_r001210_9;
    int sec_r001210_10;
    int sec_r001210_11;
    int sec_r001210_12;
    int sec_r001210_13;
    int sec_r001210_14;
    int sec_r001210_15;
    int pub_r001210_0;
    int pub_r001210_1;
    int pub_r001210_2;
    int pub_r001210_3;
    int pub_r001210_4;
    int pub_r001210_5;
    int pub_r001210_6;
    int pub_r001210_7;
    int pub_r001210_8;
    int pub_r001210_9;
    int pub_r001210_10;
    int pub_r001210_11;
    int pub_r001210_12;
    int pub_r001210_13;
    int pub_r001210_14;
    int pub_r001210_15;
    int pub_r001210_16;
    int pub_r001210_17;
    int pub_r001210_18;
    int pub_r001210_19;
    int pub_r001210_20;
    int pub_r001210_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001210_0 >= -100 && pub_r001210_0 <= 100);
    __CPROVER_assume(pub_r001210_1 >= -100 && pub_r001210_1 <= 100);
    __CPROVER_assume(pub_r001210_2 >= -100 && pub_r001210_2 <= 100);
    __CPROVER_assume(pub_r001210_3 >= -100 && pub_r001210_3 <= 100);
    __CPROVER_assume(pub_r001210_4 >= -100 && pub_r001210_4 <= 100);
    __CPROVER_assume(pub_r001210_5 >= -100 && pub_r001210_5 <= 100);
    __CPROVER_assume(pub_r001210_6 >= -100 && pub_r001210_6 <= 100);
    __CPROVER_assume(pub_r001210_7 >= -100 && pub_r001210_7 <= 100);
    __CPROVER_assume(pub_r001210_8 >= -100 && pub_r001210_8 <= 100);
    __CPROVER_assume(pub_r001210_9 >= -100 && pub_r001210_9 <= 100);
    __CPROVER_assume(pub_r001210_10 >= -100 && pub_r001210_10 <= 100);
    __CPROVER_assume(pub_r001210_11 >= -100 && pub_r001210_11 <= 100);
    __CPROVER_assume(pub_r001210_12 >= -100 && pub_r001210_12 <= 100);
    __CPROVER_assume(pub_r001210_13 >= -100 && pub_r001210_13 <= 100);
    __CPROVER_assume(pub_r001210_14 >= -100 && pub_r001210_14 <= 100);
    __CPROVER_assume(pub_r001210_15 >= -100 && pub_r001210_15 <= 100);
    __CPROVER_assume(pub_r001210_16 >= -100 && pub_r001210_16 <= 100);
    __CPROVER_assume(pub_r001210_17 >= -100 && pub_r001210_17 <= 100);
    __CPROVER_assume(pub_r001210_18 >= -100 && pub_r001210_18 <= 100);
    __CPROVER_assume(pub_r001210_19 >= -100 && pub_r001210_19 <= 100);
    __CPROVER_assume(pub_r001210_20 >= -100 && pub_r001210_20 <= 100);
    __CPROVER_assume(pub_r001210_21 >= -100 && pub_r001210_21 <= 100);
    __CPROVER_assume(sec_r001210_0 >= 0 && sec_r001210_0 <= 255);
    __CPROVER_assume(sec_r001210_1 >= 0 && sec_r001210_1 <= 255);
    __CPROVER_assume(sec_r001210_2 >= 0 && sec_r001210_2 <= 255);
    __CPROVER_assume(sec_r001210_3 >= 0 && sec_r001210_3 <= 255);
    __CPROVER_assume(sec_r001210_4 >= 0 && sec_r001210_4 <= 255);
    __CPROVER_assume(sec_r001210_5 >= 0 && sec_r001210_5 <= 255);
    __CPROVER_assume(sec_r001210_6 >= 0 && sec_r001210_6 <= 255);
    __CPROVER_assume(sec_r001210_7 >= 0 && sec_r001210_7 <= 255);
    __CPROVER_assume(sec_r001210_8 >= 0 && sec_r001210_8 <= 255);
    __CPROVER_assume(sec_r001210_9 >= 0 && sec_r001210_9 <= 255);
    __CPROVER_assume(sec_r001210_10 >= 0 && sec_r001210_10 <= 255);
    __CPROVER_assume(sec_r001210_11 >= 0 && sec_r001210_11 <= 255);
    __CPROVER_assume(sec_r001210_12 >= 0 && sec_r001210_12 <= 255);
    __CPROVER_assume(sec_r001210_13 >= 0 && sec_r001210_13 <= 255);
    __CPROVER_assume(sec_r001210_14 >= 0 && sec_r001210_14 <= 255);
    __CPROVER_assume(sec_r001210_15 >= 0 && sec_r001210_15 <= 255);

    struct FilterState_R001210_1013_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001210_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001210_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001210_0 + 7) & 15;
    struct EventLog_R001210_1013_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001210_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001210_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001210_0 + 9) & 15;
    struct Vector3D_R001210_1013_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001210_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001210_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001210_0 + 11) & 15;

    union PacketPayload_R001210_1013_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001210_1013_0(sec_r001210_0, sec_r001210_1);
    int helper_flow_1 = fn_R001210_1013_1(sec_r001210_1, sec_r001210_2, pub_r001210_3, pub_r001210_4);
    int helper_flow_2 = fn_R001210_1013_2(sec_r001210_2, sec_r001210_3, pub_r001210_4, pub_r001210_5, pub_r001210_6);
    int helper_flow_3 = fn_R001210_1013_3(sec_r001210_3, pub_r001210_4);
    int helper_flow_4 = fn_R001210_1013_4(sec_r001210_4, pub_r001210_5, pub_r001210_6, pub_r001210_7);
    int helper_flow_5 = fn_R001210_1013_5(sec_r001210_5, pub_r001210_6, pub_r001210_7);
    int helper_flow_6 = fn_R001210_1013_6(sec_r001210_6, sec_r001210_7, pub_r001210_8, pub_r001210_9, pub_r001210_10);
    int helper_flow_7 = fn_R001210_1013_7(sec_r001210_7, sec_r001210_8, pub_r001210_9, pub_r001210_10, pub_r001210_11);
    int helper_flow_8 = fn_R001210_1013_8(sec_r001210_8, pub_r001210_9, pub_r001210_10, pub_r001210_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_0 > 33) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((helper_flow_1 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_1 > 41) {
        out_sink = (out_sink + stage_v_1 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_1 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_2 > 43) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (pub_r001210_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_3) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((sec_r001210_3 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_4 > 42) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001210_14 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_5 > 21) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((sec_r001210_9 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_6 > 29) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001210_1 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_7 > 37) {
        out_sink = (out_sink + stage_v_7 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_7 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001210_15 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001210_5 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_9 > 37) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((sec_r001210_11 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_10 > 26) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001210_2 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_11 > 48) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001210_15) & 127;
    if (stage_v_12 > 43) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((sec_r001210_0 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_13 > 48) {
        out_sink = (out_sink + stage_v_13 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_13 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((sec_r001210_12 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_14 > 21) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_15 > 43) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((stage_v_10 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_16 > 42) {
        out_sink = (out_sink + stage_v_16 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_16 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_17 > 40) {
        out_sink = (out_sink + stage_v_17 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_17 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001210_14 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_19 > 30) {
        out_sink = (out_sink + stage_v_19 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_19 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_20 > 20) {
        out_sink = (out_sink + stage_v_20 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_20 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001210_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001210_15 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001210_10 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_23 > 42) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_24 > 46) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((helper_flow_5 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_25 > 22) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((stage_v_5 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_26 > 24) {
        out_sink = (out_sink + stage_v_26 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_26 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((stage_v_1 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_27 > 33) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((sec_r001210_10 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_28 > 33) {
        out_sink = (out_sink + stage_v_28 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_28 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_29 > 47) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_30 > 34) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_31 > 44) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r001210_14 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_32 > 24) {
        out_sink = (out_sink + stage_v_32 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_32 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001210_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r001210_0 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_34 > 23) {
        out_sink = (out_sink + stage_v_34 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_34 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_3 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_35 > 23) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_36 > 47) {
        out_sink = (out_sink + stage_v_36 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_36 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r001210_3 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_37 > 35) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001210_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_39 > 33) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((sec_r001210_2 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_40 > 39) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((sec_r001210_9 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_41 > 27) {
        out_sink = (out_sink + stage_v_41 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_41 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_42 > 23) {
        out_sink = (out_sink + stage_v_42 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_42 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_43 > 24) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_44 > 48) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((stage_v_4 ^ 0x2A) * 2 + pub_r001210_13) & 127;
    if (stage_v_45 > 34) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((sec_r001210_6 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_46 > 39) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((sec_r001210_7 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_47 > 36) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((stage_v_23 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_48 > 27) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001210_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_50 > 25) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001210_1 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_52 > 23) {
        out_sink = (out_sink + stage_v_52 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_52 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001210_14 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001210_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_55 > 26) {
        out_sink = (out_sink + stage_v_55 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_55 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_36 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_56 > 40) {
        out_sink = (out_sink + stage_v_56 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_56 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_57 > 30) {
        out_sink = (out_sink + stage_v_57 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_57 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_58 > 26) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_59 > 46) {
        out_sink = (out_sink + stage_v_59 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_59 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_60 > 22) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001210_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_62 > 37) {
        out_sink = (out_sink + stage_v_62 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_62 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_63 > 49) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001210_4 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r001210_15 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_65 > 21) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (pub_r001210_20 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_66) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001210_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_68 > 34) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_69 > 36) {
        out_sink = (out_sink + stage_v_69 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_69 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001210_13) & 127;
    if (stage_v_70 > 23) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_71 > 28) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001210_2 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001210_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((stage_v_57 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_74 > 44) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_75 > 37) {
        out_sink = (out_sink + stage_v_75 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_75 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((helper_flow_7 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_76 > 36) {
        out_sink = (out_sink + stage_v_76 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_76 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_42 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_77 > 26) {
        out_sink = (out_sink + stage_v_77 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_77 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((helper_flow_4 ^ 0x2A) * 2 + pub_r001210_15) & 127;
    if (stage_v_78 > 23) {
        out_sink = (out_sink + stage_v_78 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_78 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((sec_r001210_5 ^ 0x2A) * 2 + pub_r001210_8) & 127;
    if (stage_v_79 > 49) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (pub_r001210_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_80) & 127;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_81 > 39) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_9 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_82 > 44) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_83 > 32) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001210_15) & 127;
    if (stage_v_84 > 26) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r001210_1 ^ 0x2A) * 2 + pub_r001210_8) & 127;
    if (stage_v_85 > 32) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((sec_r001210_1 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_86 > 49) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001210_9 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_88 > 39) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((sec_r001210_9 ^ 0x2A) * 2 + pub_r001210_13) & 127;
    if (stage_v_89 > 34) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001210_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_91 > 26) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001210_3 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_93 > 21) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_94 > 46) {
        out_sink = (out_sink + stage_v_94 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_94 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_95 > 43) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((sec_r001210_6 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_96 > 28) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001210_13 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001210_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r001210_3 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_99 > 21) {
        out_sink = (out_sink + stage_v_99 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_99 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_56 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_100 > 29) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_6 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_101 > 26) {
        out_sink = (out_sink + stage_v_101 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_101 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001210_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001210_21 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001210_12 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r001210_5 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_105 > 37) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_106 > 38) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001210_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_76 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_108 > 28) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001210_16 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001210_6 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_16 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_111 > 24) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_48 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_112 > 49) {
        out_sink = (out_sink + stage_v_112 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_112 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_113 > 50) {
        out_sink = (out_sink + stage_v_113 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_113 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001210_16 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_115 > 46) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001210_12 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_115 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_117 > 23) {
        out_sink = (out_sink + stage_v_117 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_117 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_74 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_118 > 27) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((sec_r001210_5 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_119 > 47) {
        out_sink = (out_sink + stage_v_119 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_119 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_120 > 37) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_43 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_121 > 43) {
        out_sink = (out_sink + stage_v_121 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_121 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((stage_v_2 ^ 0x2A) * 2 + pub_r001210_8) & 127;
    if (stage_v_122 > 23) {
        out_sink = (out_sink + stage_v_122 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_122 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001210_1 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_124 > 31) {
        out_sink = (out_sink + stage_v_124 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_124 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001210_2 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r001210_5 ^ 0x2A) * 2 + pub_r001210_15) & 127;
    if (stage_v_126 > 22) {
        out_sink = (out_sink + stage_v_126 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_126 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_39 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_127 > 32) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_128 > 47) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_0 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_129 > 28) {
        out_sink = (out_sink + stage_v_129 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_129 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_130 > 30) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001210_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_132 > 49) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((sec_r001210_4 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_133 > 26) {
        out_sink = (out_sink + stage_v_133 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_133 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_15 ^ 0x2A) * 2 + pub_r001210_13) & 127;
    if (stage_v_134 > 39) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_46 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_135 > 43) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001210_11 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_68 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_137 > 24) {
        out_sink = (out_sink + stage_v_137 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_137 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_138 > 22) {
        out_sink = (out_sink + stage_v_138 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_138 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((sec_r001210_14 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_139 > 30) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r001210_15 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_140 > 27) {
        out_sink = (out_sink + stage_v_140 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_140 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001210_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_142 > 23) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_50 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_143 > 45) {
        out_sink = (out_sink + stage_v_143 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_143 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_144 > 44) {
        out_sink = (out_sink + stage_v_144 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_144 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_122 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_145 > 34) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_146 > 27) {
        out_sink = (out_sink + stage_v_146 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_146 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_99 ^ 0x2A) * 2 + pub_r001210_15) & 127;
    if (stage_v_147 > 44) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_148 > 38) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((helper_flow_0 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_149 > 26) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_11 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_150 > 37) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((stage_v_24 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_151 > 34) {
        out_sink = (out_sink + stage_v_151 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_151 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_152 > 23) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001210_15 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001210_4 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_134 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_155 > 28) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_156 > 42) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_41 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_157 > 40) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_158 > 36) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001210_12 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001210_14 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r001210_10 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_161 > 36) {
        out_sink = (out_sink + stage_v_161 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_161 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001210_1 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_163 > 36) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_164 > 21) {
        out_sink = (out_sink + stage_v_164 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_164 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_6 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_165 > 33) {
        out_sink = (out_sink + stage_v_165 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_165 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001210_8) & 127;
    if (stage_v_166 > 49) {
        out_sink = (out_sink + stage_v_166 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_166 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_35 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_167 > 24) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001210_2 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_169 > 34) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001210_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_171 > 23) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r001210_9 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_172 > 40) {
        out_sink = (out_sink + stage_v_172 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_172 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_91 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_173 > 21) {
        out_sink = (out_sink + stage_v_173 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_173 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001210_13 ^ 0x2A) * 2 + pub_r001210_8) & 127;
    if (stage_v_174 > 40) {
        out_sink = (out_sink + stage_v_174 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_174 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_47 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_175 > 34) {
        out_sink = (out_sink + stage_v_175 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_175 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_165 ^ 0x2A) * 2 + pub_r001210_13) & 127;
    if (stage_v_176 > 41) {
        out_sink = (out_sink + stage_v_176 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_176 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_58 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_177 > 22) {
        out_sink = (out_sink + stage_v_177 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_177 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_14 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_178 > 27) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_173 ^ 0x2A) * 2 + pub_r001210_18) & 127;
    if (stage_v_179 > 24) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r001210_13 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_180 > 45) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_143 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_181 > 34) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_182 > 32) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((helper_flow_8 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_183 > 31) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_184 > 26) {
        out_sink = (out_sink + stage_v_184 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_184 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_37 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_185 > 50) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((stage_v_12 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_186 > 28) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_30 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_187 > 39) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_179 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_188 > 21) {
        out_sink = (out_sink + stage_v_188 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_188 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001210_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001210_9 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_89 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_191 > 30) {
        out_sink = (out_sink + stage_v_191 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_191 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001210_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001210_7 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001210_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001210_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_196 > 30) {
        out_sink = (out_sink + stage_v_196 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_196 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_197 > 43) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_198 > 36) {
        out_sink = (out_sink + stage_v_198 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_198 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_130 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_199 > 38) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_200 > 44) {
        out_sink = (out_sink + stage_v_200 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_200 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_201 > 37) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_202 > 29) {
        out_sink = (out_sink + stage_v_202 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_202 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_78 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_203 > 40) {
        out_sink = (out_sink + stage_v_203 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_203 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001210_5 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_81 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_205 > 28) {
        out_sink = (out_sink + stage_v_205 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_205 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001210_14 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_112 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_207 > 22) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_118 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_208 > 48) {
        out_sink = (out_sink + stage_v_208 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_208 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((stage_v_171 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_209 > 35) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001210_13 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_88 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_211 > 41) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001210_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001210_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_214 > 48) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_29 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_215 > 47) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (pub_r001210_16 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_216) & 127;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_31 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_217 > 46) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (pub_r001210_3 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_218) & 127;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_77 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_219 > 31) {
        out_sink = (out_sink + stage_v_219 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_219 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_126 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_220 > 22) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_20 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_221 > 44) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r001210_3 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_222 > 32) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((sec_r001210_1 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_223 > 50) {
        out_sink = (out_sink + stage_v_223 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_223 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_224 > 27) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_164 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_225 > 47) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_83 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_226 > 35) {
        out_sink = (out_sink + stage_v_226 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_226 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001210_19 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_228 > 37) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_209 ^ 0x2A) * 2 + pub_r001210_15) & 127;
    if (stage_v_229 > 26) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((stage_v_157 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_230 > 34) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001210_18 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001210_16 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_105 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_233 > 36) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_65 ^ 0x2A) * 2 + pub_r001210_14) & 127;
    if (stage_v_234 > 37) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_215 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_235 > 29) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (pub_r001210_11 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_236) & 127;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_63 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_237 > 20) {
        out_sink = (out_sink + stage_v_237 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_237 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_183 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_238 > 24) {
        out_sink = (out_sink + stage_v_238 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_238 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_85 ^ 0x2A) * 2 + pub_r001210_1) & 127;
    if (stage_v_239 > 46) {
        out_sink = (out_sink + stage_v_239 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_239 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_120 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_240 > 23) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r001210_10 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_241 > 32) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_155 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_242 > 39) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_169 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_243 > 46) {
        out_sink = (out_sink + stage_v_243 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_243 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_119 ^ 0x2A) * 2 + pub_r001210_3) & 127;
    if (stage_v_244 > 33) {
        out_sink = (out_sink + stage_v_244 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_244 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_245 > 20) {
        out_sink = (out_sink + stage_v_245 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_245 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_101 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_246 > 41) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001210_0) & 127;
    if (stage_v_247 > 33) {
        out_sink = (out_sink + stage_v_247 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_247 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_203 ^ 0x2A) * 2 + pub_r001210_19) & 127;
    if (stage_v_248 > 40) {
        out_sink = (out_sink + stage_v_248 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_248 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001210_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001210_20 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_27 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_251 > 28) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_224 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_252 > 42) {
        out_sink = (out_sink + stage_v_252 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_252 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_180 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_253 > 33) {
        out_sink = (out_sink + stage_v_253 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_253 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_13 ^ 0x2A) * 2 + pub_r001210_12) & 127;
    if (stage_v_254 > 43) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_185 ^ 0x2A) * 2 + pub_r001210_11) & 127;
    if (stage_v_255 > 31) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001210_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((stage_v_207 ^ 0x2A) * 2 + pub_r001210_9) & 127;
    if (stage_v_257 > 35) {
        out_sink = (out_sink + stage_v_257 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_257 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_25 ^ 0x2A) * 2 + pub_r001210_16) & 127;
    if (stage_v_258 > 46) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_219 ^ 0x2A) * 2 + pub_r001210_17) & 127;
    if (stage_v_259 > 26) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((stage_v_40 ^ 0x2A) * 2 + pub_r001210_13) & 127;
    if (stage_v_260 > 23) {
        out_sink = (out_sink + stage_v_260 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_260 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001210_7) & 127;
    if (stage_v_261 > 28) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_19 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_262 > 31) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001210_21) & 127;
    if (stage_v_263 > 38) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((stage_v_176 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_264 > 31) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001210_8 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_132 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_266 > 22) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_142 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_267 > 34) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001210_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001210_16 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_198 ^ 0x2A) * 2 + pub_r001210_2) & 127;
    if (stage_v_270 > 47) {
        out_sink = (out_sink + stage_v_270 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_270 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_7 ^ 0x2A) * 2 + pub_r001210_5) & 127;
    if (stage_v_271 > 38) {
        out_sink = (out_sink + stage_v_271 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_271 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = (pub_r001210_2 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_272) & 127;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_191 ^ 0x2A) * 2 + pub_r001210_10) & 127;
    if (stage_v_273 > 48) {
        out_sink = (out_sink + stage_v_273 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_273 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((sec_r001210_5 ^ 0x2A) * 2 + pub_r001210_4) & 127;
    if (stage_v_274 > 30) {
        out_sink = (out_sink + stage_v_274 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_274 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_17 ^ 0x2A) * 2 + pub_r001210_20) & 127;
    if (stage_v_275 > 43) {
        out_sink = (out_sink + stage_v_275 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_275 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_32 ^ 0x2A) * 2 + pub_r001210_6) & 127;
    if (stage_v_276 > 24) {
        out_sink = (out_sink + stage_v_276 * 2 + 7) & 255;
    } else {
        out_sink = (out_sink - stage_v_276 + 13) & 255;
    }
    sec_accum = (sec_accum + stage_v_276) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
