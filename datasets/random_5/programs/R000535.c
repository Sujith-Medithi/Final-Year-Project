/*
 * Benchmark Program: R000535
 * Security Family: bitwise_flow
 * Generator Seed: 553513
 * High Inputs: 23 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R000535_3513_0 {
    int balance;
    short status;
    int fee;
    int buffer[3];
};

struct MatrixBlock_R000535_3513_1 {
    short stride;
    int density;
    int dim;
    unsigned char scale;
    int buffer[3];
};

struct FilterState_R000535_3513_2 {
    short mode;
    int gain_db;
    unsigned char prev_in;
    int cutoff;
    int buffer[3];
};

struct StreamBuffer_R000535_3513_3 {
    unsigned char head;
    int checksum;
    short state;
    int capacity;
    int tail;
    int buffer[3];
};

union TelemetryField_R000535_3513_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R000535_3513_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000535_3513_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000535_3513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int segment_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_53) & 63;
    acc ^= aux;
    int phase_62 = (aux + st.buffer[1]) & 3;
    switch (phase_62) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int threshold_79 = local_arr[aux % 3];
    acc = (acc + threshold_79 * 2) & 127;
    int accumulator_65 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_65 > 29) {
        acc = (acc + accumulator_65 * 2 + 5) & 127;
        aux ^= (accumulator_65 & 15);
    } else {
        acc = (acc - accumulator_65 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 23) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int quantum_63 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_63 > 18) {
        acc = (acc + quantum_63 * 2 + 5) & 127;
        aux ^= (quantum_63 & 15);
    } else {
        acc = (acc - quantum_63 + 11) & 127;
        aux += 3;
    }
    int anchor_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_54) & 63;
    acc ^= aux;
    int tally_32 = (aux + st.buffer[1]) & 3;
    switch (tally_32) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_2(int p0, int p1) {
    int acc = (p0 + 6) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int coefficient_77 = (aux + st.buffer[1]) & 3;
    switch (coefficient_77) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int residue_92 = local_arr[aux % 3];
    acc = (acc + residue_92 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int metric_58 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_58 > 23) {
        acc = (acc + metric_58 * 2 + 5) & 127;
        aux ^= (metric_58 & 15);
    } else {
        acc = (acc - metric_58 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_4(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000535_3513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int local_arr[3] = {4, 9, 15};
    int quantum_33 = local_arr[aux % 3];
    acc = (acc + quantum_33 * 2) & 127;
    int offset_98 = (aux + st.buffer[1]) & 3;
    switch (offset_98) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int sample_91 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_91) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_5(int p0, int p1) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int anchor_51 = local_arr[aux % 3];
    acc = (acc + anchor_51 * 2) & 127;
    int parity_54 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_54) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000535_3513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int segment_63 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_63 > 25) {
        acc = (acc + segment_63 * 2 + 5) & 127;
        aux ^= (segment_63 & 15);
    } else {
        acc = (acc - segment_63 + 11) & 127;
        aux += 3;
    }
    int tally_78 = (aux + st.buffer[1]) & 3;
    switch (tally_78) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int tally_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tally_76) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 42) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int accumulator_26 = local_arr[aux % 3];
    acc = (acc + accumulator_26 * 2) & 127;
    int mask_69 = (aux + st.buffer[1]) & 3;
    switch (mask_69) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int factor_29 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_29 > 41) {
        acc = (acc + factor_29 * 2 + 5) & 127;
        aux ^= (factor_29 & 15);
    } else {
        acc = (acc - factor_29 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_8(int p0, int p1) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int local_arr[3] = {4, 9, 15};
    int threshold_55 = local_arr[aux % 3];
    acc = (acc + threshold_55 * 2) & 127;
    int weight_13 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_13) & 63;
    acc ^= aux;
    int parity_45 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_45 > 25) {
        acc = (acc + parity_45 * 2 + 5) & 127;
        aux ^= (parity_45 & 15);
    } else {
        acc = (acc - parity_45 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_9(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int bound_54 = (aux + st.buffer[1]) & 3;
    switch (bound_54) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int quantum_93 = local_arr[aux % 3];
    acc = (acc + quantum_93 * 2) & 127;
    int tally_52 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_52 > 44) {
        acc = (acc + tally_52 * 2 + 5) & 127;
        aux ^= (tally_52 & 15);
    } else {
        acc = (acc - tally_52 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_10(int p0, int p1, int p2) {
    int acc = (p0 + 36) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_87 = (aux + st.buffer[1]) & 3;
    switch (checksum_87) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000535_3513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int cursor_36 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_36 > 24) {
        acc = (acc + cursor_36 * 2 + 5) & 127;
        aux ^= (cursor_36 & 15);
    } else {
        acc = (acc - cursor_36 + 11) & 127;
        aux += 3;
    }
    int coefficient_96 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_96) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_49 = local_arr[aux % 3];
    acc = (acc + tracker_49 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_12(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int cursor_37 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_37 > 33) {
        acc = (acc + cursor_37 * 2 + 5) & 127;
        aux ^= (cursor_37 & 15);
    } else {
        acc = (acc - cursor_37 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_82 = local_arr[aux % 3];
    acc = (acc + vector_82 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_13(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R000535_3513_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int window_92 = (st.buffer[0] * 3 + aux) & 63;
    if (window_92 > 35) {
        acc = (acc + window_92 * 2 + 5) & 127;
        aux ^= (window_92 & 15);
    } else {
        acc = (acc - window_92 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int margin_18 = local_arr[aux % 3];
    acc = (acc + margin_18 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_14(int p0, int p1) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000535_3513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int tracker_40 = (st.buffer[0] * 3 + aux) & 63;
    if (tracker_40 > 38) {
        acc = (acc + tracker_40 * 2 + 5) & 127;
        aux ^= (tracker_40 & 15);
    } else {
        acc = (acc - tracker_40 + 11) & 127;
        aux += 3;
    }
    int checksum_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_20) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int margin_83 = local_arr[aux % 3];
    acc = (acc + margin_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_15(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int residue_29 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + residue_29) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int quotient_53 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_53) & 63;
    acc ^= aux;
    int weight_96 = (st.buffer[0] * 3 + aux) & 63;
    if (weight_96 > 15) {
        acc = (acc + weight_96 * 2 + 5) & 127;
        aux ^= (weight_96 & 15);
    } else {
        acc = (acc - weight_96 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000535_3513_17(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R000535_3513_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_47 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + sample_47) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int stride_84 = local_arr[aux % 3];
    acc = (acc + stride_84 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000535_3513_18(int p0, int p1, int p2) {
    int acc = (p0 + 39) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct StreamBuffer_R000535_3513_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int local_arr[3] = {4, 9, 15};
    int tracker_46 = local_arr[aux % 3];
    acc = (acc + tracker_46 * 2) & 127;
    int threshold_28 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_28) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000535_3513_19(int p0, int p1) {
    int acc = (p0 + 26) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000535_3513_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int local_arr[3] = {4, 9, 15};
    int metric_19 = local_arr[aux % 3];
    acc = (acc + metric_19 * 2) & 127;
    int coefficient_12 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_12) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000535_0;
    int sec_r000535_1;
    int sec_r000535_2;
    int sec_r000535_3;
    int sec_r000535_4;
    int sec_r000535_5;
    int sec_r000535_6;
    int sec_r000535_7;
    int sec_r000535_8;
    int sec_r000535_9;
    int sec_r000535_10;
    int sec_r000535_11;
    int sec_r000535_12;
    int sec_r000535_13;
    int sec_r000535_14;
    int sec_r000535_15;
    int sec_r000535_16;
    int sec_r000535_17;
    int sec_r000535_18;
    int sec_r000535_19;
    int sec_r000535_20;
    int sec_r000535_21;
    int sec_r000535_22;
    int pub_r000535_0;
    int pub_r000535_1;
    int pub_r000535_2;
    int pub_r000535_3;
    int pub_r000535_4;
    int pub_r000535_5;
    int pub_r000535_6;
    int pub_r000535_7;
    int pub_r000535_8;
    int pub_r000535_9;
    int pub_r000535_10;
    int pub_r000535_11;
    int pub_r000535_12;
    int pub_r000535_13;
    int pub_r000535_14;
    int pub_r000535_15;
    int pub_r000535_16;
    int pub_r000535_17;
    int pub_r000535_18;
    int pub_r000535_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000535_0 >= -100 && pub_r000535_0 <= 100);
    __CPROVER_assume(pub_r000535_1 >= -100 && pub_r000535_1 <= 100);
    __CPROVER_assume(pub_r000535_2 >= -100 && pub_r000535_2 <= 100);
    __CPROVER_assume(pub_r000535_3 >= -100 && pub_r000535_3 <= 100);
    __CPROVER_assume(pub_r000535_4 >= -100 && pub_r000535_4 <= 100);
    __CPROVER_assume(pub_r000535_5 >= -100 && pub_r000535_5 <= 100);
    __CPROVER_assume(pub_r000535_6 >= -100 && pub_r000535_6 <= 100);
    __CPROVER_assume(pub_r000535_7 >= -100 && pub_r000535_7 <= 100);
    __CPROVER_assume(pub_r000535_8 >= -100 && pub_r000535_8 <= 100);
    __CPROVER_assume(pub_r000535_9 >= -100 && pub_r000535_9 <= 100);
    __CPROVER_assume(pub_r000535_10 >= -100 && pub_r000535_10 <= 100);
    __CPROVER_assume(pub_r000535_11 >= -100 && pub_r000535_11 <= 100);
    __CPROVER_assume(pub_r000535_12 >= -100 && pub_r000535_12 <= 100);
    __CPROVER_assume(pub_r000535_13 >= -100 && pub_r000535_13 <= 100);
    __CPROVER_assume(pub_r000535_14 >= -100 && pub_r000535_14 <= 100);
    __CPROVER_assume(pub_r000535_15 >= -100 && pub_r000535_15 <= 100);
    __CPROVER_assume(pub_r000535_16 >= -100 && pub_r000535_16 <= 100);
    __CPROVER_assume(pub_r000535_17 >= -100 && pub_r000535_17 <= 100);
    __CPROVER_assume(pub_r000535_18 >= -100 && pub_r000535_18 <= 100);
    __CPROVER_assume(pub_r000535_19 >= -100 && pub_r000535_19 <= 100);
    __CPROVER_assume(sec_r000535_0 >= 0 && sec_r000535_0 <= 255);
    __CPROVER_assume(sec_r000535_1 >= 0 && sec_r000535_1 <= 255);
    __CPROVER_assume(sec_r000535_2 >= 0 && sec_r000535_2 <= 255);
    __CPROVER_assume(sec_r000535_3 >= 0 && sec_r000535_3 <= 255);
    __CPROVER_assume(sec_r000535_4 >= 0 && sec_r000535_4 <= 255);
    __CPROVER_assume(sec_r000535_5 >= 0 && sec_r000535_5 <= 255);
    __CPROVER_assume(sec_r000535_6 >= 0 && sec_r000535_6 <= 255);
    __CPROVER_assume(sec_r000535_7 >= 0 && sec_r000535_7 <= 255);
    __CPROVER_assume(sec_r000535_8 >= 0 && sec_r000535_8 <= 255);
    __CPROVER_assume(sec_r000535_9 >= 0 && sec_r000535_9 <= 255);
    __CPROVER_assume(sec_r000535_10 >= 0 && sec_r000535_10 <= 255);
    __CPROVER_assume(sec_r000535_11 >= 0 && sec_r000535_11 <= 255);
    __CPROVER_assume(sec_r000535_12 >= 0 && sec_r000535_12 <= 255);
    __CPROVER_assume(sec_r000535_13 >= 0 && sec_r000535_13 <= 255);
    __CPROVER_assume(sec_r000535_14 >= 0 && sec_r000535_14 <= 255);
    __CPROVER_assume(sec_r000535_15 >= 0 && sec_r000535_15 <= 255);
    __CPROVER_assume(sec_r000535_16 >= 0 && sec_r000535_16 <= 255);
    __CPROVER_assume(sec_r000535_17 >= 0 && sec_r000535_17 <= 255);
    __CPROVER_assume(sec_r000535_18 >= 0 && sec_r000535_18 <= 255);
    __CPROVER_assume(sec_r000535_19 >= 0 && sec_r000535_19 <= 255);
    __CPROVER_assume(sec_r000535_20 >= 0 && sec_r000535_20 <= 255);
    __CPROVER_assume(sec_r000535_21 >= 0 && sec_r000535_21 <= 255);
    __CPROVER_assume(sec_r000535_22 >= 0 && sec_r000535_22 <= 255);

    struct Transaction_R000535_3513_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000535_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000535_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000535_0 + 7) & 15;
    struct MatrixBlock_R000535_3513_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000535_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000535_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000535_0 + 9) & 15;
    struct FilterState_R000535_3513_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000535_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000535_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000535_0 + 11) & 15;
    struct StreamBuffer_R000535_3513_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000535_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000535_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000535_0 + 13) & 15;

    union TelemetryField_R000535_3513_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 2) & 15;
    int stage_v_1 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;
    chk_sum ^= stage_v_1;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (st_var_2.buffer[2] * 2 + 13) & 63;
    if (stage_v_2 > 29) {
        out_sink = (out_sink + stage_v_2 - 5) & 255;
        if (stage_v_2 > 44) {
            chk_sum ^= (stage_v_2 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_2 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 3 */
    st_var_3.buffer[0] = (st_var_3.buffer[0] + 4) & 15;
    int stage_v_3 = (st_var_3.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_3) & 255;
    chk_sum ^= stage_v_3;

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = table[0];
    table[0] = (table[1] + 9) & 63;
    out_sink = (out_sink + stage_v_4) & 255;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (out_sink > 100) ? (chk_sum & 31) : (10 & 31);
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= (stage_v_5 << 1) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (out_sink > 100) ? (chk_sum & 31) : (11 & 31);
    out_sink = (out_sink + stage_v_6) & 255;
    chk_sum ^= (stage_v_6 << 1) & 127;

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_3.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_8 = (stage_v_8 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_8) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (st_var_1.buffer[0] ^ 12) & 3;
    switch (stage_v_9) {
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

    /* Execution Pipeline Stage 10 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 11) & 15;
    int stage_v_10 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_10) & 255;
    chk_sum ^= stage_v_10;

    /* Execution Pipeline Stage 11 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 12) & 15;
    int stage_v_11 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_11) & 255;
    chk_sum ^= stage_v_11;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (out_sink > 100) ? (chk_sum & 31) : (17 & 31);
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= (stage_v_12 << 1) & 127;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (st_var_1.buffer[0] ^ 16) & 3;
    switch (stage_v_13) {
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

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (st_var_2.buffer[0] ^ 17) & 3;
    switch (stage_v_14) {
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

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = table[3];
    table[3] = (table[0] + 31) & 63;
    out_sink = (out_sink + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (out_sink > 100) ? (chk_sum & 31) : (21 & 31);
    out_sink = (out_sink + stage_v_16) & 255;
    chk_sum ^= (stage_v_16 << 1) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 19) & 15;
    int stage_v_18 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_18) & 255;
    chk_sum ^= stage_v_18;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_19 = (stage_v_19 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_19) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 29) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 44) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

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
    int stage_v_23 = (st_var_3.buffer[2] * 2 + 76) & 63;
    if (stage_v_23 > 13) {
        out_sink = (out_sink + stage_v_23 - 5) & 255;
        if (stage_v_23 > 28) {
            chk_sum ^= (stage_v_23 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_23 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = table[0];
    table[0] = (table[1] + 49) & 63;
    out_sink = (out_sink + stage_v_24) & 255;

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
    int stage_v_26 = (out_sink > 100) ? (chk_sum & 31) : (31 & 31);
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= (stage_v_26 << 1) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = table[3];
    table[3] = (table[0] + 55) & 63;
    out_sink = (out_sink + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (out_sink > 100) ? (chk_sum & 31) : (33 & 31);
    out_sink = (out_sink + stage_v_28) & 255;
    chk_sum ^= (stage_v_28 << 1) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = table[1];
    table[1] = (table[2] + 59) & 63;
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (out_sink > 100) ? (chk_sum & 31) : (35 & 31);
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= (stage_v_30 << 1) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = table[3];
    table[3] = (table[0] + 63) & 63;
    out_sink = (out_sink + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = ((sec_r000535_2 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_32 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_32 & 63);

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = ((sec_r000535_16 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_33 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_33 & 63);

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = ((sec_r000535_0 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_34 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_34 & 63);

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = ((sec_r000535_11 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_35 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_35 & 63);

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = ((stage_v_32 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_36 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_36 & 63);

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = ((sec_r000535_19 << 2) ^ (sec_r000535_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_37 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_37 & 63);

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = ((stage_v_35 << 1) ^ (sec_r000535_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_38 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_38 & 63);

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = ((stage_v_36 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_39 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_39 & 63);

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = ((stage_v_38 << 2) ^ (sec_r000535_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_40 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_40 & 63);

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = ((stage_v_39 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_41 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_41 & 63);

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((stage_v_40 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_42 & 63);

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = ((stage_v_38 << 2) ^ (sec_r000535_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_43 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_43 & 63);

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((sec_r000535_1 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_44 & 63);

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = ((sec_r000535_13 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_45 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_45 & 63);

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = ((stage_v_40 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_46 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_46 & 63);

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = ((stage_v_35 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_47 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_47 & 63);

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((sec_r000535_8 << 1) ^ (sec_r000535_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_48 & 63);

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = ((sec_r000535_1 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_49 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_49 & 63);

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = ((stage_v_32 << 2) ^ (sec_r000535_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_50 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_50 & 63);

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((sec_r000535_4 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_51 & 63);

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = ((stage_v_32 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_52 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_52 & 63);

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((stage_v_40 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_53 & 63);

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = ((sec_r000535_5 << 2) ^ (sec_r000535_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_54 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_54 & 63);

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((sec_r000535_21 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_55 & 63);

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = ((stage_v_33 << 1) ^ (sec_r000535_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_56 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_56 & 63);

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = ((sec_r000535_3 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_57 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_57 & 63);

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = ((stage_v_45 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_58 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_58 & 63);

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = ((stage_v_41 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_59 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_59 & 63);

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = ((stage_v_48 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_60 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_60 & 63);

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = ((sec_r000535_16 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_61 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_61 & 63);

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = ((sec_r000535_8 << 2) ^ (sec_r000535_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_62 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_62 & 63);

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = ((stage_v_55 << 2) ^ (sec_r000535_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_63 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_63 & 63);

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = ((sec_r000535_10 << 2) ^ (sec_r000535_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_64 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_64 & 63);

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = ((sec_r000535_19 << 2) ^ (sec_r000535_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_65 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_65 & 63);

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = ((stage_v_40 << 2) ^ (sec_r000535_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_66 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_66 & 63);

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = ((stage_v_33 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_67 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_67 & 63);

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = ((sec_r000535_8 << 2) ^ (sec_r000535_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_68 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_68 & 63);

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = ((stage_v_47 << 2) ^ (sec_r000535_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_69 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_69 & 63);

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = ((sec_r000535_9 << 2) ^ (sec_r000535_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_70 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_70 & 63);

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = ((stage_v_49 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_71 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_71 & 63);

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = ((stage_v_34 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_72 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_72 & 63);

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = ((stage_v_51 << 2) ^ (sec_r000535_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_73 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_73 & 63);

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = ((sec_r000535_21 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_74 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_74 & 63);

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = ((stage_v_56 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_75 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_75 & 63);

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = ((stage_v_67 << 1) ^ (sec_r000535_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_76 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_76 & 63);

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = ((stage_v_72 << 1) ^ (sec_r000535_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_77 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_77 & 63);

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = ((stage_v_32 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_78 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_78 & 63);

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = ((stage_v_63 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_79 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_79 & 63);

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = ((sec_r000535_7 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_80 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_80 & 63);

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = ((sec_r000535_13 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_81 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_81 & 63);

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = ((stage_v_41 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_82 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_82 & 63);

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = ((stage_v_49 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_83 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_83 & 63);

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = ((stage_v_43 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_84 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_84 & 63);

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = ((sec_r000535_21 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_85 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_85 & 63);

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = ((stage_v_39 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_86 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_86 & 63);

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = ((stage_v_33 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_87 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_87 & 63);

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = ((stage_v_44 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_88 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_88 & 63);

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = ((stage_v_32 << 2) ^ (sec_r000535_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_89 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_89 & 63);

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = ((stage_v_73 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_90 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_90 & 63);

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = ((stage_v_82 << 2) ^ (sec_r000535_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_91 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_91 & 63);

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = ((sec_r000535_9 << 1) ^ (sec_r000535_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_92 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_92 & 63);

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = ((stage_v_44 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_93 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_93 & 63);

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = ((stage_v_33 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_94 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_94 & 63);

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = ((stage_v_33 << 1) ^ (sec_r000535_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_95 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_95 & 63);

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = ((stage_v_90 << 1) ^ (sec_r000535_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_96 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_96 & 63);

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = ((stage_v_87 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_97 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_97 & 63);

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = ((sec_r000535_7 << 1) ^ (sec_r000535_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_98 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_98 & 63);

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = ((sec_r000535_6 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_99 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_99 & 63);

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = ((sec_r000535_11 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_100 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_100 & 63);

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = ((stage_v_84 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_101 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_101 & 63);

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = ((stage_v_58 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_102 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_102 & 63);

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = ((stage_v_90 << 2) ^ (sec_r000535_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_103 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_103 & 63);

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = ((stage_v_46 << 1) ^ (sec_r000535_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_104 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_104 & 63);

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = ((stage_v_73 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_105 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_105 & 63);

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = ((stage_v_93 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_106 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_106 & 63);

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = ((stage_v_71 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_107 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_107 & 63);

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = ((stage_v_101 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_108 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_108 & 63);

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = ((stage_v_90 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_109 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_109 & 63);

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = ((stage_v_68 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_110 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_110 & 63);

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = ((sec_r000535_4 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_111 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_111 & 63);

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = ((stage_v_43 << 1) ^ (sec_r000535_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_112 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_112 & 63);

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = ((sec_r000535_18 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_113 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_113 & 63);

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = ((sec_r000535_15 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_114 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_114 & 63);

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = ((stage_v_52 << 2) ^ (sec_r000535_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_115 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_115 & 63);

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = ((stage_v_72 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_116 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_116 & 63);

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = ((stage_v_51 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_117 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_117 & 63);

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = ((stage_v_106 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_118 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_118 & 63);

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = ((stage_v_76 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_119 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_119 & 63);

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = ((stage_v_115 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_120 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_120 & 63);

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = ((sec_r000535_5 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_121 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_121 & 63);

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = ((sec_r000535_3 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_122 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_122 & 63);

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = ((stage_v_90 << 2) ^ (sec_r000535_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_123 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_123 & 63);

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = ((stage_v_67 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_124 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_124 & 63);

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = ((stage_v_124 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_125 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_125 & 63);

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = ((stage_v_94 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_126 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_126 & 63);

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = ((stage_v_110 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_127 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_127 & 63);

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = ((stage_v_86 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_128 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_128 & 63);

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = ((sec_r000535_5 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_129 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_129 & 63);

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = ((stage_v_73 << 1) ^ (sec_r000535_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_130 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_130 & 63);

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = ((sec_r000535_5 << 2) ^ (sec_r000535_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_131 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_131 & 63);

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = ((stage_v_125 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_132 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_132 & 63);

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = ((stage_v_129 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_133 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_133 & 63);

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = ((sec_r000535_11 << 2) ^ (sec_r000535_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_134 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_134 & 63);

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = ((sec_r000535_13 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_135 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_135 & 63);

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = ((stage_v_90 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_136 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_136 & 63);

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = ((stage_v_62 << 2) ^ (sec_r000535_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_137 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_137 & 63);

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = ((stage_v_74 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_138 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_138 & 63);

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = ((stage_v_126 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_139 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_139 & 63);

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = ((sec_r000535_18 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_140 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_140 & 63);

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = ((sec_r000535_1 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_141 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_141 & 63);

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = ((stage_v_87 << 2) ^ (sec_r000535_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_142 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_142 & 63);

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = ((stage_v_88 << 1) ^ (sec_r000535_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_143 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_143 & 63);

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = ((stage_v_46 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_144 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_144 & 63);

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = ((stage_v_41 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_145 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_145 & 63);

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = ((sec_r000535_4 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_146 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_146 & 63);

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = ((sec_r000535_15 << 1) ^ (sec_r000535_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_147 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_147 & 63);

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = ((stage_v_96 << 2) ^ (sec_r000535_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_148 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_148 & 63);

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = ((stage_v_42 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_149 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_149 & 63);

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = ((stage_v_56 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_150 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_150 & 63);

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = ((sec_r000535_2 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_151 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_151 & 63);

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = ((stage_v_72 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_152 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_152 & 63);

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = ((stage_v_131 << 2) ^ (sec_r000535_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_153 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_153 & 63);

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = ((stage_v_35 << 1) ^ (sec_r000535_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_154 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_154 & 63);

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = ((stage_v_102 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_155 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_155 & 63);

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = ((stage_v_147 << 1) ^ (sec_r000535_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_156 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_156 & 63);

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = ((sec_r000535_20 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_157 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_157 & 63);

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = ((stage_v_68 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_158 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_158 & 63);

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = ((sec_r000535_7 << 1) ^ (sec_r000535_7 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_159 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_159 & 63);

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = ((stage_v_145 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_160 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_160 & 63);

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = ((sec_r000535_20 << 2) ^ (sec_r000535_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_161 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_161 & 63);

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = ((sec_r000535_21 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_162 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_162 & 63);

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = ((stage_v_34 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_163 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_163 & 63);

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = ((sec_r000535_14 << 2) ^ (sec_r000535_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_164 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_164 & 63);

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = ((stage_v_142 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_165 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_165 & 63);

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = ((stage_v_114 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_166 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_166 & 63);

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = ((stage_v_98 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_167 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_167 & 63);

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = ((sec_r000535_4 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_168 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_168 & 63);

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = ((stage_v_168 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_169 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_169 & 63);

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = ((stage_v_47 << 2) ^ (sec_r000535_14 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_170 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_170 & 63);

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = ((stage_v_97 << 2) ^ (sec_r000535_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_171 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_171 & 63);

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = ((sec_r000535_6 << 2) ^ (sec_r000535_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_172 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_172 & 63);

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = ((stage_v_94 << 2) ^ (sec_r000535_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_173 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_173 & 63);

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = ((sec_r000535_3 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_174 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_174 & 63);

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = ((stage_v_50 << 1) ^ (sec_r000535_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_175 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_175 & 63);

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = ((stage_v_128 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_176 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_176 & 63);

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = ((sec_r000535_1 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_177 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_177 & 63);

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = ((stage_v_95 << 2) ^ (sec_r000535_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_178 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_178 & 63);

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = ((stage_v_60 << 1) ^ (sec_r000535_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_179 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_179 & 63);

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = ((sec_r000535_17 << 1) ^ (sec_r000535_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_180 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_180 & 63);

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = ((sec_r000535_22 << 1) ^ (sec_r000535_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_181 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_181 & 63);

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = ((sec_r000535_11 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_182 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_182 & 63);

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = ((stage_v_50 << 1) ^ (sec_r000535_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_183 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_183 & 63);

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = ((stage_v_169 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_184 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_184 & 63);

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = ((stage_v_109 << 1) ^ (sec_r000535_17 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_185 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_185 & 63);

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = ((sec_r000535_19 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_186 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_186 & 63);

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = ((sec_r000535_2 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_187 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_187 & 63);

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = ((stage_v_127 << 2) ^ (sec_r000535_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_188 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_188 & 63);

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = ((stage_v_106 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_189 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_189 & 63);

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = ((stage_v_188 << 1) ^ (sec_r000535_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_190 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_190 & 63);

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = ((stage_v_95 << 2) ^ (sec_r000535_5 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_191 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_191 & 63);

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = ((stage_v_183 << 1) ^ (sec_r000535_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_192 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_192 & 63);

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = ((sec_r000535_12 << 2) ^ (sec_r000535_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_193 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_193 & 63);

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = ((stage_v_96 << 2) ^ (sec_r000535_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_194 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_194 & 63);

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = ((sec_r000535_6 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_195 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_195 & 63);

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = ((stage_v_76 << 2) ^ (sec_r000535_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_196 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_196 & 63);

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = ((stage_v_175 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_197 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_197 & 63);

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = ((stage_v_191 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_198 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_198 & 63);

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = ((stage_v_114 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_199 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_199 & 63);

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = ((stage_v_34 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_200 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_200 & 63);

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = ((stage_v_144 << 2) ^ (sec_r000535_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_201 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_201 & 63);

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = ((stage_v_161 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_202 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_202 & 63);

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = ((stage_v_86 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_203 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_203 & 63);

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = ((stage_v_95 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_204 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_204 & 63);

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = ((stage_v_176 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_205 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_205 & 63);

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = ((sec_r000535_20 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_206 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_206 & 63);

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = ((sec_r000535_11 << 2) ^ (sec_r000535_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_207 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_207 & 63);

    /* Execution Pipeline Stage 208 */
    int stage_v_208 = ((sec_r000535_20 << 2) ^ (sec_r000535_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_208 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_208 & 63);

    /* Execution Pipeline Stage 209 */
    int stage_v_209 = ((sec_r000535_4 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_209 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_209 & 63);

    /* Execution Pipeline Stage 210 */
    int stage_v_210 = ((stage_v_121 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_210 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_210 & 63);

    /* Execution Pipeline Stage 211 */
    int stage_v_211 = ((stage_v_73 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_211 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_211 & 63);

    /* Execution Pipeline Stage 212 */
    int stage_v_212 = ((sec_r000535_19 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_212 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_212 & 63);

    /* Execution Pipeline Stage 213 */
    int stage_v_213 = ((stage_v_177 << 1) ^ (sec_r000535_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_213 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_213 & 63);

    /* Execution Pipeline Stage 214 */
    int stage_v_214 = ((stage_v_65 << 1) ^ (sec_r000535_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_214 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_214 & 63);

    /* Execution Pipeline Stage 215 */
    int stage_v_215 = ((stage_v_139 << 2) ^ (sec_r000535_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_215 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_215 & 63);

    /* Execution Pipeline Stage 216 */
    int stage_v_216 = ((stage_v_160 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_216 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_216 & 63);

    /* Execution Pipeline Stage 217 */
    int stage_v_217 = ((stage_v_96 << 2) ^ (sec_r000535_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_217 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_217 & 63);

    /* Execution Pipeline Stage 218 */
    int stage_v_218 = ((stage_v_201 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_218 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_218 & 63);

    /* Execution Pipeline Stage 219 */
    int stage_v_219 = ((stage_v_47 << 1) ^ (sec_r000535_19 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_219 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_219 & 63);

    /* Execution Pipeline Stage 220 */
    int stage_v_220 = ((stage_v_117 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_220 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_220 & 63);

    /* Execution Pipeline Stage 221 */
    int stage_v_221 = ((stage_v_40 << 2) ^ (sec_r000535_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_221 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_221 & 63);

    /* Execution Pipeline Stage 222 */
    int stage_v_222 = ((sec_r000535_9 << 1) ^ (sec_r000535_9 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_222 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_222 & 63);

    /* Execution Pipeline Stage 223 */
    int stage_v_223 = ((stage_v_185 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_223 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_223 & 63);

    /* Execution Pipeline Stage 224 */
    int stage_v_224 = ((stage_v_110 << 2) ^ (sec_r000535_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_224 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_224 & 63);

    /* Execution Pipeline Stage 225 */
    int stage_v_225 = ((stage_v_46 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_225 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_225 & 63);

    /* Execution Pipeline Stage 226 */
    int stage_v_226 = ((sec_r000535_2 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_226 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_226 & 63);

    /* Execution Pipeline Stage 227 */
    int stage_v_227 = ((stage_v_180 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_227 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_227 & 63);

    /* Execution Pipeline Stage 228 */
    int stage_v_228 = ((sec_r000535_2 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_228 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_228 & 63);

    /* Execution Pipeline Stage 229 */
    int stage_v_229 = ((sec_r000535_3 << 2) ^ (sec_r000535_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_229 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_229 & 63);

    /* Execution Pipeline Stage 230 */
    int stage_v_230 = ((sec_r000535_11 << 2) ^ (sec_r000535_11 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_230 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_230 & 63);

    /* Execution Pipeline Stage 231 */
    int stage_v_231 = ((stage_v_197 << 1) ^ (sec_r000535_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_231 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_231 & 63);

    /* Execution Pipeline Stage 232 */
    int stage_v_232 = ((stage_v_103 << 1) ^ (sec_r000535_15 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_232 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_232 & 63);

    /* Execution Pipeline Stage 233 */
    int stage_v_233 = ((sec_r000535_18 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_233 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_233 & 63);

    /* Execution Pipeline Stage 234 */
    int stage_v_234 = ((stage_v_128 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_234 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_234 & 63);

    /* Execution Pipeline Stage 235 */
    int stage_v_235 = ((stage_v_53 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_235 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_235 & 63);

    /* Execution Pipeline Stage 236 */
    int stage_v_236 = ((sec_r000535_6 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_236 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_236 & 63);

    /* Execution Pipeline Stage 237 */
    int stage_v_237 = ((sec_r000535_10 << 2) ^ (sec_r000535_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_237 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_237 & 63);

    /* Execution Pipeline Stage 238 */
    int stage_v_238 = ((stage_v_115 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_238 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_238 & 63);

    /* Execution Pipeline Stage 239 */
    int stage_v_239 = ((sec_r000535_17 << 2) ^ (sec_r000535_17 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_239 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_239 & 63);

    /* Execution Pipeline Stage 240 */
    int stage_v_240 = ((stage_v_237 << 2) ^ (sec_r000535_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_240 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_240 & 63);

    /* Execution Pipeline Stage 241 */
    int stage_v_241 = ((sec_r000535_4 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_241 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_241 & 63);

    /* Execution Pipeline Stage 242 */
    int stage_v_242 = ((stage_v_199 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_242 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_242 & 63);

    /* Execution Pipeline Stage 243 */
    int stage_v_243 = ((stage_v_145 << 2) ^ (sec_r000535_7 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_243 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_243 & 63);

    /* Execution Pipeline Stage 244 */
    int stage_v_244 = ((sec_r000535_12 << 2) ^ (sec_r000535_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_244 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_244 & 63);

    /* Execution Pipeline Stage 245 */
    int stage_v_245 = ((stage_v_64 << 2) ^ (sec_r000535_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_245 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_245 & 63);

    /* Execution Pipeline Stage 246 */
    int stage_v_246 = ((stage_v_192 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_246 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_246 & 63);

    /* Execution Pipeline Stage 247 */
    int stage_v_247 = ((sec_r000535_6 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_247 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_247 & 63);

    /* Execution Pipeline Stage 248 */
    int stage_v_248 = ((stage_v_171 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_248 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_248 & 63);

    /* Execution Pipeline Stage 249 */
    int stage_v_249 = ((stage_v_59 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_249 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_249 & 63);

    /* Execution Pipeline Stage 250 */
    int stage_v_250 = ((stage_v_187 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_250 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_250 & 63);

    /* Execution Pipeline Stage 251 */
    int stage_v_251 = ((stage_v_129 << 2) ^ (sec_r000535_8 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_251 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_251 & 63);

    /* Execution Pipeline Stage 252 */
    int stage_v_252 = ((sec_r000535_18 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_252 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_252 & 63);

    /* Execution Pipeline Stage 253 */
    int stage_v_253 = ((stage_v_111 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_253 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_253 & 63);

    /* Execution Pipeline Stage 254 */
    int stage_v_254 = ((stage_v_46 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_254 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_254 & 63);

    /* Execution Pipeline Stage 255 */
    int stage_v_255 = ((stage_v_115 << 2) ^ (sec_r000535_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_255 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_255 & 63);

    /* Execution Pipeline Stage 256 */
    int stage_v_256 = ((stage_v_142 << 2) ^ (sec_r000535_3 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_256 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_256 & 63);

    /* Execution Pipeline Stage 257 */
    int stage_v_257 = ((sec_r000535_14 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_257 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_257 & 63);

    /* Execution Pipeline Stage 258 */
    int stage_v_258 = ((stage_v_87 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_258 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_258 & 63);

    /* Execution Pipeline Stage 259 */
    int stage_v_259 = ((stage_v_72 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_259 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_259 & 63);

    /* Execution Pipeline Stage 260 */
    int stage_v_260 = ((sec_r000535_4 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_260 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_260 & 63);

    /* Execution Pipeline Stage 261 */
    int stage_v_261 = ((stage_v_144 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_261 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_261 & 63);

    /* Execution Pipeline Stage 262 */
    int stage_v_262 = ((stage_v_52 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_262 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_262 & 63);

    /* Execution Pipeline Stage 263 */
    int stage_v_263 = ((stage_v_234 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_263 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_263 & 63);

    /* Execution Pipeline Stage 264 */
    int stage_v_264 = ((sec_r000535_15 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_264 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_264 & 63);

    /* Execution Pipeline Stage 265 */
    int stage_v_265 = ((sec_r000535_15 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_265 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_265 & 63);

    /* Execution Pipeline Stage 266 */
    int stage_v_266 = ((sec_r000535_19 << 2) ^ (sec_r000535_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_266 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_266 & 63);

    /* Execution Pipeline Stage 267 */
    int stage_v_267 = ((stage_v_39 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_267 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_267 & 63);

    /* Execution Pipeline Stage 268 */
    int stage_v_268 = ((stage_v_189 << 1) ^ (sec_r000535_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_268 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_268 & 63);

    /* Execution Pipeline Stage 269 */
    int stage_v_269 = ((sec_r000535_18 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_269 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_269 & 63);

    /* Execution Pipeline Stage 270 */
    int stage_v_270 = ((stage_v_213 << 2) ^ (sec_r000535_15 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_270 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_270 & 63);

    /* Execution Pipeline Stage 271 */
    int stage_v_271 = ((sec_r000535_6 << 2) ^ (sec_r000535_6 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_271 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_271 & 63);

    /* Execution Pipeline Stage 272 */
    int stage_v_272 = ((sec_r000535_21 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_272 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_272 & 63);

    /* Execution Pipeline Stage 273 */
    int stage_v_273 = ((stage_v_139 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_273 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_273 & 63);

    /* Execution Pipeline Stage 274 */
    int stage_v_274 = ((stage_v_236 << 1) ^ (sec_r000535_6 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_274 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_274 & 63);

    /* Execution Pipeline Stage 275 */
    int stage_v_275 = ((stage_v_264 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_275 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_275 & 63);

    /* Execution Pipeline Stage 276 */
    int stage_v_276 = ((stage_v_80 << 2) ^ (sec_r000535_10 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_276 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_276 & 63);

    /* Execution Pipeline Stage 277 */
    int stage_v_277 = ((sec_r000535_4 << 2) ^ (sec_r000535_4 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_277 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_277 & 63);

    /* Execution Pipeline Stage 278 */
    int stage_v_278 = ((sec_r000535_21 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_278 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_278 & 63);

    /* Execution Pipeline Stage 279 */
    int stage_v_279 = ((stage_v_112 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_279 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_279 & 63);

    /* Execution Pipeline Stage 280 */
    int stage_v_280 = ((stage_v_95 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_280 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_280 & 63);

    /* Execution Pipeline Stage 281 */
    int stage_v_281 = ((stage_v_151 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_281 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_281 & 63);

    /* Execution Pipeline Stage 282 */
    int stage_v_282 = ((sec_r000535_18 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_282 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_282 & 63);

    /* Execution Pipeline Stage 283 */
    int stage_v_283 = ((stage_v_42 << 2) ^ (sec_r000535_22 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_283 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_283 & 63);

    /* Execution Pipeline Stage 284 */
    int stage_v_284 = ((stage_v_257 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_284 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_284 & 63);

    /* Execution Pipeline Stage 285 */
    int stage_v_285 = ((sec_r000535_22 << 1) ^ (sec_r000535_22 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_285 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_285 & 63);

    /* Execution Pipeline Stage 286 */
    int stage_v_286 = ((stage_v_189 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_286 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_286 & 63);

    /* Execution Pipeline Stage 287 */
    int stage_v_287 = ((stage_v_221 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_287 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_287 & 63);

    /* Execution Pipeline Stage 288 */
    int stage_v_288 = ((sec_r000535_4 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_288 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_288 & 63);

    /* Execution Pipeline Stage 289 */
    int stage_v_289 = ((stage_v_243 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_289 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_289 & 63);

    /* Execution Pipeline Stage 290 */
    int stage_v_290 = ((sec_r000535_13 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_290 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_290 & 63);

    /* Execution Pipeline Stage 291 */
    int stage_v_291 = ((stage_v_105 << 1) ^ (sec_r000535_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_291 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_291 & 63);

    /* Execution Pipeline Stage 292 */
    int stage_v_292 = ((stage_v_134 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_292 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_292 & 63);

    /* Execution Pipeline Stage 293 */
    int stage_v_293 = ((sec_r000535_14 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_293 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_293 & 63);

    /* Execution Pipeline Stage 294 */
    int stage_v_294 = ((stage_v_52 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_294 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_294 & 63);

    /* Execution Pipeline Stage 295 */
    int stage_v_295 = ((stage_v_247 << 2) ^ (sec_r000535_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_295 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_295 & 63);

    /* Execution Pipeline Stage 296 */
    int stage_v_296 = ((stage_v_281 << 2) ^ (sec_r000535_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_296 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_296 & 63);

    /* Execution Pipeline Stage 297 */
    int stage_v_297 = ((stage_v_259 << 2) ^ (sec_r000535_18 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_297 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_297 & 63);

    /* Execution Pipeline Stage 298 */
    int stage_v_298 = ((sec_r000535_11 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_298 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_298 & 63);

    /* Execution Pipeline Stage 299 */
    int stage_v_299 = ((stage_v_105 << 1) ^ (sec_r000535_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_299 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_299 & 63);

    /* Execution Pipeline Stage 300 */
    int stage_v_300 = ((sec_r000535_9 << 2) ^ (sec_r000535_9 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_300 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_300 & 63);

    /* Execution Pipeline Stage 301 */
    int stage_v_301 = ((stage_v_219 << 1) ^ (sec_r000535_13 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_301 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_301 & 63);

    /* Execution Pipeline Stage 302 */
    int stage_v_302 = ((stage_v_203 << 1) ^ (sec_r000535_21 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_302 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_302 & 63);

    /* Execution Pipeline Stage 303 */
    int stage_v_303 = ((stage_v_143 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_303 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_303 & 63);

    /* Execution Pipeline Stage 304 */
    int stage_v_304 = ((stage_v_74 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_304 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_304 & 63);

    /* Execution Pipeline Stage 305 */
    int stage_v_305 = ((stage_v_230 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_305 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_305 & 63);

    /* Execution Pipeline Stage 306 */
    int stage_v_306 = ((stage_v_68 << 2) ^ (sec_r000535_19 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_306 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_306 & 63);

    /* Execution Pipeline Stage 307 */
    int stage_v_307 = ((stage_v_231 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_307 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_307 & 63);

    /* Execution Pipeline Stage 308 */
    int stage_v_308 = ((stage_v_165 << 1) ^ (sec_r000535_2 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_308 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_308 & 63);

    /* Execution Pipeline Stage 309 */
    int stage_v_309 = ((sec_r000535_8 << 1) ^ (sec_r000535_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_309 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_309 & 63);

    /* Execution Pipeline Stage 310 */
    int stage_v_310 = ((sec_r000535_13 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_310 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_310 & 63);

    /* Execution Pipeline Stage 311 */
    int stage_v_311 = ((stage_v_284 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_311 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_311 & 63);

    /* Execution Pipeline Stage 312 */
    int stage_v_312 = ((stage_v_178 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_312 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_312 & 63);

    /* Execution Pipeline Stage 313 */
    int stage_v_313 = ((stage_v_289 << 1) ^ (sec_r000535_10 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_313 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_313 & 63);

    /* Execution Pipeline Stage 314 */
    int stage_v_314 = ((stage_v_222 << 2) ^ (sec_r000535_16 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_314 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_314 & 63);

    /* Execution Pipeline Stage 315 */
    int stage_v_315 = ((sec_r000535_4 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_315 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_315 & 63);

    /* Execution Pipeline Stage 316 */
    int stage_v_316 = ((stage_v_216 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_316 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_316 & 63);

    /* Execution Pipeline Stage 317 */
    int stage_v_317 = ((stage_v_111 << 2) ^ (sec_r000535_13 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_317 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_317 & 63);

    /* Execution Pipeline Stage 318 */
    int stage_v_318 = ((stage_v_102 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_318 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_318 & 63);

    /* Execution Pipeline Stage 319 */
    int stage_v_319 = ((stage_v_301 << 1) ^ (sec_r000535_8 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_319 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_319 & 63);

    /* Execution Pipeline Stage 320 */
    int stage_v_320 = ((stage_v_49 << 1) ^ (sec_r000535_12 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_320 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_320 & 63);

    /* Execution Pipeline Stage 321 */
    int stage_v_321 = ((stage_v_241 << 2) ^ (sec_r000535_20 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_321 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_321 & 63);

    /* Execution Pipeline Stage 322 */
    int stage_v_322 = ((stage_v_100 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_322 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_322 & 63);

    /* Execution Pipeline Stage 323 */
    int stage_v_323 = ((stage_v_153 << 1) ^ (sec_r000535_11 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_323 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_323 & 63);

    /* Execution Pipeline Stage 324 */
    int stage_v_324 = ((sec_r000535_4 << 1) ^ (sec_r000535_4 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_324 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_324 & 63);

    /* Execution Pipeline Stage 325 */
    int stage_v_325 = ((stage_v_314 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_325 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_325 & 63);

    /* Execution Pipeline Stage 326 */
    int stage_v_326 = ((stage_v_37 << 2) ^ (sec_r000535_12 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_326 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_326 & 63);

    /* Execution Pipeline Stage 327 */
    int stage_v_327 = ((stage_v_303 << 2) ^ (sec_r000535_21 >> 2) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_327 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_327 & 63);

    /* Execution Pipeline Stage 328 */
    int stage_v_328 = ((sec_r000535_0 << 2) ^ (sec_r000535_0 >> 2) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_328 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_328 & 63);

    /* Execution Pipeline Stage 329 */
    int stage_v_329 = ((stage_v_225 << 1) ^ (sec_r000535_16 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_329 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_329 & 63);

    /* Execution Pipeline Stage 330 */
    int stage_v_330 = ((stage_v_241 << 2) ^ (sec_r000535_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_330 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_330 & 63);

    /* Execution Pipeline Stage 331 */
    int stage_v_331 = ((stage_v_69 << 1) ^ (sec_r000535_3 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_331 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_331 & 63);

    /* Execution Pipeline Stage 332 */
    int stage_v_332 = ((stage_v_317 << 1) ^ (sec_r000535_0 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_332 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_332 & 63);

    /* Execution Pipeline Stage 333 */
    int stage_v_333 = ((stage_v_79 << 1) ^ (sec_r000535_1 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_333 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_333 & 63);

    /* Execution Pipeline Stage 334 */
    int stage_v_334 = ((sec_r000535_1 << 2) ^ (sec_r000535_1 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_334 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_334 & 63);

    /* Execution Pipeline Stage 335 */
    int stage_v_335 = ((stage_v_303 << 1) ^ (sec_r000535_20 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_335 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_335 & 63);

    /* Execution Pipeline Stage 336 */
    int stage_v_336 = ((stage_v_82 << 1) ^ (sec_r000535_18 >> 1) ^ 0x3C) & 127;
    u_var.raw[0] = (unsigned char)(stage_v_336 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;
    out_sink ^= (stage_v_336 & 63);

    /* Execution Pipeline Stage 337 */
    int stage_v_337 = ((sec_r000535_5 << 1) ^ (sec_r000535_5 >> 1) ^ 0x3C) & 127;
    u_var.raw[1] = (unsigned char)(stage_v_337 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;
    out_sink ^= (stage_v_337 & 63);

    /* Execution Pipeline Stage 338 */
    int stage_v_338 = ((stage_v_240 << 2) ^ (sec_r000535_2 >> 2) ^ 0x3C) & 127;
    u_var.raw[2] = (unsigned char)(stage_v_338 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;
    out_sink ^= (stage_v_338 & 63);

    /* Execution Pipeline Stage 339 */
    int stage_v_339 = ((sec_r000535_14 << 1) ^ (sec_r000535_14 >> 1) ^ 0x3C) & 127;
    u_var.raw[3] = (unsigned char)(stage_v_339 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;
    out_sink ^= (stage_v_339 & 63);

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
