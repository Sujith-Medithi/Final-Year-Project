/*
 * Benchmark Program: R000719
 * Family: secret_dependent_loops
 * Generator Seed: 471913
 * High Inputs: 22 | Low Inputs: 16
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000719_1913_0 {
    int signature;
    int severity;
    short facility;
    unsigned char code;
    unsigned char timestamp;
    int seq;
    int buffer[3];
};

struct AudioFrame_R000719_1913_1 {
    short gain;
    int peak;
    int envelope;
    unsigned char rms;
    int buffer[3];
};

union ColorPixel_R000719_1913_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;

int fn_R000719_1913_0(int p0, int p1) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int tally_54 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_54 > 37) {
        acc = (acc + tally_54 * 2 + 5) & 127;
        aux ^= (tally_54 & 15);
    } else {
        acc = (acc - tally_54 + 11) & 127;
        aux += 3;
    }
    int segment_37 = 0;
    for (int k = 0; k < 2; k++) {
        segment_37 = (segment_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_37) & 127;
    }
    int anchor_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_73) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000719_1913_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int scale_46 = (aux + st.buffer[1]) & 3;
    switch (scale_46) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_81 = local_arr[aux % 3];
    acc = (acc + tracker_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000719_1913_2(int p0, int p1, int p2) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int tally_16 = 0;
    for (int k = 0; k < 3; k++) {
        tally_16 = (tally_16 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_16) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_56 = (aux + st.buffer[1]) & 3;
    switch (checksum_56) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000719_1913_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 45) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int stride_94 = 0;
    for (int k = 0; k < 3; k++) {
        stride_94 = (stride_94 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_94) & 127;
    }
    int residue_72 = (aux + st.buffer[1]) & 3;
    switch (residue_72) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int window_22 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_22) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000719_1913_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int metric_47 = 0;
    for (int k = 0; k < 3; k++) {
        metric_47 = (metric_47 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + metric_47) & 127;
    }
    int factor_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + factor_23) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000719_1913_5(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int mask_84 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_84 > 32) {
        acc = (acc + mask_84 * 2 + 5) & 127;
        aux ^= (mask_84 & 15);
    } else {
        acc = (acc - mask_84 + 11) & 127;
        aux += 3;
    }
    int checksum_53 = 0;
    for (int k = 0; k < 2; k++) {
        checksum_53 = (checksum_53 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_53) & 127;
    }
    int scale_23 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_23) & 63;
    acc ^= aux;
    int metric_65 = (aux + st.buffer[1]) & 3;
    switch (metric_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000719_1913_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_57) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000719_1913_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int cursor_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_24) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_99 = local_arr[aux % 3];
    acc = (acc + checksum_99 * 2) & 127;
    int segment_95 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_95 > 43) {
        acc = (acc + segment_95 * 2 + 5) & 127;
        aux ^= (segment_95 & 15);
    } else {
        acc = (acc - segment_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000719_1913_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int coefficient_10 = local_arr[aux % 3];
    acc = (acc + coefficient_10 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000719_1913_9(int p0, int p1) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int quantum_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_69) & 63;
    acc ^= aux;
    int tally_33 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_33 > 19) {
        acc = (acc + tally_33 * 2 + 5) & 127;
        aux ^= (tally_33 & 15);
    } else {
        acc = (acc - tally_33 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000719_1913_10(int p0, int p1, int p2) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_50 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_50 = (cursor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_50) & 127;
    }
    int weight_45 = (aux + st.buffer[1]) & 3;
    switch (weight_45) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int phase_31 = local_arr[aux % 3];
    acc = (acc + phase_31 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000719_1913_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int pivot_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_59) & 63;
    acc ^= aux;
    int segment_94 = (aux + st.buffer[1]) & 3;
    switch (segment_94) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_88 = 0;
    for (int k = 0; k < 3; k++) {
        cursor_88 = (cursor_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_88) & 127;
    }
    int cursor_54 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_54 > 26) {
        acc = (acc + cursor_54 * 2 + 5) & 127;
        aux ^= (cursor_54 & 15);
    } else {
        acc = (acc - cursor_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000719_1913_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int stride_41 = local_arr[aux % 3];
    acc = (acc + stride_41 * 2) & 127;
    int cursor_28 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_28 > 28) {
        acc = (acc + cursor_28 * 2 + 5) & 127;
        aux ^= (cursor_28 & 15);
    } else {
        acc = (acc - cursor_28 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000719_1913_13(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int threshold_83 = local_arr[aux % 3];
    acc = (acc + threshold_83 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_14) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000719_1913_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000719_1913_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int anchor_73 = 0;
    for (int k = 0; k < 3; k++) {
        anchor_73 = (anchor_73 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_73) & 127;
    }
    int tally_77 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_77 > 34) {
        acc = (acc + tally_77 * 2 + 5) & 127;
        aux ^= (tally_77 & 15);
    } else {
        acc = (acc - tally_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int scale_22 = local_arr[aux % 3];
    acc = (acc + scale_22 * 2) & 127;
    int threshold_63 = (aux + st.buffer[1]) & 3;
    switch (threshold_63) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000719_1913_15(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000719_1913_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int vector_54 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_54 > 41) {
        acc = (acc + vector_54 * 2 + 5) & 127;
        aux ^= (vector_54 & 15);
    } else {
        acc = (acc - vector_54 + 11) & 127;
        aux += 3;
    }
    int quantum_20 = 0;
    for (int k = 0; k < 2; k++) {
        quantum_20 = (quantum_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quantum_20) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000719_0;
    int sec_r000719_1;
    int sec_r000719_2;
    int sec_r000719_3;
    int sec_r000719_4;
    int sec_r000719_5;
    int sec_r000719_6;
    int sec_r000719_7;
    int sec_r000719_8;
    int sec_r000719_9;
    int sec_r000719_10;
    int sec_r000719_11;
    int sec_r000719_12;
    int sec_r000719_13;
    int sec_r000719_14;
    int sec_r000719_15;
    int sec_r000719_16;
    int sec_r000719_17;
    int sec_r000719_18;
    int sec_r000719_19;
    int sec_r000719_20;
    int sec_r000719_21;
    int pub_r000719_0;
    int pub_r000719_1;
    int pub_r000719_2;
    int pub_r000719_3;
    int pub_r000719_4;
    int pub_r000719_5;
    int pub_r000719_6;
    int pub_r000719_7;
    int pub_r000719_8;
    int pub_r000719_9;
    int pub_r000719_10;
    int pub_r000719_11;
    int pub_r000719_12;
    int pub_r000719_13;
    int pub_r000719_14;
    int pub_r000719_15;
    int out_sink = 0;
    int chk_sum = 0;

    __CPROVER_assume(pub_r000719_0 >= -100 && pub_r000719_0 <= 100);
    __CPROVER_assume(pub_r000719_1 >= -100 && pub_r000719_1 <= 100);
    __CPROVER_assume(pub_r000719_2 >= -100 && pub_r000719_2 <= 100);
    __CPROVER_assume(pub_r000719_3 >= -100 && pub_r000719_3 <= 100);
    __CPROVER_assume(pub_r000719_4 >= -100 && pub_r000719_4 <= 100);
    __CPROVER_assume(pub_r000719_5 >= -100 && pub_r000719_5 <= 100);
    __CPROVER_assume(pub_r000719_6 >= -100 && pub_r000719_6 <= 100);
    __CPROVER_assume(pub_r000719_7 >= -100 && pub_r000719_7 <= 100);
    __CPROVER_assume(pub_r000719_8 >= -100 && pub_r000719_8 <= 100);
    __CPROVER_assume(pub_r000719_9 >= -100 && pub_r000719_9 <= 100);
    __CPROVER_assume(pub_r000719_10 >= -100 && pub_r000719_10 <= 100);
    __CPROVER_assume(pub_r000719_11 >= -100 && pub_r000719_11 <= 100);
    __CPROVER_assume(pub_r000719_12 >= -100 && pub_r000719_12 <= 100);
    __CPROVER_assume(pub_r000719_13 >= -100 && pub_r000719_13 <= 100);
    __CPROVER_assume(pub_r000719_14 >= -100 && pub_r000719_14 <= 100);
    __CPROVER_assume(pub_r000719_15 >= -100 && pub_r000719_15 <= 100);
    __CPROVER_assume(sec_r000719_0 >= 0 && sec_r000719_0 <= 255);
    __CPROVER_assume(sec_r000719_1 >= 0 && sec_r000719_1 <= 255);
    __CPROVER_assume(sec_r000719_2 >= 0 && sec_r000719_2 <= 255);
    __CPROVER_assume(sec_r000719_3 >= 0 && sec_r000719_3 <= 255);
    __CPROVER_assume(sec_r000719_4 >= 0 && sec_r000719_4 <= 255);
    __CPROVER_assume(sec_r000719_5 >= 0 && sec_r000719_5 <= 255);
    __CPROVER_assume(sec_r000719_6 >= 0 && sec_r000719_6 <= 255);
    __CPROVER_assume(sec_r000719_7 >= 0 && sec_r000719_7 <= 255);
    __CPROVER_assume(sec_r000719_8 >= 0 && sec_r000719_8 <= 255);
    __CPROVER_assume(sec_r000719_9 >= 0 && sec_r000719_9 <= 255);
    __CPROVER_assume(sec_r000719_10 >= 0 && sec_r000719_10 <= 255);
    __CPROVER_assume(sec_r000719_11 >= 0 && sec_r000719_11 <= 255);
    __CPROVER_assume(sec_r000719_12 >= 0 && sec_r000719_12 <= 255);
    __CPROVER_assume(sec_r000719_13 >= 0 && sec_r000719_13 <= 255);
    __CPROVER_assume(sec_r000719_14 >= 0 && sec_r000719_14 <= 255);
    __CPROVER_assume(sec_r000719_15 >= 0 && sec_r000719_15 <= 255);
    __CPROVER_assume(sec_r000719_16 >= 0 && sec_r000719_16 <= 255);
    __CPROVER_assume(sec_r000719_17 >= 0 && sec_r000719_17 <= 255);
    __CPROVER_assume(sec_r000719_18 >= 0 && sec_r000719_18 <= 255);
    __CPROVER_assume(sec_r000719_19 >= 0 && sec_r000719_19 <= 255);
    __CPROVER_assume(sec_r000719_20 >= 0 && sec_r000719_20 <= 255);
    __CPROVER_assume(sec_r000719_21 >= 0 && sec_r000719_21 <= 255);

    struct EventLog_R000719_1913_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000719_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000719_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000719_0 + 7) & 15;
    struct AudioFrame_R000719_1913_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000719_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000719_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000719_0 + 9) & 15;

    union ColorPixel_R000719_1913_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = table[0];
    table[0] = (table[1] + 1) & 63;
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (out_sink > 100) ? (chk_sum & 31) : (6 & 31);
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= (stage_v_1 << 1) & 127;

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
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = table[1];
    table[1] = (table[2] + 11) & 63;
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_6 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_7 = (stage_v_7 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_7) & 127;
    }
    out_sink = (out_sink + stage_v_7) & 255;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (out_sink > 100) ? (chk_sum & 31) : (14 & 31);
    out_sink = (out_sink + stage_v_9) & 255;
    chk_sum ^= (stage_v_9 << 1) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_11 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_13 = (out_sink > 100) ? (chk_sum & 31) : (18 & 31);
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= (stage_v_13 << 1) & 127;

    /* Execution Pipeline Stage 14 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 15) & 15;
    int stage_v_14 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= stage_v_14;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_1.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_1.buffer[1] * 2 + 64) & 63;
    if (stage_v_19 > 21) {
        out_sink = (out_sink + stage_v_19 - 5) & 255;
        if (stage_v_19 > 36) {
            chk_sum ^= (stage_v_19 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_19 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (out_sink > 100) ? (chk_sum & 31) : (26 & 31);
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= (stage_v_21 << 1) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_0.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = table[1];
    table[1] = (table[2] + 51) & 63;
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (st_var_1.buffer[0] ^ 30) & 3;
    switch (stage_v_27) {
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

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_0.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 23) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 38) {
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
    int stage_v_30 = (st_var_0.buffer[0] ^ 33) & 3;
    switch (stage_v_30) {
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

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_31 = (stage_v_31 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_31) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[0] ^ 35) & 3;
    switch (stage_v_32) {
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

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] ^ 36) & 3;
    switch (stage_v_33) {
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

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_1.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (st_var_0.buffer[0] * 2 + 115) & 63;
    if (stage_v_36 > 29) {
        out_sink = (out_sink + stage_v_36 - 5) & 255;
        if (stage_v_36 > 44) {
            chk_sum ^= (stage_v_36 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_36 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_38 = (stage_v_38 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_38) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = table[3];
    table[3] = (table[0] + 79) & 63;
    out_sink = (out_sink + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = table[1];
    table[1] = (table[2] + 83) & 63;
    out_sink = (out_sink + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_0.buffer[0] ^ 45) & 3;
    switch (stage_v_42) {
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

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_43 = (stage_v_43 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_43) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (out_sink > 100) ? (chk_sum & 31) : (49 & 31);
    out_sink = (out_sink + stage_v_44) & 255;
    chk_sum ^= (stage_v_44 << 1) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = table[2];
    table[2] = (table[3] + 93) & 63;
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_47 = (stage_v_47 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_47) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] * 2 + 151) & 63;
    if (stage_v_48 > 37) {
        out_sink = (out_sink + stage_v_48 - 5) & 255;
        if (stage_v_48 > 52) {
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
    for (int step = 0; step < 3; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = table[2];
    table[2] = (table[3] + 101) & 63;
    out_sink = (out_sink + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = table[0];
    table[0] = (table[1] + 105) & 63;
    out_sink = (out_sink + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (out_sink > 100) ? (chk_sum & 31) : (62 & 31);
    out_sink = (out_sink + stage_v_57) & 255;
    chk_sum ^= (stage_v_57 << 1) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_0.buffer[1] * 2 + 181) & 63;
    if (stage_v_58 > 38) {
        out_sink = (out_sink + stage_v_58 - 5) & 255;
        if (stage_v_58 > 53) {
            chk_sum ^= (stage_v_58 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_58 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 59 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_60 = (stage_v_60 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_60) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 22) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 37) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 65) & 15;
    int stage_v_64 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= stage_v_64;

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
    int stage_v_66 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = table[3];
    table[3] = (table[0] + 135) & 63;
    out_sink = (out_sink + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_0.buffer[2] * 2 + 211) & 63;
    if (stage_v_68 > 29) {
        out_sink = (out_sink + stage_v_68 - 5) & 255;
        if (stage_v_68 > 44) {
            chk_sum ^= (stage_v_68 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_68 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_1.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 32) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 47) {
            chk_sum ^= (stage_v_69 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_69 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_70 = (stage_v_70 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_70) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 72 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 73) & 15;
    int stage_v_72 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_72) & 255;
    chk_sum ^= stage_v_72;

    /* Execution Pipeline Stage 73 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 74) & 15;
    int stage_v_73 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_73) & 255;
    chk_sum ^= stage_v_73;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_0.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (st_var_1.buffer[0] * 2 + 232) & 63;
    if (stage_v_75 > 31) {
        out_sink = (out_sink + stage_v_75 - 5) & 255;
        if (stage_v_75 > 46) {
            chk_sum ^= (stage_v_75 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_75 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (st_var_0.buffer[1] * 2 + 235) & 63;
    if (stage_v_76 > 36) {
        out_sink = (out_sink + stage_v_76 - 5) & 255;
        if (stage_v_76 > 51) {
            chk_sum ^= (stage_v_76 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_76 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (out_sink > 100) ? (chk_sum & 31) : (82 & 31);
    out_sink = (out_sink + stage_v_77) & 255;
    chk_sum ^= (stage_v_77 << 1) & 127;

    /* Execution Pipeline Stage 78 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 79) & 15;
    int stage_v_78 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_78) & 255;
    chk_sum ^= stage_v_78;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (out_sink > 100) ? (chk_sum & 31) : (84 & 31);
    out_sink = (out_sink + stage_v_79) & 255;
    chk_sum ^= (stage_v_79 << 1) & 127;

    /* Execution Pipeline Stage 80 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 81) & 15;
    int stage_v_80 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_80) & 255;
    chk_sum ^= stage_v_80;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_1.buffer[0] * 2 + 250) & 63;
    if (stage_v_81 > 12) {
        out_sink = (out_sink + stage_v_81 - 5) & 255;
        if (stage_v_81 > 27) {
            chk_sum ^= (stage_v_81 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_81 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

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
    int stage_v_85 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (st_var_0.buffer[2] * 2 + 265) & 63;
    if (stage_v_86 > 10) {
        out_sink = (out_sink + stage_v_86 - 5) & 255;
        if (stage_v_86 > 25) {
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
    int stage_v_88 = table[0];
    table[0] = (table[1] + 177) & 63;
    out_sink = (out_sink + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = table[1];
    table[1] = (table[2] + 179) & 63;
    out_sink = (out_sink + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (out_sink > 100) ? (chk_sum & 31) : (95 & 31);
    out_sink = (out_sink + stage_v_90) & 255;
    chk_sum ^= (stage_v_90 << 1) & 127;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = table[3];
    table[3] = (table[0] + 183) & 63;
    out_sink = (out_sink + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_92 = (stage_v_92 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = table[1];
    table[1] = (table[2] + 187) & 63;
    out_sink = (out_sink + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (out_sink > 100) ? (chk_sum & 31) : (99 & 31);
    out_sink = (out_sink + stage_v_94) & 255;
    chk_sum ^= (stage_v_94 << 1) & 127;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = table[0];
    table[0] = (table[1] + 193) & 63;
    out_sink = (out_sink + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 99 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 100) & 15;
    int stage_v_99 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_99) & 255;
    chk_sum ^= stage_v_99;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (st_var_0.buffer[1] * 2 + 307) & 63;
    if (stage_v_100 > 19) {
        out_sink = (out_sink + stage_v_100 - 5) & 255;
        if (stage_v_100 > 34) {
            chk_sum ^= (stage_v_100 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_100 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 101 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 102) & 15;
    int stage_v_101 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_101) & 255;
    chk_sum ^= stage_v_101;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (st_var_0.buffer[0] ^ 105) & 3;
    switch (stage_v_102) {
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

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_103 = (stage_v_103 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = table[1];
    table[1] = (table[2] + 211) & 63;
    out_sink = (out_sink + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (out_sink > 100) ? (chk_sum & 31) : (111 & 31);
    out_sink = (out_sink + stage_v_106) & 255;
    chk_sum ^= (stage_v_106 << 1) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = table[3];
    table[3] = (table[0] + 215) & 63;
    out_sink = (out_sink + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (st_var_1.buffer[0] ^ 112) & 3;
    switch (stage_v_109) {
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

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = table[2];
    table[2] = (table[3] + 221) & 63;
    out_sink = (out_sink + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (out_sink > 100) ? (chk_sum & 31) : (116 & 31);
    out_sink = (out_sink + stage_v_111) & 255;
    chk_sum ^= (stage_v_111 << 1) & 127;

    /* Execution Pipeline Stage 112 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 113) & 15;
    int stage_v_112 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_112) & 255;
    chk_sum ^= stage_v_112;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = table[1];
    table[1] = (table[2] + 227) & 63;
    out_sink = (out_sink + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_114 = (stage_v_114 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (out_sink > 100) ? (chk_sum & 31) : (120 & 31);
    out_sink = (out_sink + stage_v_115) & 255;
    chk_sum ^= (stage_v_115 << 1) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_116 = (stage_v_116 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (out_sink > 100) ? (chk_sum & 31) : (122 & 31);
    out_sink = (out_sink + stage_v_117) & 255;
    chk_sum ^= (stage_v_117 << 1) & 127;

    /* Execution Pipeline Stage 118 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 119) & 15;
    int stage_v_118 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_118) & 255;
    chk_sum ^= stage_v_118;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = table[3];
    table[3] = (table[0] + 239) & 63;
    out_sink = (out_sink + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 122 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 123) & 15;
    int stage_v_122 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_122) & 255;
    chk_sum ^= stage_v_122;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (st_var_1.buffer[0] * 2 + 376) & 63;
    if (stage_v_123 > 25) {
        out_sink = (out_sink + stage_v_123 - 5) & 255;
        if (stage_v_123 > 40) {
            chk_sum ^= (stage_v_123 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_123 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = table[0];
    table[0] = (table[1] + 249) & 63;
    out_sink = (out_sink + stage_v_124) & 255;

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
    int stage_v_127 = (st_var_1.buffer[0] ^ 130) & 3;
    switch (stage_v_127) {
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

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (st_var_0.buffer[2] * 2 + 391) & 63;
    if (stage_v_128 > 17) {
        out_sink = (out_sink + stage_v_128 - 5) & 255;
        if (stage_v_128 > 32) {
            chk_sum ^= (stage_v_128 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_128 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = table[1];
    table[1] = (table[2] + 259) & 63;
    out_sink = (out_sink + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (st_var_0.buffer[1] * 2 + 397) & 63;
    if (stage_v_130 > 24) {
        out_sink = (out_sink + stage_v_130 - 5) & 255;
        if (stage_v_130 > 39) {
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
    for (int step = 0; step < 3; step++) {
        stage_v_131 = (stage_v_131 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (st_var_0.buffer[0] * 2 + 403) & 63;
    if (stage_v_132 > 20) {
        out_sink = (out_sink + stage_v_132 - 5) & 255;
        if (stage_v_132 > 35) {
            chk_sum ^= (stage_v_132 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_132 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_133 = (stage_v_133 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;

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
    int stage_v_136 = (st_var_0.buffer[0] ^ 139) & 3;
    switch (stage_v_136) {
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
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 140) & 15;
    int stage_v_139 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_139) & 255;
    chk_sum ^= stage_v_139;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (st_var_0.buffer[2] * 2 + 427) & 63;
    if (stage_v_140 > 13) {
        out_sink = (out_sink + stage_v_140 - 5) & 255;
        if (stage_v_140 > 28) {
            chk_sum ^= (stage_v_140 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_140 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 141 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 142) & 15;
    int stage_v_141 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_141) & 255;
    chk_sum ^= stage_v_141;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (st_var_0.buffer[0] * 2 + 439) & 63;
    if (stage_v_144 > 21) {
        out_sink = (out_sink + stage_v_144 - 5) & 255;
        if (stage_v_144 > 36) {
            chk_sum ^= (stage_v_144 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_144 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (out_sink > 100) ? (chk_sum & 31) : (150 & 31);
    out_sink = (out_sink + stage_v_145) & 255;
    chk_sum ^= (stage_v_145 << 1) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = table[2];
    table[2] = (table[3] + 293) & 63;
    out_sink = (out_sink + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_147 = (stage_v_147 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 149) & 15;
    int stage_v_148 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_148) & 255;
    chk_sum ^= stage_v_148;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_149 = (stage_v_149 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_150 = (stage_v_150 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (out_sink > 100) ? (chk_sum & 31) : (156 & 31);
    out_sink = (out_sink + stage_v_151) & 255;
    chk_sum ^= (stage_v_151 << 1) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_152 = (stage_v_152 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (out_sink > 100) ? (chk_sum & 31) : (158 & 31);
    out_sink = (out_sink + stage_v_153) & 255;
    chk_sum ^= (stage_v_153 << 1) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (out_sink > 100) ? (chk_sum & 31) : (160 & 31);
    out_sink = (out_sink + stage_v_155) & 255;
    chk_sum ^= (stage_v_155 << 1) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_157 = (stage_v_157 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;

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
    int stage_v_160 = (st_var_0.buffer[0] ^ 163) & 3;
    switch (stage_v_160) {
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

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_161 = (stage_v_161 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_162 = (stage_v_162 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = table[0];
    table[0] = (table[1] + 329) & 63;
    out_sink = (out_sink + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_165 = (stage_v_165 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_165) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 167) & 15;
    int stage_v_166 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_166) & 255;
    chk_sum ^= stage_v_166;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (st_var_1.buffer[0] ^ 170) & 3;
    switch (stage_v_167) {
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

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (st_var_0.buffer[0] * 2 + 511) & 63;
    if (stage_v_168 > 16) {
        out_sink = (out_sink + stage_v_168 - 5) & 255;
        if (stage_v_168 > 31) {
            chk_sum ^= (stage_v_168 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_168 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (st_var_1.buffer[1] * 2 + 514) & 63;
    if (stage_v_169 > 15) {
        out_sink = (out_sink + stage_v_169 - 5) & 255;
        if (stage_v_169 > 30) {
            chk_sum ^= (stage_v_169 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_169 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 170 */
    st_var_0.buffer[2] = (st_var_0.buffer[2] + 171) & 15;
    int stage_v_170 = (st_var_0.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_170) & 255;
    chk_sum ^= stage_v_170;

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = table[3];
    table[3] = (table[0] + 343) & 63;
    out_sink = (out_sink + stage_v_171) & 255;

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_172 = (stage_v_172 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_172) & 127;
    }
    out_sink = (out_sink + stage_v_172) & 255;

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (st_var_0.buffer[0] * 2 + 529) & 63;
    if (stage_v_174 > 23) {
        out_sink = (out_sink + stage_v_174 - 5) & 255;
        if (stage_v_174 > 38) {
            chk_sum ^= (stage_v_174 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_174 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (st_var_1.buffer[0] ^ 178) & 3;
    switch (stage_v_175) {
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

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (st_var_1.buffer[0] ^ 180) & 3;
    switch (stage_v_177) {
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

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = table[0];
    table[0] = (table[1] + 361) & 63;
    out_sink = (out_sink + stage_v_180) & 255;

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (st_var_1.buffer[1] * 2 + 550) & 63;
    if (stage_v_181 > 17) {
        out_sink = (out_sink + stage_v_181 - 5) & 255;
        if (stage_v_181 > 32) {
            chk_sum ^= (stage_v_181 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_181 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_183 = (stage_v_183 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_183) & 127;
    }
    out_sink = (out_sink + stage_v_183) & 255;

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (st_var_0.buffer[0] ^ 187) & 3;
    switch (stage_v_184) {
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

    /* Execution Pipeline Stage 185 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 186) & 15;
    int stage_v_185 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_185) & 255;
    chk_sum ^= stage_v_185;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (st_var_0.buffer[0] ^ 189) & 3;
    switch (stage_v_186) {
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

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (st_var_0.buffer[2] * 2 + 571) & 63;
    if (stage_v_188 > 15) {
        out_sink = (out_sink + stage_v_188 - 5) & 255;
        if (stage_v_188 > 30) {
            chk_sum ^= (stage_v_188 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_188 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = table[2];
    table[2] = (table[3] + 381) & 63;
    out_sink = (out_sink + stage_v_190) & 255;

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (st_var_1.buffer[0] ^ 194) & 3;
    switch (stage_v_191) {
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

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_192 = (stage_v_192 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_192) & 127;
    }
    out_sink = (out_sink + stage_v_192) & 255;

    /* Execution Pipeline Stage 193 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 194) & 15;
    int stage_v_193 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_193) & 255;
    chk_sum ^= stage_v_193;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_194 = (stage_v_194 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_194) & 127;
    }
    out_sink = (out_sink + stage_v_194) & 255;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (st_var_1.buffer[0] * 2 + 592) & 63;
    if (stage_v_195 > 25) {
        out_sink = (out_sink + stage_v_195 - 5) & 255;
        if (stage_v_195 > 40) {
            chk_sum ^= (stage_v_195 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_195 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (st_var_0.buffer[0] ^ 199) & 3;
    switch (stage_v_196) {
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

    /* Execution Pipeline Stage 197 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 198) & 15;
    int stage_v_197 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_197) & 255;
    chk_sum ^= stage_v_197;

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = table[2];
    table[2] = (table[3] + 397) & 63;
    out_sink = (out_sink + stage_v_198) & 255;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_199 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_201 = (stage_v_201 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_201) & 127;
    }
    out_sink = (out_sink + stage_v_201) & 255;

    /* Execution Pipeline Stage 202 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 203) & 15;
    int stage_v_202 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_202) & 255;
    chk_sum ^= stage_v_202;

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (st_var_1.buffer[2] * 2 + 616) & 63;
    if (stage_v_203 > 29) {
        out_sink = (out_sink + stage_v_203 - 5) & 255;
        if (stage_v_203 > 44) {
            chk_sum ^= (stage_v_203 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_203 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_204 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 205 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 206) & 15;
    int stage_v_205 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_205) & 255;
    chk_sum ^= stage_v_205;

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = table[2];
    table[2] = (table[3] + 413) & 63;
    out_sink = (out_sink + stage_v_206) & 255;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (out_sink > 100) ? (chk_sum & 31) : (212 & 31);
    out_sink = (out_sink + stage_v_207) & 255;
    chk_sum ^= (stage_v_207 << 1) & 127;

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = table[0];
    table[0] = (table[1] + 417) & 63;
    out_sink = (out_sink + stage_v_208) & 255;

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (st_var_1.buffer[2] * 2 + 634) & 63;
    if (stage_v_209 > 33) {
        out_sink = (out_sink + stage_v_209 - 5) & 255;
        if (stage_v_209 > 48) {
            chk_sum ^= (stage_v_209 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_209 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (out_sink > 100) ? (chk_sum & 31) : (215 & 31);
    out_sink = (out_sink + stage_v_210) & 255;
    chk_sum ^= (stage_v_210 << 1) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (st_var_1.buffer[0] ^ 214) & 3;
    switch (stage_v_211) {
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

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (st_var_0.buffer[0] ^ 215) & 3;
    switch (stage_v_212) {
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

    /* Execution Pipeline Stage 213 */
    st_var_1.buffer[0] = (st_var_1.buffer[0] + 214) & 15;
    int stage_v_213 = (st_var_1.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_213) & 255;
    chk_sum ^= stage_v_213;

    /* Execution Pipeline Stage 214 */
    st_var_0.buffer[1] = (st_var_0.buffer[1] + 215) & 15;
    int stage_v_214 = (st_var_0.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_214) & 255;
    chk_sum ^= stage_v_214;

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_215 = (stage_v_215 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_215) & 127;
    }
    out_sink = (out_sink + stage_v_215) & 255;

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = (st_var_0.buffer[0] * 2 + 655) & 63;
    if (stage_v_216 > 16) {
        out_sink = (out_sink + stage_v_216 - 5) & 255;
        if (stage_v_216 > 31) {
            chk_sum ^= (stage_v_216 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_216 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = (st_var_1.buffer[1] * 2 + 658) & 63;
    if (stage_v_217 > 37) {
        out_sink = (out_sink + stage_v_217 - 5) & 255;
        if (stage_v_217 > 52) {
            chk_sum ^= (stage_v_217 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_217 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = 0;
    for (int step = 0; step < 3; step++) {
        stage_v_218 = (stage_v_218 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_218) & 127;
    }
    out_sink = (out_sink + stage_v_218) & 255;

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = table[3];
    table[3] = (table[0] + 439) & 63;
    out_sink = (out_sink + stage_v_219) & 255;

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_220 = (stage_v_220 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_220) & 127;
    }
    out_sink = (out_sink + stage_v_220) & 255;

    /* Security Information Flow: Family = secret_dependent_loops */
    int l_bound_0 = (sec_r000719_12 & 1) + 1;
    for (int it = 0; it < l_bound_0; it++) {
        out_sink += (it * 3 + 6);
    }

    g_out = out_sink;
    g_chk = chk_sum;
    return 0;
}
