/*
 * Benchmark Program: R001997
 * Security Family: nested_implicit_flow
 * Generator Seed: 699713
 * High Inputs: 20 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct CipherContext_R001997_9713_0 {
    short tag;
    short counter;
    int flags;
    short iv;
    unsigned char nonce;
    int buffer[3];
};

struct SensorNode_R001997_9713_1 {
    short reading;
    int threshold;
    unsigned char calib;
    int status;
    int offset;
    int buffer[3];
};

struct Transaction_R001997_9713_2 {
    unsigned char rate;
    int balance;
    int status;
    unsigned char fee;
    short account_id;
    unsigned char auth_code;
    int buffer[3];
};

struct FilterState_R001997_9713_3 {
    int gain_db;
    int prev_out;
    int prev_in;
    int buffer[3];
};

union TelemetryField_R001997_9713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001997_9713_0(int p0, int p1) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001997_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 30;
    int damping_27 = (aux + st.buffer[1]) & 3;
    switch (damping_27) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int stride_13 = 0;
    for (int k = 0; k < 2; k++) {
        stride_13 = (stride_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_13) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001997_9713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001997_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int factor_96 = (aux + st.buffer[1]) & 3;
    switch (factor_96) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_98 = local_arr[aux % 3];
    acc = (acc + phase_98 * 2) & 127;
    int tally_99 = 0;
    for (int k = 0; k < 2; k++) {
        tally_99 = (tally_99 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_99) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001997_9713_2(int p0, int p1, int p2) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001997_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_40 = (aux + st.buffer[1]) & 3;
    switch (segment_40) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_49 = 0;
    for (int k = 0; k < 2; k++) {
        tally_49 = (tally_49 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + tally_49) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001997_9713_3(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001997_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int tally_77 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_77 > 26) {
        acc = (acc + tally_77 * 2 + 5) & 127;
        aux ^= (tally_77 & 15);
    } else {
        acc = (acc - tally_77 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_29 = local_arr[aux % 3];
    acc = (acc + index_reg_29 * 2) & 127;
    int accumulator_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_60) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001997_9713_4(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001997_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int threshold_13 = (aux + st.buffer[1]) & 3;
    switch (threshold_13) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_93 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_93 > 19) {
        acc = (acc + margin_93 * 2 + 5) & 127;
        aux ^= (margin_93 & 15);
    } else {
        acc = (acc - margin_93 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001997_9713_5(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001997_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int margin_41 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_41 > 34) {
        acc = (acc + margin_41 * 2 + 5) & 127;
        aux ^= (margin_41 & 15);
    } else {
        acc = (acc - margin_41 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_69 = 0;
    for (int k = 0; k < 2; k++) {
        cursor_69 = (cursor_69 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + cursor_69) & 127;
    }
    int tracker_67 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_67) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001997_9713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001997_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int margin_60 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_60) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int damping_77 = local_arr[aux % 3];
    acc = (acc + damping_77 * 2) & 127;
    int phase_71 = (aux + st.buffer[1]) & 3;
    switch (phase_71) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001997_9713_7(int p0, int p1) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001997_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int index_reg_76 = local_arr[aux % 3];
    acc = (acc + index_reg_76 * 2) & 127;
    int threshold_81 = (aux + st.buffer[1]) & 3;
    switch (threshold_81) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001997_9713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001997_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int pivot_63 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_63 > 27) {
        acc = (acc + pivot_63 * 2 + 5) & 127;
        aux ^= (pivot_63 & 15);
    } else {
        acc = (acc - pivot_63 + 11) & 127;
        aux += 3;
    }
    int tally_26 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_26) & 63;
    acc ^= aux;
    int stride_72 = (aux + st.buffer[1]) & 3;
    switch (stride_72) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_79 = local_arr[aux % 3];
    acc = (acc + delta_79 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001997_9713_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R001997_9713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int cursor_11 = local_arr[aux % 3];
    acc = (acc + cursor_11 * 2) & 127;
    int quotient_15 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_15 > 17) {
        acc = (acc + quotient_15 * 2 + 5) & 127;
        aux ^= (quotient_15 & 15);
    } else {
        acc = (acc - quotient_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001997_9713_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001997_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int parity_86 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_86 > 17) {
        acc = (acc + parity_86 * 2 + 5) & 127;
        aux ^= (parity_86 & 15);
    } else {
        acc = (acc - parity_86 + 11) & 127;
        aux += 3;
    }
    int metric_68 = (aux + st.buffer[1]) & 3;
    switch (metric_68) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_33 = 0;
    for (int k = 0; k < 3; k++) {
        sample_33 = (sample_33 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + sample_33) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001997_9713_11(int p0, int p1, int p2) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001997_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int phase_95 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_95 > 46) {
        acc = (acc + phase_95 * 2 + 5) & 127;
        aux ^= (phase_95 & 15);
    } else {
        acc = (acc - phase_95 + 11) & 127;
        aux += 3;
    }
    int scale_74 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_74) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001997_9713_12(int p0, int p1, int p2) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001997_9713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int coefficient_27 = local_arr[aux % 3];
    acc = (acc + coefficient_27 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_78 = (aux + st.buffer[1]) & 3;
    switch (checksum_78) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int checksum_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_39) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001997_9713_13(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001997_9713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int tally_37 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_37) & 63;
    acc ^= aux;
    int threshold_54 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_54 > 28) {
        acc = (acc + threshold_54 * 2 + 5) & 127;
        aux ^= (threshold_54 & 15);
    } else {
        acc = (acc - threshold_54 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001997_9713_14(int p0, int p1, int p2) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001997_9713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int weight_77 = (aux + st.buffer[1]) & 3;
    switch (weight_77) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_21 = 0;
    for (int k = 0; k < 3; k++) {
        residue_21 = (residue_21 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_21) & 127;
    }
    int tally_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_21) & 63;
    acc ^= aux;
    int sample_60 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_60 > 47) {
        acc = (acc + sample_60 * 2 + 5) & 127;
        aux ^= (sample_60 & 15);
    } else {
        acc = (acc - sample_60 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001997_0;
    int sec_r001997_1;
    int sec_r001997_2;
    int sec_r001997_3;
    int sec_r001997_4;
    int sec_r001997_5;
    int sec_r001997_6;
    int sec_r001997_7;
    int sec_r001997_8;
    int sec_r001997_9;
    int sec_r001997_10;
    int sec_r001997_11;
    int sec_r001997_12;
    int sec_r001997_13;
    int sec_r001997_14;
    int sec_r001997_15;
    int sec_r001997_16;
    int sec_r001997_17;
    int sec_r001997_18;
    int sec_r001997_19;
    int pub_r001997_0;
    int pub_r001997_1;
    int pub_r001997_2;
    int pub_r001997_3;
    int pub_r001997_4;
    int pub_r001997_5;
    int pub_r001997_6;
    int pub_r001997_7;
    int pub_r001997_8;
    int pub_r001997_9;
    int pub_r001997_10;
    int pub_r001997_11;
    int pub_r001997_12;
    int pub_r001997_13;
    int pub_r001997_14;
    int pub_r001997_15;
    int pub_r001997_16;
    int pub_r001997_17;
    int pub_r001997_18;
    int pub_r001997_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001997_0 >= -100 && pub_r001997_0 <= 100);
    __CPROVER_assume(pub_r001997_1 >= -100 && pub_r001997_1 <= 100);
    __CPROVER_assume(pub_r001997_2 >= -100 && pub_r001997_2 <= 100);
    __CPROVER_assume(pub_r001997_3 >= -100 && pub_r001997_3 <= 100);
    __CPROVER_assume(pub_r001997_4 >= -100 && pub_r001997_4 <= 100);
    __CPROVER_assume(pub_r001997_5 >= -100 && pub_r001997_5 <= 100);
    __CPROVER_assume(pub_r001997_6 >= -100 && pub_r001997_6 <= 100);
    __CPROVER_assume(pub_r001997_7 >= -100 && pub_r001997_7 <= 100);
    __CPROVER_assume(pub_r001997_8 >= -100 && pub_r001997_8 <= 100);
    __CPROVER_assume(pub_r001997_9 >= -100 && pub_r001997_9 <= 100);
    __CPROVER_assume(pub_r001997_10 >= -100 && pub_r001997_10 <= 100);
    __CPROVER_assume(pub_r001997_11 >= -100 && pub_r001997_11 <= 100);
    __CPROVER_assume(pub_r001997_12 >= -100 && pub_r001997_12 <= 100);
    __CPROVER_assume(pub_r001997_13 >= -100 && pub_r001997_13 <= 100);
    __CPROVER_assume(pub_r001997_14 >= -100 && pub_r001997_14 <= 100);
    __CPROVER_assume(pub_r001997_15 >= -100 && pub_r001997_15 <= 100);
    __CPROVER_assume(pub_r001997_16 >= -100 && pub_r001997_16 <= 100);
    __CPROVER_assume(pub_r001997_17 >= -100 && pub_r001997_17 <= 100);
    __CPROVER_assume(pub_r001997_18 >= -100 && pub_r001997_18 <= 100);
    __CPROVER_assume(pub_r001997_19 >= -100 && pub_r001997_19 <= 100);
    __CPROVER_assume(sec_r001997_0 >= 0 && sec_r001997_0 <= 255);
    __CPROVER_assume(sec_r001997_1 >= 0 && sec_r001997_1 <= 255);
    __CPROVER_assume(sec_r001997_2 >= 0 && sec_r001997_2 <= 255);
    __CPROVER_assume(sec_r001997_3 >= 0 && sec_r001997_3 <= 255);
    __CPROVER_assume(sec_r001997_4 >= 0 && sec_r001997_4 <= 255);
    __CPROVER_assume(sec_r001997_5 >= 0 && sec_r001997_5 <= 255);
    __CPROVER_assume(sec_r001997_6 >= 0 && sec_r001997_6 <= 255);
    __CPROVER_assume(sec_r001997_7 >= 0 && sec_r001997_7 <= 255);
    __CPROVER_assume(sec_r001997_8 >= 0 && sec_r001997_8 <= 255);
    __CPROVER_assume(sec_r001997_9 >= 0 && sec_r001997_9 <= 255);
    __CPROVER_assume(sec_r001997_10 >= 0 && sec_r001997_10 <= 255);
    __CPROVER_assume(sec_r001997_11 >= 0 && sec_r001997_11 <= 255);
    __CPROVER_assume(sec_r001997_12 >= 0 && sec_r001997_12 <= 255);
    __CPROVER_assume(sec_r001997_13 >= 0 && sec_r001997_13 <= 255);
    __CPROVER_assume(sec_r001997_14 >= 0 && sec_r001997_14 <= 255);
    __CPROVER_assume(sec_r001997_15 >= 0 && sec_r001997_15 <= 255);
    __CPROVER_assume(sec_r001997_16 >= 0 && sec_r001997_16 <= 255);
    __CPROVER_assume(sec_r001997_17 >= 0 && sec_r001997_17 <= 255);
    __CPROVER_assume(sec_r001997_18 >= 0 && sec_r001997_18 <= 255);
    __CPROVER_assume(sec_r001997_19 >= 0 && sec_r001997_19 <= 255);

    struct CipherContext_R001997_9713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001997_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001997_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001997_0 + 7) & 15;
    struct SensorNode_R001997_9713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001997_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001997_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001997_0 + 9) & 15;
    struct Transaction_R001997_9713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001997_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001997_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001997_0 + 11) & 15;
    struct FilterState_R001997_9713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001997_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001997_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001997_0 + 13) & 15;

    union TelemetryField_R001997_9713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001997_9713_0(sec_r001997_0, sec_r001997_1);
    int helper_flow_1 = fn_R001997_9713_1(sec_r001997_1, sec_r001997_2, pub_r001997_3, pub_r001997_4);
    int helper_flow_2 = fn_R001997_9713_2(sec_r001997_2, sec_r001997_3, pub_r001997_4);
    int helper_flow_3 = fn_R001997_9713_3(sec_r001997_3, pub_r001997_4);
    int helper_flow_4 = fn_R001997_9713_4(sec_r001997_4, sec_r001997_5, pub_r001997_6);
    int helper_flow_5 = fn_R001997_9713_5(sec_r001997_5, sec_r001997_6, pub_r001997_7, pub_r001997_8, pub_r001997_9);
    int helper_flow_6 = fn_R001997_9713_6(sec_r001997_6, pub_r001997_7, pub_r001997_8, pub_r001997_9);
    int helper_flow_7 = fn_R001997_9713_7(sec_r001997_7, pub_r001997_8);
    int helper_flow_8 = fn_R001997_9713_8(sec_r001997_8, sec_r001997_9, pub_r001997_10, pub_r001997_11, pub_r001997_12);
    int helper_flow_9 = fn_R001997_9713_9(sec_r001997_9, pub_r001997_10, pub_r001997_11, pub_r001997_12, pub_r001997_13);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (sec_r001997_1 ^ pub_r001997_0) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001997_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001997_1 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (sec_r001997_5 ^ pub_r001997_15) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001997_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001997_17 ^ pub_r001997_6) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001997_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (sec_r001997_0 ^ pub_r001997_0) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001997_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (sec_r001997_5 ^ pub_r001997_5) & 63;
    if ((stage_v_5 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_5 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_5 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_5 * 2) & 255;
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001997_7 ^ pub_r001997_13) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001997_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_4 ^ pub_r001997_6) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((sec_r001997_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001997_0 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (stage_v_7 ^ pub_r001997_12) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r001997_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (sec_r001997_5 ^ pub_r001997_17) & 63;
    if ((stage_v_10 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_10 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_10 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_10 * 2) & 255;
    }

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (sec_r001997_19 ^ pub_r001997_16) & 63;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r001997_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_11 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_11 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_11 * 2) & 255;
    }

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (helper_flow_1 ^ pub_r001997_14) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r001997_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (pub_r001997_14 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_13) & 127;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (stage_v_2 ^ pub_r001997_19) & 63;
    if ((stage_v_14 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_14 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_14 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_14 * 2) & 255;
    }

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001997_7 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (sec_r001997_18 ^ pub_r001997_4) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((stage_v_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (sec_r001997_10 ^ pub_r001997_6) & 63;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r001997_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_17 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_17 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_17 * 2) & 255;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (helper_flow_3 ^ pub_r001997_11) & 63;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r001997_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_18 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_18 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_18 * 2) & 255;
    }

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (helper_flow_4 ^ pub_r001997_12) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r001997_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (stage_v_19 ^ pub_r001997_13) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (sec_r001997_2 ^ pub_r001997_9) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (sec_r001997_17 ^ pub_r001997_14) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r001997_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (stage_v_10 ^ pub_r001997_3) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001997_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (sec_r001997_14 ^ pub_r001997_14) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001997_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (pub_r001997_10 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_25) & 127;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001997_14 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (helper_flow_5 ^ pub_r001997_1) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001997_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001997_14 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_18 ^ pub_r001997_8) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (stage_v_14 ^ pub_r001997_12) & 63;
    if ((stage_v_30 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_30 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_30 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_30 * 2) & 255;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (pub_r001997_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_31) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (helper_flow_2 ^ pub_r001997_2) & 63;
    if ((stage_v_32 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_32 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_32 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_32 * 2) & 255;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (stage_v_2 ^ pub_r001997_14) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001997_5 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_14 ^ pub_r001997_5) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (helper_flow_7 ^ pub_r001997_0) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r001997_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (stage_v_21 ^ pub_r001997_7) & 63;
    if ((stage_v_37 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_37 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_37 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_37 * 2) & 255;
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (pub_r001997_18 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_38) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_29 ^ pub_r001997_1) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r001997_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_20 ^ pub_r001997_6) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001997_10 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001997_15 ^ pub_r001997_6) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001997_1 * 2 + 27) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (sec_r001997_7 ^ pub_r001997_9) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001997_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (pub_r001997_2 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_46) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (stage_v_5 ^ pub_r001997_19) & 63;
    if ((stage_v_47 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_47 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_47 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_47 * 2) & 255;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (sec_r001997_15 ^ pub_r001997_10) & 63;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r001997_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_48 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_48 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_48 * 2) & 255;
    }

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001997_12 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_37 ^ pub_r001997_6) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001997_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (sec_r001997_7 ^ pub_r001997_5) & 63;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r001997_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_52 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_52 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_52 * 2) & 255;
    }

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001997_2 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (stage_v_22 ^ pub_r001997_3) & 63;
    if ((stage_v_54 & 1) != 0) {
        if ((stage_v_30 & 2) != 0) {
            out_sink = (out_sink + stage_v_54 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_54 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_54 * 2) & 255;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (sec_r001997_6 ^ pub_r001997_3) & 63;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r001997_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_55 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_55 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_55 * 2) & 255;
    }

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_5 ^ pub_r001997_4) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((sec_r001997_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (stage_v_6 ^ pub_r001997_14) & 63;
    if ((stage_v_57 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_57 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_57 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_57 * 2) & 255;
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (pub_r001997_13 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_58) & 127;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001997_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (helper_flow_5 ^ pub_r001997_2) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (sec_r001997_0 ^ pub_r001997_7) & 63;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r001997_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_61 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_61 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_61 * 2) & 255;
    }

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (pub_r001997_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_62) & 127;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (stage_v_32 ^ pub_r001997_10) & 63;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r001997_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_63 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_63 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_63 * 2) & 255;
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (stage_v_35 ^ pub_r001997_1) & 63;
    if ((stage_v_64 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_64 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_64 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_64 * 2) & 255;
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (stage_v_7 ^ pub_r001997_15) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_48 ^ pub_r001997_4) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (pub_r001997_10 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_67) & 127;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_3 ^ pub_r001997_19) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001997_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (pub_r001997_17 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_69) & 127;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_19 ^ pub_r001997_11) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r001997_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (stage_v_56 ^ pub_r001997_18) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r001997_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001997_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_54 ^ pub_r001997_10) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r001997_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (sec_r001997_1 ^ pub_r001997_15) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r001997_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (stage_v_61 ^ pub_r001997_12) & 63;
    if ((stage_v_75 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_75 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_75 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_75 * 2) & 255;
    }

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001997_9 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001997_1 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (helper_flow_2 ^ pub_r001997_3) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((sec_r001997_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_60 ^ pub_r001997_15) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_73 ^ pub_r001997_17) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_35 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (stage_v_78 ^ pub_r001997_14) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (stage_v_23 ^ pub_r001997_11) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (stage_v_3 ^ pub_r001997_7) & 63;
    if ((stage_v_83 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_83 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_83 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_83 * 2) & 255;
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001997_4 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (pub_r001997_11 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_85) & 127;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (stage_v_81 ^ pub_r001997_19) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_55 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (sec_r001997_14 ^ pub_r001997_14) & 63;
    if ((stage_v_87 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_87 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_87 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_87 * 2) & 255;
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001997_0 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (stage_v_33 ^ pub_r001997_4) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_87 ^ pub_r001997_9) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_64 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001997_5 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (stage_v_42 ^ pub_r001997_13) & 63;
    if ((stage_v_92 & 1) != 0) {
        if ((stage_v_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_92 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_92 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_92 * 2) & 255;
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (stage_v_78 ^ pub_r001997_18) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (sec_r001997_7 ^ pub_r001997_6) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (stage_v_36 ^ pub_r001997_5) & 63;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r001997_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_95 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_95 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_95 * 2) & 255;
    }

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (stage_v_71 ^ pub_r001997_14) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((stage_v_33 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001997_18 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (pub_r001997_16 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_98) & 127;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (stage_v_27 ^ pub_r001997_14) & 63;
    if ((stage_v_99 & 1) != 0) {
        if ((stage_v_54 & 2) != 0) {
            out_sink = (out_sink + stage_v_99 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_99 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_99 * 2) & 255;
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (pub_r001997_14 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_100) & 127;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (stage_v_63 ^ pub_r001997_11) & 63;
    if ((stage_v_101 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_101 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_101 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_101 * 2) & 255;
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001997_4 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (stage_v_30 ^ pub_r001997_15) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (pub_r001997_5 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_104) & 127;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (pub_r001997_7 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_105) & 127;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_95 ^ pub_r001997_9) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001997_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (sec_r001997_9 ^ pub_r001997_16) & 63;
    if ((stage_v_108 & 1) != 0) {
        if ((stage_v_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_108 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_108 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_108 * 2) & 255;
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (stage_v_6 ^ pub_r001997_8) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (stage_v_19 ^ pub_r001997_16) & 63;
    if ((stage_v_110 & 1) != 0) {
        if ((stage_v_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_110 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_110 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_110 * 2) & 255;
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001997_7 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (helper_flow_1 ^ pub_r001997_4) & 63;
    if ((stage_v_112 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_112 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_112 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_112 * 2) & 255;
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (stage_v_20 ^ pub_r001997_15) & 63;
    if ((stage_v_113 & 1) != 0) {
        if ((stage_v_61 & 2) != 0) {
            out_sink = (out_sink + stage_v_113 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_113 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_113 * 2) & 255;
    }

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (stage_v_3 ^ pub_r001997_4) & 63;
    if ((stage_v_114 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_114 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_114 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_114 * 2) & 255;
    }

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (stage_v_19 ^ pub_r001997_18) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (pub_r001997_14 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_116) & 127;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (stage_v_23 ^ pub_r001997_9) & 63;
    if ((stage_v_117 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_117 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_117 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_117 * 2) & 255;
    }

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_87 ^ pub_r001997_10) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (stage_v_93 ^ pub_r001997_9) & 63;
    if ((stage_v_119 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_119 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_119 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_119 * 2) & 255;
    }

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001997_15 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (stage_v_112 ^ pub_r001997_15) & 63;
    if ((stage_v_121 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_121 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_121 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_121 * 2) & 255;
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001997_19 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_96 ^ pub_r001997_14) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_48 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (pub_r001997_12 * 2 + 15) & 63;
    chk_sum = (chk_sum + stage_v_124) & 127;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (sec_r001997_16 ^ pub_r001997_8) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((helper_flow_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_36 ^ pub_r001997_17) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((stage_v_92 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001997_2 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (pub_r001997_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_128) & 127;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (sec_r001997_3 ^ pub_r001997_10) & 63;
    if ((stage_v_129 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_129 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_129 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_129 * 2) & 255;
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (stage_v_39 ^ pub_r001997_19) & 63;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r001997_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_130 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_130 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_130 * 2) & 255;
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_40 ^ pub_r001997_3) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (sec_r001997_9 ^ pub_r001997_12) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_29 ^ pub_r001997_6) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r001997_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (sec_r001997_11 ^ pub_r001997_5) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r001997_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (stage_v_65 ^ pub_r001997_15) & 63;
    if ((stage_v_135 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_135 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_135 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_135 * 2) & 255;
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001997_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (stage_v_99 ^ pub_r001997_9) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((stage_v_110 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (stage_v_66 ^ pub_r001997_0) & 63;
    if ((stage_v_138 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_138 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_138 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_138 * 2) & 255;
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001997_9 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (helper_flow_7 ^ pub_r001997_3) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001997_13 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (stage_v_87 ^ pub_r001997_15) & 63;
    if ((stage_v_142 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_142 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_142 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_142 * 2) & 255;
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001997_11 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001997_10 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001997_17 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (helper_flow_8 ^ pub_r001997_3) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (stage_v_92 ^ pub_r001997_0) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (helper_flow_5 ^ pub_r001997_18) & 63;
    if ((stage_v_148 & 1) != 0) {
        if ((stage_v_78 & 2) != 0) {
            out_sink = (out_sink + stage_v_148 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_148 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_148 * 2) & 255;
    }

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (stage_v_65 ^ pub_r001997_11) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_66 ^ pub_r001997_2) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_138 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_37 ^ pub_r001997_18) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_37 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001997_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001997_11 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (stage_v_33 ^ pub_r001997_18) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((stage_v_142 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (stage_v_65 ^ pub_r001997_12) & 63;
    if ((stage_v_155 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_155 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_155 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_155 * 2) & 255;
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_5 ^ pub_r001997_3) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_94 ^ pub_r001997_12) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_148 ^ pub_r001997_17) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (pub_r001997_3 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_159) & 127;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001997_18 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (stage_v_39 ^ pub_r001997_8) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_147 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (helper_flow_0 ^ pub_r001997_19) & 63;
    if ((stage_v_162 & 1) != 0) {
        if ((stage_v_137 & 2) != 0) {
            out_sink = (out_sink + stage_v_162 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_162 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_162 * 2) & 255;
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001997_19 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (helper_flow_2 ^ pub_r001997_17) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001997_1 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001997_19 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (pub_r001997_8 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_167) & 127;

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (pub_r001997_2 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_168) & 127;

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (pub_r001997_14 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_169) & 127;

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_52 ^ pub_r001997_12) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_71 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_60 ^ pub_r001997_9) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (stage_v_146 ^ pub_r001997_9) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_117 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001997_11 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001997_0 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (stage_v_109 ^ pub_r001997_9) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_149 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001997_4 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001997_4 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_90 ^ pub_r001997_8) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((sec_r001997_9 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_90 ^ pub_r001997_9) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_2 ^ pub_r001997_10) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (stage_v_36 ^ pub_r001997_5) & 63;
    if ((stage_v_181 & 1) != 0) {
        if ((stage_v_125 & 2) != 0) {
            out_sink = (out_sink + stage_v_181 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_181 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_181 * 2) & 255;
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001997_14 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (stage_v_142 ^ pub_r001997_3) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((stage_v_172 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (helper_flow_5 ^ pub_r001997_17) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_140 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (stage_v_18 ^ pub_r001997_1) & 63;
    if ((stage_v_185 & 1) != 0) {
        if ((sec_r001997_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_185 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_185 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_185 * 2) & 255;
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (pub_r001997_8 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_186) & 127;

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (helper_flow_9 ^ pub_r001997_1) & 63;
    if ((stage_v_187 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_187 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_187 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_187 * 2) & 255;
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001997_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (stage_v_27 ^ pub_r001997_4) & 63;
    if ((stage_v_189 & 1) != 0) {
        if ((stage_v_87 & 2) != 0) {
            out_sink = (out_sink + stage_v_189 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_189 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_189 * 2) & 255;
    }

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_79 ^ pub_r001997_1) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_134 ^ pub_r001997_17) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_89 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (pub_r001997_5 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_192) & 127;

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (sec_r001997_12 ^ pub_r001997_16) & 63;
    if ((stage_v_193 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_193 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_193 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_193 * 2) & 255;
    }

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (stage_v_129 ^ pub_r001997_4) & 63;
    if ((stage_v_194 & 1) != 0) {
        if ((stage_v_185 & 2) != 0) {
            out_sink = (out_sink + stage_v_194 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_194 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_194 * 2) & 255;
    }

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_184 ^ pub_r001997_18) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_108 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (pub_r001997_8 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_196) & 127;

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_175 ^ pub_r001997_11) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (pub_r001997_10 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_198) & 127;

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (stage_v_112 ^ pub_r001997_4) & 63;
    if ((stage_v_199 & 1) != 0) {
        if ((stage_v_178 & 2) != 0) {
            out_sink = (out_sink + stage_v_199 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_199 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_199 * 2) & 255;
    }

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (sec_r001997_2 ^ pub_r001997_0) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((stage_v_195 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (pub_r001997_13 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_201) & 127;

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_75 ^ pub_r001997_4) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (stage_v_137 ^ pub_r001997_5) & 63;
    if ((stage_v_203 & 1) != 0) {
        if ((stage_v_187 & 2) != 0) {
            out_sink = (out_sink + stage_v_203 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_203 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_203 * 2) & 255;
    }

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_194 ^ pub_r001997_2) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_203 ^ pub_r001997_4) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_158 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (pub_r001997_3 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_206) & 127;

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_170 ^ pub_r001997_16) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((sec_r001997_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = (stage_v_65 ^ pub_r001997_3) & 63;
    if ((stage_v_208 & 1) != 0) {
        if ((stage_v_109 & 2) != 0) {
            out_sink = (out_sink + stage_v_208 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_208 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_208 * 2) & 255;
    }

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = (stage_v_18 ^ pub_r001997_11) & 63;
    if ((stage_v_209 & 1) != 0) {
        if ((stage_v_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_209 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_209 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_209 * 2) & 255;
    }

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = (pub_r001997_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_210) & 127;

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = (pub_r001997_11 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_211) & 127;

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = (stage_v_209 ^ pub_r001997_18) & 63;
    if ((stage_v_212 & 1) != 0) {
        if ((sec_r001997_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_212 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_212 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_212 * 2) & 255;
    }

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = (stage_v_123 ^ pub_r001997_10) & 63;
    if ((stage_v_213 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_213 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_213 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_213 * 2) & 255;
    }

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = (stage_v_199 ^ pub_r001997_10) & 63;
    if ((stage_v_214 & 1) != 0) {
        if ((stage_v_131 & 2) != 0) {
            out_sink = (out_sink + stage_v_214 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_214 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_214 * 2) & 255;
    }

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = (stage_v_11 ^ pub_r001997_6) & 63;
    if ((stage_v_215 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_215 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_215 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_215 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
