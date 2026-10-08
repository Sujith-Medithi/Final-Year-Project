/*
 * Benchmark Program: R000088
 * Family: secret_dependent_loops
 * Generator Seed: 45256
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct State_R000088_256 {
    int id;
    int val;
    short flag;
    int buffer[3];
};

union Packet_R000088_256 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int helper_R000088_256_0(int a, int b) {
    int acc = a + 1;
    struct State_R000088_256 st;
    st.id = 1;
    st.val = b + 5;
    st.flag = (short)0;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 7;

    if (st.val > 10) {
        acc += (st.buffer[0] * 2 + 3) & 31;
        if (acc > 20) {
            acc -= 7;
        } else {
            acc += 5;
        }
    } else {
        acc -= (st.buffer[1] + 1) & 15;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_1(int a, int b) {
    int acc = a + 4;
    struct State_R000088_256 st;
    st.id = 2;
    st.val = b + 7;
    st.flag = (short)1;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 8;

    for (int k = 0; k < 2; k++) {
        acc += (k * 3 + st.buffer[k]) & 15;
        if (acc > 30) {
            acc -= 10;
        }
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_2(int a, int b) {
    int acc = a + 7;
    struct State_R000088_256 st;
    st.id = 3;
    st.val = b + 9;
    st.flag = (short)2;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 9;

    switch (a & 3) {
        case 0:
            acc ^= 7;
            break;
        case 1:
            acc += (b & 15) + 3;
            break;
        case 2:
            acc = (acc * 2 + 1) & 63;
            break;
        default:
            acc -= 5;
            break;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_3(int a, int b) {
    int acc = a + 10;
    struct State_R000088_256 st;
    st.id = 4;
    st.val = b + 11;
    st.flag = (short)3;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 10;

    union Packet_R000088_256 pkt;
    pkt.word = (a + b + 12) & 255;
    acc += (pkt.raw[0] ^ pkt.raw[1]) & 31;
    if ((acc & 1) != 0) {
        acc = (acc << 1) & 127;
    } else {
        acc = (acc >> 1) + 2;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_4(int a, int b, int c, int d) {
    int acc = a + 13;
    struct State_R000088_256 st;
    st.id = 5;
    st.val = b + 13;
    st.flag = (short)4;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 11;

    int cnt = 0;
    while (cnt < 2) {
        acc += (cnt + 1) * 4;
        cnt++;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_5(int a, int b, int c, int d) {
    int acc = a + 16;
    struct State_R000088_256 st;
    st.id = 6;
    st.val = b + 15;
    st.flag = (short)5;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 12;

    if (st.val > 35) {
        acc += (st.buffer[0] * 2 + 3) & 31;
        if (acc > 20) {
            acc -= 7;
        } else {
            acc += 5;
        }
    } else {
        acc -= (st.buffer[1] + 1) & 15;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_6(int a, int b, int c) {
    int acc = a + 19;
    struct State_R000088_256 st;
    st.id = 7;
    st.val = b + 17;
    st.flag = (short)6;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 13;

    for (int k = 0; k < 2; k++) {
        acc += (k * 3 + st.buffer[k]) & 15;
        if (acc > 30) {
            acc -= 10;
        }
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_7(int a, int b, int c) {
    int acc = a + 22;
    struct State_R000088_256 st;
    st.id = 8;
    st.val = b + 19;
    st.flag = (short)7;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 14;

    switch (a & 3) {
        case 0:
            acc ^= 7;
            break;
        case 1:
            acc += (b & 15) + 3;
            break;
        case 2:
            acc = (acc * 2 + 1) & 63;
            break;
        default:
            acc -= 5;
            break;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_8(int a, int b, int c) {
    int acc = a + 25;
    struct State_R000088_256 st;
    st.id = 9;
    st.val = b + 21;
    st.flag = (short)8;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 15;

    union Packet_R000088_256 pkt;
    pkt.word = (a + b + 32) & 255;
    acc += (pkt.raw[0] ^ pkt.raw[1]) & 31;
    if ((acc & 1) != 0) {
        acc = (acc << 1) & 127;
    } else {
        acc = (acc >> 1) + 2;
    }
    return (acc + st.flag) & 127;
}

int helper_R000088_256_9(int a, int b, int c) {
    int acc = a + 28;
    struct State_R000088_256 st;
    st.id = 10;
    st.val = b + 23;
    st.flag = (short)9;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 16;

    int cnt = 0;
    while (cnt < 2) {
        acc += (cnt + 1) * 4;
        cnt++;
    }
    return (acc + st.flag) & 127;
}

int main() {
    int sec_k_0;
    int sec_k_1;
    int sec_k_2;
    int pub_v_0;
    int pub_v_1;
    int pub_v_2;
    int out_sink = 0;
    int chk_sum = 0;
    int local_arr[3];
    struct State_R000088_256 main_st;
    union Packet_R000088_256 main_pkt;

    main_st.id = 1;
    main_st.val = (pub_v_0 + 10) & 63;
    main_st.flag = (short)1;
    main_st.buffer[0] = (pub_v_0 + 1) & 15;
    main_st.buffer[1] = (pub_v_0 + 2) & 15;
    main_st.buffer[2] = (pub_v_0 + 3) & 15;
    main_pkt.word = (pub_v_0 + 42) & 255;
    local_arr[0] = (pub_v_0 + 5) & 15;
    local_arr[1] = (pub_v_0 + 7) & 15;
    local_arr[2] = (pub_v_0 + 9) & 15;

    int h_res_0 = helper_R000088_256_0((3), (3));
    out_sink += h_res_0;
    chk_sum ^= (h_res_0 << 1) & 127;
    int h_res_1 = helper_R000088_256_1((4), (5));
    out_sink += h_res_1;
    chk_sum ^= (h_res_1 << 1) & 127;
    int h_res_2 = helper_R000088_256_2((5), (7));
    out_sink += h_res_2;
    chk_sum ^= (h_res_2 << 1) & 127;
    int h_res_3 = helper_R000088_256_3((6), (9));
    out_sink += h_res_3;
    chk_sum ^= (h_res_3 << 1) & 127;
    int h_res_4 = helper_R000088_256_4((7), (11), (15), (19));
    out_sink += h_res_4;
    chk_sum ^= (h_res_4 << 1) & 127;
    int h_res_5 = helper_R000088_256_5((8), (13), (18), (23));
    out_sink += h_res_5;
    chk_sum ^= (h_res_5 << 1) & 127;
    int h_res_6 = helper_R000088_256_6((9), (15), (21));
    out_sink += h_res_6;
    chk_sum ^= (h_res_6 << 1) & 127;
    int h_res_7 = helper_R000088_256_7((10), (17), (24));
    out_sink += h_res_7;
    chk_sum ^= (h_res_7 << 1) & 127;
    int h_res_8 = helper_R000088_256_8((11), (19), (27));
    out_sink += h_res_8;
    chk_sum ^= (h_res_8 << 1) & 127;
    int h_res_9 = helper_R000088_256_9((12), (21), (30));
    out_sink += h_res_9;
    chk_sum ^= (h_res_9 << 1) & 127;

    /* Computational Stage 0 */
    int blk_0 = (local_arr[0] + 3) & 31;
    if (blk_0 > 15) {
        local_arr[0] = (local_arr[0] + 1) & 15;
        out_sink += 1;
    } else {
        local_arr[0] = (local_arr[0] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_0;

    /* Computational Stage 1 */
    int blk_1 = (local_arr[1] + 8) & 31;
    for (int k = 0; k < 2; k++) {
        blk_1 = (blk_1 + k * 3) & 31;
        chk_sum = (chk_sum + blk_1) & 127;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_1;

    /* Computational Stage 2 */
    int blk_2 = (local_arr[2] + 13) & 31;
    switch (blk_2 & 3) {
        case 0:
            out_sink += (blk_2 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_2 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_2;

    /* Computational Stage 3 */
    int blk_3 = (local_arr[0] + 18) & 31;
    main_st.val = (main_st.val + blk_3) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_3 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[0];
    chk_sum ^= blk_3;

    /* Computational Stage 4 */
    int blk_4 = (local_arr[1] + 23) & 31;
    if (blk_4 > 15) {
        local_arr[1] = (local_arr[1] + 5) & 15;
        out_sink += 1;
    } else {
        local_arr[1] = (local_arr[1] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_4;

    /* Computational Stage 5 */
    int blk_5 = (local_arr[2] + 28) & 31;
    for (int k = 0; k < 2; k++) {
        blk_5 = (blk_5 + k * 3) & 31;
        chk_sum = (chk_sum + blk_5) & 127;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_5;

    /* Computational Stage 6 */
    int blk_6 = (local_arr[0] + 33) & 31;
    switch (blk_6 & 3) {
        case 0:
            out_sink += (blk_6 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_6 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_6;

    /* Computational Stage 7 */
    int blk_7 = (local_arr[1] + 38) & 31;
    main_st.val = (main_st.val + blk_7) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_7 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[1];
    chk_sum ^= blk_7;

    /* Computational Stage 8 */
    int blk_8 = (local_arr[2] + 43) & 31;
    if (blk_8 > 15) {
        local_arr[2] = (local_arr[2] + 2) & 15;
        out_sink += 1;
    } else {
        local_arr[2] = (local_arr[2] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_8;

    /* Computational Stage 9 */
    int blk_9 = (local_arr[0] + 48) & 31;
    for (int k = 0; k < 2; k++) {
        blk_9 = (blk_9 + k * 3) & 31;
        chk_sum = (chk_sum + blk_9) & 127;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_9;

    /* Computational Stage 10 */
    int blk_10 = (local_arr[1] + 53) & 31;
    switch (blk_10 & 3) {
        case 0:
            out_sink += (blk_10 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_10 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_10;

    /* Computational Stage 11 */
    int blk_11 = (local_arr[2] + 58) & 31;
    main_st.val = (main_st.val + blk_11) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_11 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[2];
    chk_sum ^= blk_11;

    /* Computational Stage 12 */
    int blk_12 = (local_arr[0] + 63) & 31;
    if (blk_12 > 15) {
        local_arr[0] = (local_arr[0] + 6) & 15;
        out_sink += 1;
    } else {
        local_arr[0] = (local_arr[0] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_12;

    /* Computational Stage 13 */
    int blk_13 = (local_arr[1] + 68) & 31;
    for (int k = 0; k < 2; k++) {
        blk_13 = (blk_13 + k * 3) & 31;
        chk_sum = (chk_sum + blk_13) & 127;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_13;

    /* Computational Stage 14 */
    int blk_14 = (local_arr[2] + 73) & 31;
    switch (blk_14 & 3) {
        case 0:
            out_sink += (blk_14 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_14 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_14;

    /* Computational Stage 15 */
    int blk_15 = (local_arr[0] + 78) & 31;
    main_st.val = (main_st.val + blk_15) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_15 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[0];
    chk_sum ^= blk_15;

    /* Computational Stage 16 */
    int blk_16 = (local_arr[1] + 83) & 31;
    if (blk_16 > 15) {
        local_arr[1] = (local_arr[1] + 3) & 15;
        out_sink += 1;
    } else {
        local_arr[1] = (local_arr[1] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_16;

    /* Computational Stage 17 */
    int blk_17 = (local_arr[2] + 88) & 31;
    for (int k = 0; k < 2; k++) {
        blk_17 = (blk_17 + k * 3) & 31;
        chk_sum = (chk_sum + blk_17) & 127;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_17;

    /* Computational Stage 18 */
    int blk_18 = (local_arr[0] + 93) & 31;
    switch (blk_18 & 3) {
        case 0:
            out_sink += (blk_18 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_18 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_18;

    /* Computational Stage 19 */
    int blk_19 = (local_arr[1] + 98) & 31;
    main_st.val = (main_st.val + blk_19) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_19 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[1];
    chk_sum ^= blk_19;

    /* Computational Stage 20 */
    int blk_20 = (local_arr[2] + 103) & 31;
    if (blk_20 > 15) {
        local_arr[2] = (local_arr[2] + 7) & 15;
        out_sink += 1;
    } else {
        local_arr[2] = (local_arr[2] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_20;

    /* Computational Stage 21 */
    int blk_21 = (local_arr[0] + 108) & 31;
    for (int k = 0; k < 2; k++) {
        blk_21 = (blk_21 + k * 3) & 31;
        chk_sum = (chk_sum + blk_21) & 127;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_21;

    /* Computational Stage 22 */
    int blk_22 = (local_arr[1] + 113) & 31;
    switch (blk_22 & 3) {
        case 0:
            out_sink += (blk_22 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_22 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_22;

    /* Computational Stage 23 */
    int blk_23 = (local_arr[2] + 118) & 31;
    main_st.val = (main_st.val + blk_23) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_23 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[2];
    chk_sum ^= blk_23;

    /* Computational Stage 24 */
    int blk_24 = (local_arr[0] + 123) & 31;
    if (blk_24 > 15) {
        local_arr[0] = (local_arr[0] + 4) & 15;
        out_sink += 1;
    } else {
        local_arr[0] = (local_arr[0] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_24;

    /* Security Information Flow: Family = secret_dependent_loops */
    int bound = (sec_k_0 & 1) + 1;
    for (int it = 0; it < bound; it++) {
        out_sink += (it + 1) * 7;
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
