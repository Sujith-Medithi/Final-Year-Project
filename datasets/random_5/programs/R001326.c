/*
 * Benchmark Program: R001326
 * Security Family: implicit_flow
 * Generator Seed: 632613
 * High Inputs: 19 | Low Inputs: 19
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R001326_2613_0 {
    int seq;
    short facility;
    short code;
    int buffer[3];
};

struct FilterState_R001326_2613_1 {
    unsigned char gain_db;
    int damping;
    short prev_in;
    short prev_out;
    int mode;
    int buffer[3];
};

struct AudioFrame_R001326_2613_2 {
    unsigned char rms;
    short sample_rate;
    int channels;
    int gain;
    int buffer[3];
};

union ColorPixel_R001326_2613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001326_2613_0(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001326_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int vector_46 = local_arr[aux % 3];
    acc = (acc + vector_46 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001326_2613_1(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001326_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int delta_28 = (aux + st.buffer[1]) & 3;
    switch (delta_28) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_35) & 63;
    acc ^= aux;
    int weight_13 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_13 > 42) {
        acc = (acc + weight_13 * 2 + 5) & 127;
        aux ^= (weight_13 & 15);
    } else {
        acc = (acc - weight_13 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001326_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int mask_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_74) & 63;
    acc ^= aux;
    int checksum_14 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_14 > 12) {
        acc = (acc + checksum_14 * 2 + 5) & 127;
        aux ^= (checksum_14 & 15);
    } else {
        acc = (acc - checksum_14 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_3(int p0, int p1, int p2) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int accumulator_43 = 0;
    for (int k = 0; k < 3; k++) {
        accumulator_43 = (accumulator_43 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + accumulator_43) & 127;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_90 = local_arr[aux % 3];
    acc = (acc + pivot_90 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_50 = (aux + st.buffer[1]) & 3;
    switch (offset_50) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001326_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int offset_80 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_80 > 36) {
        acc = (acc + offset_80 * 2 + 5) & 127;
        aux ^= (offset_80 & 15);
    } else {
        acc = (acc - offset_80 + 11) & 127;
        aux += 3;
    }
    int checksum_36 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_36 = (checksum_36 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_36) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_5(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001326_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int stride_39 = (aux + st.buffer[1]) & 3;
    switch (stride_39) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_99 = local_arr[aux % 3];
    acc = (acc + anchor_99 * 2) & 127;
    int segment_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_72) & 63;
    acc ^= aux;
    int bound_77 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_77 > 18) {
        acc = (acc + bound_77 * 2 + 5) & 127;
        aux ^= (bound_77 & 15);
    } else {
        acc = (acc - bound_77 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_6(int p0, int p1) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001326_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int window_15 = (aux + st.buffer[1]) & 3;
    switch (window_15) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int threshold_49 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_49) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001326_2613_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int checksum_85 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_85 = (checksum_85 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_85) & 127;
    }
    int window_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_54) & 63;
    acc ^= aux;
    int tally_83 = (aux + st.buffer[1]) & 3;
    switch (tally_83) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_8(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int vector_18 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_18) & 63;
    acc ^= aux;
    int damping_50 = (aux + st.buffer[1]) & 3;
    switch (damping_50) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_41 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_41 > 26) {
        acc = (acc + pivot_41 * 2 + 5) & 127;
        aux ^= (pivot_41 & 15);
    } else {
        acc = (acc - pivot_41 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_66 = local_arr[aux % 3];
    acc = (acc + window_66 * 2) & 127;
    int index_reg_44 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_44) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001326_2613_10(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int scale_30 = (aux + st.buffer[1]) & 3;
    switch (scale_30) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int index_reg_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_42) & 63;
    acc ^= aux;
    int damping_80 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_80 > 10) {
        acc = (acc + damping_80 * 2 + 5) & 127;
        aux ^= (damping_80 & 15);
    } else {
        acc = (acc - damping_80 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001326_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int local_arr[3] = {4, 9, 15};
    int tracker_74 = local_arr[aux % 3];
    acc = (acc + tracker_74 * 2) & 127;
    int tracker_11 = 0;
    for (int k = 0; k < 3; k++) {
        tracker_11 = (tracker_11 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tracker_11) & 127;
    }
    int tracker_60 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_60 > 15) {
        acc = (acc + tracker_60 * 2 + 5) & 127;
        aux ^= (tracker_60 & 15);
    } else {
        acc = (acc - tracker_60 + 11) & 127;
        aux += 3;
    }
    int cursor_64 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_64) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001326_2613_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001326_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int anchor_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_37) & 63;
    acc ^= aux;
    int vector_99 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_99 > 42) {
        acc = (acc + vector_99 * 2 + 5) & 127;
        aux ^= (vector_99 & 15);
    } else {
        acc = (acc - vector_99 + 11) & 127;
        aux += 3;
    }
    int delta_42 = (aux + st.buffer[1]) & 3;
    switch (delta_42) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_53 = local_arr[aux % 3];
    acc = (acc + stride_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001326_2613_13(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001326_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int factor_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_63) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_14 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_14 > 42) {
        acc = (acc + pivot_14 * 2 + 5) & 127;
        aux ^= (pivot_14 & 15);
    } else {
        acc = (acc - pivot_14 + 11) & 127;
        aux += 3;
    }
    int pivot_12 = (aux + st.buffer[1]) & 3;
    switch (pivot_12) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001326_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_49 = (aux + st.buffer[1]) & 3;
    switch (pivot_49) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001326_2613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int sample_28 = (aux + st.buffer[1]) & 3;
    switch (sample_28) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001326_2613_16(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001326_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int quotient_52 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_52 > 39) {
        acc = (acc + quotient_52 * 2 + 5) & 127;
        aux ^= (quotient_52 & 15);
    } else {
        acc = (acc - quotient_52 + 11) & 127;
        aux += 3;
    }
    int checksum_67 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_67 = (checksum_67 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_67) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_90 = local_arr[aux % 3];
    acc = (acc + accumulator_90 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001326_2613_17(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001326_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int window_22 = (st.buffer[0] * 3 + aux) & 63;
    if (window_22 > 39) {
        acc = (acc + window_22 * 2 + 5) & 127;
        aux ^= (window_22 & 15);
    } else {
        acc = (acc - window_22 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_76 = local_arr[aux % 3];
    acc = (acc + parity_76 * 2) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r001326_0;
    int sec_r001326_1;
    int sec_r001326_2;
    int sec_r001326_3;
    int sec_r001326_4;
    int sec_r001326_5;
    int sec_r001326_6;
    int sec_r001326_7;
    int sec_r001326_8;
    int sec_r001326_9;
    int sec_r001326_10;
    int sec_r001326_11;
    int sec_r001326_12;
    int sec_r001326_13;
    int sec_r001326_14;
    int sec_r001326_15;
    int sec_r001326_16;
    int sec_r001326_17;
    int sec_r001326_18;
    int pub_r001326_0;
    int pub_r001326_1;
    int pub_r001326_2;
    int pub_r001326_3;
    int pub_r001326_4;
    int pub_r001326_5;
    int pub_r001326_6;
    int pub_r001326_7;
    int pub_r001326_8;
    int pub_r001326_9;
    int pub_r001326_10;
    int pub_r001326_11;
    int pub_r001326_12;
    int pub_r001326_13;
    int pub_r001326_14;
    int pub_r001326_15;
    int pub_r001326_16;
    int pub_r001326_17;
    int pub_r001326_18;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001326_0 >= -100 && pub_r001326_0 <= 100);
    __CPROVER_assume(pub_r001326_1 >= -100 && pub_r001326_1 <= 100);
    __CPROVER_assume(pub_r001326_2 >= -100 && pub_r001326_2 <= 100);
    __CPROVER_assume(pub_r001326_3 >= -100 && pub_r001326_3 <= 100);
    __CPROVER_assume(pub_r001326_4 >= -100 && pub_r001326_4 <= 100);
    __CPROVER_assume(pub_r001326_5 >= -100 && pub_r001326_5 <= 100);
    __CPROVER_assume(pub_r001326_6 >= -100 && pub_r001326_6 <= 100);
    __CPROVER_assume(pub_r001326_7 >= -100 && pub_r001326_7 <= 100);
    __CPROVER_assume(pub_r001326_8 >= -100 && pub_r001326_8 <= 100);
    __CPROVER_assume(pub_r001326_9 >= -100 && pub_r001326_9 <= 100);
    __CPROVER_assume(pub_r001326_10 >= -100 && pub_r001326_10 <= 100);
    __CPROVER_assume(pub_r001326_11 >= -100 && pub_r001326_11 <= 100);
    __CPROVER_assume(pub_r001326_12 >= -100 && pub_r001326_12 <= 100);
    __CPROVER_assume(pub_r001326_13 >= -100 && pub_r001326_13 <= 100);
    __CPROVER_assume(pub_r001326_14 >= -100 && pub_r001326_14 <= 100);
    __CPROVER_assume(pub_r001326_15 >= -100 && pub_r001326_15 <= 100);
    __CPROVER_assume(pub_r001326_16 >= -100 && pub_r001326_16 <= 100);
    __CPROVER_assume(pub_r001326_17 >= -100 && pub_r001326_17 <= 100);
    __CPROVER_assume(pub_r001326_18 >= -100 && pub_r001326_18 <= 100);
    __CPROVER_assume(sec_r001326_0 >= 0 && sec_r001326_0 <= 255);
    __CPROVER_assume(sec_r001326_1 >= 0 && sec_r001326_1 <= 255);
    __CPROVER_assume(sec_r001326_2 >= 0 && sec_r001326_2 <= 255);
    __CPROVER_assume(sec_r001326_3 >= 0 && sec_r001326_3 <= 255);
    __CPROVER_assume(sec_r001326_4 >= 0 && sec_r001326_4 <= 255);
    __CPROVER_assume(sec_r001326_5 >= 0 && sec_r001326_5 <= 255);
    __CPROVER_assume(sec_r001326_6 >= 0 && sec_r001326_6 <= 255);
    __CPROVER_assume(sec_r001326_7 >= 0 && sec_r001326_7 <= 255);
    __CPROVER_assume(sec_r001326_8 >= 0 && sec_r001326_8 <= 255);
    __CPROVER_assume(sec_r001326_9 >= 0 && sec_r001326_9 <= 255);
    __CPROVER_assume(sec_r001326_10 >= 0 && sec_r001326_10 <= 255);
    __CPROVER_assume(sec_r001326_11 >= 0 && sec_r001326_11 <= 255);
    __CPROVER_assume(sec_r001326_12 >= 0 && sec_r001326_12 <= 255);
    __CPROVER_assume(sec_r001326_13 >= 0 && sec_r001326_13 <= 255);
    __CPROVER_assume(sec_r001326_14 >= 0 && sec_r001326_14 <= 255);
    __CPROVER_assume(sec_r001326_15 >= 0 && sec_r001326_15 <= 255);
    __CPROVER_assume(sec_r001326_16 >= 0 && sec_r001326_16 <= 255);
    __CPROVER_assume(sec_r001326_17 >= 0 && sec_r001326_17 <= 255);
    __CPROVER_assume(sec_r001326_18 >= 0 && sec_r001326_18 <= 255);

    struct EventLog_R001326_2613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001326_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001326_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001326_0 + 7) & 15;
    struct FilterState_R001326_2613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001326_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001326_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001326_0 + 9) & 15;
    struct AudioFrame_R001326_2613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001326_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001326_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001326_0 + 11) & 15;

    union ColorPixel_R001326_2613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001326_2613_0(sec_r001326_0, sec_r001326_1, pub_r001326_2);
    int helper_flow_1 = fn_R001326_2613_1(sec_r001326_1, sec_r001326_2, pub_r001326_3);
    int helper_flow_2 = fn_R001326_2613_2(sec_r001326_2, sec_r001326_3, pub_r001326_4, pub_r001326_5);
    int helper_flow_3 = fn_R001326_2613_3(sec_r001326_3, pub_r001326_4, pub_r001326_5);
    int helper_flow_4 = fn_R001326_2613_4(sec_r001326_4, pub_r001326_5, pub_r001326_6, pub_r001326_7, pub_r001326_8);
    int helper_flow_5 = fn_R001326_2613_5(sec_r001326_5, pub_r001326_6, pub_r001326_7, pub_r001326_8);
    int helper_flow_6 = fn_R001326_2613_6(sec_r001326_6, pub_r001326_7);
    int helper_flow_7 = fn_R001326_2613_7(sec_r001326_7, pub_r001326_8, pub_r001326_9, pub_r001326_10, pub_r001326_11);
    int helper_flow_8 = fn_R001326_2613_8(sec_r001326_8, pub_r001326_9, pub_r001326_10);
    int helper_flow_9 = fn_R001326_2613_9(sec_r001326_9, sec_r001326_10, pub_r001326_11, pub_r001326_12, pub_r001326_13);
    int helper_flow_10 = fn_R001326_2613_10(sec_r001326_10, sec_r001326_11);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_1 + pub_r001326_2 * 2 + 5) & 127;
    if (stage_v_0 > 20) {
        out_sink = (out_sink + stage_v_0 * 2 + 7) & 255;
        sec_accum ^= (stage_v_0 & 31);
    } else {
        out_sink = (out_sink - stage_v_0 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001326_17 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_8 + pub_r001326_7 * 2 + 11) & 127;
    if (stage_v_2 > 45) {
        out_sink = (out_sink + stage_v_2 * 2 + 7) & 255;
        sec_accum ^= (stage_v_2 & 31);
    } else {
        out_sink = (out_sink - stage_v_2 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (helper_flow_4 + pub_r001326_12 * 2 + 14) & 127;
    if (stage_v_3 > 59) {
        out_sink = (out_sink + stage_v_3 * 2 + 7) & 255;
        sec_accum ^= (stage_v_3 & 31);
    } else {
        out_sink = (out_sink - stage_v_3 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_5 + pub_r001326_18 * 2 + 17) & 127;
    if (stage_v_4 > 24) {
        out_sink = (out_sink + stage_v_4 * 2 + 7) & 255;
        sec_accum ^= (stage_v_4 & 31);
    } else {
        out_sink = (out_sink - stage_v_4 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (helper_flow_1 + pub_r001326_8 * 2 + 20) & 127;
    if (stage_v_5 > 23) {
        out_sink = (out_sink + stage_v_5 * 2 + 7) & 255;
        sec_accum ^= (stage_v_5 & 31);
    } else {
        out_sink = (out_sink - stage_v_5 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (stage_v_3 + pub_r001326_2 * 2 + 23) & 127;
    if (stage_v_6 > 52) {
        out_sink = (out_sink + stage_v_6 * 2 + 7) & 255;
        sec_accum ^= (stage_v_6 & 31);
    } else {
        out_sink = (out_sink - stage_v_6 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (pub_r001326_11 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_7) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (helper_flow_7 + pub_r001326_14 * 2 + 29) & 127;
    if (stage_v_8 > 18) {
        out_sink = (out_sink + stage_v_8 * 2 + 7) & 255;
        sec_accum ^= (stage_v_8 & 31);
    } else {
        out_sink = (out_sink - stage_v_8 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001326_9 + pub_r001326_14 * 2 + 32) & 127;
    if (stage_v_9 > 49) {
        out_sink = (out_sink + stage_v_9 * 2 + 7) & 255;
        sec_accum ^= (stage_v_9 & 31);
    } else {
        out_sink = (out_sink - stage_v_9 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (stage_v_4 + pub_r001326_9 * 2 + 35) & 127;
    if (stage_v_10 > 44) {
        out_sink = (out_sink + stage_v_10 * 2 + 7) & 255;
        sec_accum ^= (stage_v_10 & 31);
    } else {
        out_sink = (out_sink - stage_v_10 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (stage_v_5 + pub_r001326_3 * 2 + 38) & 127;
    if (stage_v_11 > 29) {
        out_sink = (out_sink + stage_v_11 * 2 + 7) & 255;
        sec_accum ^= (stage_v_11 & 31);
    } else {
        out_sink = (out_sink - stage_v_11 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (sec_r001326_11 + pub_r001326_14 * 2 + 41) & 127;
    if (stage_v_12 > 17) {
        out_sink = (out_sink + stage_v_12 * 2 + 7) & 255;
        sec_accum ^= (stage_v_12 & 31);
    } else {
        out_sink = (out_sink - stage_v_12 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001326_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (helper_flow_10 + pub_r001326_0 * 2 + 47) & 127;
    if (stage_v_14 > 41) {
        out_sink = (out_sink + stage_v_14 * 2 + 7) & 255;
        sec_accum ^= (stage_v_14 & 31);
    } else {
        out_sink = (out_sink - stage_v_14 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (stage_v_0 + pub_r001326_5 * 2 + 50) & 127;
    if (stage_v_15 > 25) {
        out_sink = (out_sink + stage_v_15 * 2 + 7) & 255;
        sec_accum ^= (stage_v_15 & 31);
    } else {
        out_sink = (out_sink - stage_v_15 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (pub_r001326_16 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_16) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001326_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (stage_v_6 + pub_r001326_14 * 2 + 59) & 127;
    if (stage_v_18 > 19) {
        out_sink = (out_sink + stage_v_18 * 2 + 7) & 255;
        sec_accum ^= (stage_v_18 & 31);
    } else {
        out_sink = (out_sink - stage_v_18 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (pub_r001326_9 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_19) & 127;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (pub_r001326_18 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_20) & 127;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001326_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001326_15 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_12 + pub_r001326_17 * 2 + 74) & 127;
    if (stage_v_23 > 35) {
        out_sink = (out_sink + stage_v_23 * 2 + 7) & 255;
        sec_accum ^= (stage_v_23 & 31);
    } else {
        out_sink = (out_sink - stage_v_23 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_5 + pub_r001326_3 * 2 + 77) & 127;
    if (stage_v_24 > 15) {
        out_sink = (out_sink + stage_v_24 * 2 + 7) & 255;
        sec_accum ^= (stage_v_24 & 31);
    } else {
        out_sink = (out_sink - stage_v_24 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001326_2 + pub_r001326_7 * 2 + 80) & 127;
    if (stage_v_25 > 41) {
        out_sink = (out_sink + stage_v_25 * 2 + 7) & 255;
        sec_accum ^= (stage_v_25 & 31);
    } else {
        out_sink = (out_sink - stage_v_25 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001326_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_4 + pub_r001326_13 * 2 + 86) & 127;
    if (stage_v_27 > 21) {
        out_sink = (out_sink + stage_v_27 * 2 + 7) & 255;
        sec_accum ^= (stage_v_27 & 31);
    } else {
        out_sink = (out_sink - stage_v_27 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001326_5 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (sec_r001326_0 + pub_r001326_11 * 2 + 92) & 127;
    if (stage_v_29 > 21) {
        out_sink = (out_sink + stage_v_29 * 2 + 7) & 255;
        sec_accum ^= (stage_v_29 & 31);
    } else {
        out_sink = (out_sink - stage_v_29 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (sec_r001326_1 + pub_r001326_15 * 2 + 95) & 127;
    if (stage_v_30 > 17) {
        out_sink = (out_sink + stage_v_30 * 2 + 7) & 255;
        sec_accum ^= (stage_v_30 & 31);
    } else {
        out_sink = (out_sink - stage_v_30 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (stage_v_29 + pub_r001326_6 * 2 + 98) & 127;
    if (stage_v_31 > 42) {
        out_sink = (out_sink + stage_v_31 * 2 + 7) & 255;
        sec_accum ^= (stage_v_31 & 31);
    } else {
        out_sink = (out_sink - stage_v_31 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001326_18 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (sec_r001326_1 + pub_r001326_17 * 2 + 104) & 127;
    if (stage_v_33 > 41) {
        out_sink = (out_sink + stage_v_33 * 2 + 7) & 255;
        sec_accum ^= (stage_v_33 & 31);
    } else {
        out_sink = (out_sink - stage_v_33 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001326_15 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (sec_r001326_0 + pub_r001326_8 * 2 + 110) & 127;
    if (stage_v_35 > 48) {
        out_sink = (out_sink + stage_v_35 * 2 + 7) & 255;
        sec_accum ^= (stage_v_35 & 31);
    } else {
        out_sink = (out_sink - stage_v_35 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (pub_r001326_5 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_36) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_11 + pub_r001326_15 * 2 + 116) & 127;
    if (stage_v_37 > 56) {
        out_sink = (out_sink + stage_v_37 * 2 + 7) & 255;
        sec_accum ^= (stage_v_37 & 31);
    } else {
        out_sink = (out_sink - stage_v_37 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_9 + pub_r001326_4 * 2 + 119) & 127;
    if (stage_v_38 > 18) {
        out_sink = (out_sink + stage_v_38 * 2 + 7) & 255;
        sec_accum ^= (stage_v_38 & 31);
    } else {
        out_sink = (out_sink - stage_v_38 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (sec_r001326_17 + pub_r001326_16 * 2 + 122) & 127;
    if (stage_v_39 > 23) {
        out_sink = (out_sink + stage_v_39 * 2 + 7) & 255;
        sec_accum ^= (stage_v_39 & 31);
    } else {
        out_sink = (out_sink - stage_v_39 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_12 + pub_r001326_8 * 2 + 125) & 127;
    if (stage_v_40 > 60) {
        out_sink = (out_sink + stage_v_40 * 2 + 7) & 255;
        sec_accum ^= (stage_v_40 & 31);
    } else {
        out_sink = (out_sink - stage_v_40 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001326_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (pub_r001326_5 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_42) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (helper_flow_2 + pub_r001326_4 * 2 + 134) & 127;
    if (stage_v_43 > 28) {
        out_sink = (out_sink + stage_v_43 * 2 + 7) & 255;
        sec_accum ^= (stage_v_43 & 31);
    } else {
        out_sink = (out_sink - stage_v_43 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_5 + pub_r001326_5 * 2 + 137) & 127;
    if (stage_v_44 > 33) {
        out_sink = (out_sink + stage_v_44 * 2 + 7) & 255;
        sec_accum ^= (stage_v_44 & 31);
    } else {
        out_sink = (out_sink - stage_v_44 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (stage_v_9 + pub_r001326_4 * 2 + 140) & 127;
    if (stage_v_45 > 50) {
        out_sink = (out_sink + stage_v_45 * 2 + 7) & 255;
        sec_accum ^= (stage_v_45 & 31);
    } else {
        out_sink = (out_sink - stage_v_45 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001326_4 + pub_r001326_16 * 2 + 143) & 127;
    if (stage_v_46 > 30) {
        out_sink = (out_sink + stage_v_46 * 2 + 7) & 255;
        sec_accum ^= (stage_v_46 & 31);
    } else {
        out_sink = (out_sink - stage_v_46 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_23 + pub_r001326_11 * 2 + 146) & 127;
    if (stage_v_47 > 28) {
        out_sink = (out_sink + stage_v_47 * 2 + 7) & 255;
        sec_accum ^= (stage_v_47 & 31);
    } else {
        out_sink = (out_sink - stage_v_47 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (stage_v_2 + pub_r001326_14 * 2 + 149) & 127;
    if (stage_v_48 > 21) {
        out_sink = (out_sink + stage_v_48 * 2 + 7) & 255;
        sec_accum ^= (stage_v_48 & 31);
    } else {
        out_sink = (out_sink - stage_v_48 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_46 + pub_r001326_6 * 2 + 152) & 127;
    if (stage_v_49 > 24) {
        out_sink = (out_sink + stage_v_49 * 2 + 7) & 255;
        sec_accum ^= (stage_v_49 & 31);
    } else {
        out_sink = (out_sink - stage_v_49 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (helper_flow_3 + pub_r001326_14 * 2 + 155) & 127;
    if (stage_v_50 > 33) {
        out_sink = (out_sink + stage_v_50 * 2 + 7) & 255;
        sec_accum ^= (stage_v_50 & 31);
    } else {
        out_sink = (out_sink - stage_v_50 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (stage_v_27 + pub_r001326_1 * 2 + 158) & 127;
    if (stage_v_51 > 50) {
        out_sink = (out_sink + stage_v_51 * 2 + 7) & 255;
        sec_accum ^= (stage_v_51 & 31);
    } else {
        out_sink = (out_sink - stage_v_51 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001326_13 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001326_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_35 + pub_r001326_2 * 2 + 167) & 127;
    if (stage_v_54 > 15) {
        out_sink = (out_sink + stage_v_54 * 2 + 7) & 255;
        sec_accum ^= (stage_v_54 & 31);
    } else {
        out_sink = (out_sink - stage_v_54 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001326_14 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (pub_r001326_5 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_56) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001326_4 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (sec_r001326_3 + pub_r001326_8 * 2 + 179) & 127;
    if (stage_v_58 > 30) {
        out_sink = (out_sink + stage_v_58 * 2 + 7) & 255;
        sec_accum ^= (stage_v_58 & 31);
    } else {
        out_sink = (out_sink - stage_v_58 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001326_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_30 + pub_r001326_18 * 2 + 185) & 127;
    if (stage_v_60 > 19) {
        out_sink = (out_sink + stage_v_60 * 2 + 7) & 255;
        sec_accum ^= (stage_v_60 & 31);
    } else {
        out_sink = (out_sink - stage_v_60 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (stage_v_39 + pub_r001326_8 * 2 + 188) & 127;
    if (stage_v_61 > 54) {
        out_sink = (out_sink + stage_v_61 * 2 + 7) & 255;
        sec_accum ^= (stage_v_61 & 31);
    } else {
        out_sink = (out_sink - stage_v_61 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001326_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (sec_r001326_7 + pub_r001326_8 * 2 + 194) & 127;
    if (stage_v_63 > 36) {
        out_sink = (out_sink + stage_v_63 * 2 + 7) & 255;
        sec_accum ^= (stage_v_63 & 31);
    } else {
        out_sink = (out_sink - stage_v_63 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001326_11 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_51 + pub_r001326_6 * 2 + 200) & 127;
    if (stage_v_65 > 41) {
        out_sink = (out_sink + stage_v_65 * 2 + 7) & 255;
        sec_accum ^= (stage_v_65 & 31);
    } else {
        out_sink = (out_sink - stage_v_65 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (helper_flow_7 + pub_r001326_5 * 2 + 203) & 127;
    if (stage_v_66 > 25) {
        out_sink = (out_sink + stage_v_66 * 2 + 7) & 255;
        sec_accum ^= (stage_v_66 & 31);
    } else {
        out_sink = (out_sink - stage_v_66 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001326_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_18 + pub_r001326_18 * 2 + 209) & 127;
    if (stage_v_68 > 47) {
        out_sink = (out_sink + stage_v_68 * 2 + 7) & 255;
        sec_accum ^= (stage_v_68 & 31);
    } else {
        out_sink = (out_sink - stage_v_68 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001326_2 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_31 + pub_r001326_1 * 2 + 215) & 127;
    if (stage_v_70 > 31) {
        out_sink = (out_sink + stage_v_70 * 2 + 7) & 255;
        sec_accum ^= (stage_v_70 & 31);
    } else {
        out_sink = (out_sink - stage_v_70 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_0 + pub_r001326_12 * 2 + 218) & 127;
    if (stage_v_71 > 19) {
        out_sink = (out_sink + stage_v_71 * 2 + 7) & 255;
        sec_accum ^= (stage_v_71 & 31);
    } else {
        out_sink = (out_sink - stage_v_71 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (stage_v_4 + pub_r001326_13 * 2 + 221) & 127;
    if (stage_v_72 > 32) {
        out_sink = (out_sink + stage_v_72 * 2 + 7) & 255;
        sec_accum ^= (stage_v_72 & 31);
    } else {
        out_sink = (out_sink - stage_v_72 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (pub_r001326_8 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_73) & 127;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (helper_flow_7 + pub_r001326_7 * 2 + 227) & 127;
    if (stage_v_74 > 59) {
        out_sink = (out_sink + stage_v_74 * 2 + 7) & 255;
        sec_accum ^= (stage_v_74 & 31);
    } else {
        out_sink = (out_sink - stage_v_74 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001326_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001326_1 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001326_12 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (pub_r001326_7 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_78) & 127;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (helper_flow_9 + pub_r001326_10 * 2 + 242) & 127;
    if (stage_v_79 > 58) {
        out_sink = (out_sink + stage_v_79 * 2 + 7) & 255;
        sec_accum ^= (stage_v_79 & 31);
    } else {
        out_sink = (out_sink - stage_v_79 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (helper_flow_6 + pub_r001326_4 * 2 + 245) & 127;
    if (stage_v_80 > 25) {
        out_sink = (out_sink + stage_v_80 * 2 + 7) & 255;
        sec_accum ^= (stage_v_80 & 31);
    } else {
        out_sink = (out_sink - stage_v_80 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (sec_r001326_16 + pub_r001326_18 * 2 + 248) & 127;
    if (stage_v_81 > 39) {
        out_sink = (out_sink + stage_v_81 * 2 + 7) & 255;
        sec_accum ^= (stage_v_81 & 31);
    } else {
        out_sink = (out_sink - stage_v_81 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (sec_r001326_2 + pub_r001326_16 * 2 + 251) & 127;
    if (stage_v_82 > 50) {
        out_sink = (out_sink + stage_v_82 * 2 + 7) & 255;
        sec_accum ^= (stage_v_82 & 31);
    } else {
        out_sink = (out_sink - stage_v_82 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_18 + pub_r001326_3 * 2 + 254) & 127;
    if (stage_v_83 > 54) {
        out_sink = (out_sink + stage_v_83 * 2 + 7) & 255;
        sec_accum ^= (stage_v_83 & 31);
    } else {
        out_sink = (out_sink - stage_v_83 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (stage_v_38 + pub_r001326_4 * 2 + 257) & 127;
    if (stage_v_84 > 54) {
        out_sink = (out_sink + stage_v_84 * 2 + 7) & 255;
        sec_accum ^= (stage_v_84 & 31);
    } else {
        out_sink = (out_sink - stage_v_84 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (stage_v_3 + pub_r001326_6 * 2 + 260) & 127;
    if (stage_v_85 > 56) {
        out_sink = (out_sink + stage_v_85 * 2 + 7) & 255;
        sec_accum ^= (stage_v_85 & 31);
    } else {
        out_sink = (out_sink - stage_v_85 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_3 + pub_r001326_13 * 2 + 263) & 127;
    if (stage_v_86 > 32) {
        out_sink = (out_sink + stage_v_86 * 2 + 7) & 255;
        sec_accum ^= (stage_v_86 & 31);
    } else {
        out_sink = (out_sink - stage_v_86 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (stage_v_40 + pub_r001326_16 * 2 + 266) & 127;
    if (stage_v_87 > 44) {
        out_sink = (out_sink + stage_v_87 * 2 + 7) & 255;
        sec_accum ^= (stage_v_87 & 31);
    } else {
        out_sink = (out_sink - stage_v_87 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (helper_flow_4 + pub_r001326_2 * 2 + 269) & 127;
    if (stage_v_88 > 53) {
        out_sink = (out_sink + stage_v_88 * 2 + 7) & 255;
        sec_accum ^= (stage_v_88 & 31);
    } else {
        out_sink = (out_sink - stage_v_88 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_0 + pub_r001326_1 * 2 + 272) & 127;
    if (stage_v_89 > 48) {
        out_sink = (out_sink + stage_v_89 * 2 + 7) & 255;
        sec_accum ^= (stage_v_89 & 31);
    } else {
        out_sink = (out_sink - stage_v_89 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (helper_flow_8 + pub_r001326_4 * 2 + 275) & 127;
    if (stage_v_90 > 39) {
        out_sink = (out_sink + stage_v_90 * 2 + 7) & 255;
        sec_accum ^= (stage_v_90 & 31);
    } else {
        out_sink = (out_sink - stage_v_90 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (stage_v_24 + pub_r001326_13 * 2 + 278) & 127;
    if (stage_v_91 > 29) {
        out_sink = (out_sink + stage_v_91 * 2 + 7) & 255;
        sec_accum ^= (stage_v_91 & 31);
    } else {
        out_sink = (out_sink - stage_v_91 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_6 + pub_r001326_10 * 2 + 281) & 127;
    if (stage_v_92 > 59) {
        out_sink = (out_sink + stage_v_92 * 2 + 7) & 255;
        sec_accum ^= (stage_v_92 & 31);
    } else {
        out_sink = (out_sink - stage_v_92 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_74 + pub_r001326_12 * 2 + 284) & 127;
    if (stage_v_93 > 43) {
        out_sink = (out_sink + stage_v_93 * 2 + 7) & 255;
        sec_accum ^= (stage_v_93 & 31);
    } else {
        out_sink = (out_sink - stage_v_93 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (pub_r001326_8 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_94) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_8 + pub_r001326_18 * 2 + 290) & 127;
    if (stage_v_95 > 52) {
        out_sink = (out_sink + stage_v_95 * 2 + 7) & 255;
        sec_accum ^= (stage_v_95 & 31);
    } else {
        out_sink = (out_sink - stage_v_95 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_9 + pub_r001326_2 * 2 + 293) & 127;
    if (stage_v_96 > 37) {
        out_sink = (out_sink + stage_v_96 * 2 + 7) & 255;
        sec_accum ^= (stage_v_96 & 31);
    } else {
        out_sink = (out_sink - stage_v_96 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001326_17 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (stage_v_90 + pub_r001326_13 * 2 + 299) & 127;
    if (stage_v_98 > 50) {
        out_sink = (out_sink + stage_v_98 * 2 + 7) & 255;
        sec_accum ^= (stage_v_98 & 31);
    } else {
        out_sink = (out_sink - stage_v_98 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001326_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_88 + pub_r001326_14 * 2 + 305) & 127;
    if (stage_v_100 > 46) {
        out_sink = (out_sink + stage_v_100 * 2 + 7) & 255;
        sec_accum ^= (stage_v_100 & 31);
    } else {
        out_sink = (out_sink - stage_v_100 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001326_15 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (stage_v_58 + pub_r001326_4 * 2 + 311) & 127;
    if (stage_v_102 > 31) {
        out_sink = (out_sink + stage_v_102 * 2 + 7) & 255;
        sec_accum ^= (stage_v_102 & 31);
    } else {
        out_sink = (out_sink - stage_v_102 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (sec_r001326_15 + pub_r001326_0 * 2 + 314) & 127;
    if (stage_v_103 > 44) {
        out_sink = (out_sink + stage_v_103 * 2 + 7) & 255;
        sec_accum ^= (stage_v_103 & 31);
    } else {
        out_sink = (out_sink - stage_v_103 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_58 + pub_r001326_18 * 2 + 317) & 127;
    if (stage_v_104 > 33) {
        out_sink = (out_sink + stage_v_104 * 2 + 7) & 255;
        sec_accum ^= (stage_v_104 & 31);
    } else {
        out_sink = (out_sink - stage_v_104 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (sec_r001326_8 + pub_r001326_10 * 2 + 320) & 127;
    if (stage_v_105 > 42) {
        out_sink = (out_sink + stage_v_105 * 2 + 7) & 255;
        sec_accum ^= (stage_v_105 & 31);
    } else {
        out_sink = (out_sink - stage_v_105 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_4 + pub_r001326_18 * 2 + 323) & 127;
    if (stage_v_106 > 29) {
        out_sink = (out_sink + stage_v_106 * 2 + 7) & 255;
        sec_accum ^= (stage_v_106 & 31);
    } else {
        out_sink = (out_sink - stage_v_106 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (helper_flow_1 + pub_r001326_14 * 2 + 326) & 127;
    if (stage_v_107 > 49) {
        out_sink = (out_sink + stage_v_107 * 2 + 7) & 255;
        sec_accum ^= (stage_v_107 & 31);
    } else {
        out_sink = (out_sink - stage_v_107 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (stage_v_33 + pub_r001326_9 * 2 + 329) & 127;
    if (stage_v_108 > 39) {
        out_sink = (out_sink + stage_v_108 * 2 + 7) & 255;
        sec_accum ^= (stage_v_108 & 31);
    } else {
        out_sink = (out_sink - stage_v_108 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_4 + pub_r001326_10 * 2 + 332) & 127;
    if (stage_v_109 > 26) {
        out_sink = (out_sink + stage_v_109 * 2 + 7) & 255;
        sec_accum ^= (stage_v_109 & 31);
    } else {
        out_sink = (out_sink - stage_v_109 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001326_13 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (stage_v_79 + pub_r001326_2 * 2 + 338) & 127;
    if (stage_v_111 > 60) {
        out_sink = (out_sink + stage_v_111 * 2 + 7) & 255;
        sec_accum ^= (stage_v_111 & 31);
    } else {
        out_sink = (out_sink - stage_v_111 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001326_10 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001326_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_103 + pub_r001326_1 * 2 + 347) & 127;
    if (stage_v_114 > 51) {
        out_sink = (out_sink + stage_v_114 * 2 + 7) & 255;
        sec_accum ^= (stage_v_114 & 31);
    } else {
        out_sink = (out_sink - stage_v_114 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_14 + pub_r001326_4 * 2 + 350) & 127;
    if (stage_v_115 > 30) {
        out_sink = (out_sink + stage_v_115 * 2 + 7) & 255;
        sec_accum ^= (stage_v_115 & 31);
    } else {
        out_sink = (out_sink - stage_v_115 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001326_15 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001326_11 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_103 + pub_r001326_3 * 2 + 359) & 127;
    if (stage_v_118 > 17) {
        out_sink = (out_sink + stage_v_118 * 2 + 7) & 255;
        sec_accum ^= (stage_v_118 & 31);
    } else {
        out_sink = (out_sink - stage_v_118 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001326_14 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (stage_v_46 + pub_r001326_6 * 2 + 365) & 127;
    if (stage_v_120 > 18) {
        out_sink = (out_sink + stage_v_120 * 2 + 7) & 255;
        sec_accum ^= (stage_v_120 & 31);
    } else {
        out_sink = (out_sink - stage_v_120 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001326_4 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001326_9 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001326_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001326_13 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_18 + pub_r001326_7 * 2 + 380) & 127;
    if (stage_v_125 > 37) {
        out_sink = (out_sink + stage_v_125 * 2 + 7) & 255;
        sec_accum ^= (stage_v_125 & 31);
    } else {
        out_sink = (out_sink - stage_v_125 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (pub_r001326_16 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_126) & 127;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (stage_v_107 + pub_r001326_9 * 2 + 386) & 127;
    if (stage_v_127 > 48) {
        out_sink = (out_sink + stage_v_127 * 2 + 7) & 255;
        sec_accum ^= (stage_v_127 & 31);
    } else {
        out_sink = (out_sink - stage_v_127 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_127 + pub_r001326_8 * 2 + 389) & 127;
    if (stage_v_128 > 44) {
        out_sink = (out_sink + stage_v_128 * 2 + 7) & 255;
        sec_accum ^= (stage_v_128 & 31);
    } else {
        out_sink = (out_sink - stage_v_128 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001326_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_54 + pub_r001326_1 * 2 + 395) & 127;
    if (stage_v_130 > 45) {
        out_sink = (out_sink + stage_v_130 * 2 + 7) & 255;
        sec_accum ^= (stage_v_130 & 31);
    } else {
        out_sink = (out_sink - stage_v_130 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (pub_r001326_9 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_131) & 127;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_6 + pub_r001326_10 * 2 + 401) & 127;
    if (stage_v_132 > 59) {
        out_sink = (out_sink + stage_v_132 * 2 + 7) & 255;
        sec_accum ^= (stage_v_132 & 31);
    } else {
        out_sink = (out_sink - stage_v_132 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001326_13 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001326_0 + pub_r001326_12 * 2 + 407) & 127;
    if (stage_v_134 > 15) {
        out_sink = (out_sink + stage_v_134 * 2 + 7) & 255;
        sec_accum ^= (stage_v_134 & 31);
    } else {
        out_sink = (out_sink - stage_v_134 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_60 + pub_r001326_14 * 2 + 410) & 127;
    if (stage_v_135 > 28) {
        out_sink = (out_sink + stage_v_135 * 2 + 7) & 255;
        sec_accum ^= (stage_v_135 & 31);
    } else {
        out_sink = (out_sink - stage_v_135 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_4 + pub_r001326_2 * 2 + 413) & 127;
    if (stage_v_136 > 44) {
        out_sink = (out_sink + stage_v_136 * 2 + 7) & 255;
        sec_accum ^= (stage_v_136 & 31);
    } else {
        out_sink = (out_sink - stage_v_136 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001326_12 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001326_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (stage_v_38 + pub_r001326_1 * 2 + 422) & 127;
    if (stage_v_139 > 31) {
        out_sink = (out_sink + stage_v_139 * 2 + 7) & 255;
        sec_accum ^= (stage_v_139 & 31);
    } else {
        out_sink = (out_sink - stage_v_139 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (pub_r001326_3 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_140) & 127;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (stage_v_63 + pub_r001326_8 * 2 + 428) & 127;
    if (stage_v_141 > 24) {
        out_sink = (out_sink + stage_v_141 * 2 + 7) & 255;
        sec_accum ^= (stage_v_141 & 31);
    } else {
        out_sink = (out_sink - stage_v_141 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_136 + pub_r001326_7 * 2 + 431) & 127;
    if (stage_v_142 > 35) {
        out_sink = (out_sink + stage_v_142 * 2 + 7) & 255;
        sec_accum ^= (stage_v_142 & 31);
    } else {
        out_sink = (out_sink - stage_v_142 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001326_7 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001326_15 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (stage_v_30 + pub_r001326_15 * 2 + 440) & 127;
    if (stage_v_145 > 34) {
        out_sink = (out_sink + stage_v_145 * 2 + 7) & 255;
        sec_accum ^= (stage_v_145 & 31);
    } else {
        out_sink = (out_sink - stage_v_145 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (pub_r001326_10 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_146) & 127;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_90 + pub_r001326_5 * 2 + 446) & 127;
    if (stage_v_147 > 18) {
        out_sink = (out_sink + stage_v_147 * 2 + 7) & 255;
        sec_accum ^= (stage_v_147 & 31);
    } else {
        out_sink = (out_sink - stage_v_147 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (stage_v_105 + pub_r001326_13 * 2 + 449) & 127;
    if (stage_v_148 > 46) {
        out_sink = (out_sink + stage_v_148 * 2 + 7) & 255;
        sec_accum ^= (stage_v_148 & 31);
    } else {
        out_sink = (out_sink - stage_v_148 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_35 + pub_r001326_1 * 2 + 452) & 127;
    if (stage_v_149 > 24) {
        out_sink = (out_sink + stage_v_149 * 2 + 7) & 255;
        sec_accum ^= (stage_v_149 & 31);
    } else {
        out_sink = (out_sink - stage_v_149 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_37 + pub_r001326_12 * 2 + 455) & 127;
    if (stage_v_150 > 59) {
        out_sink = (out_sink + stage_v_150 * 2 + 7) & 255;
        sec_accum ^= (stage_v_150 & 31);
    } else {
        out_sink = (out_sink - stage_v_150 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001326_11 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (stage_v_90 + pub_r001326_12 * 2 + 461) & 127;
    if (stage_v_152 > 47) {
        out_sink = (out_sink + stage_v_152 * 2 + 7) & 255;
        sec_accum ^= (stage_v_152 & 31);
    } else {
        out_sink = (out_sink - stage_v_152 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001326_16 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (pub_r001326_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_154) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (sec_r001326_10 + pub_r001326_14 * 2 + 470) & 127;
    if (stage_v_155 > 30) {
        out_sink = (out_sink + stage_v_155 * 2 + 7) & 255;
        sec_accum ^= (stage_v_155 & 31);
    } else {
        out_sink = (out_sink - stage_v_155 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_149 + pub_r001326_6 * 2 + 473) & 127;
    if (stage_v_156 > 51) {
        out_sink = (out_sink + stage_v_156 * 2 + 7) & 255;
        sec_accum ^= (stage_v_156 & 31);
    } else {
        out_sink = (out_sink - stage_v_156 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_107 + pub_r001326_16 * 2 + 476) & 127;
    if (stage_v_157 > 19) {
        out_sink = (out_sink + stage_v_157 * 2 + 7) & 255;
        sec_accum ^= (stage_v_157 & 31);
    } else {
        out_sink = (out_sink - stage_v_157 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_0 + pub_r001326_9 * 2 + 479) & 127;
    if (stage_v_158 > 60) {
        out_sink = (out_sink + stage_v_158 * 2 + 7) & 255;
        sec_accum ^= (stage_v_158 & 31);
    } else {
        out_sink = (out_sink - stage_v_158 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_93 + pub_r001326_16 * 2 + 482) & 127;
    if (stage_v_159 > 55) {
        out_sink = (out_sink + stage_v_159 * 2 + 7) & 255;
        sec_accum ^= (stage_v_159 & 31);
    } else {
        out_sink = (out_sink - stage_v_159 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001326_16 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (pub_r001326_0 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_161) & 127;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001326_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (stage_v_83 + pub_r001326_9 * 2 + 494) & 127;
    if (stage_v_163 > 38) {
        out_sink = (out_sink + stage_v_163 * 2 + 7) & 255;
        sec_accum ^= (stage_v_163 & 31);
    } else {
        out_sink = (out_sink - stage_v_163 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (pub_r001326_13 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_164) & 127;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001326_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001326_9 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_14 + pub_r001326_13 * 2 + 506) & 127;
    if (stage_v_167 > 18) {
        out_sink = (out_sink + stage_v_167 * 2 + 7) & 255;
        sec_accum ^= (stage_v_167 & 31);
    } else {
        out_sink = (out_sink - stage_v_167 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001326_13 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_45 + pub_r001326_16 * 2 + 512) & 127;
    if (stage_v_169 > 20) {
        out_sink = (out_sink + stage_v_169 * 2 + 7) & 255;
        sec_accum ^= (stage_v_169 & 31);
    } else {
        out_sink = (out_sink - stage_v_169 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_103 + pub_r001326_16 * 2 + 515) & 127;
    if (stage_v_170 > 21) {
        out_sink = (out_sink + stage_v_170 * 2 + 7) & 255;
        sec_accum ^= (stage_v_170 & 31);
    } else {
        out_sink = (out_sink - stage_v_170 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_128 + pub_r001326_16 * 2 + 518) & 127;
    if (stage_v_171 > 18) {
        out_sink = (out_sink + stage_v_171 * 2 + 7) & 255;
        sec_accum ^= (stage_v_171 & 31);
    } else {
        out_sink = (out_sink - stage_v_171 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (pub_r001326_1 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_172) & 127;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001326_6 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001326_8 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (pub_r001326_10 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_175) & 127;

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001326_12 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001326_14 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_156 + pub_r001326_15 * 2 + 539) & 127;
    if (stage_v_178 > 23) {
        out_sink = (out_sink + stage_v_178 * 2 + 7) & 255;
        sec_accum ^= (stage_v_178 & 31);
    } else {
        out_sink = (out_sink - stage_v_178 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (helper_flow_7 + pub_r001326_13 * 2 + 542) & 127;
    if (stage_v_179 > 44) {
        out_sink = (out_sink + stage_v_179 * 2 + 7) & 255;
        sec_accum ^= (stage_v_179 & 31);
    } else {
        out_sink = (out_sink - stage_v_179 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_125 + pub_r001326_18 * 2 + 545) & 127;
    if (stage_v_180 > 36) {
        out_sink = (out_sink + stage_v_180 * 2 + 7) & 255;
        sec_accum ^= (stage_v_180 & 31);
    } else {
        out_sink = (out_sink - stage_v_180 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_170 + pub_r001326_7 * 2 + 548) & 127;
    if (stage_v_181 > 44) {
        out_sink = (out_sink + stage_v_181 * 2 + 7) & 255;
        sec_accum ^= (stage_v_181 & 31);
    } else {
        out_sink = (out_sink - stage_v_181 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (stage_v_156 + pub_r001326_3 * 2 + 551) & 127;
    if (stage_v_182 > 27) {
        out_sink = (out_sink + stage_v_182 * 2 + 7) & 255;
        sec_accum ^= (stage_v_182 & 31);
    } else {
        out_sink = (out_sink - stage_v_182 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_98 + pub_r001326_7 * 2 + 554) & 127;
    if (stage_v_183 > 58) {
        out_sink = (out_sink + stage_v_183 * 2 + 7) & 255;
        sec_accum ^= (stage_v_183 & 31);
    } else {
        out_sink = (out_sink - stage_v_183 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (pub_r001326_4 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_184) & 127;

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (sec_r001326_17 + pub_r001326_8 * 2 + 560) & 127;
    if (stage_v_185 > 59) {
        out_sink = (out_sink + stage_v_185 * 2 + 7) & 255;
        sec_accum ^= (stage_v_185 & 31);
    } else {
        out_sink = (out_sink - stage_v_185 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_128 + pub_r001326_1 * 2 + 563) & 127;
    if (stage_v_186 > 56) {
        out_sink = (out_sink + stage_v_186 * 2 + 7) & 255;
        sec_accum ^= (stage_v_186 & 31);
    } else {
        out_sink = (out_sink - stage_v_186 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (stage_v_50 + pub_r001326_0 * 2 + 566) & 127;
    if (stage_v_187 > 56) {
        out_sink = (out_sink + stage_v_187 * 2 + 7) & 255;
        sec_accum ^= (stage_v_187 & 31);
    } else {
        out_sink = (out_sink - stage_v_187 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001326_0 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001326_10 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (pub_r001326_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_190) & 127;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (pub_r001326_6 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_191) & 127;

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (stage_v_142 + pub_r001326_16 * 2 + 581) & 127;
    if (stage_v_192 > 30) {
        out_sink = (out_sink + stage_v_192 * 2 + 7) & 255;
        sec_accum ^= (stage_v_192 & 31);
    } else {
        out_sink = (out_sink - stage_v_192 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (stage_v_14 + pub_r001326_16 * 2 + 584) & 127;
    if (stage_v_193 > 47) {
        out_sink = (out_sink + stage_v_193 * 2 + 7) & 255;
        sec_accum ^= (stage_v_193 & 31);
    } else {
        out_sink = (out_sink - stage_v_193 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001326_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (pub_r001326_18 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_195) & 127;

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001326_15 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_93 + pub_r001326_14 * 2 + 596) & 127;
    if (stage_v_197 > 17) {
        out_sink = (out_sink + stage_v_197 * 2 + 7) & 255;
        sec_accum ^= (stage_v_197 & 31);
    } else {
        out_sink = (out_sink - stage_v_197 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001326_4 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (sec_r001326_6 + pub_r001326_14 * 2 + 602) & 127;
    if (stage_v_199 > 53) {
        out_sink = (out_sink + stage_v_199 * 2 + 7) & 255;
        sec_accum ^= (stage_v_199 & 31);
    } else {
        out_sink = (out_sink - stage_v_199 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (pub_r001326_16 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_200) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_199 + pub_r001326_11 * 2 + 608) & 127;
    if (stage_v_201 > 50) {
        out_sink = (out_sink + stage_v_201 * 2 + 7) & 255;
        sec_accum ^= (stage_v_201 & 31);
    } else {
        out_sink = (out_sink - stage_v_201 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (pub_r001326_2 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_202) & 127;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001326_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_169 + pub_r001326_2 * 2 + 617) & 127;
    if (stage_v_204 > 50) {
        out_sink = (out_sink + stage_v_204 * 2 + 7) & 255;
        sec_accum ^= (stage_v_204 & 31);
    } else {
        out_sink = (out_sink - stage_v_204 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (pub_r001326_8 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_205) & 127;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001326_18 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_183 + pub_r001326_17 * 2 + 626) & 127;
    if (stage_v_207 > 48) {
        out_sink = (out_sink + stage_v_207 * 2 + 7) & 255;
        sec_accum ^= (stage_v_207 & 31);
    } else {
        out_sink = (out_sink - stage_v_207 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (pub_r001326_12 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_208) & 127;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_102 + pub_r001326_9 * 2 + 632) & 127;
    if (stage_v_209 > 40) {
        out_sink = (out_sink + stage_v_209 * 2 + 7) & 255;
        sec_accum ^= (stage_v_209 & 31);
    } else {
        out_sink = (out_sink - stage_v_209 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (stage_v_25 + pub_r001326_5 * 2 + 635) & 127;
    if (stage_v_210 > 17) {
        out_sink = (out_sink + stage_v_210 * 2 + 7) & 255;
        sec_accum ^= (stage_v_210 & 31);
    } else {
        out_sink = (out_sink - stage_v_210 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (stage_v_109 + pub_r001326_11 * 2 + 638) & 127;
    if (stage_v_211 > 19) {
        out_sink = (out_sink + stage_v_211 * 2 + 7) & 255;
        sec_accum ^= (stage_v_211 & 31);
    } else {
        out_sink = (out_sink - stage_v_211 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_35 + pub_r001326_11 * 2 + 641) & 127;
    if (stage_v_212 > 34) {
        out_sink = (out_sink + stage_v_212 * 2 + 7) & 255;
        sec_accum ^= (stage_v_212 & 31);
    } else {
        out_sink = (out_sink - stage_v_212 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_18 + pub_r001326_0 * 2 + 644) & 127;
    if (stage_v_213 > 46) {
        out_sink = (out_sink + stage_v_213 * 2 + 7) & 255;
        sec_accum ^= (stage_v_213 & 31);
    } else {
        out_sink = (out_sink - stage_v_213 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (sec_r001326_9 + pub_r001326_9 * 2 + 647) & 127;
    if (stage_v_214 > 60) {
        out_sink = (out_sink + stage_v_214 * 2 + 7) & 255;
        sec_accum ^= (stage_v_214 & 31);
    } else {
        out_sink = (out_sink - stage_v_214 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_98 + pub_r001326_4 * 2 + 650) & 127;
    if (stage_v_215 > 28) {
        out_sink = (out_sink + stage_v_215 * 2 + 7) & 255;
        sec_accum ^= (stage_v_215 & 31);
    } else {
        out_sink = (out_sink - stage_v_215 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (stage_v_24 + pub_r001326_17 * 2 + 653) & 127;
    if (stage_v_216 > 26) {
        out_sink = (out_sink + stage_v_216 * 2 + 7) & 255;
        sec_accum ^= (stage_v_216 & 31);
    } else {
        out_sink = (out_sink - stage_v_216 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (sec_r001326_18 + pub_r001326_9 * 2 + 656) & 127;
    if (stage_v_217 > 32) {
        out_sink = (out_sink + stage_v_217 * 2 + 7) & 255;
        sec_accum ^= (stage_v_217 & 31);
    } else {
        out_sink = (out_sink - stage_v_217 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = (stage_v_39 + pub_r001326_9 * 2 + 659) & 127;
    if (stage_v_218 > 22) {
        out_sink = (out_sink + stage_v_218 * 2 + 7) & 255;
        sec_accum ^= (stage_v_218 & 31);
    } else {
        out_sink = (out_sink - stage_v_218 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = (pub_r001326_9 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_219) & 127;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = (stage_v_157 + pub_r001326_6 * 2 + 665) & 127;
    if (stage_v_220 > 45) {
        out_sink = (out_sink + stage_v_220 * 2 + 7) & 255;
        sec_accum ^= (stage_v_220 & 31);
    } else {
        out_sink = (out_sink - stage_v_220 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = (stage_v_54 + pub_r001326_4 * 2 + 668) & 127;
    if (stage_v_221 > 37) {
        out_sink = (out_sink + stage_v_221 * 2 + 7) & 255;
        sec_accum ^= (stage_v_221 & 31);
    } else {
        out_sink = (out_sink - stage_v_221 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = (stage_v_130 + pub_r001326_17 * 2 + 671) & 127;
    if (stage_v_222 > 45) {
        out_sink = (out_sink + stage_v_222 * 2 + 7) & 255;
        sec_accum ^= (stage_v_222 & 31);
    } else {
        out_sink = (out_sink - stage_v_222 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = (pub_r001326_17 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_223) & 127;

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = (stage_v_60 + pub_r001326_2 * 2 + 677) & 127;
    if (stage_v_224 > 18) {
        out_sink = (out_sink + stage_v_224 * 2 + 7) & 255;
        sec_accum ^= (stage_v_224 & 31);
    } else {
        out_sink = (out_sink - stage_v_224 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = (stage_v_132 + pub_r001326_15 * 2 + 680) & 127;
    if (stage_v_225 > 29) {
        out_sink = (out_sink + stage_v_225 * 2 + 7) & 255;
        sec_accum ^= (stage_v_225 & 31);
    } else {
        out_sink = (out_sink - stage_v_225 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = (pub_r001326_1 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_226) & 127;

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = (pub_r001326_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_227) & 127;

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = (stage_v_23 + pub_r001326_16 * 2 + 689) & 127;
    if (stage_v_228 > 26) {
        out_sink = (out_sink + stage_v_228 * 2 + 7) & 255;
        sec_accum ^= (stage_v_228 & 31);
    } else {
        out_sink = (out_sink - stage_v_228 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = (stage_v_209 + pub_r001326_7 * 2 + 692) & 127;
    if (stage_v_229 > 47) {
        out_sink = (out_sink + stage_v_229 * 2 + 7) & 255;
        sec_accum ^= (stage_v_229 & 31);
    } else {
        out_sink = (out_sink - stage_v_229 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = (stage_v_220 + pub_r001326_6 * 2 + 695) & 127;
    if (stage_v_230 > 57) {
        out_sink = (out_sink + stage_v_230 * 2 + 7) & 255;
        sec_accum ^= (stage_v_230 & 31);
    } else {
        out_sink = (out_sink - stage_v_230 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = (pub_r001326_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_231) & 127;

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = (pub_r001326_15 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_232) & 127;

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = (stage_v_31 + pub_r001326_13 * 2 + 704) & 127;
    if (stage_v_233 > 46) {
        out_sink = (out_sink + stage_v_233 * 2 + 7) & 255;
        sec_accum ^= (stage_v_233 & 31);
    } else {
        out_sink = (out_sink - stage_v_233 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = (stage_v_159 + pub_r001326_13 * 2 + 707) & 127;
    if (stage_v_234 > 20) {
        out_sink = (out_sink + stage_v_234 * 2 + 7) & 255;
        sec_accum ^= (stage_v_234 & 31);
    } else {
        out_sink = (out_sink - stage_v_234 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = (stage_v_40 + pub_r001326_16 * 2 + 710) & 127;
    if (stage_v_235 > 57) {
        out_sink = (out_sink + stage_v_235 * 2 + 7) & 255;
        sec_accum ^= (stage_v_235 & 31);
    } else {
        out_sink = (out_sink - stage_v_235 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = (stage_v_185 + pub_r001326_0 * 2 + 713) & 127;
    if (stage_v_236 > 27) {
        out_sink = (out_sink + stage_v_236 * 2 + 7) & 255;
        sec_accum ^= (stage_v_236 & 31);
    } else {
        out_sink = (out_sink - stage_v_236 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = (pub_r001326_5 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_237) & 127;

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = (pub_r001326_12 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_238) & 127;

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = (pub_r001326_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_239) & 127;

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = (stage_v_104 + pub_r001326_8 * 2 + 725) & 127;
    if (stage_v_240 > 35) {
        out_sink = (out_sink + stage_v_240 * 2 + 7) & 255;
        sec_accum ^= (stage_v_240 & 31);
    } else {
        out_sink = (out_sink - stage_v_240 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = (stage_v_24 + pub_r001326_7 * 2 + 728) & 127;
    if (stage_v_241 > 15) {
        out_sink = (out_sink + stage_v_241 * 2 + 7) & 255;
        sec_accum ^= (stage_v_241 & 31);
    } else {
        out_sink = (out_sink - stage_v_241 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = (stage_v_48 + pub_r001326_0 * 2 + 731) & 127;
    if (stage_v_242 > 30) {
        out_sink = (out_sink + stage_v_242 * 2 + 7) & 255;
        sec_accum ^= (stage_v_242 & 31);
    } else {
        out_sink = (out_sink - stage_v_242 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = (pub_r001326_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_243) & 127;

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = (pub_r001326_10 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_244) & 127;

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = (pub_r001326_4 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_245) & 127;

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = (stage_v_50 + pub_r001326_11 * 2 + 743) & 127;
    if (stage_v_246 > 54) {
        out_sink = (out_sink + stage_v_246 * 2 + 7) & 255;
        sec_accum ^= (stage_v_246 & 31);
    } else {
        out_sink = (out_sink - stage_v_246 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = (pub_r001326_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_247) & 127;

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = (pub_r001326_12 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_248) & 127;

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = (stage_v_6 + pub_r001326_17 * 2 + 752) & 127;
    if (stage_v_249 > 34) {
        out_sink = (out_sink + stage_v_249 * 2 + 7) & 255;
        sec_accum ^= (stage_v_249 & 31);
    } else {
        out_sink = (out_sink - stage_v_249 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = (pub_r001326_11 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_250) & 127;

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = (stage_v_192 + pub_r001326_4 * 2 + 758) & 127;
    if (stage_v_251 > 58) {
        out_sink = (out_sink + stage_v_251 * 2 + 7) & 255;
        sec_accum ^= (stage_v_251 & 31);
    } else {
        out_sink = (out_sink - stage_v_251 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = (pub_r001326_4 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_252) & 127;

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = (pub_r001326_15 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_253) & 127;

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = (sec_r001326_2 + pub_r001326_10 * 2 + 767) & 127;
    if (stage_v_254 > 43) {
        out_sink = (out_sink + stage_v_254 * 2 + 7) & 255;
        sec_accum ^= (stage_v_254 & 31);
    } else {
        out_sink = (out_sink - stage_v_254 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = (stage_v_152 + pub_r001326_9 * 2 + 770) & 127;
    if (stage_v_255 > 54) {
        out_sink = (out_sink + stage_v_255 * 2 + 7) & 255;
        sec_accum ^= (stage_v_255 & 31);
    } else {
        out_sink = (out_sink - stage_v_255 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = (pub_r001326_6 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_256) & 127;

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = (pub_r001326_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_257) & 127;

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = (stage_v_193 + pub_r001326_17 * 2 + 779) & 127;
    if (stage_v_258 > 25) {
        out_sink = (out_sink + stage_v_258 * 2 + 7) & 255;
        sec_accum ^= (stage_v_258 & 31);
    } else {
        out_sink = (out_sink - stage_v_258 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = (stage_v_185 + pub_r001326_16 * 2 + 782) & 127;
    if (stage_v_259 > 49) {
        out_sink = (out_sink + stage_v_259 * 2 + 7) & 255;
        sec_accum ^= (stage_v_259 & 31);
    } else {
        out_sink = (out_sink - stage_v_259 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = (pub_r001326_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_260) & 127;

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = (stage_v_38 + pub_r001326_5 * 2 + 788) & 127;
    if (stage_v_261 > 34) {
        out_sink = (out_sink + stage_v_261 * 2 + 7) & 255;
        sec_accum ^= (stage_v_261 & 31);
    } else {
        out_sink = (out_sink - stage_v_261 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = (stage_v_163 + pub_r001326_4 * 2 + 791) & 127;
    if (stage_v_262 > 19) {
        out_sink = (out_sink + stage_v_262 * 2 + 7) & 255;
        sec_accum ^= (stage_v_262 & 31);
    } else {
        out_sink = (out_sink - stage_v_262 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = (stage_v_68 + pub_r001326_18 * 2 + 794) & 127;
    if (stage_v_263 > 59) {
        out_sink = (out_sink + stage_v_263 * 2 + 7) & 255;
        sec_accum ^= (stage_v_263 & 31);
    } else {
        out_sink = (out_sink - stage_v_263 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = (stage_v_63 + pub_r001326_5 * 2 + 797) & 127;
    if (stage_v_264 > 31) {
        out_sink = (out_sink + stage_v_264 * 2 + 7) & 255;
        sec_accum ^= (stage_v_264 & 31);
    } else {
        out_sink = (out_sink - stage_v_264 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = (stage_v_87 + pub_r001326_1 * 2 + 800) & 127;
    if (stage_v_265 > 21) {
        out_sink = (out_sink + stage_v_265 * 2 + 7) & 255;
        sec_accum ^= (stage_v_265 & 31);
    } else {
        out_sink = (out_sink - stage_v_265 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = (stage_v_163 + pub_r001326_10 * 2 + 803) & 127;
    if (stage_v_266 > 49) {
        out_sink = (out_sink + stage_v_266 * 2 + 7) & 255;
        sec_accum ^= (stage_v_266 & 31);
    } else {
        out_sink = (out_sink - stage_v_266 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = (stage_v_259 + pub_r001326_18 * 2 + 806) & 127;
    if (stage_v_267 > 53) {
        out_sink = (out_sink + stage_v_267 * 2 + 7) & 255;
        sec_accum ^= (stage_v_267 & 31);
    } else {
        out_sink = (out_sink - stage_v_267 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = (pub_r001326_18 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_268) & 127;

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = (stage_v_145 + pub_r001326_9 * 2 + 812) & 127;
    if (stage_v_269 > 20) {
        out_sink = (out_sink + stage_v_269 * 2 + 7) & 255;
        sec_accum ^= (stage_v_269 & 31);
    } else {
        out_sink = (out_sink - stage_v_269 + 13) & 255;
        sec_accum += 5;
    }

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = (pub_r001326_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_270) & 127;

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = (stage_v_207 + pub_r001326_14 * 2 + 818) & 127;
    if (stage_v_271 > 27) {
        out_sink = (out_sink + stage_v_271 * 2 + 7) & 255;
        sec_accum ^= (stage_v_271 & 31);
    } else {
        out_sink = (out_sink - stage_v_271 + 13) & 255;
        sec_accum += 5;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
