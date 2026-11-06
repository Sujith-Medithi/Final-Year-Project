/*
 * Benchmark Program: R000526
 * Security Family: implicit_flow
 * Generator Seed: 552613
 * High Inputs: 20 | Low Inputs: 22
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000526_2613_0 {
    short balance;
    unsigned char fee;
    int account_id;
    int auth_code;
    short status;
    int buffer[3];
};

struct CipherContext_R000526_2613_1 {
    int counter;
    int nonce;
    short flags;
    int buffer[3];
};

struct SensorNode_R000526_2613_2 {
    int status;
    short gain;
    unsigned char calib;
    unsigned char offset;
    int threshold;
    int buffer[3];
};

union PacketPayload_R000526_2613_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union ColorPixel_R000526_2613_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000526_2613_0(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000526_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int metric_27 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_27 > 24) {
        acc = (acc + metric_27 * 2 + 5) & 127;
        aux ^= (metric_27 & 15);
    } else {
        acc = (acc - metric_27 + 11) & 127;
        aux += 3;
    }
    int vector_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_95) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000526_2613_1(int p0, int p1, int p2) {
    int acc = (p0 + 8) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000526_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int margin_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_51) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int window_78 = local_arr[aux % 3];
    acc = (acc + window_78 * 2) & 127;
    int tally_69 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_69 > 18) {
        acc = (acc + tally_69 * 2 + 5) & 127;
        aux ^= (tally_69 & 15);
    } else {
        acc = (acc - tally_69 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_2(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000526_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int metric_88 = (aux + st.buffer[1]) & 3;
    switch (metric_88) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int coefficient_97 = local_arr[aux % 3];
    acc = (acc + coefficient_97 * 2) & 127;
    int quantum_50 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_50) & 63;
    acc ^= aux;
    int sample_44 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_44 > 37) {
        acc = (acc + sample_44 * 2 + 5) & 127;
        aux ^= (sample_44 & 15);
    } else {
        acc = (acc - sample_44 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_3(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000526_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int local_arr[3] = {4, 9, 15};
    int tracker_45 = local_arr[aux % 3];
    acc = (acc + tracker_45 * 2) & 127;
    int tracker_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_40 > 25) {
        acc = (acc + tracker_40 * 2 + 5) & 127;
        aux ^= (tracker_40 & 15);
    } else {
        acc = (acc - tracker_40 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int weight_70 = (aux + st.buffer[1]) & 3;
    switch (weight_70) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_4(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000526_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int tracker_38 = local_arr[aux % 3];
    acc = (acc + tracker_38 * 2) & 127;
    int quotient_91 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_91 > 48) {
        acc = (acc + quotient_91 * 2 + 5) & 127;
        aux ^= (quotient_91 & 15);
    } else {
        acc = (acc - quotient_91 + 11) & 127;
        aux += 3;
    }
    int mask_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + mask_25) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000526_2613_5(int p0, int p1, int p2) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000526_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int parity_78 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_78 > 11) {
        acc = (acc + parity_78 * 2 + 5) & 127;
        aux ^= (parity_78 & 15);
    } else {
        acc = (acc - parity_78 + 11) & 127;
        aux += 3;
    }
    int mask_61 = (aux + st.buffer[1]) & 3;
    switch (mask_61) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000526_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int cursor_90 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_90 > 28) {
        acc = (acc + cursor_90 * 2 + 5) & 127;
        aux ^= (cursor_90 & 15);
    } else {
        acc = (acc - cursor_90 + 11) & 127;
        aux += 3;
    }
    int scale_72 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_72) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000526_2613_7(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000526_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int offset_64 = local_arr[aux % 3];
    acc = (acc + offset_64 * 2) & 127;
    int quantum_11 = (aux + st.buffer[1]) & 3;
    switch (quantum_11) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_8(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000526_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int segment_55 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_55 > 38) {
        acc = (acc + segment_55 * 2 + 5) & 127;
        aux ^= (segment_55 & 15);
    } else {
        acc = (acc - segment_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int delta_52 = local_arr[aux % 3];
    acc = (acc + delta_52 * 2) & 127;
    int cursor_38 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + cursor_38) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000526_2613_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000526_2613_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int quotient_14 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_14 > 46) {
        acc = (acc + quotient_14 * 2 + 5) & 127;
        aux ^= (quotient_14 & 15);
    } else {
        acc = (acc - quotient_14 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quantum_89 = (aux + st.buffer[1]) & 3;
    switch (quantum_89) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_61 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_61) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000526_2613_10(int p0, int p1) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000526_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int residue_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_54) & 63;
    acc ^= aux;
    int residue_12 = (aux + st.buffer[1]) & 3;
    switch (residue_12) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_93 = local_arr[aux % 3];
    acc = (acc + window_93 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000526_2613_11(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct SensorNode_R000526_2613_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int phase_29 = (aux + st.buffer[1]) & 3;
    switch (phase_29) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_12(int p0, int p1) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000526_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int metric_75 = local_arr[aux % 3];
    acc = (acc + metric_75 * 2) & 127;
    int mask_83 = (st.buffer[0] * 3 + aux) & 63;
    if (mask_83 > 46) {
        acc = (acc + mask_83 * 2 + 5) & 127;
        aux ^= (mask_83 & 15);
    } else {
        acc = (acc - mask_83 + 11) & 127;
        aux += 3;
    }
    int damping_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_33) & 63;
    acc ^= aux;
    int bound_16 = (aux + st.buffer[1]) & 3;
    switch (bound_16) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000526_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_10 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_10 > 29) {
        acc = (acc + accumulator_10 * 2 + 5) & 127;
        aux ^= (accumulator_10 & 15);
    } else {
        acc = (acc - accumulator_10 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int phase_24 = local_arr[aux % 3];
    acc = (acc + phase_24 * 2) & 127;
    int stride_62 = (aux + st.buffer[1]) & 3;
    switch (stride_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000526_2613_14(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000526_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int checksum_51 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_51 > 23) {
        acc = (acc + checksum_51 * 2 + 5) & 127;
        aux ^= (checksum_51 & 15);
    } else {
        acc = (acc - checksum_51 + 11) & 127;
        aux += 3;
    }
    int margin_66 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_66) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int scale_17 = local_arr[aux % 3];
    acc = (acc + scale_17 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000526_2613_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000526_2613_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int index_reg_12 = local_arr[aux % 3];
    acc = (acc + index_reg_12 * 2) & 127;
    int parity_62 = (aux + st.buffer[1]) & 3;
    switch (parity_62) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000526_0;
    int sec_r000526_1;
    int sec_r000526_2;
    int sec_r000526_3;
    int sec_r000526_4;
    int sec_r000526_5;
    int sec_r000526_6;
    int sec_r000526_7;
    int sec_r000526_8;
    int sec_r000526_9;
    int sec_r000526_10;
    int sec_r000526_11;
    int sec_r000526_12;
    int sec_r000526_13;
    int sec_r000526_14;
    int sec_r000526_15;
    int sec_r000526_16;
    int sec_r000526_17;
    int sec_r000526_18;
    int sec_r000526_19;
    int pub_r000526_0;
    int pub_r000526_1;
    int pub_r000526_2;
    int pub_r000526_3;
    int pub_r000526_4;
    int pub_r000526_5;
    int pub_r000526_6;
    int pub_r000526_7;
    int pub_r000526_8;
    int pub_r000526_9;
    int pub_r000526_10;
    int pub_r000526_11;
    int pub_r000526_12;
    int pub_r000526_13;
    int pub_r000526_14;
    int pub_r000526_15;
    int pub_r000526_16;
    int pub_r000526_17;
    int pub_r000526_18;
    int pub_r000526_19;
    int pub_r000526_20;
    int pub_r000526_21;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000526_0 >= -100 && pub_r000526_0 <= 100);
    __CPROVER_assume(pub_r000526_1 >= -100 && pub_r000526_1 <= 100);
    __CPROVER_assume(pub_r000526_2 >= -100 && pub_r000526_2 <= 100);
    __CPROVER_assume(pub_r000526_3 >= -100 && pub_r000526_3 <= 100);
    __CPROVER_assume(pub_r000526_4 >= -100 && pub_r000526_4 <= 100);
    __CPROVER_assume(pub_r000526_5 >= -100 && pub_r000526_5 <= 100);
    __CPROVER_assume(pub_r000526_6 >= -100 && pub_r000526_6 <= 100);
    __CPROVER_assume(pub_r000526_7 >= -100 && pub_r000526_7 <= 100);
    __CPROVER_assume(pub_r000526_8 >= -100 && pub_r000526_8 <= 100);
    __CPROVER_assume(pub_r000526_9 >= -100 && pub_r000526_9 <= 100);
    __CPROVER_assume(pub_r000526_10 >= -100 && pub_r000526_10 <= 100);
    __CPROVER_assume(pub_r000526_11 >= -100 && pub_r000526_11 <= 100);
    __CPROVER_assume(pub_r000526_12 >= -100 && pub_r000526_12 <= 100);
    __CPROVER_assume(pub_r000526_13 >= -100 && pub_r000526_13 <= 100);
    __CPROVER_assume(pub_r000526_14 >= -100 && pub_r000526_14 <= 100);
    __CPROVER_assume(pub_r000526_15 >= -100 && pub_r000526_15 <= 100);
    __CPROVER_assume(pub_r000526_16 >= -100 && pub_r000526_16 <= 100);
    __CPROVER_assume(pub_r000526_17 >= -100 && pub_r000526_17 <= 100);
    __CPROVER_assume(pub_r000526_18 >= -100 && pub_r000526_18 <= 100);
    __CPROVER_assume(pub_r000526_19 >= -100 && pub_r000526_19 <= 100);
    __CPROVER_assume(pub_r000526_20 >= -100 && pub_r000526_20 <= 100);
    __CPROVER_assume(pub_r000526_21 >= -100 && pub_r000526_21 <= 100);
    __CPROVER_assume(sec_r000526_0 >= 0 && sec_r000526_0 <= 255);
    __CPROVER_assume(sec_r000526_1 >= 0 && sec_r000526_1 <= 255);
    __CPROVER_assume(sec_r000526_2 >= 0 && sec_r000526_2 <= 255);
    __CPROVER_assume(sec_r000526_3 >= 0 && sec_r000526_3 <= 255);
    __CPROVER_assume(sec_r000526_4 >= 0 && sec_r000526_4 <= 255);
    __CPROVER_assume(sec_r000526_5 >= 0 && sec_r000526_5 <= 255);
    __CPROVER_assume(sec_r000526_6 >= 0 && sec_r000526_6 <= 255);
    __CPROVER_assume(sec_r000526_7 >= 0 && sec_r000526_7 <= 255);
    __CPROVER_assume(sec_r000526_8 >= 0 && sec_r000526_8 <= 255);
    __CPROVER_assume(sec_r000526_9 >= 0 && sec_r000526_9 <= 255);
    __CPROVER_assume(sec_r000526_10 >= 0 && sec_r000526_10 <= 255);
    __CPROVER_assume(sec_r000526_11 >= 0 && sec_r000526_11 <= 255);
    __CPROVER_assume(sec_r000526_12 >= 0 && sec_r000526_12 <= 255);
    __CPROVER_assume(sec_r000526_13 >= 0 && sec_r000526_13 <= 255);
    __CPROVER_assume(sec_r000526_14 >= 0 && sec_r000526_14 <= 255);
    __CPROVER_assume(sec_r000526_15 >= 0 && sec_r000526_15 <= 255);
    __CPROVER_assume(sec_r000526_16 >= 0 && sec_r000526_16 <= 255);
    __CPROVER_assume(sec_r000526_17 >= 0 && sec_r000526_17 <= 255);
    __CPROVER_assume(sec_r000526_18 >= 0 && sec_r000526_18 <= 255);
    __CPROVER_assume(sec_r000526_19 >= 0 && sec_r000526_19 <= 255);

    struct Transaction_R000526_2613_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000526_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000526_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000526_0 + 7) & 15;
    struct CipherContext_R000526_2613_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000526_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000526_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000526_0 + 9) & 15;
    struct SensorNode_R000526_2613_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000526_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000526_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000526_0 + 11) & 15;

    union PacketPayload_R000526_2613_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] * 2 + 7) & 63;
    if (stage_v_0 > 40) {
        out_sink = (out_sink + stage_v_0 - 5) & 255;
        if (stage_v_0 > 55) {
            chk_sum ^= (stage_v_0 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_0 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 16) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 31) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = table[3];
    table[3] = (table[0] + 7) & 63;
    out_sink = (out_sink + stage_v_3) & 255;

    /* Execution Pipeline Stage 4 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 5) & 15;
    int stage_v_4 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_4) & 255;
    chk_sum ^= stage_v_4;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_5 = (stage_v_5 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_5) & 127;
    }
    out_sink = (out_sink + stage_v_5) & 255;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 29) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 44) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_8 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_9 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_12 = (stage_v_12 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_12) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;

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
    int stage_v_14 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_14 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_17 = (stage_v_17 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_17) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (st_var_0.buffer[0] ^ 21) & 3;
    switch (stage_v_18) {
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

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = table[0];
    table[0] = (table[1] + 41) & 63;
    out_sink = (out_sink + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = table[1];
    table[1] = (table[2] + 43) & 63;
    out_sink = (out_sink + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_22 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (st_var_2.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 17) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 32) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_24 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_25 = (stage_v_25 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_25) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_27 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (st_var_1.buffer[1] * 2 + 91) & 63;
    if (stage_v_28 > 32) {
        out_sink = (out_sink + stage_v_28 - 5) & 255;
        if (stage_v_28 > 47) {
            chk_sum ^= (stage_v_28 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_28 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (st_var_2.buffer[0] ^ 32) & 3;
    switch (stage_v_29) {
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

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (st_var_0.buffer[0] * 2 + 97) & 63;
    if (stage_v_30 > 30) {
        out_sink = (out_sink + stage_v_30 - 5) & 255;
        if (stage_v_30 > 45) {
            chk_sum ^= (stage_v_30 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_30 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (out_sink > 100) ? (chk_sum & 31) : (36 & 31);
    out_sink = (out_sink + stage_v_31) & 255;
    chk_sum ^= (stage_v_31 << 1) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_32 = (stage_v_32 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_32) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = table[1];
    table[1] = (table[2] + 67) & 63;
    out_sink = (out_sink + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (st_var_1.buffer[0] ^ 37) & 3;
    switch (stage_v_34) {
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

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = table[0];
    table[0] = (table[1] + 73) & 63;
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (out_sink > 100) ? (chk_sum & 31) : (44 & 31);
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= (stage_v_39 << 1) & 127;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_40 = (stage_v_40 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_40) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (out_sink > 100) ? (chk_sum & 31) : (47 & 31);
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= (stage_v_42 << 1) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = table[3];
    table[3] = (table[0] + 87) & 63;
    out_sink = (out_sink + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 35) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 50) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (st_var_0.buffer[0] ^ 48) & 3;
    switch (stage_v_45) {
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

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (st_var_1.buffer[0] ^ 49) & 3;
    switch (stage_v_46) {
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

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_48 = (stage_v_48 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_48) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_49 = (stage_v_49 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_49) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 36) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 51) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 52) & 15;
    int stage_v_51 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_51) & 255;
    chk_sum ^= stage_v_51;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_53 = (stage_v_53 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_53) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (out_sink > 100) ? (chk_sum & 31) : (59 & 31);
    out_sink = (out_sink + stage_v_54) & 255;
    chk_sum ^= (stage_v_54 << 1) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (out_sink > 100) ? (chk_sum & 31) : (60 & 31);
    out_sink = (out_sink + stage_v_55) & 255;
    chk_sum ^= (stage_v_55 << 1) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (st_var_1.buffer[0] ^ 61) & 3;
    switch (stage_v_58) {
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

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (st_var_2.buffer[0] ^ 62) & 3;
    switch (stage_v_59) {
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

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = table[3];
    table[3] = (table[0] + 127) & 63;
    out_sink = (out_sink + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (out_sink > 100) ? (chk_sum & 31) : (69 & 31);
    out_sink = (out_sink + stage_v_64) & 255;
    chk_sum ^= (stage_v_64 << 1) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (out_sink > 100) ? (chk_sum & 31) : (71 & 31);
    out_sink = (out_sink + stage_v_66) & 255;
    chk_sum ^= (stage_v_66 << 1) & 127;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[1] * 2 + 208) & 63;
    if (stage_v_67 > 40) {
        out_sink = (out_sink + stage_v_67 - 5) & 255;
        if (stage_v_67 > 55) {
            chk_sum ^= (stage_v_67 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_67 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (st_var_2.buffer[0] ^ 71) & 3;
    switch (stage_v_68) {
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

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_69 = (stage_v_69 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_69) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 71) & 15;
    int stage_v_70 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_70) & 255;
    chk_sum ^= stage_v_70;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_71 = (stage_v_71 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_71) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_72 = (stage_v_72 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_72) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000526_2 & 63) > 55) {
        stage_v_74 = (pub_r000526_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_74) & 255;
    } else {
        stage_v_74 = (pub_r000526_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_74 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_74 & 63) > 28) {
        stage_v_75 = (pub_r000526_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_75) & 255;
    } else {
        stage_v_75 = (pub_r000526_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_75 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_74 & 63) > 30) {
        stage_v_76 = (pub_r000526_18 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_76) & 255;
    } else {
        stage_v_76 = (pub_r000526_18 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_76 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_75 & 63) > 35) {
        stage_v_77 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_77) & 255;
    } else {
        stage_v_77 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_77 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000526_17 & 63) > 44) {
        stage_v_78 = (pub_r000526_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_78) & 255;
    } else {
        stage_v_78 = (pub_r000526_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_78 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_75 & 63) > 45) {
        stage_v_79 = (pub_r000526_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_79) & 255;
    } else {
        stage_v_79 = (pub_r000526_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_79 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000526_5 & 63) > 23) {
        stage_v_80 = (pub_r000526_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_80) & 255;
    } else {
        stage_v_80 = (pub_r000526_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_80 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((sec_r000526_7 & 63) > 20) {
        stage_v_81 = (pub_r000526_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_81) & 255;
    } else {
        stage_v_81 = (pub_r000526_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_81 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_75 & 63) > 15) {
        stage_v_82 = (pub_r000526_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_82) & 255;
    } else {
        stage_v_82 = (pub_r000526_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_82 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_78 & 63) > 51) {
        stage_v_83 = (pub_r000526_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_83) & 255;
    } else {
        stage_v_83 = (pub_r000526_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_83 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000526_12 & 63) > 43) {
        stage_v_84 = (pub_r000526_21 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_84) & 255;
    } else {
        stage_v_84 = (pub_r000526_21 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_84 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_84 & 63) > 27) {
        stage_v_85 = (pub_r000526_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_85) & 255;
    } else {
        stage_v_85 = (pub_r000526_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_85 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_82 & 63) > 46) {
        stage_v_86 = (pub_r000526_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_86) & 255;
    } else {
        stage_v_86 = (pub_r000526_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_86 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000526_8 & 63) > 22) {
        stage_v_87 = (pub_r000526_21 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_87) & 255;
    } else {
        stage_v_87 = (pub_r000526_21 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_87 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_80 & 63) > 16) {
        stage_v_88 = (pub_r000526_21 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_88) & 255;
    } else {
        stage_v_88 = (pub_r000526_21 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_88 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_82 & 63) > 31) {
        stage_v_89 = (pub_r000526_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_89) & 255;
    } else {
        stage_v_89 = (pub_r000526_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_89 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((stage_v_83 & 63) > 16) {
        stage_v_90 = (pub_r000526_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_90) & 255;
    } else {
        stage_v_90 = (pub_r000526_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_90 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_77 & 63) > 56) {
        stage_v_91 = (pub_r000526_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_91) & 255;
    } else {
        stage_v_91 = (pub_r000526_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_91 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((sec_r000526_3 & 63) > 45) {
        stage_v_92 = (pub_r000526_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_92) & 255;
    } else {
        stage_v_92 = (pub_r000526_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_92 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_81 & 63) > 18) {
        stage_v_93 = (pub_r000526_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_93) & 255;
    } else {
        stage_v_93 = (pub_r000526_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_93 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((sec_r000526_3 & 63) > 53) {
        stage_v_94 = (pub_r000526_18 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_94) & 255;
    } else {
        stage_v_94 = (pub_r000526_18 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_94 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_91 & 63) > 36) {
        stage_v_95 = (pub_r000526_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_95) & 255;
    } else {
        stage_v_95 = (pub_r000526_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_95 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_77 & 63) > 36) {
        stage_v_96 = (pub_r000526_11 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_96) & 255;
    } else {
        stage_v_96 = (pub_r000526_11 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_96 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_85 & 63) > 53) {
        stage_v_97 = (pub_r000526_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_97) & 255;
    } else {
        stage_v_97 = (pub_r000526_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_97 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000526_2 & 63) > 25) {
        stage_v_98 = (pub_r000526_4 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_98) & 255;
    } else {
        stage_v_98 = (pub_r000526_4 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_98 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_89 & 63) > 19) {
        stage_v_99 = (pub_r000526_19 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_99) & 255;
    } else {
        stage_v_99 = (pub_r000526_19 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_99 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_83 & 63) > 43) {
        stage_v_100 = (pub_r000526_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_100) & 255;
    } else {
        stage_v_100 = (pub_r000526_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_100 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_78 & 63) > 42) {
        stage_v_101 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_101) & 255;
    } else {
        stage_v_101 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_101 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_94 & 63) > 41) {
        stage_v_102 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_102) & 255;
    } else {
        stage_v_102 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_102 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_86 & 63) > 23) {
        stage_v_103 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_103) & 255;
    } else {
        stage_v_103 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_103 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_103 & 63) > 54) {
        stage_v_104 = (pub_r000526_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_104) & 255;
    } else {
        stage_v_104 = (pub_r000526_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_104 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((sec_r000526_17 & 63) > 22) {
        stage_v_105 = (pub_r000526_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_105) & 255;
    } else {
        stage_v_105 = (pub_r000526_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_105 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((sec_r000526_1 & 63) > 28) {
        stage_v_106 = (pub_r000526_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_106) & 255;
    } else {
        stage_v_106 = (pub_r000526_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_106 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_95 & 63) > 27) {
        stage_v_107 = (pub_r000526_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_107) & 255;
    } else {
        stage_v_107 = (pub_r000526_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_107 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000526_14 & 63) > 22) {
        stage_v_108 = (pub_r000526_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_108) & 255;
    } else {
        stage_v_108 = (pub_r000526_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_108 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_84 & 63) > 59) {
        stage_v_109 = (pub_r000526_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_109) & 255;
    } else {
        stage_v_109 = (pub_r000526_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_109 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_95 & 63) > 46) {
        stage_v_110 = (pub_r000526_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_110) & 255;
    } else {
        stage_v_110 = (pub_r000526_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_110 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_80 & 63) > 54) {
        stage_v_111 = (pub_r000526_19 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_111) & 255;
    } else {
        stage_v_111 = (pub_r000526_19 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_111 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_97 & 63) > 33) {
        stage_v_112 = (pub_r000526_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_112) & 255;
    } else {
        stage_v_112 = (pub_r000526_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_112 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_99 & 63) > 22) {
        stage_v_113 = (pub_r000526_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_113) & 255;
    } else {
        stage_v_113 = (pub_r000526_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_113 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000526_8 & 63) > 34) {
        stage_v_114 = (pub_r000526_15 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_114) & 255;
    } else {
        stage_v_114 = (pub_r000526_15 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_114 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_109 & 63) > 38) {
        stage_v_115 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_115) & 255;
    } else {
        stage_v_115 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_115 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_82 & 63) > 16) {
        stage_v_116 = (pub_r000526_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_116) & 255;
    } else {
        stage_v_116 = (pub_r000526_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_116 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((sec_r000526_9 & 63) > 25) {
        stage_v_117 = (pub_r000526_19 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_117) & 255;
    } else {
        stage_v_117 = (pub_r000526_19 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_117 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((stage_v_113 & 63) > 21) {
        stage_v_118 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_118) & 255;
    } else {
        stage_v_118 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_118 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_103 & 63) > 40) {
        stage_v_119 = (pub_r000526_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_119) & 255;
    } else {
        stage_v_119 = (pub_r000526_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_119 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((stage_v_75 & 63) > 21) {
        stage_v_120 = (pub_r000526_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_120) & 255;
    } else {
        stage_v_120 = (pub_r000526_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_120 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_113 & 63) > 34) {
        stage_v_121 = (pub_r000526_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_121) & 255;
    } else {
        stage_v_121 = (pub_r000526_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_121 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_80 & 63) > 25) {
        stage_v_122 = (pub_r000526_9 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_122) & 255;
    } else {
        stage_v_122 = (pub_r000526_9 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_122 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_87 & 63) > 23) {
        stage_v_123 = (pub_r000526_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_123) & 255;
    } else {
        stage_v_123 = (pub_r000526_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_123 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((stage_v_83 & 63) > 60) {
        stage_v_124 = (pub_r000526_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_124) & 255;
    } else {
        stage_v_124 = (pub_r000526_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_124 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000526_1 & 63) > 27) {
        stage_v_125 = (pub_r000526_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_125) & 255;
    } else {
        stage_v_125 = (pub_r000526_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_125 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_78 & 63) > 16) {
        stage_v_126 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_126) & 255;
    } else {
        stage_v_126 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_126 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((sec_r000526_16 & 63) > 26) {
        stage_v_127 = (pub_r000526_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_127) & 255;
    } else {
        stage_v_127 = (pub_r000526_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_127 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_113 & 63) > 26) {
        stage_v_128 = (pub_r000526_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_128) & 255;
    } else {
        stage_v_128 = (pub_r000526_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_128 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_102 & 63) > 45) {
        stage_v_129 = (pub_r000526_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_129) & 255;
    } else {
        stage_v_129 = (pub_r000526_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_129 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((stage_v_87 & 63) > 57) {
        stage_v_130 = (pub_r000526_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_130) & 255;
    } else {
        stage_v_130 = (pub_r000526_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_130 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_93 & 63) > 57) {
        stage_v_131 = (pub_r000526_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_131) & 255;
    } else {
        stage_v_131 = (pub_r000526_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_131 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_129 & 63) > 19) {
        stage_v_132 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_132) & 255;
    } else {
        stage_v_132 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_132 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((sec_r000526_5 & 63) > 23) {
        stage_v_133 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_133) & 255;
    } else {
        stage_v_133 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_133 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_130 & 63) > 23) {
        stage_v_134 = (pub_r000526_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_134) & 255;
    } else {
        stage_v_134 = (pub_r000526_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_134 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_95 & 63) > 17) {
        stage_v_135 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_135) & 255;
    } else {
        stage_v_135 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_135 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_90 & 63) > 50) {
        stage_v_136 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_136) & 255;
    } else {
        stage_v_136 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_136 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_117 & 63) > 40) {
        stage_v_137 = (pub_r000526_5 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_137) & 255;
    } else {
        stage_v_137 = (pub_r000526_5 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_137 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000526_16 & 63) > 26) {
        stage_v_138 = (pub_r000526_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_138) & 255;
    } else {
        stage_v_138 = (pub_r000526_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_138 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000526_17 & 63) > 38) {
        stage_v_139 = (pub_r000526_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_139) & 255;
    } else {
        stage_v_139 = (pub_r000526_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_139 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_86 & 63) > 22) {
        stage_v_140 = (pub_r000526_10 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_140) & 255;
    } else {
        stage_v_140 = (pub_r000526_10 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_140 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000526_8 & 63) > 32) {
        stage_v_141 = (pub_r000526_19 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_141) & 255;
    } else {
        stage_v_141 = (pub_r000526_19 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_141 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_86 & 63) > 50) {
        stage_v_142 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_142) & 255;
    } else {
        stage_v_142 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_142 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((sec_r000526_18 & 63) > 58) {
        stage_v_143 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_143) & 255;
    } else {
        stage_v_143 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_143 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_141 & 63) > 45) {
        stage_v_144 = (pub_r000526_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_144) & 255;
    } else {
        stage_v_144 = (pub_r000526_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_144 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_79 & 63) > 37) {
        stage_v_145 = (pub_r000526_18 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_145) & 255;
    } else {
        stage_v_145 = (pub_r000526_18 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_145 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_84 & 63) > 20) {
        stage_v_146 = (pub_r000526_13 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_146) & 255;
    } else {
        stage_v_146 = (pub_r000526_13 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_146 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_107 & 63) > 31) {
        stage_v_147 = (pub_r000526_1 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_147) & 255;
    } else {
        stage_v_147 = (pub_r000526_1 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_147 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((stage_v_109 & 63) > 59) {
        stage_v_148 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_148) & 255;
    } else {
        stage_v_148 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_148 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_97 & 63) > 40) {
        stage_v_149 = (pub_r000526_8 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_149) & 255;
    } else {
        stage_v_149 = (pub_r000526_8 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_149 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((stage_v_79 & 63) > 43) {
        stage_v_150 = (pub_r000526_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_150) & 255;
    } else {
        stage_v_150 = (pub_r000526_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_150 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    if ((stage_v_143 & 63) > 53) {
        stage_v_151 = (pub_r000526_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_151) & 255;
    } else {
        stage_v_151 = (pub_r000526_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_151 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    if ((sec_r000526_17 & 63) > 44) {
        stage_v_152 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_152) & 255;
    } else {
        stage_v_152 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_152 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    if ((stage_v_138 & 63) > 42) {
        stage_v_153 = (pub_r000526_7 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_153) & 255;
    } else {
        stage_v_153 = (pub_r000526_7 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_153 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    if ((stage_v_93 & 63) > 54) {
        stage_v_154 = (pub_r000526_17 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_154) & 255;
    } else {
        stage_v_154 = (pub_r000526_17 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_154 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    if ((stage_v_112 & 63) > 37) {
        stage_v_155 = (pub_r000526_14 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_155) & 255;
    } else {
        stage_v_155 = (pub_r000526_14 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_155 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    if ((sec_r000526_9 & 63) > 48) {
        stage_v_156 = (pub_r000526_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_156) & 255;
    } else {
        stage_v_156 = (pub_r000526_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_156 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    if ((stage_v_121 & 63) > 46) {
        stage_v_157 = (pub_r000526_3 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_157) & 255;
    } else {
        stage_v_157 = (pub_r000526_3 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_157 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    if ((sec_r000526_6 & 63) > 50) {
        stage_v_158 = (pub_r000526_21 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_158) & 255;
    } else {
        stage_v_158 = (pub_r000526_21 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_158 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    if ((stage_v_101 & 63) > 20) {
        stage_v_159 = (pub_r000526_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_159) & 255;
    } else {
        stage_v_159 = (pub_r000526_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_159 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    if ((stage_v_140 & 63) > 32) {
        stage_v_160 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_160) & 255;
    } else {
        stage_v_160 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_160 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    if ((stage_v_132 & 63) > 54) {
        stage_v_161 = (pub_r000526_6 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_161) & 255;
    } else {
        stage_v_161 = (pub_r000526_6 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_161 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    if ((sec_r000526_3 & 63) > 45) {
        stage_v_162 = (pub_r000526_20 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_162) & 255;
    } else {
        stage_v_162 = (pub_r000526_20 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_162 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    if ((sec_r000526_18 & 63) > 46) {
        stage_v_163 = (pub_r000526_12 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_163) & 255;
    } else {
        stage_v_163 = (pub_r000526_12 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_163 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_163) & 255;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    if ((sec_r000526_9 & 63) > 28) {
        stage_v_164 = (pub_r000526_18 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_164) & 255;
    } else {
        stage_v_164 = (pub_r000526_18 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_164 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_164) & 255;

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = 0;
    if ((stage_v_129 & 63) > 39) {
        stage_v_165 = (pub_r000526_16 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_165) & 255;
    } else {
        stage_v_165 = (pub_r000526_16 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_165 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_165) & 255;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    if ((stage_v_155 & 63) > 59) {
        stage_v_166 = (pub_r000526_0 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_166) & 255;
    } else {
        stage_v_166 = (pub_r000526_0 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_166 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_166) & 255;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    if ((stage_v_93 & 63) > 41) {
        stage_v_167 = (pub_r000526_2 * 2 + 15) & 127;
        out_sink = (out_sink + stage_v_167) & 255;
    } else {
        stage_v_167 = (pub_r000526_2 * 3 + 23) & 127;
        out_sink = (out_sink - stage_v_167 + 9) & 255;
    }
    sec_accum = (sec_accum + stage_v_167) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
