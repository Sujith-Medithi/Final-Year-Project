/*
 * Benchmark Program: R000167
 * Security Family: nested_implicit_flow
 * Generator Seed: 516713
 * High Inputs: 21 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000167_6713_0 {
    short account_id;
    int rate;
    int status;
    unsigned char fee;
    short auth_code;
    int balance;
    int buffer[3];
};

struct EventLog_R000167_6713_1 {
    int signature;
    unsigned char facility;
    int severity;
    int seq;
    int buffer[3];
};

struct FilterState_R000167_6713_2 {
    int prev_out;
    int gain_db;
    int damping;
    int buffer[3];
};

struct SensorNode_R000167_6713_3 {
    short calib;
    int gain;
    short threshold;
    unsigned char offset;
    int reading;
    short status;
    int buffer[3];
};

union PacketPayload_R000167_6713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000167_6713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000167_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int accumulator_69 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_69 > 44) {
        acc = (acc + accumulator_69 * 2 + 5) & 127;
        aux ^= (accumulator_69 & 15);
    } else {
        acc = (acc - accumulator_69 + 11) & 127;
        aux += 3;
    }
    int tracker_67 = (aux + st.buffer[1]) & 3;
    switch (tracker_67) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_56 = local_arr[aux % 3];
    acc = (acc + margin_56 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000167_6713_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000167_6713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int local_arr[3] = {4, 9, 15};
    int segment_56 = local_arr[aux % 3];
    acc = (acc + segment_56 * 2) & 127;
    int tracker_57 = (aux + st.buffer[1]) & 3;
    switch (tracker_57) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_2(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000167_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int residue_33 = local_arr[aux % 3];
    acc = (acc + residue_33 * 2) & 127;
    int parity_53 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_53 > 14) {
        acc = (acc + parity_53 * 2 + 5) & 127;
        aux ^= (parity_53 & 15);
    } else {
        acc = (acc - parity_53 + 11) & 127;
        aux += 3;
    }
    int coefficient_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_97) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000167_6713_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000167_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int damping_48 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_48 > 43) {
        acc = (acc + damping_48 * 2 + 5) & 127;
        aux ^= (damping_48 & 15);
    } else {
        acc = (acc - damping_48 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000167_6713_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000167_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int residue_72 = local_arr[aux % 3];
    acc = (acc + residue_72 * 2) & 127;
    int quantum_55 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_55 > 37) {
        acc = (acc + quantum_55 * 2 + 5) & 127;
        aux ^= (quantum_55 & 15);
    } else {
        acc = (acc - quantum_55 + 11) & 127;
        aux += 3;
    }
    int phase_99 = (aux + st.buffer[1]) & 3;
    switch (phase_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_5(int p0, int p1) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000167_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int metric_34 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_34) & 63;
    acc ^= aux;
    int tally_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_40 > 33) {
        acc = (acc + tally_40 * 2 + 5) & 127;
        aux ^= (tally_40 & 15);
    } else {
        acc = (acc - tally_40 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_57 = local_arr[aux % 3];
    acc = (acc + stride_57 * 2) & 127;
    int parity_90 = (aux + st.buffer[1]) & 3;
    switch (parity_90) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000167_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int vector_58 = local_arr[aux % 3];
    acc = (acc + vector_58 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int factor_24 = (aux + st.buffer[1]) & 3;
    switch (factor_24) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_7(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000167_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_41 = (aux + st.buffer[1]) & 3;
    switch (metric_41) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_8(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000167_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int segment_32 = (aux + st.buffer[1]) & 3;
    switch (segment_32) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int tracker_15 = local_arr[aux % 3];
    acc = (acc + tracker_15 * 2) & 127;
    int parity_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_72) & 63;
    acc ^= aux;
    int margin_79 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_79 > 50) {
        acc = (acc + margin_79 * 2 + 5) & 127;
        aux ^= (margin_79 & 15);
    } else {
        acc = (acc - margin_79 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_9(int p0, int p1) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000167_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_77 = (aux + st.buffer[1]) & 3;
    switch (checksum_77) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int metric_12 = local_arr[aux % 3];
    acc = (acc + metric_12 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000167_6713_10(int p0, int p1) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000167_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int window_54 = (st.buffer[0] * 3 + aux) & 63;
    if (window_54 > 32) {
        acc = (acc + window_54 * 2 + 5) & 127;
        aux ^= (window_54 & 15);
    } else {
        acc = (acc - window_54 + 11) & 127;
        aux += 3;
    }
    int vector_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_55) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_25 = local_arr[aux % 3];
    acc = (acc + tracker_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000167_6713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000167_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int window_29 = local_arr[aux % 3];
    acc = (acc + window_29 * 2) & 127;
    int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_80) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_93 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_93 > 32) {
        acc = (acc + index_reg_93 * 2 + 5) & 127;
        aux ^= (index_reg_93 & 15);
    } else {
        acc = (acc - index_reg_93 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_12(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000167_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int vector_85 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_85 > 11) {
        acc = (acc + vector_85 * 2 + 5) & 127;
        aux ^= (vector_85 & 15);
    } else {
        acc = (acc - vector_85 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_76 = local_arr[aux % 3];
    acc = (acc + quantum_76 * 2) & 127;
    int cursor_40 = (aux + st.buffer[1]) & 3;
    switch (cursor_40) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000167_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int tracker_62 = (aux + st.buffer[1]) & 3;
    switch (tracker_62) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_30) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_53 = local_arr[aux % 3];
    acc = (acc + tally_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000167_6713_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000167_6713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int checksum_98 = (aux + st.buffer[1]) & 3;
    switch (checksum_98) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_76 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_76 > 17) {
        acc = (acc + metric_76 * 2 + 5) & 127;
        aux ^= (metric_76 & 15);
    } else {
        acc = (acc - metric_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000167_6713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int tracker_42 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_42) & 63;
    acc ^= aux;
    int threshold_45 = (st.buffer[0] * 3 + aux) & 63;
    if (threshold_45 > 43) {
        acc = (acc + threshold_45 * 2 + 5) & 127;
        aux ^= (threshold_45 & 15);
    } else {
        acc = (acc - threshold_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000167_6713_16(int p0, int p1) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000167_6713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int local_arr[3] = {4, 9, 15};
    int margin_75 = local_arr[aux % 3];
    acc = (acc + margin_75 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_99 = (aux + st.buffer[1]) & 3;
    switch (phase_99) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_69 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_69) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000167_0;
    int sec_r000167_1;
    int sec_r000167_2;
    int sec_r000167_3;
    int sec_r000167_4;
    int sec_r000167_5;
    int sec_r000167_6;
    int sec_r000167_7;
    int sec_r000167_8;
    int sec_r000167_9;
    int sec_r000167_10;
    int sec_r000167_11;
    int sec_r000167_12;
    int sec_r000167_13;
    int sec_r000167_14;
    int sec_r000167_15;
    int sec_r000167_16;
    int sec_r000167_17;
    int sec_r000167_18;
    int sec_r000167_19;
    int sec_r000167_20;
    int pub_r000167_0;
    int pub_r000167_1;
    int pub_r000167_2;
    int pub_r000167_3;
    int pub_r000167_4;
    int pub_r000167_5;
    int pub_r000167_6;
    int pub_r000167_7;
    int pub_r000167_8;
    int pub_r000167_9;
    int pub_r000167_10;
    int pub_r000167_11;
    int pub_r000167_12;
    int pub_r000167_13;
    int pub_r000167_14;
    int pub_r000167_15;
    int pub_r000167_16;
    int pub_r000167_17;
    int pub_r000167_18;
    int pub_r000167_19;
    int pub_r000167_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000167_0 >= -100 && pub_r000167_0 <= 100);
    __CPROVER_assume(pub_r000167_1 >= -100 && pub_r000167_1 <= 100);
    __CPROVER_assume(pub_r000167_2 >= -100 && pub_r000167_2 <= 100);
    __CPROVER_assume(pub_r000167_3 >= -100 && pub_r000167_3 <= 100);
    __CPROVER_assume(pub_r000167_4 >= -100 && pub_r000167_4 <= 100);
    __CPROVER_assume(pub_r000167_5 >= -100 && pub_r000167_5 <= 100);
    __CPROVER_assume(pub_r000167_6 >= -100 && pub_r000167_6 <= 100);
    __CPROVER_assume(pub_r000167_7 >= -100 && pub_r000167_7 <= 100);
    __CPROVER_assume(pub_r000167_8 >= -100 && pub_r000167_8 <= 100);
    __CPROVER_assume(pub_r000167_9 >= -100 && pub_r000167_9 <= 100);
    __CPROVER_assume(pub_r000167_10 >= -100 && pub_r000167_10 <= 100);
    __CPROVER_assume(pub_r000167_11 >= -100 && pub_r000167_11 <= 100);
    __CPROVER_assume(pub_r000167_12 >= -100 && pub_r000167_12 <= 100);
    __CPROVER_assume(pub_r000167_13 >= -100 && pub_r000167_13 <= 100);
    __CPROVER_assume(pub_r000167_14 >= -100 && pub_r000167_14 <= 100);
    __CPROVER_assume(pub_r000167_15 >= -100 && pub_r000167_15 <= 100);
    __CPROVER_assume(pub_r000167_16 >= -100 && pub_r000167_16 <= 100);
    __CPROVER_assume(pub_r000167_17 >= -100 && pub_r000167_17 <= 100);
    __CPROVER_assume(pub_r000167_18 >= -100 && pub_r000167_18 <= 100);
    __CPROVER_assume(pub_r000167_19 >= -100 && pub_r000167_19 <= 100);
    __CPROVER_assume(pub_r000167_20 >= -100 && pub_r000167_20 <= 100);
    __CPROVER_assume(sec_r000167_0 >= 0 && sec_r000167_0 <= 255);
    __CPROVER_assume(sec_r000167_1 >= 0 && sec_r000167_1 <= 255);
    __CPROVER_assume(sec_r000167_2 >= 0 && sec_r000167_2 <= 255);
    __CPROVER_assume(sec_r000167_3 >= 0 && sec_r000167_3 <= 255);
    __CPROVER_assume(sec_r000167_4 >= 0 && sec_r000167_4 <= 255);
    __CPROVER_assume(sec_r000167_5 >= 0 && sec_r000167_5 <= 255);
    __CPROVER_assume(sec_r000167_6 >= 0 && sec_r000167_6 <= 255);
    __CPROVER_assume(sec_r000167_7 >= 0 && sec_r000167_7 <= 255);
    __CPROVER_assume(sec_r000167_8 >= 0 && sec_r000167_8 <= 255);
    __CPROVER_assume(sec_r000167_9 >= 0 && sec_r000167_9 <= 255);
    __CPROVER_assume(sec_r000167_10 >= 0 && sec_r000167_10 <= 255);
    __CPROVER_assume(sec_r000167_11 >= 0 && sec_r000167_11 <= 255);
    __CPROVER_assume(sec_r000167_12 >= 0 && sec_r000167_12 <= 255);
    __CPROVER_assume(sec_r000167_13 >= 0 && sec_r000167_13 <= 255);
    __CPROVER_assume(sec_r000167_14 >= 0 && sec_r000167_14 <= 255);
    __CPROVER_assume(sec_r000167_15 >= 0 && sec_r000167_15 <= 255);
    __CPROVER_assume(sec_r000167_16 >= 0 && sec_r000167_16 <= 255);
    __CPROVER_assume(sec_r000167_17 >= 0 && sec_r000167_17 <= 255);
    __CPROVER_assume(sec_r000167_18 >= 0 && sec_r000167_18 <= 255);
    __CPROVER_assume(sec_r000167_19 >= 0 && sec_r000167_19 <= 255);
    __CPROVER_assume(sec_r000167_20 >= 0 && sec_r000167_20 <= 255);

    struct Transaction_R000167_6713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000167_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000167_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000167_0 + 7) & 15;
    struct EventLog_R000167_6713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000167_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000167_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000167_0 + 9) & 15;
    struct FilterState_R000167_6713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000167_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000167_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000167_0 + 11) & 15;
    struct SensorNode_R000167_6713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000167_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000167_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000167_0 + 13) & 15;

    union PacketPayload_R000167_6713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 1) & 15;
    int stage_v_0 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= stage_v_0;

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[0] ^ 5) & 3;
    switch (stage_v_2) {
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

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_0.buffer[0] ^ 7) & 3;
    switch (stage_v_4) {
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

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = table[2];
    table[2] = (table[3] + 13) & 63;
    out_sink = (out_sink + stage_v_6) & 255;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 27) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 42) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[2] * 2 + 31) & 63;
    if (stage_v_8 > 34) {
        out_sink = (out_sink + stage_v_8 - 5) & 255;
        if (stage_v_8 > 49) {
            chk_sum ^= (stage_v_8 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_8 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (st_var_2.buffer[0] ^ 13) & 3;
    switch (stage_v_10) {
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

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (out_sink > 100) ? (chk_sum & 31) : (16 & 31);
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= (stage_v_11 << 1) & 127;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 14) & 15;
    int stage_v_13 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_13) & 255;
    chk_sum ^= stage_v_13;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_14 = (stage_v_14 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_14) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (out_sink > 100) ? (chk_sum & 31) : (20 & 31);
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= (stage_v_15 << 1) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_1.buffer[2] * 2 + 58) & 63;
    if (stage_v_17 > 20) {
        out_sink = (out_sink + stage_v_17 - 5) & 255;
        if (stage_v_17 > 35) {
            chk_sum ^= (stage_v_17 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_17 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_2.buffer[0] * 2 + 61) & 63;
    if (stage_v_18 > 24) {
        out_sink = (out_sink + stage_v_18 - 5) & 255;
        if (stage_v_18 > 39) {
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
    for (int step = 0; step < 2; step++) {
        stage_v_20 = (stage_v_20 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_20) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_21 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_2.buffer[0] ^ 25) & 3;
    switch (stage_v_22) {
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

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (st_var_0.buffer[0] * 2 + 79) & 63;
    if (stage_v_24 > 22) {
        out_sink = (out_sink + stage_v_24 - 5) & 255;
        if (stage_v_24 > 37) {
            chk_sum ^= (stage_v_24 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_24 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[0] ^ 28) & 3;
    switch (stage_v_25) {
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

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = table[2];
    table[2] = (table[3] + 53) & 63;
    out_sink = (out_sink + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (out_sink > 100) ? (chk_sum & 31) : (34 & 31);
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= (stage_v_29 << 1) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_30 = (stage_v_30 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_30) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (st_var_0.buffer[2] * 2 + 103) & 63;
    if (stage_v_32 > 10) {
        out_sink = (out_sink + stage_v_32 - 5) & 255;
        if (stage_v_32 > 25) {
            chk_sum ^= (stage_v_32 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_32 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_1.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 33) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 48) {
            chk_sum ^= (stage_v_33 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_33 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 37) & 15;
    int stage_v_36 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= stage_v_36;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

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
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (st_var_2.buffer[0] * 2 + 133) & 63;
    if (stage_v_42 > 11) {
        out_sink = (out_sink + stage_v_42 - 5) & 255;
        if (stage_v_42 > 26) {
            chk_sum ^= (stage_v_42 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_42 + 9) & 255;
        chk_sum ^= 0x1A;
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
    int stage_v_45 = table[1];
    table[1] = (table[2] + 91) & 63;
    out_sink = (out_sink + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[2] * 2 + 148) & 63;
    if (stage_v_47 > 25) {
        out_sink = (out_sink + stage_v_47 - 5) & 255;
        if (stage_v_47 > 40) {
            chk_sum ^= (stage_v_47 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_47 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = table[0];
    table[0] = (table[1] + 97) & 63;
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (out_sink > 100) ? (chk_sum & 31) : (56 & 31);
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= (stage_v_51 << 1) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (out_sink > 100) ? (chk_sum & 31) : (57 & 31);
    out_sink = (out_sink + stage_v_52) & 255;
    chk_sum ^= (stage_v_52 << 1) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = table[3];
    table[3] = (table[0] + 111) & 63;
    out_sink = (out_sink + stage_v_55) & 255;

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
    int stage_v_58 = (st_var_2.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_3.buffer[2] * 2 + 184) & 63;
    if (stage_v_59 > 26) {
        out_sink = (out_sink + stage_v_59 - 5) & 255;
        if (stage_v_59 > 41) {
            chk_sum ^= (stage_v_59 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_59 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = table[1];
    table[1] = (table[2] + 123) & 63;
    out_sink = (out_sink + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = table[2];
    table[2] = (table[3] + 125) & 63;
    out_sink = (out_sink + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (st_var_3.buffer[0] ^ 66) & 3;
    switch (stage_v_63) {
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

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_0.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = table[1];
    table[1] = (table[2] + 131) & 63;
    out_sink = (out_sink + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000167_8 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_66 = (pub_r000167_5 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000167_5 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000167_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000167_17 & 2) != 0) {
            stage_v_67 = (pub_r000167_3 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000167_3 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000167_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000167_18 & 2) != 0) {
            stage_v_68 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((sec_r000167_15 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_69 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_70 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000167_11 & 2) != 0) {
            stage_v_71 = (pub_r000167_3 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000167_3 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000167_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_72 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((sec_r000167_20 & 1) != 0) {
        if ((sec_r000167_16 & 2) != 0) {
            stage_v_73 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000167_15 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_74 = (pub_r000167_7 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000167_7 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000167_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((sec_r000167_8 & 1) != 0) {
        if ((sec_r000167_8 & 2) != 0) {
            stage_v_75 = (pub_r000167_4 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000167_4 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000167_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_76 = (pub_r000167_13 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000167_13 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000167_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000167_13 & 2) != 0) {
            stage_v_77 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000167_12 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_78 = (pub_r000167_9 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000167_9 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000167_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000167_3 & 2) != 0) {
            stage_v_79 = (pub_r000167_14 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000167_14 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000167_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000167_5 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_80 = (pub_r000167_0 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000167_0 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000167_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000167_12 & 2) != 0) {
            stage_v_81 = (pub_r000167_8 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000167_8 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000167_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000167_7 & 2) != 0) {
            stage_v_82 = (pub_r000167_10 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000167_10 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000167_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000167_16 & 1) != 0) {
        if ((sec_r000167_8 & 2) != 0) {
            stage_v_83 = (pub_r000167_9 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000167_9 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000167_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000167_5 & 1) != 0) {
        if ((sec_r000167_13 & 2) != 0) {
            stage_v_84 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000167_10 & 2) != 0) {
            stage_v_85 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000167_10 & 2) != 0) {
            stage_v_86 = (pub_r000167_2 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000167_2 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000167_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000167_6 & 2) != 0) {
            stage_v_87 = (pub_r000167_0 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000167_0 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000167_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000167_2 & 1) != 0) {
        if ((sec_r000167_18 & 2) != 0) {
            stage_v_88 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000167_7 & 1) != 0) {
        if ((sec_r000167_9 & 2) != 0) {
            stage_v_89 = (pub_r000167_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000167_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000167_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_90 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000167_6 & 2) != 0) {
            stage_v_91 = (pub_r000167_13 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000167_13 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000167_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000167_11 & 2) != 0) {
            stage_v_92 = (pub_r000167_17 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000167_17 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000167_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000167_2 & 2) != 0) {
            stage_v_93 = (pub_r000167_4 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000167_4 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000167_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000167_7 & 1) != 0) {
        if ((sec_r000167_13 & 2) != 0) {
            stage_v_94 = (pub_r000167_4 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000167_4 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000167_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((sec_r000167_13 & 1) != 0) {
        if ((sec_r000167_15 & 2) != 0) {
            stage_v_95 = (pub_r000167_4 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000167_4 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000167_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_96 = (pub_r000167_0 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000167_0 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000167_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000167_13 & 2) != 0) {
            stage_v_97 = (pub_r000167_18 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000167_18 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000167_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_98 = (pub_r000167_5 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000167_5 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000167_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000167_15 & 2) != 0) {
            stage_v_99 = (pub_r000167_1 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000167_1 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000167_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_95 & 1) != 0) {
        if ((sec_r000167_9 & 2) != 0) {
            stage_v_100 = (pub_r000167_19 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000167_19 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000167_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000167_10 & 1) != 0) {
        if ((sec_r000167_12 & 2) != 0) {
            stage_v_101 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_99 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_102 = (pub_r000167_1 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000167_1 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000167_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000167_2 & 2) != 0) {
            stage_v_103 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000167_6 & 2) != 0) {
            stage_v_104 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000167_5 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_105 = (pub_r000167_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000167_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000167_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000167_18 & 2) != 0) {
            stage_v_106 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((sec_r000167_18 & 1) != 0) {
        if ((sec_r000167_7 & 2) != 0) {
            stage_v_107 = (pub_r000167_8 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000167_8 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000167_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_108 = (pub_r000167_9 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000167_9 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000167_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((sec_r000167_14 & 1) != 0) {
        if ((sec_r000167_12 & 2) != 0) {
            stage_v_109 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((sec_r000167_14 & 1) != 0) {
        if ((sec_r000167_3 & 2) != 0) {
            stage_v_110 = (pub_r000167_13 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000167_13 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000167_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000167_9 & 2) != 0) {
            stage_v_111 = (pub_r000167_13 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000167_13 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000167_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000167_8 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_112 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((sec_r000167_5 & 1) != 0) {
        if ((sec_r000167_7 & 2) != 0) {
            stage_v_113 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000167_15 & 1) != 0) {
        if ((sec_r000167_17 & 2) != 0) {
            stage_v_114 = (pub_r000167_14 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000167_14 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000167_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000167_11 & 1) != 0) {
        if ((sec_r000167_0 & 2) != 0) {
            stage_v_115 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000167_11 & 1) != 0) {
        if ((sec_r000167_7 & 2) != 0) {
            stage_v_116 = (pub_r000167_0 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000167_0 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000167_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000167_0 & 1) != 0) {
        if ((sec_r000167_11 & 2) != 0) {
            stage_v_117 = (pub_r000167_7 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000167_7 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000167_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000167_3 & 1) != 0) {
        if ((sec_r000167_11 & 2) != 0) {
            stage_v_118 = (pub_r000167_9 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000167_9 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000167_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r000167_8 & 2) != 0) {
            stage_v_119 = (pub_r000167_14 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000167_14 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000167_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000167_7 & 2) != 0) {
            stage_v_120 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000167_13 & 1) != 0) {
        if ((sec_r000167_8 & 2) != 0) {
            stage_v_121 = (pub_r000167_17 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000167_17 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000167_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_122 = (pub_r000167_13 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000167_13 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000167_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000167_7 & 2) != 0) {
            stage_v_123 = (pub_r000167_2 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000167_2 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000167_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000167_16 & 2) != 0) {
            stage_v_124 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((stage_v_111 & 1) != 0) {
        if ((sec_r000167_3 & 2) != 0) {
            stage_v_125 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((sec_r000167_18 & 1) != 0) {
        if ((sec_r000167_3 & 2) != 0) {
            stage_v_126 = (pub_r000167_12 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000167_12 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000167_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000167_11 & 1) != 0) {
        if ((sec_r000167_6 & 2) != 0) {
            stage_v_127 = (pub_r000167_2 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000167_2 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000167_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_128 = (pub_r000167_3 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000167_3 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000167_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_129 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000167_17 & 1) != 0) {
        if ((sec_r000167_0 & 2) != 0) {
            stage_v_130 = (pub_r000167_10 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000167_10 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000167_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_126 & 1) != 0) {
        if ((sec_r000167_6 & 2) != 0) {
            stage_v_131 = (pub_r000167_2 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000167_2 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000167_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_118 & 1) != 0) {
        if ((sec_r000167_3 & 2) != 0) {
            stage_v_132 = (pub_r000167_4 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000167_4 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000167_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000167_1 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_133 = (pub_r000167_18 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000167_18 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000167_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000167_11 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_134 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_88 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_135 = (pub_r000167_14 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000167_14 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000167_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_101 & 1) != 0) {
        if ((sec_r000167_2 & 2) != 0) {
            stage_v_136 = (pub_r000167_4 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000167_4 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000167_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000167_18 & 2) != 0) {
            stage_v_137 = (pub_r000167_7 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000167_7 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000167_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000167_11 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_138 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_139 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_117 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_140 = (pub_r000167_2 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000167_2 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000167_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_114 & 1) != 0) {
        if ((sec_r000167_5 & 2) != 0) {
            stage_v_141 = (pub_r000167_1 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000167_1 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000167_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((sec_r000167_2 & 1) != 0) {
        if ((sec_r000167_4 & 2) != 0) {
            stage_v_142 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000167_12 & 1) != 0) {
        if ((sec_r000167_17 & 2) != 0) {
            stage_v_143 = (pub_r000167_5 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000167_5 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000167_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_138 & 1) != 0) {
        if ((sec_r000167_8 & 2) != 0) {
            stage_v_144 = (pub_r000167_8 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000167_8 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000167_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000167_6 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_145 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((sec_r000167_18 & 1) != 0) {
        if ((sec_r000167_14 & 2) != 0) {
            stage_v_146 = (pub_r000167_0 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000167_0 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000167_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000167_5 & 2) != 0) {
            stage_v_147 = (pub_r000167_1 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000167_1 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000167_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000167_15 & 2) != 0) {
            stage_v_148 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((sec_r000167_20 & 1) != 0) {
        if ((sec_r000167_8 & 2) != 0) {
            stage_v_149 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000167_13 & 1) != 0) {
        if ((sec_r000167_10 & 2) != 0) {
            stage_v_150 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((sec_r000167_12 & 1) != 0) {
        if ((sec_r000167_20 & 2) != 0) {
            stage_v_151 = (pub_r000167_5 + 31) & 127;
        } else {
            stage_v_151 = (pub_r000167_5 + 13) & 127;
        }
    } else {
        stage_v_151 = (pub_r000167_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000167_18 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_152 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_152 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_152 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((sec_r000167_2 & 1) != 0) {
        if ((sec_r000167_2 & 2) != 0) {
            stage_v_153 = (pub_r000167_19 + 31) & 127;
        } else {
            stage_v_153 = (pub_r000167_19 + 13) & 127;
        }
    } else {
        stage_v_153 = (pub_r000167_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_154 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_154 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_154 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((sec_r000167_18 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_155 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_155 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_155 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000167_4 & 2) != 0) {
            stage_v_156 = (pub_r000167_5 + 31) & 127;
        } else {
            stage_v_156 = (pub_r000167_5 + 13) & 127;
        }
    } else {
        stage_v_156 = (pub_r000167_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((sec_r000167_0 & 1) != 0) {
        if ((sec_r000167_2 & 2) != 0) {
            stage_v_157 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_157 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_157 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000167_7 & 1) != 0) {
        if ((sec_r000167_15 & 2) != 0) {
            stage_v_158 = (pub_r000167_11 + 31) & 127;
        } else {
            stage_v_158 = (pub_r000167_11 + 13) & 127;
        }
    } else {
        stage_v_158 = (pub_r000167_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_134 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_159 = (pub_r000167_6 + 31) & 127;
        } else {
            stage_v_159 = (pub_r000167_6 + 13) & 127;
        }
    } else {
        stage_v_159 = (pub_r000167_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((sec_r000167_15 & 1) != 0) {
        if ((sec_r000167_18 & 2) != 0) {
            stage_v_160 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_160 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_160 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_85 & 1) != 0) {
        if ((sec_r000167_15 & 2) != 0) {
            stage_v_161 = (pub_r000167_9 + 31) & 127;
        } else {
            stage_v_161 = (pub_r000167_9 + 13) & 127;
        }
    } else {
        stage_v_161 = (pub_r000167_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000167_13 & 2) != 0) {
            stage_v_162 = (pub_r000167_12 + 31) & 127;
        } else {
            stage_v_162 = (pub_r000167_12 + 13) & 127;
        }
    } else {
        stage_v_162 = (pub_r000167_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((stage_v_143 & 1) != 0) {
        if ((sec_r000167_1 & 2) != 0) {
            stage_v_163 = (pub_r000167_17 + 31) & 127;
        } else {
            stage_v_163 = (pub_r000167_17 + 13) & 127;
        }
    } else {
        stage_v_163 = (pub_r000167_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_163) & 255;
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000167_6 & 1) != 0) {
        if ((sec_r000167_13 & 2) != 0) {
            stage_v_164 = (pub_r000167_16 + 31) & 127;
        } else {
            stage_v_164 = (pub_r000167_16 + 13) & 127;
        }
    } else {
        stage_v_164 = (pub_r000167_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_164) & 255;
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_158 & 1) != 0) {
        if ((sec_r000167_19 & 2) != 0) {
            stage_v_165 = (pub_r000167_20 + 31) & 127;
        } else {
            stage_v_165 = (pub_r000167_20 + 13) & 127;
        }
    } else {
        stage_v_165 = (pub_r000167_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_165) & 255;
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_106 & 1) != 0) {
        if ((sec_r000167_5 & 2) != 0) {
            stage_v_166 = (pub_r000167_12 + 31) & 127;
        } else {
            stage_v_166 = (pub_r000167_12 + 13) & 127;
        }
    } else {
        stage_v_166 = (pub_r000167_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_166) & 255;
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((sec_r000167_4 & 1) != 0) {
        if ((sec_r000167_6 & 2) != 0) {
            stage_v_167 = (pub_r000167_15 + 31) & 127;
        } else {
            stage_v_167 = (pub_r000167_15 + 13) & 127;
        }
    } else {
        stage_v_167 = (pub_r000167_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_167) & 255;
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
