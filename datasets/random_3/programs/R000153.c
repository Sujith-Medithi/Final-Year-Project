/*
 * Benchmark Program: R000153
 * Family: implicit_flow
 * Generator Seed: 314307
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct AudioFrame_R000153_4307 {
    int peak;
    int sample_rate;
    int rms;
    int channels;
    int buffer[3];
};

struct EventLog_R000153_4307 {
    short severity;
    int facility;
    int timestamp;
    int buffer[3];
};

struct FilterState_R000153_4307 {
    short prev_out;
    int gain_db;
    int damping;
    int cutoff;
    int prev_in;
    int buffer[3];
};

union TelemetryField_R000153_4307 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000153_4307_0(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int stride = (st.buffer[0] * 3 + aux) & 63;
    if (stride > 41) {
        acc = (acc + stride * 2 + 5) & 127;
        aux ^= (stride & 15);
    } else {
        acc = (acc - stride + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_1(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int parity = (st.buffer[0] * 3 + aux) & 63;
    if (parity > 40) {
        acc = (acc + parity * 2 + 5) & 127;
        aux ^= (parity & 15);
    } else {
        acc = (acc - parity + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_2(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 10) & 127;
            break;
        case 2:
            acc = (acc + 14) & 127;
            break;
        case 0:
            acc = (acc + 5) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_3(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 17) & 127;
            break;
        case 0:
            acc = (acc + 4) & 127;
            break;
        case 1:
            acc = (acc + 11) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int offset = (st.buffer[0] * 3 + aux) & 63;
    if (offset > 34) {
        acc = (acc + offset * 2 + 5) & 127;
        aux ^= (offset & 15);
    } else {
        acc = (acc - offset + 11) & 127;
        aux += 3;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000153_4307_4(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quantum = (st.buffer[0] * 3 + aux) & 63;
    if (quantum > 11) {
        acc = (acc + quantum * 2 + 5) & 127;
        aux ^= (quantum & 15);
    } else {
        acc = (acc - quantum + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_5(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 8) & 127;
            break;
        case 3:
            acc = (acc + 9) & 127;
            break;
        case 1:
            acc = (acc + 17) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int stride = (st.buffer[0] * 3 + aux) & 63;
    if (stride > 40) {
        acc = (acc + stride * 2 + 5) & 127;
        aux ^= (stride & 15);
    } else {
        acc = (acc - stride + 11) & 127;
        aux += 3;
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

int fn_R000153_4307_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 15) & 127;
            break;
        case 1:
            acc = (acc + 5) & 127;
            break;
        case 2:
            acc = (acc + 13) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_7(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_8(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int stride = (st.buffer[0] * 3 + aux) & 63;
    if (stride > 12) {
        acc = (acc + stride * 2 + 5) & 127;
        aux ^= (stride & 15);
    } else {
        acc = (acc - stride + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int offset = (st.buffer[0] * 3 + aux) & 63;
    if (offset > 50) {
        acc = (acc + offset * 2 + 5) & 127;
        aux ^= (offset & 15);
    } else {
        acc = (acc - offset + 11) & 127;
        aux += 3;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 16) & 127;
            break;
        case 0:
            acc = (acc + 15) & 127;
            break;
        case 3:
            acc = (acc + 6) & 127;
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

int fn_R000153_4307_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    switch ((p0 + aux) & 3) {
        case 1:
            acc = (acc + 8) & 127;
            break;
        case 3:
            acc = (acc + 14) & 127;
            break;
        case 0:
            acc = (acc + 7) & 127;
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
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_11(int p0, int p1, int p2) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
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
    int threshold = (st.buffer[0] * 3 + aux) & 63;
    if (threshold > 25) {
        acc = (acc + threshold * 2 + 5) & 127;
        aux ^= (threshold & 15);
    } else {
        acc = (acc - threshold + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_12(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int tally = (st.buffer[0] * 3 + aux) & 63;
    if (tally > 46) {
        acc = (acc + tally * 2 + 5) & 127;
        aux ^= (tally & 15);
    } else {
        acc = (acc - tally + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_13(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 13) & 127;
            break;
        case 0:
            acc = (acc + 4) & 127;
            break;
        case 1:
            acc = (acc + 17) & 127;
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
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int metric = (st.buffer[0] * 3 + aux) & 63;
    if (metric > 17) {
        acc = (acc + metric * 2 + 5) & 127;
        aux ^= (metric & 15);
    } else {
        acc = (acc - metric + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000153_4307_14(int p0, int p1, int p2) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000153_4307 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 3) & 127;
            break;
        case 0:
            acc = (acc + 10) & 127;
            break;
        case 1:
            acc = (acc + 16) & 127;
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

int main() {
    int sec_r000153_0;
    int pub_r000153_0;
    int out_sink = 0;
    int chk_sum = 0;

    struct AudioFrame_R000153_4307 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000153_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000153_0 + 4) & 15;
    st_var_0.buffer[2] = 7;
    struct EventLog_R000153_4307 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000153_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000153_0 + 9) & 15;
    st_var_1.buffer[2] = 8;
    struct FilterState_R000153_4307 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000153_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000153_0 + 14) & 15;
    st_var_2.buffer[2] = 9;
    union TelemetryField_R000153_4307 u_var = {0};
    u_var.word = (pub_r000153_0 + 0x42) & 255;
    int table[4] = { 7, 13, 29, 41 };

    int res_0 = fn_R000153_4307_0((7), (8), (9));
    out_sink = (out_sink + res_0) & 255;
    chk_sum ^= (res_0 << 1) & 127;
    int res_1 = fn_R000153_4307_1((9), (11), (13));
    out_sink = (out_sink + res_1) & 255;
    chk_sum ^= (res_1 << 1) & 127;
    int res_2 = fn_R000153_4307_2((11), (14), (17));
    out_sink = (out_sink + res_2) & 255;
    chk_sum ^= (res_2 << 1) & 127;
    int res_3 = fn_R000153_4307_3((13), (17), (21));
    out_sink = (out_sink + res_3) & 255;
    chk_sum ^= (res_3 << 1) & 127;
    int res_4 = fn_R000153_4307_4((15), (20));
    out_sink = (out_sink + res_4) & 255;
    chk_sum ^= (res_4 << 1) & 127;
    int res_5 = fn_R000153_4307_5((17), (23), (29));
    out_sink = (out_sink + res_5) & 255;
    chk_sum ^= (res_5 << 1) & 127;
    int res_6 = fn_R000153_4307_6((19), (26), (33), (40));
    out_sink = (out_sink + res_6) & 255;
    chk_sum ^= (res_6 << 1) & 127;
    int res_7 = fn_R000153_4307_7((21), (29), (37));
    out_sink = (out_sink + res_7) & 255;
    chk_sum ^= (res_7 << 1) & 127;
    int res_8 = fn_R000153_4307_8((23), (32));
    out_sink = (out_sink + res_8) & 255;
    chk_sum ^= (res_8 << 1) & 127;
    int res_9 = fn_R000153_4307_9((25), (35), (45), (55));
    out_sink = (out_sink + res_9) & 255;
    chk_sum ^= (res_9 << 1) & 127;
    int res_10 = fn_R000153_4307_10((27), (38), (49), (60));
    out_sink = (out_sink + res_10) & 255;
    chk_sum ^= (res_10 << 1) & 127;
    int res_11 = fn_R000153_4307_11((29), (41), (53));
    out_sink = (out_sink + res_11) & 255;
    chk_sum ^= (res_11 << 1) & 127;
    int res_12 = fn_R000153_4307_12((31), (44), (57));
    out_sink = (out_sink + res_12) & 255;
    chk_sum ^= (res_12 << 1) & 127;
    int res_13 = fn_R000153_4307_13((33), (47));
    out_sink = (out_sink + res_13) & 255;
    chk_sum ^= (res_13 << 1) & 127;
    int res_14 = fn_R000153_4307_14((35), (50), (65));
    out_sink = (out_sink + res_14) & 255;
    chk_sum ^= (res_14 << 1) & 127;

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[0] ^ 4) & 3;
    switch (stage_v_1) {
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

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 16) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 31) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 31) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 46) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 18) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 33) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_1.buffer[1] * 2 + 37) & 63;
    if (stage_v_10 > 28) {
        out_sink = (out_sink + stage_v_10 - 5) & 255;
        if (stage_v_10 > 43) {
            chk_sum ^= (stage_v_10 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_10 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_0.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 10) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 25) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = table[1];
    table[1] = (table[2] + 35) & 63;
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = table[2];
    table[2] = (table[3] + 37) & 63;
    out_sink = (out_sink + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 28) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 43) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_26 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_0.buffer[0] * 2 + 88) & 63;
    if (stage_v_27 > 14) {
        out_sink = (out_sink + stage_v_27 - 5) & 255;
        if (stage_v_27 > 29) {
            chk_sum ^= (stage_v_27 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_27 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_28 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_2.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_34 = (stage_v_34 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_34) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (out_sink > 100) ? (chk_sum & 31) : (45 & 31);
    out_sink = (out_sink + stage_v_40) & 255;
    chk_sum ^= (stage_v_40 << 1) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_2.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 44) & 15;
    int stage_v_43 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= stage_v_43;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 20) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 35) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (st_var_0.buffer[0] * 2 + 160) & 63;
    if (stage_v_51 > 28) {
        out_sink = (out_sink + stage_v_51 - 5) & 255;
        if (stage_v_51 > 43) {
            chk_sum ^= (stage_v_51 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_51 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_54 = (stage_v_54 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_54) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (out_sink > 100) ? (chk_sum & 31) : (64 & 31);
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= (stage_v_59 << 1) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[0] ^ 64) & 3;
    switch (stage_v_61) {
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

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_0.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_64 = (stage_v_64 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_64) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 66) & 15;
    int stage_v_65 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_65) & 255;
    chk_sum ^= stage_v_65;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_67 = (stage_v_67 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_67) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 69) & 15;
    int stage_v_68 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_68) & 255;
    chk_sum ^= stage_v_68;

    /* Execution Pipeline Stage 69 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 70) & 15;
    int stage_v_69 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= stage_v_69;

    /* Execution Pipeline Stage 70 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (out_sink > 100) ? (chk_sum & 31) : (76 & 31);
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= (stage_v_71 << 1) & 127;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[1] * 2 + 226) & 63;
    if (stage_v_73 > 13) {
        out_sink = (out_sink + stage_v_73 - 5) & 255;
        if (stage_v_73 > 28) {
            chk_sum ^= (stage_v_73 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_73 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 76) & 15;
    int stage_v_75 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_75) & 255;
    chk_sum ^= stage_v_75;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (st_var_1.buffer[0] ^ 82) & 3;
    switch (stage_v_79) {
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

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 82) & 15;
    int stage_v_81 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_81) & 255;
    chk_sum ^= stage_v_81;

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
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_85 = (stage_v_85 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_85) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_2.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 15) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 30) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 88) & 15;
    int stage_v_87 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_87) & 255;
    chk_sum ^= stage_v_87;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_1.buffer[0] ^ 91) & 3;
    switch (stage_v_88) {
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

    /* Execution Pipeline Stage 89 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = table[0];
    table[0] = (table[1] + 185) & 63;
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (st_var_0.buffer[0] * 2 + 286) & 63;
    if (stage_v_93 > 40) {
        out_sink = (out_sink + stage_v_93 - 5) & 255;
        if (stage_v_93 > 55) {
            chk_sum ^= (stage_v_93 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_93 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_95 = (stage_v_95 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 97) & 15;
    int stage_v_96 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_96) & 255;
    chk_sum ^= stage_v_96;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_0.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 27) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 42) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_1.buffer[0] ^ 103) & 3;
    switch (stage_v_100) {
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

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (st_var_2.buffer[0] ^ 104) & 3;
    switch (stage_v_101) {
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

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = table[3];
    table[3] = (table[0] + 207) & 63;
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = table[0];
    table[0] = (table[1] + 209) & 63;
    out_sink = (out_sink + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (st_var_0.buffer[0] * 2 + 322) & 63;
    if (stage_v_105 > 25) {
        out_sink = (out_sink + stage_v_105 - 5) & 255;
        if (stage_v_105 > 40) {
            chk_sum ^= (stage_v_105 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_105 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (st_var_1.buffer[1] * 2 + 325) & 63;
    if (stage_v_106 > 30) {
        out_sink = (out_sink + stage_v_106 - 5) & 255;
        if (stage_v_106 > 45) {
            chk_sum ^= (stage_v_106 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_106 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_107 = (stage_v_107 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 38) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 53) {
            chk_sum ^= (stage_v_108 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_108 + 9) & 255;
        chk_sum ^= 0x1A;
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

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 112 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_113 = (stage_v_113 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (st_var_0.buffer[0] * 2 + 349) & 63;
    if (stage_v_114 > 14) {
        out_sink = (out_sink + stage_v_114 - 5) & 255;
        if (stage_v_114 > 29) {
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

    /* Execution Pipeline Stage 116 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 117) & 15;
    int stage_v_116 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= stage_v_116;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (st_var_0.buffer[0] ^ 120) & 3;
    switch (stage_v_117) {
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

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (out_sink > 100) ? (chk_sum & 31) : (123 & 31);
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= (stage_v_118 << 1) & 127;

    /* Execution Pipeline Stage 119 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 120) & 15;
    int stage_v_119 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_119) & 255;
    chk_sum ^= stage_v_119;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] * 2 + 367) & 63;
    if (stage_v_120 > 22) {
        out_sink = (out_sink + stage_v_120 - 5) & 255;
        if (stage_v_120 > 37) {
            chk_sum ^= (stage_v_120 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_120 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (st_var_1.buffer[0] ^ 124) & 3;
    switch (stage_v_121) {
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

    /* Execution Pipeline Stage 122 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_0.buffer[0] ^ 126) & 3;
    switch (stage_v_123) {
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

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_125 = (stage_v_125 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 129) & 15;
    int stage_v_128 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= stage_v_128;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_1.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 25) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 40) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (st_var_2.buffer[2] * 2 + 400) & 63;
    if (stage_v_131 > 23) {
        out_sink = (out_sink + stage_v_131 - 5) & 255;
        if (stage_v_131 > 38) {
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
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (st_var_0.buffer[0] ^ 138) & 3;
    switch (stage_v_135) {
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

    /* Execution Pipeline Stage 136 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 137) & 15;
    int stage_v_136 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_136) & 255;
    chk_sum ^= stage_v_136;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (out_sink > 100) ? (chk_sum & 31) : (143 & 31);
    out_sink = (out_sink + stage_v_138) & 255;
    chk_sum ^= (stage_v_138 << 1) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = table[3];
    table[3] = (table[0] + 279) & 63;
    out_sink = (out_sink + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (out_sink > 100) ? (chk_sum & 31) : (146 & 31);
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= (stage_v_141 << 1) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (st_var_1.buffer[1] * 2 + 433) & 63;
    if (stage_v_142 > 15) {
        out_sink = (out_sink + stage_v_142 - 5) & 255;
        if (stage_v_142 > 30) {
            chk_sum ^= (stage_v_142 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_142 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_2.buffer[2] * 2 + 436) & 63;
    if (stage_v_143 > 24) {
        out_sink = (out_sink + stage_v_143 - 5) & 255;
        if (stage_v_143 > 39) {
            chk_sum ^= (stage_v_143 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_143 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 144 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 145) & 15;
    int stage_v_144 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= stage_v_144;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (st_var_1.buffer[0] ^ 148) & 3;
    switch (stage_v_145) {
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

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_0.buffer[0] * 2 + 448) & 63;
    if (stage_v_147 > 18) {
        out_sink = (out_sink + stage_v_147 - 5) & 255;
        if (stage_v_147 > 33) {
            chk_sum ^= (stage_v_147 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_147 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 148 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_150 = (stage_v_150 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_151 = (stage_v_151 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = table[2];
    table[2] = (table[3] + 309) & 63;
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (st_var_2.buffer[0] ^ 161) & 3;
    switch (stage_v_158) {
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

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_0.buffer[0] ^ 162) & 3;
    switch (stage_v_159) {
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

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (out_sink > 100) ? (chk_sum & 31) : (167 & 31);
    out_sink = (out_sink + stage_v_162) & 255;
    chk_sum ^= (stage_v_162 << 1) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (st_var_1.buffer[0] ^ 166) & 3;
    switch (stage_v_163) {
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

    /* Execution Pipeline Stage 164 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 165) & 15;
    int stage_v_164 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_164) & 255;
    chk_sum ^= stage_v_164;

    /* Execution Pipeline Stage 165 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 166) & 15;
    int stage_v_165 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_165) & 255;
    chk_sum ^= stage_v_165;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_166 = (stage_v_166 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_166) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_167 = (stage_v_167 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_167) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = table[0];
    table[0] = (table[1] + 337) & 63;
    out_sink = (out_sink + stage_v_168) & 255;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = table[1];
    table[1] = (table[2] + 339) & 63;
    out_sink = (out_sink + stage_v_169) & 255;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (out_sink > 100) ? (chk_sum & 31) : (176 & 31);
    out_sink = (out_sink + stage_v_171) & 255;
    chk_sum ^= (stage_v_171 << 1) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_1.buffer[1] * 2 + 523) & 63;
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
    int stage_v_173 = (st_var_2.buffer[0] ^ 176) & 3;
    switch (stage_v_173) {
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
    int stage_v_176 = (st_var_2.buffer[0] ^ 179) & 3;
    switch (stage_v_176) {
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

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_0.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 19) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 34) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = table[2];
    table[2] = (table[3] + 357) & 63;
    out_sink = (out_sink + stage_v_178) & 255;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = table[1];
    table[1] = (table[2] + 363) & 63;
    out_sink = (out_sink + stage_v_181) & 255;

    /* Security Information Flow: Family = implicit_flow */
    if ((sec_r000153_0 & 7) > 3) {
        out_sink += 77;
    } else {
        out_sink -= 33;
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
