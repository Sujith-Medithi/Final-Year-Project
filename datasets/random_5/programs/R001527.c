/*
 * Benchmark Program: R001527
 * Security Family: nested_implicit_flow
 * Generator Seed: 652713
 * High Inputs: 19 | Low Inputs: 20
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R001527_2713_0 {
    unsigned char stop_bits;
    int id;
    int timeout;
    unsigned char port;
    int buffer[3];
};

struct CipherContext_R001527_2713_1 {
    int counter;
    short tag;
    int flags;
    unsigned char nonce;
    int buffer[3];
};

struct AudioFrame_R001527_2713_2 {
    short rms;
    short envelope;
    short peak;
    unsigned char sample_rate;
    int buffer[3];
};

struct MatrixBlock_R001527_2713_3 {
    int stride;
    unsigned char determinant;
    int scale;
    int density;
    unsigned char dim;
    int buffer[3];
};

union TelemetryField_R001527_2713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union PacketPayload_R001527_2713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R001527_2713_0(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 4) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int local_arr[3] = {4, 9, 15};
    int anchor_37 = local_arr[aux % 3];
    acc = (acc + anchor_37 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_17 = (st.buffer[0] * 3 + aux) & 63;
    if (vector_17 > 45) {
        acc = (acc + vector_17 * 2 + 5) & 127;
        aux ^= (vector_17 & 15);
    } else {
        acc = (acc - vector_17 + 11) & 127;
        aux += 3;
    }
    int sample_21 = (aux + st.buffer[1]) & 3;
    switch (sample_21) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001527_2713_1(int p0, int p1, int p2) {
    int acc = (p0 + 17) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int factor_50 = 0;
    for (int k = 0; k < 3; k++) {
        factor_50 = (factor_50 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_50) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int damping_85 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_85 > 19) {
        acc = (acc + damping_85 * 2 + 5) & 127;
        aux ^= (damping_85 & 15);
    } else {
        acc = (acc - damping_85 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R001527_2713_2(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 37) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int residue_85 = (st.buffer[0] * 3 + aux) & 63;
    if (residue_85 > 18) {
        acc = (acc + residue_85 * 2 + 5) & 127;
        aux ^= (residue_85 & 15);
    } else {
        acc = (acc - residue_85 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int quotient_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_71) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tally_47 = local_arr[aux % 3];
    acc = (acc + tally_47 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 46) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int stride_80 = 0;
    for (int k = 0; k < 2; k++) {
        stride_80 = (stride_80 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + stride_80) & 127;
    }
    int accumulator_52 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_52 > 11) {
        acc = (acc + accumulator_52 * 2 + 5) & 127;
        aux ^= (accumulator_52 & 15);
    } else {
        acc = (acc - accumulator_52 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_4(int p0, int p1) {
    int acc = (p0 + 9) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int checksum_13 = 0;
    for (int k = 0; k < 3; k++) {
        checksum_13 = (checksum_13 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + checksum_13) & 127;
    }
    int parity_86 = (aux + st.buffer[1]) & 3;
    switch (parity_86) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int vector_28 = local_arr[aux % 3];
    acc = (acc + vector_28 * 2) & 127;
    int weight_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + weight_41) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001527_2713_5(int p0, int p1) {
    int acc = (p0 + 50) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int quotient_23 = 0;
    for (int k = 0; k < 2; k++) {
        quotient_23 = (quotient_23 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + quotient_23) & 127;
    }
    int quantum_19 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_19 > 47) {
        acc = (acc + quantum_19 * 2 + 5) & 127;
        aux ^= (quantum_19 & 15);
    } else {
        acc = (acc - quantum_19 + 11) & 127;
        aux += 3;
    }
    int quantum_36 = (aux + st.buffer[1]) & 3;
    switch (quantum_36) {
        case 0: acc = (acc + 8) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001527_2713_6(int p0, int p1) {
    int acc = (p0 + 2) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int margin_51 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + margin_51) & 63;
    acc ^= aux;
    int tracker_57 = (aux + st.buffer[1]) & 3;
    switch (tracker_57) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_55 = (st.buffer[0] * 3 + aux) & 63;
    if (pivot_55 > 26) {
        acc = (acc + pivot_55 * 2 + 5) & 127;
        aux ^= (pivot_55 & 15);
    } else {
        acc = (acc - pivot_55 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int offset_41 = local_arr[aux % 3];
    acc = (acc + offset_41 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_7(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 11;
    int mask_81 = 0;
    for (int k = 0; k < 3; k++) {
        mask_81 = (mask_81 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + mask_81) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int bound_58 = (aux + st.buffer[1]) & 3;
    switch (bound_58) {
        case 0: acc = (acc + 7) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int index_reg_98 = local_arr[aux % 3];
    acc = (acc + index_reg_98 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_8(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 43) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 14;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int parity_99 = local_arr[aux % 3];
    acc = (acc + parity_99 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_9(int p0, int p1, int p2) {
    int acc = (p0 + 40) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R001527_2713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int index_reg_24 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + index_reg_24) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int margin_40 = local_arr[aux % 3];
    acc = (acc + margin_40 * 2) & 127;
    int margin_64 = 0;
    for (int k = 0; k < 2; k++) {
        margin_64 = (margin_64 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + margin_64) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001527_2713_10(int p0, int p1, int p2) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int pivot_55 = 0;
    for (int k = 0; k < 3; k++) {
        pivot_55 = (pivot_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + pivot_55) & 127;
    }
    int cursor_65 = (aux + st.buffer[1]) & 3;
    switch (cursor_65) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R001527_2713_11(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 35) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int offset_55 = (aux + st.buffer[1]) & 3;
    switch (offset_55) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int checksum_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + checksum_16) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R001527_2713_12(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R001527_2713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int local_arr[3] = {4, 9, 15};
    int offset_21 = local_arr[aux % 3];
    acc = (acc + offset_21 * 2) & 127;
    int damping_71 = 0;
    for (int k = 0; k < 2; k++) {
        damping_71 = (damping_71 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + damping_71) & 127;
    }
    int margin_82 = (aux + st.buffer[1]) & 3;
    switch (margin_82) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R001527_2713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 3) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int segment_56 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_56 > 12) {
        acc = (acc + segment_56 * 2 + 5) & 127;
        aux ^= (segment_56 & 15);
    } else {
        acc = (acc - segment_56 + 11) & 127;
        aux += 3;
    }
    int factor_88 = 0;
    for (int k = 0; k < 2; k++) {
        factor_88 = (factor_88 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_88) & 127;
    }
    return (acc + aux) & 255;
}

int fn_R001527_2713_14(int p0, int p1) {
    int acc = (p0 + 11) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 7;
    int delta_35 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_35 > 43) {
        acc = (acc + delta_35 * 2 + 5) & 127;
        aux ^= (delta_35 & 15);
    } else {
        acc = (acc - delta_35 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_95 = local_arr[aux % 3];
    acc = (acc + weight_95 * 2) & 127;
    int offset_55 = 0;
    for (int k = 0; k < 3; k++) {
        offset_55 = (offset_55 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + offset_55) & 127;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R001527_2713_15(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R001527_2713_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 12;
    int accumulator_16 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_16) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_86 = (st.buffer[0] * 3 + aux) & 63;
    if (window_86 > 49) {
        acc = (acc + window_86 * 2 + 5) & 127;
        aux ^= (window_86 & 15);
    } else {
        acc = (acc - window_86 + 11) & 127;
        aux += 3;
    }
    int factor_15 = 0;
    for (int k = 0; k < 3; k++) {
        factor_15 = (factor_15 + k * 4 + st.buffer[k % 3]) & 31;
        acc = (acc + factor_15) & 127;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r001527_0;
    int sec_r001527_1;
    int sec_r001527_2;
    int sec_r001527_3;
    int sec_r001527_4;
    int sec_r001527_5;
    int sec_r001527_6;
    int sec_r001527_7;
    int sec_r001527_8;
    int sec_r001527_9;
    int sec_r001527_10;
    int sec_r001527_11;
    int sec_r001527_12;
    int sec_r001527_13;
    int sec_r001527_14;
    int sec_r001527_15;
    int sec_r001527_16;
    int sec_r001527_17;
    int sec_r001527_18;
    int pub_r001527_0;
    int pub_r001527_1;
    int pub_r001527_2;
    int pub_r001527_3;
    int pub_r001527_4;
    int pub_r001527_5;
    int pub_r001527_6;
    int pub_r001527_7;
    int pub_r001527_8;
    int pub_r001527_9;
    int pub_r001527_10;
    int pub_r001527_11;
    int pub_r001527_12;
    int pub_r001527_13;
    int pub_r001527_14;
    int pub_r001527_15;
    int pub_r001527_16;
    int pub_r001527_17;
    int pub_r001527_18;
    int pub_r001527_19;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r001527_0 >= -100 && pub_r001527_0 <= 100);
    __CPROVER_assume(pub_r001527_1 >= -100 && pub_r001527_1 <= 100);
    __CPROVER_assume(pub_r001527_2 >= -100 && pub_r001527_2 <= 100);
    __CPROVER_assume(pub_r001527_3 >= -100 && pub_r001527_3 <= 100);
    __CPROVER_assume(pub_r001527_4 >= -100 && pub_r001527_4 <= 100);
    __CPROVER_assume(pub_r001527_5 >= -100 && pub_r001527_5 <= 100);
    __CPROVER_assume(pub_r001527_6 >= -100 && pub_r001527_6 <= 100);
    __CPROVER_assume(pub_r001527_7 >= -100 && pub_r001527_7 <= 100);
    __CPROVER_assume(pub_r001527_8 >= -100 && pub_r001527_8 <= 100);
    __CPROVER_assume(pub_r001527_9 >= -100 && pub_r001527_9 <= 100);
    __CPROVER_assume(pub_r001527_10 >= -100 && pub_r001527_10 <= 100);
    __CPROVER_assume(pub_r001527_11 >= -100 && pub_r001527_11 <= 100);
    __CPROVER_assume(pub_r001527_12 >= -100 && pub_r001527_12 <= 100);
    __CPROVER_assume(pub_r001527_13 >= -100 && pub_r001527_13 <= 100);
    __CPROVER_assume(pub_r001527_14 >= -100 && pub_r001527_14 <= 100);
    __CPROVER_assume(pub_r001527_15 >= -100 && pub_r001527_15 <= 100);
    __CPROVER_assume(pub_r001527_16 >= -100 && pub_r001527_16 <= 100);
    __CPROVER_assume(pub_r001527_17 >= -100 && pub_r001527_17 <= 100);
    __CPROVER_assume(pub_r001527_18 >= -100 && pub_r001527_18 <= 100);
    __CPROVER_assume(pub_r001527_19 >= -100 && pub_r001527_19 <= 100);
    __CPROVER_assume(sec_r001527_0 >= 0 && sec_r001527_0 <= 255);
    __CPROVER_assume(sec_r001527_1 >= 0 && sec_r001527_1 <= 255);
    __CPROVER_assume(sec_r001527_2 >= 0 && sec_r001527_2 <= 255);
    __CPROVER_assume(sec_r001527_3 >= 0 && sec_r001527_3 <= 255);
    __CPROVER_assume(sec_r001527_4 >= 0 && sec_r001527_4 <= 255);
    __CPROVER_assume(sec_r001527_5 >= 0 && sec_r001527_5 <= 255);
    __CPROVER_assume(sec_r001527_6 >= 0 && sec_r001527_6 <= 255);
    __CPROVER_assume(sec_r001527_7 >= 0 && sec_r001527_7 <= 255);
    __CPROVER_assume(sec_r001527_8 >= 0 && sec_r001527_8 <= 255);
    __CPROVER_assume(sec_r001527_9 >= 0 && sec_r001527_9 <= 255);
    __CPROVER_assume(sec_r001527_10 >= 0 && sec_r001527_10 <= 255);
    __CPROVER_assume(sec_r001527_11 >= 0 && sec_r001527_11 <= 255);
    __CPROVER_assume(sec_r001527_12 >= 0 && sec_r001527_12 <= 255);
    __CPROVER_assume(sec_r001527_13 >= 0 && sec_r001527_13 <= 255);
    __CPROVER_assume(sec_r001527_14 >= 0 && sec_r001527_14 <= 255);
    __CPROVER_assume(sec_r001527_15 >= 0 && sec_r001527_15 <= 255);
    __CPROVER_assume(sec_r001527_16 >= 0 && sec_r001527_16 <= 255);
    __CPROVER_assume(sec_r001527_17 >= 0 && sec_r001527_17 <= 255);
    __CPROVER_assume(sec_r001527_18 >= 0 && sec_r001527_18 <= 255);

    struct DeviceConfig_R001527_2713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r001527_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r001527_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r001527_0 + 7) & 15;
    struct CipherContext_R001527_2713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r001527_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r001527_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r001527_0 + 9) & 15;
    struct AudioFrame_R001527_2713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r001527_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r001527_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r001527_0 + 11) & 15;
    struct MatrixBlock_R001527_2713_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r001527_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r001527_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r001527_0 + 13) & 15;

    union TelemetryField_R001527_2713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Interprocedural Flow Pipeline */
    int helper_flow_0 = fn_R001527_2713_0(sec_r001527_0, pub_r001527_1, pub_r001527_2, pub_r001527_3);
    int helper_flow_1 = fn_R001527_2713_1(sec_r001527_1, pub_r001527_2, pub_r001527_3);
    int helper_flow_2 = fn_R001527_2713_2(sec_r001527_2, sec_r001527_3, pub_r001527_4, pub_r001527_5, pub_r001527_6);
    int helper_flow_3 = fn_R001527_2713_3(sec_r001527_3, pub_r001527_4, pub_r001527_5, pub_r001527_6, pub_r001527_7);
    int helper_flow_4 = fn_R001527_2713_4(sec_r001527_4, pub_r001527_5);
    int helper_flow_5 = fn_R001527_2713_5(sec_r001527_5, pub_r001527_6);
    int helper_flow_6 = fn_R001527_2713_6(sec_r001527_6, sec_r001527_7);
    int helper_flow_7 = fn_R001527_2713_7(sec_r001527_7, sec_r001527_8, pub_r001527_9);
    int helper_flow_8 = fn_R001527_2713_8(sec_r001527_8, pub_r001527_9, pub_r001527_10, pub_r001527_11, pub_r001527_12);
    int helper_flow_9 = fn_R001527_2713_9(sec_r001527_9, sec_r001527_10, pub_r001527_11);
    int helper_flow_10 = fn_R001527_2713_10(sec_r001527_10, sec_r001527_11, pub_r001527_12);

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (helper_flow_8 ^ pub_r001527_2) & 63;
    if ((stage_v_0 & 1) != 0) {
        if ((sec_r001527_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_0 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_0 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_0 * 2) & 255;
    }

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (pub_r001527_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_1) & 127;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = (helper_flow_7 ^ pub_r001527_16) & 63;
    if ((stage_v_2 & 1) != 0) {
        if ((sec_r001527_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_2 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_2 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_2 * 2) & 255;
    }

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (sec_r001527_4 ^ pub_r001527_5) & 63;
    if ((stage_v_3 & 1) != 0) {
        if ((sec_r001527_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_3 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_3 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_3 * 2) & 255;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = (helper_flow_10 ^ pub_r001527_0) & 63;
    if ((stage_v_4 & 1) != 0) {
        if ((sec_r001527_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_4 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_4 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_4 * 2) & 255;
    }

    /* Execution Pipeline Stage 5 */
    int stage_v_5 = (pub_r001527_8 * 2 + 43) & 63;
    chk_sum = (chk_sum + stage_v_5) & 127;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (sec_r001527_3 ^ pub_r001527_5) & 63;
    if ((stage_v_6 & 1) != 0) {
        if ((sec_r001527_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_6 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_6 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_6 * 2) & 255;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (stage_v_4 ^ pub_r001527_7) & 63;
    if ((stage_v_7 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_7 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_7 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_7 * 2) & 255;
    }

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (sec_r001527_14 ^ pub_r001527_17) & 63;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r001527_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_8 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_8 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_8 * 2) & 255;
    }

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = (sec_r001527_0 ^ pub_r001527_11) & 63;
    if ((stage_v_9 & 1) != 0) {
        if ((helper_flow_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_9 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_9 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_9 * 2) & 255;
    }

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = (pub_r001527_18 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_10) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = (pub_r001527_8 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_11) & 127;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = (stage_v_4 ^ pub_r001527_18) & 63;
    if ((stage_v_12 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_12 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_12 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_12 * 2) & 255;
    }

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = (sec_r001527_10 ^ pub_r001527_9) & 63;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r001527_11 & 2) != 0) {
            out_sink = (out_sink + stage_v_13 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_13 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_13 * 2) & 255;
    }

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (pub_r001527_3 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_14) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (pub_r001527_19 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_15) & 127;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = (helper_flow_5 ^ pub_r001527_16) & 63;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r001527_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_16 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_16 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_16 * 2) & 255;
    }

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = (pub_r001527_8 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_17) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = (pub_r001527_5 * 2 + 23) & 63;
    chk_sum = (chk_sum + stage_v_18) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (sec_r001527_5 ^ pub_r001527_18) & 63;
    if ((stage_v_19 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_19 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_19 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_19 * 2) & 255;
    }

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (sec_r001527_6 ^ pub_r001527_1) & 63;
    if ((stage_v_20 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_20 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_20 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_20 * 2) & 255;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (helper_flow_0 ^ pub_r001527_14) & 63;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r001527_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_21 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_21 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_21 * 2) & 255;
    }

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (stage_v_4 ^ pub_r001527_12) & 63;
    if ((stage_v_22 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_22 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_22 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_22 * 2) & 255;
    }

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = (sec_r001527_10 ^ pub_r001527_13) & 63;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r001527_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_23 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_23 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_23 * 2) & 255;
    }

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = (stage_v_12 ^ pub_r001527_2) & 63;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r001527_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_24 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_24 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_24 * 2) & 255;
    }

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = (sec_r001527_1 ^ pub_r001527_2) & 63;
    if ((stage_v_25 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_25 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_25 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_25 * 2) & 255;
    }

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = (pub_r001527_3 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_26) & 127;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = (sec_r001527_3 ^ pub_r001527_10) & 63;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r001527_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_27 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_27 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_27 * 2) & 255;
    }

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = (pub_r001527_11 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_28) & 127;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = (stage_v_16 ^ pub_r001527_14) & 63;
    if ((stage_v_29 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_29 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_29 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_29 * 2) & 255;
    }

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = (pub_r001527_10 * 2 + 48) & 63;
    chk_sum = (chk_sum + stage_v_30) & 127;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = (helper_flow_6 ^ pub_r001527_6) & 63;
    if ((stage_v_31 & 1) != 0) {
        if ((stage_v_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_31 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_31 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_31 * 2) & 255;
    }

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = (pub_r001527_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_32) & 127;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (helper_flow_1 ^ pub_r001527_3) & 63;
    if ((stage_v_33 & 1) != 0) {
        if ((sec_r001527_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_33 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_33 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_33 * 2) & 255;
    }

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (stage_v_21 ^ pub_r001527_11) & 63;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r001527_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_34 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_34 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_34 * 2) & 255;
    }

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (stage_v_0 ^ pub_r001527_14) & 63;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r001527_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_35 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_35 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_35 * 2) & 255;
    }

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = (sec_r001527_3 ^ pub_r001527_12) & 63;
    if ((stage_v_36 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_36 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_36 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_36 * 2) & 255;
    }

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (pub_r001527_18 * 2 + 30) & 63;
    chk_sum = (chk_sum + stage_v_37) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (stage_v_16 ^ pub_r001527_15) & 63;
    if ((stage_v_38 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_38 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_38 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_38 * 2) & 255;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (stage_v_36 ^ pub_r001527_18) & 63;
    if ((stage_v_39 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_39 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_39 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_39 * 2) & 255;
    }

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = (stage_v_27 ^ pub_r001527_15) & 63;
    if ((stage_v_40 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_40 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_40 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_40 * 2) & 255;
    }

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (helper_flow_9 ^ pub_r001527_8) & 63;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r001527_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_41 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_41 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_41 * 2) & 255;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = (sec_r001527_18 ^ pub_r001527_16) & 63;
    if ((stage_v_42 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_42 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_42 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_42 * 2) & 255;
    }

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (pub_r001527_8 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_43) & 127;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = (stage_v_36 ^ pub_r001527_4) & 63;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r001527_15 & 2) != 0) {
            out_sink = (out_sink + stage_v_44 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_44 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_44 * 2) & 255;
    }

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (pub_r001527_14 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_45) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = (sec_r001527_1 ^ pub_r001527_11) & 63;
    if ((stage_v_46 & 1) != 0) {
        if ((sec_r001527_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_46 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_46 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_46 * 2) & 255;
    }

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (pub_r001527_2 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_47) & 127;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = (pub_r001527_10 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_48) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (stage_v_21 ^ pub_r001527_13) & 63;
    if ((stage_v_49 & 1) != 0) {
        if ((stage_v_2 & 2) != 0) {
            out_sink = (out_sink + stage_v_49 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_49 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_49 * 2) & 255;
    }

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (stage_v_19 ^ pub_r001527_16) & 63;
    if ((stage_v_50 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_50 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_50 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_50 * 2) & 255;
    }

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = (pub_r001527_15 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_51) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (pub_r001527_14 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_52) & 127;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = (pub_r001527_2 * 2 + 47) & 63;
    chk_sum = (chk_sum + stage_v_53) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = (pub_r001527_12 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_54) & 127;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = (pub_r001527_9 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_55) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = (stage_v_13 ^ pub_r001527_10) & 63;
    if ((stage_v_56 & 1) != 0) {
        if ((helper_flow_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_56 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_56 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_56 * 2) & 255;
    }

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (pub_r001527_4 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_57) & 127;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = (helper_flow_5 ^ pub_r001527_1) & 63;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r001527_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_58 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_58 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_58 * 2) & 255;
    }

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = (pub_r001527_6 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_59) & 127;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (stage_v_0 ^ pub_r001527_3) & 63;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r001527_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_60 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_60 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_60 * 2) & 255;
    }

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (pub_r001527_3 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_61) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = (sec_r001527_4 ^ pub_r001527_1) & 63;
    if ((stage_v_62 & 1) != 0) {
        if ((helper_flow_3 & 2) != 0) {
            out_sink = (out_sink + stage_v_62 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_62 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_62 * 2) & 255;
    }

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = (pub_r001527_4 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_63) & 127;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = (pub_r001527_14 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_64) & 127;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = (helper_flow_3 ^ pub_r001527_8) & 63;
    if ((stage_v_65 & 1) != 0) {
        if ((stage_v_19 & 2) != 0) {
            out_sink = (out_sink + stage_v_65 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_65 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_65 * 2) & 255;
    }

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = (stage_v_58 ^ pub_r001527_18) & 63;
    if ((stage_v_66 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_66 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_66 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_66 * 2) & 255;
    }

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = (helper_flow_0 ^ pub_r001527_10) & 63;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r001527_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_67 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_67 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_67 * 2) & 255;
    }

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = (stage_v_2 ^ pub_r001527_11) & 63;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r001527_18 & 2) != 0) {
            out_sink = (out_sink + stage_v_68 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_68 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_68 * 2) & 255;
    }

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = (stage_v_23 ^ pub_r001527_15) & 63;
    if ((stage_v_69 & 1) != 0) {
        if ((helper_flow_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_69 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_69 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_69 * 2) & 255;
    }

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = (stage_v_40 ^ pub_r001527_11) & 63;
    if ((stage_v_70 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_70 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_70 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_70 * 2) & 255;
    }

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = (helper_flow_7 ^ pub_r001527_17) & 63;
    if ((stage_v_71 & 1) != 0) {
        if ((stage_v_70 & 2) != 0) {
            out_sink = (out_sink + stage_v_71 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_71 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_71 * 2) & 255;
    }

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = (pub_r001527_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_72) & 127;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = (stage_v_13 ^ pub_r001527_15) & 63;
    if ((stage_v_73 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_73 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_73 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_73 * 2) & 255;
    }

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = (stage_v_73 ^ pub_r001527_12) & 63;
    if ((stage_v_74 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_74 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_74 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_74 * 2) & 255;
    }

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = (pub_r001527_18 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_75) & 127;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = (pub_r001527_1 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_76) & 127;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = (stage_v_19 ^ pub_r001527_10) & 63;
    if ((stage_v_77 & 1) != 0) {
        if ((stage_v_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_77 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_77 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_77 * 2) & 255;
    }

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = (stage_v_29 ^ pub_r001527_6) & 63;
    if ((stage_v_78 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_78 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_78 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_78 * 2) & 255;
    }

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = (stage_v_42 ^ pub_r001527_5) & 63;
    if ((stage_v_79 & 1) != 0) {
        if ((helper_flow_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_79 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_79 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_79 * 2) & 255;
    }

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = (stage_v_77 ^ pub_r001527_0) & 63;
    if ((stage_v_80 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_80 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_80 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_80 * 2) & 255;
    }

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = (helper_flow_2 ^ pub_r001527_7) & 63;
    if ((stage_v_81 & 1) != 0) {
        if ((stage_v_31 & 2) != 0) {
            out_sink = (out_sink + stage_v_81 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_81 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_81 * 2) & 255;
    }

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = (helper_flow_4 ^ pub_r001527_11) & 63;
    if ((stage_v_82 & 1) != 0) {
        if ((stage_v_27 & 2) != 0) {
            out_sink = (out_sink + stage_v_82 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_82 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_82 * 2) & 255;
    }

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = (pub_r001527_19 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_83) & 127;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = (pub_r001527_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_84) & 127;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = (helper_flow_8 ^ pub_r001527_0) & 63;
    if ((stage_v_85 & 1) != 0) {
        if ((stage_v_25 & 2) != 0) {
            out_sink = (out_sink + stage_v_85 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_85 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_85 * 2) & 255;
    }

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = (helper_flow_10 ^ pub_r001527_16) & 63;
    if ((stage_v_86 & 1) != 0) {
        if ((stage_v_20 & 2) != 0) {
            out_sink = (out_sink + stage_v_86 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_86 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_86 * 2) & 255;
    }

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = (pub_r001527_8 * 2 + 19) & 63;
    chk_sum = (chk_sum + stage_v_87) & 127;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = (pub_r001527_5 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_88) & 127;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = (sec_r001527_13 ^ pub_r001527_14) & 63;
    if ((stage_v_89 & 1) != 0) {
        if ((stage_v_24 & 2) != 0) {
            out_sink = (out_sink + stage_v_89 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_89 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_89 * 2) & 255;
    }

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = (stage_v_12 ^ pub_r001527_10) & 63;
    if ((stage_v_90 & 1) != 0) {
        if ((stage_v_39 & 2) != 0) {
            out_sink = (out_sink + stage_v_90 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_90 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_90 * 2) & 255;
    }

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = (pub_r001527_9 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_91) & 127;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = (pub_r001527_9 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_92) & 127;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = (sec_r001527_7 ^ pub_r001527_9) & 63;
    if ((stage_v_93 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_93 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_93 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_93 * 2) & 255;
    }

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = (stage_v_0 ^ pub_r001527_5) & 63;
    if ((stage_v_94 & 1) != 0) {
        if ((stage_v_8 & 2) != 0) {
            out_sink = (out_sink + stage_v_94 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_94 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_94 * 2) & 255;
    }

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = (pub_r001527_11 * 2 + 22) & 63;
    chk_sum = (chk_sum + stage_v_95) & 127;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = (helper_flow_5 ^ pub_r001527_2) & 63;
    if ((stage_v_96 & 1) != 0) {
        if ((sec_r001527_12 & 2) != 0) {
            out_sink = (out_sink + stage_v_96 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_96 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_96 * 2) & 255;
    }

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = (pub_r001527_17 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_97) & 127;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = (sec_r001527_18 ^ pub_r001527_14) & 63;
    if ((stage_v_98 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_98 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_98 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_98 * 2) & 255;
    }

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = (pub_r001527_16 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_99) & 127;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = (stage_v_0 ^ pub_r001527_3) & 63;
    if ((stage_v_100 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_100 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_100 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_100 * 2) & 255;
    }

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = (pub_r001527_2 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_101) & 127;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = (pub_r001527_16 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_102) & 127;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = (helper_flow_3 ^ pub_r001527_17) & 63;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r001527_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_103 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_103 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_103 * 2) & 255;
    }

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = (stage_v_31 ^ pub_r001527_12) & 63;
    if ((stage_v_104 & 1) != 0) {
        if ((stage_v_60 & 2) != 0) {
            out_sink = (out_sink + stage_v_104 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_104 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_104 * 2) & 255;
    }

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = (stage_v_8 ^ pub_r001527_2) & 63;
    if ((stage_v_105 & 1) != 0) {
        if ((stage_v_36 & 2) != 0) {
            out_sink = (out_sink + stage_v_105 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_105 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_105 * 2) & 255;
    }

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = (stage_v_94 ^ pub_r001527_10) & 63;
    if ((stage_v_106 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_106 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_106 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_106 * 2) & 255;
    }

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = (sec_r001527_2 ^ pub_r001527_7) & 63;
    if ((stage_v_107 & 1) != 0) {
        if ((sec_r001527_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_107 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_107 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_107 * 2) & 255;
    }

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = (pub_r001527_13 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_108) & 127;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = (helper_flow_6 ^ pub_r001527_15) & 63;
    if ((stage_v_109 & 1) != 0) {
        if ((stage_v_4 & 2) != 0) {
            out_sink = (out_sink + stage_v_109 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_109 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_109 * 2) & 255;
    }

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = (pub_r001527_2 * 2 + 7) & 63;
    chk_sum = (chk_sum + stage_v_110) & 127;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = (sec_r001527_0 ^ pub_r001527_12) & 63;
    if ((stage_v_111 & 1) != 0) {
        if ((stage_v_21 & 2) != 0) {
            out_sink = (out_sink + stage_v_111 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_111 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_111 * 2) & 255;
    }

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = (pub_r001527_8 * 2 + 35) & 63;
    chk_sum = (chk_sum + stage_v_112) & 127;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = (pub_r001527_6 * 2 + 41) & 63;
    chk_sum = (chk_sum + stage_v_113) & 127;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = (pub_r001527_3 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_114) & 127;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = (sec_r001527_3 ^ pub_r001527_5) & 63;
    if ((stage_v_115 & 1) != 0) {
        if ((helper_flow_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_115 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_115 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_115 * 2) & 255;
    }

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = (stage_v_82 ^ pub_r001527_12) & 63;
    if ((stage_v_116 & 1) != 0) {
        if ((sec_r001527_17 & 2) != 0) {
            out_sink = (out_sink + stage_v_116 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_116 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_116 * 2) & 255;
    }

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = (pub_r001527_11 * 2 + 28) & 63;
    chk_sum = (chk_sum + stage_v_117) & 127;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = (stage_v_0 ^ pub_r001527_4) & 63;
    if ((stage_v_118 & 1) != 0) {
        if ((stage_v_13 & 2) != 0) {
            out_sink = (out_sink + stage_v_118 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_118 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_118 * 2) & 255;
    }

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = (pub_r001527_5 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_119) & 127;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = (pub_r001527_5 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_120) & 127;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = (pub_r001527_14 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_121) & 127;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = (pub_r001527_6 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_122) & 127;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = (stage_v_19 ^ pub_r001527_14) & 63;
    if ((stage_v_123 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_123 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_123 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_123 * 2) & 255;
    }

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = (stage_v_80 ^ pub_r001527_7) & 63;
    if ((stage_v_124 & 1) != 0) {
        if ((stage_v_74 & 2) != 0) {
            out_sink = (out_sink + stage_v_124 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_124 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_124 * 2) & 255;
    }

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = (stage_v_39 ^ pub_r001527_9) & 63;
    if ((stage_v_125 & 1) != 0) {
        if ((stage_v_58 & 2) != 0) {
            out_sink = (out_sink + stage_v_125 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_125 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_125 * 2) & 255;
    }

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = (stage_v_27 ^ pub_r001527_14) & 63;
    if ((stage_v_126 & 1) != 0) {
        if ((helper_flow_6 & 2) != 0) {
            out_sink = (out_sink + stage_v_126 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_126 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_126 * 2) & 255;
    }

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = (pub_r001527_1 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_127) & 127;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = (stage_v_2 ^ pub_r001527_13) & 63;
    if ((stage_v_128 & 1) != 0) {
        if ((stage_v_40 & 2) != 0) {
            out_sink = (out_sink + stage_v_128 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_128 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_128 * 2) & 255;
    }

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = (pub_r001527_15 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_129) & 127;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = (pub_r001527_7 * 2 + 33) & 63;
    chk_sum = (chk_sum + stage_v_130) & 127;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = (stage_v_125 ^ pub_r001527_2) & 63;
    if ((stage_v_131 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_131 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_131 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_131 * 2) & 255;
    }

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = (stage_v_7 ^ pub_r001527_11) & 63;
    if ((stage_v_132 & 1) != 0) {
        if ((sec_r001527_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_132 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_132 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_132 * 2) & 255;
    }

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = (stage_v_7 ^ pub_r001527_15) & 63;
    if ((stage_v_133 & 1) != 0) {
        if ((stage_v_100 & 2) != 0) {
            out_sink = (out_sink + stage_v_133 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_133 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_133 * 2) & 255;
    }

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = (stage_v_105 ^ pub_r001527_13) & 63;
    if ((stage_v_134 & 1) != 0) {
        if ((stage_v_66 & 2) != 0) {
            out_sink = (out_sink + stage_v_134 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_134 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_134 * 2) & 255;
    }

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = (pub_r001527_17 * 2 + 42) & 63;
    chk_sum = (chk_sum + stage_v_135) & 127;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = (stage_v_16 ^ pub_r001527_5) & 63;
    if ((stage_v_136 & 1) != 0) {
        if ((sec_r001527_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_136 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_136 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_136 * 2) & 255;
    }

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = (sec_r001527_15 ^ pub_r001527_2) & 63;
    if ((stage_v_137 & 1) != 0) {
        if ((sec_r001527_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_137 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_137 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_137 * 2) & 255;
    }

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = (pub_r001527_17 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_138) & 127;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = (pub_r001527_14 * 2 + 49) & 63;
    chk_sum = (chk_sum + stage_v_139) & 127;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = (helper_flow_2 ^ pub_r001527_5) & 63;
    if ((stage_v_140 & 1) != 0) {
        if ((stage_v_77 & 2) != 0) {
            out_sink = (out_sink + stage_v_140 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_140 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_140 * 2) & 255;
    }

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = (sec_r001527_8 ^ pub_r001527_16) & 63;
    if ((stage_v_141 & 1) != 0) {
        if ((stage_v_81 & 2) != 0) {
            out_sink = (out_sink + stage_v_141 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_141 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_141 * 2) & 255;
    }

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = (pub_r001527_2 * 2 + 14) & 63;
    chk_sum = (chk_sum + stage_v_142) & 127;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = (pub_r001527_5 * 2 + 31) & 63;
    chk_sum = (chk_sum + stage_v_143) & 127;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = (pub_r001527_6 * 2 + 32) & 63;
    chk_sum = (chk_sum + stage_v_144) & 127;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = (pub_r001527_12 * 2 + 46) & 63;
    chk_sum = (chk_sum + stage_v_145) & 127;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = (stage_v_79 ^ pub_r001527_16) & 63;
    if ((stage_v_146 & 1) != 0) {
        if ((helper_flow_5 & 2) != 0) {
            out_sink = (out_sink + stage_v_146 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_146 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_146 * 2) & 255;
    }

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = (sec_r001527_7 ^ pub_r001527_7) & 63;
    if ((stage_v_147 & 1) != 0) {
        if ((sec_r001527_0 & 2) != 0) {
            out_sink = (out_sink + stage_v_147 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_147 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_147 * 2) & 255;
    }

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = (pub_r001527_19 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_148) & 127;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = (sec_r001527_1 ^ pub_r001527_5) & 63;
    if ((stage_v_149 & 1) != 0) {
        if ((stage_v_73 & 2) != 0) {
            out_sink = (out_sink + stage_v_149 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_149 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_149 * 2) & 255;
    }

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = (stage_v_36 ^ pub_r001527_14) & 63;
    if ((stage_v_150 & 1) != 0) {
        if ((stage_v_82 & 2) != 0) {
            out_sink = (out_sink + stage_v_150 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_150 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_150 * 2) & 255;
    }

    /* Execution Pipeline Stage 151 */
    int stage_v_151 = (stage_v_27 ^ pub_r001527_4) & 63;
    if ((stage_v_151 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_151 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_151 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_151 * 2) & 255;
    }

    /* Execution Pipeline Stage 152 */
    int stage_v_152 = (pub_r001527_0 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_152) & 127;

    /* Execution Pipeline Stage 153 */
    int stage_v_153 = (pub_r001527_18 * 2 + 24) & 63;
    chk_sum = (chk_sum + stage_v_153) & 127;

    /* Execution Pipeline Stage 154 */
    int stage_v_154 = (helper_flow_2 ^ pub_r001527_6) & 63;
    if ((stage_v_154 & 1) != 0) {
        if ((helper_flow_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_154 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_154 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_154 * 2) & 255;
    }

    /* Execution Pipeline Stage 155 */
    int stage_v_155 = (pub_r001527_4 * 2 + 11) & 63;
    chk_sum = (chk_sum + stage_v_155) & 127;

    /* Execution Pipeline Stage 156 */
    int stage_v_156 = (stage_v_134 ^ pub_r001527_7) & 63;
    if ((stage_v_156 & 1) != 0) {
        if ((stage_v_105 & 2) != 0) {
            out_sink = (out_sink + stage_v_156 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_156 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_156 * 2) & 255;
    }

    /* Execution Pipeline Stage 157 */
    int stage_v_157 = (stage_v_79 ^ pub_r001527_1) & 63;
    if ((stage_v_157 & 1) != 0) {
        if ((sec_r001527_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_157 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_157 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_157 * 2) & 255;
    }

    /* Execution Pipeline Stage 158 */
    int stage_v_158 = (stage_v_134 ^ pub_r001527_18) & 63;
    if ((stage_v_158 & 1) != 0) {
        if ((stage_v_79 & 2) != 0) {
            out_sink = (out_sink + stage_v_158 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_158 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_158 * 2) & 255;
    }

    /* Execution Pipeline Stage 159 */
    int stage_v_159 = (stage_v_3 ^ pub_r001527_2) & 63;
    if ((stage_v_159 & 1) != 0) {
        if ((stage_v_147 & 2) != 0) {
            out_sink = (out_sink + stage_v_159 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_159 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_159 * 2) & 255;
    }

    /* Execution Pipeline Stage 160 */
    int stage_v_160 = (sec_r001527_1 ^ pub_r001527_5) & 63;
    if ((stage_v_160 & 1) != 0) {
        if ((stage_v_115 & 2) != 0) {
            out_sink = (out_sink + stage_v_160 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_160 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_160 * 2) & 255;
    }

    /* Execution Pipeline Stage 161 */
    int stage_v_161 = (helper_flow_7 ^ pub_r001527_5) & 63;
    if ((stage_v_161 & 1) != 0) {
        if ((stage_v_156 & 2) != 0) {
            out_sink = (out_sink + stage_v_161 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_161 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_161 * 2) & 255;
    }

    /* Execution Pipeline Stage 162 */
    int stage_v_162 = (pub_r001527_8 * 2 + 26) & 63;
    chk_sum = (chk_sum + stage_v_162) & 127;

    /* Execution Pipeline Stage 163 */
    int stage_v_163 = (pub_r001527_15 * 2 + 38) & 63;
    chk_sum = (chk_sum + stage_v_163) & 127;

    /* Execution Pipeline Stage 164 */
    int stage_v_164 = (sec_r001527_10 ^ pub_r001527_13) & 63;
    if ((stage_v_164 & 1) != 0) {
        if ((sec_r001527_7 & 2) != 0) {
            out_sink = (out_sink + stage_v_164 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_164 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_164 * 2) & 255;
    }

    /* Execution Pipeline Stage 165 */
    int stage_v_165 = (stage_v_86 ^ pub_r001527_3) & 63;
    if ((stage_v_165 & 1) != 0) {
        if ((stage_v_23 & 2) != 0) {
            out_sink = (out_sink + stage_v_165 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_165 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_165 * 2) & 255;
    }

    /* Execution Pipeline Stage 166 */
    int stage_v_166 = (pub_r001527_3 * 2 + 8) & 63;
    chk_sum = (chk_sum + stage_v_166) & 127;

    /* Execution Pipeline Stage 167 */
    int stage_v_167 = (stage_v_103 ^ pub_r001527_11) & 63;
    if ((stage_v_167 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_167 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_167 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_167 * 2) & 255;
    }

    /* Execution Pipeline Stage 168 */
    int stage_v_168 = (stage_v_12 ^ pub_r001527_6) & 63;
    if ((stage_v_168 & 1) != 0) {
        if ((stage_v_16 & 2) != 0) {
            out_sink = (out_sink + stage_v_168 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_168 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_168 * 2) & 255;
    }

    /* Execution Pipeline Stage 169 */
    int stage_v_169 = (stage_v_40 ^ pub_r001527_1) & 63;
    if ((stage_v_169 & 1) != 0) {
        if ((stage_v_46 & 2) != 0) {
            out_sink = (out_sink + stage_v_169 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_169 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_169 * 2) & 255;
    }

    /* Execution Pipeline Stage 170 */
    int stage_v_170 = (stage_v_150 ^ pub_r001527_19) & 63;
    if ((stage_v_170 & 1) != 0) {
        if ((stage_v_158 & 2) != 0) {
            out_sink = (out_sink + stage_v_170 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_170 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_170 * 2) & 255;
    }

    /* Execution Pipeline Stage 171 */
    int stage_v_171 = (stage_v_111 ^ pub_r001527_1) & 63;
    if ((stage_v_171 & 1) != 0) {
        if ((stage_v_86 & 2) != 0) {
            out_sink = (out_sink + stage_v_171 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_171 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_171 * 2) & 255;
    }

    /* Execution Pipeline Stage 172 */
    int stage_v_172 = (sec_r001527_1 ^ pub_r001527_14) & 63;
    if ((stage_v_172 & 1) != 0) {
        if ((stage_v_44 & 2) != 0) {
            out_sink = (out_sink + stage_v_172 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_172 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_172 * 2) & 255;
    }

    /* Execution Pipeline Stage 173 */
    int stage_v_173 = (pub_r001527_1 * 2 + 20) & 63;
    chk_sum = (chk_sum + stage_v_173) & 127;

    /* Execution Pipeline Stage 174 */
    int stage_v_174 = (pub_r001527_13 * 2 + 37) & 63;
    chk_sum = (chk_sum + stage_v_174) & 127;

    /* Execution Pipeline Stage 175 */
    int stage_v_175 = (helper_flow_4 ^ pub_r001527_5) & 63;
    if ((stage_v_175 & 1) != 0) {
        if ((stage_v_94 & 2) != 0) {
            out_sink = (out_sink + stage_v_175 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_175 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_175 * 2) & 255;
    }

    /* Execution Pipeline Stage 176 */
    int stage_v_176 = (pub_r001527_8 * 2 + 6) & 63;
    chk_sum = (chk_sum + stage_v_176) & 127;

    /* Execution Pipeline Stage 177 */
    int stage_v_177 = (pub_r001527_1 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_177) & 127;

    /* Execution Pipeline Stage 178 */
    int stage_v_178 = (stage_v_20 ^ pub_r001527_7) & 63;
    if ((stage_v_178 & 1) != 0) {
        if ((stage_v_29 & 2) != 0) {
            out_sink = (out_sink + stage_v_178 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_178 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_178 * 2) & 255;
    }

    /* Execution Pipeline Stage 179 */
    int stage_v_179 = (stage_v_85 ^ pub_r001527_17) & 63;
    if ((stage_v_179 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_179 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_179 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_179 * 2) & 255;
    }

    /* Execution Pipeline Stage 180 */
    int stage_v_180 = (stage_v_116 ^ pub_r001527_16) & 63;
    if ((stage_v_180 & 1) != 0) {
        if ((helper_flow_1 & 2) != 0) {
            out_sink = (out_sink + stage_v_180 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_180 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_180 * 2) & 255;
    }

    /* Execution Pipeline Stage 181 */
    int stage_v_181 = (pub_r001527_1 * 2 + 9) & 63;
    chk_sum = (chk_sum + stage_v_181) & 127;

    /* Execution Pipeline Stage 182 */
    int stage_v_182 = (pub_r001527_11 * 2 + 13) & 63;
    chk_sum = (chk_sum + stage_v_182) & 127;

    /* Execution Pipeline Stage 183 */
    int stage_v_183 = (helper_flow_3 ^ pub_r001527_10) & 63;
    if ((stage_v_183 & 1) != 0) {
        if ((sec_r001527_14 & 2) != 0) {
            out_sink = (out_sink + stage_v_183 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_183 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_183 * 2) & 255;
    }

    /* Execution Pipeline Stage 184 */
    int stage_v_184 = (stage_v_2 ^ pub_r001527_19) & 63;
    if ((stage_v_184 & 1) != 0) {
        if ((stage_v_128 & 2) != 0) {
            out_sink = (out_sink + stage_v_184 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_184 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_184 * 2) & 255;
    }

    /* Execution Pipeline Stage 185 */
    int stage_v_185 = (pub_r001527_10 * 2 + 25) & 63;
    chk_sum = (chk_sum + stage_v_185) & 127;

    /* Execution Pipeline Stage 186 */
    int stage_v_186 = (stage_v_0 ^ pub_r001527_4) & 63;
    if ((stage_v_186 & 1) != 0) {
        if ((stage_v_124 & 2) != 0) {
            out_sink = (out_sink + stage_v_186 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_186 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_186 * 2) & 255;
    }

    /* Execution Pipeline Stage 187 */
    int stage_v_187 = (pub_r001527_6 * 2 + 18) & 63;
    chk_sum = (chk_sum + stage_v_187) & 127;

    /* Execution Pipeline Stage 188 */
    int stage_v_188 = (pub_r001527_16 * 2 + 21) & 63;
    chk_sum = (chk_sum + stage_v_188) & 127;

    /* Execution Pipeline Stage 189 */
    int stage_v_189 = (pub_r001527_14 * 2 + 44) & 63;
    chk_sum = (chk_sum + stage_v_189) & 127;

    /* Execution Pipeline Stage 190 */
    int stage_v_190 = (stage_v_44 ^ pub_r001527_12) & 63;
    if ((stage_v_190 & 1) != 0) {
        if ((stage_v_158 & 2) != 0) {
            out_sink = (out_sink + stage_v_190 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_190 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_190 * 2) & 255;
    }

    /* Execution Pipeline Stage 191 */
    int stage_v_191 = (stage_v_134 ^ pub_r001527_19) & 63;
    if ((stage_v_191 & 1) != 0) {
        if ((stage_v_69 & 2) != 0) {
            out_sink = (out_sink + stage_v_191 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_191 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_191 * 2) & 255;
    }

    /* Execution Pipeline Stage 192 */
    int stage_v_192 = (sec_r001527_7 ^ pub_r001527_10) & 63;
    if ((stage_v_192 & 1) != 0) {
        if ((stage_v_147 & 2) != 0) {
            out_sink = (out_sink + stage_v_192 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_192 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_192 * 2) & 255;
    }

    /* Execution Pipeline Stage 193 */
    int stage_v_193 = (pub_r001527_19 * 2 + 17) & 63;
    chk_sum = (chk_sum + stage_v_193) & 127;

    /* Execution Pipeline Stage 194 */
    int stage_v_194 = (pub_r001527_0 * 2 + 40) & 63;
    chk_sum = (chk_sum + stage_v_194) & 127;

    /* Execution Pipeline Stage 195 */
    int stage_v_195 = (stage_v_82 ^ pub_r001527_8) & 63;
    if ((stage_v_195 & 1) != 0) {
        if ((stage_v_131 & 2) != 0) {
            out_sink = (out_sink + stage_v_195 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_195 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_195 * 2) & 255;
    }

    /* Execution Pipeline Stage 196 */
    int stage_v_196 = (sec_r001527_13 ^ pub_r001527_1) & 63;
    if ((stage_v_196 & 1) != 0) {
        if ((stage_v_160 & 2) != 0) {
            out_sink = (out_sink + stage_v_196 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_196 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_196 * 2) & 255;
    }

    /* Execution Pipeline Stage 197 */
    int stage_v_197 = (stage_v_184 ^ pub_r001527_0) & 63;
    if ((stage_v_197 & 1) != 0) {
        if ((stage_v_132 & 2) != 0) {
            out_sink = (out_sink + stage_v_197 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_197 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_197 * 2) & 255;
    }

    /* Execution Pipeline Stage 198 */
    int stage_v_198 = (stage_v_27 ^ pub_r001527_5) & 63;
    if ((stage_v_198 & 1) != 0) {
        if ((stage_v_186 & 2) != 0) {
            out_sink = (out_sink + stage_v_198 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_198 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_198 * 2) & 255;
    }

    /* Execution Pipeline Stage 199 */
    int stage_v_199 = (pub_r001527_12 * 2 + 50) & 63;
    chk_sum = (chk_sum + stage_v_199) & 127;

    /* Execution Pipeline Stage 200 */
    int stage_v_200 = (stage_v_109 ^ pub_r001527_5) & 63;
    if ((stage_v_200 & 1) != 0) {
        if ((stage_v_106 & 2) != 0) {
            out_sink = (out_sink + stage_v_200 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_200 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_200 * 2) & 255;
    }

    /* Execution Pipeline Stage 201 */
    int stage_v_201 = (stage_v_73 ^ pub_r001527_13) & 63;
    if ((stage_v_201 & 1) != 0) {
        if ((stage_v_93 & 2) != 0) {
            out_sink = (out_sink + stage_v_201 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_201 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_201 * 2) & 255;
    }

    /* Execution Pipeline Stage 202 */
    int stage_v_202 = (stage_v_131 ^ pub_r001527_14) & 63;
    if ((stage_v_202 & 1) != 0) {
        if ((stage_v_160 & 2) != 0) {
            out_sink = (out_sink + stage_v_202 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_202 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_202 * 2) & 255;
    }

    /* Execution Pipeline Stage 203 */
    int stage_v_203 = (pub_r001527_9 * 2 + 29) & 63;
    chk_sum = (chk_sum + stage_v_203) & 127;

    /* Execution Pipeline Stage 204 */
    int stage_v_204 = (stage_v_125 ^ pub_r001527_15) & 63;
    if ((stage_v_204 & 1) != 0) {
        if ((sec_r001527_10 & 2) != 0) {
            out_sink = (out_sink + stage_v_204 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_204 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_204 * 2) & 255;
    }

    /* Execution Pipeline Stage 205 */
    int stage_v_205 = (stage_v_198 ^ pub_r001527_15) & 63;
    if ((stage_v_205 & 1) != 0) {
        if ((stage_v_62 & 2) != 0) {
            out_sink = (out_sink + stage_v_205 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_205 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_205 * 2) & 255;
    }

    /* Execution Pipeline Stage 206 */
    int stage_v_206 = (stage_v_60 ^ pub_r001527_11) & 63;
    if ((stage_v_206 & 1) != 0) {
        if ((stage_v_34 & 2) != 0) {
            out_sink = (out_sink + stage_v_206 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_206 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_206 * 2) & 255;
    }

    /* Execution Pipeline Stage 207 */
    int stage_v_207 = (stage_v_186 ^ pub_r001527_11) & 63;
    if ((stage_v_207 & 1) != 0) {
        if ((stage_v_104 & 2) != 0) {
            out_sink = (out_sink + stage_v_207 * 3 + 1) & 255;
        } else {
            out_sink = (out_sink - stage_v_207 + 9) & 255;
        }
    } else {
        sec_accum = (sec_accum + stage_v_207 * 2) & 255;
    }

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
