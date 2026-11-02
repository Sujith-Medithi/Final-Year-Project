/*
 * Benchmark Program: R000042
 * Family: bitwise_flow
 * Generator Seed: 103107
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct StreamBuffer_R000042_3107 {
    int head;
    short tail;
    int capacity;
    int buffer[3];
};

struct SensorNode_R000042_3107 {
    short gain;
    short threshold;
    int reading;
    int calib;
    int buffer[3];
};

union ColorPixel_R000042_3107 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000042_3107_0(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 1:
            acc = (acc + 12) & 127;
            break;
        case 2:
            acc = (acc + 9) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int mask = (st.buffer[0] * 3 + aux) & 63;
    if (mask > 23) {
        acc = (acc + mask * 2 + 5) & 127;
        aux ^= (mask & 15);
    } else {
        acc = (acc - mask + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_1(int p0, int p1) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
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
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 17) & 127;
            break;
        case 1:
            acc = (acc + 9) & 127;
            break;
        case 2:
            acc = (acc + 5) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_2(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int tally = (st.buffer[0] * 3 + aux) & 63;
    if (tally > 49) {
        acc = (acc + tally * 2 + 5) & 127;
        aux ^= (tally & 15);
    } else {
        acc = (acc - tally + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_3(int p0, int p1, int p2) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int offset = (st.buffer[0] * 3 + aux) & 63;
    if (offset > 13) {
        acc = (acc + offset * 2 + 5) & 127;
        aux ^= (offset & 15);
    } else {
        acc = (acc - offset + 11) & 127;
        aux += 3;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 6) & 127;
            break;
        case 0:
            acc = (acc + 3) & 127;
            break;
        case 1:
            acc = (acc + 7) & 127;
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

int fn_R000042_3107_4(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 15) & 127;
            break;
        case 2:
            acc = (acc + 4) & 127;
            break;
        case 0:
            acc = (acc + 7) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int accumulator = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator > 29) {
        acc = (acc + accumulator * 2 + 5) & 127;
        aux ^= (accumulator & 15);
    } else {
        acc = (acc - accumulator + 11) & 127;
        aux += 3;
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
    return (acc + aux) & 127;
}

int fn_R000042_3107_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int residue = (st.buffer[0] * 3 + aux) & 63;
    if (residue > 44) {
        acc = (acc + residue * 2 + 5) & 127;
        aux ^= (residue & 15);
    } else {
        acc = (acc - residue + 11) & 127;
        aux += 3;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int phase = (st.buffer[0] * 3 + aux) & 63;
    if (phase > 33) {
        acc = (acc + phase * 2 + 5) & 127;
        aux ^= (phase & 15);
    } else {
        acc = (acc - phase + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_7(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 12) & 127;
            break;
        case 3:
            acc = (acc + 4) & 127;
            break;
        case 2:
            acc = (acc + 11) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 7) & 127;
            break;
        case 3:
            acc = (acc + 8) & 127;
            break;
        case 1:
            acc = (acc + 14) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000042_3107_9(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
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

int fn_R000042_3107_10(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int weight = (st.buffer[0] * 3 + aux) & 63;
    if (weight > 16) {
        acc = (acc + weight * 2 + 5) & 127;
        aux ^= (weight & 15);
    } else {
        acc = (acc - weight + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_11(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int cursor = (st.buffer[0] * 3 + aux) & 63;
    if (cursor > 15) {
        acc = (acc + cursor * 2 + 5) & 127;
        aux ^= (cursor & 15);
    } else {
        acc = (acc - cursor + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_12(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 14) & 127;
            break;
        case 2:
            acc = (acc + 12) & 127;
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
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000042_3107_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000042_3107_14(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000042_3107 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 7) & 127;
            break;
        case 0:
            acc = (acc + 14) & 127;
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

int main() {
    int sec_r000042_0;
    int pub_r000042_0;
    int pub_r000042_1;
    int out_sink = 0;
    int chk_sum = 0;

    struct StreamBuffer_R000042_3107 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000042_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000042_0 + 4) & 15;
    st_var_0.buffer[2] = 7;
    struct SensorNode_R000042_3107 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000042_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000042_0 + 9) & 15;
    st_var_1.buffer[2] = 8;
    union ColorPixel_R000042_3107 u_var = {0};
    u_var.word = (pub_r000042_0 + 0x42) & 255;
    int table[4] = { 7, 13, 29, 41 };

    int res_0 = fn_R000042_3107_0((7), (8), (9));
    out_sink = (out_sink + res_0) & 255;
    chk_sum ^= (res_0 << 1) & 127;
    int res_1 = fn_R000042_3107_1((9), (11));
    out_sink = (out_sink + res_1) & 255;
    chk_sum ^= (res_1 << 1) & 127;
    int res_2 = fn_R000042_3107_2((11), (14), (17));
    out_sink = (out_sink + res_2) & 255;
    chk_sum ^= (res_2 << 1) & 127;
    int res_3 = fn_R000042_3107_3((13), (17), (21));
    out_sink = (out_sink + res_3) & 255;
    chk_sum ^= (res_3 << 1) & 127;
    int res_4 = fn_R000042_3107_4((15), (20), (25));
    out_sink = (out_sink + res_4) & 255;
    chk_sum ^= (res_4 << 1) & 127;
    int res_5 = fn_R000042_3107_5((17), (23), (29), (35));
    out_sink = (out_sink + res_5) & 255;
    chk_sum ^= (res_5 << 1) & 127;
    int res_6 = fn_R000042_3107_6((19), (26), (33), (40));
    out_sink = (out_sink + res_6) & 255;
    chk_sum ^= (res_6 << 1) & 127;
    int res_7 = fn_R000042_3107_7((21), (29), (37));
    out_sink = (out_sink + res_7) & 255;
    chk_sum ^= (res_7 << 1) & 127;
    int res_8 = fn_R000042_3107_8((23), (32), (41), (50));
    out_sink = (out_sink + res_8) & 255;
    chk_sum ^= (res_8 << 1) & 127;
    int res_9 = fn_R000042_3107_9((25), (35), (45));
    out_sink = (out_sink + res_9) & 255;
    chk_sum ^= (res_9 << 1) & 127;
    int res_10 = fn_R000042_3107_10((27), (38));
    out_sink = (out_sink + res_10) & 255;
    chk_sum ^= (res_10 << 1) & 127;
    int res_11 = fn_R000042_3107_11((29), (41), (53));
    out_sink = (out_sink + res_11) & 255;
    chk_sum ^= (res_11 << 1) & 127;
    int res_12 = fn_R000042_3107_12((31), (44));
    out_sink = (out_sink + res_12) & 255;
    chk_sum ^= (res_12 << 1) & 127;
    int res_13 = fn_R000042_3107_13((33), (47), (61), (75));
    out_sink = (out_sink + res_13) & 255;
    chk_sum ^= (res_13 << 1) & 127;
    int res_14 = fn_R000042_3107_14((35), (50), (65));
    out_sink = (out_sink + res_14) & 255;
    chk_sum ^= (res_14 << 1) & 127;

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = table[0];
    table[0] = (table[1] + 17) & 63;
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = table[2];
    table[2] = (table[3] + 21) & 63;
    out_sink = (out_sink + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (st_var_1.buffer[0] ^ 14) & 3;
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
    int stage_v_12 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_13 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] * 2 + 52) & 63;
    if (stage_v_15 > 28) {
        out_sink = (out_sink + stage_v_15 - 5) & 255;
        if (stage_v_15 > 43) {
            chk_sum ^= (stage_v_15 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_15 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (out_sink > 100) ? (chk_sum & 31) : (23 & 31);
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= (stage_v_18 << 1) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (out_sink > 100) ? (chk_sum & 31) : (24 & 31);
    out_sink = (out_sink + stage_v_19) & 255;
    chk_sum ^= (stage_v_19 << 1) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_22 = (stage_v_22 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_22) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (out_sink > 100) ? (chk_sum & 31) : (29 & 31);
    out_sink = (out_sink + stage_v_24) & 255;
    chk_sum ^= (stage_v_24 << 1) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_0.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 29) & 15;
    int stage_v_28 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= stage_v_28;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 32) & 15;
    int stage_v_31 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= stage_v_31;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 35) & 15;
    int stage_v_34 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= stage_v_34;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 38) & 15;
    int stage_v_37 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= stage_v_37;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_1.buffer[0] * 2 + 124) & 63;
    if (stage_v_39 > 22) {
        out_sink = (out_sink + stage_v_39 - 5) & 255;
        if (stage_v_39 > 37) {
            chk_sum ^= (stage_v_39 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_39 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (st_var_0.buffer[0] ^ 43) & 3;
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
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_44 = (stage_v_44 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_44) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_45 = (stage_v_45 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_45) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 15) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 30) {
            chk_sum ^= (stage_v_46 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_46 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

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
    int stage_v_50 = (st_var_0.buffer[0] ^ 53) & 3;
    switch (stage_v_50) {
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

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_51 = (stage_v_51 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_51) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[1] * 2 + 163) & 63;
    if (stage_v_52 > 19) {
        out_sink = (out_sink + stage_v_52 - 5) & 255;
        if (stage_v_52 > 34) {
            chk_sum ^= (stage_v_52 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_52 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 40) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 55) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_55 = (stage_v_55 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_55) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 58) & 15;
    int stage_v_57 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= stage_v_57;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 14) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 29) {
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
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 37) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 52) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (st_var_0.buffer[0] ^ 65) & 3;
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
    int stage_v_63 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[2] * 2 + 202) & 63;
    if (stage_v_65 > 37) {
        out_sink = (out_sink + stage_v_65 - 5) & 255;
        if (stage_v_65 > 52) {
            chk_sum ^= (stage_v_65 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_65 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = table[2];
    table[2] = (table[3] + 133) & 63;
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = table[1];
    table[1] = (table[2] + 139) & 63;
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[0] ^ 73) & 3;
    switch (stage_v_70) {
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

    /* Execution Pipeline Stage 71 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = table[2];
    table[2] = (table[3] + 149) & 63;
    out_sink = (out_sink + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = table[0];
    table[0] = (table[1] + 153) & 63;
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 78) & 15;
    int stage_v_77 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= stage_v_77;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 80) & 15;
    int stage_v_79 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= stage_v_79;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_80 = (stage_v_80 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_80) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_81 = (stage_v_81 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_81) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (st_var_0.buffer[0] ^ 85) & 3;
    switch (stage_v_82) {
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

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (st_var_1.buffer[2] * 2 + 256) & 63;
    if (stage_v_83 > 11) {
        out_sink = (out_sink + stage_v_83 - 5) & 255;
        if (stage_v_83 > 26) {
            chk_sum ^= (stage_v_83 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_83 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_84 = (stage_v_84 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_84) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 35) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 50) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 29) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 44) {
            chk_sum ^= (stage_v_86 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_86 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = table[3];
    table[3] = (table[0] + 175) & 63;
    out_sink = (out_sink + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (st_var_0.buffer[0] ^ 91) & 3;
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
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (st_var_0.buffer[0] ^ 93) & 3;
    switch (stage_v_90) {
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

    /* Execution Pipeline Stage 91 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 92) & 15;
    int stage_v_91 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_91) & 255;
    chk_sum ^= stage_v_91;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 94 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 95) & 15;
    int stage_v_94 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= stage_v_94;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (st_var_1.buffer[0] ^ 98) & 3;
    switch (stage_v_95) {
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

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (st_var_0.buffer[0] ^ 99) & 3;
    switch (stage_v_96) {
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

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = table[2];
    table[2] = (table[3] + 197) & 63;
    out_sink = (out_sink + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (st_var_1.buffer[0] * 2 + 304) & 63;
    if (stage_v_99 > 33) {
        out_sink = (out_sink + stage_v_99 - 5) & 255;
        if (stage_v_99 > 48) {
            chk_sum ^= (stage_v_99 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_99 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_0.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 21) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 36) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = table[1];
    table[1] = (table[2] + 203) & 63;
    out_sink = (out_sink + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_102 = (stage_v_102 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (out_sink > 100) ? (chk_sum & 31) : (109 & 31);
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= (stage_v_104 << 1) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = table[1];
    table[1] = (table[2] + 211) & 63;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_106 = (stage_v_106 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (st_var_0.buffer[0] * 2 + 331) & 63;
    if (stage_v_108 > 40) {
        out_sink = (out_sink + stage_v_108 - 5) & 255;
        if (stage_v_108 > 55) {
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
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_1.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 18) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 33) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (st_var_1.buffer[0] ^ 116) & 3;
    switch (stage_v_113) {
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

    /* Execution Pipeline Stage 114 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 115) & 15;
    int stage_v_114 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= stage_v_114;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = table[3];
    table[3] = (table[0] + 231) & 63;
    out_sink = (out_sink + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (out_sink > 100) ? (chk_sum & 31) : (121 & 31);
    out_sink = (out_sink + stage_v_116) & 255;
    chk_sum ^= (stage_v_116 << 1) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_117 = (stage_v_117 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_118 = (stage_v_118 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_1.buffer[0] ^ 122) & 3;
    switch (stage_v_119) {
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
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 124) & 15;
    int stage_v_123 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_123) & 255;
    chk_sum ^= stage_v_123;

    /* Execution Pipeline Stage 124 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 125) & 15;
    int stage_v_124 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_124) & 255;
    chk_sum ^= stage_v_124;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (st_var_1.buffer[2] * 2 + 382) & 63;
    if (stage_v_125 > 35) {
        out_sink = (out_sink + stage_v_125 - 5) & 255;
        if (stage_v_125 > 50) {
            chk_sum ^= (stage_v_125 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_125 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_126 = (stage_v_126 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (out_sink > 100) ? (chk_sum & 31) : (132 & 31);
    out_sink = (out_sink + stage_v_127) & 255;
    chk_sum ^= (stage_v_127 << 1) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (out_sink > 100) ? (chk_sum & 31) : (133 & 31);
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= (stage_v_128 << 1) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1];
    table[1] = (table[2] + 259) & 63;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_130 = (stage_v_130 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (out_sink > 100) ? (chk_sum & 31) : (137 & 31);
    out_sink = (out_sink + stage_v_132) & 255;
    chk_sum ^= (stage_v_132 << 1) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 134 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 135) & 15;
    int stage_v_134 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_134) & 255;
    chk_sum ^= stage_v_134;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = table[3];
    table[3] = (table[0] + 271) & 63;
    out_sink = (out_sink + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = table[0];
    table[0] = (table[1] + 273) & 63;
    out_sink = (out_sink + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = table[1];
    table[1] = (table[2] + 275) & 63;
    out_sink = (out_sink + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = table[2];
    table[2] = (table[3] + 277) & 63;
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = table[0];
    table[0] = (table[1] + 281) & 63;
    out_sink = (out_sink + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (out_sink > 100) ? (chk_sum & 31) : (147 & 31);
    out_sink = (out_sink + stage_v_142) & 255;
    chk_sum ^= (stage_v_142 << 1) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (st_var_1.buffer[0] ^ 146) & 3;
    switch (stage_v_143) {
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

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (out_sink > 100) ? (chk_sum & 31) : (149 & 31);
    out_sink = (out_sink + stage_v_144) & 255;
    chk_sum ^= (stage_v_144 << 1) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (st_var_0.buffer[2] * 2 + 445) & 63;
    if (stage_v_146 > 10) {
        out_sink = (out_sink + stage_v_146 - 5) & 255;
        if (stage_v_146 > 25) {
            chk_sum ^= (stage_v_146 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_146 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (out_sink > 100) ? (chk_sum & 31) : (152 & 31);
    out_sink = (out_sink + stage_v_147) & 255;
    chk_sum ^= (stage_v_147 << 1) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_148 = (stage_v_148 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (st_var_1.buffer[2] * 2 + 454) & 63;
    if (stage_v_149 > 20) {
        out_sink = (out_sink + stage_v_149 - 5) & 255;
        if (stage_v_149 > 35) {
            chk_sum ^= (stage_v_149 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_149 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] ^ 153) & 3;
    switch (stage_v_150) {
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

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = table[3];
    table[3] = (table[0] + 303) & 63;
    out_sink = (out_sink + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (out_sink > 100) ? (chk_sum & 31) : (157 & 31);
    out_sink = (out_sink + stage_v_152) & 255;
    chk_sum ^= (stage_v_152 << 1) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (st_var_0.buffer[1] * 2 + 469) & 63;
    if (stage_v_154 > 11) {
        out_sink = (out_sink + stage_v_154 - 5) & 255;
        if (stage_v_154 > 26) {
            chk_sum ^= (stage_v_154 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_154 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (out_sink > 100) ? (chk_sum & 31) : (161 & 31);
    out_sink = (out_sink + stage_v_156) & 255;
    chk_sum ^= (stage_v_156 << 1) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (st_var_1.buffer[0] ^ 160) & 3;
    switch (stage_v_157) {
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

    /* Execution Pipeline Stage 158 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 159) & 15;
    int stage_v_158 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_158) & 255;
    chk_sum ^= stage_v_158;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_159 = (stage_v_159 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_160 = (stage_v_160 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_1.buffer[2] * 2 + 490) & 63;
    if (stage_v_161 > 26) {
        out_sink = (out_sink + stage_v_161 - 5) & 255;
        if (stage_v_161 > 41) {
            chk_sum ^= (stage_v_161 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_161 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (out_sink > 100) ? (chk_sum & 31) : (168 & 31);
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= (stage_v_163 << 1) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (st_var_1.buffer[0] ^ 168) & 3;
    switch (stage_v_165) {
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

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (out_sink > 100) ? (chk_sum & 31) : (171 & 31);
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= (stage_v_166 << 1) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] ^ 171) & 3;
    switch (stage_v_168) {
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

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (out_sink > 100) ? (chk_sum & 31) : (174 & 31);
    out_sink = (out_sink + stage_v_169) & 255;
    chk_sum ^= (stage_v_169 << 1) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (st_var_0.buffer[0] ^ 173) & 3;
    switch (stage_v_170) {
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
    if (stage_v_172 > 36) {
        out_sink = (out_sink + stage_v_172 - 5) & 255;
        if (stage_v_172 > 51) {
            chk_sum ^= (stage_v_172 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_172 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 173 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 174) & 15;
    int stage_v_173 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_173) & 255;
    chk_sum ^= stage_v_173;

    /* Execution Pipeline Stage 174 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 175) & 15;
    int stage_v_174 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= stage_v_174;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[0] ^ 178) & 3;
    switch (stage_v_175) {
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

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_176 = (stage_v_176 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_176) & 127;
    }
    out_sink = (out_sink + stage_v_176) & 255;

    /* Execution Pipeline Stage 177 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 178) & 15;
    int stage_v_177 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_177) & 255;
    chk_sum ^= stage_v_177;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (st_var_0.buffer[1] * 2 + 541) & 63;
    if (stage_v_178 > 39) {
        out_sink = (out_sink + stage_v_178 - 5) & 255;
        if (stage_v_178 > 54) {
            chk_sum ^= (stage_v_178 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_178 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (st_var_1.buffer[0] ^ 182) & 3;
    switch (stage_v_179) {
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

    /* Execution Pipeline Stage 180 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 181) & 15;
    int stage_v_180 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_180) & 255;
    chk_sum ^= stage_v_180;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_181 = (stage_v_181 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_181) & 127;
    }
    out_sink = (out_sink + stage_v_181) & 255;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (out_sink > 100) ? (chk_sum & 31) : (188 & 31);
    out_sink = (out_sink + stage_v_183) & 255;
    chk_sum ^= (stage_v_183 << 1) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = table[0];
    table[0] = (table[1] + 369) & 63;
    out_sink = (out_sink + stage_v_184) & 255;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_185 = (stage_v_185 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_185) & 127;
    }
    out_sink = (out_sink + stage_v_185) & 255;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_186 = (stage_v_186 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_186) & 127;
    }
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (out_sink > 100) ? (chk_sum & 31) : (194 & 31);
    out_sink = (out_sink + stage_v_189) & 255;
    chk_sum ^= (stage_v_189 << 1) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_190 = (stage_v_190 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_190) & 127;
    }
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 192) & 15;
    int stage_v_191 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= stage_v_191;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] ^ 195) & 3;
    switch (stage_v_192) {
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

    /* Execution Pipeline Stage 193 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 194) & 15;
    int stage_v_193 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    chk_sum ^= stage_v_193;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (out_sink > 100) ? (chk_sum & 31) : (201 & 31);
    out_sink = (out_sink + stage_v_196) & 255;
    chk_sum ^= (stage_v_196 << 1) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_197 = (stage_v_197 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_197) & 127;
    }
    out_sink = (out_sink + stage_v_197) & 255;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (out_sink > 100) ? (chk_sum & 31) : (204 & 31);
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= (stage_v_199 << 1) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_200 = (stage_v_200 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_200) & 127;
    }
    out_sink = (out_sink + stage_v_200) & 255;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = table[1];
    table[1] = (table[2] + 403) & 63;
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 203) & 15;
    int stage_v_202 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= stage_v_202;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_203 = (stage_v_203 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_203) & 127;
    }
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = table[0];
    table[0] = (table[1] + 409) & 63;
    out_sink = (out_sink + stage_v_204) & 255;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_205 = (stage_v_205 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_205) & 127;
    }
    out_sink = (out_sink + stage_v_205) & 255;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_206 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Security Information Flow: Family = bitwise_flow */
    int b_w1 = (sec_r000042_0 << 2) & 124;
    int b_w2 = (sec_r000042_0 >> 2) & 31;
    int b_w3 = (b_w1 ^ b_w2) | 5;
    out_sink += b_w3 & 63;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
