/*
 * Benchmark Program: R000124
 * Family: multi_step_explicit
 * Generator Seed: 311407
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000124_1407 {
    int timeout;
    short stop_bits;
    short parity;
    int port;
    int buffer[3];
};

struct Transaction_R000124_1407 {
    int balance;
    int account_id;
    int auth_code;
    short fee;
    int rate;
    int buffer[3];
};

union TelemetryField_R000124_1407 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000124_1407_0(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int parity = (st.buffer[0] * 3 + aux) & 63;
    if (parity > 50) {
        acc = (acc + parity * 2 + 5) & 127;
        aux ^= (parity & 15);
    } else {
        acc = (acc - parity + 11) & 127;
        aux += 3;
    }
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000124_1407_1(int p0, int p1, int p2) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride = (st.buffer[0] * 3 + aux) & 63;
    if (stride > 14) {
        acc = (acc + stride * 2 + 5) & 127;
        aux ^= (stride & 15);
    } else {
        acc = (acc - stride + 11) & 127;
        aux += 3;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 5 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 4) & 127;
            break;
        case 0:
            acc = (acc + 4) & 127;
            break;
        case 2:
            acc = (acc + 14) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    return (acc + aux) & 127;
}

int fn_R000124_1407_3(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    int parity = (st.buffer[0] * 3 + aux) & 63;
    if (parity > 27) {
        acc = (acc + parity * 2 + 5) & 127;
        aux ^= (parity & 15);
    } else {
        acc = (acc - parity + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_4(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 12) & 127;
            break;
        case 1:
            acc = (acc + 13) & 127;
            break;
        case 3:
            acc = (acc + 12) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_5(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int vector = (st.buffer[0] * 3 + aux) & 63;
    if (vector > 31) {
        acc = (acc + vector * 2 + 5) & 127;
        aux ^= (vector & 15);
    } else {
        acc = (acc - vector + 11) & 127;
        aux += 3;
    }
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_6(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 6) & 127;
            break;
        case 0:
            acc = (acc + 8) & 127;
            break;
        case 2:
            acc = (acc + 15) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 2 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    return (acc + aux) & 127;
}

int fn_R000124_1407_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    switch ((p0 + aux) & 3) {
        case 0:
            acc = (acc + 13) & 127;
            break;
        case 1:
            acc = (acc + 10) & 127;
            break;
        case 2:
            acc = (acc + 9) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int delta = (st.buffer[0] * 3 + aux) & 63;
    if (delta > 23) {
        acc = (acc + delta * 2 + 5) & 127;
        aux ^= (delta & 15);
    } else {
        acc = (acc - delta + 11) & 127;
        aux += 3;
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

int fn_R000124_1407_10(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int loop_ctr = 0;
    while (loop_ctr < 2) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    for (int k = 0; k < 3; k++) {
        aux = (aux + k * 4 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    switch ((p0 + aux) & 3) {
        case 2:
            acc = (acc + 14) & 127;
            break;
        case 0:
            acc = (acc + 7) & 127;
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

int fn_R000124_1407_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 17) & 127;
            break;
        case 1:
            acc = (acc + 3) & 127;
            break;
        case 0:
            acc = (acc + 10) & 127;
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

int fn_R000124_1407_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    for (int k = 0; k < 2; k++) {
        aux = (aux + k * 3 + st.buffer[k % 3]) & 63;
        acc = (acc ^ (aux + k)) & 127;
    }
    int phase = (st.buffer[0] * 3 + aux) & 63;
    if (phase > 23) {
        acc = (acc + phase * 2 + 5) & 127;
        aux ^= (phase & 15);
    } else {
        acc = (acc - phase + 11) & 127;
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

int fn_R000124_1407_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int quantum = (st.buffer[0] * 3 + aux) & 63;
    if (quantum > 44) {
        acc = (acc + quantum * 2 + 5) & 127;
        aux ^= (quantum & 15);
    } else {
        acc = (acc - quantum + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 127;
}

int fn_R000124_1407_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int quantum = (st.buffer[0] * 3 + aux) & 63;
    if (quantum > 12) {
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

int fn_R000124_1407_15(int p0, int p1, int p2) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000124_1407 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int loc_tab[3];
    loc_tab[0] = (p0 & 15) + 2;
    loc_tab[1] = (p1 & 15) + 4;
    loc_tab[2] = (aux & 15) + 6;
    acc = (acc + loc_tab[aux % 3]) & 127;
    switch ((p0 + aux) & 3) {
        case 3:
            acc = (acc + 6) & 127;
            break;
        case 1:
            acc = (acc + 13) & 127;
            break;
        case 0:
            acc = (acc + 11) & 127;
            break;
        default:
            acc ^= 0x1F;
            break;
    }
    int b_step = ((aux << 1) ^ (acc >> 1)) & 63;
    acc = (acc + b_step * 3) & 127;
    int loop_ctr = 0;
    while (loop_ctr < 3) {
        acc = (acc + loop_ctr * 4 + 7) & 127;
        loop_ctr++;
    }
    return (acc + aux) & 127;
}

int main() {
    int sec_r000124_0;
    int sec_r000124_1;
    int sec_r000124_2;
    int pub_r000124_0;
    int out_sink = 0;
    int chk_sum = 0;

    struct DeviceConfig_R000124_1407 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000124_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000124_0 + 4) & 15;
    st_var_0.buffer[2] = 7;
    struct Transaction_R000124_1407 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000124_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000124_0 + 9) & 15;
    st_var_1.buffer[2] = 8;
    union TelemetryField_R000124_1407 u_var = {0};
    u_var.word = (pub_r000124_0 + 0x42) & 255;
    int table[4] = { 7, 13, 29, 41 };

    int res_0 = fn_R000124_1407_0((7), (8));
    out_sink = (out_sink + res_0) & 255;
    chk_sum ^= (res_0 << 1) & 127;
    int res_1 = fn_R000124_1407_1((9), (11), (13));
    out_sink = (out_sink + res_1) & 255;
    chk_sum ^= (res_1 << 1) & 127;
    int res_2 = fn_R000124_1407_2((11), (14), (17), (20));
    out_sink = (out_sink + res_2) & 255;
    chk_sum ^= (res_2 << 1) & 127;
    int res_3 = fn_R000124_1407_3((13), (17), (21));
    out_sink = (out_sink + res_3) & 255;
    chk_sum ^= (res_3 << 1) & 127;
    int res_4 = fn_R000124_1407_4((15), (20), (25));
    out_sink = (out_sink + res_4) & 255;
    chk_sum ^= (res_4 << 1) & 127;
    int res_5 = fn_R000124_1407_5((17), (23), (29));
    out_sink = (out_sink + res_5) & 255;
    chk_sum ^= (res_5 << 1) & 127;
    int res_6 = fn_R000124_1407_6((19), (26), (33));
    out_sink = (out_sink + res_6) & 255;
    chk_sum ^= (res_6 << 1) & 127;
    int res_7 = fn_R000124_1407_7((21), (29), (37), (45));
    out_sink = (out_sink + res_7) & 255;
    chk_sum ^= (res_7 << 1) & 127;
    int res_8 = fn_R000124_1407_8((23), (32), (41), (50));
    out_sink = (out_sink + res_8) & 255;
    chk_sum ^= (res_8 << 1) & 127;
    int res_9 = fn_R000124_1407_9((25), (35), (45), (55));
    out_sink = (out_sink + res_9) & 255;
    chk_sum ^= (res_9 << 1) & 127;
    int res_10 = fn_R000124_1407_10((27), (38), (49));
    out_sink = (out_sink + res_10) & 255;
    chk_sum ^= (res_10 << 1) & 127;
    int res_11 = fn_R000124_1407_11((29), (41), (53), (65));
    out_sink = (out_sink + res_11) & 255;
    chk_sum ^= (res_11 << 1) & 127;
    int res_12 = fn_R000124_1407_12((31), (44), (57), (70));
    out_sink = (out_sink + res_12) & 255;
    chk_sum ^= (res_12 << 1) & 127;
    int res_13 = fn_R000124_1407_13((33), (47), (61), (75));
    out_sink = (out_sink + res_13) & 255;
    chk_sum ^= (res_13 << 1) & 127;
    int res_14 = fn_R000124_1407_14((35), (50), (65), (80));
    out_sink = (out_sink + res_14) & 255;
    chk_sum ^= (res_14 << 1) & 127;
    int res_15 = fn_R000124_1407_15((37), (53), (69));
    out_sink = (out_sink + res_15) & 255;
    chk_sum ^= (res_15 << 1) & 127;

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 39) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 54) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 9) & 15;
    int stage_v_8 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_8) & 255;
    chk_sum ^= stage_v_8;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_0.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_11 = (stage_v_11 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_11) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (st_var_0.buffer[0] ^ 15) & 3;
    switch (stage_v_12) {
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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[1] * 2 + 46) & 63;
    if (stage_v_13 > 28) {
        out_sink = (out_sink + stage_v_13 - 5) & 255;
        if (stage_v_13 > 43) {
            chk_sum ^= (stage_v_13 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_13 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (st_var_0.buffer[0] ^ 19) & 3;
    switch (stage_v_16) {
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
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_19 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_21 = (stage_v_21 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_21) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = table[2];
    table[2] = (table[3] + 45) & 63;
    out_sink = (out_sink + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = table[3];
    table[3] = (table[0] + 47) & 63;
    out_sink = (out_sink + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 31) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 46) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_1.buffer[2] * 2 + 94) & 63;
    if (stage_v_29 > 35) {
        out_sink = (out_sink + stage_v_29 - 5) & 255;
        if (stage_v_29 > 50) {
            chk_sum ^= (stage_v_29 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_29 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 33) & 15;
    int stage_v_32 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_32) & 255;
    chk_sum ^= stage_v_32;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_0.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[2] * 2 + 112) & 63;
    if (stage_v_35 > 22) {
        out_sink = (out_sink + stage_v_35 - 5) & 255;
        if (stage_v_35 > 37) {
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
    int stage_v_37 = table[1];
    table[1] = (table[2] + 75) & 63;
    out_sink = (out_sink + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[0] ^ 44) & 3;
    switch (stage_v_41) {
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

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = table[2];
    table[2] = (table[3] + 85) & 63;
    out_sink = (out_sink + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_1.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 29) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 44) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_0.buffer[1] * 2 + 145) & 63;
    if (stage_v_46 > 30) {
        out_sink = (out_sink + stage_v_46 - 5) & 255;
        if (stage_v_46 > 45) {
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
    for (int step = 0; step < 3; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 25) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 40) {
            chk_sum ^= (stage_v_48 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_48 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_52 = (stage_v_52 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_52) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 57) & 15;
    int stage_v_56 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_56) & 255;
    chk_sum ^= stage_v_56;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 36) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 51) {
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
    int stage_v_59 = (st_var_1.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 35) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 50) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] * 2 + 187) & 63;
    if (stage_v_60 > 15) {
        out_sink = (out_sink + stage_v_60 - 5) & 255;
        if (stage_v_60 > 30) {
            chk_sum ^= (stage_v_60 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_60 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_62 = (st_var_0.buffer[2] * 2 + 193) & 63;
    if (stage_v_62 > 24) {
        out_sink = (out_sink + stage_v_62 - 5) & 255;
        if (stage_v_62 > 39) {
            chk_sum ^= (stage_v_62 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_62 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 63 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 64) & 15;
    int stage_v_63 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= stage_v_63;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (st_var_1.buffer[0] ^ 68) & 3;
    switch (stage_v_65) {
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

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 67 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 68) & 15;
    int stage_v_67 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_67) & 255;
    chk_sum ^= stage_v_67;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_68 = (stage_v_68 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_68) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (out_sink > 100) ? (chk_sum & 31) : (74 & 31);
    out_sink = (out_sink + stage_v_69) & 255;
    chk_sum ^= (stage_v_69 << 1) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (st_var_0.buffer[1] * 2 + 217) & 63;
    if (stage_v_70 > 16) {
        out_sink = (out_sink + stage_v_70 - 5) & 255;
        if (stage_v_70 > 31) {
            chk_sum ^= (stage_v_70 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_70 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (st_var_1.buffer[2] * 2 + 220) & 63;
    if (stage_v_71 > 10) {
        out_sink = (out_sink + stage_v_71 - 5) & 255;
        if (stage_v_71 > 25) {
            chk_sum ^= (stage_v_71 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_71 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = table[0];
    table[0] = (table[1] + 145) & 63;
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (out_sink > 100) ? (chk_sum & 31) : (79 & 31);
    out_sink = (out_sink + stage_v_74) & 255;
    chk_sum ^= (stage_v_74 << 1) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_76 = (stage_v_76 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_76) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = table[1];
    table[1] = (table[2] + 155) & 63;
    out_sink = (out_sink + stage_v_77) & 255;

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
    int stage_v_80 = (st_var_0.buffer[2] * 2 + 247) & 63;
    if (stage_v_80 > 29) {
        out_sink = (out_sink + stage_v_80 - 5) & 255;
        if (stage_v_80 > 44) {
            chk_sum ^= (stage_v_80 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_80 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = table[3];
    table[3] = (table[0] + 167) & 63;
    out_sink = (out_sink + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (out_sink > 100) ? (chk_sum & 31) : (89 & 31);
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= (stage_v_84 << 1) & 127;

    /* Execution Pipeline Stage 85 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 86) & 15;
    int stage_v_85 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_85) & 255;
    chk_sum ^= stage_v_85;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = table[2];
    table[2] = (table[3] + 173) & 63;
    out_sink = (out_sink + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (st_var_1.buffer[0] * 2 + 268) & 63;
    if (stage_v_87 > 20) {
        out_sink = (out_sink + stage_v_87 - 5) & 255;
        if (stage_v_87 > 35) {
            chk_sum ^= (stage_v_87 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_87 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 90) & 15;
    int stage_v_89 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_89) & 255;
    chk_sum ^= stage_v_89;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = table[2];
    table[2] = (table[3] + 181) & 63;
    out_sink = (out_sink + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (st_var_1.buffer[0] ^ 94) & 3;
    switch (stage_v_91) {
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

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

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
    int stage_v_96 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (st_var_1.buffer[0] ^ 100) & 3;
    switch (stage_v_97) {
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

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (st_var_0.buffer[2] * 2 + 301) & 63;
    if (stage_v_98 > 37) {
        out_sink = (out_sink + stage_v_98 - 5) & 255;
        if (stage_v_98 > 52) {
            chk_sum ^= (stage_v_98 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_98 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = table[3];
    table[3] = (table[0] + 199) & 63;
    out_sink = (out_sink + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (out_sink > 100) ? (chk_sum & 31) : (105 & 31);
    out_sink = (out_sink + stage_v_100) & 255;
    chk_sum ^= (stage_v_100 << 1) & 127;

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
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 105) & 15;
    int stage_v_104 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_104) & 255;
    chk_sum ^= stage_v_104;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (out_sink > 100) ? (chk_sum & 31) : (110 & 31);
    out_sink = (out_sink + stage_v_105) & 255;
    chk_sum ^= (stage_v_105 << 1) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (out_sink > 100) ? (chk_sum & 31) : (111 & 31);
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= (stage_v_106 << 1) & 127;

    /* Execution Pipeline Stage 107 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 108) & 15;
    int stage_v_107 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_107) & 255;
    chk_sum ^= stage_v_107;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = table[1];
    table[1] = (table[2] + 219) & 63;
    out_sink = (out_sink + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (st_var_1.buffer[0] * 2 + 340) & 63;
    if (stage_v_111 > 16) {
        out_sink = (out_sink + stage_v_111 - 5) & 255;
        if (stage_v_111 > 31) {
            chk_sum ^= (stage_v_111 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_111 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (st_var_0.buffer[1] * 2 + 343) & 63;
    if (stage_v_112 > 32) {
        out_sink = (out_sink + stage_v_112 - 5) & 255;
        if (stage_v_112 > 47) {
            chk_sum ^= (stage_v_112 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_112 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (out_sink > 100) ? (chk_sum & 31) : (119 & 31);
    out_sink = (out_sink + stage_v_114) & 255;
    chk_sum ^= (stage_v_114 << 1) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (st_var_1.buffer[1] * 2 + 352) & 63;
    if (stage_v_115 > 15) {
        out_sink = (out_sink + stage_v_115 - 5) & 255;
        if (stage_v_115 > 30) {
            chk_sum ^= (stage_v_115 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_115 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (st_var_0.buffer[0] ^ 119) & 3;
    switch (stage_v_116) {
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

    /* Execution Pipeline Stage 117 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 118) & 15;
    int stage_v_117 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= stage_v_117;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (out_sink > 100) ? (chk_sum & 31) : (123 & 31);
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= (stage_v_118 << 1) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (st_var_1.buffer[2] * 2 + 364) & 63;
    if (stage_v_119 > 25) {
        out_sink = (out_sink + stage_v_119 - 5) & 255;
        if (stage_v_119 > 40) {
            chk_sum ^= (stage_v_119 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_119 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (st_var_0.buffer[0] ^ 123) & 3;
    switch (stage_v_120) {
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

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (out_sink > 100) ? (chk_sum & 31) : (126 & 31);
    out_sink = (out_sink + stage_v_121) & 255;
    chk_sum ^= (stage_v_121 << 1) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = table[2];
    table[2] = (table[3] + 245) & 63;
    out_sink = (out_sink + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_123 = (stage_v_123 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (out_sink > 100) ? (chk_sum & 31) : (130 & 31);
    out_sink = (out_sink + stage_v_125) & 255;
    chk_sum ^= (stage_v_125 << 1) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (st_var_0.buffer[0] ^ 129) & 3;
    switch (stage_v_126) {
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

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = table[3];
    table[3] = (table[0] + 255) & 63;
    out_sink = (out_sink + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (out_sink > 100) ? (chk_sum & 31) : (133 & 31);
    out_sink = (out_sink + stage_v_128) & 255;
    chk_sum ^= (stage_v_128 << 1) & 127;

    /* Execution Pipeline Stage 129 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 130) & 15;
    int stage_v_129 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_129) & 255;
    chk_sum ^= stage_v_129;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_0.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 12) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 27) {
            chk_sum ^= (stage_v_130 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_130 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (st_var_1.buffer[1] * 2 + 406) & 63;
    if (stage_v_133 > 13) {
        out_sink = (out_sink + stage_v_133 - 5) & 255;
        if (stage_v_133 > 28) {
            chk_sum ^= (stage_v_133 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_133 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (st_var_0.buffer[2] * 2 + 409) & 63;
    if (stage_v_134 > 22) {
        out_sink = (out_sink + stage_v_134 - 5) & 255;
        if (stage_v_134 > 37) {
            chk_sum ^= (stage_v_134 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_134 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (out_sink > 100) ? (chk_sum & 31) : (140 & 31);
    out_sink = (out_sink + stage_v_135) & 255;
    chk_sum ^= (stage_v_135 << 1) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (st_var_0.buffer[1] * 2 + 415) & 63;
    if (stage_v_136 > 16) {
        out_sink = (out_sink + stage_v_136 - 5) & 255;
        if (stage_v_136 > 31) {
            chk_sum ^= (stage_v_136 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_136 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (st_var_1.buffer[0] ^ 140) & 3;
    switch (stage_v_137) {
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

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_138 = (stage_v_138 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (out_sink > 100) ? (chk_sum & 31) : (144 & 31);
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= (stage_v_139 << 1) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[0] ^ 143) & 3;
    switch (stage_v_140) {
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

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_143 = (stage_v_143 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = table[0];
    table[0] = (table[1] + 289) & 63;
    out_sink = (out_sink + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2];
    table[2] = (table[3] + 293) & 63;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (st_var_1.buffer[0] ^ 150) & 3;
    switch (stage_v_147) {
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

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (st_var_0.buffer[0] ^ 151) & 3;
    switch (stage_v_148) {
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

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (out_sink > 100) ? (chk_sum & 31) : (154 & 31);
    out_sink = (out_sink + stage_v_149) & 255;
    chk_sum ^= (stage_v_149 << 1) & 127;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (st_var_0.buffer[0] * 2 + 457) & 63;
    if (stage_v_150 > 22) {
        out_sink = (out_sink + stage_v_150 - 5) & 255;
        if (stage_v_150 > 37) {
            chk_sum ^= (stage_v_150 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_150 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_154 = (stage_v_154 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 3; step++) {
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
    int stage_v_158 = (st_var_0.buffer[2] * 2 + 481) & 63;
    if (stage_v_158 > 27) {
        out_sink = (out_sink + stage_v_158 - 5) & 255;
        if (stage_v_158 > 42) {
            chk_sum ^= (stage_v_158 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_158 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (st_var_1.buffer[0] ^ 162) & 3;
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
    int stage_v_160 = table[0];
    table[0] = (table[1] + 321) & 63;
    out_sink = (out_sink + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (st_var_1.buffer[2] * 2 + 490) & 63;
    if (stage_v_161 > 37) {
        out_sink = (out_sink + stage_v_161 - 5) & 255;
        if (stage_v_161 > 52) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 164) & 15;
    int stage_v_163 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_163) & 255;
    chk_sum ^= stage_v_163;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (st_var_0.buffer[2] * 2 + 499) & 63;
    if (stage_v_164 > 24) {
        out_sink = (out_sink + stage_v_164 - 5) & 255;
        if (stage_v_164 > 39) {
            chk_sum ^= (stage_v_164 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_164 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_167 = (st_var_1.buffer[2] * 2 + 508) & 63;
    if (stage_v_167 > 40) {
        out_sink = (out_sink + stage_v_167 - 5) & 255;
        if (stage_v_167 > 55) {
            chk_sum ^= (stage_v_167 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_167 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 26) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 41) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (out_sink > 100) ? (chk_sum & 31) : (175 & 31);
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= (stage_v_170 << 1) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (st_var_1.buffer[0] * 2 + 520) & 63;
    if (stage_v_171 > 10) {
        out_sink = (out_sink + stage_v_171 - 5) & 255;
        if (stage_v_171 > 25) {
            chk_sum ^= (stage_v_171 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_171 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (st_var_0.buffer[1] * 2 + 523) & 63;
    if (stage_v_172 > 27) {
        out_sink = (out_sink + stage_v_172 - 5) & 255;
        if (stage_v_172 > 42) {
            chk_sum ^= (stage_v_172 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_172 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (st_var_1.buffer[2] * 2 + 526) & 63;
    if (stage_v_173 > 22) {
        out_sink = (out_sink + stage_v_173 - 5) & 255;
        if (stage_v_173 > 37) {
            chk_sum ^= (stage_v_173 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_173 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 174 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 175) & 15;
    int stage_v_174 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_174) & 255;
    chk_sum ^= stage_v_174;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (out_sink > 100) ? (chk_sum & 31) : (180 & 31);
    out_sink = (out_sink + stage_v_175) & 255;
    chk_sum ^= (stage_v_175 << 1) & 127;

    /* Execution Pipeline Stage 176 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 177) & 15;
    int stage_v_176 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_176) & 255;
    chk_sum ^= stage_v_176;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] * 2 + 538) & 63;
    if (stage_v_177 > 18) {
        out_sink = (out_sink + stage_v_177 - 5) & 255;
        if (stage_v_177 > 33) {
            chk_sum ^= (stage_v_177 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_177 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (st_var_0.buffer[0] ^ 183) & 3;
    switch (stage_v_180) {
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
    int stage_v_183 = (st_var_1.buffer[0] * 2 + 556) & 63;
    if (stage_v_183 > 35) {
        out_sink = (out_sink + stage_v_183 - 5) & 255;
        if (stage_v_183 > 50) {
            chk_sum ^= (stage_v_183 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_183 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (out_sink > 100) ? (chk_sum & 31) : (189 & 31);
    out_sink = (out_sink + stage_v_184) & 255;
    chk_sum ^= (stage_v_184 << 1) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_186 = (stage_v_186 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_186) & 127;
    }
    out_sink = (out_sink + stage_v_186) & 255;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (st_var_1.buffer[1] * 2 + 568) & 63;
    if (stage_v_187 > 14) {
        out_sink = (out_sink + stage_v_187 - 5) & 255;
        if (stage_v_187 > 29) {
            chk_sum ^= (stage_v_187 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_187 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = table[0];
    table[0] = (table[1] + 377) & 63;
    out_sink = (out_sink + stage_v_188) & 255;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_189 = (stage_v_189 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_189) & 127;
    }
    out_sink = (out_sink + stage_v_189) & 255;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (out_sink > 100) ? (chk_sum & 31) : (195 & 31);
    out_sink = (out_sink + stage_v_190) & 255;
    chk_sum ^= (stage_v_190 << 1) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (out_sink > 100) ? (chk_sum & 31) : (196 & 31);
    out_sink = (out_sink + stage_v_191) & 255;
    chk_sum ^= (stage_v_191 << 1) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (st_var_0.buffer[0] ^ 195) & 3;
    switch (stage_v_192) {
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

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (st_var_1.buffer[1] * 2 + 586) & 63;
    if (stage_v_193 > 23) {
        out_sink = (out_sink + stage_v_193 - 5) & 255;
        if (stage_v_193 > 38) {
            chk_sum ^= (stage_v_193 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_193 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_194 = (stage_v_194 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_194) & 127;
    }
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 196 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 197) & 15;
    int stage_v_196 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_196) & 255;
    chk_sum ^= stage_v_196;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (st_var_0.buffer[0] * 2 + 601) & 63;
    if (stage_v_198 > 37) {
        out_sink = (out_sink + stage_v_198 - 5) & 255;
        if (stage_v_198 > 52) {
            chk_sum ^= (stage_v_198 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_198 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (out_sink > 100) ? (chk_sum & 31) : (204 & 31);
    out_sink = (out_sink + stage_v_199) & 255;
    chk_sum ^= (stage_v_199 << 1) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (out_sink > 100) ? (chk_sum & 31) : (205 & 31);
    out_sink = (out_sink + stage_v_200) & 255;
    chk_sum ^= (stage_v_200 << 1) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_201 = (stage_v_201 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_201) & 127;
    }
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (st_var_0.buffer[1] * 2 + 613) & 63;
    if (stage_v_202 > 34) {
        out_sink = (out_sink + stage_v_202 - 5) & 255;
        if (stage_v_202 > 49) {
            chk_sum ^= (stage_v_202 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_202 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = table[3];
    table[3] = (table[0] + 407) & 63;
    out_sink = (out_sink + stage_v_203) & 255;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (st_var_0.buffer[0] ^ 207) & 3;
    switch (stage_v_204) {
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

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (out_sink > 100) ? (chk_sum & 31) : (210 & 31);
    out_sink = (out_sink + stage_v_205) & 255;
    chk_sum ^= (stage_v_205 << 1) & 127;

    /* Execution Pipeline Stage 206 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 207) & 15;
    int stage_v_206 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_206) & 255;
    chk_sum ^= stage_v_206;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_207 = (stage_v_207 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_207) & 127;
    }
    out_sink = (out_sink + stage_v_207) & 255;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (st_var_0.buffer[0] ^ 211) & 3;
    switch (stage_v_208) {
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

    /* Security Information Flow: Family = multi_step_explicit */
    int s_st1 = (sec_r000124_0 ^ 0x4B) & 127;
    int s_st2 = (s_st1 * 3 + 19) & 255;
    int s_st3 = (s_st2 >> 1) + (s_st1 & 15);
    int s_st4 = (s_st3 ^ 0x33) & 63;
    out_sink += s_st4;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
