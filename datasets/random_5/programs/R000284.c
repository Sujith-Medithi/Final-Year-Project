/*
 * Benchmark Program: R000284
 * Security Family: arithmetic_flow
 * Generator Seed: 528413
 * High Inputs: 23 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000284_8413_0 {
    int mode;
    int cutoff;
    short prev_in;
    short prev_out;
    short gain_db;
    int damping;
    int buffer[3];
};

struct EventLog_R000284_8413_1 {
    int seq;
    int facility;
    int code;
    int buffer[3];
};

struct AudioFrame_R000284_8413_2 {
    unsigned char envelope;
    int peak;
    int sample_rate;
    int buffer[3];
};

struct Vector3D_R000284_8413_3 {
    unsigned char coord_z;
    int coord_x;
    unsigned char heading;
    int coord_y;
    short norm_sq;
    int pitch;
    int buffer[3];
};

union ColorPixel_R000284_8413_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000284_8413_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000284_8413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_85 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_85) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000284_8413_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000284_8413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int anchor_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_25) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int parity_73 = local_arr[aux % 3];
    acc = (acc + parity_73 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000284_8413_2(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000284_8413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_45 = local_arr[aux % 3];
    acc = (acc + tracker_45 * 2) & 127;
    int index_reg_68 = (aux + st.buffer[1]) & 3;
    switch (index_reg_68) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quotient_82 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_82 > 23) {
        acc = (acc + quotient_82 * 2 + 5) & 127;
        aux ^= (quotient_82 & 15);
    } else {
        acc = (acc - quotient_82 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000284_8413_3(int p0, int p1) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000284_8413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int scale_83 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_83 > 18) {
        acc = (acc + scale_83 * 2 + 5) & 127;
        aux ^= (scale_83 & 15);
    } else {
        acc = (acc - scale_83 + 11) & 127;
        aux += 3;
    }
    int tally_41 = (aux + st.buffer[1]) & 3;
    switch (tally_41) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_37 = local_arr[aux % 3];
    acc = (acc + residue_37 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000284_8413_4(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000284_8413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int weight_77 = (aux + st.buffer[1]) & 3;
    switch (weight_77) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000284_8413_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000284_8413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quotient_78 = (aux + st.buffer[1]) & 3;
    switch (quotient_78) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_32 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_32) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000284_8413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_79 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_79) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000284_8413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int index_reg_72 = local_arr[aux % 3];
    acc = (acc + index_reg_72 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_44 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_44 > 31) {
        acc = (acc + margin_44 * 2 + 5) & 127;
        aux ^= (margin_44 & 15);
    } else {
        acc = (acc - margin_44 + 11) & 127;
        aux += 3;
    }
    int accumulator_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000284_8413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int index_reg_11 = (aux + st.buffer[1]) & 3;
    switch (index_reg_11) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_89) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_9(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000284_8413_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int residue_27 = local_arr[aux % 3];
    acc = (acc + residue_27 * 2) & 127;
    int damping_78 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_78 > 37) {
        acc = (acc + damping_78 * 2 + 5) & 127;
        aux ^= (damping_78 & 15);
    } else {
        acc = (acc - damping_78 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_12) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_10(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000284_8413_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_96) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_11(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000284_8413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_14 = (aux + st.buffer[1]) & 3;
    switch (factor_14) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_85 = local_arr[aux % 3];
    acc = (acc + parity_85 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_74) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_12(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000284_8413_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_88 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_88) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000284_8413_13(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000284_8413_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_71 = (aux + st.buffer[1]) & 3;
    switch (coefficient_71) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_12 = local_arr[aux % 3];
    acc = (acc + parity_12 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000284_0;
    int sec_r000284_1;
    int sec_r000284_2;
    int sec_r000284_3;
    int sec_r000284_4;
    int sec_r000284_5;
    int sec_r000284_6;
    int sec_r000284_7;
    int sec_r000284_8;
    int sec_r000284_9;
    int sec_r000284_10;
    int sec_r000284_11;
    int sec_r000284_12;
    int sec_r000284_13;
    int sec_r000284_14;
    int sec_r000284_15;
    int sec_r000284_16;
    int sec_r000284_17;
    int sec_r000284_18;
    int sec_r000284_19;
    int sec_r000284_20;
    int sec_r000284_21;
    int sec_r000284_22;
    int pub_r000284_0;
    int pub_r000284_1;
    int pub_r000284_2;
    int pub_r000284_3;
    int pub_r000284_4;
    int pub_r000284_5;
    int pub_r000284_6;
    int pub_r000284_7;
    int pub_r000284_8;
    int pub_r000284_9;
    int pub_r000284_10;
    int pub_r000284_11;
    int pub_r000284_12;
    int pub_r000284_13;
    int pub_r000284_14;
    int pub_r000284_15;
    int pub_r000284_16;
    int pub_r000284_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000284_0 >= -100 && pub_r000284_0 <= 100);
    __CPROVER_assume(pub_r000284_1 >= -100 && pub_r000284_1 <= 100);
    __CPROVER_assume(pub_r000284_2 >= -100 && pub_r000284_2 <= 100);
    __CPROVER_assume(pub_r000284_3 >= -100 && pub_r000284_3 <= 100);
    __CPROVER_assume(pub_r000284_4 >= -100 && pub_r000284_4 <= 100);
    __CPROVER_assume(pub_r000284_5 >= -100 && pub_r000284_5 <= 100);
    __CPROVER_assume(pub_r000284_6 >= -100 && pub_r000284_6 <= 100);
    __CPROVER_assume(pub_r000284_7 >= -100 && pub_r000284_7 <= 100);
    __CPROVER_assume(pub_r000284_8 >= -100 && pub_r000284_8 <= 100);
    __CPROVER_assume(pub_r000284_9 >= -100 && pub_r000284_9 <= 100);
    __CPROVER_assume(pub_r000284_10 >= -100 && pub_r000284_10 <= 100);
    __CPROVER_assume(pub_r000284_11 >= -100 && pub_r000284_11 <= 100);
    __CPROVER_assume(pub_r000284_12 >= -100 && pub_r000284_12 <= 100);
    __CPROVER_assume(pub_r000284_13 >= -100 && pub_r000284_13 <= 100);
    __CPROVER_assume(pub_r000284_14 >= -100 && pub_r000284_14 <= 100);
    __CPROVER_assume(pub_r000284_15 >= -100 && pub_r000284_15 <= 100);
    __CPROVER_assume(pub_r000284_16 >= -100 && pub_r000284_16 <= 100);
    __CPROVER_assume(pub_r000284_17 >= -100 && pub_r000284_17 <= 100);
    __CPROVER_assume(sec_r000284_0 >= 0 && sec_r000284_0 <= 255);
    __CPROVER_assume(sec_r000284_1 >= 0 && sec_r000284_1 <= 255);
    __CPROVER_assume(sec_r000284_2 >= 0 && sec_r000284_2 <= 255);
    __CPROVER_assume(sec_r000284_3 >= 0 && sec_r000284_3 <= 255);
    __CPROVER_assume(sec_r000284_4 >= 0 && sec_r000284_4 <= 255);
    __CPROVER_assume(sec_r000284_5 >= 0 && sec_r000284_5 <= 255);
    __CPROVER_assume(sec_r000284_6 >= 0 && sec_r000284_6 <= 255);
    __CPROVER_assume(sec_r000284_7 >= 0 && sec_r000284_7 <= 255);
    __CPROVER_assume(sec_r000284_8 >= 0 && sec_r000284_8 <= 255);
    __CPROVER_assume(sec_r000284_9 >= 0 && sec_r000284_9 <= 255);
    __CPROVER_assume(sec_r000284_10 >= 0 && sec_r000284_10 <= 255);
    __CPROVER_assume(sec_r000284_11 >= 0 && sec_r000284_11 <= 255);
    __CPROVER_assume(sec_r000284_12 >= 0 && sec_r000284_12 <= 255);
    __CPROVER_assume(sec_r000284_13 >= 0 && sec_r000284_13 <= 255);
    __CPROVER_assume(sec_r000284_14 >= 0 && sec_r000284_14 <= 255);
    __CPROVER_assume(sec_r000284_15 >= 0 && sec_r000284_15 <= 255);
    __CPROVER_assume(sec_r000284_16 >= 0 && sec_r000284_16 <= 255);
    __CPROVER_assume(sec_r000284_17 >= 0 && sec_r000284_17 <= 255);
    __CPROVER_assume(sec_r000284_18 >= 0 && sec_r000284_18 <= 255);
    __CPROVER_assume(sec_r000284_19 >= 0 && sec_r000284_19 <= 255);
    __CPROVER_assume(sec_r000284_20 >= 0 && sec_r000284_20 <= 255);
    __CPROVER_assume(sec_r000284_21 >= 0 && sec_r000284_21 <= 255);
    __CPROVER_assume(sec_r000284_22 >= 0 && sec_r000284_22 <= 255);

    struct FilterState_R000284_8413_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000284_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000284_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000284_0 + 7) & 15;
    struct EventLog_R000284_8413_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000284_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000284_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000284_0 + 9) & 15;
    struct AudioFrame_R000284_8413_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000284_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000284_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000284_0 + 11) & 15;
    struct Vector3D_R000284_8413_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000284_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000284_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000284_0 + 13) & 15;

    union ColorPixel_R000284_8413_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

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
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] * 2 + 43) & 63;
    if (stage_v_12 > 29) {
        out_sink = (out_sink + stage_v_12 - 5) & 255;
        if (stage_v_12 > 44) {
            chk_sum ^= (stage_v_12 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_12 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_15 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 16 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 18) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 33) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 21) & 15;
    int stage_v_20 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_20) & 255;
    chk_sum ^= stage_v_20;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[0] ^ 31) & 3;
    switch (stage_v_28) {
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

    /* Execution Pipeline Stage 29 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (out_sink > 100) ? (chk_sum & 31) : (37 & 31);
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= (stage_v_32 << 1) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 27) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 42) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_2.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 18) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 33) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[1] * 2 + 127) & 63;
    if (stage_v_40 > 22) {
        out_sink = (out_sink + stage_v_40 - 5) & 255;
        if (stage_v_40 > 37) {
            chk_sum ^= (stage_v_40 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_40 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_0.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 33) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 48) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_1.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 47) & 15;
    int stage_v_46 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= stage_v_46;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = table[3];
    table[3] = (table[0] + 103) & 63;
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 53) & 15;
    int stage_v_52 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= stage_v_52;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 22) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 37) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (out_sink > 100) ? (chk_sum & 31) : (63 & 31);
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= (stage_v_58 << 1) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_63 = (stage_v_63 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_63) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_65 = (stage_v_65 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_65) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_2.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 20) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 35) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] ^ 72) & 3;
    switch (stage_v_69) {
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

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_2.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 13) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 28) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_3.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 31) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 46) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = table[1];
    table[1] = (table[2] + 147) & 63;
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 75) & 15;
    int stage_v_74 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= stage_v_74;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_3.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 28) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 43) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_2.buffer[0] ^ 81) & 3;
    switch (stage_v_78) {
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

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (out_sink > 100) ? (chk_sum & 31) : (85 & 31);
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= (stage_v_80 << 1) & 127;

    /* Execution Pipeline Stage 81 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 82) & 15;
    int stage_v_81 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= stage_v_81;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_3.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 37) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 52) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((sec_r000284_15 * 3) + (sec_r000284_15 * 2) - pub_r000284_0 + 31) & 127;
    sec_accum = (sec_accum + stage_v_84 * 2) & 255;
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((stage_v_84 * 3) + (sec_r000284_21 * 2) - pub_r000284_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_85 * 3) + (sec_r000284_21 * 2) - pub_r000284_17 + 32) & 127;
    sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_85 * 3) + (sec_r000284_18 * 2) - pub_r000284_12 + 33) & 127;
    sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((sec_r000284_18 * 3) + (sec_r000284_18 * 2) - pub_r000284_10 + 13) & 127;
    sec_accum = (sec_accum + stage_v_88 * 2) & 255;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_86 * 3) + (sec_r000284_12 * 2) - pub_r000284_15 + 23) & 127;
    sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_89 * 3) + (sec_r000284_13 * 2) - pub_r000284_2 + 5) & 127;
    sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((sec_r000284_4 * 3) + (sec_r000284_4 * 2) - pub_r000284_17 + 10) & 127;
    sec_accum = (sec_accum + stage_v_91 * 2) & 255;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((stage_v_89 * 3) + (sec_r000284_1 * 2) - pub_r000284_0 + 25) & 127;
    sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_92 * 3) + (sec_r000284_7 * 2) - pub_r000284_17 + 6) & 127;
    sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((sec_r000284_4 * 3) + (sec_r000284_4 * 2) - pub_r000284_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_88 * 3) + (sec_r000284_20 * 2) - pub_r000284_1 + 4) & 127;
    sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_94 * 3) + (sec_r000284_6 * 2) - pub_r000284_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_91 * 3) + (sec_r000284_1 * 2) - pub_r000284_11 + 28) & 127;
    sec_accum = (sec_accum + stage_v_97 * 2) & 255;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((stage_v_93 * 3) + (sec_r000284_16 * 2) - pub_r000284_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_0 + 29) & 127;
    sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((stage_v_90 * 3) + (sec_r000284_8 * 2) - pub_r000284_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_88 * 3) + (sec_r000284_6 * 2) - pub_r000284_4 + 15) & 127;
    sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_88 * 3) + (sec_r000284_9 * 2) - pub_r000284_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_102 * 2) & 255;
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_84 * 3) + (sec_r000284_22 * 2) - pub_r000284_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r000284_10 * 3) + (sec_r000284_10 * 2) - pub_r000284_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((sec_r000284_6 * 3) + (sec_r000284_6 * 2) - pub_r000284_9 + 23) & 127;
    sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((sec_r000284_0 * 3) + (sec_r000284_0 * 2) - pub_r000284_9 + 37) & 127;
    sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_87 * 3) + (sec_r000284_3 * 2) - pub_r000284_8 + 27) & 127;
    sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_85 * 3) + (sec_r000284_7 * 2) - pub_r000284_0 + 15) & 127;
    sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    out_sink = (out_sink + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_103 * 3) + (sec_r000284_14 * 2) - pub_r000284_16 + 12) & 127;
    sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_109 * 3) + (sec_r000284_13 * 2) - pub_r000284_15 + 29) & 127;
    sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000284_12 * 3) + (sec_r000284_12 * 2) - pub_r000284_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_91 * 3) + (sec_r000284_16 * 2) - pub_r000284_4 + 3) & 127;
    sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r000284_1 * 3) + (sec_r000284_1 * 2) - pub_r000284_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((stage_v_84 * 3) + (sec_r000284_12 * 2) - pub_r000284_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_112 * 3) + (sec_r000284_17 * 2) - pub_r000284_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_88 * 3) + (sec_r000284_10 * 2) - pub_r000284_8 + 18) & 127;
    sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_94 * 3) + (sec_r000284_6 * 2) - pub_r000284_10 + 36) & 127;
    sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((sec_r000284_10 * 3) + (sec_r000284_10 * 2) - pub_r000284_8 + 21) & 127;
    sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_102 * 3) + (sec_r000284_21 * 2) - pub_r000284_17 + 18) & 127;
    sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_113 * 3) + (sec_r000284_1 * 2) - pub_r000284_11 + 30) & 127;
    sec_accum = (sec_accum + stage_v_120 * 2) & 255;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000284_12 * 3) + (sec_r000284_12 * 2) - pub_r000284_4 + 23) & 127;
    sec_accum = (sec_accum + stage_v_122 * 2) & 255;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_110 * 3) + (sec_r000284_14 * 2) - pub_r000284_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_109 * 3) + (sec_r000284_17 * 2) - pub_r000284_14 + 27) & 127;
    sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((sec_r000284_20 * 3) + (sec_r000284_20 * 2) - pub_r000284_14 + 31) & 127;
    sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((sec_r000284_15 * 3) + (sec_r000284_15 * 2) - pub_r000284_8 + 10) & 127;
    sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_126 * 3) + (sec_r000284_3 * 2) - pub_r000284_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_127 * 2) & 255;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((sec_r000284_17 * 3) + (sec_r000284_17 * 2) - pub_r000284_1 + 13) & 127;
    sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((stage_v_107 * 3) + (sec_r000284_9 * 2) - pub_r000284_17 + 11) & 127;
    sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_97 * 3) + (sec_r000284_22 * 2) - pub_r000284_3 + 7) & 127;
    sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((stage_v_100 * 3) + (sec_r000284_6 * 2) - pub_r000284_13 + 7) & 127;
    sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((sec_r000284_13 * 3) + (sec_r000284_13 * 2) - pub_r000284_16 + 8) & 127;
    sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_117 * 3) + (sec_r000284_22 * 2) - pub_r000284_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    out_sink = (out_sink + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000284_21 * 3) + (sec_r000284_21 * 2) - pub_r000284_15 + 30) & 127;
    sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    out_sink = (out_sink + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((stage_v_119 * 3) + (sec_r000284_19 * 2) - pub_r000284_0 + 23) & 127;
    sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_94 * 3) + (sec_r000284_9 * 2) - pub_r000284_11 + 23) & 127;
    sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_113 * 3) + (sec_r000284_9 * 2) - pub_r000284_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_116 * 3) + (sec_r000284_8 * 2) - pub_r000284_3 + 9) & 127;
    sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_133 * 3) + (sec_r000284_15 * 2) - pub_r000284_17 + 15) & 127;
    sec_accum = (sec_accum + stage_v_139 * 2) & 255;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000284_20 * 3) + (sec_r000284_20 * 2) - pub_r000284_5 + 14) & 127;
    sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((stage_v_134 * 3) + (sec_r000284_12 * 2) - pub_r000284_12 + 11) & 127;
    sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    out_sink = (out_sink + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_135 * 3) + (sec_r000284_14 * 2) - pub_r000284_17 + 10) & 127;
    sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_120 * 3) + (sec_r000284_19 * 2) - pub_r000284_16 + 6) & 127;
    sec_accum = (sec_accum + stage_v_143 * 2) & 255;
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((sec_r000284_14 * 3) + (sec_r000284_14 * 2) - pub_r000284_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_144 * 2) & 255;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_141 * 3) + (sec_r000284_1 * 2) - pub_r000284_3 + 37) & 127;
    sec_accum = (sec_accum + stage_v_145 * 2) & 255;
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000284_16 * 3) + (sec_r000284_16 * 2) - pub_r000284_6 + 3) & 127;
    sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((stage_v_126 * 3) + (sec_r000284_22 * 2) - pub_r000284_16 + 8) & 127;
    sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((sec_r000284_5 * 3) + (sec_r000284_5 * 2) - pub_r000284_16 + 25) & 127;
    sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_131 * 3) + (sec_r000284_11 * 2) - pub_r000284_17 + 3) & 127;
    sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_13 + 26) & 127;
    sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000284_10 * 3) + (sec_r000284_10 * 2) - pub_r000284_12 + 10) & 127;
    sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_146 * 3) + (sec_r000284_21 * 2) - pub_r000284_6 + 32) & 127;
    sec_accum = (sec_accum + stage_v_152 * 2) & 255;
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_102 * 3) + (sec_r000284_19 * 2) - pub_r000284_3 + 35) & 127;
    sec_accum = (sec_accum + stage_v_153 * 2) & 255;
    out_sink = (out_sink + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_91 * 3) + (sec_r000284_0 * 2) - pub_r000284_14 + 14) & 127;
    sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((sec_r000284_9 * 3) + (sec_r000284_9 * 2) - pub_r000284_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_146 * 3) + (sec_r000284_22 * 2) - pub_r000284_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((stage_v_85 * 3) + (sec_r000284_4 * 2) - pub_r000284_11 + 6) & 127;
    sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_125 * 3) + (sec_r000284_22 * 2) - pub_r000284_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000284_22 * 3) + (sec_r000284_22 * 2) - pub_r000284_9 + 19) & 127;
    sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_136 * 3) + (sec_r000284_5 * 2) - pub_r000284_8 + 22) & 127;
    sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_103 * 3) + (sec_r000284_8 * 2) - pub_r000284_17 + 14) & 127;
    sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r000284_12 * 3) + (sec_r000284_12 * 2) - pub_r000284_13 + 4) & 127;
    sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_150 * 3) + (sec_r000284_3 * 2) - pub_r000284_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_163 * 2) & 255;
    out_sink = (out_sink + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_3 + 24) & 127;
    sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_17 + 12) & 127;
    sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((sec_r000284_1 * 3) + (sec_r000284_1 * 2) - pub_r000284_7 + 4) & 127;
    sec_accum = (sec_accum + stage_v_166 * 2) & 255;
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_89 * 3) + (sec_r000284_10 * 2) - pub_r000284_15 + 16) & 127;
    sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000284_4 * 3) + (sec_r000284_4 * 2) - pub_r000284_3 + 14) & 127;
    sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((sec_r000284_6 * 3) + (sec_r000284_6 * 2) - pub_r000284_5 + 8) & 127;
    sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_91 * 3) + (sec_r000284_10 * 2) - pub_r000284_7 + 13) & 127;
    sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_117 * 3) + (sec_r000284_9 * 2) - pub_r000284_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000284_20 * 3) + (sec_r000284_20 * 2) - pub_r000284_17 + 26) & 127;
    sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_89 * 3) + (sec_r000284_8 * 2) - pub_r000284_8 + 5) & 127;
    sec_accum = (sec_accum + stage_v_173 * 2) & 255;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((stage_v_86 * 3) + (sec_r000284_1 * 2) - pub_r000284_3 + 22) & 127;
    sec_accum = (sec_accum + stage_v_174 * 2) & 255;
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((sec_r000284_21 * 3) + (sec_r000284_21 * 2) - pub_r000284_11 + 36) & 127;
    sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_120 * 3) + (sec_r000284_8 * 2) - pub_r000284_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_176 * 2) & 255;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000284_1 * 3) + (sec_r000284_1 * 2) - pub_r000284_6 + 15) & 127;
    sec_accum = (sec_accum + stage_v_177 * 2) & 255;
    out_sink = (out_sink + stage_v_177) & 255;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r000284_15 * 3) + (sec_r000284_15 * 2) - pub_r000284_4 + 22) & 127;
    sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r000284_7 * 3) + (sec_r000284_7 * 2) - pub_r000284_11 + 25) & 127;
    sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    out_sink = (out_sink + stage_v_179) & 255;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_2 + 12) & 127;
    sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_164 * 3) + (sec_r000284_0 * 2) - pub_r000284_14 + 33) & 127;
    sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000284_16 * 3) + (sec_r000284_16 * 2) - pub_r000284_5 + 29) & 127;
    sec_accum = (sec_accum + stage_v_182 * 2) & 255;
    out_sink = (out_sink + stage_v_182) & 255;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_10 + 5) & 127;
    sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r000284_16 * 3) + (sec_r000284_16 * 2) - pub_r000284_7 + 17) & 127;
    sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_135 * 3) + (sec_r000284_14 * 2) - pub_r000284_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_3 + 36) & 127;
    sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((stage_v_132 * 3) + (sec_r000284_5 * 2) - pub_r000284_17 + 6) & 127;
    sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    out_sink = (out_sink + stage_v_187) & 255;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((sec_r000284_9 * 3) + (sec_r000284_9 * 2) - pub_r000284_6 + 27) & 127;
    sec_accum = (sec_accum + stage_v_188 * 2) & 255;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((sec_r000284_8 * 3) + (sec_r000284_8 * 2) - pub_r000284_17 + 27) & 127;
    sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((sec_r000284_7 * 3) + (sec_r000284_7 * 2) - pub_r000284_17 + 21) & 127;
    sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_102 * 3) + (sec_r000284_17 * 2) - pub_r000284_1 + 33) & 127;
    sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    out_sink = (out_sink + stage_v_191) & 255;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_123 * 3) + (sec_r000284_22 * 2) - pub_r000284_7 + 36) & 127;
    sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000284_1 * 3) + (sec_r000284_1 * 2) - pub_r000284_5 + 10) & 127;
    sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_170 * 3) + (sec_r000284_17 * 2) - pub_r000284_5 + 21) & 127;
    sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((stage_v_168 * 3) + (sec_r000284_12 * 2) - pub_r000284_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    out_sink = (out_sink + stage_v_195) & 255;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_0 + 28) & 127;
    sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    out_sink = (out_sink + stage_v_196) & 255;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_5 + 11) & 127;
    sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_138 * 3) + (sec_r000284_7 * 2) - pub_r000284_1 + 9) & 127;
    sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_111 * 3) + (sec_r000284_12 * 2) - pub_r000284_4 + 11) & 127;
    sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    out_sink = (out_sink + stage_v_199) & 255;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_99 * 3) + (sec_r000284_8 * 2) - pub_r000284_8 + 6) & 127;
    sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_93 * 3) + (sec_r000284_20 * 2) - pub_r000284_0 + 24) & 127;
    sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_136 * 3) + (sec_r000284_1 * 2) - pub_r000284_5 + 35) & 127;
    sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    out_sink = (out_sink + stage_v_202) & 255;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_9 + 11) & 127;
    sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_152 * 3) + (sec_r000284_7 * 2) - pub_r000284_3 + 16) & 127;
    sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_137 * 3) + (sec_r000284_6 * 2) - pub_r000284_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_130 * 3) + (sec_r000284_14 * 2) - pub_r000284_7 + 5) & 127;
    sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((stage_v_109 * 3) + (sec_r000284_7 * 2) - pub_r000284_1 + 6) & 127;
    sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((stage_v_91 * 3) + (sec_r000284_8 * 2) - pub_r000284_8 + 4) & 127;
    sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r000284_9 * 3) + (sec_r000284_9 * 2) - pub_r000284_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    out_sink = (out_sink + stage_v_209) & 255;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_179 * 3) + (sec_r000284_4 * 2) - pub_r000284_10 + 15) & 127;
    sec_accum = (sec_accum + stage_v_210 * 2) & 255;
    out_sink = (out_sink + stage_v_210) & 255;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_211 * 2) & 255;
    out_sink = (out_sink + stage_v_211) & 255;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000284_9 * 3) + (sec_r000284_9 * 2) - pub_r000284_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    out_sink = (out_sink + stage_v_212) & 255;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((sec_r000284_14 * 3) + (sec_r000284_14 * 2) - pub_r000284_13 + 33) & 127;
    sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    out_sink = (out_sink + stage_v_213) & 255;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((sec_r000284_20 * 3) + (sec_r000284_20 * 2) - pub_r000284_9 + 36) & 127;
    sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    out_sink = (out_sink + stage_v_214) & 255;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_112 * 3) + (sec_r000284_1 * 2) - pub_r000284_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_119 * 3) + (sec_r000284_18 * 2) - pub_r000284_17 + 4) & 127;
    sec_accum = (sec_accum + stage_v_216 * 2) & 255;
    out_sink = (out_sink + stage_v_216) & 255;

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_193 * 3) + (sec_r000284_19 * 2) - pub_r000284_0 + 17) & 127;
    sec_accum = (sec_accum + stage_v_217 * 2) & 255;
    out_sink = (out_sink + stage_v_217) & 255;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_114 * 3) + (sec_r000284_5 * 2) - pub_r000284_7 + 35) & 127;
    sec_accum = (sec_accum + stage_v_218 * 2) & 255;
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_210 * 3) + (sec_r000284_12 * 2) - pub_r000284_15 + 34) & 127;
    sec_accum = (sec_accum + stage_v_219 * 2) & 255;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_169 * 3) + (sec_r000284_22 * 2) - pub_r000284_6 + 17) & 127;
    sec_accum = (sec_accum + stage_v_220 * 2) & 255;
    out_sink = (out_sink + stage_v_220) & 255;

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_208 * 3) + (sec_r000284_22 * 2) - pub_r000284_12 + 6) & 127;
    sec_accum = (sec_accum + stage_v_221 * 2) & 255;
    out_sink = (out_sink + stage_v_221) & 255;

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((stage_v_219 * 3) + (sec_r000284_3 * 2) - pub_r000284_2 + 14) & 127;
    sec_accum = (sec_accum + stage_v_222 * 2) & 255;
    out_sink = (out_sink + stage_v_222) & 255;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_153 * 3) + (sec_r000284_14 * 2) - pub_r000284_6 + 26) & 127;
    sec_accum = (sec_accum + stage_v_223 * 2) & 255;
    out_sink = (out_sink + stage_v_223) & 255;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_193 * 3) + (sec_r000284_22 * 2) - pub_r000284_8 + 15) & 127;
    sec_accum = (sec_accum + stage_v_224 * 2) & 255;
    out_sink = (out_sink + stage_v_224) & 255;

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_126 * 3) + (sec_r000284_9 * 2) - pub_r000284_16 + 3) & 127;
    sec_accum = (sec_accum + stage_v_225 * 2) & 255;
    out_sink = (out_sink + stage_v_225) & 255;

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((stage_v_170 * 3) + (sec_r000284_3 * 2) - pub_r000284_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_226 * 2) & 255;
    out_sink = (out_sink + stage_v_226) & 255;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_3 + 28) & 127;
    sec_accum = (sec_accum + stage_v_227 * 2) & 255;
    out_sink = (out_sink + stage_v_227) & 255;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r000284_7 * 3) + (sec_r000284_7 * 2) - pub_r000284_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_228 * 2) & 255;
    out_sink = (out_sink + stage_v_228) & 255;

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_229 * 2) & 255;
    out_sink = (out_sink + stage_v_229) & 255;

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000284_3 * 3) + (sec_r000284_3 * 2) - pub_r000284_15 + 6) & 127;
    sec_accum = (sec_accum + stage_v_230 * 2) & 255;
    out_sink = (out_sink + stage_v_230) & 255;

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_90 * 3) + (sec_r000284_5 * 2) - pub_r000284_8 + 33) & 127;
    sec_accum = (sec_accum + stage_v_231 * 2) & 255;
    out_sink = (out_sink + stage_v_231) & 255;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_230 * 3) + (sec_r000284_12 * 2) - pub_r000284_17 + 19) & 127;
    sec_accum = (sec_accum + stage_v_232 * 2) & 255;
    out_sink = (out_sink + stage_v_232) & 255;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000284_22 * 3) + (sec_r000284_22 * 2) - pub_r000284_17 + 20) & 127;
    sec_accum = (sec_accum + stage_v_233 * 2) & 255;
    out_sink = (out_sink + stage_v_233) & 255;

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_159 * 3) + (sec_r000284_9 * 2) - pub_r000284_3 + 15) & 127;
    sec_accum = (sec_accum + stage_v_234 * 2) & 255;
    out_sink = (out_sink + stage_v_234) & 255;

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_85 * 3) + (sec_r000284_4 * 2) - pub_r000284_4 + 9) & 127;
    sec_accum = (sec_accum + stage_v_235 * 2) & 255;
    out_sink = (out_sink + stage_v_235) & 255;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_212 * 3) + (sec_r000284_15 * 2) - pub_r000284_5 + 3) & 127;
    sec_accum = (sec_accum + stage_v_236 * 2) & 255;
    out_sink = (out_sink + stage_v_236) & 255;

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((stage_v_130 * 3) + (sec_r000284_11 * 2) - pub_r000284_6 + 20) & 127;
    sec_accum = (sec_accum + stage_v_237 * 2) & 255;
    out_sink = (out_sink + stage_v_237) & 255;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_177 * 3) + (sec_r000284_1 * 2) - pub_r000284_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_238 * 2) & 255;
    out_sink = (out_sink + stage_v_238) & 255;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_124 * 3) + (sec_r000284_12 * 2) - pub_r000284_3 + 32) & 127;
    sec_accum = (sec_accum + stage_v_239 * 2) & 255;
    out_sink = (out_sink + stage_v_239) & 255;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_7 + 6) & 127;
    sec_accum = (sec_accum + stage_v_240 * 2) & 255;
    out_sink = (out_sink + stage_v_240) & 255;

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_137 * 3) + (sec_r000284_0 * 2) - pub_r000284_13 + 37) & 127;
    sec_accum = (sec_accum + stage_v_241 * 2) & 255;
    out_sink = (out_sink + stage_v_241) & 255;

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((sec_r000284_4 * 3) + (sec_r000284_4 * 2) - pub_r000284_13 + 8) & 127;
    sec_accum = (sec_accum + stage_v_242 * 2) & 255;
    out_sink = (out_sink + stage_v_242) & 255;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((sec_r000284_8 * 3) + (sec_r000284_8 * 2) - pub_r000284_15 + 26) & 127;
    sec_accum = (sec_accum + stage_v_243 * 2) & 255;
    out_sink = (out_sink + stage_v_243) & 255;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((stage_v_210 * 3) + (sec_r000284_17 * 2) - pub_r000284_12 + 24) & 127;
    sec_accum = (sec_accum + stage_v_244 * 2) & 255;
    out_sink = (out_sink + stage_v_244) & 255;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((sec_r000284_22 * 3) + (sec_r000284_22 * 2) - pub_r000284_12 + 29) & 127;
    sec_accum = (sec_accum + stage_v_245 * 2) & 255;
    out_sink = (out_sink + stage_v_245) & 255;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_218 * 3) + (sec_r000284_15 * 2) - pub_r000284_16 + 16) & 127;
    sec_accum = (sec_accum + stage_v_246 * 2) & 255;
    out_sink = (out_sink + stage_v_246) & 255;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_8 + 30) & 127;
    sec_accum = (sec_accum + stage_v_247 * 2) & 255;
    out_sink = (out_sink + stage_v_247) & 255;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((sec_r000284_13 * 3) + (sec_r000284_13 * 2) - pub_r000284_1 + 22) & 127;
    sec_accum = (sec_accum + stage_v_248 * 2) & 255;
    out_sink = (out_sink + stage_v_248) & 255;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((sec_r000284_6 * 3) + (sec_r000284_6 * 2) - pub_r000284_16 + 27) & 127;
    sec_accum = (sec_accum + stage_v_249 * 2) & 255;
    out_sink = (out_sink + stage_v_249) & 255;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_110 * 3) + (sec_r000284_20 * 2) - pub_r000284_1 + 5) & 127;
    sec_accum = (sec_accum + stage_v_250 * 2) & 255;
    out_sink = (out_sink + stage_v_250) & 255;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((sec_r000284_22 * 3) + (sec_r000284_22 * 2) - pub_r000284_13 + 16) & 127;
    sec_accum = (sec_accum + stage_v_251 * 2) & 255;
    out_sink = (out_sink + stage_v_251) & 255;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_126 * 3) + (sec_r000284_10 * 2) - pub_r000284_9 + 28) & 127;
    sec_accum = (sec_accum + stage_v_252 * 2) & 255;
    out_sink = (out_sink + stage_v_252) & 255;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_249 * 3) + (sec_r000284_17 * 2) - pub_r000284_13 + 35) & 127;
    sec_accum = (sec_accum + stage_v_253 * 2) & 255;
    out_sink = (out_sink + stage_v_253) & 255;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((sec_r000284_10 * 3) + (sec_r000284_10 * 2) - pub_r000284_12 + 17) & 127;
    sec_accum = (sec_accum + stage_v_254 * 2) & 255;
    out_sink = (out_sink + stage_v_254) & 255;

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_229 * 3) + (sec_r000284_8 * 2) - pub_r000284_14 + 25) & 127;
    sec_accum = (sec_accum + stage_v_255 * 2) & 255;
    out_sink = (out_sink + stage_v_255) & 255;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((sec_r000284_7 * 3) + (sec_r000284_7 * 2) - pub_r000284_12 + 25) & 127;
    sec_accum = (sec_accum + stage_v_256 * 2) & 255;
    out_sink = (out_sink + stage_v_256) & 255;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_257 * 2) & 255;
    out_sink = (out_sink + stage_v_257) & 255;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_156 * 3) + (sec_r000284_2 * 2) - pub_r000284_17 + 34) & 127;
    sec_accum = (sec_accum + stage_v_258 * 2) & 255;
    out_sink = (out_sink + stage_v_258) & 255;

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_138 * 3) + (sec_r000284_9 * 2) - pub_r000284_3 + 12) & 127;
    sec_accum = (sec_accum + stage_v_259 * 2) & 255;
    out_sink = (out_sink + stage_v_259) & 255;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r000284_6 * 3) + (sec_r000284_6 * 2) - pub_r000284_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_260 * 2) & 255;
    out_sink = (out_sink + stage_v_260) & 255;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_185 * 3) + (sec_r000284_11 * 2) - pub_r000284_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_261 * 2) & 255;
    out_sink = (out_sink + stage_v_261) & 255;

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_143 * 3) + (sec_r000284_0 * 2) - pub_r000284_4 + 14) & 127;
    sec_accum = (sec_accum + stage_v_262 * 2) & 255;
    out_sink = (out_sink + stage_v_262) & 255;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_240 * 3) + (sec_r000284_20 * 2) - pub_r000284_14 + 37) & 127;
    sec_accum = (sec_accum + stage_v_263 * 2) & 255;
    out_sink = (out_sink + stage_v_263) & 255;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((sec_r000284_20 * 3) + (sec_r000284_20 * 2) - pub_r000284_9 + 21) & 127;
    sec_accum = (sec_accum + stage_v_264 * 2) & 255;
    out_sink = (out_sink + stage_v_264) & 255;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((stage_v_219 * 3) + (sec_r000284_1 * 2) - pub_r000284_1 + 17) & 127;
    sec_accum = (sec_accum + stage_v_265 * 2) & 255;
    out_sink = (out_sink + stage_v_265) & 255;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((stage_v_186 * 3) + (sec_r000284_5 * 2) - pub_r000284_13 + 17) & 127;
    sec_accum = (sec_accum + stage_v_266 * 2) & 255;
    out_sink = (out_sink + stage_v_266) & 255;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_241 * 3) + (sec_r000284_6 * 2) - pub_r000284_6 + 9) & 127;
    sec_accum = (sec_accum + stage_v_267 * 2) & 255;
    out_sink = (out_sink + stage_v_267) & 255;

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_226 * 3) + (sec_r000284_14 * 2) - pub_r000284_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_268 * 2) & 255;
    out_sink = (out_sink + stage_v_268) & 255;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((stage_v_240 * 3) + (sec_r000284_6 * 2) - pub_r000284_8 + 16) & 127;
    sec_accum = (sec_accum + stage_v_269 * 2) & 255;
    out_sink = (out_sink + stage_v_269) & 255;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_173 * 3) + (sec_r000284_21 * 2) - pub_r000284_11 + 4) & 127;
    sec_accum = (sec_accum + stage_v_270 * 2) & 255;
    out_sink = (out_sink + stage_v_270) & 255;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_270 * 3) + (sec_r000284_15 * 2) - pub_r000284_15 + 9) & 127;
    sec_accum = (sec_accum + stage_v_271 * 2) & 255;
    out_sink = (out_sink + stage_v_271) & 255;

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_124 * 3) + (sec_r000284_7 * 2) - pub_r000284_12 + 34) & 127;
    sec_accum = (sec_accum + stage_v_272 * 2) & 255;
    out_sink = (out_sink + stage_v_272) & 255;

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_114 * 3) + (sec_r000284_1 * 2) - pub_r000284_12 + 16) & 127;
    sec_accum = (sec_accum + stage_v_273 * 2) & 255;
    out_sink = (out_sink + stage_v_273) & 255;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_152 * 3) + (sec_r000284_5 * 2) - pub_r000284_5 + 7) & 127;
    sec_accum = (sec_accum + stage_v_274 * 2) & 255;
    out_sink = (out_sink + stage_v_274) & 255;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((sec_r000284_7 * 3) + (sec_r000284_7 * 2) - pub_r000284_6 + 11) & 127;
    sec_accum = (sec_accum + stage_v_275 * 2) & 255;
    out_sink = (out_sink + stage_v_275) & 255;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((sec_r000284_4 * 3) + (sec_r000284_4 * 2) - pub_r000284_16 + 15) & 127;
    sec_accum = (sec_accum + stage_v_276 * 2) & 255;
    out_sink = (out_sink + stage_v_276) & 255;

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_223 * 3) + (sec_r000284_2 * 2) - pub_r000284_5 + 37) & 127;
    sec_accum = (sec_accum + stage_v_277 * 2) & 255;
    out_sink = (out_sink + stage_v_277) & 255;

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r000284_14 * 3) + (sec_r000284_14 * 2) - pub_r000284_0 + 7) & 127;
    sec_accum = (sec_accum + stage_v_278 * 2) & 255;
    out_sink = (out_sink + stage_v_278) & 255;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_140 * 3) + (sec_r000284_1 * 2) - pub_r000284_5 + 34) & 127;
    sec_accum = (sec_accum + stage_v_279 * 2) & 255;
    out_sink = (out_sink + stage_v_279) & 255;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_128 * 3) + (sec_r000284_10 * 2) - pub_r000284_12 + 4) & 127;
    sec_accum = (sec_accum + stage_v_280 * 2) & 255;
    out_sink = (out_sink + stage_v_280) & 255;

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_138 * 3) + (sec_r000284_19 * 2) - pub_r000284_4 + 33) & 127;
    sec_accum = (sec_accum + stage_v_281 * 2) & 255;
    out_sink = (out_sink + stage_v_281) & 255;

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((stage_v_210 * 3) + (sec_r000284_3 * 2) - pub_r000284_1 + 18) & 127;
    sec_accum = (sec_accum + stage_v_282 * 2) & 255;
    out_sink = (out_sink + stage_v_282) & 255;

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_251 * 3) + (sec_r000284_19 * 2) - pub_r000284_8 + 20) & 127;
    sec_accum = (sec_accum + stage_v_283 * 2) & 255;
    out_sink = (out_sink + stage_v_283) & 255;

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_237 * 3) + (sec_r000284_6 * 2) - pub_r000284_5 + 18) & 127;
    sec_accum = (sec_accum + stage_v_284 * 2) & 255;
    out_sink = (out_sink + stage_v_284) & 255;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((sec_r000284_7 * 3) + (sec_r000284_7 * 2) - pub_r000284_15 + 11) & 127;
    sec_accum = (sec_accum + stage_v_285 * 2) & 255;
    out_sink = (out_sink + stage_v_285) & 255;

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_3 + 3) & 127;
    sec_accum = (sec_accum + stage_v_286 * 2) & 255;
    out_sink = (out_sink + stage_v_286) & 255;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_286 * 3) + (sec_r000284_18 * 2) - pub_r000284_8 + 19) & 127;
    sec_accum = (sec_accum + stage_v_287 * 2) & 255;
    out_sink = (out_sink + stage_v_287) & 255;

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000284_12 * 3) + (sec_r000284_12 * 2) - pub_r000284_1 + 26) & 127;
    sec_accum = (sec_accum + stage_v_288 * 2) & 255;
    out_sink = (out_sink + stage_v_288) & 255;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_283 * 3) + (sec_r000284_12 * 2) - pub_r000284_5 + 20) & 127;
    sec_accum = (sec_accum + stage_v_289 * 2) & 255;
    out_sink = (out_sink + stage_v_289) & 255;

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((stage_v_155 * 3) + (sec_r000284_18 * 2) - pub_r000284_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_290 * 2) & 255;
    out_sink = (out_sink + stage_v_290) & 255;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_204 * 3) + (sec_r000284_8 * 2) - pub_r000284_13 + 13) & 127;
    sec_accum = (sec_accum + stage_v_291 * 2) & 255;
    out_sink = (out_sink + stage_v_291) & 255;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_103 * 3) + (sec_r000284_22 * 2) - pub_r000284_9 + 22) & 127;
    sec_accum = (sec_accum + stage_v_292 * 2) & 255;
    out_sink = (out_sink + stage_v_292) & 255;

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_133 * 3) + (sec_r000284_21 * 2) - pub_r000284_13 + 27) & 127;
    sec_accum = (sec_accum + stage_v_293 * 2) & 255;
    out_sink = (out_sink + stage_v_293) & 255;

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_16 + 26) & 127;
    sec_accum = (sec_accum + stage_v_294 * 2) & 255;
    out_sink = (out_sink + stage_v_294) & 255;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_187 * 3) + (sec_r000284_1 * 2) - pub_r000284_7 + 14) & 127;
    sec_accum = (sec_accum + stage_v_295 * 2) & 255;
    out_sink = (out_sink + stage_v_295) & 255;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_289 * 3) + (sec_r000284_6 * 2) - pub_r000284_16 + 17) & 127;
    sec_accum = (sec_accum + stage_v_296 * 2) & 255;
    out_sink = (out_sink + stage_v_296) & 255;

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_233 * 3) + (sec_r000284_8 * 2) - pub_r000284_0 + 18) & 127;
    sec_accum = (sec_accum + stage_v_297 * 2) & 255;
    out_sink = (out_sink + stage_v_297) & 255;

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((stage_v_107 * 3) + (sec_r000284_19 * 2) - pub_r000284_16 + 19) & 127;
    sec_accum = (sec_accum + stage_v_298 * 2) & 255;
    out_sink = (out_sink + stage_v_298) & 255;

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((sec_r000284_4 * 3) + (sec_r000284_4 * 2) - pub_r000284_9 + 3) & 127;
    sec_accum = (sec_accum + stage_v_299 * 2) & 255;
    out_sink = (out_sink + stage_v_299) & 255;

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((sec_r000284_19 * 3) + (sec_r000284_19 * 2) - pub_r000284_4 + 30) & 127;
    sec_accum = (sec_accum + stage_v_300 * 2) & 255;
    out_sink = (out_sink + stage_v_300) & 255;

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_210 * 3) + (sec_r000284_16 * 2) - pub_r000284_2 + 34) & 127;
    sec_accum = (sec_accum + stage_v_301 * 2) & 255;
    out_sink = (out_sink + stage_v_301) & 255;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((sec_r000284_9 * 3) + (sec_r000284_9 * 2) - pub_r000284_6 + 37) & 127;
    sec_accum = (sec_accum + stage_v_302 * 2) & 255;
    out_sink = (out_sink + stage_v_302) & 255;

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_127 * 3) + (sec_r000284_1 * 2) - pub_r000284_9 + 8) & 127;
    sec_accum = (sec_accum + stage_v_303 * 2) & 255;
    out_sink = (out_sink + stage_v_303) & 255;

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((sec_r000284_2 * 3) + (sec_r000284_2 * 2) - pub_r000284_2 + 30) & 127;
    sec_accum = (sec_accum + stage_v_304 * 2) & 255;
    out_sink = (out_sink + stage_v_304) & 255;

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_126 * 3) + (sec_r000284_16 * 2) - pub_r000284_12 + 8) & 127;
    sec_accum = (sec_accum + stage_v_305 * 2) & 255;
    out_sink = (out_sink + stage_v_305) & 255;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_16 + 31) & 127;
    sec_accum = (sec_accum + stage_v_306 * 2) & 255;
    out_sink = (out_sink + stage_v_306) & 255;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_206 * 3) + (sec_r000284_1 * 2) - pub_r000284_10 + 6) & 127;
    sec_accum = (sec_accum + stage_v_307 * 2) & 255;
    out_sink = (out_sink + stage_v_307) & 255;

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_242 * 3) + (sec_r000284_17 * 2) - pub_r000284_7 + 31) & 127;
    sec_accum = (sec_accum + stage_v_308 * 2) & 255;
    out_sink = (out_sink + stage_v_308) & 255;

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_153 * 3) + (sec_r000284_14 * 2) - pub_r000284_12 + 5) & 127;
    sec_accum = (sec_accum + stage_v_309 * 2) & 255;
    out_sink = (out_sink + stage_v_309) & 255;

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((stage_v_229 * 3) + (sec_r000284_7 * 2) - pub_r000284_7 + 28) & 127;
    sec_accum = (sec_accum + stage_v_310 * 2) & 255;
    out_sink = (out_sink + stage_v_310) & 255;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_170 * 3) + (sec_r000284_17 * 2) - pub_r000284_16 + 11) & 127;
    sec_accum = (sec_accum + stage_v_311 * 2) & 255;
    out_sink = (out_sink + stage_v_311) & 255;

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_175 * 3) + (sec_r000284_4 * 2) - pub_r000284_10 + 27) & 127;
    sec_accum = (sec_accum + stage_v_312 * 2) & 255;
    out_sink = (out_sink + stage_v_312) & 255;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_9 + 14) & 127;
    sec_accum = (sec_accum + stage_v_313 * 2) & 255;
    out_sink = (out_sink + stage_v_313) & 255;

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_189 * 3) + (sec_r000284_3 * 2) - pub_r000284_3 + 17) & 127;
    sec_accum = (sec_accum + stage_v_314 * 2) & 255;
    out_sink = (out_sink + stage_v_314) & 255;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((stage_v_308 * 3) + (sec_r000284_18 * 2) - pub_r000284_11 + 35) & 127;
    sec_accum = (sec_accum + stage_v_315 * 2) & 255;
    out_sink = (out_sink + stage_v_315) & 255;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_294 * 3) + (sec_r000284_21 * 2) - pub_r000284_9 + 4) & 127;
    sec_accum = (sec_accum + stage_v_316 * 2) & 255;
    out_sink = (out_sink + stage_v_316) & 255;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_188 * 3) + (sec_r000284_13 * 2) - pub_r000284_6 + 28) & 127;
    sec_accum = (sec_accum + stage_v_317 * 2) & 255;
    out_sink = (out_sink + stage_v_317) & 255;

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_237 * 3) + (sec_r000284_22 * 2) - pub_r000284_8 + 8) & 127;
    sec_accum = (sec_accum + stage_v_318 * 2) & 255;
    out_sink = (out_sink + stage_v_318) & 255;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_203 * 3) + (sec_r000284_10 * 2) - pub_r000284_9 + 24) & 127;
    sec_accum = (sec_accum + stage_v_319 * 2) & 255;
    out_sink = (out_sink + stage_v_319) & 255;

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((sec_r000284_21 * 3) + (sec_r000284_21 * 2) - pub_r000284_6 + 13) & 127;
    sec_accum = (sec_accum + stage_v_320 * 2) & 255;
    out_sink = (out_sink + stage_v_320) & 255;

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_153 * 3) + (sec_r000284_8 * 2) - pub_r000284_11 + 12) & 127;
    sec_accum = (sec_accum + stage_v_321 * 2) & 255;
    out_sink = (out_sink + stage_v_321) & 255;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_186 * 3) + (sec_r000284_11 * 2) - pub_r000284_14 + 17) & 127;
    sec_accum = (sec_accum + stage_v_322 * 2) & 255;
    out_sink = (out_sink + stage_v_322) & 255;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((sec_r000284_11 * 3) + (sec_r000284_11 * 2) - pub_r000284_2 + 9) & 127;
    sec_accum = (sec_accum + stage_v_323 * 2) & 255;
    out_sink = (out_sink + stage_v_323) & 255;

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((stage_v_207 * 3) + (sec_r000284_22 * 2) - pub_r000284_13 + 12) & 127;
    sec_accum = (sec_accum + stage_v_324 * 2) & 255;
    out_sink = (out_sink + stage_v_324) & 255;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_239 * 3) + (sec_r000284_7 * 2) - pub_r000284_8 + 29) & 127;
    sec_accum = (sec_accum + stage_v_325 * 2) & 255;
    out_sink = (out_sink + stage_v_325) & 255;

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_271 * 3) + (sec_r000284_7 * 2) - pub_r000284_1 + 25) & 127;
    sec_accum = (sec_accum + stage_v_326 * 2) & 255;
    out_sink = (out_sink + stage_v_326) & 255;

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((sec_r000284_17 * 3) + (sec_r000284_17 * 2) - pub_r000284_2 + 19) & 127;
    sec_accum = (sec_accum + stage_v_327 * 2) & 255;
    out_sink = (out_sink + stage_v_327) & 255;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_179 * 3) + (sec_r000284_0 * 2) - pub_r000284_16 + 13) & 127;
    sec_accum = (sec_accum + stage_v_328 * 2) & 255;
    out_sink = (out_sink + stage_v_328) & 255;

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_219 * 3) + (sec_r000284_1 * 2) - pub_r000284_1 + 31) & 127;
    sec_accum = (sec_accum + stage_v_329 * 2) & 255;
    out_sink = (out_sink + stage_v_329) & 255;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_298 * 3) + (sec_r000284_20 * 2) - pub_r000284_5 + 9) & 127;
    sec_accum = (sec_accum + stage_v_330 * 2) & 255;
    out_sink = (out_sink + stage_v_330) & 255;

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_94 * 3) + (sec_r000284_17 * 2) - pub_r000284_10 + 26) & 127;
    sec_accum = (sec_accum + stage_v_331 * 2) & 255;
    out_sink = (out_sink + stage_v_331) & 255;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((sec_r000284_5 * 3) + (sec_r000284_5 * 2) - pub_r000284_2 + 20) & 127;
    sec_accum = (sec_accum + stage_v_332 * 2) & 255;
    out_sink = (out_sink + stage_v_332) & 255;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((sec_r000284_1 * 3) + (sec_r000284_1 * 2) - pub_r000284_17 + 29) & 127;
    sec_accum = (sec_accum + stage_v_333 * 2) & 255;
    out_sink = (out_sink + stage_v_333) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
