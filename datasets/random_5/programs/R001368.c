/*
 * Benchmark Program: R001368
 * Security Family: secret_dependent_loops
 * Generator Seed: 636813
 * High Inputs: 16 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Transaction_R001368_6813_0 {
    int rate;
    unsigned char fee;
    unsigned char auth_code;
    unsigned char status;
    int buffer[3];
};

struct MatrixBlock_R001368_6813_1 {
    short determinant;
    short stride;
    short dim;
    int density;
    unsigned char trace;
    unsigned char scale;
    int buffer[3];
};

struct FilterState_R001368_6813_2 {
    int damping;
    unsigned char prev_out;
    int mode;
    int cutoff;
    int buffer[3];
};

struct EventLog_R001368_6813_3 {
    int timestamp;
    int seq;
    int facility;
    short signature;
    unsigned char code;
    short severity;
    int buffer[3];
};

union ColorPixel_R001368_6813_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001368_6813_0(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001368_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_31 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_31 > 48) {
        acc = (acc + accumulator_31 * 2 + 5) & 127;
        aux ^= (accumulator_31 & 15);
    } else {
        acc = (acc - accumulator_31 + 11) & 127;
        aux += 3;
    }
    int pivot_66 = (aux + st.buffer[1]) & 3;
    switch (pivot_66) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_1(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001368_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int weight_63 = (aux + st.buffer[1]) & 3;
    switch (weight_63) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001368_6813_2(int p0, int p1, int p2) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001368_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    int local_arr[3] = {4, 9, 15};
    int quotient_26 = local_arr[aux % 3];
    acc = (acc + quotient_26 * 2) & 127;
    int quotient_50 = (aux + st.buffer[1]) & 3;
    switch (quotient_50) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001368_6813_3(int p0, int p1) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001368_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int margin_26 = (aux + st.buffer[1]) & 3;
    switch (margin_26) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int bound_43 = local_arr[aux % 3];
    acc = (acc + bound_43 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_92 = 0;
    for (int k = 0; k < 2; k++) {
        segment_92 = (segment_92 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + segment_92) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_4(int p0, int p1, int p2) {
    int acc = (p0 + 16) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int sample_52 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_52 > 33) {
        acc = (acc + sample_52 * 2 + 5) & 127;
        aux ^= (sample_52 & 15);
    } else {
        acc = (acc - sample_52 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int window_73 = local_arr[aux % 3];
    acc = (acc + window_73 * 2) & 127;
    int mask_83 = 0;
    for (int k = 0; k < 2; k++) {
        mask_83 = (mask_83 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_83) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_5(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_74 = (st.buffer[0] * 3 + aux) & 63;
    if (checksum_74 > 39) {
        acc = (acc + checksum_74 * 2 + 5) & 127;
        aux ^= (checksum_74 & 15);
    } else {
        acc = (acc - checksum_74 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_6(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 15) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001368_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    int local_arr[3] = {4, 9, 15};
    int window_10 = local_arr[aux % 3];
    acc = (acc + window_10 * 2) & 127;
    int residue_78 = (aux + st.buffer[1]) & 3;
    switch (residue_78) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_7(int p0, int p1, int p2) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int index_reg_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_17) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001368_6813_8(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct Transaction_R001368_6813_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int delta_16 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_16 > 11) {
        acc = (acc + delta_16 * 2 + 5) & 127;
        aux ^= (delta_16 & 15);
    } else {
        acc = (acc - delta_16 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int checksum_68 = local_arr[aux % 3];
    acc = (acc + checksum_68 * 2) & 127;
    int window_74 = 0;
    for (int k = 0; k < 2; k++) {
        window_74 = (window_74 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + window_74) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_9(int p0, int p1, int p2) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int index_reg_16 = (aux + st.buffer[1]) & 3;
    switch (index_reg_16) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int pivot_20 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_20 = (pivot_20 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_20) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_10(int p0, int p1) {
    int acc = (p0 + 13) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001368_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int quantum_33 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_33 > 27) {
        acc = (acc + quantum_33 * 2 + 5) & 127;
        aux ^= (quantum_33 & 15);
    } else {
        acc = (acc - quantum_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int quotient_47 = local_arr[aux % 3];
    acc = (acc + quotient_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001368_6813_11(int p0, int p1, int p2) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int parity_12 = (aux + st.buffer[1]) & 3;
    switch (parity_12) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int margin_13 = 0;
    for (int k = 0; k < 2; k++) {
        margin_13 = (margin_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_13) & 127;
    }
    int quotient_20 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_20) & 63;
    acc ^= aux;
    int stride_76 = (st.buffer[0] * 3 + aux) & 63;
    if (stride_76 > 12) {
        acc = (acc + stride_76 * 2 + 5) & 127;
        aux ^= (stride_76 & 15);
    } else {
        acc = (acc - stride_76 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001368_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 23;
    int local_arr[3] = {4, 9, 15};
    int bound_55 = local_arr[aux % 3];
    acc = (acc + bound_55 * 2) & 127;
    int factor_86 = (st.buffer[0] * 3 + aux) & 63;
    if (factor_86 > 16) {
        acc = (acc + factor_86 * 2 + 5) & 127;
        aux ^= (factor_86 & 15);
    } else {
        acc = (acc - factor_86 + 11) & 127;
        aux += 3;
    }
    int coefficient_93 = (aux + st.buffer[1]) & 3;
    switch (coefficient_93) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int residue_22 = 0;
    for (int k = 0; k < 3; k++) {
        residue_22 = (residue_22 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + residue_22) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_13(int p0, int p1, int p2) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int window_56 = (aux + st.buffer[1]) & 3;
    switch (window_56) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_32 = (st.buffer[0] * 3 + aux) & 63;
    if (window_32 > 24) {
        acc = (acc + window_32 * 2 + 5) & 127;
        aux ^= (window_32 & 15);
    } else {
        acc = (acc - window_32 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_14(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001368_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int tracker_80 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + tracker_80) & 63;
    acc ^= aux;
    int tracker_89 = (aux + st.buffer[1]) & 3;
    switch (tracker_89) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_15(int p0, int p1) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct FilterState_R001368_6813_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int parity_33 = (st.buffer[0] * 3 + aux) & 63;
    if (parity_33 > 35) {
        acc = (acc + parity_33 * 2 + 5) & 127;
        aux ^= (parity_33 & 15);
    } else {
        acc = (acc - parity_33 + 11) & 127;
        aux += 3;
    }
    int coefficient_30 = 0;
    for (int k = 0; k < 2; k++) {
        coefficient_30 = (coefficient_30 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + coefficient_30) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_16(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001368_6813_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 19;
    int vector_13 = (aux + st.buffer[1]) & 3;
    switch (vector_13) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int window_53 = local_arr[aux % 3];
    acc = (acc + window_53 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001368_6813_17(int p0, int p1) {
    int acc = (p0 + 27) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001368_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int anchor_86 = 0;
    for (int k = 0; k < 2; k++) {
        anchor_86 = (anchor_86 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + anchor_86) & 127;
    }
    int quantum_35 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quantum_35) & 63;
    acc ^= aux;
    int anchor_98 = (st.buffer[0] * 3 + aux) & 63;
    if (anchor_98 > 25) {
        acc = (acc + anchor_98 * 2 + 5) & 127;
        aux ^= (anchor_98 & 15);
    } else {
        acc = (acc - anchor_98 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001368_6813_18(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R001368_6813_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_37 = 0;
    for (int k = 0; k < 3; k++) {
        stride_37 = (stride_37 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_37) & 127;
    }
    int anchor_33 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_33) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int metric_36 = (st.buffer[0] * 3 + aux) & 63;
    if (metric_36 > 47) {
        acc = (acc + metric_36 * 2 + 5) & 127;
        aux ^= (metric_36 & 15);
    } else {
        acc = (acc - metric_36 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001368_0;
    int sec_r001368_1;
    int sec_r001368_2;
    int sec_r001368_3;
    int sec_r001368_4;
    int sec_r001368_5;
    int sec_r001368_6;
    int sec_r001368_7;
    int sec_r001368_8;
    int sec_r001368_9;
    int sec_r001368_10;
    int sec_r001368_11;
    int sec_r001368_12;
    int sec_r001368_13;
    int sec_r001368_14;
    int sec_r001368_15;
    int pub_r001368_0;
    int pub_r001368_1;
    int pub_r001368_2;
    int pub_r001368_3;
    int pub_r001368_4;
    int pub_r001368_5;
    int pub_r001368_6;
    int pub_r001368_7;
    int pub_r001368_8;
    int pub_r001368_9;
    int pub_r001368_10;
    int pub_r001368_11;
    int pub_r001368_12;
    int pub_r001368_13;
    int pub_r001368_14;
    int pub_r001368_15;
    int pub_r001368_16;
    int pub_r001368_17;
    int pub_r001368_18;
    int pub_r001368_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001368_0 >= -100 && pub_r001368_0 <= 100);
    __CPROVER_assume(pub_r001368_1 >= -100 && pub_r001368_1 <= 100);
    __CPROVER_assume(pub_r001368_2 >= -100 && pub_r001368_2 <= 100);
    __CPROVER_assume(pub_r001368_3 >= -100 && pub_r001368_3 <= 100);
    __CPROVER_assume(pub_r001368_4 >= -100 && pub_r001368_4 <= 100);
    __CPROVER_assume(pub_r001368_5 >= -100 && pub_r001368_5 <= 100);
    __CPROVER_assume(pub_r001368_6 >= -100 && pub_r001368_6 <= 100);
    __CPROVER_assume(pub_r001368_7 >= -100 && pub_r001368_7 <= 100);
    __CPROVER_assume(pub_r001368_8 >= -100 && pub_r001368_8 <= 100);
    __CPROVER_assume(pub_r001368_9 >= -100 && pub_r001368_9 <= 100);
    __CPROVER_assume(pub_r001368_10 >= -100 && pub_r001368_10 <= 100);
    __CPROVER_assume(pub_r001368_11 >= -100 && pub_r001368_11 <= 100);
    __CPROVER_assume(pub_r001368_12 >= -100 && pub_r001368_12 <= 100);
    __CPROVER_assume(pub_r001368_13 >= -100 && pub_r001368_13 <= 100);
    __CPROVER_assume(pub_r001368_14 >= -100 && pub_r001368_14 <= 100);
    __CPROVER_assume(pub_r001368_15 >= -100 && pub_r001368_15 <= 100);
    __CPROVER_assume(pub_r001368_16 >= -100 && pub_r001368_16 <= 100);
    __CPROVER_assume(pub_r001368_17 >= -100 && pub_r001368_17 <= 100);
    __CPROVER_assume(pub_r001368_18 >= -100 && pub_r001368_18 <= 100);
    __CPROVER_assume(pub_r001368_19 >= -100 && pub_r001368_19 <= 100);
    __CPROVER_assume(sec_r001368_0 >= 0 && sec_r001368_0 <= 255);
    __CPROVER_assume(sec_r001368_1 >= 0 && sec_r001368_1 <= 255);
    __CPROVER_assume(sec_r001368_2 >= 0 && sec_r001368_2 <= 255);
    __CPROVER_assume(sec_r001368_3 >= 0 && sec_r001368_3 <= 255);
    __CPROVER_assume(sec_r001368_4 >= 0 && sec_r001368_4 <= 255);
    __CPROVER_assume(sec_r001368_5 >= 0 && sec_r001368_5 <= 255);
    __CPROVER_assume(sec_r001368_6 >= 0 && sec_r001368_6 <= 255);
    __CPROVER_assume(sec_r001368_7 >= 0 && sec_r001368_7 <= 255);
    __CPROVER_assume(sec_r001368_8 >= 0 && sec_r001368_8 <= 255);
    __CPROVER_assume(sec_r001368_9 >= 0 && sec_r001368_9 <= 255);
    __CPROVER_assume(sec_r001368_10 >= 0 && sec_r001368_10 <= 255);
    __CPROVER_assume(sec_r001368_11 >= 0 && sec_r001368_11 <= 255);
    __CPROVER_assume(sec_r001368_12 >= 0 && sec_r001368_12 <= 255);
    __CPROVER_assume(sec_r001368_13 >= 0 && sec_r001368_13 <= 255);
    __CPROVER_assume(sec_r001368_14 >= 0 && sec_r001368_14 <= 255);
    __CPROVER_assume(sec_r001368_15 >= 0 && sec_r001368_15 <= 255);

    struct Transaction_R001368_6813_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001368_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001368_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001368_0 + 7) & 15;
    struct MatrixBlock_R001368_6813_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001368_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001368_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001368_0 + 9) & 15;
    struct FilterState_R001368_6813_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001368_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001368_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001368_0 + 11) & 15;
    struct EventLog_R001368_6813_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001368_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001368_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001368_0 + 13) & 15;

    union ColorPixel_R001368_6813_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001368_6813_0(sec_r001368_0, sec_r001368_1);
    int helper_flow_1 = fn_R001368_6813_1(sec_r001368_1, sec_r001368_2, pub_r001368_3);
    int helper_flow_2 = fn_R001368_6813_2(sec_r001368_2, pub_r001368_3, pub_r001368_4);
    int helper_flow_3 = fn_R001368_6813_3(sec_r001368_3, pub_r001368_4);
    int helper_flow_4 = fn_R001368_6813_4(sec_r001368_4, pub_r001368_5, pub_r001368_6);
    int helper_flow_5 = fn_R001368_6813_5(sec_r001368_5, sec_r001368_6, pub_r001368_7);
    int helper_flow_6 = fn_R001368_6813_6(sec_r001368_6, pub_r001368_7, pub_r001368_8, pub_r001368_9, pub_r001368_10);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_0 = (stage_v_0 + it * 3 + (helper_flow_1 & 15)) & 63;
        if ((helper_flow_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_0 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_0 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_1 = (stage_v_1 + it * 3 + (sec_r001368_4 & 15)) & 63;
        if ((sec_r001368_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_1 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_1 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_2 = (stage_v_2 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_2 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_2 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_3 = (stage_v_3 + it * 3 + (sec_r001368_13 & 15)) & 63;
        if ((sec_r001368_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_3 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_3 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (pub_r001368_12 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_4) & 127;

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_5 = (stage_v_5 + it * 3 + (sec_r001368_3 & 15)) & 63;
        if ((sec_r001368_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_5 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_5 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_6 = (stage_v_6 + it * 3 + (sec_r001368_7 & 15)) & 63;
        if ((sec_r001368_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_6 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_6 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_7 = (stage_v_7 + it * 3 + (sec_r001368_4 & 15)) & 63;
        if ((sec_r001368_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_7 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_7 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (pub_r001368_17 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_8) & 127;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_9 = (stage_v_9 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_9 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_9 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001368_13 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001368_1 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_12 = (stage_v_12 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_12 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_12 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_13 = (stage_v_13 + it * 3 + (sec_r001368_8 & 15)) & 63;
        if ((sec_r001368_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_13 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_13 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001368_4 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001368_14 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_16 = (stage_v_16 + it * 3 + (sec_r001368_2 & 15)) & 63;
        if ((sec_r001368_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_16 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_16 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001368_13 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001368_10 * 2 + 5) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_19 = (stage_v_19 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_19 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_19 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_20 = (stage_v_20 + it * 3 + (sec_r001368_4 & 15)) & 63;
        if ((sec_r001368_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_20 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_20 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (pub_r001368_13 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_21) & 127;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (pub_r001368_18 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_22) & 127;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_23 = (stage_v_23 + it * 3 + (sec_r001368_8 & 15)) & 63;
        if ((sec_r001368_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_23 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_23 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_24 = (stage_v_24 + it * 3 + (sec_r001368_7 & 15)) & 63;
        if ((sec_r001368_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_24 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_24 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_25 = (stage_v_25 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_25 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_25 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001368_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (pub_r001368_15 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_27) & 127;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_28 = (stage_v_28 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_28 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_28 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (pub_r001368_11 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_29) & 127;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_30 = (stage_v_30 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_30 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_30 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_31 = (stage_v_31 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_31 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_31 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_32 = (stage_v_32 + it * 3 + (sec_r001368_1 & 15)) & 63;
        if ((sec_r001368_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_32 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_32 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_33 = (stage_v_33 + it * 3 + (sec_r001368_7 & 15)) & 63;
        if ((sec_r001368_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_33 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_33 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (pub_r001368_13 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_34) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_35 = (stage_v_35 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_35 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_35 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_36 = (stage_v_36 + it * 3 + (sec_r001368_7 & 15)) & 63;
        if ((sec_r001368_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_36 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_36 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_37 = (stage_v_37 + it * 3 + (sec_r001368_2 & 15)) & 63;
        if ((sec_r001368_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_37 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_37 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_38 = (stage_v_38 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_38 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_38 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_39 = (stage_v_39 + it * 3 + (stage_v_6 & 15)) & 63;
        if ((stage_v_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_39 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_39 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (pub_r001368_12 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_40) & 127;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (pub_r001368_19 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_41) & 127;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_42 = (stage_v_42 + it * 3 + (helper_flow_3 & 15)) & 63;
        if ((helper_flow_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_42 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_42 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_43 = (stage_v_43 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_43 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_43 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_44 = (stage_v_44 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_44 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_44 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_45 = (stage_v_45 + it * 3 + (sec_r001368_5 & 15)) & 63;
        if ((sec_r001368_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_45 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_45 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_46 = (stage_v_46 + it * 3 + (sec_r001368_14 & 15)) & 63;
        if ((sec_r001368_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_46 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_46 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_47 = (stage_v_47 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_47 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_47 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001368_11 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (pub_r001368_2 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_49) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (pub_r001368_10 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_50) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001368_2 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001368_4 * 2 + 36) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_53 = (stage_v_53 + it * 3 + (stage_v_20 & 15)) & 63;
        if ((stage_v_20 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_53 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_53 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_54 = (stage_v_54 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_54 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_54 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001368_1 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_56 = (stage_v_56 + it * 3 + (stage_v_19 & 15)) & 63;
        if ((stage_v_19 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_56 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_56 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_57 = (stage_v_57 + it * 3 + (sec_r001368_8 & 15)) & 63;
        if ((sec_r001368_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_57 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_57 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_58 = (stage_v_58 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_58 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_58 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_59 = (stage_v_59 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_59 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_59 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_60 = (stage_v_60 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_60 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_60 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001368_19 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_62 = (stage_v_62 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_62 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_62 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_63 = (stage_v_63 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_63 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_63 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_64 = (stage_v_64 + it * 3 + (sec_r001368_11 & 15)) & 63;
        if ((sec_r001368_11 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_64 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_64 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_65 = (stage_v_65 + it * 3 + (stage_v_36 & 15)) & 63;
        if ((stage_v_36 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_65 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_65 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_66 = (stage_v_66 + it * 3 + (stage_v_39 & 15)) & 63;
        if ((stage_v_39 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_66 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_66 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_67 = (stage_v_67 + it * 3 + (stage_v_58 & 15)) & 63;
        if ((stage_v_58 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_67 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_67 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (pub_r001368_11 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_68) & 127;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_69 = (stage_v_69 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_69 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_69 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (pub_r001368_19 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_70) & 127;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_71 = (stage_v_71 + it * 3 + (stage_v_56 & 15)) & 63;
        if ((stage_v_56 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_71 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_71 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_72 = (stage_v_72 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_72 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_72 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_73 = (stage_v_73 + it * 3 + (stage_v_39 & 15)) & 63;
        if ((stage_v_39 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_73 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_73 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_74 = (stage_v_74 + it * 3 + (stage_v_38 & 15)) & 63;
        if ((stage_v_38 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_74 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_74 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001368_8 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_76 = (stage_v_76 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_76 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_76 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (pub_r001368_14 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_77) & 127;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_78 = (stage_v_78 + it * 3 + (sec_r001368_1 & 15)) & 63;
        if ((sec_r001368_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_78 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_78 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_79 = (stage_v_79 + it * 3 + (helper_flow_4 & 15)) & 63;
        if ((helper_flow_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_79 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_79 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_80 = (stage_v_80 + it * 3 + (stage_v_3 & 15)) & 63;
        if ((stage_v_3 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_80 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_80 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (pub_r001368_13 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_81) & 127;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_82 = (stage_v_82 + it * 3 + (stage_v_80 & 15)) & 63;
        if ((stage_v_80 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_82 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_82 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_83 = (stage_v_83 + it * 3 + (stage_v_62 & 15)) & 63;
        if ((stage_v_62 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_83 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_83 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_84 = (stage_v_84 + it * 3 + (stage_v_65 & 15)) & 63;
        if ((stage_v_65 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_84 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_84 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_85 = (stage_v_85 + it * 3 + (sec_r001368_10 & 15)) & 63;
        if ((sec_r001368_10 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_85 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_85 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_86 = (stage_v_86 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_86 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_86 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_87 = (stage_v_87 + it * 3 + (stage_v_80 & 15)) & 63;
        if ((stage_v_80 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_87 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_87 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_88 = (stage_v_88 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_88 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_88 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_89 = (stage_v_89 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_89 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_89 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_90 = (stage_v_90 + it * 3 + (sec_r001368_1 & 15)) & 63;
        if ((sec_r001368_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_90 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_90 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_91 = (stage_v_91 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_91 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_91 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_92 = (stage_v_92 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_92 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_92 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (pub_r001368_7 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_93) & 127;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_94 = (stage_v_94 + it * 3 + (stage_v_66 & 15)) & 63;
        if ((stage_v_66 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_94 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_94 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001368_6 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (pub_r001368_1 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_96) & 127;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_97 = (stage_v_97 + it * 3 + (stage_v_73 & 15)) & 63;
        if ((stage_v_73 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_97 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_97 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_98 = (stage_v_98 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_98 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_98 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_99 = (stage_v_99 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_99 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_99 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_100 = (stage_v_100 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_100 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_100 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_101 = (stage_v_101 + it * 3 + (sec_r001368_7 & 15)) & 63;
        if ((sec_r001368_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_101 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_101 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_102 = (stage_v_102 + it * 3 + (stage_v_32 & 15)) & 63;
        if ((stage_v_32 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_102 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_102 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_103 = (stage_v_103 + it * 3 + (stage_v_85 & 15)) & 63;
        if ((stage_v_85 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_103 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_103 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_104 = (stage_v_104 + it * 3 + (sec_r001368_6 & 15)) & 63;
        if ((sec_r001368_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_104 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_104 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_105 = (stage_v_105 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_105 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_105 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (pub_r001368_13 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_106) & 127;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (pub_r001368_17 * 2 + 34) & 63;
    chk_sum = (chk_sum + stage_v_107) & 127;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_108 = (stage_v_108 + it * 3 + (sec_r001368_4 & 15)) & 63;
        if ((sec_r001368_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_108 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_108 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (pub_r001368_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_109) & 127;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_110 = (stage_v_110 + it * 3 + (stage_v_54 & 15)) & 63;
        if ((stage_v_54 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_110 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_110 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (pub_r001368_12 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_111) & 127;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_112 = (stage_v_112 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_112 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_112 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001368_7 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001368_1 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (pub_r001368_16 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_115) & 127;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_116 = (stage_v_116 + it * 3 + (helper_flow_2 & 15)) & 63;
        if ((helper_flow_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_116 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_116 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001368_13 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_118 = (stage_v_118 + it * 3 + (stage_v_78 & 15)) & 63;
        if ((stage_v_78 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_118 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_118 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001368_7 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_120 = (stage_v_120 + it * 3 + (stage_v_39 & 15)) & 63;
        if ((stage_v_39 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_120 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_120 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_121 = (stage_v_121 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_121 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_121 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_122 = (stage_v_122 + it * 3 + (stage_v_2 & 15)) & 63;
        if ((stage_v_2 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_122 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_122 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (pub_r001368_8 * 2 + 16) & 63;
    chk_sum = (chk_sum + stage_v_123) & 127;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_124 = (stage_v_124 + it * 3 + (stage_v_112 & 15)) & 63;
        if ((stage_v_112 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_124 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_124 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (pub_r001368_13 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_125) & 127;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_126 = (stage_v_126 + it * 3 + (stage_v_1 & 15)) & 63;
        if ((stage_v_1 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_126 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_126 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_127 = (stage_v_127 + it * 3 + (helper_flow_5 & 15)) & 63;
        if ((helper_flow_5 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_127 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_127 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_128 = (stage_v_128 + it * 3 + (sec_r001368_12 & 15)) & 63;
        if ((sec_r001368_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_128 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_128 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_129 = (stage_v_129 + it * 3 + (stage_v_83 & 15)) & 63;
        if ((stage_v_83 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_129 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_129 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_130 = (stage_v_130 + it * 3 + (sec_r001368_4 & 15)) & 63;
        if ((sec_r001368_4 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_130 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_130 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_131 = (stage_v_131 + it * 3 + (stage_v_23 & 15)) & 63;
        if ((stage_v_23 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_131 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_131 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (pub_r001368_6 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_132) & 127;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (pub_r001368_5 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_133) & 127;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (pub_r001368_15 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_134) & 127;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_135 = (stage_v_135 + it * 3 + (stage_v_57 & 15)) & 63;
        if ((stage_v_57 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_135 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_135 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (pub_r001368_19 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_136) & 127;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (pub_r001368_10 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_137) & 127;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_138 = (stage_v_138 + it * 3 + (stage_v_13 & 15)) & 63;
        if ((stage_v_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_138 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_138 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001368_10 * 2 + 45) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_140 = (stage_v_140 + it * 3 + (stage_v_100 & 15)) & 63;
        if ((stage_v_100 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_140 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_140 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (pub_r001368_18 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_141) & 127;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_142 = (stage_v_142 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_142 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_142 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001368_16 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001368_3 * 2 + 10) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001368_3 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_146 = (stage_v_146 + it * 3 + (stage_v_24 & 15)) & 63;
        if ((stage_v_24 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_146 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_146 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_147 = (stage_v_147 + it * 3 + (stage_v_128 & 15)) & 63;
        if ((stage_v_128 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_147 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_147 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001368_12 * 2 + 39) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_149 = (stage_v_149 + it * 3 + (stage_v_25 & 15)) & 63;
        if ((stage_v_25 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_149 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_149 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_150 = (stage_v_150 + it * 3 + (stage_v_0 & 15)) & 63;
        if ((stage_v_0 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_150 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_150 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (pub_r001368_9 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_151) & 127;

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001368_9 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_153 = (stage_v_153 + it * 3 + (stage_v_35 & 15)) & 63;
        if ((stage_v_35 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_153 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_153 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_154 = (stage_v_154 + it * 3 + (stage_v_16 & 15)) & 63;
        if ((stage_v_16 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_154 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_154 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_155 = (stage_v_155 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_155 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_155 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_156 = (stage_v_156 + it * 3 + (stage_v_118 & 15)) & 63;
        if ((stage_v_118 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_156 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_156 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_157 = (stage_v_157 + it * 3 + (helper_flow_6 & 15)) & 63;
        if ((helper_flow_6 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_157 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_157 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (pub_r001368_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_158) & 127;

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_159 = (stage_v_159 + it * 3 + (stage_v_43 & 15)) & 63;
        if ((stage_v_43 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_159 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_159 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (pub_r001368_15 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_160) & 127;

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_161 = (stage_v_161 + it * 3 + (sec_r001368_8 & 15)) & 63;
        if ((sec_r001368_8 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_161 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_161 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_162 = (stage_v_162 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_162 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_162 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_163 = (stage_v_163 + it * 3 + (stage_v_12 & 15)) & 63;
        if ((stage_v_12 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_163 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_163 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_164 = (stage_v_164 + it * 3 + (stage_v_84 & 15)) & 63;
        if ((stage_v_84 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_164 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_164 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (pub_r001368_13 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_165) & 127;

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_166 = (stage_v_166 + it * 3 + (stage_v_53 & 15)) & 63;
        if ((stage_v_53 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_166 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_166 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_167 = (stage_v_167 + it * 3 + (stage_v_7 & 15)) & 63;
        if ((stage_v_7 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_167 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_167 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_168 = (stage_v_168 + it * 3 + (sec_r001368_14 & 15)) & 63;
        if ((sec_r001368_14 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_168 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_168 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_169 = (stage_v_169 + it * 3 + (stage_v_9 & 15)) & 63;
        if ((stage_v_9 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_169 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_169 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_170 = (stage_v_170 + it * 3 + (stage_v_91 & 15)) & 63;
        if ((stage_v_91 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_170 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_170 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_171 = (stage_v_171 + it * 3 + (stage_v_149 & 15)) & 63;
        if ((stage_v_149 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_171 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_171 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_172 = (stage_v_172 + it * 3 + (stage_v_37 & 15)) & 63;
        if ((stage_v_37 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_172 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_172 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_173 = (stage_v_173 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_173 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_173 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001368_9 * 2 + 12) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_175 = (stage_v_175 + it * 3 + (stage_v_101 & 15)) & 63;
        if ((stage_v_101 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_175 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_175 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_176 = (stage_v_176 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_176 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_176 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_177 = (stage_v_177 + it * 3 + (stage_v_130 & 15)) & 63;
        if ((stage_v_130 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_177 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_177 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_178 = (stage_v_178 + it * 3 + (stage_v_63 & 15)) & 63;
        if ((stage_v_63 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_178 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_178 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_179 = (stage_v_179 + it * 3 + (stage_v_72 & 15)) & 63;
        if ((stage_v_72 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_179 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_179 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_180 = (stage_v_180 + it * 3 + (stage_v_54 & 15)) & 63;
        if ((stage_v_54 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_180 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_180 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_181 = (stage_v_181 + it * 3 + (sec_r001368_13 & 15)) & 63;
        if ((sec_r001368_13 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_181 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_181 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_182 = (stage_v_182 + it * 3 + (stage_v_67 & 15)) & 63;
        if ((stage_v_67 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_182 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_182 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_183 = (stage_v_183 + it * 3 + (stage_v_74 & 15)) & 63;
        if ((stage_v_74 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_183 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_183 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_184 = (stage_v_184 + it * 3 + (stage_v_44 & 15)) & 63;
        if ((stage_v_44 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_184 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_184 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_185 = (stage_v_185 + it * 3 + (stage_v_31 & 15)) & 63;
        if ((stage_v_31 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_185 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_185 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_186 = (stage_v_186 + it * 3 + (stage_v_99 & 15)) & 63;
        if ((stage_v_99 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_186 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_186 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_187 = (stage_v_187 + it * 3 + (stage_v_82 & 15)) & 63;
        if ((stage_v_82 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_187 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_187 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_188 = (stage_v_188 + it * 3 + (stage_v_64 & 15)) & 63;
        if ((stage_v_64 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_188 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_188 + 7) & 255;
        }
    }

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001368_6 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = 0;
    for (int it = 0; it < 2; it++) {
        stage_v_190 = (stage_v_190 + it * 3 + (stage_v_163 & 15)) & 63;
        if ((stage_v_163 & 1) != 0) {
            sec_accum = (sec_accum + stage_v_190 + 3) & 255;
        } else {
            sec_accum = (sec_accum - stage_v_190 + 7) & 255;
        }
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
