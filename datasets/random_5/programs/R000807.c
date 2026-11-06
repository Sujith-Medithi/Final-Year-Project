/*
 * Benchmark Program: R000807
 * Security Family: nested_implicit_flow
 * Generator Seed: 580713
 * High Inputs: 22 | Low Inputs: 23
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct MatrixBlock_R000807_713_0 {
    int dim;
    int scale;
    int trace;
    int density;
    int determinant;
    unsigned char stride;
    int buffer[3];
};

struct DeviceConfig_R000807_713_1 {
    int baud_rate;
    unsigned char timeout;
    unsigned char port;
    int stop_bits;
    int id;
    int buffer[3];
};

struct AudioFrame_R000807_713_2 {
    int gain;
    unsigned char peak;
    int rms;
    int sample_rate;
    int buffer[3];
};

union PacketPayload_R000807_713_0 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

union RegisterBank_R000807_713_1 {
    int word;
    unsigned char raw[4];
    short pairs[2];
};

int g_out = 0;
int g_chk = 0;
int g_telemetry = 0;

int fn_R000807_713_0(int p0, int p1) {
    int acc = (p0 + 30) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000807_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int window_14 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + window_14) & 63;
    acc ^= aux;
    int checksum_26 = (aux + st.buffer[1]) & 3;
    switch (checksum_26) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int quantum_95 = (st.buffer[0] * 3 + aux) & 63;
    if (quantum_95 > 40) {
        acc = (acc + quantum_95 * 2 + 5) & 127;
        aux ^= (quantum_95 & 15);
    } else {
        acc = (acc - quantum_95 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_1(int p0, int p1, int p2) {
    int acc = (p0 + 38) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000807_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 17;
    int scale_63 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + scale_63) & 63;
    acc ^= aux;
    int weight_12 = (aux + st.buffer[1]) & 3;
    switch (weight_12) {
        case 0: acc = (acc + 6) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_2(int p0, int p1, int p2) {
    int acc = (p0 + 20) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000807_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int phase_97 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_97) & 63;
    acc ^= aux;
    int segment_57 = (st.buffer[0] * 3 + aux) & 63;
    if (segment_57 > 21) {
        acc = (acc + segment_57 * 2 + 5) & 127;
        aux ^= (segment_57 & 15);
    } else {
        acc = (acc - segment_57 + 11) & 127;
        aux += 3;
    }
    int coefficient_67 = (aux + st.buffer[1]) & 3;
    switch (coefficient_67) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 6) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_3(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 41) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000807_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int threshold_19 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + threshold_19) & 63;
    acc ^= aux;
    int local_arr[3] = {4, 9, 15};
    int tracker_41 = local_arr[aux % 3];
    acc = (acc + tracker_41 * 2) & 127;
    int phase_11 = (st.buffer[0] * 3 + aux) & 63;
    if (phase_11 > 18) {
        acc = (acc + phase_11 * 2 + 5) & 127;
        aux ^= (phase_11 & 15);
    } else {
        acc = (acc - phase_11 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_4(int p0, int p1, int p2, int p3, int p4) {
    int acc = (p0 + 3) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000807_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int index_reg_19 = local_arr[aux % 3];
    acc = (acc + index_reg_19 * 2) & 127;
    int cursor_61 = (st.buffer[0] * 3 + aux) & 63;
    if (cursor_61 > 36) {
        acc = (acc + cursor_61 * 2 + 5) & 127;
        aux ^= (cursor_61 & 15);
    } else {
        acc = (acc - cursor_61 + 11) & 127;
        aux += 3;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_5(int p0, int p1, int p2) {
    int acc = (p0 + 22) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000807_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 24;
    int local_arr[3] = {4, 9, 15};
    int pivot_74 = local_arr[aux % 3];
    acc = (acc + pivot_74 * 2) & 127;
    int parity_75 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + parity_75) & 63;
    acc ^= aux;
    int index_reg_68 = (aux + st.buffer[1]) & 3;
    switch (index_reg_68) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 1) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_6(int p0, int p1, int p2) {
    int acc = (p0 + 25) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000807_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 8;
    int vector_87 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + vector_87) & 63;
    acc ^= aux;
    int mask_17 = (aux + st.buffer[1]) & 3;
    switch (mask_17) {
        case 0: acc = (acc + 4) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int local_arr[3] = {4, 9, 15};
    int anchor_44 = local_arr[aux % 3];
    acc = (acc + anchor_44 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_7(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 12) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000807_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int accumulator_68 = (st.buffer[0] * 3 + aux) & 63;
    if (accumulator_68 > 38) {
        acc = (acc + accumulator_68 * 2 + 5) & 127;
        aux ^= (accumulator_68 & 15);
    } else {
        acc = (acc - accumulator_68 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int tracker_83 = local_arr[aux % 3];
    acc = (acc + tracker_83 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_8(int p0, int p1) {
    int acc = (p0 + 32) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000807_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 21;
    int stride_57 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + stride_57) & 63;
    acc ^= aux;
    int segment_53 = (aux + st.buffer[1]) & 3;
    switch (segment_53) {
        case 0: acc = (acc + 3) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    st.buffer[1] = (st.buffer[1] + 4) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int local_arr[3] = {4, 9, 15};
    int quantum_10 = local_arr[aux % 3];
    acc = (acc + quantum_10 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_9(int p0, int p1) {
    int acc = (p0 + 24) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000807_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 26;
    int local_arr[3] = {4, 9, 15};
    int coefficient_39 = local_arr[aux % 3];
    acc = (acc + coefficient_39 * 2) & 127;
    st.buffer[1] = (st.buffer[1] + 2) & 15;
    acc = (acc + st.buffer[1]) & 127;
    int coefficient_92 = (aux + st.buffer[1]) & 3;
    switch (coefficient_92) {
        case 0: acc = (acc + 5) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_10(int p0, int p1, int p2) {
    int acc = (p0 + 18) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000807_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 5;
    int offset_99 = (st.buffer[0] * 3 + aux) & 63;
    if (offset_99 > 19) {
        acc = (acc + offset_99 * 2 + 5) & 127;
        aux ^= (offset_99 & 15);
    } else {
        acc = (acc - offset_99 + 11) & 127;
        aux += 3;
    }
    int threshold_66 = (aux + st.buffer[1]) & 3;
    switch (threshold_66) {
        case 0: acc = (acc + 9) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_11(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 33) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000807_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int accumulator_41 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + accumulator_41) & 63;
    acc ^= aux;
    int margin_24 = (st.buffer[0] * 3 + aux) & 63;
    if (margin_24 > 16) {
        acc = (acc + margin_24 * 2 + 5) & 127;
        aux ^= (margin_24 & 15);
    } else {
        acc = (acc - margin_24 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int cursor_80 = local_arr[aux % 3];
    acc = (acc + cursor_80 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_12(int p0, int p1) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct DeviceConfig_R000807_713_1 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 9;
    int local_arr[3] = {4, 9, 15};
    int stride_33 = local_arr[aux % 3];
    acc = (acc + stride_33 * 2) & 127;
    int accumulator_65 = (aux + st.buffer[1]) & 3;
    switch (accumulator_65) {
        case 0: acc = (acc + 2) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    return (acc + aux) & 255;
}

int fn_R000807_713_13(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 1) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct MatrixBlock_R000807_713_0 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 10;
    int quotient_33 = (st.buffer[0] * 3 + aux) & 63;
    if (quotient_33 > 38) {
        acc = (acc + quotient_33 * 2 + 5) & 127;
        aux ^= (quotient_33 & 15);
    } else {
        acc = (acc - quotient_33 + 11) & 127;
        aux += 3;
    }
    int local_arr[3] = {4, 9, 15};
    int segment_87 = local_arr[aux % 3];
    acc = (acc + segment_87 * 2) & 127;
    return (acc + aux) & 255;
}

int fn_R000807_713_14(int p0, int p1, int p2, int p3) {
    int acc = (p0 + 47) & 127;
    int aux = (p1 ^ 0x3C) & 63;
    struct AudioFrame_R000807_713_2 st = {0};
    st.buffer[0] = (p0 + 3) & 15;
    st.buffer[1] = (p1 + 7) & 15;
    st.buffer[2] = 27;
    int coefficient_11 = (aux + st.buffer[1]) & 3;
    switch (coefficient_11) {
        case 0: acc = (acc + 1) & 127; break;
        case 1: aux ^= 0x1F; break;
        case 2: acc = (acc ^ 0x2A) & 127; break;
        default: acc = (acc + 7) & 127; break;
    }
    int phase_76 = ((acc << 1) ^ (aux >> 1)) & 63;
    aux = (aux + phase_76) & 63;
    acc ^= aux;
    int bound_15 = (st.buffer[0] * 3 + aux) & 63;
    if (bound_15 > 45) {
        acc = (acc + bound_15 * 2 + 5) & 127;
        aux ^= (bound_15 & 15);
    } else {
        acc = (acc - bound_15 + 11) & 127;
        aux += 3;
    }
    st.buffer[1] = (st.buffer[1] + 7) & 15;
    acc = (acc + st.buffer[1]) & 127;
    return (acc + aux) & 255;
}

int main() {
    int sec_r000807_0;
    int sec_r000807_1;
    int sec_r000807_2;
    int sec_r000807_3;
    int sec_r000807_4;
    int sec_r000807_5;
    int sec_r000807_6;
    int sec_r000807_7;
    int sec_r000807_8;
    int sec_r000807_9;
    int sec_r000807_10;
    int sec_r000807_11;
    int sec_r000807_12;
    int sec_r000807_13;
    int sec_r000807_14;
    int sec_r000807_15;
    int sec_r000807_16;
    int sec_r000807_17;
    int sec_r000807_18;
    int sec_r000807_19;
    int sec_r000807_20;
    int sec_r000807_21;
    int pub_r000807_0;
    int pub_r000807_1;
    int pub_r000807_2;
    int pub_r000807_3;
    int pub_r000807_4;
    int pub_r000807_5;
    int pub_r000807_6;
    int pub_r000807_7;
    int pub_r000807_8;
    int pub_r000807_9;
    int pub_r000807_10;
    int pub_r000807_11;
    int pub_r000807_12;
    int pub_r000807_13;
    int pub_r000807_14;
    int pub_r000807_15;
    int pub_r000807_16;
    int pub_r000807_17;
    int pub_r000807_18;
    int pub_r000807_19;
    int pub_r000807_20;
    int pub_r000807_21;
    int pub_r000807_22;
    int out_sink = 0;
    int chk_sum = 0;
    int sec_accum = 0;

    __CPROVER_assume(pub_r000807_0 >= -100 && pub_r000807_0 <= 100);
    __CPROVER_assume(pub_r000807_1 >= -100 && pub_r000807_1 <= 100);
    __CPROVER_assume(pub_r000807_2 >= -100 && pub_r000807_2 <= 100);
    __CPROVER_assume(pub_r000807_3 >= -100 && pub_r000807_3 <= 100);
    __CPROVER_assume(pub_r000807_4 >= -100 && pub_r000807_4 <= 100);
    __CPROVER_assume(pub_r000807_5 >= -100 && pub_r000807_5 <= 100);
    __CPROVER_assume(pub_r000807_6 >= -100 && pub_r000807_6 <= 100);
    __CPROVER_assume(pub_r000807_7 >= -100 && pub_r000807_7 <= 100);
    __CPROVER_assume(pub_r000807_8 >= -100 && pub_r000807_8 <= 100);
    __CPROVER_assume(pub_r000807_9 >= -100 && pub_r000807_9 <= 100);
    __CPROVER_assume(pub_r000807_10 >= -100 && pub_r000807_10 <= 100);
    __CPROVER_assume(pub_r000807_11 >= -100 && pub_r000807_11 <= 100);
    __CPROVER_assume(pub_r000807_12 >= -100 && pub_r000807_12 <= 100);
    __CPROVER_assume(pub_r000807_13 >= -100 && pub_r000807_13 <= 100);
    __CPROVER_assume(pub_r000807_14 >= -100 && pub_r000807_14 <= 100);
    __CPROVER_assume(pub_r000807_15 >= -100 && pub_r000807_15 <= 100);
    __CPROVER_assume(pub_r000807_16 >= -100 && pub_r000807_16 <= 100);
    __CPROVER_assume(pub_r000807_17 >= -100 && pub_r000807_17 <= 100);
    __CPROVER_assume(pub_r000807_18 >= -100 && pub_r000807_18 <= 100);
    __CPROVER_assume(pub_r000807_19 >= -100 && pub_r000807_19 <= 100);
    __CPROVER_assume(pub_r000807_20 >= -100 && pub_r000807_20 <= 100);
    __CPROVER_assume(pub_r000807_21 >= -100 && pub_r000807_21 <= 100);
    __CPROVER_assume(pub_r000807_22 >= -100 && pub_r000807_22 <= 100);
    __CPROVER_assume(sec_r000807_0 >= 0 && sec_r000807_0 <= 255);
    __CPROVER_assume(sec_r000807_1 >= 0 && sec_r000807_1 <= 255);
    __CPROVER_assume(sec_r000807_2 >= 0 && sec_r000807_2 <= 255);
    __CPROVER_assume(sec_r000807_3 >= 0 && sec_r000807_3 <= 255);
    __CPROVER_assume(sec_r000807_4 >= 0 && sec_r000807_4 <= 255);
    __CPROVER_assume(sec_r000807_5 >= 0 && sec_r000807_5 <= 255);
    __CPROVER_assume(sec_r000807_6 >= 0 && sec_r000807_6 <= 255);
    __CPROVER_assume(sec_r000807_7 >= 0 && sec_r000807_7 <= 255);
    __CPROVER_assume(sec_r000807_8 >= 0 && sec_r000807_8 <= 255);
    __CPROVER_assume(sec_r000807_9 >= 0 && sec_r000807_9 <= 255);
    __CPROVER_assume(sec_r000807_10 >= 0 && sec_r000807_10 <= 255);
    __CPROVER_assume(sec_r000807_11 >= 0 && sec_r000807_11 <= 255);
    __CPROVER_assume(sec_r000807_12 >= 0 && sec_r000807_12 <= 255);
    __CPROVER_assume(sec_r000807_13 >= 0 && sec_r000807_13 <= 255);
    __CPROVER_assume(sec_r000807_14 >= 0 && sec_r000807_14 <= 255);
    __CPROVER_assume(sec_r000807_15 >= 0 && sec_r000807_15 <= 255);
    __CPROVER_assume(sec_r000807_16 >= 0 && sec_r000807_16 <= 255);
    __CPROVER_assume(sec_r000807_17 >= 0 && sec_r000807_17 <= 255);
    __CPROVER_assume(sec_r000807_18 >= 0 && sec_r000807_18 <= 255);
    __CPROVER_assume(sec_r000807_19 >= 0 && sec_r000807_19 <= 255);
    __CPROVER_assume(sec_r000807_20 >= 0 && sec_r000807_20 <= 255);
    __CPROVER_assume(sec_r000807_21 >= 0 && sec_r000807_21 <= 255);

    struct MatrixBlock_R000807_713_0 st_var_0 = {0};
    st_var_0.buffer[0] = (pub_r000807_0 + 1) & 15;
    st_var_0.buffer[1] = (pub_r000807_0 + 4) & 15;
    st_var_0.buffer[2] = (pub_r000807_0 + 7) & 15;
    struct DeviceConfig_R000807_713_1 st_var_1 = {0};
    st_var_1.buffer[0] = (pub_r000807_0 + 4) & 15;
    st_var_1.buffer[1] = (pub_r000807_0 + 9) & 15;
    st_var_1.buffer[2] = (pub_r000807_0 + 9) & 15;
    struct AudioFrame_R000807_713_2 st_var_2 = {0};
    st_var_2.buffer[0] = (pub_r000807_0 + 7) & 15;
    st_var_2.buffer[1] = (pub_r000807_0 + 14) & 15;
    st_var_2.buffer[2] = (pub_r000807_0 + 11) & 15;

    union PacketPayload_R000807_713_0 u_var;
    u_var.word = 0;
    int table[4] = { 11, 23, 47, 89 };

    /* Execution Pipeline Stage 0 */
    int stage_v_0 = 0;
    for (int step = 0; step < 2; step++) {
        stage_v_0 = (stage_v_0 + step * 5 + table[step]) & 63;
        chk_sum = (chk_sum + stage_v_0) & 127;
    }
    out_sink = (out_sink + stage_v_0) & 255;

    /* Execution Pipeline Stage 1 */
    int stage_v_1 = table[1];
    table[1] = (table[2] + 3) & 63;
    out_sink = (out_sink + stage_v_1) & 255;

    /* Execution Pipeline Stage 2 */
    int stage_v_2 = ((out_sink << 1) ^ (chk_sum >> 1)) & 63;
    u_var.raw[2] = (unsigned char)(stage_v_2 & 255);
    chk_sum = (chk_sum ^ u_var.raw[2]) & 127;

    /* Execution Pipeline Stage 3 */
    int stage_v_3 = (st_var_0.buffer[0] ^ 6) & 3;
    switch (stage_v_3) {
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
    int stage_v_6 = (st_var_0.buffer[0] * 2 + 25) & 63;
    if (stage_v_6 > 21) {
        out_sink = (out_sink + stage_v_6 - 5) & 255;
        if (stage_v_6 > 36) {
            chk_sum ^= (stage_v_6 & 31);
        } else {
            chk_sum = (chk_sum + 3) & 127;
        }
    } else {
        out_sink = (out_sink - stage_v_6 + 9) & 255;
        chk_sum ^= 0x1A;
    }

    /* Execution Pipeline Stage 7 */
    int stage_v_7 = (st_var_1.buffer[0] ^ 10) & 3;
    switch (stage_v_7) {
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

    /* Execution Pipeline Stage 8 */
    int stage_v_8 = 0;
    if ((sec_r000807_21 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_8 = (pub_r000807_14 + 31) & 127;
        } else {
            stage_v_8 = (pub_r000807_14 + 13) & 127;
        }
    } else {
        stage_v_8 = (pub_r000807_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_8) & 255;
    sec_accum = (sec_accum + stage_v_8) & 255;

    /* Execution Pipeline Stage 9 */
    int stage_v_9 = 0;
    if ((sec_r000807_1 & 1) != 0) {
        if ((sec_r000807_9 & 2) != 0) {
            stage_v_9 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_9 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_9 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_9) & 255;
    sec_accum = (sec_accum + stage_v_9) & 255;

    /* Execution Pipeline Stage 10 */
    int stage_v_10 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_10 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_10 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_10 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_10) & 255;
    sec_accum = (sec_accum + stage_v_10) & 255;

    /* Execution Pipeline Stage 11 */
    int stage_v_11 = 0;
    if ((sec_r000807_1 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_11 = (pub_r000807_6 + 31) & 127;
        } else {
            stage_v_11 = (pub_r000807_6 + 13) & 127;
        }
    } else {
        stage_v_11 = (pub_r000807_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_11) & 255;
    sec_accum = (sec_accum + stage_v_11) & 255;

    /* Execution Pipeline Stage 12 */
    int stage_v_12 = 0;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r000807_15 & 2) != 0) {
            stage_v_12 = (pub_r000807_12 + 31) & 127;
        } else {
            stage_v_12 = (pub_r000807_12 + 13) & 127;
        }
    } else {
        stage_v_12 = (pub_r000807_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_12) & 255;
    sec_accum = (sec_accum + stage_v_12) & 255;

    /* Execution Pipeline Stage 13 */
    int stage_v_13 = 0;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_13 = (pub_r000807_18 + 31) & 127;
        } else {
            stage_v_13 = (pub_r000807_18 + 13) & 127;
        }
    } else {
        stage_v_13 = (pub_r000807_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_13) & 255;
    sec_accum = (sec_accum + stage_v_13) & 255;

    /* Execution Pipeline Stage 14 */
    int stage_v_14 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_14 = (pub_r000807_16 + 31) & 127;
        } else {
            stage_v_14 = (pub_r000807_16 + 13) & 127;
        }
    } else {
        stage_v_14 = (pub_r000807_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_14) & 255;
    sec_accum = (sec_accum + stage_v_14) & 255;

    /* Execution Pipeline Stage 15 */
    int stage_v_15 = 0;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r000807_12 & 2) != 0) {
            stage_v_15 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_15 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_15 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_15) & 255;
    sec_accum = (sec_accum + stage_v_15) & 255;

    /* Execution Pipeline Stage 16 */
    int stage_v_16 = 0;
    if ((sec_r000807_10 & 1) != 0) {
        if ((sec_r000807_3 & 2) != 0) {
            stage_v_16 = (pub_r000807_6 + 31) & 127;
        } else {
            stage_v_16 = (pub_r000807_6 + 13) & 127;
        }
    } else {
        stage_v_16 = (pub_r000807_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_16) & 255;
    sec_accum = (sec_accum + stage_v_16) & 255;

    /* Execution Pipeline Stage 17 */
    int stage_v_17 = 0;
    if ((sec_r000807_10 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_17 = (pub_r000807_22 + 31) & 127;
        } else {
            stage_v_17 = (pub_r000807_22 + 13) & 127;
        }
    } else {
        stage_v_17 = (pub_r000807_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_17) & 255;
    sec_accum = (sec_accum + stage_v_17) & 255;

    /* Execution Pipeline Stage 18 */
    int stage_v_18 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_18 = (pub_r000807_4 + 31) & 127;
        } else {
            stage_v_18 = (pub_r000807_4 + 13) & 127;
        }
    } else {
        stage_v_18 = (pub_r000807_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_18) & 255;
    sec_accum = (sec_accum + stage_v_18) & 255;

    /* Execution Pipeline Stage 19 */
    int stage_v_19 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_19 = (pub_r000807_6 + 31) & 127;
        } else {
            stage_v_19 = (pub_r000807_6 + 13) & 127;
        }
    } else {
        stage_v_19 = (pub_r000807_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_19) & 255;
    sec_accum = (sec_accum + stage_v_19) & 255;

    /* Execution Pipeline Stage 20 */
    int stage_v_20 = 0;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_20 = (pub_r000807_7 + 31) & 127;
        } else {
            stage_v_20 = (pub_r000807_7 + 13) & 127;
        }
    } else {
        stage_v_20 = (pub_r000807_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_20) & 255;
    sec_accum = (sec_accum + stage_v_20) & 255;

    /* Execution Pipeline Stage 21 */
    int stage_v_21 = 0;
    if ((sec_r000807_20 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_21 = (pub_r000807_11 + 31) & 127;
        } else {
            stage_v_21 = (pub_r000807_11 + 13) & 127;
        }
    } else {
        stage_v_21 = (pub_r000807_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_21) & 255;
    sec_accum = (sec_accum + stage_v_21) & 255;

    /* Execution Pipeline Stage 22 */
    int stage_v_22 = 0;
    if ((sec_r000807_15 & 1) != 0) {
        if ((sec_r000807_14 & 2) != 0) {
            stage_v_22 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_22 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_22 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_22) & 255;
    sec_accum = (sec_accum + stage_v_22) & 255;

    /* Execution Pipeline Stage 23 */
    int stage_v_23 = 0;
    if ((sec_r000807_1 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_23 = (pub_r000807_19 + 31) & 127;
        } else {
            stage_v_23 = (pub_r000807_19 + 13) & 127;
        }
    } else {
        stage_v_23 = (pub_r000807_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_23) & 255;
    sec_accum = (sec_accum + stage_v_23) & 255;

    /* Execution Pipeline Stage 24 */
    int stage_v_24 = 0;
    if ((sec_r000807_7 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_24 = (pub_r000807_4 + 31) & 127;
        } else {
            stage_v_24 = (pub_r000807_4 + 13) & 127;
        }
    } else {
        stage_v_24 = (pub_r000807_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_24) & 255;
    sec_accum = (sec_accum + stage_v_24) & 255;

    /* Execution Pipeline Stage 25 */
    int stage_v_25 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000807_12 & 2) != 0) {
            stage_v_25 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_25 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_25 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_25) & 255;
    sec_accum = (sec_accum + stage_v_25) & 255;

    /* Execution Pipeline Stage 26 */
    int stage_v_26 = 0;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_26 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_26 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_26 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_26) & 255;
    sec_accum = (sec_accum + stage_v_26) & 255;

    /* Execution Pipeline Stage 27 */
    int stage_v_27 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000807_19 & 2) != 0) {
            stage_v_27 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_27 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_27 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_27) & 255;
    sec_accum = (sec_accum + stage_v_27) & 255;

    /* Execution Pipeline Stage 28 */
    int stage_v_28 = 0;
    if ((stage_v_24 & 1) != 0) {
        if ((sec_r000807_12 & 2) != 0) {
            stage_v_28 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_28 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_28 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_28) & 255;
    sec_accum = (sec_accum + stage_v_28) & 255;

    /* Execution Pipeline Stage 29 */
    int stage_v_29 = 0;
    if ((sec_r000807_10 & 1) != 0) {
        if ((sec_r000807_5 & 2) != 0) {
            stage_v_29 = (pub_r000807_12 + 31) & 127;
        } else {
            stage_v_29 = (pub_r000807_12 + 13) & 127;
        }
    } else {
        stage_v_29 = (pub_r000807_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_29) & 255;
    sec_accum = (sec_accum + stage_v_29) & 255;

    /* Execution Pipeline Stage 30 */
    int stage_v_30 = 0;
    if ((sec_r000807_12 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_30 = (pub_r000807_7 + 31) & 127;
        } else {
            stage_v_30 = (pub_r000807_7 + 13) & 127;
        }
    } else {
        stage_v_30 = (pub_r000807_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_30) & 255;
    sec_accum = (sec_accum + stage_v_30) & 255;

    /* Execution Pipeline Stage 31 */
    int stage_v_31 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000807_9 & 2) != 0) {
            stage_v_31 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_31 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_31 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_31) & 255;
    sec_accum = (sec_accum + stage_v_31) & 255;

    /* Execution Pipeline Stage 32 */
    int stage_v_32 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000807_14 & 2) != 0) {
            stage_v_32 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_32 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_32 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_32) & 255;
    sec_accum = (sec_accum + stage_v_32) & 255;

    /* Execution Pipeline Stage 33 */
    int stage_v_33 = 0;
    if ((stage_v_9 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_33 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_33 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_33 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_33) & 255;
    sec_accum = (sec_accum + stage_v_33) & 255;

    /* Execution Pipeline Stage 34 */
    int stage_v_34 = 0;
    if ((sec_r000807_16 & 1) != 0) {
        if ((sec_r000807_12 & 2) != 0) {
            stage_v_34 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_34 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_34 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_34) & 255;
    sec_accum = (sec_accum + stage_v_34) & 255;

    /* Execution Pipeline Stage 35 */
    int stage_v_35 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000807_11 & 2) != 0) {
            stage_v_35 = (pub_r000807_14 + 31) & 127;
        } else {
            stage_v_35 = (pub_r000807_14 + 13) & 127;
        }
    } else {
        stage_v_35 = (pub_r000807_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_35) & 255;
    sec_accum = (sec_accum + stage_v_35) & 255;

    /* Execution Pipeline Stage 36 */
    int stage_v_36 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_36 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_36 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_36 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_36) & 255;
    sec_accum = (sec_accum + stage_v_36) & 255;

    /* Execution Pipeline Stage 37 */
    int stage_v_37 = 0;
    if ((sec_r000807_4 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_37 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_37 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_37 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_37) & 255;
    sec_accum = (sec_accum + stage_v_37) & 255;

    /* Execution Pipeline Stage 38 */
    int stage_v_38 = 0;
    if ((sec_r000807_16 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_38 = (pub_r000807_11 + 31) & 127;
        } else {
            stage_v_38 = (pub_r000807_11 + 13) & 127;
        }
    } else {
        stage_v_38 = (pub_r000807_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_38) & 255;
    sec_accum = (sec_accum + stage_v_38) & 255;

    /* Execution Pipeline Stage 39 */
    int stage_v_39 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_39 = (pub_r000807_1 + 31) & 127;
        } else {
            stage_v_39 = (pub_r000807_1 + 13) & 127;
        }
    } else {
        stage_v_39 = (pub_r000807_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_39) & 255;
    sec_accum = (sec_accum + stage_v_39) & 255;

    /* Execution Pipeline Stage 40 */
    int stage_v_40 = 0;
    if ((sec_r000807_10 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_40 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_40 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_40 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_40) & 255;
    sec_accum = (sec_accum + stage_v_40) & 255;

    /* Execution Pipeline Stage 41 */
    int stage_v_41 = 0;
    if ((sec_r000807_2 & 1) != 0) {
        if ((sec_r000807_15 & 2) != 0) {
            stage_v_41 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_41 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_41 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_41) & 255;
    sec_accum = (sec_accum + stage_v_41) & 255;

    /* Execution Pipeline Stage 42 */
    int stage_v_42 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_42 = (pub_r000807_1 + 31) & 127;
        } else {
            stage_v_42 = (pub_r000807_1 + 13) & 127;
        }
    } else {
        stage_v_42 = (pub_r000807_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_42) & 255;
    sec_accum = (sec_accum + stage_v_42) & 255;

    /* Execution Pipeline Stage 43 */
    int stage_v_43 = 0;
    if ((sec_r000807_21 & 1) != 0) {
        if ((sec_r000807_14 & 2) != 0) {
            stage_v_43 = (pub_r000807_14 + 31) & 127;
        } else {
            stage_v_43 = (pub_r000807_14 + 13) & 127;
        }
    } else {
        stage_v_43 = (pub_r000807_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_43) & 255;
    sec_accum = (sec_accum + stage_v_43) & 255;

    /* Execution Pipeline Stage 44 */
    int stage_v_44 = 0;
    if ((sec_r000807_5 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_44 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_44 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_44 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_44) & 255;
    sec_accum = (sec_accum + stage_v_44) & 255;

    /* Execution Pipeline Stage 45 */
    int stage_v_45 = 0;
    if ((stage_v_34 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_45 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_45 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_45 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_45) & 255;
    sec_accum = (sec_accum + stage_v_45) & 255;

    /* Execution Pipeline Stage 46 */
    int stage_v_46 = 0;
    if ((sec_r000807_2 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_46 = (pub_r000807_22 + 31) & 127;
        } else {
            stage_v_46 = (pub_r000807_22 + 13) & 127;
        }
    } else {
        stage_v_46 = (pub_r000807_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_46) & 255;
    sec_accum = (sec_accum + stage_v_46) & 255;

    /* Execution Pipeline Stage 47 */
    int stage_v_47 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_47 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_47 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_47 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_47) & 255;
    sec_accum = (sec_accum + stage_v_47) & 255;

    /* Execution Pipeline Stage 48 */
    int stage_v_48 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000807_6 & 2) != 0) {
            stage_v_48 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_48 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_48 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_48) & 255;
    sec_accum = (sec_accum + stage_v_48) & 255;

    /* Execution Pipeline Stage 49 */
    int stage_v_49 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000807_10 & 2) != 0) {
            stage_v_49 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_49 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_49 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_49) & 255;
    sec_accum = (sec_accum + stage_v_49) & 255;

    /* Execution Pipeline Stage 50 */
    int stage_v_50 = 0;
    if ((stage_v_15 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_50 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_50 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_50 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_50) & 255;
    sec_accum = (sec_accum + stage_v_50) & 255;

    /* Execution Pipeline Stage 51 */
    int stage_v_51 = 0;
    if ((sec_r000807_5 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_51 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_51 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_51 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_51) & 255;
    sec_accum = (sec_accum + stage_v_51) & 255;

    /* Execution Pipeline Stage 52 */
    int stage_v_52 = 0;
    if ((stage_v_30 & 1) != 0) {
        if ((sec_r000807_10 & 2) != 0) {
            stage_v_52 = (pub_r000807_9 + 31) & 127;
        } else {
            stage_v_52 = (pub_r000807_9 + 13) & 127;
        }
    } else {
        stage_v_52 = (pub_r000807_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_52) & 255;
    sec_accum = (sec_accum + stage_v_52) & 255;

    /* Execution Pipeline Stage 53 */
    int stage_v_53 = 0;
    if ((stage_v_49 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_53 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_53 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_53 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_53) & 255;
    sec_accum = (sec_accum + stage_v_53) & 255;

    /* Execution Pipeline Stage 54 */
    int stage_v_54 = 0;
    if ((sec_r000807_15 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_54 = (pub_r000807_7 + 31) & 127;
        } else {
            stage_v_54 = (pub_r000807_7 + 13) & 127;
        }
    } else {
        stage_v_54 = (pub_r000807_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_54) & 255;
    sec_accum = (sec_accum + stage_v_54) & 255;

    /* Execution Pipeline Stage 55 */
    int stage_v_55 = 0;
    if ((sec_r000807_5 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_55 = (pub_r000807_20 + 31) & 127;
        } else {
            stage_v_55 = (pub_r000807_20 + 13) & 127;
        }
    } else {
        stage_v_55 = (pub_r000807_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_55) & 255;
    sec_accum = (sec_accum + stage_v_55) & 255;

    /* Execution Pipeline Stage 56 */
    int stage_v_56 = 0;
    if ((stage_v_47 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_56 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_56 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_56 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_56) & 255;
    sec_accum = (sec_accum + stage_v_56) & 255;

    /* Execution Pipeline Stage 57 */
    int stage_v_57 = 0;
    if ((stage_v_25 & 1) != 0) {
        if ((sec_r000807_19 & 2) != 0) {
            stage_v_57 = (pub_r000807_6 + 31) & 127;
        } else {
            stage_v_57 = (pub_r000807_6 + 13) & 127;
        }
    } else {
        stage_v_57 = (pub_r000807_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_57) & 255;
    sec_accum = (sec_accum + stage_v_57) & 255;

    /* Execution Pipeline Stage 58 */
    int stage_v_58 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_58 = (pub_r000807_11 + 31) & 127;
        } else {
            stage_v_58 = (pub_r000807_11 + 13) & 127;
        }
    } else {
        stage_v_58 = (pub_r000807_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_58) & 255;
    sec_accum = (sec_accum + stage_v_58) & 255;

    /* Execution Pipeline Stage 59 */
    int stage_v_59 = 0;
    if ((sec_r000807_5 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_59 = (pub_r000807_20 + 31) & 127;
        } else {
            stage_v_59 = (pub_r000807_20 + 13) & 127;
        }
    } else {
        stage_v_59 = (pub_r000807_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_59) & 255;
    sec_accum = (sec_accum + stage_v_59) & 255;

    /* Execution Pipeline Stage 60 */
    int stage_v_60 = 0;
    if ((stage_v_27 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_60 = (pub_r000807_11 + 31) & 127;
        } else {
            stage_v_60 = (pub_r000807_11 + 13) & 127;
        }
    } else {
        stage_v_60 = (pub_r000807_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_60) & 255;
    sec_accum = (sec_accum + stage_v_60) & 255;

    /* Execution Pipeline Stage 61 */
    int stage_v_61 = 0;
    if ((stage_v_18 & 1) != 0) {
        if ((sec_r000807_14 & 2) != 0) {
            stage_v_61 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_61 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_61 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_61) & 255;
    sec_accum = (sec_accum + stage_v_61) & 255;

    /* Execution Pipeline Stage 62 */
    int stage_v_62 = 0;
    if ((sec_r000807_1 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_62 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_62 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_62 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_62) & 255;
    sec_accum = (sec_accum + stage_v_62) & 255;

    /* Execution Pipeline Stage 63 */
    int stage_v_63 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_63 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_63 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_63 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_63) & 255;
    sec_accum = (sec_accum + stage_v_63) & 255;

    /* Execution Pipeline Stage 64 */
    int stage_v_64 = 0;
    if ((stage_v_57 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_64 = (pub_r000807_20 + 31) & 127;
        } else {
            stage_v_64 = (pub_r000807_20 + 13) & 127;
        }
    } else {
        stage_v_64 = (pub_r000807_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_64) & 255;
    sec_accum = (sec_accum + stage_v_64) & 255;

    /* Execution Pipeline Stage 65 */
    int stage_v_65 = 0;
    if ((sec_r000807_20 & 1) != 0) {
        if ((sec_r000807_3 & 2) != 0) {
            stage_v_65 = (pub_r000807_12 + 31) & 127;
        } else {
            stage_v_65 = (pub_r000807_12 + 13) & 127;
        }
    } else {
        stage_v_65 = (pub_r000807_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_65) & 255;
    sec_accum = (sec_accum + stage_v_65) & 255;

    /* Execution Pipeline Stage 66 */
    int stage_v_66 = 0;
    if ((sec_r000807_21 & 1) != 0) {
        if ((sec_r000807_5 & 2) != 0) {
            stage_v_66 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_66 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_66 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_66) & 255;
    sec_accum = (sec_accum + stage_v_66) & 255;

    /* Execution Pipeline Stage 67 */
    int stage_v_67 = 0;
    if ((stage_v_45 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_67 = (pub_r000807_4 + 31) & 127;
        } else {
            stage_v_67 = (pub_r000807_4 + 13) & 127;
        }
    } else {
        stage_v_67 = (pub_r000807_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_67) & 255;
    sec_accum = (sec_accum + stage_v_67) & 255;

    /* Execution Pipeline Stage 68 */
    int stage_v_68 = 0;
    if ((stage_v_48 & 1) != 0) {
        if ((sec_r000807_10 & 2) != 0) {
            stage_v_68 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_68 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_68 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_68) & 255;
    sec_accum = (sec_accum + stage_v_68) & 255;

    /* Execution Pipeline Stage 69 */
    int stage_v_69 = 0;
    if ((stage_v_35 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_69 = (pub_r000807_7 + 31) & 127;
        } else {
            stage_v_69 = (pub_r000807_7 + 13) & 127;
        }
    } else {
        stage_v_69 = (pub_r000807_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_69) & 255;
    sec_accum = (sec_accum + stage_v_69) & 255;

    /* Execution Pipeline Stage 70 */
    int stage_v_70 = 0;
    if ((sec_r000807_17 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_70 = (pub_r000807_20 + 31) & 127;
        } else {
            stage_v_70 = (pub_r000807_20 + 13) & 127;
        }
    } else {
        stage_v_70 = (pub_r000807_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_70) & 255;
    sec_accum = (sec_accum + stage_v_70) & 255;

    /* Execution Pipeline Stage 71 */
    int stage_v_71 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_71 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_71 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_71 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_71) & 255;
    sec_accum = (sec_accum + stage_v_71) & 255;

    /* Execution Pipeline Stage 72 */
    int stage_v_72 = 0;
    if ((stage_v_11 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_72 = (pub_r000807_4 + 31) & 127;
        } else {
            stage_v_72 = (pub_r000807_4 + 13) & 127;
        }
    } else {
        stage_v_72 = (pub_r000807_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_72) & 255;
    sec_accum = (sec_accum + stage_v_72) & 255;

    /* Execution Pipeline Stage 73 */
    int stage_v_73 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000807_19 & 2) != 0) {
            stage_v_73 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_73 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_73 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_73) & 255;
    sec_accum = (sec_accum + stage_v_73) & 255;

    /* Execution Pipeline Stage 74 */
    int stage_v_74 = 0;
    if ((sec_r000807_16 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_74 = (pub_r000807_1 + 31) & 127;
        } else {
            stage_v_74 = (pub_r000807_1 + 13) & 127;
        }
    } else {
        stage_v_74 = (pub_r000807_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_74) & 255;
    sec_accum = (sec_accum + stage_v_74) & 255;

    /* Execution Pipeline Stage 75 */
    int stage_v_75 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_75 = (pub_r000807_17 + 31) & 127;
        } else {
            stage_v_75 = (pub_r000807_17 + 13) & 127;
        }
    } else {
        stage_v_75 = (pub_r000807_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_75) & 255;
    sec_accum = (sec_accum + stage_v_75) & 255;

    /* Execution Pipeline Stage 76 */
    int stage_v_76 = 0;
    if ((stage_v_67 & 1) != 0) {
        if ((sec_r000807_3 & 2) != 0) {
            stage_v_76 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_76 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_76 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_76) & 255;
    sec_accum = (sec_accum + stage_v_76) & 255;

    /* Execution Pipeline Stage 77 */
    int stage_v_77 = 0;
    if ((stage_v_69 & 1) != 0) {
        if ((sec_r000807_9 & 2) != 0) {
            stage_v_77 = (pub_r000807_15 + 31) & 127;
        } else {
            stage_v_77 = (pub_r000807_15 + 13) & 127;
        }
    } else {
        stage_v_77 = (pub_r000807_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_77) & 255;
    sec_accum = (sec_accum + stage_v_77) & 255;

    /* Execution Pipeline Stage 78 */
    int stage_v_78 = 0;
    if ((sec_r000807_12 & 1) != 0) {
        if ((sec_r000807_6 & 2) != 0) {
            stage_v_78 = (pub_r000807_19 + 31) & 127;
        } else {
            stage_v_78 = (pub_r000807_19 + 13) & 127;
        }
    } else {
        stage_v_78 = (pub_r000807_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_78) & 255;
    sec_accum = (sec_accum + stage_v_78) & 255;

    /* Execution Pipeline Stage 79 */
    int stage_v_79 = 0;
    if ((stage_v_65 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_79 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_79 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_79 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_79) & 255;
    sec_accum = (sec_accum + stage_v_79) & 255;

    /* Execution Pipeline Stage 80 */
    int stage_v_80 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000807_15 & 2) != 0) {
            stage_v_80 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_80 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_80 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_80) & 255;
    sec_accum = (sec_accum + stage_v_80) & 255;

    /* Execution Pipeline Stage 81 */
    int stage_v_81 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_81 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_81 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_81 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_81) & 255;
    sec_accum = (sec_accum + stage_v_81) & 255;

    /* Execution Pipeline Stage 82 */
    int stage_v_82 = 0;
    if ((sec_r000807_16 & 1) != 0) {
        if ((sec_r000807_11 & 2) != 0) {
            stage_v_82 = (pub_r000807_16 + 31) & 127;
        } else {
            stage_v_82 = (pub_r000807_16 + 13) & 127;
        }
    } else {
        stage_v_82 = (pub_r000807_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_82) & 255;
    sec_accum = (sec_accum + stage_v_82) & 255;

    /* Execution Pipeline Stage 83 */
    int stage_v_83 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000807_15 & 2) != 0) {
            stage_v_83 = (pub_r000807_18 + 31) & 127;
        } else {
            stage_v_83 = (pub_r000807_18 + 13) & 127;
        }
    } else {
        stage_v_83 = (pub_r000807_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_83) & 255;
    sec_accum = (sec_accum + stage_v_83) & 255;

    /* Execution Pipeline Stage 84 */
    int stage_v_84 = 0;
    if ((stage_v_10 & 1) != 0) {
        if ((sec_r000807_19 & 2) != 0) {
            stage_v_84 = (pub_r000807_15 + 31) & 127;
        } else {
            stage_v_84 = (pub_r000807_15 + 13) & 127;
        }
    } else {
        stage_v_84 = (pub_r000807_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_84) & 255;
    sec_accum = (sec_accum + stage_v_84) & 255;

    /* Execution Pipeline Stage 85 */
    int stage_v_85 = 0;
    if ((stage_v_58 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_85 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_85 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_85 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_85) & 255;
    sec_accum = (sec_accum + stage_v_85) & 255;

    /* Execution Pipeline Stage 86 */
    int stage_v_86 = 0;
    if ((stage_v_19 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_86 = (pub_r000807_11 + 31) & 127;
        } else {
            stage_v_86 = (pub_r000807_11 + 13) & 127;
        }
    } else {
        stage_v_86 = (pub_r000807_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_86) & 255;
    sec_accum = (sec_accum + stage_v_86) & 255;

    /* Execution Pipeline Stage 87 */
    int stage_v_87 = 0;
    if ((stage_v_50 & 1) != 0) {
        if ((sec_r000807_11 & 2) != 0) {
            stage_v_87 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_87 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_87 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_87) & 255;
    sec_accum = (sec_accum + stage_v_87) & 255;

    /* Execution Pipeline Stage 88 */
    int stage_v_88 = 0;
    if ((stage_v_29 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_88 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_88 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_88 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_88) & 255;
    sec_accum = (sec_accum + stage_v_88) & 255;

    /* Execution Pipeline Stage 89 */
    int stage_v_89 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000807_19 & 2) != 0) {
            stage_v_89 = (pub_r000807_9 + 31) & 127;
        } else {
            stage_v_89 = (pub_r000807_9 + 13) & 127;
        }
    } else {
        stage_v_89 = (pub_r000807_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_89) & 255;
    sec_accum = (sec_accum + stage_v_89) & 255;

    /* Execution Pipeline Stage 90 */
    int stage_v_90 = 0;
    if ((sec_r000807_21 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_90 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_90 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_90 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_90) & 255;
    sec_accum = (sec_accum + stage_v_90) & 255;

    /* Execution Pipeline Stage 91 */
    int stage_v_91 = 0;
    if ((stage_v_42 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_91 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_91 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_91 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_91) & 255;
    sec_accum = (sec_accum + stage_v_91) & 255;

    /* Execution Pipeline Stage 92 */
    int stage_v_92 = 0;
    if ((stage_v_44 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_92 = (pub_r000807_15 + 31) & 127;
        } else {
            stage_v_92 = (pub_r000807_15 + 13) & 127;
        }
    } else {
        stage_v_92 = (pub_r000807_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_92) & 255;
    sec_accum = (sec_accum + stage_v_92) & 255;

    /* Execution Pipeline Stage 93 */
    int stage_v_93 = 0;
    if ((stage_v_16 & 1) != 0) {
        if ((sec_r000807_5 & 2) != 0) {
            stage_v_93 = (pub_r000807_15 + 31) & 127;
        } else {
            stage_v_93 = (pub_r000807_15 + 13) & 127;
        }
    } else {
        stage_v_93 = (pub_r000807_15 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_93) & 255;
    sec_accum = (sec_accum + stage_v_93) & 255;

    /* Execution Pipeline Stage 94 */
    int stage_v_94 = 0;
    if ((stage_v_37 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_94 = (pub_r000807_1 + 31) & 127;
        } else {
            stage_v_94 = (pub_r000807_1 + 13) & 127;
        }
    } else {
        stage_v_94 = (pub_r000807_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_94) & 255;
    sec_accum = (sec_accum + stage_v_94) & 255;

    /* Execution Pipeline Stage 95 */
    int stage_v_95 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000807_6 & 2) != 0) {
            stage_v_95 = (pub_r000807_9 + 31) & 127;
        } else {
            stage_v_95 = (pub_r000807_9 + 13) & 127;
        }
    } else {
        stage_v_95 = (pub_r000807_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_95) & 255;
    sec_accum = (sec_accum + stage_v_95) & 255;

    /* Execution Pipeline Stage 96 */
    int stage_v_96 = 0;
    if ((stage_v_52 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_96 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_96 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_96 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_96) & 255;
    sec_accum = (sec_accum + stage_v_96) & 255;

    /* Execution Pipeline Stage 97 */
    int stage_v_97 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_97 = (pub_r000807_18 + 31) & 127;
        } else {
            stage_v_97 = (pub_r000807_18 + 13) & 127;
        }
    } else {
        stage_v_97 = (pub_r000807_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_97) & 255;
    sec_accum = (sec_accum + stage_v_97) & 255;

    /* Execution Pipeline Stage 98 */
    int stage_v_98 = 0;
    if ((sec_r000807_21 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_98 = (pub_r000807_21 + 31) & 127;
        } else {
            stage_v_98 = (pub_r000807_21 + 13) & 127;
        }
    } else {
        stage_v_98 = (pub_r000807_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_98) & 255;
    sec_accum = (sec_accum + stage_v_98) & 255;

    /* Execution Pipeline Stage 99 */
    int stage_v_99 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_99 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_99 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_99 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_99) & 255;
    sec_accum = (sec_accum + stage_v_99) & 255;

    /* Execution Pipeline Stage 100 */
    int stage_v_100 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_100 = (pub_r000807_14 + 31) & 127;
        } else {
            stage_v_100 = (pub_r000807_14 + 13) & 127;
        }
    } else {
        stage_v_100 = (pub_r000807_14 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_100) & 255;
    sec_accum = (sec_accum + stage_v_100) & 255;

    /* Execution Pipeline Stage 101 */
    int stage_v_101 = 0;
    if ((stage_v_38 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_101 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_101 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_101 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_101) & 255;
    sec_accum = (sec_accum + stage_v_101) & 255;

    /* Execution Pipeline Stage 102 */
    int stage_v_102 = 0;
    if ((stage_v_83 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_102 = (pub_r000807_7 + 31) & 127;
        } else {
            stage_v_102 = (pub_r000807_7 + 13) & 127;
        }
    } else {
        stage_v_102 = (pub_r000807_7 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_102) & 255;
    sec_accum = (sec_accum + stage_v_102) & 255;

    /* Execution Pipeline Stage 103 */
    int stage_v_103 = 0;
    if ((stage_v_20 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_103 = (pub_r000807_6 + 31) & 127;
        } else {
            stage_v_103 = (pub_r000807_6 + 13) & 127;
        }
    } else {
        stage_v_103 = (pub_r000807_6 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_103) & 255;
    sec_accum = (sec_accum + stage_v_103) & 255;

    /* Execution Pipeline Stage 104 */
    int stage_v_104 = 0;
    if ((stage_v_13 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_104 = (pub_r000807_8 + 31) & 127;
        } else {
            stage_v_104 = (pub_r000807_8 + 13) & 127;
        }
    } else {
        stage_v_104 = (pub_r000807_8 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_104) & 255;
    sec_accum = (sec_accum + stage_v_104) & 255;

    /* Execution Pipeline Stage 105 */
    int stage_v_105 = 0;
    if ((stage_v_103 & 1) != 0) {
        if ((sec_r000807_5 & 2) != 0) {
            stage_v_105 = (pub_r000807_17 + 31) & 127;
        } else {
            stage_v_105 = (pub_r000807_17 + 13) & 127;
        }
    } else {
        stage_v_105 = (pub_r000807_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_105) & 255;
    sec_accum = (sec_accum + stage_v_105) & 255;

    /* Execution Pipeline Stage 106 */
    int stage_v_106 = 0;
    if ((stage_v_102 & 1) != 0) {
        if ((sec_r000807_10 & 2) != 0) {
            stage_v_106 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_106 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_106 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_106) & 255;
    sec_accum = (sec_accum + stage_v_106) & 255;

    /* Execution Pipeline Stage 107 */
    int stage_v_107 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000807_9 & 2) != 0) {
            stage_v_107 = (pub_r000807_11 + 31) & 127;
        } else {
            stage_v_107 = (pub_r000807_11 + 13) & 127;
        }
    } else {
        stage_v_107 = (pub_r000807_11 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_107) & 255;
    sec_accum = (sec_accum + stage_v_107) & 255;

    /* Execution Pipeline Stage 108 */
    int stage_v_108 = 0;
    if ((sec_r000807_11 & 1) != 0) {
        if ((sec_r000807_15 & 2) != 0) {
            stage_v_108 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_108 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_108 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_108) & 255;
    sec_accum = (sec_accum + stage_v_108) & 255;

    /* Execution Pipeline Stage 109 */
    int stage_v_109 = 0;
    if ((stage_v_60 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_109 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_109 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_109 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_109) & 255;
    sec_accum = (sec_accum + stage_v_109) & 255;

    /* Execution Pipeline Stage 110 */
    int stage_v_110 = 0;
    if ((stage_v_21 & 1) != 0) {
        if ((sec_r000807_0 & 2) != 0) {
            stage_v_110 = (pub_r000807_4 + 31) & 127;
        } else {
            stage_v_110 = (pub_r000807_4 + 13) & 127;
        }
    } else {
        stage_v_110 = (pub_r000807_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_110) & 255;
    sec_accum = (sec_accum + stage_v_110) & 255;

    /* Execution Pipeline Stage 111 */
    int stage_v_111 = 0;
    if ((stage_v_12 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_111 = (pub_r000807_9 + 31) & 127;
        } else {
            stage_v_111 = (pub_r000807_9 + 13) & 127;
        }
    } else {
        stage_v_111 = (pub_r000807_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_111) & 255;
    sec_accum = (sec_accum + stage_v_111) & 255;

    /* Execution Pipeline Stage 112 */
    int stage_v_112 = 0;
    if ((stage_v_28 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_112 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_112 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_112 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_112) & 255;
    sec_accum = (sec_accum + stage_v_112) & 255;

    /* Execution Pipeline Stage 113 */
    int stage_v_113 = 0;
    if ((stage_v_90 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_113 = (pub_r000807_19 + 31) & 127;
        } else {
            stage_v_113 = (pub_r000807_19 + 13) & 127;
        }
    } else {
        stage_v_113 = (pub_r000807_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_113) & 255;
    sec_accum = (sec_accum + stage_v_113) & 255;

    /* Execution Pipeline Stage 114 */
    int stage_v_114 = 0;
    if ((sec_r000807_6 & 1) != 0) {
        if ((sec_r000807_21 & 2) != 0) {
            stage_v_114 = (pub_r000807_22 + 31) & 127;
        } else {
            stage_v_114 = (pub_r000807_22 + 13) & 127;
        }
    } else {
        stage_v_114 = (pub_r000807_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_114) & 255;
    sec_accum = (sec_accum + stage_v_114) & 255;

    /* Execution Pipeline Stage 115 */
    int stage_v_115 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_115 = (pub_r000807_17 + 31) & 127;
        } else {
            stage_v_115 = (pub_r000807_17 + 13) & 127;
        }
    } else {
        stage_v_115 = (pub_r000807_17 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_115) & 255;
    sec_accum = (sec_accum + stage_v_115) & 255;

    /* Execution Pipeline Stage 116 */
    int stage_v_116 = 0;
    if ((stage_v_73 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_116 = (pub_r000807_12 + 31) & 127;
        } else {
            stage_v_116 = (pub_r000807_12 + 13) & 127;
        }
    } else {
        stage_v_116 = (pub_r000807_12 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_116) & 255;
    sec_accum = (sec_accum + stage_v_116) & 255;

    /* Execution Pipeline Stage 117 */
    int stage_v_117 = 0;
    if ((stage_v_66 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_117 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_117 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_117 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_117) & 255;
    sec_accum = (sec_accum + stage_v_117) & 255;

    /* Execution Pipeline Stage 118 */
    int stage_v_118 = 0;
    if ((sec_r000807_10 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_118 = (pub_r000807_9 + 31) & 127;
        } else {
            stage_v_118 = (pub_r000807_9 + 13) & 127;
        }
    } else {
        stage_v_118 = (pub_r000807_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_118) & 255;
    sec_accum = (sec_accum + stage_v_118) & 255;

    /* Execution Pipeline Stage 119 */
    int stage_v_119 = 0;
    if ((sec_r000807_4 & 1) != 0) {
        if ((sec_r000807_3 & 2) != 0) {
            stage_v_119 = (pub_r000807_0 + 31) & 127;
        } else {
            stage_v_119 = (pub_r000807_0 + 13) & 127;
        }
    } else {
        stage_v_119 = (pub_r000807_0 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_119) & 255;
    sec_accum = (sec_accum + stage_v_119) & 255;

    /* Execution Pipeline Stage 120 */
    int stage_v_120 = 0;
    if ((sec_r000807_5 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_120 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_120 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_120 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_120) & 255;
    sec_accum = (sec_accum + stage_v_120) & 255;

    /* Execution Pipeline Stage 121 */
    int stage_v_121 = 0;
    if ((sec_r000807_18 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_121 = (pub_r000807_18 + 31) & 127;
        } else {
            stage_v_121 = (pub_r000807_18 + 13) & 127;
        }
    } else {
        stage_v_121 = (pub_r000807_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_121) & 255;
    sec_accum = (sec_accum + stage_v_121) & 255;

    /* Execution Pipeline Stage 122 */
    int stage_v_122 = 0;
    if ((stage_v_32 & 1) != 0) {
        if ((sec_r000807_5 & 2) != 0) {
            stage_v_122 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_122 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_122 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_122) & 255;
    sec_accum = (sec_accum + stage_v_122) & 255;

    /* Execution Pipeline Stage 123 */
    int stage_v_123 = 0;
    if ((stage_v_31 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_123 = (pub_r000807_20 + 31) & 127;
        } else {
            stage_v_123 = (pub_r000807_20 + 13) & 127;
        }
    } else {
        stage_v_123 = (pub_r000807_20 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_123) & 255;
    sec_accum = (sec_accum + stage_v_123) & 255;

    /* Execution Pipeline Stage 124 */
    int stage_v_124 = 0;
    if ((sec_r000807_21 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_124 = (pub_r000807_4 + 31) & 127;
        } else {
            stage_v_124 = (pub_r000807_4 + 13) & 127;
        }
    } else {
        stage_v_124 = (pub_r000807_4 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_124) & 255;
    sec_accum = (sec_accum + stage_v_124) & 255;

    /* Execution Pipeline Stage 125 */
    int stage_v_125 = 0;
    if ((sec_r000807_11 & 1) != 0) {
        if ((sec_r000807_12 & 2) != 0) {
            stage_v_125 = (pub_r000807_22 + 31) & 127;
        } else {
            stage_v_125 = (pub_r000807_22 + 13) & 127;
        }
    } else {
        stage_v_125 = (pub_r000807_22 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_125) & 255;
    sec_accum = (sec_accum + stage_v_125) & 255;

    /* Execution Pipeline Stage 126 */
    int stage_v_126 = 0;
    if ((stage_v_22 & 1) != 0) {
        if ((sec_r000807_3 & 2) != 0) {
            stage_v_126 = (pub_r000807_16 + 31) & 127;
        } else {
            stage_v_126 = (pub_r000807_16 + 13) & 127;
        }
    } else {
        stage_v_126 = (pub_r000807_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_126) & 255;
    sec_accum = (sec_accum + stage_v_126) & 255;

    /* Execution Pipeline Stage 127 */
    int stage_v_127 = 0;
    if ((stage_v_43 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_127 = (pub_r000807_19 + 31) & 127;
        } else {
            stage_v_127 = (pub_r000807_19 + 13) & 127;
        }
    } else {
        stage_v_127 = (pub_r000807_19 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_127) & 255;
    sec_accum = (sec_accum + stage_v_127) & 255;

    /* Execution Pipeline Stage 128 */
    int stage_v_128 = 0;
    if ((sec_r000807_1 & 1) != 0) {
        if ((sec_r000807_9 & 2) != 0) {
            stage_v_128 = (pub_r000807_9 + 31) & 127;
        } else {
            stage_v_128 = (pub_r000807_9 + 13) & 127;
        }
    } else {
        stage_v_128 = (pub_r000807_9 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_128) & 255;
    sec_accum = (sec_accum + stage_v_128) & 255;

    /* Execution Pipeline Stage 129 */
    int stage_v_129 = 0;
    if ((stage_v_91 & 1) != 0) {
        if ((sec_r000807_12 & 2) != 0) {
            stage_v_129 = (pub_r000807_16 + 31) & 127;
        } else {
            stage_v_129 = (pub_r000807_16 + 13) & 127;
        }
    } else {
        stage_v_129 = (pub_r000807_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_129) & 255;
    sec_accum = (sec_accum + stage_v_129) & 255;

    /* Execution Pipeline Stage 130 */
    int stage_v_130 = 0;
    if ((sec_r000807_9 & 1) != 0) {
        if ((sec_r000807_8 & 2) != 0) {
            stage_v_130 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_130 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_130 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_130) & 255;
    sec_accum = (sec_accum + stage_v_130) & 255;

    /* Execution Pipeline Stage 131 */
    int stage_v_131 = 0;
    if ((stage_v_41 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_131 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_131 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_131 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_131) & 255;
    sec_accum = (sec_accum + stage_v_131) & 255;

    /* Execution Pipeline Stage 132 */
    int stage_v_132 = 0;
    if ((stage_v_70 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_132 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_132 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_132 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_132) & 255;
    sec_accum = (sec_accum + stage_v_132) & 255;

    /* Execution Pipeline Stage 133 */
    int stage_v_133 = 0;
    if ((stage_v_71 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_133 = (pub_r000807_21 + 31) & 127;
        } else {
            stage_v_133 = (pub_r000807_21 + 13) & 127;
        }
    } else {
        stage_v_133 = (pub_r000807_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_133) & 255;
    sec_accum = (sec_accum + stage_v_133) & 255;

    /* Execution Pipeline Stage 134 */
    int stage_v_134 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000807_1 & 2) != 0) {
            stage_v_134 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_134 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_134 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_134) & 255;
    sec_accum = (sec_accum + stage_v_134) & 255;

    /* Execution Pipeline Stage 135 */
    int stage_v_135 = 0;
    if ((stage_v_8 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_135 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_135 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_135 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_135) & 255;
    sec_accum = (sec_accum + stage_v_135) & 255;

    /* Execution Pipeline Stage 136 */
    int stage_v_136 = 0;
    if ((sec_r000807_2 & 1) != 0) {
        if ((sec_r000807_17 & 2) != 0) {
            stage_v_136 = (pub_r000807_21 + 31) & 127;
        } else {
            stage_v_136 = (pub_r000807_21 + 13) & 127;
        }
    } else {
        stage_v_136 = (pub_r000807_21 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_136) & 255;
    sec_accum = (sec_accum + stage_v_136) & 255;

    /* Execution Pipeline Stage 137 */
    int stage_v_137 = 0;
    if ((stage_v_82 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_137 = (pub_r000807_18 + 31) & 127;
        } else {
            stage_v_137 = (pub_r000807_18 + 13) & 127;
        }
    } else {
        stage_v_137 = (pub_r000807_18 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_137) & 255;
    sec_accum = (sec_accum + stage_v_137) & 255;

    /* Execution Pipeline Stage 138 */
    int stage_v_138 = 0;
    if ((stage_v_23 & 1) != 0) {
        if ((sec_r000807_16 & 2) != 0) {
            stage_v_138 = (pub_r000807_10 + 31) & 127;
        } else {
            stage_v_138 = (pub_r000807_10 + 13) & 127;
        }
    } else {
        stage_v_138 = (pub_r000807_10 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_138) & 255;
    sec_accum = (sec_accum + stage_v_138) & 255;

    /* Execution Pipeline Stage 139 */
    int stage_v_139 = 0;
    if ((stage_v_26 & 1) != 0) {
        if ((sec_r000807_4 & 2) != 0) {
            stage_v_139 = (pub_r000807_2 + 31) & 127;
        } else {
            stage_v_139 = (pub_r000807_2 + 13) & 127;
        }
    } else {
        stage_v_139 = (pub_r000807_2 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_139) & 255;
    sec_accum = (sec_accum + stage_v_139) & 255;

    /* Execution Pipeline Stage 140 */
    int stage_v_140 = 0;
    if ((stage_v_89 & 1) != 0) {
        if ((sec_r000807_2 & 2) != 0) {
            stage_v_140 = (pub_r000807_3 + 31) & 127;
        } else {
            stage_v_140 = (pub_r000807_3 + 13) & 127;
        }
    } else {
        stage_v_140 = (pub_r000807_3 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_140) & 255;
    sec_accum = (sec_accum + stage_v_140) & 255;

    /* Execution Pipeline Stage 141 */
    int stage_v_141 = 0;
    if ((stage_v_84 & 1) != 0) {
        if ((sec_r000807_13 & 2) != 0) {
            stage_v_141 = (pub_r000807_13 + 31) & 127;
        } else {
            stage_v_141 = (pub_r000807_13 + 13) & 127;
        }
    } else {
        stage_v_141 = (pub_r000807_13 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_141) & 255;
    sec_accum = (sec_accum + stage_v_141) & 255;

    /* Execution Pipeline Stage 142 */
    int stage_v_142 = 0;
    if ((stage_v_59 & 1) != 0) {
        if ((sec_r000807_20 & 2) != 0) {
            stage_v_142 = (pub_r000807_5 + 31) & 127;
        } else {
            stage_v_142 = (pub_r000807_5 + 13) & 127;
        }
    } else {
        stage_v_142 = (pub_r000807_5 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_142) & 255;
    sec_accum = (sec_accum + stage_v_142) & 255;

    /* Execution Pipeline Stage 143 */
    int stage_v_143 = 0;
    if ((stage_v_61 & 1) != 0) {
        if ((sec_r000807_19 & 2) != 0) {
            stage_v_143 = (pub_r000807_16 + 31) & 127;
        } else {
            stage_v_143 = (pub_r000807_16 + 13) & 127;
        }
    } else {
        stage_v_143 = (pub_r000807_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_143) & 255;
    sec_accum = (sec_accum + stage_v_143) & 255;

    /* Execution Pipeline Stage 144 */
    int stage_v_144 = 0;
    if ((stage_v_87 & 1) != 0) {
        if ((sec_r000807_18 & 2) != 0) {
            stage_v_144 = (pub_r000807_1 + 31) & 127;
        } else {
            stage_v_144 = (pub_r000807_1 + 13) & 127;
        }
    } else {
        stage_v_144 = (pub_r000807_1 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_144) & 255;
    sec_accum = (sec_accum + stage_v_144) & 255;

    /* Execution Pipeline Stage 145 */
    int stage_v_145 = 0;
    if ((stage_v_86 & 1) != 0) {
        if ((sec_r000807_7 & 2) != 0) {
            stage_v_145 = (pub_r000807_16 + 31) & 127;
        } else {
            stage_v_145 = (pub_r000807_16 + 13) & 127;
        }
    } else {
        stage_v_145 = (pub_r000807_16 + 7) & 127;
    }
    out_sink = (out_sink + stage_v_145) & 255;
    sec_accum = (sec_accum + stage_v_145) & 255;

    /* Final Aggregate Output */
    g_out = (out_sink + sec_accum) & 255;
    g_chk = chk_sum;
    g_telemetry = (sec_accum ^ chk_sum) & 127;
    return 0;
}
