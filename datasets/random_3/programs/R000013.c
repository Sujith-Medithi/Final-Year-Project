/*
 * Benchmark Program: R000013
 * Family: direct_leakage
 * Generator Seed: 100207
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R000013_207 {
    int flags;
    int tag;
    int nonce;
    short counter;
    int round_key;
    int buffer[3];
};

struct FilterState_R000013_207 {
    short cutoff;
    int damping;
    int prev_out;
    int gain_db;
    int buffer[3];
};

union ColorPixel_R000013_207 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000013_207_0(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 15) & 127;
            break;
        case 3:
            acc = (acc + 6) & 127;
            break;
        case 0:
            acc = (acc + 11) & 127;
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
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000013_207_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int checksum = (st.buffer[0] * 3 + aux) & 63;
    if (checksum > 10) {
        acc = (acc + checksum * 2 + 5) & 127;
        aux ^= (checksum & 15);
    } else {
        acc = (acc - checksum + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_2(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 16) & 127;
            break;
        case 3:
            acc = (acc + 13) & 127;
            break;
        case 2:
            acc = (acc + 9) & 127;
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
    return (acc + aux) & 127;
}

int fn_R000013_207_3(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int factor = (st.buffer[0] * 3 + aux) & 63;
    if (factor > 46) {
        acc = (acc + factor * 2 + 5) & 127;
        aux ^= (factor & 15);
    } else {
        acc = (acc - factor + 11) & 127;
        aux += 3;
    }
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_4(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int mask = (st.buffer[0] * 3 + aux) & 63;
    if (mask > 32) {
        acc = (acc + mask * 2 + 5) & 127;
        aux ^= (mask & 15);
    } else {
        acc = (acc - mask + 11) & 127;
        aux += 3;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000013_207_5(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int stride = (st.buffer[0] * 3 + aux) & 63;
    if (stride > 44) {
        acc = (acc + stride * 2 + 5) & 127;
        aux ^= (stride & 15);
    } else {
        acc = (acc - stride + 11) & 127;
        aux += 3;
    }
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
    return (acc + aux) & 127;
}

int fn_R000013_207_6(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000013_207_7(int p0, int p1) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity = (st.buffer[0] * 3 + aux) & 63;
    if (parity > 18) {
        acc = (acc + parity * 2 + 5) & 127;
        aux ^= (parity & 15);
    } else {
        acc = (acc - parity + 11) & 127;
        aux += 3;
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
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 4) & 127;
            break;
        case 1:
            acc = (acc + 13) & 127;
            break;
        case 2:
            acc = (acc + 17) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_8(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 12) & 127;
            break;
        case 1:
            acc = (acc + 3) & 127;
            break;
        case 0:
            acc = (acc + 14) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int index_reg = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg > 18) {
        acc = (acc + index_reg * 2 + 5) & 127;
        aux ^= (index_reg & 15);
    } else {
        acc = (acc - index_reg + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int offset = (st.buffer[0] * 3 + aux) & 63;
    if (offset > 29) {
        acc = (acc + offset * 2 + 5) & 127;
        aux ^= (offset & 15);
    } else {
        acc = (acc - offset + 11) & 127;
        aux += 3;
    }
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 16) & 127;
            break;
        case 0:
            acc = (acc + 10) & 127;
            break;
        case 1:
            acc = (acc + 11) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000013_207_10(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int cursor = (st.buffer[0] * 3 + aux) & 63;
    if (cursor > 20) {
        acc = (acc + cursor * 2 + 5) & 127;
        aux ^= (cursor & 15);
    } else {
        acc = (acc - cursor + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 7) & 127;
            break;
        case 2:
            acc = (acc + 17) & 127;
            break;
        case 1:
            acc = (acc + 7) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_11(int p0, int p1) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 11) & 127;
            break;
        case 2:
            acc = (acc + 7) & 127;
            break;
        case 3:
            acc = (acc + 3) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int tally = (st.buffer[0] * 3 + aux) & 63;
    if (tally > 47) {
        acc = (acc + tally * 2 + 5) & 127;
        aux ^= (tally & 15);
    } else {
        acc = (acc - tally + 11) & 127;
        aux += 3;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_13(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_14(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 10) & 127;
            break;
        case 3:
            acc = (acc + 12) & 127;
            break;
        case 1:
            acc = (acc + 8) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int phase = (st.buffer[0] * 3 + aux) & 63;
    if (phase > 40) {
        acc = (acc + phase * 2 + 5) & 127;
        aux ^= (phase & 15);
    } else {
        acc = (acc - phase + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000013_207_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000013_207 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int main() {
    int sec_r000013_0;
    int sec_r000013_1;
    int sec_r000013_2;
    int pub_r000013_0;
    int out_sink = 0;
    int chk_sum = 0;

    struct CipherContext_R000013_207 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000013_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000013_0 + 4) & 15;
    st_var_0.buffer[2] = 7;
    struct FilterState_R000013_207 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000013_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000013_0 + 9) & 15;
    st_var_1.buffer[2] = 8;
    union ColorPixel_R000013_207 u_var = {0};
    u_var.word = (pub_r000013_0 + 0x42) & 255;
    int table[4] = { 7, 13, 29, 41 };

    int res_0 = fn_R000013_207_0((7), (8), (9));
    out_sink = (out_sink + res_0) & 255;
    chk_sum ^= (res_0 << 1) & 127;
    int res_1 = fn_R000013_207_1((9), (11), (13), (15));
    out_sink = (out_sink + res_1) & 255;
    chk_sum ^= (res_1 << 1) & 127;
    int res_2 = fn_R000013_207_2((11), (14), (17));
    out_sink = (out_sink + res_2) & 255;
    chk_sum ^= (res_2 << 1) & 127;
    int res_3 = fn_R000013_207_3((13), (17));
    out_sink = (out_sink + res_3) & 255;
    chk_sum ^= (res_3 << 1) & 127;
    int res_4 = fn_R000013_207_4((15), (20), (25));
    out_sink = (out_sink + res_4) & 255;
    chk_sum ^= (res_4 << 1) & 127;
    int res_5 = fn_R000013_207_5((17), (23), (29));
    out_sink = (out_sink + res_5) & 255;
    chk_sum ^= (res_5 << 1) & 127;
    int res_6 = fn_R000013_207_6((19), (26), (33));
    out_sink = (out_sink + res_6) & 255;
    chk_sum ^= (res_6 << 1) & 127;
    int res_7 = fn_R000013_207_7((21), (29));
    out_sink = (out_sink + res_7) & 255;
    chk_sum ^= (res_7 << 1) & 127;
    int res_8 = fn_R000013_207_8((23), (32));
    out_sink = (out_sink + res_8) & 255;
    chk_sum ^= (res_8 << 1) & 127;
    int res_9 = fn_R000013_207_9((25), (35), (45), (55));
    out_sink = (out_sink + res_9) & 255;
    chk_sum ^= (res_9 << 1) & 127;
    int res_10 = fn_R000013_207_10((27), (38), (49));
    out_sink = (out_sink + res_10) & 255;
    chk_sum ^= (res_10 << 1) & 127;
    int res_11 = fn_R000013_207_11((29), (41));
    out_sink = (out_sink + res_11) & 255;
    chk_sum ^= (res_11 << 1) & 127;
    int res_12 = fn_R000013_207_12((31), (44), (57), (70));
    out_sink = (out_sink + res_12) & 255;
    chk_sum ^= (res_12 << 1) & 127;
    int res_13 = fn_R000013_207_13((33), (47), (61));
    out_sink = (out_sink + res_13) & 255;
    chk_sum ^= (res_13 << 1) & 127;
    int res_14 = fn_R000013_207_14((35), (50), (65));
    out_sink = (out_sink + res_14) & 255;
    chk_sum ^= (res_14 << 1) & 127;
    int res_15 = fn_R000013_207_15((37), (53), (69), (85));
    out_sink = (out_sink + res_15) & 255;
    chk_sum ^= (res_15 << 1) & 127;
    int res_16 = fn_R000013_207_16((39), (56), (73), (90));
    out_sink = (out_sink + res_16) & 255;
    chk_sum ^= (res_16 << 1) & 127;

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_0.buffer[0] ^ 5) & 3;
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
    int stage_v_3 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_3 = (stage_v_3 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_3) & 127;
    }
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 13) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 28) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 18) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 33) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (out_sink > 100) ? (chk_sum & 31) : (15 & 31);
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= (stage_v_10 << 1) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = table[0];
    table[0] = (table[1] + 25) & 63;
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_0.buffer[2] * 2 + 49) & 63;
    if (stage_v_14 > 11) {
        out_sink = (out_sink + stage_v_14 - 5) & 255;
        if (stage_v_14 > 26) {
            chk_sum ^= (stage_v_14 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_14 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 18) & 15;
    int stage_v_17 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_17) & 255;
    chk_sum ^= stage_v_17;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 15) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 30) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[0] ^ 23) & 3;
    switch (stage_v_20) {
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

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] * 2 + 70) & 63;
    if (stage_v_21 > 18) {
        out_sink = (out_sink + stage_v_21 - 5) & 255;
        if (stage_v_21 > 33) {
            chk_sum ^= (stage_v_21 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_21 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_1.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 31) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 46) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_25 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 23) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 38) {
            chk_sum ^= (stage_v_35 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_35 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_0.buffer[0] ^ 41) & 3;
    switch (stage_v_38) {
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

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_39 = (stage_v_39 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_39) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 41) & 15;
    int stage_v_40 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= stage_v_40;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_41 = (stage_v_41 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_41) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_42 = (stage_v_42 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_42) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

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
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = table[1];
    table[1] = (table[2] + 107) & 63;
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 21) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 36) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
    switch (stage_v_62) {
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

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 40) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 55) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 13) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 28) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[0] ^ 79) & 3;
    switch (stage_v_76) {
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

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_1.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 20) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 35) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (out_sink > 100) ? (chk_sum & 31) : (83 & 31);
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= (stage_v_78 << 1) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = table[0];
    table[0] = (table[1] + 161) & 63;
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 25) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 40) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (out_sink > 100) ? (chk_sum & 31) : (87 & 31);
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= (stage_v_82 << 1) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (out_sink > 100) ? (chk_sum & 31) : (88 & 31);
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= (stage_v_83 << 1) & 127;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = table[1];
    table[1] = (table[2] + 171) & 63;
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_87 = (stage_v_87 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_88 = (stage_v_88 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (st_var_0.buffer[2] * 2 + 283) & 63;
    if (stage_v_92 > 40) {
        out_sink = (out_sink + stage_v_92 - 5) & 255;
        if (stage_v_92 > 55) {
            chk_sum ^= (stage_v_92 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_92 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_1.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 36) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 51) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = table[2];
    table[2] = (table[3] + 189) & 63;
    out_sink = (out_sink + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (out_sink > 100) ? (chk_sum & 31) : (103 & 31);
    out_sink = (out_sink + stage_v_98) & 255;
    chk_sum ^= (stage_v_98 << 1) & 127;

    /* Execution Pipeline Stage 99 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_0.buffer[2] * 2 + 319) & 63;
    if (stage_v_104 > 27) {
        out_sink = (out_sink + stage_v_104 - 5) & 255;
        if (stage_v_104 > 42) {
            chk_sum ^= (stage_v_104 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_104 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (out_sink > 100) ? (chk_sum & 31) : (113 & 31);
    out_sink = (out_sink + stage_v_108) & 255;
    chk_sum ^= (stage_v_108 << 1) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (out_sink > 100) ? (chk_sum & 31) : (114 & 31);
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= (stage_v_109 << 1) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_1.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 14) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 29) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_0.buffer[0] ^ 115) & 3;
    switch (stage_v_112) {
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

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[2] * 2 + 346) & 63;
    if (stage_v_113 > 12) {
        out_sink = (out_sink + stage_v_113 - 5) & 255;
        if (stage_v_113 > 27) {
            chk_sum ^= (stage_v_113 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_113 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_1.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (st_var_0.buffer[1] * 2 + 361) & 63;
    if (stage_v_118 > 12) {
        out_sink = (out_sink + stage_v_118 - 5) & 255;
        if (stage_v_118 > 27) {
            chk_sum ^= (stage_v_118 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_118 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_119 = (stage_v_119 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = table[0];
    table[0] = (table[1] + 241) & 63;
    out_sink = (out_sink + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_0.buffer[0] ^ 125) & 3;
    switch (stage_v_122) {
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

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 10) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 25) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = table[2];
    table[2] = (table[3] + 253) & 63;
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[1] * 2 + 388) & 63;
    if (stage_v_127 > 25) {
        out_sink = (out_sink + stage_v_127 - 5) & 255;
        if (stage_v_127 > 40) {
            chk_sum ^= (stage_v_127 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_127 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = table[0];
    table[0] = (table[1] + 257) & 63;
    out_sink = (out_sink + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (st_var_1.buffer[0] ^ 132) & 3;
    switch (stage_v_129) {
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

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_0.buffer[0] ^ 133) & 3;
    switch (stage_v_130) {
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

    /* Execution Pipeline Stage 131 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = table[0];
    table[0] = (table[1] + 265) & 63;
    out_sink = (out_sink + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 24) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 39) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_0.buffer[0] ^ 137) & 3;
    switch (stage_v_134) {
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

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_139 = (stage_v_139 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_140 = (stage_v_140 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = table[2];
    table[2] = (table[3] + 285) & 63;
    out_sink = (out_sink + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_1.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 16) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 31) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[1] * 2 + 442) & 63;
    if (stage_v_145 > 16) {
        out_sink = (out_sink + stage_v_145 - 5) & 255;
        if (stage_v_145 > 31) {
            chk_sum ^= (stage_v_145 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_145 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (out_sink > 100) ? (chk_sum & 31) : (152 & 31);
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= (stage_v_147 << 1) & 127;

    /* Execution Pipeline Stage 148 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 39) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 54) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 12) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 27) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[0] ^ 154) & 3;
    switch (stage_v_151) {
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

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (out_sink > 100) ? (chk_sum & 31) : (159 & 31);
    out_sink = (out_sink + stage_v_154) & 255;
    chk_sum ^= (stage_v_154 << 1) & 127;

    /* Execution Pipeline Stage 155 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 156) & 15;
    int stage_v_155 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= stage_v_155;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = table[0];
    table[0] = (table[1] + 313) & 63;
    out_sink = (out_sink + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 158) & 15;
    int stage_v_157 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_157) & 255;
    chk_sum ^= stage_v_157;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = table[2];
    table[2] = (table[3] + 317) & 63;
    out_sink = (out_sink + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = table[3];
    table[3] = (table[0] + 319) & 63;
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (out_sink > 100) ? (chk_sum & 31) : (166 & 31);
    out_sink = (out_sink + stage_v_161) & 255;
    chk_sum ^= (stage_v_161 << 1) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = table[2];
    table[2] = (table[3] + 325) & 63;
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (out_sink > 100) ? (chk_sum & 31) : (169 & 31);
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= (stage_v_164 << 1) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_166 = (stage_v_166 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (out_sink > 100) ? (chk_sum & 31) : (172 & 31);
    out_sink = (out_sink + stage_v_167) & 255;
    chk_sum ^= (stage_v_167 << 1) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 25) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 40) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[0] ^ 172) & 3;
    switch (stage_v_169) {
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

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = table[2];
    table[2] = (table[3] + 341) & 63;
    out_sink = (out_sink + stage_v_170) & 255;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_1.buffer[0] ^ 174) & 3;
    switch (stage_v_171) {
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

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_0.buffer[1] * 2 + 523) & 63;
    if (stage_v_172 > 13) {
        out_sink = (out_sink + stage_v_172 - 5) & 255;
        if (stage_v_172 > 28) {
            chk_sum ^= (stage_v_172 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_172 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_173 = (stage_v_173 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_173) & 127;
    }
    out_sink = (out_sink + stage_v_173) & 255;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_174 = (stage_v_174 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_174) & 127;
    }
    out_sink = (out_sink + stage_v_174) & 255;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_175 = (stage_v_175 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = table[0];
    table[0] = (table[1] + 353) & 63;
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] ^ 180) & 3;
    switch (stage_v_177) {
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

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_1.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 33) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 48) {
            chk_sum ^= (stage_v_179 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_179 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = table[0];
    table[0] = (table[1] + 361) & 63;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[0] ^ 184) & 3;
    switch (stage_v_181) {
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

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_0.buffer[0] ^ 187) & 3;
    switch (stage_v_184) {
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

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_185 = (stage_v_185 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_185) & 127;
    }
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] * 2 + 565) & 63;
    if (stage_v_186 > 24) {
        out_sink = (out_sink + stage_v_186 - 5) & 255;
        if (stage_v_186 > 39) {
            chk_sum ^= (stage_v_186 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_186 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (out_sink > 100) ? (chk_sum & 31) : (192 & 31);
    out_sink = (out_sink + stage_v_187) & 255;
    chk_sum ^= (stage_v_187 << 1) & 127;

    /* Execution Pipeline Stage 188 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 189) & 15;
    int stage_v_188 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_188) & 255;
    chk_sum ^= stage_v_188;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = table[1];
    table[1] = (table[2] + 379) & 63;
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_191 = (stage_v_191 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_191) & 127;
    }
    out_sink = (out_sink + stage_v_191) & 255;

    /* Security Information Flow: Family = direct_leakage */
    out_sink += sec_r000013_0;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
