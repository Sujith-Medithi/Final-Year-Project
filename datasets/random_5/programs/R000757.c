/*
 * Benchmark Program: R000757
 * Security Family: nested_implicit_flow
 * Generator Seed: 575713
 * High Inputs: 20 | Low Inputs: 21
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct EventLog_R000757_5713_0 {
    int seq;
    short severity;
    int timestamp;
    short signature;
    int buffer[3];
};

struct FilterState_R000757_5713_1 {
    unsigned char damping;
    short mode;
    unsigned char prev_in;
    int buffer[3];
};

struct Transaction_R000757_5713_2 {
    int fee;
    unsigned char rate;
    unsigned char status;
    int balance;
    short account_id;
    int buffer[3];
};

union PacketPayload_R000757_5713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000757_5713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000757_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_81 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_81 > 22) {
        acc = (acc + weight_81 * 2 + 5) & 127;
        aux ^= (weight_81 & 15);
    } else {
        acc = (acc - weight_81 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_16 = local_arr[aux % 3];
    acc = (acc + sample_16 * 2) & 127;
    int factor_32 = (aux + st.buffer[1]) & 3;
    switch (factor_32) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_1(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int scale_73 = (st.buffer[0] * 3 + aux) & 63;
    if (scale_73 > 29) {
        acc = (acc + scale_73 * 2 + 5) & 127;
        aux ^= (scale_73 & 15);
    } else {
        acc = (acc - scale_73 + 11) & 127;
        aux += 3;
    }
    int damping_87 = (aux + st.buffer[1]) & 3;
    switch (damping_87) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int metric_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000757_5713_2(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int weight_46 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_46) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int stride_62 = local_arr[aux % 3];
    acc = (acc + stride_62 * 2) & 127;
    int damping_41 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_41 > 21) {
        acc = (acc + damping_41 * 2 + 5) & 127;
        aux ^= (damping_41 & 15);
    } else {
        acc = (acc - damping_41 + 11) & 127;
        aux += 3;
    }
    int window_60 = (aux + st.buffer[1]) & 3;
    switch (window_60) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000757_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int index_reg_34 = local_arr[aux % 3];
    acc = (acc + index_reg_34 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000757_5713_4(int p0, int p1, int p2) {
    int acc = (p0 + 21) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quantum_97 = (aux + st.buffer[1]) & 3;
    switch (quantum_97) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int cursor_32 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_32 > 28) {
        acc = (acc + cursor_32 * 2 + 5) & 127;
        aux ^= (cursor_32 & 15);
    } else {
        acc = (acc - cursor_32 + 11) & 127;
        aux += 3;
    }
    int quantum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_27 = local_arr[aux % 3];
    acc = (acc + checksum_27 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000757_5713_5(int p0, int p1, int p2) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int tally_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_80) & 63;
    acc ^= aux;
    int cursor_98 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_98 > 41) {
        acc = (acc + cursor_98 * 2 + 5) & 127;
        aux ^= (cursor_98 & 15);
    } else {
        acc = (acc - cursor_98 + 11) & 127;
        aux += 3;
    }
    int stride_68 = (aux + st.buffer[1]) & 3;
    switch (stride_68) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int quotient_85 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_85 > 13) {
        acc = (acc + quotient_85 * 2 + 5) & 127;
        aux ^= (quotient_85 & 15);
    } else {
        acc = (acc - quotient_85 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int bound_67 = local_arr[aux % 3];
    acc = (acc + bound_67 * 2) & 127;
    int accumulator_55 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_55) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000757_5713_7(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000757_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_90 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_90 > 50) {
        acc = (acc + vector_90 * 2 + 5) & 127;
        aux ^= (vector_90 & 15);
    } else {
        acc = (acc - vector_90 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int offset_42 = (aux + st.buffer[1]) & 3;
    switch (offset_42) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int vector_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_30) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000757_5713_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int vector_46 = (aux + st.buffer[1]) & 3;
    switch (vector_46) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_19) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_35 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_35 > 14) {
        acc = (acc + metric_35 * 2 + 5) & 127;
        aux ^= (metric_35 & 15);
    } else {
        acc = (acc - metric_35 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_9(int p0, int p1, int p2) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000757_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int quotient_60 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_60 > 50) {
        acc = (acc + quotient_60 * 2 + 5) & 127;
        aux ^= (quotient_60 & 15);
    } else {
        acc = (acc - quotient_60 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_21 = local_arr[aux % 3];
    acc = (acc + offset_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000757_5713_10(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000757_5713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int quantum_30 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_30) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_64 = (aux + st.buffer[1]) & 3;
    switch (bound_64) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int metric_74 = local_arr[aux % 3];
    acc = (acc + metric_74 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000757_5713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000757_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int margin_24 = (aux + st.buffer[1]) & 3;
    switch (margin_24) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_89 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_89) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int residue_84 = local_arr[aux % 3];
    acc = (acc + residue_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000757_5713_13(int p0, int p1) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000757_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int cursor_51 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_51 > 23) {
        acc = (acc + cursor_51 * 2 + 5) & 127;
        aux ^= (cursor_51 & 15);
    } else {
        acc = (acc - cursor_51 + 11) & 127;
        aux += 3;
    }
    int vector_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_94) & 63;
    acc ^= aux;
    int tally_97 = (aux + st.buffer[1]) & 3;
    switch (tally_97) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000757_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int bound_10 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_10 > 19) {
        acc = (acc + bound_10 * 2 + 5) & 127;
        aux ^= (bound_10 & 15);
    } else {
        acc = (acc - bound_10 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_42 = local_arr[aux % 3];
    acc = (acc + stride_42 * 2) & 127;
    int checksum_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_92) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000757_5713_15(int p0, int p1, int p2) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000757_5713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int residue_46 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_46 > 11) {
        acc = (acc + residue_46 * 2 + 5) & 127;
        aux ^= (residue_46 & 15);
    } else {
        acc = (acc - residue_46 + 11) & 127;
        aux += 3;
    }
    int coefficient_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int pivot_81 = local_arr[aux % 3];
    acc = (acc + pivot_81 * 2) & 127;
    int phase_46 = (aux + st.buffer[1]) & 3;
    switch (phase_46) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000757_5713_16(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000757_5713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int local_arr[3] = {4, 9, 15};
    int bound_68 = local_arr[aux % 3];
    acc = (acc + bound_68 * 2) & 127;
    int factor_78 = (aux + st.buffer[1]) & 3;
    switch (factor_78) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tracker_38 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_38 > 27) {
        acc = (acc + tracker_38 * 2 + 5) & 127;
        aux ^= (tracker_38 & 15);
    } else {
        acc = (acc - tracker_38 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000757_0;
    int sec_r000757_1;
    int sec_r000757_2;
    int sec_r000757_3;
    int sec_r000757_4;
    int sec_r000757_5;
    int sec_r000757_6;
    int sec_r000757_7;
    int sec_r000757_8;
    int sec_r000757_9;
    int sec_r000757_10;
    int sec_r000757_11;
    int sec_r000757_12;
    int sec_r000757_13;
    int sec_r000757_14;
    int sec_r000757_15;
    int sec_r000757_16;
    int sec_r000757_17;
    int sec_r000757_18;
    int sec_r000757_19;
    int pub_r000757_0;
    int pub_r000757_1;
    int pub_r000757_2;
    int pub_r000757_3;
    int pub_r000757_4;
    int pub_r000757_5;
    int pub_r000757_6;
    int pub_r000757_7;
    int pub_r000757_8;
    int pub_r000757_9;
    int pub_r000757_10;
    int pub_r000757_11;
    int pub_r000757_12;
    int pub_r000757_13;
    int pub_r000757_14;
    int pub_r000757_15;
    int pub_r000757_16;
    int pub_r000757_17;
    int pub_r000757_18;
    int pub_r000757_19;
    int pub_r000757_20;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000757_0 >= -100 && pub_r000757_0 <= 100);
    __CPROVER_assume(pub_r000757_1 >= -100 && pub_r000757_1 <= 100);
    __CPROVER_assume(pub_r000757_2 >= -100 && pub_r000757_2 <= 100);
    __CPROVER_assume(pub_r000757_3 >= -100 && pub_r000757_3 <= 100);
    __CPROVER_assume(pub_r000757_4 >= -100 && pub_r000757_4 <= 100);
    __CPROVER_assume(pub_r000757_5 >= -100 && pub_r000757_5 <= 100);
    __CPROVER_assume(pub_r000757_6 >= -100 && pub_r000757_6 <= 100);
    __CPROVER_assume(pub_r000757_7 >= -100 && pub_r000757_7 <= 100);
    __CPROVER_assume(pub_r000757_8 >= -100 && pub_r000757_8 <= 100);
    __CPROVER_assume(pub_r000757_9 >= -100 && pub_r000757_9 <= 100);
    __CPROVER_assume(pub_r000757_10 >= -100 && pub_r000757_10 <= 100);
    __CPROVER_assume(pub_r000757_11 >= -100 && pub_r000757_11 <= 100);
    __CPROVER_assume(pub_r000757_12 >= -100 && pub_r000757_12 <= 100);
    __CPROVER_assume(pub_r000757_13 >= -100 && pub_r000757_13 <= 100);
    __CPROVER_assume(pub_r000757_14 >= -100 && pub_r000757_14 <= 100);
    __CPROVER_assume(pub_r000757_15 >= -100 && pub_r000757_15 <= 100);
    __CPROVER_assume(pub_r000757_16 >= -100 && pub_r000757_16 <= 100);
    __CPROVER_assume(pub_r000757_17 >= -100 && pub_r000757_17 <= 100);
    __CPROVER_assume(pub_r000757_18 >= -100 && pub_r000757_18 <= 100);
    __CPROVER_assume(pub_r000757_19 >= -100 && pub_r000757_19 <= 100);
    __CPROVER_assume(pub_r000757_20 >= -100 && pub_r000757_20 <= 100);
    __CPROVER_assume(sec_r000757_0 >= 0 && sec_r000757_0 <= 255);
    __CPROVER_assume(sec_r000757_1 >= 0 && sec_r000757_1 <= 255);
    __CPROVER_assume(sec_r000757_2 >= 0 && sec_r000757_2 <= 255);
    __CPROVER_assume(sec_r000757_3 >= 0 && sec_r000757_3 <= 255);
    __CPROVER_assume(sec_r000757_4 >= 0 && sec_r000757_4 <= 255);
    __CPROVER_assume(sec_r000757_5 >= 0 && sec_r000757_5 <= 255);
    __CPROVER_assume(sec_r000757_6 >= 0 && sec_r000757_6 <= 255);
    __CPROVER_assume(sec_r000757_7 >= 0 && sec_r000757_7 <= 255);
    __CPROVER_assume(sec_r000757_8 >= 0 && sec_r000757_8 <= 255);
    __CPROVER_assume(sec_r000757_9 >= 0 && sec_r000757_9 <= 255);
    __CPROVER_assume(sec_r000757_10 >= 0 && sec_r000757_10 <= 255);
    __CPROVER_assume(sec_r000757_11 >= 0 && sec_r000757_11 <= 255);
    __CPROVER_assume(sec_r000757_12 >= 0 && sec_r000757_12 <= 255);
    __CPROVER_assume(sec_r000757_13 >= 0 && sec_r000757_13 <= 255);
    __CPROVER_assume(sec_r000757_14 >= 0 && sec_r000757_14 <= 255);
    __CPROVER_assume(sec_r000757_15 >= 0 && sec_r000757_15 <= 255);
    __CPROVER_assume(sec_r000757_16 >= 0 && sec_r000757_16 <= 255);
    __CPROVER_assume(sec_r000757_17 >= 0 && sec_r000757_17 <= 255);
    __CPROVER_assume(sec_r000757_18 >= 0 && sec_r000757_18 <= 255);
    __CPROVER_assume(sec_r000757_19 >= 0 && sec_r000757_19 <= 255);

    struct EventLog_R000757_5713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000757_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000757_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000757_0 + 7) & 15;
    struct FilterState_R000757_5713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000757_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000757_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000757_0 + 9) & 15;
    struct Transaction_R000757_5713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000757_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000757_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000757_0 + 11) & 15;

    union PacketPayload_R000757_5713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 32) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 47) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (out_sink > 100) ? (chk_sum & 31) : (7 & 31);
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= (stage_v_2 << 1) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_3 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_4 = (stage_v_4 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_4) & 127;
    }
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (st_var_2.buffer[0] ^ 8) & 3;
    switch (stage_v_5) {
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

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_7 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_0.buffer[0] * 2 + 34) & 63;
    if (stage_v_9 > 40) {
        out_sink = (out_sink + stage_v_9 - 5) & 255;
        if (stage_v_9 > 55) {
            chk_sum ^= (stage_v_9 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_9 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    if ((sec_r000757_19 & 1) != 0) {
        if ((sec_r000757_16 & 2) != 0) {
            stage_v_10 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_10 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_10 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    if ((sec_r000757_16 & 1) != 0) {
        if ((sec_r000757_11 & 2) != 0) {
            stage_v_11 = (pub_r000757_10 + 31) & 127;
        } else {
            stage_v_11 = (pub_r000757_10 + 13) & 127;
        }
    } else {
        stage_v_11 = (pub_r000757_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_12 = (pub_r000757_6 + 31) & 127;
        } else {
            stage_v_12 = (pub_r000757_6 + 13) & 127;
        }
    } else {
        stage_v_12 = (pub_r000757_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r000757_11 & 2) != 0) {
            stage_v_13 = (pub_r000757_14 + 31) & 127;
        } else {
            stage_v_13 = (pub_r000757_14 + 13) & 127;
        }
    } else {
        stage_v_13 = (pub_r000757_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000757_9 & 2) != 0) {
            stage_v_14 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_14 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_14 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((stage_v_14 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_15 = (pub_r000757_19 + 31) & 127;
        } else {
            stage_v_15 = (pub_r000757_19 + 13) & 127;
        }
    } else {
        stage_v_15 = (pub_r000757_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((sec_r000757_10 & 1) != 0) {
        if ((sec_r000757_15 & 2) != 0) {
            stage_v_16 = (pub_r000757_5 + 31) & 127;
        } else {
            stage_v_16 = (pub_r000757_5 + 13) & 127;
        }
    } else {
        stage_v_16 = (pub_r000757_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((sec_r000757_6 & 1) != 0) {
        if ((sec_r000757_3 & 2) != 0) {
            stage_v_17 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_17 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_17 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000757_10 & 2) != 0) {
            stage_v_18 = (pub_r000757_9 + 31) & 127;
        } else {
            stage_v_18 = (pub_r000757_9 + 13) & 127;
        }
    } else {
        stage_v_18 = (pub_r000757_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((sec_r000757_2 & 1) != 0) {
        if ((sec_r000757_14 & 2) != 0) {
            stage_v_19 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_19 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_19 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_20 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_20 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_20 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_21 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000757_18 & 2) != 0) {
            stage_v_22 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((sec_r000757_7 & 1) != 0) {
        if ((sec_r000757_9 & 2) != 0) {
            stage_v_23 = (pub_r000757_16 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000757_16 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000757_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000757_11 & 2) != 0) {
            stage_v_24 = (pub_r000757_13 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000757_13 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000757_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000757_4 & 2) != 0) {
            stage_v_25 = (pub_r000757_16 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000757_16 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000757_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000757_6 & 2) != 0) {
            stage_v_26 = (pub_r000757_7 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000757_7 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000757_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((sec_r000757_16 & 1) != 0) {
        if ((sec_r000757_14 & 2) != 0) {
            stage_v_27 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_28 = (pub_r000757_18 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000757_18 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000757_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_29 = (pub_r000757_11 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000757_11 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000757_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000757_9 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_30 = (pub_r000757_19 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000757_19 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000757_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000757_11 & 2) != 0) {
            stage_v_31 = (pub_r000757_10 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000757_10 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000757_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((sec_r000757_5 & 1) != 0) {
        if ((sec_r000757_15 & 2) != 0) {
            stage_v_32 = (pub_r000757_5 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000757_5 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000757_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_33 = (pub_r000757_13 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000757_13 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000757_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_34 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000757_16 & 2) != 0) {
            stage_v_35 = (pub_r000757_9 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000757_9 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000757_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_17 & 1) != 0) {
        if ((sec_r000757_5 & 2) != 0) {
            stage_v_36 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000757_15 & 2) != 0) {
            stage_v_37 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_38 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_39 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000757_5 & 2) != 0) {
            stage_v_40 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_41 = (pub_r000757_15 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000757_15 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000757_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000757_16 & 2) != 0) {
            stage_v_42 = (pub_r000757_3 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000757_3 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000757_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_43 = (pub_r000757_11 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000757_11 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000757_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000757_18 & 2) != 0) {
            stage_v_44 = (pub_r000757_5 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000757_5 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000757_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000757_14 & 2) != 0) {
            stage_v_45 = (pub_r000757_14 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000757_14 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000757_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_46 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((sec_r000757_7 & 1) != 0) {
        if ((sec_r000757_6 & 2) != 0) {
            stage_v_47 = (pub_r000757_15 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000757_15 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000757_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_48 = (pub_r000757_15 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000757_15 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000757_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((sec_r000757_3 & 1) != 0) {
        if ((sec_r000757_17 & 2) != 0) {
            stage_v_49 = (pub_r000757_7 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000757_7 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000757_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000757_5 & 2) != 0) {
            stage_v_50 = (pub_r000757_7 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000757_7 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000757_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000757_9 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_51 = (pub_r000757_15 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000757_15 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000757_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_52 = (pub_r000757_11 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000757_11 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000757_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000757_4 & 2) != 0) {
            stage_v_53 = (pub_r000757_0 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000757_0 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000757_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000757_3 & 2) != 0) {
            stage_v_54 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((stage_v_51 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_55 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000757_12 & 2) != 0) {
            stage_v_56 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((sec_r000757_5 & 1) != 0) {
        if ((sec_r000757_4 & 2) != 0) {
            stage_v_57 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_36 & 1) != 0) {
        if ((sec_r000757_11 & 2) != 0) {
            stage_v_58 = (pub_r000757_16 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000757_16 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000757_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_59 = (pub_r000757_19 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000757_19 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000757_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000757_5 & 2) != 0) {
            stage_v_60 = (pub_r000757_7 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000757_7 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000757_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((sec_r000757_19 & 1) != 0) {
        if ((sec_r000757_17 & 2) != 0) {
            stage_v_61 = (pub_r000757_16 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000757_16 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000757_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000757_8 & 1) != 0) {
        if ((sec_r000757_5 & 2) != 0) {
            stage_v_62 = (pub_r000757_0 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000757_0 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000757_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((sec_r000757_13 & 1) != 0) {
        if ((sec_r000757_10 & 2) != 0) {
            stage_v_63 = (pub_r000757_2 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000757_2 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000757_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000757_17 & 1) != 0) {
        if ((sec_r000757_18 & 2) != 0) {
            stage_v_64 = (pub_r000757_18 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000757_18 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000757_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_40 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_65 = (pub_r000757_6 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000757_6 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000757_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_66 = (pub_r000757_16 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000757_16 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000757_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_67 = (pub_r000757_11 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000757_11 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000757_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000757_17 & 2) != 0) {
            stage_v_68 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000757_14 & 2) != 0) {
            stage_v_69 = (pub_r000757_6 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000757_6 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000757_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_70 = (pub_r000757_18 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000757_18 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000757_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_71 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((sec_r000757_6 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_72 = (pub_r000757_13 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000757_13 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000757_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_39 & 1) != 0) {
        if ((sec_r000757_17 & 2) != 0) {
            stage_v_73 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000757_16 & 2) != 0) {
            stage_v_74 = (pub_r000757_6 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000757_6 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000757_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_75 = (pub_r000757_10 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000757_10 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000757_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000757_3 & 2) != 0) {
            stage_v_76 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000757_14 & 2) != 0) {
            stage_v_77 = (pub_r000757_5 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000757_5 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000757_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000757_12 & 1) != 0) {
        if ((sec_r000757_12 & 2) != 0) {
            stage_v_78 = (pub_r000757_9 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000757_9 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000757_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000757_16 & 1) != 0) {
        if ((sec_r000757_10 & 2) != 0) {
            stage_v_79 = (pub_r000757_9 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000757_9 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000757_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000757_8 & 2) != 0) {
            stage_v_80 = (pub_r000757_13 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000757_13 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000757_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000757_14 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_81 = (pub_r000757_4 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000757_4 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000757_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000757_13 & 1) != 0) {
        if ((sec_r000757_7 & 2) != 0) {
            stage_v_82 = (pub_r000757_17 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000757_17 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000757_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((sec_r000757_13 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_83 = (pub_r000757_18 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000757_18 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000757_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000757_6 & 2) != 0) {
            stage_v_84 = (pub_r000757_19 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000757_19 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000757_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((sec_r000757_11 & 1) != 0) {
        if ((sec_r000757_15 & 2) != 0) {
            stage_v_85 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((sec_r000757_9 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_86 = (pub_r000757_5 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000757_5 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000757_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000757_18 & 2) != 0) {
            stage_v_87 = (pub_r000757_7 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000757_7 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000757_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000757_5 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_88 = (pub_r000757_0 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000757_0 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000757_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((sec_r000757_15 & 1) != 0) {
        if ((sec_r000757_10 & 2) != 0) {
            stage_v_89 = (pub_r000757_13 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000757_13 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000757_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_90 = (pub_r000757_15 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000757_15 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000757_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000757_3 & 2) != 0) {
            stage_v_91 = (pub_r000757_8 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000757_8 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000757_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_92 = (pub_r000757_1 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000757_1 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000757_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000757_17 & 2) != 0) {
            stage_v_93 = (pub_r000757_4 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000757_4 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000757_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000757_0 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_94 = (pub_r000757_2 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000757_2 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000757_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000757_8 & 2) != 0) {
            stage_v_95 = (pub_r000757_11 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000757_11 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000757_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((sec_r000757_17 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_96 = (pub_r000757_10 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000757_10 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000757_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000757_13 & 2) != 0) {
            stage_v_97 = (pub_r000757_7 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000757_7 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000757_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000757_9 & 2) != 0) {
            stage_v_98 = (pub_r000757_10 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000757_10 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000757_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((sec_r000757_10 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_99 = (pub_r000757_8 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000757_8 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000757_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_53 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_100 = (pub_r000757_0 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000757_0 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000757_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((sec_r000757_19 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_101 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_102 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000757_0 & 2) != 0) {
            stage_v_103 = (pub_r000757_8 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000757_8 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000757_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_104 = (pub_r000757_11 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000757_11 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000757_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000757_11 & 1) != 0) {
        if ((sec_r000757_3 & 2) != 0) {
            stage_v_105 = (pub_r000757_13 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000757_13 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000757_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000757_13 & 1) != 0) {
        if ((sec_r000757_18 & 2) != 0) {
            stage_v_106 = (pub_r000757_12 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000757_12 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000757_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000757_19 & 2) != 0) {
            stage_v_107 = (pub_r000757_5 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000757_5 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000757_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000757_1 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_108 = (pub_r000757_19 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000757_19 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000757_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_109 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000757_16 & 2) != 0) {
            stage_v_110 = (pub_r000757_14 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000757_14 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000757_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000757_1 & 2) != 0) {
            stage_v_111 = (pub_r000757_2 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000757_2 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000757_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((sec_r000757_9 & 1) != 0) {
        if ((sec_r000757_4 & 2) != 0) {
            stage_v_112 = (pub_r000757_20 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000757_20 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000757_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_55 & 1) != 0) {
        if ((sec_r000757_2 & 2) != 0) {
            stage_v_113 = (pub_r000757_18 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000757_18 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000757_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000757_7 & 1) != 0) {
        if ((sec_r000757_8 & 2) != 0) {
            stage_v_114 = (pub_r000757_4 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000757_4 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000757_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((sec_r000757_14 & 1) != 0) {
        if ((sec_r000757_9 & 2) != 0) {
            stage_v_115 = (pub_r000757_3 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000757_3 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000757_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000757_5 & 2) != 0) {
            stage_v_116 = (pub_r000757_15 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000757_15 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000757_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
