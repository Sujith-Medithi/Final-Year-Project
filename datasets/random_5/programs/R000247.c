/*
 * Benchmark Program: R000247
 * Security Family: nested_implicit_flow
 * Generator Seed: 526724
 * High Inputs: 19 | Low Inputs: 18
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct DeviceConfig_R000247_6724_0 {
    short port;
    int baud_rate;
    unsigned char id;
    int buffer[3];
};

struct EventLog_R000247_6724_1 {
    short timestamp;
    int severity;
    short code;
    int facility;
    int signature;
    int buffer[3];
};

struct MatrixBlock_R000247_6724_2 {
    int dim;
    int stride;
    unsigned char scale;
    int buffer[3];
};

struct CipherContext_R000247_6724_3 {
    short nonce;
    int round_key;
    int flags;
    int buffer[3];
};

union ColorPixel_R000247_6724_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000247_6724_0(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000247_6724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 18;
    int local_arr[3] = {4, 9, 15};
    int segment_24 = local_arr[aux % 3];
    acc = (acc + segment_24 * 2) & 127;
    int sample_11 = (st.buffer[0] * 3 + aux) & 63;
    if (sample_11 > 27) {
        acc = (acc + sample_11 * 2 + 5) & 127;
        aux ^= (sample_11 & 15);
    } else {
        acc = (acc - sample_11 + 11) & 127;
        aux += 3;
    }
    int window_21 = (aux + st.buffer[1]) & 3;
    switch (window_21) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_10 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_10) & 63;
    acc ^= aux;
    return (acc + aux) & 255;
}

int fn_R000247_6724_1(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 10) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000247_6724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int pivot_56 = (aux + st.buffer[1]) & 3;
    switch (pivot_56) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int damping_51 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_51 > 35) {
        acc = (acc + damping_51 * 2 + 5) & 127;
        aux ^= (damping_51 & 15);
    } else {
        acc = (acc - damping_51 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int parity_45 = local_arr[aux % 3];
    acc = (acc + parity_45 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_2(int p0, int p1) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000247_6724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int vector_89 = (aux + st.buffer[1]) & 3;
    switch (vector_89) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int bound_12 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_12 > 18) {
        acc = (acc + bound_12 * 2 + 5) & 127;
        aux ^= (bound_12 & 15);
    } else {
        acc = (acc - bound_12 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000247_6724_3(int p0, int p1, int p2) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000247_6724_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 13;
    int quantum_87 = (aux + st.buffer[1]) & 3;
    switch (quantum_87) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int delta_89 = (st.buffer[0] * 3 + aux) & 63;
    if (delta_89 > 10) {
        acc = (acc + delta_89 * 2 + 5) & 127;
        aux ^= (delta_89 & 15);
    } else {
        acc = (acc - delta_89 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000247_6724_4(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 29) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000247_6724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int coefficient_17 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + coefficient_17) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int segment_11 = local_arr[aux % 3];
    acc = (acc + segment_11 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_5(int p0, int p1) {
    int acc = (p0 + 14) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000247_6724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 28;
    int accumulator_34 = (aux + st.buffer[1]) & 3;
    switch (accumulator_34) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int stride_40 = local_arr[aux % 3];
    acc = (acc + stride_40 * 2) & 127;
    int anchor_94 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_94) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_6(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 19) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000247_6724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int anchor_40 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + anchor_40) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_7(int p0, int p1) {
    int acc = (p0 + 34) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000247_6724_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 22;
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int stride_79 = (aux + st.buffer[1]) & 3;
    switch (stride_79) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int tally_78 = (st.buffer[0] * 3 + aux) & 63;
    if (tally_78 > 16) {
        acc = (acc + tally_78 * 2 + 5) & 127;
        aux ^= (tally_78 & 15);
    } else {
        acc = (acc - tally_78 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_13 = local_arr[aux % 3];
    acc = (acc + weight_13 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_8(int p0, int p1) {
    int acc = (p0 + 5) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000247_6724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 25;
    int stride_20 = (aux + st.buffer[1]) & 3;
    switch (stride_20) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int segment_21 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + segment_21) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tally_81 = local_arr[aux % 3];
    acc = (acc + tally_81 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_9(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000247_6724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 16;
    int quotient_78 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + quotient_78) & 63;
    acc ^= aux;
    int damping_37 = (st.buffer[0] * 3 + aux) & 63;
    if (damping_37 > 45) {
        acc = (acc + damping_37 * 2 + 5) & 127;
        aux ^= (damping_37 & 15);
    } else {
        acc = (acc - damping_37 + 11) & 127;
        aux += 3;
    }
    int offset_58 = (aux + st.buffer[1]) & 3;
    switch (offset_58) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int pivot_65 = local_arr[aux % 3];
    acc = (acc + pivot_65 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_10(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000247_6724_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 6;
    int sample_59 = (aux + st.buffer[1]) & 3;
    switch (sample_59) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int pivot_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + pivot_71) & 63;
    acc ^= aux;
    st.buffer[1] = (st.buffer[1] + 8) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int delta_25 = local_arr[aux % 3];
    acc = (acc + delta_25 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_11(int p0, int p1, int p2) {
    int acc = (p0 + 28) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct CipherContext_R000247_6724_3 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    int pivot_24 = (aux + st.buffer[1]) & 3;
    switch (pivot_24) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 9) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int factor_89 = local_arr[aux % 3];
    acc = (acc + factor_89 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_12(int p0, int p1) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000247_6724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 29;
    int threshold_25 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_25) & 63;
    acc ^= aux;
    int quantum_15 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_15 > 36) {
        acc = (acc + quantum_15 * 2 + 5) & 127;
        aux ^= (quantum_15 & 15);
    } else {
        acc = (acc - quantum_15 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000247_6724_13(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000247_6724_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 20;
    st.buffer[1] = (st.buffer[1] + 5) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int accumulator_71 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_71) & 63;
    acc ^= aux;
    int margin_65 = (aux + st.buffer[1]) & 3;
    switch (margin_65) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int weight_19 = local_arr[aux % 3];
    acc = (acc + weight_19 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000247_6724_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 49) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct EventLog_R000247_6724_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 15;
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int vector_84 = (aux + st.buffer[1]) & 3;
    switch (vector_84) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int main() {
    int sec_r000247_0;
    int sec_r000247_1;
    int sec_r000247_2;
    int sec_r000247_3;
    int sec_r000247_4;
    int sec_r000247_5;
    int sec_r000247_6;
    int sec_r000247_7;
    int sec_r000247_8;
    int sec_r000247_9;
    int sec_r000247_10;
    int sec_r000247_11;
    int sec_r000247_12;
    int sec_r000247_13;
    int sec_r000247_14;
    int sec_r000247_15;
    int sec_r000247_16;
    int sec_r000247_17;
    int sec_r000247_18;
    int pub_r000247_0;
    int pub_r000247_1;
    int pub_r000247_2;
    int pub_r000247_3;
    int pub_r000247_4;
    int pub_r000247_5;
    int pub_r000247_6;
    int pub_r000247_7;
    int pub_r000247_8;
    int pub_r000247_9;
    int pub_r000247_10;
    int pub_r000247_11;
    int pub_r000247_12;
    int pub_r000247_13;
    int pub_r000247_14;
    int pub_r000247_15;
    int pub_r000247_16;
    int pub_r000247_17;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000247_0 >= -100 && pub_r000247_0 <= 100);
    __CPROVER_assume(pub_r000247_1 >= -100 && pub_r000247_1 <= 100);
    __CPROVER_assume(pub_r000247_2 >= -100 && pub_r000247_2 <= 100);
    __CPROVER_assume(pub_r000247_3 >= -100 && pub_r000247_3 <= 100);
    __CPROVER_assume(pub_r000247_4 >= -100 && pub_r000247_4 <= 100);
    __CPROVER_assume(pub_r000247_5 >= -100 && pub_r000247_5 <= 100);
    __CPROVER_assume(pub_r000247_6 >= -100 && pub_r000247_6 <= 100);
    __CPROVER_assume(pub_r000247_7 >= -100 && pub_r000247_7 <= 100);
    __CPROVER_assume(pub_r000247_8 >= -100 && pub_r000247_8 <= 100);
    __CPROVER_assume(pub_r000247_9 >= -100 && pub_r000247_9 <= 100);
    __CPROVER_assume(pub_r000247_10 >= -100 && pub_r000247_10 <= 100);
    __CPROVER_assume(pub_r000247_11 >= -100 && pub_r000247_11 <= 100);
    __CPROVER_assume(pub_r000247_12 >= -100 && pub_r000247_12 <= 100);
    __CPROVER_assume(pub_r000247_13 >= -100 && pub_r000247_13 <= 100);
    __CPROVER_assume(pub_r000247_14 >= -100 && pub_r000247_14 <= 100);
    __CPROVER_assume(pub_r000247_15 >= -100 && pub_r000247_15 <= 100);
    __CPROVER_assume(pub_r000247_16 >= -100 && pub_r000247_16 <= 100);
    __CPROVER_assume(pub_r000247_17 >= -100 && pub_r000247_17 <= 100);
    __CPROVER_assume(sec_r000247_0 >= 0 && sec_r000247_0 <= 255);
    __CPROVER_assume(sec_r000247_1 >= 0 && sec_r000247_1 <= 255);
    __CPROVER_assume(sec_r000247_2 >= 0 && sec_r000247_2 <= 255);
    __CPROVER_assume(sec_r000247_3 >= 0 && sec_r000247_3 <= 255);
    __CPROVER_assume(sec_r000247_4 >= 0 && sec_r000247_4 <= 255);
    __CPROVER_assume(sec_r000247_5 >= 0 && sec_r000247_5 <= 255);
    __CPROVER_assume(sec_r000247_6 >= 0 && sec_r000247_6 <= 255);
    __CPROVER_assume(sec_r000247_7 >= 0 && sec_r000247_7 <= 255);
    __CPROVER_assume(sec_r000247_8 >= 0 && sec_r000247_8 <= 255);
    __CPROVER_assume(sec_r000247_9 >= 0 && sec_r000247_9 <= 255);
    __CPROVER_assume(sec_r000247_10 >= 0 && sec_r000247_10 <= 255);
    __CPROVER_assume(sec_r000247_11 >= 0 && sec_r000247_11 <= 255);
    __CPROVER_assume(sec_r000247_12 >= 0 && sec_r000247_12 <= 255);
    __CPROVER_assume(sec_r000247_13 >= 0 && sec_r000247_13 <= 255);
    __CPROVER_assume(sec_r000247_14 >= 0 && sec_r000247_14 <= 255);
    __CPROVER_assume(sec_r000247_15 >= 0 && sec_r000247_15 <= 255);
    __CPROVER_assume(sec_r000247_16 >= 0 && sec_r000247_16 <= 255);
    __CPROVER_assume(sec_r000247_17 >= 0 && sec_r000247_17 <= 255);
    __CPROVER_assume(sec_r000247_18 >= 0 && sec_r000247_18 <= 255);

    struct DeviceConfig_R000247_6724_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000247_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000247_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000247_0 + 7) & 15;
    struct EventLog_R000247_6724_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000247_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000247_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000247_0 + 9) & 15;
    struct MatrixBlock_R000247_6724_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000247_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000247_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000247_0 + 11) & 15;
    struct CipherContext_R000247_6724_3 st_var_3 = {0};
    st_var_3.buffer[0] = (pub_r000247_0 + 10) & 15;
    st_var_3.buffer[1] = (pub_r000247_0 + 19) & 15;
    st_var_3.buffer[2] = (pub_r000247_0 + 13) & 15;

    union ColorPixel_R000247_6724_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = (st_var_0.buffer[0] ^ 3) & 3;
    switch (stage_v_0) {
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

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = (st_var_1.buffer[1] * 2 + 10) & 63;
    if (stage_v_1 > 29) {
        out_sink = (out_sink + stage_v_1 - 5) & 255;
        if (stage_v_1 > 44) {
            chk_sum ^= (stage_v_1 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_1 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 2 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 3) & 15;
    int stage_v_2 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_2) & 255;
    chk_sum ^= stage_v_2;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_3.buffer[0] * 2 + 16) & 63;
    if (stage_v_3 > 21) {
        out_sink = (out_sink + stage_v_3 - 5) & 255;
        if (stage_v_3 > 36) {
            chk_sum ^= (stage_v_3 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_3 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 4 */
    int stage_v_4 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_4 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 5 */
    st_var_1.buffer[2] = (st_var_1.buffer[2] + 6) & 15;
    int stage_v_5 = (st_var_1.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_5) & 255;
    chk_sum ^= stage_v_5;

    /* Execution Pipeline Stage 6 */
    int stage_v_6 = (st_var_2.buffer[0] ^ 9) & 3;
    switch (stage_v_6) {
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

    /* Execution Pipeline Stage 7 */
    st_var_3.buffer[1] = (st_var_3.buffer[1] + 8) & 15;
    int stage_v_7 = (st_var_3.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_7) & 255;
    chk_sum ^= stage_v_7;

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = (st_var_0.buffer[0] ^ 11) & 3;
    switch (stage_v_8) {
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

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = table[1];
    table[1] = (table[2] + 19) & 63;
    out_sink = (out_sink + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_10 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = table[3];
    table[3] = (table[0] + 23) & 63;
    out_sink = (out_sink + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    st_var_0.buffer[0] = (st_var_0.buffer[0] + 13) & 15;
    int stage_v_12 = (st_var_0.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_12) & 255;
    chk_sum ^= stage_v_12;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = table[1];
    table[1] = (table[2] + 27) & 63;
    out_sink = (out_sink + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = (out_sink > 100) ? (chk_sum & 31) : (19 & 31);
    out_sink = (out_sink + stage_v_14) & 255;
    chk_sum ^= (stage_v_14 << 1) & 127;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = (st_var_3.buffer[0] ^ 18) & 3;
    switch (stage_v_15) {
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

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_16 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_17 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_18 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = (st_var_3.buffer[0] ^ 22) & 3;
    switch (stage_v_19) {
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

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = (st_var_0.buffer[2] * 2 + 67) & 63;
    if (stage_v_20 > 17) {
        out_sink = (out_sink + stage_v_20 - 5) & 255;
        if (stage_v_20 > 32) {
            chk_sum ^= (stage_v_20 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_20 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = (st_var_1.buffer[0] ^ 24) & 3;
    switch (stage_v_21) {
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

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = (out_sink > 100) ? (chk_sum & 31) : (27 & 31);
    out_sink = (out_sink + stage_v_22) & 255;
    chk_sum ^= (stage_v_22 << 1) & 127;

    /* Execution Pipeline Stage 23 */
    st_var_3.buffer[2] = (st_var_3.buffer[2] + 24) & 15;
    int stage_v_23 = (st_var_3.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_23) & 255;
    chk_sum ^= stage_v_23;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_24 = (stage_v_24 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_24) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    st_var_1.buffer[1] = (st_var_1.buffer[1] + 26) & 15;
    int stage_v_25 = (st_var_1.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_25) & 255;
    chk_sum ^= stage_v_25;

    /* Execution Pipeline Stage 26 */
    st_var_2.buffer[2] = (st_var_2.buffer[2] + 27) & 15;
    int stage_v_26 = (st_var_2.buffer[2] * 3) & 63;
    out_sink = (out_sink + stage_v_26) & 255;
    chk_sum ^= stage_v_26;

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
    int stage_v_29 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_29 = (stage_v_29 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_29) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    st_var_2.buffer[0] = (st_var_2.buffer[0] + 31) & 15;
    int stage_v_30 = (st_var_2.buffer[0] * 3) & 63;
    out_sink = (out_sink + stage_v_30) & 255;
    chk_sum ^= stage_v_30;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_31 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = table[0];
    table[0] = (table[1] + 65) & 63;
    out_sink = (out_sink + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = (out_sink > 100) ? (chk_sum & 31) : (38 & 31);
    out_sink = (out_sink + stage_v_33) & 255;
    chk_sum ^= (stage_v_33 << 1) & 127;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = (out_sink > 100) ? (chk_sum & 31) : (39 & 31);
    out_sink = (out_sink + stage_v_34) & 255;
    chk_sum ^= (stage_v_34 << 1) & 127;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = (st_var_3.buffer[0] ^ 38) & 3;
    switch (stage_v_35) {
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

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_36 = (stage_v_36 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_36) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = (out_sink > 100) ? (chk_sum & 31) : (42 & 31);
    out_sink = (out_sink + stage_v_37) & 255;
    chk_sum ^= (stage_v_37 << 1) & 127;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = (st_var_2.buffer[2] * 2 + 121) & 63;
    if (stage_v_38 > 35) {
        out_sink = (out_sink + stage_v_38 - 5) & 255;
        if (stage_v_38 > 50) {
            chk_sum ^= (stage_v_38 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_38 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = (st_var_3.buffer[0] ^ 42) & 3;
    switch (stage_v_39) {
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

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = table[0];
    table[0] = (table[1] + 81) & 63;
    out_sink = (out_sink + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = (st_var_1.buffer[2] * 2 + 130) & 63;
    if (stage_v_41 > 17) {
        out_sink = (out_sink + stage_v_41 - 5) & 255;
        if (stage_v_41 > 32) {
            chk_sum ^= (stage_v_41 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_41 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_42 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = (st_var_3.buffer[1] * 2 + 136) & 63;
    if (stage_v_43 > 21) {
        out_sink = (out_sink + stage_v_43 - 5) & 255;
        if (stage_v_43 > 36) {
            chk_sum ^= (stage_v_43 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_43 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_44 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = (out_sink > 100) ? (chk_sum & 31) : (50 & 31);
    out_sink = (out_sink + stage_v_45) & 255;
    chk_sum ^= (stage_v_45 << 1) & 127;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_46 = (stage_v_46 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_46) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = (st_var_3.buffer[0] ^ 50) & 3;
    switch (stage_v_47) {
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

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[0] = (unsigned char)(stage_v_48 & 255);
    chk_sum = (chk_sum ^ u_var.raw[0]) & 127;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = (out_sink > 100) ? (chk_sum & 31) : (54 & 31);
    out_sink = (out_sink + stage_v_49) & 255;
    chk_sum ^= (stage_v_49 << 1) & 127;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = (out_sink > 100) ? (chk_sum & 31) : (55 & 31);
    out_sink = (out_sink + stage_v_50) & 255;
    chk_sum ^= (stage_v_50 << 1) & 127;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_51 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = (st_var_0.buffer[0] ^ 55) & 3;
    switch (stage_v_52) {
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

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[1] = (unsigned char)(stage_v_53 & 255);
    chk_sum = (chk_sum ^ u_var.raw[1]) & 127;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = table[2];
    table[2] = (table[3] + 109) & 63;
    out_sink = (out_sink + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[3] = (unsigned char)(stage_v_55 & 255);
    chk_sum = (chk_sum ^ u_var.raw[3]) & 127;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_56 = (stage_v_56 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_56) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = (st_var_1.buffer[0] * 2 + 178) & 63;
    if (stage_v_57 > 19) {
        out_sink = (out_sink + stage_v_57 - 5) & 255;
        if (stage_v_57 > 34) {
            chk_sum ^= (stage_v_57 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_57 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 58 */
    st_var_2.buffer[1] = (st_var_2.buffer[1] + 59) & 15;
    int stage_v_58 = (st_var_2.buffer[1] * 3) & 63;
    out_sink = (out_sink + stage_v_58) & 255;
    chk_sum ^= stage_v_58;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_59 = (stage_v_59 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_59) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = (st_var_0.buffer[0] ^ 63) & 3;
    switch (stage_v_60) {
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

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = (out_sink > 100) ? (chk_sum & 31) : (66 & 31);
    out_sink = (out_sink + stage_v_61) & 255;
    chk_sum ^= (stage_v_61 << 1) & 127;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000247_15 & 1) != 0) {
        if ((sec_r000247_3 & 2) != 0) {
            stage_v_62 = (pub_r000247_10 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000247_10 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000247_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_63 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((sec_r000247_2 & 1) != 0) {
        if ((sec_r000247_12 & 2) != 0) {
            stage_v_64 = (pub_r000247_5 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000247_5 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000247_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000247_7 & 2) != 0) {
            stage_v_65 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000247_3 & 2) != 0) {
            stage_v_66 = (pub_r000247_16 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000247_16 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000247_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((sec_r000247_1 & 1) != 0) {
        if ((sec_r000247_7 & 2) != 0) {
            stage_v_67 = (pub_r000247_5 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000247_5 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000247_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000247_1 & 2) != 0) {
            stage_v_68 = (pub_r000247_10 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000247_10 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000247_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_63 & 1) != 0) {
        if ((sec_r000247_3 & 2) != 0) {
            stage_v_69 = (pub_r000247_15 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000247_15 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000247_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000247_2 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_70 = (pub_r000247_6 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000247_6 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000247_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_71 = (pub_r000247_9 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000247_9 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000247_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_72 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_73 = (pub_r000247_9 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000247_9 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000247_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000247_6 & 2) != 0) {
            stage_v_74 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_75 = (pub_r000247_13 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000247_13 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000247_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((sec_r000247_1 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_76 = (pub_r000247_16 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000247_16 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000247_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000247_6 & 2) != 0) {
            stage_v_77 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((stage_v_64 & 1) != 0) {
        if ((sec_r000247_6 & 2) != 0) {
            stage_v_78 = (pub_r000247_8 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000247_8 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000247_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((sec_r000247_5 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_79 = (pub_r000247_10 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000247_10 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000247_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((sec_r000247_12 & 1) != 0) {
        if ((sec_r000247_3 & 2) != 0) {
            stage_v_80 = (pub_r000247_12 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000247_12 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000247_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_72 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_81 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_82 = (pub_r000247_1 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000247_1 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000247_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000247_6 & 2) != 0) {
            stage_v_83 = (pub_r000247_6 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000247_6 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000247_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((sec_r000247_8 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_84 = (pub_r000247_0 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000247_0 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000247_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000247_11 & 2) != 0) {
            stage_v_85 = (pub_r000247_0 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000247_0 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000247_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_62 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_86 = (pub_r000247_14 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000247_14 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000247_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((sec_r000247_2 & 1) != 0) {
        if ((sec_r000247_1 & 2) != 0) {
            stage_v_87 = (pub_r000247_7 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000247_7 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000247_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((sec_r000247_12 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_88 = (pub_r000247_7 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000247_7 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000247_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000247_18 & 2) != 0) {
            stage_v_89 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000247_12 & 1) != 0) {
        if ((sec_r000247_11 & 2) != 0) {
            stage_v_90 = (pub_r000247_12 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000247_12 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000247_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000247_5 & 2) != 0) {
            stage_v_91 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_75 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_92 = (pub_r000247_12 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000247_12 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000247_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((sec_r000247_13 & 1) != 0) {
        if ((sec_r000247_11 & 2) != 0) {
            stage_v_93 = (pub_r000247_5 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000247_5 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000247_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000247_16 & 2) != 0) {
            stage_v_94 = (pub_r000247_14 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000247_14 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000247_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000247_6 & 2) != 0) {
            stage_v_95 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000247_10 & 2) != 0) {
            stage_v_96 = (pub_r000247_3 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000247_3 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000247_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_97 = (pub_r000247_16 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000247_16 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000247_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((stage_v_93 & 1) != 0) {
        if ((sec_r000247_15 & 2) != 0) {
            stage_v_98 = (pub_r000247_6 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000247_6 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000247_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_98 & 1) != 0) {
        if ((sec_r000247_16 & 2) != 0) {
            stage_v_99 = (pub_r000247_6 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000247_6 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000247_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((sec_r000247_18 & 1) != 0) {
        if ((sec_r000247_0 & 2) != 0) {
            stage_v_100 = (pub_r000247_15 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000247_15 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000247_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000247_5 & 2) != 0) {
            stage_v_101 = (pub_r000247_7 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000247_7 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000247_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_102 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((sec_r000247_7 & 1) != 0) {
        if ((sec_r000247_10 & 2) != 0) {
            stage_v_103 = (pub_r000247_1 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000247_1 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000247_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000247_15 & 2) != 0) {
            stage_v_104 = (pub_r000247_16 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000247_16 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000247_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_76 & 1) != 0) {
        if ((sec_r000247_10 & 2) != 0) {
            stage_v_105 = (pub_r000247_3 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000247_3 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000247_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_106 = (pub_r000247_12 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000247_12 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000247_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000247_18 & 2) != 0) {
            stage_v_107 = (pub_r000247_3 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000247_3 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000247_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000247_15 & 2) != 0) {
            stage_v_108 = (pub_r000247_10 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000247_10 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000247_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000247_12 & 2) != 0) {
            stage_v_109 = (pub_r000247_9 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000247_9 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000247_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_68 & 1) != 0) {
        if ((sec_r000247_5 & 2) != 0) {
            stage_v_110 = (pub_r000247_1 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000247_1 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000247_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((sec_r000247_7 & 1) != 0) {
        if ((sec_r000247_17 & 2) != 0) {
            stage_v_111 = (pub_r000247_1 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000247_1 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000247_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000247_15 & 2) != 0) {
            stage_v_112 = (pub_r000247_6 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000247_6 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000247_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_74 & 1) != 0) {
        if ((sec_r000247_17 & 2) != 0) {
            stage_v_113 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((stage_v_79 & 1) != 0) {
        if ((sec_r000247_5 & 2) != 0) {
            stage_v_114 = (pub_r000247_3 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000247_3 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000247_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_97 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_115 = (pub_r000247_14 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000247_14 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000247_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((sec_r000247_9 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_116 = (pub_r000247_2 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000247_2 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000247_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_80 & 1) != 0) {
        if ((sec_r000247_7 & 2) != 0) {
            stage_v_117 = (pub_r000247_16 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000247_16 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000247_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000247_3 & 1) != 0) {
        if ((sec_r000247_6 & 2) != 0) {
            stage_v_118 = (pub_r000247_3 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000247_3 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000247_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_119 = (pub_r000247_6 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000247_6 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000247_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000247_15 & 1) != 0) {
        if ((sec_r000247_7 & 2) != 0) {
            stage_v_120 = (pub_r000247_5 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000247_5 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000247_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((stage_v_104 & 1) != 0) {
        if ((sec_r000247_14 & 2) != 0) {
            stage_v_121 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_122 = (pub_r000247_5 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000247_5 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000247_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000247_10 & 2) != 0) {
            stage_v_123 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000247_15 & 1) != 0) {
        if ((sec_r000247_14 & 2) != 0) {
            stage_v_124 = (pub_r000247_13 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000247_13 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000247_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000247_7 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_125 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000247_15 & 2) != 0) {
            stage_v_126 = (pub_r000247_7 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000247_7 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000247_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_92 & 1) != 0) {
        if ((sec_r000247_14 & 2) != 0) {
            stage_v_127 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((stage_v_94 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_128 = (pub_r000247_16 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000247_16 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000247_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((sec_r000247_16 & 1) != 0) {
        if ((sec_r000247_15 & 2) != 0) {
            stage_v_129 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000247_15 & 1) != 0) {
        if ((sec_r000247_14 & 2) != 0) {
            stage_v_130 = (pub_r000247_9 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000247_9 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000247_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_81 & 1) != 0) {
        if ((sec_r000247_13 & 2) != 0) {
            stage_v_131 = (pub_r000247_9 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000247_9 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000247_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((sec_r000247_2 & 1) != 0) {
        if ((sec_r000247_7 & 2) != 0) {
            stage_v_132 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_105 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_133 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((sec_r000247_14 & 1) != 0) {
        if ((sec_r000247_14 & 2) != 0) {
            stage_v_134 = (pub_r000247_2 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000247_2 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000247_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_122 & 1) != 0) {
        if ((sec_r000247_7 & 2) != 0) {
            stage_v_135 = (pub_r000247_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000247_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000247_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((stage_v_130 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_136 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_133 & 1) != 0) {
        if ((sec_r000247_17 & 2) != 0) {
            stage_v_137 = (pub_r000247_11 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000247_11 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000247_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((sec_r000247_7 & 1) != 0) {
        if ((sec_r000247_12 & 2) != 0) {
            stage_v_138 = (pub_r000247_10 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000247_10 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000247_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((sec_r000247_12 & 1) != 0) {
        if ((sec_r000247_0 & 2) != 0) {
            stage_v_139 = (pub_r000247_13 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000247_13 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000247_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((sec_r000247_11 & 1) != 0) {
        if ((sec_r000247_2 & 2) != 0) {
            stage_v_140 = (pub_r000247_15 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000247_15 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000247_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((sec_r000247_16 & 1) != 0) {
        if ((sec_r000247_3 & 2) != 0) {
            stage_v_141 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_124 & 1) != 0) {
        if ((sec_r000247_5 & 2) != 0) {
            stage_v_142 = (pub_r000247_0 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000247_0 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000247_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_119 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_143 = (pub_r000247_8 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000247_8 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000247_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_108 & 1) != 0) {
        if ((sec_r000247_1 & 2) != 0) {
            stage_v_144 = (pub_r000247_15 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000247_15 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000247_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((sec_r000247_7 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_145 = (pub_r000247_2 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000247_2 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000247_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Execution Pipeline Stage 146 */
    int stage_v_146 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000247_10 & 2) != 0) {
            stage_v_146 = (pub_r000247_17 + 31) & 127;
        } else {
            stage_v_146 = (pub_r000247_17 + 13) & 127;
        }
    } else {
        stage_v_146 = (pub_r000247_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_146) & 255;
    sec_accum = (sec_accum + stage_v_146) & 255;

    /* Execution Pipeline Stage 147 */
    int stage_v_147 = 0;
    if ((stage_v_142 & 1) != 0) {
        if ((sec_r000247_10 & 2) != 0) {
            stage_v_147 = (pub_r000247_12 + 31) & 127;
        } else {
            stage_v_147 = (pub_r000247_12 + 13) & 127;
        }
    } else {
        stage_v_147 = (pub_r000247_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_147) & 255;
    sec_accum = (sec_accum + stage_v_147) & 255;

    /* Execution Pipeline Stage 148 */
    int stage_v_148 = 0;
    if ((sec_r000247_16 & 1) != 0) {
        if ((sec_r000247_8 & 2) != 0) {
            stage_v_148 = (pub_r000247_9 + 31) & 127;
        } else {
            stage_v_148 = (pub_r000247_9 + 13) & 127;
        }
    } else {
        stage_v_148 = (pub_r000247_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_148) & 255;
    sec_accum = (sec_accum + stage_v_148) & 255;

    /* Execution Pipeline Stage 149 */
    int stage_v_149 = 0;
    if ((stage_v_110 & 1) != 0) {
        if ((sec_r000247_4 & 2) != 0) {
            stage_v_149 = (pub_r000247_0 + 31) & 127;
        } else {
            stage_v_149 = (pub_r000247_0 + 13) & 127;
        }
    } else {
        stage_v_149 = (pub_r000247_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_149) & 255;
    sec_accum = (sec_accum + stage_v_149) & 255;

    /* Execution Pipeline Stage 150 */
    int stage_v_150 = 0;
    if ((sec_r000247_16 & 1) != 0) {
        if ((sec_r000247_9 & 2) != 0) {
            stage_v_150 = (pub_r000247_4 + 31) & 127;
        } else {
            stage_v_150 = (pub_r000247_4 + 13) & 127;
        }
    } else {
        stage_v_150 = (pub_r000247_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_150) & 255;
    sec_accum = (sec_accum + stage_v_150) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
