/*
 * Benchmark Program: R000986
 * Security Family: implicit_flow
 * Generator Seed: 598613
 * High Inputs: 17 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Vector3D_R000986_8613_0 {
    int heading;
    unsigned char coord_z;
    unsigned char coord_y;
    int coord_x;
    unsigned char pitch;
    int norm_sq;
    int buffer[3];
};

struct Transaction_R000986_8613_1 {
    int account_id;
    unsigned char auth_code;
    int status;
    int rate;
    int buffer[3];
};

union ColorPixel_R000986_8613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000986_8613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000986_8613_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000986_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int parity_36 = (aux + st.buffer[1]) & 3;
    switch (parity_36) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_87 = local_arr[aux % 3];
    acc = (acc + checksum_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000986_8613_1(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int residue_49 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_49 > 17) {
        acc = (acc + residue_49 * 2 + 5) & 127;
        aux ^= (residue_49 & 15);
    } else {
        acc = (acc - residue_49 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_13 = local_arr[aux % 3];
    acc = (acc + index_reg_13 * 2) & 127;
    int residue_48 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_48 > 50) {
        acc = (acc + residue_48 * 2 + 5) & 127;
        aux ^= (residue_48 & 15);
    } else {
        acc = (acc - residue_48 + 11) & 127;
        aux += 3;
    }
    int coefficient_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_99) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000986_8613_3(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_37) & 63;
    acc ^= aux;
    int quotient_80 = (aux + st.buffer[1]) & 3;
    switch (quotient_80) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_92 = local_arr[aux % 3];
    acc = (acc + stride_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000986_8613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int factor_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_59) & 63;
    acc ^= aux;
    int phase_23 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_23 > 50) {
        acc = (acc + phase_23 * 2 + 5) & 127;
        aux ^= (phase_23 & 15);
    } else {
        acc = (acc - phase_23 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_5(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000986_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int quotient_93 = local_arr[aux % 3];
    acc = (acc + quotient_93 * 2) & 127;
    int accumulator_71 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_71 > 10) {
        acc = (acc + accumulator_71 * 2 + 5) & 127;
        aux ^= (accumulator_71 & 15);
    } else {
        acc = (acc - accumulator_71 + 11) & 127;
        aux += 3;
    }
    int metric_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_91) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000986_8613_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_43 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_43) & 63;
    acc ^= aux;
    int window_98 = (aux + st.buffer[1]) & 3;
    switch (window_98) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_7(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000986_8613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_94 = (aux + st.buffer[1]) & 3;
    switch (quotient_94) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int factor_32 = local_arr[aux % 3];
    acc = (acc + factor_32 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000986_8613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int cursor_80 = local_arr[aux % 3];
    acc = (acc + cursor_80 * 2) & 127;
    int metric_26 = (aux + st.buffer[1]) & 3;
    switch (metric_26) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int checksum_98 = (aux + st.buffer[1]) & 3;
    switch (checksum_98) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_30 = local_arr[aux % 3];
    acc = (acc + parity_30 * 2) & 127;
    int factor_97 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_97 > 43) {
        acc = (acc + factor_97 * 2 + 5) & 127;
        aux ^= (factor_97 & 15);
    } else {
        acc = (acc - factor_97 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int window_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_14) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int weight_20 = local_arr[aux % 3];
    acc = (acc + weight_20 * 2) & 127;
    int damping_22 = (aux + st.buffer[1]) & 3;
    switch (damping_22) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000986_8613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int tally_99 = (aux + st.buffer[1]) & 3;
    switch (tally_99) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int anchor_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_44) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000986_8613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Vector3D_R000986_8613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_15 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_15 > 49) {
        acc = (acc + mask_15 * 2 + 5) & 127;
        aux ^= (mask_15 & 15);
    } else {
        acc = (acc - mask_15 + 11) & 127;
        aux += 3;
    }
    int stride_91 = (aux + st.buffer[1]) & 3;
    switch (stride_91) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000986_0;
    int sec_r000986_1;
    int sec_r000986_2;
    int sec_r000986_3;
    int sec_r000986_4;
    int sec_r000986_5;
    int sec_r000986_6;
    int sec_r000986_7;
    int sec_r000986_8;
    int sec_r000986_9;
    int sec_r000986_10;
    int sec_r000986_11;
    int sec_r000986_12;
    int sec_r000986_13;
    int sec_r000986_14;
    int sec_r000986_15;
    int sec_r000986_16;
    int pub_r000986_0;
    int pub_r000986_1;
    int pub_r000986_2;
    int pub_r000986_3;
    int pub_r000986_4;
    int pub_r000986_5;
    int pub_r000986_6;
    int pub_r000986_7;
    int pub_r000986_8;
    int pub_r000986_9;
    int pub_r000986_10;
    int pub_r000986_11;
    int pub_r000986_12;
    int pub_r000986_13;
    int pub_r000986_14;
    int pub_r000986_15;
    int pub_r000986_16;
    int pub_r000986_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000986_0 >= -100 && pub_r000986_0 <= 100);
    __CPROVER_assume(pub_r000986_1 >= -100 && pub_r000986_1 <= 100);
    __CPROVER_assume(pub_r000986_2 >= -100 && pub_r000986_2 <= 100);
    __CPROVER_assume(pub_r000986_3 >= -100 && pub_r000986_3 <= 100);
    __CPROVER_assume(pub_r000986_4 >= -100 && pub_r000986_4 <= 100);
    __CPROVER_assume(pub_r000986_5 >= -100 && pub_r000986_5 <= 100);
    __CPROVER_assume(pub_r000986_6 >= -100 && pub_r000986_6 <= 100);
    __CPROVER_assume(pub_r000986_7 >= -100 && pub_r000986_7 <= 100);
    __CPROVER_assume(pub_r000986_8 >= -100 && pub_r000986_8 <= 100);
    __CPROVER_assume(pub_r000986_9 >= -100 && pub_r000986_9 <= 100);
    __CPROVER_assume(pub_r000986_10 >= -100 && pub_r000986_10 <= 100);
    __CPROVER_assume(pub_r000986_11 >= -100 && pub_r000986_11 <= 100);
    __CPROVER_assume(pub_r000986_12 >= -100 && pub_r000986_12 <= 100);
    __CPROVER_assume(pub_r000986_13 >= -100 && pub_r000986_13 <= 100);
    __CPROVER_assume(pub_r000986_14 >= -100 && pub_r000986_14 <= 100);
    __CPROVER_assume(pub_r000986_15 >= -100 && pub_r000986_15 <= 100);
    __CPROVER_assume(pub_r000986_16 >= -100 && pub_r000986_16 <= 100);
    __CPROVER_assume(pub_r000986_17 >= -100 && pub_r000986_17 <= 100);
    __CPROVER_assume(sec_r000986_0 >= 0 && sec_r000986_0 <= 255);
    __CPROVER_assume(sec_r000986_1 >= 0 && sec_r000986_1 <= 255);
    __CPROVER_assume(sec_r000986_2 >= 0 && sec_r000986_2 <= 255);
    __CPROVER_assume(sec_r000986_3 >= 0 && sec_r000986_3 <= 255);
    __CPROVER_assume(sec_r000986_4 >= 0 && sec_r000986_4 <= 255);
    __CPROVER_assume(sec_r000986_5 >= 0 && sec_r000986_5 <= 255);
    __CPROVER_assume(sec_r000986_6 >= 0 && sec_r000986_6 <= 255);
    __CPROVER_assume(sec_r000986_7 >= 0 && sec_r000986_7 <= 255);
    __CPROVER_assume(sec_r000986_8 >= 0 && sec_r000986_8 <= 255);
    __CPROVER_assume(sec_r000986_9 >= 0 && sec_r000986_9 <= 255);
    __CPROVER_assume(sec_r000986_10 >= 0 && sec_r000986_10 <= 255);
    __CPROVER_assume(sec_r000986_11 >= 0 && sec_r000986_11 <= 255);
    __CPROVER_assume(sec_r000986_12 >= 0 && sec_r000986_12 <= 255);
    __CPROVER_assume(sec_r000986_13 >= 0 && sec_r000986_13 <= 255);
    __CPROVER_assume(sec_r000986_14 >= 0 && sec_r000986_14 <= 255);
    __CPROVER_assume(sec_r000986_15 >= 0 && sec_r000986_15 <= 255);
    __CPROVER_assume(sec_r000986_16 >= 0 && sec_r000986_16 <= 255);

    struct Vector3D_R000986_8613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000986_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000986_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000986_0 + 7) & 15;
    struct Transaction_R000986_8613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000986_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000986_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000986_0 + 9) & 15;

    union ColorPixel_R000986_8613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (out_sink > 100) ? (chk_sum & 31) : (9 & 31);
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= (stage_v_4 << 1) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    if ((sec_r000986_2 & 63) > 30) {
        stage_v_5 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_5) & 255;
    } else {
        stage_v_5 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_5 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    if ((stage_v_5 & 63) > 59) {
        stage_v_6 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_6) & 255;
    } else {
        stage_v_6 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_6 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    if ((stage_v_6 & 63) > 50) {
        stage_v_7 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_7) & 255;
    } else {
        stage_v_7 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_7 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    if ((stage_v_7 & 63) > 30) {
        stage_v_8 = (pub_r000986_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_8) & 255;
    } else {
        stage_v_8 = (pub_r000986_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_8 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    if ((stage_v_7 & 63) > 33) {
        stage_v_9 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_9) & 255;
    } else {
        stage_v_9 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_9 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    if ((sec_r000986_15 & 63) > 56) {
        stage_v_10 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_10) & 255;
    } else {
        stage_v_10 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_10 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    if ((stage_v_10 & 63) > 50) {
        stage_v_11 = (pub_r000986_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_11) & 255;
    } else {
        stage_v_11 = (pub_r000986_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_11 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    if ((stage_v_8 & 63) > 17) {
        stage_v_12 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_12) & 255;
    } else {
        stage_v_12 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_12 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    if ((stage_v_8 & 63) > 19) {
        stage_v_13 = (pub_r000986_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_13) & 255;
    } else {
        stage_v_13 = (pub_r000986_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_13 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((stage_v_7 & 63) > 50) {
        stage_v_14 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_14) & 255;
    } else {
        stage_v_14 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_14 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((sec_r000986_15 & 63) > 24) {
        stage_v_15 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_15) & 255;
    } else {
        stage_v_15 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_15 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((stage_v_9 & 63) > 53) {
        stage_v_16 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_16) & 255;
    } else {
        stage_v_16 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_16 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((stage_v_16 & 63) > 50) {
        stage_v_17 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_17) & 255;
    } else {
        stage_v_17 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_17 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((stage_v_16 & 63) > 17) {
        stage_v_18 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_18) & 255;
    } else {
        stage_v_18 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_18 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((stage_v_10 & 63) > 46) {
        stage_v_19 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_19) & 255;
    } else {
        stage_v_19 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_19 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_11 & 63) > 23) {
        stage_v_20 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_20) & 255;
    } else {
        stage_v_20 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_20 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000986_1 & 63) > 17) {
        stage_v_21 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_21) & 255;
    } else {
        stage_v_21 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_21 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((stage_v_20 & 63) > 47) {
        stage_v_22 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_22) & 255;
    } else {
        stage_v_22 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_22 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((sec_r000986_16 & 63) > 51) {
        stage_v_23 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_23) & 255;
    } else {
        stage_v_23 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_23 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_16 & 63) > 57) {
        stage_v_24 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_24) & 255;
    } else {
        stage_v_24 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_24 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_14 & 63) > 28) {
        stage_v_25 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_25) & 255;
    } else {
        stage_v_25 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_25 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_18 & 63) > 38) {
        stage_v_26 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_26) & 255;
    } else {
        stage_v_26 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_26 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_20 & 63) > 55) {
        stage_v_27 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_27) & 255;
    } else {
        stage_v_27 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_27 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_17 & 63) > 52) {
        stage_v_28 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_28) & 255;
    } else {
        stage_v_28 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_28 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((sec_r000986_13 & 63) > 54) {
        stage_v_29 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_29) & 255;
    } else {
        stage_v_29 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_29 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000986_4 & 63) > 29) {
        stage_v_30 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_30) & 255;
    } else {
        stage_v_30 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_30 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((sec_r000986_13 & 63) > 43) {
        stage_v_31 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_31) & 255;
    } else {
        stage_v_31 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_31 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_22 & 63) > 27) {
        stage_v_32 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_32) & 255;
    } else {
        stage_v_32 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_32 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_21 & 63) > 18) {
        stage_v_33 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_33) & 255;
    } else {
        stage_v_33 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_33 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_23 & 63) > 22) {
        stage_v_34 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_34) & 255;
    } else {
        stage_v_34 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_34 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_11 & 63) > 28) {
        stage_v_35 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_35) & 255;
    } else {
        stage_v_35 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_35 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_33 & 63) > 52) {
        stage_v_36 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_36) & 255;
    } else {
        stage_v_36 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_36 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((sec_r000986_9 & 63) > 57) {
        stage_v_37 = (pub_r000986_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_37) & 255;
    } else {
        stage_v_37 = (pub_r000986_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_37 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_15 & 63) > 52) {
        stage_v_38 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_38) & 255;
    } else {
        stage_v_38 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_38 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((sec_r000986_8 & 63) > 52) {
        stage_v_39 = (pub_r000986_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_39) & 255;
    } else {
        stage_v_39 = (pub_r000986_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_39 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_12 & 63) > 16) {
        stage_v_40 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_40) & 255;
    } else {
        stage_v_40 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_40 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000986_9 & 63) > 45) {
        stage_v_41 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_41) & 255;
    } else {
        stage_v_41 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_41 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((sec_r000986_14 & 63) > 58) {
        stage_v_42 = (pub_r000986_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_42) & 255;
    } else {
        stage_v_42 = (pub_r000986_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_42 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_11 & 63) > 33) {
        stage_v_43 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_43) & 255;
    } else {
        stage_v_43 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_43 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000986_0 & 63) > 48) {
        stage_v_44 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_44) & 255;
    } else {
        stage_v_44 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_44 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_24 & 63) > 52) {
        stage_v_45 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_45) & 255;
    } else {
        stage_v_45 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_45 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_16 & 63) > 39) {
        stage_v_46 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_46) & 255;
    } else {
        stage_v_46 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_46 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_41 & 63) > 49) {
        stage_v_47 = (pub_r000986_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_47) & 255;
    } else {
        stage_v_47 = (pub_r000986_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_47 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_20 & 63) > 20) {
        stage_v_48 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_48) & 255;
    } else {
        stage_v_48 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_48 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_36 & 63) > 44) {
        stage_v_49 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_49) & 255;
    } else {
        stage_v_49 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_49 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_21 & 63) > 51) {
        stage_v_50 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_50) & 255;
    } else {
        stage_v_50 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_50 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((stage_v_44 & 63) > 15) {
        stage_v_51 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_51) & 255;
    } else {
        stage_v_51 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_51 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_25 & 63) > 55) {
        stage_v_52 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_52) & 255;
    } else {
        stage_v_52 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_52 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_16 & 63) > 40) {
        stage_v_53 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_53) & 255;
    } else {
        stage_v_53 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_53 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_45 & 63) > 24) {
        stage_v_54 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_54) & 255;
    } else {
        stage_v_54 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_54 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_44 & 63) > 56) {
        stage_v_55 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_55) & 255;
    } else {
        stage_v_55 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_55 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((sec_r000986_14 & 63) > 50) {
        stage_v_56 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_56) & 255;
    } else {
        stage_v_56 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_56 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_52 & 63) > 51) {
        stage_v_57 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_57) & 255;
    } else {
        stage_v_57 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_57 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_48 & 63) > 45) {
        stage_v_58 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_58) & 255;
    } else {
        stage_v_58 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_58 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_13 & 63) > 33) {
        stage_v_59 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_59) & 255;
    } else {
        stage_v_59 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_59 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_21 & 63) > 25) {
        stage_v_60 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_60) & 255;
    } else {
        stage_v_60 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_60 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_47 & 63) > 28) {
        stage_v_61 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_61) & 255;
    } else {
        stage_v_61 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_61 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000986_10 & 63) > 60) {
        stage_v_62 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_62) & 255;
    } else {
        stage_v_62 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_62 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_54 & 63) > 27) {
        stage_v_63 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_63) & 255;
    } else {
        stage_v_63 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_63 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_63 & 63) > 30) {
        stage_v_64 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_64) & 255;
    } else {
        stage_v_64 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_64 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000986_12 & 63) > 37) {
        stage_v_65 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_65) & 255;
    } else {
        stage_v_65 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_65 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000986_14 & 63) > 16) {
        stage_v_66 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_66) & 255;
    } else {
        stage_v_66 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_66 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000986_3 & 63) > 58) {
        stage_v_67 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_67) & 255;
    } else {
        stage_v_67 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_67 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_32 & 63) > 44) {
        stage_v_68 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_68) & 255;
    } else {
        stage_v_68 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_68 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000986_10 & 63) > 30) {
        stage_v_69 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_69) & 255;
    } else {
        stage_v_69 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_69 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_65 & 63) > 55) {
        stage_v_70 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_70) & 255;
    } else {
        stage_v_70 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_70 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_27 & 63) > 59) {
        stage_v_71 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_71) & 255;
    } else {
        stage_v_71 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_71 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000986_14 & 63) > 31) {
        stage_v_72 = (pub_r000986_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_72) & 255;
    } else {
        stage_v_72 = (pub_r000986_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_72 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000986_6 & 63) > 45) {
        stage_v_73 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_73) & 255;
    } else {
        stage_v_73 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_73 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_33 & 63) > 29) {
        stage_v_74 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_74) & 255;
    } else {
        stage_v_74 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_74 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_16 & 63) > 54) {
        stage_v_75 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_75) & 255;
    } else {
        stage_v_75 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_75 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_54 & 63) > 42) {
        stage_v_76 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_76) & 255;
    } else {
        stage_v_76 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_76 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_22 & 63) > 47) {
        stage_v_77 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_77) & 255;
    } else {
        stage_v_77 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_77 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_10 & 63) > 58) {
        stage_v_78 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_78) & 255;
    } else {
        stage_v_78 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_78 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_73 & 63) > 27) {
        stage_v_79 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_79) & 255;
    } else {
        stage_v_79 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_79 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000986_13 & 63) > 42) {
        stage_v_80 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_80) & 255;
    } else {
        stage_v_80 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_80 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_6 & 63) > 60) {
        stage_v_81 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_81) & 255;
    } else {
        stage_v_81 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_81 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_56 & 63) > 31) {
        stage_v_82 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_82) & 255;
    } else {
        stage_v_82 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_82 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_77 & 63) > 38) {
        stage_v_83 = (pub_r000986_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_83) & 255;
    } else {
        stage_v_83 = (pub_r000986_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_83 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_37 & 63) > 27) {
        stage_v_84 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_84) & 255;
    } else {
        stage_v_84 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_84 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000986_0 & 63) > 17) {
        stage_v_85 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_85) & 255;
    } else {
        stage_v_85 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_85 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000986_14 & 63) > 29) {
        stage_v_86 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_86) & 255;
    } else {
        stage_v_86 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_86 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_51 & 63) > 40) {
        stage_v_87 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_87) & 255;
    } else {
        stage_v_87 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_87 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000986_1 & 63) > 21) {
        stage_v_88 = (pub_r000986_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_88) & 255;
    } else {
        stage_v_88 = (pub_r000986_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_88 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_22 & 63) > 60) {
        stage_v_89 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_89) & 255;
    } else {
        stage_v_89 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_89 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_5 & 63) > 57) {
        stage_v_90 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_90) & 255;
    } else {
        stage_v_90 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_90 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_52 & 63) > 20) {
        stage_v_91 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_91) & 255;
    } else {
        stage_v_91 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_91 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_84 & 63) > 46) {
        stage_v_92 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_92) & 255;
    } else {
        stage_v_92 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_92 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_86 & 63) > 47) {
        stage_v_93 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_93) & 255;
    } else {
        stage_v_93 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_93 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_45 & 63) > 34) {
        stage_v_94 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_94) & 255;
    } else {
        stage_v_94 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_94 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_9 & 63) > 41) {
        stage_v_95 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_95) & 255;
    } else {
        stage_v_95 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_95 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_95 & 63) > 24) {
        stage_v_96 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_96) & 255;
    } else {
        stage_v_96 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_96 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((sec_r000986_10 & 63) > 51) {
        stage_v_97 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_97) & 255;
    } else {
        stage_v_97 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_97 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000986_4 & 63) > 52) {
        stage_v_98 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_98) & 255;
    } else {
        stage_v_98 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_98 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_87 & 63) > 38) {
        stage_v_99 = (pub_r000986_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_99) & 255;
    } else {
        stage_v_99 = (pub_r000986_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_99 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_98 & 63) > 36) {
        stage_v_100 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_100) & 255;
    } else {
        stage_v_100 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_100 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_87 & 63) > 30) {
        stage_v_101 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_101) & 255;
    } else {
        stage_v_101 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_101 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_30 & 63) > 29) {
        stage_v_102 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_102) & 255;
    } else {
        stage_v_102 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_102 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000986_0 & 63) > 58) {
        stage_v_103 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_103) & 255;
    } else {
        stage_v_103 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_103 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_24 & 63) > 32) {
        stage_v_104 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_104) & 255;
    } else {
        stage_v_104 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_104 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_85 & 63) > 31) {
        stage_v_105 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_105) & 255;
    } else {
        stage_v_105 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_105 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000986_3 & 63) > 49) {
        stage_v_106 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_106) & 255;
    } else {
        stage_v_106 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_106 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000986_14 & 63) > 42) {
        stage_v_107 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_107) & 255;
    } else {
        stage_v_107 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_107 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_26 & 63) > 48) {
        stage_v_108 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_108) & 255;
    } else {
        stage_v_108 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_108 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000986_4 & 63) > 29) {
        stage_v_109 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_109) & 255;
    } else {
        stage_v_109 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_109 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_18 & 63) > 16) {
        stage_v_110 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_110) & 255;
    } else {
        stage_v_110 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_110 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_65 & 63) > 15) {
        stage_v_111 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_111) & 255;
    } else {
        stage_v_111 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_111 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_96 & 63) > 23) {
        stage_v_112 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_112) & 255;
    } else {
        stage_v_112 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_112 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000986_9 & 63) > 34) {
        stage_v_113 = (pub_r000986_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_113) & 255;
    } else {
        stage_v_113 = (pub_r000986_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_113 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000986_14 & 63) > 51) {
        stage_v_114 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_114) & 255;
    } else {
        stage_v_114 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_114 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_113 & 63) > 17) {
        stage_v_115 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_115) & 255;
    } else {
        stage_v_115 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_115 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000986_5 & 63) > 21) {
        stage_v_116 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_116) & 255;
    } else {
        stage_v_116 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_116 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000986_8 & 63) > 43) {
        stage_v_117 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_117) & 255;
    } else {
        stage_v_117 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_117 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_109 & 63) > 60) {
        stage_v_118 = (pub_r000986_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_118) & 255;
    } else {
        stage_v_118 = (pub_r000986_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_118 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_36 & 63) > 17) {
        stage_v_119 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_119) & 255;
    } else {
        stage_v_119 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_119 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_77 & 63) > 31) {
        stage_v_120 = (pub_r000986_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_120) & 255;
    } else {
        stage_v_120 = (pub_r000986_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_120 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_109 & 63) > 54) {
        stage_v_121 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_121) & 255;
    } else {
        stage_v_121 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_121 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_114 & 63) > 48) {
        stage_v_122 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_122) & 255;
    } else {
        stage_v_122 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_122 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_27 & 63) > 57) {
        stage_v_123 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_123) & 255;
    } else {
        stage_v_123 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_123 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000986_16 & 63) > 24) {
        stage_v_124 = (pub_r000986_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_124) & 255;
    } else {
        stage_v_124 = (pub_r000986_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_124 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_93 & 63) > 32) {
        stage_v_125 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_125) & 255;
    } else {
        stage_v_125 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_125 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000986_0 & 63) > 45) {
        stage_v_126 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_126) & 255;
    } else {
        stage_v_126 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_126 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000986_14 & 63) > 19) {
        stage_v_127 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_127) & 255;
    } else {
        stage_v_127 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_127 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000986_11 & 63) > 55) {
        stage_v_128 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_128) & 255;
    } else {
        stage_v_128 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_128 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_104 & 63) > 16) {
        stage_v_129 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_129) & 255;
    } else {
        stage_v_129 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_129 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000986_16 & 63) > 15) {
        stage_v_130 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_130) & 255;
    } else {
        stage_v_130 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_130 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_94 & 63) > 52) {
        stage_v_131 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_131) & 255;
    } else {
        stage_v_131 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_131 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_39 & 63) > 40) {
        stage_v_132 = (pub_r000986_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_132) & 255;
    } else {
        stage_v_132 = (pub_r000986_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_132 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_48 & 63) > 15) {
        stage_v_133 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_133) & 255;
    } else {
        stage_v_133 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_133 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000986_12 & 63) > 51) {
        stage_v_134 = (pub_r000986_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_134) & 255;
    } else {
        stage_v_134 = (pub_r000986_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_134 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((sec_r000986_3 & 63) > 28) {
        stage_v_135 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_135) & 255;
    } else {
        stage_v_135 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_135 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_46 & 63) > 18) {
        stage_v_136 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_136) & 255;
    } else {
        stage_v_136 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_136 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((sec_r000986_13 & 63) > 20) {
        stage_v_137 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_137) & 255;
    } else {
        stage_v_137 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_137 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_8 & 63) > 33) {
        stage_v_138 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_138) & 255;
    } else {
        stage_v_138 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_138 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000986_5 & 63) > 54) {
        stage_v_139 = (pub_r000986_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_139) & 255;
    } else {
        stage_v_139 = (pub_r000986_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_139 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_83 & 63) > 51) {
        stage_v_140 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_140) & 255;
    } else {
        stage_v_140 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_140 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_47 & 63) > 16) {
        stage_v_141 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_141) & 255;
    } else {
        stage_v_141 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_141 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_136 & 63) > 17) {
        stage_v_142 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_142) & 255;
    } else {
        stage_v_142 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_142 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000986_16 & 63) > 44) {
        stage_v_143 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_143) & 255;
    } else {
        stage_v_143 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_143 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((sec_r000986_3 & 63) > 26) {
        stage_v_144 = (pub_r000986_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_144) & 255;
    } else {
        stage_v_144 = (pub_r000986_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_144 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000986_0 & 63) > 48) {
        stage_v_145 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_145) & 255;
    } else {
        stage_v_145 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_145 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_27 & 63) > 39) {
        stage_v_146 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_146) & 255;
    } else {
        stage_v_146 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_146 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_66 & 63) > 27) {
        stage_v_147 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_147) & 255;
    } else {
        stage_v_147 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_147 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_35 & 63) > 23) {
        stage_v_148 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_148) & 255;
    } else {
        stage_v_148 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_148 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_50 & 63) > 47) {
        stage_v_149 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_149) & 255;
    } else {
        stage_v_149 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_149 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000986_16 & 63) > 28) {
        stage_v_150 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_150) & 255;
    } else {
        stage_v_150 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_150 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000986_3 & 63) > 19) {
        stage_v_151 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_151) & 255;
    } else {
        stage_v_151 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_151 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((stage_v_145 & 63) > 34) {
        stage_v_152 = (pub_r000986_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_152) & 255;
    } else {
        stage_v_152 = (pub_r000986_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_152 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000986_13 & 63) > 39) {
        stage_v_153 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_153) & 255;
    } else {
        stage_v_153 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_153 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_89 & 63) > 21) {
        stage_v_154 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_154) & 255;
    } else {
        stage_v_154 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_154 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000986_5 & 63) > 29) {
        stage_v_155 = (pub_r000986_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_155) & 255;
    } else {
        stage_v_155 = (pub_r000986_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_155 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_80 & 63) > 31) {
        stage_v_156 = (pub_r000986_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_156) & 255;
    } else {
        stage_v_156 = (pub_r000986_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_156 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_139 & 63) > 48) {
        stage_v_157 = (pub_r000986_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_157) & 255;
    } else {
        stage_v_157 = (pub_r000986_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_157 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((stage_v_137 & 63) > 24) {
        stage_v_158 = (pub_r000986_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_158) & 255;
    } else {
        stage_v_158 = (pub_r000986_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_158 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_151 & 63) > 17) {
        stage_v_159 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_159) & 255;
    } else {
        stage_v_159 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_159 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000986_2 & 63) > 59) {
        stage_v_160 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_160) & 255;
    } else {
        stage_v_160 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_160 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_42 & 63) > 60) {
        stage_v_161 = (pub_r000986_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_161) & 255;
    } else {
        stage_v_161 = (pub_r000986_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_161 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000986_6 & 63) > 46) {
        stage_v_162 = (pub_r000986_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_162) & 255;
    } else {
        stage_v_162 = (pub_r000986_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_162 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_66 & 63) > 42) {
        stage_v_163 = (pub_r000986_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_163) & 255;
    } else {
        stage_v_163 = (pub_r000986_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_163 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((stage_v_109 & 63) > 45) {
        stage_v_164 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_164) & 255;
    } else {
        stage_v_164 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_164 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_6 & 63) > 35) {
        stage_v_165 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_165) & 255;
    } else {
        stage_v_165 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_165 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_37 & 63) > 49) {
        stage_v_166 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_166) & 255;
    } else {
        stage_v_166 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_166 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_63 & 63) > 42) {
        stage_v_167 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_167) & 255;
    } else {
        stage_v_167 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_167 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    if ((sec_r000986_0 & 63) > 35) {
        stage_v_168 = (pub_r000986_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_168) & 255;
    } else {
        stage_v_168 = (pub_r000986_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_168 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    if ((stage_v_7 & 63) > 34) {
        stage_v_169 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_169) & 255;
    } else {
        stage_v_169 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_169 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    if ((sec_r000986_9 & 63) > 53) {
        stage_v_170 = (pub_r000986_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_170) & 255;
    } else {
        stage_v_170 = (pub_r000986_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_170 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    if ((stage_v_6 & 63) > 47) {
        stage_v_171 = (pub_r000986_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_171) & 255;
    } else {
        stage_v_171 = (pub_r000986_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_171 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    if ((sec_r000986_3 & 63) > 20) {
        stage_v_172 = (pub_r000986_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_172) & 255;
    } else {
        stage_v_172 = (pub_r000986_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_172 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    if ((sec_r000986_15 & 63) > 28) {
        stage_v_173 = (pub_r000986_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_173) & 255;
    } else {
        stage_v_173 = (pub_r000986_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_173 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_173) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
