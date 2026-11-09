/*
 * Benchmark Program: R001775
 * Security Family: bitwise_flow
 * Generator Seed: 677513
 * High Inputs: 18 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001775_7513_0 {
    short iv;
    unsigned char tag;
    int round_key;
    short nonce;
    short flags;
    int counter;
    int buffer[3];
};

struct Transaction_R001775_7513_1 {
    unsigned char balance;
    unsigned char account_id;
    int status;
    unsigned char rate;
    int auth_code;
    short fee;
    int buffer[3];
};

union ColorPixel_R001775_7513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001775_7513_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int scale_91 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_91 > 48) {
        acc = (acc + scale_91 * 2 + 5) & 127;
        aux ^= (scale_91 & 15);
    } else {
        acc = (acc - scale_91 + 11) & 127;
        aux += 3;
    }
    int anchor_55 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_55 = (anchor_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_55) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_12 = local_arr[aux % 3];
    acc = (acc + segment_12 * 2) & 127;
    int threshold_31 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_31) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001775_7513_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int offset_77 = 0;
    for (int k = 0; k < 3; k++) {
        offset_77 = (offset_77 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_77) & 127;
    }
    int bound_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001775_7513_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_35 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_35 > 14) {
        acc = (acc + anchor_35 * 2 + 5) & 127;
        aux ^= (anchor_35 & 15);
    } else {
        acc = (acc - anchor_35 + 11) & 127;
        aux += 3;
    }
    int metric_57 = 0;
    for (int k = 0; k < 3; k++) {
        metric_57 = (metric_57 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_57) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int mask_20 = local_arr[aux % 3];
    acc = (acc + mask_20 * 2) & 127;
    int residue_36 = (aux + st.buffer[1]) & 3;
    switch (residue_36) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int threshold_19 = (aux + st.buffer[1]) & 3;
    switch (threshold_19) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int vector_13 = local_arr[aux % 3];
    acc = (acc + vector_13 * 2) & 127;
    int mask_58 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_58 > 39) {
        acc = (acc + mask_58 * 2 + 5) & 127;
        aux ^= (mask_58 & 15);
    } else {
        acc = (acc - mask_58 + 11) & 127;
        aux += 3;
    }
    int mask_19 = (aux + st.buffer[1]) & 3;
    switch (mask_19) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_53) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001775_7513_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int tracker_82 = (aux + st.buffer[1]) & 3;
    switch (tracker_82) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int accumulator_26 = local_arr[aux % 3];
    acc = (acc + accumulator_26 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_38 = 0;
    for (int k = 0; k < 2; k++) {
        accumulator_38 = (accumulator_38 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_38) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_19 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_19 > 31) {
        acc = (acc + anchor_19 * 2 + 5) & 127;
        aux ^= (anchor_19 & 15);
    } else {
        acc = (acc - anchor_19 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int anchor_85 = local_arr[aux % 3];
    acc = (acc + anchor_85 * 2) & 127;
    int window_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001775_7513_7(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int checksum_55 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_55 = (checksum_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_55) & 127;
    }
    int stride_17 = (aux + st.buffer[1]) & 3;
    switch (stride_17) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_54 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_54 > 27) {
        acc = (acc + metric_54 * 2 + 5) & 127;
        aux ^= (metric_54 & 15);
    } else {
        acc = (acc - metric_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_34 = local_arr[aux % 3];
    acc = (acc + coefficient_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001775_7513_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_54 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_54 > 40) {
        acc = (acc + metric_54 * 2 + 5) & 127;
        aux ^= (metric_54 & 15);
    } else {
        acc = (acc - metric_54 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_91 = local_arr[aux % 3];
    acc = (acc + vector_91 * 2) & 127;
    int quotient_63 = (aux + st.buffer[1]) & 3;
    switch (quotient_63) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_9(int p0, int p1, int p2) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int offset_55 = local_arr[aux % 3];
    acc = (acc + offset_55 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001775_7513_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int anchor_68 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_68 > 43) {
        acc = (acc + anchor_68 * 2 + 5) & 127;
        aux ^= (anchor_68 & 15);
    } else {
        acc = (acc - anchor_68 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_96 = local_arr[aux % 3];
    acc = (acc + cursor_96 * 2) & 127;
    int index_reg_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_17) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001775_7513_11(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int local_arr[3] = {4, 9, 15};
    int metric_45 = local_arr[aux % 3];
    acc = (acc + metric_45 * 2) & 127;
    int threshold_86 = (aux + st.buffer[1]) & 3;
    switch (threshold_86) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_12(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_41 = 0;
    for (int k = 0; k < 3; k++) {
        sample_41 = (sample_41 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_41) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_27 = (aux + st.buffer[1]) & 3;
    switch (pivot_27) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int weight_10 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_10 > 18) {
        acc = (acc + weight_10 * 2 + 5) & 127;
        aux ^= (weight_10 & 15);
    } else {
        acc = (acc - weight_10 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_13(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int damping_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_22) & 63;
    acc ^= aux;
    int margin_34 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_34 > 39) {
        acc = (acc + margin_34 * 2 + 5) & 127;
        aux ^= (margin_34 & 15);
    } else {
        acc = (acc - margin_34 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_40 = local_arr[aux % 3];
    acc = (acc + checksum_40 * 2) & 127;
    int checksum_23 = (aux + st.buffer[1]) & 3;
    switch (checksum_23) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tracker_19 = 0;
    for (int k = 0; k < 2; k++) {
        tracker_19 = (tracker_19 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_19) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_43 = local_arr[aux % 3];
    acc = (acc + stride_43 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001775_7513_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int mask_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_36) & 63;
    acc ^= aux;
    int margin_54 = 0;
    for (int k = 0; k < 3; k++) {
        margin_54 = (margin_54 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_54) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001775_7513_16(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001775_7513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int metric_28 = 0;
    for (int k = 0; k < 3; k++) {
        metric_28 = (metric_28 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_28) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001775_7513_17(int p0, int p1) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001775_7513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int delta_90 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_90 > 21) {
        acc = (acc + delta_90 * 2 + 5) & 127;
        aux ^= (delta_90 & 15);
    } else {
        acc = (acc - delta_90 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_72 = (aux + st.buffer[1]) & 3;
    switch (vector_72) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001775_0;
    int sec_r001775_1;
    int sec_r001775_2;
    int sec_r001775_3;
    int sec_r001775_4;
    int sec_r001775_5;
    int sec_r001775_6;
    int sec_r001775_7;
    int sec_r001775_8;
    int sec_r001775_9;
    int sec_r001775_10;
    int sec_r001775_11;
    int sec_r001775_12;
    int sec_r001775_13;
    int sec_r001775_14;
    int sec_r001775_15;
    int sec_r001775_16;
    int sec_r001775_17;
    int pub_r001775_0;
    int pub_r001775_1;
    int pub_r001775_2;
    int pub_r001775_3;
    int pub_r001775_4;
    int pub_r001775_5;
    int pub_r001775_6;
    int pub_r001775_7;
    int pub_r001775_8;
    int pub_r001775_9;
    int pub_r001775_10;
    int pub_r001775_11;
    int pub_r001775_12;
    int pub_r001775_13;
    int pub_r001775_14;
    int pub_r001775_15;
    int pub_r001775_16;
    int pub_r001775_17;
    int pub_r001775_18;
    int pub_r001775_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001775_0 >= -100 && pub_r001775_0 <= 100);
    __CPROVER_assume(pub_r001775_1 >= -100 && pub_r001775_1 <= 100);
    __CPROVER_assume(pub_r001775_2 >= -100 && pub_r001775_2 <= 100);
    __CPROVER_assume(pub_r001775_3 >= -100 && pub_r001775_3 <= 100);
    __CPROVER_assume(pub_r001775_4 >= -100 && pub_r001775_4 <= 100);
    __CPROVER_assume(pub_r001775_5 >= -100 && pub_r001775_5 <= 100);
    __CPROVER_assume(pub_r001775_6 >= -100 && pub_r001775_6 <= 100);
    __CPROVER_assume(pub_r001775_7 >= -100 && pub_r001775_7 <= 100);
    __CPROVER_assume(pub_r001775_8 >= -100 && pub_r001775_8 <= 100);
    __CPROVER_assume(pub_r001775_9 >= -100 && pub_r001775_9 <= 100);
    __CPROVER_assume(pub_r001775_10 >= -100 && pub_r001775_10 <= 100);
    __CPROVER_assume(pub_r001775_11 >= -100 && pub_r001775_11 <= 100);
    __CPROVER_assume(pub_r001775_12 >= -100 && pub_r001775_12 <= 100);
    __CPROVER_assume(pub_r001775_13 >= -100 && pub_r001775_13 <= 100);
    __CPROVER_assume(pub_r001775_14 >= -100 && pub_r001775_14 <= 100);
    __CPROVER_assume(pub_r001775_15 >= -100 && pub_r001775_15 <= 100);
    __CPROVER_assume(pub_r001775_16 >= -100 && pub_r001775_16 <= 100);
    __CPROVER_assume(pub_r001775_17 >= -100 && pub_r001775_17 <= 100);
    __CPROVER_assume(pub_r001775_18 >= -100 && pub_r001775_18 <= 100);
    __CPROVER_assume(pub_r001775_19 >= -100 && pub_r001775_19 <= 100);
    __CPROVER_assume(sec_r001775_0 >= 0 && sec_r001775_0 <= 255);
    __CPROVER_assume(sec_r001775_1 >= 0 && sec_r001775_1 <= 255);
    __CPROVER_assume(sec_r001775_2 >= 0 && sec_r001775_2 <= 255);
    __CPROVER_assume(sec_r001775_3 >= 0 && sec_r001775_3 <= 255);
    __CPROVER_assume(sec_r001775_4 >= 0 && sec_r001775_4 <= 255);
    __CPROVER_assume(sec_r001775_5 >= 0 && sec_r001775_5 <= 255);
    __CPROVER_assume(sec_r001775_6 >= 0 && sec_r001775_6 <= 255);
    __CPROVER_assume(sec_r001775_7 >= 0 && sec_r001775_7 <= 255);
    __CPROVER_assume(sec_r001775_8 >= 0 && sec_r001775_8 <= 255);
    __CPROVER_assume(sec_r001775_9 >= 0 && sec_r001775_9 <= 255);
    __CPROVER_assume(sec_r001775_10 >= 0 && sec_r001775_10 <= 255);
    __CPROVER_assume(sec_r001775_11 >= 0 && sec_r001775_11 <= 255);
    __CPROVER_assume(sec_r001775_12 >= 0 && sec_r001775_12 <= 255);
    __CPROVER_assume(sec_r001775_13 >= 0 && sec_r001775_13 <= 255);
    __CPROVER_assume(sec_r001775_14 >= 0 && sec_r001775_14 <= 255);
    __CPROVER_assume(sec_r001775_15 >= 0 && sec_r001775_15 <= 255);
    __CPROVER_assume(sec_r001775_16 >= 0 && sec_r001775_16 <= 255);
    __CPROVER_assume(sec_r001775_17 >= 0 && sec_r001775_17 <= 255);

    struct CipherContext_R001775_7513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001775_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001775_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001775_0 + 7) & 15;
    struct Transaction_R001775_7513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001775_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001775_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001775_0 + 9) & 15;

    union ColorPixel_R001775_7513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001775_7513_0(sec_r001775_0, sec_r001775_1, pub_r001775_2, pub_r001775_3);
    int helper_flow_1 = fn_R001775_7513_1(sec_r001775_1, pub_r001775_2, pub_r001775_3, pub_r001775_4, pub_r001775_5);
    int helper_flow_2 = fn_R001775_7513_2(sec_r001775_2, pub_r001775_3, pub_r001775_4, pub_r001775_5);
    int helper_flow_3 = fn_R001775_7513_3(sec_r001775_3, pub_r001775_4, pub_r001775_5, pub_r001775_6, pub_r001775_7);
    int helper_flow_4 = fn_R001775_7513_4(sec_r001775_4, sec_r001775_5, pub_r001775_6, pub_r001775_7);
    int helper_flow_5 = fn_R001775_7513_5(sec_r001775_5, sec_r001775_6, pub_r001775_7, pub_r001775_8, pub_r001775_9);
    int helper_flow_6 = fn_R001775_7513_6(sec_r001775_6, sec_r001775_7, pub_r001775_8, pub_r001775_9, pub_r001775_10);
    int helper_flow_7 = fn_R001775_7513_7(sec_r001775_7, pub_r001775_8);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (pub_r001775_1 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_0) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001775_5 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (pub_r001775_4 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_2) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((helper_flow_5 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_3 + 1) & 15;
    out_sink ^= (stage_v_3 & 63);

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001775_10 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((sec_r001775_3 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_5 + 1) & 15;
    out_sink ^= (stage_v_5 & 63);

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (pub_r001775_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_6) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((sec_r001775_15 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_7 + 1) & 15;
    out_sink ^= (stage_v_7 & 63);

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((helper_flow_7 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_8 + 1) & 15;
    out_sink ^= (stage_v_8 & 63);

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((sec_r001775_1 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_9 + 1) & 15;
    out_sink ^= (stage_v_9 & 63);

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001775_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((sec_r001775_2 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_11 + 1) & 15;
    out_sink ^= (stage_v_11 & 63);

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (pub_r001775_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_12) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001775_7 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001775_8 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001775_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001775_12 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001775_10 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001775_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = ((sec_r001775_2 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_19 + 1) & 15;
    out_sink ^= (stage_v_19 & 63);

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((helper_flow_6 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_20 + 1) & 15;
    out_sink ^= (stage_v_20 & 63);

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001775_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((helper_flow_4 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_22 + 1) & 15;
    out_sink ^= (stage_v_22 & 63);

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = ((sec_r001775_0 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_23 + 1) & 15;
    out_sink ^= (stage_v_23 & 63);

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (pub_r001775_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_24) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = ((stage_v_8 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_25 + 1) & 15;
    out_sink ^= (stage_v_25 & 63);

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001775_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001775_17 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = ((helper_flow_2 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_28 + 1) & 15;
    out_sink ^= (stage_v_28 & 63);

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = ((stage_v_22 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_29 + 1) & 15;
    out_sink ^= (stage_v_29 & 63);

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((helper_flow_7 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_30 + 1) & 15;
    out_sink ^= (stage_v_30 & 63);

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001775_12 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001775_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (pub_r001775_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_33) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((stage_v_23 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_34 + 1) & 15;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((helper_flow_6 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_35 + 1) & 15;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001775_3 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001775_5 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_30 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_38 + 1) & 15;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (pub_r001775_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_39) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001775_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001775_7 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((sec_r001775_16 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_42 + 1) & 15;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_25 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_43 + 1) & 15;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (pub_r001775_5 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_44) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r001775_11 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_45 + 1) & 15;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001775_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001775_10 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001775_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((helper_flow_1 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_49 + 1) & 15;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((helper_flow_6 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_50 + 1) & 15;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((stage_v_22 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_51 + 1) & 15;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001775_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001775_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001775_2 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001775_4 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((sec_r001775_17 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_56 + 1) & 15;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((helper_flow_4 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_57 + 1) & 15;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001775_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((sec_r001775_13 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_59 + 1) & 15;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_56 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_60 + 1) & 15;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r001775_3 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_61 + 1) & 15;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((stage_v_57 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_62 + 1) & 15;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_8 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_63 + 1) & 15;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((stage_v_42 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_64 + 1) & 15;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (pub_r001775_11 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_65) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_51 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_66 + 1) & 15;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001775_0 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((stage_v_30 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_68 + 1) & 15;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((sec_r001775_4 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_69 + 1) & 15;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001775_1 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_49 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_71 + 1) & 15;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_42 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_72 + 1) & 15;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((helper_flow_1 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_73 + 1) & 15;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (pub_r001775_13 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_74) & 127;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001775_13 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_5 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_76 + 1) & 15;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001775_17 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001775_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (pub_r001775_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_79) & 127;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((stage_v_61 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_80 + 1) & 15;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001775_10 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_43 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_82 + 1) & 15;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001775_0 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001775_6 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001775_13 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (pub_r001775_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_86) & 127;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001775_5 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001775_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_66 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_89 + 1) & 15;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (pub_r001775_16 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_90) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((helper_flow_0 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_91 + 1) & 15;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001775_11 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_68 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_93 + 1) & 15;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_82 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_94 + 1) & 15;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((sec_r001775_2 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_95 + 1) & 15;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001775_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001775_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001775_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((stage_v_73 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_99 + 1) & 15;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001775_19 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((helper_flow_5 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_101 + 1) & 15;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_35 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_102 + 1) & 15;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (pub_r001775_13 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_103) & 127;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((sec_r001775_16 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_104 + 1) & 15;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_99 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_105 + 1) & 15;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_71 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_106 + 1) & 15;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_71 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_107 + 1) & 15;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_60 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_108 + 1) & 15;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_59 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_109 + 1) & 15;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_30 << 1) ^ (pub_r001775_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_110 + 1) & 15;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((stage_v_25 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_111 + 1) & 15;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001775_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r001775_11 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_113 + 1) & 15;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001775_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001775_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((sec_r001775_8 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_116 + 1) & 15;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_25 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_117 + 1) & 15;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (pub_r001775_18 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_118) & 127;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_25 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_119 + 1) & 15;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((helper_flow_5 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_120 + 1) & 15;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((stage_v_76 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_121 + 1) & 15;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r001775_11 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_122 + 1) & 15;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((sec_r001775_9 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_123 + 1) & 15;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001775_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((helper_flow_4 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_125 + 1) & 15;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001775_0 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_45 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_127 + 1) & 15;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_82 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_128 + 1) & 15;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001775_18 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((sec_r001775_1 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_130 + 1) & 15;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001775_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_50 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_132 + 1) & 15;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001775_13 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((stage_v_119 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_134 + 1) & 15;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001775_16 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001775_0 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001775_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_56 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_138 + 1) & 15;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((helper_flow_7 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_139 + 1) & 15;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001775_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001775_17 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001775_12 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_66 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_143 + 1) & 15;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001775_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001775_11 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001775_0 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (pub_r001775_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_147) & 127;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_120 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_148 + 1) & 15;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((sec_r001775_1 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_149 + 1) & 15;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (pub_r001775_6 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_150) & 127;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001775_1 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001775_18 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_49 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_153 + 1) & 15;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_11 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_154 + 1) & 15;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_66 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_155 + 1) & 15;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((sec_r001775_17 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_156 + 1) & 15;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (pub_r001775_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_157) & 127;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_3 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_158 + 1) & 15;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001775_16 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_99 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_160 + 1) & 15;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((stage_v_51 << 1) ^ (pub_r001775_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_161 + 1) & 15;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((stage_v_107 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_162 + 1) & 15;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001775_3 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001775_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_148 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_165 + 1) & 15;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001775_11 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001775_4 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001775_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_154 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_169 + 1) & 15;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (pub_r001775_6 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_170) & 127;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (pub_r001775_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_171) & 127;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001775_14 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_154 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_173 + 1) & 15;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r001775_12 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_174 + 1) & 15;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001775_15 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001775_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((stage_v_63 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_177 + 1) & 15;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((sec_r001775_6 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_178 + 1) & 15;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((sec_r001775_1 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_179 + 1) & 15;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((stage_v_174 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_180 + 1) & 15;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((stage_v_108 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_181 + 1) & 15;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001775_18 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (pub_r001775_5 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_183) & 127;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((sec_r001775_11 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_184 + 1) & 15;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001775_0 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((helper_flow_4 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_186 + 1) & 15;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001775_2 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001775_9 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_30 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_189 + 1) & 15;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_106 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_190 + 1) & 15;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_179 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_191 + 1) & 15;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_121 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_192 + 1) & 15;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((helper_flow_2 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_193 + 1) & 15;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001775_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r001775_5 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_195 + 1) & 15;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001775_5 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (pub_r001775_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_197) & 127;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_22 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_198 + 1) & 15;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001775_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001775_6 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_69 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_201 + 1) & 15;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_62 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_202 + 1) & 15;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001775_10 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (pub_r001775_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_204) & 127;

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001775_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((stage_v_127 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_206 + 1) & 15;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (pub_r001775_14 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_207) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001775_11 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (pub_r001775_0 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_209) & 127;

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_102 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_210 + 1) & 15;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_132 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_211 + 1) & 15;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (pub_r001775_18 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_212) & 127;

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (pub_r001775_10 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_213) & 127;

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_7 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_214 + 1) & 15;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_121 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_215 + 1) & 15;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((sec_r001775_0 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_216 + 1) & 15;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (pub_r001775_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_217) & 127;

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_56 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_218 + 1) & 15;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_22 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_219 + 1) & 15;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_49 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_220 + 1) & 15;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((helper_flow_3 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_221 + 1) & 15;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (pub_r001775_15 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_222) & 127;

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001775_7 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_11 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_224 + 1) & 15;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((sec_r001775_1 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_225 + 1) & 15;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((helper_flow_3 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_226 + 1) & 15;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_219 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_227 + 1) & 15;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((stage_v_154 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_228 + 1) & 15;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((stage_v_94 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_229 + 1) & 15;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r001775_10 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_230 + 1) & 15;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_156 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_231 + 1) & 15;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_125 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_232 + 1) & 15;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((stage_v_125 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_233 + 1) & 15;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_94 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_234 + 1) & 15;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (pub_r001775_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_235) & 127;

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((stage_v_195 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_236 + 1) & 15;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001775_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_11 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_238 + 1) & 15;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((stage_v_138 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_239 + 1) & 15;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_169 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_240 + 1) & 15;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((stage_v_134 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_241 + 1) & 15;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (pub_r001775_15 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_242) & 127;

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001775_8 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((helper_flow_4 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_244 + 1) & 15;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_155 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_245 + 1) & 15;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (pub_r001775_17 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_246) & 127;

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001775_15 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_215 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_248 + 1) & 15;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (pub_r001775_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_249) & 127;

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_220 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_250 + 1) & 15;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (pub_r001775_5 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_251) & 127;

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((stage_v_119 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_252 + 1) & 15;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_238 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_253 + 1) & 15;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_143 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_254 + 1) & 15;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (pub_r001775_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_255) & 127;

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001775_15 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001775_14 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((helper_flow_3 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_258 + 1) & 15;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (pub_r001775_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_259) & 127;

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001775_9 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_119 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_261 + 1) & 15;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (pub_r001775_10 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_262) & 127;

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (pub_r001775_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_263) & 127;

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (pub_r001775_10 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_264) & 127;

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (pub_r001775_4 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_265) & 127;

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (pub_r001775_15 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_266) & 127;

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_111 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_267 + 1) & 15;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001775_0 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (pub_r001775_3 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_269) & 127;

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_113 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_270 + 1) & 15;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((stage_v_3 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_271 + 1) & 15;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((stage_v_99 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_272 + 1) & 15;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = (pub_r001775_3 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_273) & 127;

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = (pub_r001775_11 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_274) & 127;

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = (pub_r001775_2 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_275) & 127;

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_121 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_276 + 1) & 15;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((stage_v_45 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_277 + 1) & 15;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = (pub_r001775_6 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_278) & 127;

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = (pub_r001775_15 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_279) & 127;

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((sec_r001775_15 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_280 + 1) & 15;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_250 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_281 + 1) & 15;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((sec_r001775_6 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_282 + 1) & 15;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((sec_r001775_16 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_283 + 1) & 15;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = (pub_r001775_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_284) & 127;

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((stage_v_210 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_285 + 1) & 15;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = (pub_r001775_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_286) & 127;

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_25 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_287 + 1) & 15;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = (pub_r001775_7 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_288) & 127;

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_214 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_289 + 1) & 15;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = (pub_r001775_0 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_290) & 127;

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = (pub_r001775_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_291) & 127;

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_230 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_292 + 1) & 15;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((stage_v_72 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_293 + 1) & 15;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = (pub_r001775_8 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_294) & 127;

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = (pub_r001775_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_295) & 127;

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_138 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_296 + 1) & 15;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_155 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_297 + 1) & 15;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((helper_flow_7 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_298 + 1) & 15;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_227 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_299 + 1) & 15;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((stage_v_5 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_300 + 1) & 15;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = (pub_r001775_19 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_301) & 127;

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_160 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_302 + 1) & 15;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((sec_r001775_15 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_303 + 1) & 15;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_245 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_304 + 1) & 15;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = (pub_r001775_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_305) & 127;

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = (pub_r001775_15 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_306) & 127;

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_23 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_307 + 1) & 15;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_139 << 1) ^ (pub_r001775_4 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_308 + 1) & 15;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((stage_v_186 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_309 + 1) & 15;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = (pub_r001775_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_310) & 127;

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_181 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_311 + 1) & 15;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = (pub_r001775_9 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_312) & 127;

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_29 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_313 + 1) & 15;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = (pub_r001775_15 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_314) & 127;

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = (pub_r001775_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_315) & 127;

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = (pub_r001775_3 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_316) & 127;

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_258 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_317 + 1) & 15;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = (pub_r001775_9 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_318) & 127;

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_3 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_319 + 1) & 15;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_80 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_320 + 1) & 15;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = (pub_r001775_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_321) & 127;

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = (pub_r001775_3 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_322) & 127;

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_191 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_323 + 1) & 15;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = (pub_r001775_18 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_324) & 127;

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_250 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_325 + 1) & 15;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_184 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_326 + 1) & 15;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = (pub_r001775_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_327) & 127;

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((stage_v_73 << 1) ^ (pub_r001775_2 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_328 + 1) & 15;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = (pub_r001775_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_329) & 127;

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((helper_flow_2 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_330 + 1) & 15;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = (pub_r001775_6 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_331) & 127;

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = (pub_r001775_1 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_332) & 127;

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = (pub_r001775_8 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_333) & 127;

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = (pub_r001775_12 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_334) & 127;

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((sec_r001775_6 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_335 + 1) & 15;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = (pub_r001775_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_336) & 127;

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((stage_v_296 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_337 + 1) & 15;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_62 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_338 + 1) & 15;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((sec_r001775_17 << 1) ^ (pub_r001775_11 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_339 + 1) & 15;
    out_sink ^= (stage_v_339 & 63);

    /* Execution Pipeline Stage 340 */
    int stage_v_340 = ((stage_v_210 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_340 + 1) & 15;
    out_sink ^= (stage_v_340 & 63);

    /* Execution Pipeline Stage 341 */
    int stage_v_341 = (pub_r001775_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_341) & 127;

    /* Execution Pipeline Stage 342 */
    int stage_v_342 = ((stage_v_94 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_342 + 1) & 15;
    out_sink ^= (stage_v_342 & 63);

    /* Execution Pipeline Stage 343 */
    int stage_v_343 = ((helper_flow_4 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_343 + 1) & 15;
    out_sink ^= (stage_v_343 & 63);

    /* Execution Pipeline Stage 344 */
    int stage_v_344 = ((stage_v_339 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_344 + 1) & 15;
    out_sink ^= (stage_v_344 & 63);

    /* Execution Pipeline Stage 345 */
    int stage_v_345 = ((helper_flow_1 << 1) ^ (pub_r001775_1 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_345 + 1) & 15;
    out_sink ^= (stage_v_345 & 63);

    /* Execution Pipeline Stage 346 */
    int stage_v_346 = (pub_r001775_4 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_346) & 127;

    /* Execution Pipeline Stage 347 */
    int stage_v_347 = ((stage_v_277 << 1) ^ (pub_r001775_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_347 + 1) & 15;
    out_sink ^= (stage_v_347 & 63);

    /* Execution Pipeline Stage 348 */
    int stage_v_348 = ((stage_v_130 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_348 + 1) & 15;
    out_sink ^= (stage_v_348 & 63);

    /* Execution Pipeline Stage 349 */
    int stage_v_349 = (pub_r001775_7 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_349) & 127;

    /* Execution Pipeline Stage 350 */
    int stage_v_350 = (pub_r001775_3 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_350) & 127;

    /* Execution Pipeline Stage 351 */
    int stage_v_351 = (pub_r001775_18 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_351) & 127;

    /* Execution Pipeline Stage 352 */
    int stage_v_352 = (pub_r001775_14 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_352) & 127;

    /* Execution Pipeline Stage 353 */
    int stage_v_353 = ((stage_v_20 << 1) ^ (pub_r001775_4 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_353 + 1) & 15;
    out_sink ^= (stage_v_353 & 63);

    /* Execution Pipeline Stage 354 */
    int stage_v_354 = ((stage_v_127 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_354 + 1) & 15;
    out_sink ^= (stage_v_354 & 63);

    /* Execution Pipeline Stage 355 */
    int stage_v_355 = (pub_r001775_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_355) & 127;

    /* Execution Pipeline Stage 356 */
    int stage_v_356 = ((stage_v_50 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_356 + 1) & 15;
    out_sink ^= (stage_v_356 & 63);

    /* Execution Pipeline Stage 357 */
    int stage_v_357 = ((stage_v_190 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_357 + 1) & 15;
    out_sink ^= (stage_v_357 & 63);

    /* Execution Pipeline Stage 358 */
    int stage_v_358 = ((stage_v_102 << 1) ^ (pub_r001775_9 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_358 + 1) & 15;
    out_sink ^= (stage_v_358 & 63);

    /* Execution Pipeline Stage 359 */
    int stage_v_359 = ((stage_v_281 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_359 + 1) & 15;
    out_sink ^= (stage_v_359 & 63);

    /* Execution Pipeline Stage 360 */
    int stage_v_360 = ((sec_r001775_7 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_360 + 1) & 15;
    out_sink ^= (stage_v_360 & 63);

    /* Execution Pipeline Stage 361 */
    int stage_v_361 = ((sec_r001775_4 << 1) ^ (pub_r001775_19 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_361 + 1) & 15;
    out_sink ^= (stage_v_361 & 63);

    /* Execution Pipeline Stage 362 */
    int stage_v_362 = ((stage_v_357 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_362 + 1) & 15;
    out_sink ^= (stage_v_362 & 63);

    /* Execution Pipeline Stage 363 */
    int stage_v_363 = (pub_r001775_7 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_363) & 127;

    /* Execution Pipeline Stage 364 */
    int stage_v_364 = ((stage_v_221 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_364 + 1) & 15;
    out_sink ^= (stage_v_364 & 63);

    /* Execution Pipeline Stage 365 */
    int stage_v_365 = ((stage_v_49 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_365 + 1) & 15;
    out_sink ^= (stage_v_365 & 63);

    /* Execution Pipeline Stage 366 */
    int stage_v_366 = ((stage_v_7 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_366 + 1) & 15;
    out_sink ^= (stage_v_366 & 63);

    /* Execution Pipeline Stage 367 */
    int stage_v_367 = (pub_r001775_16 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_367) & 127;

    /* Execution Pipeline Stage 368 */
    int stage_v_368 = (pub_r001775_5 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_368) & 127;

    /* Execution Pipeline Stage 369 */
    int stage_v_369 = (pub_r001775_9 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_369) & 127;

    /* Execution Pipeline Stage 370 */
    int stage_v_370 = ((stage_v_130 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_370 + 1) & 15;
    out_sink ^= (stage_v_370 & 63);

    /* Execution Pipeline Stage 371 */
    int stage_v_371 = (pub_r001775_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_371) & 127;

    /* Execution Pipeline Stage 372 */
    int stage_v_372 = (pub_r001775_14 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_372) & 127;

    /* Execution Pipeline Stage 373 */
    int stage_v_373 = ((stage_v_302 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_373 + 1) & 15;
    out_sink ^= (stage_v_373 & 63);

    /* Execution Pipeline Stage 374 */
    int stage_v_374 = ((stage_v_128 << 1) ^ (pub_r001775_0 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_374 + 1) & 15;
    out_sink ^= (stage_v_374 & 63);

    /* Execution Pipeline Stage 375 */
    int stage_v_375 = (pub_r001775_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_375) & 127;

    /* Execution Pipeline Stage 376 */
    int stage_v_376 = ((stage_v_304 << 1) ^ (pub_r001775_6 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_376 + 1) & 15;
    out_sink ^= (stage_v_376 & 63);

    /* Execution Pipeline Stage 377 */
    int stage_v_377 = (pub_r001775_12 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_377) & 127;

    /* Execution Pipeline Stage 378 */
    int stage_v_378 = (pub_r001775_17 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_378) & 127;

    /* Execution Pipeline Stage 379 */
    int stage_v_379 = (pub_r001775_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_379) & 127;

    /* Execution Pipeline Stage 380 */
    int stage_v_380 = (pub_r001775_4 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_380) & 127;

    /* Execution Pipeline Stage 381 */
    int stage_v_381 = ((stage_v_61 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_381 + 1) & 15;
    out_sink ^= (stage_v_381 & 63);

    /* Execution Pipeline Stage 382 */
    int stage_v_382 = ((stage_v_62 << 1) ^ (pub_r001775_3 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_382 + 1) & 15;
    out_sink ^= (stage_v_382 & 63);

    /* Execution Pipeline Stage 383 */
    int stage_v_383 = ((stage_v_180 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_383 + 1) & 15;
    out_sink ^= (stage_v_383 & 63);

    /* Execution Pipeline Stage 384 */
    int stage_v_384 = ((sec_r001775_14 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_384 + 1) & 15;
    out_sink ^= (stage_v_384 & 63);

    /* Execution Pipeline Stage 385 */
    int stage_v_385 = (pub_r001775_9 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_385) & 127;

    /* Execution Pipeline Stage 386 */
    int stage_v_386 = ((stage_v_227 << 1) ^ (pub_r001775_5 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_386 + 1) & 15;
    out_sink ^= (stage_v_386 & 63);

    /* Execution Pipeline Stage 387 */
    int stage_v_387 = ((stage_v_307 << 1) ^ (pub_r001775_13 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_387 + 1) & 15;
    out_sink ^= (stage_v_387 & 63);

    /* Execution Pipeline Stage 388 */
    int stage_v_388 = ((stage_v_178 << 1) ^ (pub_r001775_15 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_388 + 1) & 15;
    out_sink ^= (stage_v_388 & 63);

    /* Execution Pipeline Stage 389 */
    int stage_v_389 = ((helper_flow_4 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_1.buffer[2] = (stage_v_389 + 1) & 15;
    out_sink ^= (stage_v_389 & 63);

    /* Execution Pipeline Stage 390 */
    int stage_v_390 = (pub_r001775_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_390) & 127;

    /* Execution Pipeline Stage 391 */
    int stage_v_391 = ((helper_flow_4 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_391 + 1) & 15;
    out_sink ^= (stage_v_391 & 63);

    /* Execution Pipeline Stage 392 */
    int stage_v_392 = ((stage_v_252 << 1) ^ (pub_r001775_17 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_392 + 1) & 15;
    out_sink ^= (stage_v_392 & 63);

    /* Execution Pipeline Stage 393 */
    int stage_v_393 = (pub_r001775_16 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_393) & 127;

    /* Execution Pipeline Stage 394 */
    int stage_v_394 = ((stage_v_241 << 1) ^ (pub_r001775_14 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_394 + 1) & 15;
    out_sink ^= (stage_v_394 & 63);

    /* Execution Pipeline Stage 395 */
    int stage_v_395 = (pub_r001775_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_395) & 127;

    /* Execution Pipeline Stage 396 */
    int stage_v_396 = (pub_r001775_19 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_396) & 127;

    /* Execution Pipeline Stage 397 */
    int stage_v_397 = ((stage_v_229 << 1) ^ (pub_r001775_18 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_397 + 1) & 15;
    out_sink ^= (stage_v_397 & 63);

    /* Execution Pipeline Stage 398 */
    int stage_v_398 = (pub_r001775_17 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_398) & 127;

    /* Execution Pipeline Stage 399 */
    int stage_v_399 = (pub_r001775_11 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_399) & 127;

    /* Execution Pipeline Stage 400 */
    int stage_v_400 = ((stage_v_309 << 1) ^ (pub_r001775_12 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_400 + 1) & 15;
    out_sink ^= (stage_v_400 & 63);

    /* Execution Pipeline Stage 401 */
    int stage_v_401 = (pub_r001775_11 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_401) & 127;

    /* Execution Pipeline Stage 402 */
    int stage_v_402 = ((stage_v_5 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[0] = (stage_v_402 + 1) & 15;
    out_sink ^= (stage_v_402 & 63);

    /* Execution Pipeline Stage 403 */
    int stage_v_403 = ((sec_r001775_13 << 1) ^ (pub_r001775_7 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_403 + 1) & 15;
    out_sink ^= (stage_v_403 & 63);

    /* Execution Pipeline Stage 404 */
    int stage_v_404 = (pub_r001775_6 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_404) & 127;

    /* Execution Pipeline Stage 405 */
    int stage_v_405 = (pub_r001775_12 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_405) & 127;

    /* Execution Pipeline Stage 406 */
    int stage_v_406 = ((stage_v_348 << 1) ^ (pub_r001775_16 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_406 + 1) & 15;
    out_sink ^= (stage_v_406 & 63);

    /* Execution Pipeline Stage 407 */
    int stage_v_407 = (pub_r001775_3 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_407) & 127;

    /* Execution Pipeline Stage 408 */
    int stage_v_408 = (pub_r001775_11 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_408) & 127;

    /* Execution Pipeline Stage 409 */
    int stage_v_409 = (pub_r001775_16 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_409) & 127;

    /* Execution Pipeline Stage 410 */
    int stage_v_410 = ((stage_v_73 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_0.buffer[2] = (stage_v_410 + 1) & 15;
    out_sink ^= (stage_v_410 & 63);

    /* Execution Pipeline Stage 411 */
    int stage_v_411 = (pub_r001775_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_411) & 127;

    /* Execution Pipeline Stage 412 */
    int stage_v_412 = ((stage_v_289 << 1) ^ (pub_r001775_4 >> 1)) & 127;
    st_var_0.buffer[1] = (stage_v_412 + 1) & 15;
    out_sink ^= (stage_v_412 & 63);

    /* Execution Pipeline Stage 413 */
    int stage_v_413 = (pub_r001775_8 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_413) & 127;

    /* Execution Pipeline Stage 414 */
    int stage_v_414 = (pub_r001775_4 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_414) & 127;

    /* Execution Pipeline Stage 415 */
    int stage_v_415 = ((stage_v_403 << 1) ^ (pub_r001775_10 >> 1)) & 127;
    st_var_1.buffer[1] = (stage_v_415 + 1) & 15;
    out_sink ^= (stage_v_415 & 63);

    /* Execution Pipeline Stage 416 */
    int stage_v_416 = (pub_r001775_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_416) & 127;

    /* Execution Pipeline Stage 417 */
    int stage_v_417 = ((stage_v_230 << 1) ^ (pub_r001775_8 >> 1)) & 127;
    st_var_1.buffer[0] = (stage_v_417 + 1) & 15;
    out_sink ^= (stage_v_417 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
