/*
 * Benchmark Program: R000528
 * Security Family: secret_dependent_loops
 * Generator Seed: 552813
 * High Inputs: 22 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000528_2813_0 {
    short auth_code;
    int rate;
    unsigned char status;
    short account_id;
    int buffer[3];
};

struct EventLog_R000528_2813_1 {
    int severity;
    short seq;
    short timestamp;
    int buffer[3];
};

struct MatrixBlock_R000528_2813_2 {
    unsigned char scale;
    unsigned char stride;
    int trace;
    int dim;
    short determinant;
    int buffer[3];
};

union TelemetryField_R000528_2813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000528_2813_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000528_2813_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000528_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int checksum_89 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_89 > 28) {
        acc = (acc + checksum_89 * 2 + 5) & 127;
        aux ^= (checksum_89 & 15);
    } else {
        acc = (acc - checksum_89 + 11) & 127;
        aux += 3;
    }
    int damping_65 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_65) & 63;
    acc ^= aux;
    int weight_70 = (aux + st.buffer[1]) & 3;
    switch (weight_70) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000528_2813_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000528_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int local_arr[3] = {4, 9, 15};
    int quantum_44 = local_arr[aux % 3];
    acc = (acc + quantum_44 * 2) & 127;
    int metric_95 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + metric_95) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int anchor_39 = (aux + st.buffer[1]) & 3;
    switch (anchor_39) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000528_2813_2(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int parity_90 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_90) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int phase_21 = local_arr[aux % 3];
    acc = (acc + phase_21 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000528_2813_3(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000528_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int threshold_32 = local_arr[aux % 3];
    acc = (acc + threshold_32 * 2) & 127;
    int phase_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_19) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000528_2813_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int accumulator_99 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_99) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int factor_83 = local_arr[aux % 3];
    acc = (acc + factor_83 * 2) & 127;
    int threshold_36 = (aux + st.buffer[1]) & 3;
    switch (threshold_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000528_2813_5(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_96 = (aux + st.buffer[1]) & 3;
    switch (quotient_96) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000528_2813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int delta_20 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_20 > 19) {
        acc = (acc + delta_20 * 2 + 5) & 127;
        aux ^= (delta_20 & 15);
    } else {
        acc = (acc - delta_20 + 11) & 127;
        aux += 3;
    }
    int tracker_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_71) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000528_2813_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000528_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int parity_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_96) & 63;
    acc ^= aux;
    int sample_58 = (aux + st.buffer[1]) & 3;
    switch (sample_58) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int index_reg_70 = (st.buffer[0] * 3 + aux) & 63;
    if (index_reg_70 > 19) {
        acc = (acc + index_reg_70 * 2 + 5) & 127;
        aux ^= (index_reg_70 & 15);
    } else {
        acc = (acc - index_reg_70 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000528_2813_8(int p0, int p1) {
    int acc = (p0 + 44) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int residue_20 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_20 > 29) {
        acc = (acc + residue_20 * 2 + 5) & 127;
        aux ^= (residue_20 & 15);
    } else {
        acc = (acc - residue_20 + 11) & 127;
        aux += 3;
    }
    int pivot_92 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_92) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int checksum_65 = local_arr[aux % 3];
    acc = (acc + checksum_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000528_2813_9(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000528_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int margin_73 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_73) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_94 = local_arr[aux % 3];
    acc = (acc + tally_94 * 2) & 127;
    int threshold_14 = (aux + st.buffer[1]) & 3;
    switch (threshold_14) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000528_2813_10(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quantum_89 = (aux + st.buffer[1]) & 3;
    switch (quantum_89) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int accumulator_73 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_73 > 21) {
        acc = (acc + accumulator_73 * 2 + 5) & 127;
        aux ^= (accumulator_73 & 15);
    } else {
        acc = (acc - accumulator_73 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000528_2813_11(int p0, int p1) {
    int acc = (p0 + 7) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_56 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_56 > 37) {
        acc = (acc + segment_56 * 2 + 5) & 127;
        aux ^= (segment_56 & 15);
    } else {
        acc = (acc - segment_56 + 11) & 127;
        aux += 3;
    }
    int sample_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_87) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000528_2813_12(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000528_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_36 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_36) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000528_2813_13(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    int segment_99 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_99 > 19) {
        acc = (acc + segment_99 * 2 + 5) & 127;
        aux ^= (segment_99 & 15);
    } else {
        acc = (acc - segment_99 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int sample_15 = local_arr[aux % 3];
    acc = (acc + sample_15 * 2) & 127;
    int scale_50 = (aux + st.buffer[1]) & 3;
    switch (scale_50) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000528_2813_14(int p0, int p1, int p2) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000528_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int quantum_25 = local_arr[aux % 3];
    acc = (acc + quantum_25 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tracker_69 = (aux + st.buffer[1]) & 3;
    switch (tracker_69) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_68 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + delta_68) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000528_2813_15(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000528_2813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_97 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_97 > 25) {
        acc = (acc + phase_97 * 2 + 5) & 127;
        aux ^= (phase_97 & 15);
    } else {
        acc = (acc - phase_97 + 11) & 127;
        aux += 3;
    }
    int bound_59 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + bound_59) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000528_2813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000528_2813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int tally_22 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_22 > 45) {
        acc = (acc + tally_22 * 2 + 5) & 127;
        aux ^= (tally_22 & 15);
    } else {
        acc = (acc - tally_22 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_33 = local_arr[aux % 3];
    acc = (acc + segment_33 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000528_2813_17(int p0, int p1) {
    int acc = (p0 + 31) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000528_2813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int delta_93 = (aux + st.buffer[1]) & 3;
    switch (delta_93) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int checksum_86 = local_arr[aux % 3];
    acc = (acc + checksum_86 * 2) & 127;
    int damping_39 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + damping_39) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000528_0;
    int sec_r000528_1;
    int sec_r000528_2;
    int sec_r000528_3;
    int sec_r000528_4;
    int sec_r000528_5;
    int sec_r000528_6;
    int sec_r000528_7;
    int sec_r000528_8;
    int sec_r000528_9;
    int sec_r000528_10;
    int sec_r000528_11;
    int sec_r000528_12;
    int sec_r000528_13;
    int sec_r000528_14;
    int sec_r000528_15;
    int sec_r000528_16;
    int sec_r000528_17;
    int sec_r000528_18;
    int sec_r000528_19;
    int sec_r000528_20;
    int sec_r000528_21;
    int pub_r000528_0;
    int pub_r000528_1;
    int pub_r000528_2;
    int pub_r000528_3;
    int pub_r000528_4;
    int pub_r000528_5;
    int pub_r000528_6;
    int pub_r000528_7;
    int pub_r000528_8;
    int pub_r000528_9;
    int pub_r000528_10;
    int pub_r000528_11;
    int pub_r000528_12;
    int pub_r000528_13;
    int pub_r000528_14;
    int pub_r000528_15;
    int pub_r000528_16;
    int pub_r000528_17;
    int pub_r000528_18;
    int pub_r000528_19;
    int pub_r000528_20;
    int pub_r000528_21;
    int pub_r000528_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000528_0 >= -100 && pub_r000528_0 <= 100);
    __CPROVER_assume(pub_r000528_1 >= -100 && pub_r000528_1 <= 100);
    __CPROVER_assume(pub_r000528_2 >= -100 && pub_r000528_2 <= 100);
    __CPROVER_assume(pub_r000528_3 >= -100 && pub_r000528_3 <= 100);
    __CPROVER_assume(pub_r000528_4 >= -100 && pub_r000528_4 <= 100);
    __CPROVER_assume(pub_r000528_5 >= -100 && pub_r000528_5 <= 100);
    __CPROVER_assume(pub_r000528_6 >= -100 && pub_r000528_6 <= 100);
    __CPROVER_assume(pub_r000528_7 >= -100 && pub_r000528_7 <= 100);
    __CPROVER_assume(pub_r000528_8 >= -100 && pub_r000528_8 <= 100);
    __CPROVER_assume(pub_r000528_9 >= -100 && pub_r000528_9 <= 100);
    __CPROVER_assume(pub_r000528_10 >= -100 && pub_r000528_10 <= 100);
    __CPROVER_assume(pub_r000528_11 >= -100 && pub_r000528_11 <= 100);
    __CPROVER_assume(pub_r000528_12 >= -100 && pub_r000528_12 <= 100);
    __CPROVER_assume(pub_r000528_13 >= -100 && pub_r000528_13 <= 100);
    __CPROVER_assume(pub_r000528_14 >= -100 && pub_r000528_14 <= 100);
    __CPROVER_assume(pub_r000528_15 >= -100 && pub_r000528_15 <= 100);
    __CPROVER_assume(pub_r000528_16 >= -100 && pub_r000528_16 <= 100);
    __CPROVER_assume(pub_r000528_17 >= -100 && pub_r000528_17 <= 100);
    __CPROVER_assume(pub_r000528_18 >= -100 && pub_r000528_18 <= 100);
    __CPROVER_assume(pub_r000528_19 >= -100 && pub_r000528_19 <= 100);
    __CPROVER_assume(pub_r000528_20 >= -100 && pub_r000528_20 <= 100);
    __CPROVER_assume(pub_r000528_21 >= -100 && pub_r000528_21 <= 100);
    __CPROVER_assume(pub_r000528_22 >= -100 && pub_r000528_22 <= 100);
    __CPROVER_assume(sec_r000528_0 >= 0 && sec_r000528_0 <= 255);
    __CPROVER_assume(sec_r000528_1 >= 0 && sec_r000528_1 <= 255);
    __CPROVER_assume(sec_r000528_2 >= 0 && sec_r000528_2 <= 255);
    __CPROVER_assume(sec_r000528_3 >= 0 && sec_r000528_3 <= 255);
    __CPROVER_assume(sec_r000528_4 >= 0 && sec_r000528_4 <= 255);
    __CPROVER_assume(sec_r000528_5 >= 0 && sec_r000528_5 <= 255);
    __CPROVER_assume(sec_r000528_6 >= 0 && sec_r000528_6 <= 255);
    __CPROVER_assume(sec_r000528_7 >= 0 && sec_r000528_7 <= 255);
    __CPROVER_assume(sec_r000528_8 >= 0 && sec_r000528_8 <= 255);
    __CPROVER_assume(sec_r000528_9 >= 0 && sec_r000528_9 <= 255);
    __CPROVER_assume(sec_r000528_10 >= 0 && sec_r000528_10 <= 255);
    __CPROVER_assume(sec_r000528_11 >= 0 && sec_r000528_11 <= 255);
    __CPROVER_assume(sec_r000528_12 >= 0 && sec_r000528_12 <= 255);
    __CPROVER_assume(sec_r000528_13 >= 0 && sec_r000528_13 <= 255);
    __CPROVER_assume(sec_r000528_14 >= 0 && sec_r000528_14 <= 255);
    __CPROVER_assume(sec_r000528_15 >= 0 && sec_r000528_15 <= 255);
    __CPROVER_assume(sec_r000528_16 >= 0 && sec_r000528_16 <= 255);
    __CPROVER_assume(sec_r000528_17 >= 0 && sec_r000528_17 <= 255);
    __CPROVER_assume(sec_r000528_18 >= 0 && sec_r000528_18 <= 255);
    __CPROVER_assume(sec_r000528_19 >= 0 && sec_r000528_19 <= 255);
    __CPROVER_assume(sec_r000528_20 >= 0 && sec_r000528_20 <= 255);
    __CPROVER_assume(sec_r000528_21 >= 0 && sec_r000528_21 <= 255);

    struct Transaction_R000528_2813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000528_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000528_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000528_0 + 7) & 15;
    struct EventLog_R000528_2813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000528_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000528_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000528_0 + 9) & 15;
    struct MatrixBlock_R000528_2813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000528_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000528_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000528_0 + 11) & 15;

    union TelemetryField_R000528_2813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (out_sink > 100) ? (chk_sum & 31) : (5 & 31);
    out_sink = (out_sink + stage_v_0) & 255;
    chk_sum ^= (stage_v_0 << 1) & 127;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_1 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = table[2];
    table[2] = (table[3] + 5) & 63;
    out_sink = (out_sink + stage_v_2) & 255;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (out_sink > 100) ? (chk_sum & 31) : (8 & 31);
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= (stage_v_3 << 1) & 127;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (st_var_1.buffer[1] * 2 + 19) & 63;
    if (stage_v_4 > 33) {
        out_sink = (out_sink + stage_v_4 - 5) & 255;
        if (stage_v_4 > 48) {
            chk_sum ^= (stage_v_4 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_4 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_5 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 19) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 34) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[1] * 2 + 28) & 63;
    if (stage_v_7 > 24) {
        out_sink = (out_sink + stage_v_7 - 5) & 255;
        if (stage_v_7 > 39) {
            chk_sum ^= (stage_v_7 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_7 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_9 = (stage_v_9 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_9) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_10 = (stage_v_10 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_10) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;

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

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = table[2];
    table[2] = (table[3] + 29) & 63;
    out_sink = (out_sink + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 16) & 15;
    int stage_v_15 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_15) & 255;
    chk_sum ^= stage_v_15;

    /* Execution Pipeline Stage 16 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 17) & 15;
    int stage_v_16 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= stage_v_16;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (st_var_2.buffer[0] ^ 20) & 3;
    switch (stage_v_17) {
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

    /* Execution Pipeline Stage 18 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = table[3];
    table[3] = (table[0] + 39) & 63;
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_20 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 21 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 22) & 15;
    int stage_v_21 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_21) & 255;
    chk_sum ^= stage_v_21;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (st_var_1.buffer[0] ^ 25) & 3;
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
    int stage_v_23 = (st_var_2.buffer[0] ^ 26) & 3;
    switch (stage_v_23) {
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

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (st_var_1.buffer[1] * 2 + 82) & 63;
    if (stage_v_25 > 24) {
        out_sink = (out_sink + stage_v_25 - 5) & 255;
        if (stage_v_25 > 39) {
            chk_sum ^= (stage_v_25 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_25 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (st_var_2.buffer[0] ^ 29) & 3;
    switch (stage_v_26) {
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

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_27 = (stage_v_27 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_27) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_28 = (stage_v_28 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_28) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 30) & 15;
    int stage_v_29 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_29) & 255;
    chk_sum ^= stage_v_29;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_30 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (st_var_1.buffer[1] * 2 + 100) & 63;
    if (stage_v_31 > 31) {
        out_sink = (out_sink + stage_v_31 - 5) & 255;
        if (stage_v_31 > 46) {
            chk_sum ^= (stage_v_31 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_31 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (st_var_0.buffer[0] * 2 + 106) & 63;
    if (stage_v_33 > 25) {
        out_sink = (out_sink + stage_v_33 - 5) & 255;
        if (stage_v_33 > 40) {
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
    int stage_v_35 = table[3];
    table[3] = (table[0] + 71) & 63;
    out_sink = (out_sink + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (out_sink > 100) ? (chk_sum & 31) : (41 & 31);
    out_sink = (out_sink + stage_v_36) & 255;
    chk_sum ^= (stage_v_36 << 1) & 127;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = table[2];
    table[2] = (table[3] + 77) & 63;
    out_sink = (out_sink + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 40) & 15;
    int stage_v_39 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_39) & 255;
    chk_sum ^= stage_v_39;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (out_sink > 100) ? (chk_sum & 31) : (46 & 31);
    out_sink = (out_sink + stage_v_41) & 255;
    chk_sum ^= (stage_v_41 << 1) & 127;

    /* Execution Pipeline Stage 42 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 43) & 15;
    int stage_v_42 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_42) & 255;
    chk_sum ^= stage_v_42;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (out_sink > 100) ? (chk_sum & 31) : (48 & 31);
    out_sink = (out_sink + stage_v_43) & 255;
    chk_sum ^= (stage_v_43 << 1) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (st_var_2.buffer[2] * 2 + 139) & 63;
    if (stage_v_44 > 13) {
        out_sink = (out_sink + stage_v_44 - 5) & 255;
        if (stage_v_44 > 28) {
            chk_sum ^= (stage_v_44 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_44 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 45 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 46) & 15;
    int stage_v_45 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= stage_v_45;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (out_sink > 100) ? (chk_sum & 31) : (51 & 31);
    out_sink = (out_sink + stage_v_46) & 255;
    chk_sum ^= (stage_v_46 << 1) & 127;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = table[3];
    table[3] = (table[0] + 95) & 63;
    out_sink = (out_sink + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (st_var_0.buffer[0] ^ 51) & 3;
    switch (stage_v_48) {
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

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (st_var_1.buffer[0] ^ 52) & 3;
    switch (stage_v_49) {
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

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (st_var_2.buffer[2] * 2 + 157) & 63;
    if (stage_v_50 > 13) {
        out_sink = (out_sink + stage_v_50 - 5) & 255;
        if (stage_v_50 > 28) {
            chk_sum ^= (stage_v_50 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_50 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_1.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (out_sink > 100) ? (chk_sum & 31) : (58 & 31);
    out_sink = (out_sink + stage_v_53) & 255;
    chk_sum ^= (stage_v_53 << 1) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (st_var_0.buffer[0] * 2 + 169) & 63;
    if (stage_v_54 > 21) {
        out_sink = (out_sink + stage_v_54 - 5) & 255;
        if (stage_v_54 > 36) {
            chk_sum ^= (stage_v_54 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_54 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (st_var_1.buffer[0] ^ 58) & 3;
    switch (stage_v_55) {
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

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_0.buffer[0] ^ 60) & 3;
    switch (stage_v_57) {
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

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 59 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 60) & 15;
    int stage_v_59 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_59) & 255;
    chk_sum ^= stage_v_59;

    /* Execution Pipeline Stage 60 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 61) & 15;
    int stage_v_60 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_60) & 255;
    chk_sum ^= stage_v_60;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (st_var_1.buffer[1] * 2 + 190) & 63;
    if (stage_v_61 > 26) {
        out_sink = (out_sink + stage_v_61 - 5) & 255;
        if (stage_v_61 > 41) {
            chk_sum ^= (stage_v_61 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_61 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 62 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 63) & 15;
    int stage_v_62 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_62) & 255;
    chk_sum ^= stage_v_62;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (out_sink > 100) ? (chk_sum & 31) : (68 & 31);
    out_sink = (out_sink + stage_v_63) & 255;
    chk_sum ^= (stage_v_63 << 1) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (st_var_1.buffer[0] ^ 67) & 3;
    switch (stage_v_64) {
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

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_66 = (stage_v_66 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_66) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (st_var_1.buffer[0] ^ 70) & 3;
    switch (stage_v_67) {
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

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = table[0];
    table[0] = (table[1] + 137) & 63;
    out_sink = (out_sink + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (st_var_0.buffer[0] * 2 + 214) & 63;
    if (stage_v_69 > 28) {
        out_sink = (out_sink + stage_v_69 - 5) & 255;
        if (stage_v_69 > 43) {
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
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 72) & 15;
    int stage_v_71 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_71) & 255;
    chk_sum ^= stage_v_71;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (st_var_0.buffer[0] * 2 + 223) & 63;
    if (stage_v_72 > 39) {
        out_sink = (out_sink + stage_v_72 - 5) & 255;
        if (stage_v_72 > 54) {
            chk_sum ^= (stage_v_72 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_72 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (st_var_1.buffer[0] ^ 76) & 3;
    switch (stage_v_73) {
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

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (st_var_2.buffer[0] ^ 77) & 3;
    switch (stage_v_74) {
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

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = table[3];
    table[3] = (table[0] + 151) & 63;
    out_sink = (out_sink + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (out_sink > 100) ? (chk_sum & 31) : (81 & 31);
    out_sink = (out_sink + stage_v_76) & 255;
    chk_sum ^= (stage_v_76 << 1) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (st_var_2.buffer[2] * 2 + 238) & 63;
    if (stage_v_77 > 20) {
        out_sink = (out_sink + stage_v_77 - 5) & 255;
        if (stage_v_77 > 35) {
            chk_sum ^= (stage_v_77 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_77 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_80 = (st_var_2.buffer[0] ^ 83) & 3;
    switch (stage_v_80) {
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

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (st_var_0.buffer[0] ^ 84) & 3;
    switch (stage_v_81) {
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

    /* Execution Pipeline Stage 82 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 83) & 15;
    int stage_v_82 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_82) & 255;
    chk_sum ^= stage_v_82;

    /* Execution Pipeline Stage 83 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 84) & 15;
    int stage_v_83 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_83) & 255;
    chk_sum ^= stage_v_83;

    /* Execution Pipeline Stage 84 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 85) & 15;
    int stage_v_84 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_84) & 255;
    chk_sum ^= stage_v_84;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (st_var_1.buffer[1] * 2 + 262) & 63;
    if (stage_v_85 > 12) {
        out_sink = (out_sink + stage_v_85 - 5) & 255;
        if (stage_v_85 > 27) {
            chk_sum ^= (stage_v_85 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_85 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_4 & 1) == step) {
            stage_v_86 = (stage_v_86 + step * 4 + pub_r000528_6) & 63;
        } else {
            stage_v_86 = (stage_v_86 + pub_r000528_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_86) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_20 & 1) == step) {
            stage_v_87 = (stage_v_87 + step * 4 + pub_r000528_9) & 63;
        } else {
            stage_v_87 = (stage_v_87 + pub_r000528_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_87) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_9 & 1) == step) {
            stage_v_88 = (stage_v_88 + step * 4 + pub_r000528_18) & 63;
        } else {
            stage_v_88 = (stage_v_88 + pub_r000528_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_88) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_1 & 1) == step) {
            stage_v_89 = (stage_v_89 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_89 = (stage_v_89 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_89) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_90 = (stage_v_90 + step * 4 + pub_r000528_15) & 63;
        } else {
            stage_v_90 = (stage_v_90 + pub_r000528_0 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_90) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_89 & 1) == step) {
            stage_v_91 = (stage_v_91 + step * 4 + pub_r000528_3) & 63;
        } else {
            stage_v_91 = (stage_v_91 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_91) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_92 = (stage_v_92 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_92 = (stage_v_92 + pub_r000528_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_92) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_21 & 1) == step) {
            stage_v_93 = (stage_v_93 + step * 4 + pub_r000528_12) & 63;
        } else {
            stage_v_93 = (stage_v_93 + pub_r000528_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_93) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_94 = (stage_v_94 + step * 4 + pub_r000528_9) & 63;
        } else {
            stage_v_94 = (stage_v_94 + pub_r000528_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_94) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_95 = (stage_v_95 + step * 4 + pub_r000528_5) & 63;
        } else {
            stage_v_95 = (stage_v_95 + pub_r000528_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_95) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_9 & 1) == step) {
            stage_v_96 = (stage_v_96 + step * 4 + pub_r000528_3) & 63;
        } else {
            stage_v_96 = (stage_v_96 + pub_r000528_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_96) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_10 & 1) == step) {
            stage_v_97 = (stage_v_97 + step * 4 + pub_r000528_7) & 63;
        } else {
            stage_v_97 = (stage_v_97 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_97) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_2 & 1) == step) {
            stage_v_98 = (stage_v_98 + step * 4 + pub_r000528_20) & 63;
        } else {
            stage_v_98 = (stage_v_98 + pub_r000528_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_98) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_99 = (stage_v_99 + step * 4 + pub_r000528_4) & 63;
        } else {
            stage_v_99 = (stage_v_99 + pub_r000528_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_99) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_7 & 1) == step) {
            stage_v_100 = (stage_v_100 + step * 4 + pub_r000528_19) & 63;
        } else {
            stage_v_100 = (stage_v_100 + pub_r000528_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_100) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_20 & 1) == step) {
            stage_v_101 = (stage_v_101 + step * 4 + pub_r000528_16) & 63;
        } else {
            stage_v_101 = (stage_v_101 + pub_r000528_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_101) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_102 = (stage_v_102 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_102 = (stage_v_102 + pub_r000528_22 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_102) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_7 & 1) == step) {
            stage_v_103 = (stage_v_103 + step * 4 + pub_r000528_17) & 63;
        } else {
            stage_v_103 = (stage_v_103 + pub_r000528_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_103) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_6 & 1) == step) {
            stage_v_104 = (stage_v_104 + step * 4 + pub_r000528_20) & 63;
        } else {
            stage_v_104 = (stage_v_104 + pub_r000528_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_104) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_105 = (stage_v_105 + step * 4 + pub_r000528_10) & 63;
        } else {
            stage_v_105 = (stage_v_105 + pub_r000528_5 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_105) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_106 = (stage_v_106 + step * 4 + pub_r000528_4) & 63;
        } else {
            stage_v_106 = (stage_v_106 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_106) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_12 & 1) == step) {
            stage_v_107 = (stage_v_107 + step * 4 + pub_r000528_8) & 63;
        } else {
            stage_v_107 = (stage_v_107 + pub_r000528_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_107) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_108 = (stage_v_108 + step * 4 + pub_r000528_18) & 63;
        } else {
            stage_v_108 = (stage_v_108 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_108) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_20 & 1) == step) {
            stage_v_109 = (stage_v_109 + step * 4 + pub_r000528_21) & 63;
        } else {
            stage_v_109 = (stage_v_109 + pub_r000528_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_109) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_7 & 1) == step) {
            stage_v_110 = (stage_v_110 + step * 4 + pub_r000528_13) & 63;
        } else {
            stage_v_110 = (stage_v_110 + pub_r000528_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_110) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_14 & 1) == step) {
            stage_v_111 = (stage_v_111 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_111 = (stage_v_111 + pub_r000528_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_111) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_105 & 1) == step) {
            stage_v_112 = (stage_v_112 + step * 4 + pub_r000528_13) & 63;
        } else {
            stage_v_112 = (stage_v_112 + pub_r000528_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_112) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_113 = (stage_v_113 + step * 4 + pub_r000528_20) & 63;
        } else {
            stage_v_113 = (stage_v_113 + pub_r000528_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_113) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_114 = (stage_v_114 + step * 4 + pub_r000528_14) & 63;
        } else {
            stage_v_114 = (stage_v_114 + pub_r000528_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_114) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_15 & 1) == step) {
            stage_v_115 = (stage_v_115 + step * 4 + pub_r000528_1) & 63;
        } else {
            stage_v_115 = (stage_v_115 + pub_r000528_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_115) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_100 & 1) == step) {
            stage_v_116 = (stage_v_116 + step * 4 + pub_r000528_21) & 63;
        } else {
            stage_v_116 = (stage_v_116 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_116) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_117 = (stage_v_117 + step * 4 + pub_r000528_0) & 63;
        } else {
            stage_v_117 = (stage_v_117 + pub_r000528_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_117) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_103 & 1) == step) {
            stage_v_118 = (stage_v_118 + step * 4 + pub_r000528_4) & 63;
        } else {
            stage_v_118 = (stage_v_118 + pub_r000528_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_118) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_6 & 1) == step) {
            stage_v_119 = (stage_v_119 + step * 4 + pub_r000528_21) & 63;
        } else {
            stage_v_119 = (stage_v_119 + pub_r000528_21 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_119) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_7 & 1) == step) {
            stage_v_120 = (stage_v_120 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_120 = (stage_v_120 + pub_r000528_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_120) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_6 & 1) == step) {
            stage_v_121 = (stage_v_121 + step * 4 + pub_r000528_12) & 63;
        } else {
            stage_v_121 = (stage_v_121 + pub_r000528_10 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_121) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_122 = (stage_v_122 + step * 4 + pub_r000528_15) & 63;
        } else {
            stage_v_122 = (stage_v_122 + pub_r000528_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_122) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_12 & 1) == step) {
            stage_v_123 = (stage_v_123 + step * 4 + pub_r000528_1) & 63;
        } else {
            stage_v_123 = (stage_v_123 + pub_r000528_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_123) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_13 & 1) == step) {
            stage_v_124 = (stage_v_124 + step * 4 + pub_r000528_13) & 63;
        } else {
            stage_v_124 = (stage_v_124 + pub_r000528_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_124) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_87 & 1) == step) {
            stage_v_125 = (stage_v_125 + step * 4 + pub_r000528_10) & 63;
        } else {
            stage_v_125 = (stage_v_125 + pub_r000528_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_125) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_116 & 1) == step) {
            stage_v_126 = (stage_v_126 + step * 4 + pub_r000528_22) & 63;
        } else {
            stage_v_126 = (stage_v_126 + pub_r000528_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_126) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_127 = (stage_v_127 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_127 = (stage_v_127 + pub_r000528_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_127) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_126 & 1) == step) {
            stage_v_128 = (stage_v_128 + step * 4 + pub_r000528_5) & 63;
        } else {
            stage_v_128 = (stage_v_128 + pub_r000528_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_128) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_123 & 1) == step) {
            stage_v_129 = (stage_v_129 + step * 4 + pub_r000528_6) & 63;
        } else {
            stage_v_129 = (stage_v_129 + pub_r000528_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_129) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_5 & 1) == step) {
            stage_v_130 = (stage_v_130 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_130 = (stage_v_130 + pub_r000528_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_130) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_93 & 1) == step) {
            stage_v_131 = (stage_v_131 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_131 = (stage_v_131 + pub_r000528_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_131) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_16 & 1) == step) {
            stage_v_132 = (stage_v_132 + step * 4 + pub_r000528_2) & 63;
        } else {
            stage_v_132 = (stage_v_132 + pub_r000528_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_132) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_96 & 1) == step) {
            stage_v_133 = (stage_v_133 + step * 4 + pub_r000528_8) & 63;
        } else {
            stage_v_133 = (stage_v_133 + pub_r000528_15 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_133) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_128 & 1) == step) {
            stage_v_134 = (stage_v_134 + step * 4 + pub_r000528_4) & 63;
        } else {
            stage_v_134 = (stage_v_134 + pub_r000528_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_134) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_88 & 1) == step) {
            stage_v_135 = (stage_v_135 + step * 4 + pub_r000528_6) & 63;
        } else {
            stage_v_135 = (stage_v_135 + pub_r000528_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_135) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_17 & 1) == step) {
            stage_v_136 = (stage_v_136 + step * 4 + pub_r000528_12) & 63;
        } else {
            stage_v_136 = (stage_v_136 + pub_r000528_6 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_136) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_110 & 1) == step) {
            stage_v_137 = (stage_v_137 + step * 4 + pub_r000528_14) & 63;
        } else {
            stage_v_137 = (stage_v_137 + pub_r000528_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_137) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_95 & 1) == step) {
            stage_v_138 = (stage_v_138 + step * 4 + pub_r000528_18) & 63;
        } else {
            stage_v_138 = (stage_v_138 + pub_r000528_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_138) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_106 & 1) == step) {
            stage_v_139 = (stage_v_139 + step * 4 + pub_r000528_3) & 63;
        } else {
            stage_v_139 = (stage_v_139 + pub_r000528_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_139) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_112 & 1) == step) {
            stage_v_140 = (stage_v_140 + step * 4 + pub_r000528_8) & 63;
        } else {
            stage_v_140 = (stage_v_140 + pub_r000528_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_140) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_3 & 1) == step) {
            stage_v_141 = (stage_v_141 + step * 4 + pub_r000528_2) & 63;
        } else {
            stage_v_141 = (stage_v_141 + pub_r000528_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_141) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_20 & 1) == step) {
            stage_v_142 = (stage_v_142 + step * 4 + pub_r000528_8) & 63;
        } else {
            stage_v_142 = (stage_v_142 + pub_r000528_18 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_142) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_130 & 1) == step) {
            stage_v_143 = (stage_v_143 + step * 4 + pub_r000528_11) & 63;
        } else {
            stage_v_143 = (stage_v_143 + pub_r000528_1 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_143) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_115 & 1) == step) {
            stage_v_144 = (stage_v_144 + step * 4 + pub_r000528_20) & 63;
        } else {
            stage_v_144 = (stage_v_144 + pub_r000528_4 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_144) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_11 & 1) == step) {
            stage_v_145 = (stage_v_145 + step * 4 + pub_r000528_21) & 63;
        } else {
            stage_v_145 = (stage_v_145 + pub_r000528_8 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_145) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_146 = (stage_v_146 + step * 4 + pub_r000528_1) & 63;
        } else {
            stage_v_146 = (stage_v_146 + pub_r000528_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_146) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_21 & 1) == step) {
            stage_v_147 = (stage_v_147 + step * 4 + pub_r000528_19) & 63;
        } else {
            stage_v_147 = (stage_v_147 + pub_r000528_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_147) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_11 & 1) == step) {
            stage_v_148 = (stage_v_148 + step * 4 + pub_r000528_0) & 63;
        } else {
            stage_v_148 = (stage_v_148 + pub_r000528_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_148) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_10 & 1) == step) {
            stage_v_149 = (stage_v_149 + step * 4 + pub_r000528_1) & 63;
        } else {
            stage_v_149 = (stage_v_149 + pub_r000528_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_149) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_4 & 1) == step) {
            stage_v_150 = (stage_v_150 + step * 4 + pub_r000528_22) & 63;
        } else {
            stage_v_150 = (stage_v_150 + pub_r000528_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_150) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_91 & 1) == step) {
            stage_v_151 = (stage_v_151 + step * 4 + pub_r000528_7) & 63;
        } else {
            stage_v_151 = (stage_v_151 + pub_r000528_3 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_151) & 127;
    }
    out_sink = (out_sink + stage_v_151) & 255;
    sec_accum = (sec_accum + stage_v_151) & 255;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_4 & 1) == step) {
            stage_v_152 = (stage_v_152 + step * 4 + pub_r000528_10) & 63;
        } else {
            stage_v_152 = (stage_v_152 + pub_r000528_17 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_152) & 127;
    }
    out_sink = (out_sink + stage_v_152) & 255;
    sec_accum = (sec_accum + stage_v_152) & 255;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_6 & 1) == step) {
            stage_v_153 = (stage_v_153 + step * 4 + pub_r000528_1) & 63;
        } else {
            stage_v_153 = (stage_v_153 + pub_r000528_2 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_153) & 127;
    }
    out_sink = (out_sink + stage_v_153) & 255;
    sec_accum = (sec_accum + stage_v_153) & 255;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_92 & 1) == step) {
            stage_v_154 = (stage_v_154 + step * 4 + pub_r000528_3) & 63;
        } else {
            stage_v_154 = (stage_v_154 + pub_r000528_16 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_154) & 127;
    }
    out_sink = (out_sink + stage_v_154) & 255;
    sec_accum = (sec_accum + stage_v_154) & 255;

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_94 & 1) == step) {
            stage_v_155 = (stage_v_155 + step * 4 + pub_r000528_10) & 63;
        } else {
            stage_v_155 = (stage_v_155 + pub_r000528_7 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_155) & 127;
    }
    out_sink = (out_sink + stage_v_155) & 255;
    sec_accum = (sec_accum + stage_v_155) & 255;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_90 & 1) == step) {
            stage_v_156 = (stage_v_156 + step * 4 + pub_r000528_21) & 63;
        } else {
            stage_v_156 = (stage_v_156 + pub_r000528_20 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_156) & 127;
    }
    out_sink = (out_sink + stage_v_156) & 255;
    sec_accum = (sec_accum + stage_v_156) & 255;

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_17 & 1) == step) {
            stage_v_157 = (stage_v_157 + step * 4 + pub_r000528_6) & 63;
        } else {
            stage_v_157 = (stage_v_157 + pub_r000528_12 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_157) & 127;
    }
    out_sink = (out_sink + stage_v_157) & 255;
    sec_accum = (sec_accum + stage_v_157) & 255;

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_98 & 1) == step) {
            stage_v_158 = (stage_v_158 + step * 4 + pub_r000528_2) & 63;
        } else {
            stage_v_158 = (stage_v_158 + pub_r000528_19 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_158) & 127;
    }
    out_sink = (out_sink + stage_v_158) & 255;
    sec_accum = (sec_accum + stage_v_158) & 255;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_6 & 1) == step) {
            stage_v_159 = (stage_v_159 + step * 4 + pub_r000528_20) & 63;
        } else {
            stage_v_159 = (stage_v_159 + pub_r000528_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_159) & 127;
    }
    out_sink = (out_sink + stage_v_159) & 255;
    sec_accum = (sec_accum + stage_v_159) & 255;

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_20 & 1) == step) {
            stage_v_160 = (stage_v_160 + step * 4 + pub_r000528_5) & 63;
        } else {
            stage_v_160 = (stage_v_160 + pub_r000528_14 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_160) & 127;
    }
    out_sink = (out_sink + stage_v_160) & 255;
    sec_accum = (sec_accum + stage_v_160) & 255;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int step = 0; step < 2; step++) {
        if ((sec_r000528_16 & 1) == step) {
            stage_v_161 = (stage_v_161 + step * 4 + pub_r000528_21) & 63;
        } else {
            stage_v_161 = (stage_v_161 + pub_r000528_13 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_161) & 127;
    }
    out_sink = (out_sink + stage_v_161) & 255;
    sec_accum = (sec_accum + stage_v_161) & 255;

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int step = 0; step < 2; step++) {
        if ((stage_v_101 & 1) == step) {
            stage_v_162 = (stage_v_162 + step * 4 + pub_r000528_17) & 63;
        } else {
            stage_v_162 = (stage_v_162 + pub_r000528_11 + 5) & 63;
        }
        chk_sum = (chk_sum + stage_v_162) & 127;
    }
    out_sink = (out_sink + stage_v_162) & 255;
    sec_accum = (sec_accum + stage_v_162) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
