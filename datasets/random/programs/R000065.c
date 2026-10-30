/*
 * Benchmark Program: R000065
 * Family: bitwise_flow
 * Generator Seed: 44405
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

struct State_R000065_405 {
    int id;
    int val;
    short flag;
    int buffer[3];
};

union Packet_R000065_405 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int helper_R000065_405_0(int a, int b, int c, int d) {
    int acc = a + 1;
    struct State_R000065_405 st;
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

int helper_R000065_405_1(int a, int b) {
    int acc = a + 4;
    struct State_R000065_405 st;
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

int helper_R000065_405_2(int a, int b) {
    int acc = a + 7;
    struct State_R000065_405 st;
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

int helper_R000065_405_3(int a, int b, int c, int d) {
    int acc = a + 10;
    struct State_R000065_405 st;
    st.id = 4;
    st.val = b + 11;
    st.flag = (short)3;
    st.buffer[0] = a & 15;
    st.buffer[1] = b & 15;
    st.buffer[2] = 10;

    union Packet_R000065_405 pkt;
    pkt.word = (a + b + 12) & 255;
    acc += (pkt.raw[0] ^ pkt.raw[1]) & 31;
    if ((acc & 1) != 0) {
        acc = (acc << 1) & 127;
    } else {
        acc = (acc >> 1) + 2;
    }
    return (acc + st.flag) & 127;
}

int main() {
    int sec_k_0;
    int sec_k_1;
    int pub_v_0;
    int pub_v_1;
    int pub_v_2;
    int out_sink = 0;
    int chk_sum = 0;
    int local_arr[3];
    struct State_R000065_405 main_st;
    union Packet_R000065_405 main_pkt;

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

    int h_res_0 = helper_R000065_405_0((3), (3), (3), (3));
    out_sink += h_res_0;
    chk_sum ^= (h_res_0 << 1) & 127;
    int h_res_1 = helper_R000065_405_1((4), (5));
    out_sink += h_res_1;
    chk_sum ^= (h_res_1 << 1) & 127;
    int h_res_2 = helper_R000065_405_2((5), (7));
    out_sink += h_res_2;
    chk_sum ^= (h_res_2 << 1) & 127;
    int h_res_3 = helper_R000065_405_3((6), (9), (12), (15));
    out_sink += h_res_3;
    chk_sum ^= (h_res_3 << 1) & 127;

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

    /* Computational Stage 25 */
    int blk_25 = (local_arr[1] + 128) & 31;
    for (int k = 0; k < 2; k++) {
        blk_25 = (blk_25 + k * 3) & 31;
        chk_sum = (chk_sum + blk_25) & 127;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_25;

    /* Computational Stage 26 */
    int blk_26 = (local_arr[2] + 133) & 31;
    switch (blk_26 & 3) {
        case 0:
            out_sink += (blk_26 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_26 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_26;

    /* Computational Stage 27 */
    int blk_27 = (local_arr[0] + 138) & 31;
    main_st.val = (main_st.val + blk_27) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_27 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[0];
    chk_sum ^= blk_27;

    /* Computational Stage 28 */
    int blk_28 = (local_arr[1] + 143) & 31;
    if (blk_28 > 15) {
        local_arr[1] = (local_arr[1] + 1) & 15;
        out_sink += 1;
    } else {
        local_arr[1] = (local_arr[1] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_28;

    /* Computational Stage 29 */
    int blk_29 = (local_arr[2] + 148) & 31;
    for (int k = 0; k < 2; k++) {
        blk_29 = (blk_29 + k * 3) & 31;
        chk_sum = (chk_sum + blk_29) & 127;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_29;

    /* Computational Stage 30 */
    int blk_30 = (local_arr[0] + 153) & 31;
    switch (blk_30 & 3) {
        case 0:
            out_sink += (blk_30 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_30 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_30;

    /* Computational Stage 31 */
    int blk_31 = (local_arr[1] + 158) & 31;
    main_st.val = (main_st.val + blk_31) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_31 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[1];
    chk_sum ^= blk_31;

    /* Computational Stage 32 */
    int blk_32 = (local_arr[2] + 163) & 31;
    if (blk_32 > 15) {
        local_arr[2] = (local_arr[2] + 5) & 15;
        out_sink += 1;
    } else {
        local_arr[2] = (local_arr[2] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_32;

    /* Computational Stage 33 */
    int blk_33 = (local_arr[0] + 168) & 31;
    for (int k = 0; k < 2; k++) {
        blk_33 = (blk_33 + k * 3) & 31;
        chk_sum = (chk_sum + blk_33) & 127;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_33;

    /* Computational Stage 34 */
    int blk_34 = (local_arr[1] + 173) & 31;
    switch (blk_34 & 3) {
        case 0:
            out_sink += (blk_34 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_34 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_34;

    /* Computational Stage 35 */
    int blk_35 = (local_arr[2] + 178) & 31;
    main_st.val = (main_st.val + blk_35) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_35 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[2];
    chk_sum ^= blk_35;

    /* Computational Stage 36 */
    int blk_36 = (local_arr[0] + 183) & 31;
    if (blk_36 > 15) {
        local_arr[0] = (local_arr[0] + 2) & 15;
        out_sink += 1;
    } else {
        local_arr[0] = (local_arr[0] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_36;

    /* Computational Stage 37 */
    int blk_37 = (local_arr[1] + 188) & 31;
    for (int k = 0; k < 2; k++) {
        blk_37 = (blk_37 + k * 3) & 31;
        chk_sum = (chk_sum + blk_37) & 127;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_37;

    /* Computational Stage 38 */
    int blk_38 = (local_arr[2] + 193) & 31;
    switch (blk_38 & 3) {
        case 0:
            out_sink += (blk_38 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_38 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_38;

    /* Computational Stage 39 */
    int blk_39 = (local_arr[0] + 198) & 31;
    main_st.val = (main_st.val + blk_39) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_39 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[0];
    chk_sum ^= blk_39;

    /* Computational Stage 40 */
    int blk_40 = (local_arr[1] + 203) & 31;
    if (blk_40 > 15) {
        local_arr[1] = (local_arr[1] + 6) & 15;
        out_sink += 1;
    } else {
        local_arr[1] = (local_arr[1] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_40;

    /* Computational Stage 41 */
    int blk_41 = (local_arr[2] + 208) & 31;
    for (int k = 0; k < 2; k++) {
        blk_41 = (blk_41 + k * 3) & 31;
        chk_sum = (chk_sum + blk_41) & 127;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_41;

    /* Computational Stage 42 */
    int blk_42 = (local_arr[0] + 213) & 31;
    switch (blk_42 & 3) {
        case 0:
            out_sink += (blk_42 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_42 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_42;

    /* Computational Stage 43 */
    int blk_43 = (local_arr[1] + 218) & 31;
    main_st.val = (main_st.val + blk_43) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_43 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[1];
    chk_sum ^= blk_43;

    /* Computational Stage 44 */
    int blk_44 = (local_arr[2] + 223) & 31;
    if (blk_44 > 15) {
        local_arr[2] = (local_arr[2] + 3) & 15;
        out_sink += 1;
    } else {
        local_arr[2] = (local_arr[2] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_44;

    /* Computational Stage 45 */
    int blk_45 = (local_arr[0] + 228) & 31;
    for (int k = 0; k < 2; k++) {
        blk_45 = (blk_45 + k * 3) & 31;
        chk_sum = (chk_sum + blk_45) & 127;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_45;

    /* Computational Stage 46 */
    int blk_46 = (local_arr[1] + 233) & 31;
    switch (blk_46 & 3) {
        case 0:
            out_sink += (blk_46 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_46 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_46;

    /* Computational Stage 47 */
    int blk_47 = (local_arr[2] + 238) & 31;
    main_st.val = (main_st.val + blk_47) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_47 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[2];
    chk_sum ^= blk_47;

    /* Computational Stage 48 */
    int blk_48 = (local_arr[0] + 243) & 31;
    if (blk_48 > 15) {
        local_arr[0] = (local_arr[0] + 7) & 15;
        out_sink += 1;
    } else {
        local_arr[0] = (local_arr[0] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_48;

    /* Computational Stage 49 */
    int blk_49 = (local_arr[1] + 248) & 31;
    for (int k = 0; k < 2; k++) {
        blk_49 = (blk_49 + k * 3) & 31;
        chk_sum = (chk_sum + blk_49) & 127;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_49;

    /* Computational Stage 50 */
    int blk_50 = (local_arr[2] + 253) & 31;
    switch (blk_50 & 3) {
        case 0:
            out_sink += (blk_50 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_50 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_50;

    /* Computational Stage 51 */
    int blk_51 = (local_arr[0] + 258) & 31;
    main_st.val = (main_st.val + blk_51) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_51 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[0];
    chk_sum ^= blk_51;

    /* Computational Stage 52 */
    int blk_52 = (local_arr[1] + 263) & 31;
    if (blk_52 > 15) {
        local_arr[1] = (local_arr[1] + 4) & 15;
        out_sink += 1;
    } else {
        local_arr[1] = (local_arr[1] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_52;

    /* Computational Stage 53 */
    int blk_53 = (local_arr[2] + 268) & 31;
    for (int k = 0; k < 2; k++) {
        blk_53 = (blk_53 + k * 3) & 31;
        chk_sum = (chk_sum + blk_53) & 127;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_53;

    /* Computational Stage 54 */
    int blk_54 = (local_arr[0] + 273) & 31;
    switch (blk_54 & 3) {
        case 0:
            out_sink += (blk_54 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_54 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_54;

    /* Computational Stage 55 */
    int blk_55 = (local_arr[1] + 278) & 31;
    main_st.val = (main_st.val + blk_55) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_55 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[1];
    chk_sum ^= blk_55;

    /* Computational Stage 56 */
    int blk_56 = (local_arr[2] + 283) & 31;
    if (blk_56 > 15) {
        local_arr[2] = (local_arr[2] + 1) & 15;
        out_sink += 1;
    } else {
        local_arr[2] = (local_arr[2] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[2];
    chk_sum ^= blk_56;

    /* Computational Stage 57 */
    int blk_57 = (local_arr[0] + 288) & 31;
    for (int k = 0; k < 2; k++) {
        blk_57 = (blk_57 + k * 3) & 31;
        chk_sum = (chk_sum + blk_57) & 127;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_57;

    /* Computational Stage 58 */
    int blk_58 = (local_arr[1] + 293) & 31;
    switch (blk_58 & 3) {
        case 0:
            out_sink += (blk_58 ^ 3) & 15;
            break;
        case 1:
            out_sink -= (blk_58 + 2) & 15;
            break;
        default:
            out_sink ^= 5;
            break;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_58;

    /* Computational Stage 59 */
    int blk_59 = (local_arr[2] + 298) & 31;
    main_st.val = (main_st.val + blk_59) & 63;
    main_pkt.raw[3] = (unsigned char)(blk_59 & 255);
    out_sink += (main_st.val ^ main_pkt.raw[3]) & 15;
    out_sink += local_arr[2];
    chk_sum ^= blk_59;

    /* Computational Stage 60 */
    int blk_60 = (local_arr[0] + 303) & 31;
    if (blk_60 > 15) {
        local_arr[0] = (local_arr[0] + 5) & 15;
        out_sink += 1;
    } else {
        local_arr[0] = (local_arr[0] - 1) & 15;
        out_sink -= 1;
    }
    out_sink += local_arr[0];
    chk_sum ^= blk_60;

    /* Computational Stage 61 */
    int blk_61 = (local_arr[1] + 308) & 31;
    for (int k = 0; k < 2; k++) {
        blk_61 = (blk_61 + k * 3) & 31;
        chk_sum = (chk_sum + blk_61) & 127;
    }
    out_sink += local_arr[1];
    chk_sum ^= blk_61;

    /* Security Information Flow: Family = bitwise_flow */
    int bit1 = (sec_k_0 << 2) & 120;
    int bit2 = (sec_k_0 >> 1) & 15;
    int bit3 = (bit1 ^ bit2) | 3;
    out_sink += bit3 & 63;

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
