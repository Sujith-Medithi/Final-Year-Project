/*
 * Benchmark Program: R000186
 * Family: secret_dependent_array
 * Generator Seed: 317607
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000186_7607 {
    int sample_rate;
    short rms;
    short channels;
    int envelope;
    int buffer[3];
};

struct FilterState_R000186_7607 {
    int prev_in;
    int cutoff;
    int prev_out;
    int damping;
    int buffer[3];
};

struct MatrixBlock_R000186_7607 {
    int determinant;
    int dim;
    int scale;
    short trace;
    short stride;
    int buffer[3];
};

union RegisterBank_R000186_7607 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000186_7607_0(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000186_7607_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 9) & 127;
            break;
        case 0:
            acc = (acc + 9) & 127;
            break;
        case 1:
            acc = (acc + 6) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int cursor = (st.buffer[0] * 3 + aux) & 63;
    if (cursor > 16) {
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
    return (acc + aux) & 127;
}

int fn_R000186_7607_2(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int vector = (st.buffer[0] * 3 + aux) & 63;
    if (vector > 40) {
        acc = (acc + vector * 2 + 5) & 127;
        aux ^= (vector & 15);
    } else {
        acc = (acc - vector + 11) & 127;
        aux += 3;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000186_7607_3(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int cursor = (st.buffer[0] * 3 + aux) & 63;
    if (cursor > 12) {
        acc = (acc + cursor * 2 + 5) & 127;
        aux ^= (cursor & 15);
    } else {
        acc = (acc - cursor + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_4(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int quantum = (st.buffer[0] * 3 + aux) & 63;
    if (quantum > 36) {
        acc = (acc + quantum * 2 + 5) & 127;
        aux ^= (quantum & 15);
    } else {
        acc = (acc - quantum + 11) & 127;
        aux += 3;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 4) & 127;
            break;
        case 2:
            acc = (acc + 15) & 127;
            break;
        case 1:
            acc = (acc + 16) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int quantum = (st.buffer[0] * 3 + aux) & 63;
    if (quantum > 41) {
        acc = (acc + quantum * 2 + 5) & 127;
        aux ^= (quantum & 15);
    } else {
        acc = (acc - quantum + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_6(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 4) & 127;
            break;
        case 1:
            acc = (acc + 3) & 127;
            break;
        case 0:
            acc = (acc + 15) & 127;
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
    int pivot = (st.buffer[0] * 3 + aux) & 63;
    if (pivot > 30) {
        acc = (acc + pivot * 2 + 5) & 127;
        aux ^= (pivot & 15);
    } else {
        acc = (acc - pivot + 11) & 127;
        aux += 3;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000186_7607_7(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 7) & 127;
            break;
        case 0:
            acc = (acc + 5) & 127;
            break;
        case 3:
            acc = (acc + 9) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int coefficient = (st.buffer[0] * 3 + aux) & 63;
    if (coefficient > 11) {
        acc = (acc + coefficient * 2 + 5) & 127;
        aux ^= (coefficient & 15);
    } else {
        acc = (acc - coefficient + 11) & 127;
        aux += 3;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000186_7607_8(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
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
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int quotient = (st.buffer[0] * 3 + aux) & 63;
    if (quotient > 18) {
        acc = (acc + quotient * 2 + 5) & 127;
        aux ^= (quotient & 15);
    } else {
        acc = (acc - quotient + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_9(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int damping = (st.buffer[0] * 3 + aux) & 63;
    if (damping > 40) {
        acc = (acc + damping * 2 + 5) & 127;
        aux ^= (damping & 15);
    } else {
        acc = (acc - damping + 11) & 127;
        aux += 3;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_10(int p0, int p1, int p2) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 14) & 127;
            break;
        case 2:
            acc = (acc + 16) & 127;
            break;
        case 1:
            acc = (acc + 6) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int tally = (st.buffer[0] * 3 + aux) & 63;
    if (tally > 37) {
        acc = (acc + tally * 2 + 5) & 127;
        aux ^= (tally & 15);
    } else {
        acc = (acc - tally + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int factor = (st.buffer[0] * 3 + aux) & 63;
    if (factor > 19) {
        acc = (acc + factor * 2 + 5) & 127;
        aux ^= (factor & 15);
    } else {
        acc = (acc - factor + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_12(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 6) & 127;
            break;
        case 3:
            acc = (acc + 10) & 127;
            break;
        case 2:
            acc = (acc + 13) & 127;
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
    int cursor = (st.buffer[0] * 3 + aux) & 63;
    if (cursor > 19) {
        acc = (acc + cursor * 2 + 5) & 127;
        aux ^= (cursor & 15);
    } else {
        acc = (acc - cursor + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 2:
            acc = (acc + 6) & 127;
            break;
        case 3:
            acc = (acc + 5) & 127;
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
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int scale = (st.buffer[0] * 3 + aux) & 63;
    if (scale > 26) {
        acc = (acc + scale * 2 + 5) & 127;
        aux ^= (scale & 15);
    } else {
        acc = (acc - scale + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_15(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000186_7607_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 3) & 127;
            break;
        case 2:
            acc = (acc + 3) & 127;
            break;
        case 3:
            acc = (acc + 6) & 127;
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

int fn_R000186_7607_17(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 6) & 127;
            break;
        case 0:
            acc = (acc + 4) & 127;
            break;
        case 2:
            acc = (acc + 9) & 127;
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
    return (acc + aux) & 127;
}

int fn_R000186_7607_18(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000186_7607 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int main() {
    int sec_r000186_0;
    int pub_r000186_0;
    int pub_r000186_1;
    int pub_r000186_2;
    int out_sink = 0;
    int chk_sum = 0;

    struct AudioFrame_R000186_7607 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000186_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000186_0 + 4) & 15;
    st_var_0.buffer[2] = 7;
    struct FilterState_R000186_7607 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000186_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000186_0 + 9) & 15;
    st_var_1.buffer[2] = 8;
    struct MatrixBlock_R000186_7607 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000186_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000186_0 + 14) & 15;
    st_var_2.buffer[2] = 9;
    union RegisterBank_R000186_7607 u_var = {0};
    u_var.word = (pub_r000186_0 + 0x42) & 255;
    int table[4] = { 7, 13, 29, 41 };

    int res_0 = fn_R000186_7607_0((7), (8));
    out_sink = (out_sink + res_0) & 255;
    chk_sum ^= (res_0 << 1) & 127;
    int res_1 = fn_R000186_7607_1((9), (11), (13), (15));
    out_sink = (out_sink + res_1) & 255;
    chk_sum ^= (res_1 << 1) & 127;
    int res_2 = fn_R000186_7607_2((11), (14), (17));
    out_sink = (out_sink + res_2) & 255;
    chk_sum ^= (res_2 << 1) & 127;
    int res_3 = fn_R000186_7607_3((13), (17));
    out_sink = (out_sink + res_3) & 255;
    chk_sum ^= (res_3 << 1) & 127;
    int res_4 = fn_R000186_7607_4((15), (20), (25));
    out_sink = (out_sink + res_4) & 255;
    chk_sum ^= (res_4 << 1) & 127;
    int res_5 = fn_R000186_7607_5((17), (23), (29), (35));
    out_sink = (out_sink + res_5) & 255;
    chk_sum ^= (res_5 << 1) & 127;
    int res_6 = fn_R000186_7607_6((19), (26), (33));
    out_sink = (out_sink + res_6) & 255;
    chk_sum ^= (res_6 << 1) & 127;
    int res_7 = fn_R000186_7607_7((21), (29), (37));
    out_sink = (out_sink + res_7) & 255;
    chk_sum ^= (res_7 << 1) & 127;
    int res_8 = fn_R000186_7607_8((23), (32));
    out_sink = (out_sink + res_8) & 255;
    chk_sum ^= (res_8 << 1) & 127;
    int res_9 = fn_R000186_7607_9((25), (35));
    out_sink = (out_sink + res_9) & 255;
    chk_sum ^= (res_9 << 1) & 127;
    int res_10 = fn_R000186_7607_10((27), (38), (49));
    out_sink = (out_sink + res_10) & 255;
    chk_sum ^= (res_10 << 1) & 127;
    int res_11 = fn_R000186_7607_11((29), (41), (53), (65));
    out_sink = (out_sink + res_11) & 255;
    chk_sum ^= (res_11 << 1) & 127;
    int res_12 = fn_R000186_7607_12((31), (44), (57));
    out_sink = (out_sink + res_12) & 255;
    chk_sum ^= (res_12 << 1) & 127;
    int res_13 = fn_R000186_7607_13((33), (47), (61), (75));
    out_sink = (out_sink + res_13) & 255;
    chk_sum ^= (res_13 << 1) & 127;
    int res_14 = fn_R000186_7607_14((35), (50), (65), (80));
    out_sink = (out_sink + res_14) & 255;
    chk_sum ^= (res_14 << 1) & 127;
    int res_15 = fn_R000186_7607_15((37), (53), (69));
    out_sink = (out_sink + res_15) & 255;
    chk_sum ^= (res_15 << 1) & 127;
    int res_16 = fn_R000186_7607_16((39), (56), (73), (90));
    out_sink = (out_sink + res_16) & 255;
    chk_sum ^= (res_16 << 1) & 127;
    int res_17 = fn_R000186_7607_17((41), (59), (77), (95));
    out_sink = (out_sink + res_17) & 255;
    chk_sum ^= (res_17 << 1) & 127;
    int res_18 = fn_R000186_7607_18((43), (62), (81), (100));
    out_sink = (out_sink + res_18) & 255;
    chk_sum ^= (res_18 << 1) & 127;

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_1 = (stage_v_1 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_1) & 127;
    }
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 25) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 40) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = table[3];
    table[3] = (table[0] + 15) & 63;
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 10) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 25) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

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
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_16 = (stage_v_16 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_16) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 33) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 48) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 15) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 30) {
            chk_sum ^= (stage_v_18 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_18 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 3; step++) {
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
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_26 = (stage_v_26 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_26) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 34) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 49) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = table[2];
    table[2] = (table[3] + 61) & 63;
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_2.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (st_var_1.buffer[1] * 2 + 118) & 63;
    if (stage_v_37 > 14) {
        out_sink = (out_sink + stage_v_37 - 5) & 255;
        if (stage_v_37 > 29) {
            chk_sum ^= (stage_v_37 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_37 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (out_sink > 100) ? (chk_sum & 31) : (43 & 31);
    out_sink = (out_sink + stage_v_38) & 255;
    chk_sum ^= (stage_v_38 << 1) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 41 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 42) & 15;
    int stage_v_41 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= stage_v_41;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 27) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 42) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 47 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 48) & 15;
    int stage_v_47 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_47) & 255;
    chk_sum ^= stage_v_47;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_50 = (stage_v_50 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_50) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 54) & 15;
    int stage_v_53 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= stage_v_53;

    /* Execution Pipeline Stage 54 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 55) & 15;
    int stage_v_54 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= stage_v_54;

    /* Execution Pipeline Stage 55 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 56) & 15;
    int stage_v_55 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= stage_v_55;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = table[0];
    table[0] = (table[1] + 113) & 63;
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 62) & 15;
    int stage_v_61 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= stage_v_61;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_2.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 33) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 48) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] * 2 + 196) & 63;
    if (stage_v_63 > 33) {
        out_sink = (out_sink + stage_v_63 - 5) & 255;
        if (stage_v_63 > 48) {
            chk_sum ^= (stage_v_63 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_63 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[1] * 2 + 199) & 63;
    if (stage_v_64 > 33) {
        out_sink = (out_sink + stage_v_64 - 5) & 255;
        if (stage_v_64 > 48) {
            chk_sum ^= (stage_v_64 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_64 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 67) & 15;
    int stage_v_66 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= stage_v_66;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 24) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 39) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = table[2];
    table[2] = (table[3] + 141) & 63;
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = table[3];
    table[3] = (table[0] + 143) & 63;
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] ^ 75) & 3;
    switch (stage_v_72) {
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

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_73 = (stage_v_73 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_73) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_0.buffer[0] ^ 78) & 3;
    switch (stage_v_75) {
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

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[0] ^ 80) & 3;
    switch (stage_v_77) {
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

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (st_var_0.buffer[0] * 2 + 241) & 63;
    if (stage_v_78 > 10) {
        out_sink = (out_sink + stage_v_78 - 5) & 255;
        if (stage_v_78 > 25) {
            chk_sum ^= (stage_v_78 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_78 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = table[3];
    table[3] = (table[0] + 159) & 63;
    out_sink = (out_sink + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (st_var_2.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = table[1];
    table[1] = (table[2] + 163) & 63;
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_82 = (stage_v_82 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_82) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (out_sink > 100) ? (chk_sum & 31) : (90 & 31);
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= (stage_v_85 << 1) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (out_sink > 100) ? (chk_sum & 31) : (91 & 31);
    out_sink = (out_sink + stage_v_86) & 255;
    chk_sum ^= (stage_v_86 << 1) & 127;

    /* Execution Pipeline Stage 87 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[1] * 2 + 271) & 63;
    if (stage_v_88 > 22) {
        out_sink = (out_sink + stage_v_88 - 5) & 255;
        if (stage_v_88 > 37) {
            chk_sum ^= (stage_v_88 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_88 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (st_var_2.buffer[0] ^ 92) & 3;
    switch (stage_v_89) {
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

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (out_sink > 100) ? (chk_sum & 31) : (96 & 31);
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= (stage_v_91 << 1) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 94 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 96) & 15;
    int stage_v_95 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_95) & 255;
    chk_sum ^= stage_v_95;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = table[1];
    table[1] = (table[2] + 195) & 63;
    out_sink = (out_sink + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = table[2];
    table[2] = (table[3] + 197) & 63;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = table[0];
    table[0] = (table[1] + 201) & 63;
    out_sink = (out_sink + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (out_sink > 100) ? (chk_sum & 31) : (106 & 31);
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= (stage_v_101 << 1) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] * 2 + 313) & 63;
    if (stage_v_102 > 24) {
        out_sink = (out_sink + stage_v_102 - 5) & 255;
        if (stage_v_102 > 39) {
            chk_sum ^= (stage_v_102 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_102 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (out_sink > 100) ? (chk_sum & 31) : (108 & 31);
    out_sink = (out_sink + stage_v_103) & 255;
    chk_sum ^= (stage_v_103 << 1) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (st_var_2.buffer[0] ^ 107) & 3;
    switch (stage_v_104) {
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

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_105 = (stage_v_105 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 107) & 15;
    int stage_v_106 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= stage_v_106;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] ^ 111) & 3;
    switch (stage_v_108) {
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

    /* Execution Pipeline Stage 109 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 110) & 15;
    int stage_v_109 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_109) & 255;
    chk_sum ^= stage_v_109;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (st_var_2.buffer[0] ^ 113) & 3;
    switch (stage_v_110) {
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = table[3];
    table[3] = (table[0] + 223) & 63;
    out_sink = (out_sink + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_1.buffer[0] ^ 115) & 3;
    switch (stage_v_112) {
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

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_2.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = table[2];
    table[2] = (table[3] + 229) & 63;
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_115 = (stage_v_115 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = table[1];
    table[1] = (table[2] + 235) & 63;
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = table[2];
    table[2] = (table[3] + 237) & 63;
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_119 = (stage_v_119 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (out_sink > 100) ? (chk_sum & 31) : (125 & 31);
    out_sink = (out_sink + stage_v_120) & 255;
    chk_sum ^= (stage_v_120 << 1) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_121 = (stage_v_121 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (st_var_2.buffer[0] ^ 125) & 3;
    switch (stage_v_122) {
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
    int stage_v_124 = (out_sink > 100) ? (chk_sum & 31) : (129 & 31);
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= (stage_v_124 << 1) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_2.buffer[0] ^ 128) & 3;
    switch (stage_v_125) {
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

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (out_sink > 100) ? (chk_sum & 31) : (133 & 31);
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= (stage_v_128 << 1) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = table[2];
    table[2] = (table[3] + 261) & 63;
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 132) & 15;
    int stage_v_131 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_131) & 255;
    chk_sum ^= stage_v_131;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 134) & 15;
    int stage_v_133 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_133) & 255;
    chk_sum ^= stage_v_133;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (out_sink > 100) ? (chk_sum & 31) : (139 & 31);
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= (stage_v_134 << 1) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_2.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 139) & 15;
    int stage_v_138 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= stage_v_138;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (st_var_1.buffer[0] ^ 142) & 3;
    switch (stage_v_139) {
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

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
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
    int stage_v_143 = (out_sink > 100) ? (chk_sum & 31) : (148 & 31);
    out_sink = (out_sink + stage_v_143) & 255;
    chk_sum ^= (stage_v_143 << 1) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_144 = (stage_v_144 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 146) & 15;
    int stage_v_145 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= stage_v_145;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_2.buffer[2] * 2 + 445) & 63;
    if (stage_v_146 > 33) {
        out_sink = (out_sink + stage_v_146 - 5) & 255;
        if (stage_v_146 > 48) {
            chk_sum ^= (stage_v_146 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_146 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_1.buffer[0] ^ 151) & 3;
    switch (stage_v_148) {
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

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 24) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 39) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (st_var_1.buffer[1] * 2 + 460) & 63;
    if (stage_v_151 > 33) {
        out_sink = (out_sink + stage_v_151 - 5) & 255;
        if (stage_v_151 > 48) {
            chk_sum ^= (stage_v_151 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_151 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (st_var_2.buffer[2] * 2 + 463) & 63;
    if (stage_v_152 > 33) {
        out_sink = (out_sink + stage_v_152 - 5) & 255;
        if (stage_v_152 > 48) {
            chk_sum ^= (stage_v_152 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_152 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (st_var_0.buffer[0] ^ 156) & 3;
    switch (stage_v_153) {
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

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (st_var_0.buffer[0] * 2 + 475) & 63;
    if (stage_v_156 > 30) {
        out_sink = (out_sink + stage_v_156 - 5) & 255;
        if (stage_v_156 > 45) {
            chk_sum ^= (stage_v_156 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_156 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 20) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 35) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] * 2 + 484) & 63;
    if (stage_v_159 > 18) {
        out_sink = (out_sink + stage_v_159 - 5) & 255;
        if (stage_v_159 > 33) {
            chk_sum ^= (stage_v_159 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_159 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 160 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 161) & 15;
    int stage_v_160 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_160) & 255;
    chk_sum ^= stage_v_160;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (st_var_0.buffer[0] ^ 165) & 3;
    switch (stage_v_162) {
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

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (out_sink > 100) ? (chk_sum & 31) : (168 & 31);
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= (stage_v_163 << 1) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = table[3];
    table[3] = (table[0] + 335) & 63;
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 13) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 28) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_169 = (stage_v_169 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_169) & 127;
    }
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_2.buffer[0] ^ 173) & 3;
    switch (stage_v_170) {
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

    /* Execution Pipeline Stage 171 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 172) & 15;
    int stage_v_171 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= stage_v_171;

    /* Execution Pipeline Stage 172 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 173) & 15;
    int stage_v_172 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_172) & 255;
    chk_sum ^= stage_v_172;

    /* Execution Pipeline Stage 173 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 175) & 15;
    int stage_v_174 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= stage_v_174;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_175 = (stage_v_175 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_175) & 127;
    }
    out_sink = (out_sink + stage_v_175) & 255;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (st_var_2.buffer[2] * 2 + 535) & 63;
    if (stage_v_176 > 39) {
        out_sink = (out_sink + stage_v_176 - 5) & 255;
        if (stage_v_176 > 54) {
            chk_sum ^= (stage_v_176 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_176 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_0.buffer[0] ^ 180) & 3;
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
    int stage_v_178 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_178 = (stage_v_178 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_178) & 127;
    }
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_2.buffer[2] * 2 + 544) & 63;
    if (stage_v_179 > 17) {
        out_sink = (out_sink + stage_v_179 - 5) & 255;
        if (stage_v_179 > 32) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 182) & 15;
    int stage_v_181 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_181) & 255;
    chk_sum ^= stage_v_181;

    /* Execution Pipeline Stage 182 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 183) & 15;
    int stage_v_182 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_182) & 255;
    chk_sum ^= stage_v_182;

    /* Execution Pipeline Stage 183 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 184) & 15;
    int stage_v_183 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= stage_v_183;

    /* Execution Pipeline Stage 184 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 185) & 15;
    int stage_v_184 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= stage_v_184;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (out_sink > 100) ? (chk_sum & 31) : (190 & 31);
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= (stage_v_185 << 1) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] ^ 189) & 3;
    switch (stage_v_186) {
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

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[0] ^ 190) & 3;
    switch (stage_v_187) {
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

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 190) & 15;
    int stage_v_189 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_189) & 255;
    chk_sum ^= stage_v_189;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (st_var_1.buffer[1] * 2 + 577) & 63;
    if (stage_v_190 > 33) {
        out_sink = (out_sink + stage_v_190 - 5) & 255;
        if (stage_v_190 > 48) {
            chk_sum ^= (stage_v_190 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_190 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (out_sink > 100) ? (chk_sum & 31) : (196 & 31);
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= (stage_v_191 << 1) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_192 = (stage_v_192 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_192) & 127;
    }
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = table[1];
    table[1] = (table[2] + 387) & 63;
    out_sink = (out_sink + stage_v_193) & 255;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (st_var_2.buffer[2] * 2 + 589) & 63;
    if (stage_v_194 > 19) {
        out_sink = (out_sink + stage_v_194 - 5) & 255;
        if (stage_v_194 > 34) {
            chk_sum ^= (stage_v_194 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_194 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_0.buffer[0] * 2 + 592) & 63;
    if (stage_v_195 > 20) {
        out_sink = (out_sink + stage_v_195 - 5) & 255;
        if (stage_v_195 > 35) {
            chk_sum ^= (stage_v_195 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_195 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_1.buffer[1] * 2 + 595) & 63;
    if (stage_v_196 > 32) {
        out_sink = (out_sink + stage_v_196 - 5) & 255;
        if (stage_v_196 > 47) {
            chk_sum ^= (stage_v_196 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_196 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Security Information Flow: Family = secret_dependent_array */
    int s_lut[4] = { 19, 43, 71, 97 };
    int s_idx = (sec_r000186_0 & 3);
    out_sink += s_lut[s_idx];

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
