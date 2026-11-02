/*
 * Benchmark Program: R000150
 * Family: bitwise_flow
 * Generator Seed: 314007
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct FilterState_R000150_4007 {
    int prev_in;
    short cutoff;
    int damping;
    short gain_db;
    int prev_out;
    int buffer[3];
};

struct CipherContext_R000150_4007 {
    int flags;
    int nonce;
    short round_key;
    int counter;
    int buffer[3];
};

struct MatrixBlock_R000150_4007 {
    int stride;
    int scale;
    int determinant;
    int dim;
    int buffer[3];
};

union TelemetryField_R000150_4007 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000150_4007_0(int p0, int p1, int p2) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int factor = (st.buffer[0] * 3 + aux) & 63;
    if (factor > 17) {
        acc = (acc + factor * 2 + 5) & 127;
        aux ^= (factor & 15);
    } else {
        acc = (acc - factor + 11) & 127;
        aux += 3;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000150_4007_1(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 3:
            acc = (acc + 6) & 127;
            break;
        case 1:
            acc = (acc + 12) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000150_4007_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int threshold = (st.buffer[0] * 3 + aux) & 63;
    if (threshold > 32) {
        acc = (acc + threshold * 2 + 5) & 127;
        aux ^= (threshold & 15);
    } else {
        acc = (acc - threshold + 11) & 127;
        aux += 3;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000150_4007_3(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 2:
            acc = (acc + 17) & 127;
            break;
        case 3:
            acc = (acc + 7) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_4(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 4) & 127;
            break;
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 2:
            acc = (acc + 16) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int tally = (st.buffer[0] * 3 + aux) & 63;
    if (tally > 36) {
        acc = (acc + tally * 2 + 5) & 127;
        aux ^= (tally & 15);
    } else {
        acc = (acc - tally + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_5(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 8) & 127;
            break;
        case 0:
            acc = (acc + 7) & 127;
            break;
        case 3:
            acc = (acc + 16) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_6(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 12) & 127;
            break;
        case 2:
            acc = (acc + 7) & 127;
            break;
        case 0:
            acc = (acc + 17) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000150_4007_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 10) & 127;
            break;
        case 1:
            acc = (acc + 5) & 127;
            break;
        case 2:
            acc = (acc + 10) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int scale = (st.buffer[0] * 3 + aux) & 63;
    if (scale > 32) {
        acc = (acc + scale * 2 + 5) & 127;
        aux ^= (scale & 15);
    } else {
        acc = (acc - scale + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_9(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int index_reg = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg > 50) {
        acc = (acc + index_reg * 2 + 5) & 127;
        aux ^= (index_reg & 15);
    } else {
        acc = (acc - index_reg + 11) & 127;
        aux += 3;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000150_4007_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_11(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 16) & 127;
            break;
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 1:
            acc = (acc + 11) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int index_reg = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg > 37) {
        acc = (acc + index_reg * 2 + 5) & 127;
        aux ^= (index_reg & 15);
    } else {
        acc = (acc - index_reg + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_12(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int metric = (st.buffer[0] * 3 + aux) & 63;
    if (metric > 45) {
        acc = (acc + metric * 2 + 5) & 127;
        aux ^= (metric & 15);
    } else {
        acc = (acc - metric + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000150_4007_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000150_4007 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 6) & 127;
            break;
        case 3:
            acc = (acc + 15) & 127;
            break;
        case 0:
            acc = (acc + 9) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int main() {
    int sec_r000150_0;
    int sec_r000150_1;
    int sec_r000150_2;
    int pub_r000150_0;
    int out_sink = 0;
    int chk_sum = 0;

    struct FilterState_R000150_4007 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000150_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000150_0 + 4) & 15;
    st_var_0.buffer[2] = 7;
    struct CipherContext_R000150_4007 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000150_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000150_0 + 9) & 15;
    st_var_1.buffer[2] = 8;
    struct MatrixBlock_R000150_4007 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000150_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000150_0 + 14) & 15;
    st_var_2.buffer[2] = 9;
    union TelemetryField_R000150_4007 u_var = {0};
    u_var.word = (pub_r000150_0 + 0x42) & 255;
    int table[4] = { 7, 13, 29, 41 };

    int res_0 = fn_R000150_4007_0((7), (8), (9));
    out_sink = (out_sink + res_0) & 255;
    chk_sum ^= (res_0 << 1) & 127;
    int res_1 = fn_R000150_4007_1((9), (11), (13));
    out_sink = (out_sink + res_1) & 255;
    chk_sum ^= (res_1 << 1) & 127;
    int res_2 = fn_R000150_4007_2((11), (14), (17), (20));
    out_sink = (out_sink + res_2) & 255;
    chk_sum ^= (res_2 << 1) & 127;
    int res_3 = fn_R000150_4007_3((13), (17));
    out_sink = (out_sink + res_3) & 255;
    chk_sum ^= (res_3 << 1) & 127;
    int res_4 = fn_R000150_4007_4((15), (20), (25));
    out_sink = (out_sink + res_4) & 255;
    chk_sum ^= (res_4 << 1) & 127;
    int res_5 = fn_R000150_4007_5((17), (23), (29));
    out_sink = (out_sink + res_5) & 255;
    chk_sum ^= (res_5 << 1) & 127;
    int res_6 = fn_R000150_4007_6((19), (26), (33));
    out_sink = (out_sink + res_6) & 255;
    chk_sum ^= (res_6 << 1) & 127;
    int res_7 = fn_R000150_4007_7((21), (29), (37), (45));
    out_sink = (out_sink + res_7) & 255;
    chk_sum ^= (res_7 << 1) & 127;
    int res_8 = fn_R000150_4007_8((23), (32), (41), (50));
    out_sink = (out_sink + res_8) & 255;
    chk_sum ^= (res_8 << 1) & 127;
    int res_9 = fn_R000150_4007_9((25), (35));
    out_sink = (out_sink + res_9) & 255;
    chk_sum ^= (res_9 << 1) & 127;
    int res_10 = fn_R000150_4007_10((27), (38), (49), (60));
    out_sink = (out_sink + res_10) & 255;
    chk_sum ^= (res_10 << 1) & 127;
    int res_11 = fn_R000150_4007_11((29), (41), (53));
    out_sink = (out_sink + res_11) & 255;
    chk_sum ^= (res_11 << 1) & 127;
    int res_12 = fn_R000150_4007_12((31), (44), (57));
    out_sink = (out_sink + res_12) & 255;
    chk_sum ^= (res_12 << 1) & 127;
    int res_13 = fn_R000150_4007_13((33), (47), (61), (75));
    out_sink = (out_sink + res_13) & 255;
    chk_sum ^= (res_13 << 1) & 127;

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_2 = (stage_v_2 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_2) & 127;
    }
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 31) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 46) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (out_sink > 100) ? (chk_sum & 31) : (13 & 31);
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= (stage_v_8 << 1) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_2.buffer[2] * 2 + 40) & 63;
    if (stage_v_11 > 37) {
        out_sink = (out_sink + stage_v_11 - 5) & 255;
        if (stage_v_11 > 52) {
            chk_sum ^= (stage_v_11 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_11 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_15 = (stage_v_15 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_15) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_18 = (stage_v_18 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_18) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_2.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 33) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 48) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (out_sink > 100) ? (chk_sum & 31) : (28 & 31);
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= (stage_v_23 << 1) & 127;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[2] * 2 + 85) & 63;
    if (stage_v_26 > 26) {
        out_sink = (out_sink + stage_v_26 - 5) & 255;
        if (stage_v_26 > 41) {
            chk_sum ^= (stage_v_26 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_26 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (out_sink > 100) ? (chk_sum & 31) : (32 & 31);
    out_sink = (out_sink + stage_v_27) & 255;
    chk_sum ^= (stage_v_27 << 1) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = table[0];
    table[0] = (table[1] + 57) & 63;
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 12) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 27) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] ^ 36) & 3;
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
    int stage_v_34 = table[2];
    table[2] = (table[3] + 69) & 63;
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 20) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 35) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[0] ^ 40) & 3;
    switch (stage_v_37) {
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

    /* Execution Pipeline Stage 38 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 39) & 15;
    int stage_v_38 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= stage_v_38;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_0.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_1.buffer[0] ^ 43) & 3;
    switch (stage_v_40) {
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

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = table[0];
    table[0] = (table[1] + 89) & 63;
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 49) & 15;
    int stage_v_48 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_48) & 255;
    chk_sum ^= stage_v_48;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 25) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 40) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (st_var_2.buffer[0] ^ 59) & 3;
    switch (stage_v_56) {
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

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = table[1];
    table[1] = (table[2] + 115) & 63;
    out_sink = (out_sink + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = table[2];
    table[2] = (table[3] + 117) & 63;
    out_sink = (out_sink + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = table[3];
    table[3] = (table[0] + 119) & 63;
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (st_var_0.buffer[0] * 2 + 205) & 63;
    if (stage_v_66 > 18) {
        out_sink = (out_sink + stage_v_66 - 5) & 255;
        if (stage_v_66 > 33) {
            chk_sum ^= (stage_v_66 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_66 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 16) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 31) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (out_sink > 100) ? (chk_sum & 31) : (73 & 31);
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= (stage_v_68 << 1) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] ^ 72) & 3;
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
    int stage_v_70 = (out_sink > 100) ? (chk_sum & 31) : (75 & 31);
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= (stage_v_70 << 1) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 40) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 55) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_74 = (stage_v_74 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_74) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 17) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 32) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_1.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[1] * 2 + 244) & 63;
    if (stage_v_79 > 31) {
        out_sink = (out_sink + stage_v_79 - 5) & 255;
        if (stage_v_79 > 46) {
            chk_sum ^= (stage_v_79 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_79 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = table[2];
    table[2] = (table[3] + 165) & 63;
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_83 = (stage_v_83 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_83) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (st_var_0.buffer[0] * 2 + 259) & 63;
    if (stage_v_84 > 20) {
        out_sink = (out_sink + stage_v_84 - 5) & 255;
        if (stage_v_84 > 35) {
            chk_sum ^= (stage_v_84 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_84 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 38) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 53) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[0] ^ 89) & 3;
    switch (stage_v_86) {
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

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_0.buffer[0] ^ 90) & 3;
    switch (stage_v_87) {
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

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 91) & 15;
    int stage_v_90 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= stage_v_90;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_2.buffer[0] ^ 95) & 3;
    switch (stage_v_92) {
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

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] ^ 96) & 3;
    switch (stage_v_93) {
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

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_94 = (stage_v_94 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] * 2 + 295) & 63;
    if (stage_v_96 > 25) {
        out_sink = (out_sink + stage_v_96 - 5) & 255;
        if (stage_v_96 > 40) {
            chk_sum ^= (stage_v_96 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_96 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 97 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 98) & 15;
    int stage_v_97 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_97) & 255;
    chk_sum ^= stage_v_97;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_98 = (stage_v_98 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_99 = (stage_v_99 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 20) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 35) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_102 = (stage_v_102 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_2.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] * 2 + 322) & 63;
    if (stage_v_105 > 39) {
        out_sink = (out_sink + stage_v_105 - 5) & 255;
        if (stage_v_105 > 54) {
            chk_sum ^= (stage_v_105 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_105 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = table[2];
    table[2] = (table[3] + 213) & 63;
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (st_var_2.buffer[0] ^ 110) & 3;
    switch (stage_v_107) {
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

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_109 = (stage_v_109 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (out_sink > 100) ? (chk_sum & 31) : (115 & 31);
    out_sink = (out_sink + stage_v_110) & 255;
    chk_sum ^= (stage_v_110 << 1) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_0.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 40) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 55) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = table[0];
    table[0] = (table[1] + 225) & 63;
    out_sink = (out_sink + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 114) & 15;
    int stage_v_113 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_113) & 255;
    chk_sum ^= stage_v_113;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 29) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 44) {
            chk_sum ^= (stage_v_114 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_114 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[0] ^ 118) & 3;
    switch (stage_v_115) {
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

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_2.buffer[2] * 2 + 355) & 63;
    if (stage_v_116 > 19) {
        out_sink = (out_sink + stage_v_116 - 5) & 255;
        if (stage_v_116 > 34) {
            chk_sum ^= (stage_v_116 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_116 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_1.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 22) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 37) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 120) & 15;
    int stage_v_119 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= stage_v_119;

    /* Execution Pipeline Stage 120 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 121) & 15;
    int stage_v_120 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= stage_v_120;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_122 = (stage_v_122 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 29) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 44) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_124 = (stage_v_124 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = table[1];
    table[1] = (table[2] + 251) & 63;
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_2.buffer[0] ^ 131) & 3;
    switch (stage_v_128) {
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

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_0.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 17) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 32) {
            chk_sum ^= (stage_v_131 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_131 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 134) & 15;
    int stage_v_133 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= stage_v_133;

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (out_sink > 100) ? (chk_sum & 31) : (141 & 31);
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= (stage_v_136 << 1) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[0] ^ 142) & 3;
    switch (stage_v_139) {
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

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_2.buffer[0] ^ 143) & 3;
    switch (stage_v_140) {
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

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (st_var_0.buffer[0] * 2 + 430) & 63;
    if (stage_v_141 > 13) {
        out_sink = (out_sink + stage_v_141 - 5) & 255;
        if (stage_v_141 > 28) {
            chk_sum ^= (stage_v_141 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_141 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[0] ^ 145) & 3;
    switch (stage_v_142) {
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

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (out_sink > 100) ? (chk_sum & 31) : (148 & 31);
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= (stage_v_143 << 1) & 127;

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_145 = (stage_v_145 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 147) & 15;
    int stage_v_146 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_146) & 255;
    chk_sum ^= stage_v_146;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = table[0];
    table[0] = (table[1] + 297) & 63;
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (out_sink > 100) ? (chk_sum & 31) : (155 & 31);
    out_sink = (out_sink + stage_v_150) & 255;
    chk_sum ^= (stage_v_150 << 1) & 127;

    /* Execution Pipeline Stage 151 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 152) & 15;
    int stage_v_151 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= stage_v_151;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_155 = (stage_v_155 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 26) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 41) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (st_var_1.buffer[0] ^ 163) & 3;
    switch (stage_v_160) {
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

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_2.buffer[0] ^ 164) & 3;
    switch (stage_v_161) {
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

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[1] * 2 + 496) & 63;
    if (stage_v_163 > 14) {
        out_sink = (out_sink + stage_v_163 - 5) & 255;
        if (stage_v_163 > 29) {
            chk_sum ^= (stage_v_163 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_163 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 164 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 165) & 15;
    int stage_v_164 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= stage_v_164;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_0.buffer[0] * 2 + 502) & 63;
    if (stage_v_165 > 14) {
        out_sink = (out_sink + stage_v_165 - 5) & 255;
        if (stage_v_165 > 29) {
            chk_sum ^= (stage_v_165 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_165 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (st_var_1.buffer[0] ^ 169) & 3;
    switch (stage_v_166) {
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

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
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

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (out_sink > 100) ? (chk_sum & 31) : (174 & 31);
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= (stage_v_169 << 1) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[2] * 2 + 517) & 63;
    if (stage_v_170 > 14) {
        out_sink = (out_sink + stage_v_170 - 5) & 255;
        if (stage_v_170 > 29) {
            chk_sum ^= (stage_v_170 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_170 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_1.buffer[0] ^ 175) & 3;
    switch (stage_v_172) {
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

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = table[1];
    table[1] = (table[2] + 347) & 63;
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (out_sink > 100) ? (chk_sum & 31) : (179 & 31);
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= (stage_v_174 << 1) & 127;

    /* Execution Pipeline Stage 175 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 176) & 15;
    int stage_v_175 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= stage_v_175;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 178) & 15;
    int stage_v_177 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= stage_v_177;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_1.buffer[0] ^ 181) & 3;
    switch (stage_v_178) {
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

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 21) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 36) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (out_sink > 100) ? (chk_sum & 31) : (185 & 31);
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= (stage_v_180 << 1) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (out_sink > 100) ? (chk_sum & 31) : (187 & 31);
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= (stage_v_182 << 1) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = table[3];
    table[3] = (table[0] + 367) & 63;
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = table[2];
    table[2] = (table[3] + 373) & 63;
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[1] * 2 + 568) & 63;
    if (stage_v_187 > 32) {
        out_sink = (out_sink + stage_v_187 - 5) & 255;
        if (stage_v_187 > 47) {
            chk_sum ^= (stage_v_187 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_187 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_188 = (stage_v_188 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_188) & 127;
    }
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (out_sink > 100) ? (chk_sum & 31) : (195 & 31);
    out_sink = (out_sink + stage_v_190) & 255;
    chk_sum ^= (stage_v_190 << 1) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_2.buffer[2] * 2 + 580) & 63;
    if (stage_v_191 > 23) {
        out_sink = (out_sink + stage_v_191 - 5) & 255;
        if (stage_v_191 > 38) {
            chk_sum ^= (stage_v_191 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_191 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 192 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 193) & 15;
    int stage_v_192 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_192) & 255;
    chk_sum ^= stage_v_192;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[0] ^ 196) & 3;
    switch (stage_v_193) {
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

    /* Security Information Flow: Family = bitwise_flow */
    int b_w1 = (sec_r000150_0 << 2) & 124;
    int b_w2 = (sec_r000150_0 >> 2) & 31;
    int b_w3 = (b_w1 ^ b_w2) | 5;
    out_sink += b_w3 & 63;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
